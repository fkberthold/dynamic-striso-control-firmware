import("stdfaust.lib");
maxmsp = library("maxmsp.lib");
fast = library("fast.lib");

/*
 * # Striso Synthesizer
 * This variant of the Striso synthesizer will allow the musician to:
 * - Control the volume of the note by pressing harder or softer.
 * - Control the complexity of the by moving their finger forward and backward.
 * - Per standard Striso behavior, the pitch can be shifted by moving the finger
 *      left and right.
 * - When a button is tapped, then the note will have a longer release time,
 *      making it similar to a plucked string.
 *
 * # Tabulation
 * Throughout the code, I make heavy use of tabulation. This is because
 * the processor on the Striso is not very powerful, and tabulation is
 * much faster than using a function.  I haven't hit space limitations yet.
 * 
 * # Code Organization
 * The code is organized into five sections.
 *   1. Utility Functions, Constants, and Libraries
 *   2. Values coming in from the interface.
 *   3. Amplitude Envelope
 *   4. Wave form generation.
 *   5. Combine it all to make pretty sounds.
 *
 * Generally speaking, I've organized the code from most to least specific,
 *  For any given section, if you want to see the high level function that
 *  combines everything, look at the bottom, if you want to see the low level
 *  functions, look at the top.  This seems to be standard practice in Faust.
 *  where the `process` function is at the bottom.
 */


/*
 * Utility Functions, Constants, and Libraries
 */

// The number of voices/simultanious notes.
VOICE_COUNT = 6;

// Convert frequency to K value for use by the filters.
K_f0 = fast.K_f0;
// Each of the filter functions takes takes a value K and a value Q.
//  At least the BPF will take a frequency through the K value processed
//  via `K_f0`, eg: `BPF(K_f0(freq), 1000)`.
//  The Q value is a quality factor, and is used to determine the width of
//  the filter.
HPF = fast.HPF; // High Pass Filter
LPF = fast.LPF; // Low Pass Filter
BPF = fast.BPF; // Band Pass Filter
note_2_freq = fast.note2freq; // Given a midi note, return the frequency.

// Utility functions for the BPF filter.
halftime_2_fac(x) = 0.5^(1./(ma.SR*x));
halftime_2_fac_fast(x) = 1-0.7*(1./(ma.SR*x));

//smooth(c)        = *(1-c) : +~*(c);
smooth(x) = maxmsp.line(x,2);


/*
 * Take in values from the interface.
 *  Takes in the note, pressure, and x/y position of the finger.
 *  Outputs the sound.
 *
 * I've commeted those that I understand, if you understand the others,
 *  I love pull requests.
 */
// The numeric midi note, where 69 is A4.
note = vslider("[0]note[style:knob]",69,0,127,.01);
// The pressure on the z axis, where 1 is the maximum pressure.
pres = vslider("[1]pres[style:knob]",0,0,1,0.01);
// The velocity on the z axis, where 1 is the maximum velocity going down
//  and -1 is the maximum velocity going up.
vpres = vslider("[2]vpres[style:knob]",0,-1,1,0.01);
// The pressure on the x axis, where 1 is all the way right and -1 is
//  all the way left.
but_x = vslider("but_x[style:knob]",0,-1,1,0.01);
// The pressure on the y axis, where 1 is all the way away from you and -1 is
//  all the way towards you.
but_y = vslider("but_y[style:knob]",0,-1,1,0.01);

// When working with the accelerometers, remember that
//  gravity is always pulling down on the device. So when
//  the device is flat, the z axis will be 1, and the x & y
//  axis will be 0. When the device is held upright so the
//  controls are facing you, the z axis will be 0, and the
//  y axis will be 1.
acc_abs = vslider("v:accelerometer/acc_abs[style:knob]",1,0,4,0.01) : LPF(K_f0(40),1.31) : LPF(K_f0(40),0.54);
acc_x = vslider("v:accelerometer/acc_x[style:knob]",0,-1,1,0.01);
acc_y = vslider("v:accelerometer/acc_y[style:knob]",0,-1,1,0.01);
acc_z = vslider("v:accelerometer/acc_z[style:knob]",-1,-1,1,0.01);

// Rotation is the rotation of the device around the x, y, and z axis.
//  remember that means that, say you are holding the device so the
//  controls are up, then when you rotate it left and right, it's changing
//  on the z axis.
rot_x = vslider("v:gyroscope/rot_x[style:knob]",0,-1,1,0.01);
rot_y = vslider("v:gyroscope/rot_y[style:knob]",0,-1,1,0.01);
rot_z = vslider("v:gyroscope/rot_z[style:knob]",0,-1,1,0.01);

