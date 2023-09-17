//----------------------------------------------------------
// name: "synth.dsp.tmp"
//
// Code generated with Faust 2.60.3 (https://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>

extern "C" {
    #include "ch.h"
    #include "hal.h"
    #include "synth.h"
}

#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)

#define MAX_VAL (1<<23)
#define VOLUME_FILTER 0.99f

class dsp {
	protected:
		int fSamplingFreq;
};

struct Meta {
    virtual void declare(const char* key, const char* value) = 0;
};

// variables
synth_interface_t synth_interface;

static float dump;
float volume = 1.0f;

static int32_t *outbuf;
static int32_t *inbuf;
static float output0[CHANNEL_BUFFER_SIZE] = {0.0};
static float output1[CHANNEL_BUFFER_SIZE] = {0.0};
static float* output[2] = {output0, output1};

// Intrinsics

// Class
#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

class mydsp : public dsp {
  private:
	class SIG0 {
	  private:
		int fSampleRate;
		int 	iVec0[2];
		int 	iRec0[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iVec0[i] = 0;
			for (int i=0; i<2; i++) iRec0[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iVec0[0] = 1;
				iRec0[0] = ((iVec0[1] + iRec0[1]) % 65536);
				output[i] = sinf((9.58738e-05f * float(iRec0[0])));
				// post processing
				iRec0[1] = iRec0[0];
				iVec0[1] = iVec0[0];
			}
		}
	};


