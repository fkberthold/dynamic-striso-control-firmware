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
				float 	fTemp18 = ((0.002002002f * float((iRec11[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp18)) + -1.0f))) * float(((fTemp18 > 0.0f) - (fTemp18 < 0.0f))));
				// post processing
				iRec11[1] = iRec11[0];
			}
		}
	};


	class SIG1 {
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
				int 	iTemp31 = int((1.05f * float((iRec21[0] + -1))));
				output[i] = (((iTemp31 >= 11)) ? (((iTemp31 >= 16)) ? (((iTemp31 >= 19)) ? (((iTemp31 >= 20)) ? 0.0f : 0.01f) : (((iTemp31 >= 18)) ? 0.03f : (((iTemp31 >= 17)) ? 0.06f : 0.08f))) : (((iTemp31 >= 14)) ? (((iTemp31 >= 15)) ? 0.1f : 0.12f) : (((iTemp31 >= 13)) ? 0.14f : (((iTemp31 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp31 >= 6)) ? (((iTemp31 >= 9)) ? (((iTemp31 >= 10)) ? 0.22f : 0.26f) : (((iTemp31 >= 8)) ? 0.3f : (((iTemp31 >= 7)) ? 0.35f : 0.4f))) : (((iTemp31 >= 3)) ? (((iTemp31 >= 5)) ? 0.47f : (((iTemp31 >= 4)) ? 0.55f : 0.64f)) : (((iTemp31 >= 2)) ? 0.74f : (((iTemp31 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec21[1] = iRec21[0];
			}
		}
	};


	class SIG2 {
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
				output[i] = ((0.004008016f * float((iRec27[0] + -1))) + -1.0f);
				// post processing
				iRec27[1] = iRec27[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec31[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec31[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec31[0] = (iRec31[1] + 1);
				float 	fTemp59 = float((iRec31[0] + -1));
				float 	fTemp60 = (0.002004008f * fTemp59);
				output[i] = (((fTemp60 < 0.5f)) ? ((0.008016032f * fTemp59) + -1.0f) : ((4.0f * (1.0f - fTemp60)) + -1.0f));
				// post processing
				iRec31[1] = iRec31[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst1;
	FAUSTFLOAT 	fslider0;
	int 	iRec1[2];
	float 	fRec2[2];
	float 	fConst2;
	float 	fRec0[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec3[2];
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	float 	fConst6;
	int 	iRec5[2];
	float 	fConst7;
	float 	fRec6[2];
	float 	fRec4[3];
	int 	iRec9[2];
	float 	fRec10[2];
	float 	fRec8[2];
	static float 	ftbl0[1000];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	float 	fRec12[3];
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec3[2];
	int 	iVec4[2];
	int 	iRec17[2];
	int 	iRec16[2];
	float 	fVec5[2];
	float 	fRec18[2];
	float 	fRec19[2];
	int 	iRec14[3];
	static float 	ftbl1[21];
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	int 	iVec6[2];
	int 	iRec22[2];
	int 	iRec23[2];
	float 	fRec24[2];
	float 	fRec25[2];
	float 	fRec20[2];
	float 	fRec15[2];
	float 	fRec13[3];
	float 	fConst20;
	static float 	ftbl2[500];
	float 	fConst21;
	float 	fRec28[2];
	float 	fRec29[2];
	float 	fRec30[2];
	static float 	ftbl3[500];
	float 	fConst22;
	float 	fRec26[2];
	float 	fConst23;
	float 	fRec32[2];
	float 	fConst24;
	float 	fRec33[2];
	FAUSTFLOAT 	fslider8;
	FAUSTFLOAT 	fslider9;
	float 	fRec34[3];
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec7[2];
	int 	iVec8[2];
	int 	iRec38[2];
	float 	fVec9[2];
	float 	fRec39[2];
	float 	fRec40[2];
	int 	iRec36[3];
	int 	iVec10[2];
	int 	iRec42[2];
	int 	iRec43[2];
	float 	fRec44[2];
	float 	fRec45[2];
	float 	fRec41[2];
	float 	fRec37[2];
	float 	fRec35[3];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec49[2];
	float 	fRec46[2];
	float 	fRec50[2];
	float 	fRec51[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	float 	fRec52[3];
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec11[2];
	int 	iVec12[2];
	int 	iRec56[2];
	float 	fVec13[2];
	float 	fRec57[2];
	float 	fRec58[2];
	int 	iRec54[3];
	int 	iVec14[2];
	int 	iRec60[2];
	int 	iRec61[2];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec59[2];
	float 	fRec55[2];
	float 	fRec53[3];
	float 	fRec65[2];
	float 	fRec66[2];
	float 	fRec67[2];
	float 	fRec64[2];
	float 	fRec68[2];
	float 	fRec69[2];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	float 	fRec70[3];
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec15[2];
	int 	iVec16[2];
	int 	iRec74[2];
	float 	fVec17[2];
	float 	fRec75[2];
	float 	fRec76[2];
	int 	iRec72[3];
	int 	iVec18[2];
	int 	iRec78[2];
	int 	iRec79[2];
	float 	fRec80[2];
	float 	fRec81[2];
	float 	fRec77[2];
	float 	fRec73[2];
	float 	fRec71[3];
	float 	fRec83[2];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec82[2];
	float 	fRec86[2];
	float 	fRec87[2];
	FAUSTFLOAT 	fslider20;
	FAUSTFLOAT 	fslider21;
	float 	fRec88[3];
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec19[2];
	int 	iVec20[2];
	int 	iRec92[2];
	float 	fVec21[2];
	float 	fRec93[2];
	float 	fRec94[2];
	int 	iRec90[3];
	int 	iVec22[2];
	int 	iRec96[2];
	int 	iRec97[2];
	float 	fRec98[2];
	float 	fRec99[2];
	float 	fRec95[2];
	float 	fRec91[2];
	float 	fRec89[3];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec103[2];
	float 	fRec100[2];
	float 	fRec104[2];
	float 	fRec105[2];
	FAUSTFLOAT 	fslider24;
	FAUSTFLOAT 	fslider25;
	float 	fRec106[3];
	FAUSTFLOAT 	fslider26;
	FAUSTFLOAT 	fslider27;
	float 	fVec23[2];
	int 	iVec24[2];
	int 	iRec110[2];
	float 	fVec25[2];
	float 	fRec111[2];
	float 	fRec112[2];
	int 	iRec108[3];
	int 	iVec26[2];
	int 	iRec114[2];
	int 	iRec115[2];
	float 	fRec116[2];
	float 	fRec117[2];
	float 	fRec113[2];
	float 	fRec109[2];
	float 	fRec107[3];
	float 	fRec119[2];
	float 	fRec120[2];
	float 	fRec121[2];
	float 	fRec118[2];
	float 	fRec122[2];
	float 	fRec123[2];
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakhold:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("basics.lib/peakholder:author", "Dario Sanfilippo");
		m->declare("basics.lib/peakholder:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("basics.lib/peakholder:license", "MIT-style STK-4.3 license");
		m->declare("basics.lib/tabulate:author", "Stephane Letz");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.2.0");
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
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.3.0");
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
		fConst1 = (0.3f * fConst0);
		fConst2 = (1e+02f / fConst0);
		fConst3 = max(1.0f, (0.05f * fConst0));
		fConst4 = (1.0f / fConst3);
		fConst5 = (0.15f * fConst0);
		fConst6 = (1.0f / max(1.0f, fConst5));
		fConst7 = (1.0f / fConst0);
		float 	fConst8 = powf(fConst0,2.0f);
		float 	fConst9 = powf((62.831852f / fConst0),2.0f);
		float 	fConst10 = ((fConst9 * ((0.2033f * fConst9) + 0.31755f)) + 1.0f);
		float 	fConst11 = powf(fConst10,2.0f);
		fConst12 = (2.0f * ((3947.8418f * (fConst11 / fConst8)) + -1.0f));
		float 	fConst13 = (3947.8418f * (fConst10 / fConst0));
		fConst14 = (((fConst10 * (fConst13 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst15 = (((fConst10 * (fConst13 + 88.49557f)) / fConst0) + 1.0f);
		fConst16 = (1.0f / fConst15);
		fConst17 = (0.1f * fConst0);
		fConst18 = (0.4f * fConst0);
		fConst19 = (0.2f * fConst0);
		fConst20 = (fConst11 / (fConst8 * fConst15));
		fConst21 = (8.175799f / fConst0);
		fConst22 = (3333.3333f / fConst0);
		fConst23 = (4.0878997f / fConst0);
		fConst24 = (2.0439498f / fConst0);
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = -1.0f;
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
		fslider24 = 0.0f;
		fslider25 = 69.0f;
		fslider26 = 0.0f;
		fslider27 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) iRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec3[i] = 0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) iRec16[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<3; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<3; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<3; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<3; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<3; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<3; i++) iRec72[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) iRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<3; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec92[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<3; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<3; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec110[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<3; i++) iRec108[i] = 0;
		for (int i=0; i<2; i++) iVec26[i] = 0;
		for (int i=0; i<2; i++) iRec114[i] = 0;
		for (int i=0; i<2; i++) iRec115[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<3; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
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
		synth_interface.acc_x = &fslider3;
		synth_interface.acc_y = &fslider2;
		synth_interface.acc_z = &fslider1;
		synth_interface.rot_z = &fslider0;
		synth_interface.note[0] = &fslider25;
		synth_interface.pres[0] = &fslider26;
		synth_interface.vpres[0] = &fslider27;
		synth_interface.but_y[0] = &fslider24;
		synth_interface.note[1] = &fslider21;
		synth_interface.pres[1] = &fslider22;
		synth_interface.vpres[1] = &fslider23;
		synth_interface.but_y[1] = &fslider20;
		synth_interface.note[2] = &fslider17;
		synth_interface.pres[2] = &fslider18;
		synth_interface.vpres[2] = &fslider19;
		synth_interface.but_y[2] = &fslider16;
		synth_interface.note[3] = &fslider13;
		synth_interface.pres[3] = &fslider14;
		synth_interface.vpres[3] = &fslider15;
		synth_interface.but_y[3] = &fslider12;
		synth_interface.note[4] = &fslider9;
		synth_interface.pres[4] = &fslider10;
		synth_interface.vpres[4] = &fslider11;
		synth_interface.but_y[4] = &fslider8;
		synth_interface.note[5] = &fslider5;
		synth_interface.pres[5] = &fslider6;
		synth_interface.vpres[5] = &fslider7;
		synth_interface.but_y[5] = &fslider4;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fabsf(float(fslider0));
		int 	iSlow1 = (float(fslider2) < (0.0f - float(fslider1)));
		float 	fSlow2 = fabsf(float(fslider3));
		float 	fSlow3 = float(fslider4);
		float 	fSlow4 = ftbl0[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (fSlow4 + 1.0f);
		float 	fSlow6 = fastpow2((0.083333336f * float(fslider5)));
		float 	fSlow7 = ((((8.175799f * fSlow6) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow8 = (1.0f - (0.5f * (fSlow7 * fSlow5)));
		float 	fSlow9 = (2.0f * ((2.7822554e-07f * powf(fSlow6,2.0f)) + -1.0f));
		float 	fSlow10 = (2.7822554e-07f * fSlow6);
		float 	fSlow11 = ((fSlow6 * (fSlow10 + -5.274709e-07f)) + 1.0f);
		float 	fSlow12 = ((fSlow6 * (fSlow10 + 5.274709e-07f)) + 1.0f);
		float 	fSlow13 = (1.0f / fSlow12);
		float 	fSlow14 = float(fslider6);
		float 	fSlow15 = float(fslider7);
		int 	iSlow16 = (fSlow15 == 0.0f);
		float 	fSlow17 = (0.9f * fSlow15);
		float 	fSlow18 = (0.0f - fSlow17);
		float 	fSlow19 = max(0.05f, (0.1f - fabsf(fSlow17)));
		float 	fSlow20 = (5.274709e-07f * (fSlow6 / fSlow12));
		float 	fSlow21 = (fConst21 * fSlow6);
		float 	fSlow22 = (0.0f - fSlow3);
		float 	fSlow23 = (fConst23 * fSlow6);
		float 	fSlow24 = (fConst24 * fSlow6);
		float 	fSlow25 = float(fslider8);
		float 	fSlow26 = ftbl0[int(((499.5f * (fSlow25 + 1.0f)) + 0.5f))];
		float 	fSlow27 = (fSlow26 + 1.0f);
		float 	fSlow28 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow29 = ((((8.175799f * fSlow28) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow30 = (1.0f - (0.5f * (fSlow29 * fSlow27)));
		float 	fSlow31 = (2.0f * ((2.7822554e-07f * powf(fSlow28,2.0f)) + -1.0f));
		float 	fSlow32 = (2.7822554e-07f * fSlow28);
		float 	fSlow33 = ((fSlow28 * (fSlow32 + -5.274709e-07f)) + 1.0f);
		float 	fSlow34 = ((fSlow28 * (fSlow32 + 5.274709e-07f)) + 1.0f);
		float 	fSlow35 = (1.0f / fSlow34);
		float 	fSlow36 = float(fslider10);
		float 	fSlow37 = float(fslider11);
		int 	iSlow38 = (fSlow37 == 0.0f);
		float 	fSlow39 = (0.9f * fSlow37);
		float 	fSlow40 = (0.0f - fSlow39);
		float 	fSlow41 = max(0.05f, (0.1f - fabsf(fSlow39)));
		float 	fSlow42 = (5.274709e-07f * (fSlow28 / fSlow34));
		float 	fSlow43 = (fConst21 * fSlow28);
		float 	fSlow44 = (0.0f - fSlow25);
		float 	fSlow45 = (fConst23 * fSlow28);
		float 	fSlow46 = (fConst24 * fSlow28);
		float 	fSlow47 = float(fslider12);
		float 	fSlow48 = ftbl0[int(((499.5f * (fSlow47 + 1.0f)) + 0.5f))];
		float 	fSlow49 = (fSlow48 + 1.0f);
		float 	fSlow50 = fastpow2((0.083333336f * float(fslider13)));
		float 	fSlow51 = ((((8.175799f * fSlow50) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow52 = (1.0f - (0.5f * (fSlow51 * fSlow49)));
		float 	fSlow53 = (2.0f * ((2.7822554e-07f * powf(fSlow50,2.0f)) + -1.0f));
		float 	fSlow54 = (2.7822554e-07f * fSlow50);
		float 	fSlow55 = ((fSlow50 * (fSlow54 + -5.274709e-07f)) + 1.0f);
		float 	fSlow56 = ((fSlow50 * (fSlow54 + 5.274709e-07f)) + 1.0f);
		float 	fSlow57 = (1.0f / fSlow56);
		float 	fSlow58 = float(fslider14);
		float 	fSlow59 = float(fslider15);
		int 	iSlow60 = (fSlow59 == 0.0f);
		float 	fSlow61 = (0.9f * fSlow59);
		float 	fSlow62 = (0.0f - fSlow61);
		float 	fSlow63 = max(0.05f, (0.1f - fabsf(fSlow61)));
		float 	fSlow64 = (5.274709e-07f * (fSlow50 / fSlow56));
		float 	fSlow65 = (fConst21 * fSlow50);
		float 	fSlow66 = (0.0f - fSlow47);
		float 	fSlow67 = (fConst23 * fSlow50);
		float 	fSlow68 = (fConst24 * fSlow50);
		float 	fSlow69 = float(fslider16);
		float 	fSlow70 = ftbl0[int(((499.5f * (fSlow69 + 1.0f)) + 0.5f))];
		float 	fSlow71 = (fSlow70 + 1.0f);
		float 	fSlow72 = fastpow2((0.083333336f * float(fslider17)));
		float 	fSlow73 = ((((8.175799f * fSlow72) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow74 = (1.0f - (0.5f * (fSlow73 * fSlow71)));
		float 	fSlow75 = (2.0f * ((2.7822554e-07f * powf(fSlow72,2.0f)) + -1.0f));
		float 	fSlow76 = (2.7822554e-07f * fSlow72);
		float 	fSlow77 = ((fSlow72 * (fSlow76 + -5.274709e-07f)) + 1.0f);
		float 	fSlow78 = ((fSlow72 * (fSlow76 + 5.274709e-07f)) + 1.0f);
		float 	fSlow79 = (1.0f / fSlow78);
		float 	fSlow80 = float(fslider18);
		float 	fSlow81 = float(fslider19);
		int 	iSlow82 = (fSlow81 == 0.0f);
		float 	fSlow83 = (0.9f * fSlow81);
		float 	fSlow84 = (0.0f - fSlow83);
		float 	fSlow85 = max(0.05f, (0.1f - fabsf(fSlow83)));
		float 	fSlow86 = (5.274709e-07f * (fSlow72 / fSlow78));
		float 	fSlow87 = (fConst21 * fSlow72);
		float 	fSlow88 = (0.0f - fSlow69);
		float 	fSlow89 = (fConst23 * fSlow72);
		float 	fSlow90 = (fConst24 * fSlow72);
		float 	fSlow91 = float(fslider20);
		float 	fSlow92 = ftbl0[int(((499.5f * (fSlow91 + 1.0f)) + 0.5f))];
		float 	fSlow93 = (fSlow92 + 1.0f);
		float 	fSlow94 = fastpow2((0.083333336f * float(fslider21)));
		float 	fSlow95 = ((((8.175799f * fSlow94) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow96 = (1.0f - (0.5f * (fSlow95 * fSlow93)));
		float 	fSlow97 = (2.0f * ((2.7822554e-07f * powf(fSlow94,2.0f)) + -1.0f));
		float 	fSlow98 = (2.7822554e-07f * fSlow94);
		float 	fSlow99 = ((fSlow94 * (fSlow98 + -5.274709e-07f)) + 1.0f);
		float 	fSlow100 = ((fSlow94 * (fSlow98 + 5.274709e-07f)) + 1.0f);
		float 	fSlow101 = (1.0f / fSlow100);
		float 	fSlow102 = float(fslider22);
		float 	fSlow103 = float(fslider23);
		int 	iSlow104 = (fSlow103 == 0.0f);
		float 	fSlow105 = (0.9f * fSlow103);
		float 	fSlow106 = (0.0f - fSlow105);
		float 	fSlow107 = max(0.05f, (0.1f - fabsf(fSlow105)));
		float 	fSlow108 = (5.274709e-07f * (fSlow94 / fSlow100));
		float 	fSlow109 = (fConst21 * fSlow94);
		float 	fSlow110 = (0.0f - fSlow91);
		float 	fSlow111 = (fConst23 * fSlow94);
		float 	fSlow112 = (fConst24 * fSlow94);
		float 	fSlow113 = float(fslider24);
		float 	fSlow114 = ftbl0[int(((499.5f * (fSlow113 + 1.0f)) + 0.5f))];
		float 	fSlow115 = (fSlow114 + 1.0f);
		float 	fSlow116 = fastpow2((0.083333336f * float(fslider25)));
		float 	fSlow117 = ((((8.175799f * fSlow116) >= 8e+01f)) ? 0.1f : 0.0f);
		float 	fSlow118 = (1.0f - (0.5f * (fSlow117 * fSlow115)));
		float 	fSlow119 = (2.0f * ((2.7822554e-07f * powf(fSlow116,2.0f)) + -1.0f));
		float 	fSlow120 = (2.7822554e-07f * fSlow116);
		float 	fSlow121 = ((fSlow116 * (fSlow120 + -5.274709e-07f)) + 1.0f);
		float 	fSlow122 = ((fSlow116 * (fSlow120 + 5.274709e-07f)) + 1.0f);
		float 	fSlow123 = (1.0f / fSlow122);
		float 	fSlow124 = float(fslider26);
		float 	fSlow125 = float(fslider27);
		int 	iSlow126 = (fSlow125 == 0.0f);
		float 	fSlow127 = (0.9f * fSlow125);
		float 	fSlow128 = (0.0f - fSlow127);
		float 	fSlow129 = max(0.05f, (0.1f - fabsf(fSlow127)));
		float 	fSlow130 = (5.274709e-07f * (fSlow116 / fSlow122));
		float 	fSlow131 = (fConst21 * fSlow116);
		float 	fSlow132 = (0.0f - fSlow113);
		float 	fSlow133 = (fConst23 * fSlow116);
		float 	fSlow134 = (fConst24 * fSlow116);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp0 = ((fSlow0 >= fRec2[1]) | (float(iRec1[1]) >= fConst1));
			iRec1[0] = ((iTemp0) ? 0 : (iRec1[1] + 1));
			fRec2[0] = ((iTemp0) ? fSlow0 : fRec2[1]);
			float 	fTemp1 = ((5e+02f * fRec2[0]) + 6e+01f);
			float 	fTemp2 = (fRec0[1] - fConst2);
			float 	fTemp3 = (fConst2 + fRec0[1]);
			fRec0[0] = (((fTemp3 < fTemp1)) ? fTemp3 : (((fTemp2 > fTemp1)) ? fTemp2 : fTemp1));
			float 	fTemp4 = (4.162331e-09f * fRec0[0]);
			float 	fTemp5 = ((fRec0[0] * (fTemp4 + 1.6129032e-06f)) + 1.0f);
			fVec1[0] = fSlow2;
			float 	fTemp6 = (fSlow2 - fVec1[1]);
			int 	iTemp7 = ((fTemp6 > 0.04f) & iSlow1);
			iVec2[0] = iTemp7;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (iVec2[0] <= iVec2[1])) + (iVec2[0] > iVec2[1]));
			float 	fTemp8 = float(iRec3[0]);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float 	fTemp9 = float(iRec5[0]);
			float 	fTemp10 = max(1.1920929e-07f, fabsf(fRec0[0]));
			float 	fTemp11 = (fRec6[1] + (fConst7 * fTemp10));
			float 	fTemp12 = (fTemp11 + -1.0f);
			int 	iTemp13 = (fTemp12 < 0.0f);
			fRec6[0] = ((iTemp13) ? fTemp11 : fTemp12);
			float 	fRec7 = ((iTemp13) ? fTemp11 : (fTemp11 + ((1.0f - (fConst0 / fTemp10)) * fTemp12)));
			fRec4[0] = (((0.8f * ((2.0f * fRec7) + -1.0f)) + (9.313226e-11f * fTemp9)) - (((((fRec0[0] * (fTemp4 + -1.6129032e-06f)) + 1.0f) * fRec4[2]) + (2.0f * (((4.162331e-09f * powf(fRec0[0],2.0f)) + -1.0f) * fRec4[1]))) / fTemp5));
			float 	fTemp14 = fabsf(fTemp6);
			int 	iTemp15 = ((fTemp14 >= fRec10[1]) | (float(iRec9[1]) >= fConst1));
			iRec9[0] = ((iTemp15) ? 0 : (iRec9[1] + 1));
			fRec10[0] = ((iTemp15) ? fTemp14 : fRec10[1]);
			float 	fTemp16 = (fRec8[1] - fConst2);
			float 	fTemp17 = (fConst2 + fRec8[1]);
			fRec8[0] = (((fTemp17 < fRec10[0])) ? fTemp17 : (((fTemp16 > fRec10[0])) ? fTemp16 : fRec10[0]));
			float 	fTemp19 = (4.656613e-10f * fTemp9);
			fRec12[0] = (fTemp19 - (fSlow13 * ((fSlow11 * fRec12[2]) + (fSlow9 * fRec12[1]))));
			fVec3[0] = fSlow15;
			int 	iTemp20 = (fSlow17 != (0.9f * fVec3[1]));
			iVec4[0] = iTemp20;
			int 	iTemp21 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec17[0] = (iRec17[1] + 1);
			int 	iTemp22 = (iRec17[0] + -1);
			iRec16[0] = ((iRec16[1] * (1 - iTemp21)) + (iTemp22 * iTemp21));
			float 	fTemp23 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec16[0])))) > 0.5f) & iSlow16)) ? 0.0f : fSlow14) + 1.0f)) + 0.5f))];
			fVec5[0] = fTemp23;
			int 	iTemp24 = (fVec5[0] > 0.003f);
			int 	iTemp25 = (fVec5[0] <= 0.003f);
			float 	fTemp26 = float((iTemp25 | (fVec5[1] >= 0.003f)));
			fRec18[0] = max((fRec18[1] * fTemp26), fSlow17);
			fRec19[0] = max((fTemp26 * fRec19[1]), fSlow18);
			float 	fTemp27 = (min(1.0f, fRec19[0]) + min(1.0f, fRec18[0]));
			int 	iTemp28 = (fVec5[0] >= fRec15[1]);
			int 	iTemp29 = (fRec15[1] <= 0.001f);
			int 	iTemp30 = (((iRec14[1] >= 4)) ? (((iRec14[1] >= 6)) ? ((iTemp29) ? 0 : ((iTemp24) ? 1 : 6)) : (((iRec14[1] >= 5)) ? ((iTemp25) ? 3 : ((iTemp28) ? 4 : 5)) : ((iTemp25) ? 3 : (((fVec5[0] <= fRec15[1])) ? 5 : 4)))) : (((iRec14[1] >= 2)) ? (((iRec14[1] >= 3)) ? (((iTemp25 & iTemp29)) ? 0 : ((iTemp24) ? 1 : 3)) : ((iTemp25) ? 6 : ((iTemp28) ? 4 : 2))) : (((iRec14[1] >= 1)) ? (((fRec15[1] >= min(fTemp27, 1.0f))) ? ((iTemp25) ? 6 : 2) : 1) : ((iTemp24) ? 1 : 0))));
			iRec14[0] = iTemp30;
			float 	fTemp32 = (((iTemp30 >= 4)) ? (((iTemp30 >= 6)) ? fConst0 : fConst19) : (((iTemp30 >= 2)) ? (((iTemp30 >= 3)) ? fConst5 : fConst18) : (((iTemp30 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp33 = (iRec14[1] != iRec14[2]);
			iVec6[0] = iTemp33;
			int 	iTemp34 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec22[0] = ((iRec22[1] * (1 - iTemp34)) + (iTemp22 * iTemp34));
			float 	fTemp35 = (2e+01f * (((fTemp32 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec22[0]))) / fTemp32) : 0.0f));
			int 	iTemp36 = int(fTemp35);
			float 	fTemp37 = ftbl1[max(0, int(min(int(iTemp36), 20)))];
			float 	fTemp38 = (fTemp37 + ((fTemp35 - float(iTemp36)) * (ftbl1[max(0, int(min(int((iTemp36 + 1)), 20)))] - fTemp37)));
			iRec23[0] = iRec14[1];
			int 	iTemp39 = (iRec23[1] == iRec14[1]);
			int 	iTemp40 = (iRec14[1] == 0);
			fRec24[0] = ((iTemp40) ? fVec5[0] : ((iTemp39) ? min(min(fRec24[1], fVec5[0]), fRec15[1]) : min(fVec5[0], fRec15[1])));
			fRec25[0] = ((iTemp40) ? fVec5[0] : ((iTemp39) ? max(max(fRec25[1], fVec5[0]), fRec15[1]) : max(fVec5[0], fRec15[1])));
			int 	iTemp41 = (iRec14[1] == 3);
			int 	iTemp42 = (iRec14[1] == 6);
			float 	fTemp43 = (((iRec14[1] == 1)) ? min(1.0f, fTemp27) : ((iTemp40) ? 0.0f : ((iTemp42) ? (fTemp27 * fTemp38) : ((iTemp41) ? (fRec25[0] * fTemp38) : fVec5[0]))));
			float 	fTemp44 = (1.0f / ((iTemp40) ? 0.0001f : (((iTemp41 | iTemp42)) ? (0.04761905f * fTemp32) : fTemp32)));
			float 	fTemp45 = (fRec20[1] - fTemp44);
			float 	fTemp46 = (fRec20[1] + fTemp44);
			fRec20[0] = (((fTemp46 < fTemp43)) ? fTemp46 : (((fTemp45 > fTemp43)) ? fTemp45 : fTemp43));
			fRec15[0] = fRec20[0];
			fRec13[0] = (fRec15[0] - (fConst16 * ((fConst14 * fRec13[2]) + (fConst12 * fRec13[1]))));
			float 	fTemp47 = min(0.99f, (fConst20 * (((3947.8418f * fRec13[0]) + (7895.6836f * fRec13[1])) + (3947.8418f * fRec13[2]))));
			float 	fTemp48 = min(1.0f, (fSlow19 + (((fTemp47 < 0.1f)) ? (1.0f - (1e+01f * fTemp47)) : 0.0f)));
			int 	iTemp49 = (1 - iVec0[1]);
			float 	fTemp50 = ((iTemp49) ? 0.0f : (fSlow21 + fRec28[1]));
			fRec28[0] = (fTemp50 - floorf(fTemp50));
			float 	fTemp51 = (499.0f * fRec28[0]);
			int 	iTemp52 = int(fTemp51);
			int 	iTemp53 = max(0, min(iTemp52, 499));
			float 	fTemp54 = ftbl2[iTemp53];
			int 	iTemp55 = max(0, min((iTemp52 + 1), 499));
			float 	fTemp56 = (fTemp51 - float(iTemp52));
			float 	fTemp57 = float((((fVec5[1] <= 0.003f) & iTemp24) != 1));
			fRec29[0] = max((fTemp57 * fRec29[1]), fSlow22);
			fRec30[0] = max((fRec30[1] * fTemp57), fSlow3);
			float 	fTemp58 = max(min(((0.5f * (fVec5[0] - fTemp47)) + (0.2f - (0.8f * ((iTemp25) ? (2.0f * (((fRec30[0] > fRec29[0])) ? fRec30[0] : (0.0f - fRec29[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp61 = ftbl3[iTemp53];
			float 	fTemp62 = (((fTemp61 + (fTemp56 * (ftbl3[iTemp55] - fTemp61))) * (1.0f - fTemp58)) + (fTemp58 * (fTemp54 + (fTemp56 * (ftbl2[iTemp55] - fTemp54)))));
			float 	fTemp63 = (fRec26[1] - fConst22);
			float 	fTemp64 = (fConst22 + fRec26[1]);
			fRec26[0] = (((fTemp64 < fTemp62)) ? fTemp64 : (((fTemp63 > fTemp62)) ? fTemp63 : fTemp62));
			float 	fTemp65 = ((iTemp49) ? 0.0f : (fSlow23 + fRec32[1]));
			fRec32[0] = (fTemp65 - floorf(fTemp65));
			float 	fTemp66 = (499.0f * fRec32[0]);
			int 	iTemp67 = int(fTemp66);
			float 	fTemp68 = ftbl3[max(0, min(iTemp67, 499))];
			float 	fTemp69 = ((iTemp49) ? 0.0f : (fSlow24 + fRec33[1]));
			fRec33[0] = (fTemp69 - floorf(fTemp69));
			float 	fTemp70 = (499.0f * fRec33[0]);
			int 	iTemp71 = int(fTemp70);
			float 	fTemp72 = ftbl2[max(0, min(iTemp71, 499))];
			fRec34[0] = (fTemp19 - (fSlow35 * ((fSlow33 * fRec34[2]) + (fSlow31 * fRec34[1]))));
			fVec7[0] = fSlow37;
			int 	iTemp73 = (fSlow39 != (0.9f * fVec7[1]));
			iVec8[0] = iTemp73;
			int 	iTemp74 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec38[0] = ((iRec38[1] * (1 - iTemp74)) + (iTemp22 * iTemp74));
			float 	fTemp75 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec38[0])))) > 0.5f) & iSlow38)) ? 0.0f : fSlow36) + 1.0f)) + 0.5f))];
			fVec9[0] = fTemp75;
			int 	iTemp76 = (fVec9[0] > 0.003f);
			int 	iTemp77 = (fVec9[0] <= 0.003f);
			float 	fTemp78 = float((iTemp77 | (fVec9[1] >= 0.003f)));
			fRec39[0] = max((fRec39[1] * fTemp78), fSlow39);
			fRec40[0] = max((fTemp78 * fRec40[1]), fSlow40);
			float 	fTemp79 = (min(1.0f, fRec40[0]) + min(1.0f, fRec39[0]));
			int 	iTemp80 = (fVec9[0] >= fRec37[1]);
			int 	iTemp81 = (fRec37[1] <= 0.001f);
			int 	iTemp82 = (((iRec36[1] >= 4)) ? (((iRec36[1] >= 6)) ? ((iTemp81) ? 0 : ((iTemp76) ? 1 : 6)) : (((iRec36[1] >= 5)) ? ((iTemp77) ? 3 : ((iTemp80) ? 4 : 5)) : ((iTemp77) ? 3 : (((fVec9[0] <= fRec37[1])) ? 5 : 4)))) : (((iRec36[1] >= 2)) ? (((iRec36[1] >= 3)) ? (((iTemp77 & iTemp81)) ? 0 : ((iTemp76) ? 1 : 3)) : ((iTemp77) ? 6 : ((iTemp80) ? 4 : 2))) : (((iRec36[1] >= 1)) ? (((fRec37[1] >= min(fTemp79, 1.0f))) ? ((iTemp77) ? 6 : 2) : 1) : ((iTemp76) ? 1 : 0))));
			iRec36[0] = iTemp82;
			float 	fTemp83 = (((iTemp82 >= 4)) ? (((iTemp82 >= 6)) ? fConst0 : fConst19) : (((iTemp82 >= 2)) ? (((iTemp82 >= 3)) ? fConst5 : fConst18) : (((iTemp82 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp84 = (iRec36[1] != iRec36[2]);
			iVec10[0] = iTemp84;
			int 	iTemp85 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec42[0] = ((iRec42[1] * (1 - iTemp85)) + (iTemp22 * iTemp85));
			float 	fTemp86 = (2e+01f * (((fTemp83 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec42[0]))) / fTemp83) : 0.0f));
			int 	iTemp87 = int(fTemp86);
			float 	fTemp88 = ftbl1[max(0, int(min(int(iTemp87), 20)))];
			float 	fTemp89 = (fTemp88 + ((fTemp86 - float(iTemp87)) * (ftbl1[max(0, int(min(int((iTemp87 + 1)), 20)))] - fTemp88)));
			iRec43[0] = iRec36[1];
			int 	iTemp90 = (iRec43[1] == iRec36[1]);
			int 	iTemp91 = (iRec36[1] == 0);
			fRec44[0] = ((iTemp91) ? fVec9[0] : ((iTemp90) ? min(min(fRec44[1], fVec9[0]), fRec37[1]) : min(fVec9[0], fRec37[1])));
			fRec45[0] = ((iTemp91) ? fVec9[0] : ((iTemp90) ? max(max(fRec45[1], fVec9[0]), fRec37[1]) : max(fVec9[0], fRec37[1])));
			int 	iTemp92 = (iRec36[1] == 3);
			int 	iTemp93 = (iRec36[1] == 6);
			float 	fTemp94 = (((iRec36[1] == 1)) ? min(1.0f, fTemp79) : ((iTemp91) ? 0.0f : ((iTemp93) ? (fTemp79 * fTemp89) : ((iTemp92) ? (fRec45[0] * fTemp89) : fVec9[0]))));
			float 	fTemp95 = (1.0f / ((iTemp91) ? 0.0001f : (((iTemp92 | iTemp93)) ? (0.04761905f * fTemp83) : fTemp83)));
			float 	fTemp96 = (fRec41[1] - fTemp95);
			float 	fTemp97 = (fRec41[1] + fTemp95);
			fRec41[0] = (((fTemp97 < fTemp94)) ? fTemp97 : (((fTemp96 > fTemp94)) ? fTemp96 : fTemp94));
			fRec37[0] = fRec41[0];
			fRec35[0] = (fRec37[0] - (fConst16 * ((fConst14 * fRec35[2]) + (fConst12 * fRec35[1]))));
			float 	fTemp98 = min(0.99f, (fConst20 * (((3947.8418f * fRec35[0]) + (7895.6836f * fRec35[1])) + (3947.8418f * fRec35[2]))));
			float 	fTemp99 = min(1.0f, (fSlow41 + (((fTemp98 < 0.1f)) ? (1.0f - (1e+01f * fTemp98)) : 0.0f)));
			float 	fTemp100 = ((iTemp49) ? 0.0f : (fSlow43 + fRec47[1]));
			fRec47[0] = (fTemp100 - floorf(fTemp100));
			float 	fTemp101 = (499.0f * fRec47[0]);
			int 	iTemp102 = int(fTemp101);
			int 	iTemp103 = max(0, min(iTemp102, 499));
			float 	fTemp104 = ftbl2[iTemp103];
			int 	iTemp105 = max(0, min((iTemp102 + 1), 499));
			float 	fTemp106 = (fTemp101 - float(iTemp102));
			float 	fTemp107 = float((((fVec9[1] <= 0.003f) & iTemp76) != 1));
			fRec48[0] = max((fTemp107 * fRec48[1]), fSlow44);
			fRec49[0] = max((fRec49[1] * fTemp107), fSlow25);
			float 	fTemp108 = max(min(((0.5f * (fVec9[0] - fTemp98)) + (0.2f - (0.8f * ((iTemp77) ? (2.0f * (((fRec49[0] > fRec48[0])) ? fRec49[0] : (0.0f - fRec48[0]))) : fSlow26)))), 1.0f), 0.0f);
			float 	fTemp109 = ftbl3[iTemp103];
			float 	fTemp110 = (((fTemp109 + (fTemp106 * (ftbl3[iTemp105] - fTemp109))) * (1.0f - fTemp108)) + (fTemp108 * (fTemp104 + (fTemp106 * (ftbl2[iTemp105] - fTemp104)))));
			float 	fTemp111 = (fRec46[1] - fConst22);
			float 	fTemp112 = (fConst22 + fRec46[1]);
			fRec46[0] = (((fTemp112 < fTemp110)) ? fTemp112 : (((fTemp111 > fTemp110)) ? fTemp111 : fTemp110));
			float 	fTemp113 = ((iTemp49) ? 0.0f : (fSlow45 + fRec50[1]));
			fRec50[0] = (fTemp113 - floorf(fTemp113));
			float 	fTemp114 = (499.0f * fRec50[0]);
			int 	iTemp115 = int(fTemp114);
			float 	fTemp116 = ftbl3[max(0, min(iTemp115, 499))];
			float 	fTemp117 = ((iTemp49) ? 0.0f : (fSlow46 + fRec51[1]));
			fRec51[0] = (fTemp117 - floorf(fTemp117));
			float 	fTemp118 = (499.0f * fRec51[0]);
			int 	iTemp119 = int(fTemp118);
			float 	fTemp120 = ftbl2[max(0, min(iTemp119, 499))];
			fRec52[0] = (fTemp19 - (fSlow57 * ((fSlow55 * fRec52[2]) + (fSlow53 * fRec52[1]))));
			fVec11[0] = fSlow59;
			int 	iTemp121 = (fSlow61 != (0.9f * fVec11[1]));
			iVec12[0] = iTemp121;
			int 	iTemp122 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec56[0] = ((iRec56[1] * (1 - iTemp122)) + (iTemp22 * iTemp122));
			float 	fTemp123 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec56[0])))) > 0.5f) & iSlow60)) ? 0.0f : fSlow58) + 1.0f)) + 0.5f))];
			fVec13[0] = fTemp123;
			int 	iTemp124 = (fVec13[0] > 0.003f);
			int 	iTemp125 = (fVec13[0] <= 0.003f);
			float 	fTemp126 = float((iTemp125 | (fVec13[1] >= 0.003f)));
			fRec57[0] = max((fRec57[1] * fTemp126), fSlow61);
			fRec58[0] = max((fTemp126 * fRec58[1]), fSlow62);
			float 	fTemp127 = (min(1.0f, fRec58[0]) + min(1.0f, fRec57[0]));
			int 	iTemp128 = (fVec13[0] >= fRec55[1]);
			int 	iTemp129 = (fRec55[1] <= 0.001f);
			int 	iTemp130 = (((iRec54[1] >= 4)) ? (((iRec54[1] >= 6)) ? ((iTemp129) ? 0 : ((iTemp124) ? 1 : 6)) : (((iRec54[1] >= 5)) ? ((iTemp125) ? 3 : ((iTemp128) ? 4 : 5)) : ((iTemp125) ? 3 : (((fVec13[0] <= fRec55[1])) ? 5 : 4)))) : (((iRec54[1] >= 2)) ? (((iRec54[1] >= 3)) ? (((iTemp125 & iTemp129)) ? 0 : ((iTemp124) ? 1 : 3)) : ((iTemp125) ? 6 : ((iTemp128) ? 4 : 2))) : (((iRec54[1] >= 1)) ? (((fRec55[1] >= min(fTemp127, 1.0f))) ? ((iTemp125) ? 6 : 2) : 1) : ((iTemp124) ? 1 : 0))));
			iRec54[0] = iTemp130;
			float 	fTemp131 = (((iTemp130 >= 4)) ? (((iTemp130 >= 6)) ? fConst0 : fConst19) : (((iTemp130 >= 2)) ? (((iTemp130 >= 3)) ? fConst5 : fConst18) : (((iTemp130 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp132 = (iRec54[1] != iRec54[2]);
			iVec14[0] = iTemp132;
			int 	iTemp133 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp133)) + (iTemp22 * iTemp133));
			float 	fTemp134 = (2e+01f * (((fTemp131 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec60[0]))) / fTemp131) : 0.0f));
			int 	iTemp135 = int(fTemp134);
			float 	fTemp136 = ftbl1[max(0, int(min(int(iTemp135), 20)))];
			float 	fTemp137 = (fTemp136 + ((fTemp134 - float(iTemp135)) * (ftbl1[max(0, int(min(int((iTemp135 + 1)), 20)))] - fTemp136)));
			iRec61[0] = iRec54[1];
			int 	iTemp138 = (iRec61[1] == iRec54[1]);
			int 	iTemp139 = (iRec54[1] == 0);
			fRec62[0] = ((iTemp139) ? fVec13[0] : ((iTemp138) ? min(min(fRec62[1], fVec13[0]), fRec55[1]) : min(fVec13[0], fRec55[1])));
			fRec63[0] = ((iTemp139) ? fVec13[0] : ((iTemp138) ? max(max(fRec63[1], fVec13[0]), fRec55[1]) : max(fVec13[0], fRec55[1])));
			int 	iTemp140 = (iRec54[1] == 3);
			int 	iTemp141 = (iRec54[1] == 6);
			float 	fTemp142 = (((iRec54[1] == 1)) ? min(1.0f, fTemp127) : ((iTemp139) ? 0.0f : ((iTemp141) ? (fTemp127 * fTemp137) : ((iTemp140) ? (fRec63[0] * fTemp137) : fVec13[0]))));
			float 	fTemp143 = (1.0f / ((iTemp139) ? 0.0001f : (((iTemp140 | iTemp141)) ? (0.04761905f * fTemp131) : fTemp131)));
			float 	fTemp144 = (fRec59[1] - fTemp143);
			float 	fTemp145 = (fRec59[1] + fTemp143);
			fRec59[0] = (((fTemp145 < fTemp142)) ? fTemp145 : (((fTemp144 > fTemp142)) ? fTemp144 : fTemp142));
			fRec55[0] = fRec59[0];
			fRec53[0] = (fRec55[0] - (fConst16 * ((fConst14 * fRec53[2]) + (fConst12 * fRec53[1]))));
			float 	fTemp146 = min(0.99f, (fConst20 * (((3947.8418f * fRec53[0]) + (7895.6836f * fRec53[1])) + (3947.8418f * fRec53[2]))));
			float 	fTemp147 = min(1.0f, (fSlow63 + (((fTemp146 < 0.1f)) ? (1.0f - (1e+01f * fTemp146)) : 0.0f)));
			float 	fTemp148 = ((iTemp49) ? 0.0f : (fSlow65 + fRec65[1]));
			fRec65[0] = (fTemp148 - floorf(fTemp148));
			float 	fTemp149 = (499.0f * fRec65[0]);
			int 	iTemp150 = int(fTemp149);
			int 	iTemp151 = max(0, min(iTemp150, 499));
			float 	fTemp152 = ftbl2[iTemp151];
			int 	iTemp153 = max(0, min((iTemp150 + 1), 499));
			float 	fTemp154 = (fTemp149 - float(iTemp150));
			float 	fTemp155 = float((((fVec13[1] <= 0.003f) & iTemp124) != 1));
			fRec66[0] = max((fTemp155 * fRec66[1]), fSlow66);
			fRec67[0] = max((fRec67[1] * fTemp155), fSlow47);
			float 	fTemp156 = max(min(((0.5f * (fVec13[0] - fTemp146)) + (0.2f - (0.8f * ((iTemp125) ? (2.0f * (((fRec67[0] > fRec66[0])) ? fRec67[0] : (0.0f - fRec66[0]))) : fSlow48)))), 1.0f), 0.0f);
			float 	fTemp157 = ftbl3[iTemp151];
			float 	fTemp158 = (((fTemp157 + (fTemp154 * (ftbl3[iTemp153] - fTemp157))) * (1.0f - fTemp156)) + (fTemp156 * (fTemp152 + (fTemp154 * (ftbl2[iTemp153] - fTemp152)))));
			float 	fTemp159 = (fRec64[1] - fConst22);
			float 	fTemp160 = (fConst22 + fRec64[1]);
			fRec64[0] = (((fTemp160 < fTemp158)) ? fTemp160 : (((fTemp159 > fTemp158)) ? fTemp159 : fTemp158));
			float 	fTemp161 = ((iTemp49) ? 0.0f : (fSlow67 + fRec68[1]));
			fRec68[0] = (fTemp161 - floorf(fTemp161));
			float 	fTemp162 = (499.0f * fRec68[0]);
			int 	iTemp163 = int(fTemp162);
			float 	fTemp164 = ftbl3[max(0, min(iTemp163, 499))];
			float 	fTemp165 = ((iTemp49) ? 0.0f : (fSlow68 + fRec69[1]));
			fRec69[0] = (fTemp165 - floorf(fTemp165));
			float 	fTemp166 = (499.0f * fRec69[0]);
			int 	iTemp167 = int(fTemp166);
			float 	fTemp168 = ftbl2[max(0, min(iTemp167, 499))];
			fRec70[0] = (fTemp19 - (fSlow79 * ((fSlow77 * fRec70[2]) + (fSlow75 * fRec70[1]))));
			fVec15[0] = fSlow81;
			int 	iTemp169 = (fSlow83 != (0.9f * fVec15[1]));
			iVec16[0] = iTemp169;
			int 	iTemp170 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec74[0] = ((iRec74[1] * (1 - iTemp170)) + (iTemp22 * iTemp170));
			float 	fTemp171 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec74[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec17[0] = fTemp171;
			int 	iTemp172 = (fVec17[0] > 0.003f);
			int 	iTemp173 = (fVec17[0] <= 0.003f);
			float 	fTemp174 = float((iTemp173 | (fVec17[1] >= 0.003f)));
			fRec75[0] = max((fRec75[1] * fTemp174), fSlow83);
			fRec76[0] = max((fTemp174 * fRec76[1]), fSlow84);
			float 	fTemp175 = (min(1.0f, fRec76[0]) + min(1.0f, fRec75[0]));
			int 	iTemp176 = (fVec17[0] >= fRec73[1]);
			int 	iTemp177 = (fRec73[1] <= 0.001f);
			int 	iTemp178 = (((iRec72[1] >= 4)) ? (((iRec72[1] >= 6)) ? ((iTemp177) ? 0 : ((iTemp172) ? 1 : 6)) : (((iRec72[1] >= 5)) ? ((iTemp173) ? 3 : ((iTemp176) ? 4 : 5)) : ((iTemp173) ? 3 : (((fVec17[0] <= fRec73[1])) ? 5 : 4)))) : (((iRec72[1] >= 2)) ? (((iRec72[1] >= 3)) ? (((iTemp173 & iTemp177)) ? 0 : ((iTemp172) ? 1 : 3)) : ((iTemp173) ? 6 : ((iTemp176) ? 4 : 2))) : (((iRec72[1] >= 1)) ? (((fRec73[1] >= min(fTemp175, 1.0f))) ? ((iTemp173) ? 6 : 2) : 1) : ((iTemp172) ? 1 : 0))));
			iRec72[0] = iTemp178;
			float 	fTemp179 = (((iTemp178 >= 4)) ? (((iTemp178 >= 6)) ? fConst0 : fConst19) : (((iTemp178 >= 2)) ? (((iTemp178 >= 3)) ? fConst5 : fConst18) : (((iTemp178 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp180 = (iRec72[1] != iRec72[2]);
			iVec18[0] = iTemp180;
			int 	iTemp181 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec78[0] = ((iRec78[1] * (1 - iTemp181)) + (iTemp22 * iTemp181));
			float 	fTemp182 = (2e+01f * (((fTemp179 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec78[0]))) / fTemp179) : 0.0f));
			int 	iTemp183 = int(fTemp182);
			float 	fTemp184 = ftbl1[max(0, int(min(int(iTemp183), 20)))];
			float 	fTemp185 = (fTemp184 + ((fTemp182 - float(iTemp183)) * (ftbl1[max(0, int(min(int((iTemp183 + 1)), 20)))] - fTemp184)));
			iRec79[0] = iRec72[1];
			int 	iTemp186 = (iRec79[1] == iRec72[1]);
			int 	iTemp187 = (iRec72[1] == 0);
			fRec80[0] = ((iTemp187) ? fVec17[0] : ((iTemp186) ? min(min(fRec80[1], fVec17[0]), fRec73[1]) : min(fVec17[0], fRec73[1])));
			fRec81[0] = ((iTemp187) ? fVec17[0] : ((iTemp186) ? max(max(fRec81[1], fVec17[0]), fRec73[1]) : max(fVec17[0], fRec73[1])));
			int 	iTemp188 = (iRec72[1] == 3);
			int 	iTemp189 = (iRec72[1] == 6);
			float 	fTemp190 = (((iRec72[1] == 1)) ? min(1.0f, fTemp175) : ((iTemp187) ? 0.0f : ((iTemp189) ? (fTemp175 * fTemp185) : ((iTemp188) ? (fRec81[0] * fTemp185) : fVec17[0]))));
			float 	fTemp191 = (1.0f / ((iTemp187) ? 0.0001f : (((iTemp188 | iTemp189)) ? (0.04761905f * fTemp179) : fTemp179)));
			float 	fTemp192 = (fRec77[1] - fTemp191);
			float 	fTemp193 = (fRec77[1] + fTemp191);
			fRec77[0] = (((fTemp193 < fTemp190)) ? fTemp193 : (((fTemp192 > fTemp190)) ? fTemp192 : fTemp190));
			fRec73[0] = fRec77[0];
			fRec71[0] = (fRec73[0] - (fConst16 * ((fConst14 * fRec71[2]) + (fConst12 * fRec71[1]))));
			float 	fTemp194 = min(0.99f, (fConst20 * (((3947.8418f * fRec71[0]) + (7895.6836f * fRec71[1])) + (3947.8418f * fRec71[2]))));
			float 	fTemp195 = min(1.0f, (fSlow85 + (((fTemp194 < 0.1f)) ? (1.0f - (1e+01f * fTemp194)) : 0.0f)));
			float 	fTemp196 = ((iTemp49) ? 0.0f : (fSlow87 + fRec83[1]));
			fRec83[0] = (fTemp196 - floorf(fTemp196));
			float 	fTemp197 = (499.0f * fRec83[0]);
			int 	iTemp198 = int(fTemp197);
			int 	iTemp199 = max(0, min(iTemp198, 499));
			float 	fTemp200 = ftbl2[iTemp199];
			int 	iTemp201 = max(0, min((iTemp198 + 1), 499));
			float 	fTemp202 = (fTemp197 - float(iTemp198));
			float 	fTemp203 = float((((fVec17[1] <= 0.003f) & iTemp172) != 1));
			fRec84[0] = max((fTemp203 * fRec84[1]), fSlow88);
			fRec85[0] = max((fRec85[1] * fTemp203), fSlow69);
			float 	fTemp204 = max(min(((0.5f * (fVec17[0] - fTemp194)) + (0.2f - (0.8f * ((iTemp173) ? (2.0f * (((fRec85[0] > fRec84[0])) ? fRec85[0] : (0.0f - fRec84[0]))) : fSlow70)))), 1.0f), 0.0f);
			float 	fTemp205 = ftbl3[iTemp199];
			float 	fTemp206 = (((fTemp205 + (fTemp202 * (ftbl3[iTemp201] - fTemp205))) * (1.0f - fTemp204)) + (fTemp204 * (fTemp200 + (fTemp202 * (ftbl2[iTemp201] - fTemp200)))));
			float 	fTemp207 = (fRec82[1] - fConst22);
			float 	fTemp208 = (fConst22 + fRec82[1]);
			fRec82[0] = (((fTemp208 < fTemp206)) ? fTemp208 : (((fTemp207 > fTemp206)) ? fTemp207 : fTemp206));
			float 	fTemp209 = ((iTemp49) ? 0.0f : (fSlow89 + fRec86[1]));
			fRec86[0] = (fTemp209 - floorf(fTemp209));
			float 	fTemp210 = (499.0f * fRec86[0]);
			int 	iTemp211 = int(fTemp210);
			float 	fTemp212 = ftbl3[max(0, min(iTemp211, 499))];
			float 	fTemp213 = ((iTemp49) ? 0.0f : (fSlow90 + fRec87[1]));
			fRec87[0] = (fTemp213 - floorf(fTemp213));
			float 	fTemp214 = (499.0f * fRec87[0]);
			int 	iTemp215 = int(fTemp214);
			float 	fTemp216 = ftbl2[max(0, min(iTemp215, 499))];
			fRec88[0] = (fTemp19 - (fSlow101 * ((fSlow99 * fRec88[2]) + (fSlow97 * fRec88[1]))));
			fVec19[0] = fSlow103;
			int 	iTemp217 = (fSlow105 != (0.9f * fVec19[1]));
			iVec20[0] = iTemp217;
			int 	iTemp218 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec92[0] = ((iRec92[1] * (1 - iTemp218)) + (iTemp22 * iTemp218));
			float 	fTemp219 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec92[0])))) > 0.5f) & iSlow104)) ? 0.0f : fSlow102) + 1.0f)) + 0.5f))];
			fVec21[0] = fTemp219;
			int 	iTemp220 = (fVec21[0] > 0.003f);
			int 	iTemp221 = (fVec21[0] <= 0.003f);
			float 	fTemp222 = float((iTemp221 | (fVec21[1] >= 0.003f)));
			fRec93[0] = max((fRec93[1] * fTemp222), fSlow105);
			fRec94[0] = max((fTemp222 * fRec94[1]), fSlow106);
			float 	fTemp223 = (min(1.0f, fRec94[0]) + min(1.0f, fRec93[0]));
			int 	iTemp224 = (fVec21[0] >= fRec91[1]);
			int 	iTemp225 = (fRec91[1] <= 0.001f);
			int 	iTemp226 = (((iRec90[1] >= 4)) ? (((iRec90[1] >= 6)) ? ((iTemp225) ? 0 : ((iTemp220) ? 1 : 6)) : (((iRec90[1] >= 5)) ? ((iTemp221) ? 3 : ((iTemp224) ? 4 : 5)) : ((iTemp221) ? 3 : (((fVec21[0] <= fRec91[1])) ? 5 : 4)))) : (((iRec90[1] >= 2)) ? (((iRec90[1] >= 3)) ? (((iTemp221 & iTemp225)) ? 0 : ((iTemp220) ? 1 : 3)) : ((iTemp221) ? 6 : ((iTemp224) ? 4 : 2))) : (((iRec90[1] >= 1)) ? (((fRec91[1] >= min(fTemp223, 1.0f))) ? ((iTemp221) ? 6 : 2) : 1) : ((iTemp220) ? 1 : 0))));
			iRec90[0] = iTemp226;
			float 	fTemp227 = (((iTemp226 >= 4)) ? (((iTemp226 >= 6)) ? fConst0 : fConst19) : (((iTemp226 >= 2)) ? (((iTemp226 >= 3)) ? fConst5 : fConst18) : (((iTemp226 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp228 = (iRec90[1] != iRec90[2]);
			iVec22[0] = iTemp228;
			int 	iTemp229 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp229)) + (iTemp22 * iTemp229));
			float 	fTemp230 = (2e+01f * (((fTemp227 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec96[0]))) / fTemp227) : 0.0f));
			int 	iTemp231 = int(fTemp230);
			float 	fTemp232 = ftbl1[max(0, int(min(int(iTemp231), 20)))];
			float 	fTemp233 = (fTemp232 + ((fTemp230 - float(iTemp231)) * (ftbl1[max(0, int(min(int((iTemp231 + 1)), 20)))] - fTemp232)));
			iRec97[0] = iRec90[1];
			int 	iTemp234 = (iRec97[1] == iRec90[1]);
			int 	iTemp235 = (iRec90[1] == 0);
			fRec98[0] = ((iTemp235) ? fVec21[0] : ((iTemp234) ? min(min(fRec98[1], fVec21[0]), fRec91[1]) : min(fVec21[0], fRec91[1])));
			fRec99[0] = ((iTemp235) ? fVec21[0] : ((iTemp234) ? max(max(fRec99[1], fVec21[0]), fRec91[1]) : max(fVec21[0], fRec91[1])));
			int 	iTemp236 = (iRec90[1] == 3);
			int 	iTemp237 = (iRec90[1] == 6);
			float 	fTemp238 = (((iRec90[1] == 1)) ? min(1.0f, fTemp223) : ((iTemp235) ? 0.0f : ((iTemp237) ? (fTemp223 * fTemp233) : ((iTemp236) ? (fRec99[0] * fTemp233) : fVec21[0]))));
			float 	fTemp239 = (1.0f / ((iTemp235) ? 0.0001f : (((iTemp236 | iTemp237)) ? (0.04761905f * fTemp227) : fTemp227)));
			float 	fTemp240 = (fRec95[1] - fTemp239);
			float 	fTemp241 = (fRec95[1] + fTemp239);
			fRec95[0] = (((fTemp241 < fTemp238)) ? fTemp241 : (((fTemp240 > fTemp238)) ? fTemp240 : fTemp238));
			fRec91[0] = fRec95[0];
			fRec89[0] = (fRec91[0] - (fConst16 * ((fConst14 * fRec89[2]) + (fConst12 * fRec89[1]))));
			float 	fTemp242 = min(0.99f, (fConst20 * (((3947.8418f * fRec89[0]) + (7895.6836f * fRec89[1])) + (3947.8418f * fRec89[2]))));
			float 	fTemp243 = min(1.0f, (fSlow107 + (((fTemp242 < 0.1f)) ? (1.0f - (1e+01f * fTemp242)) : 0.0f)));
			float 	fTemp244 = ((iTemp49) ? 0.0f : (fSlow109 + fRec101[1]));
			fRec101[0] = (fTemp244 - floorf(fTemp244));
			float 	fTemp245 = (499.0f * fRec101[0]);
			int 	iTemp246 = int(fTemp245);
			int 	iTemp247 = max(0, min(iTemp246, 499));
			float 	fTemp248 = ftbl2[iTemp247];
			int 	iTemp249 = max(0, min((iTemp246 + 1), 499));
			float 	fTemp250 = (fTemp245 - float(iTemp246));
			float 	fTemp251 = float((((fVec21[1] <= 0.003f) & iTemp220) != 1));
			fRec102[0] = max((fTemp251 * fRec102[1]), fSlow110);
			fRec103[0] = max((fRec103[1] * fTemp251), fSlow91);
			float 	fTemp252 = max(min(((0.5f * (fVec21[0] - fTemp242)) + (0.2f - (0.8f * ((iTemp221) ? (2.0f * (((fRec103[0] > fRec102[0])) ? fRec103[0] : (0.0f - fRec102[0]))) : fSlow92)))), 1.0f), 0.0f);
			float 	fTemp253 = ftbl3[iTemp247];
			float 	fTemp254 = (((fTemp253 + (fTemp250 * (ftbl3[iTemp249] - fTemp253))) * (1.0f - fTemp252)) + (fTemp252 * (fTemp248 + (fTemp250 * (ftbl2[iTemp249] - fTemp248)))));
			float 	fTemp255 = (fRec100[1] - fConst22);
			float 	fTemp256 = (fConst22 + fRec100[1]);
			fRec100[0] = (((fTemp256 < fTemp254)) ? fTemp256 : (((fTemp255 > fTemp254)) ? fTemp255 : fTemp254));
			float 	fTemp257 = ((iTemp49) ? 0.0f : (fSlow111 + fRec104[1]));
			fRec104[0] = (fTemp257 - floorf(fTemp257));
			float 	fTemp258 = (499.0f * fRec104[0]);
			int 	iTemp259 = int(fTemp258);
			float 	fTemp260 = ftbl3[max(0, min(iTemp259, 499))];
			float 	fTemp261 = ((iTemp49) ? 0.0f : (fSlow112 + fRec105[1]));
			fRec105[0] = (fTemp261 - floorf(fTemp261));
			float 	fTemp262 = (499.0f * fRec105[0]);
			int 	iTemp263 = int(fTemp262);
			float 	fTemp264 = ftbl2[max(0, min(iTemp263, 499))];
			fRec106[0] = (fTemp19 - (fSlow123 * ((fSlow121 * fRec106[2]) + (fSlow119 * fRec106[1]))));
			fVec23[0] = fSlow125;
			int 	iTemp265 = (fSlow127 != (0.9f * fVec23[1]));
			iVec24[0] = iTemp265;
			int 	iTemp266 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec110[0] = ((iRec110[1] * (1 - iTemp266)) + (iTemp22 * iTemp266));
			float 	fTemp267 = ftbl0[int(((499.5f * ((((((fConst7 * float((iRec17[0] + (-1 - iRec110[0])))) > 0.5f) & iSlow126)) ? 0.0f : fSlow124) + 1.0f)) + 0.5f))];
			fVec25[0] = fTemp267;
			int 	iTemp268 = (fVec25[0] > 0.003f);
			int 	iTemp269 = (fVec25[0] <= 0.003f);
			float 	fTemp270 = float((iTemp269 | (fVec25[1] >= 0.003f)));
			fRec111[0] = max((fRec111[1] * fTemp270), fSlow127);
			fRec112[0] = max((fTemp270 * fRec112[1]), fSlow128);
			float 	fTemp271 = (min(1.0f, fRec112[0]) + min(1.0f, fRec111[0]));
			int 	iTemp272 = (fVec25[0] >= fRec109[1]);
			int 	iTemp273 = (fRec109[1] <= 0.001f);
			int 	iTemp274 = (((iRec108[1] >= 4)) ? (((iRec108[1] >= 6)) ? ((iTemp273) ? 0 : ((iTemp268) ? 1 : 6)) : (((iRec108[1] >= 5)) ? ((iTemp269) ? 3 : ((iTemp272) ? 4 : 5)) : ((iTemp269) ? 3 : (((fVec25[0] <= fRec109[1])) ? 5 : 4)))) : (((iRec108[1] >= 2)) ? (((iRec108[1] >= 3)) ? (((iTemp269 & iTemp273)) ? 0 : ((iTemp268) ? 1 : 3)) : ((iTemp269) ? 6 : ((iTemp272) ? 4 : 2))) : (((iRec108[1] >= 1)) ? (((fRec109[1] >= min(fTemp271, 1.0f))) ? ((iTemp269) ? 6 : 2) : 1) : ((iTemp268) ? 1 : 0))));
			iRec108[0] = iTemp274;
			float 	fTemp275 = (((iTemp274 >= 4)) ? (((iTemp274 >= 6)) ? fConst0 : fConst19) : (((iTemp274 >= 2)) ? (((iTemp274 >= 3)) ? fConst5 : fConst18) : (((iTemp274 >= 1)) ? fConst17 : 0.0f)));
			int 	iTemp276 = (iRec108[1] != iRec108[2]);
			iVec26[0] = iTemp276;
			int 	iTemp277 = ((iVec26[1] <= 0) & (iVec26[0] > 0));
			iRec114[0] = ((iRec114[1] * (1 - iTemp277)) + (iTemp22 * iTemp277));
			float 	fTemp278 = (2e+01f * (((fTemp275 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec114[0]))) / fTemp275) : 0.0f));
			int 	iTemp279 = int(fTemp278);
			float 	fTemp280 = ftbl1[max(0, int(min(int(iTemp279), 20)))];
			float 	fTemp281 = (fTemp280 + ((fTemp278 - float(iTemp279)) * (ftbl1[max(0, int(min(int((iTemp279 + 1)), 20)))] - fTemp280)));
			iRec115[0] = iRec108[1];
			int 	iTemp282 = (iRec115[1] == iRec108[1]);
			int 	iTemp283 = (iRec108[1] == 0);
			fRec116[0] = ((iTemp283) ? fVec25[0] : ((iTemp282) ? min(min(fRec116[1], fVec25[0]), fRec109[1]) : min(fVec25[0], fRec109[1])));
			fRec117[0] = ((iTemp283) ? fVec25[0] : ((iTemp282) ? max(max(fRec117[1], fVec25[0]), fRec109[1]) : max(fVec25[0], fRec109[1])));
			int 	iTemp284 = (iRec108[1] == 3);
			int 	iTemp285 = (iRec108[1] == 6);
			float 	fTemp286 = (((iRec108[1] == 1)) ? min(1.0f, fTemp271) : ((iTemp283) ? 0.0f : ((iTemp285) ? (fTemp271 * fTemp281) : ((iTemp284) ? (fRec117[0] * fTemp281) : fVec25[0]))));
			float 	fTemp287 = (1.0f / ((iTemp283) ? 0.0001f : (((iTemp284 | iTemp285)) ? (0.04761905f * fTemp275) : fTemp275)));
			float 	fTemp288 = (fRec113[1] - fTemp287);
			float 	fTemp289 = (fRec113[1] + fTemp287);
			fRec113[0] = (((fTemp289 < fTemp286)) ? fTemp289 : (((fTemp288 > fTemp286)) ? fTemp288 : fTemp286));
			fRec109[0] = fRec113[0];
			fRec107[0] = (fRec109[0] - (fConst16 * ((fConst14 * fRec107[2]) + (fConst12 * fRec107[1]))));
			float 	fTemp290 = min(0.99f, (fConst20 * (((3947.8418f * fRec107[0]) + (7895.6836f * fRec107[1])) + (3947.8418f * fRec107[2]))));
			float 	fTemp291 = min(1.0f, (fSlow129 + (((fTemp290 < 0.1f)) ? (1.0f - (1e+01f * fTemp290)) : 0.0f)));
			float 	fTemp292 = ((iTemp49) ? 0.0f : (fSlow131 + fRec119[1]));
			fRec119[0] = (fTemp292 - floorf(fTemp292));
			float 	fTemp293 = (499.0f * fRec119[0]);
			int 	iTemp294 = int(fTemp293);
			int 	iTemp295 = max(0, min(iTemp294, 499));
			float 	fTemp296 = ftbl2[iTemp295];
			int 	iTemp297 = max(0, min((iTemp294 + 1), 499));
			float 	fTemp298 = (fTemp293 - float(iTemp294));
			float 	fTemp299 = float((((fVec25[1] <= 0.003f) & iTemp268) != 1));
			fRec120[0] = max((fTemp299 * fRec120[1]), fSlow132);
			fRec121[0] = max((fRec121[1] * fTemp299), fSlow113);
			float 	fTemp300 = max(min(((0.5f * (fVec25[0] - fTemp290)) + (0.2f - (0.8f * ((iTemp269) ? (2.0f * (((fRec121[0] > fRec120[0])) ? fRec121[0] : (0.0f - fRec120[0]))) : fSlow114)))), 1.0f), 0.0f);
			float 	fTemp301 = ftbl3[iTemp295];
			float 	fTemp302 = (((fTemp301 + (fTemp298 * (ftbl3[iTemp297] - fTemp301))) * (1.0f - fTemp300)) + (fTemp300 * (fTemp296 + (fTemp298 * (ftbl2[iTemp297] - fTemp296)))));
			float 	fTemp303 = (fRec118[1] - fConst22);
			float 	fTemp304 = (fConst22 + fRec118[1]);
			fRec118[0] = (((fTemp304 < fTemp302)) ? fTemp304 : (((fTemp303 > fTemp302)) ? fTemp303 : fTemp302));
			float 	fTemp305 = ((iTemp49) ? 0.0f : (fSlow133 + fRec122[1]));
			fRec122[0] = (fTemp305 - floorf(fTemp305));
			float 	fTemp306 = (499.0f * fRec122[0]);
			int 	iTemp307 = int(fTemp306);
			float 	fTemp308 = ftbl3[max(0, min(iTemp307, 499))];
			float 	fTemp309 = ((iTemp49) ? 0.0f : (fSlow134 + fRec123[1]));
			fRec123[0] = (fTemp309 - floorf(fTemp309));
			float 	fTemp310 = (499.0f * fRec123[0]);
			int 	iTemp311 = int(fTemp310);
			float 	fTemp312 = ftbl2[max(0, min(iTemp311, 499))];
			output0[i] = (FAUSTFLOAT)((((((((fTemp290 * ((0.5f * ((((0.2f * (fTemp312 + ((fTemp310 - float(iTemp311)) * (ftbl2[max(0, min((iTemp311 + 1), 499))] - fTemp312)))) + (0.8f * (fTemp308 + ((fTemp306 - float(iTemp307)) * (ftbl3[max(0, min((iTemp307 + 1), 499))] - fTemp308))))) * fSlow117) * fSlow115)) + (((fRec118[0] * (1.0f - fTemp291)) + (fSlow130 * (fTemp291 * (fRec106[0] - fRec106[2])))) * fSlow118))) + (fTemp242 * ((0.5f * ((((0.2f * (fTemp264 + ((fTemp262 - float(iTemp263)) * (ftbl2[max(0, min((iTemp263 + 1), 499))] - fTemp264)))) + (0.8f * (fTemp260 + ((fTemp258 - float(iTemp259)) * (ftbl3[max(0, min((iTemp259 + 1), 499))] - fTemp260))))) * fSlow95) * fSlow93)) + (((fRec100[0] * (1.0f - fTemp243)) + (fSlow108 * (fTemp243 * (fRec88[0] - fRec88[2])))) * fSlow96)))) + (fTemp194 * ((0.5f * ((((0.2f * (fTemp216 + ((fTemp214 - float(iTemp215)) * (ftbl2[max(0, min((iTemp215 + 1), 499))] - fTemp216)))) + (0.8f * (fTemp212 + ((fTemp210 - float(iTemp211)) * (ftbl3[max(0, min((iTemp211 + 1), 499))] - fTemp212))))) * fSlow73) * fSlow71)) + (((fRec82[0] * (1.0f - fTemp195)) + (fSlow86 * (fTemp195 * (fRec70[0] - fRec70[2])))) * fSlow74)))) + (fTemp146 * ((0.5f * ((((0.2f * (fTemp168 + ((fTemp166 - float(iTemp167)) * (ftbl2[max(0, min((iTemp167 + 1), 499))] - fTemp168)))) + (0.8f * (fTemp164 + ((fTemp162 - float(iTemp163)) * (ftbl3[max(0, min((iTemp163 + 1), 499))] - fTemp164))))) * fSlow51) * fSlow49)) + (((fRec64[0] * (1.0f - fTemp147)) + (fSlow64 * (fTemp147 * (fRec52[0] - fRec52[2])))) * fSlow52)))) + (fTemp98 * ((0.5f * ((((0.2f * (fTemp120 + ((fTemp118 - float(iTemp119)) * (ftbl2[max(0, min((iTemp119 + 1), 499))] - fTemp120)))) + (0.8f * (fTemp116 + ((fTemp114 - float(iTemp115)) * (ftbl3[max(0, min((iTemp115 + 1), 499))] - fTemp116))))) * fSlow29) * fSlow27)) + (((fRec46[0] * (1.0f - fTemp99)) + (fSlow42 * (fTemp99 * (fRec34[0] - fRec34[2])))) * fSlow30)))) + (fTemp47 * ((0.5f * ((((0.2f * (fTemp72 + ((fTemp70 - float(iTemp71)) * (ftbl2[max(0, min((iTemp71 + 1), 499))] - fTemp72)))) + (0.8f * (fTemp68 + ((fTemp66 - float(iTemp67)) * (ftbl3[max(0, min((iTemp67 + 1), 499))] - fTemp68))))) * fSlow7) * fSlow5)) + (((fRec26[0] * (1.0f - fTemp48)) + (fSlow20 * (fTemp48 * (fRec12[0] - fRec12[2])))) * fSlow8)))) + (1.6129032e-06f * ((((fRec8[0] * fRec0[0]) * (fRec4[0] - fRec4[2])) * max(0.0f, min((fConst4 * fTemp8), ((fConst6 * (fConst3 - fTemp8)) + 1.0f)))) / fTemp5))));
			// post processing
			fRec123[1] = fRec123[0];
			fRec122[1] = fRec122[0];
			fRec118[1] = fRec118[0];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			fRec107[2] = fRec107[1]; fRec107[1] = fRec107[0];
			fRec109[1] = fRec109[0];
			fRec113[1] = fRec113[0];
			fRec117[1] = fRec117[0];
			fRec116[1] = fRec116[0];
			iRec115[1] = iRec115[0];
			iRec114[1] = iRec114[0];
			iVec26[1] = iVec26[0];
			iRec108[2] = iRec108[1]; iRec108[1] = iRec108[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fVec25[1] = fVec25[0];
			iRec110[1] = iRec110[0];
			iVec24[1] = iVec24[0];
			fVec23[1] = fVec23[0];
			fRec106[2] = fRec106[1]; fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec100[1] = fRec100[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec89[2] = fRec89[1]; fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			fRec95[1] = fRec95[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			iRec97[1] = iRec97[0];
			iRec96[1] = iRec96[0];
			iVec22[1] = iVec22[0];
			iRec90[2] = iRec90[1]; iRec90[1] = iRec90[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fVec21[1] = fVec21[0];
			iRec92[1] = iRec92[0];
			iVec20[1] = iVec20[0];
			fVec19[1] = fVec19[0];
			fRec88[2] = fRec88[1]; fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec82[1] = fRec82[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec71[2] = fRec71[1]; fRec71[1] = fRec71[0];
			fRec73[1] = fRec73[0];
			fRec77[1] = fRec77[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			iRec79[1] = iRec79[0];
			iRec78[1] = iRec78[0];
			iVec18[1] = iVec18[0];
			iRec72[2] = iRec72[1]; iRec72[1] = iRec72[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			fVec17[1] = fVec17[0];
			iRec74[1] = iRec74[0];
			iVec16[1] = iVec16[0];
			fVec15[1] = fVec15[0];
			fRec70[2] = fRec70[1]; fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec64[1] = fRec64[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec55[1] = fRec55[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			iRec61[1] = iRec61[0];
			iRec60[1] = iRec60[0];
			iVec14[1] = iVec14[0];
			iRec54[2] = iRec54[1]; iRec54[1] = iRec54[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fVec13[1] = fVec13[0];
			iRec56[1] = iRec56[0];
			iVec12[1] = iVec12[0];
			fVec11[1] = fVec11[0];
			fRec52[2] = fRec52[1]; fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec46[1] = fRec46[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec41[1] = fRec41[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			iRec43[1] = iRec43[0];
			iRec42[1] = iRec42[0];
			iVec10[1] = iVec10[0];
			iRec36[2] = iRec36[1]; iRec36[1] = iRec36[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fVec9[1] = fVec9[0];
			iRec38[1] = iRec38[0];
			iVec8[1] = iVec8[0];
			fVec7[1] = fVec7[0];
			fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec26[1] = fRec26[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[1] = fRec28[0];
			fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			iRec23[1] = iRec23[0];
			iRec22[1] = iRec22[0];
			iVec6[1] = iVec6[0];
			iRec14[2] = iRec14[1]; iRec14[1] = iRec14[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fVec5[1] = fVec5[0];
			iRec16[1] = iRec16[0];
			iRec17[1] = iRec17[0];
			iVec4[1] = iVec4[0];
			fVec3[1] = fVec3[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			iRec9[1] = iRec9[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			iRec5[1] = iRec5[0];
			iRec3[1] = iRec3[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			iRec1[1] = iRec1[0];
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
