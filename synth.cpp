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
				output[i] = fmodf((0.004008016f * float((iRec2[0] + -1))),1.0f);
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
				output[i] = ((0.004008016f * float((iRec4[0] + -1))) + -1.0f);
				// post processing
				iRec4[1] = iRec4[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec16[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec16[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec16[0] = (iRec16[1] + 1);
				output[i] = (0.5f * (0.0f - (cosf((0.006295777f * float((iRec16[0] + -1)))) + -1.0f)));
				// post processing
				iRec16[1] = iRec16[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[500];
	static float 	ftbl1[500];
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec3[2];
	static float 	ftbl2[500];
	float 	fConst10;
	float 	fRec5[2];
	float 	fRec7[2];
	float 	fRec9[2];
	float 	fRec11[2];
	FAUSTFLOAT 	fslider1;
	float 	fConst14;
	float 	fConst16;
	float 	fConst18;
	static float 	ftbl3[500];
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec18[2];
	int 	iRec17[2];
	float 	fVec3[2];
	float 	fRec19[2];
	int 	iRec14[3];
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fRec21[2];
	int 	iVec4[2];
	int 	iRec22[2];
	int 	iRec23[2];
	float 	fRec24[2];
	float 	fRec25[2];
	FAUSTFLOAT 	fbargraph0;
	float 	fRec20[2];
	float 	fRec15[2];
	float 	fRec13[3];
	float 	fConst24;
	FAUSTFLOAT 	fslider4;
	float 	fRec26[2];
	float 	fRec27[2];
	float 	fRec29[2];
	float 	fRec31[2];
	float 	fRec33[2];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec5[2];
	int 	iVec6[2];
	int 	iRec38[2];
	float 	fVec7[2];
	float 	fRec39[2];
	int 	iRec36[3];
	float 	fRec41[2];
	int 	iVec8[2];
	int 	iRec42[2];
	int 	iRec43[2];
	float 	fRec44[2];
	float 	fRec45[2];
	FAUSTFLOAT 	fbargraph1;
	float 	fRec40[2];
	float 	fRec37[2];
	float 	fRec35[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec46[2];
	float 	fRec47[2];
	float 	fRec49[2];
	float 	fRec51[2];
	float 	fRec53[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec58[2];
	float 	fVec11[2];
	float 	fRec59[2];
	int 	iRec56[3];
	float 	fRec61[2];
	int 	iVec12[2];
	int 	iRec62[2];
	int 	iRec63[2];
	float 	fRec64[2];
	float 	fRec65[2];
	FAUSTFLOAT 	fbargraph2;
	float 	fRec60[2];
	float 	fRec57[2];
	float 	fRec55[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec66[2];
	float 	fRec67[2];
	float 	fRec69[2];
	float 	fRec71[2];
	float 	fRec73[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec78[2];
	float 	fVec15[2];
	float 	fRec79[2];
	int 	iRec76[3];
	float 	fRec81[2];
	int 	iVec16[2];
	int 	iRec82[2];
	int 	iRec83[2];
	float 	fRec84[2];
	float 	fRec85[2];
	FAUSTFLOAT 	fbargraph3;
	float 	fRec80[2];
	float 	fRec77[2];
	float 	fRec75[3];
	FAUSTFLOAT 	fslider16;
	float 	fRec86[2];
	float 	fRec87[2];
	float 	fRec89[2];
	float 	fRec91[2];
	float 	fRec93[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec98[2];
	float 	fVec19[2];
	float 	fRec99[2];
	int 	iRec96[3];
	float 	fRec101[2];
	int 	iVec20[2];
	int 	iRec102[2];
	int 	iRec103[2];
	float 	fRec104[2];
	float 	fRec105[2];
	FAUSTFLOAT 	fbargraph4;
	float 	fRec100[2];
	float 	fRec97[2];
	float 	fRec95[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec106[2];
	float 	fRec107[2];
	float 	fRec109[2];
	float 	fRec111[2];
	float 	fRec113[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec118[2];
	float 	fVec23[2];
	float 	fRec119[2];
	int 	iRec116[3];
	float 	fRec121[2];
	int 	iVec24[2];
	int 	iRec122[2];
	int 	iRec123[2];
	float 	fRec124[2];
	float 	fRec125[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec120[2];
	float 	fRec117[2];
	float 	fRec115[3];
	float 	fRec0[3];
	float 	fConst25;
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
		sig1.fill(500,ftbl1);
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
		fConst9 = (2.0439498f / fConst0);
		fConst10 = (1.0f / fConst0);
		float 	fConst11 = powf((62.831852f / fConst0),2.0f);
		float 	fConst12 = ((fConst11 * ((0.2033f * fConst11) + 0.31755f)) + 1.0f);
		float 	fConst13 = powf(fConst12,2.0f);
		fConst14 = (2.0f * ((3947.8418f * (fConst13 / fConst1)) + -1.0f));
		float 	fConst15 = (3947.8418f * (fConst12 / fConst0));
		fConst16 = (((fConst12 * (fConst15 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst17 = (((fConst12 * (fConst15 + 88.49557f)) / fConst0) + 1.0f);
		fConst18 = (1.0f / fConst17);
		fConst19 = (0.3f * fConst0);
		fConst20 = (1.4f * fConst0);
		fConst21 = (0.15f * fConst0);
		fConst22 = (0.2f * fConst0);
		fConst23 = (2.5f * fConst0);
		fConst24 = (fConst13 / (fConst1 * fConst17));
		fConst25 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<3; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<3; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<3; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<3; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<3; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec82[i] = 0;
		for (int i=0; i<2; i++) iRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<3; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec98[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<3; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec102[i] = 0;
		for (int i=0; i<2; i++) iRec103[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<3; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec118[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<3; i++) iRec116[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec122[i] = 0;
		for (int i=0; i<2; i++) iRec123[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<3; i++) fRec115[i] = 0;
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
		float 	fSlow2 = max(1.1920929e-07f, fabsf((7.975231f * fSlow0)));
		float 	fSlow3 = (fConst10 * fSlow2);
		float 	fSlow4 = (1.0f - (fConst0 / fSlow2));
		float 	fSlow5 = max(1.1920929e-07f, fabsf((8.381411f * fSlow0)));
		float 	fSlow6 = (fConst10 * fSlow5);
		float 	fSlow7 = (1.0f - (fConst0 / fSlow5));
		float 	fSlow8 = max(1.1920929e-07f, fabsf((8.067899f * fSlow0)));
		float 	fSlow9 = (fConst10 * fSlow8);
		float 	fSlow10 = (1.0f - (fConst0 / fSlow8));
		float 	fSlow11 = max(1.1920929e-07f, fabsf((8.285142f * fSlow0)));
		float 	fSlow12 = (fConst10 * fSlow11);
		float 	fSlow13 = (1.0f - (fConst0 / fSlow11));
		float 	fSlow14 = (0.5f * float(fslider1));
		float 	fSlow15 = float(fslider2);
		float 	fSlow16 = float(fslider3);
		int 	iSlow17 = (fSlow16 == 0.0f);
		float 	fSlow18 = (0.0f - fSlow16);
		float 	fSlow19 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow20 = (fConst9 * fSlow19);
		float 	fSlow21 = max(1.1920929e-07f, fabsf((7.975231f * fSlow19)));
		float 	fSlow22 = (fConst10 * fSlow21);
		float 	fSlow23 = (1.0f - (fConst0 / fSlow21));
		float 	fSlow24 = max(1.1920929e-07f, fabsf((8.381411f * fSlow19)));
		float 	fSlow25 = (fConst10 * fSlow24);
		float 	fSlow26 = (1.0f - (fConst0 / fSlow24));
		float 	fSlow27 = max(1.1920929e-07f, fabsf((8.067899f * fSlow19)));
		float 	fSlow28 = (fConst10 * fSlow27);
		float 	fSlow29 = (1.0f - (fConst0 / fSlow27));
		float 	fSlow30 = max(1.1920929e-07f, fabsf((8.285142f * fSlow19)));
		float 	fSlow31 = (fConst10 * fSlow30);
		float 	fSlow32 = (1.0f - (fConst0 / fSlow30));
		float 	fSlow33 = (0.5f * float(fslider5));
		float 	fSlow34 = float(fslider6);
		float 	fSlow35 = float(fslider7);
		int 	iSlow36 = (fSlow35 == 0.0f);
		float 	fSlow37 = (0.0f - fSlow35);
		float 	fSlow38 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow39 = (fConst9 * fSlow38);
		float 	fSlow40 = max(1.1920929e-07f, fabsf((7.975231f * fSlow38)));
		float 	fSlow41 = (fConst10 * fSlow40);
		float 	fSlow42 = (1.0f - (fConst0 / fSlow40));
		float 	fSlow43 = max(1.1920929e-07f, fabsf((8.381411f * fSlow38)));
		float 	fSlow44 = (fConst10 * fSlow43);
		float 	fSlow45 = (1.0f - (fConst0 / fSlow43));
		float 	fSlow46 = max(1.1920929e-07f, fabsf((8.067899f * fSlow38)));
		float 	fSlow47 = (fConst10 * fSlow46);
		float 	fSlow48 = (1.0f - (fConst0 / fSlow46));
		float 	fSlow49 = max(1.1920929e-07f, fabsf((8.285142f * fSlow38)));
		float 	fSlow50 = (fConst10 * fSlow49);
		float 	fSlow51 = (1.0f - (fConst0 / fSlow49));
		float 	fSlow52 = (0.5f * float(fslider9));
		float 	fSlow53 = float(fslider10);
		float 	fSlow54 = float(fslider11);
		int 	iSlow55 = (fSlow54 == 0.0f);
		float 	fSlow56 = (0.0f - fSlow54);
		float 	fSlow57 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow58 = (fConst9 * fSlow57);
		float 	fSlow59 = max(1.1920929e-07f, fabsf((7.975231f * fSlow57)));
		float 	fSlow60 = (fConst10 * fSlow59);
		float 	fSlow61 = (1.0f - (fConst0 / fSlow59));
		float 	fSlow62 = max(1.1920929e-07f, fabsf((8.381411f * fSlow57)));
		float 	fSlow63 = (fConst10 * fSlow62);
		float 	fSlow64 = (1.0f - (fConst0 / fSlow62));
		float 	fSlow65 = max(1.1920929e-07f, fabsf((8.067899f * fSlow57)));
		float 	fSlow66 = (fConst10 * fSlow65);
		float 	fSlow67 = (1.0f - (fConst0 / fSlow65));
		float 	fSlow68 = max(1.1920929e-07f, fabsf((8.285142f * fSlow57)));
		float 	fSlow69 = (fConst10 * fSlow68);
		float 	fSlow70 = (1.0f - (fConst0 / fSlow68));
		float 	fSlow71 = (0.5f * float(fslider13));
		float 	fSlow72 = float(fslider14);
		float 	fSlow73 = float(fslider15);
		int 	iSlow74 = (fSlow73 == 0.0f);
		float 	fSlow75 = (0.0f - fSlow73);
		float 	fSlow76 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow77 = (fConst9 * fSlow76);
		float 	fSlow78 = max(1.1920929e-07f, fabsf((7.975231f * fSlow76)));
		float 	fSlow79 = (fConst10 * fSlow78);
		float 	fSlow80 = (1.0f - (fConst0 / fSlow78));
		float 	fSlow81 = max(1.1920929e-07f, fabsf((8.381411f * fSlow76)));
		float 	fSlow82 = (fConst10 * fSlow81);
		float 	fSlow83 = (1.0f - (fConst0 / fSlow81));
		float 	fSlow84 = max(1.1920929e-07f, fabsf((8.067899f * fSlow76)));
		float 	fSlow85 = (fConst10 * fSlow84);
		float 	fSlow86 = (1.0f - (fConst0 / fSlow84));
		float 	fSlow87 = max(1.1920929e-07f, fabsf((8.285142f * fSlow76)));
		float 	fSlow88 = (fConst10 * fSlow87);
		float 	fSlow89 = (1.0f - (fConst0 / fSlow87));
		float 	fSlow90 = (0.5f * float(fslider17));
		float 	fSlow91 = float(fslider18);
		float 	fSlow92 = float(fslider19);
		int 	iSlow93 = (fSlow92 == 0.0f);
		float 	fSlow94 = (0.0f - fSlow92);
		float 	fSlow95 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow96 = (fConst9 * fSlow95);
		float 	fSlow97 = max(1.1920929e-07f, fabsf((7.975231f * fSlow95)));
		float 	fSlow98 = (fConst10 * fSlow97);
		float 	fSlow99 = (1.0f - (fConst0 / fSlow97));
		float 	fSlow100 = max(1.1920929e-07f, fabsf((8.381411f * fSlow95)));
		float 	fSlow101 = (fConst10 * fSlow100);
		float 	fSlow102 = (1.0f - (fConst0 / fSlow100));
		float 	fSlow103 = max(1.1920929e-07f, fabsf((8.067899f * fSlow95)));
		float 	fSlow104 = (fConst10 * fSlow103);
		float 	fSlow105 = (1.0f - (fConst0 / fSlow103));
		float 	fSlow106 = max(1.1920929e-07f, fabsf((8.285142f * fSlow95)));
		float 	fSlow107 = (fConst10 * fSlow106);
		float 	fSlow108 = (1.0f - (fConst0 / fSlow106));
		float 	fSlow109 = (0.5f * float(fslider21));
		float 	fSlow110 = float(fslider22);
		float 	fSlow111 = float(fslider23);
		int 	iSlow112 = (fSlow111 == 0.0f);
		float 	fSlow113 = (0.0f - fSlow111);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp2 = (1 - iVec0[1]);
			float 	fTemp3 = ((iTemp2) ? 0.0f : (fSlow1 + fRec3[1]));
			fRec3[0] = (fTemp3 - floorf(fTemp3));
			int 	iTemp4 = max(0, min(int(((499.0f * fRec3[0]) + 0.5f)), 499));
			int 	iTemp5 = max(0, min(int(((499.0f * ftbl1[iTemp4]) + 0.5f)), 499));
			float 	fTemp6 = (fSlow3 + (fRec5[1] + -1.0f));
			float 	fTemp7 = (fSlow3 + fRec5[1]);
			int 	iTemp8 = (fTemp6 < 0.0f);
			fRec5[0] = ((iTemp8) ? fTemp7 : fTemp6);
			float 	fRec6 = ((iTemp8) ? fTemp7 : (fSlow3 + (fRec5[1] + (fSlow4 * fTemp6))));
			float 	fTemp9 = (fSlow6 + (fRec7[1] + -1.0f));
			float 	fTemp10 = (fSlow6 + fRec7[1]);
			int 	iTemp11 = (fTemp9 < 0.0f);
			fRec7[0] = ((iTemp11) ? fTemp10 : fTemp9);
			float 	fRec8 = ((iTemp11) ? fTemp10 : (fSlow6 + (fRec7[1] + (fSlow7 * fTemp9))));
			float 	fTemp12 = (fSlow9 + (fRec9[1] + -1.0f));
			float 	fTemp13 = (fSlow9 + fRec9[1]);
			int 	iTemp14 = (fTemp12 < 0.0f);
			fRec9[0] = ((iTemp14) ? fTemp13 : fTemp12);
			float 	fRec10 = ((iTemp14) ? fTemp13 : (fSlow9 + (fRec9[1] + (fSlow10 * fTemp12))));
			float 	fTemp15 = (fSlow12 + (fRec11[1] + -1.0f));
			float 	fTemp16 = (fSlow12 + fRec11[1]);
			int 	iTemp17 = (fTemp15 < 0.0f);
			fRec11[0] = ((iTemp17) ? fTemp16 : fTemp15);
			float 	fRec12 = ((iTemp17) ? fTemp16 : (fSlow12 + (fRec11[1] + (fSlow13 * fTemp15))));
			fVec1[0] = fSlow16;
			int 	iTemp18 = (fSlow16 != fVec1[1]);
			iVec2[0] = iTemp18;
			int 	iTemp19 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec18[0] = (iRec18[1] + 1);
			int 	iTemp20 = (iRec18[0] + -1);
			iRec17[0] = ((iRec17[1] * (1 - iTemp19)) + (iTemp20 * iTemp19));
			float 	fTemp21 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec17[0])))) > 0.5f) & iSlow17)) ? 0.0f : fSlow15)) + 0.5f))];
			fVec3[0] = fTemp21;
			int 	iTemp22 = (fVec3[0] > 0.001f);
			int 	iTemp23 = (fVec3[0] <= 0.001f);
			float 	fTemp24 = float((iTemp23 | (fVec3[1] >= 0.001f)));
			fRec19[0] = max((fRec19[1] * fTemp24), fSlow16);
			float 	fTemp25 = min(1.0f, fRec19[0]);
			int 	iTemp26 = (fVec3[0] >= fRec15[1]);
			int 	iTemp27 = (fRec15[1] <= 0.001f);
			int 	iTemp28 = (((iRec14[1] >= 4)) ? (((iRec14[1] >= 6)) ? ((iTemp27) ? 0 : ((iTemp22) ? 1 : 6)) : (((iRec14[1] >= 5)) ? ((iTemp23) ? 3 : ((iTemp26) ? 4 : 5)) : ((iTemp23) ? 3 : (((fVec3[0] <= fRec15[1])) ? 5 : 4)))) : (((iRec14[1] >= 2)) ? (((iRec14[1] >= 3)) ? (((iTemp23 & iTemp27)) ? 0 : ((iTemp22) ? 1 : 3)) : ((iTemp23) ? 3 : ((iTemp26) ? ((iTemp23) ? 6 : 4) : 2))) : (((iRec14[1] >= 1)) ? (((fRec15[1] >= min(fTemp25, 1.0f))) ? ((iTemp23) ? 6 : 2) : 1) : ((iTemp22) ? 1 : 0))));
			iRec14[0] = iTemp28;
			fRec21[0] = max((fTemp24 * fRec21[1]), fSlow18);
			float 	fTemp29 = (((iTemp28 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec21[0]))) : (((iTemp28 >= 4)) ? (((iTemp28 >= 6)) ? fConst23 : fConst22) : (((iTemp28 >= 2)) ? (((iTemp28 >= 3)) ? fConst21 : fConst20) : (((iTemp28 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp30 = (iRec14[1] != iRec14[2]);
			iVec4[0] = iTemp30;
			int 	iTemp31 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec22[0] = ((iRec22[1] * (1 - iTemp31)) + (iTemp20 * iTemp31));
			float 	fTemp32 = min(19.0f, floorf((21.0f * (((fTemp29 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec22[0]))) / fTemp29) : 1.0f))));
			float 	fTemp33 = min((fTemp32 + 1.0f), 2e+01f);
			float 	fTemp34 = (((fTemp33 >= 11.0f)) ? (((fTemp33 >= 16.0f)) ? (((fTemp33 >= 19.0f)) ? (((fTemp33 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp33 >= 18.0f)) ? 0.03f : (((fTemp33 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp33 >= 14.0f)) ? (((fTemp33 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp33 >= 13.0f)) ? 0.14f : (((fTemp33 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp33 >= 6.0f)) ? (((fTemp33 >= 9.0f)) ? (((fTemp33 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp33 >= 8.0f)) ? 0.3f : (((fTemp33 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp33 >= 3.0f)) ? (((fTemp33 >= 5.0f)) ? 0.47f : (((fTemp33 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp33 >= 2.0f)) ? 0.74f : (((fTemp33 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec23[0] = iRec14[1];
			int 	iTemp35 = (iRec23[1] == iRec14[1]);
			int 	iTemp36 = (iRec14[1] == 0);
			fRec24[0] = ((iTemp36) ? fVec3[0] : ((iTemp35) ? min(min(fRec24[1], fVec3[0]), fRec15[1]) : min(fVec3[0], fRec15[1])));
			fRec25[0] = ((iTemp36) ? fVec3[0] : ((iTemp35) ? max(max(fRec25[1], fVec3[0]), fRec15[1]) : max(fVec3[0], fRec15[1])));
			int 	iTemp37 = ((iRec14[1] == 3) | (iRec14[1] == 6));
			fbargraph0 = float(iRec14[1]);
			float 	fTemp38 = (((fbargraph0 == 1.0f)) ? min(1.0f, fTemp25) : ((iTemp36) ? 0.0f : ((iTemp37) ? (fRec25[0] * fTemp34) : fVec3[0])));
			float 	fTemp39 = (1.0f / ((iTemp36) ? 0.0001f : ((iTemp37) ? (0.05f * (fTemp29 / ((((fTemp32 >= 11.0f)) ? (((fTemp32 >= 16.0f)) ? (((fTemp32 >= 19.0f)) ? (((fTemp32 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp32 >= 18.0f)) ? 0.03f : (((fTemp32 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp32 >= 14.0f)) ? (((fTemp32 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp32 >= 13.0f)) ? 0.14f : (((fTemp32 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp32 >= 6.0f)) ? (((fTemp32 >= 9.0f)) ? (((fTemp32 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp32 >= 8.0f)) ? 0.3f : (((fTemp32 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp32 >= 3.0f)) ? (((fTemp32 >= 5.0f)) ? 0.47f : (((fTemp32 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp32 >= 2.0f)) ? 0.74f : (((fTemp32 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp34))) : fTemp29)));
			float 	fTemp40 = (fRec20[1] - fTemp39);
			float 	fTemp41 = (fRec20[1] + fTemp39);
			fRec20[0] = (((fTemp41 < fTemp38)) ? fTemp41 : (((fTemp40 > fTemp38)) ? fTemp40 : fTemp38));
			fRec15[0] = fRec20[0];
			fRec13[0] = (fRec15[0] - (fConst18 * ((fConst16 * fRec13[2]) + (fConst14 * fRec13[1]))));
			float 	fTemp42 = min(0.99f, (fConst24 * (((3947.8418f * fRec13[0]) + (7895.6836f * fRec13[1])) + (3947.8418f * fRec13[2]))));
			float 	fTemp43 = min(0.8f, max(0.0f, ((fVec3[0] + (0.1f - fTemp42)) - fSlow14)));
			int 	iTemp44 = max(0, min(int(((499.0f * ftbl1[iTemp5]) + 0.5f)), 499));
			float 	fTemp45 = max(min((3.0f * (fVec3[0] - fTemp42)), 0.3f), -0.15f);
			float 	fTemp46 = ((iTemp2) ? 0.0f : (fSlow20 + fRec26[1]));
			fRec26[0] = (fTemp46 - floorf(fTemp46));
			int 	iTemp47 = max(0, min(int(((499.0f * fRec26[0]) + 0.5f)), 499));
			int 	iTemp48 = max(0, min(int(((499.0f * ftbl1[iTemp47]) + 0.5f)), 499));
			float 	fTemp49 = (fSlow22 + (fRec27[1] + -1.0f));
			float 	fTemp50 = (fSlow22 + fRec27[1]);
			int 	iTemp51 = (fTemp49 < 0.0f);
			fRec27[0] = ((iTemp51) ? fTemp50 : fTemp49);
			float 	fRec28 = ((iTemp51) ? fTemp50 : (fSlow22 + (fRec27[1] + (fSlow23 * fTemp49))));
			float 	fTemp52 = (fSlow25 + (fRec29[1] + -1.0f));
			float 	fTemp53 = (fSlow25 + fRec29[1]);
			int 	iTemp54 = (fTemp52 < 0.0f);
			fRec29[0] = ((iTemp54) ? fTemp53 : fTemp52);
			float 	fRec30 = ((iTemp54) ? fTemp53 : (fSlow25 + (fRec29[1] + (fSlow26 * fTemp52))));
			float 	fTemp55 = (fSlow28 + (fRec31[1] + -1.0f));
			float 	fTemp56 = (fSlow28 + fRec31[1]);
			int 	iTemp57 = (fTemp55 < 0.0f);
			fRec31[0] = ((iTemp57) ? fTemp56 : fTemp55);
			float 	fRec32 = ((iTemp57) ? fTemp56 : (fSlow28 + (fRec31[1] + (fSlow29 * fTemp55))));
			float 	fTemp58 = (fSlow31 + (fRec33[1] + -1.0f));
			float 	fTemp59 = (fSlow31 + fRec33[1]);
			int 	iTemp60 = (fTemp58 < 0.0f);
			fRec33[0] = ((iTemp60) ? fTemp59 : fTemp58);
			float 	fRec34 = ((iTemp60) ? fTemp59 : (fSlow31 + (fRec33[1] + (fSlow32 * fTemp58))));
			fVec5[0] = fSlow35;
			int 	iTemp61 = (fSlow35 != fVec5[1]);
			iVec6[0] = iTemp61;
			int 	iTemp62 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec38[0] = ((iRec38[1] * (1 - iTemp62)) + (iTemp20 * iTemp62));
			float 	fTemp63 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec38[0])))) > 0.5f) & iSlow36)) ? 0.0f : fSlow34)) + 0.5f))];
			fVec7[0] = fTemp63;
			int 	iTemp64 = (fVec7[0] > 0.001f);
			int 	iTemp65 = (fVec7[0] <= 0.001f);
			float 	fTemp66 = float((iTemp65 | (fVec7[1] >= 0.001f)));
			fRec39[0] = max((fRec39[1] * fTemp66), fSlow35);
			float 	fTemp67 = min(1.0f, fRec39[0]);
			int 	iTemp68 = (fVec7[0] >= fRec37[1]);
			int 	iTemp69 = (fRec37[1] <= 0.001f);
			int 	iTemp70 = (((iRec36[1] >= 4)) ? (((iRec36[1] >= 6)) ? ((iTemp69) ? 0 : ((iTemp64) ? 1 : 6)) : (((iRec36[1] >= 5)) ? ((iTemp65) ? 3 : ((iTemp68) ? 4 : 5)) : ((iTemp65) ? 3 : (((fVec7[0] <= fRec37[1])) ? 5 : 4)))) : (((iRec36[1] >= 2)) ? (((iRec36[1] >= 3)) ? (((iTemp65 & iTemp69)) ? 0 : ((iTemp64) ? 1 : 3)) : ((iTemp65) ? 3 : ((iTemp68) ? ((iTemp65) ? 6 : 4) : 2))) : (((iRec36[1] >= 1)) ? (((fRec37[1] >= min(fTemp67, 1.0f))) ? ((iTemp65) ? 6 : 2) : 1) : ((iTemp64) ? 1 : 0))));
			iRec36[0] = iTemp70;
			fRec41[0] = max((fTemp66 * fRec41[1]), fSlow37);
			float 	fTemp71 = (((iTemp70 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec41[0]))) : (((iTemp70 >= 4)) ? (((iTemp70 >= 6)) ? fConst23 : fConst22) : (((iTemp70 >= 2)) ? (((iTemp70 >= 3)) ? fConst21 : fConst20) : (((iTemp70 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp72 = (iRec36[1] != iRec36[2]);
			iVec8[0] = iTemp72;
			int 	iTemp73 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec42[0] = ((iRec42[1] * (1 - iTemp73)) + (iTemp20 * iTemp73));
			float 	fTemp74 = min(19.0f, floorf((21.0f * (((fTemp71 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec42[0]))) / fTemp71) : 1.0f))));
			float 	fTemp75 = min((fTemp74 + 1.0f), 2e+01f);
			float 	fTemp76 = (((fTemp75 >= 11.0f)) ? (((fTemp75 >= 16.0f)) ? (((fTemp75 >= 19.0f)) ? (((fTemp75 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp75 >= 18.0f)) ? 0.03f : (((fTemp75 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp75 >= 14.0f)) ? (((fTemp75 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp75 >= 13.0f)) ? 0.14f : (((fTemp75 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp75 >= 6.0f)) ? (((fTemp75 >= 9.0f)) ? (((fTemp75 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp75 >= 8.0f)) ? 0.3f : (((fTemp75 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp75 >= 3.0f)) ? (((fTemp75 >= 5.0f)) ? 0.47f : (((fTemp75 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp75 >= 2.0f)) ? 0.74f : (((fTemp75 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec43[0] = iRec36[1];
			int 	iTemp77 = (iRec43[1] == iRec36[1]);
			int 	iTemp78 = (iRec36[1] == 0);
			fRec44[0] = ((iTemp78) ? fVec7[0] : ((iTemp77) ? min(min(fRec44[1], fVec7[0]), fRec37[1]) : min(fVec7[0], fRec37[1])));
			fRec45[0] = ((iTemp78) ? fVec7[0] : ((iTemp77) ? max(max(fRec45[1], fVec7[0]), fRec37[1]) : max(fVec7[0], fRec37[1])));
			int 	iTemp79 = ((iRec36[1] == 3) | (iRec36[1] == 6));
			fbargraph1 = float(iRec36[1]);
			float 	fTemp80 = (((fbargraph1 == 1.0f)) ? min(1.0f, fTemp67) : ((iTemp78) ? 0.0f : ((iTemp79) ? (fRec45[0] * fTemp76) : fVec7[0])));
			float 	fTemp81 = (1.0f / ((iTemp78) ? 0.0001f : ((iTemp79) ? (0.05f * (fTemp71 / ((((fTemp74 >= 11.0f)) ? (((fTemp74 >= 16.0f)) ? (((fTemp74 >= 19.0f)) ? (((fTemp74 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp74 >= 18.0f)) ? 0.03f : (((fTemp74 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp74 >= 14.0f)) ? (((fTemp74 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp74 >= 13.0f)) ? 0.14f : (((fTemp74 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp74 >= 6.0f)) ? (((fTemp74 >= 9.0f)) ? (((fTemp74 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp74 >= 8.0f)) ? 0.3f : (((fTemp74 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp74 >= 3.0f)) ? (((fTemp74 >= 5.0f)) ? 0.47f : (((fTemp74 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp74 >= 2.0f)) ? 0.74f : (((fTemp74 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp76))) : fTemp71)));
			float 	fTemp82 = (fRec40[1] - fTemp81);
			float 	fTemp83 = (fRec40[1] + fTemp81);
			fRec40[0] = (((fTemp83 < fTemp80)) ? fTemp83 : (((fTemp82 > fTemp80)) ? fTemp82 : fTemp80));
			fRec37[0] = fRec40[0];
			fRec35[0] = (fRec37[0] - (fConst18 * ((fConst16 * fRec35[2]) + (fConst14 * fRec35[1]))));
			float 	fTemp84 = min(0.99f, (fConst24 * (((3947.8418f * fRec35[0]) + (7895.6836f * fRec35[1])) + (3947.8418f * fRec35[2]))));
			float 	fTemp85 = min(0.8f, max(0.0f, ((fVec7[0] + (0.1f - fTemp84)) - fSlow33)));
			int 	iTemp86 = max(0, min(int(((499.0f * ftbl1[iTemp48]) + 0.5f)), 499));
			float 	fTemp87 = max(min((3.0f * (fVec7[0] - fTemp84)), 0.3f), -0.15f);
			float 	fTemp88 = ((iTemp2) ? 0.0f : (fSlow39 + fRec46[1]));
			fRec46[0] = (fTemp88 - floorf(fTemp88));
			int 	iTemp89 = max(0, min(int(((499.0f * fRec46[0]) + 0.5f)), 499));
			int 	iTemp90 = max(0, min(int(((499.0f * ftbl1[iTemp89]) + 0.5f)), 499));
			float 	fTemp91 = (fSlow41 + (fRec47[1] + -1.0f));
			float 	fTemp92 = (fSlow41 + fRec47[1]);
			int 	iTemp93 = (fTemp91 < 0.0f);
			fRec47[0] = ((iTemp93) ? fTemp92 : fTemp91);
			float 	fRec48 = ((iTemp93) ? fTemp92 : (fSlow41 + (fRec47[1] + (fSlow42 * fTemp91))));
			float 	fTemp94 = (fSlow44 + (fRec49[1] + -1.0f));
			float 	fTemp95 = (fSlow44 + fRec49[1]);
			int 	iTemp96 = (fTemp94 < 0.0f);
			fRec49[0] = ((iTemp96) ? fTemp95 : fTemp94);
			float 	fRec50 = ((iTemp96) ? fTemp95 : (fSlow44 + (fRec49[1] + (fSlow45 * fTemp94))));
			float 	fTemp97 = (fSlow47 + (fRec51[1] + -1.0f));
			float 	fTemp98 = (fSlow47 + fRec51[1]);
			int 	iTemp99 = (fTemp97 < 0.0f);
			fRec51[0] = ((iTemp99) ? fTemp98 : fTemp97);
			float 	fRec52 = ((iTemp99) ? fTemp98 : (fSlow47 + (fRec51[1] + (fSlow48 * fTemp97))));
			float 	fTemp100 = (fSlow50 + (fRec53[1] + -1.0f));
			float 	fTemp101 = (fSlow50 + fRec53[1]);
			int 	iTemp102 = (fTemp100 < 0.0f);
			fRec53[0] = ((iTemp102) ? fTemp101 : fTemp100);
			float 	fRec54 = ((iTemp102) ? fTemp101 : (fSlow50 + (fRec53[1] + (fSlow51 * fTemp100))));
			fVec9[0] = fSlow54;
			int 	iTemp103 = (fSlow54 != fVec9[1]);
			iVec10[0] = iTemp103;
			int 	iTemp104 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec58[0] = ((iRec58[1] * (1 - iTemp104)) + (iTemp20 * iTemp104));
			float 	fTemp105 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec58[0])))) > 0.5f) & iSlow55)) ? 0.0f : fSlow53)) + 0.5f))];
			fVec11[0] = fTemp105;
			int 	iTemp106 = (fVec11[0] > 0.001f);
			int 	iTemp107 = (fVec11[0] <= 0.001f);
			float 	fTemp108 = float((iTemp107 | (fVec11[1] >= 0.001f)));
			fRec59[0] = max((fRec59[1] * fTemp108), fSlow54);
			float 	fTemp109 = min(1.0f, fRec59[0]);
			int 	iTemp110 = (fVec11[0] >= fRec57[1]);
			int 	iTemp111 = (fRec57[1] <= 0.001f);
			int 	iTemp112 = (((iRec56[1] >= 4)) ? (((iRec56[1] >= 6)) ? ((iTemp111) ? 0 : ((iTemp106) ? 1 : 6)) : (((iRec56[1] >= 5)) ? ((iTemp107) ? 3 : ((iTemp110) ? 4 : 5)) : ((iTemp107) ? 3 : (((fVec11[0] <= fRec57[1])) ? 5 : 4)))) : (((iRec56[1] >= 2)) ? (((iRec56[1] >= 3)) ? (((iTemp107 & iTemp111)) ? 0 : ((iTemp106) ? 1 : 3)) : ((iTemp107) ? 3 : ((iTemp110) ? ((iTemp107) ? 6 : 4) : 2))) : (((iRec56[1] >= 1)) ? (((fRec57[1] >= min(fTemp109, 1.0f))) ? ((iTemp107) ? 6 : 2) : 1) : ((iTemp106) ? 1 : 0))));
			iRec56[0] = iTemp112;
			fRec61[0] = max((fTemp108 * fRec61[1]), fSlow56);
			float 	fTemp113 = (((iTemp112 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec61[0]))) : (((iTemp112 >= 4)) ? (((iTemp112 >= 6)) ? fConst23 : fConst22) : (((iTemp112 >= 2)) ? (((iTemp112 >= 3)) ? fConst21 : fConst20) : (((iTemp112 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp114 = (iRec56[1] != iRec56[2]);
			iVec12[0] = iTemp114;
			int 	iTemp115 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec62[0] = ((iRec62[1] * (1 - iTemp115)) + (iTemp20 * iTemp115));
			float 	fTemp116 = min(19.0f, floorf((21.0f * (((fTemp113 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec62[0]))) / fTemp113) : 1.0f))));
			float 	fTemp117 = min((fTemp116 + 1.0f), 2e+01f);
			float 	fTemp118 = (((fTemp117 >= 11.0f)) ? (((fTemp117 >= 16.0f)) ? (((fTemp117 >= 19.0f)) ? (((fTemp117 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp117 >= 18.0f)) ? 0.03f : (((fTemp117 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp117 >= 14.0f)) ? (((fTemp117 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp117 >= 13.0f)) ? 0.14f : (((fTemp117 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp117 >= 6.0f)) ? (((fTemp117 >= 9.0f)) ? (((fTemp117 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp117 >= 8.0f)) ? 0.3f : (((fTemp117 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp117 >= 3.0f)) ? (((fTemp117 >= 5.0f)) ? 0.47f : (((fTemp117 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp117 >= 2.0f)) ? 0.74f : (((fTemp117 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec63[0] = iRec56[1];
			int 	iTemp119 = (iRec63[1] == iRec56[1]);
			int 	iTemp120 = (iRec56[1] == 0);
			fRec64[0] = ((iTemp120) ? fVec11[0] : ((iTemp119) ? min(min(fRec64[1], fVec11[0]), fRec57[1]) : min(fVec11[0], fRec57[1])));
			fRec65[0] = ((iTemp120) ? fVec11[0] : ((iTemp119) ? max(max(fRec65[1], fVec11[0]), fRec57[1]) : max(fVec11[0], fRec57[1])));
			int 	iTemp121 = ((iRec56[1] == 3) | (iRec56[1] == 6));
			fbargraph2 = float(iRec56[1]);
			float 	fTemp122 = (((fbargraph2 == 1.0f)) ? min(1.0f, fTemp109) : ((iTemp120) ? 0.0f : ((iTemp121) ? (fRec65[0] * fTemp118) : fVec11[0])));
			float 	fTemp123 = (1.0f / ((iTemp120) ? 0.0001f : ((iTemp121) ? (0.05f * (fTemp113 / ((((fTemp116 >= 11.0f)) ? (((fTemp116 >= 16.0f)) ? (((fTemp116 >= 19.0f)) ? (((fTemp116 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp116 >= 18.0f)) ? 0.03f : (((fTemp116 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp116 >= 14.0f)) ? (((fTemp116 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp116 >= 13.0f)) ? 0.14f : (((fTemp116 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp116 >= 6.0f)) ? (((fTemp116 >= 9.0f)) ? (((fTemp116 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp116 >= 8.0f)) ? 0.3f : (((fTemp116 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp116 >= 3.0f)) ? (((fTemp116 >= 5.0f)) ? 0.47f : (((fTemp116 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp116 >= 2.0f)) ? 0.74f : (((fTemp116 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp118))) : fTemp113)));
			float 	fTemp124 = (fRec60[1] - fTemp123);
			float 	fTemp125 = (fRec60[1] + fTemp123);
			fRec60[0] = (((fTemp125 < fTemp122)) ? fTemp125 : (((fTemp124 > fTemp122)) ? fTemp124 : fTemp122));
			fRec57[0] = fRec60[0];
			fRec55[0] = (fRec57[0] - (fConst18 * ((fConst16 * fRec55[2]) + (fConst14 * fRec55[1]))));
			float 	fTemp126 = min(0.99f, (fConst24 * (((3947.8418f * fRec55[0]) + (7895.6836f * fRec55[1])) + (3947.8418f * fRec55[2]))));
			float 	fTemp127 = min(0.8f, max(0.0f, ((fVec11[0] + (0.1f - fTemp126)) - fSlow52)));
			int 	iTemp128 = max(0, min(int(((499.0f * ftbl1[iTemp90]) + 0.5f)), 499));
			float 	fTemp129 = max(min((3.0f * (fVec11[0] - fTemp126)), 0.3f), -0.15f);
			float 	fTemp130 = ((iTemp2) ? 0.0f : (fSlow58 + fRec66[1]));
			fRec66[0] = (fTemp130 - floorf(fTemp130));
			int 	iTemp131 = max(0, min(int(((499.0f * fRec66[0]) + 0.5f)), 499));
			int 	iTemp132 = max(0, min(int(((499.0f * ftbl1[iTemp131]) + 0.5f)), 499));
			float 	fTemp133 = (fSlow60 + (fRec67[1] + -1.0f));
			float 	fTemp134 = (fSlow60 + fRec67[1]);
			int 	iTemp135 = (fTemp133 < 0.0f);
			fRec67[0] = ((iTemp135) ? fTemp134 : fTemp133);
			float 	fRec68 = ((iTemp135) ? fTemp134 : (fSlow60 + (fRec67[1] + (fSlow61 * fTemp133))));
			float 	fTemp136 = (fSlow63 + (fRec69[1] + -1.0f));
			float 	fTemp137 = (fSlow63 + fRec69[1]);
			int 	iTemp138 = (fTemp136 < 0.0f);
			fRec69[0] = ((iTemp138) ? fTemp137 : fTemp136);
			float 	fRec70 = ((iTemp138) ? fTemp137 : (fSlow63 + (fRec69[1] + (fSlow64 * fTemp136))));
			float 	fTemp139 = (fSlow66 + (fRec71[1] + -1.0f));
			float 	fTemp140 = (fSlow66 + fRec71[1]);
			int 	iTemp141 = (fTemp139 < 0.0f);
			fRec71[0] = ((iTemp141) ? fTemp140 : fTemp139);
			float 	fRec72 = ((iTemp141) ? fTemp140 : (fSlow66 + (fRec71[1] + (fSlow67 * fTemp139))));
			float 	fTemp142 = (fSlow69 + (fRec73[1] + -1.0f));
			float 	fTemp143 = (fSlow69 + fRec73[1]);
			int 	iTemp144 = (fTemp142 < 0.0f);
			fRec73[0] = ((iTemp144) ? fTemp143 : fTemp142);
			float 	fRec74 = ((iTemp144) ? fTemp143 : (fSlow69 + (fRec73[1] + (fSlow70 * fTemp142))));
			fVec13[0] = fSlow73;
			int 	iTemp145 = (fSlow73 != fVec13[1]);
			iVec14[0] = iTemp145;
			int 	iTemp146 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec78[0] = ((iRec78[1] * (1 - iTemp146)) + (iTemp20 * iTemp146));
			float 	fTemp147 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec78[0])))) > 0.5f) & iSlow74)) ? 0.0f : fSlow72)) + 0.5f))];
			fVec15[0] = fTemp147;
			int 	iTemp148 = (fVec15[0] > 0.001f);
			int 	iTemp149 = (fVec15[0] <= 0.001f);
			float 	fTemp150 = float((iTemp149 | (fVec15[1] >= 0.001f)));
			fRec79[0] = max((fRec79[1] * fTemp150), fSlow73);
			float 	fTemp151 = min(1.0f, fRec79[0]);
			int 	iTemp152 = (fVec15[0] >= fRec77[1]);
			int 	iTemp153 = (fRec77[1] <= 0.001f);
			int 	iTemp154 = (((iRec76[1] >= 4)) ? (((iRec76[1] >= 6)) ? ((iTemp153) ? 0 : ((iTemp148) ? 1 : 6)) : (((iRec76[1] >= 5)) ? ((iTemp149) ? 3 : ((iTemp152) ? 4 : 5)) : ((iTemp149) ? 3 : (((fVec15[0] <= fRec77[1])) ? 5 : 4)))) : (((iRec76[1] >= 2)) ? (((iRec76[1] >= 3)) ? (((iTemp149 & iTemp153)) ? 0 : ((iTemp148) ? 1 : 3)) : ((iTemp149) ? 3 : ((iTemp152) ? ((iTemp149) ? 6 : 4) : 2))) : (((iRec76[1] >= 1)) ? (((fRec77[1] >= min(fTemp151, 1.0f))) ? ((iTemp149) ? 6 : 2) : 1) : ((iTemp148) ? 1 : 0))));
			iRec76[0] = iTemp154;
			fRec81[0] = max((fTemp150 * fRec81[1]), fSlow75);
			float 	fTemp155 = (((iTemp154 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec81[0]))) : (((iTemp154 >= 4)) ? (((iTemp154 >= 6)) ? fConst23 : fConst22) : (((iTemp154 >= 2)) ? (((iTemp154 >= 3)) ? fConst21 : fConst20) : (((iTemp154 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp156 = (iRec76[1] != iRec76[2]);
			iVec16[0] = iTemp156;
			int 	iTemp157 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec82[0] = ((iRec82[1] * (1 - iTemp157)) + (iTemp20 * iTemp157));
			float 	fTemp158 = min(19.0f, floorf((21.0f * (((fTemp155 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec82[0]))) / fTemp155) : 1.0f))));
			float 	fTemp159 = min((fTemp158 + 1.0f), 2e+01f);
			float 	fTemp160 = (((fTemp159 >= 11.0f)) ? (((fTemp159 >= 16.0f)) ? (((fTemp159 >= 19.0f)) ? (((fTemp159 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp159 >= 18.0f)) ? 0.03f : (((fTemp159 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp159 >= 14.0f)) ? (((fTemp159 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp159 >= 13.0f)) ? 0.14f : (((fTemp159 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp159 >= 6.0f)) ? (((fTemp159 >= 9.0f)) ? (((fTemp159 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp159 >= 8.0f)) ? 0.3f : (((fTemp159 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp159 >= 3.0f)) ? (((fTemp159 >= 5.0f)) ? 0.47f : (((fTemp159 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp159 >= 2.0f)) ? 0.74f : (((fTemp159 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec83[0] = iRec76[1];
			int 	iTemp161 = (iRec83[1] == iRec76[1]);
			int 	iTemp162 = (iRec76[1] == 0);
			fRec84[0] = ((iTemp162) ? fVec15[0] : ((iTemp161) ? min(min(fRec84[1], fVec15[0]), fRec77[1]) : min(fVec15[0], fRec77[1])));
			fRec85[0] = ((iTemp162) ? fVec15[0] : ((iTemp161) ? max(max(fRec85[1], fVec15[0]), fRec77[1]) : max(fVec15[0], fRec77[1])));
			int 	iTemp163 = ((iRec76[1] == 3) | (iRec76[1] == 6));
			fbargraph3 = float(iRec76[1]);
			float 	fTemp164 = (((fbargraph3 == 1.0f)) ? min(1.0f, fTemp151) : ((iTemp162) ? 0.0f : ((iTemp163) ? (fRec85[0] * fTemp160) : fVec15[0])));
			float 	fTemp165 = (1.0f / ((iTemp162) ? 0.0001f : ((iTemp163) ? (0.05f * (fTemp155 / ((((fTemp158 >= 11.0f)) ? (((fTemp158 >= 16.0f)) ? (((fTemp158 >= 19.0f)) ? (((fTemp158 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp158 >= 18.0f)) ? 0.03f : (((fTemp158 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp158 >= 14.0f)) ? (((fTemp158 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp158 >= 13.0f)) ? 0.14f : (((fTemp158 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp158 >= 6.0f)) ? (((fTemp158 >= 9.0f)) ? (((fTemp158 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp158 >= 8.0f)) ? 0.3f : (((fTemp158 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp158 >= 3.0f)) ? (((fTemp158 >= 5.0f)) ? 0.47f : (((fTemp158 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp158 >= 2.0f)) ? 0.74f : (((fTemp158 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp160))) : fTemp155)));
			float 	fTemp166 = (fRec80[1] - fTemp165);
			float 	fTemp167 = (fRec80[1] + fTemp165);
			fRec80[0] = (((fTemp167 < fTemp164)) ? fTemp167 : (((fTemp166 > fTemp164)) ? fTemp166 : fTemp164));
			fRec77[0] = fRec80[0];
			fRec75[0] = (fRec77[0] - (fConst18 * ((fConst16 * fRec75[2]) + (fConst14 * fRec75[1]))));
			float 	fTemp168 = min(0.99f, (fConst24 * (((3947.8418f * fRec75[0]) + (7895.6836f * fRec75[1])) + (3947.8418f * fRec75[2]))));
			float 	fTemp169 = min(0.8f, max(0.0f, ((fVec15[0] + (0.1f - fTemp168)) - fSlow71)));
			int 	iTemp170 = max(0, min(int(((499.0f * ftbl1[iTemp132]) + 0.5f)), 499));
			float 	fTemp171 = max(min((3.0f * (fVec15[0] - fTemp168)), 0.3f), -0.15f);
			float 	fTemp172 = ((iTemp2) ? 0.0f : (fSlow77 + fRec86[1]));
			fRec86[0] = (fTemp172 - floorf(fTemp172));
			int 	iTemp173 = max(0, min(int(((499.0f * fRec86[0]) + 0.5f)), 499));
			int 	iTemp174 = max(0, min(int(((499.0f * ftbl1[iTemp173]) + 0.5f)), 499));
			float 	fTemp175 = (fSlow79 + (fRec87[1] + -1.0f));
			float 	fTemp176 = (fSlow79 + fRec87[1]);
			int 	iTemp177 = (fTemp175 < 0.0f);
			fRec87[0] = ((iTemp177) ? fTemp176 : fTemp175);
			float 	fRec88 = ((iTemp177) ? fTemp176 : (fSlow79 + (fRec87[1] + (fSlow80 * fTemp175))));
			float 	fTemp178 = (fSlow82 + (fRec89[1] + -1.0f));
			float 	fTemp179 = (fSlow82 + fRec89[1]);
			int 	iTemp180 = (fTemp178 < 0.0f);
			fRec89[0] = ((iTemp180) ? fTemp179 : fTemp178);
			float 	fRec90 = ((iTemp180) ? fTemp179 : (fSlow82 + (fRec89[1] + (fSlow83 * fTemp178))));
			float 	fTemp181 = (fSlow85 + (fRec91[1] + -1.0f));
			float 	fTemp182 = (fSlow85 + fRec91[1]);
			int 	iTemp183 = (fTemp181 < 0.0f);
			fRec91[0] = ((iTemp183) ? fTemp182 : fTemp181);
			float 	fRec92 = ((iTemp183) ? fTemp182 : (fSlow85 + (fRec91[1] + (fSlow86 * fTemp181))));
			float 	fTemp184 = (fSlow88 + (fRec93[1] + -1.0f));
			float 	fTemp185 = (fSlow88 + fRec93[1]);
			int 	iTemp186 = (fTemp184 < 0.0f);
			fRec93[0] = ((iTemp186) ? fTemp185 : fTemp184);
			float 	fRec94 = ((iTemp186) ? fTemp185 : (fSlow88 + (fRec93[1] + (fSlow89 * fTemp184))));
			fVec17[0] = fSlow92;
			int 	iTemp187 = (fSlow92 != fVec17[1]);
			iVec18[0] = iTemp187;
			int 	iTemp188 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec98[0] = ((iRec98[1] * (1 - iTemp188)) + (iTemp20 * iTemp188));
			float 	fTemp189 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec98[0])))) > 0.5f) & iSlow93)) ? 0.0f : fSlow91)) + 0.5f))];
			fVec19[0] = fTemp189;
			int 	iTemp190 = (fVec19[0] > 0.001f);
			int 	iTemp191 = (fVec19[0] <= 0.001f);
			float 	fTemp192 = float((iTemp191 | (fVec19[1] >= 0.001f)));
			fRec99[0] = max((fRec99[1] * fTemp192), fSlow92);
			float 	fTemp193 = min(1.0f, fRec99[0]);
			int 	iTemp194 = (fVec19[0] >= fRec97[1]);
			int 	iTemp195 = (fRec97[1] <= 0.001f);
			int 	iTemp196 = (((iRec96[1] >= 4)) ? (((iRec96[1] >= 6)) ? ((iTemp195) ? 0 : ((iTemp190) ? 1 : 6)) : (((iRec96[1] >= 5)) ? ((iTemp191) ? 3 : ((iTemp194) ? 4 : 5)) : ((iTemp191) ? 3 : (((fVec19[0] <= fRec97[1])) ? 5 : 4)))) : (((iRec96[1] >= 2)) ? (((iRec96[1] >= 3)) ? (((iTemp191 & iTemp195)) ? 0 : ((iTemp190) ? 1 : 3)) : ((iTemp191) ? 3 : ((iTemp194) ? ((iTemp191) ? 6 : 4) : 2))) : (((iRec96[1] >= 1)) ? (((fRec97[1] >= min(fTemp193, 1.0f))) ? ((iTemp191) ? 6 : 2) : 1) : ((iTemp190) ? 1 : 0))));
			iRec96[0] = iTemp196;
			fRec101[0] = max((fTemp192 * fRec101[1]), fSlow94);
			float 	fTemp197 = (((iTemp196 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec101[0]))) : (((iTemp196 >= 4)) ? (((iTemp196 >= 6)) ? fConst23 : fConst22) : (((iTemp196 >= 2)) ? (((iTemp196 >= 3)) ? fConst21 : fConst20) : (((iTemp196 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp198 = (iRec96[1] != iRec96[2]);
			iVec20[0] = iTemp198;
			int 	iTemp199 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec102[0] = ((iRec102[1] * (1 - iTemp199)) + (iTemp20 * iTemp199));
			float 	fTemp200 = min(19.0f, floorf((21.0f * (((fTemp197 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec102[0]))) / fTemp197) : 1.0f))));
			float 	fTemp201 = min((fTemp200 + 1.0f), 2e+01f);
			float 	fTemp202 = (((fTemp201 >= 11.0f)) ? (((fTemp201 >= 16.0f)) ? (((fTemp201 >= 19.0f)) ? (((fTemp201 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp201 >= 18.0f)) ? 0.03f : (((fTemp201 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp201 >= 14.0f)) ? (((fTemp201 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp201 >= 13.0f)) ? 0.14f : (((fTemp201 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp201 >= 6.0f)) ? (((fTemp201 >= 9.0f)) ? (((fTemp201 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp201 >= 8.0f)) ? 0.3f : (((fTemp201 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp201 >= 3.0f)) ? (((fTemp201 >= 5.0f)) ? 0.47f : (((fTemp201 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp201 >= 2.0f)) ? 0.74f : (((fTemp201 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec103[0] = iRec96[1];
			int 	iTemp203 = (iRec103[1] == iRec96[1]);
			int 	iTemp204 = (iRec96[1] == 0);
			fRec104[0] = ((iTemp204) ? fVec19[0] : ((iTemp203) ? min(min(fRec104[1], fVec19[0]), fRec97[1]) : min(fVec19[0], fRec97[1])));
			fRec105[0] = ((iTemp204) ? fVec19[0] : ((iTemp203) ? max(max(fRec105[1], fVec19[0]), fRec97[1]) : max(fVec19[0], fRec97[1])));
			int 	iTemp205 = ((iRec96[1] == 3) | (iRec96[1] == 6));
			fbargraph4 = float(iRec96[1]);
			float 	fTemp206 = (((fbargraph4 == 1.0f)) ? min(1.0f, fTemp193) : ((iTemp204) ? 0.0f : ((iTemp205) ? (fRec105[0] * fTemp202) : fVec19[0])));
			float 	fTemp207 = (1.0f / ((iTemp204) ? 0.0001f : ((iTemp205) ? (0.05f * (fTemp197 / ((((fTemp200 >= 11.0f)) ? (((fTemp200 >= 16.0f)) ? (((fTemp200 >= 19.0f)) ? (((fTemp200 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp200 >= 18.0f)) ? 0.03f : (((fTemp200 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp200 >= 14.0f)) ? (((fTemp200 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp200 >= 13.0f)) ? 0.14f : (((fTemp200 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp200 >= 6.0f)) ? (((fTemp200 >= 9.0f)) ? (((fTemp200 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp200 >= 8.0f)) ? 0.3f : (((fTemp200 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp200 >= 3.0f)) ? (((fTemp200 >= 5.0f)) ? 0.47f : (((fTemp200 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp200 >= 2.0f)) ? 0.74f : (((fTemp200 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp202))) : fTemp197)));
			float 	fTemp208 = (fRec100[1] - fTemp207);
			float 	fTemp209 = (fRec100[1] + fTemp207);
			fRec100[0] = (((fTemp209 < fTemp206)) ? fTemp209 : (((fTemp208 > fTemp206)) ? fTemp208 : fTemp206));
			fRec97[0] = fRec100[0];
			fRec95[0] = (fRec97[0] - (fConst18 * ((fConst16 * fRec95[2]) + (fConst14 * fRec95[1]))));
			float 	fTemp210 = min(0.99f, (fConst24 * (((3947.8418f * fRec95[0]) + (7895.6836f * fRec95[1])) + (3947.8418f * fRec95[2]))));
			float 	fTemp211 = min(0.8f, max(0.0f, ((fVec19[0] + (0.1f - fTemp210)) - fSlow90)));
			int 	iTemp212 = max(0, min(int(((499.0f * ftbl1[iTemp174]) + 0.5f)), 499));
			float 	fTemp213 = max(min((3.0f * (fVec19[0] - fTemp210)), 0.3f), -0.15f);
			float 	fTemp214 = ((iTemp2) ? 0.0f : (fSlow96 + fRec106[1]));
			fRec106[0] = (fTemp214 - floorf(fTemp214));
			int 	iTemp215 = max(0, min(int(((499.0f * fRec106[0]) + 0.5f)), 499));
			int 	iTemp216 = max(0, min(int(((499.0f * ftbl1[iTemp215]) + 0.5f)), 499));
			float 	fTemp217 = (fSlow98 + (fRec107[1] + -1.0f));
			float 	fTemp218 = (fSlow98 + fRec107[1]);
			int 	iTemp219 = (fTemp217 < 0.0f);
			fRec107[0] = ((iTemp219) ? fTemp218 : fTemp217);
			float 	fRec108 = ((iTemp219) ? fTemp218 : (fSlow98 + (fRec107[1] + (fSlow99 * fTemp217))));
			float 	fTemp220 = (fSlow101 + (fRec109[1] + -1.0f));
			float 	fTemp221 = (fSlow101 + fRec109[1]);
			int 	iTemp222 = (fTemp220 < 0.0f);
			fRec109[0] = ((iTemp222) ? fTemp221 : fTemp220);
			float 	fRec110 = ((iTemp222) ? fTemp221 : (fSlow101 + (fRec109[1] + (fSlow102 * fTemp220))));
			float 	fTemp223 = (fSlow104 + (fRec111[1] + -1.0f));
			float 	fTemp224 = (fSlow104 + fRec111[1]);
			int 	iTemp225 = (fTemp223 < 0.0f);
			fRec111[0] = ((iTemp225) ? fTemp224 : fTemp223);
			float 	fRec112 = ((iTemp225) ? fTemp224 : (fSlow104 + (fRec111[1] + (fSlow105 * fTemp223))));
			float 	fTemp226 = (fSlow107 + (fRec113[1] + -1.0f));
			float 	fTemp227 = (fSlow107 + fRec113[1]);
			int 	iTemp228 = (fTemp226 < 0.0f);
			fRec113[0] = ((iTemp228) ? fTemp227 : fTemp226);
			float 	fRec114 = ((iTemp228) ? fTemp227 : (fSlow107 + (fRec113[1] + (fSlow108 * fTemp226))));
			fVec21[0] = fSlow111;
			int 	iTemp229 = (fSlow111 != fVec21[1]);
			iVec22[0] = iTemp229;
			int 	iTemp230 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec118[0] = ((iRec118[1] * (1 - iTemp230)) + (iTemp20 * iTemp230));
			float 	fTemp231 = ftbl3[int(((499.0f * (((((fConst10 * float((iRec18[0] + (-1 - iRec118[0])))) > 0.5f) & iSlow112)) ? 0.0f : fSlow110)) + 0.5f))];
			fVec23[0] = fTemp231;
			int 	iTemp232 = (fVec23[0] > 0.001f);
			int 	iTemp233 = (fVec23[0] <= 0.001f);
			float 	fTemp234 = float((iTemp233 | (fVec23[1] >= 0.001f)));
			fRec119[0] = max((fRec119[1] * fTemp234), fSlow111);
			float 	fTemp235 = min(1.0f, fRec119[0]);
			int 	iTemp236 = (fVec23[0] >= fRec117[1]);
			int 	iTemp237 = (fRec117[1] <= 0.001f);
			int 	iTemp238 = (((iRec116[1] >= 4)) ? (((iRec116[1] >= 6)) ? ((iTemp237) ? 0 : ((iTemp232) ? 1 : 6)) : (((iRec116[1] >= 5)) ? ((iTemp233) ? 3 : ((iTemp236) ? 4 : 5)) : ((iTemp233) ? 3 : (((fVec23[0] <= fRec117[1])) ? 5 : 4)))) : (((iRec116[1] >= 2)) ? (((iRec116[1] >= 3)) ? (((iTemp233 & iTemp237)) ? 0 : ((iTemp232) ? 1 : 3)) : ((iTemp233) ? 3 : ((iTemp236) ? ((iTemp233) ? 6 : 4) : 2))) : (((iRec116[1] >= 1)) ? (((fRec117[1] >= min(fTemp235, 1.0f))) ? ((iTemp233) ? 6 : 2) : 1) : ((iTemp232) ? 1 : 0))));
			iRec116[0] = iTemp238;
			fRec121[0] = max((fTemp234 * fRec121[1]), fSlow113);
			float 	fTemp239 = (((iTemp238 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec121[0]))) : (((iTemp238 >= 4)) ? (((iTemp238 >= 6)) ? fConst23 : fConst22) : (((iTemp238 >= 2)) ? (((iTemp238 >= 3)) ? fConst21 : fConst20) : (((iTemp238 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp240 = (iRec116[1] != iRec116[2]);
			iVec24[0] = iTemp240;
			int 	iTemp241 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec122[0] = ((iRec122[1] * (1 - iTemp241)) + (iTemp20 * iTemp241));
			float 	fTemp242 = min(19.0f, floorf((21.0f * (((fTemp239 > 0.0f)) ? (float((iRec18[0] + (-1 - iRec122[0]))) / fTemp239) : 1.0f))));
			float 	fTemp243 = min((fTemp242 + 1.0f), 2e+01f);
			float 	fTemp244 = (((fTemp243 >= 11.0f)) ? (((fTemp243 >= 16.0f)) ? (((fTemp243 >= 19.0f)) ? (((fTemp243 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp243 >= 18.0f)) ? 0.03f : (((fTemp243 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp243 >= 14.0f)) ? (((fTemp243 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp243 >= 13.0f)) ? 0.14f : (((fTemp243 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp243 >= 6.0f)) ? (((fTemp243 >= 9.0f)) ? (((fTemp243 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp243 >= 8.0f)) ? 0.3f : (((fTemp243 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp243 >= 3.0f)) ? (((fTemp243 >= 5.0f)) ? 0.47f : (((fTemp243 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp243 >= 2.0f)) ? 0.74f : (((fTemp243 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec123[0] = iRec116[1];
			int 	iTemp245 = (iRec123[1] == iRec116[1]);
			int 	iTemp246 = (iRec116[1] == 0);
			fRec124[0] = ((iTemp246) ? fVec23[0] : ((iTemp245) ? min(min(fRec124[1], fVec23[0]), fRec117[1]) : min(fVec23[0], fRec117[1])));
			fRec125[0] = ((iTemp246) ? fVec23[0] : ((iTemp245) ? max(max(fRec125[1], fVec23[0]), fRec117[1]) : max(fVec23[0], fRec117[1])));
			int 	iTemp247 = ((iRec116[1] == 3) | (iRec116[1] == 6));
			fbargraph5 = float(iRec116[1]);
			float 	fTemp248 = (((fbargraph5 == 1.0f)) ? min(1.0f, fTemp235) : ((iTemp246) ? 0.0f : ((iTemp247) ? (fRec125[0] * fTemp244) : fVec23[0])));
			float 	fTemp249 = (1.0f / ((iTemp246) ? 0.0001f : ((iTemp247) ? (0.05f * (fTemp239 / ((((fTemp242 >= 11.0f)) ? (((fTemp242 >= 16.0f)) ? (((fTemp242 >= 19.0f)) ? (((fTemp242 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp242 >= 18.0f)) ? 0.03f : (((fTemp242 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp242 >= 14.0f)) ? (((fTemp242 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp242 >= 13.0f)) ? 0.14f : (((fTemp242 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp242 >= 6.0f)) ? (((fTemp242 >= 9.0f)) ? (((fTemp242 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp242 >= 8.0f)) ? 0.3f : (((fTemp242 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp242 >= 3.0f)) ? (((fTemp242 >= 5.0f)) ? 0.47f : (((fTemp242 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp242 >= 2.0f)) ? 0.74f : (((fTemp242 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp244))) : fTemp239)));
			float 	fTemp250 = (fRec120[1] - fTemp249);
			float 	fTemp251 = (fRec120[1] + fTemp249);
			fRec120[0] = (((fTemp251 < fTemp248)) ? fTemp251 : (((fTemp250 > fTemp248)) ? fTemp250 : fTemp248));
			fRec117[0] = fRec120[0];
			fRec115[0] = (fRec117[0] - (fConst18 * ((fConst16 * fRec115[2]) + (fConst14 * fRec115[1]))));
			float 	fTemp252 = min(0.99f, (fConst24 * (((3947.8418f * fRec115[0]) + (7895.6836f * fRec115[1])) + (3947.8418f * fRec115[2]))));
			float 	fTemp253 = min(0.8f, max(0.0f, ((fVec23[0] + (0.1f - fTemp252)) - fSlow109)));
			int 	iTemp254 = max(0, min(int(((499.0f * ftbl1[iTemp216]) + 0.5f)), 499));
			float 	fTemp255 = max(min((3.0f * (fVec23[0] - fTemp252)), 0.3f), -0.15f);
			fRec0[0] = ((1.37f * ((((((fTemp252 * (((((ftbl0[iTemp254] * (0.85f - fTemp255)) + ((fTemp255 + 0.15f) * ftbl2[iTemp254])) * (0.95f - fTemp253)) + (fTemp253 * ((0.3f * (((2.0f * fRec114) + -1.0f) + ((2.0f * fRec112) + -1.0f))) + (0.2f * (((2.0f * fRec110) + -1.0f) + ((2.0f * fRec108) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp215]) + (0.67f * ftbl0[iTemp216]))))) + (fTemp210 * (((((ftbl0[iTemp212] * (0.85f - fTemp213)) + ((fTemp213 + 0.15f) * ftbl2[iTemp212])) * (0.95f - fTemp211)) + (fTemp211 * ((0.3f * (((2.0f * fRec94) + -1.0f) + ((2.0f * fRec92) + -1.0f))) + (0.2f * (((2.0f * fRec90) + -1.0f) + ((2.0f * fRec88) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp173]) + (0.67f * ftbl0[iTemp174])))))) + (fTemp168 * (((((ftbl0[iTemp170] * (0.85f - fTemp171)) + ((fTemp171 + 0.15f) * ftbl2[iTemp170])) * (0.95f - fTemp169)) + (fTemp169 * ((0.3f * (((2.0f * fRec74) + -1.0f) + ((2.0f * fRec72) + -1.0f))) + (0.2f * (((2.0f * fRec70) + -1.0f) + ((2.0f * fRec68) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp131]) + (0.67f * ftbl0[iTemp132])))))) + (fTemp126 * (((((ftbl0[iTemp128] * (0.85f - fTemp129)) + ((fTemp129 + 0.15f) * ftbl2[iTemp128])) * (0.95f - fTemp127)) + (fTemp127 * ((0.3f * (((2.0f * fRec54) + -1.0f) + ((2.0f * fRec52) + -1.0f))) + (0.2f * (((2.0f * fRec50) + -1.0f) + ((2.0f * fRec48) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp89]) + (0.67f * ftbl0[iTemp90])))))) + (fTemp84 * (((((ftbl0[iTemp86] * (0.85f - fTemp87)) + ((fTemp87 + 0.15f) * ftbl2[iTemp86])) * (0.95f - fTemp85)) + (fTemp85 * ((0.3f * (((2.0f * fRec34) + -1.0f) + ((2.0f * fRec32) + -1.0f))) + (0.2f * (((2.0f * fRec30) + -1.0f) + ((2.0f * fRec28) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp47]) + (0.67f * ftbl0[iTemp48])))))) + (fTemp42 * (((((ftbl0[iTemp44] * (0.85f - fTemp45)) + ((fTemp45 + 0.15f) * ftbl2[iTemp44])) * (0.95f - fTemp43)) + (fTemp43 * ((0.3f * (((2.0f * fRec12) + -1.0f) + ((2.0f * fRec10) + -1.0f))) + (0.2f * (((2.0f * fRec8) + -1.0f) + ((2.0f * fRec6) + -1.0f)))))) + (0.05f * ((0.33f * ftbl2[iTemp4]) + (0.67f * ftbl0[iTemp5]))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst25 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec115[2] = fRec115[1]; fRec115[1] = fRec115[0];
			fRec117[1] = fRec117[0];
			fRec120[1] = fRec120[0];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			iRec123[1] = iRec123[0];
			iRec122[1] = iRec122[0];
			iVec24[1] = iVec24[0];
			fRec121[1] = fRec121[0];
			iRec116[2] = iRec116[1]; iRec116[1] = iRec116[0];
			fRec119[1] = fRec119[0];
			fVec23[1] = fVec23[0];
			iRec118[1] = iRec118[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec113[1] = fRec113[0];
			fRec111[1] = fRec111[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec106[1] = fRec106[0];
			fRec95[2] = fRec95[1]; fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			fRec100[1] = fRec100[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			iRec103[1] = iRec103[0];
			iRec102[1] = iRec102[0];
			iVec20[1] = iVec20[0];
			fRec101[1] = fRec101[0];
			iRec96[2] = iRec96[1]; iRec96[1] = iRec96[0];
			fRec99[1] = fRec99[0];
			fVec19[1] = fVec19[0];
			iRec98[1] = iRec98[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec93[1] = fRec93[0];
			fRec91[1] = fRec91[0];
			fRec89[1] = fRec89[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec75[2] = fRec75[1]; fRec75[1] = fRec75[0];
			fRec77[1] = fRec77[0];
			fRec80[1] = fRec80[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			iRec83[1] = iRec83[0];
			iRec82[1] = iRec82[0];
			iVec16[1] = iVec16[0];
			fRec81[1] = fRec81[0];
			iRec76[2] = iRec76[1]; iRec76[1] = iRec76[0];
			fRec79[1] = fRec79[0];
			fVec15[1] = fVec15[0];
			iRec78[1] = iRec78[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec73[1] = fRec73[0];
			fRec71[1] = fRec71[0];
			fRec69[1] = fRec69[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec55[2] = fRec55[1]; fRec55[1] = fRec55[0];
			fRec57[1] = fRec57[0];
			fRec60[1] = fRec60[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			iRec63[1] = iRec63[0];
			iRec62[1] = iRec62[0];
			iVec12[1] = iVec12[0];
			fRec61[1] = fRec61[0];
			iRec56[2] = iRec56[1]; iRec56[1] = iRec56[0];
			fRec59[1] = fRec59[0];
			fVec11[1] = fVec11[0];
			iRec58[1] = iRec58[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec53[1] = fRec53[0];
			fRec51[1] = fRec51[0];
			fRec49[1] = fRec49[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec40[1] = fRec40[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			iRec43[1] = iRec43[0];
			iRec42[1] = iRec42[0];
			iVec8[1] = iVec8[0];
			fRec41[1] = fRec41[0];
			iRec36[2] = iRec36[1]; iRec36[1] = iRec36[0];
			fRec39[1] = fRec39[0];
			fVec7[1] = fVec7[0];
			iRec38[1] = iRec38[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec33[1] = fRec33[0];
			fRec31[1] = fRec31[0];
			fRec29[1] = fRec29[0];
			fRec27[1] = fRec27[0];
			fRec26[1] = fRec26[0];
			fRec13[2] = fRec13[1]; fRec13[1] = fRec13[0];
			fRec15[1] = fRec15[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec24[1] = fRec24[0];
			iRec23[1] = iRec23[0];
			iRec22[1] = iRec22[0];
			iVec4[1] = iVec4[0];
			fRec21[1] = fRec21[0];
			iRec14[2] = iRec14[1]; iRec14[1] = iRec14[0];
			fRec19[1] = fRec19[0];
			fVec3[1] = fVec3[0];
			iRec17[1] = iRec17[0];
			iRec18[1] = iRec18[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec11[1] = fRec11[0];
			fRec9[1] = fRec9[0];
			fRec7[1] = fRec7[0];
			fRec5[1] = fRec5[0];
			fRec3[1] = fRec3[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[500];
float 	mydsp::ftbl1[500];
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
