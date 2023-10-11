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

voice(note,pres,vpres,but_x,but_y1) = level * os.osc(freq)
with {
    freq = note2freq(note);
    vosc = varOsc(pres, level, freq);

    throttle = ramp_max_abs(0.2, 1.0, min(but_y1 * 2, 1.0));
    level = (pres, vpres, throttle) : get_amplitude : LPF(K_f0(20),0.71) : min(0.95) ;
};

varOsc(pres, amp, freq) = wave with {
    diff = pres - amp;
    percent_saw = 0.25 + max(min(diff * 3, 0.3), -0.15);
    precent_triangle = (1 - diff);
    wave = (os.triangle(freq) * precent_triangle) + (os.saw2(freq) * percent_saw); 
};

/*
 * NEW CODE
 */

INIT = 0;
ATTACK = 1;
DECAY = 2;
RELEASE = 3;
QUICK_RELEASE = 4;
SUSTAIN_INCR = 5;
SUSTAIN_DECR = 6;

DECR = 0;
INCR = 1;
NEG = 0;
POS = 1;

// The time to remain in each state
//  This indicates a rate of travel, 
//  not a time to reach the target.
ATTACK_GEN = 0.05 * ma.SR;
DECAY_GEN = 0.5 * ma.SR;
RELEASE_GEN = 10.0 * ma.SR;
SUSTAIN_GEN = 1.0 * ma.SR;
QUICK_GEN = 0.01 * ma.SR;

ATTACK_PLUCK = ATTACK_GEN;
DECAY_PLUCK = DECAY_GEN;
RELEASE_PLUCK = RELEASE_GEN;
SUSTAIN_PLUCK = SUSTAIN_GEN;
QUICK_PLUCK = QUICK_GEN;

ATTACK_CENTER = ATTACK_GEN;
DECAY_CENTER = DECAY_GEN;
RELEASE_CENTER = RELEASE_GEN;
SUSTAIN_CENTER = SUSTAIN_GEN;
QUICK_CENTER = QUICK_GEN;

ATTACK_FAST = ATTACK_GEN;
DECAY_FAST = DECAY_GEN;
RELEASE_FAST = RELEASE_GEN;
SUSTAIN_FAST = SUSTAIN_GEN;
QUICK_FAST = QUICK_GEN;


/*
ATTACK_PLUCK = 0.05 * ma.SR;
DECAY_PLUCK = 5.1 * ma.SR;
RELEASE_PLUCK = 8.0 * ma.SR;
SUSTAIN_PLUCK = 2.0 * ma.SR;
QUICK_PLUCK = 0.01 * ma.SR;

ATTACK_CENTER = 0.05 * ma.SR;
DECAY_CENTER = 5.05 * ma.SR;
RELEASE_CENTER = 0.4 * ma.SR;
SUSTAIN_CENTER = 0.6 * ma.SR;
QUICK_CENTER = 0.01 * ma.SR;

ATTACK_FAST = 0.05 * ma.SR;
DECAY_FAST = 5.05 * ma.SR;
RELEASE_FAST = 0.01 * ma.SR;
SUSTAIN_FAST = 0.01 * ma.SR;
QUICK_FAST = 0.01 * ma.SR;
*/

// How much attack goes over the target.
ATTACK_MOD_PLUCK = 2.0;
ATTACK_MOD_CENTER = 2.0;
ATTACK_MOD_FAST = 2.0;

// When to go from Decay to Release
RELEASE_THRESHOLD = 0.1;

