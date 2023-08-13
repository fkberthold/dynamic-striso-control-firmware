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

voice(note,pres,vpres,but_x,but_y1) = vosc <: filt, filt2, bfs * bflevel :> _ * level
with {
    even_harm = (acc_x+1)/2;
    freq = note2freq(note);
    vosc = osc_white(freq);
    resetni = abs(note-note')<1.0;

//    but_y = but_y1 : LPF(K_f0(20),0.71);
    pluck = but_y^2 : envdecay(select2(pres==0, halftime2fac_fast(0.01), 1));
    // decaytime = max(max(min(pluck * 2 - 0.4, 0.5+pluck), min(pres * 16, 0.5+pres)), 0.05) * 64 / note;
    decaytime = max(min(pres * 16, 0.5+pres*0.5), pedal * 0.2 + 0.01) * 64 / note;
    vpres1 = max(vpres - 0.02, 0);
    vplev = vpres1 / (0.5+vpres1);// + min(pres, 0.001);
    rotlev = min(pres * 2, max(rot_y^2+rot_z^2 - 0.005, 0));
    but_y = but_y1 : LPF(K_f0(20),0.71) : (_ * 0.5 + 0.5);
//    level = (pres, but_y1) : get_amplitude : select_easing(but_y1) : LPF(K_f0(20),0.71);
    level = (pres, but_y1) : get_amplitude : ease_in_out_quad : LPF(K_f0(20),0.71);

    vdacc = min(acc_abs,2):envdecay(accDecay);
    // K = K_f0(max(freq,minFreq)) + filtFF*(level*(1-max(-but_y,0))+max(vdacc-1,0))^2^2;
    // filt = LPF(K, filtQ+max(-but_y,0)*8) * (1-max(-but_y,0)/2)^2;
    f = min(max(freq,minFreq) * (1 + filtFF*(level*(1-max(-but_y,0))+max(vdacc-1,0))^2), 16000);
    filt = fi.svf.lp(f, filtQ+max(-but_y,0)*8) * (1-max(-but_y,0)/2)^2;

    filt2lev = max(but_y,0) * but_y * pres;
    // filt2 = BPF(K_f0(filt2Freq*filt2lev+minFreq), filt2Q) * filt2level * filt2lev;
    filt2 = fi.svf.bp(filt2Freq*filt2lev+minFreq, filt2Q) * filt2level * filt2lev;

    K1 = select2(rot_y>0, K_f0(900), K_f0(1700)) * (1+0.5*abs(rot_y));
    b1 = BPF(K1, bfQ1) * abs(rot_y);
    K2 = select2(rot_x>0, K_f0(300), K_f0(600)) * (1+0.5*abs(rot_x));
    b2 = BPF(K2, bfQ2) * abs(rot_x);
    K3 = select2(rot_z>0, K_f0(1300), K_f0(2600)) * (1+0.5*abs(rot_z));
    b3 = BPF(K3, bfQ3) * abs(rot_z);
    bfs = _ <: b1, b2, b3 :> _;


};


voice_sine(note,pres,vpres,but_x,but_y) = vosc * level
with {
    pitchbend = but_x^3;
    freq = note2freq(note+pitchbend*bendRange);
    vosc = os.oscw(freq);
    level = pres : LPF(K_f0(20),1);
};


seed = 1034790774; // no. 62351 in sequence
impulse = _ ~ (_ == 0);
RANDMAX = 2147483647.0;

myrandom = ffunction(int rand_hoaglin (), "fastpow.h", "");

mynoise = myrandom / RANDMAX;

// offset to improve spectral shape
o = 0;//320;//int(hslider("v:[2]config3/offset[style:knob]", 0, 0, 1<<11, 1));
osc_white1(freq) = s1 + d * (s2 - s1)
with {
    tablesize = 1 << 12; // enough for notes as low as 11 Hz
    whitetable = rdtable(tablesize, mynoise*2);
    periodf = float(SR)/freq;
    period = int(min(periodf * 0.5, tablesize));
    inc = period/periodf;
    loop = _ <: _,((_ > period) * period) :> -;
    phase = inc : (+ : loop) ~ _;
    s1 = whitetable(o + int(phase));
    s2 = whitetable(o + ((int(phase)+1) % int(period)));
    d = dotpart(phase);
};

// osc_white = os.saw2;
osc_white = osc_white1;

// white oscilator test to reduce clicks on frequency change
inco = hslider("v:[2]config3/inc[style:knob]", 1, 0, 2, 0.01);
osc_white2(freq) = s1 + d * (s2 - s1)
with {
    tablesize = 1 << 12; // enough for notes as low as 11 Hz
    whitetable = rdtable(tablesize, mynoise*2);
    periodf = float(SR)/freq;
    inc = inco;
    period = periodf*inc;
    loop = _ <: _,((_ > period) * period) :> -;
    phase = inc : (+ : loop) ~ _;
    s1 = whitetable(o + int(phase));
    s2 = whitetable(o + ((int(phase)+1) % int(period)));
    jump = phase > int(period);
    d = select2(jump, dotpart(phase), dotpart(phase) / dotpart(period));
    //d = dotpart(phase) * 1.0/dotpart(period);
};

// Body Filter
bodyFilter = _ <: _ * .7,LPF(K_f0(bodyFreq),0.3) * 2 :> _;

vmeter(x) = attach(x, envelop(x) : vbargraph("[2]level", 0, 1));
envelop = abs : max ~ -(20.0/SR);


/*
 * NEW CODE
 */

INIT = 0;
ATTACK = 1;
DECAY = 2;
SUSTAIN = 3;
RELEASE = 4;
QUICK_RELEASE = 5;

DECR = 0;
INCR = 1;
NEG = 0;
POS = 1;

// The time to remain in each state
ATTACK_TIME = ATTACK_CENTER * ma.SR;
DECAY_TIME = DECAY_CENTER * ma.SR;
RELEASE_TIME = RELEASE_CENTER * ma.SR;
SUSTAIN_TIME = SUSTAIN_CENTER * ma.SR; // This dictates how long it takes values to change while in sustain.
QUICK_RELEASE_TIME = QUICK_CENTER * ma.SR;
ATTACK_MOD = ATTACK_MOD_CENTER;

ATTACK_TEST = 1.1;
DECAY_TEST = 1.2;
RELEASE_TEST = 5.4;
SUSTAIN_TEST = 0.1;
QUICK_TEST = 0.2;

ATTACK_PLUCK = 0.19;
DECAY_PLUCK = 0.10;
RELEASE_PLUCK = 1.0;
SUSTAIN_PLUCK = 0.3;
QUICK_PLUCK = 0.01;

ATTACK_CENTER = 0.1;
DECAY_CENTER = 0.2;
RELEASE_CENTER = 0.35;
SUSTAIN_CENTER = 0.1;
QUICK_CENTER = 0.01;

ATTACK_FAST = 0.01;
DECAY_FAST = 0.01;
RELEASE_FAST = 0.01;
SUSTAIN_FAST = 0.01;
QUICK_FAST = 0.01;

// How much attack goes over the target.
ATTACK_MOD_PLUCK = 1.7;
ATTACK_MOD_CENTER = 1.2;
ATTACK_MOD_FAST = 1.0;

// When to go from Decay to Release
RELEASE_THRESHOLD = 0.05;

get_state(prev_state, time_since, pressure, amplitude) = next_state with {
    // State transitions.
    from_init = ba.if(pressure >= RELEASE_THRESHOLD, ATTACK, INIT);
    from_attack = ba.if(time_since >= ATTACK_TIME, DECAY, ATTACK);
    from_decay = ba.if((time_since >= DECAY_TIME) | (pressure > amplitude), SUSTAIN, ba.if(pressure <= RELEASE_THRESHOLD, RELEASE, DECAY));
    from_sustain = ba.if(pressure < amplitude, DECAY, ba.if(pressure > amplitude, ATTACK, SUSTAIN));
    from_release = ba.if((pressure <= 0) & (amplitude <= 0), INIT, ba.if(pressure > amplitude, QUICK_RELEASE, RELEASE));
    from_quick_release = ba.if(time_since >= QUICK_RELEASE_TIME, INIT, QUICK_RELEASE);

    next_state = ba.if(prev_state==INIT, from_init,
                 ba.if(prev_state==ATTACK, from_attack,
                 ba.if(prev_state==DECAY, from_decay,
                 ba.if(prev_state==SUSTAIN, from_sustain,
                 ba.if(prev_state==RELEASE, from_release, from_quick_release)))));
};

direction(prev_val, cur_val) = dir with {
    dir = ba.if(cur_val > prev_val, POS, ba.if(cur_val < prev_val, NEG, dir));
};

inflection(prev_dir, cur_dir) = inflect with {
    inflect = ba.if(prev_dir != cur_dir, 1, 0);
};

attack_curve(pressure, min_pressure, max_pressure, time_since) = new_amp with {
    new_amp = min(max_pressure, min_pressure + ((max_pressure - min_pressure) * (time_since / ATTACK_TIME)));
};

decay_curve(pressure, min_pressure, max_pressure, time_since) = new_amp with {
    new_amp = max(min_pressure, min_pressure + ((max_pressure - min_pressure) * (1 - (time_since / DECAY_TIME))));
};

release_curve(pressure, min_pressure, max_pressure, time_since) = new_amp with {
    new_amp = max(0, max_pressure * (1 - (time_since / RELEASE_TIME)));
};

quick_release_curve(pressure, min_pressure, max_pressure, time_since) = new_amp with {
    new_amp = max(0, max_pressure * (1 - (time_since / QUICK_RELEASE_TIME)));
};

amp_range(st,pres,amp) = (st, pres, amp) : range_rec ~ (_, _, _)  with {
    range_rec(prev_state, prev_min, prev_max, cur_state, cur_pres, cur_amp) = (cur_state, new_min, new_max) with {
        attack_pres = cur_pres * ATTACK_MOD;
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

get_amplitude = (get_amplitude_rec ~ (_, _)) : (!, _) with {
    get_amplitude_rec(prev_state, prev_amp, pressure, throttle) = (new_state, amplitude) with {
        pressures = amp_range(prev_state, pressure, prev_amp);
        min_pressure = pressures : (!, _, !) : hbargraph("min_bg", 0, 1);
        max_pressure = pressures : (!, !, _) : hbargraph("max_bg", 0, 1);
        start_time = time_changed(prev_state);
        time_since = (ba.time - start_time);
        full_pressure = max_pressure;

        amplitude = ba.selectn(6, prev_state, 0,
                                    attack_curve(pressure, min_pressure, full_pressure, time_since),
                                    decay_curve(pressure, min_pressure, full_pressure, time_since),
                                    pressure,
                                    release_curve(pressure, min_pressure, full_pressure, time_since),
                                    quick_release_curve(pressure, min_pressure, full_pressure, time_since));
        
        new_state = get_state(prev_state, time_since, pressure, prev_amp);
    };
};


hold_max_abs(val_in, threshold, hold_time) = (val_in, ba.time) : (hold_max_abs_rec ~ (_, _)) : (_, !) with {
    hold_max_abs_rec(prev_val, prev_time, cur_val, cur_time) = (new_val, new_time) with {
        new_val = ba.if(abs(cur_val) > abs(prev_val), cur_val, 
                        ba.if((cur_val * prev_val < 0) & (abs(cur_val) > threshold), cur_val,
                            ba.if(ba.time < prev_time + hold_time, cur_val, prev_val)));
        new_time = ba.if(new_val == cur_val, cur_time, ba.time);
    };
};

get_adsr(throttle) = (get_adsr_rec ~ (_, _)) : (!, _) with {
    get_adsr_rec(prev_state, prev_amp, pressure, throttle) = (new_state, amplitude) with {
        pressures = amp_range(prev_state, pressure, prev_amp);
        min_pressure = pressures : (!, _, !) : hbargraph("min_bg", 0, 1);
        max_pressure = pressures : (!, !, _) : hbargraph("max_bg", 0, 1);
        start_time = time_changed(prev_state);
        time_since = (ba.time - start_time);
        full_pressure = max_pressure;

        amplitude = ba.selectn(6, prev_state, 0,
                                    attack_curve(pressure, min_pressure, full_pressure, time_since),
                                    decay_curve(pressure, min_pressure, full_pressure, time_since),
                                    pressure,
                                    release_curve(pressure, min_pressure, full_pressure, time_since),
                                    quick_release_curve(pressure, min_pressure, full_pressure, time_since));
        
        new_state = get_state(prev_state, time_since, pressure, prev_amp);
    };
};

// Cubic Ease Out
ease_out_cubic(t) = 1 - (1-t)^3;

// Quad Ease In Out
ease_in_out_quad(t) = ba.if(t < 0.5, 2*t*t, 1 - pow(-2*t + 2, 2)/2);

// Average the easing function between
//  negative and positive throttle.
//  postive throttle is linear
//  negative throttle is ease out cubic
//  0 throttle is ease in out quad
select_easing(throttle, pressure) = out_value with {
    dist_from_zero = abs(throttle);
    dist_from_one = 1 - dist_from_zero;
    zero_case = ease_in_out_quad(pressure);
    negative_case = ease_out_cubic(pressure) * dist_from_one + ease_out_cubic(pressure) * dist_from_zero;
    positive_case = pressure * dist_from_one + ease_in_out_quad(pressure) * dist_from_zero;
    out_value = ba.if(throttle < 0, negative_case, ba.if(throttle > 0, positive_case, zero_case));
}; 

process = hgroup("strisy",
        sum(n, voicecount, vgroup("v%n", (note,pres,vpres,but_x,but_y)) : voice) // : vgroup("v%n", vmeter))
        * 1.37 : HPF(K_f0(80),1.31) );


/*
Amp curve depends on y-axis and does not stick.

Have a speed of shift for sustain too, instead of doing a new attack & decay
*/
