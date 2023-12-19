import("stdfaust.lib");
SR = ma.SR;

maxmsp = library("maxmsp.lib");

fast = library("fast.lib");
K_f0 = fast.K_f0;
HPF = fast.HPF;
LPF = fast.LPF;
BPF = fast.BPF;
note2freq = fast.note2freq;

voicecount = 6;

halftime2fac(x) = 0.5^(1./(SR*x));
halftime2fac_fast(x) = 1-0.7*(1./(SR*x));

//smooth(c)        = *(1-c) : +~*(c);
smooth(x) = maxmsp.line(x,2);

envdecay(c) = (max:_ * c) ~ _;

dotpart(x) = x - int(x);

oscss(freq, even_harm) = even_harm*saw-(1-even_harm)*square
with {
    square = os.lf_squarewave(freq)*0.5;
    saw = os.saw2(freq);
};

note = vslider("[0]note[style:knob]",69,0,127,.01);
pres = vslider("[1]pres[style:knob]",0,0,1,0.01);
vpres = vslider("[2]vpres[style:knob]",0,-1,1,0.01);
but_x = vslider("but_x[style:knob]",0,-1,1,0.01);
but_y = vslider("but_y[style:knob]",0,-1,1,0.01);

acc_abs = vslider("v:accelerometer/acc_abs[style:knob]",1,0,4,0.01) : LPF(K_f0(40),1.31) : LPF(K_f0(40),0.54);
acc_x = vslider("v:accelerometer/acc_x[style:knob]",0,-1,1,0.01);
acc_y = vslider("v:accelerometer/acc_y[style:knob]",0,-1,1,0.01);
acc_z = vslider("v:accelerometer/acc_z[style:knob]",-1,-1,1,0.01);

rot_x = vslider("v:gyroscope/rot_x[style:knob]",0,-1,1,0.01);
rot_y = vslider("v:gyroscope/rot_y[style:knob]",0,-1,1,0.01);
rot_z = vslider("v:gyroscope/rot_z[style:knob]",0,-1,1,0.01);

pedal = vslider("v:control/pedal[style:knob]",3/16,0,1,0.01);

posDecay = hslider("v:[0]config/posDecay[style:knob]",0.1,0,1,0.01):halftime2fac;
negDecay = hslider("v:[0]config/negDecay[style:knob]",0.2,0,1,0.01):halftime2fac;
pDecay = hslider("v:[0]config/pDecay[style:knob]",0.05,0,1,0.01):halftime2fac;
accDecay = hslider("v:[0]config/accDecay[style:knob]",0.10,0,1,0.01):halftime2fac;

wpos = hslider("v:[0]config/wpos[style:knob]",0.05,0,1,0.01);
wneg = hslider("v:[0]config/wneg[style:knob]",0.0,0,1,0.01);
wpres = hslider("v:[0]config/wpres[style:knob]",0.9,0,1,0.01);

filtQ = hslider("v:[1]config2/filtQ[style:knob]",1,0,10,0.01);
filtFF = hslider("v:[1]config2/filtFF[style:knob]",1,0,16,0.01);
bendRange = hslider("v:[1]config2/bendRange[style:knob]",0.5,0,2,0.01);
minFreq = hslider("v:[1]config2/minFreq[style:knob]",200,0,1000,1);
bodyFreq = hslider("v:[1]config2/bodyFreq[style:knob]",1000,0,2000,1);
filt2Freq = hslider("v:[1]config2/filt2Freq[style:knob]",3000,0,10000,1);
filt2Q = hslider("v:[1]config2/filt2Q[style:knob]",2,0.01,10,0.01);
filt2level = hslider("v:[1]config2/filt2Level[style:knob]",0.8,0,50,0.01);

B = hslider("v:[2]config3/brightness[style:knob]", 0.5, 0, 1, 0.01);// 0-1
t60 = hslider("v:[2]config3/decaytime_T60[style:knob]", 10, 0, 10, 0.01);  // -60db decay time (sec)
resfact = hslider("v:[2]config3/resfact[style:knob]", 0.03, 0, 1, 0.01);
ppOffset = hslider("v:[2]config3/ppOffset[style:knob]", 48, 0, 100, 0.1);
ppRange = hslider("v:[2]config3/ppRange[style:knob]", 18, 0, 36, 0.1);