get_state(prev_state, time_since, pressure, max_pressure, max_velocity, attack_mod, amplitude) = next_state with {
    // State transitions.
    from_init = ba.if(pressure >= RELEASE_THRESHOLD, ATTACK, INIT);
    from_attack = ba.if(amplitude >= (max_velocity * attack_mod), DECAY, ATTACK);
    from_decay = ba.if(pressure >= amplitude, SUSTAIN_INCR, ba.if(pressure <= RELEASE_THRESHOLD, INIT, DECAY));
    from_sustain_incr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure <= amplitude, SUSTAIN_DECR, SUSTAIN_INCR));
    from_sustain_decr = ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, ba.if(pressure >= amplitude, SUSTAIN_INCR, SUSTAIN_DECR));
    from_release = ba.if((pressure <= 0) & (amplitude <= 0.001), INIT, ba.if(pressure > amplitude, ATTACK, RELEASE));
    from_quick_release = ba.if(amplitude <= RELEASE_THRESHOLD, INIT, QUICK_RELEASE);

    next_state = ba.selectn(7, prev_state,
                               from_init,
                               from_attack,
                               from_decay,
                               from_release,
                               from_quick_release,
                               from_sustain_incr,
                               from_sustain_decr);
};


// Returns the last state
amp_range(st,pres,amp, attack_mod) = (st, pres, amp) : range_rec ~ (_, _, _)  with { 
    range_rec(prev_state, prev_min, prev_max, cur_state, cur_pres, cur_amp) = (cur_state, new_min, new_max) with {
        attack_pres = cur_pres * attack_mod;
        new_min = ba.if(cur_state==INIT, cur_pres, ba.if(prev_state == cur_state, min(min(prev_min, cur_pres),cur_amp), min(cur_pres, cur_amp)));
        new_max = ba.if(cur_state==INIT, cur_pres, 
            ba.if(cur_state == ATTACK,
                ba.if(prev_state == cur_state, max(max(prev_max, attack_pres),cur_amp), max(attack_pres, cur_amp)),
                ba.if(prev_state == cur_state, max(max(prev_max, cur_pres),cur_amp), max(cur_pres, cur_amp))));
    };
};

// Indicates the tick when the state began.
time_changed(state) = (state, ba.time) : lock_on_state_change;

lock_on_state_change(state, val) = (state, val) : (locker~(_, _)) : (!, _) with {
    locker(prev_state, prev_val, cur_state, cur_val) = (cur_state, lock_val) with {
        lock_val = ba.if(prev_state != cur_state, cur_val, prev_val);
    };
};

// get the maximum value since the state changed.
max_since_state_change(state, val) = (state, val) : (maxer~(_, _)) : (!, _) with {
    maxer(prev_state, prev_val, cur_state, cur_val) = (cur_state, max_val) with {
        max_val = ba.if(prev_state != cur_state, cur_val, max(prev_val, cur_val));
    };
};

get_amplitude(amp_in, vpres, throttle) = (amp_in) : (get_amplitude_rec ~ (_, _)) : (!, _) with {
    get_amplitude_rec(prev_state, prev_amp, pressure) = (new_state, amplitude) with {
        pressures = amp_range(prev_state, pressure, prev_amp, attack_mod);
        min_pressure = pressures : (!, _, !);
        max_pressure = pressures : (!, !, _);
        start_time = time_changed(prev_state);
        time_since = (ba.time - start_time);
        max_vpres = max_since_state_change(prev_state, vpres);
        full_pressure = max_pressure;
        attack_mod = select3(ma.signum(throttle) + 1, ATTACK_MOD_PLUCK, ATTACK_MOD_CENTER, ATTACK_MOD_FAST);
        time_base = get_time_base(new_state, throttle);

        amplitude = calculate_curve(prev_state, pressure, max_vpres, time_base, attack_mod, max_pressure, time_since);
        new_state = get_state(prev_state, time_since, pressure, max_pressure, max_vpres, attack_mod, prev_amp);
    };
};

get_time_base(state, throttle) = time_base with {
    center = ba.selectn(7, state, 0, ATTACK_CENTER, DECAY_CENTER, RELEASE_CENTER, QUICK_CENTER, SUSTAIN_CENTER, SUSTAIN_CENTER);
    pluck = ba.selectn(7, state, 0, ATTACK_PLUCK, DECAY_PLUCK, RELEASE_PLUCK, QUICK_PLUCK, SUSTAIN_PLUCK, SUSTAIN_PLUCK);
    fast = ba.selectn(7, state, 0, ATTACK_FAST, DECAY_FAST, RELEASE_FAST, QUICK_FAST, SUSTAIN_FAST, SUSTAIN_FAST);
    dist_from_zero = abs(throttle);
    dist_from_one = 1 - dist_from_zero;

    time_base = select3(ma.signum(throttle) + 1, pluck, center, fast) * dist_from_zero + center * dist_from_one; 
};

