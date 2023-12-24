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
		int 	iRec20[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec20[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec20[0] = (iRec20[1] + 1);
				float 	fTemp40 = float((iRec20[0] + -1));
				float 	fTemp41 = (0.002004008f * fTemp40);
				output[i] = (((fTemp41 < 0.5f)) ? ((0.008016032f * fTemp40) + -1.0f) : ((4.0f * (1.0f - fTemp41)) + -1.0f));
				// post processing
				iRec20[1] = iRec20[0];
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
	static float 	ftbl3[500];
	float 	fConst24;
	float 	fRec17[2];
	float 	fConst25;
	float 	fRec21[2];
	float 	fConst26;
	float 	fRec22[2];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec26[2];
	float 	fVec7[2];
	float 	fRec27[2];
	float 	fRec28[2];
	int 	iRec24[3];
	int 	iVec8[2];
	int 	iRec30[2];
	int 	iRec31[2];
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fRec29[2];
	float 	fRec25[2];
	float 	fRec23[3];
	float 	fRec35[2];
	float 	fRec34[2];
	float 	fRec36[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec41[2];
	float 	fVec11[2];
	float 	fRec42[2];
	float 	fRec43[2];
	int 	iRec39[3];
	int 	iVec12[2];
	int 	iRec45[2];
	int 	iRec46[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec44[2];
	float 	fRec40[2];
	float 	fRec38[3];
	float 	fRec50[2];
	float 	fRec49[2];
	float 	fRec51[2];
	float 	fRec52[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec56[2];
	float 	fVec15[2];
	float 	fRec57[2];
	float 	fRec58[2];
	int 	iRec54[3];
	int 	iVec16[2];
	int 	iRec60[2];
	int 	iRec61[2];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec59[2];
	float 	fRec55[2];
	float 	fRec53[3];
	float 	fRec65[2];
	float 	fRec64[2];
	float 	fRec66[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec71[2];
	float 	fVec19[2];
	float 	fRec72[2];
	float 	fRec73[2];
	int 	iRec69[3];
	int 	iVec20[2];
	int 	iRec75[2];
	int 	iRec76[2];
	float 	fRec77[2];
	float 	fRec78[2];
	float 	fRec74[2];
	float 	fRec70[2];
	float 	fRec68[3];
	float 	fRec80[2];
	float 	fRec79[2];
	float 	fRec81[2];
	float 	fRec82[2];
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec86[2];
	float 	fVec23[2];
	float 	fRec87[2];
	float 	fRec88[2];
	int 	iRec84[3];
	int 	iVec24[2];
	int 	iRec90[2];
	int 	iRec91[2];
	float 	fRec92[2];
	float 	fRec93[2];
	float 	fRec89[2];
	float 	fRec85[2];
	float 	fRec83[3];
	float 	fRec95[2];
	float 	fRec94[2];
	float 	fRec96[2];
	float 	fRec97[2];
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
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<3; i++) iRec24[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<3; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec75[i] = 0;
		for (int i=0; i<2; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<3; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<3; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
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
		float 	fSlow0 = ftbl0[int(((499.5f * (float(fslider0) + 1.0f)) + 0.5f))];
		float 	fSlow1 = (fSlow0 + 1.0f);
		float 	fSlow2 = fastpow2((0.083333336f * float(fslider1)));
		float 	fSlow3 = ((((8.175799f * fSlow2) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow4 = (1.0f - (0.5f * (fSlow3 * fSlow1)));
		float 	fSlow5 = float(fslider2);
		float 	fSlow6 = float(fslider3);
		int 	iSlow7 = (fSlow6 == 0.0f);
		float 	fSlow8 = (0.9f * fSlow6);
		float 	fSlow9 = (0.0f - fSlow8);
		float 	fSlow10 = max(0.05f, (0.1f - fabsf(fSlow8)));
		float 	fSlow11 = (fConst23 * fSlow2);
		float 	fSlow12 = (0.2f - (0.8f * fSlow0));
		float 	fSlow13 = (fConst25 * fSlow2);
		float 	fSlow14 = (fConst26 * fSlow2);
		float 	fSlow15 = ftbl0[int(((499.5f * (float(fslider4) + 1.0f)) + 0.5f))];
		float 	fSlow16 = (fSlow15 + 1.0f);
		float 	fSlow17 = fastpow2((0.083333336f * float(fslider5)));
		float 	fSlow18 = ((((8.175799f * fSlow17) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow19 = (1.0f - (0.5f * (fSlow18 * fSlow16)));
		float 	fSlow20 = float(fslider6);
		float 	fSlow21 = float(fslider7);
		int 	iSlow22 = (fSlow21 == 0.0f);
		float 	fSlow23 = (0.9f * fSlow21);
		float 	fSlow24 = (0.0f - fSlow23);
		float 	fSlow25 = max(0.05f, (0.1f - fabsf(fSlow23)));
		float 	fSlow26 = (fConst23 * fSlow17);
		float 	fSlow27 = (0.2f - (0.8f * fSlow15));
		float 	fSlow28 = (fConst25 * fSlow17);
		float 	fSlow29 = (fConst26 * fSlow17);
		float 	fSlow30 = ftbl0[int(((499.5f * (float(fslider8) + 1.0f)) + 0.5f))];
		float 	fSlow31 = (fSlow30 + 1.0f);
		float 	fSlow32 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow33 = ((((8.175799f * fSlow32) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow34 = (1.0f - (0.5f * (fSlow33 * fSlow31)));
		float 	fSlow35 = float(fslider10);
		float 	fSlow36 = float(fslider11);
		int 	iSlow37 = (fSlow36 == 0.0f);
		float 	fSlow38 = (0.9f * fSlow36);
		float 	fSlow39 = (0.0f - fSlow38);
		float 	fSlow40 = max(0.05f, (0.1f - fabsf(fSlow38)));
		float 	fSlow41 = (fConst23 * fSlow32);
		float 	fSlow42 = (0.2f - (0.8f * fSlow30));
		float 	fSlow43 = (fConst25 * fSlow32);
		float 	fSlow44 = (fConst26 * fSlow32);
		float 	fSlow45 = ftbl0[int(((499.5f * (float(fslider12) + 1.0f)) + 0.5f))];
		float 	fSlow46 = (fSlow45 + 1.0f);
		float 	fSlow47 = fastpow2((0.083333336f * float(fslider13)));
		float 	fSlow48 = ((((8.175799f * fSlow47) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow49 = (1.0f - (0.5f * (fSlow48 * fSlow46)));
		float 	fSlow50 = float(fslider14);
		float 	fSlow51 = float(fslider15);
		int 	iSlow52 = (fSlow51 == 0.0f);
		float 	fSlow53 = (0.9f * fSlow51);
		float 	fSlow54 = (0.0f - fSlow53);
		float 	fSlow55 = max(0.05f, (0.1f - fabsf(fSlow53)));
		float 	fSlow56 = (fConst23 * fSlow47);
		float 	fSlow57 = (0.2f - (0.8f * fSlow45));
		float 	fSlow58 = (fConst25 * fSlow47);
		float 	fSlow59 = (fConst26 * fSlow47);
		float 	fSlow60 = ftbl0[int(((499.5f * (float(fslider16) + 1.0f)) + 0.5f))];
		float 	fSlow61 = (fSlow60 + 1.0f);
		float 	fSlow62 = fastpow2((0.083333336f * float(fslider17)));
		float 	fSlow63 = ((((8.175799f * fSlow62) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow64 = (1.0f - (0.5f * (fSlow63 * fSlow61)));
		float 	fSlow65 = float(fslider18);
		float 	fSlow66 = float(fslider19);
		int 	iSlow67 = (fSlow66 == 0.0f);
		float 	fSlow68 = (0.9f * fSlow66);
		float 	fSlow69 = (0.0f - fSlow68);
		float 	fSlow70 = max(0.05f, (0.1f - fabsf(fSlow68)));
		float 	fSlow71 = (fConst23 * fSlow62);
		float 	fSlow72 = (0.2f - (0.8f * fSlow60));
		float 	fSlow73 = (fConst25 * fSlow62);
		float 	fSlow74 = (fConst26 * fSlow62);
		float 	fSlow75 = ftbl0[int(((499.5f * (float(fslider20) + 1.0f)) + 0.5f))];
		float 	fSlow76 = (fSlow75 + 1.0f);
		float 	fSlow77 = fastpow2((0.083333336f * float(fslider21)));
		float 	fSlow78 = ((((8.175799f * fSlow77) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow79 = (1.0f - (0.5f * (fSlow78 * fSlow76)));
		float 	fSlow80 = float(fslider22);
		float 	fSlow81 = float(fslider23);
		int 	iSlow82 = (fSlow81 == 0.0f);
		float 	fSlow83 = (0.9f * fSlow81);
		float 	fSlow84 = (0.0f - fSlow83);
		float 	fSlow85 = max(0.05f, (0.1f - fabsf(fSlow83)));
		float 	fSlow86 = (fConst23 * fSlow77);
		float 	fSlow87 = (0.2f - (0.8f * fSlow75));
		float 	fSlow88 = (fConst25 * fSlow77);
		float 	fSlow89 = (fConst26 * fSlow77);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			fVec1[0] = fSlow6;
			int 	iTemp1 = (fSlow8 != (0.9f * fVec1[1]));
			iVec2[0] = iTemp1;
			int 	iTemp2 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec6[0] = (iRec6[1] + 1);
			int 	iTemp3 = (iRec6[0] + -1);
			iRec5[0] = ((iRec5[1] * (1 - iTemp2)) + (iTemp3 * iTemp2));
			float 	fTemp4 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec5[0])))) > 0.5f) & iSlow7)) ? 0.0f : fSlow5) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp4;
			int 	iTemp5 = (fVec3[0] > 0.003f);
			int 	iTemp6 = (fVec3[0] <= 0.003f);
			float 	fTemp7 = float((iTemp6 | (fVec3[1] >= 0.003f)));
			fRec7[0] = max((fRec7[1] * fTemp7), fSlow8);
			fRec8[0] = max((fTemp7 * fRec8[1]), fSlow9);
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
			float 	fTemp29 = min(1.0f, (fSlow10 + (((fTemp28 < 0.1f)) ? (1.0f - (1e+01f * fTemp28)) : 0.0f)));
			iRec16[0] = ((1103515245 * iRec16[1]) + 12345);
			fRec15[0] = (((1.9999999f * fRec15[1]) + (4.656613e-10f * float(iRec16[0]))) - (0.9999999f * fRec15[2]));
			float 	fTemp30 = (fRec15[0] - fRec15[2]);
			int 	iTemp31 = (1 - iVec0[1]);
			float 	fTemp32 = ((iTemp31) ? 0.0f : (fSlow11 + fRec19[1]));
			fRec19[0] = (fTemp32 - floorf(fTemp32));
			float 	fTemp33 = (499.0f * fRec19[0]);
			int 	iTemp34 = int(fTemp33);
			int 	iTemp35 = max(0, min(iTemp34, 499));
			float 	fTemp36 = ftbl2[iTemp35];
			int 	iTemp37 = max(0, min((iTemp34 + 1), 499));
			float 	fTemp38 = (fTemp33 - float(iTemp34));
			float 	fTemp39 = max(min(((0.5f * (fVec3[0] - fTemp28)) + fSlow12), 1.0f), 0.0f);
			float 	fTemp42 = ftbl3[iTemp35];
			float 	fTemp43 = (((fTemp42 + (fTemp38 * (ftbl3[iTemp37] - fTemp42))) * (1.0f - fTemp39)) + (fTemp39 * (fTemp36 + (fTemp38 * (ftbl2[iTemp37] - fTemp36)))));
			float 	fTemp44 = (fRec17[1] - fConst24);
			float 	fTemp45 = (fConst24 + fRec17[1]);
			fRec17[0] = (((fTemp45 < fTemp43)) ? fTemp45 : (((fTemp44 > fTemp43)) ? fTemp44 : fTemp43));
			float 	fTemp46 = ((iTemp31) ? 0.0f : (fSlow13 + fRec21[1]));
			fRec21[0] = (fTemp46 - floorf(fTemp46));
			float 	fTemp47 = (499.0f * fRec21[0]);
			int 	iTemp48 = int(fTemp47);
			float 	fTemp49 = ftbl3[max(0, min(iTemp48, 499))];
			float 	fTemp50 = ((iTemp31) ? 0.0f : (fSlow14 + fRec22[1]));
			fRec22[0] = (fTemp50 - floorf(fTemp50));
			float 	fTemp51 = (499.0f * fRec22[0]);
			int 	iTemp52 = int(fTemp51);
			float 	fTemp53 = ftbl2[max(0, min(iTemp52, 499))];
			fVec5[0] = fSlow21;
			int 	iTemp54 = (fSlow23 != (0.9f * fVec5[1]));
			iVec6[0] = iTemp54;
			int 	iTemp55 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec26[0] = ((iRec26[1] * (1 - iTemp55)) + (iTemp3 * iTemp55));
			float 	fTemp56 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec26[0])))) > 0.5f) & iSlow22)) ? 0.0f : fSlow20) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp56;
			int 	iTemp57 = (fVec7[0] > 0.003f);
			int 	iTemp58 = (fVec7[0] <= 0.003f);
			float 	fTemp59 = float((iTemp58 | (fVec7[1] >= 0.003f)));
			fRec27[0] = max((fRec27[1] * fTemp59), fSlow23);
			fRec28[0] = max((fTemp59 * fRec28[1]), fSlow24);
			float 	fTemp60 = (min(1.0f, fRec28[0]) + min(1.0f, fRec27[0]));
			int 	iTemp61 = (fVec7[0] >= fRec25[1]);
			int 	iTemp62 = (fRec25[1] <= 0.001f);
			int 	iTemp63 = (((iRec24[1] >= 4)) ? (((iRec24[1] >= 6)) ? ((iTemp62) ? 0 : ((iTemp57) ? 1 : 6)) : (((iRec24[1] >= 5)) ? ((iTemp58) ? 3 : ((iTemp61) ? 4 : 5)) : ((iTemp58) ? 3 : (((fVec7[0] <= fRec25[1])) ? 5 : 4)))) : (((iRec24[1] >= 2)) ? (((iRec24[1] >= 3)) ? (((iTemp58 & iTemp62)) ? 0 : ((iTemp57) ? 1 : 3)) : ((iTemp58) ? 6 : ((iTemp61) ? 4 : 2))) : (((iRec24[1] >= 1)) ? (((fRec25[1] >= min(fTemp60, 1.0f))) ? ((iTemp58) ? 6 : 2) : 1) : ((iTemp57) ? 1 : 0))));
			iRec24[0] = iTemp63;
			float 	fTemp64 = (((iTemp63 >= 4)) ? (((iTemp63 >= 6)) ? fConst0 : fConst21) : (((iTemp63 >= 2)) ? (((iTemp63 >= 3)) ? fConst20 : fConst19) : (((iTemp63 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp65 = (iRec24[1] != iRec24[2]);
			iVec8[0] = iTemp65;
			int 	iTemp66 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec30[0] = ((iRec30[1] * (1 - iTemp66)) + (iTemp3 * iTemp66));
			float 	fTemp67 = (2e+01f * (((fTemp64 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec30[0]))) / fTemp64) : 0.0f));
			int 	iTemp68 = int(fTemp67);
			float 	fTemp69 = ftbl1[max(0, int(min(int(iTemp68), 20)))];
			float 	fTemp70 = (fTemp69 + ((fTemp67 - float(iTemp68)) * (ftbl1[max(0, int(min(int((iTemp68 + 1)), 20)))] - fTemp69)));
			iRec31[0] = iRec24[1];
			int 	iTemp71 = (iRec31[1] == iRec24[1]);
			int 	iTemp72 = (iRec24[1] == 0);
			fRec32[0] = ((iTemp72) ? fVec7[0] : ((iTemp71) ? min(min(fRec32[1], fVec7[0]), fRec25[1]) : min(fVec7[0], fRec25[1])));
			fRec33[0] = ((iTemp72) ? fVec7[0] : ((iTemp71) ? max(max(fRec33[1], fVec7[0]), fRec25[1]) : max(fVec7[0], fRec25[1])));
			int 	iTemp73 = (iRec24[1] == 3);
			int 	iTemp74 = (iRec24[1] == 6);
			float 	fTemp75 = (((iRec24[1] == 1)) ? min(1.0f, fTemp60) : ((iTemp72) ? 0.0f : ((iTemp74) ? (fTemp60 * fTemp70) : ((iTemp73) ? (fRec33[0] * fTemp70) : fVec7[0]))));
			float 	fTemp76 = (1.0f / ((iTemp72) ? 0.0001f : (((iTemp73 | iTemp74)) ? (0.04761905f * fTemp64) : fTemp64)));
			float 	fTemp77 = (fRec29[1] - fTemp76);
			float 	fTemp78 = (fRec29[1] + fTemp76);
			fRec29[0] = (((fTemp78 < fTemp75)) ? fTemp78 : (((fTemp77 > fTemp75)) ? fTemp77 : fTemp75));
			fRec25[0] = fRec29[0];
			fRec23[0] = (fRec25[0] - (fConst16 * ((fConst14 * fRec23[2]) + (fConst12 * fRec23[1]))));
			float 	fTemp79 = min(0.99f, (fConst22 * (((3947.8418f * fRec23[0]) + (7895.6836f * fRec23[1])) + (3947.8418f * fRec23[2]))));
			float 	fTemp80 = min(1.0f, (fSlow25 + (((fTemp79 < 0.1f)) ? (1.0f - (1e+01f * fTemp79)) : 0.0f)));
			float 	fTemp81 = ((iTemp31) ? 0.0f : (fSlow26 + fRec35[1]));
			fRec35[0] = (fTemp81 - floorf(fTemp81));
			float 	fTemp82 = (499.0f * fRec35[0]);
			int 	iTemp83 = int(fTemp82);
			int 	iTemp84 = max(0, min(iTemp83, 499));
			float 	fTemp85 = ftbl2[iTemp84];
			int 	iTemp86 = max(0, min((iTemp83 + 1), 499));
			float 	fTemp87 = (fTemp82 - float(iTemp83));
			float 	fTemp88 = max(min(((0.5f * (fVec7[0] - fTemp79)) + fSlow27), 1.0f), 0.0f);
			float 	fTemp89 = ftbl3[iTemp84];
			float 	fTemp90 = (((fTemp89 + (fTemp87 * (ftbl3[iTemp86] - fTemp89))) * (1.0f - fTemp88)) + (fTemp88 * (fTemp85 + (fTemp87 * (ftbl2[iTemp86] - fTemp85)))));
			float 	fTemp91 = (fRec34[1] - fConst24);
			float 	fTemp92 = (fConst24 + fRec34[1]);
			fRec34[0] = (((fTemp92 < fTemp90)) ? fTemp92 : (((fTemp91 > fTemp90)) ? fTemp91 : fTemp90));
			float 	fTemp93 = ((iTemp31) ? 0.0f : (fSlow28 + fRec36[1]));
			fRec36[0] = (fTemp93 - floorf(fTemp93));
			float 	fTemp94 = (499.0f * fRec36[0]);
			int 	iTemp95 = int(fTemp94);
			float 	fTemp96 = ftbl3[max(0, min(iTemp95, 499))];
			float 	fTemp97 = ((iTemp31) ? 0.0f : (fSlow29 + fRec37[1]));
			fRec37[0] = (fTemp97 - floorf(fTemp97));
			float 	fTemp98 = (499.0f * fRec37[0]);
			int 	iTemp99 = int(fTemp98);
			float 	fTemp100 = ftbl2[max(0, min(iTemp99, 499))];
			fVec9[0] = fSlow36;
			int 	iTemp101 = (fSlow38 != (0.9f * fVec9[1]));
			iVec10[0] = iTemp101;
			int 	iTemp102 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec41[0] = ((iRec41[1] * (1 - iTemp102)) + (iTemp3 * iTemp102));
			float 	fTemp103 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec41[0])))) > 0.5f) & iSlow37)) ? 0.0f : fSlow35) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp103;
			int 	iTemp104 = (fVec11[0] > 0.003f);
			int 	iTemp105 = (fVec11[0] <= 0.003f);
			float 	fTemp106 = float((iTemp105 | (fVec11[1] >= 0.003f)));
			fRec42[0] = max((fRec42[1] * fTemp106), fSlow38);
			fRec43[0] = max((fTemp106 * fRec43[1]), fSlow39);
			float 	fTemp107 = (min(1.0f, fRec43[0]) + min(1.0f, fRec42[0]));
			int 	iTemp108 = (fVec11[0] >= fRec40[1]);
			int 	iTemp109 = (fRec40[1] <= 0.001f);
			int 	iTemp110 = (((iRec39[1] >= 4)) ? (((iRec39[1] >= 6)) ? ((iTemp109) ? 0 : ((iTemp104) ? 1 : 6)) : (((iRec39[1] >= 5)) ? ((iTemp105) ? 3 : ((iTemp108) ? 4 : 5)) : ((iTemp105) ? 3 : (((fVec11[0] <= fRec40[1])) ? 5 : 4)))) : (((iRec39[1] >= 2)) ? (((iRec39[1] >= 3)) ? (((iTemp105 & iTemp109)) ? 0 : ((iTemp104) ? 1 : 3)) : ((iTemp105) ? 6 : ((iTemp108) ? 4 : 2))) : (((iRec39[1] >= 1)) ? (((fRec40[1] >= min(fTemp107, 1.0f))) ? ((iTemp105) ? 6 : 2) : 1) : ((iTemp104) ? 1 : 0))));
			iRec39[0] = iTemp110;
			float 	fTemp111 = (((iTemp110 >= 4)) ? (((iTemp110 >= 6)) ? fConst0 : fConst21) : (((iTemp110 >= 2)) ? (((iTemp110 >= 3)) ? fConst20 : fConst19) : (((iTemp110 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp112 = (iRec39[1] != iRec39[2]);
			iVec12[0] = iTemp112;
			int 	iTemp113 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec45[0] = ((iRec45[1] * (1 - iTemp113)) + (iTemp3 * iTemp113));
			float 	fTemp114 = (2e+01f * (((fTemp111 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec45[0]))) / fTemp111) : 0.0f));
			int 	iTemp115 = int(fTemp114);
			float 	fTemp116 = ftbl1[max(0, int(min(int(iTemp115), 20)))];
			float 	fTemp117 = (fTemp116 + ((fTemp114 - float(iTemp115)) * (ftbl1[max(0, int(min(int((iTemp115 + 1)), 20)))] - fTemp116)));
			iRec46[0] = iRec39[1];
			int 	iTemp118 = (iRec46[1] == iRec39[1]);
			int 	iTemp119 = (iRec39[1] == 0);
			fRec47[0] = ((iTemp119) ? fVec11[0] : ((iTemp118) ? min(min(fRec47[1], fVec11[0]), fRec40[1]) : min(fVec11[0], fRec40[1])));
			fRec48[0] = ((iTemp119) ? fVec11[0] : ((iTemp118) ? max(max(fRec48[1], fVec11[0]), fRec40[1]) : max(fVec11[0], fRec40[1])));
			int 	iTemp120 = (iRec39[1] == 3);
			int 	iTemp121 = (iRec39[1] == 6);
			float 	fTemp122 = (((iRec39[1] == 1)) ? min(1.0f, fTemp107) : ((iTemp119) ? 0.0f : ((iTemp121) ? (fTemp107 * fTemp117) : ((iTemp120) ? (fRec48[0] * fTemp117) : fVec11[0]))));
			float 	fTemp123 = (1.0f / ((iTemp119) ? 0.0001f : (((iTemp120 | iTemp121)) ? (0.04761905f * fTemp111) : fTemp111)));
			float 	fTemp124 = (fRec44[1] - fTemp123);
			float 	fTemp125 = (fRec44[1] + fTemp123);
			fRec44[0] = (((fTemp125 < fTemp122)) ? fTemp125 : (((fTemp124 > fTemp122)) ? fTemp124 : fTemp122));
			fRec40[0] = fRec44[0];
			fRec38[0] = (fRec40[0] - (fConst16 * ((fConst14 * fRec38[2]) + (fConst12 * fRec38[1]))));
			float 	fTemp126 = min(0.99f, (fConst22 * (((3947.8418f * fRec38[0]) + (7895.6836f * fRec38[1])) + (3947.8418f * fRec38[2]))));
			float 	fTemp127 = min(1.0f, (fSlow40 + (((fTemp126 < 0.1f)) ? (1.0f - (1e+01f * fTemp126)) : 0.0f)));
			float 	fTemp128 = ((iTemp31) ? 0.0f : (fSlow41 + fRec50[1]));
			fRec50[0] = (fTemp128 - floorf(fTemp128));
			float 	fTemp129 = (499.0f * fRec50[0]);
			int 	iTemp130 = int(fTemp129);
			int 	iTemp131 = max(0, min(iTemp130, 499));
			float 	fTemp132 = ftbl2[iTemp131];
			int 	iTemp133 = max(0, min((iTemp130 + 1), 499));
			float 	fTemp134 = (fTemp129 - float(iTemp130));
			float 	fTemp135 = max(min(((0.5f * (fVec11[0] - fTemp126)) + fSlow42), 1.0f), 0.0f);
			float 	fTemp136 = ftbl3[iTemp131];
			float 	fTemp137 = (((fTemp136 + (fTemp134 * (ftbl3[iTemp133] - fTemp136))) * (1.0f - fTemp135)) + (fTemp135 * (fTemp132 + (fTemp134 * (ftbl2[iTemp133] - fTemp132)))));
			float 	fTemp138 = (fRec49[1] - fConst24);
			float 	fTemp139 = (fConst24 + fRec49[1]);
			fRec49[0] = (((fTemp139 < fTemp137)) ? fTemp139 : (((fTemp138 > fTemp137)) ? fTemp138 : fTemp137));
			float 	fTemp140 = ((iTemp31) ? 0.0f : (fSlow43 + fRec51[1]));
			fRec51[0] = (fTemp140 - floorf(fTemp140));
			float 	fTemp141 = (499.0f * fRec51[0]);
			int 	iTemp142 = int(fTemp141);
			float 	fTemp143 = ftbl3[max(0, min(iTemp142, 499))];
			float 	fTemp144 = ((iTemp31) ? 0.0f : (fSlow44 + fRec52[1]));
			fRec52[0] = (fTemp144 - floorf(fTemp144));
			float 	fTemp145 = (499.0f * fRec52[0]);
			int 	iTemp146 = int(fTemp145);
			float 	fTemp147 = ftbl2[max(0, min(iTemp146, 499))];
			fVec13[0] = fSlow51;
			int 	iTemp148 = (fSlow53 != (0.9f * fVec13[1]));
			iVec14[0] = iTemp148;
			int 	iTemp149 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec56[0] = ((iRec56[1] * (1 - iTemp149)) + (iTemp3 * iTemp149));
			float 	fTemp150 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec56[0])))) > 0.5f) & iSlow52)) ? 0.0f : fSlow50) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp150;
			int 	iTemp151 = (fVec15[0] > 0.003f);
			int 	iTemp152 = (fVec15[0] <= 0.003f);
			float 	fTemp153 = float((iTemp152 | (fVec15[1] >= 0.003f)));
			fRec57[0] = max((fRec57[1] * fTemp153), fSlow53);
			fRec58[0] = max((fTemp153 * fRec58[1]), fSlow54);
			float 	fTemp154 = (min(1.0f, fRec58[0]) + min(1.0f, fRec57[0]));
			int 	iTemp155 = (fVec15[0] >= fRec55[1]);
			int 	iTemp156 = (fRec55[1] <= 0.001f);
			int 	iTemp157 = (((iRec54[1] >= 4)) ? (((iRec54[1] >= 6)) ? ((iTemp156) ? 0 : ((iTemp151) ? 1 : 6)) : (((iRec54[1] >= 5)) ? ((iTemp152) ? 3 : ((iTemp155) ? 4 : 5)) : ((iTemp152) ? 3 : (((fVec15[0] <= fRec55[1])) ? 5 : 4)))) : (((iRec54[1] >= 2)) ? (((iRec54[1] >= 3)) ? (((iTemp152 & iTemp156)) ? 0 : ((iTemp151) ? 1 : 3)) : ((iTemp152) ? 6 : ((iTemp155) ? 4 : 2))) : (((iRec54[1] >= 1)) ? (((fRec55[1] >= min(fTemp154, 1.0f))) ? ((iTemp152) ? 6 : 2) : 1) : ((iTemp151) ? 1 : 0))));
			iRec54[0] = iTemp157;
			float 	fTemp158 = (((iTemp157 >= 4)) ? (((iTemp157 >= 6)) ? fConst0 : fConst21) : (((iTemp157 >= 2)) ? (((iTemp157 >= 3)) ? fConst20 : fConst19) : (((iTemp157 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp159 = (iRec54[1] != iRec54[2]);
			iVec16[0] = iTemp159;
			int 	iTemp160 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp160)) + (iTemp3 * iTemp160));
			float 	fTemp161 = (2e+01f * (((fTemp158 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec60[0]))) / fTemp158) : 0.0f));
			int 	iTemp162 = int(fTemp161);
			float 	fTemp163 = ftbl1[max(0, int(min(int(iTemp162), 20)))];
			float 	fTemp164 = (fTemp163 + ((fTemp161 - float(iTemp162)) * (ftbl1[max(0, int(min(int((iTemp162 + 1)), 20)))] - fTemp163)));
			iRec61[0] = iRec54[1];
			int 	iTemp165 = (iRec61[1] == iRec54[1]);
			int 	iTemp166 = (iRec54[1] == 0);
			fRec62[0] = ((iTemp166) ? fVec15[0] : ((iTemp165) ? min(min(fRec62[1], fVec15[0]), fRec55[1]) : min(fVec15[0], fRec55[1])));
			fRec63[0] = ((iTemp166) ? fVec15[0] : ((iTemp165) ? max(max(fRec63[1], fVec15[0]), fRec55[1]) : max(fVec15[0], fRec55[1])));
			int 	iTemp167 = (iRec54[1] == 3);
			int 	iTemp168 = (iRec54[1] == 6);
			float 	fTemp169 = (((iRec54[1] == 1)) ? min(1.0f, fTemp154) : ((iTemp166) ? 0.0f : ((iTemp168) ? (fTemp154 * fTemp164) : ((iTemp167) ? (fRec63[0] * fTemp164) : fVec15[0]))));
			float 	fTemp170 = (1.0f / ((iTemp166) ? 0.0001f : (((iTemp167 | iTemp168)) ? (0.04761905f * fTemp158) : fTemp158)));
			float 	fTemp171 = (fRec59[1] - fTemp170);
			float 	fTemp172 = (fRec59[1] + fTemp170);
			fRec59[0] = (((fTemp172 < fTemp169)) ? fTemp172 : (((fTemp171 > fTemp169)) ? fTemp171 : fTemp169));
			fRec55[0] = fRec59[0];
			fRec53[0] = (fRec55[0] - (fConst16 * ((fConst14 * fRec53[2]) + (fConst12 * fRec53[1]))));
			float 	fTemp173 = min(0.99f, (fConst22 * (((3947.8418f * fRec53[0]) + (7895.6836f * fRec53[1])) + (3947.8418f * fRec53[2]))));
			float 	fTemp174 = min(1.0f, (fSlow55 + (((fTemp173 < 0.1f)) ? (1.0f - (1e+01f * fTemp173)) : 0.0f)));
			float 	fTemp175 = ((iTemp31) ? 0.0f : (fSlow56 + fRec65[1]));
			fRec65[0] = (fTemp175 - floorf(fTemp175));
			float 	fTemp176 = (499.0f * fRec65[0]);
			int 	iTemp177 = int(fTemp176);
			int 	iTemp178 = max(0, min(iTemp177, 499));
			float 	fTemp179 = ftbl2[iTemp178];
			int 	iTemp180 = max(0, min((iTemp177 + 1), 499));
			float 	fTemp181 = (fTemp176 - float(iTemp177));
			float 	fTemp182 = max(min(((0.5f * (fVec15[0] - fTemp173)) + fSlow57), 1.0f), 0.0f);
			float 	fTemp183 = ftbl3[iTemp178];
			float 	fTemp184 = (((fTemp183 + (fTemp181 * (ftbl3[iTemp180] - fTemp183))) * (1.0f - fTemp182)) + (fTemp182 * (fTemp179 + (fTemp181 * (ftbl2[iTemp180] - fTemp179)))));
			float 	fTemp185 = (fRec64[1] - fConst24);
			float 	fTemp186 = (fConst24 + fRec64[1]);
			fRec64[0] = (((fTemp186 < fTemp184)) ? fTemp186 : (((fTemp185 > fTemp184)) ? fTemp185 : fTemp184));
			float 	fTemp187 = ((iTemp31) ? 0.0f : (fSlow58 + fRec66[1]));
			fRec66[0] = (fTemp187 - floorf(fTemp187));
			float 	fTemp188 = (499.0f * fRec66[0]);
			int 	iTemp189 = int(fTemp188);
			float 	fTemp190 = ftbl3[max(0, min(iTemp189, 499))];
			float 	fTemp191 = ((iTemp31) ? 0.0f : (fSlow59 + fRec67[1]));
			fRec67[0] = (fTemp191 - floorf(fTemp191));
			float 	fTemp192 = (499.0f * fRec67[0]);
			int 	iTemp193 = int(fTemp192);
			float 	fTemp194 = ftbl2[max(0, min(iTemp193, 499))];
			fVec17[0] = fSlow66;
			int 	iTemp195 = (fSlow68 != (0.9f * fVec17[1]));
			iVec18[0] = iTemp195;
			int 	iTemp196 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec71[0] = ((iRec71[1] * (1 - iTemp196)) + (iTemp3 * iTemp196));
			float 	fTemp197 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec71[0])))) > 0.5f) & iSlow67)) ? 0.0f : fSlow65) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp197;
			int 	iTemp198 = (fVec19[0] > 0.003f);
			int 	iTemp199 = (fVec19[0] <= 0.003f);
			float 	fTemp200 = float((iTemp199 | (fVec19[1] >= 0.003f)));
			fRec72[0] = max((fRec72[1] * fTemp200), fSlow68);
			fRec73[0] = max((fTemp200 * fRec73[1]), fSlow69);
			float 	fTemp201 = (min(1.0f, fRec73[0]) + min(1.0f, fRec72[0]));
			int 	iTemp202 = (fVec19[0] >= fRec70[1]);
			int 	iTemp203 = (fRec70[1] <= 0.001f);
			int 	iTemp204 = (((iRec69[1] >= 4)) ? (((iRec69[1] >= 6)) ? ((iTemp203) ? 0 : ((iTemp198) ? 1 : 6)) : (((iRec69[1] >= 5)) ? ((iTemp199) ? 3 : ((iTemp202) ? 4 : 5)) : ((iTemp199) ? 3 : (((fVec19[0] <= fRec70[1])) ? 5 : 4)))) : (((iRec69[1] >= 2)) ? (((iRec69[1] >= 3)) ? (((iTemp199 & iTemp203)) ? 0 : ((iTemp198) ? 1 : 3)) : ((iTemp199) ? 6 : ((iTemp202) ? 4 : 2))) : (((iRec69[1] >= 1)) ? (((fRec70[1] >= min(fTemp201, 1.0f))) ? ((iTemp199) ? 6 : 2) : 1) : ((iTemp198) ? 1 : 0))));
			iRec69[0] = iTemp204;
			float 	fTemp205 = (((iTemp204 >= 4)) ? (((iTemp204 >= 6)) ? fConst0 : fConst21) : (((iTemp204 >= 2)) ? (((iTemp204 >= 3)) ? fConst20 : fConst19) : (((iTemp204 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp206 = (iRec69[1] != iRec69[2]);
			iVec20[0] = iTemp206;
			int 	iTemp207 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec75[0] = ((iRec75[1] * (1 - iTemp207)) + (iTemp3 * iTemp207));
			float 	fTemp208 = (2e+01f * (((fTemp205 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec75[0]))) / fTemp205) : 0.0f));
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl1[max(0, int(min(int(iTemp209), 20)))];
			float 	fTemp211 = (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl1[max(0, int(min(int((iTemp209 + 1)), 20)))] - fTemp210)));
			iRec76[0] = iRec69[1];
			int 	iTemp212 = (iRec76[1] == iRec69[1]);
			int 	iTemp213 = (iRec69[1] == 0);
			fRec77[0] = ((iTemp213) ? fVec19[0] : ((iTemp212) ? min(min(fRec77[1], fVec19[0]), fRec70[1]) : min(fVec19[0], fRec70[1])));
			fRec78[0] = ((iTemp213) ? fVec19[0] : ((iTemp212) ? max(max(fRec78[1], fVec19[0]), fRec70[1]) : max(fVec19[0], fRec70[1])));
			int 	iTemp214 = (iRec69[1] == 3);
			int 	iTemp215 = (iRec69[1] == 6);
			float 	fTemp216 = (((iRec69[1] == 1)) ? min(1.0f, fTemp201) : ((iTemp213) ? 0.0f : ((iTemp215) ? (fTemp201 * fTemp211) : ((iTemp214) ? (fRec78[0] * fTemp211) : fVec19[0]))));
			float 	fTemp217 = (1.0f / ((iTemp213) ? 0.0001f : (((iTemp214 | iTemp215)) ? (0.04761905f * fTemp205) : fTemp205)));
			float 	fTemp218 = (fRec74[1] - fTemp217);
			float 	fTemp219 = (fRec74[1] + fTemp217);
			fRec74[0] = (((fTemp219 < fTemp216)) ? fTemp219 : (((fTemp218 > fTemp216)) ? fTemp218 : fTemp216));
			fRec70[0] = fRec74[0];
			fRec68[0] = (fRec70[0] - (fConst16 * ((fConst14 * fRec68[2]) + (fConst12 * fRec68[1]))));
			float 	fTemp220 = min(0.99f, (fConst22 * (((3947.8418f * fRec68[0]) + (7895.6836f * fRec68[1])) + (3947.8418f * fRec68[2]))));
			float 	fTemp221 = min(1.0f, (fSlow70 + (((fTemp220 < 0.1f)) ? (1.0f - (1e+01f * fTemp220)) : 0.0f)));
			float 	fTemp222 = ((iTemp31) ? 0.0f : (fSlow71 + fRec80[1]));
			fRec80[0] = (fTemp222 - floorf(fTemp222));
			float 	fTemp223 = (499.0f * fRec80[0]);
			int 	iTemp224 = int(fTemp223);
			int 	iTemp225 = max(0, min(iTemp224, 499));
			float 	fTemp226 = ftbl2[iTemp225];
			int 	iTemp227 = max(0, min((iTemp224 + 1), 499));
			float 	fTemp228 = (fTemp223 - float(iTemp224));
			float 	fTemp229 = max(min(((0.5f * (fVec19[0] - fTemp220)) + fSlow72), 1.0f), 0.0f);
			float 	fTemp230 = ftbl3[iTemp225];
			float 	fTemp231 = (((fTemp230 + (fTemp228 * (ftbl3[iTemp227] - fTemp230))) * (1.0f - fTemp229)) + (fTemp229 * (fTemp226 + (fTemp228 * (ftbl2[iTemp227] - fTemp226)))));
			float 	fTemp232 = (fRec79[1] - fConst24);
			float 	fTemp233 = (fConst24 + fRec79[1]);
			fRec79[0] = (((fTemp233 < fTemp231)) ? fTemp233 : (((fTemp232 > fTemp231)) ? fTemp232 : fTemp231));
			float 	fTemp234 = ((iTemp31) ? 0.0f : (fSlow73 + fRec81[1]));
			fRec81[0] = (fTemp234 - floorf(fTemp234));
			float 	fTemp235 = (499.0f * fRec81[0]);
			int 	iTemp236 = int(fTemp235);
			float 	fTemp237 = ftbl3[max(0, min(iTemp236, 499))];
			float 	fTemp238 = ((iTemp31) ? 0.0f : (fSlow74 + fRec82[1]));
			fRec82[0] = (fTemp238 - floorf(fTemp238));
			float 	fTemp239 = (499.0f * fRec82[0]);
			int 	iTemp240 = int(fTemp239);
			float 	fTemp241 = ftbl2[max(0, min(iTemp240, 499))];
			fVec21[0] = fSlow81;
			int 	iTemp242 = (fSlow83 != (0.9f * fVec21[1]));
			iVec22[0] = iTemp242;
			int 	iTemp243 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp243)) + (iTemp3 * iTemp243));
			float 	fTemp244 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec6[0] + (-1 - iRec86[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp244;
			int 	iTemp245 = (fVec23[0] > 0.003f);
			int 	iTemp246 = (fVec23[0] <= 0.003f);
			float 	fTemp247 = float((iTemp246 | (fVec23[1] >= 0.003f)));
			fRec87[0] = max((fRec87[1] * fTemp247), fSlow83);
			fRec88[0] = max((fTemp247 * fRec88[1]), fSlow84);
			float 	fTemp248 = (min(1.0f, fRec88[0]) + min(1.0f, fRec87[0]));
			int 	iTemp249 = (fVec23[0] >= fRec85[1]);
			int 	iTemp250 = (fRec85[1] <= 0.001f);
			int 	iTemp251 = (((iRec84[1] >= 4)) ? (((iRec84[1] >= 6)) ? ((iTemp250) ? 0 : ((iTemp245) ? 1 : 6)) : (((iRec84[1] >= 5)) ? ((iTemp246) ? 3 : ((iTemp249) ? 4 : 5)) : ((iTemp246) ? 3 : (((fVec23[0] <= fRec85[1])) ? 5 : 4)))) : (((iRec84[1] >= 2)) ? (((iRec84[1] >= 3)) ? (((iTemp246 & iTemp250)) ? 0 : ((iTemp245) ? 1 : 3)) : ((iTemp246) ? 6 : ((iTemp249) ? 4 : 2))) : (((iRec84[1] >= 1)) ? (((fRec85[1] >= min(fTemp248, 1.0f))) ? ((iTemp246) ? 6 : 2) : 1) : ((iTemp245) ? 1 : 0))));
			iRec84[0] = iTemp251;
			float 	fTemp252 = (((iTemp251 >= 4)) ? (((iTemp251 >= 6)) ? fConst0 : fConst21) : (((iTemp251 >= 2)) ? (((iTemp251 >= 3)) ? fConst20 : fConst19) : (((iTemp251 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp253 = (iRec84[1] != iRec84[2]);
			iVec24[0] = iTemp253;
			int 	iTemp254 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp254)) + (iTemp3 * iTemp254));
			float 	fTemp255 = (2e+01f * (((fTemp252 > 0.0f)) ? (float((iRec6[0] + (-1 - iRec90[0]))) / fTemp252) : 0.0f));
			int 	iTemp256 = int(fTemp255);
			float 	fTemp257 = ftbl1[max(0, int(min(int(iTemp256), 20)))];
			float 	fTemp258 = (fTemp257 + ((fTemp255 - float(iTemp256)) * (ftbl1[max(0, int(min(int((iTemp256 + 1)), 20)))] - fTemp257)));
			iRec91[0] = iRec84[1];
			int 	iTemp259 = (iRec91[1] == iRec84[1]);
			int 	iTemp260 = (iRec84[1] == 0);
			fRec92[0] = ((iTemp260) ? fVec23[0] : ((iTemp259) ? min(min(fRec92[1], fVec23[0]), fRec85[1]) : min(fVec23[0], fRec85[1])));
			fRec93[0] = ((iTemp260) ? fVec23[0] : ((iTemp259) ? max(max(fRec93[1], fVec23[0]), fRec85[1]) : max(fVec23[0], fRec85[1])));
			int 	iTemp261 = (iRec84[1] == 3);
			int 	iTemp262 = (iRec84[1] == 6);
			float 	fTemp263 = (((iRec84[1] == 1)) ? min(1.0f, fTemp248) : ((iTemp260) ? 0.0f : ((iTemp262) ? (fTemp248 * fTemp258) : ((iTemp261) ? (fRec93[0] * fTemp258) : fVec23[0]))));
			float 	fTemp264 = (1.0f / ((iTemp260) ? 0.0001f : (((iTemp261 | iTemp262)) ? (0.04761905f * fTemp252) : fTemp252)));
			float 	fTemp265 = (fRec89[1] - fTemp264);
			float 	fTemp266 = (fRec89[1] + fTemp264);
			fRec89[0] = (((fTemp266 < fTemp263)) ? fTemp266 : (((fTemp265 > fTemp263)) ? fTemp265 : fTemp263));
			fRec85[0] = fRec89[0];
			fRec83[0] = (fRec85[0] - (fConst16 * ((fConst14 * fRec83[2]) + (fConst12 * fRec83[1]))));
			float 	fTemp267 = min(0.99f, (fConst22 * (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]))));
			float 	fTemp268 = min(1.0f, (fSlow85 + (((fTemp267 < 0.1f)) ? (1.0f - (1e+01f * fTemp267)) : 0.0f)));
			float 	fTemp269 = ((iTemp31) ? 0.0f : (fSlow86 + fRec95[1]));
			fRec95[0] = (fTemp269 - floorf(fTemp269));
			float 	fTemp270 = (499.0f * fRec95[0]);
			int 	iTemp271 = int(fTemp270);
			int 	iTemp272 = max(0, min(iTemp271, 499));
			float 	fTemp273 = ftbl2[iTemp272];
			int 	iTemp274 = max(0, min((iTemp271 + 1), 499));
			float 	fTemp275 = (fTemp270 - float(iTemp271));
			float 	fTemp276 = max(min(((0.5f * (fVec23[0] - fTemp267)) + fSlow87), 1.0f), 0.0f);
			float 	fTemp277 = ftbl3[iTemp272];
			float 	fTemp278 = (((fTemp277 + (fTemp275 * (ftbl3[iTemp274] - fTemp277))) * (1.0f - fTemp276)) + (fTemp276 * (fTemp273 + (fTemp275 * (ftbl2[iTemp274] - fTemp273)))));
			float 	fTemp279 = (fRec94[1] - fConst24);
			float 	fTemp280 = (fConst24 + fRec94[1]);
			fRec94[0] = (((fTemp280 < fTemp278)) ? fTemp280 : (((fTemp279 > fTemp278)) ? fTemp279 : fTemp278));
			float 	fTemp281 = ((iTemp31) ? 0.0f : (fSlow88 + fRec96[1]));
			fRec96[0] = (fTemp281 - floorf(fTemp281));
			float 	fTemp282 = (499.0f * fRec96[0]);
			int 	iTemp283 = int(fTemp282);
			float 	fTemp284 = ftbl3[max(0, min(iTemp283, 499))];
			float 	fTemp285 = ((iTemp31) ? 0.0f : (fSlow89 + fRec97[1]));
			fRec97[0] = (fTemp285 - floorf(fTemp285));
			float 	fTemp286 = (499.0f * fRec97[0]);
			int 	iTemp287 = int(fTemp286);
			float 	fTemp288 = ftbl2[max(0, min(iTemp287, 499))];
			fRec0[0] = ((1.37f * ((((((fTemp267 * ((0.5f * ((((0.2f * (fTemp288 + ((fTemp286 - float(iTemp287)) * (ftbl2[max(0, min((iTemp287 + 1), 499))] - fTemp288)))) + (0.8f * (fTemp284 + ((fTemp282 - float(iTemp283)) * (ftbl3[max(0, min((iTemp283 + 1), 499))] - fTemp284))))) * fSlow78) * fSlow76)) + (((fRec94[0] * (1.0f - fTemp268)) + (6.451612e-08f * (fTemp268 * fTemp30))) * fSlow79))) + (fTemp220 * ((0.5f * ((((0.2f * (fTemp241 + ((fTemp239 - float(iTemp240)) * (ftbl2[max(0, min((iTemp240 + 1), 499))] - fTemp241)))) + (0.8f * (fTemp237 + ((fTemp235 - float(iTemp236)) * (ftbl3[max(0, min((iTemp236 + 1), 499))] - fTemp237))))) * fSlow63) * fSlow61)) + (((fRec79[0] * (1.0f - fTemp221)) + (6.451612e-08f * (fTemp30 * fTemp221))) * fSlow64)))) + (fTemp173 * ((0.5f * ((((0.2f * (fTemp194 + ((fTemp192 - float(iTemp193)) * (ftbl2[max(0, min((iTemp193 + 1), 499))] - fTemp194)))) + (0.8f * (fTemp190 + ((fTemp188 - float(iTemp189)) * (ftbl3[max(0, min((iTemp189 + 1), 499))] - fTemp190))))) * fSlow48) * fSlow46)) + (((fRec64[0] * (1.0f - fTemp174)) + (6.451612e-08f * (fTemp30 * fTemp174))) * fSlow49)))) + (fTemp126 * ((0.5f * ((((0.2f * (fTemp147 + ((fTemp145 - float(iTemp146)) * (ftbl2[max(0, min((iTemp146 + 1), 499))] - fTemp147)))) + (0.8f * (fTemp143 + ((fTemp141 - float(iTemp142)) * (ftbl3[max(0, min((iTemp142 + 1), 499))] - fTemp143))))) * fSlow33) * fSlow31)) + (((fRec49[0] * (1.0f - fTemp127)) + (6.451612e-08f * (fTemp30 * fTemp127))) * fSlow34)))) + (fTemp79 * ((0.5f * ((((0.2f * (fTemp100 + ((fTemp98 - float(iTemp99)) * (ftbl2[max(0, min((iTemp99 + 1), 499))] - fTemp100)))) + (0.8f * (fTemp96 + ((fTemp94 - float(iTemp95)) * (ftbl3[max(0, min((iTemp95 + 1), 499))] - fTemp96))))) * fSlow18) * fSlow16)) + (((fRec34[0] * (1.0f - fTemp80)) + (6.451612e-08f * (fTemp30 * fTemp80))) * fSlow19)))) + (fTemp28 * ((0.5f * ((((0.2f * (fTemp53 + ((fTemp51 - float(iTemp52)) * (ftbl2[max(0, min((iTemp52 + 1), 499))] - fTemp53)))) + (0.8f * (fTemp49 + ((fTemp47 - float(iTemp48)) * (ftbl3[max(0, min((iTemp48 + 1), 499))] - fTemp49))))) * fSlow3) * fSlow1)) + (((fRec17[0] * (1.0f - fTemp29)) + (6.451612e-08f * (fTemp30 * fTemp29))) * fSlow4))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst27 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec94[1] = fRec94[0];
			fRec95[1] = fRec95[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec85[1] = fRec85[0];
			fRec89[1] = fRec89[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			iRec91[1] = iRec91[0];
			iRec90[1] = iRec90[0];
			iVec24[1] = iVec24[0];
			iRec84[2] = iRec84[1]; iRec84[1] = iRec84[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fVec23[1] = fVec23[0];
			iRec86[1] = iRec86[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec80[1] = fRec80[0];
			fRec68[2] = fRec68[1]; fRec68[1] = fRec68[0];
			fRec70[1] = fRec70[0];
			fRec74[1] = fRec74[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			iRec76[1] = iRec76[0];
			iRec75[1] = iRec75[0];
			iVec20[1] = iVec20[0];
			iRec69[2] = iRec69[1]; iRec69[1] = iRec69[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fVec19[1] = fVec19[0];
			iRec71[1] = iRec71[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec55[1] = fRec55[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			iRec61[1] = iRec61[0];
			iRec60[1] = iRec60[0];
			iVec16[1] = iVec16[0];
			iRec54[2] = iRec54[1]; iRec54[1] = iRec54[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fVec15[1] = fVec15[0];
			iRec56[1] = iRec56[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec38[2] = fRec38[1]; fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			iRec46[1] = iRec46[0];
			iRec45[1] = iRec45[0];
			iVec12[1] = iVec12[0];
			iRec39[2] = iRec39[1]; iRec39[1] = iRec39[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fVec11[1] = fVec11[0];
			iRec41[1] = iRec41[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec29[1] = fRec29[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			iRec31[1] = iRec31[0];
			iRec30[1] = iRec30[0];
			iVec8[1] = iVec8[0];
			iRec24[2] = iRec24[1]; iRec24[1] = iRec24[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			fVec7[1] = fVec7[0];
			iRec26[1] = iRec26[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec17[1] = fRec17[0];
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