	static float 	ftbl0[65536];
	int 	iVec1[2];
	FAUSTFLOAT 	fslider0;
	float 	fConst0;
	float 	fRec1[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	float 	fRec2[2];
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fRec3[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	float 	fRec4[2];
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fslider8;
	float 	fRec5[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	float 	fRec6[2];
	FAUSTFLOAT 	fslider11;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.10.0");
		m->declare("filename", "synth.dsp.tmp");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.6.0");
		m->declare("name", "synth.dsp.tmp");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate) {
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(65536,ftbl0);
	}
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = (1e+03f / min(1.92e+05f, max(1.0f, float(fSampleRate))));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		fslider3 = 0.0f;
		fslider4 = 0.0f;
		fslider5 = 0.0f;
		fslider6 = 0.0f;
		fslider7 = 0.0f;
		fslider8 = 0.0f;
		fslider9 = 0.0f;
		fslider10 = 0.0f;
		fslider11 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec1[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
	}
	virtual void init(int sample_rate) {
		classInit(sample_rate);
		instanceInit(sample_rate);
	}
	virtual void instanceInit(int sample_rate) {
		instanceConstants(sample_rate);
		instanceResetUserInterface();
		instanceClear();
	}

	virtual int getSampleRate() {
		return fSampleRate;
	}
	virtual void buildUserInterfaceEmbedded() {
		synth_interface.pres[0] = &fslider11;
		synth_interface.vpres[0] = &fslider10;
		synth_interface.pres[1] = &fslider9;
		synth_interface.vpres[1] = &fslider8;
		synth_interface.pres[2] = &fslider7;
		synth_interface.vpres[2] = &fslider6;
		synth_interface.pres[3] = &fslider5;
		synth_interface.vpres[3] = &fslider4;
		synth_interface.pres[4] = &fslider3;
		synth_interface.vpres[4] = &fslider2;
		synth_interface.pres[5] = &fslider1;
		synth_interface.vpres[5] = &fslider0;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = (fConst0 * (float(fslider0) + 1.0f));
		float 	fSlow1 = float((float(fslider1) >= 0.01f));
		float 	fSlow2 = (fConst0 * (float(fslider2) + 1.0f));
		float 	fSlow3 = float((float(fslider3) >= 0.01f));
		float 	fSlow4 = (fConst0 * (float(fslider4) + 1.0f));
		float 	fSlow5 = float((float(fslider5) >= 0.01f));
		float 	fSlow6 = (fConst0 * (float(fslider6) + 1.0f));
		float 	fSlow7 = float((float(fslider7) >= 0.01f));
		float 	fSlow8 = (fConst0 * (float(fslider8) + 1.0f));
		float 	fSlow9 = float((float(fslider9) >= 0.01f));
		float 	fSlow10 = (fConst0 * (float(fslider10) + 1.0f));
		float 	fSlow11 = float((float(fslider11) >= 0.01f));
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec1[0] = 1;
			int 	iTemp0 = (1 - iVec1[1]);
			float 	fTemp1 = ((iTemp0) ? 0.0f : (fSlow0 + fRec1[1]));
			fRec1[0] = (fTemp1 - floorf(fTemp1));
			float 	fTemp2 = ((iTemp0) ? 0.0f : (fSlow2 + fRec2[1]));
			fRec2[0] = (fTemp2 - floorf(fTemp2));
			float 	fTemp3 = ((iTemp0) ? 0.0f : (fSlow4 + fRec3[1]));
			fRec3[0] = (fTemp3 - floorf(fTemp3));
			float 	fTemp4 = ((iTemp0) ? 0.0f : (fSlow6 + fRec4[1]));
			fRec4[0] = (fTemp4 - floorf(fTemp4));
			float 	fTemp5 = ((iTemp0) ? 0.0f : (fSlow8 + fRec5[1]));
			fRec5[0] = (fTemp5 - floorf(fTemp5));
			float 	fTemp6 = ((iTemp0) ? 0.0f : (fSlow10 + fRec6[1]));
			fRec6[0] = (fTemp6 - floorf(fTemp6));
			output0[i] = (FAUSTFLOAT)(((((((fSlow11 * ftbl0[max(0, min(int((65536.0f * fRec6[0])), 65535))]) + (fSlow9 * ftbl0[max(0, min(int((65536.0f * fRec5[0])), 65535))])) + (fSlow7 * ftbl0[max(0, min(int((65536.0f * fRec4[0])), 65535))])) + (fSlow5 * ftbl0[max(0, min(int((65536.0f * fRec3[0])), 65535))])) + (fSlow3 * ftbl0[max(0, min(int((65536.0f * fRec2[0])), 65535))])) + (fSlow1 * ftbl0[max(0, min(int((65536.0f * fRec1[0])), 65535))])));
			// post processing
			fRec6[1] = fRec6[0];
			fRec5[1] = fRec5[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			fRec1[1] = fRec1[0];
			iVec1[1] = iVec1[0];
		}
	}
};


float 	mydsp::ftbl0[65536];

FAUSTCLASS dsp;

static THD_WORKING_AREA(waSynthThread, 1024);
static thread_t* pThreadDSP = 0;
static void synthThread(void *arg) {  // THE SYNTH THREAD
	(void)arg;
	chRegSetThreadName("SYNTH");

	int32_t tmp;
	int count = CHANNEL_BUFFER_SIZE;
	float volume_filtered = 0.0f;

	//codec_pwrCtl(1);    // POWER ON
	//codec_muteCtl(0);   // MUTE OFF

	chEvtAddEvents(1);

	// initialize interface with dump, for when controls are not used
	synth_interface.acc_abs = &dump;
	synth_interface.acc_x = &dump;
	synth_interface.acc_y = &dump;
	synth_interface.acc_z = &dump;
	synth_interface.rot_x = &dump;
	synth_interface.rot_y = &dump;
	synth_interface.rot_z = &dump;
	synth_interface.pedal = &dump;

	// initialization
	dsp.init(SAMPLINGFREQ);

	// initialize interface
	dsp.buildUserInterfaceEmbedded();

	// computation loop
	while (true) {
		// palClearLine(LINE_LED_ALT);
		chEvtWaitOne(1);
		// palSetLine(LINE_LED_ALT);

		dsp.compute(count, NULL, output);

		volume_filtered = VOLUME_FILTER * volume_filtered + (1 - VOLUME_FILTER) * volume;

		// convert float to int with scale, clamp and round
		for (int n = 0; n < CHANNEL_BUFFER_SIZE; n++) {
			tmp = (int32_t)(output0[n] * volume_filtered * MAX_VAL);
			// enable LED on clip
			if (tmp <= -MAX_VAL) {
				tmp = -(MAX_VAL-1);
			} else if (tmp >= MAX_VAL) {
				tmp = MAX_VAL-1;
			}
			// make both audio channels the same
			outbuf[2*n] = outbuf[2*n+1] = tmp * (1<<8);
		}

		//if (--n <= 0) {
		//	palToggleLine(LINE_LED1);       /* Orange.  */
		//	n = 100;
		//}

		// TODO: synth_tick better called here or in main?
		// synth_tick();

		if (chThdShouldTerminateX()) break;
	}

	//codec_muteCtl(1);
	//codec_pwrCtl(0);

	pThreadDSP=NULL;
	palToggleLine(LINE_LED1);
};

void start_synth_thread(void) {
	pThreadDSP = chThdCreateStatic(waSynthThread, sizeof(waSynthThread), NORMALPRIO+2, synthThread, NULL);
}

void computebufI(int32_t *inp, int32_t *outp) {
  int i;
  //for (i = 0; i < 32; i++) {
  //  inbuf[i] = inp[i];
  //}
  outbuf = outp;
  inbuf = inp;
  if (pThreadDSP) {
    chSysLockFromISR();
    chEvtSignalI(pThreadDSP, (eventmask_t)1);
    chSysUnlockFromISR();
  }
  else
    for (i = 0; i < PLAYBACK_BUFFER_SIZE; i++) {
      outp[i] = (i - PLAYBACK_BUFFER_SIZE / 2) * 1<<22;
      // square wave 34952 * (1<<8) * 2 * ((i>PLAYBACK_BUFFER_SIZE/2)-0.5);
      // saw ware (i - PLAYBACK_BUFFER_SIZE / 2) * 100000; // testing noise 0;
    }
}
