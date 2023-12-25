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
				float 	fTemp0 = ((0.002002002f * float((iRec1[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp0)) + -1.0f))) * float(((fTemp0 > 0.0f) - (fTemp0 < 0.0f))));
				// post processing
				iRec1[1] = iRec1[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec10[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec10[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec10[0] = (iRec10[1] + 1);
				int 	iTemp12 = int((1.05f * float((iRec10[0] + -1))));
				output[i] = (((iTemp12 >= 11)) ? (((iTemp12 >= 16)) ? (((iTemp12 >= 19)) ? (((iTemp12 >= 20)) ? 0.0f : 0.01f) : (((iTemp12 >= 18)) ? 0.03f : (((iTemp12 >= 17)) ? 0.06f : 0.08f))) : (((iTemp12 >= 14)) ? (((iTemp12 >= 15)) ? 0.1f : 0.12f) : (((iTemp12 >= 13)) ? 0.14f : (((iTemp12 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp12 >= 6)) ? (((iTemp12 >= 9)) ? (((iTemp12 >= 10)) ? 0.22f : 0.26f) : (((iTemp12 >= 8)) ? 0.3f : (((iTemp12 >= 7)) ? 0.35f : 0.4f))) : (((iTemp12 >= 3)) ? (((iTemp12 >= 5)) ? 0.47f : (((iTemp12 >= 4)) ? 0.55f : 0.64f)) : (((iTemp12 >= 2)) ? 0.74f : (((iTemp12 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec10[1] = iRec10[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec18[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec18[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec18[0] = (iRec18[1] + 1);
				output[i] = ((0.004008016f * float((iRec18[0] + -1))) + -1.0f);
				// post processing
				iRec18[1] = iRec18[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec22[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec22[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec22[0] = (iRec22[1] + 1);
				float 	fTemp41 = float((iRec22[0] + -1));
				float 	fTemp42 = (0.002004008f * fTemp41);
				output[i] = (((fTemp42 < 0.5f)) ? ((0.008016032f * fTemp41) + -1.0f) : ((4.0f * (1.0f - fTemp42)) + -1.0f));
				// post processing
				iRec22[1] = iRec22[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[1000];
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec6[2];
	int 	iRec5[2];
	float 	fConst17;
	float 	fVec3[2];
	float 	fRec7[2];
	float 	fRec8[2];
	int 	iRec3[3];
	static float 	ftbl1[21];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	int 	iVec4[2];
	int 	iRec11[2];
	int 	iRec12[2];
	float 	fRec13[2];
	float 	fRec14[2];
	float 	fRec9[2];
	float 	fRec4[2];
	float 	fRec2[3];
	float 	fConst22;
	int 	iRec16[2];
	float 	fRec15[3];
	static float 	ftbl2[500];
	float 	fConst23;
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec21[2];
	static float 	ftbl3[500];
	float 	fConst24;
	float 	fRec17[2];
	float 	fConst25;
	float 	fRec23[2];
	float 	fConst26;
	float 	fRec24[2];
	FAUSTFLOAT 	fslider4;
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
	int 	iRec33[2];
	float 	fRec34[2];
	float 	fRec35[2];
	float 	fRec31[2];
	float 	fRec27[2];
	float 	fRec25[3];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec39[2];
	float 	fRec36[2];
	float 	fRec40[2];
	float 	fRec41[2];
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec45[2];
	float 	fVec11[2];
	float 	fRec46[2];
	float 	fRec47[2];
	int 	iRec43[3];
	int 	iVec12[2];
	int 	iRec49[2];
	int 	iRec50[2];
	float 	fRec51[2];
	float 	fRec52[2];
	float 	fRec48[2];
	float 	fRec44[2];
	float 	fRec42[3];
	float 	fRec54[2];
	float 	fRec55[2];
	float 	fRec56[2];
	float 	fRec53[2];
	float 	fRec57[2];
	float 	fRec58[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec62[2];
	float 	fVec15[2];
	float 	fRec63[2];
	float 	fRec64[2];
	int 	iRec60[3];
	int 	iVec16[2];
	int 	iRec66[2];
	int 	iRec67[2];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec65[2];
	float 	fRec61[2];
	float 	fRec59[3];
	float 	fRec71[2];
	float 	fRec72[2];
	float 	fRec73[2];
	float 	fRec70[2];
	float 	fRec74[2];
	float 	fRec75[2];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec79[2];
	float 	fVec19[2];
	float 	fRec80[2];
	float 	fRec81[2];
	int 	iRec77[3];
	int 	iVec20[2];
	int 	iRec83[2];
	int 	iRec84[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fRec82[2];
	float 	fRec78[2];
	float 	fRec76[3];
	float 	fRec88[2];
	float 	fRec89[2];
	float 	fRec90[2];
	float 	fRec87[2];
	float 	fRec91[2];
	float 	fRec92[2];
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec96[2];
	float 	fVec23[2];
	float 	fRec97[2];
	float 	fRec98[2];
	int 	iRec94[3];
	int 	iVec24[2];
	int 	iRec100[2];
	int 	iRec101[2];
	float 	fRec102[2];
	float 	fRec103[2];
	float 	fRec99[2];
	float 	fRec95[2];
	float 	fRec93[3];
	float 	fRec105[2];
	float 	fRec106[2];
	float 	fRec107[2];
	float 	fRec104[2];
	float 	fRec108[2];
	float 	fRec109[2];
	float 	fRec0[3];
	float 	fConst27;
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
		sig0.fill(1000,ftbl0);
		SIG1 sig1;
		sig1.init(sample_rate);
		sig1.fill(21,ftbl1);
		SIG2 sig2;
		sig2.init(sample_rate);
		sig2.fill(500,ftbl2);
		SIG3 sig3;
		sig3.init(sample_rate);
		sig3.fill(500,ftbl3);
	}
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = min(1.92e+05f, max(1.0f, float(fSampleRate)));
		float 	fConst1 = powf(fConst0,2.0f);
		float 	fConst2 = powf((251.32741f / fConst0),2.0f);
		float 	fConst3 = ((fConst2 * ((0.2033f * fConst2) + 0.31755f)) + 1.0f);
		fConst4 = (2.0f * ((63165.47f * (powf(fConst3,2.0f) / fConst1)) + -1.0f));
		float 	fConst5 = (63165.47f * (fConst3 / fConst0));
		fConst6 = (((fConst3 * (fConst5 + -191.85298f)) / fConst0) + 1.0f);
		float 	fConst7 = (((fConst3 * (fConst5 + 191.85298f)) / fConst0) + 1.0f);
		fConst8 = (1.0f / fConst7);
		float 	fConst9 = powf((62.831852f / fConst0),2.0f);
		float 	fConst10 = ((fConst9 * ((0.2033f * fConst9) + 0.31755f)) + 1.0f);
		float 	fConst11 = powf(fConst10,2.0f);
		fConst12 = (2.0f * ((3947.8418f * (fConst11 / fConst1)) + -1.0f));
		float 	fConst13 = (3947.8418f * (fConst10 / fConst0));
		fConst14 = (((fConst10 * (fConst13 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst15 = (((fConst10 * (fConst13 + 88.49557f)) / fConst0) + 1.0f);
		fConst16 = (1.0f / fConst15);
		fConst17 = (1.0f / fConst0);
		fConst18 = (0.1f * fConst0);
		fConst19 = (0.4f * fConst0);
		fConst20 = (0.15f * fConst0);
		fConst21 = (0.2f * fConst0);
		fConst22 = (fConst11 / (fConst1 * fConst15));
		fConst23 = (8.175799f / fConst0);
		fConst24 = (3333.3333f / fConst0);
		fConst25 = (4.0878997f / fConst0);
		fConst26 = (2.0439498f / fConst0);
		fConst27 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = 69.0f;
		fslider2 = 0.0f;
		fslider3 = 0.0f;
		fslider4 = 0.0f;
		fslider5 = 69.0f;
		fslider6 = 0.0f;
		fslider7 = 0.0f;
		fslider8 = 0.0f;
		fslider9 = 69.0f;
		fslider10 = 0.0f;
		fslider11 = 0.0f;
		fslider12 = 0.0f;
		fslider13 = 69.0f;
		fslider14 = 0.0f;
		fslider15 = 0.0f;
		fslider16 = 0.0f;
		fslider17 = 69.0f;
		fslider18 = 0.0f;
		fslider19 = 0.0f;
		fslider20 = 0.0f;
		fslider21 = 69.0f;
		fslider22 = 0.0f;
		fslider23 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) iRec3[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) iRec16[i] = 0;
		for (int i=0; i<3; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
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
		for (int i=0; i<2; i++) iRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<3; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec49[i] = 0;
		for (int i=0; i<2; i++) iRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec66[i] = 0;
		for (int i=0; i<2; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<3; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec79[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<3; i++) iRec77[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec83[i] = 0;
		for (int i=0; i<2; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<3; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<3; i++) iRec94[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec100[i] = 0;
		for (int i=0; i<2; i++) iRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
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
		synth_interface.note[0] = &fslider21;
		synth_interface.pres[0] = &fslider22;
		synth_interface.vpres[0] = &fslider23;
		synth_interface.but_y[0] = &fslider20;
		synth_interface.note[1] = &fslider17;
		synth_interface.pres[1] = &fslider18;
		synth_interface.vpres[1] = &fslider19;
		synth_interface.but_y[1] = &fslider16;
		synth_interface.note[2] = &fslider13;
		synth_interface.pres[2] = &fslider14;
		synth_interface.vpres[2] = &fslider15;
		synth_interface.but_y[2] = &fslider12;
		synth_interface.note[3] = &fslider9;
		synth_interface.pres[3] = &fslider10;
		synth_interface.vpres[3] = &fslider11;
		synth_interface.but_y[3] = &fslider8;
		synth_interface.note[4] = &fslider5;
		synth_interface.pres[4] = &fslider6;
		synth_interface.vpres[4] = &fslider7;
		synth_interface.but_y[4] = &fslider4;
		synth_interface.note[5] = &fslider1;
		synth_interface.pres[5] = &fslider2;
		synth_interface.vpres[5] = &fslider3;
		synth_interface.but_y[5] = &fslider0;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = float(fslider0);
		float 	fSlow1 = ftbl0[int(((499.5f * (fSlow0 + 1.0f)) + 0.5f))];
		float 	fSlow2 = (fSlow1 + 1.0f);
		float 	fSlow3 = fastpow2((0.083333336f * float(fslider1)));
		float 	fSlow4 = ((((8.175799f * fSlow3) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow5 = (1.0f - (0.5f * (fSlow4 * fSlow2)));
		float 	fSlow6 = float(fslider2);
		float 	fSlow7 = float(fslider3);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.9f * fSlow7);
		float 	fSlow10 = (0.0f - fSlow9);
		float 	fSlow11 = max(0.05f, (0.1f - fabsf(fSlow9)));
		float 	fSlow12 = (fConst23 * fSlow3);
		float 	fSlow13 = (0.0f - fSlow0);
		float 	fSlow14 = (fConst25 * fSlow3);
		float 	fSlow15 = (fConst26 * fSlow3);
		float 	fSlow16 = float(fslider4);
		float 	fSlow17 = ftbl0[int(((499.5f * (fSlow16 + 1.0f)) + 0.5f))];
		float 	fSlow18 = (fSlow17 + 1.0f);
		float 	fSlow19 = fastpow2((0.083333336f * float(fslider5)));
		float 	fSlow20 = ((((8.175799f * fSlow19) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow21 = (1.0f - (0.5f * (fSlow20 * fSlow18)));
		float 	fSlow22 = float(fslider6);
		float 	fSlow23 = float(fslider7);
		int 	iSlow24 = (fSlow23 == 0.0f);
		float 	fSlow25 = (0.9f * fSlow23);
		float 	fSlow26 = (0.0f - fSlow25);
		float 	fSlow27 = max(0.05f, (0.1f - fabsf(fSlow25)));
		float 	fSlow28 = (fConst23 * fSlow19);
		float 	fSlow29 = (0.0f - fSlow16);
		float 	fSlow30 = (fConst25 * fSlow19);
		float 	fSlow31 = (fConst26 * fSlow19);
		float 	fSlow32 = float(fslider8);
		float 	fSlow33 = ftbl0[int(((499.5f * (fSlow32 + 1.0f)) + 0.5f))];
		float 	fSlow34 = (fSlow33 + 1.0f);
		float 	fSlow35 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow36 = ((((8.175799f * fSlow35) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow37 = (1.0f - (0.5f * (fSlow36 * fSlow34)));
		float 	fSlow38 = float(fslider10);
		float 	fSlow39 = float(fslider11);
		int 	iSlow40 = (fSlow39 == 0.0f);
		float 	fSlow41 = (0.9f * fSlow39);
		float 	fSlow42 = (0.0f - fSlow41);
		float 	fSlow43 = max(0.05f, (0.1f - fabsf(fSlow41)));
		float 	fSlow44 = (fConst23 * fSlow35);
		float 	fSlow45 = (0.0f - fSlow32);
		float 	fSlow46 = (fConst25 * fSlow35);
		float 	fSlow47 = (fConst26 * fSlow35);
		float 	fSlow48 = float(fslider12);
		float 	fSlow49 = ftbl0[int(((499.5f * (fSlow48 + 1.0f)) + 0.5f))];
		float 	fSlow50 = (fSlow49 + 1.0f);
		float 	fSlow51 = fastpow2((0.083333336f * float(fslider13)));
		float 	fSlow52 = ((((8.175799f * fSlow51) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow53 = (1.0f - (0.5f * (fSlow52 * fSlow50)));
		float 	fSlow54 = float(fslider14);
		float 	fSlow55 = float(fslider15);
		int 	iSlow56 = (fSlow55 == 0.0f);
		float 	fSlow57 = (0.9f * fSlow55);
		float 	fSlow58 = (0.0f - fSlow57);
		float 	fSlow59 = max(0.05f, (0.1f - fabsf(fSlow57)));
		float 	fSlow60 = (fConst23 * fSlow51);
		float 	fSlow61 = (0.0f - fSlow48);
		float 	fSlow62 = (fConst25 * fSlow51);
		float 	fSlow63 = (fConst26 * fSlow51);
		float 	fSlow64 = float(fslider16);
		float 	fSlow65 = ftbl0[int(((499.5f * (fSlow64 + 1.0f)) + 0.5f))];
		float 	fSlow66 = (fSlow65 + 1.0f);
		float 	fSlow67 = fastpow2((0.083333336f * float(fslider17)));
		float 	fSlow68 = ((((8.175799f * fSlow67) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow69 = (1.0f - (0.5f * (fSlow68 * fSlow66)));
		float 	fSlow70 = float(fslider18);
		float 	fSlow71 = float(fslider19);
		int 	iSlow72 = (fSlow71 == 0.0f);
		float 	fSlow73 = (0.9f * fSlow71);
		float 	fSlow74 = (0.0f - fSlow73);
		float 	fSlow75 = max(0.05f, (0.1f - fabsf(fSlow73)));
		float 	fSlow76 = (fConst23 * fSlow67);
		float 	fSlow77 = (0.0f - fSlow64);
		float 	fSlow78 = (fConst25 * fSlow67);
		float 	fSlow79 = (fConst26 * fSlow67);
		float 	fSlow80 = float(fslider20);
		float 	fSlow81 = ftbl0[int(((499.5f * (fSlow80 + 1.0f)) + 0.5f))];
		float 	fSlow82 = (fSlow81 + 1.0f);
		float 	fSlow83 = fastpow2((0.083333336f * float(fslider21)));
		float 	fSlow84 = ((((8.175799f * fSlow83) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow85 = (1.0f - (0.5f * (fSlow84 * fSlow82)));
		float 	fSlow86 = float(fslider22);
		float 	fSlow87 = float(fslider23);
		int 	iSlow88 = (fSlow87 == 0.0f);
		float 	fSlow89 = (0.9f * fSlow87);
		float 	fSlow90 = (0.0f - fSlow89);
		float 	fSlow91 = max(0.05f, (0.1f - fabsf(fSlow89)));
		float 	fSlow92 = (fConst23 * fSlow83);
		float 	fSlow93 = (0.0f - fSlow80);
		float 	fSlow94 = (fConst25 * fSlow83);
		float 	fSlow95 = (fConst26 * fSlow83);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fVec1[0] = fSlow7;
			int 	iTemp1 = (fSlow9 != (0.9f * fVec1[1]));
			iVec2[0] = iTemp1;
			int 	iTemp2 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec6[0] = (iRec6[1] + 1);
			int 	iTemp3 = (iRec6[0] + -1);
			iRec5[0] = ((iRec5[1] * (1 - iTemp2)) + (iTemp3 * iTemp2));
			float 	fTemp4 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec5[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp4;
			int 	iTemp5 = (fVec3[0] > 0.003f);
			int 	iTemp6 = (fVec3[0] <= 0.003f);
			float 	fTemp7 = float((iTemp6 | (fVec3[1] >= 0.003f)));
			fRec7[0] = max((fRec7[1] * fTemp7), fSlow9);
			fRec8[0] = max((fTemp7 * fRec8[1]), fSlow10);
			float 	fTemp8 = (min(1.0f, fRec8[0]) + min(1.0f, fRec7[0]));
			int 	iTemp9 = (fVec3[0] >= fRec4[1]);
			int 	iTemp10 = (fRec4[1] <= 0.001f);
			int 	iTemp11 = (((iRec3[1] >= 4)) ? (((iRec3[1] >= 6)) ? ((iTemp10) ? 0 : ((iTemp5) ? 1 : 6)) : (((iRec3[1] >= 5)) ? ((iTemp6) ? 3 : ((iTemp9) ? 4 : 5)) : ((iTemp6) ? 3 : (((fVec3[0] <= fRec4[1])) ? 5 : 4)))) : (((iRec3[1] >= 2)) ? (((iRec3[1] >= 3)) ? (((iTemp6 & iTemp10)) ? 0 : ((iTemp5) ? 1 : 3)) : ((iTemp6) ? 6 : ((iTemp9) ? 4 : 2))) : (((iRec3[1] >= 1)) ? (((fRec4[1] >= min(fTemp8, 1.0f))) ? ((iTemp6) ? 6 : 2) : 1) : ((iTemp5) ? 1 : 0))));
			iRec3[0] = iTemp11;
			float 	fTemp13 = (((iTemp11 >= 4)) ? (((iTemp11 >= 6)) ? fConst0 : fConst21) : (((iTemp11 >= 2)) ? (((iTemp11 >= 3)) ? fConst20 : fConst19) : (((iTemp11 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp14 = (iRec3[1] != iRec3[2]);
			iVec4[0] = iTemp14;
			int 	iTemp15 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec11[0] = ((iRec11[1] * (1 - iTemp15)) + (iTemp3 * iTemp15));
			float 	fTemp16 = (2e+01f * (((fTemp13 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec11[0]))) / fTemp13) : 0.0f));
			int 	iTemp17 = int(fTemp16);
			float 	fTemp18 = ftbl1[max(0, int(min(int(iTemp17), 20)))];
			float 	fTemp19 = (fTemp18 + ((fTemp16 - float(iTemp17)) * (ftbl1[max(0, int(min(int((iTemp17 + 1)), 20)))] - fTemp18)));
			iRec12[0] = iRec3[1];
			int 	iTemp20 = (iRec12[1] == iRec3[1]);
			int 	iTemp21 = (iRec3[1] == 0);
			fRec13[0] = ((iTemp21) ? fVec3[0] : ((iTemp20) ? min(min(fRec13[1], fVec3[0]), fRec4[1]) : min(fVec3[0], fRec4[1])));
			fRec14[0] = ((iTemp21) ? fVec3[0] : ((iTemp20) ? max(max(fRec14[1], fVec3[0]), fRec4[1]) : max(fVec3[0], fRec4[1])));
			int 	iTemp22 = (iRec3[1] == 3);
			int 	iTemp23 = (iRec3[1] == 6);
			float 	fTemp24 = (((iRec3[1] == 1)) ? min(1.0f, fTemp8) : ((iTemp21) ? 0.0f : ((iTemp23) ? (fTemp8 * fTemp19) : ((iTemp22) ? (fRec14[0] * fTemp19) : fVec3[0]))));
			float 	fTemp25 = (1.0f / ((iTemp21) ? 0.0001f : (((iTemp22 | iTemp23)) ? (0.04761905f * fTemp13) : fTemp13)));
			float 	fTemp26 = (fRec9[1] - fTemp25);
			float 	fTemp27 = (fRec9[1] + fTemp25);
			fRec9[0] = (((fTemp27 < fTemp24)) ? fTemp27 : (((fTemp26 > fTemp24)) ? fTemp26 : fTemp24));
			fRec4[0] = fRec9[0];
			fRec2[0] = (fRec4[0] - (fConst16 * ((fConst14 * fRec2[2]) + (fConst12 * fRec2[1]))));
			float 	fTemp28 = min(0.99f, (fConst22 * (((3947.8418f * fRec2[0]) + (7895.6836f * fRec2[1])) + (3947.8418f * fRec2[2]))));
			float 	fTemp29 = min(1.0f, (fSlow11 + (((fTemp28 < 0.1f)) ? (1.0f - (1e+01f * fTemp28)) : 0.0f)));
			iRec16[0] = ((1103515245 * iRec16[1]) + 12345);
			fRec15[0] = (((1.9999999f * fRec15[1]) + (4.656613e-10f * float(iRec16[0]))) - (0.9999999f * fRec15[2]));
			float 	fTemp30 = (fRec15[0] - fRec15[2]);
			int 	iTemp31 = (1 - iVec0[1]);
			float 	fTemp32 = ((iTemp31) ? 0.0f : (fSlow12 + fRec19[1]));
			fRec19[0] = (fTemp32 - floorf(fTemp32));
			float 	fTemp33 = (499.0f * fRec19[0]);
			int 	iTemp34 = int(fTemp33);
			int 	iTemp35 = max(0, min(iTemp34, 499));
			float 	fTemp36 = ftbl2[iTemp35];
			int 	iTemp37 = max(0, min((iTemp34 + 1), 499));
			float 	fTemp38 = (fTemp33 - float(iTemp34));
			float 	fTemp39 = float((((fVec3[1] <= 0.003f) & iTemp5) != 1));
			fRec20[0] = max((fTemp39 * fRec20[1]), fSlow13);
			fRec21[0] = max((fRec21[1] * fTemp39), fSlow0);
			float 	fTemp40 = max(min(((0.5f * (fVec3[0] - fTemp28)) + (0.2f - (0.8f * ((iTemp6) ? (2.0f * (((fRec21[0] > fRec20[0])) ? fRec21[0] : (0.0f - fRec20[0]))) : fSlow1)))), 1.0f), 0.0f);
			float 	fTemp43 = ftbl3[iTemp35];
			float 	fTemp44 = (((fTemp43 + (fTemp38 * (ftbl3[iTemp37] - fTemp43))) * (1.0f - fTemp40)) + (fTemp40 * (fTemp36 + (fTemp38 * (ftbl2[iTemp37] - fTemp36)))));
			float 	fTemp45 = (fRec17[1] - fConst24);
			float 	fTemp46 = (fConst24 + fRec17[1]);
			fRec17[0] = (((fTemp46 < fTemp44)) ? fTemp46 : (((fTemp45 > fTemp44)) ? fTemp45 : fTemp44));
			float 	fTemp47 = ((iTemp31) ? 0.0f : (fSlow14 + fRec23[1]));
			fRec23[0] = (fTemp47 - floorf(fTemp47));
			float 	fTemp48 = (499.0f * fRec23[0]);
			int 	iTemp49 = int(fTemp48);
			float 	fTemp50 = ftbl3[max(0, min(iTemp49, 499))];
			float 	fTemp51 = ((iTemp31) ? 0.0f : (fSlow15 + fRec24[1]));
			fRec24[0] = (fTemp51 - floorf(fTemp51));
			float 	fTemp52 = (499.0f * fRec24[0]);
			int 	iTemp53 = int(fTemp52);
			float 	fTemp54 = ftbl2[max(0, min(iTemp53, 499))];
			fVec5[0] = fSlow23;
			int 	iTemp55 = (fSlow25 != (0.9f * fVec5[1]));
			iVec6[0] = iTemp55;
			int 	iTemp56 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec28[0] = ((iRec28[1] * (1 - iTemp56)) + (iTemp3 * iTemp56));
			float 	fTemp57 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec28[0])))) > 0.5f) & iSlow24)) ? 0.0f : fSlow22) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp57;
			int 	iTemp58 = (fVec7[0] > 0.003f);
			int 	iTemp59 = (fVec7[0] <= 0.003f);
			float 	fTemp60 = float((iTemp59 | (fVec7[1] >= 0.003f)));
			fRec29[0] = max((fRec29[1] * fTemp60), fSlow25);
			fRec30[0] = max((fTemp60 * fRec30[1]), fSlow26);
			float 	fTemp61 = (min(1.0f, fRec30[0]) + min(1.0f, fRec29[0]));
			int 	iTemp62 = (fVec7[0] >= fRec27[1]);
			int 	iTemp63 = (fRec27[1] <= 0.001f);
			int 	iTemp64 = (((iRec26[1] >= 4)) ? (((iRec26[1] >= 6)) ? ((iTemp63) ? 0 : ((iTemp58) ? 1 : 6)) : (((iRec26[1] >= 5)) ? ((iTemp59) ? 3 : ((iTemp62) ? 4 : 5)) : ((iTemp59) ? 3 : (((fVec7[0] <= fRec27[1])) ? 5 : 4)))) : (((iRec26[1] >= 2)) ? (((iRec26[1] >= 3)) ? (((iTemp59 & iTemp63)) ? 0 : ((iTemp58) ? 1 : 3)) : ((iTemp59) ? 6 : ((iTemp62) ? 4 : 2))) : (((iRec26[1] >= 1)) ? (((fRec27[1] >= min(fTemp61, 1.0f))) ? ((iTemp59) ? 6 : 2) : 1) : ((iTemp58) ? 1 : 0))));
			iRec26[0] = iTemp64;
			float 	fTemp65 = (((iTemp64 >= 4)) ? (((iTemp64 >= 6)) ? fConst0 : fConst21) : (((iTemp64 >= 2)) ? (((iTemp64 >= 3)) ? fConst20 : fConst19) : (((iTemp64 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp66 = (iRec26[1] != iRec26[2]);
			iVec8[0] = iTemp66;
			int 	iTemp67 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp67)) + (iTemp3 * iTemp67));
			float 	fTemp68 = (2e+01f * (((fTemp65 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec32[0]))) / fTemp65) : 0.0f));
			int 	iTemp69 = int(fTemp68);
			float 	fTemp70 = ftbl1[max(0, int(min(int(iTemp69), 20)))];
			float 	fTemp71 = (fTemp70 + ((fTemp68 - float(iTemp69)) * (ftbl1[max(0, int(min(int((iTemp69 + 1)), 20)))] - fTemp70)));
			iRec33[0] = iRec26[1];
			int 	iTemp72 = (iRec33[1] == iRec26[1]);
			int 	iTemp73 = (iRec26[1] == 0);
			fRec34[0] = ((iTemp73) ? fVec7[0] : ((iTemp72) ? min(min(fRec34[1], fVec7[0]), fRec27[1]) : min(fVec7[0], fRec27[1])));
			fRec35[0] = ((iTemp73) ? fVec7[0] : ((iTemp72) ? max(max(fRec35[1], fVec7[0]), fRec27[1]) : max(fVec7[0], fRec27[1])));
			int 	iTemp74 = (iRec26[1] == 3);
			int 	iTemp75 = (iRec26[1] == 6);
			float 	fTemp76 = (((iRec26[1] == 1)) ? min(1.0f, fTemp61) : ((iTemp73) ? 0.0f : ((iTemp75) ? (fTemp61 * fTemp71) : ((iTemp74) ? (fRec35[0] * fTemp71) : fVec7[0]))));
			float 	fTemp77 = (1.0f / ((iTemp73) ? 0.0001f : (((iTemp74 | iTemp75)) ? (0.04761905f * fTemp65) : fTemp65)));
			float 	fTemp78 = (fRec31[1] - fTemp77);
			float 	fTemp79 = (fRec31[1] + fTemp77);
			fRec31[0] = (((fTemp79 < fTemp76)) ? fTemp79 : (((fTemp78 > fTemp76)) ? fTemp78 : fTemp76));
			fRec27[0] = fRec31[0];
			fRec25[0] = (fRec27[0] - (fConst16 * ((fConst14 * fRec25[2]) + (fConst12 * fRec25[1]))));
			float 	fTemp80 = min(0.99f, (fConst22 * (((3947.8418f * fRec25[0]) + (7895.6836f * fRec25[1])) + (3947.8418f * fRec25[2]))));
			float 	fTemp81 = min(1.0f, (fSlow27 + (((fTemp80 < 0.1f)) ? (1.0f - (1e+01f * fTemp80)) : 0.0f)));
			float 	fTemp82 = ((iTemp31) ? 0.0f : (fSlow28 + fRec37[1]));
			fRec37[0] = (fTemp82 - floorf(fTemp82));
			float 	fTemp83 = (499.0f * fRec37[0]);
			int 	iTemp84 = int(fTemp83);
			int 	iTemp85 = max(0, min(iTemp84, 499));
			float 	fTemp86 = ftbl2[iTemp85];
			int 	iTemp87 = max(0, min((iTemp84 + 1), 499));
			float 	fTemp88 = (fTemp83 - float(iTemp84));
			float 	fTemp89 = float((((fVec7[1] <= 0.003f) & iTemp58) != 1));
			fRec38[0] = max((fTemp89 * fRec38[1]), fSlow29);
			fRec39[0] = max((fRec39[1] * fTemp89), fSlow16);
			float 	fTemp90 = max(min(((0.5f * (fVec7[0] - fTemp80)) + (0.2f - (0.8f * ((iTemp59) ? (2.0f * (((fRec39[0] > fRec38[0])) ? fRec39[0] : (0.0f - fRec38[0]))) : fSlow17)))), 1.0f), 0.0f);
			float 	fTemp91 = ftbl3[iTemp85];
			float 	fTemp92 = (((fTemp91 + (fTemp88 * (ftbl3[iTemp87] - fTemp91))) * (1.0f - fTemp90)) + (fTemp90 * (fTemp86 + (fTemp88 * (ftbl2[iTemp87] - fTemp86)))));
			float 	fTemp93 = (fRec36[1] - fConst24);
			float 	fTemp94 = (fConst24 + fRec36[1]);
			fRec36[0] = (((fTemp94 < fTemp92)) ? fTemp94 : (((fTemp93 > fTemp92)) ? fTemp93 : fTemp92));
			float 	fTemp95 = ((iTemp31) ? 0.0f : (fSlow30 + fRec40[1]));
			fRec40[0] = (fTemp95 - floorf(fTemp95));
			float 	fTemp96 = (499.0f * fRec40[0]);
			int 	iTemp97 = int(fTemp96);
			float 	fTemp98 = ftbl3[max(0, min(iTemp97, 499))];
			float 	fTemp99 = ((iTemp31) ? 0.0f : (fSlow31 + fRec41[1]));
			fRec41[0] = (fTemp99 - floorf(fTemp99));
			float 	fTemp100 = (499.0f * fRec41[0]);
			int 	iTemp101 = int(fTemp100);
			float 	fTemp102 = ftbl2[max(0, min(iTemp101, 499))];
			fVec9[0] = fSlow39;
			int 	iTemp103 = (fSlow41 != (0.9f * fVec9[1]));
			iVec10[0] = iTemp103;
			int 	iTemp104 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec45[0] = ((iRec45[1] * (1 - iTemp104)) + (iTemp3 * iTemp104));
			float 	fTemp105 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec45[0])))) > 0.5f) & iSlow40)) ? 0.0f : fSlow38) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp105;
			int 	iTemp106 = (fVec11[0] > 0.003f);
			int 	iTemp107 = (fVec11[0] <= 0.003f);
			float 	fTemp108 = float((iTemp107 | (fVec11[1] >= 0.003f)));
			fRec46[0] = max((fRec46[1] * fTemp108), fSlow41);
			fRec47[0] = max((fTemp108 * fRec47[1]), fSlow42);
			float 	fTemp109 = (min(1.0f, fRec47[0]) + min(1.0f, fRec46[0]));
			int 	iTemp110 = (fVec11[0] >= fRec44[1]);
			int 	iTemp111 = (fRec44[1] <= 0.001f);
			int 	iTemp112 = (((iRec43[1] >= 4)) ? (((iRec43[1] >= 6)) ? ((iTemp111) ? 0 : ((iTemp106) ? 1 : 6)) : (((iRec43[1] >= 5)) ? ((iTemp107) ? 3 : ((iTemp110) ? 4 : 5)) : ((iTemp107) ? 3 : (((fVec11[0] <= fRec44[1])) ? 5 : 4)))) : (((iRec43[1] >= 2)) ? (((iRec43[1] >= 3)) ? (((iTemp107 & iTemp111)) ? 0 : ((iTemp106) ? 1 : 3)) : ((iTemp107) ? 6 : ((iTemp110) ? 4 : 2))) : (((iRec43[1] >= 1)) ? (((fRec44[1] >= min(fTemp109, 1.0f))) ? ((iTemp107) ? 6 : 2) : 1) : ((iTemp106) ? 1 : 0))));
			iRec43[0] = iTemp112;
			float 	fTemp113 = (((iTemp112 >= 4)) ? (((iTemp112 >= 6)) ? fConst0 : fConst21) : (((iTemp112 >= 2)) ? (((iTemp112 >= 3)) ? fConst20 : fConst19) : (((iTemp112 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp114 = (iRec43[1] != iRec43[2]);
			iVec12[0] = iTemp114;
			int 	iTemp115 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec49[0] = ((iRec49[1] * (1 - iTemp115)) + (iTemp3 * iTemp115));
			float 	fTemp116 = (2e+01f * (((fTemp113 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec49[0]))) / fTemp113) : 0.0f));
			int 	iTemp117 = int(fTemp116);
			float 	fTemp118 = ftbl1[max(0, int(min(int(iTemp117), 20)))];
			float 	fTemp119 = (fTemp118 + ((fTemp116 - float(iTemp117)) * (ftbl1[max(0, int(min(int((iTemp117 + 1)), 20)))] - fTemp118)));
			iRec50[0] = iRec43[1];
			int 	iTemp120 = (iRec50[1] == iRec43[1]);
			int 	iTemp121 = (iRec43[1] == 0);
			fRec51[0] = ((iTemp121) ? fVec11[0] : ((iTemp120) ? min(min(fRec51[1], fVec11[0]), fRec44[1]) : min(fVec11[0], fRec44[1])));
			fRec52[0] = ((iTemp121) ? fVec11[0] : ((iTemp120) ? max(max(fRec52[1], fVec11[0]), fRec44[1]) : max(fVec11[0], fRec44[1])));
			int 	iTemp122 = (iRec43[1] == 3);
			int 	iTemp123 = (iRec43[1] == 6);
			float 	fTemp124 = (((iRec43[1] == 1)) ? min(1.0f, fTemp109) : ((iTemp121) ? 0.0f : ((iTemp123) ? (fTemp109 * fTemp119) : ((iTemp122) ? (fRec52[0] * fTemp119) : fVec11[0]))));
			float 	fTemp125 = (1.0f / ((iTemp121) ? 0.0001f : (((iTemp122 | iTemp123)) ? (0.04761905f * fTemp113) : fTemp113)));
			float 	fTemp126 = (fRec48[1] - fTemp125);
			float 	fTemp127 = (fRec48[1] + fTemp125);
			fRec48[0] = (((fTemp127 < fTemp124)) ? fTemp127 : (((fTemp126 > fTemp124)) ? fTemp126 : fTemp124));
			fRec44[0] = fRec48[0];
			fRec42[0] = (fRec44[0] - (fConst16 * ((fConst14 * fRec42[2]) + (fConst12 * fRec42[1]))));
			float 	fTemp128 = min(0.99f, (fConst22 * (((3947.8418f * fRec42[0]) + (7895.6836f * fRec42[1])) + (3947.8418f * fRec42[2]))));
			float 	fTemp129 = min(1.0f, (fSlow43 + (((fTemp128 < 0.1f)) ? (1.0f - (1e+01f * fTemp128)) : 0.0f)));
			float 	fTemp130 = ((iTemp31) ? 0.0f : (fSlow44 + fRec54[1]));
			fRec54[0] = (fTemp130 - floorf(fTemp130));
			float 	fTemp131 = (499.0f * fRec54[0]);
			int 	iTemp132 = int(fTemp131);
			int 	iTemp133 = max(0, min(iTemp132, 499));
			float 	fTemp134 = ftbl2[iTemp133];
			int 	iTemp135 = max(0, min((iTemp132 + 1), 499));
			float 	fTemp136 = (fTemp131 - float(iTemp132));
			float 	fTemp137 = float((((fVec11[1] <= 0.003f) & iTemp106) != 1));
			fRec55[0] = max((fTemp137 * fRec55[1]), fSlow45);
			fRec56[0] = max((fRec56[1] * fTemp137), fSlow32);
			float 	fTemp138 = max(min(((0.5f * (fVec11[0] - fTemp128)) + (0.2f - (0.8f * ((iTemp107) ? (2.0f * (((fRec56[0] > fRec55[0])) ? fRec56[0] : (0.0f - fRec55[0]))) : fSlow33)))), 1.0f), 0.0f);
			float 	fTemp139 = ftbl3[iTemp133];
			float 	fTemp140 = (((fTemp139 + (fTemp136 * (ftbl3[iTemp135] - fTemp139))) * (1.0f - fTemp138)) + (fTemp138 * (fTemp134 + (fTemp136 * (ftbl2[iTemp135] - fTemp134)))));
			float 	fTemp141 = (fRec53[1] - fConst24);
			float 	fTemp142 = (fConst24 + fRec53[1]);
			fRec53[0] = (((fTemp142 < fTemp140)) ? fTemp142 : (((fTemp141 > fTemp140)) ? fTemp141 : fTemp140));
			float 	fTemp143 = ((iTemp31) ? 0.0f : (fSlow46 + fRec57[1]));
			fRec57[0] = (fTemp143 - floorf(fTemp143));
			float 	fTemp144 = (499.0f * fRec57[0]);
			int 	iTemp145 = int(fTemp144);
			float 	fTemp146 = ftbl3[max(0, min(iTemp145, 499))];
			float 	fTemp147 = ((iTemp31) ? 0.0f : (fSlow47 + fRec58[1]));
			fRec58[0] = (fTemp147 - floorf(fTemp147));
			float 	fTemp148 = (499.0f * fRec58[0]);
			int 	iTemp149 = int(fTemp148);
			float 	fTemp150 = ftbl2[max(0, min(iTemp149, 499))];
			fVec13[0] = fSlow55;
			int 	iTemp151 = (fSlow57 != (0.9f * fVec13[1]));
			iVec14[0] = iTemp151;
			int 	iTemp152 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec62[0] = ((iRec62[1] * (1 - iTemp152)) + (iTemp3 * iTemp152));
			float 	fTemp153 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec62[0])))) > 0.5f) & iSlow56)) ? 0.0f : fSlow54) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp153;
			int 	iTemp154 = (fVec15[0] > 0.003f);
			int 	iTemp155 = (fVec15[0] <= 0.003f);
			float 	fTemp156 = float((iTemp155 | (fVec15[1] >= 0.003f)));
			fRec63[0] = max((fRec63[1] * fTemp156), fSlow57);
			fRec64[0] = max((fTemp156 * fRec64[1]), fSlow58);
			float 	fTemp157 = (min(1.0f, fRec64[0]) + min(1.0f, fRec63[0]));
			int 	iTemp158 = (fVec15[0] >= fRec61[1]);
			int 	iTemp159 = (fRec61[1] <= 0.001f);
			int 	iTemp160 = (((iRec60[1] >= 4)) ? (((iRec60[1] >= 6)) ? ((iTemp159) ? 0 : ((iTemp154) ? 1 : 6)) : (((iRec60[1] >= 5)) ? ((iTemp155) ? 3 : ((iTemp158) ? 4 : 5)) : ((iTemp155) ? 3 : (((fVec15[0] <= fRec61[1])) ? 5 : 4)))) : (((iRec60[1] >= 2)) ? (((iRec60[1] >= 3)) ? (((iTemp155 & iTemp159)) ? 0 : ((iTemp154) ? 1 : 3)) : ((iTemp155) ? 6 : ((iTemp158) ? 4 : 2))) : (((iRec60[1] >= 1)) ? (((fRec61[1] >= min(fTemp157, 1.0f))) ? ((iTemp155) ? 6 : 2) : 1) : ((iTemp154) ? 1 : 0))));
			iRec60[0] = iTemp160;
			float 	fTemp161 = (((iTemp160 >= 4)) ? (((iTemp160 >= 6)) ? fConst0 : fConst21) : (((iTemp160 >= 2)) ? (((iTemp160 >= 3)) ? fConst20 : fConst19) : (((iTemp160 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp162 = (iRec60[1] != iRec60[2]);
			iVec16[0] = iTemp162;
			int 	iTemp163 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec66[0] = ((iRec66[1] * (1 - iTemp163)) + (iTemp3 * iTemp163));
			float 	fTemp164 = (2e+01f * (((fTemp161 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec66[0]))) / fTemp161) : 0.0f));
			int 	iTemp165 = int(fTemp164);
			float 	fTemp166 = ftbl1[max(0, int(min(int(iTemp165), 20)))];
			float 	fTemp167 = (fTemp166 + ((fTemp164 - float(iTemp165)) * (ftbl1[max(0, int(min(int((iTemp165 + 1)), 20)))] - fTemp166)));
			iRec67[0] = iRec60[1];
			int 	iTemp168 = (iRec67[1] == iRec60[1]);
			int 	iTemp169 = (iRec60[1] == 0);
			fRec68[0] = ((iTemp169) ? fVec15[0] : ((iTemp168) ? min(min(fRec68[1], fVec15[0]), fRec61[1]) : min(fVec15[0], fRec61[1])));
			fRec69[0] = ((iTemp169) ? fVec15[0] : ((iTemp168) ? max(max(fRec69[1], fVec15[0]), fRec61[1]) : max(fVec15[0], fRec61[1])));
			int 	iTemp170 = (iRec60[1] == 3);
			int 	iTemp171 = (iRec60[1] == 6);
			float 	fTemp172 = (((iRec60[1] == 1)) ? min(1.0f, fTemp157) : ((iTemp169) ? 0.0f : ((iTemp171) ? (fTemp157 * fTemp167) : ((iTemp170) ? (fRec69[0] * fTemp167) : fVec15[0]))));
			float 	fTemp173 = (1.0f / ((iTemp169) ? 0.0001f : (((iTemp170 | iTemp171)) ? (0.04761905f * fTemp161) : fTemp161)));
			float 	fTemp174 = (fRec65[1] - fTemp173);
			float 	fTemp175 = (fRec65[1] + fTemp173);
			fRec65[0] = (((fTemp175 < fTemp172)) ? fTemp175 : (((fTemp174 > fTemp172)) ? fTemp174 : fTemp172));
			fRec61[0] = fRec65[0];
			fRec59[0] = (fRec61[0] - (fConst16 * ((fConst14 * fRec59[2]) + (fConst12 * fRec59[1]))));
			float 	fTemp176 = min(0.99f, (fConst22 * (((3947.8418f * fRec59[0]) + (7895.6836f * fRec59[1])) + (3947.8418f * fRec59[2]))));
			float 	fTemp177 = min(1.0f, (fSlow59 + (((fTemp176 < 0.1f)) ? (1.0f - (1e+01f * fTemp176)) : 0.0f)));
			float 	fTemp178 = ((iTemp31) ? 0.0f : (fSlow60 + fRec71[1]));
			fRec71[0] = (fTemp178 - floorf(fTemp178));
			float 	fTemp179 = (499.0f * fRec71[0]);
			int 	iTemp180 = int(fTemp179);
			int 	iTemp181 = max(0, min(iTemp180, 499));
			float 	fTemp182 = ftbl2[iTemp181];
			int 	iTemp183 = max(0, min((iTemp180 + 1), 499));
			float 	fTemp184 = (fTemp179 - float(iTemp180));
			float 	fTemp185 = float((((fVec15[1] <= 0.003f) & iTemp154) != 1));
			fRec72[0] = max((fTemp185 * fRec72[1]), fSlow61);
			fRec73[0] = max((fRec73[1] * fTemp185), fSlow48);
			float 	fTemp186 = max(min(((0.5f * (fVec15[0] - fTemp176)) + (0.2f - (0.8f * ((iTemp155) ? (2.0f * (((fRec73[0] > fRec72[0])) ? fRec73[0] : (0.0f - fRec72[0]))) : fSlow49)))), 1.0f), 0.0f);
			float 	fTemp187 = ftbl3[iTemp181];
			float 	fTemp188 = (((fTemp187 + (fTemp184 * (ftbl3[iTemp183] - fTemp187))) * (1.0f - fTemp186)) + (fTemp186 * (fTemp182 + (fTemp184 * (ftbl2[iTemp183] - fTemp182)))));
			float 	fTemp189 = (fRec70[1] - fConst24);
			float 	fTemp190 = (fConst24 + fRec70[1]);
			fRec70[0] = (((fTemp190 < fTemp188)) ? fTemp190 : (((fTemp189 > fTemp188)) ? fTemp189 : fTemp188));
			float 	fTemp191 = ((iTemp31) ? 0.0f : (fSlow62 + fRec74[1]));
			fRec74[0] = (fTemp191 - floorf(fTemp191));
			float 	fTemp192 = (499.0f * fRec74[0]);
			int 	iTemp193 = int(fTemp192);
			float 	fTemp194 = ftbl3[max(0, min(iTemp193, 499))];
			float 	fTemp195 = ((iTemp31) ? 0.0f : (fSlow63 + fRec75[1]));
			fRec75[0] = (fTemp195 - floorf(fTemp195));
			float 	fTemp196 = (499.0f * fRec75[0]);
			int 	iTemp197 = int(fTemp196);
			float 	fTemp198 = ftbl2[max(0, min(iTemp197, 499))];
			fVec17[0] = fSlow71;
			int 	iTemp199 = (fSlow73 != (0.9f * fVec17[1]));
			iVec18[0] = iTemp199;
			int 	iTemp200 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec79[0] = ((iRec79[1] * (1 - iTemp200)) + (iTemp3 * iTemp200));
			float 	fTemp201 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec79[0])))) > 0.5f) & iSlow72)) ? 0.0f : fSlow70) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp201;
			int 	iTemp202 = (fVec19[0] > 0.003f);
			int 	iTemp203 = (fVec19[0] <= 0.003f);
			float 	fTemp204 = float((iTemp203 | (fVec19[1] >= 0.003f)));
			fRec80[0] = max((fRec80[1] * fTemp204), fSlow73);
			fRec81[0] = max((fTemp204 * fRec81[1]), fSlow74);
			float 	fTemp205 = (min(1.0f, fRec81[0]) + min(1.0f, fRec80[0]));
			int 	iTemp206 = (fVec19[0] >= fRec78[1]);
			int 	iTemp207 = (fRec78[1] <= 0.001f);
			int 	iTemp208 = (((iRec77[1] >= 4)) ? (((iRec77[1] >= 6)) ? ((iTemp207) ? 0 : ((iTemp202) ? 1 : 6)) : (((iRec77[1] >= 5)) ? ((iTemp203) ? 3 : ((iTemp206) ? 4 : 5)) : ((iTemp203) ? 3 : (((fVec19[0] <= fRec78[1])) ? 5 : 4)))) : (((iRec77[1] >= 2)) ? (((iRec77[1] >= 3)) ? (((iTemp203 & iTemp207)) ? 0 : ((iTemp202) ? 1 : 3)) : ((iTemp203) ? 6 : ((iTemp206) ? 4 : 2))) : (((iRec77[1] >= 1)) ? (((fRec78[1] >= min(fTemp205, 1.0f))) ? ((iTemp203) ? 6 : 2) : 1) : ((iTemp202) ? 1 : 0))));
			iRec77[0] = iTemp208;
			float 	fTemp209 = (((iTemp208 >= 4)) ? (((iTemp208 >= 6)) ? fConst0 : fConst21) : (((iTemp208 >= 2)) ? (((iTemp208 >= 3)) ? fConst20 : fConst19) : (((iTemp208 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp210 = (iRec77[1] != iRec77[2]);
			iVec20[0] = iTemp210;
			int 	iTemp211 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec83[0] = ((iRec83[1] * (1 - iTemp211)) + (iTemp3 * iTemp211));
			float 	fTemp212 = (2e+01f * (((fTemp209 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec83[0]))) / fTemp209) : 0.0f));
			int 	iTemp213 = int(fTemp212);
			float 	fTemp214 = ftbl1[max(0, int(min(int(iTemp213), 20)))];
			float 	fTemp215 = (fTemp214 + ((fTemp212 - float(iTemp213)) * (ftbl1[max(0, int(min(int((iTemp213 + 1)), 20)))] - fTemp214)));
			iRec84[0] = iRec77[1];
			int 	iTemp216 = (iRec84[1] == iRec77[1]);
			int 	iTemp217 = (iRec77[1] == 0);
			fRec85[0] = ((iTemp217) ? fVec19[0] : ((iTemp216) ? min(min(fRec85[1], fVec19[0]), fRec78[1]) : min(fVec19[0], fRec78[1])));
			fRec86[0] = ((iTemp217) ? fVec19[0] : ((iTemp216) ? max(max(fRec86[1], fVec19[0]), fRec78[1]) : max(fVec19[0], fRec78[1])));
			int 	iTemp218 = (iRec77[1] == 3);
			int 	iTemp219 = (iRec77[1] == 6);
			float 	fTemp220 = (((iRec77[1] == 1)) ? min(1.0f, fTemp205) : ((iTemp217) ? 0.0f : ((iTemp219) ? (fTemp205 * fTemp215) : ((iTemp218) ? (fRec86[0] * fTemp215) : fVec19[0]))));
			float 	fTemp221 = (1.0f / ((iTemp217) ? 0.0001f : (((iTemp218 | iTemp219)) ? (0.04761905f * fTemp209) : fTemp209)));
			float 	fTemp222 = (fRec82[1] - fTemp221);
			float 	fTemp223 = (fRec82[1] + fTemp221);
			fRec82[0] = (((fTemp223 < fTemp220)) ? fTemp223 : (((fTemp222 > fTemp220)) ? fTemp222 : fTemp220));
			fRec78[0] = fRec82[0];
			fRec76[0] = (fRec78[0] - (fConst16 * ((fConst14 * fRec76[2]) + (fConst12 * fRec76[1]))));
			float 	fTemp224 = min(0.99f, (fConst22 * (((3947.8418f * fRec76[0]) + (7895.6836f * fRec76[1])) + (3947.8418f * fRec76[2]))));
			float 	fTemp225 = min(1.0f, (fSlow75 + (((fTemp224 < 0.1f)) ? (1.0f - (1e+01f * fTemp224)) : 0.0f)));
			float 	fTemp226 = ((iTemp31) ? 0.0f : (fSlow76 + fRec88[1]));
			fRec88[0] = (fTemp226 - floorf(fTemp226));
			float 	fTemp227 = (499.0f * fRec88[0]);
			int 	iTemp228 = int(fTemp227);
			int 	iTemp229 = max(0, min(iTemp228, 499));
			float 	fTemp230 = ftbl2[iTemp229];
			int 	iTemp231 = max(0, min((iTemp228 + 1), 499));
			float 	fTemp232 = (fTemp227 - float(iTemp228));
			float 	fTemp233 = float((((fVec19[1] <= 0.003f) & iTemp202) != 1));
			fRec89[0] = max((fTemp233 * fRec89[1]), fSlow77);
			fRec90[0] = max((fRec90[1] * fTemp233), fSlow64);
			float 	fTemp234 = max(min(((0.5f * (fVec19[0] - fTemp224)) + (0.2f - (0.8f * ((iTemp203) ? (2.0f * (((fRec90[0] > fRec89[0])) ? fRec90[0] : (0.0f - fRec89[0]))) : fSlow65)))), 1.0f), 0.0f);
			float 	fTemp235 = ftbl3[iTemp229];
			float 	fTemp236 = (((fTemp235 + (fTemp232 * (ftbl3[iTemp231] - fTemp235))) * (1.0f - fTemp234)) + (fTemp234 * (fTemp230 + (fTemp232 * (ftbl2[iTemp231] - fTemp230)))));
			float 	fTemp237 = (fRec87[1] - fConst24);
			float 	fTemp238 = (fConst24 + fRec87[1]);
			fRec87[0] = (((fTemp238 < fTemp236)) ? fTemp238 : (((fTemp237 > fTemp236)) ? fTemp237 : fTemp236));
			float 	fTemp239 = ((iTemp31) ? 0.0f : (fSlow78 + fRec91[1]));
			fRec91[0] = (fTemp239 - floorf(fTemp239));
			float 	fTemp240 = (499.0f * fRec91[0]);
			int 	iTemp241 = int(fTemp240);
			float 	fTemp242 = ftbl3[max(0, min(iTemp241, 499))];
			float 	fTemp243 = ((iTemp31) ? 0.0f : (fSlow79 + fRec92[1]));
			fRec92[0] = (fTemp243 - floorf(fTemp243));
			float 	fTemp244 = (499.0f * fRec92[0]);
			int 	iTemp245 = int(fTemp244);
			float 	fTemp246 = ftbl2[max(0, min(iTemp245, 499))];
			fVec21[0] = fSlow87;
			int 	iTemp247 = (fSlow89 != (0.9f * fVec21[1]));
			iVec22[0] = iTemp247;
			int 	iTemp248 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp248)) + (iTemp3 * iTemp248));
			float 	fTemp249 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec96[0])))) > 0.5f) & iSlow88)) ? 0.0f : fSlow86) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp249;
			int 	iTemp250 = (fVec23[0] > 0.003f);
			int 	iTemp251 = (fVec23[0] <= 0.003f);
			float 	fTemp252 = float((iTemp251 | (fVec23[1] >= 0.003f)));
			fRec97[0] = max((fRec97[1] * fTemp252), fSlow89);
			fRec98[0] = max((fTemp252 * fRec98[1]), fSlow90);
			float 	fTemp253 = (min(1.0f, fRec98[0]) + min(1.0f, fRec97[0]));
			int 	iTemp254 = (fVec23[0] >= fRec95[1]);
			int 	iTemp255 = (fRec95[1] <= 0.001f);
			int 	iTemp256 = (((iRec94[1] >= 4)) ? (((iRec94[1] >= 6)) ? ((iTemp255) ? 0 : ((iTemp250) ? 1 : 6)) : (((iRec94[1] >= 5)) ? ((iTemp251) ? 3 : ((iTemp254) ? 4 : 5)) : ((iTemp251) ? 3 : (((fVec23[0] <= fRec95[1])) ? 5 : 4)))) : (((iRec94[1] >= 2)) ? (((iRec94[1] >= 3)) ? (((iTemp251 & iTemp255)) ? 0 : ((iTemp250) ? 1 : 3)) : ((iTemp251) ? 6 : ((iTemp254) ? 4 : 2))) : (((iRec94[1] >= 1)) ? (((fRec95[1] >= min(fTemp253, 1.0f))) ? ((iTemp251) ? 6 : 2) : 1) : ((iTemp250) ? 1 : 0))));
			iRec94[0] = iTemp256;
			float 	fTemp257 = (((iTemp256 >= 4)) ? (((iTemp256 >= 6)) ? fConst0 : fConst21) : (((iTemp256 >= 2)) ? (((iTemp256 >= 3)) ? fConst20 : fConst19) : (((iTemp256 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp258 = (iRec94[1] != iRec94[2]);
			iVec24[0] = iTemp258;
			int 	iTemp259 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec100[0] = ((iRec100[1] * (1 - iTemp259)) + (iTemp3 * iTemp259));
			float 	fTemp260 = (2e+01f * (((fTemp257 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec100[0]))) / fTemp257) : 0.0f));
			int 	iTemp261 = int(fTemp260);
			float 	fTemp262 = ftbl1[max(0, int(min(int(iTemp261), 20)))];
			float 	fTemp263 = (fTemp262 + ((fTemp260 - float(iTemp261)) * (ftbl1[max(0, int(min(int((iTemp261 + 1)), 20)))] - fTemp262)));
			iRec101[0] = iRec94[1];
			int 	iTemp264 = (iRec101[1] == iRec94[1]);
			int 	iTemp265 = (iRec94[1] == 0);
			fRec102[0] = ((iTemp265) ? fVec23[0] : ((iTemp264) ? min(min(fRec102[1], fVec23[0]), fRec95[1]) : min(fVec23[0], fRec95[1])));
			fRec103[0] = ((iTemp265) ? fVec23[0] : ((iTemp264) ? max(max(fRec103[1], fVec23[0]), fRec95[1]) : max(fVec23[0], fRec95[1])));
			int 	iTemp266 = (iRec94[1] == 3);
			int 	iTemp267 = (iRec94[1] == 6);
			float 	fTemp268 = (((iRec94[1] == 1)) ? min(1.0f, fTemp253) : ((iTemp265) ? 0.0f : ((iTemp267) ? (fTemp253 * fTemp263) : ((iTemp266) ? (fRec103[0] * fTemp263) : fVec23[0]))));
			float 	fTemp269 = (1.0f / ((iTemp265) ? 0.0001f : (((iTemp266 | iTemp267)) ? (0.04761905f * fTemp257) : fTemp257)));
			float 	fTemp270 = (fRec99[1] - fTemp269);
			float 	fTemp271 = (fRec99[1] + fTemp269);
			fRec99[0] = (((fTemp271 < fTemp268)) ? fTemp271 : (((fTemp270 > fTemp268)) ? fTemp270 : fTemp268));
			fRec95[0] = fRec99[0];
			fRec93[0] = (fRec95[0] - (fConst16 * ((fConst14 * fRec93[2]) + (fConst12 * fRec93[1]))));
			float 	fTemp272 = min(0.99f, (fConst22 * (((3947.8418f * fRec93[0]) + (7895.6836f * fRec93[1])) + (3947.8418f * fRec93[2]))));
			float 	fTemp273 = min(1.0f, (fSlow91 + (((fTemp272 < 0.1f)) ? (1.0f - (1e+01f * fTemp272)) : 0.0f)));
			float 	fTemp274 = ((iTemp31) ? 0.0f : (fSlow92 + fRec105[1]));
			fRec105[0] = (fTemp274 - floorf(fTemp274));
			float 	fTemp275 = (499.0f * fRec105[0]);
			int 	iTemp276 = int(fTemp275);
			int 	iTemp277 = max(0, min(iTemp276, 499));
			float 	fTemp278 = ftbl2[iTemp277];
			int 	iTemp279 = max(0, min((iTemp276 + 1), 499));
			float 	fTemp280 = (fTemp275 - float(iTemp276));
			float 	fTemp281 = float((((fVec23[1] <= 0.003f) & iTemp250) != 1));
			fRec106[0] = max((fTemp281 * fRec106[1]), fSlow93);
			fRec107[0] = max((fRec107[1] * fTemp281), fSlow80);
			float 	fTemp282 = max(min(((0.5f * (fVec23[0] - fTemp272)) + (0.2f - (0.8f * ((iTemp251) ? (2.0f * (((fRec107[0] > fRec106[0])) ? fRec107[0] : (0.0f - fRec106[0]))) : fSlow81)))), 1.0f), 0.0f);
			float 	fTemp283 = ftbl3[iTemp277];
			float 	fTemp284 = (((fTemp283 + (fTemp280 * (ftbl3[iTemp279] - fTemp283))) * (1.0f - fTemp282)) + (fTemp282 * (fTemp278 + (fTemp280 * (ftbl2[iTemp279] - fTemp278)))));
			float 	fTemp285 = (fRec104[1] - fConst24);
			float 	fTemp286 = (fConst24 + fRec104[1]);
			fRec104[0] = (((fTemp286 < fTemp284)) ? fTemp286 : (((fTemp285 > fTemp284)) ? fTemp285 : fTemp284));
			float 	fTemp287 = ((iTemp31) ? 0.0f : (fSlow94 + fRec108[1]));
			fRec108[0] = (fTemp287 - floorf(fTemp287));
			float 	fTemp288 = (499.0f * fRec108[0]);
			int 	iTemp289 = int(fTemp288);
			float 	fTemp290 = ftbl3[max(0, min(iTemp289, 499))];
			float 	fTemp291 = ((iTemp31) ? 0.0f : (fSlow95 + fRec109[1]));
			fRec109[0] = (fTemp291 - floorf(fTemp291));
			float 	fTemp292 = (499.0f * fRec109[0]);
			int 	iTemp293 = int(fTemp292);
			float 	fTemp294 = ftbl2[max(0, min(iTemp293, 499))];
			fRec0[0] = ((1.37f * ((((((fTemp272 * ((0.5f * ((((0.2f * (fTemp294 + ((fTemp292 - float(iTemp293)) * (ftbl2[max(0, min((iTemp293 + 1), 499))] - fTemp294)))) + (0.8f * (fTemp290 + ((fTemp288 - float(iTemp289)) * (ftbl3[max(0, min((iTemp289 + 1), 499))] - fTemp290))))) * fSlow84) * fSlow82)) + (((fRec104[0] * (1.0f - fTemp273)) + (6.451612e-08f * (fTemp273 * fTemp30))) * fSlow85))) + (fTemp224 * ((0.5f * ((((0.2f * (fTemp246 + ((fTemp244 - float(iTemp245)) * (ftbl2[max(0, min((iTemp245 + 1), 499))] - fTemp246)))) + (0.8f * (fTemp242 + ((fTemp240 - float(iTemp241)) * (ftbl3[max(0, min((iTemp241 + 1), 499))] - fTemp242))))) * fSlow68) * fSlow66)) + (((fRec87[0] * (1.0f - fTemp225)) + (6.451612e-08f * (fTemp30 * fTemp225))) * fSlow69)))) + (fTemp176 * ((0.5f * ((((0.2f * (fTemp198 + ((fTemp196 - float(iTemp197)) * (ftbl2[max(0, min((iTemp197 + 1), 499))] - fTemp198)))) + (0.8f * (fTemp194 + ((fTemp192 - float(iTemp193)) * (ftbl3[max(0, min((iTemp193 + 1), 499))] - fTemp194))))) * fSlow52) * fSlow50)) + (((fRec70[0] * (1.0f - fTemp177)) + (6.451612e-08f * (fTemp30 * fTemp177))) * fSlow53)))) + (fTemp128 * ((0.5f * ((((0.2f * (fTemp150 + ((fTemp148 - float(iTemp149)) * (ftbl2[max(0, min((iTemp149 + 1), 499))] - fTemp150)))) + (0.8f * (fTemp146 + ((fTemp144 - float(iTemp145)) * (ftbl3[max(0, min((iTemp145 + 1), 499))] - fTemp146))))) * fSlow36) * fSlow34)) + (((fRec53[0] * (1.0f - fTemp129)) + (6.451612e-08f * (fTemp30 * fTemp129))) * fSlow37)))) + (fTemp80 * ((0.5f * ((((0.2f * (fTemp102 + ((fTemp100 - float(iTemp101)) * (ftbl2[max(0, min((iTemp101 + 1), 499))] - fTemp102)))) + (0.8f * (fTemp98 + ((fTemp96 - float(iTemp97)) * (ftbl3[max(0, min((iTemp97 + 1), 499))] - fTemp98))))) * fSlow20) * fSlow18)) + (((fRec36[0] * (1.0f - fTemp81)) + (6.451612e-08f * (fTemp30 * fTemp81))) * fSlow21)))) + (fTemp28 * ((0.5f * ((((0.2f * (fTemp54 + ((fTemp52 - float(iTemp53)) * (ftbl2[max(0, min((iTemp53 + 1), 499))] - fTemp54)))) + (0.8f * (fTemp50 + ((fTemp48 - float(iTemp49)) * (ftbl3[max(0, min((iTemp49 + 1), 499))] - fTemp50))))) * fSlow4) * fSlow2)) + (((fRec17[0] * (1.0f - fTemp29)) + (6.451612e-08f * (fTemp30 * fTemp29))) * fSlow5))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst27 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec104[1] = fRec104[0];
			fRec107[1] = fRec107[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec93[2] = fRec93[1]; fRec93[1] = fRec93[0];
			fRec95[1] = fRec95[0];
			fRec99[1] = fRec99[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			iRec101[1] = iRec101[0];
			iRec100[1] = iRec100[0];
			iVec24[1] = iVec24[0];
			iRec94[2] = iRec94[1]; iRec94[1] = iRec94[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fVec23[1] = fVec23[0];
			iRec96[1] = iRec96[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec87[1] = fRec87[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec76[2] = fRec76[1]; fRec76[1] = fRec76[0];
			fRec78[1] = fRec78[0];
			fRec82[1] = fRec82[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			iRec84[1] = iRec84[0];
			iRec83[1] = iRec83[0];
			iVec20[1] = iVec20[0];
			iRec77[2] = iRec77[1]; iRec77[1] = iRec77[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fVec19[1] = fVec19[0];
			iRec79[1] = iRec79[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec70[1] = fRec70[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec59[2] = fRec59[1]; fRec59[1] = fRec59[0];
			fRec61[1] = fRec61[0];
			fRec65[1] = fRec65[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			iRec67[1] = iRec67[0];
			iRec66[1] = iRec66[0];
			iVec16[1] = iVec16[0];
			iRec60[2] = iRec60[1]; iRec60[1] = iRec60[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fVec15[1] = fVec15[0];
			iRec62[1] = iRec62[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec53[1] = fRec53[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			iRec50[1] = iRec50[0];
			iRec49[1] = iRec49[0];
			iVec12[1] = iVec12[0];
			iRec43[2] = iRec43[1]; iRec43[1] = iRec43[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fVec11[1] = fVec11[0];
			iRec45[1] = iRec45[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec36[1] = fRec36[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			iRec33[1] = iRec33[0];
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
			fRec17[1] = fRec17[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec15[2] = fRec15[1]; fRec15[1] = fRec15[0];
			iRec16[1] = iRec16[0];
			fRec2[2] = fRec2[1]; fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec9[1] = fRec9[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			iRec12[1] = iRec12[0];
			iRec11[1] = iRec11[0];
			iVec4[1] = iVec4[0];
			iRec3[2] = iRec3[1]; iRec3[1] = iRec3[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fVec3[1] = fVec3[0];
			iRec5[1] = iRec5[0];
			iRec6[1] = iRec6[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[1000];
float 	mydsp::ftbl1[21];
float 	mydsp::ftbl2[500];
float 	mydsp::ftbl3[500];

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
