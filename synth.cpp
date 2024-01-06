//----------------------------------------------------------
// name: "synth.dsp.tmp"
//
// Code generated with Faust 2.68.1 (https://faust.grame.fr)
//----------------------------------------------------------

/* link with : "" */
#include "fastpow.h"
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
		int 	iRec1[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec1[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec1[0] = (iRec1[1] + 1);
				float 	fTemp0 = float((iRec1[0] + -1));
				float 	fTemp1 = (0.002004008f * fTemp0);
				output[i] = (((fTemp1 < 0.5f)) ? ((0.008016032f * fTemp0) + -1.0f) : ((4.0f * (1.0f - fTemp1)) + -1.0f));
				// post processing
				iRec1[1] = iRec1[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec3[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec3[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec3[0] = (iRec3[1] + 1);
				output[i] = ((0.004008016f * float((iRec3[0] + -1))) + -1.0f);
				// post processing
				iRec3[1] = iRec3[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec5[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec5[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec5[0] = (iRec5[1] + 1);
				float 	fTemp11 = ((0.002002002f * float((iRec5[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp11)) + -1.0f))) * float(((fTemp11 > 0.0f) - (fTemp11 < 0.0f))));
				// post processing
				iRec5[1] = iRec5[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec14[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec14[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec14[0] = (iRec14[1] + 1);
				int 	iTemp23 = int((1.05f * float((iRec14[0] + -1))));
				output[i] = (((iTemp23 >= 11)) ? (((iTemp23 >= 16)) ? (((iTemp23 >= 19)) ? (((iTemp23 >= 20)) ? 0.0f : 0.01f) : (((iTemp23 >= 18)) ? 0.03f : (((iTemp23 >= 17)) ? 0.06f : 0.08f))) : (((iTemp23 >= 14)) ? (((iTemp23 >= 15)) ? 0.1f : 0.12f) : (((iTemp23 >= 13)) ? 0.14f : (((iTemp23 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp23 >= 6)) ? (((iTemp23 >= 9)) ? (((iTemp23 >= 10)) ? 0.22f : 0.26f) : (((iTemp23 >= 8)) ? 0.3f : (((iTemp23 >= 7)) ? 0.35f : 0.4f))) : (((iTemp23 >= 3)) ? (((iTemp23 >= 5)) ? 0.47f : (((iTemp23 >= 4)) ? 0.55f : 0.64f)) : (((iTemp23 >= 2)) ? 0.74f : (((iTemp23 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec14[1] = iRec14[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[500];
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec2[2];
	static float 	ftbl1[500];
	float 	fConst10;
	float 	fRec4[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec10[2];
	int 	iRec9[2];
	float 	fConst11;
	float 	fVec3[2];
	float 	fRec11[2];
	float 	fRec12[2];
	int 	iRec7[3];
	static float 	ftbl3[21];
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	int 	iVec4[2];
	int 	iRec15[2];
	float 	fRec16[2];
	float 	fRec13[2];
	float 	fRec8[2];
	float 	fConst17;
	float 	fRec6[2];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	int 	iRec18[2];
	float 	fRec17[3];
	float 	fConst21;
	float 	fConst22;
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fConst23;
	float 	fRec19[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec23[2];
	float 	fRec24[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec28[2];
	float 	fVec7[2];
	float 	fRec29[2];
	float 	fRec30[2];
	int 	iRec26[3];
	int 	iVec8[2];
	int 	iRec32[2];
	float 	fRec33[2];
	float 	fRec31[2];
	float 	fRec27[2];
	float 	fRec25[2];
	float 	fRec34[3];
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec35[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec39[2];
	float 	fRec40[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec44[2];
	float 	fVec11[2];
	float 	fRec45[2];
	float 	fRec46[2];
	int 	iRec42[3];
	int 	iVec12[2];
	int 	iRec48[2];
	float 	fRec49[2];
	float 	fRec47[2];
	float 	fRec43[2];
	float 	fRec41[2];
	float 	fRec50[3];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec54[2];
	float 	fRec51[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec55[2];
	float 	fRec56[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec60[2];
	float 	fVec15[2];
	float 	fRec61[2];
	float 	fRec62[2];
	int 	iRec58[3];
	int 	iVec16[2];
	int 	iRec64[2];
	float 	fRec65[2];
	float 	fRec63[2];
	float 	fRec59[2];
	float 	fRec57[2];
	float 	fRec66[3];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec70[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec71[2];
	float 	fRec72[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec76[2];
	float 	fVec19[2];
	float 	fRec77[2];
	float 	fRec78[2];
	int 	iRec74[3];
	int 	iVec20[2];
	int 	iRec80[2];
	float 	fRec81[2];
	float 	fRec79[2];
	float 	fRec75[2];
	float 	fRec73[2];
	float 	fRec82[3];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fRec83[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec87[2];
	float 	fRec88[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec92[2];
	float 	fVec23[2];
	float 	fRec93[2];
	float 	fRec94[2];
	int 	iRec90[3];
	int 	iVec24[2];
	int 	iRec96[2];
	float 	fRec97[2];
	float 	fRec95[2];
	float 	fRec91[2];
	float 	fRec89[2];
	float 	fRec98[3];
	float 	fRec100[2];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec99[2];
	float 	fRec0[3];
	float 	fConst24;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakhold:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("basics.lib/tabulate:author", "Stephane Letz");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("fast.lib/author", "Piers Titus van der Torren (pierstitus@toverlamp.org)");
		m->declare("fast.lib/licence", "Apache-2.0");
		m->declare("fast.lib/name", "Faust Fast Approximations Library");
		m->declare("filename", "synth.dsp.tmp");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.6.0");
		m->declare("name", "synth.dsp.tmp");
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.0");
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
		sig0.fill(500,ftbl0);
		SIG1 sig1;
		sig1.init(sample_rate);
		sig1.fill(500,ftbl1);
		SIG2 sig2;
		sig2.init(sample_rate);
		sig2.fill(1000,ftbl2);
		SIG3 sig3;
		sig3.init(sample_rate);
		sig3.fill(21,ftbl3);
	}
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		float 	fConst0 = min(1.92e+05f, max(1.0f, float(fSampleRate)));
		float 	fConst1 = powf(fConst0,2.0f);
		float 	fConst2 = powf((125.663704f / fConst0),2.0f);
		float 	fConst3 = ((fConst2 * ((0.2033f * fConst2) + 0.31755f)) + 1.0f);
		fConst4 = (2.0f * ((15791.367f * (powf(fConst3,2.0f) / fConst1)) + -1.0f));
		float 	fConst5 = (15791.367f * (fConst3 / fConst0));
		fConst6 = (((fConst3 * (fConst5 + -95.92649f)) / fConst0) + 1.0f);
		float 	fConst7 = (((fConst3 * (fConst5 + 95.92649f)) / fConst0) + 1.0f);
		fConst8 = (1.0f / fConst7);
		fConst9 = (4.0878997f / fConst0);
		fConst10 = (2.0439498f / fConst0);
		fConst11 = (1.0f / fConst0);
		fConst12 = (0.1f * fConst0);
		fConst13 = (0.4f * fConst0);
		fConst14 = (0.15f * fConst0);
		fConst15 = (0.2f * fConst0);
		fConst16 = (0.75f * fConst0);
		fConst17 = (2e+01f / fConst0);
		fConst18 = (25.68503f / fConst0);
		fConst19 = (659.72076f / fConst1);
		fConst20 = (659.72076f / fConst0);
		fConst21 = (0.2568503f / fConst0);
		fConst22 = (8.175799f / fConst0);
		fConst23 = (3333.3333f / fConst0);
		fConst24 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 69.0f;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		fslider3 = 0.0f;
		fslider4 = 69.0f;
		fslider5 = 0.0f;
		fslider6 = 0.0f;
		fslider7 = 0.0f;
		fslider8 = 69.0f;
		fslider9 = 0.0f;
		fslider10 = 0.0f;
		fslider11 = 0.0f;
		fslider12 = 69.0f;
		fslider13 = 0.0f;
		fslider14 = 0.0f;
		fslider15 = 0.0f;
		fslider16 = 69.0f;
		fslider17 = 0.0f;
		fslider18 = 0.0f;
		fslider19 = 0.0f;
		fslider20 = 69.0f;
		fslider21 = 0.0f;
		fslider22 = 0.0f;
		fslider23 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec28[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec44[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<3; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<3; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<3; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec92[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
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
		synth_interface.note[0] = &fslider20;
		synth_interface.pres[0] = &fslider22;
		synth_interface.vpres[0] = &fslider23;
		synth_interface.but_y[0] = &fslider21;
		synth_interface.note[1] = &fslider16;
		synth_interface.pres[1] = &fslider18;
		synth_interface.vpres[1] = &fslider19;
		synth_interface.but_y[1] = &fslider17;
		synth_interface.note[2] = &fslider12;
		synth_interface.pres[2] = &fslider14;
		synth_interface.vpres[2] = &fslider15;
		synth_interface.but_y[2] = &fslider13;
		synth_interface.note[3] = &fslider8;
		synth_interface.pres[3] = &fslider10;
		synth_interface.vpres[3] = &fslider11;
		synth_interface.but_y[3] = &fslider9;
		synth_interface.note[4] = &fslider4;
		synth_interface.pres[4] = &fslider6;
		synth_interface.vpres[4] = &fslider7;
		synth_interface.but_y[4] = &fslider5;
		synth_interface.note[5] = &fslider0;
		synth_interface.pres[5] = &fslider2;
		synth_interface.vpres[5] = &fslider3;
		synth_interface.but_y[5] = &fslider1;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fastpow2((0.083333336f * float(fslider0)));
		float 	fSlow1 = (fConst9 * fSlow0);
		float 	fSlow2 = (fConst10 * fSlow0);
		float 	fSlow3 = float(fslider1);
		float 	fSlow4 = ftbl2[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (fSlow4 + 1.0f);
		float 	fSlow6 = float(fslider2);
		float 	fSlow7 = float(fslider3);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.0f - fSlow7);
		float 	fSlow10 = powf((fConst18 * fSlow0),2.0f);
		float 	fSlow11 = ((fSlow10 * ((0.2033f * fSlow10) + 0.31755f)) + 1.0f);
		float 	fSlow12 = (2.0f * ((fConst19 * (powf(fSlow0,2.0f) * powf(fSlow11,2.0f))) + -1.0f));
		float 	fSlow13 = (fSlow0 * fSlow11);
		float 	fSlow14 = (fConst20 * fSlow13);
		float 	fSlow15 = ((fConst11 * (fSlow13 * (fSlow14 + -0.2568503f))) + 1.0f);
		float 	fSlow16 = ((fConst11 * (fSlow13 * (fSlow14 + 0.2568503f))) + 1.0f);
		float 	fSlow17 = (1.0f / fSlow16);
		float 	fSlow18 = max(0.05f, (0.1f - fabsf(fSlow7)));
		float 	fSlow19 = (fConst21 * (fSlow13 / fSlow16));
		float 	fSlow20 = (fConst22 * fSlow0);
		float 	fSlow21 = (0.0f - fSlow3);
		float 	fSlow22 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow23 = (fConst9 * fSlow22);
		float 	fSlow24 = (fConst10 * fSlow22);
		float 	fSlow25 = float(fslider5);
		float 	fSlow26 = ftbl2[int(((499.5f * (fSlow25 + 1.0f)) + 0.5f))];
		float 	fSlow27 = (fSlow26 + 1.0f);
		float 	fSlow28 = float(fslider6);
		float 	fSlow29 = float(fslider7);
		int 	iSlow30 = (fSlow29 == 0.0f);
		float 	fSlow31 = (0.0f - fSlow29);
		float 	fSlow32 = powf((fConst18 * fSlow22),2.0f);
		float 	fSlow33 = ((fSlow32 * ((0.2033f * fSlow32) + 0.31755f)) + 1.0f);
		float 	fSlow34 = (2.0f * ((fConst19 * (powf(fSlow22,2.0f) * powf(fSlow33,2.0f))) + -1.0f));
		float 	fSlow35 = (fSlow22 * fSlow33);
		float 	fSlow36 = (fConst20 * fSlow35);
		float 	fSlow37 = ((fConst11 * (fSlow35 * (fSlow36 + -0.2568503f))) + 1.0f);
		float 	fSlow38 = ((fConst11 * (fSlow35 * (fSlow36 + 0.2568503f))) + 1.0f);
		float 	fSlow39 = (1.0f / fSlow38);
		float 	fSlow40 = max(0.05f, (0.1f - fabsf(fSlow29)));
		float 	fSlow41 = (fConst21 * (fSlow35 / fSlow38));
		float 	fSlow42 = (fConst22 * fSlow22);
		float 	fSlow43 = (0.0f - fSlow25);
		float 	fSlow44 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow45 = (fConst9 * fSlow44);
		float 	fSlow46 = (fConst10 * fSlow44);
		float 	fSlow47 = float(fslider9);
		float 	fSlow48 = ftbl2[int(((499.5f * (fSlow47 + 1.0f)) + 0.5f))];
		float 	fSlow49 = (fSlow48 + 1.0f);
		float 	fSlow50 = float(fslider10);
		float 	fSlow51 = float(fslider11);
		int 	iSlow52 = (fSlow51 == 0.0f);
		float 	fSlow53 = (0.0f - fSlow51);
		float 	fSlow54 = powf((fConst18 * fSlow44),2.0f);
		float 	fSlow55 = ((fSlow54 * ((0.2033f * fSlow54) + 0.31755f)) + 1.0f);
		float 	fSlow56 = (2.0f * ((fConst19 * (powf(fSlow44,2.0f) * powf(fSlow55,2.0f))) + -1.0f));
		float 	fSlow57 = (fSlow44 * fSlow55);
		float 	fSlow58 = (fConst20 * fSlow57);
		float 	fSlow59 = ((fConst11 * (fSlow57 * (fSlow58 + -0.2568503f))) + 1.0f);
		float 	fSlow60 = ((fConst11 * (fSlow57 * (fSlow58 + 0.2568503f))) + 1.0f);
		float 	fSlow61 = (1.0f / fSlow60);
		float 	fSlow62 = max(0.05f, (0.1f - fabsf(fSlow51)));
		float 	fSlow63 = (fConst21 * (fSlow57 / fSlow60));
		float 	fSlow64 = (fConst22 * fSlow44);
		float 	fSlow65 = (0.0f - fSlow47);
		float 	fSlow66 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow67 = (fConst9 * fSlow66);
		float 	fSlow68 = (fConst10 * fSlow66);
		float 	fSlow69 = float(fslider13);
		float 	fSlow70 = ftbl2[int(((499.5f * (fSlow69 + 1.0f)) + 0.5f))];
		float 	fSlow71 = (fSlow70 + 1.0f);
		float 	fSlow72 = float(fslider14);
		float 	fSlow73 = float(fslider15);
		int 	iSlow74 = (fSlow73 == 0.0f);
		float 	fSlow75 = (0.0f - fSlow73);
		float 	fSlow76 = powf((fConst18 * fSlow66),2.0f);
		float 	fSlow77 = ((fSlow76 * ((0.2033f * fSlow76) + 0.31755f)) + 1.0f);
		float 	fSlow78 = (2.0f * ((fConst19 * (powf(fSlow66,2.0f) * powf(fSlow77,2.0f))) + -1.0f));
		float 	fSlow79 = (fSlow66 * fSlow77);
		float 	fSlow80 = (fConst20 * fSlow79);
		float 	fSlow81 = ((fConst11 * (fSlow79 * (fSlow80 + -0.2568503f))) + 1.0f);
		float 	fSlow82 = ((fConst11 * (fSlow79 * (fSlow80 + 0.2568503f))) + 1.0f);
		float 	fSlow83 = (1.0f / fSlow82);
		float 	fSlow84 = max(0.05f, (0.1f - fabsf(fSlow73)));
		float 	fSlow85 = (fConst21 * (fSlow79 / fSlow82));
		float 	fSlow86 = (fConst22 * fSlow66);
		float 	fSlow87 = (0.0f - fSlow69);
		float 	fSlow88 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow89 = (fConst9 * fSlow88);
		float 	fSlow90 = (fConst10 * fSlow88);
		float 	fSlow91 = float(fslider17);
		float 	fSlow92 = ftbl2[int(((499.5f * (fSlow91 + 1.0f)) + 0.5f))];
		float 	fSlow93 = (fSlow92 + 1.0f);
		float 	fSlow94 = float(fslider18);
		float 	fSlow95 = float(fslider19);
		int 	iSlow96 = (fSlow95 == 0.0f);
		float 	fSlow97 = (0.0f - fSlow95);
		float 	fSlow98 = powf((fConst18 * fSlow88),2.0f);
		float 	fSlow99 = ((fSlow98 * ((0.2033f * fSlow98) + 0.31755f)) + 1.0f);
		float 	fSlow100 = (2.0f * ((fConst19 * (powf(fSlow88,2.0f) * powf(fSlow99,2.0f))) + -1.0f));
		float 	fSlow101 = (fSlow88 * fSlow99);
		float 	fSlow102 = (fConst20 * fSlow101);
		float 	fSlow103 = ((fConst11 * (fSlow101 * (fSlow102 + -0.2568503f))) + 1.0f);
		float 	fSlow104 = ((fConst11 * (fSlow101 * (fSlow102 + 0.2568503f))) + 1.0f);
		float 	fSlow105 = (1.0f / fSlow104);
		float 	fSlow106 = max(0.05f, (0.1f - fabsf(fSlow95)));
		float 	fSlow107 = (fConst21 * (fSlow101 / fSlow104));
		float 	fSlow108 = (fConst22 * fSlow88);
		float 	fSlow109 = (0.0f - fSlow91);
		float 	fSlow110 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow111 = (fConst9 * fSlow110);
		float 	fSlow112 = (fConst10 * fSlow110);
		float 	fSlow113 = float(fslider21);
		float 	fSlow114 = ftbl2[int(((499.5f * (fSlow113 + 1.0f)) + 0.5f))];
		float 	fSlow115 = (fSlow114 + 1.0f);
		float 	fSlow116 = float(fslider22);
		float 	fSlow117 = float(fslider23);
		int 	iSlow118 = (fSlow117 == 0.0f);
		float 	fSlow119 = (0.0f - fSlow117);
		float 	fSlow120 = powf((fConst18 * fSlow110),2.0f);
		float 	fSlow121 = ((fSlow120 * ((0.2033f * fSlow120) + 0.31755f)) + 1.0f);
		float 	fSlow122 = (2.0f * ((fConst19 * (powf(fSlow110,2.0f) * powf(fSlow121,2.0f))) + -1.0f));
		float 	fSlow123 = (fSlow110 * fSlow121);
		float 	fSlow124 = (fConst20 * fSlow123);
		float 	fSlow125 = ((fConst11 * (fSlow123 * (fSlow124 + -0.2568503f))) + 1.0f);
		float 	fSlow126 = ((fConst11 * (fSlow123 * (fSlow124 + 0.2568503f))) + 1.0f);
		float 	fSlow127 = (1.0f / fSlow126);
		float 	fSlow128 = max(0.05f, (0.1f - fabsf(fSlow117)));
		float 	fSlow129 = (fConst21 * (fSlow123 / fSlow126));
		float 	fSlow130 = (fConst22 * fSlow110);
		float 	fSlow131 = (0.0f - fSlow113);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp2 = (1 - iVec0[1]);
			float 	fTemp3 = ((iTemp2) ? 0.0f : (fSlow1 + fRec2[1]));
			fRec2[0] = (fTemp3 - floorf(fTemp3));
			float 	fTemp4 = (499.0f * fRec2[0]);
			int 	iTemp5 = int(fTemp4);
			float 	fTemp6 = ftbl0[max(0, min(iTemp5, 499))];
			float 	fTemp7 = ((iTemp2) ? 0.0f : (fSlow2 + fRec4[1]));
			fRec4[0] = (fTemp7 - floorf(fTemp7));
			float 	fTemp8 = (499.0f * fRec4[0]);
			int 	iTemp9 = int(fTemp8);
			float 	fTemp10 = ftbl1[max(0, min(iTemp9, 499))];
			fVec1[0] = fSlow7;
			int 	iTemp12 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp12;
			int 	iTemp13 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec10[0] = (iRec10[1] + 1);
			int 	iTemp14 = (iRec10[0] + -1);
			iRec9[0] = ((iRec9[1] * (1 - iTemp13)) + (iTemp14 * iTemp13));
			float 	fTemp15 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp15;
			int 	iTemp16 = (fVec3[0] > 0.003f);
			int 	iTemp17 = (fVec3[0] <= 0.003f);
			float 	fTemp18 = float((iTemp17 | (fVec3[1] >= 0.003f)));
			fRec11[0] = max((fRec11[1] * fTemp18), fSlow7);
			fRec12[0] = max((fTemp18 * fRec12[1]), fSlow9);
			float 	fTemp19 = (min(1.0f, fRec12[0]) + min(1.0f, fRec11[0]));
			int 	iTemp20 = (fVec3[0] >= fRec8[1]);
			int 	iTemp21 = (fRec8[1] <= 0.001f);
			int 	iTemp22 = (((iRec7[1] >= 4)) ? (((iRec7[1] >= 6)) ? ((iTemp21) ? 0 : ((iTemp16) ? 1 : 6)) : (((iRec7[1] >= 5)) ? ((iTemp17) ? 3 : ((iTemp20) ? 4 : 5)) : ((iTemp17) ? 3 : (((fVec3[0] <= fRec8[1])) ? 5 : 4)))) : (((iRec7[1] >= 2)) ? (((iRec7[1] >= 3)) ? (((iTemp17 & iTemp21)) ? 0 : ((iTemp16) ? 1 : 3)) : ((iTemp16) ? ((iTemp20) ? 4 : 2) : 6)) : (((iRec7[1] >= 1)) ? (((fRec8[1] >= min(fTemp19, 1.0f))) ? ((iTemp17) ? 6 : 2) : 1) : ((iTemp16) ? 1 : 0))));
			iRec7[0] = iTemp22;
			float 	fTemp24 = (((iTemp22 >= 4)) ? (((iTemp22 >= 6)) ? fConst16 : fConst15) : (((iTemp22 >= 2)) ? (((iTemp22 >= 3)) ? fConst14 : fConst13) : (((iTemp22 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp25 = (iRec7[1] != iRec7[2]);
			iVec4[0] = iTemp25;
			int 	iTemp26 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec15[0] = ((iRec15[1] * (1 - iTemp26)) + (iTemp14 * iTemp26));
			float 	fTemp27 = (2e+01f * (((fTemp24 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec15[0]))) / fTemp24) : 0.0f));
			int 	iTemp28 = int(fTemp27);
			float 	fTemp29 = ftbl3[max(0, int(min(int(iTemp28), 20)))];
			float 	fTemp30 = (fTemp29 + ((fTemp27 - float(iTemp28)) * (ftbl3[max(0, int(min(int((iTemp28 + 1)), 20)))] - fTemp29)));
			fRec16[0] = max((fRec16[1] * float(iVec4[0])), max(fVec3[0], fRec8[1]));
			int 	iTemp31 = (iRec7[1] == 3);
			int 	iTemp32 = (iRec7[1] == 6);
			int 	iTemp33 = (iRec7[1] == 0);
			float 	fTemp34 = (((iRec7[1] == 1)) ? min(1.0f, fTemp19) : ((iTemp33) ? 0.0f : ((iTemp32) ? (fTemp19 * fTemp30) : ((iTemp31) ? (fRec16[0] * fTemp30) : fVec3[0]))));
			float 	fTemp35 = (1.0f / ((iTemp33) ? 0.0001f : (((iTemp31 | iTemp32)) ? (0.04761905f * fTemp24) : fTemp24)));
			float 	fTemp36 = (fRec13[1] - fTemp35);
			float 	fTemp37 = (fRec13[1] + fTemp35);
			fRec13[0] = (((fTemp37 < fTemp34)) ? fTemp37 : (((fTemp36 > fTemp34)) ? fTemp36 : fTemp34));
			fRec8[0] = fRec13[0];
			float 	fTemp38 = (fRec6[1] - fConst17);
			float 	fTemp39 = (fConst17 + fRec6[1]);
			fRec6[0] = (((fTemp39 < fRec8[0])) ? fTemp39 : (((fTemp38 > fRec8[0])) ? fTemp38 : fRec8[0]));
			int 	iTemp40 = (fRec6[0] < 0.1f);
			float 	fTemp41 = (((iTemp40) ? fRec6[0] : 0.1f) * fSlow5);
			iRec18[0] = ((1103515245 * iRec18[1]) + 12345);
			float 	fTemp42 = (4.656613e-10f * float(iRec18[0]));
			fRec17[0] = (fTemp42 - (fSlow17 * ((fSlow15 * fRec17[2]) + (fSlow12 * fRec17[1]))));
			float 	fTemp43 = min(1.0f, (fSlow18 + ((iTemp40) ? (1.0f - (1e+01f * fRec6[0])) : 0.0f)));
			float 	fTemp44 = ((iTemp2) ? 0.0f : (fSlow20 + fRec20[1]));
			fRec20[0] = (fTemp44 - floorf(fTemp44));
			float 	fTemp45 = (499.0f * fRec20[0]);
			int 	iTemp46 = int(fTemp45);
			int 	iTemp47 = max(0, min(iTemp46, 499));
			float 	fTemp48 = ftbl1[iTemp47];
			int 	iTemp49 = max(0, min((iTemp46 + 1), 499));
			float 	fTemp50 = (fTemp45 - float(iTemp46));
			float 	fTemp51 = float((((fVec3[1] <= 0.003f) & iTemp16) != 1));
			fRec21[0] = max((fTemp51 * fRec21[1]), fSlow21);
			fRec22[0] = max((fRec22[1] * fTemp51), fSlow3);
			float 	fTemp52 = max(min(((0.5f * (fVec3[0] - fRec6[0])) + (0.2f - (0.8f * ((iTemp17) ? (2.0f * (((fRec22[0] > fRec21[0])) ? fRec22[0] : (0.0f - fRec21[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp53 = ftbl0[iTemp47];
			float 	fTemp54 = (((fTemp53 + (fTemp50 * (ftbl0[iTemp49] - fTemp53))) * (1.0f - fTemp52)) + (fTemp52 * (fTemp48 + (fTemp50 * (ftbl1[iTemp49] - fTemp48)))));
			float 	fTemp55 = (fRec19[1] - fConst23);
			float 	fTemp56 = (fConst23 + fRec19[1]);
			fRec19[0] = (((fTemp56 < fTemp54)) ? fTemp56 : (((fTemp55 > fTemp54)) ? fTemp55 : fTemp54));
			float 	fTemp57 = ((iTemp2) ? 0.0f : (fSlow23 + fRec23[1]));
			fRec23[0] = (fTemp57 - floorf(fTemp57));
			float 	fTemp58 = (499.0f * fRec23[0]);
			int 	iTemp59 = int(fTemp58);
			float 	fTemp60 = ftbl0[max(0, min(iTemp59, 499))];
			float 	fTemp61 = ((iTemp2) ? 0.0f : (fSlow24 + fRec24[1]));
			fRec24[0] = (fTemp61 - floorf(fTemp61));
			float 	fTemp62 = (499.0f * fRec24[0]);
			int 	iTemp63 = int(fTemp62);
			float 	fTemp64 = ftbl1[max(0, min(iTemp63, 499))];
			fVec5[0] = fSlow29;
			int 	iTemp65 = (fSlow29 != fVec5[1]);
			iVec6[0] = iTemp65;
			int 	iTemp66 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec28[0] = ((iRec28[1] * (1 - iTemp66)) + (iTemp14 * iTemp66));
			float 	fTemp67 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec28[0])))) > 0.5f) & iSlow30)) ? 0.0f : fSlow28) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp67;
			int 	iTemp68 = (fVec7[0] > 0.003f);
			int 	iTemp69 = (fVec7[0] <= 0.003f);
			float 	fTemp70 = float((iTemp69 | (fVec7[1] >= 0.003f)));
			fRec29[0] = max((fRec29[1] * fTemp70), fSlow29);
			fRec30[0] = max((fTemp70 * fRec30[1]), fSlow31);
			float 	fTemp71 = (min(1.0f, fRec30[0]) + min(1.0f, fRec29[0]));
			int 	iTemp72 = (fVec7[0] >= fRec27[1]);
			int 	iTemp73 = (fRec27[1] <= 0.001f);
			int 	iTemp74 = (((iRec26[1] >= 4)) ? (((iRec26[1] >= 6)) ? ((iTemp73) ? 0 : ((iTemp68) ? 1 : 6)) : (((iRec26[1] >= 5)) ? ((iTemp69) ? 3 : ((iTemp72) ? 4 : 5)) : ((iTemp69) ? 3 : (((fVec7[0] <= fRec27[1])) ? 5 : 4)))) : (((iRec26[1] >= 2)) ? (((iRec26[1] >= 3)) ? (((iTemp69 & iTemp73)) ? 0 : ((iTemp68) ? 1 : 3)) : ((iTemp68) ? ((iTemp72) ? 4 : 2) : 6)) : (((iRec26[1] >= 1)) ? (((fRec27[1] >= min(fTemp71, 1.0f))) ? ((iTemp69) ? 6 : 2) : 1) : ((iTemp68) ? 1 : 0))));
			iRec26[0] = iTemp74;
			float 	fTemp75 = (((iTemp74 >= 4)) ? (((iTemp74 >= 6)) ? fConst16 : fConst15) : (((iTemp74 >= 2)) ? (((iTemp74 >= 3)) ? fConst14 : fConst13) : (((iTemp74 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp76 = (iRec26[1] != iRec26[2]);
			iVec8[0] = iTemp76;
			int 	iTemp77 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp77)) + (iTemp14 * iTemp77));
			float 	fTemp78 = (2e+01f * (((fTemp75 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec32[0]))) / fTemp75) : 0.0f));
			int 	iTemp79 = int(fTemp78);
			float 	fTemp80 = ftbl3[max(0, int(min(int(iTemp79), 20)))];
			float 	fTemp81 = (fTemp80 + ((fTemp78 - float(iTemp79)) * (ftbl3[max(0, int(min(int((iTemp79 + 1)), 20)))] - fTemp80)));
			fRec33[0] = max((fRec33[1] * float(iVec8[0])), max(fVec7[0], fRec27[1]));
			int 	iTemp82 = (iRec26[1] == 3);
			int 	iTemp83 = (iRec26[1] == 6);
			int 	iTemp84 = (iRec26[1] == 0);
			float 	fTemp85 = (((iRec26[1] == 1)) ? min(1.0f, fTemp71) : ((iTemp84) ? 0.0f : ((iTemp83) ? (fTemp71 * fTemp81) : ((iTemp82) ? (fRec33[0] * fTemp81) : fVec7[0]))));
			float 	fTemp86 = (1.0f / ((iTemp84) ? 0.0001f : (((iTemp82 | iTemp83)) ? (0.04761905f * fTemp75) : fTemp75)));
			float 	fTemp87 = (fRec31[1] - fTemp86);
			float 	fTemp88 = (fRec31[1] + fTemp86);
			fRec31[0] = (((fTemp88 < fTemp85)) ? fTemp88 : (((fTemp87 > fTemp85)) ? fTemp87 : fTemp85));
			fRec27[0] = fRec31[0];
			float 	fTemp89 = (fRec25[1] - fConst17);
			float 	fTemp90 = (fConst17 + fRec25[1]);
			fRec25[0] = (((fTemp90 < fRec27[0])) ? fTemp90 : (((fTemp89 > fRec27[0])) ? fTemp89 : fRec27[0]));
			int 	iTemp91 = (fRec25[0] < 0.1f);
			float 	fTemp92 = (((iTemp91) ? fRec25[0] : 0.1f) * fSlow27);
			fRec34[0] = (fTemp42 - (fSlow39 * ((fSlow37 * fRec34[2]) + (fSlow34 * fRec34[1]))));
			float 	fTemp93 = min(1.0f, (fSlow40 + ((iTemp91) ? (1.0f - (1e+01f * fRec25[0])) : 0.0f)));
			float 	fTemp94 = ((iTemp2) ? 0.0f : (fSlow42 + fRec36[1]));
			fRec36[0] = (fTemp94 - floorf(fTemp94));
			float 	fTemp95 = (499.0f * fRec36[0]);
			int 	iTemp96 = int(fTemp95);
			int 	iTemp97 = max(0, min(iTemp96, 499));
			float 	fTemp98 = ftbl1[iTemp97];
			int 	iTemp99 = max(0, min((iTemp96 + 1), 499));
			float 	fTemp100 = (fTemp95 - float(iTemp96));
			float 	fTemp101 = float((((fVec7[1] <= 0.003f) & iTemp68) != 1));
			fRec37[0] = max((fTemp101 * fRec37[1]), fSlow43);
			fRec38[0] = max((fRec38[1] * fTemp101), fSlow25);
			float 	fTemp102 = max(min(((0.5f * (fVec7[0] - fRec25[0])) + (0.2f - (0.8f * ((iTemp69) ? (2.0f * (((fRec38[0] > fRec37[0])) ? fRec38[0] : (0.0f - fRec37[0]))) : fSlow26)))), 1.0f), 0.0f);
			float 	fTemp103 = ftbl0[iTemp97];
			float 	fTemp104 = (((fTemp103 + (fTemp100 * (ftbl0[iTemp99] - fTemp103))) * (1.0f - fTemp102)) + (fTemp102 * (fTemp98 + (fTemp100 * (ftbl1[iTemp99] - fTemp98)))));
			float 	fTemp105 = (fRec35[1] - fConst23);
			float 	fTemp106 = (fConst23 + fRec35[1]);
			fRec35[0] = (((fTemp106 < fTemp104)) ? fTemp106 : (((fTemp105 > fTemp104)) ? fTemp105 : fTemp104));
			float 	fTemp107 = ((iTemp2) ? 0.0f : (fSlow45 + fRec39[1]));
			fRec39[0] = (fTemp107 - floorf(fTemp107));
			float 	fTemp108 = (499.0f * fRec39[0]);
			int 	iTemp109 = int(fTemp108);
			float 	fTemp110 = ftbl0[max(0, min(iTemp109, 499))];
			float 	fTemp111 = ((iTemp2) ? 0.0f : (fSlow46 + fRec40[1]));
			fRec40[0] = (fTemp111 - floorf(fTemp111));
			float 	fTemp112 = (499.0f * fRec40[0]);
			int 	iTemp113 = int(fTemp112);
			float 	fTemp114 = ftbl1[max(0, min(iTemp113, 499))];
			fVec9[0] = fSlow51;
			int 	iTemp115 = (fSlow51 != fVec9[1]);
			iVec10[0] = iTemp115;
			int 	iTemp116 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec44[0] = ((iRec44[1] * (1 - iTemp116)) + (iTemp14 * iTemp116));
			float 	fTemp117 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec44[0])))) > 0.5f) & iSlow52)) ? 0.0f : fSlow50) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp117;
			int 	iTemp118 = (fVec11[0] > 0.003f);
			int 	iTemp119 = (fVec11[0] <= 0.003f);
			float 	fTemp120 = float((iTemp119 | (fVec11[1] >= 0.003f)));
			fRec45[0] = max((fRec45[1] * fTemp120), fSlow51);
			fRec46[0] = max((fTemp120 * fRec46[1]), fSlow53);
			float 	fTemp121 = (min(1.0f, fRec46[0]) + min(1.0f, fRec45[0]));
			int 	iTemp122 = (fVec11[0] >= fRec43[1]);
			int 	iTemp123 = (fRec43[1] <= 0.001f);
			int 	iTemp124 = (((iRec42[1] >= 4)) ? (((iRec42[1] >= 6)) ? ((iTemp123) ? 0 : ((iTemp118) ? 1 : 6)) : (((iRec42[1] >= 5)) ? ((iTemp119) ? 3 : ((iTemp122) ? 4 : 5)) : ((iTemp119) ? 3 : (((fVec11[0] <= fRec43[1])) ? 5 : 4)))) : (((iRec42[1] >= 2)) ? (((iRec42[1] >= 3)) ? (((iTemp119 & iTemp123)) ? 0 : ((iTemp118) ? 1 : 3)) : ((iTemp118) ? ((iTemp122) ? 4 : 2) : 6)) : (((iRec42[1] >= 1)) ? (((fRec43[1] >= min(fTemp121, 1.0f))) ? ((iTemp119) ? 6 : 2) : 1) : ((iTemp118) ? 1 : 0))));
			iRec42[0] = iTemp124;
			float 	fTemp125 = (((iTemp124 >= 4)) ? (((iTemp124 >= 6)) ? fConst16 : fConst15) : (((iTemp124 >= 2)) ? (((iTemp124 >= 3)) ? fConst14 : fConst13) : (((iTemp124 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp126 = (iRec42[1] != iRec42[2]);
			iVec12[0] = iTemp126;
			int 	iTemp127 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec48[0] = ((iRec48[1] * (1 - iTemp127)) + (iTemp14 * iTemp127));
			float 	fTemp128 = (2e+01f * (((fTemp125 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec48[0]))) / fTemp125) : 0.0f));
			int 	iTemp129 = int(fTemp128);
			float 	fTemp130 = ftbl3[max(0, int(min(int(iTemp129), 20)))];
			float 	fTemp131 = (fTemp130 + ((fTemp128 - float(iTemp129)) * (ftbl3[max(0, int(min(int((iTemp129 + 1)), 20)))] - fTemp130)));
			fRec49[0] = max((fRec49[1] * float(iVec12[0])), max(fVec11[0], fRec43[1]));
			int 	iTemp132 = (iRec42[1] == 3);
			int 	iTemp133 = (iRec42[1] == 6);
			int 	iTemp134 = (iRec42[1] == 0);
			float 	fTemp135 = (((iRec42[1] == 1)) ? min(1.0f, fTemp121) : ((iTemp134) ? 0.0f : ((iTemp133) ? (fTemp121 * fTemp131) : ((iTemp132) ? (fRec49[0] * fTemp131) : fVec11[0]))));
			float 	fTemp136 = (1.0f / ((iTemp134) ? 0.0001f : (((iTemp132 | iTemp133)) ? (0.04761905f * fTemp125) : fTemp125)));
			float 	fTemp137 = (fRec47[1] - fTemp136);
			float 	fTemp138 = (fRec47[1] + fTemp136);
			fRec47[0] = (((fTemp138 < fTemp135)) ? fTemp138 : (((fTemp137 > fTemp135)) ? fTemp137 : fTemp135));
			fRec43[0] = fRec47[0];
			float 	fTemp139 = (fRec41[1] - fConst17);
			float 	fTemp140 = (fConst17 + fRec41[1]);
			fRec41[0] = (((fTemp140 < fRec43[0])) ? fTemp140 : (((fTemp139 > fRec43[0])) ? fTemp139 : fRec43[0]));
			int 	iTemp141 = (fRec41[0] < 0.1f);
			float 	fTemp142 = (((iTemp141) ? fRec41[0] : 0.1f) * fSlow49);
			fRec50[0] = (fTemp42 - (fSlow61 * ((fSlow59 * fRec50[2]) + (fSlow56 * fRec50[1]))));
			float 	fTemp143 = min(1.0f, (fSlow62 + ((iTemp141) ? (1.0f - (1e+01f * fRec41[0])) : 0.0f)));
			float 	fTemp144 = ((iTemp2) ? 0.0f : (fSlow64 + fRec52[1]));
			fRec52[0] = (fTemp144 - floorf(fTemp144));
			float 	fTemp145 = (499.0f * fRec52[0]);
			int 	iTemp146 = int(fTemp145);
			int 	iTemp147 = max(0, min(iTemp146, 499));
			float 	fTemp148 = ftbl1[iTemp147];
			int 	iTemp149 = max(0, min((iTemp146 + 1), 499));
			float 	fTemp150 = (fTemp145 - float(iTemp146));
			float 	fTemp151 = float((((fVec11[1] <= 0.003f) & iTemp118) != 1));
			fRec53[0] = max((fTemp151 * fRec53[1]), fSlow65);
			fRec54[0] = max((fRec54[1] * fTemp151), fSlow47);
			float 	fTemp152 = max(min(((0.5f * (fVec11[0] - fRec41[0])) + (0.2f - (0.8f * ((iTemp119) ? (2.0f * (((fRec54[0] > fRec53[0])) ? fRec54[0] : (0.0f - fRec53[0]))) : fSlow48)))), 1.0f), 0.0f);
			float 	fTemp153 = ftbl0[iTemp147];
			float 	fTemp154 = (((fTemp153 + (fTemp150 * (ftbl0[iTemp149] - fTemp153))) * (1.0f - fTemp152)) + (fTemp152 * (fTemp148 + (fTemp150 * (ftbl1[iTemp149] - fTemp148)))));
			float 	fTemp155 = (fRec51[1] - fConst23);
			float 	fTemp156 = (fConst23 + fRec51[1]);
			fRec51[0] = (((fTemp156 < fTemp154)) ? fTemp156 : (((fTemp155 > fTemp154)) ? fTemp155 : fTemp154));
			float 	fTemp157 = ((iTemp2) ? 0.0f : (fSlow67 + fRec55[1]));
			fRec55[0] = (fTemp157 - floorf(fTemp157));
			float 	fTemp158 = (499.0f * fRec55[0]);
			int 	iTemp159 = int(fTemp158);
			float 	fTemp160 = ftbl0[max(0, min(iTemp159, 499))];
			float 	fTemp161 = ((iTemp2) ? 0.0f : (fSlow68 + fRec56[1]));
			fRec56[0] = (fTemp161 - floorf(fTemp161));
			float 	fTemp162 = (499.0f * fRec56[0]);
			int 	iTemp163 = int(fTemp162);
			float 	fTemp164 = ftbl1[max(0, min(iTemp163, 499))];
			fVec13[0] = fSlow73;
			int 	iTemp165 = (fSlow73 != fVec13[1]);
			iVec14[0] = iTemp165;
			int 	iTemp166 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp166)) + (iTemp14 * iTemp166));
			float 	fTemp167 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec60[0])))) > 0.5f) & iSlow74)) ? 0.0f : fSlow72) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp167;
			int 	iTemp168 = (fVec15[0] > 0.003f);
			int 	iTemp169 = (fVec15[0] <= 0.003f);
			float 	fTemp170 = float((iTemp169 | (fVec15[1] >= 0.003f)));
			fRec61[0] = max((fRec61[1] * fTemp170), fSlow73);
			fRec62[0] = max((fTemp170 * fRec62[1]), fSlow75);
			float 	fTemp171 = (min(1.0f, fRec62[0]) + min(1.0f, fRec61[0]));
			int 	iTemp172 = (fVec15[0] >= fRec59[1]);
			int 	iTemp173 = (fRec59[1] <= 0.001f);
			int 	iTemp174 = (((iRec58[1] >= 4)) ? (((iRec58[1] >= 6)) ? ((iTemp173) ? 0 : ((iTemp168) ? 1 : 6)) : (((iRec58[1] >= 5)) ? ((iTemp169) ? 3 : ((iTemp172) ? 4 : 5)) : ((iTemp169) ? 3 : (((fVec15[0] <= fRec59[1])) ? 5 : 4)))) : (((iRec58[1] >= 2)) ? (((iRec58[1] >= 3)) ? (((iTemp169 & iTemp173)) ? 0 : ((iTemp168) ? 1 : 3)) : ((iTemp168) ? ((iTemp172) ? 4 : 2) : 6)) : (((iRec58[1] >= 1)) ? (((fRec59[1] >= min(fTemp171, 1.0f))) ? ((iTemp169) ? 6 : 2) : 1) : ((iTemp168) ? 1 : 0))));
			iRec58[0] = iTemp174;
			float 	fTemp175 = (((iTemp174 >= 4)) ? (((iTemp174 >= 6)) ? fConst16 : fConst15) : (((iTemp174 >= 2)) ? (((iTemp174 >= 3)) ? fConst14 : fConst13) : (((iTemp174 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp176 = (iRec58[1] != iRec58[2]);
			iVec16[0] = iTemp176;
			int 	iTemp177 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec64[0] = ((iRec64[1] * (1 - iTemp177)) + (iTemp14 * iTemp177));
			float 	fTemp178 = (2e+01f * (((fTemp175 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec64[0]))) / fTemp175) : 0.0f));
			int 	iTemp179 = int(fTemp178);
			float 	fTemp180 = ftbl3[max(0, int(min(int(iTemp179), 20)))];
			float 	fTemp181 = (fTemp180 + ((fTemp178 - float(iTemp179)) * (ftbl3[max(0, int(min(int((iTemp179 + 1)), 20)))] - fTemp180)));
			fRec65[0] = max((fRec65[1] * float(iVec16[0])), max(fVec15[0], fRec59[1]));
			int 	iTemp182 = (iRec58[1] == 3);
			int 	iTemp183 = (iRec58[1] == 6);
			int 	iTemp184 = (iRec58[1] == 0);
			float 	fTemp185 = (((iRec58[1] == 1)) ? min(1.0f, fTemp171) : ((iTemp184) ? 0.0f : ((iTemp183) ? (fTemp171 * fTemp181) : ((iTemp182) ? (fRec65[0] * fTemp181) : fVec15[0]))));
			float 	fTemp186 = (1.0f / ((iTemp184) ? 0.0001f : (((iTemp182 | iTemp183)) ? (0.04761905f * fTemp175) : fTemp175)));
			float 	fTemp187 = (fRec63[1] - fTemp186);
			float 	fTemp188 = (fRec63[1] + fTemp186);
			fRec63[0] = (((fTemp188 < fTemp185)) ? fTemp188 : (((fTemp187 > fTemp185)) ? fTemp187 : fTemp185));
			fRec59[0] = fRec63[0];
			float 	fTemp189 = (fRec57[1] - fConst17);
			float 	fTemp190 = (fConst17 + fRec57[1]);
			fRec57[0] = (((fTemp190 < fRec59[0])) ? fTemp190 : (((fTemp189 > fRec59[0])) ? fTemp189 : fRec59[0]));
			int 	iTemp191 = (fRec57[0] < 0.1f);
			float 	fTemp192 = (((iTemp191) ? fRec57[0] : 0.1f) * fSlow71);
			fRec66[0] = (fTemp42 - (fSlow83 * ((fSlow81 * fRec66[2]) + (fSlow78 * fRec66[1]))));
			float 	fTemp193 = min(1.0f, (fSlow84 + ((iTemp191) ? (1.0f - (1e+01f * fRec57[0])) : 0.0f)));
			float 	fTemp194 = ((iTemp2) ? 0.0f : (fSlow86 + fRec68[1]));
			fRec68[0] = (fTemp194 - floorf(fTemp194));
			float 	fTemp195 = (499.0f * fRec68[0]);
			int 	iTemp196 = int(fTemp195);
			int 	iTemp197 = max(0, min(iTemp196, 499));
			float 	fTemp198 = ftbl1[iTemp197];
			int 	iTemp199 = max(0, min((iTemp196 + 1), 499));
			float 	fTemp200 = (fTemp195 - float(iTemp196));
			float 	fTemp201 = float((((fVec15[1] <= 0.003f) & iTemp168) != 1));
			fRec69[0] = max((fTemp201 * fRec69[1]), fSlow87);
			fRec70[0] = max((fRec70[1] * fTemp201), fSlow69);
			float 	fTemp202 = max(min(((0.5f * (fVec15[0] - fRec57[0])) + (0.2f - (0.8f * ((iTemp169) ? (2.0f * (((fRec70[0] > fRec69[0])) ? fRec70[0] : (0.0f - fRec69[0]))) : fSlow70)))), 1.0f), 0.0f);
			float 	fTemp203 = ftbl0[iTemp197];
			float 	fTemp204 = (((fTemp203 + (fTemp200 * (ftbl0[iTemp199] - fTemp203))) * (1.0f - fTemp202)) + (fTemp202 * (fTemp198 + (fTemp200 * (ftbl1[iTemp199] - fTemp198)))));
			float 	fTemp205 = (fRec67[1] - fConst23);
			float 	fTemp206 = (fConst23 + fRec67[1]);
			fRec67[0] = (((fTemp206 < fTemp204)) ? fTemp206 : (((fTemp205 > fTemp204)) ? fTemp205 : fTemp204));
			float 	fTemp207 = ((iTemp2) ? 0.0f : (fSlow89 + fRec71[1]));
			fRec71[0] = (fTemp207 - floorf(fTemp207));
			float 	fTemp208 = (499.0f * fRec71[0]);
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl0[max(0, min(iTemp209, 499))];
			float 	fTemp211 = ((iTemp2) ? 0.0f : (fSlow90 + fRec72[1]));
			fRec72[0] = (fTemp211 - floorf(fTemp211));
			float 	fTemp212 = (499.0f * fRec72[0]);
			int 	iTemp213 = int(fTemp212);
			float 	fTemp214 = ftbl1[max(0, min(iTemp213, 499))];
			fVec17[0] = fSlow95;
			int 	iTemp215 = (fSlow95 != fVec17[1]);
			iVec18[0] = iTemp215;
			int 	iTemp216 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec76[0] = ((iRec76[1] * (1 - iTemp216)) + (iTemp14 * iTemp216));
			float 	fTemp217 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec76[0])))) > 0.5f) & iSlow96)) ? 0.0f : fSlow94) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp217;
			int 	iTemp218 = (fVec19[0] > 0.003f);
			int 	iTemp219 = (fVec19[0] <= 0.003f);
			float 	fTemp220 = float((iTemp219 | (fVec19[1] >= 0.003f)));
			fRec77[0] = max((fRec77[1] * fTemp220), fSlow95);
			fRec78[0] = max((fTemp220 * fRec78[1]), fSlow97);
			float 	fTemp221 = (min(1.0f, fRec78[0]) + min(1.0f, fRec77[0]));
			int 	iTemp222 = (fVec19[0] >= fRec75[1]);
			int 	iTemp223 = (fRec75[1] <= 0.001f);
			int 	iTemp224 = (((iRec74[1] >= 4)) ? (((iRec74[1] >= 6)) ? ((iTemp223) ? 0 : ((iTemp218) ? 1 : 6)) : (((iRec74[1] >= 5)) ? ((iTemp219) ? 3 : ((iTemp222) ? 4 : 5)) : ((iTemp219) ? 3 : (((fVec19[0] <= fRec75[1])) ? 5 : 4)))) : (((iRec74[1] >= 2)) ? (((iRec74[1] >= 3)) ? (((iTemp219 & iTemp223)) ? 0 : ((iTemp218) ? 1 : 3)) : ((iTemp218) ? ((iTemp222) ? 4 : 2) : 6)) : (((iRec74[1] >= 1)) ? (((fRec75[1] >= min(fTemp221, 1.0f))) ? ((iTemp219) ? 6 : 2) : 1) : ((iTemp218) ? 1 : 0))));
			iRec74[0] = iTemp224;
			float 	fTemp225 = (((iTemp224 >= 4)) ? (((iTemp224 >= 6)) ? fConst16 : fConst15) : (((iTemp224 >= 2)) ? (((iTemp224 >= 3)) ? fConst14 : fConst13) : (((iTemp224 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp226 = (iRec74[1] != iRec74[2]);
			iVec20[0] = iTemp226;
			int 	iTemp227 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec80[0] = ((iRec80[1] * (1 - iTemp227)) + (iTemp14 * iTemp227));
			float 	fTemp228 = (2e+01f * (((fTemp225 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec80[0]))) / fTemp225) : 0.0f));
			int 	iTemp229 = int(fTemp228);
			float 	fTemp230 = ftbl3[max(0, int(min(int(iTemp229), 20)))];
			float 	fTemp231 = (fTemp230 + ((fTemp228 - float(iTemp229)) * (ftbl3[max(0, int(min(int((iTemp229 + 1)), 20)))] - fTemp230)));
			fRec81[0] = max((fRec81[1] * float(iVec20[0])), max(fVec19[0], fRec75[1]));
			int 	iTemp232 = (iRec74[1] == 3);
			int 	iTemp233 = (iRec74[1] == 6);
			int 	iTemp234 = (iRec74[1] == 0);
			float 	fTemp235 = (((iRec74[1] == 1)) ? min(1.0f, fTemp221) : ((iTemp234) ? 0.0f : ((iTemp233) ? (fTemp221 * fTemp231) : ((iTemp232) ? (fRec81[0] * fTemp231) : fVec19[0]))));
			float 	fTemp236 = (1.0f / ((iTemp234) ? 0.0001f : (((iTemp232 | iTemp233)) ? (0.04761905f * fTemp225) : fTemp225)));
			float 	fTemp237 = (fRec79[1] - fTemp236);
			float 	fTemp238 = (fRec79[1] + fTemp236);
			fRec79[0] = (((fTemp238 < fTemp235)) ? fTemp238 : (((fTemp237 > fTemp235)) ? fTemp237 : fTemp235));
			fRec75[0] = fRec79[0];
			float 	fTemp239 = (fRec73[1] - fConst17);
			float 	fTemp240 = (fConst17 + fRec73[1]);
			fRec73[0] = (((fTemp240 < fRec75[0])) ? fTemp240 : (((fTemp239 > fRec75[0])) ? fTemp239 : fRec75[0]));
			int 	iTemp241 = (fRec73[0] < 0.1f);
			float 	fTemp242 = (((iTemp241) ? fRec73[0] : 0.1f) * fSlow93);
			fRec82[0] = (fTemp42 - (fSlow105 * ((fSlow103 * fRec82[2]) + (fSlow100 * fRec82[1]))));
			float 	fTemp243 = min(1.0f, (fSlow106 + ((iTemp241) ? (1.0f - (1e+01f * fRec73[0])) : 0.0f)));
			float 	fTemp244 = ((iTemp2) ? 0.0f : (fSlow108 + fRec84[1]));
			fRec84[0] = (fTemp244 - floorf(fTemp244));
			float 	fTemp245 = (499.0f * fRec84[0]);
			int 	iTemp246 = int(fTemp245);
			int 	iTemp247 = max(0, min(iTemp246, 499));
			float 	fTemp248 = ftbl1[iTemp247];
			int 	iTemp249 = max(0, min((iTemp246 + 1), 499));
			float 	fTemp250 = (fTemp245 - float(iTemp246));
			float 	fTemp251 = float((((fVec19[1] <= 0.003f) & iTemp218) != 1));
			fRec85[0] = max((fTemp251 * fRec85[1]), fSlow109);
			fRec86[0] = max((fRec86[1] * fTemp251), fSlow91);
			float 	fTemp252 = max(min(((0.5f * (fVec19[0] - fRec73[0])) + (0.2f - (0.8f * ((iTemp219) ? (2.0f * (((fRec86[0] > fRec85[0])) ? fRec86[0] : (0.0f - fRec85[0]))) : fSlow92)))), 1.0f), 0.0f);
			float 	fTemp253 = ftbl0[iTemp247];
			float 	fTemp254 = (((fTemp253 + (fTemp250 * (ftbl0[iTemp249] - fTemp253))) * (1.0f - fTemp252)) + (fTemp252 * (fTemp248 + (fTemp250 * (ftbl1[iTemp249] - fTemp248)))));
			float 	fTemp255 = (fRec83[1] - fConst23);
			float 	fTemp256 = (fConst23 + fRec83[1]);
			fRec83[0] = (((fTemp256 < fTemp254)) ? fTemp256 : (((fTemp255 > fTemp254)) ? fTemp255 : fTemp254));
			float 	fTemp257 = ((iTemp2) ? 0.0f : (fSlow111 + fRec87[1]));
			fRec87[0] = (fTemp257 - floorf(fTemp257));
			float 	fTemp258 = (499.0f * fRec87[0]);
			int 	iTemp259 = int(fTemp258);
			float 	fTemp260 = ftbl0[max(0, min(iTemp259, 499))];
			float 	fTemp261 = ((iTemp2) ? 0.0f : (fSlow112 + fRec88[1]));
			fRec88[0] = (fTemp261 - floorf(fTemp261));
			float 	fTemp262 = (499.0f * fRec88[0]);
			int 	iTemp263 = int(fTemp262);
			float 	fTemp264 = ftbl1[max(0, min(iTemp263, 499))];
			fVec21[0] = fSlow117;
			int 	iTemp265 = (fSlow117 != fVec21[1]);
			iVec22[0] = iTemp265;
			int 	iTemp266 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec92[0] = ((iRec92[1] * (1 - iTemp266)) + (iTemp14 * iTemp266));
			float 	fTemp267 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec92[0])))) > 0.5f) & iSlow118)) ? 0.0f : fSlow116) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp267;
			int 	iTemp268 = (fVec23[0] > 0.003f);
			int 	iTemp269 = (fVec23[0] <= 0.003f);
			float 	fTemp270 = float((iTemp269 | (fVec23[1] >= 0.003f)));
			fRec93[0] = max((fRec93[1] * fTemp270), fSlow117);
			fRec94[0] = max((fTemp270 * fRec94[1]), fSlow119);
			float 	fTemp271 = (min(1.0f, fRec94[0]) + min(1.0f, fRec93[0]));
			int 	iTemp272 = (fVec23[0] >= fRec91[1]);
			int 	iTemp273 = (fRec91[1] <= 0.001f);
			int 	iTemp274 = (((iRec90[1] >= 4)) ? (((iRec90[1] >= 6)) ? ((iTemp273) ? 0 : ((iTemp268) ? 1 : 6)) : (((iRec90[1] >= 5)) ? ((iTemp269) ? 3 : ((iTemp272) ? 4 : 5)) : ((iTemp269) ? 3 : (((fVec23[0] <= fRec91[1])) ? 5 : 4)))) : (((iRec90[1] >= 2)) ? (((iRec90[1] >= 3)) ? (((iTemp269 & iTemp273)) ? 0 : ((iTemp268) ? 1 : 3)) : ((iTemp268) ? ((iTemp272) ? 4 : 2) : 6)) : (((iRec90[1] >= 1)) ? (((fRec91[1] >= min(fTemp271, 1.0f))) ? ((iTemp269) ? 6 : 2) : 1) : ((iTemp268) ? 1 : 0))));
			iRec90[0] = iTemp274;
			float 	fTemp275 = (((iTemp274 >= 4)) ? (((iTemp274 >= 6)) ? fConst16 : fConst15) : (((iTemp274 >= 2)) ? (((iTemp274 >= 3)) ? fConst14 : fConst13) : (((iTemp274 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp276 = (iRec90[1] != iRec90[2]);
			iVec24[0] = iTemp276;
			int 	iTemp277 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp277)) + (iTemp14 * iTemp277));
			float 	fTemp278 = (2e+01f * (((fTemp275 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec96[0]))) / fTemp275) : 0.0f));
			int 	iTemp279 = int(fTemp278);
			float 	fTemp280 = ftbl3[max(0, int(min(int(iTemp279), 20)))];
			float 	fTemp281 = (fTemp280 + ((fTemp278 - float(iTemp279)) * (ftbl3[max(0, int(min(int((iTemp279 + 1)), 20)))] - fTemp280)));
			fRec97[0] = max((fRec97[1] * float(iVec24[0])), max(fVec23[0], fRec91[1]));
			int 	iTemp282 = (iRec90[1] == 3);
			int 	iTemp283 = (iRec90[1] == 6);
			int 	iTemp284 = (iRec90[1] == 0);
			float 	fTemp285 = (((iRec90[1] == 1)) ? min(1.0f, fTemp271) : ((iTemp284) ? 0.0f : ((iTemp283) ? (fTemp271 * fTemp281) : ((iTemp282) ? (fRec97[0] * fTemp281) : fVec23[0]))));
			float 	fTemp286 = (1.0f / ((iTemp284) ? 0.0001f : (((iTemp282 | iTemp283)) ? (0.04761905f * fTemp275) : fTemp275)));
			float 	fTemp287 = (fRec95[1] - fTemp286);
			float 	fTemp288 = (fRec95[1] + fTemp286);
			fRec95[0] = (((fTemp288 < fTemp285)) ? fTemp288 : (((fTemp287 > fTemp285)) ? fTemp287 : fTemp285));
			fRec91[0] = fRec95[0];
			float 	fTemp289 = (fRec89[1] - fConst17);
			float 	fTemp290 = (fConst17 + fRec89[1]);
			fRec89[0] = (((fTemp290 < fRec91[0])) ? fTemp290 : (((fTemp289 > fRec91[0])) ? fTemp289 : fRec91[0]));
			int 	iTemp291 = (fRec89[0] < 0.1f);
			float 	fTemp292 = (((iTemp291) ? fRec89[0] : 0.1f) * fSlow115);
			fRec98[0] = (fTemp42 - (fSlow127 * ((fSlow125 * fRec98[2]) + (fSlow122 * fRec98[1]))));
			float 	fTemp293 = min(1.0f, (fSlow128 + ((iTemp291) ? (1.0f - (1e+01f * fRec89[0])) : 0.0f)));
			float 	fTemp294 = ((iTemp2) ? 0.0f : (fSlow130 + fRec100[1]));
			fRec100[0] = (fTemp294 - floorf(fTemp294));
			float 	fTemp295 = (499.0f * fRec100[0]);
			int 	iTemp296 = int(fTemp295);
			int 	iTemp297 = max(0, min(iTemp296, 499));
			float 	fTemp298 = ftbl1[iTemp297];
			int 	iTemp299 = max(0, min((iTemp296 + 1), 499));
			float 	fTemp300 = (fTemp295 - float(iTemp296));
			float 	fTemp301 = float((((fVec23[1] <= 0.003f) & iTemp268) != 1));
			fRec101[0] = max((fTemp301 * fRec101[1]), fSlow131);
			fRec102[0] = max((fRec102[1] * fTemp301), fSlow113);
			float 	fTemp302 = max(min(((0.5f * (fVec23[0] - fRec89[0])) + (0.2f - (0.8f * ((iTemp269) ? (2.0f * (((fRec102[0] > fRec101[0])) ? fRec102[0] : (0.0f - fRec101[0]))) : fSlow114)))), 1.0f), 0.0f);
			float 	fTemp303 = ftbl0[iTemp297];
			float 	fTemp304 = (((fTemp303 + (fTemp300 * (ftbl0[iTemp299] - fTemp303))) * (1.0f - fTemp302)) + (fTemp302 * (fTemp298 + (fTemp300 * (ftbl1[iTemp299] - fTemp298)))));
			float 	fTemp305 = (fRec99[1] - fConst23);
			float 	fTemp306 = (fConst23 + fRec99[1]);
			fRec99[0] = (((fTemp306 < fTemp304)) ? fTemp306 : (((fTemp305 > fTemp304)) ? fTemp305 : fTemp304));
			fRec0[0] = ((1.37f * ((((((fRec89[0] * ((((1.1f * (fRec99[0] * (1.0f - fTemp293))) + (fSlow129 * (fTemp293 * (fRec98[0] - fRec98[2])))) * (1.0f - (0.5f * fTemp292))) + (0.5f * (fTemp292 * ((0.2f * (fTemp264 + ((fTemp262 - float(iTemp263)) * (ftbl1[max(0, min((iTemp263 + 1), 499))] - fTemp264)))) + (0.8f * (fTemp260 + ((fTemp258 - float(iTemp259)) * (ftbl0[max(0, min((iTemp259 + 1), 499))] - fTemp260))))))))) + (fRec73[0] * ((((1.1f * (fRec83[0] * (1.0f - fTemp243))) + (fSlow107 * (fTemp243 * (fRec82[0] - fRec82[2])))) * (1.0f - (0.5f * fTemp242))) + (0.5f * (fTemp242 * ((0.2f * (fTemp214 + ((fTemp212 - float(iTemp213)) * (ftbl1[max(0, min((iTemp213 + 1), 499))] - fTemp214)))) + (0.8f * (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl0[max(0, min((iTemp209 + 1), 499))] - fTemp210)))))))))) + (fRec57[0] * ((((1.1f * (fRec67[0] * (1.0f - fTemp193))) + (fSlow85 * (fTemp193 * (fRec66[0] - fRec66[2])))) * (1.0f - (0.5f * fTemp192))) + (0.5f * (fTemp192 * ((0.2f * (fTemp164 + ((fTemp162 - float(iTemp163)) * (ftbl1[max(0, min((iTemp163 + 1), 499))] - fTemp164)))) + (0.8f * (fTemp160 + ((fTemp158 - float(iTemp159)) * (ftbl0[max(0, min((iTemp159 + 1), 499))] - fTemp160)))))))))) + (fRec41[0] * ((((1.1f * (fRec51[0] * (1.0f - fTemp143))) + (fSlow63 * (fTemp143 * (fRec50[0] - fRec50[2])))) * (1.0f - (0.5f * fTemp142))) + (0.5f * (fTemp142 * ((0.2f * (fTemp114 + ((fTemp112 - float(iTemp113)) * (ftbl1[max(0, min((iTemp113 + 1), 499))] - fTemp114)))) + (0.8f * (fTemp110 + ((fTemp108 - float(iTemp109)) * (ftbl0[max(0, min((iTemp109 + 1), 499))] - fTemp110)))))))))) + (fRec25[0] * ((((1.1f * (fRec35[0] * (1.0f - fTemp93))) + (fSlow41 * (fTemp93 * (fRec34[0] - fRec34[2])))) * (1.0f - (0.5f * fTemp92))) + (0.5f * (fTemp92 * ((0.2f * (fTemp64 + ((fTemp62 - float(iTemp63)) * (ftbl1[max(0, min((iTemp63 + 1), 499))] - fTemp64)))) + (0.8f * (fTemp60 + ((fTemp58 - float(iTemp59)) * (ftbl0[max(0, min((iTemp59 + 1), 499))] - fTemp60)))))))))) + (fRec6[0] * ((((1.1f * (fRec19[0] * (1.0f - fTemp43))) + (fSlow19 * (fTemp43 * (fRec17[0] - fRec17[2])))) * (1.0f - (0.5f * fTemp41))) + (0.5f * (fTemp41 * ((0.2f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl1[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.8f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6))))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst24 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec99[1] = fRec99[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[2] = fRec98[1]; fRec98[1] = fRec98[0];
			fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			iRec96[1] = iRec96[0];
			iVec24[1] = iVec24[0];
			iRec90[2] = iRec90[1]; iRec90[1] = iRec90[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fVec23[1] = fVec23[0];
			iRec92[1] = iRec92[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec82[2] = fRec82[1]; fRec82[1] = fRec82[0];
			fRec73[1] = fRec73[0];
			fRec75[1] = fRec75[0];
			fRec79[1] = fRec79[0];
			fRec81[1] = fRec81[0];
			iRec80[1] = iRec80[0];
			iVec20[1] = iVec20[0];
			iRec74[2] = iRec74[1]; iRec74[1] = iRec74[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fVec19[1] = fVec19[0];
			iRec76[1] = iRec76[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec67[1] = fRec67[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec57[1] = fRec57[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec65[1] = fRec65[0];
			iRec64[1] = iRec64[0];
			iVec16[1] = iVec16[0];
			iRec58[2] = iRec58[1]; iRec58[1] = iRec58[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fVec15[1] = fVec15[0];
			iRec60[1] = iRec60[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec51[1] = fRec51[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			iRec48[1] = iRec48[0];
			iVec12[1] = iVec12[0];
			iRec42[2] = iRec42[1]; iRec42[1] = iRec42[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fVec11[1] = fVec11[0];
			iRec44[1] = iRec44[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec35[1] = fRec35[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			iRec32[1] = iRec32[0];
			iVec8[1] = iVec8[0];
			iRec26[2] = iRec26[1]; iRec26[1] = iRec26[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fVec7[1] = fVec7[0];
			iRec28[1] = iRec28[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec19[1] = fRec19[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
			iVec4[1] = iVec4[0];
			iRec7[2] = iRec7[1]; iRec7[1] = iRec7[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fVec3[1] = fVec3[0];
			iRec9[1] = iRec9[0];
			iRec10[1] = iRec10[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[500];
float 	mydsp::ftbl1[500];
float 	mydsp::ftbl2[1000];
float 	mydsp::ftbl3[21];

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
