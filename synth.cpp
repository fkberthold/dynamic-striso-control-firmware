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
		int 	iRec0[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec0[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec0[0] = (iRec0[1] + 1);
				float 	fTemp0 = float((iRec0[0] + -1));
				float 	fTemp1 = (0.002004008f * fTemp0);
				output[i] = (((fTemp1 < 0.5f)) ? ((0.008016032f * fTemp0) + -1.0f) : ((4.0f * (1.0f - fTemp1)) + -1.0f));
				// post processing
				iRec0[1] = iRec0[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec2[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec2[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec2[0] = (iRec2[1] + 1);
				output[i] = ((0.004008016f * float((iRec2[0] + -1))) + -1.0f);
				// post processing
				iRec2[1] = iRec2[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec4[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec4[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec4[0] = (iRec4[1] + 1);
				float 	fTemp11 = ((0.002002002f * float((iRec4[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp11)) + -1.0f))) * float(((fTemp11 > 0.0f) - (fTemp11 < 0.0f))));
				// post processing
				iRec4[1] = iRec4[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec13[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec13[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec13[0] = (iRec13[1] + 1);
				int 	iTemp23 = int((1.05f * float((iRec13[0] + -1))));
				output[i] = (((iTemp23 >= 11)) ? (((iTemp23 >= 16)) ? (((iTemp23 >= 19)) ? (((iTemp23 >= 20)) ? 0.0f : 0.01f) : (((iTemp23 >= 18)) ? 0.03f : (((iTemp23 >= 17)) ? 0.06f : 0.08f))) : (((iTemp23 >= 14)) ? (((iTemp23 >= 15)) ? 0.1f : 0.12f) : (((iTemp23 >= 13)) ? 0.14f : (((iTemp23 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp23 >= 6)) ? (((iTemp23 >= 9)) ? (((iTemp23 >= 10)) ? 0.22f : 0.26f) : (((iTemp23 >= 8)) ? 0.3f : (((iTemp23 >= 7)) ? 0.35f : 0.4f))) : (((iTemp23 >= 3)) ? (((iTemp23 >= 5)) ? 0.47f : (((iTemp23 >= 4)) ? 0.55f : 0.64f)) : (((iTemp23 >= 2)) ? 0.74f : (((iTemp23 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec13[1] = iRec13[0];
			}
		}
	};


	static float 	ftbl0[500];
	int 	iVec0[2];
	FAUSTFLOAT 	fslider0;
	float 	fConst1;
	float 	fRec1[2];
	static float 	ftbl1[500];
	float 	fConst2;
	float 	fRec3[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider1;
	float 	fConst7;
	float 	fConst9;
	float 	fConst11;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec9[2];
	int 	iRec8[2];
	float 	fConst12;
	float 	fVec3[2];
	float 	fRec10[2];
	float 	fRec11[2];
	int 	iRec6[3];
	static float 	ftbl3[21];
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	int 	iVec4[2];
	int 	iRec14[2];
	float 	fRec15[2];
	float 	fRec12[2];
	float 	fRec7[2];
	float 	fRec5[3];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	int 	iRec17[2];
	float 	fRec16[3];
	float 	fConst22;
	float 	fConst23;
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fConst24;
	float 	fRec18[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec22[2];
	float 	fRec23[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec27[2];
	float 	fVec7[2];
	float 	fRec28[2];
	float 	fRec29[2];
	int 	iRec25[3];
	int 	iVec8[2];
	int 	iRec31[2];
	float 	fRec32[2];
	float 	fRec30[2];
	float 	fRec26[2];
	float 	fRec24[3];
	float 	fRec33[3];
	float 	fRec35[2];
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec34[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec38[2];
	float 	fRec39[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec43[2];
	float 	fVec11[2];
	float 	fRec44[2];
	float 	fRec45[2];
	int 	iRec41[3];
	int 	iVec12[2];
	int 	iRec47[2];
	float 	fRec48[2];
	float 	fRec46[2];
	float 	fRec42[2];
	float 	fRec40[3];
	float 	fRec49[3];
	float 	fRec51[2];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec50[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec54[2];
	float 	fRec55[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec59[2];
	float 	fVec15[2];
	float 	fRec60[2];
	float 	fRec61[2];
	int 	iRec57[3];
	int 	iVec16[2];
	int 	iRec63[2];
	float 	fRec64[2];
	float 	fRec62[2];
	float 	fRec58[2];
	float 	fRec56[3];
	float 	fRec65[3];
	float 	fRec67[2];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec66[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec70[2];
	float 	fRec71[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec75[2];
	float 	fVec19[2];
	float 	fRec76[2];
	float 	fRec77[2];
	int 	iRec73[3];
	int 	iVec20[2];
	int 	iRec79[2];
	float 	fRec80[2];
	float 	fRec78[2];
	float 	fRec74[2];
	float 	fRec72[3];
	float 	fRec81[3];
	float 	fRec83[2];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec82[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec86[2];
	float 	fRec87[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec91[2];
	float 	fVec23[2];
	float 	fRec92[2];
	float 	fRec93[2];
	int 	iRec89[3];
	int 	iVec24[2];
	int 	iRec95[2];
	float 	fRec96[2];
	float 	fRec94[2];
	float 	fRec90[2];
	float 	fRec88[3];
	float 	fRec97[3];
	float 	fRec99[2];
	float 	fRec100[2];
	float 	fRec101[2];
	float 	fRec98[2];
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
		fConst1 = (4.0878997f / fConst0);
		fConst2 = (2.0439498f / fConst0);
		float 	fConst3 = powf(fConst0,2.0f);
		float 	fConst4 = powf((62.831852f / fConst0),2.0f);
		float 	fConst5 = ((fConst4 * ((0.2033f * fConst4) + 0.31755f)) + 1.0f);
		float 	fConst6 = powf(fConst5,2.0f);
		fConst7 = (2.0f * ((3947.8418f * (fConst6 / fConst3)) + -1.0f));
		float 	fConst8 = (3947.8418f * (fConst5 / fConst0));
		fConst9 = (((fConst5 * (fConst8 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst10 = (((fConst5 * (fConst8 + 88.49557f)) / fConst0) + 1.0f);
		fConst11 = (1.0f / fConst10);
		fConst12 = (1.0f / fConst0);
		fConst13 = (0.1f * fConst0);
		fConst14 = (0.4f * fConst0);
		fConst15 = (0.15f * fConst0);
		fConst16 = (0.2f * fConst0);
		fConst17 = (0.75f * fConst0);
		fConst18 = (fConst6 / (fConst3 * fConst10));
		fConst19 = (25.68503f / fConst0);
		fConst20 = (659.72076f / fConst3);
		fConst21 = (659.72076f / fConst0);
		fConst22 = (0.2568503f / fConst0);
		fConst23 = (8.175799f / fConst0);
		fConst24 = (3333.3333f / fConst0);
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
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) iRec8[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<3; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<3; i++) iRec25[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<3; i++) fRec24[i] = 0;
		for (int i=0; i<3; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<3; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<3; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec59[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<3; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<3; i++) fRec56[i] = 0;
		for (int i=0; i<3; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec75[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<3; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<3; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<3; i++) iRec89[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<3; i++) fRec88[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
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
		float 	fSlow1 = (fConst1 * fSlow0);
		float 	fSlow2 = (fConst2 * fSlow0);
		float 	fSlow3 = float(fslider1);
		float 	fSlow4 = ftbl2[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (fSlow4 + 1.0f);
		float 	fSlow6 = float(fslider2);
		float 	fSlow7 = float(fslider3);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.0f - fSlow7);
		int 	iSlow10 = ((8.175799f * fSlow0) >= 8e+01f);
		float 	fSlow11 = powf((fConst19 * fSlow0),2.0f);
		float 	fSlow12 = ((fSlow11 * ((0.2033f * fSlow11) + 0.31755f)) + 1.0f);
		float 	fSlow13 = (2.0f * ((fConst20 * (powf(fSlow0,2.0f) * powf(fSlow12,2.0f))) + -1.0f));
		float 	fSlow14 = (fSlow0 * fSlow12);
		float 	fSlow15 = (fConst21 * fSlow14);
		float 	fSlow16 = ((fConst12 * (fSlow14 * (fSlow15 + -0.2568503f))) + 1.0f);
		float 	fSlow17 = ((fConst12 * (fSlow14 * (fSlow15 + 0.2568503f))) + 1.0f);
		float 	fSlow18 = (1.0f / fSlow17);
		float 	fSlow19 = max(0.05f, (0.1f - fabsf(fSlow7)));
		float 	fSlow20 = (fConst22 * (fSlow14 / fSlow17));
		float 	fSlow21 = (fConst23 * fSlow0);
		float 	fSlow22 = (0.0f - fSlow3);
		float 	fSlow23 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow24 = (fConst1 * fSlow23);
		float 	fSlow25 = (fConst2 * fSlow23);
		float 	fSlow26 = float(fslider5);
		float 	fSlow27 = ftbl2[int(((499.5f * (fSlow26 + 1.0f)) + 0.5f))];
		float 	fSlow28 = (fSlow27 + 1.0f);
		float 	fSlow29 = float(fslider6);
		float 	fSlow30 = float(fslider7);
		int 	iSlow31 = (fSlow30 == 0.0f);
		float 	fSlow32 = (0.0f - fSlow30);
		int 	iSlow33 = ((8.175799f * fSlow23) >= 8e+01f);
		float 	fSlow34 = powf((fConst19 * fSlow23),2.0f);
		float 	fSlow35 = ((fSlow34 * ((0.2033f * fSlow34) + 0.31755f)) + 1.0f);
		float 	fSlow36 = (2.0f * ((fConst20 * (powf(fSlow23,2.0f) * powf(fSlow35,2.0f))) + -1.0f));
		float 	fSlow37 = (fSlow23 * fSlow35);
		float 	fSlow38 = (fConst21 * fSlow37);
		float 	fSlow39 = ((fConst12 * (fSlow37 * (fSlow38 + -0.2568503f))) + 1.0f);
		float 	fSlow40 = ((fConst12 * (fSlow37 * (fSlow38 + 0.2568503f))) + 1.0f);
		float 	fSlow41 = (1.0f / fSlow40);
		float 	fSlow42 = max(0.05f, (0.1f - fabsf(fSlow30)));
		float 	fSlow43 = (fConst22 * (fSlow37 / fSlow40));
		float 	fSlow44 = (fConst23 * fSlow23);
		float 	fSlow45 = (0.0f - fSlow26);
		float 	fSlow46 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow47 = (fConst1 * fSlow46);
		float 	fSlow48 = (fConst2 * fSlow46);
		float 	fSlow49 = float(fslider9);
		float 	fSlow50 = ftbl2[int(((499.5f * (fSlow49 + 1.0f)) + 0.5f))];
		float 	fSlow51 = (fSlow50 + 1.0f);
		float 	fSlow52 = float(fslider10);
		float 	fSlow53 = float(fslider11);
		int 	iSlow54 = (fSlow53 == 0.0f);
		float 	fSlow55 = (0.0f - fSlow53);
		int 	iSlow56 = ((8.175799f * fSlow46) >= 8e+01f);
		float 	fSlow57 = powf((fConst19 * fSlow46),2.0f);
		float 	fSlow58 = ((fSlow57 * ((0.2033f * fSlow57) + 0.31755f)) + 1.0f);
		float 	fSlow59 = (2.0f * ((fConst20 * (powf(fSlow46,2.0f) * powf(fSlow58,2.0f))) + -1.0f));
		float 	fSlow60 = (fSlow46 * fSlow58);
		float 	fSlow61 = (fConst21 * fSlow60);
		float 	fSlow62 = ((fConst12 * (fSlow60 * (fSlow61 + -0.2568503f))) + 1.0f);
		float 	fSlow63 = ((fConst12 * (fSlow60 * (fSlow61 + 0.2568503f))) + 1.0f);
		float 	fSlow64 = (1.0f / fSlow63);
		float 	fSlow65 = max(0.05f, (0.1f - fabsf(fSlow53)));
		float 	fSlow66 = (fConst22 * (fSlow60 / fSlow63));
		float 	fSlow67 = (fConst23 * fSlow46);
		float 	fSlow68 = (0.0f - fSlow49);
		float 	fSlow69 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow70 = (fConst1 * fSlow69);
		float 	fSlow71 = (fConst2 * fSlow69);
		float 	fSlow72 = float(fslider13);
		float 	fSlow73 = ftbl2[int(((499.5f * (fSlow72 + 1.0f)) + 0.5f))];
		float 	fSlow74 = (fSlow73 + 1.0f);
		float 	fSlow75 = float(fslider14);
		float 	fSlow76 = float(fslider15);
		int 	iSlow77 = (fSlow76 == 0.0f);
		float 	fSlow78 = (0.0f - fSlow76);
		int 	iSlow79 = ((8.175799f * fSlow69) >= 8e+01f);
		float 	fSlow80 = powf((fConst19 * fSlow69),2.0f);
		float 	fSlow81 = ((fSlow80 * ((0.2033f * fSlow80) + 0.31755f)) + 1.0f);
		float 	fSlow82 = (2.0f * ((fConst20 * (powf(fSlow69,2.0f) * powf(fSlow81,2.0f))) + -1.0f));
		float 	fSlow83 = (fSlow69 * fSlow81);
		float 	fSlow84 = (fConst21 * fSlow83);
		float 	fSlow85 = ((fConst12 * (fSlow83 * (fSlow84 + -0.2568503f))) + 1.0f);
		float 	fSlow86 = ((fConst12 * (fSlow83 * (fSlow84 + 0.2568503f))) + 1.0f);
		float 	fSlow87 = (1.0f / fSlow86);
		float 	fSlow88 = max(0.05f, (0.1f - fabsf(fSlow76)));
		float 	fSlow89 = (fConst22 * (fSlow83 / fSlow86));
		float 	fSlow90 = (fConst23 * fSlow69);
		float 	fSlow91 = (0.0f - fSlow72);
		float 	fSlow92 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow93 = (fConst1 * fSlow92);
		float 	fSlow94 = (fConst2 * fSlow92);
		float 	fSlow95 = float(fslider17);
		float 	fSlow96 = ftbl2[int(((499.5f * (fSlow95 + 1.0f)) + 0.5f))];
		float 	fSlow97 = (fSlow96 + 1.0f);
		float 	fSlow98 = float(fslider18);
		float 	fSlow99 = float(fslider19);
		int 	iSlow100 = (fSlow99 == 0.0f);
		float 	fSlow101 = (0.0f - fSlow99);
		int 	iSlow102 = ((8.175799f * fSlow92) >= 8e+01f);
		float 	fSlow103 = powf((fConst19 * fSlow92),2.0f);
		float 	fSlow104 = ((fSlow103 * ((0.2033f * fSlow103) + 0.31755f)) + 1.0f);
		float 	fSlow105 = (2.0f * ((fConst20 * (powf(fSlow92,2.0f) * powf(fSlow104,2.0f))) + -1.0f));
		float 	fSlow106 = (fSlow92 * fSlow104);
		float 	fSlow107 = (fConst21 * fSlow106);
		float 	fSlow108 = ((fConst12 * (fSlow106 * (fSlow107 + -0.2568503f))) + 1.0f);
		float 	fSlow109 = ((fConst12 * (fSlow106 * (fSlow107 + 0.2568503f))) + 1.0f);
		float 	fSlow110 = (1.0f / fSlow109);
		float 	fSlow111 = max(0.05f, (0.1f - fabsf(fSlow99)));
		float 	fSlow112 = (fConst22 * (fSlow106 / fSlow109));
		float 	fSlow113 = (fConst23 * fSlow92);
		float 	fSlow114 = (0.0f - fSlow95);
		float 	fSlow115 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow116 = (fConst1 * fSlow115);
		float 	fSlow117 = (fConst2 * fSlow115);
		float 	fSlow118 = float(fslider21);
		float 	fSlow119 = ftbl2[int(((499.5f * (fSlow118 + 1.0f)) + 0.5f))];
		float 	fSlow120 = (fSlow119 + 1.0f);
		float 	fSlow121 = float(fslider22);
		float 	fSlow122 = float(fslider23);
		int 	iSlow123 = (fSlow122 == 0.0f);
		float 	fSlow124 = (0.0f - fSlow122);
		int 	iSlow125 = ((8.175799f * fSlow115) >= 8e+01f);
		float 	fSlow126 = powf((fConst19 * fSlow115),2.0f);
		float 	fSlow127 = ((fSlow126 * ((0.2033f * fSlow126) + 0.31755f)) + 1.0f);
		float 	fSlow128 = (2.0f * ((fConst20 * (powf(fSlow115,2.0f) * powf(fSlow127,2.0f))) + -1.0f));
		float 	fSlow129 = (fSlow115 * fSlow127);
		float 	fSlow130 = (fConst21 * fSlow129);
		float 	fSlow131 = ((fConst12 * (fSlow129 * (fSlow130 + -0.2568503f))) + 1.0f);
		float 	fSlow132 = ((fConst12 * (fSlow129 * (fSlow130 + 0.2568503f))) + 1.0f);
		float 	fSlow133 = (1.0f / fSlow132);
		float 	fSlow134 = max(0.05f, (0.1f - fabsf(fSlow122)));
		float 	fSlow135 = (fConst22 * (fSlow129 / fSlow132));
		float 	fSlow136 = (fConst23 * fSlow115);
		float 	fSlow137 = (0.0f - fSlow118);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp2 = (1 - iVec0[1]);
			float 	fTemp3 = ((iTemp2) ? 0.0f : (fSlow1 + fRec1[1]));
			fRec1[0] = (fTemp3 - floorf(fTemp3));
			float 	fTemp4 = (499.0f * fRec1[0]);
			int 	iTemp5 = int(fTemp4);
			float 	fTemp6 = ftbl0[max(0, min(iTemp5, 499))];
			float 	fTemp7 = ((iTemp2) ? 0.0f : (fSlow2 + fRec3[1]));
			fRec3[0] = (fTemp7 - floorf(fTemp7));
			float 	fTemp8 = (499.0f * fRec3[0]);
			int 	iTemp9 = int(fTemp8);
			float 	fTemp10 = ftbl1[max(0, min(iTemp9, 499))];
			fVec1[0] = fSlow7;
			int 	iTemp12 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp12;
			int 	iTemp13 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec9[0] = (iRec9[1] + 1);
			int 	iTemp14 = (iRec9[0] + -1);
			iRec8[0] = ((iRec8[1] * (1 - iTemp13)) + (iTemp14 * iTemp13));
			float 	fTemp15 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec8[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp15;
			int 	iTemp16 = (fVec3[0] > 0.003f);
			int 	iTemp17 = (fVec3[0] <= 0.003f);
			float 	fTemp18 = float((iTemp17 | (fVec3[1] >= 0.003f)));
			fRec10[0] = max((fRec10[1] * fTemp18), fSlow7);
			fRec11[0] = max((fTemp18 * fRec11[1]), fSlow9);
			float 	fTemp19 = (min(1.0f, fRec11[0]) + min(1.0f, fRec10[0]));
			int 	iTemp20 = (fVec3[0] >= fRec7[1]);
			int 	iTemp21 = (fRec7[1] <= 0.001f);
			int 	iTemp22 = (((iRec6[1] >= 4)) ? (((iRec6[1] >= 6)) ? ((iTemp21) ? 0 : ((iTemp16) ? 1 : 6)) : (((iRec6[1] >= 5)) ? ((iTemp17) ? 3 : ((iTemp20) ? 4 : 5)) : ((iTemp17) ? 3 : (((fVec3[0] <= fRec7[1])) ? 5 : 4)))) : (((iRec6[1] >= 2)) ? (((iRec6[1] >= 3)) ? (((iTemp17 & iTemp21)) ? 0 : ((iTemp16) ? 1 : 3)) : ((iTemp16) ? ((iTemp20) ? 4 : 2) : 6)) : (((iRec6[1] >= 1)) ? (((fRec7[1] >= min(fTemp19, 1.0f))) ? ((iTemp17) ? 6 : 2) : 1) : ((iTemp16) ? 1 : 0))));
			iRec6[0] = iTemp22;
			float 	fTemp24 = (((iTemp22 >= 4)) ? (((iTemp22 >= 6)) ? fConst17 : fConst16) : (((iTemp22 >= 2)) ? (((iTemp22 >= 3)) ? fConst15 : fConst14) : (((iTemp22 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp25 = (iRec6[1] != iRec6[2]);
			iVec4[0] = iTemp25;
			int 	iTemp26 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec14[0] = ((iRec14[1] * (1 - iTemp26)) + (iTemp14 * iTemp26));
			float 	fTemp27 = (2e+01f * (((fTemp24 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec14[0]))) / fTemp24) : 0.0f));
			int 	iTemp28 = int(fTemp27);
			float 	fTemp29 = ftbl3[max(0, int(min(int(iTemp28), 20)))];
			float 	fTemp30 = (fTemp29 + ((fTemp27 - float(iTemp28)) * (ftbl3[max(0, int(min(int((iTemp28 + 1)), 20)))] - fTemp29)));
			fRec15[0] = max((fRec15[1] * float(iVec4[0])), max(fVec3[0], fRec7[1]));
			int 	iTemp31 = (iRec6[1] == 3);
			int 	iTemp32 = (iRec6[1] == 6);
			int 	iTemp33 = (iRec6[1] == 0);
			float 	fTemp34 = (((iRec6[1] == 1)) ? min(1.0f, fTemp19) : ((iTemp33) ? 0.0f : ((iTemp32) ? (fTemp19 * fTemp30) : ((iTemp31) ? (fRec15[0] * fTemp30) : fVec3[0]))));
			float 	fTemp35 = (1.0f / ((iTemp33) ? 0.0001f : (((iTemp31 | iTemp32)) ? (0.04761905f * fTemp24) : fTemp24)));
			float 	fTemp36 = (fRec12[1] - fTemp35);
			float 	fTemp37 = (fRec12[1] + fTemp35);
			fRec12[0] = (((fTemp37 < fTemp34)) ? fTemp37 : (((fTemp36 > fTemp34)) ? fTemp36 : fTemp34));
			fRec7[0] = fRec12[0];
			fRec5[0] = (fRec7[0] - (fConst11 * ((fConst9 * fRec5[2]) + (fConst7 * fRec5[1]))));
			float 	fTemp38 = min(0.99f, (fConst18 * (((3947.8418f * fRec5[0]) + (7895.6836f * fRec5[1])) + (3947.8418f * fRec5[2]))));
			int 	iTemp39 = (fTemp38 < 0.1f);
			float 	fTemp40 = (((iSlow10) ? ((iTemp39) ? fTemp38 : 0.1f) : 0.0f) * fSlow5);
			iRec17[0] = ((1103515245 * iRec17[1]) + 12345);
			float 	fTemp41 = (4.656613e-10f * float(iRec17[0]));
			fRec16[0] = (fTemp41 - (fSlow18 * ((fSlow16 * fRec16[2]) + (fSlow13 * fRec16[1]))));
			float 	fTemp42 = min(1.0f, (fSlow19 + ((iTemp39) ? (1.0f - (1e+01f * fTemp38)) : 0.0f)));
			float 	fTemp43 = ((iTemp2) ? 0.0f : (fSlow21 + fRec19[1]));
			fRec19[0] = (fTemp43 - floorf(fTemp43));
			float 	fTemp44 = (499.0f * fRec19[0]);
			int 	iTemp45 = int(fTemp44);
			int 	iTemp46 = max(0, min(iTemp45, 499));
			float 	fTemp47 = ftbl1[iTemp46];
			int 	iTemp48 = max(0, min((iTemp45 + 1), 499));
			float 	fTemp49 = (fTemp44 - float(iTemp45));
			float 	fTemp50 = float((((fVec3[1] <= 0.003f) & iTemp16) != 1));
			fRec20[0] = max((fTemp50 * fRec20[1]), fSlow22);
			fRec21[0] = max((fRec21[1] * fTemp50), fSlow3);
			float 	fTemp51 = max(min(((0.5f * (fVec3[0] - fTemp38)) + (0.2f - (0.8f * ((iTemp17) ? (2.0f * (((fRec21[0] > fRec20[0])) ? fRec21[0] : (0.0f - fRec20[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp52 = ftbl0[iTemp46];
			float 	fTemp53 = (((fTemp52 + (fTemp49 * (ftbl0[iTemp48] - fTemp52))) * (1.0f - fTemp51)) + (fTemp51 * (fTemp47 + (fTemp49 * (ftbl1[iTemp48] - fTemp47)))));
			float 	fTemp54 = (fRec18[1] - fConst24);
			float 	fTemp55 = (fConst24 + fRec18[1]);
			fRec18[0] = (((fTemp55 < fTemp53)) ? fTemp55 : (((fTemp54 > fTemp53)) ? fTemp54 : fTemp53));
			float 	fTemp56 = ((iTemp2) ? 0.0f : (fSlow24 + fRec22[1]));
			fRec22[0] = (fTemp56 - floorf(fTemp56));
			float 	fTemp57 = (499.0f * fRec22[0]);
			int 	iTemp58 = int(fTemp57);
			float 	fTemp59 = ftbl0[max(0, min(iTemp58, 499))];
			float 	fTemp60 = ((iTemp2) ? 0.0f : (fSlow25 + fRec23[1]));
			fRec23[0] = (fTemp60 - floorf(fTemp60));
			float 	fTemp61 = (499.0f * fRec23[0]);
			int 	iTemp62 = int(fTemp61);
			float 	fTemp63 = ftbl1[max(0, min(iTemp62, 499))];
			fVec5[0] = fSlow30;
			int 	iTemp64 = (fSlow30 != fVec5[1]);
			iVec6[0] = iTemp64;
			int 	iTemp65 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec27[0] = ((iRec27[1] * (1 - iTemp65)) + (iTemp14 * iTemp65));
			float 	fTemp66 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec27[0])))) > 0.5f) & iSlow31)) ? 0.0f : fSlow29) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp66;
			int 	iTemp67 = (fVec7[0] > 0.003f);
			int 	iTemp68 = (fVec7[0] <= 0.003f);
			float 	fTemp69 = float((iTemp68 | (fVec7[1] >= 0.003f)));
			fRec28[0] = max((fRec28[1] * fTemp69), fSlow30);
			fRec29[0] = max((fTemp69 * fRec29[1]), fSlow32);
			float 	fTemp70 = (min(1.0f, fRec29[0]) + min(1.0f, fRec28[0]));
			int 	iTemp71 = (fVec7[0] >= fRec26[1]);
			int 	iTemp72 = (fRec26[1] <= 0.001f);
			int 	iTemp73 = (((iRec25[1] >= 4)) ? (((iRec25[1] >= 6)) ? ((iTemp72) ? 0 : ((iTemp67) ? 1 : 6)) : (((iRec25[1] >= 5)) ? ((iTemp68) ? 3 : ((iTemp71) ? 4 : 5)) : ((iTemp68) ? 3 : (((fVec7[0] <= fRec26[1])) ? 5 : 4)))) : (((iRec25[1] >= 2)) ? (((iRec25[1] >= 3)) ? (((iTemp68 & iTemp72)) ? 0 : ((iTemp67) ? 1 : 3)) : ((iTemp67) ? ((iTemp71) ? 4 : 2) : 6)) : (((iRec25[1] >= 1)) ? (((fRec26[1] >= min(fTemp70, 1.0f))) ? ((iTemp68) ? 6 : 2) : 1) : ((iTemp67) ? 1 : 0))));
			iRec25[0] = iTemp73;
			float 	fTemp74 = (((iTemp73 >= 4)) ? (((iTemp73 >= 6)) ? fConst17 : fConst16) : (((iTemp73 >= 2)) ? (((iTemp73 >= 3)) ? fConst15 : fConst14) : (((iTemp73 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp75 = (iRec25[1] != iRec25[2]);
			iVec8[0] = iTemp75;
			int 	iTemp76 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec31[0] = ((iRec31[1] * (1 - iTemp76)) + (iTemp14 * iTemp76));
			float 	fTemp77 = (2e+01f * (((fTemp74 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec31[0]))) / fTemp74) : 0.0f));
			int 	iTemp78 = int(fTemp77);
			float 	fTemp79 = ftbl3[max(0, int(min(int(iTemp78), 20)))];
			float 	fTemp80 = (fTemp79 + ((fTemp77 - float(iTemp78)) * (ftbl3[max(0, int(min(int((iTemp78 + 1)), 20)))] - fTemp79)));
			fRec32[0] = max((fRec32[1] * float(iVec8[0])), max(fVec7[0], fRec26[1]));
			int 	iTemp81 = (iRec25[1] == 3);
			int 	iTemp82 = (iRec25[1] == 6);
			int 	iTemp83 = (iRec25[1] == 0);
			float 	fTemp84 = (((iRec25[1] == 1)) ? min(1.0f, fTemp70) : ((iTemp83) ? 0.0f : ((iTemp82) ? (fTemp70 * fTemp80) : ((iTemp81) ? (fRec32[0] * fTemp80) : fVec7[0]))));
			float 	fTemp85 = (1.0f / ((iTemp83) ? 0.0001f : (((iTemp81 | iTemp82)) ? (0.04761905f * fTemp74) : fTemp74)));
			float 	fTemp86 = (fRec30[1] - fTemp85);
			float 	fTemp87 = (fRec30[1] + fTemp85);
			fRec30[0] = (((fTemp87 < fTemp84)) ? fTemp87 : (((fTemp86 > fTemp84)) ? fTemp86 : fTemp84));
			fRec26[0] = fRec30[0];
			fRec24[0] = (fRec26[0] - (fConst11 * ((fConst9 * fRec24[2]) + (fConst7 * fRec24[1]))));
			float 	fTemp88 = min(0.99f, (fConst18 * (((3947.8418f * fRec24[0]) + (7895.6836f * fRec24[1])) + (3947.8418f * fRec24[2]))));
			int 	iTemp89 = (fTemp88 < 0.1f);
			float 	fTemp90 = (((iSlow33) ? ((iTemp89) ? fTemp88 : 0.1f) : 0.0f) * fSlow28);
			fRec33[0] = (fTemp41 - (fSlow41 * ((fSlow39 * fRec33[2]) + (fSlow36 * fRec33[1]))));
			float 	fTemp91 = min(1.0f, (fSlow42 + ((iTemp89) ? (1.0f - (1e+01f * fTemp88)) : 0.0f)));
			float 	fTemp92 = ((iTemp2) ? 0.0f : (fSlow44 + fRec35[1]));
			fRec35[0] = (fTemp92 - floorf(fTemp92));
			float 	fTemp93 = (499.0f * fRec35[0]);
			int 	iTemp94 = int(fTemp93);
			int 	iTemp95 = max(0, min(iTemp94, 499));
			float 	fTemp96 = ftbl1[iTemp95];
			int 	iTemp97 = max(0, min((iTemp94 + 1), 499));
			float 	fTemp98 = (fTemp93 - float(iTemp94));
			float 	fTemp99 = float((((fVec7[1] <= 0.003f) & iTemp67) != 1));
			fRec36[0] = max((fTemp99 * fRec36[1]), fSlow45);
			fRec37[0] = max((fRec37[1] * fTemp99), fSlow26);
			float 	fTemp100 = max(min(((0.5f * (fVec7[0] - fTemp88)) + (0.2f - (0.8f * ((iTemp68) ? (2.0f * (((fRec37[0] > fRec36[0])) ? fRec37[0] : (0.0f - fRec36[0]))) : fSlow27)))), 1.0f), 0.0f);
			float 	fTemp101 = ftbl0[iTemp95];
			float 	fTemp102 = (((fTemp101 + (fTemp98 * (ftbl0[iTemp97] - fTemp101))) * (1.0f - fTemp100)) + (fTemp100 * (fTemp96 + (fTemp98 * (ftbl1[iTemp97] - fTemp96)))));
			float 	fTemp103 = (fRec34[1] - fConst24);
			float 	fTemp104 = (fConst24 + fRec34[1]);
			fRec34[0] = (((fTemp104 < fTemp102)) ? fTemp104 : (((fTemp103 > fTemp102)) ? fTemp103 : fTemp102));
			float 	fTemp105 = ((iTemp2) ? 0.0f : (fSlow47 + fRec38[1]));
			fRec38[0] = (fTemp105 - floorf(fTemp105));
			float 	fTemp106 = (499.0f * fRec38[0]);
			int 	iTemp107 = int(fTemp106);
			float 	fTemp108 = ftbl0[max(0, min(iTemp107, 499))];
			float 	fTemp109 = ((iTemp2) ? 0.0f : (fSlow48 + fRec39[1]));
			fRec39[0] = (fTemp109 - floorf(fTemp109));
			float 	fTemp110 = (499.0f * fRec39[0]);
			int 	iTemp111 = int(fTemp110);
			float 	fTemp112 = ftbl1[max(0, min(iTemp111, 499))];
			fVec9[0] = fSlow53;
			int 	iTemp113 = (fSlow53 != fVec9[1]);
			iVec10[0] = iTemp113;
			int 	iTemp114 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec43[0] = ((iRec43[1] * (1 - iTemp114)) + (iTemp14 * iTemp114));
			float 	fTemp115 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec43[0])))) > 0.5f) & iSlow54)) ? 0.0f : fSlow52) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp115;
			int 	iTemp116 = (fVec11[0] > 0.003f);
			int 	iTemp117 = (fVec11[0] <= 0.003f);
			float 	fTemp118 = float((iTemp117 | (fVec11[1] >= 0.003f)));
			fRec44[0] = max((fRec44[1] * fTemp118), fSlow53);
			fRec45[0] = max((fTemp118 * fRec45[1]), fSlow55);
			float 	fTemp119 = (min(1.0f, fRec45[0]) + min(1.0f, fRec44[0]));
			int 	iTemp120 = (fVec11[0] >= fRec42[1]);
			int 	iTemp121 = (fRec42[1] <= 0.001f);
			int 	iTemp122 = (((iRec41[1] >= 4)) ? (((iRec41[1] >= 6)) ? ((iTemp121) ? 0 : ((iTemp116) ? 1 : 6)) : (((iRec41[1] >= 5)) ? ((iTemp117) ? 3 : ((iTemp120) ? 4 : 5)) : ((iTemp117) ? 3 : (((fVec11[0] <= fRec42[1])) ? 5 : 4)))) : (((iRec41[1] >= 2)) ? (((iRec41[1] >= 3)) ? (((iTemp117 & iTemp121)) ? 0 : ((iTemp116) ? 1 : 3)) : ((iTemp116) ? ((iTemp120) ? 4 : 2) : 6)) : (((iRec41[1] >= 1)) ? (((fRec42[1] >= min(fTemp119, 1.0f))) ? ((iTemp117) ? 6 : 2) : 1) : ((iTemp116) ? 1 : 0))));
			iRec41[0] = iTemp122;
			float 	fTemp123 = (((iTemp122 >= 4)) ? (((iTemp122 >= 6)) ? fConst17 : fConst16) : (((iTemp122 >= 2)) ? (((iTemp122 >= 3)) ? fConst15 : fConst14) : (((iTemp122 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp124 = (iRec41[1] != iRec41[2]);
			iVec12[0] = iTemp124;
			int 	iTemp125 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec47[0] = ((iRec47[1] * (1 - iTemp125)) + (iTemp14 * iTemp125));
			float 	fTemp126 = (2e+01f * (((fTemp123 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec47[0]))) / fTemp123) : 0.0f));
			int 	iTemp127 = int(fTemp126);
			float 	fTemp128 = ftbl3[max(0, int(min(int(iTemp127), 20)))];
			float 	fTemp129 = (fTemp128 + ((fTemp126 - float(iTemp127)) * (ftbl3[max(0, int(min(int((iTemp127 + 1)), 20)))] - fTemp128)));
			fRec48[0] = max((fRec48[1] * float(iVec12[0])), max(fVec11[0], fRec42[1]));
			int 	iTemp130 = (iRec41[1] == 3);
			int 	iTemp131 = (iRec41[1] == 6);
			int 	iTemp132 = (iRec41[1] == 0);
			float 	fTemp133 = (((iRec41[1] == 1)) ? min(1.0f, fTemp119) : ((iTemp132) ? 0.0f : ((iTemp131) ? (fTemp119 * fTemp129) : ((iTemp130) ? (fRec48[0] * fTemp129) : fVec11[0]))));
			float 	fTemp134 = (1.0f / ((iTemp132) ? 0.0001f : (((iTemp130 | iTemp131)) ? (0.04761905f * fTemp123) : fTemp123)));
			float 	fTemp135 = (fRec46[1] - fTemp134);
			float 	fTemp136 = (fRec46[1] + fTemp134);
			fRec46[0] = (((fTemp136 < fTemp133)) ? fTemp136 : (((fTemp135 > fTemp133)) ? fTemp135 : fTemp133));
			fRec42[0] = fRec46[0];
			fRec40[0] = (fRec42[0] - (fConst11 * ((fConst9 * fRec40[2]) + (fConst7 * fRec40[1]))));
			float 	fTemp137 = min(0.99f, (fConst18 * (((3947.8418f * fRec40[0]) + (7895.6836f * fRec40[1])) + (3947.8418f * fRec40[2]))));
			int 	iTemp138 = (fTemp137 < 0.1f);
			float 	fTemp139 = (((iSlow56) ? ((iTemp138) ? fTemp137 : 0.1f) : 0.0f) * fSlow51);
			fRec49[0] = (fTemp41 - (fSlow64 * ((fSlow62 * fRec49[2]) + (fSlow59 * fRec49[1]))));
			float 	fTemp140 = min(1.0f, (fSlow65 + ((iTemp138) ? (1.0f - (1e+01f * fTemp137)) : 0.0f)));
			float 	fTemp141 = ((iTemp2) ? 0.0f : (fSlow67 + fRec51[1]));
			fRec51[0] = (fTemp141 - floorf(fTemp141));
			float 	fTemp142 = (499.0f * fRec51[0]);
			int 	iTemp143 = int(fTemp142);
			int 	iTemp144 = max(0, min(iTemp143, 499));
			float 	fTemp145 = ftbl1[iTemp144];
			int 	iTemp146 = max(0, min((iTemp143 + 1), 499));
			float 	fTemp147 = (fTemp142 - float(iTemp143));
			float 	fTemp148 = float((((fVec11[1] <= 0.003f) & iTemp116) != 1));
			fRec52[0] = max((fTemp148 * fRec52[1]), fSlow68);
			fRec53[0] = max((fRec53[1] * fTemp148), fSlow49);
			float 	fTemp149 = max(min(((0.5f * (fVec11[0] - fTemp137)) + (0.2f - (0.8f * ((iTemp117) ? (2.0f * (((fRec53[0] > fRec52[0])) ? fRec53[0] : (0.0f - fRec52[0]))) : fSlow50)))), 1.0f), 0.0f);
			float 	fTemp150 = ftbl0[iTemp144];
			float 	fTemp151 = (((fTemp150 + (fTemp147 * (ftbl0[iTemp146] - fTemp150))) * (1.0f - fTemp149)) + (fTemp149 * (fTemp145 + (fTemp147 * (ftbl1[iTemp146] - fTemp145)))));
			float 	fTemp152 = (fRec50[1] - fConst24);
			float 	fTemp153 = (fConst24 + fRec50[1]);
			fRec50[0] = (((fTemp153 < fTemp151)) ? fTemp153 : (((fTemp152 > fTemp151)) ? fTemp152 : fTemp151));
			float 	fTemp154 = ((iTemp2) ? 0.0f : (fSlow70 + fRec54[1]));
			fRec54[0] = (fTemp154 - floorf(fTemp154));
			float 	fTemp155 = (499.0f * fRec54[0]);
			int 	iTemp156 = int(fTemp155);
			float 	fTemp157 = ftbl0[max(0, min(iTemp156, 499))];
			float 	fTemp158 = ((iTemp2) ? 0.0f : (fSlow71 + fRec55[1]));
			fRec55[0] = (fTemp158 - floorf(fTemp158));
			float 	fTemp159 = (499.0f * fRec55[0]);
			int 	iTemp160 = int(fTemp159);
			float 	fTemp161 = ftbl1[max(0, min(iTemp160, 499))];
			fVec13[0] = fSlow76;
			int 	iTemp162 = (fSlow76 != fVec13[1]);
			iVec14[0] = iTemp162;
			int 	iTemp163 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec59[0] = ((iRec59[1] * (1 - iTemp163)) + (iTemp14 * iTemp163));
			float 	fTemp164 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec59[0])))) > 0.5f) & iSlow77)) ? 0.0f : fSlow75) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp164;
			int 	iTemp165 = (fVec15[0] > 0.003f);
			int 	iTemp166 = (fVec15[0] <= 0.003f);
			float 	fTemp167 = float((iTemp166 | (fVec15[1] >= 0.003f)));
			fRec60[0] = max((fRec60[1] * fTemp167), fSlow76);
			fRec61[0] = max((fTemp167 * fRec61[1]), fSlow78);
			float 	fTemp168 = (min(1.0f, fRec61[0]) + min(1.0f, fRec60[0]));
			int 	iTemp169 = (fVec15[0] >= fRec58[1]);
			int 	iTemp170 = (fRec58[1] <= 0.001f);
			int 	iTemp171 = (((iRec57[1] >= 4)) ? (((iRec57[1] >= 6)) ? ((iTemp170) ? 0 : ((iTemp165) ? 1 : 6)) : (((iRec57[1] >= 5)) ? ((iTemp166) ? 3 : ((iTemp169) ? 4 : 5)) : ((iTemp166) ? 3 : (((fVec15[0] <= fRec58[1])) ? 5 : 4)))) : (((iRec57[1] >= 2)) ? (((iRec57[1] >= 3)) ? (((iTemp166 & iTemp170)) ? 0 : ((iTemp165) ? 1 : 3)) : ((iTemp165) ? ((iTemp169) ? 4 : 2) : 6)) : (((iRec57[1] >= 1)) ? (((fRec58[1] >= min(fTemp168, 1.0f))) ? ((iTemp166) ? 6 : 2) : 1) : ((iTemp165) ? 1 : 0))));
			iRec57[0] = iTemp171;
			float 	fTemp172 = (((iTemp171 >= 4)) ? (((iTemp171 >= 6)) ? fConst17 : fConst16) : (((iTemp171 >= 2)) ? (((iTemp171 >= 3)) ? fConst15 : fConst14) : (((iTemp171 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp173 = (iRec57[1] != iRec57[2]);
			iVec16[0] = iTemp173;
			int 	iTemp174 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec63[0] = ((iRec63[1] * (1 - iTemp174)) + (iTemp14 * iTemp174));
			float 	fTemp175 = (2e+01f * (((fTemp172 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec63[0]))) / fTemp172) : 0.0f));
			int 	iTemp176 = int(fTemp175);
			float 	fTemp177 = ftbl3[max(0, int(min(int(iTemp176), 20)))];
			float 	fTemp178 = (fTemp177 + ((fTemp175 - float(iTemp176)) * (ftbl3[max(0, int(min(int((iTemp176 + 1)), 20)))] - fTemp177)));
			fRec64[0] = max((fRec64[1] * float(iVec16[0])), max(fVec15[0], fRec58[1]));
			int 	iTemp179 = (iRec57[1] == 3);
			int 	iTemp180 = (iRec57[1] == 6);
			int 	iTemp181 = (iRec57[1] == 0);
			float 	fTemp182 = (((iRec57[1] == 1)) ? min(1.0f, fTemp168) : ((iTemp181) ? 0.0f : ((iTemp180) ? (fTemp168 * fTemp178) : ((iTemp179) ? (fRec64[0] * fTemp178) : fVec15[0]))));
			float 	fTemp183 = (1.0f / ((iTemp181) ? 0.0001f : (((iTemp179 | iTemp180)) ? (0.04761905f * fTemp172) : fTemp172)));
			float 	fTemp184 = (fRec62[1] - fTemp183);
			float 	fTemp185 = (fRec62[1] + fTemp183);
			fRec62[0] = (((fTemp185 < fTemp182)) ? fTemp185 : (((fTemp184 > fTemp182)) ? fTemp184 : fTemp182));
			fRec58[0] = fRec62[0];
			fRec56[0] = (fRec58[0] - (fConst11 * ((fConst9 * fRec56[2]) + (fConst7 * fRec56[1]))));
			float 	fTemp186 = min(0.99f, (fConst18 * (((3947.8418f * fRec56[0]) + (7895.6836f * fRec56[1])) + (3947.8418f * fRec56[2]))));
			int 	iTemp187 = (fTemp186 < 0.1f);
			float 	fTemp188 = (((iSlow79) ? ((iTemp187) ? fTemp186 : 0.1f) : 0.0f) * fSlow74);
			fRec65[0] = (fTemp41 - (fSlow87 * ((fSlow85 * fRec65[2]) + (fSlow82 * fRec65[1]))));
			float 	fTemp189 = min(1.0f, (fSlow88 + ((iTemp187) ? (1.0f - (1e+01f * fTemp186)) : 0.0f)));
			float 	fTemp190 = ((iTemp2) ? 0.0f : (fSlow90 + fRec67[1]));
			fRec67[0] = (fTemp190 - floorf(fTemp190));
			float 	fTemp191 = (499.0f * fRec67[0]);
			int 	iTemp192 = int(fTemp191);
			int 	iTemp193 = max(0, min(iTemp192, 499));
			float 	fTemp194 = ftbl1[iTemp193];
			int 	iTemp195 = max(0, min((iTemp192 + 1), 499));
			float 	fTemp196 = (fTemp191 - float(iTemp192));
			float 	fTemp197 = float((((fVec15[1] <= 0.003f) & iTemp165) != 1));
			fRec68[0] = max((fTemp197 * fRec68[1]), fSlow91);
			fRec69[0] = max((fRec69[1] * fTemp197), fSlow72);
			float 	fTemp198 = max(min(((0.5f * (fVec15[0] - fTemp186)) + (0.2f - (0.8f * ((iTemp166) ? (2.0f * (((fRec69[0] > fRec68[0])) ? fRec69[0] : (0.0f - fRec68[0]))) : fSlow73)))), 1.0f), 0.0f);
			float 	fTemp199 = ftbl0[iTemp193];
			float 	fTemp200 = (((fTemp199 + (fTemp196 * (ftbl0[iTemp195] - fTemp199))) * (1.0f - fTemp198)) + (fTemp198 * (fTemp194 + (fTemp196 * (ftbl1[iTemp195] - fTemp194)))));
			float 	fTemp201 = (fRec66[1] - fConst24);
			float 	fTemp202 = (fConst24 + fRec66[1]);
			fRec66[0] = (((fTemp202 < fTemp200)) ? fTemp202 : (((fTemp201 > fTemp200)) ? fTemp201 : fTemp200));
			float 	fTemp203 = ((iTemp2) ? 0.0f : (fSlow93 + fRec70[1]));
			fRec70[0] = (fTemp203 - floorf(fTemp203));
			float 	fTemp204 = (499.0f * fRec70[0]);
			int 	iTemp205 = int(fTemp204);
			float 	fTemp206 = ftbl0[max(0, min(iTemp205, 499))];
			float 	fTemp207 = ((iTemp2) ? 0.0f : (fSlow94 + fRec71[1]));
			fRec71[0] = (fTemp207 - floorf(fTemp207));
			float 	fTemp208 = (499.0f * fRec71[0]);
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl1[max(0, min(iTemp209, 499))];
			fVec17[0] = fSlow99;
			int 	iTemp211 = (fSlow99 != fVec17[1]);
			iVec18[0] = iTemp211;
			int 	iTemp212 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec75[0] = ((iRec75[1] * (1 - iTemp212)) + (iTemp14 * iTemp212));
			float 	fTemp213 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec75[0])))) > 0.5f) & iSlow100)) ? 0.0f : fSlow98) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp213;
			int 	iTemp214 = (fVec19[0] > 0.003f);
			int 	iTemp215 = (fVec19[0] <= 0.003f);
			float 	fTemp216 = float((iTemp215 | (fVec19[1] >= 0.003f)));
			fRec76[0] = max((fRec76[1] * fTemp216), fSlow99);
			fRec77[0] = max((fTemp216 * fRec77[1]), fSlow101);
			float 	fTemp217 = (min(1.0f, fRec77[0]) + min(1.0f, fRec76[0]));
			int 	iTemp218 = (fVec19[0] >= fRec74[1]);
			int 	iTemp219 = (fRec74[1] <= 0.001f);
			int 	iTemp220 = (((iRec73[1] >= 4)) ? (((iRec73[1] >= 6)) ? ((iTemp219) ? 0 : ((iTemp214) ? 1 : 6)) : (((iRec73[1] >= 5)) ? ((iTemp215) ? 3 : ((iTemp218) ? 4 : 5)) : ((iTemp215) ? 3 : (((fVec19[0] <= fRec74[1])) ? 5 : 4)))) : (((iRec73[1] >= 2)) ? (((iRec73[1] >= 3)) ? (((iTemp215 & iTemp219)) ? 0 : ((iTemp214) ? 1 : 3)) : ((iTemp214) ? ((iTemp218) ? 4 : 2) : 6)) : (((iRec73[1] >= 1)) ? (((fRec74[1] >= min(fTemp217, 1.0f))) ? ((iTemp215) ? 6 : 2) : 1) : ((iTemp214) ? 1 : 0))));
			iRec73[0] = iTemp220;
			float 	fTemp221 = (((iTemp220 >= 4)) ? (((iTemp220 >= 6)) ? fConst17 : fConst16) : (((iTemp220 >= 2)) ? (((iTemp220 >= 3)) ? fConst15 : fConst14) : (((iTemp220 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp222 = (iRec73[1] != iRec73[2]);
			iVec20[0] = iTemp222;
			int 	iTemp223 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec79[0] = ((iRec79[1] * (1 - iTemp223)) + (iTemp14 * iTemp223));
			float 	fTemp224 = (2e+01f * (((fTemp221 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec79[0]))) / fTemp221) : 0.0f));
			int 	iTemp225 = int(fTemp224);
			float 	fTemp226 = ftbl3[max(0, int(min(int(iTemp225), 20)))];
			float 	fTemp227 = (fTemp226 + ((fTemp224 - float(iTemp225)) * (ftbl3[max(0, int(min(int((iTemp225 + 1)), 20)))] - fTemp226)));
			fRec80[0] = max((fRec80[1] * float(iVec20[0])), max(fVec19[0], fRec74[1]));
			int 	iTemp228 = (iRec73[1] == 3);
			int 	iTemp229 = (iRec73[1] == 6);
			int 	iTemp230 = (iRec73[1] == 0);
			float 	fTemp231 = (((iRec73[1] == 1)) ? min(1.0f, fTemp217) : ((iTemp230) ? 0.0f : ((iTemp229) ? (fTemp217 * fTemp227) : ((iTemp228) ? (fRec80[0] * fTemp227) : fVec19[0]))));
			float 	fTemp232 = (1.0f / ((iTemp230) ? 0.0001f : (((iTemp228 | iTemp229)) ? (0.04761905f * fTemp221) : fTemp221)));
			float 	fTemp233 = (fRec78[1] - fTemp232);
			float 	fTemp234 = (fRec78[1] + fTemp232);
			fRec78[0] = (((fTemp234 < fTemp231)) ? fTemp234 : (((fTemp233 > fTemp231)) ? fTemp233 : fTemp231));
			fRec74[0] = fRec78[0];
			fRec72[0] = (fRec74[0] - (fConst11 * ((fConst9 * fRec72[2]) + (fConst7 * fRec72[1]))));
			float 	fTemp235 = min(0.99f, (fConst18 * (((3947.8418f * fRec72[0]) + (7895.6836f * fRec72[1])) + (3947.8418f * fRec72[2]))));
			int 	iTemp236 = (fTemp235 < 0.1f);
			float 	fTemp237 = (((iSlow102) ? ((iTemp236) ? fTemp235 : 0.1f) : 0.0f) * fSlow97);
			fRec81[0] = (fTemp41 - (fSlow110 * ((fSlow108 * fRec81[2]) + (fSlow105 * fRec81[1]))));
			float 	fTemp238 = min(1.0f, (fSlow111 + ((iTemp236) ? (1.0f - (1e+01f * fTemp235)) : 0.0f)));
			float 	fTemp239 = ((iTemp2) ? 0.0f : (fSlow113 + fRec83[1]));
			fRec83[0] = (fTemp239 - floorf(fTemp239));
			float 	fTemp240 = (499.0f * fRec83[0]);
			int 	iTemp241 = int(fTemp240);
			int 	iTemp242 = max(0, min(iTemp241, 499));
			float 	fTemp243 = ftbl1[iTemp242];
			int 	iTemp244 = max(0, min((iTemp241 + 1), 499));
			float 	fTemp245 = (fTemp240 - float(iTemp241));
			float 	fTemp246 = float((((fVec19[1] <= 0.003f) & iTemp214) != 1));
			fRec84[0] = max((fTemp246 * fRec84[1]), fSlow114);
			fRec85[0] = max((fRec85[1] * fTemp246), fSlow95);
			float 	fTemp247 = max(min(((0.5f * (fVec19[0] - fTemp235)) + (0.2f - (0.8f * ((iTemp215) ? (2.0f * (((fRec85[0] > fRec84[0])) ? fRec85[0] : (0.0f - fRec84[0]))) : fSlow96)))), 1.0f), 0.0f);
			float 	fTemp248 = ftbl0[iTemp242];
			float 	fTemp249 = (((fTemp248 + (fTemp245 * (ftbl0[iTemp244] - fTemp248))) * (1.0f - fTemp247)) + (fTemp247 * (fTemp243 + (fTemp245 * (ftbl1[iTemp244] - fTemp243)))));
			float 	fTemp250 = (fRec82[1] - fConst24);
			float 	fTemp251 = (fConst24 + fRec82[1]);
			fRec82[0] = (((fTemp251 < fTemp249)) ? fTemp251 : (((fTemp250 > fTemp249)) ? fTemp250 : fTemp249));
			float 	fTemp252 = ((iTemp2) ? 0.0f : (fSlow116 + fRec86[1]));
			fRec86[0] = (fTemp252 - floorf(fTemp252));
			float 	fTemp253 = (499.0f * fRec86[0]);
			int 	iTemp254 = int(fTemp253);
			float 	fTemp255 = ftbl0[max(0, min(iTemp254, 499))];
			float 	fTemp256 = ((iTemp2) ? 0.0f : (fSlow117 + fRec87[1]));
			fRec87[0] = (fTemp256 - floorf(fTemp256));
			float 	fTemp257 = (499.0f * fRec87[0]);
			int 	iTemp258 = int(fTemp257);
			float 	fTemp259 = ftbl1[max(0, min(iTemp258, 499))];
			fVec21[0] = fSlow122;
			int 	iTemp260 = (fSlow122 != fVec21[1]);
			iVec22[0] = iTemp260;
			int 	iTemp261 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec91[0] = ((iRec91[1] * (1 - iTemp261)) + (iTemp14 * iTemp261));
			float 	fTemp262 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec9[0] + (-1 - iRec91[0])))) > 0.5f) & iSlow123)) ? 0.0f : fSlow121) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp262;
			int 	iTemp263 = (fVec23[0] > 0.003f);
			int 	iTemp264 = (fVec23[0] <= 0.003f);
			float 	fTemp265 = float((iTemp264 | (fVec23[1] >= 0.003f)));
			fRec92[0] = max((fRec92[1] * fTemp265), fSlow122);
			fRec93[0] = max((fTemp265 * fRec93[1]), fSlow124);
			float 	fTemp266 = (min(1.0f, fRec93[0]) + min(1.0f, fRec92[0]));
			int 	iTemp267 = (fVec23[0] >= fRec90[1]);
			int 	iTemp268 = (fRec90[1] <= 0.001f);
			int 	iTemp269 = (((iRec89[1] >= 4)) ? (((iRec89[1] >= 6)) ? ((iTemp268) ? 0 : ((iTemp263) ? 1 : 6)) : (((iRec89[1] >= 5)) ? ((iTemp264) ? 3 : ((iTemp267) ? 4 : 5)) : ((iTemp264) ? 3 : (((fVec23[0] <= fRec90[1])) ? 5 : 4)))) : (((iRec89[1] >= 2)) ? (((iRec89[1] >= 3)) ? (((iTemp264 & iTemp268)) ? 0 : ((iTemp263) ? 1 : 3)) : ((iTemp263) ? ((iTemp267) ? 4 : 2) : 6)) : (((iRec89[1] >= 1)) ? (((fRec90[1] >= min(fTemp266, 1.0f))) ? ((iTemp264) ? 6 : 2) : 1) : ((iTemp263) ? 1 : 0))));
			iRec89[0] = iTemp269;
			float 	fTemp270 = (((iTemp269 >= 4)) ? (((iTemp269 >= 6)) ? fConst17 : fConst16) : (((iTemp269 >= 2)) ? (((iTemp269 >= 3)) ? fConst15 : fConst14) : (((iTemp269 >= 1)) ? fConst13 : 0.0f)));
			int 	iTemp271 = (iRec89[1] != iRec89[2]);
			iVec24[0] = iTemp271;
			int 	iTemp272 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec95[0] = ((iRec95[1] * (1 - iTemp272)) + (iTemp14 * iTemp272));
			float 	fTemp273 = (2e+01f * (((fTemp270 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec95[0]))) / fTemp270) : 0.0f));
			int 	iTemp274 = int(fTemp273);
			float 	fTemp275 = ftbl3[max(0, int(min(int(iTemp274), 20)))];
			float 	fTemp276 = (fTemp275 + ((fTemp273 - float(iTemp274)) * (ftbl3[max(0, int(min(int((iTemp274 + 1)), 20)))] - fTemp275)));
			fRec96[0] = max((fRec96[1] * float(iVec24[0])), max(fVec23[0], fRec90[1]));
			int 	iTemp277 = (iRec89[1] == 3);
			int 	iTemp278 = (iRec89[1] == 6);
			int 	iTemp279 = (iRec89[1] == 0);
			float 	fTemp280 = (((iRec89[1] == 1)) ? min(1.0f, fTemp266) : ((iTemp279) ? 0.0f : ((iTemp278) ? (fTemp266 * fTemp276) : ((iTemp277) ? (fRec96[0] * fTemp276) : fVec23[0]))));
			float 	fTemp281 = (1.0f / ((iTemp279) ? 0.0001f : (((iTemp277 | iTemp278)) ? (0.04761905f * fTemp270) : fTemp270)));
			float 	fTemp282 = (fRec94[1] - fTemp281);
			float 	fTemp283 = (fRec94[1] + fTemp281);
			fRec94[0] = (((fTemp283 < fTemp280)) ? fTemp283 : (((fTemp282 > fTemp280)) ? fTemp282 : fTemp280));
			fRec90[0] = fRec94[0];
			fRec88[0] = (fRec90[0] - (fConst11 * ((fConst9 * fRec88[2]) + (fConst7 * fRec88[1]))));
			float 	fTemp284 = min(0.99f, (fConst18 * (((3947.8418f * fRec88[0]) + (7895.6836f * fRec88[1])) + (3947.8418f * fRec88[2]))));
			int 	iTemp285 = (fTemp284 < 0.1f);
			float 	fTemp286 = (((iSlow125) ? ((iTemp285) ? fTemp284 : 0.1f) : 0.0f) * fSlow120);
			fRec97[0] = (fTemp41 - (fSlow133 * ((fSlow131 * fRec97[2]) + (fSlow128 * fRec97[1]))));
			float 	fTemp287 = min(1.0f, (fSlow134 + ((iTemp285) ? (1.0f - (1e+01f * fTemp284)) : 0.0f)));
			float 	fTemp288 = ((iTemp2) ? 0.0f : (fSlow136 + fRec99[1]));
			fRec99[0] = (fTemp288 - floorf(fTemp288));
			float 	fTemp289 = (499.0f * fRec99[0]);
			int 	iTemp290 = int(fTemp289);
			int 	iTemp291 = max(0, min(iTemp290, 499));
			float 	fTemp292 = ftbl1[iTemp291];
			int 	iTemp293 = max(0, min((iTemp290 + 1), 499));
			float 	fTemp294 = (fTemp289 - float(iTemp290));
			float 	fTemp295 = float((((fVec23[1] <= 0.003f) & iTemp263) != 1));
			fRec100[0] = max((fTemp295 * fRec100[1]), fSlow137);
			fRec101[0] = max((fRec101[1] * fTemp295), fSlow118);
			float 	fTemp296 = max(min(((0.5f * (fVec23[0] - fTemp284)) + (0.2f - (0.8f * ((iTemp264) ? (2.0f * (((fRec101[0] > fRec100[0])) ? fRec101[0] : (0.0f - fRec100[0]))) : fSlow119)))), 1.0f), 0.0f);
			float 	fTemp297 = ftbl0[iTemp291];
			float 	fTemp298 = (((fTemp297 + (fTemp294 * (ftbl0[iTemp293] - fTemp297))) * (1.0f - fTemp296)) + (fTemp296 * (fTemp292 + (fTemp294 * (ftbl1[iTemp293] - fTemp292)))));
			float 	fTemp299 = (fRec98[1] - fConst24);
			float 	fTemp300 = (fConst24 + fRec98[1]);
			fRec98[0] = (((fTemp300 < fTemp298)) ? fTemp300 : (((fTemp299 > fTemp298)) ? fTemp299 : fTemp298));
			output0[i] = (FAUSTFLOAT)(((((((fTemp284 * ((((1.1f * (fRec98[0] * (1.0f - fTemp287))) + (fSlow135 * (fTemp287 * (fRec97[0] - fRec97[2])))) * (1.0f - (0.5f * fTemp286))) + (0.5f * (fTemp286 * ((0.2f * (fTemp259 + ((fTemp257 - float(iTemp258)) * (ftbl1[max(0, min((iTemp258 + 1), 499))] - fTemp259)))) + (0.8f * (fTemp255 + ((fTemp253 - float(iTemp254)) * (ftbl0[max(0, min((iTemp254 + 1), 499))] - fTemp255))))))))) + (fTemp235 * ((((1.1f * (fRec82[0] * (1.0f - fTemp238))) + (fSlow112 * (fTemp238 * (fRec81[0] - fRec81[2])))) * (1.0f - (0.5f * fTemp237))) + (0.5f * (fTemp237 * ((0.2f * (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl1[max(0, min((iTemp209 + 1), 499))] - fTemp210)))) + (0.8f * (fTemp206 + ((fTemp204 - float(iTemp205)) * (ftbl0[max(0, min((iTemp205 + 1), 499))] - fTemp206)))))))))) + (fTemp186 * ((((1.1f * (fRec66[0] * (1.0f - fTemp189))) + (fSlow89 * (fTemp189 * (fRec65[0] - fRec65[2])))) * (1.0f - (0.5f * fTemp188))) + (0.5f * (fTemp188 * ((0.2f * (fTemp161 + ((fTemp159 - float(iTemp160)) * (ftbl1[max(0, min((iTemp160 + 1), 499))] - fTemp161)))) + (0.8f * (fTemp157 + ((fTemp155 - float(iTemp156)) * (ftbl0[max(0, min((iTemp156 + 1), 499))] - fTemp157)))))))))) + (fTemp137 * ((((1.1f * (fRec50[0] * (1.0f - fTemp140))) + (fSlow66 * (fTemp140 * (fRec49[0] - fRec49[2])))) * (1.0f - (0.5f * fTemp139))) + (0.5f * (fTemp139 * ((0.2f * (fTemp112 + ((fTemp110 - float(iTemp111)) * (ftbl1[max(0, min((iTemp111 + 1), 499))] - fTemp112)))) + (0.8f * (fTemp108 + ((fTemp106 - float(iTemp107)) * (ftbl0[max(0, min((iTemp107 + 1), 499))] - fTemp108)))))))))) + (fTemp88 * ((((1.1f * (fRec34[0] * (1.0f - fTemp91))) + (fSlow43 * (fTemp91 * (fRec33[0] - fRec33[2])))) * (1.0f - (0.5f * fTemp90))) + (0.5f * (fTemp90 * ((0.2f * (fTemp63 + ((fTemp61 - float(iTemp62)) * (ftbl1[max(0, min((iTemp62 + 1), 499))] - fTemp63)))) + (0.8f * (fTemp59 + ((fTemp57 - float(iTemp58)) * (ftbl0[max(0, min((iTemp58 + 1), 499))] - fTemp59)))))))))) + (fTemp38 * ((((1.1f * (fRec18[0] * (1.0f - fTemp42))) + (fSlow20 * (fTemp42 * (fRec16[0] - fRec16[2])))) * (1.0f - (0.5f * fTemp40))) + (0.5f * (fTemp40 * ((0.2f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl1[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.8f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6)))))))))));
			// post processing
			fRec98[1] = fRec98[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec88[2] = fRec88[1]; fRec88[1] = fRec88[0];
			fRec90[1] = fRec90[0];
			fRec94[1] = fRec94[0];
			fRec96[1] = fRec96[0];
			iRec95[1] = iRec95[0];
			iVec24[1] = iVec24[0];
			iRec89[2] = iRec89[1]; iRec89[1] = iRec89[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fVec23[1] = fVec23[0];
			iRec91[1] = iRec91[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec82[1] = fRec82[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec81[2] = fRec81[1]; fRec81[1] = fRec81[0];
			fRec72[2] = fRec72[1]; fRec72[1] = fRec72[0];
			fRec74[1] = fRec74[0];
			fRec78[1] = fRec78[0];
			fRec80[1] = fRec80[0];
			iRec79[1] = iRec79[0];
			iVec20[1] = iVec20[0];
			iRec73[2] = iRec73[1]; iRec73[1] = iRec73[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fVec19[1] = fVec19[0];
			iRec75[1] = iRec75[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec66[1] = fRec66[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec65[2] = fRec65[1]; fRec65[1] = fRec65[0];
			fRec56[2] = fRec56[1]; fRec56[1] = fRec56[0];
			fRec58[1] = fRec58[0];
			fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			iRec63[1] = iRec63[0];
			iVec16[1] = iVec16[0];
			iRec57[2] = iRec57[1]; iRec57[1] = iRec57[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fVec15[1] = fVec15[0];
			iRec59[1] = iRec59[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec50[1] = fRec50[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
			fRec40[2] = fRec40[1]; fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fRec46[1] = fRec46[0];
			fRec48[1] = fRec48[0];
			iRec47[1] = iRec47[0];
			iVec12[1] = iVec12[0];
			iRec41[2] = iRec41[1]; iRec41[1] = iRec41[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			fVec11[1] = fVec11[0];
			iRec43[1] = iRec43[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec33[2] = fRec33[1]; fRec33[1] = fRec33[0];
			fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			iRec31[1] = iRec31[0];
			iVec8[1] = iVec8[0];
			iRec25[2] = iRec25[1]; iRec25[1] = iRec25[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fVec7[1] = fVec7[0];
			iRec27[1] = iRec27[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec18[1] = fRec18[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec16[2] = fRec16[1]; fRec16[1] = fRec16[0];
			iRec17[1] = iRec17[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec12[1] = fRec12[0];
			fRec15[1] = fRec15[0];
			iRec14[1] = iRec14[0];
			iVec4[1] = iVec4[0];
			iRec6[2] = iRec6[1]; iRec6[1] = iRec6[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fVec3[1] = fVec3[0];
			iRec8[1] = iRec8[0];
			iRec9[1] = iRec9[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
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
