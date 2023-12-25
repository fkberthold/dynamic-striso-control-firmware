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
				float 	fTemp0 = ((0.002002002f * float((iRec0[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp0)) + -1.0f))) * float(((fTemp0 > 0.0f) - (fTemp0 < 0.0f))));
				// post processing
				iRec0[1] = iRec0[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec11[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec11[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec11[0] = (iRec11[1] + 1);
				int 	iTemp13 = int((1.05f * float((iRec11[0] + -1))));
				output[i] = (((iTemp13 >= 11)) ? (((iTemp13 >= 16)) ? (((iTemp13 >= 19)) ? (((iTemp13 >= 20)) ? 0.0f : 0.01f) : (((iTemp13 >= 18)) ? 0.03f : (((iTemp13 >= 17)) ? 0.06f : 0.08f))) : (((iTemp13 >= 14)) ? (((iTemp13 >= 15)) ? 0.1f : 0.12f) : (((iTemp13 >= 13)) ? 0.14f : (((iTemp13 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp13 >= 6)) ? (((iTemp13 >= 9)) ? (((iTemp13 >= 10)) ? 0.22f : 0.26f) : (((iTemp13 >= 8)) ? 0.3f : (((iTemp13 >= 7)) ? 0.35f : 0.4f))) : (((iTemp13 >= 3)) ? (((iTemp13 >= 5)) ? 0.47f : (((iTemp13 >= 4)) ? 0.55f : 0.64f)) : (((iTemp13 >= 2)) ? 0.74f : (((iTemp13 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec11[1] = iRec11[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec17[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec17[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec17[0] = (iRec17[1] + 1);
				output[i] = ((0.004008016f * float((iRec17[0] + -1))) + -1.0f);
				// post processing
				iRec17[1] = iRec17[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec21[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec21[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec21[0] = (iRec21[1] + 1);
				float 	fTemp41 = float((iRec21[0] + -1));
				float 	fTemp42 = (0.002004008f * fTemp41);
				output[i] = (((fTemp42 < 0.5f)) ? ((0.008016032f * fTemp41) + -1.0f) : ((4.0f * (1.0f - fTemp42)) + -1.0f));
				// post processing
				iRec21[1] = iRec21[0];
			}
		}
	};


	static float 	ftbl0[1000];
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	int 	iVec0[2];
	int 	iRec2[2];
	float 	fRec1[3];
	float 	fConst0;
	float 	fConst5;
	float 	fConst7;
	float 	fConst9;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec7[2];
	int 	iRec6[2];
	float 	fConst10;
	float 	fVec3[2];
	float 	fRec8[2];
	float 	fRec9[2];
	int 	iRec4[3];
	static float 	ftbl1[21];
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	int 	iVec4[2];
	int 	iRec12[2];
	int 	iRec13[2];
	float 	fRec14[2];
	float 	fRec15[2];
	float 	fRec10[2];
	float 	fRec5[2];
	float 	fRec3[3];
	float 	fConst15;
	static float 	ftbl2[500];
	float 	fConst16;
	float 	fRec18[2];
	float 	fRec19[2];
	float 	fRec20[2];
	static float 	ftbl3[500];
	float 	fConst17;
	float 	fRec16[2];
	float 	fConst18;
	float 	fRec22[2];
	float 	fConst19;
	float 	fRec23[2];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	float 	fRec24[3];
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
	float 	fRec42[3];
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec46[2];
	float 	fVec11[2];
	float 	fRec47[2];
	float 	fRec48[2];
	int 	iRec44[3];
	int 	iVec12[2];
	int 	iRec50[2];
	int 	iRec51[2];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec49[2];
	float 	fRec45[2];
	float 	fRec43[3];
	float 	fRec55[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec54[2];
	float 	fRec58[2];
	float 	fRec59[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	float 	fRec60[3];
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec64[2];
	float 	fVec15[2];
	float 	fRec65[2];
	float 	fRec66[2];
	int 	iRec62[3];
	int 	iVec16[2];
	int 	iRec68[2];
	int 	iRec69[2];
	float 	fRec70[2];
	float 	fRec71[2];
	float 	fRec67[2];
	float 	fRec63[2];
	float 	fRec61[3];
	float 	fRec73[2];
	float 	fRec74[2];
	float 	fRec75[2];
	float 	fRec72[2];
	float 	fRec76[2];
	float 	fRec77[2];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	float 	fRec78[3];
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec82[2];
	float 	fVec19[2];
	float 	fRec83[2];
	float 	fRec84[2];
	int 	iRec80[3];
	int 	iVec20[2];
	int 	iRec86[2];
	int 	iRec87[2];
	float 	fRec88[2];
	float 	fRec89[2];
	float 	fRec85[2];
	float 	fRec81[2];
	float 	fRec79[3];
	float 	fRec91[2];
	float 	fRec92[2];
	float 	fRec93[2];
	float 	fRec90[2];
	float 	fRec94[2];
	float 	fRec95[2];
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	float 	fRec96[3];
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec100[2];
	float 	fVec23[2];
	float 	fRec101[2];
	float 	fRec102[2];
	int 	iRec98[3];
	int 	iVec24[2];
	int 	iRec104[2];
	int 	iRec105[2];
	float 	fRec106[2];
	float 	fRec107[2];
	float 	fRec103[2];
	float 	fRec99[2];
	float 	fRec97[3];
	float 	fRec109[2];
	float 	fRec110[2];
	float 	fRec111[2];
	float 	fRec108[2];
	float 	fRec112[2];
	float 	fRec113[2];
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
		float 	fConst2 = powf((62.831852f / fConst0),2.0f);
		float 	fConst3 = ((fConst2 * ((0.2033f * fConst2) + 0.31755f)) + 1.0f);
		float 	fConst4 = powf(fConst3,2.0f);
		fConst5 = (2.0f * ((3947.8418f * (fConst4 / fConst1)) + -1.0f));
		float 	fConst6 = (3947.8418f * (fConst3 / fConst0));
		fConst7 = (((fConst3 * (fConst6 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst8 = (((fConst3 * (fConst6 + 88.49557f)) / fConst0) + 1.0f);
		fConst9 = (1.0f / fConst8);
		fConst10 = (1.0f / fConst0);
		fConst11 = (0.1f * fConst0);
		fConst12 = (0.4f * fConst0);
		fConst13 = (0.15f * fConst0);
		fConst14 = (0.2f * fConst0);
		fConst15 = (fConst4 / (fConst1 * fConst8));
		fConst16 = (8.175799f / fConst0);
		fConst17 = (3333.3333f / fConst0);
		fConst18 = (4.0878997f / fConst0);
		fConst19 = (2.0439498f / fConst0);
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
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<3; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<3; i++) fRec24[i] = 0;
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
		for (int i=0; i<3; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<3; i++) iRec44[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec50[i] = 0;
		for (int i=0; i<2; i++) iRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<3; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<3; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec64[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<3; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec68[i] = 0;
		for (int i=0; i<2; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<3; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<3; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec82[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) iRec80[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) iRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<3; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec100[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<3; i++) iRec98[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec104[i] = 0;
		for (int i=0; i<2; i++) iRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
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
		float 	fSlow6 = (2.0f * ((2.7822554e-07f * powf(fSlow3,2.0f)) + -1.0f));
		float 	fSlow7 = (2.7822554e-07f * fSlow3);
		float 	fSlow8 = ((fSlow3 * (fSlow7 + -5.274709e-07f)) + 1.0f);
		float 	fSlow9 = ((fSlow3 * (fSlow7 + 5.274709e-07f)) + 1.0f);
		float 	fSlow10 = (1.0f / fSlow9);
		float 	fSlow11 = float(fslider2);
		float 	fSlow12 = float(fslider3);
		int 	iSlow13 = (fSlow12 == 0.0f);
		float 	fSlow14 = (0.9f * fSlow12);
		float 	fSlow15 = (0.0f - fSlow14);
		float 	fSlow16 = max(0.05f, (0.1f - fabsf(fSlow14)));
		float 	fSlow17 = (5.274709e-07f * (fSlow3 / fSlow9));
		float 	fSlow18 = (fConst16 * fSlow3);
		float 	fSlow19 = (0.0f - fSlow0);
		float 	fSlow20 = (fConst18 * fSlow3);
		float 	fSlow21 = (fConst19 * fSlow3);
		float 	fSlow22 = float(fslider4);
		float 	fSlow23 = ftbl0[int(((499.5f * (fSlow22 + 1.0f)) + 0.5f))];
		float 	fSlow24 = (fSlow23 + 1.0f);
		float 	fSlow25 = fastpow2((0.083333336f * float(fslider5)));
		float 	fSlow26 = ((((8.175799f * fSlow25) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow27 = (1.0f - (0.5f * (fSlow26 * fSlow24)));
		float 	fSlow28 = (2.0f * ((2.7822554e-07f * powf(fSlow25,2.0f)) + -1.0f));
		float 	fSlow29 = (2.7822554e-07f * fSlow25);
		float 	fSlow30 = ((fSlow25 * (fSlow29 + -5.274709e-07f)) + 1.0f);
		float 	fSlow31 = ((fSlow25 * (fSlow29 + 5.274709e-07f)) + 1.0f);
		float 	fSlow32 = (1.0f / fSlow31);
		float 	fSlow33 = float(fslider6);
		float 	fSlow34 = float(fslider7);
		int 	iSlow35 = (fSlow34 == 0.0f);
		float 	fSlow36 = (0.9f * fSlow34);
		float 	fSlow37 = (0.0f - fSlow36);
		float 	fSlow38 = max(0.05f, (0.1f - fabsf(fSlow36)));
		float 	fSlow39 = (5.274709e-07f * (fSlow25 / fSlow31));
		float 	fSlow40 = (fConst16 * fSlow25);
		float 	fSlow41 = (0.0f - fSlow22);
		float 	fSlow42 = (fConst18 * fSlow25);
		float 	fSlow43 = (fConst19 * fSlow25);
		float 	fSlow44 = float(fslider8);
		float 	fSlow45 = ftbl0[int(((499.5f * (fSlow44 + 1.0f)) + 0.5f))];
		float 	fSlow46 = (fSlow45 + 1.0f);
		float 	fSlow47 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow48 = ((((8.175799f * fSlow47) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow49 = (1.0f - (0.5f * (fSlow48 * fSlow46)));
		float 	fSlow50 = (2.0f * ((2.7822554e-07f * powf(fSlow47,2.0f)) + -1.0f));
		float 	fSlow51 = (2.7822554e-07f * fSlow47);
		float 	fSlow52 = ((fSlow47 * (fSlow51 + -5.274709e-07f)) + 1.0f);
		float 	fSlow53 = ((fSlow47 * (fSlow51 + 5.274709e-07f)) + 1.0f);
		float 	fSlow54 = (1.0f / fSlow53);
		float 	fSlow55 = float(fslider10);
		float 	fSlow56 = float(fslider11);
		int 	iSlow57 = (fSlow56 == 0.0f);
		float 	fSlow58 = (0.9f * fSlow56);
		float 	fSlow59 = (0.0f - fSlow58);
		float 	fSlow60 = max(0.05f, (0.1f - fabsf(fSlow58)));
		float 	fSlow61 = (5.274709e-07f * (fSlow47 / fSlow53));
		float 	fSlow62 = (fConst16 * fSlow47);
		float 	fSlow63 = (0.0f - fSlow44);
		float 	fSlow64 = (fConst18 * fSlow47);
		float 	fSlow65 = (fConst19 * fSlow47);
		float 	fSlow66 = float(fslider12);
		float 	fSlow67 = ftbl0[int(((499.5f * (fSlow66 + 1.0f)) + 0.5f))];
		float 	fSlow68 = (fSlow67 + 1.0f);
		float 	fSlow69 = fastpow2((0.083333336f * float(fslider13)));
		float 	fSlow70 = ((((8.175799f * fSlow69) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow71 = (1.0f - (0.5f * (fSlow70 * fSlow68)));
		float 	fSlow72 = (2.0f * ((2.7822554e-07f * powf(fSlow69,2.0f)) + -1.0f));
		float 	fSlow73 = (2.7822554e-07f * fSlow69);
		float 	fSlow74 = ((fSlow69 * (fSlow73 + -5.274709e-07f)) + 1.0f);
		float 	fSlow75 = ((fSlow69 * (fSlow73 + 5.274709e-07f)) + 1.0f);
		float 	fSlow76 = (1.0f / fSlow75);
		float 	fSlow77 = float(fslider14);
		float 	fSlow78 = float(fslider15);
		int 	iSlow79 = (fSlow78 == 0.0f);
		float 	fSlow80 = (0.9f * fSlow78);
		float 	fSlow81 = (0.0f - fSlow80);
		float 	fSlow82 = max(0.05f, (0.1f - fabsf(fSlow80)));
		float 	fSlow83 = (5.274709e-07f * (fSlow69 / fSlow75));
		float 	fSlow84 = (fConst16 * fSlow69);
		float 	fSlow85 = (0.0f - fSlow66);
		float 	fSlow86 = (fConst18 * fSlow69);
		float 	fSlow87 = (fConst19 * fSlow69);
		float 	fSlow88 = float(fslider16);
		float 	fSlow89 = ftbl0[int(((499.5f * (fSlow88 + 1.0f)) + 0.5f))];
		float 	fSlow90 = (fSlow89 + 1.0f);
		float 	fSlow91 = fastpow2((0.083333336f * float(fslider17)));
		float 	fSlow92 = ((((8.175799f * fSlow91) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow93 = (1.0f - (0.5f * (fSlow92 * fSlow90)));
		float 	fSlow94 = (2.0f * ((2.7822554e-07f * powf(fSlow91,2.0f)) + -1.0f));
		float 	fSlow95 = (2.7822554e-07f * fSlow91);
		float 	fSlow96 = ((fSlow91 * (fSlow95 + -5.274709e-07f)) + 1.0f);
		float 	fSlow97 = ((fSlow91 * (fSlow95 + 5.274709e-07f)) + 1.0f);
		float 	fSlow98 = (1.0f / fSlow97);
		float 	fSlow99 = float(fslider18);
		float 	fSlow100 = float(fslider19);
		int 	iSlow101 = (fSlow100 == 0.0f);
		float 	fSlow102 = (0.9f * fSlow100);
		float 	fSlow103 = (0.0f - fSlow102);
		float 	fSlow104 = max(0.05f, (0.1f - fabsf(fSlow102)));
		float 	fSlow105 = (5.274709e-07f * (fSlow91 / fSlow97));
		float 	fSlow106 = (fConst16 * fSlow91);
		float 	fSlow107 = (0.0f - fSlow88);
		float 	fSlow108 = (fConst18 * fSlow91);
		float 	fSlow109 = (fConst19 * fSlow91);
		float 	fSlow110 = float(fslider20);
		float 	fSlow111 = ftbl0[int(((499.5f * (fSlow110 + 1.0f)) + 0.5f))];
		float 	fSlow112 = (fSlow111 + 1.0f);
		float 	fSlow113 = fastpow2((0.083333336f * float(fslider21)));
		float 	fSlow114 = ((((8.175799f * fSlow113) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow115 = (1.0f - (0.5f * (fSlow114 * fSlow112)));
		float 	fSlow116 = (2.0f * ((2.7822554e-07f * powf(fSlow113,2.0f)) + -1.0f));
		float 	fSlow117 = (2.7822554e-07f * fSlow113);
		float 	fSlow118 = ((fSlow113 * (fSlow117 + -5.274709e-07f)) + 1.0f);
		float 	fSlow119 = ((fSlow113 * (fSlow117 + 5.274709e-07f)) + 1.0f);
		float 	fSlow120 = (1.0f / fSlow119);
		float 	fSlow121 = float(fslider22);
		float 	fSlow122 = float(fslider23);
		int 	iSlow123 = (fSlow122 == 0.0f);
		float 	fSlow124 = (0.9f * fSlow122);
		float 	fSlow125 = (0.0f - fSlow124);
		float 	fSlow126 = max(0.05f, (0.1f - fabsf(fSlow124)));
		float 	fSlow127 = (5.274709e-07f * (fSlow113 / fSlow119));
		float 	fSlow128 = (fConst16 * fSlow113);
		float 	fSlow129 = (0.0f - fSlow110);
		float 	fSlow130 = (fConst18 * fSlow113);
		float 	fSlow131 = (fConst19 * fSlow113);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			float 	fTemp1 = (4.656613e-10f * float(iRec2[0]));
			fRec1[0] = (fTemp1 - (fSlow10 * ((fSlow8 * fRec1[2]) + (fSlow6 * fRec1[1]))));
			fVec1[0] = fSlow12;
			int 	iTemp2 = (fSlow14 != (0.9f * fVec1[1]));
			iVec2[0] = iTemp2;
			int 	iTemp3 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec7[0] = (iRec7[1] + 1);
			int 	iTemp4 = (iRec7[0] + -1);
			iRec6[0] = ((iRec6[1] * (1 - iTemp3)) + (iTemp4 * iTemp3));
			float 	fTemp5 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec6[0])))) > 0.5f) & iSlow13)) ? 0.0f : fSlow11) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp5;
			int 	iTemp6 = (fVec3[0] > 0.003f);
			int 	iTemp7 = (fVec3[0] <= 0.003f);
			float 	fTemp8 = float((iTemp7 | (fVec3[1] >= 0.003f)));
			fRec8[0] = max((fRec8[1] * fTemp8), fSlow14);
			fRec9[0] = max((fTemp8 * fRec9[1]), fSlow15);
			float 	fTemp9 = (min(1.0f, fRec9[0]) + min(1.0f, fRec8[0]));
			int 	iTemp10 = (fVec3[0] >= fRec5[1]);
			int 	iTemp11 = (fRec5[1] <= 0.001f);
			int 	iTemp12 = (((iRec4[1] >= 4)) ? (((iRec4[1] >= 6)) ? ((iTemp11) ? 0 : ((iTemp6) ? 1 : 6)) : (((iRec4[1] >= 5)) ? ((iTemp7) ? 3 : ((iTemp10) ? 4 : 5)) : ((iTemp7) ? 3 : (((fVec3[0] <= fRec5[1])) ? 5 : 4)))) : (((iRec4[1] >= 2)) ? (((iRec4[1] >= 3)) ? (((iTemp7 & iTemp11)) ? 0 : ((iTemp6) ? 1 : 3)) : ((iTemp7) ? 6 : ((iTemp10) ? 4 : 2))) : (((iRec4[1] >= 1)) ? (((fRec5[1] >= min(fTemp9, 1.0f))) ? ((iTemp7) ? 6 : 2) : 1) : ((iTemp6) ? 1 : 0))));
			iRec4[0] = iTemp12;
			float 	fTemp14 = (((iTemp12 >= 4)) ? (((iTemp12 >= 6)) ? fConst0 : fConst14) : (((iTemp12 >= 2)) ? (((iTemp12 >= 3)) ? fConst13 : fConst12) : (((iTemp12 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp15 = (iRec4[1] != iRec4[2]);
			iVec4[0] = iTemp15;
			int 	iTemp16 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec12[0] = ((iRec12[1] * (1 - iTemp16)) + (iTemp4 * iTemp16));
			float 	fTemp17 = (2e+01f * (((fTemp14 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec12[0]))) / fTemp14) : 0.0f));
			int 	iTemp18 = int(fTemp17);
			float 	fTemp19 = ftbl1[max(0, int(min(int(iTemp18), 20)))];
			float 	fTemp20 = (fTemp19 + ((fTemp17 - float(iTemp18)) * (ftbl1[max(0, int(min(int((iTemp18 + 1)), 20)))] - fTemp19)));
			iRec13[0] = iRec4[1];
			int 	iTemp21 = (iRec13[1] == iRec4[1]);
			int 	iTemp22 = (iRec4[1] == 0);
			fRec14[0] = ((iTemp22) ? fVec3[0] : ((iTemp21) ? min(min(fRec14[1], fVec3[0]), fRec5[1]) : min(fVec3[0], fRec5[1])));
			fRec15[0] = ((iTemp22) ? fVec3[0] : ((iTemp21) ? max(max(fRec15[1], fVec3[0]), fRec5[1]) : max(fVec3[0], fRec5[1])));
			int 	iTemp23 = (iRec4[1] == 3);
			int 	iTemp24 = (iRec4[1] == 6);
			float 	fTemp25 = (((iRec4[1] == 1)) ? min(1.0f, fTemp9) : ((iTemp22) ? 0.0f : ((iTemp24) ? (fTemp9 * fTemp20) : ((iTemp23) ? (fRec15[0] * fTemp20) : fVec3[0]))));
			float 	fTemp26 = (1.0f / ((iTemp22) ? 0.0001f : (((iTemp23 | iTemp24)) ? (0.04761905f * fTemp14) : fTemp14)));
			float 	fTemp27 = (fRec10[1] - fTemp26);
			float 	fTemp28 = (fRec10[1] + fTemp26);
			fRec10[0] = (((fTemp28 < fTemp25)) ? fTemp28 : (((fTemp27 > fTemp25)) ? fTemp27 : fTemp25));
			fRec5[0] = fRec10[0];
			fRec3[0] = (fRec5[0] - (fConst9 * ((fConst7 * fRec3[2]) + (fConst5 * fRec3[1]))));
			float 	fTemp29 = min(0.99f, (fConst15 * (((3947.8418f * fRec3[0]) + (7895.6836f * fRec3[1])) + (3947.8418f * fRec3[2]))));
			float 	fTemp30 = min(1.0f, (fSlow16 + (((fTemp29 < 0.1f)) ? (1.0f - (1e+01f * fTemp29)) : 0.0f)));
			int 	iTemp31 = (1 - iVec0[1]);
			float 	fTemp32 = ((iTemp31) ? 0.0f : (fSlow18 + fRec18[1]));
			fRec18[0] = (fTemp32 - floorf(fTemp32));
			float 	fTemp33 = (499.0f * fRec18[0]);
			int 	iTemp34 = int(fTemp33);
			int 	iTemp35 = max(0, min(iTemp34, 499));
			float 	fTemp36 = ftbl2[iTemp35];
			int 	iTemp37 = max(0, min((iTemp34 + 1), 499));
			float 	fTemp38 = (fTemp33 - float(iTemp34));
			float 	fTemp39 = float((((fVec3[1] <= 0.003f) & iTemp6) != 1));
			fRec19[0] = max((fTemp39 * fRec19[1]), fSlow19);
			fRec20[0] = max((fRec20[1] * fTemp39), fSlow0);
			float 	fTemp40 = max(min(((0.5f * (fVec3[0] - fTemp29)) + (0.2f - (0.8f * ((iTemp7) ? (2.0f * (((fRec20[0] > fRec19[0])) ? fRec20[0] : (0.0f - fRec19[0]))) : fSlow1)))), 1.0f), 0.0f);
			float 	fTemp43 = ftbl3[iTemp35];
			float 	fTemp44 = (((fTemp43 + (fTemp38 * (ftbl3[iTemp37] - fTemp43))) * (1.0f - fTemp40)) + (fTemp40 * (fTemp36 + (fTemp38 * (ftbl2[iTemp37] - fTemp36)))));
			float 	fTemp45 = (fRec16[1] - fConst17);
			float 	fTemp46 = (fConst17 + fRec16[1]);
			fRec16[0] = (((fTemp46 < fTemp44)) ? fTemp46 : (((fTemp45 > fTemp44)) ? fTemp45 : fTemp44));
			float 	fTemp47 = ((iTemp31) ? 0.0f : (fSlow20 + fRec22[1]));
			fRec22[0] = (fTemp47 - floorf(fTemp47));
			float 	fTemp48 = (499.0f * fRec22[0]);
			int 	iTemp49 = int(fTemp48);
			float 	fTemp50 = ftbl3[max(0, min(iTemp49, 499))];
			float 	fTemp51 = ((iTemp31) ? 0.0f : (fSlow21 + fRec23[1]));
			fRec23[0] = (fTemp51 - floorf(fTemp51));
			float 	fTemp52 = (499.0f * fRec23[0]);
			int 	iTemp53 = int(fTemp52);
			float 	fTemp54 = ftbl2[max(0, min(iTemp53, 499))];
			fRec24[0] = (fTemp1 - (fSlow32 * ((fSlow30 * fRec24[2]) + (fSlow28 * fRec24[1]))));
			fVec5[0] = fSlow34;
			int 	iTemp55 = (fSlow36 != (0.9f * fVec5[1]));
			iVec6[0] = iTemp55;
			int 	iTemp56 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec28[0] = ((iRec28[1] * (1 - iTemp56)) + (iTemp4 * iTemp56));
			float 	fTemp57 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec28[0])))) > 0.5f) & iSlow35)) ? 0.0f : fSlow33) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp57;
			int 	iTemp58 = (fVec7[0] > 0.003f);
			int 	iTemp59 = (fVec7[0] <= 0.003f);
			float 	fTemp60 = float((iTemp59 | (fVec7[1] >= 0.003f)));
			fRec29[0] = max((fRec29[1] * fTemp60), fSlow36);
			fRec30[0] = max((fTemp60 * fRec30[1]), fSlow37);
			float 	fTemp61 = (min(1.0f, fRec30[0]) + min(1.0f, fRec29[0]));
			int 	iTemp62 = (fVec7[0] >= fRec27[1]);
			int 	iTemp63 = (fRec27[1] <= 0.001f);
			int 	iTemp64 = (((iRec26[1] >= 4)) ? (((iRec26[1] >= 6)) ? ((iTemp63) ? 0 : ((iTemp58) ? 1 : 6)) : (((iRec26[1] >= 5)) ? ((iTemp59) ? 3 : ((iTemp62) ? 4 : 5)) : ((iTemp59) ? 3 : (((fVec7[0] <= fRec27[1])) ? 5 : 4)))) : (((iRec26[1] >= 2)) ? (((iRec26[1] >= 3)) ? (((iTemp59 & iTemp63)) ? 0 : ((iTemp58) ? 1 : 3)) : ((iTemp59) ? 6 : ((iTemp62) ? 4 : 2))) : (((iRec26[1] >= 1)) ? (((fRec27[1] >= min(fTemp61, 1.0f))) ? ((iTemp59) ? 6 : 2) : 1) : ((iTemp58) ? 1 : 0))));
			iRec26[0] = iTemp64;
			float 	fTemp65 = (((iTemp64 >= 4)) ? (((iTemp64 >= 6)) ? fConst0 : fConst14) : (((iTemp64 >= 2)) ? (((iTemp64 >= 3)) ? fConst13 : fConst12) : (((iTemp64 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp66 = (iRec26[1] != iRec26[2]);
			iVec8[0] = iTemp66;
			int 	iTemp67 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp67)) + (iTemp4 * iTemp67));
			float 	fTemp68 = (2e+01f * (((fTemp65 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec32[0]))) / fTemp65) : 0.0f));
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
			fRec25[0] = (fRec27[0] - (fConst9 * ((fConst7 * fRec25[2]) + (fConst5 * fRec25[1]))));
			float 	fTemp80 = min(0.99f, (fConst15 * (((3947.8418f * fRec25[0]) + (7895.6836f * fRec25[1])) + (3947.8418f * fRec25[2]))));
			float 	fTemp81 = min(1.0f, (fSlow38 + (((fTemp80 < 0.1f)) ? (1.0f - (1e+01f * fTemp80)) : 0.0f)));
			float 	fTemp82 = ((iTemp31) ? 0.0f : (fSlow40 + fRec37[1]));
			fRec37[0] = (fTemp82 - floorf(fTemp82));
			float 	fTemp83 = (499.0f * fRec37[0]);
			int 	iTemp84 = int(fTemp83);
			int 	iTemp85 = max(0, min(iTemp84, 499));
			float 	fTemp86 = ftbl2[iTemp85];
			int 	iTemp87 = max(0, min((iTemp84 + 1), 499));
			float 	fTemp88 = (fTemp83 - float(iTemp84));
			float 	fTemp89 = float((((fVec7[1] <= 0.003f) & iTemp58) != 1));
			fRec38[0] = max((fTemp89 * fRec38[1]), fSlow41);
			fRec39[0] = max((fRec39[1] * fTemp89), fSlow22);
			float 	fTemp90 = max(min(((0.5f * (fVec7[0] - fTemp80)) + (0.2f - (0.8f * ((iTemp59) ? (2.0f * (((fRec39[0] > fRec38[0])) ? fRec39[0] : (0.0f - fRec38[0]))) : fSlow23)))), 1.0f), 0.0f);
			float 	fTemp91 = ftbl3[iTemp85];
			float 	fTemp92 = (((fTemp91 + (fTemp88 * (ftbl3[iTemp87] - fTemp91))) * (1.0f - fTemp90)) + (fTemp90 * (fTemp86 + (fTemp88 * (ftbl2[iTemp87] - fTemp86)))));
			float 	fTemp93 = (fRec36[1] - fConst17);
			float 	fTemp94 = (fConst17 + fRec36[1]);
			fRec36[0] = (((fTemp94 < fTemp92)) ? fTemp94 : (((fTemp93 > fTemp92)) ? fTemp93 : fTemp92));
			float 	fTemp95 = ((iTemp31) ? 0.0f : (fSlow42 + fRec40[1]));
			fRec40[0] = (fTemp95 - floorf(fTemp95));
			float 	fTemp96 = (499.0f * fRec40[0]);
			int 	iTemp97 = int(fTemp96);
			float 	fTemp98 = ftbl3[max(0, min(iTemp97, 499))];
			float 	fTemp99 = ((iTemp31) ? 0.0f : (fSlow43 + fRec41[1]));
			fRec41[0] = (fTemp99 - floorf(fTemp99));
			float 	fTemp100 = (499.0f * fRec41[0]);
			int 	iTemp101 = int(fTemp100);
			float 	fTemp102 = ftbl2[max(0, min(iTemp101, 499))];
			fRec42[0] = (fTemp1 - (fSlow54 * ((fSlow52 * fRec42[2]) + (fSlow50 * fRec42[1]))));
			fVec9[0] = fSlow56;
			int 	iTemp103 = (fSlow58 != (0.9f * fVec9[1]));
			iVec10[0] = iTemp103;
			int 	iTemp104 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec46[0] = ((iRec46[1] * (1 - iTemp104)) + (iTemp4 * iTemp104));
			float 	fTemp105 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec46[0])))) > 0.5f) & iSlow57)) ? 0.0f : fSlow55) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp105;
			int 	iTemp106 = (fVec11[0] > 0.003f);
			int 	iTemp107 = (fVec11[0] <= 0.003f);
			float 	fTemp108 = float((iTemp107 | (fVec11[1] >= 0.003f)));
			fRec47[0] = max((fRec47[1] * fTemp108), fSlow58);
			fRec48[0] = max((fTemp108 * fRec48[1]), fSlow59);
			float 	fTemp109 = (min(1.0f, fRec48[0]) + min(1.0f, fRec47[0]));
			int 	iTemp110 = (fVec11[0] >= fRec45[1]);
			int 	iTemp111 = (fRec45[1] <= 0.001f);
			int 	iTemp112 = (((iRec44[1] >= 4)) ? (((iRec44[1] >= 6)) ? ((iTemp111) ? 0 : ((iTemp106) ? 1 : 6)) : (((iRec44[1] >= 5)) ? ((iTemp107) ? 3 : ((iTemp110) ? 4 : 5)) : ((iTemp107) ? 3 : (((fVec11[0] <= fRec45[1])) ? 5 : 4)))) : (((iRec44[1] >= 2)) ? (((iRec44[1] >= 3)) ? (((iTemp107 & iTemp111)) ? 0 : ((iTemp106) ? 1 : 3)) : ((iTemp107) ? 6 : ((iTemp110) ? 4 : 2))) : (((iRec44[1] >= 1)) ? (((fRec45[1] >= min(fTemp109, 1.0f))) ? ((iTemp107) ? 6 : 2) : 1) : ((iTemp106) ? 1 : 0))));
			iRec44[0] = iTemp112;
			float 	fTemp113 = (((iTemp112 >= 4)) ? (((iTemp112 >= 6)) ? fConst0 : fConst14) : (((iTemp112 >= 2)) ? (((iTemp112 >= 3)) ? fConst13 : fConst12) : (((iTemp112 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp114 = (iRec44[1] != iRec44[2]);
			iVec12[0] = iTemp114;
			int 	iTemp115 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec50[0] = ((iRec50[1] * (1 - iTemp115)) + (iTemp4 * iTemp115));
			float 	fTemp116 = (2e+01f * (((fTemp113 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec50[0]))) / fTemp113) : 0.0f));
			int 	iTemp117 = int(fTemp116);
			float 	fTemp118 = ftbl1[max(0, int(min(int(iTemp117), 20)))];
			float 	fTemp119 = (fTemp118 + ((fTemp116 - float(iTemp117)) * (ftbl1[max(0, int(min(int((iTemp117 + 1)), 20)))] - fTemp118)));
			iRec51[0] = iRec44[1];
			int 	iTemp120 = (iRec51[1] == iRec44[1]);
			int 	iTemp121 = (iRec44[1] == 0);
			fRec52[0] = ((iTemp121) ? fVec11[0] : ((iTemp120) ? min(min(fRec52[1], fVec11[0]), fRec45[1]) : min(fVec11[0], fRec45[1])));
			fRec53[0] = ((iTemp121) ? fVec11[0] : ((iTemp120) ? max(max(fRec53[1], fVec11[0]), fRec45[1]) : max(fVec11[0], fRec45[1])));
			int 	iTemp122 = (iRec44[1] == 3);
			int 	iTemp123 = (iRec44[1] == 6);
			float 	fTemp124 = (((iRec44[1] == 1)) ? min(1.0f, fTemp109) : ((iTemp121) ? 0.0f : ((iTemp123) ? (fTemp109 * fTemp119) : ((iTemp122) ? (fRec53[0] * fTemp119) : fVec11[0]))));
			float 	fTemp125 = (1.0f / ((iTemp121) ? 0.0001f : (((iTemp122 | iTemp123)) ? (0.04761905f * fTemp113) : fTemp113)));
			float 	fTemp126 = (fRec49[1] - fTemp125);
			float 	fTemp127 = (fRec49[1] + fTemp125);
			fRec49[0] = (((fTemp127 < fTemp124)) ? fTemp127 : (((fTemp126 > fTemp124)) ? fTemp126 : fTemp124));
			fRec45[0] = fRec49[0];
			fRec43[0] = (fRec45[0] - (fConst9 * ((fConst7 * fRec43[2]) + (fConst5 * fRec43[1]))));
			float 	fTemp128 = min(0.99f, (fConst15 * (((3947.8418f * fRec43[0]) + (7895.6836f * fRec43[1])) + (3947.8418f * fRec43[2]))));
			float 	fTemp129 = min(1.0f, (fSlow60 + (((fTemp128 < 0.1f)) ? (1.0f - (1e+01f * fTemp128)) : 0.0f)));
			float 	fTemp130 = ((iTemp31) ? 0.0f : (fSlow62 + fRec55[1]));
			fRec55[0] = (fTemp130 - floorf(fTemp130));
			float 	fTemp131 = (499.0f * fRec55[0]);
			int 	iTemp132 = int(fTemp131);
			int 	iTemp133 = max(0, min(iTemp132, 499));
			float 	fTemp134 = ftbl2[iTemp133];
			int 	iTemp135 = max(0, min((iTemp132 + 1), 499));
			float 	fTemp136 = (fTemp131 - float(iTemp132));
			float 	fTemp137 = float((((fVec11[1] <= 0.003f) & iTemp106) != 1));
			fRec56[0] = max((fTemp137 * fRec56[1]), fSlow63);
			fRec57[0] = max((fRec57[1] * fTemp137), fSlow44);
			float 	fTemp138 = max(min(((0.5f * (fVec11[0] - fTemp128)) + (0.2f - (0.8f * ((iTemp107) ? (2.0f * (((fRec57[0] > fRec56[0])) ? fRec57[0] : (0.0f - fRec56[0]))) : fSlow45)))), 1.0f), 0.0f);
			float 	fTemp139 = ftbl3[iTemp133];
			float 	fTemp140 = (((fTemp139 + (fTemp136 * (ftbl3[iTemp135] - fTemp139))) * (1.0f - fTemp138)) + (fTemp138 * (fTemp134 + (fTemp136 * (ftbl2[iTemp135] - fTemp134)))));
			float 	fTemp141 = (fRec54[1] - fConst17);
			float 	fTemp142 = (fConst17 + fRec54[1]);
			fRec54[0] = (((fTemp142 < fTemp140)) ? fTemp142 : (((fTemp141 > fTemp140)) ? fTemp141 : fTemp140));
			float 	fTemp143 = ((iTemp31) ? 0.0f : (fSlow64 + fRec58[1]));
			fRec58[0] = (fTemp143 - floorf(fTemp143));
			float 	fTemp144 = (499.0f * fRec58[0]);
			int 	iTemp145 = int(fTemp144);
			float 	fTemp146 = ftbl3[max(0, min(iTemp145, 499))];
			float 	fTemp147 = ((iTemp31) ? 0.0f : (fSlow65 + fRec59[1]));
			fRec59[0] = (fTemp147 - floorf(fTemp147));
			float 	fTemp148 = (499.0f * fRec59[0]);
			int 	iTemp149 = int(fTemp148);
			float 	fTemp150 = ftbl2[max(0, min(iTemp149, 499))];
			fRec60[0] = (fTemp1 - (fSlow76 * ((fSlow74 * fRec60[2]) + (fSlow72 * fRec60[1]))));
			fVec13[0] = fSlow78;
			int 	iTemp151 = (fSlow80 != (0.9f * fVec13[1]));
			iVec14[0] = iTemp151;
			int 	iTemp152 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec64[0] = ((iRec64[1] * (1 - iTemp152)) + (iTemp4 * iTemp152));
			float 	fTemp153 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec64[0])))) > 0.5f) & iSlow79)) ? 0.0f : fSlow77) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp153;
			int 	iTemp154 = (fVec15[0] > 0.003f);
			int 	iTemp155 = (fVec15[0] <= 0.003f);
			float 	fTemp156 = float((iTemp155 | (fVec15[1] >= 0.003f)));
			fRec65[0] = max((fRec65[1] * fTemp156), fSlow80);
			fRec66[0] = max((fTemp156 * fRec66[1]), fSlow81);
			float 	fTemp157 = (min(1.0f, fRec66[0]) + min(1.0f, fRec65[0]));
			int 	iTemp158 = (fVec15[0] >= fRec63[1]);
			int 	iTemp159 = (fRec63[1] <= 0.001f);
			int 	iTemp160 = (((iRec62[1] >= 4)) ? (((iRec62[1] >= 6)) ? ((iTemp159) ? 0 : ((iTemp154) ? 1 : 6)) : (((iRec62[1] >= 5)) ? ((iTemp155) ? 3 : ((iTemp158) ? 4 : 5)) : ((iTemp155) ? 3 : (((fVec15[0] <= fRec63[1])) ? 5 : 4)))) : (((iRec62[1] >= 2)) ? (((iRec62[1] >= 3)) ? (((iTemp155 & iTemp159)) ? 0 : ((iTemp154) ? 1 : 3)) : ((iTemp155) ? 6 : ((iTemp158) ? 4 : 2))) : (((iRec62[1] >= 1)) ? (((fRec63[1] >= min(fTemp157, 1.0f))) ? ((iTemp155) ? 6 : 2) : 1) : ((iTemp154) ? 1 : 0))));
			iRec62[0] = iTemp160;
			float 	fTemp161 = (((iTemp160 >= 4)) ? (((iTemp160 >= 6)) ? fConst0 : fConst14) : (((iTemp160 >= 2)) ? (((iTemp160 >= 3)) ? fConst13 : fConst12) : (((iTemp160 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp162 = (iRec62[1] != iRec62[2]);
			iVec16[0] = iTemp162;
			int 	iTemp163 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec68[0] = ((iRec68[1] * (1 - iTemp163)) + (iTemp4 * iTemp163));
			float 	fTemp164 = (2e+01f * (((fTemp161 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec68[0]))) / fTemp161) : 0.0f));
			int 	iTemp165 = int(fTemp164);
			float 	fTemp166 = ftbl1[max(0, int(min(int(iTemp165), 20)))];
			float 	fTemp167 = (fTemp166 + ((fTemp164 - float(iTemp165)) * (ftbl1[max(0, int(min(int((iTemp165 + 1)), 20)))] - fTemp166)));
			iRec69[0] = iRec62[1];
			int 	iTemp168 = (iRec69[1] == iRec62[1]);
			int 	iTemp169 = (iRec62[1] == 0);
			fRec70[0] = ((iTemp169) ? fVec15[0] : ((iTemp168) ? min(min(fRec70[1], fVec15[0]), fRec63[1]) : min(fVec15[0], fRec63[1])));
			fRec71[0] = ((iTemp169) ? fVec15[0] : ((iTemp168) ? max(max(fRec71[1], fVec15[0]), fRec63[1]) : max(fVec15[0], fRec63[1])));
			int 	iTemp170 = (iRec62[1] == 3);
			int 	iTemp171 = (iRec62[1] == 6);
			float 	fTemp172 = (((iRec62[1] == 1)) ? min(1.0f, fTemp157) : ((iTemp169) ? 0.0f : ((iTemp171) ? (fTemp157 * fTemp167) : ((iTemp170) ? (fRec71[0] * fTemp167) : fVec15[0]))));
			float 	fTemp173 = (1.0f / ((iTemp169) ? 0.0001f : (((iTemp170 | iTemp171)) ? (0.04761905f * fTemp161) : fTemp161)));
			float 	fTemp174 = (fRec67[1] - fTemp173);
			float 	fTemp175 = (fRec67[1] + fTemp173);
			fRec67[0] = (((fTemp175 < fTemp172)) ? fTemp175 : (((fTemp174 > fTemp172)) ? fTemp174 : fTemp172));
			fRec63[0] = fRec67[0];
			fRec61[0] = (fRec63[0] - (fConst9 * ((fConst7 * fRec61[2]) + (fConst5 * fRec61[1]))));
			float 	fTemp176 = min(0.99f, (fConst15 * (((3947.8418f * fRec61[0]) + (7895.6836f * fRec61[1])) + (3947.8418f * fRec61[2]))));
			float 	fTemp177 = min(1.0f, (fSlow82 + (((fTemp176 < 0.1f)) ? (1.0f - (1e+01f * fTemp176)) : 0.0f)));
			float 	fTemp178 = ((iTemp31) ? 0.0f : (fSlow84 + fRec73[1]));
			fRec73[0] = (fTemp178 - floorf(fTemp178));
			float 	fTemp179 = (499.0f * fRec73[0]);
			int 	iTemp180 = int(fTemp179);
			int 	iTemp181 = max(0, min(iTemp180, 499));
			float 	fTemp182 = ftbl2[iTemp181];
			int 	iTemp183 = max(0, min((iTemp180 + 1), 499));
			float 	fTemp184 = (fTemp179 - float(iTemp180));
			float 	fTemp185 = float((((fVec15[1] <= 0.003f) & iTemp154) != 1));
			fRec74[0] = max((fTemp185 * fRec74[1]), fSlow85);
			fRec75[0] = max((fRec75[1] * fTemp185), fSlow66);
			float 	fTemp186 = max(min(((0.5f * (fVec15[0] - fTemp176)) + (0.2f - (0.8f * ((iTemp155) ? (2.0f * (((fRec75[0] > fRec74[0])) ? fRec75[0] : (0.0f - fRec74[0]))) : fSlow67)))), 1.0f), 0.0f);
			float 	fTemp187 = ftbl3[iTemp181];
			float 	fTemp188 = (((fTemp187 + (fTemp184 * (ftbl3[iTemp183] - fTemp187))) * (1.0f - fTemp186)) + (fTemp186 * (fTemp182 + (fTemp184 * (ftbl2[iTemp183] - fTemp182)))));
			float 	fTemp189 = (fRec72[1] - fConst17);
			float 	fTemp190 = (fConst17 + fRec72[1]);
			fRec72[0] = (((fTemp190 < fTemp188)) ? fTemp190 : (((fTemp189 > fTemp188)) ? fTemp189 : fTemp188));
			float 	fTemp191 = ((iTemp31) ? 0.0f : (fSlow86 + fRec76[1]));
			fRec76[0] = (fTemp191 - floorf(fTemp191));
			float 	fTemp192 = (499.0f * fRec76[0]);
			int 	iTemp193 = int(fTemp192);
			float 	fTemp194 = ftbl3[max(0, min(iTemp193, 499))];
			float 	fTemp195 = ((iTemp31) ? 0.0f : (fSlow87 + fRec77[1]));
			fRec77[0] = (fTemp195 - floorf(fTemp195));
			float 	fTemp196 = (499.0f * fRec77[0]);
			int 	iTemp197 = int(fTemp196);
			float 	fTemp198 = ftbl2[max(0, min(iTemp197, 499))];
			fRec78[0] = (fTemp1 - (fSlow98 * ((fSlow96 * fRec78[2]) + (fSlow94 * fRec78[1]))));
			fVec17[0] = fSlow100;
			int 	iTemp199 = (fSlow102 != (0.9f * fVec17[1]));
			iVec18[0] = iTemp199;
			int 	iTemp200 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec82[0] = ((iRec82[1] * (1 - iTemp200)) + (iTemp4 * iTemp200));
			float 	fTemp201 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec82[0])))) > 0.5f) & iSlow101)) ? 0.0f : fSlow99) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp201;
			int 	iTemp202 = (fVec19[0] > 0.003f);
			int 	iTemp203 = (fVec19[0] <= 0.003f);
			float 	fTemp204 = float((iTemp203 | (fVec19[1] >= 0.003f)));
			fRec83[0] = max((fRec83[1] * fTemp204), fSlow102);
			fRec84[0] = max((fTemp204 * fRec84[1]), fSlow103);
			float 	fTemp205 = (min(1.0f, fRec84[0]) + min(1.0f, fRec83[0]));
			int 	iTemp206 = (fVec19[0] >= fRec81[1]);
			int 	iTemp207 = (fRec81[1] <= 0.001f);
			int 	iTemp208 = (((iRec80[1] >= 4)) ? (((iRec80[1] >= 6)) ? ((iTemp207) ? 0 : ((iTemp202) ? 1 : 6)) : (((iRec80[1] >= 5)) ? ((iTemp203) ? 3 : ((iTemp206) ? 4 : 5)) : ((iTemp203) ? 3 : (((fVec19[0] <= fRec81[1])) ? 5 : 4)))) : (((iRec80[1] >= 2)) ? (((iRec80[1] >= 3)) ? (((iTemp203 & iTemp207)) ? 0 : ((iTemp202) ? 1 : 3)) : ((iTemp203) ? 6 : ((iTemp206) ? 4 : 2))) : (((iRec80[1] >= 1)) ? (((fRec81[1] >= min(fTemp205, 1.0f))) ? ((iTemp203) ? 6 : 2) : 1) : ((iTemp202) ? 1 : 0))));
			iRec80[0] = iTemp208;
			float 	fTemp209 = (((iTemp208 >= 4)) ? (((iTemp208 >= 6)) ? fConst0 : fConst14) : (((iTemp208 >= 2)) ? (((iTemp208 >= 3)) ? fConst13 : fConst12) : (((iTemp208 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp210 = (iRec80[1] != iRec80[2]);
			iVec20[0] = iTemp210;
			int 	iTemp211 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp211)) + (iTemp4 * iTemp211));
			float 	fTemp212 = (2e+01f * (((fTemp209 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec86[0]))) / fTemp209) : 0.0f));
			int 	iTemp213 = int(fTemp212);
			float 	fTemp214 = ftbl1[max(0, int(min(int(iTemp213), 20)))];
			float 	fTemp215 = (fTemp214 + ((fTemp212 - float(iTemp213)) * (ftbl1[max(0, int(min(int((iTemp213 + 1)), 20)))] - fTemp214)));
			iRec87[0] = iRec80[1];
			int 	iTemp216 = (iRec87[1] == iRec80[1]);
			int 	iTemp217 = (iRec80[1] == 0);
			fRec88[0] = ((iTemp217) ? fVec19[0] : ((iTemp216) ? min(min(fRec88[1], fVec19[0]), fRec81[1]) : min(fVec19[0], fRec81[1])));
			fRec89[0] = ((iTemp217) ? fVec19[0] : ((iTemp216) ? max(max(fRec89[1], fVec19[0]), fRec81[1]) : max(fVec19[0], fRec81[1])));
			int 	iTemp218 = (iRec80[1] == 3);
			int 	iTemp219 = (iRec80[1] == 6);
			float 	fTemp220 = (((iRec80[1] == 1)) ? min(1.0f, fTemp205) : ((iTemp217) ? 0.0f : ((iTemp219) ? (fTemp205 * fTemp215) : ((iTemp218) ? (fRec89[0] * fTemp215) : fVec19[0]))));
			float 	fTemp221 = (1.0f / ((iTemp217) ? 0.0001f : (((iTemp218 | iTemp219)) ? (0.04761905f * fTemp209) : fTemp209)));
			float 	fTemp222 = (fRec85[1] - fTemp221);
			float 	fTemp223 = (fRec85[1] + fTemp221);
			fRec85[0] = (((fTemp223 < fTemp220)) ? fTemp223 : (((fTemp222 > fTemp220)) ? fTemp222 : fTemp220));
			fRec81[0] = fRec85[0];
			fRec79[0] = (fRec81[0] - (fConst9 * ((fConst7 * fRec79[2]) + (fConst5 * fRec79[1]))));
			float 	fTemp224 = min(0.99f, (fConst15 * (((3947.8418f * fRec79[0]) + (7895.6836f * fRec79[1])) + (3947.8418f * fRec79[2]))));
			float 	fTemp225 = min(1.0f, (fSlow104 + (((fTemp224 < 0.1f)) ? (1.0f - (1e+01f * fTemp224)) : 0.0f)));
			float 	fTemp226 = ((iTemp31) ? 0.0f : (fSlow106 + fRec91[1]));
			fRec91[0] = (fTemp226 - floorf(fTemp226));
			float 	fTemp227 = (499.0f * fRec91[0]);
			int 	iTemp228 = int(fTemp227);
			int 	iTemp229 = max(0, min(iTemp228, 499));
			float 	fTemp230 = ftbl2[iTemp229];
			int 	iTemp231 = max(0, min((iTemp228 + 1), 499));
			float 	fTemp232 = (fTemp227 - float(iTemp228));
			float 	fTemp233 = float((((fVec19[1] <= 0.003f) & iTemp202) != 1));
			fRec92[0] = max((fTemp233 * fRec92[1]), fSlow107);
			fRec93[0] = max((fRec93[1] * fTemp233), fSlow88);
			float 	fTemp234 = max(min(((0.5f * (fVec19[0] - fTemp224)) + (0.2f - (0.8f * ((iTemp203) ? (2.0f * (((fRec93[0] > fRec92[0])) ? fRec93[0] : (0.0f - fRec92[0]))) : fSlow89)))), 1.0f), 0.0f);
			float 	fTemp235 = ftbl3[iTemp229];
			float 	fTemp236 = (((fTemp235 + (fTemp232 * (ftbl3[iTemp231] - fTemp235))) * (1.0f - fTemp234)) + (fTemp234 * (fTemp230 + (fTemp232 * (ftbl2[iTemp231] - fTemp230)))));
			float 	fTemp237 = (fRec90[1] - fConst17);
			float 	fTemp238 = (fConst17 + fRec90[1]);
			fRec90[0] = (((fTemp238 < fTemp236)) ? fTemp238 : (((fTemp237 > fTemp236)) ? fTemp237 : fTemp236));
			float 	fTemp239 = ((iTemp31) ? 0.0f : (fSlow108 + fRec94[1]));
			fRec94[0] = (fTemp239 - floorf(fTemp239));
			float 	fTemp240 = (499.0f * fRec94[0]);
			int 	iTemp241 = int(fTemp240);
			float 	fTemp242 = ftbl3[max(0, min(iTemp241, 499))];
			float 	fTemp243 = ((iTemp31) ? 0.0f : (fSlow109 + fRec95[1]));
			fRec95[0] = (fTemp243 - floorf(fTemp243));
			float 	fTemp244 = (499.0f * fRec95[0]);
			int 	iTemp245 = int(fTemp244);
			float 	fTemp246 = ftbl2[max(0, min(iTemp245, 499))];
			fRec96[0] = (fTemp1 - (fSlow120 * ((fSlow118 * fRec96[2]) + (fSlow116 * fRec96[1]))));
			fVec21[0] = fSlow122;
			int 	iTemp247 = (fSlow124 != (0.9f * fVec21[1]));
			iVec22[0] = iTemp247;
			int 	iTemp248 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec100[0] = ((iRec100[1] * (1 - iTemp248)) + (iTemp4 * iTemp248));
			float 	fTemp249 = ftbl0[int(((499.5f * ((((((fConst10 * float((iRec7[0] + (-1 - iRec100[0])))) > 0.5f) & iSlow123)) ? 0.0f : fSlow121) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp249;
			int 	iTemp250 = (fVec23[0] > 0.003f);
			int 	iTemp251 = (fVec23[0] <= 0.003f);
			float 	fTemp252 = float((iTemp251 | (fVec23[1] >= 0.003f)));
			fRec101[0] = max((fRec101[1] * fTemp252), fSlow124);
			fRec102[0] = max((fTemp252 * fRec102[1]), fSlow125);
			float 	fTemp253 = (min(1.0f, fRec102[0]) + min(1.0f, fRec101[0]));
			int 	iTemp254 = (fVec23[0] >= fRec99[1]);
			int 	iTemp255 = (fRec99[1] <= 0.001f);
			int 	iTemp256 = (((iRec98[1] >= 4)) ? (((iRec98[1] >= 6)) ? ((iTemp255) ? 0 : ((iTemp250) ? 1 : 6)) : (((iRec98[1] >= 5)) ? ((iTemp251) ? 3 : ((iTemp254) ? 4 : 5)) : ((iTemp251) ? 3 : (((fVec23[0] <= fRec99[1])) ? 5 : 4)))) : (((iRec98[1] >= 2)) ? (((iRec98[1] >= 3)) ? (((iTemp251 & iTemp255)) ? 0 : ((iTemp250) ? 1 : 3)) : ((iTemp251) ? 6 : ((iTemp254) ? 4 : 2))) : (((iRec98[1] >= 1)) ? (((fRec99[1] >= min(fTemp253, 1.0f))) ? ((iTemp251) ? 6 : 2) : 1) : ((iTemp250) ? 1 : 0))));
			iRec98[0] = iTemp256;
			float 	fTemp257 = (((iTemp256 >= 4)) ? (((iTemp256 >= 6)) ? fConst0 : fConst14) : (((iTemp256 >= 2)) ? (((iTemp256 >= 3)) ? fConst13 : fConst12) : (((iTemp256 >= 1)) ? fConst11 : 0.0f)));
			int 	iTemp258 = (iRec98[1] != iRec98[2]);
			iVec24[0] = iTemp258;
			int 	iTemp259 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec104[0] = ((iRec104[1] * (1 - iTemp259)) + (iTemp4 * iTemp259));
			float 	fTemp260 = (2e+01f * (((fTemp257 > 0.0f)) ? (float((iRec7[0] + (-1 - iRec104[0]))) / fTemp257) : 0.0f));
			int 	iTemp261 = int(fTemp260);
			float 	fTemp262 = ftbl1[max(0, int(min(int(iTemp261), 20)))];
			float 	fTemp263 = (fTemp262 + ((fTemp260 - float(iTemp261)) * (ftbl1[max(0, int(min(int((iTemp261 + 1)), 20)))] - fTemp262)));
			iRec105[0] = iRec98[1];
			int 	iTemp264 = (iRec105[1] == iRec98[1]);
			int 	iTemp265 = (iRec98[1] == 0);
			fRec106[0] = ((iTemp265) ? fVec23[0] : ((iTemp264) ? min(min(fRec106[1], fVec23[0]), fRec99[1]) : min(fVec23[0], fRec99[1])));
			fRec107[0] = ((iTemp265) ? fVec23[0] : ((iTemp264) ? max(max(fRec107[1], fVec23[0]), fRec99[1]) : max(fVec23[0], fRec99[1])));
			int 	iTemp266 = (iRec98[1] == 3);
			int 	iTemp267 = (iRec98[1] == 6);
			float 	fTemp268 = (((iRec98[1] == 1)) ? min(1.0f, fTemp253) : ((iTemp265) ? 0.0f : ((iTemp267) ? (fTemp253 * fTemp263) : ((iTemp266) ? (fRec107[0] * fTemp263) : fVec23[0]))));
			float 	fTemp269 = (1.0f / ((iTemp265) ? 0.0001f : (((iTemp266 | iTemp267)) ? (0.04761905f * fTemp257) : fTemp257)));
			float 	fTemp270 = (fRec103[1] - fTemp269);
			float 	fTemp271 = (fRec103[1] + fTemp269);
			fRec103[0] = (((fTemp271 < fTemp268)) ? fTemp271 : (((fTemp270 > fTemp268)) ? fTemp270 : fTemp268));
			fRec99[0] = fRec103[0];
			fRec97[0] = (fRec99[0] - (fConst9 * ((fConst7 * fRec97[2]) + (fConst5 * fRec97[1]))));
			float 	fTemp272 = min(0.99f, (fConst15 * (((3947.8418f * fRec97[0]) + (7895.6836f * fRec97[1])) + (3947.8418f * fRec97[2]))));
			float 	fTemp273 = min(1.0f, (fSlow126 + (((fTemp272 < 0.1f)) ? (1.0f - (1e+01f * fTemp272)) : 0.0f)));
			float 	fTemp274 = ((iTemp31) ? 0.0f : (fSlow128 + fRec109[1]));
			fRec109[0] = (fTemp274 - floorf(fTemp274));
			float 	fTemp275 = (499.0f * fRec109[0]);
			int 	iTemp276 = int(fTemp275);
			int 	iTemp277 = max(0, min(iTemp276, 499));
			float 	fTemp278 = ftbl2[iTemp277];
			int 	iTemp279 = max(0, min((iTemp276 + 1), 499));
			float 	fTemp280 = (fTemp275 - float(iTemp276));
			float 	fTemp281 = float((((fVec23[1] <= 0.003f) & iTemp250) != 1));
			fRec110[0] = max((fTemp281 * fRec110[1]), fSlow129);
			fRec111[0] = max((fRec111[1] * fTemp281), fSlow110);
			float 	fTemp282 = max(min(((0.5f * (fVec23[0] - fTemp272)) + (0.2f - (0.8f * ((iTemp251) ? (2.0f * (((fRec111[0] > fRec110[0])) ? fRec111[0] : (0.0f - fRec110[0]))) : fSlow111)))), 1.0f), 0.0f);
			float 	fTemp283 = ftbl3[iTemp277];
			float 	fTemp284 = (((fTemp283 + (fTemp280 * (ftbl3[iTemp279] - fTemp283))) * (1.0f - fTemp282)) + (fTemp282 * (fTemp278 + (fTemp280 * (ftbl2[iTemp279] - fTemp278)))));
			float 	fTemp285 = (fRec108[1] - fConst17);
			float 	fTemp286 = (fConst17 + fRec108[1]);
			fRec108[0] = (((fTemp286 < fTemp284)) ? fTemp286 : (((fTemp285 > fTemp284)) ? fTemp285 : fTemp284));
			float 	fTemp287 = ((iTemp31) ? 0.0f : (fSlow130 + fRec112[1]));
			fRec112[0] = (fTemp287 - floorf(fTemp287));
			float 	fTemp288 = (499.0f * fRec112[0]);
			int 	iTemp289 = int(fTemp288);
			float 	fTemp290 = ftbl3[max(0, min(iTemp289, 499))];
			float 	fTemp291 = ((iTemp31) ? 0.0f : (fSlow131 + fRec113[1]));
			fRec113[0] = (fTemp291 - floorf(fTemp291));
			float 	fTemp292 = (499.0f * fRec113[0]);
			int 	iTemp293 = int(fTemp292);
			float 	fTemp294 = ftbl2[max(0, min(iTemp293, 499))];
			output0[i] = (FAUSTFLOAT)(((((((fTemp272 * ((0.5f * ((((0.2f * (fTemp294 + ((fTemp292 - float(iTemp293)) * (ftbl2[max(0, min((iTemp293 + 1), 499))] - fTemp294)))) + (0.8f * (fTemp290 + ((fTemp288 - float(iTemp289)) * (ftbl3[max(0, min((iTemp289 + 1), 499))] - fTemp290))))) * fSlow114) * fSlow112)) + (((fRec108[0] * (1.0f - fTemp273)) + (fSlow127 * (fTemp273 * (fRec96[0] - fRec96[2])))) * fSlow115))) + (fTemp224 * ((0.5f * ((((0.2f * (fTemp246 + ((fTemp244 - float(iTemp245)) * (ftbl2[max(0, min((iTemp245 + 1), 499))] - fTemp246)))) + (0.8f * (fTemp242 + ((fTemp240 - float(iTemp241)) * (ftbl3[max(0, min((iTemp241 + 1), 499))] - fTemp242))))) * fSlow92) * fSlow90)) + (((fRec90[0] * (1.0f - fTemp225)) + (fSlow105 * (fTemp225 * (fRec78[0] - fRec78[2])))) * fSlow93)))) + (fTemp176 * ((0.5f * ((((0.2f * (fTemp198 + ((fTemp196 - float(iTemp197)) * (ftbl2[max(0, min((iTemp197 + 1), 499))] - fTemp198)))) + (0.8f * (fTemp194 + ((fTemp192 - float(iTemp193)) * (ftbl3[max(0, min((iTemp193 + 1), 499))] - fTemp194))))) * fSlow70) * fSlow68)) + (((fRec72[0] * (1.0f - fTemp177)) + (fSlow83 * (fTemp177 * (fRec60[0] - fRec60[2])))) * fSlow71)))) + (fTemp128 * ((0.5f * ((((0.2f * (fTemp150 + ((fTemp148 - float(iTemp149)) * (ftbl2[max(0, min((iTemp149 + 1), 499))] - fTemp150)))) + (0.8f * (fTemp146 + ((fTemp144 - float(iTemp145)) * (ftbl3[max(0, min((iTemp145 + 1), 499))] - fTemp146))))) * fSlow48) * fSlow46)) + (((fRec54[0] * (1.0f - fTemp129)) + (fSlow61 * (fTemp129 * (fRec42[0] - fRec42[2])))) * fSlow49)))) + (fTemp80 * ((0.5f * ((((0.2f * (fTemp102 + ((fTemp100 - float(iTemp101)) * (ftbl2[max(0, min((iTemp101 + 1), 499))] - fTemp102)))) + (0.8f * (fTemp98 + ((fTemp96 - float(iTemp97)) * (ftbl3[max(0, min((iTemp97 + 1), 499))] - fTemp98))))) * fSlow26) * fSlow24)) + (((fRec36[0] * (1.0f - fTemp81)) + (fSlow39 * (fTemp81 * (fRec24[0] - fRec24[2])))) * fSlow27)))) + (fTemp29 * ((0.5f * ((((0.2f * (fTemp54 + ((fTemp52 - float(iTemp53)) * (ftbl2[max(0, min((iTemp53 + 1), 499))] - fTemp54)))) + (0.8f * (fTemp50 + ((fTemp48 - float(iTemp49)) * (ftbl3[max(0, min((iTemp49 + 1), 499))] - fTemp50))))) * fSlow4) * fSlow2)) + (((fRec16[0] * (1.0f - fTemp30)) + (fSlow17 * (fTemp30 * (fRec1[0] - fRec1[2])))) * fSlow5)))));
			// post processing
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec108[1] = fRec108[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec109[1] = fRec109[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec99[1] = fRec99[0];
			fRec103[1] = fRec103[0];
			fRec107[1] = fRec107[0];
			fRec106[1] = fRec106[0];
			iRec105[1] = iRec105[0];
			iRec104[1] = iRec104[0];
			iVec24[1] = iVec24[0];
			iRec98[2] = iRec98[1]; iRec98[1] = iRec98[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fVec23[1] = fVec23[0];
			iRec100[1] = iRec100[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec96[2] = fRec96[1]; fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec90[1] = fRec90[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			fRec79[2] = fRec79[1]; fRec79[1] = fRec79[0];
			fRec81[1] = fRec81[0];
			fRec85[1] = fRec85[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			iRec87[1] = iRec87[0];
			iRec86[1] = iRec86[0];
			iVec20[1] = iVec20[0];
			iRec80[2] = iRec80[1]; iRec80[1] = iRec80[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fVec19[1] = fVec19[0];
			iRec82[1] = iRec82[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec78[2] = fRec78[1]; fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec72[1] = fRec72[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fRec73[1] = fRec73[0];
			fRec61[2] = fRec61[1]; fRec61[1] = fRec61[0];
			fRec63[1] = fRec63[0];
			fRec67[1] = fRec67[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			iRec69[1] = iRec69[0];
			iRec68[1] = iRec68[0];
			iVec16[1] = iVec16[0];
			iRec62[2] = iRec62[1]; iRec62[1] = iRec62[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fVec15[1] = fVec15[0];
			iRec64[1] = iRec64[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec60[2] = fRec60[1]; fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec54[1] = fRec54[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec43[2] = fRec43[1]; fRec43[1] = fRec43[0];
			fRec45[1] = fRec45[0];
			fRec49[1] = fRec49[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			iRec51[1] = iRec51[0];
			iRec50[1] = iRec50[0];
			iVec12[1] = iVec12[0];
			iRec44[2] = iRec44[1]; iRec44[1] = iRec44[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fVec11[1] = fVec11[0];
			iRec46[1] = iRec46[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
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
			fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec16[1] = fRec16[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec10[1] = fRec10[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			iRec13[1] = iRec13[0];
			iRec12[1] = iRec12[0];
			iVec4[1] = iVec4[0];
			iRec4[2] = iRec4[1]; iRec4[1] = iRec4[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fVec3[1] = fVec3[0];
			iRec6[1] = iRec6[0];
			iRec7[1] = iRec7[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
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