pedal = vslider("v:control/pedal[style:knob]",3/16,0,1,0.01);

pos_decay = hslider("v:[0]config/posDecay[style:knob]",0.1,0,1,0.01):halftime_2_fac;
neg_decay = hslider("v:[0]config/negDecay[style:knob]",0.2,0,1,0.01):halftime_2_fac;
p_decay = hslider("v:[0]config/pDecay[style:knob]",0.05,0,1,0.01):halftime_2_fac;
acc_decay = hslider("v:[0]config/accDecay[style:knob]",0.10,0,1,0.01):halftime_2_fac;

wpos = hslider("v:[0]config/wpos[style:knob]",0.05,0,1,0.01);
wneg = hslider("v:[0]config/wneg[style:knob]",0.0,0,1,0.01);
wpres = hslider("v:[0]config/wpres[style:knob]",0.9,0,1,0.01);

filt_q = hslider("v:[1]config2/filtQ[style:knob]",1,0,10,0.01);
filt_ff = hslider("v:[1]config2/filtFF[style:knob]",1,0,16,0.01);
bend_Range = hslider("v:[1]config2/bendRange[style:knob]",0.5,0,2,0.01);
min_freq = hslider("v:[1]config2/minFreq[style:knob]",200,0,1000,1);
body_freq = hslider("v:[1]config2/bodyFreq[style:knob]",1000,0,2000,1);
filt_2_freq = hslider("v:[1]config2/filt2Freq[style:knob]",3000,0,10000,1);
filt_2_q = hslider("v:[1]config2/filt2Q[style:knob]",2,0.01,10,0.01);
filt_2_level = hslider("v:[1]config2/filt2Level[style:knob]",0.8,0,50,0.01);

B = hslider("v:[2]config3/brightness[style:knob]", 0.5, 0, 1, 0.01);// 0-1
t60 = hslider("v:[2]config3/decaytime_T60[style:knob]", 10, 0, 10, 0.01);  // -60db decay time (sec)
res_fact = hslider("v:[2]config3/resfact[style:knob]", 0.03, 0, 1, 0.01);
pp_offset = hslider("v:[2]config3/ppOffset[style:knob]", 48, 0, 100, 0.1);
pp_range = hslider("v:[2]config3/ppRange[style:knob]", 18, 0, 36, 0.1);

bf_q1 = hslider("v:[2]config3/bfQ1[style:knob]",5,0.3,20,0.01);
bf_q2 = hslider("v:[2]config3/bfQ2[style:knob]",8,0.3,20,0.01);
bf_q3 = hslider("v:[2]config3/bfQ3[style:knob]",8,0.3,20,0.01);
bf_level = hslider("v:[2]config3/bflevel[style:knob]",6,0.1,20,0.01);

/*
 * Amplitude Envelope
 */

// States for the state machine
//  that controls the amplitude.
//  This just makes it so you can follow
//  what goes on in the state machine.
INIT = 0;
ATTACK = 1;
DECAY = 2;
RELEASE = 3;
SUSTAIN_INCR = 4;
SUSTAIN_DECR = 5;
PLUCK = 6;

// Time constants for the state machine.
//  this influences how long the stages
//  are in seconds.
ATTACK_T = 0.1 * ma.SR;
DECAY_T = 0.4 * ma.SR;
RELEASE_T = 0.15 * ma.SR;
SUSTAIN_T = 0.2 * ma.SR;
PLUCK_T = 0.75 * ma.SR;

// Determines when the note is released.
RELEASE_THRESHOLD = 0.003;


// The release decay rate is used to control the release/pluck time to give it a more
//  natural sound.  While it's modeled loosely after an exponential decay curve, it
//  will hold on at the middle curve longer.  The math says this is wrong, my ear
//  disagrees.
// Args in:
//      x_in: The x value to calculate the decay rate for.
//  Returns: The decay rate.
release_decay_rate(x_in) = ba.tabulate(0, helper, 21, 0, 1, x_in).lin with {
    helper(x) = y with {
        y = ba.selectn(21, int(x * 21), 1, 0.86, 0.74, 0.64, 0.55, 0.47, 0.40, 0.35, 0.30, 0.26, 0.22, 0.19, 0.16, 0.14, 0.12, 0.10, 0.08, 0.06, 0.03, 0.01, 0);
    };
};