bfQ1 = hslider("v:[2]config3/bfQ1[style:knob]",5,0.3,20,0.01);
bfQ2 = hslider("v:[2]config3/bfQ2[style:knob]",8,0.3,20,0.01);
bfQ3 = hslider("v:[2]config3/bfQ3[style:knob]",8,0.3,20,0.01);
bflevel = hslider("v:[2]config3/bflevel[style:knob]",6,0.1,20,0.01);

// Takes raw data as input, and outputs pretty sound waves.
voice(note,pres,vpres,but_x,but_y1) = fullsound(level)
with {
    realVpres = vpres * 0.9;
    scaled_pres = easeInOutSine(realPres);
    freq = note2freq(note);
    fullsound(ampl) = ampl <: (_, tamborGen(scaled_pres, realVpres, freq, y)) :  *;

    timeSincePressureChange = (ba.time - time_changed(realVpres)) / ma.SR;
    y = but_y1; // : LPF(K_f0(20),0.71) : min(0.99);
    realPres = ba.if((timeSincePressureChange > 0.5) & (vpres == 0), 0, pres);

    ampl_res = (scaled_pres, realVpres) : get_amplitude ;
    level = ampl_res : LPF(K_f0(20),0.71) : min(0.99);
};

double_phasor(wave_in) = ba.tabulate(0, helper, 1000, 0, 1, wave_in).lin with {
    helper(wave) = (wave * 2) % 1;
};
phas_to_tri(phasor) = ba.tabulate(0, helper, 500, 0, 1, phasor).lin with {
    helper(phasor_in) = ba.if(phasor_in < 0.5, phasor_in * 4 - 1, (1 - phasor_in) * 4 - 1);
};
phas_to_saw(phasor) = ba.tabulate(0, helper, 500, 0, 1, phasor).lin with {
    helper(phasor_in) = (phasor_in * 2) - 1;
};
phas_to_sin(phasor) = ba.tabulate(0, helper, 500, 0, 1, phasor).lin with {
    helper(phasor_in) = sin(phasor_in * ma.PI * 2);
};


// Determines the shape of the sound waves.
tamborGen(pres, realVpres, freq, y, amp, state) = wave with {
    quarter = os.phasor(1, freq/4);
    half = os.phasor(1, freq/2);
    full = os.phasor(1, freq); 
    double = os.phasor(1, freq * 2);
    ampdiff = pres - amp;
    scale_y = easeInOutSine(y);

    // Naturalizer
    white_note = no.noise : BPF(freq * (0.05/750), 102);
    white_amp = ((1-pres) * 0.3) + ba.if(scale_y > 0, y, 0);

    sinWave = phas_to_sin(full);
    triWave = phas_to_tri(full);
    sawWave = phas_to_saw(full);
    percent_saw = min(1, 0.15 + max(min(ampdiff * 3, 0.3), -0.2));
    percent_triangle = (1 - percent_saw);
    tri_saw_wave = (triWave * percent_triangle) + (sawWave * percent_saw);
    formed_wave = ba.if(scale_y > 0, (tri_saw_wave * (1-scale_y)) + (sinWave * scale_y), tri_saw_wave);
    base_wave = (formed_wave * (1 - white_amp)) + (white_note * white_amp);

    lower_harms = (phas_to_tri(quarter) * 0.33) + (phas_to_tri(half) * 0.67);
    wave_up1 = os.saw2(freq * ba.cent2ratio(23));
    wave_dn1 = os.saw2(freq * ba.cent2ratio(-23));
    lower = lower_harms;
    lower_amp = ba.if(freq >= 80, 0.1, 0) * scale_y;



    // Sidebands to give a cycle effect when
    //  playing chords.
    down_ocatve = phas_to_tri(half);
    up_octave = phas_to_tri(double);
    side_bands = ba.if(scale_y<0, (down_ocatve * 0.5) + (up_octave * 0.5), ((down_ocatve * 0.5) + (up_octave * 0.5)) * (1-(scale_y)));

    harmonic = ((wave_up1 * 0.5) + (wave_dn1 * 0.5));
    // consider easing function for y.
    // consider overdrive on pressure.
    harmonic_amp =  min(0.8, max(0.0, 0.05 + (-1 * (ba.if(scale_y < 0, scale_y / 2, scale_y))) + max(-0.75, ampdiff)));
    side_bands_amp = max(0, (ampdiff - harmonic_amp) - lower_amp - 0.5);
    base = base_wave;
    base_wave_amp = ((1.0 - harmonic_amp) - lower_amp) - side_bands_amp; // - white;
    wave = (base * base_wave_amp) + (harmonic * harmonic_amp) + (lower * lower_amp) + (side_bands_amp * side_bands);
//    wave = white_amp * white_note; //(base * base_wave_amp) + (harmonic * harmonic_amp) + (lower * lower_amp) + (side_bands_amp * side_bands);
};

