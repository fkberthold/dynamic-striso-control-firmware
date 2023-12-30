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
		int 	iRec3[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec3[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec3[0] = (iRec3[1] + 1);
				output[i] = ((0.004008016f * float((iRec3[0] + -1))) + -1.0f);
				// post processing
				iRec3[1] = iRec3[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec5[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec5[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec5[0] = (iRec5[1] + 1);
				float 	fTemp11 = ((0.002002002f * float((iRec5[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp11)) + -1.0f))) * float(((fTemp11 > 0.0f) - (fTemp11 < 0.0f))));
				// post processing
				iRec5[1] = iRec5[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec14[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec14[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec14[0] = (iRec14[1] + 1);
				int 	iTemp23 = int((1.05f * float((iRec14[0] + -1))));
				output[i] = (((iTemp23 >= 11)) ? (((iTemp23 >= 16)) ? (((iTemp23 >= 19)) ? (((iTemp23 >= 20)) ? 0.0f : 0.01f) : (((iTemp23 >= 18)) ? 0.03f : (((iTemp23 >= 17)) ? 0.06f : 0.08f))) : (((iTemp23 >= 14)) ? (((iTemp23 >= 15)) ? 0.1f : 0.12f) : (((iTemp23 >= 13)) ? 0.14f : (((iTemp23 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp23 >= 6)) ? (((iTemp23 >= 9)) ? (((iTemp23 >= 10)) ? 0.22f : 0.26f) : (((iTemp23 >= 8)) ? 0.3f : (((iTemp23 >= 7)) ? 0.35f : 0.4f))) : (((iTemp23 >= 3)) ? (((iTemp23 >= 5)) ? 0.47f : (((iTemp23 >= 4)) ? 0.55f : 0.64f)) : (((iTemp23 >= 2)) ? 0.74f : (((iTemp23 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec14[1] = iRec14[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[500];
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec2[2];
	static float 	ftbl1[500];
	float 	fConst10;
	float 	fRec4[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider1;
	float 	fConst14;
	float 	fConst16;
	float 	fConst18;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec10[2];
	int 	iRec9[2];
	float 	fConst19;
	float 	fVec3[2];
	float 	fRec11[2];
	float 	fRec12[2];
	int 	iRec7[3];
	static float 	ftbl3[21];
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fConst24;
	int 	iVec4[2];
	int 	iRec15[2];
	float 	fRec16[2];
	float 	fRec13[2];
	float 	fRec8[2];
	float 	fRec6[3];
	float 	fConst25;
	float 	fConst26;
	float 	fConst27;
	float 	fConst28;
	int 	iRec18[2];
	float 	fRec17[3];
	float 	fConst29;
	float 	fConst30;
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fConst31;
	float 	fRec19[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec23[2];
	float 	fRec24[2];
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
	float 	fRec33[2];
	float 	fRec31[2];
	float 	fRec27[2];
	float 	fRec25[3];
	float 	fRec34[3];
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec35[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec39[2];
	float 	fRec40[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec9[2];
	int 	iVec10[2];
	int 	iRec44[2];
	float 	fVec11[2];
	float 	fRec45[2];
	float 	fRec46[2];
	int 	iRec42[3];
	int 	iVec12[2];
	int 	iRec48[2];
	float 	fRec49[2];
	float 	fRec47[2];
	float 	fRec43[2];
	float 	fRec41[3];
	float 	fRec50[3];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec54[2];
	float 	fRec51[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec55[2];
	float 	fRec56[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec13[2];
	int 	iVec14[2];
	int 	iRec60[2];
	float 	fVec15[2];
	float 	fRec61[2];
	float 	fRec62[2];
	int 	iRec58[3];
	int 	iVec16[2];
	int 	iRec64[2];
	float 	fRec65[2];
	float 	fRec63[2];
	float 	fRec59[2];
	float 	fRec57[3];
	float 	fRec66[3];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec70[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec71[2];
	float 	fRec72[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec17[2];
	int 	iVec18[2];
	int 	iRec76[2];
	float 	fVec19[2];
	float 	fRec77[2];
	float 	fRec78[2];
	int 	iRec74[3];
	int 	iVec20[2];
	int 	iRec80[2];
	float 	fRec81[2];
	float 	fRec79[2];
	float 	fRec75[2];
	float 	fRec73[3];
	float 	fRec82[3];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fRec83[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec87[2];
	float 	fRec88[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec21[2];
	int 	iVec22[2];
	int 	iRec92[2];
	float 	fVec23[2];
	float 	fRec93[2];
	float 	fRec94[2];
	int 	iRec90[3];
	int 	iVec24[2];
	int 	iRec96[2];
	float 	fRec97[2];
	float 	fRec95[2];
	float 	fRec91[2];
	float 	fRec89[3];
	float 	fRec98[3];
	float 	fRec100[2];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec99[2];
	float 	fRec0[3];
	float 	fConst32;
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
		float 	fConst1 = powf(fConst0,2.0f);
		float 	fConst2 = powf((125.663704f / fConst0),2.0f);
		float 	fConst3 = ((fConst2 * ((0.2033f * fConst2) + 0.31755f)) + 1.0f);
		fConst4 = (2.0f * ((15791.367f * (powf(fConst3,2.0f) / fConst1)) + -1.0f));
		float 	fConst5 = (15791.367f * (fConst3 / fConst0));
		fConst6 = (((fConst3 * (fConst5 + -95.92649f)) / fConst0) + 1.0f);
		float 	fConst7 = (((fConst3 * (fConst5 + 95.92649f)) / fConst0) + 1.0f);
		fConst8 = (1.0f / fConst7);
		fConst9 = (4.0878997f / fConst0);
		fConst10 = (2.0439498f / fConst0);
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
		fConst24 = (0.75f * fConst0);
		fConst25 = (fConst13 / (fConst1 * fConst17));
		fConst26 = (25.68503f / fConst0);
		fConst27 = (659.72076f / fConst1);
		fConst28 = (659.72076f / fConst0);
		fConst29 = (0.2568503f / fConst0);
		fConst30 = (8.175799f / fConst0);
		fConst31 = (3333.3333f / fConst0);
		fConst32 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
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
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec44[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<3; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<3; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<3; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<3; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec92[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<3; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
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
		float 	fSlow4 = ftbl2[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (fSlow4 + 1.0f);
		float 	fSlow6 = float(fslider2);
		float 	fSlow7 = float(fslider3);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.0f - fSlow7);
		float 	fSlow10 = powf((fConst26 * fSlow0),2.0f);
		float 	fSlow11 = ((fSlow10 * ((0.2033f * fSlow10) + 0.31755f)) + 1.0f);
		float 	fSlow12 = (2.0f * ((fConst27 * (powf(fSlow0,2.0f) * powf(fSlow11,2.0f))) + -1.0f));
		float 	fSlow13 = (fSlow0 * fSlow11);
		float 	fSlow14 = (fConst28 * fSlow13);
		float 	fSlow15 = ((fConst19 * (fSlow13 * (fSlow14 + -0.2568503f))) + 1.0f);
		float 	fSlow16 = ((fConst19 * (fSlow13 * (fSlow14 + 0.2568503f))) + 1.0f);
		float 	fSlow17 = (1.0f / fSlow16);
		float 	fSlow18 = max(0.05f, (0.1f - fabsf(fSlow7)));
		float 	fSlow19 = (fConst29 * (fSlow13 / fSlow16));
		float 	fSlow20 = (fConst30 * fSlow0);
		float 	fSlow21 = (0.0f - fSlow3);
		float 	fSlow22 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow23 = (fConst9 * fSlow22);
		float 	fSlow24 = (fConst10 * fSlow22);
		float 	fSlow25 = float(fslider5);
		float 	fSlow26 = ftbl2[int(((499.5f * (fSlow25 + 1.0f)) + 0.5f))];
		float 	fSlow27 = (fSlow26 + 1.0f);
		float 	fSlow28 = float(fslider6);
		float 	fSlow29 = float(fslider7);
		int 	iSlow30 = (fSlow29 == 0.0f);
		float 	fSlow31 = (0.0f - fSlow29);
		float 	fSlow32 = powf((fConst26 * fSlow22),2.0f);
		float 	fSlow33 = ((fSlow32 * ((0.2033f * fSlow32) + 0.31755f)) + 1.0f);
		float 	fSlow34 = (2.0f * ((fConst27 * (powf(fSlow22,2.0f) * powf(fSlow33,2.0f))) + -1.0f));
		float 	fSlow35 = (fSlow22 * fSlow33);
		float 	fSlow36 = (fConst28 * fSlow35);
		float 	fSlow37 = ((fConst19 * (fSlow35 * (fSlow36 + -0.2568503f))) + 1.0f);
		float 	fSlow38 = ((fConst19 * (fSlow35 * (fSlow36 + 0.2568503f))) + 1.0f);
		float 	fSlow39 = (1.0f / fSlow38);
		float 	fSlow40 = max(0.05f, (0.1f - fabsf(fSlow29)));
		float 	fSlow41 = (fConst29 * (fSlow35 / fSlow38));
		float 	fSlow42 = (fConst30 * fSlow22);
		float 	fSlow43 = (0.0f - fSlow25);
		float 	fSlow44 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow45 = (fConst9 * fSlow44);
		float 	fSlow46 = (fConst10 * fSlow44);
		float 	fSlow47 = float(fslider9);
		float 	fSlow48 = ftbl2[int(((499.5f * (fSlow47 + 1.0f)) + 0.5f))];
		float 	fSlow49 = (fSlow48 + 1.0f);
		float 	fSlow50 = float(fslider10);
		float 	fSlow51 = float(fslider11);
		int 	iSlow52 = (fSlow51 == 0.0f);
		float 	fSlow53 = (0.0f - fSlow51);
		float 	fSlow54 = powf((fConst26 * fSlow44),2.0f);
		float 	fSlow55 = ((fSlow54 * ((0.2033f * fSlow54) + 0.31755f)) + 1.0f);
		float 	fSlow56 = (2.0f * ((fConst27 * (powf(fSlow44,2.0f) * powf(fSlow55,2.0f))) + -1.0f));
		float 	fSlow57 = (fSlow44 * fSlow55);
		float 	fSlow58 = (fConst28 * fSlow57);
		float 	fSlow59 = ((fConst19 * (fSlow57 * (fSlow58 + -0.2568503f))) + 1.0f);
		float 	fSlow60 = ((fConst19 * (fSlow57 * (fSlow58 + 0.2568503f))) + 1.0f);
		float 	fSlow61 = (1.0f / fSlow60);
		float 	fSlow62 = max(0.05f, (0.1f - fabsf(fSlow51)));
		float 	fSlow63 = (fConst29 * (fSlow57 / fSlow60));
		float 	fSlow64 = (fConst30 * fSlow44);
		float 	fSlow65 = (0.0f - fSlow47);
		float 	fSlow66 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow67 = (fConst9 * fSlow66);
		float 	fSlow68 = (fConst10 * fSlow66);
		float 	fSlow69 = float(fslider13);
		float 	fSlow70 = ftbl2[int(((499.5f * (fSlow69 + 1.0f)) + 0.5f))];
		float 	fSlow71 = (fSlow70 + 1.0f);
		float 	fSlow72 = float(fslider14);
		float 	fSlow73 = float(fslider15);
		int 	iSlow74 = (fSlow73 == 0.0f);
		float 	fSlow75 = (0.0f - fSlow73);
		float 	fSlow76 = powf((fConst26 * fSlow66),2.0f);
		float 	fSlow77 = ((fSlow76 * ((0.2033f * fSlow76) + 0.31755f)) + 1.0f);
		float 	fSlow78 = (2.0f * ((fConst27 * (powf(fSlow66,2.0f) * powf(fSlow77,2.0f))) + -1.0f));
		float 	fSlow79 = (fSlow66 * fSlow77);
		float 	fSlow80 = (fConst28 * fSlow79);
		float 	fSlow81 = ((fConst19 * (fSlow79 * (fSlow80 + -0.2568503f))) + 1.0f);
		float 	fSlow82 = ((fConst19 * (fSlow79 * (fSlow80 + 0.2568503f))) + 1.0f);
		float 	fSlow83 = (1.0f / fSlow82);
		float 	fSlow84 = max(0.05f, (0.1f - fabsf(fSlow73)));
		float 	fSlow85 = (fConst29 * (fSlow79 / fSlow82));
		float 	fSlow86 = (fConst30 * fSlow66);
		float 	fSlow87 = (0.0f - fSlow69);
		float 	fSlow88 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow89 = (fConst9 * fSlow88);
		float 	fSlow90 = (fConst10 * fSlow88);
		float 	fSlow91 = float(fslider17);
		float 	fSlow92 = ftbl2[int(((499.5f * (fSlow91 + 1.0f)) + 0.5f))];
		float 	fSlow93 = (fSlow92 + 1.0f);
		float 	fSlow94 = float(fslider18);
		float 	fSlow95 = float(fslider19);
		int 	iSlow96 = (fSlow95 == 0.0f);
		float 	fSlow97 = (0.0f - fSlow95);
		float 	fSlow98 = powf((fConst26 * fSlow88),2.0f);
		float 	fSlow99 = ((fSlow98 * ((0.2033f * fSlow98) + 0.31755f)) + 1.0f);
		float 	fSlow100 = (2.0f * ((fConst27 * (powf(fSlow88,2.0f) * powf(fSlow99,2.0f))) + -1.0f));
		float 	fSlow101 = (fSlow88 * fSlow99);
		float 	fSlow102 = (fConst28 * fSlow101);
		float 	fSlow103 = ((fConst19 * (fSlow101 * (fSlow102 + -0.2568503f))) + 1.0f);
		float 	fSlow104 = ((fConst19 * (fSlow101 * (fSlow102 + 0.2568503f))) + 1.0f);
		float 	fSlow105 = (1.0f / fSlow104);
		float 	fSlow106 = max(0.05f, (0.1f - fabsf(fSlow95)));
		float 	fSlow107 = (fConst29 * (fSlow101 / fSlow104));
		float 	fSlow108 = (fConst30 * fSlow88);
		float 	fSlow109 = (0.0f - fSlow91);
		float 	fSlow110 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow111 = (fConst9 * fSlow110);
		float 	fSlow112 = (fConst10 * fSlow110);
		float 	fSlow113 = float(fslider21);
		float 	fSlow114 = ftbl2[int(((499.5f * (fSlow113 + 1.0f)) + 0.5f))];
		float 	fSlow115 = (fSlow114 + 1.0f);
		float 	fSlow116 = float(fslider22);
		float 	fSlow117 = float(fslider23);
		int 	iSlow118 = (fSlow117 == 0.0f);
		float 	fSlow119 = (0.0f - fSlow117);
		float 	fSlow120 = powf((fConst26 * fSlow110),2.0f);
		float 	fSlow121 = ((fSlow120 * ((0.2033f * fSlow120) + 0.31755f)) + 1.0f);
		float 	fSlow122 = (2.0f * ((fConst27 * (powf(fSlow110,2.0f) * powf(fSlow121,2.0f))) + -1.0f));
		float 	fSlow123 = (fSlow110 * fSlow121);
		float 	fSlow124 = (fConst28 * fSlow123);
		float 	fSlow125 = ((fConst19 * (fSlow123 * (fSlow124 + -0.2568503f))) + 1.0f);
		float 	fSlow126 = ((fConst19 * (fSlow123 * (fSlow124 + 0.2568503f))) + 1.0f);
		float 	fSlow127 = (1.0f / fSlow126);
		float 	fSlow128 = max(0.05f, (0.1f - fabsf(fSlow117)));
		float 	fSlow129 = (fConst29 * (fSlow123 / fSlow126));
		float 	fSlow130 = (fConst30 * fSlow110);
		float 	fSlow131 = (0.0f - fSlow113);
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
			float 	fTemp7 = ((iTemp2) ? 0.0f : (fSlow2 + fRec4[1]));
			fRec4[0] = (fTemp7 - floorf(fTemp7));
			float 	fTemp8 = (499.0f * fRec4[0]);
			int 	iTemp9 = int(fTemp8);
			float 	fTemp10 = ftbl1[max(0, min(iTemp9, 499))];
			fVec1[0] = fSlow7;
			int 	iTemp12 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp12;
			int 	iTemp13 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec10[0] = (iRec10[1] + 1);
			int 	iTemp14 = (iRec10[0] + -1);
			iRec9[0] = ((iRec9[1] * (1 - iTemp13)) + (iTemp14 * iTemp13));
			float 	fTemp15 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp15;
			int 	iTemp16 = (fVec3[0] > 0.003f);
			int 	iTemp17 = (fVec3[0] <= 0.003f);
			float 	fTemp18 = float((iTemp17 | (fVec3[1] >= 0.003f)));
			fRec11[0] = max((fRec11[1] * fTemp18), fSlow7);
			fRec12[0] = max((fTemp18 * fRec12[1]), fSlow9);
			float 	fTemp19 = (min(1.0f, fRec12[0]) + min(1.0f, fRec11[0]));
			int 	iTemp20 = (fVec3[0] >= fRec8[1]);
			int 	iTemp21 = (fRec8[1] <= 0.001f);
			int 	iTemp22 = (((iRec7[1] >= 4)) ? (((iRec7[1] >= 6)) ? ((iTemp21) ? 0 : ((iTemp16) ? 1 : 6)) : (((iRec7[1] >= 5)) ? ((iTemp17) ? 3 : ((iTemp20) ? 4 : 5)) : ((iTemp17) ? 3 : (((fVec3[0] <= fRec8[1])) ? 5 : 4)))) : (((iRec7[1] >= 2)) ? (((iRec7[1] >= 3)) ? (((iTemp17 & iTemp21)) ? 0 : ((iTemp16) ? 1 : 3)) : ((iTemp16) ? ((iTemp20) ? 4 : 2) : 6)) : (((iRec7[1] >= 1)) ? (((fRec8[1] >= min(fTemp19, 1.0f))) ? ((iTemp17) ? 6 : 2) : 1) : ((iTemp16) ? 1 : 0))));
			iRec7[0] = iTemp22;
			float 	fTemp24 = (((iTemp22 >= 4)) ? (((iTemp22 >= 6)) ? fConst24 : fConst23) : (((iTemp22 >= 2)) ? (((iTemp22 >= 3)) ? fConst22 : fConst21) : (((iTemp22 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp25 = (iRec7[1] != iRec7[2]);
			iVec4[0] = iTemp25;
			int 	iTemp26 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec15[0] = ((iRec15[1] * (1 - iTemp26)) + (iTemp14 * iTemp26));
			float 	fTemp27 = (2e+01f * (((fTemp24 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec15[0]))) / fTemp24) : 0.0f));
			int 	iTemp28 = int(fTemp27);
			float 	fTemp29 = ftbl3[max(0, int(min(int(iTemp28), 20)))];
			float 	fTemp30 = (fTemp29 + ((fTemp27 - float(iTemp28)) * (ftbl3[max(0, int(min(int((iTemp28 + 1)), 20)))] - fTemp29)));
			fRec16[0] = max((fRec16[1] * float(iVec4[0])), max(fVec3[0], fRec8[1]));
			int 	iTemp31 = (iRec7[1] == 3);
			int 	iTemp32 = (iRec7[1] == 6);
			int 	iTemp33 = (iRec7[1] == 0);
			float 	fTemp34 = (((iRec7[1] == 1)) ? min(1.0f, fTemp19) : ((iTemp33) ? 0.0f : ((iTemp32) ? (fTemp19 * fTemp30) : ((iTemp31) ? (fRec16[0] * fTemp30) : fVec3[0]))));
			float 	fTemp35 = (1.0f / ((iTemp33) ? 0.0001f : (((iTemp31 | iTemp32)) ? (0.04761905f * fTemp24) : fTemp24)));
			float 	fTemp36 = (fRec13[1] - fTemp35);
			float 	fTemp37 = (fRec13[1] + fTemp35);
			fRec13[0] = (((fTemp37 < fTemp34)) ? fTemp37 : (((fTemp36 > fTemp34)) ? fTemp36 : fTemp34));
			fRec8[0] = fRec13[0];
			fRec6[0] = (fRec8[0] - (fConst18 * ((fConst16 * fRec6[2]) + (fConst14 * fRec6[1]))));
			float 	fTemp38 = min(0.99f, (fConst25 * (((3947.8418f * fRec6[0]) + (7895.6836f * fRec6[1])) + (3947.8418f * fRec6[2]))));
			int 	iTemp39 = (fTemp38 < 0.1f);
			float 	fTemp40 = (((iTemp39) ? fTemp38 : 0.1f) * fSlow5);
			iRec18[0] = ((1103515245 * iRec18[1]) + 12345);
			float 	fTemp41 = (4.656613e-10f * float(iRec18[0]));
			fRec17[0] = (fTemp41 - (fSlow17 * ((fSlow15 * fRec17[2]) + (fSlow12 * fRec17[1]))));
			float 	fTemp42 = min(1.0f, (fSlow18 + ((iTemp39) ? (1.0f - (1e+01f * fTemp38)) : 0.0f)));
			float 	fTemp43 = ((iTemp2) ? 0.0f : (fSlow20 + fRec20[1]));
			fRec20[0] = (fTemp43 - floorf(fTemp43));
			float 	fTemp44 = (499.0f * fRec20[0]);
			int 	iTemp45 = int(fTemp44);
			int 	iTemp46 = max(0, min(iTemp45, 499));
			float 	fTemp47 = ftbl1[iTemp46];
			int 	iTemp48 = max(0, min((iTemp45 + 1), 499));
			float 	fTemp49 = (fTemp44 - float(iTemp45));
			float 	fTemp50 = float((((fVec3[1] <= 0.003f) & iTemp16) != 1));
			fRec21[0] = max((fTemp50 * fRec21[1]), fSlow21);
			fRec22[0] = max((fRec22[1] * fTemp50), fSlow3);
			float 	fTemp51 = max(min(((0.5f * (fVec3[0] - fTemp38)) + (0.2f - (0.8f * ((iTemp17) ? (2.0f * (((fRec22[0] > fRec21[0])) ? fRec22[0] : (0.0f - fRec21[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp52 = ftbl0[iTemp46];
			float 	fTemp53 = (((fTemp52 + (fTemp49 * (ftbl0[iTemp48] - fTemp52))) * (1.0f - fTemp51)) + (fTemp51 * (fTemp47 + (fTemp49 * (ftbl1[iTemp48] - fTemp47)))));
			float 	fTemp54 = (fRec19[1] - fConst31);
			float 	fTemp55 = (fConst31 + fRec19[1]);
			fRec19[0] = (((fTemp55 < fTemp53)) ? fTemp55 : (((fTemp54 > fTemp53)) ? fTemp54 : fTemp53));
			float 	fTemp56 = ((iTemp2) ? 0.0f : (fSlow23 + fRec23[1]));
			fRec23[0] = (fTemp56 - floorf(fTemp56));
			float 	fTemp57 = (499.0f * fRec23[0]);
			int 	iTemp58 = int(fTemp57);
			float 	fTemp59 = ftbl0[max(0, min(iTemp58, 499))];
			float 	fTemp60 = ((iTemp2) ? 0.0f : (fSlow24 + fRec24[1]));
			fRec24[0] = (fTemp60 - floorf(fTemp60));
			float 	fTemp61 = (499.0f * fRec24[0]);
			int 	iTemp62 = int(fTemp61);
			float 	fTemp63 = ftbl1[max(0, min(iTemp62, 499))];
			fVec5[0] = fSlow29;
			int 	iTemp64 = (fSlow29 != fVec5[1]);
			iVec6[0] = iTemp64;
			int 	iTemp65 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec28[0] = ((iRec28[1] * (1 - iTemp65)) + (iTemp14 * iTemp65));
			float 	fTemp66 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec28[0])))) > 0.5f) & iSlow30)) ? 0.0f : fSlow28) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp66;
			int 	iTemp67 = (fVec7[0] > 0.003f);
			int 	iTemp68 = (fVec7[0] <= 0.003f);
			float 	fTemp69 = float((iTemp68 | (fVec7[1] >= 0.003f)));
			fRec29[0] = max((fRec29[1] * fTemp69), fSlow29);
			fRec30[0] = max((fTemp69 * fRec30[1]), fSlow31);
			float 	fTemp70 = (min(1.0f, fRec30[0]) + min(1.0f, fRec29[0]));
			int 	iTemp71 = (fVec7[0] >= fRec27[1]);
			int 	iTemp72 = (fRec27[1] <= 0.001f);
			int 	iTemp73 = (((iRec26[1] >= 4)) ? (((iRec26[1] >= 6)) ? ((iTemp72) ? 0 : ((iTemp67) ? 1 : 6)) : (((iRec26[1] >= 5)) ? ((iTemp68) ? 3 : ((iTemp71) ? 4 : 5)) : ((iTemp68) ? 3 : (((fVec7[0] <= fRec27[1])) ? 5 : 4)))) : (((iRec26[1] >= 2)) ? (((iRec26[1] >= 3)) ? (((iTemp68 & iTemp72)) ? 0 : ((iTemp67) ? 1 : 3)) : ((iTemp67) ? ((iTemp71) ? 4 : 2) : 6)) : (((iRec26[1] >= 1)) ? (((fRec27[1] >= min(fTemp70, 1.0f))) ? ((iTemp68) ? 6 : 2) : 1) : ((iTemp67) ? 1 : 0))));
			iRec26[0] = iTemp73;
			float 	fTemp74 = (((iTemp73 >= 4)) ? (((iTemp73 >= 6)) ? fConst24 : fConst23) : (((iTemp73 >= 2)) ? (((iTemp73 >= 3)) ? fConst22 : fConst21) : (((iTemp73 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp75 = (iRec26[1] != iRec26[2]);
			iVec8[0] = iTemp75;
			int 	iTemp76 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp76)) + (iTemp14 * iTemp76));
			float 	fTemp77 = (2e+01f * (((fTemp74 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec32[0]))) / fTemp74) : 0.0f));
			int 	iTemp78 = int(fTemp77);
			float 	fTemp79 = ftbl3[max(0, int(min(int(iTemp78), 20)))];
			float 	fTemp80 = (fTemp79 + ((fTemp77 - float(iTemp78)) * (ftbl3[max(0, int(min(int((iTemp78 + 1)), 20)))] - fTemp79)));
			fRec33[0] = max((fRec33[1] * float(iVec8[0])), max(fVec7[0], fRec27[1]));
			int 	iTemp81 = (iRec26[1] == 3);
			int 	iTemp82 = (iRec26[1] == 6);
			int 	iTemp83 = (iRec26[1] == 0);
			float 	fTemp84 = (((iRec26[1] == 1)) ? min(1.0f, fTemp70) : ((iTemp83) ? 0.0f : ((iTemp82) ? (fTemp70 * fTemp80) : ((iTemp81) ? (fRec33[0] * fTemp80) : fVec7[0]))));
			float 	fTemp85 = (1.0f / ((iTemp83) ? 0.0001f : (((iTemp81 | iTemp82)) ? (0.04761905f * fTemp74) : fTemp74)));
			float 	fTemp86 = (fRec31[1] - fTemp85);
			float 	fTemp87 = (fRec31[1] + fTemp85);
			fRec31[0] = (((fTemp87 < fTemp84)) ? fTemp87 : (((fTemp86 > fTemp84)) ? fTemp86 : fTemp84));
			fRec27[0] = fRec31[0];
			fRec25[0] = (fRec27[0] - (fConst18 * ((fConst16 * fRec25[2]) + (fConst14 * fRec25[1]))));
			float 	fTemp88 = min(0.99f, (fConst25 * (((3947.8418f * fRec25[0]) + (7895.6836f * fRec25[1])) + (3947.8418f * fRec25[2]))));
			int 	iTemp89 = (fTemp88 < 0.1f);
			float 	fTemp90 = (((iTemp89) ? fTemp88 : 0.1f) * fSlow27);
			fRec34[0] = (fTemp41 - (fSlow39 * ((fSlow37 * fRec34[2]) + (fSlow34 * fRec34[1]))));
			float 	fTemp91 = min(1.0f, (fSlow40 + ((iTemp89) ? (1.0f - (1e+01f * fTemp88)) : 0.0f)));
			float 	fTemp92 = ((iTemp2) ? 0.0f : (fSlow42 + fRec36[1]));
			fRec36[0] = (fTemp92 - floorf(fTemp92));
			float 	fTemp93 = (499.0f * fRec36[0]);
			int 	iTemp94 = int(fTemp93);
			int 	iTemp95 = max(0, min(iTemp94, 499));
			float 	fTemp96 = ftbl1[iTemp95];
			int 	iTemp97 = max(0, min((iTemp94 + 1), 499));
			float 	fTemp98 = (fTemp93 - float(iTemp94));
			float 	fTemp99 = float((((fVec7[1] <= 0.003f) & iTemp67) != 1));
			fRec37[0] = max((fTemp99 * fRec37[1]), fSlow43);
			fRec38[0] = max((fRec38[1] * fTemp99), fSlow25);
			float 	fTemp100 = max(min(((0.5f * (fVec7[0] - fTemp88)) + (0.2f - (0.8f * ((iTemp68) ? (2.0f * (((fRec38[0] > fRec37[0])) ? fRec38[0] : (0.0f - fRec37[0]))) : fSlow26)))), 1.0f), 0.0f);
			float 	fTemp101 = ftbl0[iTemp95];
			float 	fTemp102 = (((fTemp101 + (fTemp98 * (ftbl0[iTemp97] - fTemp101))) * (1.0f - fTemp100)) + (fTemp100 * (fTemp96 + (fTemp98 * (ftbl1[iTemp97] - fTemp96)))));
			float 	fTemp103 = (fRec35[1] - fConst31);
			float 	fTemp104 = (fConst31 + fRec35[1]);
			fRec35[0] = (((fTemp104 < fTemp102)) ? fTemp104 : (((fTemp103 > fTemp102)) ? fTemp103 : fTemp102));
			float 	fTemp105 = ((iTemp2) ? 0.0f : (fSlow45 + fRec39[1]));
			fRec39[0] = (fTemp105 - floorf(fTemp105));
			float 	fTemp106 = (499.0f * fRec39[0]);
			int 	iTemp107 = int(fTemp106);
			float 	fTemp108 = ftbl0[max(0, min(iTemp107, 499))];
			float 	fTemp109 = ((iTemp2) ? 0.0f : (fSlow46 + fRec40[1]));
			fRec40[0] = (fTemp109 - floorf(fTemp109));
			float 	fTemp110 = (499.0f * fRec40[0]);
			int 	iTemp111 = int(fTemp110);
			float 	fTemp112 = ftbl1[max(0, min(iTemp111, 499))];
			fVec9[0] = fSlow51;
			int 	iTemp113 = (fSlow51 != fVec9[1]);
			iVec10[0] = iTemp113;
			int 	iTemp114 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec44[0] = ((iRec44[1] * (1 - iTemp114)) + (iTemp14 * iTemp114));
			float 	fTemp115 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec44[0])))) > 0.5f) & iSlow52)) ? 0.0f : fSlow50) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp115;
			int 	iTemp116 = (fVec11[0] > 0.003f);
			int 	iTemp117 = (fVec11[0] <= 0.003f);
			float 	fTemp118 = float((iTemp117 | (fVec11[1] >= 0.003f)));
			fRec45[0] = max((fRec45[1] * fTemp118), fSlow51);
			fRec46[0] = max((fTemp118 * fRec46[1]), fSlow53);
			float 	fTemp119 = (min(1.0f, fRec46[0]) + min(1.0f, fRec45[0]));
			int 	iTemp120 = (fVec11[0] >= fRec43[1]);
			int 	iTemp121 = (fRec43[1] <= 0.001f);
			int 	iTemp122 = (((iRec42[1] >= 4)) ? (((iRec42[1] >= 6)) ? ((iTemp121) ? 0 : ((iTemp116) ? 1 : 6)) : (((iRec42[1] >= 5)) ? ((iTemp117) ? 3 : ((iTemp120) ? 4 : 5)) : ((iTemp117) ? 3 : (((fVec11[0] <= fRec43[1])) ? 5 : 4)))) : (((iRec42[1] >= 2)) ? (((iRec42[1] >= 3)) ? (((iTemp117 & iTemp121)) ? 0 : ((iTemp116) ? 1 : 3)) : ((iTemp116) ? ((iTemp120) ? 4 : 2) : 6)) : (((iRec42[1] >= 1)) ? (((fRec43[1] >= min(fTemp119, 1.0f))) ? ((iTemp117) ? 6 : 2) : 1) : ((iTemp116) ? 1 : 0))));
			iRec42[0] = iTemp122;
			float 	fTemp123 = (((iTemp122 >= 4)) ? (((iTemp122 >= 6)) ? fConst24 : fConst23) : (((iTemp122 >= 2)) ? (((iTemp122 >= 3)) ? fConst22 : fConst21) : (((iTemp122 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp124 = (iRec42[1] != iRec42[2]);
			iVec12[0] = iTemp124;
			int 	iTemp125 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec48[0] = ((iRec48[1] * (1 - iTemp125)) + (iTemp14 * iTemp125));
			float 	fTemp126 = (2e+01f * (((fTemp123 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec48[0]))) / fTemp123) : 0.0f));
			int 	iTemp127 = int(fTemp126);
			float 	fTemp128 = ftbl3[max(0, int(min(int(iTemp127), 20)))];
			float 	fTemp129 = (fTemp128 + ((fTemp126 - float(iTemp127)) * (ftbl3[max(0, int(min(int((iTemp127 + 1)), 20)))] - fTemp128)));
			fRec49[0] = max((fRec49[1] * float(iVec12[0])), max(fVec11[0], fRec43[1]));
			int 	iTemp130 = (iRec42[1] == 3);
			int 	iTemp131 = (iRec42[1] == 6);
			int 	iTemp132 = (iRec42[1] == 0);
			float 	fTemp133 = (((iRec42[1] == 1)) ? min(1.0f, fTemp119) : ((iTemp132) ? 0.0f : ((iTemp131) ? (fTemp119 * fTemp129) : ((iTemp130) ? (fRec49[0] * fTemp129) : fVec11[0]))));
			float 	fTemp134 = (1.0f / ((iTemp132) ? 0.0001f : (((iTemp130 | iTemp131)) ? (0.04761905f * fTemp123) : fTemp123)));
			float 	fTemp135 = (fRec47[1] - fTemp134);
			float 	fTemp136 = (fRec47[1] + fTemp134);
			fRec47[0] = (((fTemp136 < fTemp133)) ? fTemp136 : (((fTemp135 > fTemp133)) ? fTemp135 : fTemp133));
			fRec43[0] = fRec47[0];
			fRec41[0] = (fRec43[0] - (fConst18 * ((fConst16 * fRec41[2]) + (fConst14 * fRec41[1]))));
			float 	fTemp137 = min(0.99f, (fConst25 * (((3947.8418f * fRec41[0]) + (7895.6836f * fRec41[1])) + (3947.8418f * fRec41[2]))));
			int 	iTemp138 = (fTemp137 < 0.1f);
			float 	fTemp139 = (((iTemp138) ? fTemp137 : 0.1f) * fSlow49);
			fRec50[0] = (fTemp41 - (fSlow61 * ((fSlow59 * fRec50[2]) + (fSlow56 * fRec50[1]))));
			float 	fTemp140 = min(1.0f, (fSlow62 + ((iTemp138) ? (1.0f - (1e+01f * fTemp137)) : 0.0f)));
			float 	fTemp141 = ((iTemp2) ? 0.0f : (fSlow64 + fRec52[1]));
			fRec52[0] = (fTemp141 - floorf(fTemp141));
			float 	fTemp142 = (499.0f * fRec52[0]);
			int 	iTemp143 = int(fTemp142);
			int 	iTemp144 = max(0, min(iTemp143, 499));
			float 	fTemp145 = ftbl1[iTemp144];
			int 	iTemp146 = max(0, min((iTemp143 + 1), 499));
			float 	fTemp147 = (fTemp142 - float(iTemp143));
			float 	fTemp148 = float((((fVec11[1] <= 0.003f) & iTemp116) != 1));
			fRec53[0] = max((fTemp148 * fRec53[1]), fSlow65);
			fRec54[0] = max((fRec54[1] * fTemp148), fSlow47);
			float 	fTemp149 = max(min(((0.5f * (fVec11[0] - fTemp137)) + (0.2f - (0.8f * ((iTemp117) ? (2.0f * (((fRec54[0] > fRec53[0])) ? fRec54[0] : (0.0f - fRec53[0]))) : fSlow48)))), 1.0f), 0.0f);
			float 	fTemp150 = ftbl0[iTemp144];
			float 	fTemp151 = (((fTemp150 + (fTemp147 * (ftbl0[iTemp146] - fTemp150))) * (1.0f - fTemp149)) + (fTemp149 * (fTemp145 + (fTemp147 * (ftbl1[iTemp146] - fTemp145)))));
			float 	fTemp152 = (fRec51[1] - fConst31);
			float 	fTemp153 = (fConst31 + fRec51[1]);
			fRec51[0] = (((fTemp153 < fTemp151)) ? fTemp153 : (((fTemp152 > fTemp151)) ? fTemp152 : fTemp151));
			float 	fTemp154 = ((iTemp2) ? 0.0f : (fSlow67 + fRec55[1]));
			fRec55[0] = (fTemp154 - floorf(fTemp154));
			float 	fTemp155 = (499.0f * fRec55[0]);
			int 	iTemp156 = int(fTemp155);
			float 	fTemp157 = ftbl0[max(0, min(iTemp156, 499))];
			float 	fTemp158 = ((iTemp2) ? 0.0f : (fSlow68 + fRec56[1]));
			fRec56[0] = (fTemp158 - floorf(fTemp158));
			float 	fTemp159 = (499.0f * fRec56[0]);
			int 	iTemp160 = int(fTemp159);
			float 	fTemp161 = ftbl1[max(0, min(iTemp160, 499))];
			fVec13[0] = fSlow73;
			int 	iTemp162 = (fSlow73 != fVec13[1]);
			iVec14[0] = iTemp162;
			int 	iTemp163 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp163)) + (iTemp14 * iTemp163));
			float 	fTemp164 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec60[0])))) > 0.5f) & iSlow74)) ? 0.0f : fSlow72) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp164;
			int 	iTemp165 = (fVec15[0] > 0.003f);
			int 	iTemp166 = (fVec15[0] <= 0.003f);
			float 	fTemp167 = float((iTemp166 | (fVec15[1] >= 0.003f)));
			fRec61[0] = max((fRec61[1] * fTemp167), fSlow73);
			fRec62[0] = max((fTemp167 * fRec62[1]), fSlow75);
			float 	fTemp168 = (min(1.0f, fRec62[0]) + min(1.0f, fRec61[0]));
			int 	iTemp169 = (fVec15[0] >= fRec59[1]);
			int 	iTemp170 = (fRec59[1] <= 0.001f);
			int 	iTemp171 = (((iRec58[1] >= 4)) ? (((iRec58[1] >= 6)) ? ((iTemp170) ? 0 : ((iTemp165) ? 1 : 6)) : (((iRec58[1] >= 5)) ? ((iTemp166) ? 3 : ((iTemp169) ? 4 : 5)) : ((iTemp166) ? 3 : (((fVec15[0] <= fRec59[1])) ? 5 : 4)))) : (((iRec58[1] >= 2)) ? (((iRec58[1] >= 3)) ? (((iTemp166 & iTemp170)) ? 0 : ((iTemp165) ? 1 : 3)) : ((iTemp165) ? ((iTemp169) ? 4 : 2) : 6)) : (((iRec58[1] >= 1)) ? (((fRec59[1] >= min(fTemp168, 1.0f))) ? ((iTemp166) ? 6 : 2) : 1) : ((iTemp165) ? 1 : 0))));
			iRec58[0] = iTemp171;
			float 	fTemp172 = (((iTemp171 >= 4)) ? (((iTemp171 >= 6)) ? fConst24 : fConst23) : (((iTemp171 >= 2)) ? (((iTemp171 >= 3)) ? fConst22 : fConst21) : (((iTemp171 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp173 = (iRec58[1] != iRec58[2]);
			iVec16[0] = iTemp173;
			int 	iTemp174 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec64[0] = ((iRec64[1] * (1 - iTemp174)) + (iTemp14 * iTemp174));
			float 	fTemp175 = (2e+01f * (((fTemp172 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec64[0]))) / fTemp172) : 0.0f));
			int 	iTemp176 = int(fTemp175);
			float 	fTemp177 = ftbl3[max(0, int(min(int(iTemp176), 20)))];
			float 	fTemp178 = (fTemp177 + ((fTemp175 - float(iTemp176)) * (ftbl3[max(0, int(min(int((iTemp176 + 1)), 20)))] - fTemp177)));
			fRec65[0] = max((fRec65[1] * float(iVec16[0])), max(fVec15[0], fRec59[1]));
			int 	iTemp179 = (iRec58[1] == 3);
			int 	iTemp180 = (iRec58[1] == 6);
			int 	iTemp181 = (iRec58[1] == 0);
			float 	fTemp182 = (((iRec58[1] == 1)) ? min(1.0f, fTemp168) : ((iTemp181) ? 0.0f : ((iTemp180) ? (fTemp168 * fTemp178) : ((iTemp179) ? (fRec65[0] * fTemp178) : fVec15[0]))));
			float 	fTemp183 = (1.0f / ((iTemp181) ? 0.0001f : (((iTemp179 | iTemp180)) ? (0.04761905f * fTemp172) : fTemp172)));
			float 	fTemp184 = (fRec63[1] - fTemp183);
			float 	fTemp185 = (fRec63[1] + fTemp183);
			fRec63[0] = (((fTemp185 < fTemp182)) ? fTemp185 : (((fTemp184 > fTemp182)) ? fTemp184 : fTemp182));
			fRec59[0] = fRec63[0];
			fRec57[0] = (fRec59[0] - (fConst18 * ((fConst16 * fRec57[2]) + (fConst14 * fRec57[1]))));
			float 	fTemp186 = min(0.99f, (fConst25 * (((3947.8418f * fRec57[0]) + (7895.6836f * fRec57[1])) + (3947.8418f * fRec57[2]))));
			int 	iTemp187 = (fTemp186 < 0.1f);
			float 	fTemp188 = (((iTemp187) ? fTemp186 : 0.1f) * fSlow71);
			fRec66[0] = (fTemp41 - (fSlow83 * ((fSlow81 * fRec66[2]) + (fSlow78 * fRec66[1]))));
			float 	fTemp189 = min(1.0f, (fSlow84 + ((iTemp187) ? (1.0f - (1e+01f * fTemp186)) : 0.0f)));
			float 	fTemp190 = ((iTemp2) ? 0.0f : (fSlow86 + fRec68[1]));
			fRec68[0] = (fTemp190 - floorf(fTemp190));
			float 	fTemp191 = (499.0f * fRec68[0]);
			int 	iTemp192 = int(fTemp191);
			int 	iTemp193 = max(0, min(iTemp192, 499));
			float 	fTemp194 = ftbl1[iTemp193];
			int 	iTemp195 = max(0, min((iTemp192 + 1), 499));
			float 	fTemp196 = (fTemp191 - float(iTemp192));
			float 	fTemp197 = float((((fVec15[1] <= 0.003f) & iTemp165) != 1));
			fRec69[0] = max((fTemp197 * fRec69[1]), fSlow87);
			fRec70[0] = max((fRec70[1] * fTemp197), fSlow69);
			float 	fTemp198 = max(min(((0.5f * (fVec15[0] - fTemp186)) + (0.2f - (0.8f * ((iTemp166) ? (2.0f * (((fRec70[0] > fRec69[0])) ? fRec70[0] : (0.0f - fRec69[0]))) : fSlow70)))), 1.0f), 0.0f);
			float 	fTemp199 = ftbl0[iTemp193];
			float 	fTemp200 = (((fTemp199 + (fTemp196 * (ftbl0[iTemp195] - fTemp199))) * (1.0f - fTemp198)) + (fTemp198 * (fTemp194 + (fTemp196 * (ftbl1[iTemp195] - fTemp194)))));
			float 	fTemp201 = (fRec67[1] - fConst31);
			float 	fTemp202 = (fConst31 + fRec67[1]);
			fRec67[0] = (((fTemp202 < fTemp200)) ? fTemp202 : (((fTemp201 > fTemp200)) ? fTemp201 : fTemp200));
			float 	fTemp203 = ((iTemp2) ? 0.0f : (fSlow89 + fRec71[1]));
			fRec71[0] = (fTemp203 - floorf(fTemp203));
			float 	fTemp204 = (499.0f * fRec71[0]);
			int 	iTemp205 = int(fTemp204);
			float 	fTemp206 = ftbl0[max(0, min(iTemp205, 499))];
			float 	fTemp207 = ((iTemp2) ? 0.0f : (fSlow90 + fRec72[1]));
			fRec72[0] = (fTemp207 - floorf(fTemp207));
			float 	fTemp208 = (499.0f * fRec72[0]);
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl1[max(0, min(iTemp209, 499))];
			fVec17[0] = fSlow95;
			int 	iTemp211 = (fSlow95 != fVec17[1]);
			iVec18[0] = iTemp211;
			int 	iTemp212 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec76[0] = ((iRec76[1] * (1 - iTemp212)) + (iTemp14 * iTemp212));
			float 	fTemp213 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec76[0])))) > 0.5f) & iSlow96)) ? 0.0f : fSlow94) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp213;
			int 	iTemp214 = (fVec19[0] > 0.003f);
			int 	iTemp215 = (fVec19[0] <= 0.003f);
			float 	fTemp216 = float((iTemp215 | (fVec19[1] >= 0.003f)));
			fRec77[0] = max((fRec77[1] * fTemp216), fSlow95);
			fRec78[0] = max((fTemp216 * fRec78[1]), fSlow97);
			float 	fTemp217 = (min(1.0f, fRec78[0]) + min(1.0f, fRec77[0]));
			int 	iTemp218 = (fVec19[0] >= fRec75[1]);
			int 	iTemp219 = (fRec75[1] <= 0.001f);
			int 	iTemp220 = (((iRec74[1] >= 4)) ? (((iRec74[1] >= 6)) ? ((iTemp219) ? 0 : ((iTemp214) ? 1 : 6)) : (((iRec74[1] >= 5)) ? ((iTemp215) ? 3 : ((iTemp218) ? 4 : 5)) : ((iTemp215) ? 3 : (((fVec19[0] <= fRec75[1])) ? 5 : 4)))) : (((iRec74[1] >= 2)) ? (((iRec74[1] >= 3)) ? (((iTemp215 & iTemp219)) ? 0 : ((iTemp214) ? 1 : 3)) : ((iTemp214) ? ((iTemp218) ? 4 : 2) : 6)) : (((iRec74[1] >= 1)) ? (((fRec75[1] >= min(fTemp217, 1.0f))) ? ((iTemp215) ? 6 : 2) : 1) : ((iTemp214) ? 1 : 0))));
			iRec74[0] = iTemp220;
			float 	fTemp221 = (((iTemp220 >= 4)) ? (((iTemp220 >= 6)) ? fConst24 : fConst23) : (((iTemp220 >= 2)) ? (((iTemp220 >= 3)) ? fConst22 : fConst21) : (((iTemp220 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp222 = (iRec74[1] != iRec74[2]);
			iVec20[0] = iTemp222;
			int 	iTemp223 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec80[0] = ((iRec80[1] * (1 - iTemp223)) + (iTemp14 * iTemp223));
			float 	fTemp224 = (2e+01f * (((fTemp221 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec80[0]))) / fTemp221) : 0.0f));
			int 	iTemp225 = int(fTemp224);
			float 	fTemp226 = ftbl3[max(0, int(min(int(iTemp225), 20)))];
			float 	fTemp227 = (fTemp226 + ((fTemp224 - float(iTemp225)) * (ftbl3[max(0, int(min(int((iTemp225 + 1)), 20)))] - fTemp226)));
			fRec81[0] = max((fRec81[1] * float(iVec20[0])), max(fVec19[0], fRec75[1]));
			int 	iTemp228 = (iRec74[1] == 3);
			int 	iTemp229 = (iRec74[1] == 6);
			int 	iTemp230 = (iRec74[1] == 0);
			float 	fTemp231 = (((iRec74[1] == 1)) ? min(1.0f, fTemp217) : ((iTemp230) ? 0.0f : ((iTemp229) ? (fTemp217 * fTemp227) : ((iTemp228) ? (fRec81[0] * fTemp227) : fVec19[0]))));
			float 	fTemp232 = (1.0f / ((iTemp230) ? 0.0001f : (((iTemp228 | iTemp229)) ? (0.04761905f * fTemp221) : fTemp221)));
			float 	fTemp233 = (fRec79[1] - fTemp232);
			float 	fTemp234 = (fRec79[1] + fTemp232);
			fRec79[0] = (((fTemp234 < fTemp231)) ? fTemp234 : (((fTemp233 > fTemp231)) ? fTemp233 : fTemp231));
			fRec75[0] = fRec79[0];
			fRec73[0] = (fRec75[0] - (fConst18 * ((fConst16 * fRec73[2]) + (fConst14 * fRec73[1]))));
			float 	fTemp235 = min(0.99f, (fConst25 * (((3947.8418f * fRec73[0]) + (7895.6836f * fRec73[1])) + (3947.8418f * fRec73[2]))));
			int 	iTemp236 = (fTemp235 < 0.1f);
			float 	fTemp237 = (((iTemp236) ? fTemp235 : 0.1f) * fSlow93);
			fRec82[0] = (fTemp41 - (fSlow105 * ((fSlow103 * fRec82[2]) + (fSlow100 * fRec82[1]))));
			float 	fTemp238 = min(1.0f, (fSlow106 + ((iTemp236) ? (1.0f - (1e+01f * fTemp235)) : 0.0f)));
			float 	fTemp239 = ((iTemp2) ? 0.0f : (fSlow108 + fRec84[1]));
			fRec84[0] = (fTemp239 - floorf(fTemp239));
			float 	fTemp240 = (499.0f * fRec84[0]);
			int 	iTemp241 = int(fTemp240);
			int 	iTemp242 = max(0, min(iTemp241, 499));
			float 	fTemp243 = ftbl1[iTemp242];
			int 	iTemp244 = max(0, min((iTemp241 + 1), 499));
			float 	fTemp245 = (fTemp240 - float(iTemp241));
			float 	fTemp246 = float((((fVec19[1] <= 0.003f) & iTemp214) != 1));
			fRec85[0] = max((fTemp246 * fRec85[1]), fSlow109);
			fRec86[0] = max((fRec86[1] * fTemp246), fSlow91);
			float 	fTemp247 = max(min(((0.5f * (fVec19[0] - fTemp235)) + (0.2f - (0.8f * ((iTemp215) ? (2.0f * (((fRec86[0] > fRec85[0])) ? fRec86[0] : (0.0f - fRec85[0]))) : fSlow92)))), 1.0f), 0.0f);
			float 	fTemp248 = ftbl0[iTemp242];
			float 	fTemp249 = (((fTemp248 + (fTemp245 * (ftbl0[iTemp244] - fTemp248))) * (1.0f - fTemp247)) + (fTemp247 * (fTemp243 + (fTemp245 * (ftbl1[iTemp244] - fTemp243)))));
			float 	fTemp250 = (fRec83[1] - fConst31);
			float 	fTemp251 = (fConst31 + fRec83[1]);
			fRec83[0] = (((fTemp251 < fTemp249)) ? fTemp251 : (((fTemp250 > fTemp249)) ? fTemp250 : fTemp249));
			float 	fTemp252 = ((iTemp2) ? 0.0f : (fSlow111 + fRec87[1]));
			fRec87[0] = (fTemp252 - floorf(fTemp252));
			float 	fTemp253 = (499.0f * fRec87[0]);
			int 	iTemp254 = int(fTemp253);
			float 	fTemp255 = ftbl0[max(0, min(iTemp254, 499))];
			float 	fTemp256 = ((iTemp2) ? 0.0f : (fSlow112 + fRec88[1]));
			fRec88[0] = (fTemp256 - floorf(fTemp256));
			float 	fTemp257 = (499.0f * fRec88[0]);
			int 	iTemp258 = int(fTemp257);
			float 	fTemp259 = ftbl1[max(0, min(iTemp258, 499))];
			fVec21[0] = fSlow117;
			int 	iTemp260 = (fSlow117 != fVec21[1]);
			iVec22[0] = iTemp260;
			int 	iTemp261 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec92[0] = ((iRec92[1] * (1 - iTemp261)) + (iTemp14 * iTemp261));
			float 	fTemp262 = ftbl2[int(((499.5f * ((((((fConst19 * float((iRec10[0] + (-1 - iRec92[0])))) > 0.5f) & iSlow118)) ? 0.0f : fSlow116) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp262;
			int 	iTemp263 = (fVec23[0] > 0.003f);
			int 	iTemp264 = (fVec23[0] <= 0.003f);
			float 	fTemp265 = float((iTemp264 | (fVec23[1] >= 0.003f)));
			fRec93[0] = max((fRec93[1] * fTemp265), fSlow117);
			fRec94[0] = max((fTemp265 * fRec94[1]), fSlow119);
			float 	fTemp266 = (min(1.0f, fRec94[0]) + min(1.0f, fRec93[0]));
			int 	iTemp267 = (fVec23[0] >= fRec91[1]);
			int 	iTemp268 = (fRec91[1] <= 0.001f);
			int 	iTemp269 = (((iRec90[1] >= 4)) ? (((iRec90[1] >= 6)) ? ((iTemp268) ? 0 : ((iTemp263) ? 1 : 6)) : (((iRec90[1] >= 5)) ? ((iTemp264) ? 3 : ((iTemp267) ? 4 : 5)) : ((iTemp264) ? 3 : (((fVec23[0] <= fRec91[1])) ? 5 : 4)))) : (((iRec90[1] >= 2)) ? (((iRec90[1] >= 3)) ? (((iTemp264 & iTemp268)) ? 0 : ((iTemp263) ? 1 : 3)) : ((iTemp263) ? ((iTemp267) ? 4 : 2) : 6)) : (((iRec90[1] >= 1)) ? (((fRec91[1] >= min(fTemp266, 1.0f))) ? ((iTemp264) ? 6 : 2) : 1) : ((iTemp263) ? 1 : 0))));
			iRec90[0] = iTemp269;
			float 	fTemp270 = (((iTemp269 >= 4)) ? (((iTemp269 >= 6)) ? fConst24 : fConst23) : (((iTemp269 >= 2)) ? (((iTemp269 >= 3)) ? fConst22 : fConst21) : (((iTemp269 >= 1)) ? fConst20 : 0.0f)));
			int 	iTemp271 = (iRec90[1] != iRec90[2]);
			iVec24[0] = iTemp271;
			int 	iTemp272 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp272)) + (iTemp14 * iTemp272));
			float 	fTemp273 = (2e+01f * (((fTemp270 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec96[0]))) / fTemp270) : 0.0f));
			int 	iTemp274 = int(fTemp273);
			float 	fTemp275 = ftbl3[max(0, int(min(int(iTemp274), 20)))];
			float 	fTemp276 = (fTemp275 + ((fTemp273 - float(iTemp274)) * (ftbl3[max(0, int(min(int((iTemp274 + 1)), 20)))] - fTemp275)));
			fRec97[0] = max((fRec97[1] * float(iVec24[0])), max(fVec23[0], fRec91[1]));
			int 	iTemp277 = (iRec90[1] == 3);
			int 	iTemp278 = (iRec90[1] == 6);
			int 	iTemp279 = (iRec90[1] == 0);
			float 	fTemp280 = (((iRec90[1] == 1)) ? min(1.0f, fTemp266) : ((iTemp279) ? 0.0f : ((iTemp278) ? (fTemp266 * fTemp276) : ((iTemp277) ? (fRec97[0] * fTemp276) : fVec23[0]))));
			float 	fTemp281 = (1.0f / ((iTemp279) ? 0.0001f : (((iTemp277 | iTemp278)) ? (0.04761905f * fTemp270) : fTemp270)));
			float 	fTemp282 = (fRec95[1] - fTemp281);
			float 	fTemp283 = (fRec95[1] + fTemp281);
			fRec95[0] = (((fTemp283 < fTemp280)) ? fTemp283 : (((fTemp282 > fTemp280)) ? fTemp282 : fTemp280));
			fRec91[0] = fRec95[0];
			fRec89[0] = (fRec91[0] - (fConst18 * ((fConst16 * fRec89[2]) + (fConst14 * fRec89[1]))));
			float 	fTemp284 = min(0.99f, (fConst25 * (((3947.8418f * fRec89[0]) + (7895.6836f * fRec89[1])) + (3947.8418f * fRec89[2]))));
			int 	iTemp285 = (fTemp284 < 0.1f);
			float 	fTemp286 = (((iTemp285) ? fTemp284 : 0.1f) * fSlow115);
			fRec98[0] = (fTemp41 - (fSlow127 * ((fSlow125 * fRec98[2]) + (fSlow122 * fRec98[1]))));
			float 	fTemp287 = min(1.0f, (fSlow128 + ((iTemp285) ? (1.0f - (1e+01f * fTemp284)) : 0.0f)));
			float 	fTemp288 = ((iTemp2) ? 0.0f : (fSlow130 + fRec100[1]));
			fRec100[0] = (fTemp288 - floorf(fTemp288));
			float 	fTemp289 = (499.0f * fRec100[0]);
			int 	iTemp290 = int(fTemp289);
			int 	iTemp291 = max(0, min(iTemp290, 499));
			float 	fTemp292 = ftbl1[iTemp291];
			int 	iTemp293 = max(0, min((iTemp290 + 1), 499));
			float 	fTemp294 = (fTemp289 - float(iTemp290));
			float 	fTemp295 = float((((fVec23[1] <= 0.003f) & iTemp263) != 1));
			fRec101[0] = max((fTemp295 * fRec101[1]), fSlow131);
			fRec102[0] = max((fRec102[1] * fTemp295), fSlow113);
			float 	fTemp296 = max(min(((0.5f * (fVec23[0] - fTemp284)) + (0.2f - (0.8f * ((iTemp264) ? (2.0f * (((fRec102[0] > fRec101[0])) ? fRec102[0] : (0.0f - fRec101[0]))) : fSlow114)))), 1.0f), 0.0f);
			float 	fTemp297 = ftbl0[iTemp291];
			float 	fTemp298 = (((fTemp297 + (fTemp294 * (ftbl0[iTemp293] - fTemp297))) * (1.0f - fTemp296)) + (fTemp296 * (fTemp292 + (fTemp294 * (ftbl1[iTemp293] - fTemp292)))));
			float 	fTemp299 = (fRec99[1] - fConst31);
			float 	fTemp300 = (fConst31 + fRec99[1]);
			fRec99[0] = (((fTemp300 < fTemp298)) ? fTemp300 : (((fTemp299 > fTemp298)) ? fTemp299 : fTemp298));
			fRec0[0] = ((1.37f * ((((((fTemp284 * ((((1.1f * (fRec99[0] * (1.0f - fTemp287))) + (fSlow129 * (fTemp287 * (fRec98[0] - fRec98[2])))) * (1.0f - (0.5f * fTemp286))) + (0.5f * (fTemp286 * ((0.2f * (fTemp259 + ((fTemp257 - float(iTemp258)) * (ftbl1[max(0, min((iTemp258 + 1), 499))] - fTemp259)))) + (0.8f * (fTemp255 + ((fTemp253 - float(iTemp254)) * (ftbl0[max(0, min((iTemp254 + 1), 499))] - fTemp255))))))))) + (fTemp235 * ((((1.1f * (fRec83[0] * (1.0f - fTemp238))) + (fSlow107 * (fTemp238 * (fRec82[0] - fRec82[2])))) * (1.0f - (0.5f * fTemp237))) + (0.5f * (fTemp237 * ((0.2f * (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl1[max(0, min((iTemp209 + 1), 499))] - fTemp210)))) + (0.8f * (fTemp206 + ((fTemp204 - float(iTemp205)) * (ftbl0[max(0, min((iTemp205 + 1), 499))] - fTemp206)))))))))) + (fTemp186 * ((((1.1f * (fRec67[0] * (1.0f - fTemp189))) + (fSlow85 * (fTemp189 * (fRec66[0] - fRec66[2])))) * (1.0f - (0.5f * fTemp188))) + (0.5f * (fTemp188 * ((0.2f * (fTemp161 + ((fTemp159 - float(iTemp160)) * (ftbl1[max(0, min((iTemp160 + 1), 499))] - fTemp161)))) + (0.8f * (fTemp157 + ((fTemp155 - float(iTemp156)) * (ftbl0[max(0, min((iTemp156 + 1), 499))] - fTemp157)))))))))) + (fTemp137 * ((((1.1f * (fRec51[0] * (1.0f - fTemp140))) + (fSlow63 * (fTemp140 * (fRec50[0] - fRec50[2])))) * (1.0f - (0.5f * fTemp139))) + (0.5f * (fTemp139 * ((0.2f * (fTemp112 + ((fTemp110 - float(iTemp111)) * (ftbl1[max(0, min((iTemp111 + 1), 499))] - fTemp112)))) + (0.8f * (fTemp108 + ((fTemp106 - float(iTemp107)) * (ftbl0[max(0, min((iTemp107 + 1), 499))] - fTemp108)))))))))) + (fTemp88 * ((((1.1f * (fRec35[0] * (1.0f - fTemp91))) + (fSlow41 * (fTemp91 * (fRec34[0] - fRec34[2])))) * (1.0f - (0.5f * fTemp90))) + (0.5f * (fTemp90 * ((0.2f * (fTemp63 + ((fTemp61 - float(iTemp62)) * (ftbl1[max(0, min((iTemp62 + 1), 499))] - fTemp63)))) + (0.8f * (fTemp59 + ((fTemp57 - float(iTemp58)) * (ftbl0[max(0, min((iTemp58 + 1), 499))] - fTemp59)))))))))) + (fTemp38 * ((((1.1f * (fRec19[0] * (1.0f - fTemp42))) + (fSlow19 * (fTemp42 * (fRec17[0] - fRec17[2])))) * (1.0f - (0.5f * fTemp40))) + (0.5f * (fTemp40 * ((0.2f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl1[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.8f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6))))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst32 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec99[1] = fRec99[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[2] = fRec98[1]; fRec98[1] = fRec98[0];
			fRec89[2] = fRec89[1]; fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			iRec96[1] = iRec96[0];
			iVec24[1] = iVec24[0];
			iRec90[2] = iRec90[1]; iRec90[1] = iRec90[0];
			fRec94[1] = fRec94[0];
			fRec93[1] = fRec93[0];
			fVec23[1] = fVec23[0];
			iRec92[1] = iRec92[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fRec83[1] = fRec83[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec82[2] = fRec82[1]; fRec82[1] = fRec82[0];
			fRec73[2] = fRec73[1]; fRec73[1] = fRec73[0];
			fRec75[1] = fRec75[0];
			fRec79[1] = fRec79[0];
			fRec81[1] = fRec81[0];
			iRec80[1] = iRec80[0];
			iVec20[1] = iVec20[0];
			iRec74[2] = iRec74[1]; iRec74[1] = iRec74[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fVec19[1] = fVec19[0];
			iRec76[1] = iRec76[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fRec67[1] = fRec67[0];
			fRec70[1] = fRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec57[2] = fRec57[1]; fRec57[1] = fRec57[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec65[1] = fRec65[0];
			iRec64[1] = iRec64[0];
			iVec16[1] = iVec16[0];
			iRec58[2] = iRec58[1]; iRec58[1] = iRec58[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			fVec15[1] = fVec15[0];
			iRec60[1] = iRec60[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec51[1] = fRec51[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec41[2] = fRec41[1]; fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			iRec48[1] = iRec48[0];
			iVec12[1] = iVec12[0];
			iRec42[2] = iRec42[1]; iRec42[1] = iRec42[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fVec11[1] = fVec11[0];
			iRec44[1] = iRec44[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fRec35[1] = fRec35[0];
			fRec38[1] = fRec38[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
			fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
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
			fRec19[1] = fRec19[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
			iVec4[1] = iVec4[0];
			iRec7[2] = iRec7[1]; iRec7[1] = iRec7[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fVec3[1] = fVec3[0];
			iRec9[1] = iRec9[0];
			iRec10[1] = iRec10[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec4[1] = fRec4[0];
			fRec2[1] = fRec2[0];
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