// Indicates the tick when the state began.
// This is used to calculate the time since the state changed.
// Args in:
//      state: The current state.
//  Returns: The time the state changed.
time_changed(state) = ba.time : ba.latch(state != state');

// Given the current velocity and pressure, returns the maximum/most positive velocity since the button
//  went from an unpressed state to a pressed state.
// Args in:
//      velocity: The current velocity, on the z axis.
//      pressure: The current pressure, on the z axis.
//  Returns: The maximum velocity since the state changed.
get_pos_velocity_abs(velocity, pressure) = velocity : ba.peakhold(((pressure <= RELEASE_THRESHOLD) | (pressure' >= RELEASE_THRESHOLD)));

// Given the current velocity and pressure, returns the minimum/most negative velocity since the button
//  went from an unpressed state to a pressed state.
// Args in:
//      velocity: The current velocity, on the z axis.
//      pressure: The current pressure, on the z axis.
//  Returns: The minimum velocity since the state changed.
get_neg_velocity_abs(velocity, pressure) = get_pos_velocity_abs(-1 * velocity, pressure);

// Returns the maximum pressure & amplitude since the state changed.
// Args in:
//      state: The current state.
//      pres: The current pressure, on the z axis.
//      amp: The current amplitude.
//  Returns: The maximum pressure & amplitude since the state changed.
max_pres_amp(state,pres,amp) = ba.peakhold(state!=state', max(pres, amp));

// Given the current state, returns the time base for the state. Which dictates how long
//  the state will last.
// Args in:
//      state: The current state.
// Returns: The time base for the state.
get_time_base(state) = ba.selectn(7, state, 0, ATTACK_T, DECAY_T, RELEASE_T, SUSTAIN_T, SUSTAIN_T, PLUCK_T);

// Given current conditions, returns the next state.
//  Args in:
//      prev_state: The previous state.
//      time_since: The time since the state changed.
//      pressure: The current pressure, on the z axis.
//      max_pressure: The maximum pressure since the state changed.
//      min_velocity: The minimum velocity since the state changed.
//      max_velocity: The maximum velocity since the state changed.
//      amplitude: The current amplitude.
//  Returns: The next state.
get_state(prev_state, time_since, pressure, max_pressure, min_velocity, max_velocity, amplitude) = next_state with {
    // Init is the state where the button is not percieved as having been pushed.
    from_init = ba.if((pressure > RELEASE_THRESHOLD), ATTACK, INIT);
    // Remain in attack until the total amplitude is greater than the distance between the min and max velocity.
    //  (max_velocity is distance above 0, min_velocity is distance below 0)
    // If the pressure is fully released, go to pluck, which will generally be longer, otherwise decay to the current pressure.
    from_attack = ba.if(amplitude >= min(max_velocity + min_velocity, 1.0), ba.if(pressure <= RELEASE_THRESHOLD, PLUCK, DECAY), ATTACK);
    // A pluck event can still happen during decay if the pressure is released.
    from_decay = ba.if(pressure > RELEASE_THRESHOLD, ba.if(pressure >= amplitude, SUSTAIN_INCR, DECAY), PLUCK);
    // In early design I thought it might be interesting to have the change in sustain be different whether it was
    //  increasing or decreasing, I didn't really find a particularly musical use for it, but someone else may.
    from_sustain_incr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure <= amplitude, SUSTAIN_DECR, SUSTAIN_INCR));
    from_sustain_decr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure >= amplitude, SUSTAIN_INCR, SUSTAIN_DECR));
    // While in principle the release state decays similarly to the pluck state, in practice the sustain responds so
    //  quickly that we rarely have the release state happen.
    // Note that for the release state to end, both the pressure and the amplitude have to be at or near zero, this
    //   keeps the system from accidently jumping straight to init again and giving a double attack at the start.
    from_release = ba.if((pressure <= RELEASE_THRESHOLD) & (amplitude <= 0.001), INIT, ba.if(pressure > RELEASE_THRESHOLD, ATTACK, RELEASE));
    // The pluck state is designed for a long release time.  Notice that pluck can go straight to Attack again if
    //  the release threshold is is passed for repeated rapid plucking.
    from_pluck = ba.if(amplitude <= 0.001, INIT, ba.if(pressure > RELEASE_THRESHOLD, ATTACK, PLUCK));

    next_state = ba.selectn(7, prev_state,
                               from_init,
                               from_attack,
                               from_decay,
                               from_release,
                               from_sustain_incr,
                               from_sustain_decr,
                               from_pluck);
};

// Calculates the amplitude curve.
//  Args in:
//      state: The current state.
//      pressure: The current pressure, on the z axis.
//      min_velocity: The minimum velocity since the state changed.
//      max_velocity: The maximum velocity since the state changed.
//      time_base: The time base for the current state, in seconds.
//      max_pressure: The maximum pressure since the state changed.
//      time_since: The time since the state changed.
//  Returns: The amplitude.
calculate_curve(state, pressure, min_velocity, max_velocity, time_base, max_pressure, time_since) = amplitude with {
    // Where max_velocity is the max distance above 0, and min_velocity is the max distance below 0.
    vel_diff = max_velocity + min_velocity;
    // The if solves the crash when the time base is 0 if the state is INIT.
    rel_target = release_decay_rate(ba.if(time_base > 0, time_since/time_base, 0));

    // The curve is aiming for the `target` value, this will be the based on
    //  velocity on attack, the pressure on decay and sustain, and the rel_target
    //  which will be a steadily decreasing value that roughly matches exponential
    //  decay.
    target = ba.if(state == ATTACK, min(1, vel_diff), 
                ba.if(state == INIT, 0.0,
                    ba.if(state == PLUCK, rel_target * vel_diff,
                        ba.if(state == RELEASE, rel_target * max_pressure, pressure))));
    // For most cases the ramp time is the time base, for RELEASE and PLUCK, it's divided by
    //  21 because that's the number of steps I split my fake exponential decay into.
    ramp_time = ba.if(state == INIT, 0.0001,
                    ba.if((state == RELEASE)|(state == PLUCK), time_base/21, time_base));
    amplitude = ba.ramp(ramp_time, target);
};


// Given the current pressure and velocity, returns the amplitude.
//  Args in:
//      pres: The current pressure, on the z axis.
//      vpres: The current velocity, on the z axis.
//  Returns: The amplitude.
get_amplitude(pres, vpres) = (pres) : (get_amplitude_rec ~ (_, _)) : (!, _) with {
    min_velocity = get_neg_velocity_abs(vpres, pres) : min(1, _);
    max_velocity = get_pos_velocity_abs(vpres, pres) : min(1, _);
    get_amplitude_rec(prev_state, prev_amp, pressure) = (new_state, amplitude) with {
        max_pressure = max_pres_amp(prev_state, pressure, prev_amp);
        start_time = time_changed(prev_state);
        time_since = (ba.time - start_time);
        time_base = get_time_base(new_state);

        amplitude = calculate_curve(prev_state, pressure, min_velocity, max_velocity, time_base, max_pressure, time_since);
        new_state = get_state(prev_state, time_since, pressure, max_pressure, min_velocity, max_velocity, prev_amp);
    };
};


/*
 * Wave form generation.
 */

// This helper function is used to generate a triangle wave.
// Args in:
//      phasor: The phasor to generate the triangle wave for.
//  Returns: The triangle wave.
phas_to_tri(phasor) = ba.tabulate(0, helper, 500, 0, 1, phasor).lin with {
    helper(phasor_in) = ba.if(phasor_in < 0.5, phasor_in * 4 - 1, (1 - phasor_in) * 4 - 1);
};

// This helper function is used to generate a saw wave.
// Args in:
//      phasor: The phasor to generate the saw wave for.
//  Returns: The saw wave.
phas_to_saw(phasor) = ba.tabulate(0, helper, 500, 0, 1, phasor).lin with {
    helper(phasor_in) = (phasor_in * 2) - 1;
};

// This helper functions gives a more natural feel to the buttons where there's
//  low sensitivity at the beginning and end, and high sensitivity in the middle.
//  so if you press gently, you get a more gentle sound, and it's hard to press
//  at the very top end of the amplitude.
// Args in:
//      x_in: The x value to calculate the ease in/out for.
//  Returns: The ease in/out value.
ease_in_out_sine(x_in) = ba.tabulate(0, helper, 1000, -1, 1, x_in).val with {
    helper(x) = y with {
        y = (cos(ma.PI * x) - 1) / -2 * ma.signum(x);
    };
};

// This helper function is used to lock the y axis to the maximum amplitude
//  since the last time the pressure was released.  This means that when a
//  note is 'plucked' with the y axis up or down, it maintains the intended
//  timbre.
// Args in:
//      y: The current y position, on the y axis.
//      pres: The current pressure, on the z axis.
//  Returns: The maximum amplitude since the last time the pressure was released.
lock_max_amp(y, pres) = peak with {
    lowest_val = ba.peakhold(((pres' <= RELEASE_THRESHOLD) & (pres > RELEASE_THRESHOLD) != 1), -1 * y);
    highest_val = ba.peakhold(((pres' <= RELEASE_THRESHOLD) & (pres > RELEASE_THRESHOLD)) != 1, y);
    peak = ba.if(highest_val > lowest_val, highest_val, -1 * lowest_val);
};

// Generates the wave form.
// Args in:
//      pres: The current pressure, on the z axis.
//      vpres: The current velocity, on the z axis.
//      freq: The frequency of the note.
//      y: The current y position, on the y axis.
//      amp: The current amplitude.
//  Returns: The wave form.
timbre_gen(pres, vpres, freq, y, amp) = wave with {
    // Control modifier    
    scale_y = ease_in_out_sine(y);
    amp_diff = pres - amp;
    lock_y = lock_max_amp(y, pres) * 2;

    // phasors for the different harmonics.
    full = os.phasor(1, freq); 

    // Main wave. This wave has a lot of control over the complexity of the
    //  timbre based mostly on the `scale_y` value.
    main_wave = wave_out with {
        tri_wave = phas_to_tri(full);
        saw_wave = phas_to_saw(full);
        saw_y = ba.if(pres <= RELEASE_THRESHOLD, lock_y, scale_y);
        saw_wave_amp = max(min(((saw_y * -0.8) + 0.2)  + (amp_diff/2), 1), 0);
        tri_wave_amp = 1 - (saw_wave_amp);
        wave_out = ((tri_wave * tri_wave_amp) + (saw_wave * saw_wave_amp)) : ba.ramp(ma.SR * 0.0003) : (_ * 1.1);
    };

    // By adding white noise, it softens the general sound, this allows us to
    //  pres forward and back on the y axis, and make it sound like the sound
    //  was always of the timbre, instead of some more rough transitional sounds
    //  at the beginning.
    add_noise(wave_in) = wave_out with {
        white_note = no.noise : BPF(K_f0(freq), 100);
        white_amp = min(1, ba.if(amp < 0.1, 1 - (amp * 10), 0) + max(0.05, 0.1 - abs(vpres))) ;
        wave_out = (wave_in * (1 - white_amp)) + (white_note * white_amp);
    };

    // By adding sub harmonics, it makes the sound more full.
    add_sub_harmonics(wave_in) = wave_out with {
        half = os.phasor(1, freq/2);
        quarter = os.phasor(1, freq/4);

        sub_harms = (phas_to_saw(quarter) * 0.2) + (phas_to_tri(half) * 0.8);
        sub_harm_amp = ba.if(amp < 0.1, amp, 0.1) * ((scale_y + 1) / 2);
        wave_out = (wave_in * (1 - sub_harm_amp)) + (sub_harms * sub_harm_amp);
    };

    wave = main_wave : add_noise : add_sub_harmonics;
};

/*
 * Combine it all to make pretty sounds.
 */

// Takes raw data as input, and outputs pretty sound waves.
// Args in:
//      note: The midi note.
//      pres: The pressure on the z(up/down) axis.
//      vpres: The velocity on the z axis.
//      but_x: The pressure on the x(left/right) axis.
//      but_y: The pressure on the y(forward/backward) axis.
// Returns: The sound wave.
voice(note,pres,vpres,but_x,but_y) = full_sound(level) //full_sound(level)
with {
    scaled_pres = ease_in_out_sine(real_pres);
    freq = note_2_freq(note);

    time_since_pressure_change = (ba.time - time_changed(vpres)) / ma.SR;
    // This is a bit of trickery to determine when the pressure has actually been released,
    //  there's a known issue on the Striso where if the pressure is held down hard then
    //  it sticks at around 0.007, so we need to ignore that.
    real_pres = ba.if((time_since_pressure_change > 0.5) & (vpres == 0), 0, pres);

    ampl_res = get_amplitude(scaled_pres, vpres);
    level = ampl_res : ba.ramp(ma.SR * 0.05);

    full_sound(ampl) = ampl <: (_, timbre_gen(scaled_pres, vpres, freq, but_y)) :  *;
};

// The main process function reads in the values from each of the individual
//  buttons pressed, transforms them via the `voice` function, and then
//  sums them together.
// I suspect that the High Pass Filter removes some static and clicks, the original
//  was set at 80hz, but where the Striso goes well below 80hz, I've dropped it to 40hz.
process = hgroup("strisy",
        sum(n, VOICE_COUNT, vgroup("v%n", (note,pres,vpres,but_x,but_y)) : voice)
        * 1.37 : HPF(K_f0(40),1.31)); 