// States for the state machine
//  that controls the amplitude.
INIT = 0;
ATTACK = 1;
DECAY = 2;
RELEASE = 3;
SUSTAIN_INCR = 4;
SUSTAIN_DECR = 5;
PLUCK = 6;

// When the y axis is toward the center,
//  lean towards the center curve.
ATTACK_T = 0.1 * ma.SR;
DECAY_T = 0.4 * ma.SR;
RELEASE_T = 0.15 * ma.SR;
SUSTAIN_T = 0.2 * ma.SR;
PLUCK_T = 1.0 * ma.SR;

// How much attack goes over the target.
VEL_INC_MOD = 0.4;
VEL_DEC_MOD = 3.5;

// When to go from Decay to Release
RELEASE_THRESHOLD = 0.003;

get_state(prev_state, time_since, pressure, max_pressure, min_velocity, max_velocity, amplitude) = next_state with {
    // State transitions.
    from_init = ba.if((pressure > RELEASE_THRESHOLD), ATTACK, INIT);
    from_attack = ba.if(amplitude >= min(max_velocity + min_velocity, 1.0), ba.if(pressure <= RELEASE_THRESHOLD, PLUCK, DECAY), ATTACK);
    from_decay = ba.if(pressure <= RELEASE_THRESHOLD, PLUCK, ba.if(pressure >= amplitude, SUSTAIN_INCR, DECAY));
    from_sustain_incr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure <= amplitude, SUSTAIN_DECR, SUSTAIN_INCR));
    from_sustain_decr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure >= amplitude, SUSTAIN_INCR, SUSTAIN_DECR));
    from_release = ba.if((pressure <= RELEASE_THRESHOLD) & (amplitude <= 0.001), INIT, ba.if(pressure > RELEASE_THRESHOLD, ATTACK, RELEASE));
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


amp_range(st,pres,amp) = (st, pres, amp) : range_rec ~ (_, _, _)  with { 
    range_rec(prev_state, prev_min, prev_max, cur_state, cur_pres, cur_amp) = (cur_state, new_min, new_max) with {
        new_min = ba.if(cur_state==INIT, cur_pres, ba.if(prev_state == cur_state, min(min(prev_min, cur_pres),cur_amp), min(cur_pres, cur_amp)));
        new_max = ba.if(cur_state==INIT, cur_pres, ba.if(prev_state == cur_state, max(max(prev_max, cur_pres),cur_amp), max(cur_pres, cur_amp)));
    };
};

