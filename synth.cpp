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
				float 	fTemp16 = ((0.002002002f * float((iRec11[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp16)) + -1.0f))) * float(((fTemp16 > 0.0f) - (fTemp16 < 0.0f))));
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
				int 	iTemp29 = int((1.05f * float((iRec21[0] + -1))));
				output[i] = (((iTemp29 >= 11)) ? (((iTemp29 >= 16)) ? (((iTemp29 >= 19)) ? (((iTemp29 >= 20)) ? 0.0f : 0.01f) : (((iTemp29 >= 18)) ? 0.03f : (((iTemp29 >= 17)) ? 0.06f : 0.08f))) : (((iTemp29 >= 14)) ? (((iTemp29 >= 15)) ? 0.1f : 0.12f) : (((iTemp29 >= 13)) ? 0.14f : (((iTemp29 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp29 >= 6)) ? (((iTemp29 >= 9)) ? (((iTemp29 >= 10)) ? 0.22f : 0.26f) : (((iTemp29 >= 8)) ? 0.3f : (((iTemp29 >= 7)) ? 0.35f : 0.4f))) : (((iTemp29 >= 3)) ? (((iTemp29 >= 5)) ? 0.47f : (((iTemp29 >= 4)) ? 0.55f : 0.64f)) : (((iTemp29 >= 2)) ? 0.74f : (((iTemp29 >= 1)) ? 0.86f : 1.0f)))));
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
				float 	fTemp57 = float((iRec31[0] + -1));
				float 	fTemp58 = (0.002004008f * fTemp57);
				output[i] = (((fTemp58 < 0.5f)) ? ((0.008016032f * fTemp57) + -1.0f) : ((4.0f * (1.0f - fTemp58)) + -1.0f));
				// post processing
				iRec31[1] = iRec31[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst1;
	FAUSTFLOAT 	fslider0;
	int 	iRec0[2];
	float 	fRec1[2];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec2[2];
	float 	fConst2;
	float 	fConst3;
	float 	fConst4;
	float 	fConst5;
	int 	iRec4[2];
	float 	fConst6;
	float 	fRec5[2];
	float 	fRec3[3];
	float 	fConst7;
	int 	iRec8[2];
	float 	fRec9[2];
	float 	fConst8;
	float 	fRec7[2];
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	static float 	ftbl0[1000];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	float 	fRec12[3];
	float 	fConst20;
	float 	fConst22;
	float 	fConst24;
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
	float 	fConst25;
	float 	fConst26;
	int 	iVec6[2];
	int 	iRec22[2];
	int 	iRec23[2];
	float 	fRec24[2];
	float 	fRec25[2];
	float 	fRec20[2];
	float 	fRec15[2];
	float 	fRec13[3];
	float 	fConst27;
	static float 	ftbl2[500];
	float 	fConst28;
	float 	fRec28[2];
	float 	fRec29[2];
	float 	fRec30[2];
	static float 	ftbl3[500];
	float 	fConst29;
	float 	fRec26[2];
	float 	fConst30;
	float 	fRec32[2];
	float 	fConst31;
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
	float 	fRec10[3];
	float 	fConst32;
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
		fConst1 = (0.1f * fConst0);
		fConst2 = max(1.0f, (0.02f * fConst0));
		fConst3 = (1.0f / fConst2);
		fConst4 = (0.2f * fConst0);
		fConst5 = (1.0f / max(1.0f, fConst4));
		fConst6 = (1.0f / fConst0);
		fConst7 = (0.3f * fConst0);
		fConst8 = (1e+02f / fConst0);
		float 	fConst9 = powf(fConst0,2.0f);
		float 	fConst10 = powf((251.32741f / fConst0),2.0f);
		float 	fConst11 = ((fConst10 * ((0.2033f * fConst10) + 0.31755f)) + 1.0f);
		fConst12 = (2.0f * ((63165.47f * (powf(fConst11,2.0f) / fConst9)) + -1.0f));
		float 	fConst13 = (63165.47f * (fConst11 / fConst0));
		fConst14 = (((fConst11 * (fConst13 + -191.85298f)) / fConst0) + 1.0f);
		float 	fConst15 = (((fConst11 * (fConst13 + 191.85298f)) / fConst0) + 1.0f);
		fConst16 = (1.0f / fConst15);
		float 	fConst17 = powf((62.831852f / fConst0),2.0f);
		float 	fConst18 = ((fConst17 * ((0.2033f * fConst17) + 0.31755f)) + 1.0f);
		float 	fConst19 = powf(fConst18,2.0f);
		fConst20 = (2.0f * ((3947.8418f * (fConst19 / fConst9)) + -1.0f));
		float 	fConst21 = (3947.8418f * (fConst18 / fConst0));
		fConst22 = (((fConst18 * (fConst21 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst23 = (((fConst18 * (fConst21 + 88.49557f)) / fConst0) + 1.0f);
		fConst24 = (1.0f / fConst23);
		fConst25 = (0.4f * fConst0);
		fConst26 = (0.15f * fConst0);
		fConst27 = (fConst19 / (fConst9 * fConst23));
		fConst28 = (8.175799f / fConst0);
		fConst29 = (3333.3333f / fConst0);
		fConst30 = (4.0878997f / fConst0);
		fConst31 = (2.0439498f / fConst0);
		fConst32 = (0.0f - (2.0f / fConst15));
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
		for (int i=0; i<2; i++) iRec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<2; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) iRec8[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
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
		for (int i=0; i<3; i++) fRec10[i] = 0;
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
		float 	fSlow21 = (fConst28 * fSlow6);
		float 	fSlow22 = (0.0f - fSlow3);
		float 	fSlow23 = (fConst30 * fSlow6);
		float 	fSlow24 = (fConst31 * fSlow6);
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
		float 	fSlow43 = (fConst28 * fSlow28);
		float 	fSlow44 = (0.0f - fSlow25);
		float 	fSlow45 = (fConst30 * fSlow28);
		float 	fSlow46 = (fConst31 * fSlow28);
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
		float 	fSlow65 = (fConst28 * fSlow50);
		float 	fSlow66 = (0.0f - fSlow47);
		float 	fSlow67 = (fConst30 * fSlow50);
		float 	fSlow68 = (fConst31 * fSlow50);
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
		float 	fSlow87 = (fConst28 * fSlow72);
		float 	fSlow88 = (0.0f - fSlow69);
		float 	fSlow89 = (fConst30 * fSlow72);
		float 	fSlow90 = (fConst31 * fSlow72);
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
		float 	fSlow109 = (fConst28 * fSlow94);
		float 	fSlow110 = (0.0f - fSlow91);
		float 	fSlow111 = (fConst30 * fSlow94);
		float 	fSlow112 = (fConst31 * fSlow94);
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
		float 	fSlow131 = (fConst28 * fSlow116);
		float 	fSlow132 = (0.0f - fSlow113);
		float 	fSlow133 = (fConst30 * fSlow116);
		float 	fSlow134 = (fConst31 * fSlow116);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp0 = ((fSlow0 >= fRec1[1]) | (float(iRec0[1]) >= fConst1));
			iRec0[0] = ((iTemp0) ? 0 : (iRec0[1] + 1));
			fRec1[0] = ((iTemp0) ? fSlow0 : fRec1[1]);
			float 	fTemp1 = ((5e+02f * fRec1[0]) + 6e+01f);
			float 	fTemp2 = (4.162331e-09f * fTemp1);
			float 	fTemp3 = ((fTemp1 * (fTemp2 + 1.6129032e-06f)) + 1.0f);
			fVec1[0] = fSlow2;
			float 	fTemp4 = (fSlow2 - fVec1[1]);
			int 	iTemp5 = ((fTemp4 > 0.04f) & iSlow1);
			iVec2[0] = iTemp5;
			iRec2[0] = (((iRec2[1] + (iRec2[1] > 0)) * (iVec2[0] <= iVec2[1])) + (iVec2[0] > iVec2[1]));
			float 	fTemp6 = float(iRec2[0]);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float 	fTemp7 = float(iRec4[0]);
			float 	fTemp8 = max(1.1920929e-07f, fabsf(fTemp1));
			float 	fTemp9 = (fRec5[1] + (fConst6 * fTemp8));
			float 	fTemp10 = (fTemp9 + -1.0f);
			int 	iTemp11 = (fTemp10 < 0.0f);
			fRec5[0] = ((iTemp11) ? fTemp9 : fTemp10);
			float 	fRec6 = ((iTemp11) ? fTemp9 : (fTemp9 + (fTemp10 * (1.0f - (fConst0 / fTemp8)))));
			fRec3[0] = (((0.8f * ((2.0f * fRec6) + -1.0f)) + (9.313226e-11f * fTemp7)) - (((((fTemp1 * (fTemp2 + -1.6129032e-06f)) + 1.0f) * fRec3[2]) + (2.0f * (((4.162331e-09f * powf(fTemp1,2.0f)) + -1.0f) * fRec3[1]))) / fTemp3));
			float 	fTemp12 = fabsf(fTemp4);
			int 	iTemp13 = ((fTemp12 >= fRec9[1]) | (float(iRec8[1]) >= fConst7));
			iRec8[0] = ((iTemp13) ? 0 : (iRec8[1] + 1));
			fRec9[0] = ((iTemp13) ? fTemp12 : fRec9[1]);
			float 	fTemp14 = (fRec7[1] - fConst8);
			float 	fTemp15 = (fConst8 + fRec7[1]);
			fRec7[0] = (((fTemp15 < fRec9[0])) ? fTemp15 : (((fTemp14 > fRec9[0])) ? fTemp14 : fRec9[0]));
			float 	fTemp17 = (4.656613e-10f * fTemp7);
			fRec12[0] = (fTemp17 - (fSlow13 * ((fSlow11 * fRec12[2]) + (fSlow9 * fRec12[1]))));
			fVec3[0] = fSlow15;
			int 	iTemp18 = (fSlow17 != (0.9f * fVec3[1]));
			iVec4[0] = iTemp18;
			int 	iTemp19 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec17[0] = (iRec17[1] + 1);
			int 	iTemp20 = (iRec17[0] + -1);
			iRec16[0] = ((iRec16[1] * (1 - iTemp19)) + (iTemp20 * iTemp19));
			float 	fTemp21 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec16[0])))) > 0.5f) & iSlow16)) ? 0.0f : fSlow14) + 1.0f)) + 0.5f))];
			fVec5[0] = fTemp21;
			int 	iTemp22 = (fVec5[0] > 0.003f);
			int 	iTemp23 = (fVec5[0] <= 0.003f);
			float 	fTemp24 = float((iTemp23 | (fVec5[1] >= 0.003f)));
			fRec18[0] = max((fRec18[1] * fTemp24), fSlow17);
			fRec19[0] = max((fTemp24 * fRec19[1]), fSlow18);
			float 	fTemp25 = (min(1.0f, fRec19[0]) + min(1.0f, fRec18[0]));
			int 	iTemp26 = (fVec5[0] >= fRec15[1]);
			int 	iTemp27 = (fRec15[1] <= 0.001f);
			int 	iTemp28 = (((iRec14[1] >= 4)) ? (((iRec14[1] >= 6)) ? ((iTemp27) ? 0 : ((iTemp22) ? 1 : 6)) : (((iRec14[1] >= 5)) ? ((iTemp23) ? 3 : ((iTemp26) ? 4 : 5)) : ((iTemp23) ? 3 : (((fVec5[0] <= fRec15[1])) ? 5 : 4)))) : (((iRec14[1] >= 2)) ? (((iRec14[1] >= 3)) ? (((iTemp23 & iTemp27)) ? 0 : ((iTemp22) ? 1 : 3)) : ((iTemp23) ? 6 : ((iTemp26) ? 4 : 2))) : (((iRec14[1] >= 1)) ? (((fRec15[1] >= min(fTemp25, 1.0f))) ? ((iTemp23) ? 6 : 2) : 1) : ((iTemp22) ? 1 : 0))));
			iRec14[0] = iTemp28;
			float 	fTemp30 = (((iTemp28 >= 4)) ? (((iTemp28 >= 6)) ? fConst0 : fConst4) : (((iTemp28 >= 2)) ? (((iTemp28 >= 3)) ? fConst26 : fConst25) : (((iTemp28 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp31 = (iRec14[1] != iRec14[2]);
			iVec6[0] = iTemp31;
			int 	iTemp32 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec22[0] = ((iRec22[1] * (1 - iTemp32)) + (iTemp20 * iTemp32));
			float 	fTemp33 = (2e+01f * (((fTemp30 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec22[0]))) / fTemp30) : 0.0f));
			int 	iTemp34 = int(fTemp33);
			float 	fTemp35 = ftbl1[max(0, int(min(int(iTemp34), 20)))];
			float 	fTemp36 = (fTemp35 + ((fTemp33 - float(iTemp34)) * (ftbl1[max(0, int(min(int((iTemp34 + 1)), 20)))] - fTemp35)));
			iRec23[0] = iRec14[1];
			int 	iTemp37 = (iRec23[1] == iRec14[1]);
			int 	iTemp38 = (iRec14[1] == 0);
			fRec24[0] = ((iTemp38) ? fVec5[0] : ((iTemp37) ? min(min(fRec24[1], fVec5[0]), fRec15[1]) : min(fVec5[0], fRec15[1])));
			fRec25[0] = ((iTemp38) ? fVec5[0] : ((iTemp37) ? max(max(fRec25[1], fVec5[0]), fRec15[1]) : max(fVec5[0], fRec15[1])));
			int 	iTemp39 = (iRec14[1] == 3);
			int 	iTemp40 = (iRec14[1] == 6);
			float 	fTemp41 = (((iRec14[1] == 1)) ? min(1.0f, fTemp25) : ((iTemp38) ? 0.0f : ((iTemp40) ? (fTemp25 * fTemp36) : ((iTemp39) ? (fRec25[0] * fTemp36) : fVec5[0]))));
			float 	fTemp42 = (1.0f / ((iTemp38) ? 0.0001f : (((iTemp39 | iTemp40)) ? (0.04761905f * fTemp30) : fTemp30)));
			float 	fTemp43 = (fRec20[1] - fTemp42);
			float 	fTemp44 = (fRec20[1] + fTemp42);
			fRec20[0] = (((fTemp44 < fTemp41)) ? fTemp44 : (((fTemp43 > fTemp41)) ? fTemp43 : fTemp41));
			fRec15[0] = fRec20[0];
			fRec13[0] = (fRec15[0] - (fConst24 * ((fConst22 * fRec13[2]) + (fConst20 * fRec13[1]))));
			float 	fTemp45 = min(0.99f, (fConst27 * (((3947.8418f * fRec13[0]) + (7895.6836f * fRec13[1])) + (3947.8418f * fRec13[2]))));
			float 	fTemp46 = min(1.0f, (fSlow19 + (((fTemp45 < 0.1f)) ? (1.0f - (1e+01f * fTemp45)) : 0.0f)));
			int 	iTemp47 = (1 - iVec0[1]);
			float 	fTemp48 = ((iTemp47) ? 0.0f : (fSlow21 + fRec28[1]));
			fRec28[0] = (fTemp48 - floorf(fTemp48));
			float 	fTemp49 = (499.0f * fRec28[0]);
			int 	iTemp50 = int(fTemp49);
			int 	iTemp51 = max(0, min(iTemp50, 499));
			float 	fTemp52 = ftbl2[iTemp51];
			int 	iTemp53 = max(0, min((iTemp50 + 1), 499));
			float 	fTemp54 = (fTemp49 - float(iTemp50));
			float 	fTemp55 = float((((fVec5[1] <= 0.003f) & iTemp22) != 1));
			fRec29[0] = max((fTemp55 * fRec29[1]), fSlow22);
			fRec30[0] = max((fRec30[1] * fTemp55), fSlow3);
			float 	fTemp56 = max(min(((0.5f * (fVec5[0] - fTemp45)) + (0.2f - (0.8f * ((iTemp23) ? (2.0f * (((fRec30[0] > fRec29[0])) ? fRec30[0] : (0.0f - fRec29[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp59 = ftbl3[iTemp51];
			float 	fTemp60 = (((fTemp59 + (fTemp54 * (ftbl3[iTemp53] - fTemp59))) * (1.0f - fTemp56)) + (fTemp56 * (fTemp52 + (fTemp54 * (ftbl2[iTemp53] - fTemp52)))));
			float 	fTemp61 = (fRec26[1] - fConst29);
			float 	fTemp62 = (fConst29 + fRec26[1]);
			fRec26[0] = (((fTemp62 < fTemp60)) ? fTemp62 : (((fTemp61 > fTemp60)) ? fTemp61 : fTemp60));
			float 	fTemp63 = ((iTemp47) ? 0.0f : (fSlow23 + fRec32[1]));
			fRec32[0] = (fTemp63 - floorf(fTemp63));
			float 	fTemp64 = (499.0f * fRec32[0]);
			int 	iTemp65 = int(fTemp64);
			float 	fTemp66 = ftbl3[max(0, min(iTemp65, 499))];
			float 	fTemp67 = ((iTemp47) ? 0.0f : (fSlow24 + fRec33[1]));
			fRec33[0] = (fTemp67 - floorf(fTemp67));
			float 	fTemp68 = (499.0f * fRec33[0]);
			int 	iTemp69 = int(fTemp68);
			float 	fTemp70 = ftbl2[max(0, min(iTemp69, 499))];
			fRec34[0] = (fTemp17 - (fSlow35 * ((fSlow33 * fRec34[2]) + (fSlow31 * fRec34[1]))));
			fVec7[0] = fSlow37;
			int 	iTemp71 = (fSlow39 != (0.9f * fVec7[1]));
			iVec8[0] = iTemp71;
			int 	iTemp72 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec38[0] = ((iRec38[1] * (1 - iTemp72)) + (iTemp20 * iTemp72));
			float 	fTemp73 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec38[0])))) > 0.5f) & iSlow38)) ? 0.0f : fSlow36) + 1.0f)) + 0.5f))];
			fVec9[0] = fTemp73;
			int 	iTemp74 = (fVec9[0] > 0.003f);
			int 	iTemp75 = (fVec9[0] <= 0.003f);
			float 	fTemp76 = float((iTemp75 | (fVec9[1] >= 0.003f)));
			fRec39[0] = max((fRec39[1] * fTemp76), fSlow39);
			fRec40[0] = max((fTemp76 * fRec40[1]), fSlow40);
			float 	fTemp77 = (min(1.0f, fRec40[0]) + min(1.0f, fRec39[0]));
			int 	iTemp78 = (fVec9[0] >= fRec37[1]);
			int 	iTemp79 = (fRec37[1] <= 0.001f);
			int 	iTemp80 = (((iRec36[1] >= 4)) ? (((iRec36[1] >= 6)) ? ((iTemp79) ? 0 : ((iTemp74) ? 1 : 6)) : (((iRec36[1] >= 5)) ? ((iTemp75) ? 3 : ((iTemp78) ? 4 : 5)) : ((iTemp75) ? 3 : (((fVec9[0] <= fRec37[1])) ? 5 : 4)))) : (((iRec36[1] >= 2)) ? (((iRec36[1] >= 3)) ? (((iTemp75 & iTemp79)) ? 0 : ((iTemp74) ? 1 : 3)) : ((iTemp75) ? 6 : ((iTemp78) ? 4 : 2))) : (((iRec36[1] >= 1)) ? (((fRec37[1] >= min(fTemp77, 1.0f))) ? ((iTemp75) ? 6 : 2) : 1) : ((iTemp74) ? 1 : 0))));
			iRec36[0] = iTemp80;
			float 	fTemp81 = (((iTemp80 >= 4)) ? (((iTemp80 >= 6)) ? fConst0 : fConst4) : (((iTemp80 >= 2)) ? (((iTemp80 >= 3)) ? fConst26 : fConst25) : (((iTemp80 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp82 = (iRec36[1] != iRec36[2]);
			iVec10[0] = iTemp82;
			int 	iTemp83 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec42[0] = ((iRec42[1] * (1 - iTemp83)) + (iTemp20 * iTemp83));
			float 	fTemp84 = (2e+01f * (((fTemp81 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec42[0]))) / fTemp81) : 0.0f));
			int 	iTemp85 = int(fTemp84);
			float 	fTemp86 = ftbl1[max(0, int(min(int(iTemp85), 20)))];
			float 	fTemp87 = (fTemp86 + ((fTemp84 - float(iTemp85)) * (ftbl1[max(0, int(min(int((iTemp85 + 1)), 20)))] - fTemp86)));
			iRec43[0] = iRec36[1];
			int 	iTemp88 = (iRec43[1] == iRec36[1]);
			int 	iTemp89 = (iRec36[1] == 0);
			fRec44[0] = ((iTemp89) ? fVec9[0] : ((iTemp88) ? min(min(fRec44[1], fVec9[0]), fRec37[1]) : min(fVec9[0], fRec37[1])));
			fRec45[0] = ((iTemp89) ? fVec9[0] : ((iTemp88) ? max(max(fRec45[1], fVec9[0]), fRec37[1]) : max(fVec9[0], fRec37[1])));
			int 	iTemp90 = (iRec36[1] == 3);
			int 	iTemp91 = (iRec36[1] == 6);
			float 	fTemp92 = (((iRec36[1] == 1)) ? min(1.0f, fTemp77) : ((iTemp89) ? 0.0f : ((iTemp91) ? (fTemp77 * fTemp87) : ((iTemp90) ? (fRec45[0] * fTemp87) : fVec9[0]))));
			float 	fTemp93 = (1.0f / ((iTemp89) ? 0.0001f : (((iTemp90 | iTemp91)) ? (0.04761905f * fTemp81) : fTemp81)));
			float 	fTemp94 = (fRec41[1] - fTemp93);
			float 	fTemp95 = (fRec41[1] + fTemp93);
			fRec41[0] = (((fTemp95 < fTemp92)) ? fTemp95 : (((fTemp94 > fTemp92)) ? fTemp94 : fTemp92));
			fRec37[0] = fRec41[0];
			fRec35[0] = (fRec37[0] - (fConst24 * ((fConst22 * fRec35[2]) + (fConst20 * fRec35[1]))));
			float 	fTemp96 = min(0.99f, (fConst27 * (((3947.8418f * fRec35[0]) + (7895.6836f * fRec35[1])) + (3947.8418f * fRec35[2]))));
			float 	fTemp97 = min(1.0f, (fSlow41 + (((fTemp96 < 0.1f)) ? (1.0f - (1e+01f * fTemp96)) : 0.0f)));
			float 	fTemp98 = ((iTemp47) ? 0.0f : (fSlow43 + fRec47[1]));
			fRec47[0] = (fTemp98 - floorf(fTemp98));
			float 	fTemp99 = (499.0f * fRec47[0]);
			int 	iTemp100 = int(fTemp99);
			int 	iTemp101 = max(0, min(iTemp100, 499));
			float 	fTemp102 = ftbl2[iTemp101];
			int 	iTemp103 = max(0, min((iTemp100 + 1), 499));
			float 	fTemp104 = (fTemp99 - float(iTemp100));
			float 	fTemp105 = float((((fVec9[1] <= 0.003f) & iTemp74) != 1));
			fRec48[0] = max((fTemp105 * fRec48[1]), fSlow44);
			fRec49[0] = max((fRec49[1] * fTemp105), fSlow25);
			float 	fTemp106 = max(min(((0.5f * (fVec9[0] - fTemp96)) + (0.2f - (0.8f * ((iTemp75) ? (2.0f * (((fRec49[0] > fRec48[0])) ? fRec49[0] : (0.0f - fRec48[0]))) : fSlow26)))), 1.0f), 0.0f);
			float 	fTemp107 = ftbl3[iTemp101];
			float 	fTemp108 = (((fTemp107 + (fTemp104 * (ftbl3[iTemp103] - fTemp107))) * (1.0f - fTemp106)) + (fTemp106 * (fTemp102 + (fTemp104 * (ftbl2[iTemp103] - fTemp102)))));
			float 	fTemp109 = (fRec46[1] - fConst29);
			float 	fTemp110 = (fConst29 + fRec46[1]);
			fRec46[0] = (((fTemp110 < fTemp108)) ? fTemp110 : (((fTemp109 > fTemp108)) ? fTemp109 : fTemp108));
			float 	fTemp111 = ((iTemp47) ? 0.0f : (fSlow45 + fRec50[1]));
			fRec50[0] = (fTemp111 - floorf(fTemp111));
			float 	fTemp112 = (499.0f * fRec50[0]);
			int 	iTemp113 = int(fTemp112);
			float 	fTemp114 = ftbl3[max(0, min(iTemp113, 499))];
			float 	fTemp115 = ((iTemp47) ? 0.0f : (fSlow46 + fRec51[1]));
			fRec51[0] = (fTemp115 - floorf(fTemp115));
			float 	fTemp116 = (499.0f * fRec51[0]);
			int 	iTemp117 = int(fTemp116);
			float 	fTemp118 = ftbl2[max(0, min(iTemp117, 499))];
			fRec52[0] = (fTemp17 - (fSlow57 * ((fSlow55 * fRec52[2]) + (fSlow53 * fRec52[1]))));
			fVec11[0] = fSlow59;
			int 	iTemp119 = (fSlow61 != (0.9f * fVec11[1]));
			iVec12[0] = iTemp119;
			int 	iTemp120 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec56[0] = ((iRec56[1] * (1 - iTemp120)) + (iTemp20 * iTemp120));
			float 	fTemp121 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec56[0])))) > 0.5f) & iSlow60)) ? 0.0f : fSlow58) + 1.0f)) + 0.5f))];
			fVec13[0] = fTemp121;
			int 	iTemp122 = (fVec13[0] > 0.003f);
			int 	iTemp123 = (fVec13[0] <= 0.003f);
			float 	fTemp124 = float((iTemp123 | (fVec13[1] >= 0.003f)));
			fRec57[0] = max((fRec57[1] * fTemp124), fSlow61);
			fRec58[0] = max((fTemp124 * fRec58[1]), fSlow62);
			float 	fTemp125 = (min(1.0f, fRec58[0]) + min(1.0f, fRec57[0]));
			int 	iTemp126 = (fVec13[0] >= fRec55[1]);
			int 	iTemp127 = (fRec55[1] <= 0.001f);
			int 	iTemp128 = (((iRec54[1] >= 4)) ? (((iRec54[1] >= 6)) ? ((iTemp127) ? 0 : ((iTemp122) ? 1 : 6)) : (((iRec54[1] >= 5)) ? ((iTemp123) ? 3 : ((iTemp126) ? 4 : 5)) : ((iTemp123) ? 3 : (((fVec13[0] <= fRec55[1])) ? 5 : 4)))) : (((iRec54[1] >= 2)) ? (((iRec54[1] >= 3)) ? (((iTemp123 & iTemp127)) ? 0 : ((iTemp122) ? 1 : 3)) : ((iTemp123) ? 6 : ((iTemp126) ? 4 : 2))) : (((iRec54[1] >= 1)) ? (((fRec55[1] >= min(fTemp125, 1.0f))) ? ((iTemp123) ? 6 : 2) : 1) : ((iTemp122) ? 1 : 0))));
			iRec54[0] = iTemp128;
			float 	fTemp129 = (((iTemp128 >= 4)) ? (((iTemp128 >= 6)) ? fConst0 : fConst4) : (((iTemp128 >= 2)) ? (((iTemp128 >= 3)) ? fConst26 : fConst25) : (((iTemp128 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp130 = (iRec54[1] != iRec54[2]);
			iVec14[0] = iTemp130;
			int 	iTemp131 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp131)) + (iTemp20 * iTemp131));
			float 	fTemp132 = (2e+01f * (((fTemp129 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec60[0]))) / fTemp129) : 0.0f));
			int 	iTemp133 = int(fTemp132);
			float 	fTemp134 = ftbl1[max(0, int(min(int(iTemp133), 20)))];
			float 	fTemp135 = (fTemp134 + ((fTemp132 - float(iTemp133)) * (ftbl1[max(0, int(min(int((iTemp133 + 1)), 20)))] - fTemp134)));
			iRec61[0] = iRec54[1];
			int 	iTemp136 = (iRec61[1] == iRec54[1]);
			int 	iTemp137 = (iRec54[1] == 0);
			fRec62[0] = ((iTemp137) ? fVec13[0] : ((iTemp136) ? min(min(fRec62[1], fVec13[0]), fRec55[1]) : min(fVec13[0], fRec55[1])));
			fRec63[0] = ((iTemp137) ? fVec13[0] : ((iTemp136) ? max(max(fRec63[1], fVec13[0]), fRec55[1]) : max(fVec13[0], fRec55[1])));
			int 	iTemp138 = (iRec54[1] == 3);
			int 	iTemp139 = (iRec54[1] == 6);
			float 	fTemp140 = (((iRec54[1] == 1)) ? min(1.0f, fTemp125) : ((iTemp137) ? 0.0f : ((iTemp139) ? (fTemp125 * fTemp135) : ((iTemp138) ? (fRec63[0] * fTemp135) : fVec13[0]))));
			float 	fTemp141 = (1.0f / ((iTemp137) ? 0.0001f : (((iTemp138 | iTemp139)) ? (0.04761905f * fTemp129) : fTemp129)));
			float 	fTemp142 = (fRec59[1] - fTemp141);
			float 	fTemp143 = (fRec59[1] + fTemp141);
			fRec59[0] = (((fTemp143 < fTemp140)) ? fTemp143 : (((fTemp142 > fTemp140)) ? fTemp142 : fTemp140));
			fRec55[0] = fRec59[0];
			fRec53[0] = (fRec55[0] - (fConst24 * ((fConst22 * fRec53[2]) + (fConst20 * fRec53[1]))));
			float 	fTemp144 = min(0.99f, (fConst27 * (((3947.8418f * fRec53[0]) + (7895.6836f * fRec53[1])) + (3947.8418f * fRec53[2]))));
			float 	fTemp145 = min(1.0f, (fSlow63 + (((fTemp144 < 0.1f)) ? (1.0f - (1e+01f * fTemp144)) : 0.0f)));
			float 	fTemp146 = ((iTemp47) ? 0.0f : (fSlow65 + fRec65[1]));
			fRec65[0] = (fTemp146 - floorf(fTemp146));
			float 	fTemp147 = (499.0f * fRec65[0]);
			int 	iTemp148 = int(fTemp147);
			int 	iTemp149 = max(0, min(iTemp148, 499));
			float 	fTemp150 = ftbl2[iTemp149];
			int 	iTemp151 = max(0, min((iTemp148 + 1), 499));
			float 	fTemp152 = (fTemp147 - float(iTemp148));
			float 	fTemp153 = float((((fVec13[1] <= 0.003f) & iTemp122) != 1));
			fRec66[0] = max((fTemp153 * fRec66[1]), fSlow66);
			fRec67[0] = max((fRec67[1] * fTemp153), fSlow47);
			float 	fTemp154 = max(min(((0.5f * (fVec13[0] - fTemp144)) + (0.2f - (0.8f * ((iTemp123) ? (2.0f * (((fRec67[0] > fRec66[0])) ? fRec67[0] : (0.0f - fRec66[0]))) : fSlow48)))), 1.0f), 0.0f);
			float 	fTemp155 = ftbl3[iTemp149];
			float 	fTemp156 = (((fTemp155 + (fTemp152 * (ftbl3[iTemp151] - fTemp155))) * (1.0f - fTemp154)) + (fTemp154 * (fTemp150 + (fTemp152 * (ftbl2[iTemp151] - fTemp150)))));
			float 	fTemp157 = (fRec64[1] - fConst29);
			float 	fTemp158 = (fConst29 + fRec64[1]);
			fRec64[0] = (((fTemp158 < fTemp156)) ? fTemp158 : (((fTemp157 > fTemp156)) ? fTemp157 : fTemp156));
			float 	fTemp159 = ((iTemp47) ? 0.0f : (fSlow67 + fRec68[1]));
			fRec68[0] = (fTemp159 - floorf(fTemp159));
			float 	fTemp160 = (499.0f * fRec68[0]);
			int 	iTemp161 = int(fTemp160);
			float 	fTemp162 = ftbl3[max(0, min(iTemp161, 499))];
			float 	fTemp163 = ((iTemp47) ? 0.0f : (fSlow68 + fRec69[1]));
			fRec69[0] = (fTemp163 - floorf(fTemp163));
			float 	fTemp164 = (499.0f * fRec69[0]);
			int 	iTemp165 = int(fTemp164);
			float 	fTemp166 = ftbl2[max(0, min(iTemp165, 499))];
			fRec70[0] = (fTemp17 - (fSlow79 * ((fSlow77 * fRec70[2]) + (fSlow75 * fRec70[1]))));
			fVec15[0] = fSlow81;
			int 	iTemp167 = (fSlow83 != (0.9f * fVec15[1]));
			iVec16[0] = iTemp167;
			int 	iTemp168 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec74[0] = ((iRec74[1] * (1 - iTemp168)) + (iTemp20 * iTemp168));
			float 	fTemp169 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec74[0])))) > 0.5f) & iSlow82)) ? 0.0f : fSlow80) + 1.0f)) + 0.5f))];
			fVec17[0] = fTemp169;
			int 	iTemp170 = (fVec17[0] > 0.003f);
			int 	iTemp171 = (fVec17[0] <= 0.003f);
			float 	fTemp172 = float((iTemp171 | (fVec17[1] >= 0.003f)));
			fRec75[0] = max((fRec75[1] * fTemp172), fSlow83);
			fRec76[0] = max((fTemp172 * fRec76[1]), fSlow84);
			float 	fTemp173 = (min(1.0f, fRec76[0]) + min(1.0f, fRec75[0]));
			int 	iTemp174 = (fVec17[0] >= fRec73[1]);
			int 	iTemp175 = (fRec73[1] <= 0.001f);
			int 	iTemp176 = (((iRec72[1] >= 4)) ? (((iRec72[1] >= 6)) ? ((iTemp175) ? 0 : ((iTemp170) ? 1 : 6)) : (((iRec72[1] >= 5)) ? ((iTemp171) ? 3 : ((iTemp174) ? 4 : 5)) : ((iTemp171) ? 3 : (((fVec17[0] <= fRec73[1])) ? 5 : 4)))) : (((iRec72[1] >= 2)) ? (((iRec72[1] >= 3)) ? (((iTemp171 & iTemp175)) ? 0 : ((iTemp170) ? 1 : 3)) : ((iTemp171) ? 6 : ((iTemp174) ? 4 : 2))) : (((iRec72[1] >= 1)) ? (((fRec73[1] >= min(fTemp173, 1.0f))) ? ((iTemp171) ? 6 : 2) : 1) : ((iTemp170) ? 1 : 0))));
			iRec72[0] = iTemp176;
			float 	fTemp177 = (((iTemp176 >= 4)) ? (((iTemp176 >= 6)) ? fConst0 : fConst4) : (((iTemp176 >= 2)) ? (((iTemp176 >= 3)) ? fConst26 : fConst25) : (((iTemp176 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp178 = (iRec72[1] != iRec72[2]);
			iVec18[0] = iTemp178;
			int 	iTemp179 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec78[0] = ((iRec78[1] * (1 - iTemp179)) + (iTemp20 * iTemp179));
			float 	fTemp180 = (2e+01f * (((fTemp177 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec78[0]))) / fTemp177) : 0.0f));
			int 	iTemp181 = int(fTemp180);
			float 	fTemp182 = ftbl1[max(0, int(min(int(iTemp181), 20)))];
			float 	fTemp183 = (fTemp182 + ((fTemp180 - float(iTemp181)) * (ftbl1[max(0, int(min(int((iTemp181 + 1)), 20)))] - fTemp182)));
			iRec79[0] = iRec72[1];
			int 	iTemp184 = (iRec79[1] == iRec72[1]);
			int 	iTemp185 = (iRec72[1] == 0);
			fRec80[0] = ((iTemp185) ? fVec17[0] : ((iTemp184) ? min(min(fRec80[1], fVec17[0]), fRec73[1]) : min(fVec17[0], fRec73[1])));
			fRec81[0] = ((iTemp185) ? fVec17[0] : ((iTemp184) ? max(max(fRec81[1], fVec17[0]), fRec73[1]) : max(fVec17[0], fRec73[1])));
			int 	iTemp186 = (iRec72[1] == 3);
			int 	iTemp187 = (iRec72[1] == 6);
			float 	fTemp188 = (((iRec72[1] == 1)) ? min(1.0f, fTemp173) : ((iTemp185) ? 0.0f : ((iTemp187) ? (fTemp173 * fTemp183) : ((iTemp186) ? (fRec81[0] * fTemp183) : fVec17[0]))));
			float 	fTemp189 = (1.0f / ((iTemp185) ? 0.0001f : (((iTemp186 | iTemp187)) ? (0.04761905f * fTemp177) : fTemp177)));
			float 	fTemp190 = (fRec77[1] - fTemp189);
			float 	fTemp191 = (fRec77[1] + fTemp189);
			fRec77[0] = (((fTemp191 < fTemp188)) ? fTemp191 : (((fTemp190 > fTemp188)) ? fTemp190 : fTemp188));
			fRec73[0] = fRec77[0];
			fRec71[0] = (fRec73[0] - (fConst24 * ((fConst22 * fRec71[2]) + (fConst20 * fRec71[1]))));
			float 	fTemp192 = min(0.99f, (fConst27 * (((3947.8418f * fRec71[0]) + (7895.6836f * fRec71[1])) + (3947.8418f * fRec71[2]))));
			float 	fTemp193 = min(1.0f, (fSlow85 + (((fTemp192 < 0.1f)) ? (1.0f - (1e+01f * fTemp192)) : 0.0f)));
			float 	fTemp194 = ((iTemp47) ? 0.0f : (fSlow87 + fRec83[1]));
			fRec83[0] = (fTemp194 - floorf(fTemp194));
			float 	fTemp195 = (499.0f * fRec83[0]);
			int 	iTemp196 = int(fTemp195);
			int 	iTemp197 = max(0, min(iTemp196, 499));
			float 	fTemp198 = ftbl2[iTemp197];
			int 	iTemp199 = max(0, min((iTemp196 + 1), 499));
			float 	fTemp200 = (fTemp195 - float(iTemp196));
			float 	fTemp201 = float((((fVec17[1] <= 0.003f) & iTemp170) != 1));
			fRec84[0] = max((fTemp201 * fRec84[1]), fSlow88);
			fRec85[0] = max((fRec85[1] * fTemp201), fSlow69);
			float 	fTemp202 = max(min(((0.5f * (fVec17[0] - fTemp192)) + (0.2f - (0.8f * ((iTemp171) ? (2.0f * (((fRec85[0] > fRec84[0])) ? fRec85[0] : (0.0f - fRec84[0]))) : fSlow70)))), 1.0f), 0.0f);
			float 	fTemp203 = ftbl3[iTemp197];
			float 	fTemp204 = (((fTemp203 + (fTemp200 * (ftbl3[iTemp199] - fTemp203))) * (1.0f - fTemp202)) + (fTemp202 * (fTemp198 + (fTemp200 * (ftbl2[iTemp199] - fTemp198)))));
			float 	fTemp205 = (fRec82[1] - fConst29);
			float 	fTemp206 = (fConst29 + fRec82[1]);
			fRec82[0] = (((fTemp206 < fTemp204)) ? fTemp206 : (((fTemp205 > fTemp204)) ? fTemp205 : fTemp204));
			float 	fTemp207 = ((iTemp47) ? 0.0f : (fSlow89 + fRec86[1]));
			fRec86[0] = (fTemp207 - floorf(fTemp207));
			float 	fTemp208 = (499.0f * fRec86[0]);
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl3[max(0, min(iTemp209, 499))];
			float 	fTemp211 = ((iTemp47) ? 0.0f : (fSlow90 + fRec87[1]));
			fRec87[0] = (fTemp211 - floorf(fTemp211));
			float 	fTemp212 = (499.0f * fRec87[0]);
			int 	iTemp213 = int(fTemp212);
			float 	fTemp214 = ftbl2[max(0, min(iTemp213, 499))];
			fRec88[0] = (fTemp17 - (fSlow101 * ((fSlow99 * fRec88[2]) + (fSlow97 * fRec88[1]))));
			fVec19[0] = fSlow103;
			int 	iTemp215 = (fSlow105 != (0.9f * fVec19[1]));
			iVec20[0] = iTemp215;
			int 	iTemp216 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec92[0] = ((iRec92[1] * (1 - iTemp216)) + (iTemp20 * iTemp216));
			float 	fTemp217 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec92[0])))) > 0.5f) & iSlow104)) ? 0.0f : fSlow102) + 1.0f)) + 0.5f))];
			fVec21[0] = fTemp217;
			int 	iTemp218 = (fVec21[0] > 0.003f);
			int 	iTemp219 = (fVec21[0] <= 0.003f);
			float 	fTemp220 = float((iTemp219 | (fVec21[1] >= 0.003f)));
			fRec93[0] = max((fRec93[1] * fTemp220), fSlow105);
			fRec94[0] = max((fTemp220 * fRec94[1]), fSlow106);
			float 	fTemp221 = (min(1.0f, fRec94[0]) + min(1.0f, fRec93[0]));
			int 	iTemp222 = (fVec21[0] >= fRec91[1]);
			int 	iTemp223 = (fRec91[1] <= 0.001f);
			int 	iTemp224 = (((iRec90[1] >= 4)) ? (((iRec90[1] >= 6)) ? ((iTemp223) ? 0 : ((iTemp218) ? 1 : 6)) : (((iRec90[1] >= 5)) ? ((iTemp219) ? 3 : ((iTemp222) ? 4 : 5)) : ((iTemp219) ? 3 : (((fVec21[0] <= fRec91[1])) ? 5 : 4)))) : (((iRec90[1] >= 2)) ? (((iRec90[1] >= 3)) ? (((iTemp219 & iTemp223)) ? 0 : ((iTemp218) ? 1 : 3)) : ((iTemp219) ? 6 : ((iTemp222) ? 4 : 2))) : (((iRec90[1] >= 1)) ? (((fRec91[1] >= min(fTemp221, 1.0f))) ? ((iTemp219) ? 6 : 2) : 1) : ((iTemp218) ? 1 : 0))));
			iRec90[0] = iTemp224;
			float 	fTemp225 = (((iTemp224 >= 4)) ? (((iTemp224 >= 6)) ? fConst0 : fConst4) : (((iTemp224 >= 2)) ? (((iTemp224 >= 3)) ? fConst26 : fConst25) : (((iTemp224 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp226 = (iRec90[1] != iRec90[2]);
			iVec22[0] = iTemp226;
			int 	iTemp227 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp227)) + (iTemp20 * iTemp227));
			float 	fTemp228 = (2e+01f * (((fTemp225 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec96[0]))) / fTemp225) : 0.0f));
			int 	iTemp229 = int(fTemp228);
			float 	fTemp230 = ftbl1[max(0, int(min(int(iTemp229), 20)))];
			float 	fTemp231 = (fTemp230 + ((fTemp228 - float(iTemp229)) * (ftbl1[max(0, int(min(int((iTemp229 + 1)), 20)))] - fTemp230)));
			iRec97[0] = iRec90[1];
			int 	iTemp232 = (iRec97[1] == iRec90[1]);
			int 	iTemp233 = (iRec90[1] == 0);
			fRec98[0] = ((iTemp233) ? fVec21[0] : ((iTemp232) ? min(min(fRec98[1], fVec21[0]), fRec91[1]) : min(fVec21[0], fRec91[1])));
			fRec99[0] = ((iTemp233) ? fVec21[0] : ((iTemp232) ? max(max(fRec99[1], fVec21[0]), fRec91[1]) : max(fVec21[0], fRec91[1])));
			int 	iTemp234 = (iRec90[1] == 3);
			int 	iTemp235 = (iRec90[1] == 6);
			float 	fTemp236 = (((iRec90[1] == 1)) ? min(1.0f, fTemp221) : ((iTemp233) ? 0.0f : ((iTemp235) ? (fTemp221 * fTemp231) : ((iTemp234) ? (fRec99[0] * fTemp231) : fVec21[0]))));
			float 	fTemp237 = (1.0f / ((iTemp233) ? 0.0001f : (((iTemp234 | iTemp235)) ? (0.04761905f * fTemp225) : fTemp225)));
			float 	fTemp238 = (fRec95[1] - fTemp237);
			float 	fTemp239 = (fRec95[1] + fTemp237);
			fRec95[0] = (((fTemp239 < fTemp236)) ? fTemp239 : (((fTemp238 > fTemp236)) ? fTemp238 : fTemp236));
			fRec91[0] = fRec95[0];
			fRec89[0] = (fRec91[0] - (fConst24 * ((fConst22 * fRec89[2]) + (fConst20 * fRec89[1]))));
			float 	fTemp240 = min(0.99f, (fConst27 * (((3947.8418f * fRec89[0]) + (7895.6836f * fRec89[1])) + (3947.8418f * fRec89[2]))));
			float 	fTemp241 = min(1.0f, (fSlow107 + (((fTemp240 < 0.1f)) ? (1.0f - (1e+01f * fTemp240)) : 0.0f)));
			float 	fTemp242 = ((iTemp47) ? 0.0f : (fSlow109 + fRec101[1]));
			fRec101[0] = (fTemp242 - floorf(fTemp242));
			float 	fTemp243 = (499.0f * fRec101[0]);
			int 	iTemp244 = int(fTemp243);
			int 	iTemp245 = max(0, min(iTemp244, 499));
			float 	fTemp246 = ftbl2[iTemp245];
			int 	iTemp247 = max(0, min((iTemp244 + 1), 499));
			float 	fTemp248 = (fTemp243 - float(iTemp244));
			float 	fTemp249 = float((((fVec21[1] <= 0.003f) & iTemp218) != 1));
			fRec102[0] = max((fTemp249 * fRec102[1]), fSlow110);
			fRec103[0] = max((fRec103[1] * fTemp249), fSlow91);
			float 	fTemp250 = max(min(((0.5f * (fVec21[0] - fTemp240)) + (0.2f - (0.8f * ((iTemp219) ? (2.0f * (((fRec103[0] > fRec102[0])) ? fRec103[0] : (0.0f - fRec102[0]))) : fSlow92)))), 1.0f), 0.0f);
			float 	fTemp251 = ftbl3[iTemp245];
			float 	fTemp252 = (((fTemp251 + (fTemp248 * (ftbl3[iTemp247] - fTemp251))) * (1.0f - fTemp250)) + (fTemp250 * (fTemp246 + (fTemp248 * (ftbl2[iTemp247] - fTemp246)))));
			float 	fTemp253 = (fRec100[1] - fConst29);
			float 	fTemp254 = (fConst29 + fRec100[1]);
			fRec100[0] = (((fTemp254 < fTemp252)) ? fTemp254 : (((fTemp253 > fTemp252)) ? fTemp253 : fTemp252));
			float 	fTemp255 = ((iTemp47) ? 0.0f : (fSlow111 + fRec104[1]));
			fRec104[0] = (fTemp255 - floorf(fTemp255));
			float 	fTemp256 = (499.0f * fRec104[0]);
			int 	iTemp257 = int(fTemp256);
			float 	fTemp258 = ftbl3[max(0, min(iTemp257, 499))];
			float 	fTemp259 = ((iTemp47) ? 0.0f : (fSlow112 + fRec105[1]));
			fRec105[0] = (fTemp259 - floorf(fTemp259));
			float 	fTemp260 = (499.0f * fRec105[0]);
			int 	iTemp261 = int(fTemp260);
			float 	fTemp262 = ftbl2[max(0, min(iTemp261, 499))];
			fRec106[0] = (fTemp17 - (fSlow123 * ((fSlow121 * fRec106[2]) + (fSlow119 * fRec106[1]))));
			fVec23[0] = fSlow125;
			int 	iTemp263 = (fSlow127 != (0.9f * fVec23[1]));
			iVec24[0] = iTemp263;
			int 	iTemp264 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec110[0] = ((iRec110[1] * (1 - iTemp264)) + (iTemp20 * iTemp264));
			float 	fTemp265 = ftbl0[int(((499.5f * ((((((fConst6 * float((iRec17[0] + (-1 - iRec110[0])))) > 0.5f) & iSlow126)) ? 0.0f : fSlow124) + 1.0f)) + 0.5f))];
			fVec25[0] = fTemp265;
			int 	iTemp266 = (fVec25[0] > 0.003f);
			int 	iTemp267 = (fVec25[0] <= 0.003f);
			float 	fTemp268 = float((iTemp267 | (fVec25[1] >= 0.003f)));
			fRec111[0] = max((fRec111[1] * fTemp268), fSlow127);
			fRec112[0] = max((fTemp268 * fRec112[1]), fSlow128);
			float 	fTemp269 = (min(1.0f, fRec112[0]) + min(1.0f, fRec111[0]));
			int 	iTemp270 = (fVec25[0] >= fRec109[1]);
			int 	iTemp271 = (fRec109[1] <= 0.001f);
			int 	iTemp272 = (((iRec108[1] >= 4)) ? (((iRec108[1] >= 6)) ? ((iTemp271) ? 0 : ((iTemp266) ? 1 : 6)) : (((iRec108[1] >= 5)) ? ((iTemp267) ? 3 : ((iTemp270) ? 4 : 5)) : ((iTemp267) ? 3 : (((fVec25[0] <= fRec109[1])) ? 5 : 4)))) : (((iRec108[1] >= 2)) ? (((iRec108[1] >= 3)) ? (((iTemp267 & iTemp271)) ? 0 : ((iTemp266) ? 1 : 3)) : ((iTemp267) ? 6 : ((iTemp270) ? 4 : 2))) : (((iRec108[1] >= 1)) ? (((fRec109[1] >= min(fTemp269, 1.0f))) ? ((iTemp267) ? 6 : 2) : 1) : ((iTemp266) ? 1 : 0))));
			iRec108[0] = iTemp272;
			float 	fTemp273 = (((iTemp272 >= 4)) ? (((iTemp272 >= 6)) ? fConst0 : fConst4) : (((iTemp272 >= 2)) ? (((iTemp272 >= 3)) ? fConst26 : fConst25) : (((iTemp272 >= 1)) ? fConst1 : 0.0f)));
			int 	iTemp274 = (iRec108[1] != iRec108[2]);
			iVec26[0] = iTemp274;
			int 	iTemp275 = ((iVec26[1] <= 0) & (iVec26[0] > 0));
			iRec114[0] = ((iRec114[1] * (1 - iTemp275)) + (iTemp20 * iTemp275));
			float 	fTemp276 = (2e+01f * (((fTemp273 > 0.0f)) ? (float((iRec17[0] + (-1 - iRec114[0]))) / fTemp273) : 0.0f));
			int 	iTemp277 = int(fTemp276);
			float 	fTemp278 = ftbl1[max(0, int(min(int(iTemp277), 20)))];
			float 	fTemp279 = (fTemp278 + ((fTemp276 - float(iTemp277)) * (ftbl1[max(0, int(min(int((iTemp277 + 1)), 20)))] - fTemp278)));
			iRec115[0] = iRec108[1];
			int 	iTemp280 = (iRec115[1] == iRec108[1]);
			int 	iTemp281 = (iRec108[1] == 0);
			fRec116[0] = ((iTemp281) ? fVec25[0] : ((iTemp280) ? min(min(fRec116[1], fVec25[0]), fRec109[1]) : min(fVec25[0], fRec109[1])));
			fRec117[0] = ((iTemp281) ? fVec25[0] : ((iTemp280) ? max(max(fRec117[1], fVec25[0]), fRec109[1]) : max(fVec25[0], fRec109[1])));
			int 	iTemp282 = (iRec108[1] == 3);
			int 	iTemp283 = (iRec108[1] == 6);
			float 	fTemp284 = (((iRec108[1] == 1)) ? min(1.0f, fTemp269) : ((iTemp281) ? 0.0f : ((iTemp283) ? (fTemp269 * fTemp279) : ((iTemp282) ? (fRec117[0] * fTemp279) : fVec25[0]))));
			float 	fTemp285 = (1.0f / ((iTemp281) ? 0.0001f : (((iTemp282 | iTemp283)) ? (0.04761905f * fTemp273) : fTemp273)));
			float 	fTemp286 = (fRec113[1] - fTemp285);
			float 	fTemp287 = (fRec113[1] + fTemp285);
			fRec113[0] = (((fTemp287 < fTemp284)) ? fTemp287 : (((fTemp286 > fTemp284)) ? fTemp286 : fTemp284));
			fRec109[0] = fRec113[0];
			fRec107[0] = (fRec109[0] - (fConst24 * ((fConst22 * fRec107[2]) + (fConst20 * fRec107[1]))));
			float 	fTemp288 = min(0.99f, (fConst27 * (((3947.8418f * fRec107[0]) + (7895.6836f * fRec107[1])) + (3947.8418f * fRec107[2]))));
			float 	fTemp289 = min(1.0f, (fSlow129 + (((fTemp288 < 0.1f)) ? (1.0f - (1e+01f * fTemp288)) : 0.0f)));
			float 	fTemp290 = ((iTemp47) ? 0.0f : (fSlow131 + fRec119[1]));
			fRec119[0] = (fTemp290 - floorf(fTemp290));
			float 	fTemp291 = (499.0f * fRec119[0]);
			int 	iTemp292 = int(fTemp291);
			int 	iTemp293 = max(0, min(iTemp292, 499));
			float 	fTemp294 = ftbl2[iTemp293];
			int 	iTemp295 = max(0, min((iTemp292 + 1), 499));
			float 	fTemp296 = (fTemp291 - float(iTemp292));
			float 	fTemp297 = float((((fVec25[1] <= 0.003f) & iTemp266) != 1));
			fRec120[0] = max((fTemp297 * fRec120[1]), fSlow132);
			fRec121[0] = max((fRec121[1] * fTemp297), fSlow113);
			float 	fTemp298 = max(min(((0.5f * (fVec25[0] - fTemp288)) + (0.2f - (0.8f * ((iTemp267) ? (2.0f * (((fRec121[0] > fRec120[0])) ? fRec121[0] : (0.0f - fRec120[0]))) : fSlow114)))), 1.0f), 0.0f);
			float 	fTemp299 = ftbl3[iTemp293];
			float 	fTemp300 = (((fTemp299 + (fTemp296 * (ftbl3[iTemp295] - fTemp299))) * (1.0f - fTemp298)) + (fTemp298 * (fTemp294 + (fTemp296 * (ftbl2[iTemp295] - fTemp294)))));
			float 	fTemp301 = (fRec118[1] - fConst29);
			float 	fTemp302 = (fConst29 + fRec118[1]);
			fRec118[0] = (((fTemp302 < fTemp300)) ? fTemp302 : (((fTemp301 > fTemp300)) ? fTemp301 : fTemp300));
			float 	fTemp303 = ((iTemp47) ? 0.0f : (fSlow133 + fRec122[1]));
			fRec122[0] = (fTemp303 - floorf(fTemp303));
			float 	fTemp304 = (499.0f * fRec122[0]);
			int 	iTemp305 = int(fTemp304);
			float 	fTemp306 = ftbl3[max(0, min(iTemp305, 499))];
			float 	fTemp307 = ((iTemp47) ? 0.0f : (fSlow134 + fRec123[1]));
			fRec123[0] = (fTemp307 - floorf(fTemp307));
			float 	fTemp308 = (499.0f * fRec123[0]);
			int 	iTemp309 = int(fTemp308);
			float 	fTemp310 = ftbl2[max(0, min(iTemp309, 499))];
			fRec10[0] = ((1.37f * ((((((fTemp288 * ((0.5f * ((((0.2f * (fTemp310 + ((fTemp308 - float(iTemp309)) * (ftbl2[max(0, min((iTemp309 + 1), 499))] - fTemp310)))) + (0.8f * (fTemp306 + ((fTemp304 - float(iTemp305)) * (ftbl3[max(0, min((iTemp305 + 1), 499))] - fTemp306))))) * fSlow117) * fSlow115)) + (((fRec118[0] * (1.0f - fTemp289)) + (fSlow130 * (fTemp289 * (fRec106[0] - fRec106[2])))) * fSlow118))) + (fTemp240 * ((0.5f * ((((0.2f * (fTemp262 + ((fTemp260 - float(iTemp261)) * (ftbl2[max(0, min((iTemp261 + 1), 499))] - fTemp262)))) + (0.8f * (fTemp258 + ((fTemp256 - float(iTemp257)) * (ftbl3[max(0, min((iTemp257 + 1), 499))] - fTemp258))))) * fSlow95) * fSlow93)) + (((fRec100[0] * (1.0f - fTemp241)) + (fSlow108 * (fTemp241 * (fRec88[0] - fRec88[2])))) * fSlow96)))) + (fTemp192 * ((0.5f * ((((0.2f * (fTemp214 + ((fTemp212 - float(iTemp213)) * (ftbl2[max(0, min((iTemp213 + 1), 499))] - fTemp214)))) + (0.8f * (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl3[max(0, min((iTemp209 + 1), 499))] - fTemp210))))) * fSlow73) * fSlow71)) + (((fRec82[0] * (1.0f - fTemp193)) + (fSlow86 * (fTemp193 * (fRec70[0] - fRec70[2])))) * fSlow74)))) + (fTemp144 * ((0.5f * ((((0.2f * (fTemp166 + ((fTemp164 - float(iTemp165)) * (ftbl2[max(0, min((iTemp165 + 1), 499))] - fTemp166)))) + (0.8f * (fTemp162 + ((fTemp160 - float(iTemp161)) * (ftbl3[max(0, min((iTemp161 + 1), 499))] - fTemp162))))) * fSlow51) * fSlow49)) + (((fRec64[0] * (1.0f - fTemp145)) + (fSlow64 * (fTemp145 * (fRec52[0] - fRec52[2])))) * fSlow52)))) + (fTemp96 * ((0.5f * ((((0.2f * (fTemp118 + ((fTemp116 - float(iTemp117)) * (ftbl2[max(0, min((iTemp117 + 1), 499))] - fTemp118)))) + (0.8f * (fTemp114 + ((fTemp112 - float(iTemp113)) * (ftbl3[max(0, min((iTemp113 + 1), 499))] - fTemp114))))) * fSlow29) * fSlow27)) + (((fRec46[0] * (1.0f - fTemp97)) + (fSlow42 * (fTemp97 * (fRec34[0] - fRec34[2])))) * fSlow30)))) + (fTemp45 * ((0.5f * ((((0.2f * (fTemp70 + ((fTemp68 - float(iTemp69)) * (ftbl2[max(0, min((iTemp69 + 1), 499))] - fTemp70)))) + (0.8f * (fTemp66 + ((fTemp64 - float(iTemp65)) * (ftbl3[max(0, min((iTemp65 + 1), 499))] - fTemp66))))) * fSlow7) * fSlow5)) + (((fRec26[0] * (1.0f - fTemp46)) + (fSlow20 * (fTemp46 * (fRec12[0] - fRec12[2])))) * fSlow8))))) - (fConst16 * ((fConst14 * fRec10[2]) + (fConst12 * fRec10[1]))));
			output0[i] = (FAUSTFLOAT)((((fConst32 * fRec10[1]) + (fConst16 * (fRec10[0] + fRec10[2]))) + (1.6129032e-06f * ((((fRec7[0] * fTemp1) * (fRec3[0] - fRec3[2])) * max(0.0f, min((fConst3 * fTemp6), ((fConst5 * (fConst2 - fTemp6)) + 1.0f)))) / fTemp3))));
			// post processing
			fRec10[2] = fRec10[1]; fRec10[1] = fRec10[0];
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
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			iRec8[1] = iRec8[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			iRec4[1] = iRec4[0];
			iRec2[1] = iRec2[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec1[1] = fRec1[0];
			iRec0[1] = iRec0[0];
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
