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
		int 	iRec8[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec8[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec8[0] = (iRec8[1] + 1);
				float 	fTemp17 = ((0.002002002f * float((iRec8[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp17)) + -1.0f))) * float(((fTemp17 > 0.0f) - (fTemp17 < 0.0f))));
				// post processing
				iRec8[1] = iRec8[0];
			}
		}
	};


	class SIG2 {
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
				output[i] = ((0.004008016f * float((iRec21[0] + -1))) + -1.0f);
				// post processing
				iRec21[1] = iRec21[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[500];
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec2[2];
	float 	fConst10;
	float 	fRec3[2];
	float 	fConst11;
	float 	fRec4[2];
	float 	fRec6[2];
	static float 	ftbl1[1000];
	FAUSTFLOAT 	fslider1;
	float 	fConst15;
	float 	fConst17;
	float 	fConst19;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec13[2];
	int 	iRec12[2];
	float 	fVec3[2];
	float 	fRec14[2];
	float 	fRec15[2];
	int 	iRec10[3];
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	int 	iVec4[2];
	int 	iRec17[2];
	int 	iRec18[2];
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec16[2];
	float 	fRec11[2];
	float 	fRec9[3];
	float 	fConst24;
	static float 	ftbl2[500];
	float 	fConst25;
	float 	fRec22[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec23[2];
	float 	fRec24[2];
	float 	fRec25[2];
	float 	fRec27[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec32[2];
	float 	fVec7[2];
	float 	fRec33[2];
	float 	fRec34[2];
	int 	iRec30[3];
	int 	iVec8[2];
	int 	iRec36[2];
	int 	iRec37[2];
	float 	fRec38[2];
	float 	fRec39[2];
	float 	fRec35[2];
	float 	fRec31[2];
	float 	fRec29[3];
	float 	fRec40[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec41[2];
	float 	fRec42[2];
	float 	fRec43[2];
	float 	fRec45[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec50[2];
	float 	fVec11[2];
	float 	fRec51[2];
	float 	fRec52[2];
	int 	iRec48[3];
	int 	iVec12[2];
	int 	iRec54[2];
	int 	iRec55[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec53[2];
	float 	fRec49[2];
	float 	fRec47[3];
	float 	fRec58[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec59[2];
	float 	fRec60[2];
	float 	fRec61[2];
	float 	fRec63[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec68[2];
	float 	fVec15[2];
	float 	fRec69[2];
	float 	fRec70[2];
	int 	iRec66[3];
	int 	iVec16[2];
	int 	iRec72[2];
	int 	iRec73[2];
	float 	fRec74[2];
	float 	fRec75[2];
	float 	fRec71[2];
	float 	fRec67[2];
	float 	fRec65[3];
	float 	fRec76[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec77[2];
	float 	fRec78[2];
	float 	fRec79[2];
	float 	fRec81[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec86[2];
	float 	fVec19[2];
	float 	fRec87[2];
	float 	fRec88[2];
	int 	iRec84[3];
	int 	iVec20[2];
	int 	iRec90[2];
	int 	iRec91[2];
	float 	fRec92[2];
	float 	fRec93[2];
	float 	fRec89[2];
	float 	fRec85[2];
	float 	fRec83[3];
	float 	fRec94[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec95[2];
	float 	fRec96[2];
	float 	fRec97[2];
	float 	fRec99[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec104[2];
	float 	fVec23[2];
	float 	fRec105[2];
	float 	fRec106[2];
	int 	iRec102[3];
	int 	iVec24[2];
	int 	iRec108[2];
	int 	iRec109[2];
	float 	fRec110[2];
	float 	fRec111[2];
	float 	fRec107[2];
	float 	fRec103[2];
	float 	fRec101[3];
	float 	fRec112[2];
	float 	fRec0[3];
	float 	fConst26;
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
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw2ptr:author", "Julius O. Smith III");
		m->declare("oscillators.lib/saw2ptr:license", "STK-4.3");
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
		sig1.fill(1000,ftbl1);
		SIG2 sig2;
		sig2.init(sample_rate);
		sig2.fill(500,ftbl2);
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
		fConst9 = (4.0878997f / fConst0);
		fConst10 = (2.0439498f / fConst0);
		fConst11 = (1.0f / fConst0);
		float 	fConst12 = powf((62.831852f / fConst0),2.0f);
		float 	fConst13 = ((fConst12 * ((0.2033f * fConst12) + 0.31755f)) + 1.0f);
		float 	fConst14 = powf(fConst13,2.0f);
		fConst15 = (2.0f * ((3947.8418f * (fConst14 / fConst1)) + -1.0f));
		float 	fConst16 = (3947.8418f * (fConst13 / fConst0));
		fConst17 = (((fConst13 * (fConst16 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst18 = (((fConst13 * (fConst16 + 88.49557f)) / fConst0) + 1.0f);
		fConst19 = (1.0f / fConst18);
		fConst20 = (0.1f * fConst0);
		fConst21 = (0.4f * fConst0);
		fConst22 = (0.15f * fConst0);
		fConst23 = (0.2f * fConst0);
		fConst24 = (fConst14 / (fConst1 * fConst18));
		fConst25 = (8.175799f / fConst0);
		fConst26 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<3; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec32[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<3; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec50[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<3; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec68[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<3; i++) iRec66[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec72[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<3; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<3; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec104[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<3; i++) iRec102[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec108[i] = 0;
		for (int i=0; i<2; i++) iRec109[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<3; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
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
		float 	fSlow3 = ((((8.175799f * fSlow0) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow4 = max(1.1920929e-07f, fabsf((8.067899f * fSlow0)));
		float 	fSlow5 = (fConst11 * fSlow4);
		float 	fSlow6 = (1.0f - (fConst0 / fSlow4));
		float 	fSlow7 = max(1.1920929e-07f, fabsf((8.285142f * fSlow0)));
		float 	fSlow8 = (fConst11 * fSlow7);
		float 	fSlow9 = (1.0f - (fConst0 / fSlow7));
		float 	fSlow10 = ftbl1[int(((499.5f * (float(fslider1) + 1.0f)) + 0.5f))];
		float 	fSlow11 = (0.05f - (((fSlow10 < 0.0f)) ? (0.5f * fSlow10) : fSlow10));
		float 	fSlow12 = float(fslider2);
		float 	fSlow13 = float(fslider3);
		int 	iSlow14 = (fSlow13 == 0.0f);
		float 	fSlow15 = (0.0f - fSlow13);
		float 	fSlow16 = (fConst25 * fSlow0);
		float 	fSlow17 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow18 = (fConst9 * fSlow17);
		float 	fSlow19 = (fConst10 * fSlow17);
		float 	fSlow20 = ((((8.175799f * fSlow17) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow21 = max(1.1920929e-07f, fabsf((8.067899f * fSlow17)));
		float 	fSlow22 = (fConst11 * fSlow21);
		float 	fSlow23 = (1.0f - (fConst0 / fSlow21));
		float 	fSlow24 = max(1.1920929e-07f, fabsf((8.285142f * fSlow17)));
		float 	fSlow25 = (fConst11 * fSlow24);
		float 	fSlow26 = (1.0f - (fConst0 / fSlow24));
		float 	fSlow27 = ftbl1[int(((499.5f * (float(fslider5) + 1.0f)) + 0.5f))];
		float 	fSlow28 = (0.05f - (((fSlow27 < 0.0f)) ? (0.5f * fSlow27) : fSlow27));
		float 	fSlow29 = float(fslider6);
		float 	fSlow30 = float(fslider7);
		int 	iSlow31 = (fSlow30 == 0.0f);
		float 	fSlow32 = (0.0f - fSlow30);
		float 	fSlow33 = (fConst25 * fSlow17);
		float 	fSlow34 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow35 = (fConst9 * fSlow34);
		float 	fSlow36 = (fConst10 * fSlow34);
		float 	fSlow37 = ((((8.175799f * fSlow34) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow38 = max(1.1920929e-07f, fabsf((8.067899f * fSlow34)));
		float 	fSlow39 = (fConst11 * fSlow38);
		float 	fSlow40 = (1.0f - (fConst0 / fSlow38));
		float 	fSlow41 = max(1.1920929e-07f, fabsf((8.285142f * fSlow34)));
		float 	fSlow42 = (fConst11 * fSlow41);
		float 	fSlow43 = (1.0f - (fConst0 / fSlow41));
		float 	fSlow44 = ftbl1[int(((499.5f * (float(fslider9) + 1.0f)) + 0.5f))];
		float 	fSlow45 = (0.05f - (((fSlow44 < 0.0f)) ? (0.5f * fSlow44) : fSlow44));
		float 	fSlow46 = float(fslider10);
		float 	fSlow47 = float(fslider11);
		int 	iSlow48 = (fSlow47 == 0.0f);
		float 	fSlow49 = (0.0f - fSlow47);
		float 	fSlow50 = (fConst25 * fSlow34);
		float 	fSlow51 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow52 = (fConst9 * fSlow51);
		float 	fSlow53 = (fConst10 * fSlow51);
		float 	fSlow54 = ((((8.175799f * fSlow51) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow55 = max(1.1920929e-07f, fabsf((8.067899f * fSlow51)));
		float 	fSlow56 = (fConst11 * fSlow55);
		float 	fSlow57 = (1.0f - (fConst0 / fSlow55));
		float 	fSlow58 = max(1.1920929e-07f, fabsf((8.285142f * fSlow51)));
		float 	fSlow59 = (fConst11 * fSlow58);
		float 	fSlow60 = (1.0f - (fConst0 / fSlow58));
		float 	fSlow61 = ftbl1[int(((499.5f * (float(fslider13) + 1.0f)) + 0.5f))];
		float 	fSlow62 = (0.05f - (((fSlow61 < 0.0f)) ? (0.5f * fSlow61) : fSlow61));
		float 	fSlow63 = float(fslider14);
		float 	fSlow64 = float(fslider15);
		int 	iSlow65 = (fSlow64 == 0.0f);
		float 	fSlow66 = (0.0f - fSlow64);
		float 	fSlow67 = (fConst25 * fSlow51);
		float 	fSlow68 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow69 = (fConst9 * fSlow68);
		float 	fSlow70 = (fConst10 * fSlow68);
		float 	fSlow71 = ((((8.175799f * fSlow68) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow72 = max(1.1920929e-07f, fabsf((8.067899f * fSlow68)));
		float 	fSlow73 = (fConst11 * fSlow72);
		float 	fSlow74 = (1.0f - (fConst0 / fSlow72));
		float 	fSlow75 = max(1.1920929e-07f, fabsf((8.285142f * fSlow68)));
		float 	fSlow76 = (fConst11 * fSlow75);
		float 	fSlow77 = (1.0f - (fConst0 / fSlow75));
		float 	fSlow78 = ftbl1[int(((499.5f * (float(fslider17) + 1.0f)) + 0.5f))];
		float 	fSlow79 = (0.05f - (((fSlow78 < 0.0f)) ? (0.5f * fSlow78) : fSlow78));
		float 	fSlow80 = float(fslider18);
		float 	fSlow81 = float(fslider19);
		int 	iSlow82 = (fSlow81 == 0.0f);
		float 	fSlow83 = (0.0f - fSlow81);
		float 	fSlow84 = (fConst25 * fSlow68);
		float 	fSlow85 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow86 = (fConst9 * fSlow85);
		float 	fSlow87 = (fConst10 * fSlow85);
		float 	fSlow88 = ((((8.175799f * fSlow85) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow89 = max(1.1920929e-07f, fabsf((8.067899f * fSlow85)));
		float 	fSlow90 = (fConst11 * fSlow89);
		float 	fSlow91 = (1.0f - (fConst0 / fSlow89));
		float 	fSlow92 = max(1.1920929e-07f, fabsf((8.285142f * fSlow85)));
		float 	fSlow93 = (fConst11 * fSlow92);
		float 	fSlow94 = (1.0f - (fConst0 / fSlow92));
		float 	fSlow95 = ftbl1[int(((499.5f * (float(fslider21) + 1.0f)) + 0.5f))];
		float 	fSlow96 = (0.05f - (((fSlow95 < 0.0f)) ? (0.5f * fSlow95) : fSlow95));
		float 	fSlow97 = float(fslider22);
		float 	fSlow98 = float(fslider23);
		int 	iSlow99 = (fSlow98 == 0.0f);
		float 	fSlow100 = (0.0f - fSlow98);
		float 	fSlow101 = (fConst25 * fSlow85);
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
			float 	fTemp7 = ((iTemp2) ? 0.0f : (fSlow2 + fRec3[1]));
			fRec3[0] = (fTemp7 - floorf(fTemp7));
			float 	fTemp8 = (499.0f * fRec3[0]);
			int 	iTemp9 = int(fTemp8);
			float 	fTemp10 = ftbl0[max(0, min(iTemp9, 499))];
			float 	fTemp11 = (fSlow5 + (fRec4[1] + -1.0f));
			float 	fTemp12 = (fSlow5 + fRec4[1]);
			int 	iTemp13 = (fTemp11 < 0.0f);
			fRec4[0] = ((iTemp13) ? fTemp12 : fTemp11);
			float 	fRec5 = ((iTemp13) ? fTemp12 : (fSlow5 + (fRec4[1] + (fSlow6 * fTemp11))));
			float 	fTemp14 = (fSlow8 + (fRec6[1] + -1.0f));
			float 	fTemp15 = (fSlow8 + fRec6[1]);
			int 	iTemp16 = (fTemp14 < 0.0f);
			fRec6[0] = ((iTemp16) ? fTemp15 : fTemp14);
			float 	fRec7 = ((iTemp16) ? fTemp15 : (fSlow8 + (fRec6[1] + (fSlow9 * fTemp14))));
			fVec1[0] = fSlow13;
			int 	iTemp18 = (fSlow13 != fVec1[1]);
			iVec2[0] = iTemp18;
			int 	iTemp19 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec13[0] = (iRec13[1] + 1);
			int 	iTemp20 = (iRec13[0] + -1);
			iRec12[0] = ((iRec12[1] * (1 - iTemp19)) + (iTemp20 * iTemp19));
			float 	fTemp21 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec12[0])))) > 0.5f) & iSlow14)) ? 0.0f : fSlow12) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp21;
			int 	iTemp22 = (fVec3[0] > 0.003f);
			int 	iTemp23 = (fVec3[0] <= 0.003f);
			float 	fTemp24 = float((iTemp23 | (fVec3[1] >= 0.003f)));
			fRec14[0] = max((fRec14[1] * fTemp24), fSlow13);
			fRec15[0] = max((fTemp24 * fRec15[1]), fSlow15);
			float 	fTemp25 = (min(1.0f, fRec15[0]) + min(1.0f, fRec14[0]));
			int 	iTemp26 = (fVec3[0] >= fRec11[1]);
			int 	iTemp27 = (fRec11[1] <= 0.001f);
			int 	iTemp28 = (((iRec10[1] >= 4)) ? (((iRec10[1] >= 6)) ? ((iTemp27) ? 0 : ((iTemp22) ? 1 : 6)) : (((iRec10[1] >= 5)) ? ((iTemp23) ? 3 : ((iTemp26) ? 4 : 5)) : ((iTemp23) ? 3 : (((fVec3[0] <= fRec11[1])) ? 5 : 4)))) : (((iRec10[1] >= 2)) ? (((iRec10[1] >= 3)) ? (((iTemp23 & iTemp27)) ? 0 : ((iTemp22) ? 1 : 3)) : ((iTemp23) ? 6 : ((iTemp26) ? 4 : 2))) : (((iRec10[1] >= 1)) ? (((fRec11[1] >= min(fTemp25, 1.0f))) ? ((iTemp23) ? 6 : 2) : 1) : ((iTemp22) ? 1 : 0))));
			iRec10[0] = iTemp28;
			float 	fTemp29 = (((iTemp28 >= 4)) ? (((iTemp28 >= 6)) ? fConst0 : fConst23) : (((iTemp28 >= 2)) ? (((iTemp28 >= 3)) ? fConst22 : fConst21) : (((iTemp28 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp30 = (iRec10[1] != iRec10[2]);
			iVec4[0] = iTemp30;
			int 	iTemp31 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec17[0] = ((iRec17[1] * (1 - iTemp31)) + (iTemp20 * iTemp31));
			float 	fTemp32 = min(19.0f, floorf((21.0f * (((fTemp29 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec17[0]))) / fTemp29) : 1.0f))));
			float 	fTemp33 = min((fTemp32 + 1.0f), 2e+01f);
			float 	fTemp34 = (((fTemp33 >= 11.0f)) ? (((fTemp33 >= 16.0f)) ? (((fTemp33 >= 19.0f)) ? (((fTemp33 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp33 >= 18.0f)) ? 0.03f : (((fTemp33 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp33 >= 14.0f)) ? (((fTemp33 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp33 >= 13.0f)) ? 0.14f : (((fTemp33 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp33 >= 6.0f)) ? (((fTemp33 >= 9.0f)) ? (((fTemp33 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp33 >= 8.0f)) ? 0.3f : (((fTemp33 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp33 >= 3.0f)) ? (((fTemp33 >= 5.0f)) ? 0.47f : (((fTemp33 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp33 >= 2.0f)) ? 0.74f : (((fTemp33 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec18[0] = iRec10[1];
			int 	iTemp35 = (iRec18[1] == iRec10[1]);
			int 	iTemp36 = (iRec10[1] == 0);
			fRec19[0] = ((iTemp36) ? fVec3[0] : ((iTemp35) ? min(min(fRec19[1], fVec3[0]), fRec11[1]) : min(fVec3[0], fRec11[1])));
			fRec20[0] = ((iTemp36) ? fVec3[0] : ((iTemp35) ? max(max(fRec20[1], fVec3[0]), fRec11[1]) : max(fVec3[0], fRec11[1])));
			int 	iTemp37 = (iRec10[1] == 3);
			int 	iTemp38 = (iRec10[1] == 6);
			float 	fTemp39 = (((iRec10[1] == 1)) ? min(1.0f, fTemp25) : ((iTemp36) ? 0.0f : ((iTemp38) ? (fTemp25 * fTemp34) : ((iTemp37) ? (fRec20[0] * fTemp34) : fVec3[0]))));
			float 	fTemp40 = (1.0f / ((iTemp36) ? 0.0001f : (((iTemp37 | iTemp38)) ? (0.05f * (fTemp29 / ((((fTemp32 >= 11.0f)) ? (((fTemp32 >= 16.0f)) ? (((fTemp32 >= 19.0f)) ? (((fTemp32 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp32 >= 18.0f)) ? 0.03f : (((fTemp32 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp32 >= 14.0f)) ? (((fTemp32 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp32 >= 13.0f)) ? 0.14f : (((fTemp32 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp32 >= 6.0f)) ? (((fTemp32 >= 9.0f)) ? (((fTemp32 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp32 >= 8.0f)) ? 0.3f : (((fTemp32 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp32 >= 3.0f)) ? (((fTemp32 >= 5.0f)) ? 0.47f : (((fTemp32 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp32 >= 2.0f)) ? 0.74f : (((fTemp32 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp34))) : fTemp29)));
			float 	fTemp41 = (fRec16[1] - fTemp40);
			float 	fTemp42 = (fRec16[1] + fTemp40);
			fRec16[0] = (((fTemp42 < fTemp39)) ? fTemp42 : (((fTemp41 > fTemp39)) ? fTemp41 : fTemp39));
			fRec11[0] = fRec16[0];
			fRec9[0] = (fRec11[0] - (fConst19 * ((fConst17 * fRec9[2]) + (fConst15 * fRec9[1]))));
			float 	fTemp43 = min(0.99f, (fConst24 * (((3947.8418f * fRec9[0]) + (7895.6836f * fRec9[1])) + (3947.8418f * fRec9[2]))));
			float 	fTemp44 = (fVec3[0] - fTemp43);
			float 	fTemp45 = min(0.8f, max(0.0f, (max(-0.75f, fTemp44) + fSlow11)));
			float 	fTemp46 = ((iTemp2) ? 0.0f : (fSlow16 + fRec22[1]));
			fRec22[0] = (fTemp46 - floorf(fTemp46));
			float 	fTemp47 = (499.0f * fRec22[0]);
			int 	iTemp48 = int(fTemp47);
			int 	iTemp49 = max(0, min(iTemp48, 499));
			float 	fTemp50 = ftbl2[iTemp49];
			int 	iTemp51 = max(0, min((iTemp48 + 1), 499));
			float 	fTemp52 = (fTemp47 - float(iTemp48));
			float 	fTemp53 = min(1.0f, (max(min((3.0f * fTemp44), 0.3f), -0.2f) + 0.15f));
			float 	fTemp54 = ftbl0[iTemp49];
			float 	fTemp55 = ((iTemp2) ? 0.0f : (fSlow18 + fRec23[1]));
			fRec23[0] = (fTemp55 - floorf(fTemp55));
			float 	fTemp56 = (499.0f * fRec23[0]);
			int 	iTemp57 = int(fTemp56);
			float 	fTemp58 = ftbl0[max(0, min(iTemp57, 499))];
			float 	fTemp59 = ((iTemp2) ? 0.0f : (fSlow19 + fRec24[1]));
			fRec24[0] = (fTemp59 - floorf(fTemp59));
			float 	fTemp60 = (499.0f * fRec24[0]);
			int 	iTemp61 = int(fTemp60);
			float 	fTemp62 = ftbl0[max(0, min(iTemp61, 499))];
			float 	fTemp63 = (fSlow22 + (fRec25[1] + -1.0f));
			float 	fTemp64 = (fSlow22 + fRec25[1]);
			int 	iTemp65 = (fTemp63 < 0.0f);
			fRec25[0] = ((iTemp65) ? fTemp64 : fTemp63);
			float 	fRec26 = ((iTemp65) ? fTemp64 : (fSlow22 + (fRec25[1] + (fSlow23 * fTemp63))));
			float 	fTemp66 = (fSlow25 + (fRec27[1] + -1.0f));
			float 	fTemp67 = (fSlow25 + fRec27[1]);
			int 	iTemp68 = (fTemp66 < 0.0f);
			fRec27[0] = ((iTemp68) ? fTemp67 : fTemp66);
			float 	fRec28 = ((iTemp68) ? fTemp67 : (fSlow25 + (fRec27[1] + (fSlow26 * fTemp66))));
			fVec5[0] = fSlow30;
			int 	iTemp69 = (fSlow30 != fVec5[1]);
			iVec6[0] = iTemp69;
			int 	iTemp70 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp70)) + (iTemp20 * iTemp70));
			float 	fTemp71 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec32[0])))) > 0.5f) & iSlow31)) ? 0.0f : fSlow29) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp71;
			int 	iTemp72 = (fVec7[0] > 0.003f);
			int 	iTemp73 = (fVec7[0] <= 0.003f);
			float 	fTemp74 = float((iTemp73 | (fVec7[1] >= 0.003f)));
			fRec33[0] = max((fRec33[1] * fTemp74), fSlow30);
			fRec34[0] = max((fTemp74 * fRec34[1]), fSlow32);
			float 	fTemp75 = (min(1.0f, fRec34[0]) + min(1.0f, fRec33[0]));
			int 	iTemp76 = (fVec7[0] >= fRec31[1]);
			int 	iTemp77 = (fRec31[1] <= 0.001f);
			int 	iTemp78 = (((iRec30[1] >= 4)) ? (((iRec30[1] >= 6)) ? ((iTemp77) ? 0 : ((iTemp72) ? 1 : 6)) : (((iRec30[1] >= 5)) ? ((iTemp73) ? 3 : ((iTemp76) ? 4 : 5)) : ((iTemp73) ? 3 : (((fVec7[0] <= fRec31[1])) ? 5 : 4)))) : (((iRec30[1] >= 2)) ? (((iRec30[1] >= 3)) ? (((iTemp73 & iTemp77)) ? 0 : ((iTemp72) ? 1 : 3)) : ((iTemp73) ? 6 : ((iTemp76) ? 4 : 2))) : (((iRec30[1] >= 1)) ? (((fRec31[1] >= min(fTemp75, 1.0f))) ? ((iTemp73) ? 6 : 2) : 1) : ((iTemp72) ? 1 : 0))));
			iRec30[0] = iTemp78;
			float 	fTemp79 = (((iTemp78 >= 4)) ? (((iTemp78 >= 6)) ? fConst0 : fConst23) : (((iTemp78 >= 2)) ? (((iTemp78 >= 3)) ? fConst22 : fConst21) : (((iTemp78 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp80 = (iRec30[1] != iRec30[2]);
			iVec8[0] = iTemp80;
			int 	iTemp81 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec36[0] = ((iRec36[1] * (1 - iTemp81)) + (iTemp20 * iTemp81));
			float 	fTemp82 = min(19.0f, floorf((21.0f * (((fTemp79 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec36[0]))) / fTemp79) : 1.0f))));
			float 	fTemp83 = min((fTemp82 + 1.0f), 2e+01f);
			float 	fTemp84 = (((fTemp83 >= 11.0f)) ? (((fTemp83 >= 16.0f)) ? (((fTemp83 >= 19.0f)) ? (((fTemp83 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp83 >= 18.0f)) ? 0.03f : (((fTemp83 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp83 >= 14.0f)) ? (((fTemp83 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp83 >= 13.0f)) ? 0.14f : (((fTemp83 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp83 >= 6.0f)) ? (((fTemp83 >= 9.0f)) ? (((fTemp83 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp83 >= 8.0f)) ? 0.3f : (((fTemp83 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp83 >= 3.0f)) ? (((fTemp83 >= 5.0f)) ? 0.47f : (((fTemp83 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp83 >= 2.0f)) ? 0.74f : (((fTemp83 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec37[0] = iRec30[1];
			int 	iTemp85 = (iRec37[1] == iRec30[1]);
			int 	iTemp86 = (iRec30[1] == 0);
			fRec38[0] = ((iTemp86) ? fVec7[0] : ((iTemp85) ? min(min(fRec38[1], fVec7[0]), fRec31[1]) : min(fVec7[0], fRec31[1])));
			fRec39[0] = ((iTemp86) ? fVec7[0] : ((iTemp85) ? max(max(fRec39[1], fVec7[0]), fRec31[1]) : max(fVec7[0], fRec31[1])));
			int 	iTemp87 = (iRec30[1] == 3);
			int 	iTemp88 = (iRec30[1] == 6);
			float 	fTemp89 = (((iRec30[1] == 1)) ? min(1.0f, fTemp75) : ((iTemp86) ? 0.0f : ((iTemp88) ? (fTemp75 * fTemp84) : ((iTemp87) ? (fRec39[0] * fTemp84) : fVec7[0]))));
			float 	fTemp90 = (1.0f / ((iTemp86) ? 0.0001f : (((iTemp87 | iTemp88)) ? (0.05f * (fTemp79 / ((((fTemp82 >= 11.0f)) ? (((fTemp82 >= 16.0f)) ? (((fTemp82 >= 19.0f)) ? (((fTemp82 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp82 >= 18.0f)) ? 0.03f : (((fTemp82 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp82 >= 14.0f)) ? (((fTemp82 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp82 >= 13.0f)) ? 0.14f : (((fTemp82 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp82 >= 6.0f)) ? (((fTemp82 >= 9.0f)) ? (((fTemp82 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp82 >= 8.0f)) ? 0.3f : (((fTemp82 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp82 >= 3.0f)) ? (((fTemp82 >= 5.0f)) ? 0.47f : (((fTemp82 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp82 >= 2.0f)) ? 0.74f : (((fTemp82 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp84))) : fTemp79)));
			float 	fTemp91 = (fRec35[1] - fTemp90);
			float 	fTemp92 = (fRec35[1] + fTemp90);
			fRec35[0] = (((fTemp92 < fTemp89)) ? fTemp92 : (((fTemp91 > fTemp89)) ? fTemp91 : fTemp89));
			fRec31[0] = fRec35[0];
			fRec29[0] = (fRec31[0] - (fConst19 * ((fConst17 * fRec29[2]) + (fConst15 * fRec29[1]))));
			float 	fTemp93 = min(0.99f, (fConst24 * (((3947.8418f * fRec29[0]) + (7895.6836f * fRec29[1])) + (3947.8418f * fRec29[2]))));
			float 	fTemp94 = (fVec7[0] - fTemp93);
			float 	fTemp95 = min(0.8f, max(0.0f, (max(-0.75f, fTemp94) + fSlow28)));
			float 	fTemp96 = ((iTemp2) ? 0.0f : (fSlow33 + fRec40[1]));
			fRec40[0] = (fTemp96 - floorf(fTemp96));
			float 	fTemp97 = (499.0f * fRec40[0]);
			int 	iTemp98 = int(fTemp97);
			int 	iTemp99 = max(0, min(iTemp98, 499));
			float 	fTemp100 = ftbl2[iTemp99];
			int 	iTemp101 = max(0, min((iTemp98 + 1), 499));
			float 	fTemp102 = (fTemp97 - float(iTemp98));
			float 	fTemp103 = min(1.0f, (max(min((3.0f * fTemp94), 0.3f), -0.2f) + 0.15f));
			float 	fTemp104 = ftbl0[iTemp99];
			float 	fTemp105 = ((iTemp2) ? 0.0f : (fSlow35 + fRec41[1]));
			fRec41[0] = (fTemp105 - floorf(fTemp105));
			float 	fTemp106 = (499.0f * fRec41[0]);
			int 	iTemp107 = int(fTemp106);
			float 	fTemp108 = ftbl0[max(0, min(iTemp107, 499))];
			float 	fTemp109 = ((iTemp2) ? 0.0f : (fSlow36 + fRec42[1]));
			fRec42[0] = (fTemp109 - floorf(fTemp109));
			float 	fTemp110 = (499.0f * fRec42[0]);
			int 	iTemp111 = int(fTemp110);
			float 	fTemp112 = ftbl0[max(0, min(iTemp111, 499))];
			float 	fTemp113 = (fSlow39 + (fRec43[1] + -1.0f));
			float 	fTemp114 = (fSlow39 + fRec43[1]);
			int 	iTemp115 = (fTemp113 < 0.0f);
			fRec43[0] = ((iTemp115) ? fTemp114 : fTemp113);
			float 	fRec44 = ((iTemp115) ? fTemp114 : (fSlow39 + (fRec43[1] + (fSlow40 * fTemp113))));
			float 	fTemp116 = (fSlow42 + (fRec45[1] + -1.0f));
			float 	fTemp117 = (fSlow42 + fRec45[1]);
			int 	iTemp118 = (fTemp116 < 0.0f);
			fRec45[0] = ((iTemp118) ? fTemp117 : fTemp116);
			float 	fRec46 = ((iTemp118) ? fTemp117 : (fSlow42 + (fRec45[1] + (fSlow43 * fTemp116))));
			fVec9[0] = fSlow47;
			int 	iTemp119 = (fSlow47 != fVec9[1]);
			iVec10[0] = iTemp119;
			int 	iTemp120 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec50[0] = ((iRec50[1] * (1 - iTemp120)) + (iTemp20 * iTemp120));
			float 	fTemp121 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec50[0])))) > 0.5f) & iSlow48)) ? 0.0f : fSlow46) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp121;
			int 	iTemp122 = (fVec11[0] > 0.003f);
			int 	iTemp123 = (fVec11[0] <= 0.003f);
			float 	fTemp124 = float((iTemp123 | (fVec11[1] >= 0.003f)));
			fRec51[0] = max((fRec51[1] * fTemp124), fSlow47);
			fRec52[0] = max((fTemp124 * fRec52[1]), fSlow49);
			float 	fTemp125 = (min(1.0f, fRec52[0]) + min(1.0f, fRec51[0]));
			int 	iTemp126 = (fVec11[0] >= fRec49[1]);
			int 	iTemp127 = (fRec49[1] <= 0.001f);
			int 	iTemp128 = (((iRec48[1] >= 4)) ? (((iRec48[1] >= 6)) ? ((iTemp127) ? 0 : ((iTemp122) ? 1 : 6)) : (((iRec48[1] >= 5)) ? ((iTemp123) ? 3 : ((iTemp126) ? 4 : 5)) : ((iTemp123) ? 3 : (((fVec11[0] <= fRec49[1])) ? 5 : 4)))) : (((iRec48[1] >= 2)) ? (((iRec48[1] >= 3)) ? (((iTemp123 & iTemp127)) ? 0 : ((iTemp122) ? 1 : 3)) : ((iTemp123) ? 6 : ((iTemp126) ? 4 : 2))) : (((iRec48[1] >= 1)) ? (((fRec49[1] >= min(fTemp125, 1.0f))) ? ((iTemp123) ? 6 : 2) : 1) : ((iTemp122) ? 1 : 0))));
			iRec48[0] = iTemp128;
			float 	fTemp129 = (((iTemp128 >= 4)) ? (((iTemp128 >= 6)) ? fConst0 : fConst23) : (((iTemp128 >= 2)) ? (((iTemp128 >= 3)) ? fConst22 : fConst21) : (((iTemp128 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp130 = (iRec48[1] != iRec48[2]);
			iVec12[0] = iTemp130;
			int 	iTemp131 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec54[0] = ((iRec54[1] * (1 - iTemp131)) + (iTemp20 * iTemp131));
			float 	fTemp132 = min(19.0f, floorf((21.0f * (((fTemp129 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec54[0]))) / fTemp129) : 1.0f))));
			float 	fTemp133 = min((fTemp132 + 1.0f), 2e+01f);
			float 	fTemp134 = (((fTemp133 >= 11.0f)) ? (((fTemp133 >= 16.0f)) ? (((fTemp133 >= 19.0f)) ? (((fTemp133 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp133 >= 18.0f)) ? 0.03f : (((fTemp133 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp133 >= 14.0f)) ? (((fTemp133 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp133 >= 13.0f)) ? 0.14f : (((fTemp133 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp133 >= 6.0f)) ? (((fTemp133 >= 9.0f)) ? (((fTemp133 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp133 >= 8.0f)) ? 0.3f : (((fTemp133 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp133 >= 3.0f)) ? (((fTemp133 >= 5.0f)) ? 0.47f : (((fTemp133 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp133 >= 2.0f)) ? 0.74f : (((fTemp133 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec55[0] = iRec48[1];
			int 	iTemp135 = (iRec55[1] == iRec48[1]);
			int 	iTemp136 = (iRec48[1] == 0);
			fRec56[0] = ((iTemp136) ? fVec11[0] : ((iTemp135) ? min(min(fRec56[1], fVec11[0]), fRec49[1]) : min(fVec11[0], fRec49[1])));
			fRec57[0] = ((iTemp136) ? fVec11[0] : ((iTemp135) ? max(max(fRec57[1], fVec11[0]), fRec49[1]) : max(fVec11[0], fRec49[1])));
			int 	iTemp137 = (iRec48[1] == 3);
			int 	iTemp138 = (iRec48[1] == 6);
			float 	fTemp139 = (((iRec48[1] == 1)) ? min(1.0f, fTemp125) : ((iTemp136) ? 0.0f : ((iTemp138) ? (fTemp125 * fTemp134) : ((iTemp137) ? (fRec57[0] * fTemp134) : fVec11[0]))));
			float 	fTemp140 = (1.0f / ((iTemp136) ? 0.0001f : (((iTemp137 | iTemp138)) ? (0.05f * (fTemp129 / ((((fTemp132 >= 11.0f)) ? (((fTemp132 >= 16.0f)) ? (((fTemp132 >= 19.0f)) ? (((fTemp132 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp132 >= 18.0f)) ? 0.03f : (((fTemp132 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp132 >= 14.0f)) ? (((fTemp132 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp132 >= 13.0f)) ? 0.14f : (((fTemp132 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp132 >= 6.0f)) ? (((fTemp132 >= 9.0f)) ? (((fTemp132 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp132 >= 8.0f)) ? 0.3f : (((fTemp132 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp132 >= 3.0f)) ? (((fTemp132 >= 5.0f)) ? 0.47f : (((fTemp132 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp132 >= 2.0f)) ? 0.74f : (((fTemp132 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp134))) : fTemp129)));
			float 	fTemp141 = (fRec53[1] - fTemp140);
			float 	fTemp142 = (fRec53[1] + fTemp140);
			fRec53[0] = (((fTemp142 < fTemp139)) ? fTemp142 : (((fTemp141 > fTemp139)) ? fTemp141 : fTemp139));
			fRec49[0] = fRec53[0];
			fRec47[0] = (fRec49[0] - (fConst19 * ((fConst17 * fRec47[2]) + (fConst15 * fRec47[1]))));
			float 	fTemp143 = min(0.99f, (fConst24 * (((3947.8418f * fRec47[0]) + (7895.6836f * fRec47[1])) + (3947.8418f * fRec47[2]))));
			float 	fTemp144 = (fVec11[0] - fTemp143);
			float 	fTemp145 = min(0.8f, max(0.0f, (max(-0.75f, fTemp144) + fSlow45)));
			float 	fTemp146 = ((iTemp2) ? 0.0f : (fSlow50 + fRec58[1]));
			fRec58[0] = (fTemp146 - floorf(fTemp146));
			float 	fTemp147 = (499.0f * fRec58[0]);
			int 	iTemp148 = int(fTemp147);
			int 	iTemp149 = max(0, min(iTemp148, 499));
			float 	fTemp150 = ftbl2[iTemp149];
			int 	iTemp151 = max(0, min((iTemp148 + 1), 499));
			float 	fTemp152 = (fTemp147 - float(iTemp148));
			float 	fTemp153 = min(1.0f, (max(min((3.0f * fTemp144), 0.3f), -0.2f) + 0.15f));
			float 	fTemp154 = ftbl0[iTemp149];
			float 	fTemp155 = ((iTemp2) ? 0.0f : (fSlow52 + fRec59[1]));
			fRec59[0] = (fTemp155 - floorf(fTemp155));
			float 	fTemp156 = (499.0f * fRec59[0]);
			int 	iTemp157 = int(fTemp156);
			float 	fTemp158 = ftbl0[max(0, min(iTemp157, 499))];
			float 	fTemp159 = ((iTemp2) ? 0.0f : (fSlow53 + fRec60[1]));
			fRec60[0] = (fTemp159 - floorf(fTemp159));
			float 	fTemp160 = (499.0f * fRec60[0]);
			int 	iTemp161 = int(fTemp160);
			float 	fTemp162 = ftbl0[max(0, min(iTemp161, 499))];
			float 	fTemp163 = (fSlow56 + (fRec61[1] + -1.0f));
			float 	fTemp164 = (fSlow56 + fRec61[1]);
			int 	iTemp165 = (fTemp163 < 0.0f);
			fRec61[0] = ((iTemp165) ? fTemp164 : fTemp163);
			float 	fRec62 = ((iTemp165) ? fTemp164 : (fSlow56 + (fRec61[1] + (fSlow57 * fTemp163))));
			float 	fTemp166 = (fSlow59 + (fRec63[1] + -1.0f));
			float 	fTemp167 = (fSlow59 + fRec63[1]);
			int 	iTemp168 = (fTemp166 < 0.0f);
			fRec63[0] = ((iTemp168) ? fTemp167 : fTemp166);
			float 	fRec64 = ((iTemp168) ? fTemp167 : (fSlow59 + (fRec63[1] + (fSlow60 * fTemp166))));
			fVec13[0] = fSlow64;
			int 	iTemp169 = (fSlow64 != fVec13[1]);
			iVec14[0] = iTemp169;
			int 	iTemp170 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec68[0] = ((iRec68[1] * (1 - iTemp170)) + (iTemp20 * iTemp170));
			float 	fTemp171 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec68[0])))) > 0.5f) & iSlow65)) ? 0.0f : fSlow63) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp171;
			int 	iTemp172 = (fVec15[0] > 0.003f);
			int 	iTemp173 = (fVec15[0] <= 0.003f);
			float 	fTemp174 = float((iTemp173 | (fVec15[1] >= 0.003f)));
			fRec69[0] = max((fRec69[1] * fTemp174), fSlow64);
			fRec70[0] = max((fTemp174 * fRec70[1]), fSlow66);
			float 	fTemp175 = (min(1.0f, fRec70[0]) + min(1.0f, fRec69[0]));
			int 	iTemp176 = (fVec15[0] >= fRec67[1]);
			int 	iTemp177 = (fRec67[1] <= 0.001f);
			int 	iTemp178 = (((iRec66[1] >= 4)) ? (((iRec66[1] >= 6)) ? ((iTemp177) ? 0 : ((iTemp172) ? 1 : 6)) : (((iRec66[1] >= 5)) ? ((iTemp173) ? 3 : ((iTemp176) ? 4 : 5)) : ((iTemp173) ? 3 : (((fVec15[0] <= fRec67[1])) ? 5 : 4)))) : (((iRec66[1] >= 2)) ? (((iRec66[1] >= 3)) ? (((iTemp173 & iTemp177)) ? 0 : ((iTemp172) ? 1 : 3)) : ((iTemp173) ? 6 : ((iTemp176) ? 4 : 2))) : (((iRec66[1] >= 1)) ? (((fRec67[1] >= min(fTemp175, 1.0f))) ? ((iTemp173) ? 6 : 2) : 1) : ((iTemp172) ? 1 : 0))));
			iRec66[0] = iTemp178;
			float 	fTemp179 = (((iTemp178 >= 4)) ? (((iTemp178 >= 6)) ? fConst0 : fConst23) : (((iTemp178 >= 2)) ? (((iTemp178 >= 3)) ? fConst22 : fConst21) : (((iTemp178 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp180 = (iRec66[1] != iRec66[2]);
			iVec16[0] = iTemp180;
			int 	iTemp181 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec72[0] = ((iRec72[1] * (1 - iTemp181)) + (iTemp20 * iTemp181));
			float 	fTemp182 = min(19.0f, floorf((21.0f * (((fTemp179 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec72[0]))) / fTemp179) : 1.0f))));
			float 	fTemp183 = min((fTemp182 + 1.0f), 2e+01f);
			float 	fTemp184 = (((fTemp183 >= 11.0f)) ? (((fTemp183 >= 16.0f)) ? (((fTemp183 >= 19.0f)) ? (((fTemp183 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp183 >= 18.0f)) ? 0.03f : (((fTemp183 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp183 >= 14.0f)) ? (((fTemp183 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp183 >= 13.0f)) ? 0.14f : (((fTemp183 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp183 >= 6.0f)) ? (((fTemp183 >= 9.0f)) ? (((fTemp183 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp183 >= 8.0f)) ? 0.3f : (((fTemp183 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp183 >= 3.0f)) ? (((fTemp183 >= 5.0f)) ? 0.47f : (((fTemp183 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp183 >= 2.0f)) ? 0.74f : (((fTemp183 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec73[0] = iRec66[1];
			int 	iTemp185 = (iRec73[1] == iRec66[1]);
			int 	iTemp186 = (iRec66[1] == 0);
			fRec74[0] = ((iTemp186) ? fVec15[0] : ((iTemp185) ? min(min(fRec74[1], fVec15[0]), fRec67[1]) : min(fVec15[0], fRec67[1])));
			fRec75[0] = ((iTemp186) ? fVec15[0] : ((iTemp185) ? max(max(fRec75[1], fVec15[0]), fRec67[1]) : max(fVec15[0], fRec67[1])));
			int 	iTemp187 = (iRec66[1] == 3);
			int 	iTemp188 = (iRec66[1] == 6);
			float 	fTemp189 = (((iRec66[1] == 1)) ? min(1.0f, fTemp175) : ((iTemp186) ? 0.0f : ((iTemp188) ? (fTemp175 * fTemp184) : ((iTemp187) ? (fRec75[0] * fTemp184) : fVec15[0]))));
			float 	fTemp190 = (1.0f / ((iTemp186) ? 0.0001f : (((iTemp187 | iTemp188)) ? (0.05f * (fTemp179 / ((((fTemp182 >= 11.0f)) ? (((fTemp182 >= 16.0f)) ? (((fTemp182 >= 19.0f)) ? (((fTemp182 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp182 >= 18.0f)) ? 0.03f : (((fTemp182 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp182 >= 14.0f)) ? (((fTemp182 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp182 >= 13.0f)) ? 0.14f : (((fTemp182 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp182 >= 6.0f)) ? (((fTemp182 >= 9.0f)) ? (((fTemp182 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp182 >= 8.0f)) ? 0.3f : (((fTemp182 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp182 >= 3.0f)) ? (((fTemp182 >= 5.0f)) ? 0.47f : (((fTemp182 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp182 >= 2.0f)) ? 0.74f : (((fTemp182 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp184))) : fTemp179)));
			float 	fTemp191 = (fRec71[1] - fTemp190);
			float 	fTemp192 = (fRec71[1] + fTemp190);
			fRec71[0] = (((fTemp192 < fTemp189)) ? fTemp192 : (((fTemp191 > fTemp189)) ? fTemp191 : fTemp189));
			fRec67[0] = fRec71[0];
			fRec65[0] = (fRec67[0] - (fConst19 * ((fConst17 * fRec65[2]) + (fConst15 * fRec65[1]))));
			float 	fTemp193 = min(0.99f, (fConst24 * (((3947.8418f * fRec65[0]) + (7895.6836f * fRec65[1])) + (3947.8418f * fRec65[2]))));
			float 	fTemp194 = (fVec15[0] - fTemp193);
			float 	fTemp195 = min(0.8f, max(0.0f, (max(-0.75f, fTemp194) + fSlow62)));
			float 	fTemp196 = ((iTemp2) ? 0.0f : (fSlow67 + fRec76[1]));
			fRec76[0] = (fTemp196 - floorf(fTemp196));
			float 	fTemp197 = (499.0f * fRec76[0]);
			int 	iTemp198 = int(fTemp197);
			int 	iTemp199 = max(0, min(iTemp198, 499));
			float 	fTemp200 = ftbl2[iTemp199];
			int 	iTemp201 = max(0, min((iTemp198 + 1), 499));
			float 	fTemp202 = (fTemp197 - float(iTemp198));
			float 	fTemp203 = min(1.0f, (max(min((3.0f * fTemp194), 0.3f), -0.2f) + 0.15f));
			float 	fTemp204 = ftbl0[iTemp199];
			float 	fTemp205 = ((iTemp2) ? 0.0f : (fSlow69 + fRec77[1]));
			fRec77[0] = (fTemp205 - floorf(fTemp205));
			float 	fTemp206 = (499.0f * fRec77[0]);
			int 	iTemp207 = int(fTemp206);
			float 	fTemp208 = ftbl0[max(0, min(iTemp207, 499))];
			float 	fTemp209 = ((iTemp2) ? 0.0f : (fSlow70 + fRec78[1]));
			fRec78[0] = (fTemp209 - floorf(fTemp209));
			float 	fTemp210 = (499.0f * fRec78[0]);
			int 	iTemp211 = int(fTemp210);
			float 	fTemp212 = ftbl0[max(0, min(iTemp211, 499))];
			float 	fTemp213 = (fSlow73 + (fRec79[1] + -1.0f));
			float 	fTemp214 = (fSlow73 + fRec79[1]);
			int 	iTemp215 = (fTemp213 < 0.0f);
			fRec79[0] = ((iTemp215) ? fTemp214 : fTemp213);
			float 	fRec80 = ((iTemp215) ? fTemp214 : (fSlow73 + (fRec79[1] + (fSlow74 * fTemp213))));
			float 	fTemp216 = (fSlow76 + (fRec81[1] + -1.0f));
			float 	fTemp217 = (fSlow76 + fRec81[1]);
			int 	iTemp218 = (fTemp216 < 0.0f);
			fRec81[0] = ((iTemp218) ? fTemp217 : fTemp216);
			float 	fRec82 = ((iTemp218) ? fTemp217 : (fSlow76 + (fRec81[1] + (fSlow77 * fTemp216))));
			fVec17[0] = fSlow81;
			int 	iTemp219 = (fSlow81 != fVec17[1]);
			iVec18[0] = iTemp219;
			int 	iTemp220 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp220)) + (iTemp20 * iTemp220));
			float 	fTemp221 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec86[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp221;
			int 	iTemp222 = (fVec19[0] > 0.003f);
			int 	iTemp223 = (fVec19[0] <= 0.003f);
			float 	fTemp224 = float((iTemp223 | (fVec19[1] >= 0.003f)));
			fRec87[0] = max((fRec87[1] * fTemp224), fSlow81);
			fRec88[0] = max((fTemp224 * fRec88[1]), fSlow83);
			float 	fTemp225 = (min(1.0f, fRec88[0]) + min(1.0f, fRec87[0]));
			int 	iTemp226 = (fVec19[0] >= fRec85[1]);
			int 	iTemp227 = (fRec85[1] <= 0.001f);
			int 	iTemp228 = (((iRec84[1] >= 4)) ? (((iRec84[1] >= 6)) ? ((iTemp227) ? 0 : ((iTemp222) ? 1 : 6)) : (((iRec84[1] >= 5)) ? ((iTemp223) ? 3 : ((iTemp226) ? 4 : 5)) : ((iTemp223) ? 3 : (((fVec19[0] <= fRec85[1])) ? 5 : 4)))) : (((iRec84[1] >= 2)) ? (((iRec84[1] >= 3)) ? (((iTemp223 & iTemp227)) ? 0 : ((iTemp222) ? 1 : 3)) : ((iTemp223) ? 6 : ((iTemp226) ? 4 : 2))) : (((iRec84[1] >= 1)) ? (((fRec85[1] >= min(fTemp225, 1.0f))) ? ((iTemp223) ? 6 : 2) : 1) : ((iTemp222) ? 1 : 0))));
			iRec84[0] = iTemp228;
			float 	fTemp229 = (((iTemp228 >= 4)) ? (((iTemp228 >= 6)) ? fConst0 : fConst23) : (((iTemp228 >= 2)) ? (((iTemp228 >= 3)) ? fConst22 : fConst21) : (((iTemp228 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp230 = (iRec84[1] != iRec84[2]);
			iVec20[0] = iTemp230;
			int 	iTemp231 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp231)) + (iTemp20 * iTemp231));
			float 	fTemp232 = min(19.0f, floorf((21.0f * (((fTemp229 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec90[0]))) / fTemp229) : 1.0f))));
			float 	fTemp233 = min((fTemp232 + 1.0f), 2e+01f);
			float 	fTemp234 = (((fTemp233 >= 11.0f)) ? (((fTemp233 >= 16.0f)) ? (((fTemp233 >= 19.0f)) ? (((fTemp233 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp233 >= 18.0f)) ? 0.03f : (((fTemp233 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp233 >= 14.0f)) ? (((fTemp233 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp233 >= 13.0f)) ? 0.14f : (((fTemp233 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp233 >= 6.0f)) ? (((fTemp233 >= 9.0f)) ? (((fTemp233 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp233 >= 8.0f)) ? 0.3f : (((fTemp233 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp233 >= 3.0f)) ? (((fTemp233 >= 5.0f)) ? 0.47f : (((fTemp233 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp233 >= 2.0f)) ? 0.74f : (((fTemp233 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec91[0] = iRec84[1];
			int 	iTemp235 = (iRec91[1] == iRec84[1]);
			int 	iTemp236 = (iRec84[1] == 0);
			fRec92[0] = ((iTemp236) ? fVec19[0] : ((iTemp235) ? min(min(fRec92[1], fVec19[0]), fRec85[1]) : min(fVec19[0], fRec85[1])));
			fRec93[0] = ((iTemp236) ? fVec19[0] : ((iTemp235) ? max(max(fRec93[1], fVec19[0]), fRec85[1]) : max(fVec19[0], fRec85[1])));
			int 	iTemp237 = (iRec84[1] == 3);
			int 	iTemp238 = (iRec84[1] == 6);
			float 	fTemp239 = (((iRec84[1] == 1)) ? min(1.0f, fTemp225) : ((iTemp236) ? 0.0f : ((iTemp238) ? (fTemp225 * fTemp234) : ((iTemp237) ? (fRec93[0] * fTemp234) : fVec19[0]))));
			float 	fTemp240 = (1.0f / ((iTemp236) ? 0.0001f : (((iTemp237 | iTemp238)) ? (0.05f * (fTemp229 / ((((fTemp232 >= 11.0f)) ? (((fTemp232 >= 16.0f)) ? (((fTemp232 >= 19.0f)) ? (((fTemp232 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp232 >= 18.0f)) ? 0.03f : (((fTemp232 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp232 >= 14.0f)) ? (((fTemp232 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp232 >= 13.0f)) ? 0.14f : (((fTemp232 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp232 >= 6.0f)) ? (((fTemp232 >= 9.0f)) ? (((fTemp232 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp232 >= 8.0f)) ? 0.3f : (((fTemp232 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp232 >= 3.0f)) ? (((fTemp232 >= 5.0f)) ? 0.47f : (((fTemp232 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp232 >= 2.0f)) ? 0.74f : (((fTemp232 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp234))) : fTemp229)));
			float 	fTemp241 = (fRec89[1] - fTemp240);
			float 	fTemp242 = (fRec89[1] + fTemp240);
			fRec89[0] = (((fTemp242 < fTemp239)) ? fTemp242 : (((fTemp241 > fTemp239)) ? fTemp241 : fTemp239));
			fRec85[0] = fRec89[0];
			fRec83[0] = (fRec85[0] - (fConst19 * ((fConst17 * fRec83[2]) + (fConst15 * fRec83[1]))));
			float 	fTemp243 = min(0.99f, (fConst24 * (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]))));
			float 	fTemp244 = (fVec19[0] - fTemp243);
			float 	fTemp245 = min(0.8f, max(0.0f, (max(-0.75f, fTemp244) + fSlow79)));
			float 	fTemp246 = ((iTemp2) ? 0.0f : (fSlow84 + fRec94[1]));
			fRec94[0] = (fTemp246 - floorf(fTemp246));
			float 	fTemp247 = (499.0f * fRec94[0]);
			int 	iTemp248 = int(fTemp247);
			int 	iTemp249 = max(0, min(iTemp248, 499));
			float 	fTemp250 = ftbl2[iTemp249];
			int 	iTemp251 = max(0, min((iTemp248 + 1), 499));
			float 	fTemp252 = (fTemp247 - float(iTemp248));
			float 	fTemp253 = min(1.0f, (max(min((3.0f * fTemp244), 0.3f), -0.2f) + 0.15f));
			float 	fTemp254 = ftbl0[iTemp249];
			float 	fTemp255 = ((iTemp2) ? 0.0f : (fSlow86 + fRec95[1]));
			fRec95[0] = (fTemp255 - floorf(fTemp255));
			float 	fTemp256 = (499.0f * fRec95[0]);
			int 	iTemp257 = int(fTemp256);
			float 	fTemp258 = ftbl0[max(0, min(iTemp257, 499))];
			float 	fTemp259 = ((iTemp2) ? 0.0f : (fSlow87 + fRec96[1]));
			fRec96[0] = (fTemp259 - floorf(fTemp259));
			float 	fTemp260 = (499.0f * fRec96[0]);
			int 	iTemp261 = int(fTemp260);
			float 	fTemp262 = ftbl0[max(0, min(iTemp261, 499))];
			float 	fTemp263 = (fSlow90 + (fRec97[1] + -1.0f));
			float 	fTemp264 = (fSlow90 + fRec97[1]);
			int 	iTemp265 = (fTemp263 < 0.0f);
			fRec97[0] = ((iTemp265) ? fTemp264 : fTemp263);
			float 	fRec98 = ((iTemp265) ? fTemp264 : (fSlow90 + (fRec97[1] + (fSlow91 * fTemp263))));
			float 	fTemp266 = (fSlow93 + (fRec99[1] + -1.0f));
			float 	fTemp267 = (fSlow93 + fRec99[1]);
			int 	iTemp268 = (fTemp266 < 0.0f);
			fRec99[0] = ((iTemp268) ? fTemp267 : fTemp266);
			float 	fRec100 = ((iTemp268) ? fTemp267 : (fSlow93 + (fRec99[1] + (fSlow94 * fTemp266))));
			fVec21[0] = fSlow98;
			int 	iTemp269 = (fSlow98 != fVec21[1]);
			iVec22[0] = iTemp269;
			int 	iTemp270 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec104[0] = ((iRec104[1] * (1 - iTemp270)) + (iTemp20 * iTemp270));
			float 	fTemp271 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec104[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp271;
			int 	iTemp272 = (fVec23[0] > 0.003f);
			int 	iTemp273 = (fVec23[0] <= 0.003f);
			float 	fTemp274 = float((iTemp273 | (fVec23[1] >= 0.003f)));
			fRec105[0] = max((fRec105[1] * fTemp274), fSlow98);
			fRec106[0] = max((fTemp274 * fRec106[1]), fSlow100);
			float 	fTemp275 = (min(1.0f, fRec106[0]) + min(1.0f, fRec105[0]));
			int 	iTemp276 = (fVec23[0] >= fRec103[1]);
			int 	iTemp277 = (fRec103[1] <= 0.001f);
			int 	iTemp278 = (((iRec102[1] >= 4)) ? (((iRec102[1] >= 6)) ? ((iTemp277) ? 0 : ((iTemp272) ? 1 : 6)) : (((iRec102[1] >= 5)) ? ((iTemp273) ? 3 : ((iTemp276) ? 4 : 5)) : ((iTemp273) ? 3 : (((fVec23[0] <= fRec103[1])) ? 5 : 4)))) : (((iRec102[1] >= 2)) ? (((iRec102[1] >= 3)) ? (((iTemp273 & iTemp277)) ? 0 : ((iTemp272) ? 1 : 3)) : ((iTemp273) ? 6 : ((iTemp276) ? 4 : 2))) : (((iRec102[1] >= 1)) ? (((fRec103[1] >= min(fTemp275, 1.0f))) ? ((iTemp273) ? 6 : 2) : 1) : ((iTemp272) ? 1 : 0))));
			iRec102[0] = iTemp278;
			float 	fTemp279 = (((iTemp278 >= 4)) ? (((iTemp278 >= 6)) ? fConst0 : fConst23) : (((iTemp278 >= 2)) ? (((iTemp278 >= 3)) ? fConst22 : fConst21) : (((iTemp278 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp280 = (iRec102[1] != iRec102[2]);
			iVec24[0] = iTemp280;
			int 	iTemp281 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec108[0] = ((iRec108[1] * (1 - iTemp281)) + (iTemp20 * iTemp281));
			float 	fTemp282 = min(19.0f, floorf((21.0f * (((fTemp279 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec108[0]))) / fTemp279) : 1.0f))));
			float 	fTemp283 = min((fTemp282 + 1.0f), 2e+01f);
			float 	fTemp284 = (((fTemp283 >= 11.0f)) ? (((fTemp283 >= 16.0f)) ? (((fTemp283 >= 19.0f)) ? (((fTemp283 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp283 >= 18.0f)) ? 0.03f : (((fTemp283 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp283 >= 14.0f)) ? (((fTemp283 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp283 >= 13.0f)) ? 0.14f : (((fTemp283 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp283 >= 6.0f)) ? (((fTemp283 >= 9.0f)) ? (((fTemp283 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp283 >= 8.0f)) ? 0.3f : (((fTemp283 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp283 >= 3.0f)) ? (((fTemp283 >= 5.0f)) ? 0.47f : (((fTemp283 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp283 >= 2.0f)) ? 0.74f : (((fTemp283 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec109[0] = iRec102[1];
			int 	iTemp285 = (iRec109[1] == iRec102[1]);
			int 	iTemp286 = (iRec102[1] == 0);
			fRec110[0] = ((iTemp286) ? fVec23[0] : ((iTemp285) ? min(min(fRec110[1], fVec23[0]), fRec103[1]) : min(fVec23[0], fRec103[1])));
			fRec111[0] = ((iTemp286) ? fVec23[0] : ((iTemp285) ? max(max(fRec111[1], fVec23[0]), fRec103[1]) : max(fVec23[0], fRec103[1])));
			int 	iTemp287 = (iRec102[1] == 3);
			int 	iTemp288 = (iRec102[1] == 6);
			float 	fTemp289 = (((iRec102[1] == 1)) ? min(1.0f, fTemp275) : ((iTemp286) ? 0.0f : ((iTemp288) ? (fTemp275 * fTemp284) : ((iTemp287) ? (fRec111[0] * fTemp284) : fVec23[0]))));
			float 	fTemp290 = (1.0f / ((iTemp286) ? 0.0001f : (((iTemp287 | iTemp288)) ? (0.05f * (fTemp279 / ((((fTemp282 >= 11.0f)) ? (((fTemp282 >= 16.0f)) ? (((fTemp282 >= 19.0f)) ? (((fTemp282 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp282 >= 18.0f)) ? 0.03f : (((fTemp282 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp282 >= 14.0f)) ? (((fTemp282 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp282 >= 13.0f)) ? 0.14f : (((fTemp282 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp282 >= 6.0f)) ? (((fTemp282 >= 9.0f)) ? (((fTemp282 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp282 >= 8.0f)) ? 0.3f : (((fTemp282 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp282 >= 3.0f)) ? (((fTemp282 >= 5.0f)) ? 0.47f : (((fTemp282 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp282 >= 2.0f)) ? 0.74f : (((fTemp282 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp284))) : fTemp279)));
			float 	fTemp291 = (fRec107[1] - fTemp290);
			float 	fTemp292 = (fRec107[1] + fTemp290);
			fRec107[0] = (((fTemp292 < fTemp289)) ? fTemp292 : (((fTemp291 > fTemp289)) ? fTemp291 : fTemp289));
			fRec103[0] = fRec107[0];
			fRec101[0] = (fRec103[0] - (fConst19 * ((fConst17 * fRec101[2]) + (fConst15 * fRec101[1]))));
			float 	fTemp293 = min(0.99f, (fConst24 * (((3947.8418f * fRec101[0]) + (7895.6836f * fRec101[1])) + (3947.8418f * fRec101[2]))));
			float 	fTemp294 = (fVec23[0] - fTemp293);
			float 	fTemp295 = min(0.8f, max(0.0f, (max(-0.75f, fTemp294) + fSlow96)));
			float 	fTemp296 = ((iTemp2) ? 0.0f : (fSlow101 + fRec112[1]));
			fRec112[0] = (fTemp296 - floorf(fTemp296));
			float 	fTemp297 = (499.0f * fRec112[0]);
			int 	iTemp298 = int(fTemp297);
			int 	iTemp299 = max(0, min(iTemp298, 499));
			float 	fTemp300 = ftbl2[iTemp299];
			int 	iTemp301 = max(0, min((iTemp298 + 1), 499));
			float 	fTemp302 = (fTemp297 - float(iTemp298));
			float 	fTemp303 = min(1.0f, (max(min((3.0f * fTemp294), 0.3f), -0.2f) + 0.15f));
			float 	fTemp304 = ftbl0[iTemp299];
			fRec0[0] = ((1.37f * ((((((fTemp293 * ((((((fTemp304 + (fTemp302 * (ftbl0[iTemp301] - fTemp304))) * (1.0f - fTemp303)) + (fTemp303 * (fTemp300 + (fTemp302 * (ftbl2[iTemp301] - fTemp300))))) * (1.0f - (fTemp295 + fSlow88))) + (0.5f * (fTemp295 * (((2.0f * fRec100) + -1.0f) + ((2.0f * fRec98) + -1.0f))))) + (fSlow88 * ((0.33f * (fTemp262 + ((fTemp260 - float(iTemp261)) * (ftbl0[max(0, min((iTemp261 + 1), 499))] - fTemp262)))) + (0.67f * (fTemp258 + ((fTemp256 - float(iTemp257)) * (ftbl0[max(0, min((iTemp257 + 1), 499))] - fTemp258)))))))) + (fTemp243 * ((((((fTemp254 + (fTemp252 * (ftbl0[iTemp251] - fTemp254))) * (1.0f - fTemp253)) + (fTemp253 * (fTemp250 + (fTemp252 * (ftbl2[iTemp251] - fTemp250))))) * (1.0f - (fTemp245 + fSlow71))) + (0.5f * (fTemp245 * (((2.0f * fRec82) + -1.0f) + ((2.0f * fRec80) + -1.0f))))) + (fSlow71 * ((0.33f * (fTemp212 + ((fTemp210 - float(iTemp211)) * (ftbl0[max(0, min((iTemp211 + 1), 499))] - fTemp212)))) + (0.67f * (fTemp208 + ((fTemp206 - float(iTemp207)) * (ftbl0[max(0, min((iTemp207 + 1), 499))] - fTemp208))))))))) + (fTemp193 * ((((((fTemp204 + (fTemp202 * (ftbl0[iTemp201] - fTemp204))) * (1.0f - fTemp203)) + (fTemp203 * (fTemp200 + (fTemp202 * (ftbl2[iTemp201] - fTemp200))))) * (1.0f - (fTemp195 + fSlow54))) + (0.5f * (fTemp195 * (((2.0f * fRec64) + -1.0f) + ((2.0f * fRec62) + -1.0f))))) + (fSlow54 * ((0.33f * (fTemp162 + ((fTemp160 - float(iTemp161)) * (ftbl0[max(0, min((iTemp161 + 1), 499))] - fTemp162)))) + (0.67f * (fTemp158 + ((fTemp156 - float(iTemp157)) * (ftbl0[max(0, min((iTemp157 + 1), 499))] - fTemp158))))))))) + (fTemp143 * ((((((fTemp154 + (fTemp152 * (ftbl0[iTemp151] - fTemp154))) * (1.0f - fTemp153)) + (fTemp153 * (fTemp150 + (fTemp152 * (ftbl2[iTemp151] - fTemp150))))) * (1.0f - (fTemp145 + fSlow37))) + (0.5f * (fTemp145 * (((2.0f * fRec46) + -1.0f) + ((2.0f * fRec44) + -1.0f))))) + (fSlow37 * ((0.33f * (fTemp112 + ((fTemp110 - float(iTemp111)) * (ftbl0[max(0, min((iTemp111 + 1), 499))] - fTemp112)))) + (0.67f * (fTemp108 + ((fTemp106 - float(iTemp107)) * (ftbl0[max(0, min((iTemp107 + 1), 499))] - fTemp108))))))))) + (fTemp93 * ((((((fTemp104 + (fTemp102 * (ftbl0[iTemp101] - fTemp104))) * (1.0f - fTemp103)) + (fTemp103 * (fTemp100 + (fTemp102 * (ftbl2[iTemp101] - fTemp100))))) * (1.0f - (fTemp95 + fSlow20))) + (0.5f * (fTemp95 * (((2.0f * fRec28) + -1.0f) + ((2.0f * fRec26) + -1.0f))))) + (fSlow20 * ((0.33f * (fTemp62 + ((fTemp60 - float(iTemp61)) * (ftbl0[max(0, min((iTemp61 + 1), 499))] - fTemp62)))) + (0.67f * (fTemp58 + ((fTemp56 - float(iTemp57)) * (ftbl0[max(0, min((iTemp57 + 1), 499))] - fTemp58))))))))) + (fTemp43 * ((((((fTemp54 + (fTemp52 * (ftbl0[iTemp51] - fTemp54))) * (1.0f - fTemp53)) + (fTemp53 * (fTemp50 + (fTemp52 * (ftbl2[iTemp51] - fTemp50))))) * (1.0f - (fTemp45 + fSlow3))) + (0.5f * (fTemp45 * (((2.0f * fRec7) + -1.0f) + ((2.0f * fRec5) + -1.0f))))) + (fSlow3 * ((0.33f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl0[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.67f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst26 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec112[1] = fRec112[0];
			fRec101[2] = fRec101[1]; fRec101[1] = fRec101[0];
			fRec103[1] = fRec103[0];
			fRec107[1] = fRec107[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			iRec109[1] = iRec109[0];
			iRec108[1] = iRec108[0];
			iVec24[1] = iVec24[0];
			iRec102[2] = iRec102[1]; iRec102[1] = iRec102[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fVec23[1] = fVec23[0];
			iRec104[1] = iRec104[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec99[1] = fRec99[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec85[1] = fRec85[0];
			fRec89[1] = fRec89[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			iRec91[1] = iRec91[0];
			iRec90[1] = iRec90[0];
			iVec20[1] = iVec20[0];
			iRec84[2] = iRec84[1]; iRec84[1] = iRec84[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fVec19[1] = fVec19[0];
			iRec86[1] = iRec86[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec81[1] = fRec81[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec65[2] = fRec65[1]; fRec65[1] = fRec65[0];
			fRec67[1] = fRec67[0];
			fRec71[1] = fRec71[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			iRec73[1] = iRec73[0];
			iRec72[1] = iRec72[0];
			iVec16[1] = iVec16[0];
			iRec66[2] = iRec66[1]; iRec66[1] = iRec66[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fVec15[1] = fVec15[0];
			iRec68[1] = iRec68[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec63[1] = fRec63[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			fRec53[1] = fRec53[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			iRec55[1] = iRec55[0];
			iRec54[1] = iRec54[0];
			iVec12[1] = iVec12[0];
			iRec48[2] = iRec48[1]; iRec48[1] = iRec48[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fVec11[1] = fVec11[0];
			iRec50[1] = iRec50[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec45[1] = fRec45[0];
			fRec43[1] = fRec43[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec35[1] = fRec35[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			iRec37[1] = iRec37[0];
			iRec36[1] = iRec36[0];
			iVec8[1] = iVec8[0];
			iRec30[2] = iRec30[1]; iRec30[1] = iRec30[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fVec7[1] = fVec7[0];
			iRec32[1] = iRec32[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec27[1] = fRec27[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec9[2] = fRec9[1]; fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			fRec16[1] = fRec16[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			iRec18[1] = iRec18[0];
			iRec17[1] = iRec17[0];
			iVec4[1] = iVec4[0];
			iRec10[2] = iRec10[1]; iRec10[1] = iRec10[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			fVec3[1] = fVec3[0];
			iRec12[1] = iRec12[0];
			iRec13[1] = iRec13[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec6[1] = fRec6[0];
			fRec4[1] = fRec4[0];
			fRec3[1] = fRec3[0];
			fRec2[1] = fRec2[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[500];
float 	mydsp::ftbl1[1000];
float 	mydsp::ftbl2[500];

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