calculate_curve(state, pressure, vpres, time_base, attack_mod, max_pressure, time_since) = curve_res with {
    rel_targets = release_decay_target(time_since, time_base);
    rel_diff = rel_targets : (_ - _);
    rel_target = rel_targets : (!, _);
    rel_ramp_time = ba.if(rel_diff > 0, (time_base / 20) * (1.0 / rel_diff), 0);

    target = ba.if(state == ATTACK, min(1, vpres * attack_mod), 
                ba.if(state == INIT, 0,
                    ba.if(state == RELEASE, rel_target * max_pressure, pressure)));
    ramp_time = ba.if(state == INIT, 0.0001,
                    ba.if(state == RELEASE, rel_ramp_time, time_base));
    curve_res = ba.ramp(ramp_time, target);
};

release_decay_target(cur_time, max_time) = prev_target, cur_target with {
    percent_total = ba.if(max_time > 0, (cur_time) / (max_time), 0) : hbargraph("percent_total", 0, 1);
    target_position = ((percent_total * 20) : floor) : hbargraph("target_pos", 0, 1);
    targets = (0.86, 0.74, 0.64, 0.55, 0.47, 0.40, 0.35, 0.30, 0.26, 0.22, 0.19, 0.16, 0.14, 0.12, 0.10, 0.08, 0.06, 0.03, 0.01, 0);
    prev_target = ba.if(target_position>0, ba.selectn(20, target_position - 1, targets), 1.0);
    cur_target = ba.selectn(20, target_position, targets);
};

ramp_max_abs(threshold, hold_time, val_in) = val_out with {
    abs_in = abs(val_in);
    same_signum(ramp_val) = (ma.signum(val_in) == ma.signum(ramp_val));

    change_rate(ramp_val) = ba.if(same_signum(ramp_val),
                                ba.if(abs_in >= abs(ramp_val), ma.SR/10,ma.SR*hold_time),
                                ba.if(abs_in >= threshold,ma.SR/10,ma.SR*hold_time));

    target_value = val_in;
    ramp_fun(cr, val) = ba.ramp(cr, val);
    val_out = val_in : ramp_fun ~ change_rate;
};


// Sharktooth wave as used by the minimoog,
//  75% triangle, 25% sawtooth
sharktooth(t) = ba.if(t < 0.75, 4*t, 4*(t-0.75));

//process = (amp_in, throttle_in) : (_, hold_max_abs(0.01, RELEASE_PLUCK)) : get_amplitude;

// HOLD MAX ABS won't work on it's own.  When it changes it will make and abrupt change in the volume,
//  I need a way to rig it to change over time, it can be a short time but it can't just flip... Can it?
//  it isn't changing something directly like easing, it's just changing how fast it's moving, so, maybe?
//  Nope. It'll drop because all those numbers are being calculated on the fly based on the curves, so it could go instantly to zero
//  not frosty.

process = hgroup("strisy",
        sum(n, voicecount, vgroup("v%n", (note,pres,vpres,but_x,but_y)) : voice) // : vgroup("v%n", vmeter))
        * 1.37 : HPF(K_f0(80),1.31) );

/*
2023/08/21
FIXED: Still having trouble getting the attack to time right. It looks like it just isn't holding long
enough.

2023/08/25
FIXED: Fix the decay, it's replacing the release if it takes too long.

2023/08/28
From conversation with weinski:
* TODO: Attack level controlled by strike velocity
* TODO: Higher attack, slower decay on high y value
* TODO: Exponential decay on release
*/