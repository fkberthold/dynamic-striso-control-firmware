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
	FAUSTFLOAT 	fbargraph0;
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
	FAUSTFLOAT 	fbargraph1;
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
	FAUSTFLOAT 	fbargraph2;
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
	FAUSTFLOAT 	fbargraph3;
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
	FAUSTFLOAT 	fbargraph4;
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
	FAUSTFLOAT 	fbargraph5;
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
		fConst21 = (1.4f * fConst0);
		fConst22 = (0.15f * fConst0);
		fConst23 = (0.2f * fConst0);
		fConst24 = (2.5f * fConst0);
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
			float 	fTemp25 = min(1.0f, (0.9f * fRec14[0]));
			int 	iTemp26 = (fVec3[0] >= fRec11[1]);
			int 	iTemp27 = (fRec11[1] <= 0.001f);
			int 	iTemp28 = (((iRec10[1] >= 4)) ? (((iRec10[1] >= 6)) ? ((iTemp27) ? 0 : ((iTemp22) ? 1 : 6)) : (((iRec10[1] >= 5)) ? ((iTemp23) ? 3 : ((iTemp26) ? 4 : 5)) : ((iTemp23) ? 3 : (((fVec3[0] <= fRec11[1])) ? 5 : 4)))) : (((iRec10[1] >= 2)) ? (((iRec10[1] >= 3)) ? (((iTemp23 & iTemp27)) ? 0 : ((iTemp22) ? 1 : 3)) : ((iTemp23) ? 3 : ((iTemp26) ? ((iTemp23) ? 6 : 4) : 2))) : (((iRec10[1] >= 1)) ? (((fRec11[1] >= min(fTemp25, 1.0f))) ? ((iTemp23) ? 6 : 2) : 1) : ((iTemp22) ? 1 : 0))));
			iRec10[0] = iTemp28;
			fRec16[0] = max((fTemp24 * fRec16[1]), fSlow15);
			float 	fTemp29 = (((iTemp28 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec16[0]))) : (((iTemp28 >= 4)) ? (((iTemp28 >= 6)) ? fConst24 : fConst23) : (((iTemp28 >= 2)) ? (((iTemp28 >= 3)) ? fConst22 : fConst21) : (((iTemp28 >= 1)) ? fConst20 : 0.0f))));
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
			int 	iTemp37 = ((iRec10[1] == 3) | (iRec10[1] == 6));
			fbargraph0 = float(iRec10[1]);
			float 	fTemp38 = (((fbargraph0 == 1.0f)) ? min(1.0f, fTemp25) : ((iTemp36) ? 0.0f : ((iTemp37) ? (fRec20[0] * fTemp34) : fVec3[0])));
			float 	fTemp39 = (1.0f / ((iTemp36) ? 0.0001f : ((iTemp37) ? (0.05f * (fTemp29 / ((((fTemp32 >= 11.0f)) ? (((fTemp32 >= 16.0f)) ? (((fTemp32 >= 19.0f)) ? (((fTemp32 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp32 >= 18.0f)) ? 0.03f : (((fTemp32 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp32 >= 14.0f)) ? (((fTemp32 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp32 >= 13.0f)) ? 0.14f : (((fTemp32 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp32 >= 6.0f)) ? (((fTemp32 >= 9.0f)) ? (((fTemp32 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp32 >= 8.0f)) ? 0.3f : (((fTemp32 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp32 >= 3.0f)) ? (((fTemp32 >= 5.0f)) ? 0.47f : (((fTemp32 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp32 >= 2.0f)) ? 0.74f : (((fTemp32 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp34))) : fTemp29)));
			float 	fTemp40 = (fRec15[1] - fTemp39);
			float 	fTemp41 = (fRec15[1] + fTemp39);
			fRec15[0] = (((fTemp41 < fTemp38)) ? fTemp41 : (((fTemp40 > fTemp38)) ? fTemp40 : fTemp38));
			fRec11[0] = fRec15[0];
			fRec9[0] = (fRec11[0] - (fConst19 * ((fConst17 * fRec9[2]) + (fConst15 * fRec9[1]))));
			float 	fTemp42 = min(0.99f, (fConst25 * (((3947.8418f * fRec9[0]) + (7895.6836f * fRec9[1])) + (3947.8418f * fRec9[2]))));
			float 	fTemp43 = (fVec3[0] - fTemp42);
			float 	fTemp44 = min(0.8f, max(0.0f, (max(-0.75f, fTemp43) + fSlow11)));
			float 	fTemp45 = ((iTemp2) ? 0.0f : (fSlow16 + fRec22[1]));
			fRec22[0] = (fTemp45 - floorf(fTemp45));
			float 	fTemp46 = (499.0f * fRec22[0]);
			int 	iTemp47 = int(fTemp46);
			int 	iTemp48 = max(0, min(iTemp47, 499));
			float 	fTemp49 = ftbl2[iTemp48];
			int 	iTemp50 = max(0, min((iTemp47 + 1), 499));
			float 	fTemp51 = (fTemp46 - float(iTemp47));
			float 	fTemp52 = min(1.0f, (max(min((3.0f * fTemp43), 0.3f), -0.13f) + 0.15f));
			float 	fTemp53 = ftbl0[iTemp48];
			float 	fTemp54 = ((iTemp2) ? 0.0f : (fSlow18 + fRec23[1]));
			fRec23[0] = (fTemp54 - floorf(fTemp54));
			float 	fTemp55 = (499.0f * fRec23[0]);
			int 	iTemp56 = int(fTemp55);
			float 	fTemp57 = ftbl0[max(0, min(iTemp56, 499))];
			float 	fTemp58 = ((iTemp2) ? 0.0f : (fSlow19 + fRec24[1]));
			fRec24[0] = (fTemp58 - floorf(fTemp58));
			float 	fTemp59 = (499.0f * fRec24[0]);
			int 	iTemp60 = int(fTemp59);
			float 	fTemp61 = ftbl0[max(0, min(iTemp60, 499))];
			float 	fTemp62 = (fSlow22 + (fRec25[1] + -1.0f));
			float 	fTemp63 = (fSlow22 + fRec25[1]);
			int 	iTemp64 = (fTemp62 < 0.0f);
			fRec25[0] = ((iTemp64) ? fTemp63 : fTemp62);
			float 	fRec26 = ((iTemp64) ? fTemp63 : (fSlow22 + (fRec25[1] + (fSlow23 * fTemp62))));
			float 	fTemp65 = (fSlow25 + (fRec27[1] + -1.0f));
			float 	fTemp66 = (fSlow25 + fRec27[1]);
			int 	iTemp67 = (fTemp65 < 0.0f);
			fRec27[0] = ((iTemp67) ? fTemp66 : fTemp65);
			float 	fRec28 = ((iTemp67) ? fTemp66 : (fSlow25 + (fRec27[1] + (fSlow26 * fTemp65))));
			fVec5[0] = fSlow30;
			int 	iTemp68 = (fSlow30 != fVec5[1]);
			iVec6[0] = iTemp68;
			int 	iTemp69 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp69)) + (iTemp20 * iTemp69));
			float 	fTemp70 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec32[0])))) > 0.5f) & iSlow31)) ? 0.0f : fSlow29) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp70;
			int 	iTemp71 = (fVec7[0] > 0.001f);
			int 	iTemp72 = (fVec7[0] <= 0.001f);
			float 	fTemp73 = float((iTemp72 | (fVec7[1] >= 0.001f)));
			fRec33[0] = max((fRec33[1] * fTemp73), fSlow30);
			float 	fTemp74 = min(1.0f, (0.9f * fRec33[0]));
			int 	iTemp75 = (fVec7[0] >= fRec31[1]);
			int 	iTemp76 = (fRec31[1] <= 0.001f);
			int 	iTemp77 = (((iRec30[1] >= 4)) ? (((iRec30[1] >= 6)) ? ((iTemp76) ? 0 : ((iTemp71) ? 1 : 6)) : (((iRec30[1] >= 5)) ? ((iTemp72) ? 3 : ((iTemp75) ? 4 : 5)) : ((iTemp72) ? 3 : (((fVec7[0] <= fRec31[1])) ? 5 : 4)))) : (((iRec30[1] >= 2)) ? (((iRec30[1] >= 3)) ? (((iTemp72 & iTemp76)) ? 0 : ((iTemp71) ? 1 : 3)) : ((iTemp72) ? 3 : ((iTemp75) ? ((iTemp72) ? 6 : 4) : 2))) : (((iRec30[1] >= 1)) ? (((fRec31[1] >= min(fTemp74, 1.0f))) ? ((iTemp72) ? 6 : 2) : 1) : ((iTemp71) ? 1 : 0))));
			iRec30[0] = iTemp77;
			fRec35[0] = max((fTemp73 * fRec35[1]), fSlow32);
			float 	fTemp78 = (((iTemp77 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec35[0]))) : (((iTemp77 >= 4)) ? (((iTemp77 >= 6)) ? fConst24 : fConst23) : (((iTemp77 >= 2)) ? (((iTemp77 >= 3)) ? fConst22 : fConst21) : (((iTemp77 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp79 = (iRec30[1] != iRec30[2]);
			iVec8[0] = iTemp79;
			int 	iTemp80 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec36[0] = ((iRec36[1] * (1 - iTemp80)) + (iTemp20 * iTemp80));
			float 	fTemp81 = min(19.0f, floorf((21.0f * (((fTemp78 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec36[0]))) / fTemp78) : 1.0f))));
			float 	fTemp82 = min((fTemp81 + 1.0f), 2e+01f);
			float 	fTemp83 = (((fTemp82 >= 11.0f)) ? (((fTemp82 >= 16.0f)) ? (((fTemp82 >= 19.0f)) ? (((fTemp82 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp82 >= 18.0f)) ? 0.03f : (((fTemp82 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp82 >= 14.0f)) ? (((fTemp82 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp82 >= 13.0f)) ? 0.14f : (((fTemp82 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp82 >= 6.0f)) ? (((fTemp82 >= 9.0f)) ? (((fTemp82 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp82 >= 8.0f)) ? 0.3f : (((fTemp82 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp82 >= 3.0f)) ? (((fTemp82 >= 5.0f)) ? 0.47f : (((fTemp82 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp82 >= 2.0f)) ? 0.74f : (((fTemp82 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec37[0] = iRec30[1];
			int 	iTemp84 = (iRec37[1] == iRec30[1]);
			int 	iTemp85 = (iRec30[1] == 0);
			fRec38[0] = ((iTemp85) ? fVec7[0] : ((iTemp84) ? min(min(fRec38[1], fVec7[0]), fRec31[1]) : min(fVec7[0], fRec31[1])));
			fRec39[0] = ((iTemp85) ? fVec7[0] : ((iTemp84) ? max(max(fRec39[1], fVec7[0]), fRec31[1]) : max(fVec7[0], fRec31[1])));
			int 	iTemp86 = ((iRec30[1] == 3) | (iRec30[1] == 6));
			fbargraph1 = float(iRec30[1]);
			float 	fTemp87 = (((fbargraph1 == 1.0f)) ? min(1.0f, fTemp74) : ((iTemp85) ? 0.0f : ((iTemp86) ? (fRec39[0] * fTemp83) : fVec7[0])));
			float 	fTemp88 = (1.0f / ((iTemp85) ? 0.0001f : ((iTemp86) ? (0.05f * (fTemp78 / ((((fTemp81 >= 11.0f)) ? (((fTemp81 >= 16.0f)) ? (((fTemp81 >= 19.0f)) ? (((fTemp81 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp81 >= 18.0f)) ? 0.03f : (((fTemp81 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp81 >= 14.0f)) ? (((fTemp81 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp81 >= 13.0f)) ? 0.14f : (((fTemp81 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp81 >= 6.0f)) ? (((fTemp81 >= 9.0f)) ? (((fTemp81 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp81 >= 8.0f)) ? 0.3f : (((fTemp81 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp81 >= 3.0f)) ? (((fTemp81 >= 5.0f)) ? 0.47f : (((fTemp81 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp81 >= 2.0f)) ? 0.74f : (((fTemp81 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp83))) : fTemp78)));
			float 	fTemp89 = (fRec34[1] - fTemp88);
			float 	fTemp90 = (fRec34[1] + fTemp88);
			fRec34[0] = (((fTemp90 < fTemp87)) ? fTemp90 : (((fTemp89 > fTemp87)) ? fTemp89 : fTemp87));
			fRec31[0] = fRec34[0];
			fRec29[0] = (fRec31[0] - (fConst19 * ((fConst17 * fRec29[2]) + (fConst15 * fRec29[1]))));
			float 	fTemp91 = min(0.99f, (fConst25 * (((3947.8418f * fRec29[0]) + (7895.6836f * fRec29[1])) + (3947.8418f * fRec29[2]))));
			float 	fTemp92 = (fVec7[0] - fTemp91);
			float 	fTemp93 = min(0.8f, max(0.0f, (max(-0.75f, fTemp92) + fSlow28)));
			float 	fTemp94 = ((iTemp2) ? 0.0f : (fSlow33 + fRec40[1]));
			fRec40[0] = (fTemp94 - floorf(fTemp94));
			float 	fTemp95 = (499.0f * fRec40[0]);
			int 	iTemp96 = int(fTemp95);
			int 	iTemp97 = max(0, min(iTemp96, 499));
			float 	fTemp98 = ftbl2[iTemp97];
			int 	iTemp99 = max(0, min((iTemp96 + 1), 499));
			float 	fTemp100 = (fTemp95 - float(iTemp96));
			float 	fTemp101 = min(1.0f, (max(min((3.0f * fTemp92), 0.3f), -0.13f) + 0.15f));
			float 	fTemp102 = ftbl0[iTemp97];
			float 	fTemp103 = ((iTemp2) ? 0.0f : (fSlow35 + fRec41[1]));
			fRec41[0] = (fTemp103 - floorf(fTemp103));
			float 	fTemp104 = (499.0f * fRec41[0]);
			int 	iTemp105 = int(fTemp104);
			float 	fTemp106 = ftbl0[max(0, min(iTemp105, 499))];
			float 	fTemp107 = ((iTemp2) ? 0.0f : (fSlow36 + fRec42[1]));
			fRec42[0] = (fTemp107 - floorf(fTemp107));
			float 	fTemp108 = (499.0f * fRec42[0]);
			int 	iTemp109 = int(fTemp108);
			float 	fTemp110 = ftbl0[max(0, min(iTemp109, 499))];
			float 	fTemp111 = (fSlow39 + (fRec43[1] + -1.0f));
			float 	fTemp112 = (fSlow39 + fRec43[1]);
			int 	iTemp113 = (fTemp111 < 0.0f);
			fRec43[0] = ((iTemp113) ? fTemp112 : fTemp111);
			float 	fRec44 = ((iTemp113) ? fTemp112 : (fSlow39 + (fRec43[1] + (fSlow40 * fTemp111))));
			float 	fTemp114 = (fSlow42 + (fRec45[1] + -1.0f));
			float 	fTemp115 = (fSlow42 + fRec45[1]);
			int 	iTemp116 = (fTemp114 < 0.0f);
			fRec45[0] = ((iTemp116) ? fTemp115 : fTemp114);
			float 	fRec46 = ((iTemp116) ? fTemp115 : (fSlow42 + (fRec45[1] + (fSlow43 * fTemp114))));
			fVec9[0] = fSlow47;
			int 	iTemp117 = (fSlow47 != fVec9[1]);
			iVec10[0] = iTemp117;
			int 	iTemp118 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec50[0] = ((iRec50[1] * (1 - iTemp118)) + (iTemp20 * iTemp118));
			float 	fTemp119 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec50[0])))) > 0.5f) & iSlow48)) ? 0.0f : fSlow46) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp119;
			int 	iTemp120 = (fVec11[0] > 0.001f);
			int 	iTemp121 = (fVec11[0] <= 0.001f);
			float 	fTemp122 = float((iTemp121 | (fVec11[1] >= 0.001f)));
			fRec51[0] = max((fRec51[1] * fTemp122), fSlow47);
			float 	fTemp123 = min(1.0f, (0.9f * fRec51[0]));
			int 	iTemp124 = (fVec11[0] >= fRec49[1]);
			int 	iTemp125 = (fRec49[1] <= 0.001f);
			int 	iTemp126 = (((iRec48[1] >= 4)) ? (((iRec48[1] >= 6)) ? ((iTemp125) ? 0 : ((iTemp120) ? 1 : 6)) : (((iRec48[1] >= 5)) ? ((iTemp121) ? 3 : ((iTemp124) ? 4 : 5)) : ((iTemp121) ? 3 : (((fVec11[0] <= fRec49[1])) ? 5 : 4)))) : (((iRec48[1] >= 2)) ? (((iRec48[1] >= 3)) ? (((iTemp121 & iTemp125)) ? 0 : ((iTemp120) ? 1 : 3)) : ((iTemp121) ? 3 : ((iTemp124) ? ((iTemp121) ? 6 : 4) : 2))) : (((iRec48[1] >= 1)) ? (((fRec49[1] >= min(fTemp123, 1.0f))) ? ((iTemp121) ? 6 : 2) : 1) : ((iTemp120) ? 1 : 0))));
			iRec48[0] = iTemp126;
			fRec53[0] = max((fTemp122 * fRec53[1]), fSlow49);
			float 	fTemp127 = (((iTemp126 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec53[0]))) : (((iTemp126 >= 4)) ? (((iTemp126 >= 6)) ? fConst24 : fConst23) : (((iTemp126 >= 2)) ? (((iTemp126 >= 3)) ? fConst22 : fConst21) : (((iTemp126 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp128 = (iRec48[1] != iRec48[2]);
			iVec12[0] = iTemp128;
			int 	iTemp129 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec54[0] = ((iRec54[1] * (1 - iTemp129)) + (iTemp20 * iTemp129));
			float 	fTemp130 = min(19.0f, floorf((21.0f * (((fTemp127 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec54[0]))) / fTemp127) : 1.0f))));
			float 	fTemp131 = min((fTemp130 + 1.0f), 2e+01f);
			float 	fTemp132 = (((fTemp131 >= 11.0f)) ? (((fTemp131 >= 16.0f)) ? (((fTemp131 >= 19.0f)) ? (((fTemp131 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp131 >= 18.0f)) ? 0.03f : (((fTemp131 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp131 >= 14.0f)) ? (((fTemp131 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp131 >= 13.0f)) ? 0.14f : (((fTemp131 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp131 >= 6.0f)) ? (((fTemp131 >= 9.0f)) ? (((fTemp131 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp131 >= 8.0f)) ? 0.3f : (((fTemp131 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp131 >= 3.0f)) ? (((fTemp131 >= 5.0f)) ? 0.47f : (((fTemp131 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp131 >= 2.0f)) ? 0.74f : (((fTemp131 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec55[0] = iRec48[1];
			int 	iTemp133 = (iRec55[1] == iRec48[1]);
			int 	iTemp134 = (iRec48[1] == 0);
			fRec56[0] = ((iTemp134) ? fVec11[0] : ((iTemp133) ? min(min(fRec56[1], fVec11[0]), fRec49[1]) : min(fVec11[0], fRec49[1])));
			fRec57[0] = ((iTemp134) ? fVec11[0] : ((iTemp133) ? max(max(fRec57[1], fVec11[0]), fRec49[1]) : max(fVec11[0], fRec49[1])));
			int 	iTemp135 = ((iRec48[1] == 3) | (iRec48[1] == 6));
			fbargraph2 = float(iRec48[1]);
			float 	fTemp136 = (((fbargraph2 == 1.0f)) ? min(1.0f, fTemp123) : ((iTemp134) ? 0.0f : ((iTemp135) ? (fRec57[0] * fTemp132) : fVec11[0])));
			float 	fTemp137 = (1.0f / ((iTemp134) ? 0.0001f : ((iTemp135) ? (0.05f * (fTemp127 / ((((fTemp130 >= 11.0f)) ? (((fTemp130 >= 16.0f)) ? (((fTemp130 >= 19.0f)) ? (((fTemp130 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp130 >= 18.0f)) ? 0.03f : (((fTemp130 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp130 >= 14.0f)) ? (((fTemp130 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp130 >= 13.0f)) ? 0.14f : (((fTemp130 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp130 >= 6.0f)) ? (((fTemp130 >= 9.0f)) ? (((fTemp130 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp130 >= 8.0f)) ? 0.3f : (((fTemp130 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp130 >= 3.0f)) ? (((fTemp130 >= 5.0f)) ? 0.47f : (((fTemp130 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp130 >= 2.0f)) ? 0.74f : (((fTemp130 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp132))) : fTemp127)));
			float 	fTemp138 = (fRec52[1] - fTemp137);
			float 	fTemp139 = (fRec52[1] + fTemp137);
			fRec52[0] = (((fTemp139 < fTemp136)) ? fTemp139 : (((fTemp138 > fTemp136)) ? fTemp138 : fTemp136));
			fRec49[0] = fRec52[0];
			fRec47[0] = (fRec49[0] - (fConst19 * ((fConst17 * fRec47[2]) + (fConst15 * fRec47[1]))));
			float 	fTemp140 = min(0.99f, (fConst25 * (((3947.8418f * fRec47[0]) + (7895.6836f * fRec47[1])) + (3947.8418f * fRec47[2]))));
			float 	fTemp141 = (fVec11[0] - fTemp140);
			float 	fTemp142 = min(0.8f, max(0.0f, (max(-0.75f, fTemp141) + fSlow45)));
			float 	fTemp143 = ((iTemp2) ? 0.0f : (fSlow50 + fRec58[1]));
			fRec58[0] = (fTemp143 - floorf(fTemp143));
			float 	fTemp144 = (499.0f * fRec58[0]);
			int 	iTemp145 = int(fTemp144);
			int 	iTemp146 = max(0, min(iTemp145, 499));
			float 	fTemp147 = ftbl2[iTemp146];
			int 	iTemp148 = max(0, min((iTemp145 + 1), 499));
			float 	fTemp149 = (fTemp144 - float(iTemp145));
			float 	fTemp150 = min(1.0f, (max(min((3.0f * fTemp141), 0.3f), -0.13f) + 0.15f));
			float 	fTemp151 = ftbl0[iTemp146];
			float 	fTemp152 = ((iTemp2) ? 0.0f : (fSlow52 + fRec59[1]));
			fRec59[0] = (fTemp152 - floorf(fTemp152));
			float 	fTemp153 = (499.0f * fRec59[0]);
			int 	iTemp154 = int(fTemp153);
			float 	fTemp155 = ftbl0[max(0, min(iTemp154, 499))];
			float 	fTemp156 = ((iTemp2) ? 0.0f : (fSlow53 + fRec60[1]));
			fRec60[0] = (fTemp156 - floorf(fTemp156));
			float 	fTemp157 = (499.0f * fRec60[0]);
			int 	iTemp158 = int(fTemp157);
			float 	fTemp159 = ftbl0[max(0, min(iTemp158, 499))];
			float 	fTemp160 = (fSlow56 + (fRec61[1] + -1.0f));
			float 	fTemp161 = (fSlow56 + fRec61[1]);
			int 	iTemp162 = (fTemp160 < 0.0f);
			fRec61[0] = ((iTemp162) ? fTemp161 : fTemp160);
			float 	fRec62 = ((iTemp162) ? fTemp161 : (fSlow56 + (fRec61[1] + (fSlow57 * fTemp160))));
			float 	fTemp163 = (fSlow59 + (fRec63[1] + -1.0f));
			float 	fTemp164 = (fSlow59 + fRec63[1]);
			int 	iTemp165 = (fTemp163 < 0.0f);
			fRec63[0] = ((iTemp165) ? fTemp164 : fTemp163);
			float 	fRec64 = ((iTemp165) ? fTemp164 : (fSlow59 + (fRec63[1] + (fSlow60 * fTemp163))));
			fVec13[0] = fSlow64;
			int 	iTemp166 = (fSlow64 != fVec13[1]);
			iVec14[0] = iTemp166;
			int 	iTemp167 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec68[0] = ((iRec68[1] * (1 - iTemp167)) + (iTemp20 * iTemp167));
			float 	fTemp168 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec68[0])))) > 0.5f) & iSlow65)) ? 0.0f : fSlow63) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp168;
			int 	iTemp169 = (fVec15[0] > 0.001f);
			int 	iTemp170 = (fVec15[0] <= 0.001f);
			float 	fTemp171 = float((iTemp170 | (fVec15[1] >= 0.001f)));
			fRec69[0] = max((fRec69[1] * fTemp171), fSlow64);
			float 	fTemp172 = min(1.0f, (0.9f * fRec69[0]));
			int 	iTemp173 = (fVec15[0] >= fRec67[1]);
			int 	iTemp174 = (fRec67[1] <= 0.001f);
			int 	iTemp175 = (((iRec66[1] >= 4)) ? (((iRec66[1] >= 6)) ? ((iTemp174) ? 0 : ((iTemp169) ? 1 : 6)) : (((iRec66[1] >= 5)) ? ((iTemp170) ? 3 : ((iTemp173) ? 4 : 5)) : ((iTemp170) ? 3 : (((fVec15[0] <= fRec67[1])) ? 5 : 4)))) : (((iRec66[1] >= 2)) ? (((iRec66[1] >= 3)) ? (((iTemp170 & iTemp174)) ? 0 : ((iTemp169) ? 1 : 3)) : ((iTemp170) ? 3 : ((iTemp173) ? ((iTemp170) ? 6 : 4) : 2))) : (((iRec66[1] >= 1)) ? (((fRec67[1] >= min(fTemp172, 1.0f))) ? ((iTemp170) ? 6 : 2) : 1) : ((iTemp169) ? 1 : 0))));
			iRec66[0] = iTemp175;
			fRec71[0] = max((fTemp171 * fRec71[1]), fSlow66);
			float 	fTemp176 = (((iTemp175 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec71[0]))) : (((iTemp175 >= 4)) ? (((iTemp175 >= 6)) ? fConst24 : fConst23) : (((iTemp175 >= 2)) ? (((iTemp175 >= 3)) ? fConst22 : fConst21) : (((iTemp175 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp177 = (iRec66[1] != iRec66[2]);
			iVec16[0] = iTemp177;
			int 	iTemp178 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec72[0] = ((iRec72[1] * (1 - iTemp178)) + (iTemp20 * iTemp178));
			float 	fTemp179 = min(19.0f, floorf((21.0f * (((fTemp176 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec72[0]))) / fTemp176) : 1.0f))));
			float 	fTemp180 = min((fTemp179 + 1.0f), 2e+01f);
			float 	fTemp181 = (((fTemp180 >= 11.0f)) ? (((fTemp180 >= 16.0f)) ? (((fTemp180 >= 19.0f)) ? (((fTemp180 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp180 >= 18.0f)) ? 0.03f : (((fTemp180 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp180 >= 14.0f)) ? (((fTemp180 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp180 >= 13.0f)) ? 0.14f : (((fTemp180 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp180 >= 6.0f)) ? (((fTemp180 >= 9.0f)) ? (((fTemp180 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp180 >= 8.0f)) ? 0.3f : (((fTemp180 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp180 >= 3.0f)) ? (((fTemp180 >= 5.0f)) ? 0.47f : (((fTemp180 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp180 >= 2.0f)) ? 0.74f : (((fTemp180 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec73[0] = iRec66[1];
			int 	iTemp182 = (iRec73[1] == iRec66[1]);
			int 	iTemp183 = (iRec66[1] == 0);
			fRec74[0] = ((iTemp183) ? fVec15[0] : ((iTemp182) ? min(min(fRec74[1], fVec15[0]), fRec67[1]) : min(fVec15[0], fRec67[1])));
			fRec75[0] = ((iTemp183) ? fVec15[0] : ((iTemp182) ? max(max(fRec75[1], fVec15[0]), fRec67[1]) : max(fVec15[0], fRec67[1])));
			int 	iTemp184 = ((iRec66[1] == 3) | (iRec66[1] == 6));
			fbargraph3 = float(iRec66[1]);
			float 	fTemp185 = (((fbargraph3 == 1.0f)) ? min(1.0f, fTemp172) : ((iTemp183) ? 0.0f : ((iTemp184) ? (fRec75[0] * fTemp181) : fVec15[0])));
			float 	fTemp186 = (1.0f / ((iTemp183) ? 0.0001f : ((iTemp184) ? (0.05f * (fTemp176 / ((((fTemp179 >= 11.0f)) ? (((fTemp179 >= 16.0f)) ? (((fTemp179 >= 19.0f)) ? (((fTemp179 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp179 >= 18.0f)) ? 0.03f : (((fTemp179 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp179 >= 14.0f)) ? (((fTemp179 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp179 >= 13.0f)) ? 0.14f : (((fTemp179 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp179 >= 6.0f)) ? (((fTemp179 >= 9.0f)) ? (((fTemp179 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp179 >= 8.0f)) ? 0.3f : (((fTemp179 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp179 >= 3.0f)) ? (((fTemp179 >= 5.0f)) ? 0.47f : (((fTemp179 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp179 >= 2.0f)) ? 0.74f : (((fTemp179 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp181))) : fTemp176)));
			float 	fTemp187 = (fRec70[1] - fTemp186);
			float 	fTemp188 = (fRec70[1] + fTemp186);
			fRec70[0] = (((fTemp188 < fTemp185)) ? fTemp188 : (((fTemp187 > fTemp185)) ? fTemp187 : fTemp185));
			fRec67[0] = fRec70[0];
			fRec65[0] = (fRec67[0] - (fConst19 * ((fConst17 * fRec65[2]) + (fConst15 * fRec65[1]))));
			float 	fTemp189 = min(0.99f, (fConst25 * (((3947.8418f * fRec65[0]) + (7895.6836f * fRec65[1])) + (3947.8418f * fRec65[2]))));
			float 	fTemp190 = (fVec15[0] - fTemp189);
			float 	fTemp191 = min(0.8f, max(0.0f, (max(-0.75f, fTemp190) + fSlow62)));
			float 	fTemp192 = ((iTemp2) ? 0.0f : (fSlow67 + fRec76[1]));
			fRec76[0] = (fTemp192 - floorf(fTemp192));
			float 	fTemp193 = (499.0f * fRec76[0]);
			int 	iTemp194 = int(fTemp193);
			int 	iTemp195 = max(0, min(iTemp194, 499));
			float 	fTemp196 = ftbl2[iTemp195];
			int 	iTemp197 = max(0, min((iTemp194 + 1), 499));
			float 	fTemp198 = (fTemp193 - float(iTemp194));
			float 	fTemp199 = min(1.0f, (max(min((3.0f * fTemp190), 0.3f), -0.13f) + 0.15f));
			float 	fTemp200 = ftbl0[iTemp195];
			float 	fTemp201 = ((iTemp2) ? 0.0f : (fSlow69 + fRec77[1]));
			fRec77[0] = (fTemp201 - floorf(fTemp201));
			float 	fTemp202 = (499.0f * fRec77[0]);
			int 	iTemp203 = int(fTemp202);
			float 	fTemp204 = ftbl0[max(0, min(iTemp203, 499))];
			float 	fTemp205 = ((iTemp2) ? 0.0f : (fSlow70 + fRec78[1]));
			fRec78[0] = (fTemp205 - floorf(fTemp205));
			float 	fTemp206 = (499.0f * fRec78[0]);
			int 	iTemp207 = int(fTemp206);
			float 	fTemp208 = ftbl0[max(0, min(iTemp207, 499))];
			float 	fTemp209 = (fSlow73 + (fRec79[1] + -1.0f));
			float 	fTemp210 = (fSlow73 + fRec79[1]);
			int 	iTemp211 = (fTemp209 < 0.0f);
			fRec79[0] = ((iTemp211) ? fTemp210 : fTemp209);
			float 	fRec80 = ((iTemp211) ? fTemp210 : (fSlow73 + (fRec79[1] + (fSlow74 * fTemp209))));
			float 	fTemp212 = (fSlow76 + (fRec81[1] + -1.0f));
			float 	fTemp213 = (fSlow76 + fRec81[1]);
			int 	iTemp214 = (fTemp212 < 0.0f);
			fRec81[0] = ((iTemp214) ? fTemp213 : fTemp212);
			float 	fRec82 = ((iTemp214) ? fTemp213 : (fSlow76 + (fRec81[1] + (fSlow77 * fTemp212))));
			fVec17[0] = fSlow81;
			int 	iTemp215 = (fSlow81 != fVec17[1]);
			iVec18[0] = iTemp215;
			int 	iTemp216 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp216)) + (iTemp20 * iTemp216));
			float 	fTemp217 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec86[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp217;
			int 	iTemp218 = (fVec19[0] > 0.001f);
			int 	iTemp219 = (fVec19[0] <= 0.001f);
			float 	fTemp220 = float((iTemp219 | (fVec19[1] >= 0.001f)));
			fRec87[0] = max((fRec87[1] * fTemp220), fSlow81);
			float 	fTemp221 = min(1.0f, (0.9f * fRec87[0]));
			int 	iTemp222 = (fVec19[0] >= fRec85[1]);
			int 	iTemp223 = (fRec85[1] <= 0.001f);
			int 	iTemp224 = (((iRec84[1] >= 4)) ? (((iRec84[1] >= 6)) ? ((iTemp223) ? 0 : ((iTemp218) ? 1 : 6)) : (((iRec84[1] >= 5)) ? ((iTemp219) ? 3 : ((iTemp222) ? 4 : 5)) : ((iTemp219) ? 3 : (((fVec19[0] <= fRec85[1])) ? 5 : 4)))) : (((iRec84[1] >= 2)) ? (((iRec84[1] >= 3)) ? (((iTemp219 & iTemp223)) ? 0 : ((iTemp218) ? 1 : 3)) : ((iTemp219) ? 3 : ((iTemp222) ? ((iTemp219) ? 6 : 4) : 2))) : (((iRec84[1] >= 1)) ? (((fRec85[1] >= min(fTemp221, 1.0f))) ? ((iTemp219) ? 6 : 2) : 1) : ((iTemp218) ? 1 : 0))));
			iRec84[0] = iTemp224;
			fRec89[0] = max((fTemp220 * fRec89[1]), fSlow83);
			float 	fTemp225 = (((iTemp224 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec89[0]))) : (((iTemp224 >= 4)) ? (((iTemp224 >= 6)) ? fConst24 : fConst23) : (((iTemp224 >= 2)) ? (((iTemp224 >= 3)) ? fConst22 : fConst21) : (((iTemp224 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp226 = (iRec84[1] != iRec84[2]);
			iVec20[0] = iTemp226;
			int 	iTemp227 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp227)) + (iTemp20 * iTemp227));
			float 	fTemp228 = min(19.0f, floorf((21.0f * (((fTemp225 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec90[0]))) / fTemp225) : 1.0f))));
			float 	fTemp229 = min((fTemp228 + 1.0f), 2e+01f);
			float 	fTemp230 = (((fTemp229 >= 11.0f)) ? (((fTemp229 >= 16.0f)) ? (((fTemp229 >= 19.0f)) ? (((fTemp229 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp229 >= 18.0f)) ? 0.03f : (((fTemp229 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp229 >= 14.0f)) ? (((fTemp229 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp229 >= 13.0f)) ? 0.14f : (((fTemp229 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp229 >= 6.0f)) ? (((fTemp229 >= 9.0f)) ? (((fTemp229 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp229 >= 8.0f)) ? 0.3f : (((fTemp229 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp229 >= 3.0f)) ? (((fTemp229 >= 5.0f)) ? 0.47f : (((fTemp229 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp229 >= 2.0f)) ? 0.74f : (((fTemp229 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec91[0] = iRec84[1];
			int 	iTemp231 = (iRec91[1] == iRec84[1]);
			int 	iTemp232 = (iRec84[1] == 0);
			fRec92[0] = ((iTemp232) ? fVec19[0] : ((iTemp231) ? min(min(fRec92[1], fVec19[0]), fRec85[1]) : min(fVec19[0], fRec85[1])));
			fRec93[0] = ((iTemp232) ? fVec19[0] : ((iTemp231) ? max(max(fRec93[1], fVec19[0]), fRec85[1]) : max(fVec19[0], fRec85[1])));
			int 	iTemp233 = ((iRec84[1] == 3) | (iRec84[1] == 6));
			fbargraph4 = float(iRec84[1]);
			float 	fTemp234 = (((fbargraph4 == 1.0f)) ? min(1.0f, fTemp221) : ((iTemp232) ? 0.0f : ((iTemp233) ? (fRec93[0] * fTemp230) : fVec19[0])));
			float 	fTemp235 = (1.0f / ((iTemp232) ? 0.0001f : ((iTemp233) ? (0.05f * (fTemp225 / ((((fTemp228 >= 11.0f)) ? (((fTemp228 >= 16.0f)) ? (((fTemp228 >= 19.0f)) ? (((fTemp228 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp228 >= 18.0f)) ? 0.03f : (((fTemp228 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp228 >= 14.0f)) ? (((fTemp228 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp228 >= 13.0f)) ? 0.14f : (((fTemp228 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp228 >= 6.0f)) ? (((fTemp228 >= 9.0f)) ? (((fTemp228 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp228 >= 8.0f)) ? 0.3f : (((fTemp228 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp228 >= 3.0f)) ? (((fTemp228 >= 5.0f)) ? 0.47f : (((fTemp228 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp228 >= 2.0f)) ? 0.74f : (((fTemp228 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp230))) : fTemp225)));
			float 	fTemp236 = (fRec88[1] - fTemp235);
			float 	fTemp237 = (fRec88[1] + fTemp235);
			fRec88[0] = (((fTemp237 < fTemp234)) ? fTemp237 : (((fTemp236 > fTemp234)) ? fTemp236 : fTemp234));
			fRec85[0] = fRec88[0];
			fRec83[0] = (fRec85[0] - (fConst19 * ((fConst17 * fRec83[2]) + (fConst15 * fRec83[1]))));
			float 	fTemp238 = min(0.99f, (fConst25 * (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]))));
			float 	fTemp239 = (fVec19[0] - fTemp238);
			float 	fTemp240 = min(0.8f, max(0.0f, (max(-0.75f, fTemp239) + fSlow79)));
			float 	fTemp241 = ((iTemp2) ? 0.0f : (fSlow84 + fRec94[1]));
			fRec94[0] = (fTemp241 - floorf(fTemp241));
			float 	fTemp242 = (499.0f * fRec94[0]);
			int 	iTemp243 = int(fTemp242);
			int 	iTemp244 = max(0, min(iTemp243, 499));
			float 	fTemp245 = ftbl2[iTemp244];
			int 	iTemp246 = max(0, min((iTemp243 + 1), 499));
			float 	fTemp247 = (fTemp242 - float(iTemp243));
			float 	fTemp248 = min(1.0f, (max(min((3.0f * fTemp239), 0.3f), -0.13f) + 0.15f));
			float 	fTemp249 = ftbl0[iTemp244];
			float 	fTemp250 = ((iTemp2) ? 0.0f : (fSlow86 + fRec95[1]));
			fRec95[0] = (fTemp250 - floorf(fTemp250));
			float 	fTemp251 = (499.0f * fRec95[0]);
			int 	iTemp252 = int(fTemp251);
			float 	fTemp253 = ftbl0[max(0, min(iTemp252, 499))];
			float 	fTemp254 = ((iTemp2) ? 0.0f : (fSlow87 + fRec96[1]));
			fRec96[0] = (fTemp254 - floorf(fTemp254));
			float 	fTemp255 = (499.0f * fRec96[0]);
			int 	iTemp256 = int(fTemp255);
			float 	fTemp257 = ftbl0[max(0, min(iTemp256, 499))];
			float 	fTemp258 = (fSlow90 + (fRec97[1] + -1.0f));
			float 	fTemp259 = (fSlow90 + fRec97[1]);
			int 	iTemp260 = (fTemp258 < 0.0f);
			fRec97[0] = ((iTemp260) ? fTemp259 : fTemp258);
			float 	fRec98 = ((iTemp260) ? fTemp259 : (fSlow90 + (fRec97[1] + (fSlow91 * fTemp258))));
			float 	fTemp261 = (fSlow93 + (fRec99[1] + -1.0f));
			float 	fTemp262 = (fSlow93 + fRec99[1]);
			int 	iTemp263 = (fTemp261 < 0.0f);
			fRec99[0] = ((iTemp263) ? fTemp262 : fTemp261);
			float 	fRec100 = ((iTemp263) ? fTemp262 : (fSlow93 + (fRec99[1] + (fSlow94 * fTemp261))));
			fVec21[0] = fSlow98;
			int 	iTemp264 = (fSlow98 != fVec21[1]);
			iVec22[0] = iTemp264;
			int 	iTemp265 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec104[0] = ((iRec104[1] * (1 - iTemp265)) + (iTemp20 * iTemp265));
			float 	fTemp266 = ftbl1[int(((499.5f * ((((((fConst11 * float((iRec13[0] + (-1 - iRec104[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp266;
			int 	iTemp267 = (fVec23[0] > 0.001f);
			int 	iTemp268 = (fVec23[0] <= 0.001f);
			float 	fTemp269 = float((iTemp268 | (fVec23[1] >= 0.001f)));
			fRec105[0] = max((fRec105[1] * fTemp269), fSlow98);
			float 	fTemp270 = min(1.0f, (0.9f * fRec105[0]));
			int 	iTemp271 = (fVec23[0] >= fRec103[1]);
			int 	iTemp272 = (fRec103[1] <= 0.001f);
			int 	iTemp273 = (((iRec102[1] >= 4)) ? (((iRec102[1] >= 6)) ? ((iTemp272) ? 0 : ((iTemp267) ? 1 : 6)) : (((iRec102[1] >= 5)) ? ((iTemp268) ? 3 : ((iTemp271) ? 4 : 5)) : ((iTemp268) ? 3 : (((fVec23[0] <= fRec103[1])) ? 5 : 4)))) : (((iRec102[1] >= 2)) ? (((iRec102[1] >= 3)) ? (((iTemp268 & iTemp272)) ? 0 : ((iTemp267) ? 1 : 3)) : ((iTemp268) ? 3 : ((iTemp271) ? ((iTemp268) ? 6 : 4) : 2))) : (((iRec102[1] >= 1)) ? (((fRec103[1] >= min(fTemp270, 1.0f))) ? ((iTemp268) ? 6 : 2) : 1) : ((iTemp267) ? 1 : 0))));
			iRec102[0] = iTemp273;
			fRec107[0] = max((fTemp269 * fRec107[1]), fSlow100);
			float 	fTemp274 = (((iTemp273 == 6)) ? (fConst24 * min(1.0f, (2.0f * fRec107[0]))) : (((iTemp273 >= 4)) ? (((iTemp273 >= 6)) ? fConst24 : fConst23) : (((iTemp273 >= 2)) ? (((iTemp273 >= 3)) ? fConst22 : fConst21) : (((iTemp273 >= 1)) ? fConst20 : 0.0f))));
			int 	iTemp275 = (iRec102[1] != iRec102[2]);
			iVec24[0] = iTemp275;
			int 	iTemp276 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec108[0] = ((iRec108[1] * (1 - iTemp276)) + (iTemp20 * iTemp276));
			float 	fTemp277 = min(19.0f, floorf((21.0f * (((fTemp274 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec108[0]))) / fTemp274) : 1.0f))));
			float 	fTemp278 = min((fTemp277 + 1.0f), 2e+01f);
			float 	fTemp279 = (((fTemp278 >= 11.0f)) ? (((fTemp278 >= 16.0f)) ? (((fTemp278 >= 19.0f)) ? (((fTemp278 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp278 >= 18.0f)) ? 0.03f : (((fTemp278 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp278 >= 14.0f)) ? (((fTemp278 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp278 >= 13.0f)) ? 0.14f : (((fTemp278 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp278 >= 6.0f)) ? (((fTemp278 >= 9.0f)) ? (((fTemp278 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp278 >= 8.0f)) ? 0.3f : (((fTemp278 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp278 >= 3.0f)) ? (((fTemp278 >= 5.0f)) ? 0.47f : (((fTemp278 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp278 >= 2.0f)) ? 0.74f : (((fTemp278 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec109[0] = iRec102[1];
			int 	iTemp280 = (iRec109[1] == iRec102[1]);
			int 	iTemp281 = (iRec102[1] == 0);
			fRec110[0] = ((iTemp281) ? fVec23[0] : ((iTemp280) ? min(min(fRec110[1], fVec23[0]), fRec103[1]) : min(fVec23[0], fRec103[1])));
			fRec111[0] = ((iTemp281) ? fVec23[0] : ((iTemp280) ? max(max(fRec111[1], fVec23[0]), fRec103[1]) : max(fVec23[0], fRec103[1])));
			int 	iTemp282 = ((iRec102[1] == 3) | (iRec102[1] == 6));
			fbargraph5 = float(iRec102[1]);
			float 	fTemp283 = (((fbargraph5 == 1.0f)) ? min(1.0f, fTemp270) : ((iTemp281) ? 0.0f : ((iTemp282) ? (fRec111[0] * fTemp279) : fVec23[0])));
			float 	fTemp284 = (1.0f / ((iTemp281) ? 0.0001f : ((iTemp282) ? (0.05f * (fTemp274 / ((((fTemp277 >= 11.0f)) ? (((fTemp277 >= 16.0f)) ? (((fTemp277 >= 19.0f)) ? (((fTemp277 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp277 >= 18.0f)) ? 0.03f : (((fTemp277 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp277 >= 14.0f)) ? (((fTemp277 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp277 >= 13.0f)) ? 0.14f : (((fTemp277 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp277 >= 6.0f)) ? (((fTemp277 >= 9.0f)) ? (((fTemp277 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp277 >= 8.0f)) ? 0.3f : (((fTemp277 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp277 >= 3.0f)) ? (((fTemp277 >= 5.0f)) ? 0.47f : (((fTemp277 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp277 >= 2.0f)) ? 0.74f : (((fTemp277 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp279))) : fTemp274)));
			float 	fTemp285 = (fRec106[1] - fTemp284);
			float 	fTemp286 = (fRec106[1] + fTemp284);
			fRec106[0] = (((fTemp286 < fTemp283)) ? fTemp286 : (((fTemp285 > fTemp283)) ? fTemp285 : fTemp283));
			fRec103[0] = fRec106[0];
			fRec101[0] = (fRec103[0] - (fConst19 * ((fConst17 * fRec101[2]) + (fConst15 * fRec101[1]))));
			float 	fTemp287 = min(0.99f, (fConst25 * (((3947.8418f * fRec101[0]) + (7895.6836f * fRec101[1])) + (3947.8418f * fRec101[2]))));
			float 	fTemp288 = (fVec23[0] - fTemp287);
			float 	fTemp289 = min(0.8f, max(0.0f, (max(-0.75f, fTemp288) + fSlow96)));
			float 	fTemp290 = ((iTemp2) ? 0.0f : (fSlow101 + fRec112[1]));
			fRec112[0] = (fTemp290 - floorf(fTemp290));
			float 	fTemp291 = (499.0f * fRec112[0]);
			int 	iTemp292 = int(fTemp291);
			int 	iTemp293 = max(0, min(iTemp292, 499));
			float 	fTemp294 = ftbl2[iTemp293];
			int 	iTemp295 = max(0, min((iTemp292 + 1), 499));
			float 	fTemp296 = (fTemp291 - float(iTemp292));
			float 	fTemp297 = min(1.0f, (max(min((3.0f * fTemp288), 0.3f), -0.13f) + 0.15f));
			float 	fTemp298 = ftbl0[iTemp293];
			fRec0[0] = ((1.37f * ((((((fTemp287 * ((((((fTemp298 + (fTemp296 * (ftbl0[iTemp295] - fTemp298))) * (1.0f - fTemp297)) + (fTemp297 * (fTemp294 + (fTemp296 * (ftbl2[iTemp295] - fTemp294))))) * (1.0f - (fTemp289 + fSlow88))) + (0.5f * (fTemp289 * (((2.0f * fRec100) + -1.0f) + ((2.0f * fRec98) + -1.0f))))) + (fSlow88 * ((0.33f * (fTemp257 + ((fTemp255 - float(iTemp256)) * (ftbl0[max(0, min((iTemp256 + 1), 499))] - fTemp257)))) + (0.67f * (fTemp253 + ((fTemp251 - float(iTemp252)) * (ftbl0[max(0, min((iTemp252 + 1), 499))] - fTemp253)))))))) + (fTemp238 * ((((((fTemp249 + (fTemp247 * (ftbl0[iTemp246] - fTemp249))) * (1.0f - fTemp248)) + (fTemp248 * (fTemp245 + (fTemp247 * (ftbl2[iTemp246] - fTemp245))))) * (1.0f - (fTemp240 + fSlow71))) + (0.5f * (fTemp240 * (((2.0f * fRec82) + -1.0f) + ((2.0f * fRec80) + -1.0f))))) + (fSlow71 * ((0.33f * (fTemp208 + ((fTemp206 - float(iTemp207)) * (ftbl0[max(0, min((iTemp207 + 1), 499))] - fTemp208)))) + (0.67f * (fTemp204 + ((fTemp202 - float(iTemp203)) * (ftbl0[max(0, min((iTemp203 + 1), 499))] - fTemp204))))))))) + (fTemp189 * ((((((fTemp200 + (fTemp198 * (ftbl0[iTemp197] - fTemp200))) * (1.0f - fTemp199)) + (fTemp199 * (fTemp196 + (fTemp198 * (ftbl2[iTemp197] - fTemp196))))) * (1.0f - (fTemp191 + fSlow54))) + (0.5f * (fTemp191 * (((2.0f * fRec64) + -1.0f) + ((2.0f * fRec62) + -1.0f))))) + (fSlow54 * ((0.33f * (fTemp159 + ((fTemp157 - float(iTemp158)) * (ftbl0[max(0, min((iTemp158 + 1), 499))] - fTemp159)))) + (0.67f * (fTemp155 + ((fTemp153 - float(iTemp154)) * (ftbl0[max(0, min((iTemp154 + 1), 499))] - fTemp155))))))))) + (fTemp140 * ((((((fTemp151 + (fTemp149 * (ftbl0[iTemp148] - fTemp151))) * (1.0f - fTemp150)) + (fTemp150 * (fTemp147 + (fTemp149 * (ftbl2[iTemp148] - fTemp147))))) * (1.0f - (fTemp142 + fSlow37))) + (0.5f * (fTemp142 * (((2.0f * fRec46) + -1.0f) + ((2.0f * fRec44) + -1.0f))))) + (fSlow37 * ((0.33f * (fTemp110 + ((fTemp108 - float(iTemp109)) * (ftbl0[max(0, min((iTemp109 + 1), 499))] - fTemp110)))) + (0.67f * (fTemp106 + ((fTemp104 - float(iTemp105)) * (ftbl0[max(0, min((iTemp105 + 1), 499))] - fTemp106))))))))) + (fTemp91 * ((((((fTemp102 + (fTemp100 * (ftbl0[iTemp99] - fTemp102))) * (1.0f - fTemp101)) + (fTemp101 * (fTemp98 + (fTemp100 * (ftbl2[iTemp99] - fTemp98))))) * (1.0f - (fTemp93 + fSlow20))) + (0.5f * (fTemp93 * (((2.0f * fRec28) + -1.0f) + ((2.0f * fRec26) + -1.0f))))) + (fSlow20 * ((0.33f * (fTemp61 + ((fTemp59 - float(iTemp60)) * (ftbl0[max(0, min((iTemp60 + 1), 499))] - fTemp61)))) + (0.67f * (fTemp57 + ((fTemp55 - float(iTemp56)) * (ftbl0[max(0, min((iTemp56 + 1), 499))] - fTemp57))))))))) + (fTemp42 * ((((((fTemp53 + (fTemp51 * (ftbl0[iTemp50] - fTemp53))) * (1.0f - fTemp52)) + (fTemp52 * (fTemp49 + (fTemp51 * (ftbl2[iTemp50] - fTemp49))))) * (1.0f - (fTemp44 + fSlow3))) + (0.5f * (fTemp44 * (((2.0f * fRec7) + -1.0f) + ((2.0f * fRec5) + -1.0f))))) + (fSlow3 * ((0.33f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl0[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.67f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
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