// Indicates the tick when the state began.
time_changed(state) = ba.time : ba.latch(state != state');

// hold min/max velocity since first pressed.
get_pos_velocity_abs(velocity, pressure) = velocity : ba.peakhold(((pressure <= RELEASE_THRESHOLD) | (pressure' >= RELEASE_THRESHOLD)));
get_neg_velocity_abs(velocity, pressure) = get_pos_velocity_abs(-1 * velocity, pressure);

// get the maximum value since the state changed.
max_since_state_change(state, val) = val : ba.peakhold(state != state');

sinScaler(vin) = (1 - cos(vin * 0.5 * ma.PI)) * ma.signum(vin);

// select from 3 values based on the depth from -1 to 1
//  giving a percentage of the value between them so that
//  -1 gives the first value,
//   0 gives the middle value,
//   1 gives the last value
//   values between those will give a percentage depending on how
//   close they are to each.
percentSelect3(depth, left, center, right) = val with {
    dist_from_zero = abs(depth);
    dist_from_one = 1 - dist_from_zero;

    val = select3(ma.signum(depth) + 1, left, center, right) * dist_from_zero + center * dist_from_one; 
};

// Get the amplitude based on the current state.
get_amplitude(amp_in, vpres) = (amp_in) : (get_amplitude_rec ~ (_, _)) : (!, _) with {
    min_velocity = get_neg_velocity_abs(vpres, amp_in) : min(1, _);
    max_velocity = get_pos_velocity_abs(vpres, amp_in) : min(1, _);
    get_amplitude_rec(prev_state, prev_amp, pressure) = (new_state, amplitude) with {
        pressures = amp_range(prev_state, pressure, prev_amp);
        min_pressure = pressures : (!, _, !);
        max_pressure = pressures : (!, !, _);
        start_time = time_changed(prev_state);
        time_since = (ba.time - start_time);
        full_pressure = max_pressure;
        time_base = get_time_base(new_state, min_velocity, max_velocity);

        amplitude = calculate_curve(prev_state, pressure, min_velocity, max_velocity, time_base, max_pressure, time_since);
        new_state = get_state(prev_state, time_since, pressure, max_pressure, min_velocity, max_velocity, prev_amp);
    };
};

get_time_base(state, min_velocity, max_velocity) = time_base with {
    vel_diff = max_velocity + min_velocity;
    multiplier = ba.selectn(7, state, 0, ATTACK_T, DECAY_T, RELEASE_T, SUSTAIN_T, SUSTAIN_T, PLUCK_T);
    time_base = multiplier; 
};

calculate_curve(state, pressure, min_velocity, max_velocity, time_base, max_pressure, time_since) = curve_res with {
    vel_diff = max_velocity + min_velocity;
    rel_target = release_decay_rate(ba.if(time_base > 0, time_since/time_base, 0));

    target = ba.if(state == ATTACK, min(1, vel_diff), 
                ba.if(state == INIT, 0.0,
                    ba.if(state == PLUCK, rel_target * vel_diff,
                        ba.if(state == RELEASE, rel_target * max_pressure, pressure))));
    ramp_time = ba.if(state == INIT, 0.0001,
                    ba.if((state == RELEASE)|(state == PLUCK), time_base/21, time_base));
    curve_res = ba.ramp(ramp_time, target);
};

release_decay_rate(x_in) = ba.tabulate(0, helper, 21, 0, 1, x_in).lin with {
    helper(x) = y with {
        y = ba.selectn(21, int(x * 21), 1, 0.86, 0.74, 0.64, 0.55, 0.47, 0.40, 0.35, 0.30, 0.26, 0.22, 0.19, 0.16, 0.14, 0.12, 0.10, 0.08, 0.06, 0.03, 0.01, 0);
    };
};

lock_max_abs(threshold, hold_time, val) = peak with {
    pos_time = ba.if(val < (-threshold), 0, hold_time);
    neg_time = ba.if(val > threshold, 0, hold_time);
    pos_peak = ba.peakholder(ma.SR * pos_time, max(0, val));
    neg_peak = ba.peakholder(ma.SR * neg_time, min(0, val) * -1);
    peak = ba.if(pos_peak > neg_peak, pos_peak, -neg_peak);
};

//process = (amp_in, throttle_in) : (_, hold_max_abs(0.01, RELEASE_PLUCK)) : get_amplitude;

controlRate(note, pres, vpres, but_x, but_y) = (note, presC, vpresC, but_xC, but_yC) with {
    presC = pres;
    vpresC = ba.ramp(ma.SR/10, vpres);
    but_xC = but_x;
    but_yC = ba.ramp(ma.SR/10, but_y);
};

// Use tabulate to create a table of values for the curve.
easeInOutSine(x_in) = ba.tabulate(0, helper, 1000, -1, 1, x_in).val with {
    helper(x) = y with {
        y = (cos(ma.PI * x) - 1) / -2 * ma.signum(x);
    };
};

easeOutCirc(x) = y with {
    y = sqrt(1 - ((x - 1)^2));
};

easeOutExpo(x) = y with {
    y = ba.if(x >= 1, 1, 1 - (2^(-10 * x)));
};

process = hgroup("strisy",
        sum(n, voicecount, vgroup("v%n", (note,pres,vpres,but_x,but_y)) : voice) // : vgroup("v%n", vmeter))
        * 1.37 : HPF(K_f0(80),1.31) );

/*
There's still a problem with buttons sticking under some conditions, I haven't
been able to make it consistent.

Trying to use statelock on vpres to see if I can solve it that way.
*/