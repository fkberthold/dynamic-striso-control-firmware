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
	int 	iRec10[3];
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	float 	fRec16[2];
	int 	iVec4[2];
	int 	iRec17[2];
	int 	iRec18[2];
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec15[2];
	float 	fRec11[2];
	float 	fRec9[3];
	float 	fConst25;
	static float 	ftbl2[500];
	float 	fConst26;
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
	int 	iRec30[3];
	float 	fRec35[2];
	int 	iVec8[2];
	int 	iRec36[2];
	int 	iRec37[2];
	float 	fRec38[2];
	float 	fRec39[2];
	float 	fRec34[2];
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
	int 	iRec48[3];
	float 	fRec53[2];
	int 	iVec12[2];
	int 	iRec54[2];
	int 	iRec55[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec52[2];
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
	int 	iRec66[3];
	float 	fRec71[2];
	int 	iVec16[2];
	int 	iRec72[2];
	int 	iRec73[2];
	float 	fRec74[2];
	float 	fRec75[2];
	float 	fRec70[2];
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
	int 	iRec84[3];
	float 	fRec89[2];
	int 	iVec20[2];
	int 	iRec90[2];
	int 	iRec91[2];
	float 	fRec92[2];
	float 	fRec93[2];
	float 	fRec88[2];
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
	int 	iRec102[3];
	float 	fRec107[2];
	int 	iVec24[2];
	int 	iRec108[2];
	int 	iRec109[2];
	float 	fRec110[2];
	float 	fRec111[2];
	float 	fRec106[2];
	float 	fRec103[2];
	float 	fRec101[3];
	float 	fRec112[2];
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
		fConst20 = (0.3f * fConst0);
		fConst21 = (0.2f * fConst0);
		fConst22 = (0.15f * fConst0);
		fConst23 = (2.5f * fConst0);
		fConst24 = (0.05f * fConst0);
		fConst25 = (fConst14 / (fConst1 * fConst18));
		fConst26 = (8.175799f / fConst0);
		fConst27 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<3; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
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
		for (int i=0; i<3; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
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
		for (int i=0; i<3; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
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
		for (int i=0; i<3; i++) iRec66[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec72[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
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
		for (int i=0; i<3; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
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
		for (int i=0; i<3; i++) iRec102[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec108[i] = 0;
		for (int i=0; i<2; i++) iRec109[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
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
		float 	fSlow16 = (fConst26 * fSlow0);
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
		float 	fSlow33 = (fConst26 * fSlow17);
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
		float 	fSlow50 = (fConst26 * fSlow34);
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
		float 	fSlow67 = (fConst26 * fSlow51);
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
		float 	fSlow84 = (fConst26 * fSlow68);
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
		float 	fSlow101 = (fConst26 * fSlow85);
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
			int 	iTemp22 = (fVec3[0] > 0.001f);
			int 	iTemp23 = (fVec3[0] <= 0.001f);
			float 	fTemp24 = float((iTemp23 | (fVec3[1] >= 0.001f)));
			fRec14[0] = max((fRec14[1] * fTemp24), fSlow13);
			float 	fTemp25 = (2.0f * min(1.0f, (0.9f * fRec14[0])));
			int 	iTemp26 = (fRec11[1] >= min(fTemp25, 1.0f));
			int 	iTemp27 = (fVec3[0] >= fRec11[1]);
			int 	iTemp28 = (fRec11[1] <= 0.001f);
			int 	iTemp29 = (((iRec10[1] >= 4)) ? (((iRec10[1] >= 6)) ? (((iRec10[1] >= 7)) ? ((iTemp22) ? 1 : ((iTemp26) ? 2 : 7)) : ((iTemp28) ? 0 : ((iTemp22) ? 1 : 6))) : (((iRec10[1] >= 5)) ? ((iTemp23) ? 3 : ((iTemp27) ? 4 : 5)) : ((iTemp23) ? 3 : (((fVec3[0] <= fRec11[1])) ? 5 : 4)))) : (((iRec10[1] >= 2)) ? (((iRec10[1] >= 3)) ? (((iTemp23 & iTemp28)) ? 0 : ((iTemp22) ? 1 : 3)) : ((iTemp23) ? 3 : ((iTemp27) ? ((iTemp23) ? 7 : 4) : 2))) : (((iRec10[1] >= 1)) ? ((iTemp23) ? 7 : ((iTemp26) ? 2 : 1)) : ((iTemp22) ? 1 : 0))));
			iRec10[0] = iTemp29;
			fRec16[0] = max((fTemp24 * fRec16[1]), fSlow15);
			float 	fTemp30 = (((iTemp29 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec16[0]))) : (((iTemp29 >= 4)) ? (((iTemp29 >= 6)) ? (((iTemp29 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp29 >= 2)) ? (((iTemp29 >= 3)) ? fConst22 : fConst21) : (((iTemp29 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp31 = (iRec10[1] != iRec10[2]);
			iVec4[0] = iTemp31;
			int 	iTemp32 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec17[0] = ((iRec17[1] * (1 - iTemp32)) + (iTemp20 * iTemp32));
			float 	fTemp33 = min(19.0f, floorf((21.0f * (((fTemp30 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec17[0]))) / fTemp30) : 1.0f))));
			float 	fTemp34 = min((fTemp33 + 1.0f), 2e+01f);
			float 	fTemp35 = (((fTemp34 >= 11.0f)) ? (((fTemp34 >= 16.0f)) ? (((fTemp34 >= 19.0f)) ? (((fTemp34 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp34 >= 18.0f)) ? 0.03f : (((fTemp34 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp34 >= 14.0f)) ? (((fTemp34 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp34 >= 13.0f)) ? 0.14f : (((fTemp34 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp34 >= 6.0f)) ? (((fTemp34 >= 9.0f)) ? (((fTemp34 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp34 >= 8.0f)) ? 0.3f : (((fTemp34 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp34 >= 3.0f)) ? (((fTemp34 >= 5.0f)) ? 0.47f : (((fTemp34 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp34 >= 2.0f)) ? 0.74f : (((fTemp34 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec18[0] = iRec10[1];
			int 	iTemp36 = (iRec18[1] == iRec10[1]);
			int 	iTemp37 = (iRec10[1] == 0);
			fRec19[0] = ((iTemp37) ? fVec3[0] : ((iTemp36) ? min(min(fRec19[1], fVec3[0]), fRec11[1]) : min(fVec3[0], fRec11[1])));
			fRec20[0] = ((iTemp37) ? fVec3[0] : ((iTemp36) ? max(max(fRec20[1], fVec3[0]), fRec11[1]) : max(fVec3[0], fRec11[1])));
			int 	iTemp38 = ((iRec10[1] == 3) | (iRec10[1] == 6));
			float 	fTemp39 = min(1.0f, fTemp25);
			float 	fTemp40 = (((iRec10[1] == 7)) ? fTemp39 : (((iRec10[1] == 1)) ? fTemp39 : ((iTemp37) ? 0.0f : ((iTemp38) ? (fRec20[0] * fTemp35) : fVec3[0]))));
			float 	fTemp41 = (1.0f / ((iTemp37) ? 0.0001f : ((iTemp38) ? (0.05f * (fTemp30 / ((((fTemp33 >= 11.0f)) ? (((fTemp33 >= 16.0f)) ? (((fTemp33 >= 19.0f)) ? (((fTemp33 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp33 >= 18.0f)) ? 0.03f : (((fTemp33 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp33 >= 14.0f)) ? (((fTemp33 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp33 >= 13.0f)) ? 0.14f : (((fTemp33 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp33 >= 6.0f)) ? (((fTemp33 >= 9.0f)) ? (((fTemp33 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp33 >= 8.0f)) ? 0.3f : (((fTemp33 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp33 >= 3.0f)) ? (((fTemp33 >= 5.0f)) ? 0.47f : (((fTemp33 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp33 >= 2.0f)) ? 0.74f : (((fTemp33 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp35))) : fTemp30)));
			float 	fTemp42 = (fRec15[1] - fTemp41);
			float 	fTemp43 = (fRec15[1] + fTemp41);
			fRec15[0] = (((fTemp43 < fTemp40)) ? fTemp43 : (((fTemp42 > fTemp40)) ? fTemp42 : fTemp40));
			fRec11[0] = fRec15[0];
			fRec9[0] = (fRec11[0] - (fConst19 * ((fConst17 * fRec9[2]) + (fConst15 * fRec9[1]))));
			float 	fTemp44 = min(0.99f, (fConst25 * (((3947.8418f * fRec9[0]) + (7895.6836f * fRec9[1])) + (3947.8418f * fRec9[2]))));
			float 	fTemp45 = (fVec3[0] - fTemp44);
			float 	fTemp46 = min(0.8f, max(0.0f, (max(-0.75f, fTemp45) + fSlow11)));
			float 	fTemp47 = ((iTemp2) ? 0.0f : (fSlow16 + fRec22[1]));
			fRec22[0] = (fTemp47 - floorf(fTemp47));
			float 	fTemp48 = (499.0f * fRec22[0]);
			int 	iTemp49 = int(fTemp48);
			int 	iTemp50 = max(0, min(iTemp49, 499));
			float 	fTemp51 = ftbl2[iTemp50];
			int 	iTemp52 = max(0, min((iTemp49 + 1), 499));
			float 	fTemp53 = (fTemp48 - float(iTemp49));
			float 	fTemp54 = min(1.0f, (max(min((3.0f * fTemp45), 0.3f), -0.13f) + 0.15f));
			float 	fTemp55 = ftbl0[iTemp50];
			float 	fTemp56 = ((iTemp2) ? 0.0f : (fSlow18 + fRec23[1]));
			fRec23[0] = (fTemp56 - floorf(fTemp56));
			float 	fTemp57 = (499.0f * fRec23[0]);
			int 	iTemp58 = int(fTemp57);
			float 	fTemp59 = ftbl0[max(0, min(iTemp58, 499))];
			float 	fTemp60 = ((iTemp2) ? 0.0f : (fSlow19 + fRec24[1]));
			fRec24[0] = (fTemp60 - floorf(fTemp60));
			float 	fTemp61 = (499.0f * fRec24[0]);
			int 	iTemp62 = int(fTemp61);
			float 	fTemp63 = ftbl0[max(0, min(iTemp62, 499))];
			float 	fTemp64 = (fSlow22 + (fRec25[1] + -1.0f));
			float 	fTemp65 = (fSlow22 + fRec25[1]);
			int 	iTemp66 = (fTemp64 < 0.0f);
			fRec25[0] = ((iTemp66) ? fTemp65 : fTemp64);
			float 	fRec26 = ((iTemp66) ? fTemp65 : (fSlow22 + (fRec25[1] + (fSlow23 * fTemp64))));
			float 	fTemp67 = (fSlow25 + (fRec27[1] + -1.0f));
			float 	fTemp68 = (fSlow25 + fRec27[1]);
			int 	iTemp69 = (fTemp67 < 0.0f);
			fRec27[0] = ((iTemp69) ? fTemp68 : fTemp67);
			float 	fRec28 = ((iTemp69) ? fTemp68 : (fSlow25 + (fRec27[1] + (fSlow26 * fTemp67))));
			fVec5[0] = fSlow30;
			int 	iTemp70 = (fSlow30 != fVec5[1]);
			iVec6[0] = iTemp70;
			int 	iTemp71 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp71)) + (iTemp20 * iTemp71));
			float 	fTemp72 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec32[0])))) > 0.5f) & iSlow31)) ? 0.0f : fSlow29) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp72;
			int 	iTemp73 = (fVec7[0] > 0.001f);
			int 	iTemp74 = (fVec7[0] <= 0.001f);
			float 	fTemp75 = float((iTemp74 | (fVec7[1] >= 0.001f)));
			fRec33[0] = max((fRec33[1] * fTemp75), fSlow30);
			float 	fTemp76 = (2.0f * min(1.0f, (0.9f * fRec33[0])));
			int 	iTemp77 = (fRec31[1] >= min(fTemp76, 1.0f));
			int 	iTemp78 = (fVec7[0] >= fRec31[1]);
			int 	iTemp79 = (fRec31[1] <= 0.001f);
			int 	iTemp80 = (((iRec30[1] >= 4)) ? (((iRec30[1] >= 6)) ? (((iRec30[1] >= 7)) ? ((iTemp73) ? 1 : ((iTemp77) ? 2 : 7)) : ((iTemp79) ? 0 : ((iTemp73) ? 1 : 6))) : (((iRec30[1] >= 5)) ? ((iTemp74) ? 3 : ((iTemp78) ? 4 : 5)) : ((iTemp74) ? 3 : (((fVec7[0] <= fRec31[1])) ? 5 : 4)))) : (((iRec30[1] >= 2)) ? (((iRec30[1] >= 3)) ? (((iTemp74 & iTemp79)) ? 0 : ((iTemp73) ? 1 : 3)) : ((iTemp74) ? 3 : ((iTemp78) ? ((iTemp74) ? 7 : 4) : 2))) : (((iRec30[1] >= 1)) ? ((iTemp74) ? 7 : ((iTemp77) ? 2 : 1)) : ((iTemp73) ? 1 : 0))));
			iRec30[0] = iTemp80;
			fRec35[0] = max((fTemp75 * fRec35[1]), fSlow32);
			float 	fTemp81 = (((iTemp80 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec35[0]))) : (((iTemp80 >= 4)) ? (((iTemp80 >= 6)) ? (((iTemp80 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp80 >= 2)) ? (((iTemp80 >= 3)) ? fConst22 : fConst21) : (((iTemp80 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp82 = (iRec30[1] != iRec30[2]);
			iVec8[0] = iTemp82;
			int 	iTemp83 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec36[0] = ((iRec36[1] * (1 - iTemp83)) + (iTemp20 * iTemp83));
			float 	fTemp84 = min(19.0f, floorf((21.0f * (((fTemp81 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec36[0]))) / fTemp81) : 1.0f))));
			float 	fTemp85 = min((fTemp84 + 1.0f), 2e+01f);
			float 	fTemp86 = (((fTemp85 >= 11.0f)) ? (((fTemp85 >= 16.0f)) ? (((fTemp85 >= 19.0f)) ? (((fTemp85 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp85 >= 18.0f)) ? 0.03f : (((fTemp85 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp85 >= 14.0f)) ? (((fTemp85 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp85 >= 13.0f)) ? 0.14f : (((fTemp85 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp85 >= 6.0f)) ? (((fTemp85 >= 9.0f)) ? (((fTemp85 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp85 >= 8.0f)) ? 0.3f : (((fTemp85 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp85 >= 3.0f)) ? (((fTemp85 >= 5.0f)) ? 0.47f : (((fTemp85 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp85 >= 2.0f)) ? 0.74f : (((fTemp85 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec37[0] = iRec30[1];
			int 	iTemp87 = (iRec37[1] == iRec30[1]);
			int 	iTemp88 = (iRec30[1] == 0);
			fRec38[0] = ((iTemp88) ? fVec7[0] : ((iTemp87) ? min(min(fRec38[1], fVec7[0]), fRec31[1]) : min(fVec7[0], fRec31[1])));
			fRec39[0] = ((iTemp88) ? fVec7[0] : ((iTemp87) ? max(max(fRec39[1], fVec7[0]), fRec31[1]) : max(fVec7[0], fRec31[1])));
			int 	iTemp89 = ((iRec30[1] == 3) | (iRec30[1] == 6));
			float 	fTemp90 = min(1.0f, fTemp76);
			float 	fTemp91 = (((iRec30[1] == 7)) ? fTemp90 : (((iRec30[1] == 1)) ? fTemp90 : ((iTemp88) ? 0.0f : ((iTemp89) ? (fRec39[0] * fTemp86) : fVec7[0]))));
			float 	fTemp92 = (1.0f / ((iTemp88) ? 0.0001f : ((iTemp89) ? (0.05f * (fTemp81 / ((((fTemp84 >= 11.0f)) ? (((fTemp84 >= 16.0f)) ? (((fTemp84 >= 19.0f)) ? (((fTemp84 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp84 >= 18.0f)) ? 0.03f : (((fTemp84 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp84 >= 14.0f)) ? (((fTemp84 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp84 >= 13.0f)) ? 0.14f : (((fTemp84 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp84 >= 6.0f)) ? (((fTemp84 >= 9.0f)) ? (((fTemp84 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp84 >= 8.0f)) ? 0.3f : (((fTemp84 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp84 >= 3.0f)) ? (((fTemp84 >= 5.0f)) ? 0.47f : (((fTemp84 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp84 >= 2.0f)) ? 0.74f : (((fTemp84 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp86))) : fTemp81)));
			float 	fTemp93 = (fRec34[1] - fTemp92);
			float 	fTemp94 = (fRec34[1] + fTemp92);
			fRec34[0] = (((fTemp94 < fTemp91)) ? fTemp94 : (((fTemp93 > fTemp91)) ? fTemp93 : fTemp91));
			fRec31[0] = fRec34[0];
			fRec29[0] = (fRec31[0] - (fConst19 * ((fConst17 * fRec29[2]) + (fConst15 * fRec29[1]))));
			float 	fTemp95 = min(0.99f, (fConst25 * (((3947.8418f * fRec29[0]) + (7895.6836f * fRec29[1])) + (3947.8418f * fRec29[2]))));
			float 	fTemp96 = (fVec7[0] - fTemp95);
			float 	fTemp97 = min(0.8f, max(0.0f, (max(-0.75f, fTemp96) + fSlow28)));
			float 	fTemp98 = ((iTemp2) ? 0.0f : (fSlow33 + fRec40[1]));
			fRec40[0] = (fTemp98 - floorf(fTemp98));
			float 	fTemp99 = (499.0f * fRec40[0]);
			int 	iTemp100 = int(fTemp99);
			int 	iTemp101 = max(0, min(iTemp100, 499));
			float 	fTemp102 = ftbl2[iTemp101];
			int 	iTemp103 = max(0, min((iTemp100 + 1), 499));
			float 	fTemp104 = (fTemp99 - float(iTemp100));
			float 	fTemp105 = min(1.0f, (max(min((3.0f * fTemp96), 0.3f), -0.13f) + 0.15f));
			float 	fTemp106 = ftbl0[iTemp101];
			float 	fTemp107 = ((iTemp2) ? 0.0f : (fSlow35 + fRec41[1]));
			fRec41[0] = (fTemp107 - floorf(fTemp107));
			float 	fTemp108 = (499.0f * fRec41[0]);
			int 	iTemp109 = int(fTemp108);
			float 	fTemp110 = ftbl0[max(0, min(iTemp109, 499))];
			float 	fTemp111 = ((iTemp2) ? 0.0f : (fSlow36 + fRec42[1]));
			fRec42[0] = (fTemp111 - floorf(fTemp111));
			float 	fTemp112 = (499.0f * fRec42[0]);
			int 	iTemp113 = int(fTemp112);
			float 	fTemp114 = ftbl0[max(0, min(iTemp113, 499))];
			float 	fTemp115 = (fSlow39 + (fRec43[1] + -1.0f));
			float 	fTemp116 = (fSlow39 + fRec43[1]);
			int 	iTemp117 = (fTemp115 < 0.0f);
			fRec43[0] = ((iTemp117) ? fTemp116 : fTemp115);
			float 	fRec44 = ((iTemp117) ? fTemp116 : (fSlow39 + (fRec43[1] + (fSlow40 * fTemp115))));
			float 	fTemp118 = (fSlow42 + (fRec45[1] + -1.0f));
			float 	fTemp119 = (fSlow42 + fRec45[1]);
			int 	iTemp120 = (fTemp118 < 0.0f);
			fRec45[0] = ((iTemp120) ? fTemp119 : fTemp118);
			float 	fRec46 = ((iTemp120) ? fTemp119 : (fSlow42 + (fRec45[1] + (fSlow43 * fTemp118))));
			fVec9[0] = fSlow47;
			int 	iTemp121 = (fSlow47 != fVec9[1]);
			iVec10[0] = iTemp121;
			int 	iTemp122 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec50[0] = ((iRec50[1] * (1 - iTemp122)) + (iTemp20 * iTemp122));
			float 	fTemp123 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec50[0])))) > 0.5f) & iSlow48)) ? 0.0f : fSlow46) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp123;
			int 	iTemp124 = (fVec11[0] > 0.001f);
			int 	iTemp125 = (fVec11[0] <= 0.001f);
			float 	fTemp126 = float((iTemp125 | (fVec11[1] >= 0.001f)));
			fRec51[0] = max((fRec51[1] * fTemp126), fSlow47);
			float 	fTemp127 = (2.0f * min(1.0f, (0.9f * fRec51[0])));
			int 	iTemp128 = (fRec49[1] >= min(fTemp127, 1.0f));
			int 	iTemp129 = (fVec11[0] >= fRec49[1]);
			int 	iTemp130 = (fRec49[1] <= 0.001f);
			int 	iTemp131 = (((iRec48[1] >= 4)) ? (((iRec48[1] >= 6)) ? (((iRec48[1] >= 7)) ? ((iTemp124) ? 1 : ((iTemp128) ? 2 : 7)) : ((iTemp130) ? 0 : ((iTemp124) ? 1 : 6))) : (((iRec48[1] >= 5)) ? ((iTemp125) ? 3 : ((iTemp129) ? 4 : 5)) : ((iTemp125) ? 3 : (((fVec11[0] <= fRec49[1])) ? 5 : 4)))) : (((iRec48[1] >= 2)) ? (((iRec48[1] >= 3)) ? (((iTemp125 & iTemp130)) ? 0 : ((iTemp124) ? 1 : 3)) : ((iTemp125) ? 3 : ((iTemp129) ? ((iTemp125) ? 7 : 4) : 2))) : (((iRec48[1] >= 1)) ? ((iTemp125) ? 7 : ((iTemp128) ? 2 : 1)) : ((iTemp124) ? 1 : 0))));
			iRec48[0] = iTemp131;
			fRec53[0] = max((fTemp126 * fRec53[1]), fSlow49);
			float 	fTemp132 = (((iTemp131 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec53[0]))) : (((iTemp131 >= 4)) ? (((iTemp131 >= 6)) ? (((iTemp131 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp131 >= 2)) ? (((iTemp131 >= 3)) ? fConst22 : fConst21) : (((iTemp131 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp133 = (iRec48[1] != iRec48[2]);
			iVec12[0] = iTemp133;
			int 	iTemp134 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec54[0] = ((iRec54[1] * (1 - iTemp134)) + (iTemp20 * iTemp134));
			float 	fTemp135 = min(19.0f, floorf((21.0f * (((fTemp132 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec54[0]))) / fTemp132) : 1.0f))));
			float 	fTemp136 = min((fTemp135 + 1.0f), 2e+01f);
			float 	fTemp137 = (((fTemp136 >= 11.0f)) ? (((fTemp136 >= 16.0f)) ? (((fTemp136 >= 19.0f)) ? (((fTemp136 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp136 >= 18.0f)) ? 0.03f : (((fTemp136 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp136 >= 14.0f)) ? (((fTemp136 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp136 >= 13.0f)) ? 0.14f : (((fTemp136 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp136 >= 6.0f)) ? (((fTemp136 >= 9.0f)) ? (((fTemp136 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp136 >= 8.0f)) ? 0.3f : (((fTemp136 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp136 >= 3.0f)) ? (((fTemp136 >= 5.0f)) ? 0.47f : (((fTemp136 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp136 >= 2.0f)) ? 0.74f : (((fTemp136 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec55[0] = iRec48[1];
			int 	iTemp138 = (iRec55[1] == iRec48[1]);
			int 	iTemp139 = (iRec48[1] == 0);
			fRec56[0] = ((iTemp139) ? fVec11[0] : ((iTemp138) ? min(min(fRec56[1], fVec11[0]), fRec49[1]) : min(fVec11[0], fRec49[1])));
			fRec57[0] = ((iTemp139) ? fVec11[0] : ((iTemp138) ? max(max(fRec57[1], fVec11[0]), fRec49[1]) : max(fVec11[0], fRec49[1])));
			int 	iTemp140 = ((iRec48[1] == 3) | (iRec48[1] == 6));
			float 	fTemp141 = min(1.0f, fTemp127);
			float 	fTemp142 = (((iRec48[1] == 7)) ? fTemp141 : (((iRec48[1] == 1)) ? fTemp141 : ((iTemp139) ? 0.0f : ((iTemp140) ? (fRec57[0] * fTemp137) : fVec11[0]))));
			float 	fTemp143 = (1.0f / ((iTemp139) ? 0.0001f : ((iTemp140) ? (0.05f * (fTemp132 / ((((fTemp135 >= 11.0f)) ? (((fTemp135 >= 16.0f)) ? (((fTemp135 >= 19.0f)) ? (((fTemp135 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp135 >= 18.0f)) ? 0.03f : (((fTemp135 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp135 >= 14.0f)) ? (((fTemp135 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp135 >= 13.0f)) ? 0.14f : (((fTemp135 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp135 >= 6.0f)) ? (((fTemp135 >= 9.0f)) ? (((fTemp135 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp135 >= 8.0f)) ? 0.3f : (((fTemp135 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp135 >= 3.0f)) ? (((fTemp135 >= 5.0f)) ? 0.47f : (((fTemp135 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp135 >= 2.0f)) ? 0.74f : (((fTemp135 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp137))) : fTemp132)));
			float 	fTemp144 = (fRec52[1] - fTemp143);
			float 	fTemp145 = (fRec52[1] + fTemp143);
			fRec52[0] = (((fTemp145 < fTemp142)) ? fTemp145 : (((fTemp144 > fTemp142)) ? fTemp144 : fTemp142));
			fRec49[0] = fRec52[0];
			fRec47[0] = (fRec49[0] - (fConst19 * ((fConst17 * fRec47[2]) + (fConst15 * fRec47[1]))));
			float 	fTemp146 = min(0.99f, (fConst25 * (((3947.8418f * fRec47[0]) + (7895.6836f * fRec47[1])) + (3947.8418f * fRec47[2]))));
			float 	fTemp147 = (fVec11[0] - fTemp146);
			float 	fTemp148 = min(0.8f, max(0.0f, (max(-0.75f, fTemp147) + fSlow45)));
			float 	fTemp149 = ((iTemp2) ? 0.0f : (fSlow50 + fRec58[1]));
			fRec58[0] = (fTemp149 - floorf(fTemp149));
			float 	fTemp150 = (499.0f * fRec58[0]);
			int 	iTemp151 = int(fTemp150);
			int 	iTemp152 = max(0, min(iTemp151, 499));
			float 	fTemp153 = ftbl2[iTemp152];
			int 	iTemp154 = max(0, min((iTemp151 + 1), 499));
			float 	fTemp155 = (fTemp150 - float(iTemp151));
			float 	fTemp156 = min(1.0f, (max(min((3.0f * fTemp147), 0.3f), -0.13f) + 0.15f));
			float 	fTemp157 = ftbl0[iTemp152];
			float 	fTemp158 = ((iTemp2) ? 0.0f : (fSlow52 + fRec59[1]));
			fRec59[0] = (fTemp158 - floorf(fTemp158));
			float 	fTemp159 = (499.0f * fRec59[0]);
			int 	iTemp160 = int(fTemp159);
			float 	fTemp161 = ftbl0[max(0, min(iTemp160, 499))];
			float 	fTemp162 = ((iTemp2) ? 0.0f : (fSlow53 + fRec60[1]));
			fRec60[0] = (fTemp162 - floorf(fTemp162));
			float 	fTemp163 = (499.0f * fRec60[0]);
			int 	iTemp164 = int(fTemp163);
			float 	fTemp165 = ftbl0[max(0, min(iTemp164, 499))];
			float 	fTemp166 = (fSlow56 + (fRec61[1] + -1.0f));
			float 	fTemp167 = (fSlow56 + fRec61[1]);
			int 	iTemp168 = (fTemp166 < 0.0f);
			fRec61[0] = ((iTemp168) ? fTemp167 : fTemp166);
			float 	fRec62 = ((iTemp168) ? fTemp167 : (fSlow56 + (fRec61[1] + (fSlow57 * fTemp166))));
			float 	fTemp169 = (fSlow59 + (fRec63[1] + -1.0f));
			float 	fTemp170 = (fSlow59 + fRec63[1]);
			int 	iTemp171 = (fTemp169 < 0.0f);
			fRec63[0] = ((iTemp171) ? fTemp170 : fTemp169);
			float 	fRec64 = ((iTemp171) ? fTemp170 : (fSlow59 + (fRec63[1] + (fSlow60 * fTemp169))));
			fVec13[0] = fSlow64;
			int 	iTemp172 = (fSlow64 != fVec13[1]);
			iVec14[0] = iTemp172;
			int 	iTemp173 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec68[0] = ((iRec68[1] * (1 - iTemp173)) + (iTemp20 * iTemp173));
			float 	fTemp174 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec68[0])))) > 0.5f) & iSlow65)) ? 0.0f : fSlow63) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp174;
			int 	iTemp175 = (fVec15[0] > 0.001f);
			int 	iTemp176 = (fVec15[0] <= 0.001f);
			float 	fTemp177 = float((iTemp176 | (fVec15[1] >= 0.001f)));
			fRec69[0] = max((fRec69[1] * fTemp177), fSlow64);
			float 	fTemp178 = (2.0f * min(1.0f, (0.9f * fRec69[0])));
			int 	iTemp179 = (fRec67[1] >= min(fTemp178, 1.0f));
			int 	iTemp180 = (fVec15[0] >= fRec67[1]);
			int 	iTemp181 = (fRec67[1] <= 0.001f);
			int 	iTemp182 = (((iRec66[1] >= 4)) ? (((iRec66[1] >= 6)) ? (((iRec66[1] >= 7)) ? ((iTemp175) ? 1 : ((iTemp179) ? 2 : 7)) : ((iTemp181) ? 0 : ((iTemp175) ? 1 : 6))) : (((iRec66[1] >= 5)) ? ((iTemp176) ? 3 : ((iTemp180) ? 4 : 5)) : ((iTemp176) ? 3 : (((fVec15[0] <= fRec67[1])) ? 5 : 4)))) : (((iRec66[1] >= 2)) ? (((iRec66[1] >= 3)) ? (((iTemp176 & iTemp181)) ? 0 : ((iTemp175) ? 1 : 3)) : ((iTemp176) ? 3 : ((iTemp180) ? ((iTemp176) ? 7 : 4) : 2))) : (((iRec66[1] >= 1)) ? ((iTemp176) ? 7 : ((iTemp179) ? 2 : 1)) : ((iTemp175) ? 1 : 0))));
			iRec66[0] = iTemp182;
			fRec71[0] = max((fTemp177 * fRec71[1]), fSlow66);
			float 	fTemp183 = (((iTemp182 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec71[0]))) : (((iTemp182 >= 4)) ? (((iTemp182 >= 6)) ? (((iTemp182 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp182 >= 2)) ? (((iTemp182 >= 3)) ? fConst22 : fConst21) : (((iTemp182 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp184 = (iRec66[1] != iRec66[2]);
			iVec16[0] = iTemp184;
			int 	iTemp185 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec72[0] = ((iRec72[1] * (1 - iTemp185)) + (iTemp20 * iTemp185));
			float 	fTemp186 = min(19.0f, floorf((21.0f * (((fTemp183 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec72[0]))) / fTemp183) : 1.0f))));
			float 	fTemp187 = min((fTemp186 + 1.0f), 2e+01f);
			float 	fTemp188 = (((fTemp187 >= 11.0f)) ? (((fTemp187 >= 16.0f)) ? (((fTemp187 >= 19.0f)) ? (((fTemp187 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp187 >= 18.0f)) ? 0.03f : (((fTemp187 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp187 >= 14.0f)) ? (((fTemp187 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp187 >= 13.0f)) ? 0.14f : (((fTemp187 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp187 >= 6.0f)) ? (((fTemp187 >= 9.0f)) ? (((fTemp187 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp187 >= 8.0f)) ? 0.3f : (((fTemp187 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp187 >= 3.0f)) ? (((fTemp187 >= 5.0f)) ? 0.47f : (((fTemp187 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp187 >= 2.0f)) ? 0.74f : (((fTemp187 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec73[0] = iRec66[1];
			int 	iTemp189 = (iRec73[1] == iRec66[1]);
			int 	iTemp190 = (iRec66[1] == 0);
			fRec74[0] = ((iTemp190) ? fVec15[0] : ((iTemp189) ? min(min(fRec74[1], fVec15[0]), fRec67[1]) : min(fVec15[0], fRec67[1])));
			fRec75[0] = ((iTemp190) ? fVec15[0] : ((iTemp189) ? max(max(fRec75[1], fVec15[0]), fRec67[1]) : max(fVec15[0], fRec67[1])));
			int 	iTemp191 = ((iRec66[1] == 3) | (iRec66[1] == 6));
			float 	fTemp192 = min(1.0f, fTemp178);
			float 	fTemp193 = (((iRec66[1] == 7)) ? fTemp192 : (((iRec66[1] == 1)) ? fTemp192 : ((iTemp190) ? 0.0f : ((iTemp191) ? (fRec75[0] * fTemp188) : fVec15[0]))));
			float 	fTemp194 = (1.0f / ((iTemp190) ? 0.0001f : ((iTemp191) ? (0.05f * (fTemp183 / ((((fTemp186 >= 11.0f)) ? (((fTemp186 >= 16.0f)) ? (((fTemp186 >= 19.0f)) ? (((fTemp186 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp186 >= 18.0f)) ? 0.03f : (((fTemp186 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp186 >= 14.0f)) ? (((fTemp186 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp186 >= 13.0f)) ? 0.14f : (((fTemp186 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp186 >= 6.0f)) ? (((fTemp186 >= 9.0f)) ? (((fTemp186 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp186 >= 8.0f)) ? 0.3f : (((fTemp186 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp186 >= 3.0f)) ? (((fTemp186 >= 5.0f)) ? 0.47f : (((fTemp186 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp186 >= 2.0f)) ? 0.74f : (((fTemp186 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp188))) : fTemp183)));
			float 	fTemp195 = (fRec70[1] - fTemp194);
			float 	fTemp196 = (fRec70[1] + fTemp194);
			fRec70[0] = (((fTemp196 < fTemp193)) ? fTemp196 : (((fTemp195 > fTemp193)) ? fTemp195 : fTemp193));
			fRec67[0] = fRec70[0];
			fRec65[0] = (fRec67[0] - (fConst19 * ((fConst17 * fRec65[2]) + (fConst15 * fRec65[1]))));
			float 	fTemp197 = min(0.99f, (fConst25 * (((3947.8418f * fRec65[0]) + (7895.6836f * fRec65[1])) + (3947.8418f * fRec65[2]))));
			float 	fTemp198 = (fVec15[0] - fTemp197);
			float 	fTemp199 = min(0.8f, max(0.0f, (max(-0.75f, fTemp198) + fSlow62)));
			float 	fTemp200 = ((iTemp2) ? 0.0f : (fSlow67 + fRec76[1]));
			fRec76[0] = (fTemp200 - floorf(fTemp200));
			float 	fTemp201 = (499.0f * fRec76[0]);
			int 	iTemp202 = int(fTemp201);
			int 	iTemp203 = max(0, min(iTemp202, 499));
			float 	fTemp204 = ftbl2[iTemp203];
			int 	iTemp205 = max(0, min((iTemp202 + 1), 499));
			float 	fTemp206 = (fTemp201 - float(iTemp202));
			float 	fTemp207 = min(1.0f, (max(min((3.0f * fTemp198), 0.3f), -0.13f) + 0.15f));
			float 	fTemp208 = ftbl0[iTemp203];
			float 	fTemp209 = ((iTemp2) ? 0.0f : (fSlow69 + fRec77[1]));
			fRec77[0] = (fTemp209 - floorf(fTemp209));
			float 	fTemp210 = (499.0f * fRec77[0]);
			int 	iTemp211 = int(fTemp210);
			float 	fTemp212 = ftbl0[max(0, min(iTemp211, 499))];
			float 	fTemp213 = ((iTemp2) ? 0.0f : (fSlow70 + fRec78[1]));
			fRec78[0] = (fTemp213 - floorf(fTemp213));
			float 	fTemp214 = (499.0f * fRec78[0]);
			int 	iTemp215 = int(fTemp214);
			float 	fTemp216 = ftbl0[max(0, min(iTemp215, 499))];
			float 	fTemp217 = (fSlow73 + (fRec79[1] + -1.0f));
			float 	fTemp218 = (fSlow73 + fRec79[1]);
			int 	iTemp219 = (fTemp217 < 0.0f);
			fRec79[0] = ((iTemp219) ? fTemp218 : fTemp217);
			float 	fRec80 = ((iTemp219) ? fTemp218 : (fSlow73 + (fRec79[1] + (fSlow74 * fTemp217))));
			float 	fTemp220 = (fSlow76 + (fRec81[1] + -1.0f));
			float 	fTemp221 = (fSlow76 + fRec81[1]);
			int 	iTemp222 = (fTemp220 < 0.0f);
			fRec81[0] = ((iTemp222) ? fTemp221 : fTemp220);
			float 	fRec82 = ((iTemp222) ? fTemp221 : (fSlow76 + (fRec81[1] + (fSlow77 * fTemp220))));
			fVec17[0] = fSlow81;
			int 	iTemp223 = (fSlow81 != fVec17[1]);
			iVec18[0] = iTemp223;
			int 	iTemp224 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp224)) + (iTemp20 * iTemp224));
			float 	fTemp225 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec86[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp225;
			int 	iTemp226 = (fVec19[0] > 0.001f);
			int 	iTemp227 = (fVec19[0] <= 0.001f);
			float 	fTemp228 = float((iTemp227 | (fVec19[1] >= 0.001f)));
			fRec87[0] = max((fRec87[1] * fTemp228), fSlow81);
			float 	fTemp229 = (2.0f * min(1.0f, (0.9f * fRec87[0])));
			int 	iTemp230 = (fRec85[1] >= min(fTemp229, 1.0f));
			int 	iTemp231 = (fVec19[0] >= fRec85[1]);
			int 	iTemp232 = (fRec85[1] <= 0.001f);
			int 	iTemp233 = (((iRec84[1] >= 4)) ? (((iRec84[1] >= 6)) ? (((iRec84[1] >= 7)) ? ((iTemp226) ? 1 : ((iTemp230) ? 2 : 7)) : ((iTemp232) ? 0 : ((iTemp226) ? 1 : 6))) : (((iRec84[1] >= 5)) ? ((iTemp227) ? 3 : ((iTemp231) ? 4 : 5)) : ((iTemp227) ? 3 : (((fVec19[0] <= fRec85[1])) ? 5 : 4)))) : (((iRec84[1] >= 2)) ? (((iRec84[1] >= 3)) ? (((iTemp227 & iTemp232)) ? 0 : ((iTemp226) ? 1 : 3)) : ((iTemp227) ? 3 : ((iTemp231) ? ((iTemp227) ? 7 : 4) : 2))) : (((iRec84[1] >= 1)) ? ((iTemp227) ? 7 : ((iTemp230) ? 2 : 1)) : ((iTemp226) ? 1 : 0))));
			iRec84[0] = iTemp233;
			fRec89[0] = max((fTemp228 * fRec89[1]), fSlow83);
			float 	fTemp234 = (((iTemp233 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec89[0]))) : (((iTemp233 >= 4)) ? (((iTemp233 >= 6)) ? (((iTemp233 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp233 >= 2)) ? (((iTemp233 >= 3)) ? fConst22 : fConst21) : (((iTemp233 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp235 = (iRec84[1] != iRec84[2]);
			iVec20[0] = iTemp235;
			int 	iTemp236 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp236)) + (iTemp20 * iTemp236));
			float 	fTemp237 = min(19.0f, floorf((21.0f * (((fTemp234 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec90[0]))) / fTemp234) : 1.0f))));
			float 	fTemp238 = min((fTemp237 + 1.0f), 2e+01f);
			float 	fTemp239 = (((fTemp238 >= 11.0f)) ? (((fTemp238 >= 16.0f)) ? (((fTemp238 >= 19.0f)) ? (((fTemp238 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp238 >= 18.0f)) ? 0.03f : (((fTemp238 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp238 >= 14.0f)) ? (((fTemp238 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp238 >= 13.0f)) ? 0.14f : (((fTemp238 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp238 >= 6.0f)) ? (((fTemp238 >= 9.0f)) ? (((fTemp238 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp238 >= 8.0f)) ? 0.3f : (((fTemp238 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp238 >= 3.0f)) ? (((fTemp238 >= 5.0f)) ? 0.47f : (((fTemp238 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp238 >= 2.0f)) ? 0.74f : (((fTemp238 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec91[0] = iRec84[1];
			int 	iTemp240 = (iRec91[1] == iRec84[1]);
			int 	iTemp241 = (iRec84[1] == 0);
			fRec92[0] = ((iTemp241) ? fVec19[0] : ((iTemp240) ? min(min(fRec92[1], fVec19[0]), fRec85[1]) : min(fVec19[0], fRec85[1])));
			fRec93[0] = ((iTemp241) ? fVec19[0] : ((iTemp240) ? max(max(fRec93[1], fVec19[0]), fRec85[1]) : max(fVec19[0], fRec85[1])));
			int 	iTemp242 = ((iRec84[1] == 3) | (iRec84[1] == 6));
			float 	fTemp243 = min(1.0f, fTemp229);
			float 	fTemp244 = (((iRec84[1] == 7)) ? fTemp243 : (((iRec84[1] == 1)) ? fTemp243 : ((iTemp241) ? 0.0f : ((iTemp242) ? (fRec93[0] * fTemp239) : fVec19[0]))));
			float 	fTemp245 = (1.0f / ((iTemp241) ? 0.0001f : ((iTemp242) ? (0.05f * (fTemp234 / ((((fTemp237 >= 11.0f)) ? (((fTemp237 >= 16.0f)) ? (((fTemp237 >= 19.0f)) ? (((fTemp237 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp237 >= 18.0f)) ? 0.03f : (((fTemp237 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp237 >= 14.0f)) ? (((fTemp237 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp237 >= 13.0f)) ? 0.14f : (((fTemp237 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp237 >= 6.0f)) ? (((fTemp237 >= 9.0f)) ? (((fTemp237 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp237 >= 8.0f)) ? 0.3f : (((fTemp237 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp237 >= 3.0f)) ? (((fTemp237 >= 5.0f)) ? 0.47f : (((fTemp237 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp237 >= 2.0f)) ? 0.74f : (((fTemp237 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp239))) : fTemp234)));
			float 	fTemp246 = (fRec88[1] - fTemp245);
			float 	fTemp247 = (fRec88[1] + fTemp245);
			fRec88[0] = (((fTemp247 < fTemp244)) ? fTemp247 : (((fTemp246 > fTemp244)) ? fTemp246 : fTemp244));
			fRec85[0] = fRec88[0];
			fRec83[0] = (fRec85[0] - (fConst19 * ((fConst17 * fRec83[2]) + (fConst15 * fRec83[1]))));
			float 	fTemp248 = min(0.99f, (fConst25 * (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]))));
			float 	fTemp249 = (fVec19[0] - fTemp248);
			float 	fTemp250 = min(0.8f, max(0.0f, (max(-0.75f, fTemp249) + fSlow79)));
			float 	fTemp251 = ((iTemp2) ? 0.0f : (fSlow84 + fRec94[1]));
			fRec94[0] = (fTemp251 - floorf(fTemp251));
			float 	fTemp252 = (499.0f * fRec94[0]);
			int 	iTemp253 = int(fTemp252);
			int 	iTemp254 = max(0, min(iTemp253, 499));
			float 	fTemp255 = ftbl2[iTemp254];
			int 	iTemp256 = max(0, min((iTemp253 + 1), 499));
			float 	fTemp257 = (fTemp252 - float(iTemp253));
			float 	fTemp258 = min(1.0f, (max(min((3.0f * fTemp249), 0.3f), -0.13f) + 0.15f));
			float 	fTemp259 = ftbl0[iTemp254];
			float 	fTemp260 = ((iTemp2) ? 0.0f : (fSlow86 + fRec95[1]));
			fRec95[0] = (fTemp260 - floorf(fTemp260));
			float 	fTemp261 = (499.0f * fRec95[0]);
			int 	iTemp262 = int(fTemp261);
			float 	fTemp263 = ftbl0[max(0, min(iTemp262, 499))];
			float 	fTemp264 = ((iTemp2) ? 0.0f : (fSlow87 + fRec96[1]));
			fRec96[0] = (fTemp264 - floorf(fTemp264));
			float 	fTemp265 = (499.0f * fRec96[0]);
			int 	iTemp266 = int(fTemp265);
			float 	fTemp267 = ftbl0[max(0, min(iTemp266, 499))];
			float 	fTemp268 = (fSlow90 + (fRec97[1] + -1.0f));
			float 	fTemp269 = (fSlow90 + fRec97[1]);
			int 	iTemp270 = (fTemp268 < 0.0f);
			fRec97[0] = ((iTemp270) ? fTemp269 : fTemp268);
			float 	fRec98 = ((iTemp270) ? fTemp269 : (fSlow90 + (fRec97[1] + (fSlow91 * fTemp268))));
			float 	fTemp271 = (fSlow93 + (fRec99[1] + -1.0f));
			float 	fTemp272 = (fSlow93 + fRec99[1]);
			int 	iTemp273 = (fTemp271 < 0.0f);
			fRec99[0] = ((iTemp273) ? fTemp272 : fTemp271);
			float 	fRec100 = ((iTemp273) ? fTemp272 : (fSlow93 + (fRec99[1] + (fSlow94 * fTemp271))));
			fVec21[0] = fSlow98;
			int 	iTemp274 = (fSlow98 != fVec21[1]);
			iVec22[0] = iTemp274;
			int 	iTemp275 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec104[0] = ((iRec104[1] * (1 - iTemp275)) + (iTemp20 * iTemp275));
			float 	fTemp276 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec104[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp276;
			int 	iTemp277 = (fVec23[0] > 0.001f);
			int 	iTemp278 = (fVec23[0] <= 0.001f);
			float 	fTemp279 = float((iTemp278 | (fVec23[1] >= 0.001f)));
			fRec105[0] = max((fRec105[1] * fTemp279), fSlow98);
			float 	fTemp280 = (2.0f * min(1.0f, (0.9f * fRec105[0])));
			int 	iTemp281 = (fRec103[1] >= min(fTemp280, 1.0f));
			int 	iTemp282 = (fVec23[0] >= fRec103[1]);
			int 	iTemp283 = (fRec103[1] <= 0.001f);
			int 	iTemp284 = (((iRec102[1] >= 4)) ? (((iRec102[1] >= 6)) ? (((iRec102[1] >= 7)) ? ((iTemp277) ? 1 : ((iTemp281) ? 2 : 7)) : ((iTemp283) ? 0 : ((iTemp277) ? 1 : 6))) : (((iRec102[1] >= 5)) ? ((iTemp278) ? 3 : ((iTemp282) ? 4 : 5)) : ((iTemp278) ? 3 : (((fVec23[0] <= fRec103[1])) ? 5 : 4)))) : (((iRec102[1] >= 2)) ? (((iRec102[1] >= 3)) ? (((iTemp278 & iTemp283)) ? 0 : ((iTemp277) ? 1 : 3)) : ((iTemp278) ? 3 : ((iTemp282) ? ((iTemp278) ? 7 : 4) : 2))) : (((iRec102[1] >= 1)) ? ((iTemp278) ? 7 : ((iTemp281) ? 2 : 1)) : ((iTemp277) ? 1 : 0))));
			iRec102[0] = iTemp284;
			fRec107[0] = max((fTemp279 * fRec107[1]), fSlow100);
			float 	fTemp285 = (((iTemp284 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec107[0]))) : (((iTemp284 >= 4)) ? (((iTemp284 >= 6)) ? (((iTemp284 >= 7)) ? fConst24 : fConst23) : fConst21) : (((iTemp284 >= 2)) ? (((iTemp284 >= 3)) ? fConst22 : fConst21) : (((iTemp284 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp286 = (iRec102[1] != iRec102[2]);
			iVec24[0] = iTemp286;
			int 	iTemp287 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec108[0] = ((iRec108[1] * (1 - iTemp287)) + (iTemp20 * iTemp287));
			float 	fTemp288 = min(19.0f, floorf((21.0f * (((fTemp285 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec108[0]))) / fTemp285) : 1.0f))));
			float 	fTemp289 = min((fTemp288 + 1.0f), 2e+01f);
			float 	fTemp290 = (((fTemp289 >= 11.0f)) ? (((fTemp289 >= 16.0f)) ? (((fTemp289 >= 19.0f)) ? (((fTemp289 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp289 >= 18.0f)) ? 0.03f : (((fTemp289 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp289 >= 14.0f)) ? (((fTemp289 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp289 >= 13.0f)) ? 0.14f : (((fTemp289 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp289 >= 6.0f)) ? (((fTemp289 >= 9.0f)) ? (((fTemp289 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp289 >= 8.0f)) ? 0.3f : (((fTemp289 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp289 >= 3.0f)) ? (((fTemp289 >= 5.0f)) ? 0.47f : (((fTemp289 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp289 >= 2.0f)) ? 0.74f : (((fTemp289 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec109[0] = iRec102[1];
			int 	iTemp291 = (iRec109[1] == iRec102[1]);
			int 	iTemp292 = (iRec102[1] == 0);
			fRec110[0] = ((iTemp292) ? fVec23[0] : ((iTemp291) ? min(min(fRec110[1], fVec23[0]), fRec103[1]) : min(fVec23[0], fRec103[1])));
			fRec111[0] = ((iTemp292) ? fVec23[0] : ((iTemp291) ? max(max(fRec111[1], fVec23[0]), fRec103[1]) : max(fVec23[0], fRec103[1])));
			int 	iTemp293 = ((iRec102[1] == 3) | (iRec102[1] == 6));
			float 	fTemp294 = min(1.0f, fTemp280);
			float 	fTemp295 = (((iRec102[1] == 7)) ? fTemp294 : (((iRec102[1] == 1)) ? fTemp294 : ((iTemp292) ? 0.0f : ((iTemp293) ? (fRec111[0] * fTemp290) : fVec23[0]))));
			float 	fTemp296 = (1.0f / ((iTemp292) ? 0.0001f : ((iTemp293) ? (0.05f * (fTemp285 / ((((fTemp288 >= 11.0f)) ? (((fTemp288 >= 16.0f)) ? (((fTemp288 >= 19.0f)) ? (((fTemp288 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp288 >= 18.0f)) ? 0.03f : (((fTemp288 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp288 >= 14.0f)) ? (((fTemp288 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp288 >= 13.0f)) ? 0.14f : (((fTemp288 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp288 >= 6.0f)) ? (((fTemp288 >= 9.0f)) ? (((fTemp288 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp288 >= 8.0f)) ? 0.3f : (((fTemp288 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp288 >= 3.0f)) ? (((fTemp288 >= 5.0f)) ? 0.47f : (((fTemp288 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp288 >= 2.0f)) ? 0.74f : (((fTemp288 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp290))) : fTemp285)));
			float 	fTemp297 = (fRec106[1] - fTemp296);
			float 	fTemp298 = (fRec106[1] + fTemp296);
			fRec106[0] = (((fTemp298 < fTemp295)) ? fTemp298 : (((fTemp297 > fTemp295)) ? fTemp297 : fTemp295));
			fRec103[0] = fRec106[0];
			fRec101[0] = (fRec103[0] - (fConst19 * ((fConst17 * fRec101[2]) + (fConst15 * fRec101[1]))));
			float 	fTemp299 = min(0.99f, (fConst25 * (((3947.8418f * fRec101[0]) + (7895.6836f * fRec101[1])) + (3947.8418f * fRec101[2]))));
			float 	fTemp300 = (fVec23[0] - fTemp299);
			float 	fTemp301 = min(0.8f, max(0.0f, (max(-0.75f, fTemp300) + fSlow96)));
			float 	fTemp302 = ((iTemp2) ? 0.0f : (fSlow101 + fRec112[1]));
			fRec112[0] = (fTemp302 - floorf(fTemp302));
			float 	fTemp303 = (499.0f * fRec112[0]);
			int 	iTemp304 = int(fTemp303);
			int 	iTemp305 = max(0, min(iTemp304, 499));
			float 	fTemp306 = ftbl2[iTemp305];
			int 	iTemp307 = max(0, min((iTemp304 + 1), 499));
			float 	fTemp308 = (fTemp303 - float(iTemp304));
			float 	fTemp309 = min(1.0f, (max(min((3.0f * fTemp300), 0.3f), -0.13f) + 0.15f));
			float 	fTemp310 = ftbl0[iTemp305];
			fRec0[0] = ((1.37f * ((((((fTemp299 * ((((((fTemp310 + (fTemp308 * (ftbl0[iTemp307] - fTemp310))) * (1.0f - fTemp309)) + (fTemp309 * (fTemp306 + (fTemp308 * (ftbl2[iTemp307] - fTemp306))))) * (1.0f - (fTemp301 + fSlow88))) + (0.5f * (fTemp301 * (((2.0f * fRec100) + -1.0f) + ((2.0f * fRec98) + -1.0f))))) + (fSlow88 * ((0.33f * (fTemp267 + ((fTemp265 - float(iTemp266)) * (ftbl0[max(0, min((iTemp266 + 1), 499))] - fTemp267)))) + (0.67f * (fTemp263 + ((fTemp261 - float(iTemp262)) * (ftbl0[max(0, min((iTemp262 + 1), 499))] - fTemp263)))))))) + (fTemp248 * ((((((fTemp259 + (fTemp257 * (ftbl0[iTemp256] - fTemp259))) * (1.0f - fTemp258)) + (fTemp258 * (fTemp255 + (fTemp257 * (ftbl2[iTemp256] - fTemp255))))) * (1.0f - (fTemp250 + fSlow71))) + (0.5f * (fTemp250 * (((2.0f * fRec82) + -1.0f) + ((2.0f * fRec80) + -1.0f))))) + (fSlow71 * ((0.33f * (fTemp216 + ((fTemp214 - float(iTemp215)) * (ftbl0[max(0, min((iTemp215 + 1), 499))] - fTemp216)))) + (0.67f * (fTemp212 + ((fTemp210 - float(iTemp211)) * (ftbl0[max(0, min((iTemp211 + 1), 499))] - fTemp212))))))))) + (fTemp197 * ((((((fTemp208 + (fTemp206 * (ftbl0[iTemp205] - fTemp208))) * (1.0f - fTemp207)) + (fTemp207 * (fTemp204 + (fTemp206 * (ftbl2[iTemp205] - fTemp204))))) * (1.0f - (fTemp199 + fSlow54))) + (0.5f * (fTemp199 * (((2.0f * fRec64) + -1.0f) + ((2.0f * fRec62) + -1.0f))))) + (fSlow54 * ((0.33f * (fTemp165 + ((fTemp163 - float(iTemp164)) * (ftbl0[max(0, min((iTemp164 + 1), 499))] - fTemp165)))) + (0.67f * (fTemp161 + ((fTemp159 - float(iTemp160)) * (ftbl0[max(0, min((iTemp160 + 1), 499))] - fTemp161))))))))) + (fTemp146 * ((((((fTemp157 + (fTemp155 * (ftbl0[iTemp154] - fTemp157))) * (1.0f - fTemp156)) + (fTemp156 * (fTemp153 + (fTemp155 * (ftbl2[iTemp154] - fTemp153))))) * (1.0f - (fTemp148 + fSlow37))) + (0.5f * (fTemp148 * (((2.0f * fRec46) + -1.0f) + ((2.0f * fRec44) + -1.0f))))) + (fSlow37 * ((0.33f * (fTemp114 + ((fTemp112 - float(iTemp113)) * (ftbl0[max(0, min((iTemp113 + 1), 499))] - fTemp114)))) + (0.67f * (fTemp110 + ((fTemp108 - float(iTemp109)) * (ftbl0[max(0, min((iTemp109 + 1), 499))] - fTemp110))))))))) + (fTemp95 * ((((((fTemp106 + (fTemp104 * (ftbl0[iTemp103] - fTemp106))) * (1.0f - fTemp105)) + (fTemp105 * (fTemp102 + (fTemp104 * (ftbl2[iTemp103] - fTemp102))))) * (1.0f - (fTemp97 + fSlow20))) + (0.5f * (fTemp97 * (((2.0f * fRec28) + -1.0f) + ((2.0f * fRec26) + -1.0f))))) + (fSlow20 * ((0.33f * (fTemp63 + ((fTemp61 - float(iTemp62)) * (ftbl0[max(0, min((iTemp62 + 1), 499))] - fTemp63)))) + (0.67f * (fTemp59 + ((fTemp57 - float(iTemp58)) * (ftbl0[max(0, min((iTemp58 + 1), 499))] - fTemp59))))))))) + (fTemp44 * ((((((fTemp55 + (fTemp53 * (ftbl0[iTemp52] - fTemp55))) * (1.0f - fTemp54)) + (fTemp54 * (fTemp51 + (fTemp53 * (ftbl2[iTemp52] - fTemp51))))) * (1.0f - (fTemp46 + fSlow3))) + (0.5f * (fTemp46 * (((2.0f * fRec7) + -1.0f) + ((2.0f * fRec5) + -1.0f))))) + (fSlow3 * ((0.33f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl0[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.67f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst27 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec112[1] = fRec112[0];
			fRec101[2] = fRec101[1]; fRec101[1] = fRec101[0];
			fRec103[1] = fRec103[0];
			fRec106[1] = fRec106[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			iRec109[1] = iRec109[0];
			iRec108[1] = iRec108[0];
			iVec24[1] = iVec24[0];
			fRec107[1] = fRec107[0];
			iRec102[2] = iRec102[1]; iRec102[1] = iRec102[0];
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
			fRec88[1] = fRec88[0];
			fRec93[1] = fRec93[0];
			fRec92[1] = fRec92[0];
			iRec91[1] = iRec91[0];
			iRec90[1] = iRec90[0];
			iVec20[1] = iVec20[0];
			fRec89[1] = fRec89[0];
			iRec84[2] = iRec84[1]; iRec84[1] = iRec84[0];
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
			fRec70[1] = fRec70[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			iRec73[1] = iRec73[0];
			iRec72[1] = iRec72[0];
			iVec16[1] = iVec16[0];
			fRec71[1] = fRec71[0];
			iRec66[2] = iRec66[1]; iRec66[1] = iRec66[0];
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
			fRec52[1] = fRec52[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			iRec55[1] = iRec55[0];
			iRec54[1] = iRec54[0];
			iVec12[1] = iVec12[0];
			fRec53[1] = fRec53[0];
			iRec48[2] = iRec48[1]; iRec48[1] = iRec48[0];
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
			fRec34[1] = fRec34[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			iRec37[1] = iRec37[0];
			iRec36[1] = iRec36[0];
			iVec8[1] = iVec8[0];
			fRec35[1] = fRec35[0];
			iRec30[2] = iRec30[1]; iRec30[1] = iRec30[0];
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
			fRec15[1] = fRec15[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			iRec18[1] = iRec18[0];
			iRec17[1] = iRec17[0];
			iVec4[1] = iVec4[0];
			fRec16[1] = fRec16[0];
			iRec10[2] = iRec10[1]; iRec10[1] = iRec10[0];
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
