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
				float 	fTemp13 = ((0.002002002f * float((iRec4[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp13)) + -1.0f))) * float(((fTemp13 > 0.0f) - (fTemp13 < 0.0f))));
				// post processing
				iRec4[1] = iRec4[0];
			}
		}
	};


	class SIG2 {
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
				int 	iTemp25 = int((1.05f * float((iRec13[0] + -1))));
				output[i] = (((iTemp25 >= 11)) ? (((iTemp25 >= 16)) ? (((iTemp25 >= 19)) ? (((iTemp25 >= 20)) ? 0.0f : 0.01f) : (((iTemp25 >= 18)) ? 0.03f : (((iTemp25 >= 17)) ? 0.06f : 0.08f))) : (((iTemp25 >= 14)) ? (((iTemp25 >= 15)) ? 0.1f : 0.12f) : (((iTemp25 >= 13)) ? 0.14f : (((iTemp25 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp25 >= 6)) ? (((iTemp25 >= 9)) ? (((iTemp25 >= 10)) ? 0.22f : 0.26f) : (((iTemp25 >= 8)) ? 0.3f : (((iTemp25 >= 7)) ? 0.35f : 0.4f))) : (((iTemp25 >= 3)) ? (((iTemp25 >= 5)) ? 0.47f : (((iTemp25 >= 4)) ? 0.55f : 0.64f)) : (((iTemp25 >= 2)) ? 0.74f : (((iTemp25 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec13[1] = iRec13[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec25[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec25[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec25[0] = (iRec25[1] + 1);
				output[i] = ((0.004008016f * float((iRec25[0] + -1))) + -1.0f);
				// post processing
				iRec25[1] = iRec25[0];
			}
		}
	};


	class SIG4 {
	  private:
		int fSampleRate;
		int 	iRec27[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec27[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec27[0] = (iRec27[1] + 1);
				output[i] = sinf((0.012591554f * float((iRec27[0] + -1))));
				// post processing
				iRec27[1] = iRec27[0];
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
	static float 	ftbl1[1000];
	FAUSTFLOAT 	fslider1;
	float 	fConst14;
	float 	fConst16;
	float 	fConst18;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec9[2];
	int 	iRec8[2];
	float 	fConst19;
	float 	fVec3[2];
	float 	fRec10[2];
	float 	fRec11[2];
	int 	iRec6[3];
	static float 	ftbl2[21];
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	int 	iVec4[2];
	int 	iRec14[2];
	int 	iRec15[2];
	float 	fRec16[2];
	float 	fRec17[2];
	float 	fRec12[2];
	float 	fRec7[2];
	float 	fRec5[3];
	float 	fConst24;
	float 	fConst25;
	float 	fRec18[2];
	float 	fRec19[2];
	float 	fRec21[2];
	int 	iRec24[2];
	float 	fRec23[3];
	static float 	ftbl3[500];
	float 	fConst26;
	float 	fRec26[2];
	static float 	ftbl4[500];
	FAUSTFLOAT 	fslider4;
	float 	fRec28[2];
	float 	fRec29[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec33[2];
	float 	fVec7[2];
	float 	fRec34[2];
	float 	fRec35[2];
	int 	iRec31[3];
	int 	iVec8[2];
	int 	iRec37[2];
	int 	iRec38[2];
	float 	fRec39[2];
	float 	fRec40[2];
	float 	fRec36[2];
	float 	fRec32[2];
	float 	fRec30[3];
	float 	fRec41[2];
	float 	fRec42[2];
	float 	fRec44[2];
	float 	fRec46[3];
	float 	fRec47[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec48[2];
	float 	fRec49[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec53[2];
	float 	fVec11[2];
	float 	fRec54[2];
	float 	fRec55[2];
	int 	iRec51[3];
	int 	iVec12[2];
	int 	iRec57[2];
	int 	iRec58[2];
	float 	fRec59[2];
	float 	fRec60[2];
	float 	fRec56[2];
	float 	fRec52[2];
	float 	fRec50[3];
	float 	fRec61[2];
	float 	fRec62[2];
	float 	fRec64[2];
	float 	fRec66[3];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec68[2];
	float 	fRec69[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec73[2];
	float 	fVec15[2];
	float 	fRec74[2];
	float 	fRec75[2];
	int 	iRec71[3];
	int 	iVec16[2];
	int 	iRec77[2];
	int 	iRec78[2];
	float 	fRec79[2];
	float 	fRec80[2];
	float 	fRec76[2];
	float 	fRec72[2];
	float 	fRec70[3];
	float 	fRec81[2];
	float 	fRec82[2];
	float 	fRec84[2];
	float 	fRec86[3];
	float 	fRec87[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec88[2];
	float 	fRec89[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec93[2];
	float 	fVec19[2];
	float 	fRec94[2];
	float 	fRec95[2];
	int 	iRec91[3];
	int 	iVec20[2];
	int 	iRec97[2];
	int 	iRec98[2];
	float 	fRec99[2];
	float 	fRec100[2];
	float 	fRec96[2];
	float 	fRec92[2];
	float 	fRec90[3];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec104[2];
	float 	fRec106[3];
	float 	fRec107[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec108[2];
	float 	fRec109[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec113[2];
	float 	fVec23[2];
	float 	fRec114[2];
	float 	fRec115[2];
	int 	iRec111[3];
	int 	iVec24[2];
	int 	iRec117[2];
	int 	iRec118[2];
	float 	fRec119[2];
	float 	fRec120[2];
	float 	fRec116[2];
	float 	fRec112[2];
	float 	fRec110[3];
	float 	fRec121[2];
	float 	fRec122[2];
	float 	fRec124[2];
	float 	fRec126[3];
	float 	fRec127[2];
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
		sig2.fill(21,ftbl2);
		SIG3 sig3;
		sig3.init(sample_rate);
		sig3.fill(500,ftbl3);
		SIG4 sig4;
		sig4.init(sample_rate);
		sig4.fill(500,ftbl4);
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
		fConst9 = (16.351599f / fConst0);
		fConst10 = (4.0878997f / fConst0);
		float 	fConst11 = powf((62.831852f / fConst0),2.0f);
		float 	fConst12 = ((fConst11 * ((0.2033f * fConst11) + 0.31755f)) + 1.0f);
		float 	fConst13 = powf(fConst12,2.0f);
		fConst14 = (2.0f * ((3947.8418f * (fConst13 / fConst1)) + -1.0f));
		float 	fConst15 = (3947.8418f * (fConst12 / fConst0));
		fConst16 = (((fConst12 * (fConst15 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst17 = (((fConst12 * (fConst15 + 88.49557f)) / fConst0) + 1.0f);
		fConst18 = (1.0f / fConst17);
		fConst19 = (1.0f / fConst0);
		fConst20 = (0.1f * fConst0);
		fConst21 = (0.4f * fConst0);
		fConst22 = (0.15f * fConst0);
		fConst23 = (0.2f * fConst0);
		fConst24 = (fConst13 / (fConst1 * fConst17));
		fConst25 = (2.0439498f / fConst0);
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
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) iRec24[i] = 0;
		for (int i=0; i<3; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec33[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<3; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec53[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<3; i++) iRec51[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec77[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec93[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) iRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<3; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<3; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec113[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<3; i++) iRec111[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec117[i] = 0;
		for (int i=0; i<2; i++) iRec118[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<3; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<3; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec127[i] = 0;
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
		float 	fSlow4 = ftbl1[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (1.0f - fSlow4);
		int 	iSlow6 = (fSlow4 < 0.0f);
		float 	fSlow7 = (0.05f - ((iSlow6) ? (0.5f * fSlow4) : fSlow4));
		float 	fSlow8 = float(fslider2);
		float 	fSlow9 = float(fslider3);
		int 	iSlow10 = (fSlow9 == 0.0f);
		float 	fSlow11 = (0.9f * fSlow9);
		float 	fSlow12 = (0.0f - fSlow11);
		float 	fSlow13 = (fSlow4 * ((((8.175799f * fSlow0) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow14 = (fConst25 * fSlow0);
		float 	fSlow15 = max(1.1920929e-07f, fabsf((8.067899f * fSlow0)));
		float 	fSlow16 = (fConst19 * fSlow15);
		float 	fSlow17 = (1.0f - (fConst0 / fSlow15));
		float 	fSlow18 = max(1.1920929e-07f, fabsf((8.285142f * fSlow0)));
		float 	fSlow19 = (fConst19 * fSlow18);
		float 	fSlow20 = (1.0f - (fConst0 / fSlow18));
		float 	fSlow21 = (2.0f * ((2.9708306e-07f * powf(fSlow0,2.0f)) + -1.0f));
		float 	fSlow22 = (2.9708306e-07f * fSlow0);
		float 	fSlow23 = ((fSlow0 * (fSlow22 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow24 = ((fSlow0 * (fSlow22 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow25 = (1.0f / fSlow24);
		int 	iSlow26 = (fSlow4 > 0.0f);
		float 	fSlow27 = ((iSlow26) ? fSlow3 : 0.0f);
		float 	fSlow28 = (5.3436593e-06f * (fSlow0 / fSlow24));
		float 	fSlow29 = (fConst26 * fSlow0);
		float 	fSlow30 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow31 = (fConst9 * fSlow30);
		float 	fSlow32 = (fConst10 * fSlow30);
		float 	fSlow33 = float(fslider5);
		float 	fSlow34 = ftbl1[int(((499.5f * (fSlow33 + 1.0f)) + 0.5f))];
		float 	fSlow35 = (1.0f - fSlow34);
		int 	iSlow36 = (fSlow34 < 0.0f);
		float 	fSlow37 = (0.05f - ((iSlow36) ? (0.5f * fSlow34) : fSlow34));
		float 	fSlow38 = float(fslider6);
		float 	fSlow39 = float(fslider7);
		int 	iSlow40 = (fSlow39 == 0.0f);
		float 	fSlow41 = (0.9f * fSlow39);
		float 	fSlow42 = (0.0f - fSlow41);
		float 	fSlow43 = (fSlow34 * ((((8.175799f * fSlow30) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow44 = (fConst25 * fSlow30);
		float 	fSlow45 = max(1.1920929e-07f, fabsf((8.067899f * fSlow30)));
		float 	fSlow46 = (fConst19 * fSlow45);
		float 	fSlow47 = (1.0f - (fConst0 / fSlow45));
		float 	fSlow48 = max(1.1920929e-07f, fabsf((8.285142f * fSlow30)));
		float 	fSlow49 = (fConst19 * fSlow48);
		float 	fSlow50 = (1.0f - (fConst0 / fSlow48));
		float 	fSlow51 = (2.0f * ((2.9708306e-07f * powf(fSlow30,2.0f)) + -1.0f));
		float 	fSlow52 = (2.9708306e-07f * fSlow30);
		float 	fSlow53 = ((fSlow30 * (fSlow52 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow54 = ((fSlow30 * (fSlow52 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow55 = (1.0f / fSlow54);
		int 	iSlow56 = (fSlow34 > 0.0f);
		float 	fSlow57 = ((iSlow56) ? fSlow33 : 0.0f);
		float 	fSlow58 = (5.3436593e-06f * (fSlow30 / fSlow54));
		float 	fSlow59 = (fConst26 * fSlow30);
		float 	fSlow60 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow61 = (fConst9 * fSlow60);
		float 	fSlow62 = (fConst10 * fSlow60);
		float 	fSlow63 = float(fslider9);
		float 	fSlow64 = ftbl1[int(((499.5f * (fSlow63 + 1.0f)) + 0.5f))];
		float 	fSlow65 = (1.0f - fSlow64);
		int 	iSlow66 = (fSlow64 < 0.0f);
		float 	fSlow67 = (0.05f - ((iSlow66) ? (0.5f * fSlow64) : fSlow64));
		float 	fSlow68 = float(fslider10);
		float 	fSlow69 = float(fslider11);
		int 	iSlow70 = (fSlow69 == 0.0f);
		float 	fSlow71 = (0.9f * fSlow69);
		float 	fSlow72 = (0.0f - fSlow71);
		float 	fSlow73 = (fSlow64 * ((((8.175799f * fSlow60) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow74 = (fConst25 * fSlow60);
		float 	fSlow75 = max(1.1920929e-07f, fabsf((8.067899f * fSlow60)));
		float 	fSlow76 = (fConst19 * fSlow75);
		float 	fSlow77 = (1.0f - (fConst0 / fSlow75));
		float 	fSlow78 = max(1.1920929e-07f, fabsf((8.285142f * fSlow60)));
		float 	fSlow79 = (fConst19 * fSlow78);
		float 	fSlow80 = (1.0f - (fConst0 / fSlow78));
		float 	fSlow81 = (2.0f * ((2.9708306e-07f * powf(fSlow60,2.0f)) + -1.0f));
		float 	fSlow82 = (2.9708306e-07f * fSlow60);
		float 	fSlow83 = ((fSlow60 * (fSlow82 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow84 = ((fSlow60 * (fSlow82 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow85 = (1.0f / fSlow84);
		int 	iSlow86 = (fSlow64 > 0.0f);
		float 	fSlow87 = ((iSlow86) ? fSlow63 : 0.0f);
		float 	fSlow88 = (5.3436593e-06f * (fSlow60 / fSlow84));
		float 	fSlow89 = (fConst26 * fSlow60);
		float 	fSlow90 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow91 = (fConst9 * fSlow90);
		float 	fSlow92 = (fConst10 * fSlow90);
		float 	fSlow93 = float(fslider13);
		float 	fSlow94 = ftbl1[int(((499.5f * (fSlow93 + 1.0f)) + 0.5f))];
		float 	fSlow95 = (1.0f - fSlow94);
		int 	iSlow96 = (fSlow94 < 0.0f);
		float 	fSlow97 = (0.05f - ((iSlow96) ? (0.5f * fSlow94) : fSlow94));
		float 	fSlow98 = float(fslider14);
		float 	fSlow99 = float(fslider15);
		int 	iSlow100 = (fSlow99 == 0.0f);
		float 	fSlow101 = (0.9f * fSlow99);
		float 	fSlow102 = (0.0f - fSlow101);
		float 	fSlow103 = (fSlow94 * ((((8.175799f * fSlow90) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow104 = (fConst25 * fSlow90);
		float 	fSlow105 = max(1.1920929e-07f, fabsf((8.067899f * fSlow90)));
		float 	fSlow106 = (fConst19 * fSlow105);
		float 	fSlow107 = (1.0f - (fConst0 / fSlow105));
		float 	fSlow108 = max(1.1920929e-07f, fabsf((8.285142f * fSlow90)));
		float 	fSlow109 = (fConst19 * fSlow108);
		float 	fSlow110 = (1.0f - (fConst0 / fSlow108));
		float 	fSlow111 = (2.0f * ((2.9708306e-07f * powf(fSlow90,2.0f)) + -1.0f));
		float 	fSlow112 = (2.9708306e-07f * fSlow90);
		float 	fSlow113 = ((fSlow90 * (fSlow112 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow114 = ((fSlow90 * (fSlow112 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow115 = (1.0f / fSlow114);
		int 	iSlow116 = (fSlow94 > 0.0f);
		float 	fSlow117 = ((iSlow116) ? fSlow93 : 0.0f);
		float 	fSlow118 = (5.3436593e-06f * (fSlow90 / fSlow114));
		float 	fSlow119 = (fConst26 * fSlow90);
		float 	fSlow120 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow121 = (fConst9 * fSlow120);
		float 	fSlow122 = (fConst10 * fSlow120);
		float 	fSlow123 = float(fslider17);
		float 	fSlow124 = ftbl1[int(((499.5f * (fSlow123 + 1.0f)) + 0.5f))];
		float 	fSlow125 = (1.0f - fSlow124);
		int 	iSlow126 = (fSlow124 < 0.0f);
		float 	fSlow127 = (0.05f - ((iSlow126) ? (0.5f * fSlow124) : fSlow124));
		float 	fSlow128 = float(fslider18);
		float 	fSlow129 = float(fslider19);
		int 	iSlow130 = (fSlow129 == 0.0f);
		float 	fSlow131 = (0.9f * fSlow129);
		float 	fSlow132 = (0.0f - fSlow131);
		float 	fSlow133 = (fSlow124 * ((((8.175799f * fSlow120) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow134 = (fConst25 * fSlow120);
		float 	fSlow135 = max(1.1920929e-07f, fabsf((8.067899f * fSlow120)));
		float 	fSlow136 = (fConst19 * fSlow135);
		float 	fSlow137 = (1.0f - (fConst0 / fSlow135));
		float 	fSlow138 = max(1.1920929e-07f, fabsf((8.285142f * fSlow120)));
		float 	fSlow139 = (fConst19 * fSlow138);
		float 	fSlow140 = (1.0f - (fConst0 / fSlow138));
		float 	fSlow141 = (2.0f * ((2.9708306e-07f * powf(fSlow120,2.0f)) + -1.0f));
		float 	fSlow142 = (2.9708306e-07f * fSlow120);
		float 	fSlow143 = ((fSlow120 * (fSlow142 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow144 = ((fSlow120 * (fSlow142 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow145 = (1.0f / fSlow144);
		int 	iSlow146 = (fSlow124 > 0.0f);
		float 	fSlow147 = ((iSlow146) ? fSlow123 : 0.0f);
		float 	fSlow148 = (5.3436593e-06f * (fSlow120 / fSlow144));
		float 	fSlow149 = (fConst26 * fSlow120);
		float 	fSlow150 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow151 = (fConst9 * fSlow150);
		float 	fSlow152 = (fConst10 * fSlow150);
		float 	fSlow153 = float(fslider21);
		float 	fSlow154 = ftbl1[int(((499.5f * (fSlow153 + 1.0f)) + 0.5f))];
		float 	fSlow155 = (1.0f - fSlow154);
		int 	iSlow156 = (fSlow154 < 0.0f);
		float 	fSlow157 = (0.05f - ((iSlow156) ? (0.5f * fSlow154) : fSlow154));
		float 	fSlow158 = float(fslider22);
		float 	fSlow159 = float(fslider23);
		int 	iSlow160 = (fSlow159 == 0.0f);
		float 	fSlow161 = (0.9f * fSlow159);
		float 	fSlow162 = (0.0f - fSlow161);
		float 	fSlow163 = (fSlow154 * ((((8.175799f * fSlow150) >= 8e+01f)) ? 0.1f : 0.0f));
		float 	fSlow164 = (fConst25 * fSlow150);
		float 	fSlow165 = max(1.1920929e-07f, fabsf((8.067899f * fSlow150)));
		float 	fSlow166 = (fConst19 * fSlow165);
		float 	fSlow167 = (1.0f - (fConst0 / fSlow165));
		float 	fSlow168 = max(1.1920929e-07f, fabsf((8.285142f * fSlow150)));
		float 	fSlow169 = (fConst19 * fSlow168);
		float 	fSlow170 = (1.0f - (fConst0 / fSlow168));
		float 	fSlow171 = (2.0f * ((2.9708306e-07f * powf(fSlow150,2.0f)) + -1.0f));
		float 	fSlow172 = (2.9708306e-07f * fSlow150);
		float 	fSlow173 = ((fSlow150 * (fSlow172 + -5.3436593e-06f)) + 1.0f);
		float 	fSlow174 = ((fSlow150 * (fSlow172 + 5.3436593e-06f)) + 1.0f);
		float 	fSlow175 = (1.0f / fSlow174);
		int 	iSlow176 = (fSlow154 > 0.0f);
		float 	fSlow177 = ((iSlow176) ? fSlow153 : 0.0f);
		float 	fSlow178 = (5.3436593e-06f * (fSlow150 / fSlow174));
		float 	fSlow179 = (fConst26 * fSlow150);
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
			float 	fTemp11 = (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl0[max(0, min((iTemp9 + 1), 499))] - fTemp10)));
			float 	fTemp12 = (fTemp11 + (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6))));
			fVec1[0] = fSlow9;
			int 	iTemp14 = (fSlow11 != (0.9f * fVec1[1]));
			iVec2[0] = iTemp14;
			int 	iTemp15 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec9[0] = (iRec9[1] + 1);
			int 	iTemp16 = (iRec9[0] + -1);
			iRec8[0] = ((iRec8[1] * (1 - iTemp15)) + (iTemp16 * iTemp15));
			float 	fTemp17 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec8[0])))) > 0.5f) & iSlow10)) ? 0.0f : fSlow8) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp17;
			int 	iTemp18 = (fVec3[0] > 0.003f);
			int 	iTemp19 = (fVec3[0] <= 0.003f);
			float 	fTemp20 = float((iTemp19 | (fVec3[1] >= 0.003f)));
			fRec10[0] = max((fRec10[1] * fTemp20), fSlow11);
			fRec11[0] = max((fTemp20 * fRec11[1]), fSlow12);
			float 	fTemp21 = (min(1.0f, fRec11[0]) + min(1.0f, fRec10[0]));
			int 	iTemp22 = (fVec3[0] >= fRec7[1]);
			int 	iTemp23 = (fRec7[1] <= 0.001f);
			int 	iTemp24 = (((iRec6[1] >= 4)) ? (((iRec6[1] >= 6)) ? ((iTemp23) ? 0 : ((iTemp18) ? 1 : 6)) : (((iRec6[1] >= 5)) ? ((iTemp19) ? 3 : ((iTemp22) ? 4 : 5)) : ((iTemp19) ? 3 : (((fVec3[0] <= fRec7[1])) ? 5 : 4)))) : (((iRec6[1] >= 2)) ? (((iRec6[1] >= 3)) ? (((iTemp19 & iTemp23)) ? 0 : ((iTemp18) ? 1 : 3)) : ((iTemp19) ? 6 : ((iTemp22) ? 4 : 2))) : (((iRec6[1] >= 1)) ? (((fRec7[1] >= min(fTemp21, 1.0f))) ? ((iTemp19) ? 6 : 2) : 1) : ((iTemp18) ? 1 : 0))));
			iRec6[0] = iTemp24;
			float 	fTemp26 = (((iTemp24 >= 4)) ? (((iTemp24 >= 6)) ? fConst0 : fConst23) : (((iTemp24 >= 2)) ? (((iTemp24 >= 3)) ? fConst22 : fConst21) : (((iTemp24 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp27 = (iRec6[1] != iRec6[2]);
			iVec4[0] = iTemp27;
			int 	iTemp28 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec14[0] = ((iRec14[1] * (1 - iTemp28)) + (iTemp16 * iTemp28));
			float 	fTemp29 = (2e+01f * (((fTemp26 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec14[0]))) / fTemp26) : 0.0f));
			int 	iTemp30 = int(fTemp29);
			float 	fTemp31 = ftbl2[max(0, int(min(int(iTemp30), 20)))];
			float 	fTemp32 = (fTemp31 + ((fTemp29 - float(iTemp30)) * (ftbl2[max(0, int(min(int((iTemp30 + 1)), 20)))] - fTemp31)));
			iRec15[0] = iRec6[1];
			int 	iTemp33 = (iRec15[1] == iRec6[1]);
			int 	iTemp34 = (iRec6[1] == 0);
			fRec16[0] = ((iTemp34) ? fVec3[0] : ((iTemp33) ? min(min(fRec16[1], fVec3[0]), fRec7[1]) : min(fVec3[0], fRec7[1])));
			fRec17[0] = ((iTemp34) ? fVec3[0] : ((iTemp33) ? max(max(fRec17[1], fVec3[0]), fRec7[1]) : max(fVec3[0], fRec7[1])));
			int 	iTemp35 = (iRec6[1] == 3);
			int 	iTemp36 = (iRec6[1] == 6);
			float 	fTemp37 = (((iRec6[1] == 1)) ? min(1.0f, fTemp21) : ((iTemp34) ? 0.0f : ((iTemp36) ? (fTemp21 * fTemp32) : ((iTemp35) ? (fRec17[0] * fTemp32) : fVec3[0]))));
			float 	fTemp38 = (1.0f / ((iTemp34) ? 0.0001f : (((iTemp35 | iTemp36)) ? (0.04761905f * fTemp26) : fTemp26)));
			float 	fTemp39 = (fRec12[1] - fTemp38);
			float 	fTemp40 = (fRec12[1] + fTemp38);
			fRec12[0] = (((fTemp40 < fTemp37)) ? fTemp40 : (((fTemp39 > fTemp37)) ? fTemp39 : fTemp37));
			fRec7[0] = fRec12[0];
			fRec5[0] = (fRec7[0] - (fConst18 * ((fConst16 * fRec5[2]) + (fConst14 * fRec5[1]))));
			float 	fTemp41 = min(0.99f, (fConst24 * (((3947.8418f * fRec5[0]) + (7895.6836f * fRec5[1])) + (3947.8418f * fRec5[2]))));
			float 	fTemp42 = (fVec3[0] - fTemp41);
			float 	fTemp43 = min(0.8f, max(0.0f, (max(-0.75f, fTemp42) + fSlow7)));
			float 	fTemp44 = max(0.0f, (fVec3[0] + (-0.5f - (fSlow13 + (fTemp41 + fTemp43)))));
			float 	fTemp45 = ((iTemp2) ? 0.0f : (fSlow14 + fRec18[1]));
			fRec18[0] = (fTemp45 - floorf(fTemp45));
			float 	fTemp46 = (499.0f * fRec18[0]);
			int 	iTemp47 = int(fTemp46);
			float 	fTemp48 = ftbl0[max(0, min(iTemp47, 499))];
			float 	fTemp49 = (fSlow16 + (fRec19[1] + -1.0f));
			float 	fTemp50 = (fSlow16 + fRec19[1]);
			int 	iTemp51 = (fTemp49 < 0.0f);
			fRec19[0] = ((iTemp51) ? fTemp50 : fTemp49);
			float 	fRec20 = ((iTemp51) ? fTemp50 : (fSlow16 + (fRec19[1] + (fSlow17 * fTemp49))));
			float 	fTemp52 = (fSlow19 + (fRec21[1] + -1.0f));
			float 	fTemp53 = (fSlow19 + fRec21[1]);
			int 	iTemp54 = (fTemp52 < 0.0f);
			fRec21[0] = ((iTemp54) ? fTemp53 : fTemp52);
			float 	fRec22 = ((iTemp54) ? fTemp53 : (fSlow19 + (fRec21[1] + (fSlow20 * fTemp52))));
			iRec24[0] = ((1103515245 * iRec24[1]) + 12345);
			float 	fTemp55 = (4.656613e-10f * float(iRec24[0]));
			fRec23[0] = (fTemp55 - (fSlow25 * ((fSlow23 * fRec23[2]) + (fSlow21 * fRec23[1]))));
			float 	fTemp56 = ((0.3f * (1.0f - fVec3[0])) + fSlow27);
			float 	fTemp57 = ((iTemp2) ? 0.0f : (fSlow29 + fRec26[1]));
			fRec26[0] = (fTemp57 - floorf(fTemp57));
			float 	fTemp58 = (499.0f * fRec26[0]);
			int 	iTemp59 = int(fTemp58);
			int 	iTemp60 = max(0, min(iTemp59, 499));
			float 	fTemp61 = ftbl3[iTemp60];
			int 	iTemp62 = max(0, min((iTemp59 + 1), 499));
			float 	fTemp63 = (fTemp58 - float(iTemp59));
			float 	fTemp64 = min(1.0f, (max(min((3.0f * fTemp42), 0.3f), -0.2f) + 0.15f));
			float 	fTemp65 = ftbl0[iTemp60];
			float 	fTemp66 = (((fTemp65 + (fTemp63 * (ftbl0[iTemp62] - fTemp65))) * (1.0f - fTemp64)) + (fTemp64 * (fTemp61 + (fTemp63 * (ftbl3[iTemp62] - fTemp61)))));
			float 	fTemp67 = ftbl4[iTemp60];
			float 	fTemp68 = ((iTemp2) ? 0.0f : (fSlow31 + fRec28[1]));
			fRec28[0] = (fTemp68 - floorf(fTemp68));
			float 	fTemp69 = (499.0f * fRec28[0]);
			int 	iTemp70 = int(fTemp69);
			float 	fTemp71 = ftbl0[max(0, min(iTemp70, 499))];
			float 	fTemp72 = ((iTemp2) ? 0.0f : (fSlow32 + fRec29[1]));
			fRec29[0] = (fTemp72 - floorf(fTemp72));
			float 	fTemp73 = (499.0f * fRec29[0]);
			int 	iTemp74 = int(fTemp73);
			float 	fTemp75 = ftbl0[max(0, min(iTemp74, 499))];
			float 	fTemp76 = (fTemp75 + ((fTemp73 - float(iTemp74)) * (ftbl0[max(0, min((iTemp74 + 1), 499))] - fTemp75)));
			float 	fTemp77 = (fTemp76 + (fTemp71 + ((fTemp69 - float(iTemp70)) * (ftbl0[max(0, min((iTemp70 + 1), 499))] - fTemp71))));
			fVec5[0] = fSlow39;
			int 	iTemp78 = (fSlow41 != (0.9f * fVec5[1]));
			iVec6[0] = iTemp78;
			int 	iTemp79 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec33[0] = ((iRec33[1] * (1 - iTemp79)) + (iTemp16 * iTemp79));
			float 	fTemp80 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec33[0])))) > 0.5f) & iSlow40)) ? 0.0f : fSlow38) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp80;
			int 	iTemp81 = (fVec7[0] > 0.003f);
			int 	iTemp82 = (fVec7[0] <= 0.003f);
			float 	fTemp83 = float((iTemp82 | (fVec7[1] >= 0.003f)));
			fRec34[0] = max((fRec34[1] * fTemp83), fSlow41);
			fRec35[0] = max((fTemp83 * fRec35[1]), fSlow42);
			float 	fTemp84 = (min(1.0f, fRec35[0]) + min(1.0f, fRec34[0]));
			int 	iTemp85 = (fVec7[0] >= fRec32[1]);
			int 	iTemp86 = (fRec32[1] <= 0.001f);
			int 	iTemp87 = (((iRec31[1] >= 4)) ? (((iRec31[1] >= 6)) ? ((iTemp86) ? 0 : ((iTemp81) ? 1 : 6)) : (((iRec31[1] >= 5)) ? ((iTemp82) ? 3 : ((iTemp85) ? 4 : 5)) : ((iTemp82) ? 3 : (((fVec7[0] <= fRec32[1])) ? 5 : 4)))) : (((iRec31[1] >= 2)) ? (((iRec31[1] >= 3)) ? (((iTemp82 & iTemp86)) ? 0 : ((iTemp81) ? 1 : 3)) : ((iTemp82) ? 6 : ((iTemp85) ? 4 : 2))) : (((iRec31[1] >= 1)) ? (((fRec32[1] >= min(fTemp84, 1.0f))) ? ((iTemp82) ? 6 : 2) : 1) : ((iTemp81) ? 1 : 0))));
			iRec31[0] = iTemp87;
			float 	fTemp88 = (((iTemp87 >= 4)) ? (((iTemp87 >= 6)) ? fConst0 : fConst23) : (((iTemp87 >= 2)) ? (((iTemp87 >= 3)) ? fConst22 : fConst21) : (((iTemp87 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp89 = (iRec31[1] != iRec31[2]);
			iVec8[0] = iTemp89;
			int 	iTemp90 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec37[0] = ((iRec37[1] * (1 - iTemp90)) + (iTemp16 * iTemp90));
			float 	fTemp91 = (2e+01f * (((fTemp88 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec37[0]))) / fTemp88) : 0.0f));
			int 	iTemp92 = int(fTemp91);
			float 	fTemp93 = ftbl2[max(0, int(min(int(iTemp92), 20)))];
			float 	fTemp94 = (fTemp93 + ((fTemp91 - float(iTemp92)) * (ftbl2[max(0, int(min(int((iTemp92 + 1)), 20)))] - fTemp93)));
			iRec38[0] = iRec31[1];
			int 	iTemp95 = (iRec38[1] == iRec31[1]);
			int 	iTemp96 = (iRec31[1] == 0);
			fRec39[0] = ((iTemp96) ? fVec7[0] : ((iTemp95) ? min(min(fRec39[1], fVec7[0]), fRec32[1]) : min(fVec7[0], fRec32[1])));
			fRec40[0] = ((iTemp96) ? fVec7[0] : ((iTemp95) ? max(max(fRec40[1], fVec7[0]), fRec32[1]) : max(fVec7[0], fRec32[1])));
			int 	iTemp97 = (iRec31[1] == 3);
			int 	iTemp98 = (iRec31[1] == 6);
			float 	fTemp99 = (((iRec31[1] == 1)) ? min(1.0f, fTemp84) : ((iTemp96) ? 0.0f : ((iTemp98) ? (fTemp84 * fTemp94) : ((iTemp97) ? (fRec40[0] * fTemp94) : fVec7[0]))));
			float 	fTemp100 = (1.0f / ((iTemp96) ? 0.0001f : (((iTemp97 | iTemp98)) ? (0.04761905f * fTemp88) : fTemp88)));
			float 	fTemp101 = (fRec36[1] - fTemp100);
			float 	fTemp102 = (fRec36[1] + fTemp100);
			fRec36[0] = (((fTemp102 < fTemp99)) ? fTemp102 : (((fTemp101 > fTemp99)) ? fTemp101 : fTemp99));
			fRec32[0] = fRec36[0];
			fRec30[0] = (fRec32[0] - (fConst18 * ((fConst16 * fRec30[2]) + (fConst14 * fRec30[1]))));
			float 	fTemp103 = min(0.99f, (fConst24 * (((3947.8418f * fRec30[0]) + (7895.6836f * fRec30[1])) + (3947.8418f * fRec30[2]))));
			float 	fTemp104 = (fVec7[0] - fTemp103);
			float 	fTemp105 = min(0.8f, max(0.0f, (max(-0.75f, fTemp104) + fSlow37)));
			float 	fTemp106 = max(0.0f, (fVec7[0] + (-0.5f - (fSlow43 + (fTemp103 + fTemp105)))));
			float 	fTemp107 = ((iTemp2) ? 0.0f : (fSlow44 + fRec41[1]));
			fRec41[0] = (fTemp107 - floorf(fTemp107));
			float 	fTemp108 = (499.0f * fRec41[0]);
			int 	iTemp109 = int(fTemp108);
			float 	fTemp110 = ftbl0[max(0, min(iTemp109, 499))];
			float 	fTemp111 = (fSlow46 + (fRec42[1] + -1.0f));
			float 	fTemp112 = (fSlow46 + fRec42[1]);
			int 	iTemp113 = (fTemp111 < 0.0f);
			fRec42[0] = ((iTemp113) ? fTemp112 : fTemp111);
			float 	fRec43 = ((iTemp113) ? fTemp112 : (fSlow46 + (fRec42[1] + (fSlow47 * fTemp111))));
			float 	fTemp114 = (fSlow49 + (fRec44[1] + -1.0f));
			float 	fTemp115 = (fSlow49 + fRec44[1]);
			int 	iTemp116 = (fTemp114 < 0.0f);
			fRec44[0] = ((iTemp116) ? fTemp115 : fTemp114);
			float 	fRec45 = ((iTemp116) ? fTemp115 : (fSlow49 + (fRec44[1] + (fSlow50 * fTemp114))));
			fRec46[0] = (fTemp55 - (fSlow55 * ((fSlow53 * fRec46[2]) + (fSlow51 * fRec46[1]))));
			float 	fTemp117 = ((0.3f * (1.0f - fVec7[0])) + fSlow57);
			float 	fTemp118 = ((iTemp2) ? 0.0f : (fSlow59 + fRec47[1]));
			fRec47[0] = (fTemp118 - floorf(fTemp118));
			float 	fTemp119 = (499.0f * fRec47[0]);
			int 	iTemp120 = int(fTemp119);
			int 	iTemp121 = max(0, min(iTemp120, 499));
			float 	fTemp122 = ftbl3[iTemp121];
			int 	iTemp123 = max(0, min((iTemp120 + 1), 499));
			float 	fTemp124 = (fTemp119 - float(iTemp120));
			float 	fTemp125 = min(1.0f, (max(min((3.0f * fTemp104), 0.3f), -0.2f) + 0.15f));
			float 	fTemp126 = ftbl0[iTemp121];
			float 	fTemp127 = (((fTemp126 + (fTemp124 * (ftbl0[iTemp123] - fTemp126))) * (1.0f - fTemp125)) + (fTemp125 * (fTemp122 + (fTemp124 * (ftbl3[iTemp123] - fTemp122)))));
			float 	fTemp128 = ftbl4[iTemp121];
			float 	fTemp129 = ((iTemp2) ? 0.0f : (fSlow61 + fRec48[1]));
			fRec48[0] = (fTemp129 - floorf(fTemp129));
			float 	fTemp130 = (499.0f * fRec48[0]);
			int 	iTemp131 = int(fTemp130);
			float 	fTemp132 = ftbl0[max(0, min(iTemp131, 499))];
			float 	fTemp133 = ((iTemp2) ? 0.0f : (fSlow62 + fRec49[1]));
			fRec49[0] = (fTemp133 - floorf(fTemp133));
			float 	fTemp134 = (499.0f * fRec49[0]);
			int 	iTemp135 = int(fTemp134);
			float 	fTemp136 = ftbl0[max(0, min(iTemp135, 499))];
			float 	fTemp137 = (fTemp136 + ((fTemp134 - float(iTemp135)) * (ftbl0[max(0, min((iTemp135 + 1), 499))] - fTemp136)));
			float 	fTemp138 = (fTemp137 + (fTemp132 + ((fTemp130 - float(iTemp131)) * (ftbl0[max(0, min((iTemp131 + 1), 499))] - fTemp132))));
			fVec9[0] = fSlow69;
			int 	iTemp139 = (fSlow71 != (0.9f * fVec9[1]));
			iVec10[0] = iTemp139;
			int 	iTemp140 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec53[0] = ((iRec53[1] * (1 - iTemp140)) + (iTemp16 * iTemp140));
			float 	fTemp141 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec53[0])))) > 0.5f) & iSlow70)) ? 0.0f : fSlow68) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp141;
			int 	iTemp142 = (fVec11[0] > 0.003f);
			int 	iTemp143 = (fVec11[0] <= 0.003f);
			float 	fTemp144 = float((iTemp143 | (fVec11[1] >= 0.003f)));
			fRec54[0] = max((fRec54[1] * fTemp144), fSlow71);
			fRec55[0] = max((fTemp144 * fRec55[1]), fSlow72);
			float 	fTemp145 = (min(1.0f, fRec55[0]) + min(1.0f, fRec54[0]));
			int 	iTemp146 = (fVec11[0] >= fRec52[1]);
			int 	iTemp147 = (fRec52[1] <= 0.001f);
			int 	iTemp148 = (((iRec51[1] >= 4)) ? (((iRec51[1] >= 6)) ? ((iTemp147) ? 0 : ((iTemp142) ? 1 : 6)) : (((iRec51[1] >= 5)) ? ((iTemp143) ? 3 : ((iTemp146) ? 4 : 5)) : ((iTemp143) ? 3 : (((fVec11[0] <= fRec52[1])) ? 5 : 4)))) : (((iRec51[1] >= 2)) ? (((iRec51[1] >= 3)) ? (((iTemp143 & iTemp147)) ? 0 : ((iTemp142) ? 1 : 3)) : ((iTemp143) ? 6 : ((iTemp146) ? 4 : 2))) : (((iRec51[1] >= 1)) ? (((fRec52[1] >= min(fTemp145, 1.0f))) ? ((iTemp143) ? 6 : 2) : 1) : ((iTemp142) ? 1 : 0))));
			iRec51[0] = iTemp148;
			float 	fTemp149 = (((iTemp148 >= 4)) ? (((iTemp148 >= 6)) ? fConst0 : fConst23) : (((iTemp148 >= 2)) ? (((iTemp148 >= 3)) ? fConst22 : fConst21) : (((iTemp148 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp150 = (iRec51[1] != iRec51[2]);
			iVec12[0] = iTemp150;
			int 	iTemp151 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec57[0] = ((iRec57[1] * (1 - iTemp151)) + (iTemp16 * iTemp151));
			float 	fTemp152 = (2e+01f * (((fTemp149 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec57[0]))) / fTemp149) : 0.0f));
			int 	iTemp153 = int(fTemp152);
			float 	fTemp154 = ftbl2[max(0, int(min(int(iTemp153), 20)))];
			float 	fTemp155 = (fTemp154 + ((fTemp152 - float(iTemp153)) * (ftbl2[max(0, int(min(int((iTemp153 + 1)), 20)))] - fTemp154)));
			iRec58[0] = iRec51[1];
			int 	iTemp156 = (iRec58[1] == iRec51[1]);
			int 	iTemp157 = (iRec51[1] == 0);
			fRec59[0] = ((iTemp157) ? fVec11[0] : ((iTemp156) ? min(min(fRec59[1], fVec11[0]), fRec52[1]) : min(fVec11[0], fRec52[1])));
			fRec60[0] = ((iTemp157) ? fVec11[0] : ((iTemp156) ? max(max(fRec60[1], fVec11[0]), fRec52[1]) : max(fVec11[0], fRec52[1])));
			int 	iTemp158 = (iRec51[1] == 3);
			int 	iTemp159 = (iRec51[1] == 6);
			float 	fTemp160 = (((iRec51[1] == 1)) ? min(1.0f, fTemp145) : ((iTemp157) ? 0.0f : ((iTemp159) ? (fTemp145 * fTemp155) : ((iTemp158) ? (fRec60[0] * fTemp155) : fVec11[0]))));
			float 	fTemp161 = (1.0f / ((iTemp157) ? 0.0001f : (((iTemp158 | iTemp159)) ? (0.04761905f * fTemp149) : fTemp149)));
			float 	fTemp162 = (fRec56[1] - fTemp161);
			float 	fTemp163 = (fRec56[1] + fTemp161);
			fRec56[0] = (((fTemp163 < fTemp160)) ? fTemp163 : (((fTemp162 > fTemp160)) ? fTemp162 : fTemp160));
			fRec52[0] = fRec56[0];
			fRec50[0] = (fRec52[0] - (fConst18 * ((fConst16 * fRec50[2]) + (fConst14 * fRec50[1]))));
			float 	fTemp164 = min(0.99f, (fConst24 * (((3947.8418f * fRec50[0]) + (7895.6836f * fRec50[1])) + (3947.8418f * fRec50[2]))));
			float 	fTemp165 = (fVec11[0] - fTemp164);
			float 	fTemp166 = min(0.8f, max(0.0f, (max(-0.75f, fTemp165) + fSlow67)));
			float 	fTemp167 = max(0.0f, (fVec11[0] + (-0.5f - (fSlow73 + (fTemp164 + fTemp166)))));
			float 	fTemp168 = ((iTemp2) ? 0.0f : (fSlow74 + fRec61[1]));
			fRec61[0] = (fTemp168 - floorf(fTemp168));
			float 	fTemp169 = (499.0f * fRec61[0]);
			int 	iTemp170 = int(fTemp169);
			float 	fTemp171 = ftbl0[max(0, min(iTemp170, 499))];
			float 	fTemp172 = (fSlow76 + (fRec62[1] + -1.0f));
			float 	fTemp173 = (fSlow76 + fRec62[1]);
			int 	iTemp174 = (fTemp172 < 0.0f);
			fRec62[0] = ((iTemp174) ? fTemp173 : fTemp172);
			float 	fRec63 = ((iTemp174) ? fTemp173 : (fSlow76 + (fRec62[1] + (fSlow77 * fTemp172))));
			float 	fTemp175 = (fSlow79 + (fRec64[1] + -1.0f));
			float 	fTemp176 = (fSlow79 + fRec64[1]);
			int 	iTemp177 = (fTemp175 < 0.0f);
			fRec64[0] = ((iTemp177) ? fTemp176 : fTemp175);
			float 	fRec65 = ((iTemp177) ? fTemp176 : (fSlow79 + (fRec64[1] + (fSlow80 * fTemp175))));
			fRec66[0] = (fTemp55 - (fSlow85 * ((fSlow83 * fRec66[2]) + (fSlow81 * fRec66[1]))));
			float 	fTemp178 = ((0.3f * (1.0f - fVec11[0])) + fSlow87);
			float 	fTemp179 = ((iTemp2) ? 0.0f : (fSlow89 + fRec67[1]));
			fRec67[0] = (fTemp179 - floorf(fTemp179));
			float 	fTemp180 = (499.0f * fRec67[0]);
			int 	iTemp181 = int(fTemp180);
			int 	iTemp182 = max(0, min(iTemp181, 499));
			float 	fTemp183 = ftbl3[iTemp182];
			int 	iTemp184 = max(0, min((iTemp181 + 1), 499));
			float 	fTemp185 = (fTemp180 - float(iTemp181));
			float 	fTemp186 = min(1.0f, (max(min((3.0f * fTemp165), 0.3f), -0.2f) + 0.15f));
			float 	fTemp187 = ftbl0[iTemp182];
			float 	fTemp188 = (((fTemp187 + (fTemp185 * (ftbl0[iTemp184] - fTemp187))) * (1.0f - fTemp186)) + (fTemp186 * (fTemp183 + (fTemp185 * (ftbl3[iTemp184] - fTemp183)))));
			float 	fTemp189 = ftbl4[iTemp182];
			float 	fTemp190 = ((iTemp2) ? 0.0f : (fSlow91 + fRec68[1]));
			fRec68[0] = (fTemp190 - floorf(fTemp190));
			float 	fTemp191 = (499.0f * fRec68[0]);
			int 	iTemp192 = int(fTemp191);
			float 	fTemp193 = ftbl0[max(0, min(iTemp192, 499))];
			float 	fTemp194 = ((iTemp2) ? 0.0f : (fSlow92 + fRec69[1]));
			fRec69[0] = (fTemp194 - floorf(fTemp194));
			float 	fTemp195 = (499.0f * fRec69[0]);
			int 	iTemp196 = int(fTemp195);
			float 	fTemp197 = ftbl0[max(0, min(iTemp196, 499))];
			float 	fTemp198 = (fTemp197 + ((fTemp195 - float(iTemp196)) * (ftbl0[max(0, min((iTemp196 + 1), 499))] - fTemp197)));
			float 	fTemp199 = (fTemp198 + (fTemp193 + ((fTemp191 - float(iTemp192)) * (ftbl0[max(0, min((iTemp192 + 1), 499))] - fTemp193))));
			fVec13[0] = fSlow99;
			int 	iTemp200 = (fSlow101 != (0.9f * fVec13[1]));
			iVec14[0] = iTemp200;
			int 	iTemp201 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec73[0] = ((iRec73[1] * (1 - iTemp201)) + (iTemp16 * iTemp201));
			float 	fTemp202 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec73[0])))) > 0.5f) & iSlow100)) ? 0.0f : fSlow98) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp202;
			int 	iTemp203 = (fVec15[0] > 0.003f);
			int 	iTemp204 = (fVec15[0] <= 0.003f);
			float 	fTemp205 = float((iTemp204 | (fVec15[1] >= 0.003f)));
			fRec74[0] = max((fRec74[1] * fTemp205), fSlow101);
			fRec75[0] = max((fTemp205 * fRec75[1]), fSlow102);
			float 	fTemp206 = (min(1.0f, fRec75[0]) + min(1.0f, fRec74[0]));
			int 	iTemp207 = (fVec15[0] >= fRec72[1]);
			int 	iTemp208 = (fRec72[1] <= 0.001f);
			int 	iTemp209 = (((iRec71[1] >= 4)) ? (((iRec71[1] >= 6)) ? ((iTemp208) ? 0 : ((iTemp203) ? 1 : 6)) : (((iRec71[1] >= 5)) ? ((iTemp204) ? 3 : ((iTemp207) ? 4 : 5)) : ((iTemp204) ? 3 : (((fVec15[0] <= fRec72[1])) ? 5 : 4)))) : (((iRec71[1] >= 2)) ? (((iRec71[1] >= 3)) ? (((iTemp204 & iTemp208)) ? 0 : ((iTemp203) ? 1 : 3)) : ((iTemp204) ? 6 : ((iTemp207) ? 4 : 2))) : (((iRec71[1] >= 1)) ? (((fRec72[1] >= min(fTemp206, 1.0f))) ? ((iTemp204) ? 6 : 2) : 1) : ((iTemp203) ? 1 : 0))));
			iRec71[0] = iTemp209;
			float 	fTemp210 = (((iTemp209 >= 4)) ? (((iTemp209 >= 6)) ? fConst0 : fConst23) : (((iTemp209 >= 2)) ? (((iTemp209 >= 3)) ? fConst22 : fConst21) : (((iTemp209 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp211 = (iRec71[1] != iRec71[2]);
			iVec16[0] = iTemp211;
			int 	iTemp212 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec77[0] = ((iRec77[1] * (1 - iTemp212)) + (iTemp16 * iTemp212));
			float 	fTemp213 = (2e+01f * (((fTemp210 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec77[0]))) / fTemp210) : 0.0f));
			int 	iTemp214 = int(fTemp213);
			float 	fTemp215 = ftbl2[max(0, int(min(int(iTemp214), 20)))];
			float 	fTemp216 = (fTemp215 + ((fTemp213 - float(iTemp214)) * (ftbl2[max(0, int(min(int((iTemp214 + 1)), 20)))] - fTemp215)));
			iRec78[0] = iRec71[1];
			int 	iTemp217 = (iRec78[1] == iRec71[1]);
			int 	iTemp218 = (iRec71[1] == 0);
			fRec79[0] = ((iTemp218) ? fVec15[0] : ((iTemp217) ? min(min(fRec79[1], fVec15[0]), fRec72[1]) : min(fVec15[0], fRec72[1])));
			fRec80[0] = ((iTemp218) ? fVec15[0] : ((iTemp217) ? max(max(fRec80[1], fVec15[0]), fRec72[1]) : max(fVec15[0], fRec72[1])));
			int 	iTemp219 = (iRec71[1] == 3);
			int 	iTemp220 = (iRec71[1] == 6);
			float 	fTemp221 = (((iRec71[1] == 1)) ? min(1.0f, fTemp206) : ((iTemp218) ? 0.0f : ((iTemp220) ? (fTemp206 * fTemp216) : ((iTemp219) ? (fRec80[0] * fTemp216) : fVec15[0]))));
			float 	fTemp222 = (1.0f / ((iTemp218) ? 0.0001f : (((iTemp219 | iTemp220)) ? (0.04761905f * fTemp210) : fTemp210)));
			float 	fTemp223 = (fRec76[1] - fTemp222);
			float 	fTemp224 = (fRec76[1] + fTemp222);
			fRec76[0] = (((fTemp224 < fTemp221)) ? fTemp224 : (((fTemp223 > fTemp221)) ? fTemp223 : fTemp221));
			fRec72[0] = fRec76[0];
			fRec70[0] = (fRec72[0] - (fConst18 * ((fConst16 * fRec70[2]) + (fConst14 * fRec70[1]))));
			float 	fTemp225 = min(0.99f, (fConst24 * (((3947.8418f * fRec70[0]) + (7895.6836f * fRec70[1])) + (3947.8418f * fRec70[2]))));
			float 	fTemp226 = (fVec15[0] - fTemp225);
			float 	fTemp227 = min(0.8f, max(0.0f, (max(-0.75f, fTemp226) + fSlow97)));
			float 	fTemp228 = max(0.0f, (fVec15[0] + (-0.5f - (fSlow103 + (fTemp225 + fTemp227)))));
			float 	fTemp229 = ((iTemp2) ? 0.0f : (fSlow104 + fRec81[1]));
			fRec81[0] = (fTemp229 - floorf(fTemp229));
			float 	fTemp230 = (499.0f * fRec81[0]);
			int 	iTemp231 = int(fTemp230);
			float 	fTemp232 = ftbl0[max(0, min(iTemp231, 499))];
			float 	fTemp233 = (fSlow106 + (fRec82[1] + -1.0f));
			float 	fTemp234 = (fSlow106 + fRec82[1]);
			int 	iTemp235 = (fTemp233 < 0.0f);
			fRec82[0] = ((iTemp235) ? fTemp234 : fTemp233);
			float 	fRec83 = ((iTemp235) ? fTemp234 : (fSlow106 + (fRec82[1] + (fSlow107 * fTemp233))));
			float 	fTemp236 = (fSlow109 + (fRec84[1] + -1.0f));
			float 	fTemp237 = (fSlow109 + fRec84[1]);
			int 	iTemp238 = (fTemp236 < 0.0f);
			fRec84[0] = ((iTemp238) ? fTemp237 : fTemp236);
			float 	fRec85 = ((iTemp238) ? fTemp237 : (fSlow109 + (fRec84[1] + (fSlow110 * fTemp236))));
			fRec86[0] = (fTemp55 - (fSlow115 * ((fSlow113 * fRec86[2]) + (fSlow111 * fRec86[1]))));
			float 	fTemp239 = ((0.3f * (1.0f - fVec15[0])) + fSlow117);
			float 	fTemp240 = ((iTemp2) ? 0.0f : (fSlow119 + fRec87[1]));
			fRec87[0] = (fTemp240 - floorf(fTemp240));
			float 	fTemp241 = (499.0f * fRec87[0]);
			int 	iTemp242 = int(fTemp241);
			int 	iTemp243 = max(0, min(iTemp242, 499));
			float 	fTemp244 = ftbl3[iTemp243];
			int 	iTemp245 = max(0, min((iTemp242 + 1), 499));
			float 	fTemp246 = (fTemp241 - float(iTemp242));
			float 	fTemp247 = min(1.0f, (max(min((3.0f * fTemp226), 0.3f), -0.2f) + 0.15f));
			float 	fTemp248 = ftbl0[iTemp243];
			float 	fTemp249 = (((fTemp248 + (fTemp246 * (ftbl0[iTemp245] - fTemp248))) * (1.0f - fTemp247)) + (fTemp247 * (fTemp244 + (fTemp246 * (ftbl3[iTemp245] - fTemp244)))));
			float 	fTemp250 = ftbl4[iTemp243];
			float 	fTemp251 = ((iTemp2) ? 0.0f : (fSlow121 + fRec88[1]));
			fRec88[0] = (fTemp251 - floorf(fTemp251));
			float 	fTemp252 = (499.0f * fRec88[0]);
			int 	iTemp253 = int(fTemp252);
			float 	fTemp254 = ftbl0[max(0, min(iTemp253, 499))];
			float 	fTemp255 = ((iTemp2) ? 0.0f : (fSlow122 + fRec89[1]));
			fRec89[0] = (fTemp255 - floorf(fTemp255));
			float 	fTemp256 = (499.0f * fRec89[0]);
			int 	iTemp257 = int(fTemp256);
			float 	fTemp258 = ftbl0[max(0, min(iTemp257, 499))];
			float 	fTemp259 = (fTemp258 + ((fTemp256 - float(iTemp257)) * (ftbl0[max(0, min((iTemp257 + 1), 499))] - fTemp258)));
			float 	fTemp260 = (fTemp259 + (fTemp254 + ((fTemp252 - float(iTemp253)) * (ftbl0[max(0, min((iTemp253 + 1), 499))] - fTemp254))));
			fVec17[0] = fSlow129;
			int 	iTemp261 = (fSlow131 != (0.9f * fVec17[1]));
			iVec18[0] = iTemp261;
			int 	iTemp262 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec93[0] = ((iRec93[1] * (1 - iTemp262)) + (iTemp16 * iTemp262));
			float 	fTemp263 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec93[0])))) > 0.5f) & iSlow130)) ? 0.0f : fSlow128) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp263;
			int 	iTemp264 = (fVec19[0] > 0.003f);
			int 	iTemp265 = (fVec19[0] <= 0.003f);
			float 	fTemp266 = float((iTemp265 | (fVec19[1] >= 0.003f)));
			fRec94[0] = max((fRec94[1] * fTemp266), fSlow131);
			fRec95[0] = max((fTemp266 * fRec95[1]), fSlow132);
			float 	fTemp267 = (min(1.0f, fRec95[0]) + min(1.0f, fRec94[0]));
			int 	iTemp268 = (fVec19[0] >= fRec92[1]);
			int 	iTemp269 = (fRec92[1] <= 0.001f);
			int 	iTemp270 = (((iRec91[1] >= 4)) ? (((iRec91[1] >= 6)) ? ((iTemp269) ? 0 : ((iTemp264) ? 1 : 6)) : (((iRec91[1] >= 5)) ? ((iTemp265) ? 3 : ((iTemp268) ? 4 : 5)) : ((iTemp265) ? 3 : (((fVec19[0] <= fRec92[1])) ? 5 : 4)))) : (((iRec91[1] >= 2)) ? (((iRec91[1] >= 3)) ? (((iTemp265 & iTemp269)) ? 0 : ((iTemp264) ? 1 : 3)) : ((iTemp265) ? 6 : ((iTemp268) ? 4 : 2))) : (((iRec91[1] >= 1)) ? (((fRec92[1] >= min(fTemp267, 1.0f))) ? ((iTemp265) ? 6 : 2) : 1) : ((iTemp264) ? 1 : 0))));
			iRec91[0] = iTemp270;
			float 	fTemp271 = (((iTemp270 >= 4)) ? (((iTemp270 >= 6)) ? fConst0 : fConst23) : (((iTemp270 >= 2)) ? (((iTemp270 >= 3)) ? fConst22 : fConst21) : (((iTemp270 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp272 = (iRec91[1] != iRec91[2]);
			iVec20[0] = iTemp272;
			int 	iTemp273 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec97[0] = ((iRec97[1] * (1 - iTemp273)) + (iTemp16 * iTemp273));
			float 	fTemp274 = (2e+01f * (((fTemp271 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec97[0]))) / fTemp271) : 0.0f));
			int 	iTemp275 = int(fTemp274);
			float 	fTemp276 = ftbl2[max(0, int(min(int(iTemp275), 20)))];
			float 	fTemp277 = (fTemp276 + ((fTemp274 - float(iTemp275)) * (ftbl2[max(0, int(min(int((iTemp275 + 1)), 20)))] - fTemp276)));
			iRec98[0] = iRec91[1];
			int 	iTemp278 = (iRec98[1] == iRec91[1]);
			int 	iTemp279 = (iRec91[1] == 0);
			fRec99[0] = ((iTemp279) ? fVec19[0] : ((iTemp278) ? min(min(fRec99[1], fVec19[0]), fRec92[1]) : min(fVec19[0], fRec92[1])));
			fRec100[0] = ((iTemp279) ? fVec19[0] : ((iTemp278) ? max(max(fRec100[1], fVec19[0]), fRec92[1]) : max(fVec19[0], fRec92[1])));
			int 	iTemp280 = (iRec91[1] == 3);
			int 	iTemp281 = (iRec91[1] == 6);
			float 	fTemp282 = (((iRec91[1] == 1)) ? min(1.0f, fTemp267) : ((iTemp279) ? 0.0f : ((iTemp281) ? (fTemp267 * fTemp277) : ((iTemp280) ? (fRec100[0] * fTemp277) : fVec19[0]))));
			float 	fTemp283 = (1.0f / ((iTemp279) ? 0.0001f : (((iTemp280 | iTemp281)) ? (0.04761905f * fTemp271) : fTemp271)));
			float 	fTemp284 = (fRec96[1] - fTemp283);
			float 	fTemp285 = (fRec96[1] + fTemp283);
			fRec96[0] = (((fTemp285 < fTemp282)) ? fTemp285 : (((fTemp284 > fTemp282)) ? fTemp284 : fTemp282));
			fRec92[0] = fRec96[0];
			fRec90[0] = (fRec92[0] - (fConst18 * ((fConst16 * fRec90[2]) + (fConst14 * fRec90[1]))));
			float 	fTemp286 = min(0.99f, (fConst24 * (((3947.8418f * fRec90[0]) + (7895.6836f * fRec90[1])) + (3947.8418f * fRec90[2]))));
			float 	fTemp287 = (fVec19[0] - fTemp286);
			float 	fTemp288 = min(0.8f, max(0.0f, (max(-0.75f, fTemp287) + fSlow127)));
			float 	fTemp289 = max(0.0f, (fVec19[0] + (-0.5f - (fSlow133 + (fTemp286 + fTemp288)))));
			float 	fTemp290 = ((iTemp2) ? 0.0f : (fSlow134 + fRec101[1]));
			fRec101[0] = (fTemp290 - floorf(fTemp290));
			float 	fTemp291 = (499.0f * fRec101[0]);
			int 	iTemp292 = int(fTemp291);
			float 	fTemp293 = ftbl0[max(0, min(iTemp292, 499))];
			float 	fTemp294 = (fSlow136 + (fRec102[1] + -1.0f));
			float 	fTemp295 = (fSlow136 + fRec102[1]);
			int 	iTemp296 = (fTemp294 < 0.0f);
			fRec102[0] = ((iTemp296) ? fTemp295 : fTemp294);
			float 	fRec103 = ((iTemp296) ? fTemp295 : (fSlow136 + (fRec102[1] + (fSlow137 * fTemp294))));
			float 	fTemp297 = (fSlow139 + (fRec104[1] + -1.0f));
			float 	fTemp298 = (fSlow139 + fRec104[1]);
			int 	iTemp299 = (fTemp297 < 0.0f);
			fRec104[0] = ((iTemp299) ? fTemp298 : fTemp297);
			float 	fRec105 = ((iTemp299) ? fTemp298 : (fSlow139 + (fRec104[1] + (fSlow140 * fTemp297))));
			fRec106[0] = (fTemp55 - (fSlow145 * ((fSlow143 * fRec106[2]) + (fSlow141 * fRec106[1]))));
			float 	fTemp300 = ((0.3f * (1.0f - fVec19[0])) + fSlow147);
			float 	fTemp301 = ((iTemp2) ? 0.0f : (fSlow149 + fRec107[1]));
			fRec107[0] = (fTemp301 - floorf(fTemp301));
			float 	fTemp302 = (499.0f * fRec107[0]);
			int 	iTemp303 = int(fTemp302);
			int 	iTemp304 = max(0, min(iTemp303, 499));
			float 	fTemp305 = ftbl3[iTemp304];
			int 	iTemp306 = max(0, min((iTemp303 + 1), 499));
			float 	fTemp307 = (fTemp302 - float(iTemp303));
			float 	fTemp308 = min(1.0f, (max(min((3.0f * fTemp287), 0.3f), -0.2f) + 0.15f));
			float 	fTemp309 = ftbl0[iTemp304];
			float 	fTemp310 = (((fTemp309 + (fTemp307 * (ftbl0[iTemp306] - fTemp309))) * (1.0f - fTemp308)) + (fTemp308 * (fTemp305 + (fTemp307 * (ftbl3[iTemp306] - fTemp305)))));
			float 	fTemp311 = ftbl4[iTemp304];
			float 	fTemp312 = ((iTemp2) ? 0.0f : (fSlow151 + fRec108[1]));
			fRec108[0] = (fTemp312 - floorf(fTemp312));
			float 	fTemp313 = (499.0f * fRec108[0]);
			int 	iTemp314 = int(fTemp313);
			float 	fTemp315 = ftbl0[max(0, min(iTemp314, 499))];
			float 	fTemp316 = ((iTemp2) ? 0.0f : (fSlow152 + fRec109[1]));
			fRec109[0] = (fTemp316 - floorf(fTemp316));
			float 	fTemp317 = (499.0f * fRec109[0]);
			int 	iTemp318 = int(fTemp317);
			float 	fTemp319 = ftbl0[max(0, min(iTemp318, 499))];
			float 	fTemp320 = (fTemp319 + ((fTemp317 - float(iTemp318)) * (ftbl0[max(0, min((iTemp318 + 1), 499))] - fTemp319)));
			float 	fTemp321 = (fTemp320 + (fTemp315 + ((fTemp313 - float(iTemp314)) * (ftbl0[max(0, min((iTemp314 + 1), 499))] - fTemp315))));
			fVec21[0] = fSlow159;
			int 	iTemp322 = (fSlow161 != (0.9f * fVec21[1]));
			iVec22[0] = iTemp322;
			int 	iTemp323 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec113[0] = ((iRec113[1] * (1 - iTemp323)) + (iTemp16 * iTemp323));
			float 	fTemp324 = ftbl1[int(((499.5f * ((((((fConst19 * float((iRec9[0] + (-1 - iRec113[0])))) > 0.5f) & iSlow160)) ? 0.0f : fSlow158) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp324;
			int 	iTemp325 = (fVec23[0] > 0.003f);
			int 	iTemp326 = (fVec23[0] <= 0.003f);
			float 	fTemp327 = float((iTemp326 | (fVec23[1] >= 0.003f)));
			fRec114[0] = max((fRec114[1] * fTemp327), fSlow161);
			fRec115[0] = max((fTemp327 * fRec115[1]), fSlow162);
			float 	fTemp328 = (min(1.0f, fRec115[0]) + min(1.0f, fRec114[0]));
			int 	iTemp329 = (fVec23[0] >= fRec112[1]);
			int 	iTemp330 = (fRec112[1] <= 0.001f);
			int 	iTemp331 = (((iRec111[1] >= 4)) ? (((iRec111[1] >= 6)) ? ((iTemp330) ? 0 : ((iTemp325) ? 1 : 6)) : (((iRec111[1] >= 5)) ? ((iTemp326) ? 3 : ((iTemp329) ? 4 : 5)) : ((iTemp326) ? 3 : (((fVec23[0] <= fRec112[1])) ? 5 : 4)))) : (((iRec111[1] >= 2)) ? (((iRec111[1] >= 3)) ? (((iTemp326 & iTemp330)) ? 0 : ((iTemp325) ? 1 : 3)) : ((iTemp326) ? 6 : ((iTemp329) ? 4 : 2))) : (((iRec111[1] >= 1)) ? (((fRec112[1] >= min(fTemp328, 1.0f))) ? ((iTemp326) ? 6 : 2) : 1) : ((iTemp325) ? 1 : 0))));
			iRec111[0] = iTemp331;
			float 	fTemp332 = (((iTemp331 >= 4)) ? (((iTemp331 >= 6)) ? fConst0 : fConst23) : (((iTemp331 >= 2)) ? (((iTemp331 >= 3)) ? fConst22 : fConst21) : (((iTemp331 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp333 = (iRec111[1] != iRec111[2]);
			iVec24[0] = iTemp333;
			int 	iTemp334 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec117[0] = ((iRec117[1] * (1 - iTemp334)) + (iTemp16 * iTemp334));
			float 	fTemp335 = (2e+01f * (((fTemp332 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec117[0]))) / fTemp332) : 0.0f));
			int 	iTemp336 = int(fTemp335);
			float 	fTemp337 = ftbl2[max(0, int(min(int(iTemp336), 20)))];
			float 	fTemp338 = (fTemp337 + ((fTemp335 - float(iTemp336)) * (ftbl2[max(0, int(min(int((iTemp336 + 1)), 20)))] - fTemp337)));
			iRec118[0] = iRec111[1];
			int 	iTemp339 = (iRec118[1] == iRec111[1]);
			int 	iTemp340 = (iRec111[1] == 0);
			fRec119[0] = ((iTemp340) ? fVec23[0] : ((iTemp339) ? min(min(fRec119[1], fVec23[0]), fRec112[1]) : min(fVec23[0], fRec112[1])));
			fRec120[0] = ((iTemp340) ? fVec23[0] : ((iTemp339) ? max(max(fRec120[1], fVec23[0]), fRec112[1]) : max(fVec23[0], fRec112[1])));
			int 	iTemp341 = (iRec111[1] == 3);
			int 	iTemp342 = (iRec111[1] == 6);
			float 	fTemp343 = (((iRec111[1] == 1)) ? min(1.0f, fTemp328) : ((iTemp340) ? 0.0f : ((iTemp342) ? (fTemp328 * fTemp338) : ((iTemp341) ? (fRec120[0] * fTemp338) : fVec23[0]))));
			float 	fTemp344 = (1.0f / ((iTemp340) ? 0.0001f : (((iTemp341 | iTemp342)) ? (0.04761905f * fTemp332) : fTemp332)));
			float 	fTemp345 = (fRec116[1] - fTemp344);
			float 	fTemp346 = (fRec116[1] + fTemp344);
			fRec116[0] = (((fTemp346 < fTemp343)) ? fTemp346 : (((fTemp345 > fTemp343)) ? fTemp345 : fTemp343));
			fRec112[0] = fRec116[0];
			fRec110[0] = (fRec112[0] - (fConst18 * ((fConst16 * fRec110[2]) + (fConst14 * fRec110[1]))));
			float 	fTemp347 = min(0.99f, (fConst24 * (((3947.8418f * fRec110[0]) + (7895.6836f * fRec110[1])) + (3947.8418f * fRec110[2]))));
			float 	fTemp348 = (fVec23[0] - fTemp347);
			float 	fTemp349 = min(0.8f, max(0.0f, (max(-0.75f, fTemp348) + fSlow157)));
			float 	fTemp350 = max(0.0f, (fVec23[0] + (-0.5f - (fSlow163 + (fTemp347 + fTemp349)))));
			float 	fTemp351 = ((iTemp2) ? 0.0f : (fSlow164 + fRec121[1]));
			fRec121[0] = (fTemp351 - floorf(fTemp351));
			float 	fTemp352 = (499.0f * fRec121[0]);
			int 	iTemp353 = int(fTemp352);
			float 	fTemp354 = ftbl0[max(0, min(iTemp353, 499))];
			float 	fTemp355 = (fSlow166 + (fRec122[1] + -1.0f));
			float 	fTemp356 = (fSlow166 + fRec122[1]);
			int 	iTemp357 = (fTemp355 < 0.0f);
			fRec122[0] = ((iTemp357) ? fTemp356 : fTemp355);
			float 	fRec123 = ((iTemp357) ? fTemp356 : (fSlow166 + (fRec122[1] + (fSlow167 * fTemp355))));
			float 	fTemp358 = (fSlow169 + (fRec124[1] + -1.0f));
			float 	fTemp359 = (fSlow169 + fRec124[1]);
			int 	iTemp360 = (fTemp358 < 0.0f);
			fRec124[0] = ((iTemp360) ? fTemp359 : fTemp358);
			float 	fRec125 = ((iTemp360) ? fTemp359 : (fSlow169 + (fRec124[1] + (fSlow170 * fTemp358))));
			fRec126[0] = (fTemp55 - (fSlow175 * ((fSlow173 * fRec126[2]) + (fSlow171 * fRec126[1]))));
			float 	fTemp361 = ((0.3f * (1.0f - fVec23[0])) + fSlow177);
			float 	fTemp362 = ((iTemp2) ? 0.0f : (fSlow179 + fRec127[1]));
			fRec127[0] = (fTemp362 - floorf(fTemp362));
			float 	fTemp363 = (499.0f * fRec127[0]);
			int 	iTemp364 = int(fTemp363);
			int 	iTemp365 = max(0, min(iTemp364, 499));
			float 	fTemp366 = ftbl3[iTemp365];
			int 	iTemp367 = max(0, min((iTemp364 + 1), 499));
			float 	fTemp368 = (fTemp363 - float(iTemp364));
			float 	fTemp369 = min(1.0f, (max(min((3.0f * fTemp348), 0.3f), -0.2f) + 0.15f));
			float 	fTemp370 = ftbl0[iTemp365];
			float 	fTemp371 = (((fTemp370 + (fTemp368 * (ftbl0[iTemp367] - fTemp370))) * (1.0f - fTemp369)) + (fTemp369 * (fTemp366 + (fTemp368 * (ftbl3[iTemp367] - fTemp366)))));
			float 	fTemp372 = ftbl4[iTemp365];
			fRec0[0] = ((1.37f * ((((((fTemp347 * ((((((((iSlow176) ? ((fTemp371 * fSlow155) + (fSlow154 * (fTemp372 + (fTemp368 * (ftbl4[iTemp367] - fTemp372))))) : fTemp371) * (1.0f - fTemp361)) + (fSlow178 * (fTemp361 * (fRec126[0] - fRec126[2])))) * (1.0f - ((fTemp349 + fSlow163) + fTemp350))) + (0.5f * (fTemp349 * (((2.0f * fRec125) + -1.0f) + ((2.0f * fRec123) + -1.0f))))) + (fSlow163 * ((0.33f * (fTemp354 + ((fTemp352 - float(iTemp353)) * (ftbl0[max(0, min((iTemp353 + 1), 499))] - fTemp354)))) + (0.67f * fTemp320)))) + (fTemp350 * ((iSlow156) ? (0.5f * fTemp321) : (0.5f * (fSlow155 * fTemp321)))))) + (fTemp286 * ((((((((iSlow146) ? ((fTemp310 * fSlow125) + (fSlow124 * (fTemp311 + (fTemp307 * (ftbl4[iTemp306] - fTemp311))))) : fTemp310) * (1.0f - fTemp300)) + (fSlow148 * (fTemp300 * (fRec106[0] - fRec106[2])))) * (1.0f - ((fTemp288 + fSlow133) + fTemp289))) + (0.5f * (fTemp288 * (((2.0f * fRec105) + -1.0f) + ((2.0f * fRec103) + -1.0f))))) + (fSlow133 * ((0.33f * (fTemp293 + ((fTemp291 - float(iTemp292)) * (ftbl0[max(0, min((iTemp292 + 1), 499))] - fTemp293)))) + (0.67f * fTemp259)))) + (fTemp289 * ((iSlow126) ? (0.5f * fTemp260) : (0.5f * (fSlow125 * fTemp260))))))) + (fTemp225 * ((((((((iSlow116) ? ((fTemp249 * fSlow95) + (fSlow94 * (fTemp250 + (fTemp246 * (ftbl4[iTemp245] - fTemp250))))) : fTemp249) * (1.0f - fTemp239)) + (fSlow118 * (fTemp239 * (fRec86[0] - fRec86[2])))) * (1.0f - ((fTemp227 + fSlow103) + fTemp228))) + (0.5f * (fTemp227 * (((2.0f * fRec85) + -1.0f) + ((2.0f * fRec83) + -1.0f))))) + (fSlow103 * ((0.33f * (fTemp232 + ((fTemp230 - float(iTemp231)) * (ftbl0[max(0, min((iTemp231 + 1), 499))] - fTemp232)))) + (0.67f * fTemp198)))) + (fTemp228 * ((iSlow96) ? (0.5f * fTemp199) : (0.5f * (fSlow95 * fTemp199))))))) + (fTemp164 * ((((((((iSlow86) ? ((fTemp188 * fSlow65) + (fSlow64 * (fTemp189 + (fTemp185 * (ftbl4[iTemp184] - fTemp189))))) : fTemp188) * (1.0f - fTemp178)) + (fSlow88 * (fTemp178 * (fRec66[0] - fRec66[2])))) * (1.0f - ((fTemp166 + fSlow73) + fTemp167))) + (0.5f * (fTemp166 * (((2.0f * fRec65) + -1.0f) + ((2.0f * fRec63) + -1.0f))))) + (fSlow73 * ((0.33f * (fTemp171 + ((fTemp169 - float(iTemp170)) * (ftbl0[max(0, min((iTemp170 + 1), 499))] - fTemp171)))) + (0.67f * fTemp137)))) + (fTemp167 * ((iSlow66) ? (0.5f * fTemp138) : (0.5f * (fSlow65 * fTemp138))))))) + (fTemp103 * ((((((((iSlow56) ? ((fTemp127 * fSlow35) + (fSlow34 * (fTemp128 + (fTemp124 * (ftbl4[iTemp123] - fTemp128))))) : fTemp127) * (1.0f - fTemp117)) + (fSlow58 * (fTemp117 * (fRec46[0] - fRec46[2])))) * (1.0f - ((fTemp105 + fSlow43) + fTemp106))) + (0.5f * (fTemp105 * (((2.0f * fRec45) + -1.0f) + ((2.0f * fRec43) + -1.0f))))) + (fSlow43 * ((0.33f * (fTemp110 + ((fTemp108 - float(iTemp109)) * (ftbl0[max(0, min((iTemp109 + 1), 499))] - fTemp110)))) + (0.67f * fTemp76)))) + (fTemp106 * ((iSlow36) ? (0.5f * fTemp77) : (0.5f * (fSlow35 * fTemp77))))))) + (fTemp41 * ((((((((iSlow26) ? ((fTemp66 * fSlow5) + (fSlow4 * (fTemp67 + (fTemp63 * (ftbl4[iTemp62] - fTemp67))))) : fTemp66) * (1.0f - fTemp56)) + (fSlow28 * (fTemp56 * (fRec23[0] - fRec23[2])))) * (1.0f - ((fTemp43 + fSlow13) + fTemp44))) + (0.5f * (fTemp43 * (((2.0f * fRec22) + -1.0f) + ((2.0f * fRec20) + -1.0f))))) + (fSlow13 * ((0.33f * (fTemp48 + ((fTemp46 - float(iTemp47)) * (ftbl0[max(0, min((iTemp47 + 1), 499))] - fTemp48)))) + (0.67f * fTemp11)))) + (fTemp44 * ((iSlow6) ? (0.5f * fTemp12) : (0.5f * (fSlow5 * fTemp12)))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst27 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec127[1] = fRec127[0];
			fRec126[2] = fRec126[1]; fRec126[1] = fRec126[0];
			fRec124[1] = fRec124[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec110[2] = fRec110[1]; fRec110[1] = fRec110[0];
			fRec112[1] = fRec112[0];
			fRec116[1] = fRec116[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			iRec118[1] = iRec118[0];
			iRec117[1] = iRec117[0];
			iVec24[1] = iVec24[0];
			iRec111[2] = iRec111[1]; iRec111[1] = iRec111[0];
			fRec115[1] = fRec115[0];
			fRec114[1] = fRec114[0];
			fVec23[1] = fVec23[0];
			iRec113[1] = iRec113[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec107[1] = fRec107[0];
			fRec106[2] = fRec106[1]; fRec106[1] = fRec106[0];
			fRec104[1] = fRec104[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec90[2] = fRec90[1]; fRec90[1] = fRec90[0];
			fRec92[1] = fRec92[0];
			fRec96[1] = fRec96[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			iRec98[1] = iRec98[0];
			iRec97[1] = iRec97[0];
			iVec20[1] = iVec20[0];
			iRec91[2] = iRec91[1]; iRec91[1] = iRec91[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fVec19[1] = fVec19[0];
			iRec93[1] = iRec93[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec86[2] = fRec86[1]; fRec86[1] = fRec86[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec70[2] = fRec70[1]; fRec70[1] = fRec70[0];
			fRec72[1] = fRec72[0];
			fRec76[1] = fRec76[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			iRec78[1] = iRec78[0];
			iRec77[1] = iRec77[0];
			iVec16[1] = iVec16[0];
			iRec71[2] = iRec71[1]; iRec71[1] = iRec71[0];
			fRec75[1] = fRec75[0];
			fRec74[1] = fRec74[0];
			fVec15[1] = fVec15[0];
			iRec73[1] = iRec73[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec52[1] = fRec52[0];
			fRec56[1] = fRec56[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			iRec58[1] = iRec58[0];
			iRec57[1] = iRec57[0];
			iVec12[1] = iVec12[0];
			iRec51[2] = iRec51[1]; iRec51[1] = iRec51[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fVec11[1] = fVec11[0];
			iRec53[1] = iRec53[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1]; fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec36[1] = fRec36[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			iRec38[1] = iRec38[0];
			iRec37[1] = iRec37[0];
			iVec8[1] = iVec8[0];
			iRec31[2] = iRec31[1]; iRec31[1] = iRec31[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fVec7[1] = fVec7[0];
			iRec33[1] = iRec33[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec26[1] = fRec26[0];
			fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
			iRec24[1] = iRec24[0];
			fRec21[1] = fRec21[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec12[1] = fRec12[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
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
			fRec2[1] = fRec2[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[500];
float 	mydsp::ftbl1[1000];
float 	mydsp::ftbl2[21];
float 	mydsp::ftbl3[500];
float 	mydsp::ftbl4[500];

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
