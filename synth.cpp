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
		int 	iRec6[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec6[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec6[0] = (iRec6[1] + 1);
				float 	fTemp1 = ((0.002002002f * float((iRec6[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp1)) + -1.0f))) * float(((fTemp1 > 0.0f) - (fTemp1 < 0.0f))));
				// post processing
				iRec6[1] = iRec6[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec12[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec12[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec12[0] = (iRec12[1] + 1);
				int 	iTemp13 = int((1.05f * float((iRec12[0] + -1))));
				output[i] = (((iTemp13 >= 11)) ? (((iTemp13 >= 16)) ? (((iTemp13 >= 19)) ? (((iTemp13 >= 20)) ? 0.0f : 0.01f) : (((iTemp13 >= 18)) ? 0.03f : (((iTemp13 >= 17)) ? 0.06f : 0.08f))) : (((iTemp13 >= 14)) ? (((iTemp13 >= 15)) ? 0.1f : 0.12f) : (((iTemp13 >= 13)) ? 0.14f : (((iTemp13 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp13 >= 6)) ? (((iTemp13 >= 9)) ? (((iTemp13 >= 10)) ? 0.22f : 0.26f) : (((iTemp13 >= 8)) ? 0.3f : (((iTemp13 >= 7)) ? 0.35f : 0.4f))) : (((iTemp13 >= 3)) ? (((iTemp13 >= 5)) ? 0.47f : (((iTemp13 >= 4)) ? 0.55f : 0.64f)) : (((iTemp13 >= 2)) ? 0.74f : (((iTemp13 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec12[1] = iRec12[0];
			}
		}
	};


	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	FAUSTFLOAT 	fslider0;
	int 	iRec2[2];
	float 	fRec1[3];
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	static float 	ftbl0[1000];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	float 	fVec0[2];
	int 	iVec1[2];
	int 	iRec8[2];
	int 	iRec7[2];
	float 	fConst17;
	float 	fVec2[2];
	float 	fRec9[2];
	float 	fRec10[2];
	int 	iRec4[3];
	static float 	ftbl1[21];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	int 	iVec3[2];
	int 	iRec13[2];
	int 	iRec14[2];
	float 	fRec15[2];
	float 	fRec16[2];
	float 	fRec11[2];
	float 	fRec5[2];
	float 	fRec3[3];
	float 	fConst22;
	FAUSTFLOAT 	fslider3;
	float 	fRec17[3];
	FAUSTFLOAT 	fslider4;
	FAUSTFLOAT 	fslider5;
	float 	fVec4[2];
	int 	iVec5[2];
	int 	iRec21[2];
	float 	fVec6[2];
	float 	fRec22[2];
	float 	fRec23[2];
	int 	iRec19[3];
	int 	iVec7[2];
	int 	iRec25[2];
	int 	iRec26[2];
	float 	fRec27[2];
	float 	fRec28[2];
	float 	fRec24[2];
	float 	fRec20[2];
	float 	fRec18[3];
	FAUSTFLOAT 	fslider6;
	float 	fRec29[3];
	FAUSTFLOAT 	fslider7;
	FAUSTFLOAT 	fslider8;
	float 	fVec8[2];
	int 	iVec9[2];
	int 	iRec33[2];
	float 	fVec10[2];
	float 	fRec34[2];
	float 	fRec35[2];
	int 	iRec31[3];
	int 	iVec11[2];
	int 	iRec37[2];
	int 	iRec38[2];
	float 	fRec39[2];
	float 	fRec40[2];
	float 	fRec36[2];
	float 	fRec32[2];
	float 	fRec30[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec41[3];
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec12[2];
	int 	iVec13[2];
	int 	iRec45[2];
	float 	fVec14[2];
	float 	fRec46[2];
	float 	fRec47[2];
	int 	iRec43[3];
	int 	iVec15[2];
	int 	iRec49[2];
	int 	iRec50[2];
	float 	fRec51[2];
	float 	fRec52[2];
	float 	fRec48[2];
	float 	fRec44[2];
	float 	fRec42[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec53[3];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	float 	fVec16[2];
	int 	iVec17[2];
	int 	iRec57[2];
	float 	fVec18[2];
	float 	fRec58[2];
	float 	fRec59[2];
	int 	iRec55[3];
	int 	iVec19[2];
	int 	iRec61[2];
	int 	iRec62[2];
	float 	fRec63[2];
	float 	fRec64[2];
	float 	fRec60[2];
	float 	fRec56[2];
	float 	fRec54[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec65[3];
	FAUSTFLOAT 	fslider16;
	FAUSTFLOAT 	fslider17;
	float 	fVec20[2];
	int 	iVec21[2];
	int 	iRec69[2];
	float 	fVec22[2];
	float 	fRec70[2];
	float 	fRec71[2];
	int 	iRec67[3];
	int 	iVec23[2];
	int 	iRec73[2];
	int 	iRec74[2];
	float 	fRec75[2];
	float 	fRec76[2];
	float 	fRec72[2];
	float 	fRec68[2];
	float 	fRec66[3];
	float 	fRec0[3];
	float 	fConst23;
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
		fConst23 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 69.0f;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		fslider3 = 69.0f;
		fslider4 = 0.0f;
		fslider5 = 0.0f;
		fslider6 = 69.0f;
		fslider7 = 0.0f;
		fslider8 = 0.0f;
		fslider9 = 69.0f;
		fslider10 = 0.0f;
		fslider11 = 0.0f;
		fslider12 = 69.0f;
		fslider13 = 0.0f;
		fslider14 = 0.0f;
		fslider15 = 69.0f;
		fslider16 = 0.0f;
		fslider17 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) iVec1[i] = 0;
		for (int i=0; i<2; i++) iRec8[i] = 0;
		for (int i=0; i<2; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<3; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) iVec3[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) iVec5[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<3; i++) iRec19[i] = 0;
		for (int i=0; i<2; i++) iVec7[i] = 0;
		for (int i=0; i<2; i++) iRec25[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) iVec9[i] = 0;
		for (int i=0; i<2; i++) iRec33[i] = 0;
		for (int i=0; i<2; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<3; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) iVec11[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) iVec13[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) fVec14[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<3; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) iVec15[i] = 0;
		for (int i=0; i<2; i++) iRec49[i] = 0;
		for (int i=0; i<2; i++) iRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec42[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) iVec17[i] = 0;
		for (int i=0; i<2; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) fVec18[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<3; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) iVec19[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<3; i++) fRec54[i] = 0;
		for (int i=0; i<3; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) iVec21[i] = 0;
		for (int i=0; i<2; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<3; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) iVec23[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
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
		synth_interface.note[0] = &fslider15;
		synth_interface.pres[0] = &fslider16;
		synth_interface.vpres[0] = &fslider17;
		synth_interface.note[1] = &fslider12;
		synth_interface.pres[1] = &fslider13;
		synth_interface.vpres[1] = &fslider14;
		synth_interface.note[2] = &fslider9;
		synth_interface.pres[2] = &fslider10;
		synth_interface.vpres[2] = &fslider11;
		synth_interface.note[3] = &fslider6;
		synth_interface.pres[3] = &fslider7;
		synth_interface.vpres[3] = &fslider8;
		synth_interface.note[4] = &fslider3;
		synth_interface.pres[4] = &fslider4;
		synth_interface.vpres[4] = &fslider5;
		synth_interface.note[5] = &fslider0;
		synth_interface.pres[5] = &fslider1;
		synth_interface.vpres[5] = &fslider2;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fastpow2((0.083333336f * float(fslider0)));
		float 	fSlow1 = (2.0f * ((1.5820991e-06f * powf(fSlow0,2.0f)) + -1.0f));
		float 	fSlow2 = (1.5820991e-06f * fSlow0);
		float 	fSlow3 = ((fSlow0 * (fSlow2 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow4 = ((fSlow0 * (fSlow2 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow5 = (1.0f / fSlow4);
		float 	fSlow6 = float(fslider1);
		float 	fSlow7 = float(fslider2);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.9f * fSlow7);
		float 	fSlow10 = (0.0f - fSlow9);
		float 	fSlow11 = (fSlow0 / fSlow4);
		float 	fSlow12 = fastpow2((0.083333336f * float(fslider3)));
		float 	fSlow13 = (2.0f * ((1.5820991e-06f * powf(fSlow12,2.0f)) + -1.0f));
		float 	fSlow14 = (1.5820991e-06f * fSlow12);
		float 	fSlow15 = ((fSlow12 * (fSlow14 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow16 = ((fSlow12 * (fSlow14 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow17 = (1.0f / fSlow16);
		float 	fSlow18 = float(fslider4);
		float 	fSlow19 = float(fslider5);
		int 	iSlow20 = (fSlow19 == 0.0f);
		float 	fSlow21 = (0.9f * fSlow19);
		float 	fSlow22 = (0.0f - fSlow21);
		float 	fSlow23 = (fSlow12 / fSlow16);
		float 	fSlow24 = fastpow2((0.083333336f * float(fslider6)));
		float 	fSlow25 = (2.0f * ((1.5820991e-06f * powf(fSlow24,2.0f)) + -1.0f));
		float 	fSlow26 = (1.5820991e-06f * fSlow24);
		float 	fSlow27 = ((fSlow24 * (fSlow26 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow28 = ((fSlow24 * (fSlow26 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow29 = (1.0f / fSlow28);
		float 	fSlow30 = float(fslider7);
		float 	fSlow31 = float(fslider8);
		int 	iSlow32 = (fSlow31 == 0.0f);
		float 	fSlow33 = (0.9f * fSlow31);
		float 	fSlow34 = (0.0f - fSlow33);
		float 	fSlow35 = (fSlow24 / fSlow28);
		float 	fSlow36 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow37 = (2.0f * ((1.5820991e-06f * powf(fSlow36,2.0f)) + -1.0f));
		float 	fSlow38 = (1.5820991e-06f * fSlow36);
		float 	fSlow39 = ((fSlow36 * (fSlow38 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow40 = ((fSlow36 * (fSlow38 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow41 = (1.0f / fSlow40);
		float 	fSlow42 = float(fslider10);
		float 	fSlow43 = float(fslider11);
		int 	iSlow44 = (fSlow43 == 0.0f);
		float 	fSlow45 = (0.9f * fSlow43);
		float 	fSlow46 = (0.0f - fSlow45);
		float 	fSlow47 = (fSlow36 / fSlow40);
		float 	fSlow48 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow49 = (2.0f * ((1.5820991e-06f * powf(fSlow48,2.0f)) + -1.0f));
		float 	fSlow50 = (1.5820991e-06f * fSlow48);
		float 	fSlow51 = ((fSlow48 * (fSlow50 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow52 = ((fSlow48 * (fSlow50 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow53 = (1.0f / fSlow52);
		float 	fSlow54 = float(fslider13);
		float 	fSlow55 = float(fslider14);
		int 	iSlow56 = (fSlow55 == 0.0f);
		float 	fSlow57 = (0.9f * fSlow55);
		float 	fSlow58 = (0.0f - fSlow57);
		float 	fSlow59 = (fSlow48 / fSlow52);
		float 	fSlow60 = fastpow2((0.083333336f * float(fslider15)));
		float 	fSlow61 = (2.0f * ((1.5820991e-06f * powf(fSlow60,2.0f)) + -1.0f));
		float 	fSlow62 = (1.5820991e-06f * fSlow60);
		float 	fSlow63 = ((fSlow60 * (fSlow62 + -1.5683481e-06f)) + 1.0f);
		float 	fSlow64 = ((fSlow60 * (fSlow62 + 1.5683481e-06f)) + 1.0f);
		float 	fSlow65 = (1.0f / fSlow64);
		float 	fSlow66 = float(fslider16);
		float 	fSlow67 = float(fslider17);
		int 	iSlow68 = (fSlow67 == 0.0f);
		float 	fSlow69 = (0.9f * fSlow67);
		float 	fSlow70 = (0.0f - fSlow69);
		float 	fSlow71 = (fSlow60 / fSlow64);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iRec2[0] = ((1103515245 * iRec2[1]) + 12345);
			float 	fTemp0 = (4.656613e-10f * float(iRec2[0]));
			fRec1[0] = (fTemp0 - (fSlow5 * ((fSlow3 * fRec1[2]) + (fSlow1 * fRec1[1]))));
			fVec0[0] = fSlow7;
			int 	iTemp2 = (fSlow9 != (0.9f * fVec0[1]));
			iVec1[0] = iTemp2;
			int 	iTemp3 = ((iVec1[1] <= 0) & (iVec1[0] > 0));
			iRec8[0] = (iRec8[1] + 1);
			int 	iTemp4 = (iRec8[0] + -1);
			iRec7[0] = ((iRec7[1] * (1 - iTemp3)) + (iTemp4 * iTemp3));
			float 	fTemp5 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec7[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec2[0] = fTemp5;
			int 	iTemp6 = (fVec2[0] > 0.003f);
			int 	iTemp7 = (fVec2[0] <= 0.003f);
			float 	fTemp8 = float((iTemp7 | (fVec2[1] >= 0.003f)));
			fRec9[0] = max((fRec9[1] * fTemp8), fSlow9);
			fRec10[0] = max((fTemp8 * fRec10[1]), fSlow10);
			float 	fTemp9 = (min(1.0f, fRec10[0]) + min(1.0f, fRec9[0]));
			int 	iTemp10 = (fVec2[0] >= fRec5[1]);
			int 	iTemp11 = (fRec5[1] <= 0.001f);
			int 	iTemp12 = (((iRec4[1] >= 4)) ? (((iRec4[1] >= 6)) ? ((iTemp11) ? 0 : ((iTemp6) ? 1 : 6)) : (((iRec4[1] >= 5)) ? ((iTemp7) ? 3 : ((iTemp10) ? 4 : 5)) : ((iTemp7) ? 3 : (((fVec2[0] <= fRec5[1])) ? 5 : 4)))) : (((iRec4[1] >= 2)) ? (((iRec4[1] >= 3)) ? (((iTemp7 & iTemp11)) ? 0 : ((iTemp6) ? 1 : 3)) : ((iTemp7) ? 6 : ((iTemp10) ? 4 : 2))) : (((iRec4[1] >= 1)) ? (((fRec5[1] >= min(fTemp9, 1.0f))) ? ((iTemp7) ? 6 : 2) : 1) : ((iTemp6) ? 1 : 0))));
			iRec4[0] = iTemp12;
			float 	fTemp14 = (((iTemp12 >= 4)) ? (((iTemp12 >= 6)) ? fConst0 : fConst21) : (((iTemp12 >= 2)) ? (((iTemp12 >= 3)) ? fConst20 : fConst19) : (((iTemp12 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp15 = (iRec4[1] != iRec4[2]);
			iVec3[0] = iTemp15;
			int 	iTemp16 = ((iVec3[1] <= 0) & (iVec3[0] > 0));
			iRec13[0] = ((iRec13[1] * (1 - iTemp16)) + (iTemp4 * iTemp16));
			float 	fTemp17 = (2e+01f * (((fTemp14 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec13[0]))) / fTemp14) : 0.0f));
			int 	iTemp18 = int(fTemp17);
			float 	fTemp19 = ftbl1[max(0, int(min(int(iTemp18), 20)))];
			float 	fTemp20 = (fTemp19 + ((fTemp17 - float(iTemp18)) * (ftbl1[max(0, int(min(int((iTemp18 + 1)), 20)))] - fTemp19)));
			iRec14[0] = iRec4[1];
			int 	iTemp21 = (iRec14[1] == iRec4[1]);
			int 	iTemp22 = (iRec4[1] == 0);
			fRec15[0] = ((iTemp22) ? fVec2[0] : ((iTemp21) ? min(min(fRec15[1], fVec2[0]), fRec5[1]) : min(fVec2[0], fRec5[1])));
			fRec16[0] = ((iTemp22) ? fVec2[0] : ((iTemp21) ? max(max(fRec16[1], fVec2[0]), fRec5[1]) : max(fVec2[0], fRec5[1])));
			int 	iTemp23 = (iRec4[1] == 3);
			int 	iTemp24 = (iRec4[1] == 6);
			float 	fTemp25 = (((iRec4[1] == 1)) ? min(1.0f, fTemp9) : ((iTemp22) ? 0.0f : ((iTemp24) ? (fTemp9 * fTemp20) : ((iTemp23) ? (fRec16[0] * fTemp20) : fVec2[0]))));
			float 	fTemp26 = (1.0f / ((iTemp22) ? 0.0001f : (((iTemp23 | iTemp24)) ? (0.04761905f * fTemp14) : fTemp14)));
			float 	fTemp27 = (fRec11[1] - fTemp26);
			float 	fTemp28 = (fRec11[1] + fTemp26);
			fRec11[0] = (((fTemp28 < fTemp25)) ? fTemp28 : (((fTemp27 > fTemp25)) ? fTemp27 : fTemp25));
			fRec5[0] = fRec11[0];
			fRec3[0] = (fRec5[0] - (fConst16 * ((fConst14 * fRec3[2]) + (fConst12 * fRec3[1]))));
			fRec17[0] = (fTemp0 - (fSlow17 * ((fSlow15 * fRec17[2]) + (fSlow13 * fRec17[1]))));
			fVec4[0] = fSlow19;
			int 	iTemp29 = (fSlow21 != (0.9f * fVec4[1]));
			iVec5[0] = iTemp29;
			int 	iTemp30 = ((iVec5[1] <= 0) & (iVec5[0] > 0));
			iRec21[0] = ((iRec21[1] * (1 - iTemp30)) + (iTemp4 * iTemp30));
			float 	fTemp31 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec21[0])))) > 0.5f) & iSlow20)) ? 0.0f : fSlow18) + 1.0f)) + 0.5f))];
			fVec6[0] = fTemp31;
			int 	iTemp32 = (fVec6[0] > 0.003f);
			int 	iTemp33 = (fVec6[0] <= 0.003f);
			float 	fTemp34 = float((iTemp33 | (fVec6[1] >= 0.003f)));
			fRec22[0] = max((fRec22[1] * fTemp34), fSlow21);
			fRec23[0] = max((fTemp34 * fRec23[1]), fSlow22);
			float 	fTemp35 = (min(1.0f, fRec23[0]) + min(1.0f, fRec22[0]));
			int 	iTemp36 = (fVec6[0] >= fRec20[1]);
			int 	iTemp37 = (fRec20[1] <= 0.001f);
			int 	iTemp38 = (((iRec19[1] >= 4)) ? (((iRec19[1] >= 6)) ? ((iTemp37) ? 0 : ((iTemp32) ? 1 : 6)) : (((iRec19[1] >= 5)) ? ((iTemp33) ? 3 : ((iTemp36) ? 4 : 5)) : ((iTemp33) ? 3 : (((fVec6[0] <= fRec20[1])) ? 5 : 4)))) : (((iRec19[1] >= 2)) ? (((iRec19[1] >= 3)) ? (((iTemp33 & iTemp37)) ? 0 : ((iTemp32) ? 1 : 3)) : ((iTemp33) ? 6 : ((iTemp36) ? 4 : 2))) : (((iRec19[1] >= 1)) ? (((fRec20[1] >= min(fTemp35, 1.0f))) ? ((iTemp33) ? 6 : 2) : 1) : ((iTemp32) ? 1 : 0))));
			iRec19[0] = iTemp38;
			float 	fTemp39 = (((iTemp38 >= 4)) ? (((iTemp38 >= 6)) ? fConst0 : fConst21) : (((iTemp38 >= 2)) ? (((iTemp38 >= 3)) ? fConst20 : fConst19) : (((iTemp38 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp40 = (iRec19[1] != iRec19[2]);
			iVec7[0] = iTemp40;
			int 	iTemp41 = ((iVec7[1] <= 0) & (iVec7[0] > 0));
			iRec25[0] = ((iRec25[1] * (1 - iTemp41)) + (iTemp4 * iTemp41));
			float 	fTemp42 = (2e+01f * (((fTemp39 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec25[0]))) / fTemp39) : 0.0f));
			int 	iTemp43 = int(fTemp42);
			float 	fTemp44 = ftbl1[max(0, int(min(int(iTemp43), 20)))];
			float 	fTemp45 = (fTemp44 + ((fTemp42 - float(iTemp43)) * (ftbl1[max(0, int(min(int((iTemp43 + 1)), 20)))] - fTemp44)));
			iRec26[0] = iRec19[1];
			int 	iTemp46 = (iRec26[1] == iRec19[1]);
			int 	iTemp47 = (iRec19[1] == 0);
			fRec27[0] = ((iTemp47) ? fVec6[0] : ((iTemp46) ? min(min(fRec27[1], fVec6[0]), fRec20[1]) : min(fVec6[0], fRec20[1])));
			fRec28[0] = ((iTemp47) ? fVec6[0] : ((iTemp46) ? max(max(fRec28[1], fVec6[0]), fRec20[1]) : max(fVec6[0], fRec20[1])));
			int 	iTemp48 = (iRec19[1] == 3);
			int 	iTemp49 = (iRec19[1] == 6);
			float 	fTemp50 = (((iRec19[1] == 1)) ? min(1.0f, fTemp35) : ((iTemp47) ? 0.0f : ((iTemp49) ? (fTemp35 * fTemp45) : ((iTemp48) ? (fRec28[0] * fTemp45) : fVec6[0]))));
			float 	fTemp51 = (1.0f / ((iTemp47) ? 0.0001f : (((iTemp48 | iTemp49)) ? (0.04761905f * fTemp39) : fTemp39)));
			float 	fTemp52 = (fRec24[1] - fTemp51);
			float 	fTemp53 = (fRec24[1] + fTemp51);
			fRec24[0] = (((fTemp53 < fTemp50)) ? fTemp53 : (((fTemp52 > fTemp50)) ? fTemp52 : fTemp50));
			fRec20[0] = fRec24[0];
			fRec18[0] = (fRec20[0] - (fConst16 * ((fConst14 * fRec18[2]) + (fConst12 * fRec18[1]))));
			fRec29[0] = (fTemp0 - (fSlow29 * ((fSlow27 * fRec29[2]) + (fSlow25 * fRec29[1]))));
			fVec8[0] = fSlow31;
			int 	iTemp54 = (fSlow33 != (0.9f * fVec8[1]));
			iVec9[0] = iTemp54;
			int 	iTemp55 = ((iVec9[1] <= 0) & (iVec9[0] > 0));
			iRec33[0] = ((iRec33[1] * (1 - iTemp55)) + (iTemp4 * iTemp55));
			float 	fTemp56 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec33[0])))) > 0.5f) & iSlow32)) ? 0.0f : fSlow30) + 1.0f)) + 0.5f))];
			fVec10[0] = fTemp56;
			int 	iTemp57 = (fVec10[0] > 0.003f);
			int 	iTemp58 = (fVec10[0] <= 0.003f);
			float 	fTemp59 = float((iTemp58 | (fVec10[1] >= 0.003f)));
			fRec34[0] = max((fRec34[1] * fTemp59), fSlow33);
			fRec35[0] = max((fTemp59 * fRec35[1]), fSlow34);
			float 	fTemp60 = (min(1.0f, fRec35[0]) + min(1.0f, fRec34[0]));
			int 	iTemp61 = (fVec10[0] >= fRec32[1]);
			int 	iTemp62 = (fRec32[1] <= 0.001f);
			int 	iTemp63 = (((iRec31[1] >= 4)) ? (((iRec31[1] >= 6)) ? ((iTemp62) ? 0 : ((iTemp57) ? 1 : 6)) : (((iRec31[1] >= 5)) ? ((iTemp58) ? 3 : ((iTemp61) ? 4 : 5)) : ((iTemp58) ? 3 : (((fVec10[0] <= fRec32[1])) ? 5 : 4)))) : (((iRec31[1] >= 2)) ? (((iRec31[1] >= 3)) ? (((iTemp58 & iTemp62)) ? 0 : ((iTemp57) ? 1 : 3)) : ((iTemp58) ? 6 : ((iTemp61) ? 4 : 2))) : (((iRec31[1] >= 1)) ? (((fRec32[1] >= min(fTemp60, 1.0f))) ? ((iTemp58) ? 6 : 2) : 1) : ((iTemp57) ? 1 : 0))));
			iRec31[0] = iTemp63;
			float 	fTemp64 = (((iTemp63 >= 4)) ? (((iTemp63 >= 6)) ? fConst0 : fConst21) : (((iTemp63 >= 2)) ? (((iTemp63 >= 3)) ? fConst20 : fConst19) : (((iTemp63 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp65 = (iRec31[1] != iRec31[2]);
			iVec11[0] = iTemp65;
			int 	iTemp66 = ((iVec11[1] <= 0) & (iVec11[0] > 0));
			iRec37[0] = ((iRec37[1] * (1 - iTemp66)) + (iTemp4 * iTemp66));
			float 	fTemp67 = (2e+01f * (((fTemp64 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec37[0]))) / fTemp64) : 0.0f));
			int 	iTemp68 = int(fTemp67);
			float 	fTemp69 = ftbl1[max(0, int(min(int(iTemp68), 20)))];
			float 	fTemp70 = (fTemp69 + ((fTemp67 - float(iTemp68)) * (ftbl1[max(0, int(min(int((iTemp68 + 1)), 20)))] - fTemp69)));
			iRec38[0] = iRec31[1];
			int 	iTemp71 = (iRec38[1] == iRec31[1]);
			int 	iTemp72 = (iRec31[1] == 0);
			fRec39[0] = ((iTemp72) ? fVec10[0] : ((iTemp71) ? min(min(fRec39[1], fVec10[0]), fRec32[1]) : min(fVec10[0], fRec32[1])));
			fRec40[0] = ((iTemp72) ? fVec10[0] : ((iTemp71) ? max(max(fRec40[1], fVec10[0]), fRec32[1]) : max(fVec10[0], fRec32[1])));
			int 	iTemp73 = (iRec31[1] == 3);
			int 	iTemp74 = (iRec31[1] == 6);
			float 	fTemp75 = (((iRec31[1] == 1)) ? min(1.0f, fTemp60) : ((iTemp72) ? 0.0f : ((iTemp74) ? (fTemp60 * fTemp70) : ((iTemp73) ? (fRec40[0] * fTemp70) : fVec10[0]))));
			float 	fTemp76 = (1.0f / ((iTemp72) ? 0.0001f : (((iTemp73 | iTemp74)) ? (0.04761905f * fTemp64) : fTemp64)));
			float 	fTemp77 = (fRec36[1] - fTemp76);
			float 	fTemp78 = (fRec36[1] + fTemp76);
			fRec36[0] = (((fTemp78 < fTemp75)) ? fTemp78 : (((fTemp77 > fTemp75)) ? fTemp77 : fTemp75));
			fRec32[0] = fRec36[0];
			fRec30[0] = (fRec32[0] - (fConst16 * ((fConst14 * fRec30[2]) + (fConst12 * fRec30[1]))));
			fRec41[0] = (fTemp0 - (fSlow41 * ((fSlow39 * fRec41[2]) + (fSlow37 * fRec41[1]))));
			fVec12[0] = fSlow43;
			int 	iTemp79 = (fSlow45 != (0.9f * fVec12[1]));
			iVec13[0] = iTemp79;
			int 	iTemp80 = ((iVec13[1] <= 0) & (iVec13[0] > 0));
			iRec45[0] = ((iRec45[1] * (1 - iTemp80)) + (iTemp4 * iTemp80));
			float 	fTemp81 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec45[0])))) > 0.5f) & iSlow44)) ? 0.0f : fSlow42) + 1.0f)) + 0.5f))];
			fVec14[0] = fTemp81;
			int 	iTemp82 = (fVec14[0] > 0.003f);
			int 	iTemp83 = (fVec14[0] <= 0.003f);
			float 	fTemp84 = float((iTemp83 | (fVec14[1] >= 0.003f)));
			fRec46[0] = max((fRec46[1] * fTemp84), fSlow45);
			fRec47[0] = max((fTemp84 * fRec47[1]), fSlow46);
			float 	fTemp85 = (min(1.0f, fRec47[0]) + min(1.0f, fRec46[0]));
			int 	iTemp86 = (fVec14[0] >= fRec44[1]);
			int 	iTemp87 = (fRec44[1] <= 0.001f);
			int 	iTemp88 = (((iRec43[1] >= 4)) ? (((iRec43[1] >= 6)) ? ((iTemp87) ? 0 : ((iTemp82) ? 1 : 6)) : (((iRec43[1] >= 5)) ? ((iTemp83) ? 3 : ((iTemp86) ? 4 : 5)) : ((iTemp83) ? 3 : (((fVec14[0] <= fRec44[1])) ? 5 : 4)))) : (((iRec43[1] >= 2)) ? (((iRec43[1] >= 3)) ? (((iTemp83 & iTemp87)) ? 0 : ((iTemp82) ? 1 : 3)) : ((iTemp83) ? 6 : ((iTemp86) ? 4 : 2))) : (((iRec43[1] >= 1)) ? (((fRec44[1] >= min(fTemp85, 1.0f))) ? ((iTemp83) ? 6 : 2) : 1) : ((iTemp82) ? 1 : 0))));
			iRec43[0] = iTemp88;
			float 	fTemp89 = (((iTemp88 >= 4)) ? (((iTemp88 >= 6)) ? fConst0 : fConst21) : (((iTemp88 >= 2)) ? (((iTemp88 >= 3)) ? fConst20 : fConst19) : (((iTemp88 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp90 = (iRec43[1] != iRec43[2]);
			iVec15[0] = iTemp90;
			int 	iTemp91 = ((iVec15[1] <= 0) & (iVec15[0] > 0));
			iRec49[0] = ((iRec49[1] * (1 - iTemp91)) + (iTemp4 * iTemp91));
			float 	fTemp92 = (2e+01f * (((fTemp89 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec49[0]))) / fTemp89) : 0.0f));
			int 	iTemp93 = int(fTemp92);
			float 	fTemp94 = ftbl1[max(0, int(min(int(iTemp93), 20)))];
			float 	fTemp95 = (fTemp94 + ((fTemp92 - float(iTemp93)) * (ftbl1[max(0, int(min(int((iTemp93 + 1)), 20)))] - fTemp94)));
			iRec50[0] = iRec43[1];
			int 	iTemp96 = (iRec50[1] == iRec43[1]);
			int 	iTemp97 = (iRec43[1] == 0);
			fRec51[0] = ((iTemp97) ? fVec14[0] : ((iTemp96) ? min(min(fRec51[1], fVec14[0]), fRec44[1]) : min(fVec14[0], fRec44[1])));
			fRec52[0] = ((iTemp97) ? fVec14[0] : ((iTemp96) ? max(max(fRec52[1], fVec14[0]), fRec44[1]) : max(fVec14[0], fRec44[1])));
			int 	iTemp98 = (iRec43[1] == 3);
			int 	iTemp99 = (iRec43[1] == 6);
			float 	fTemp100 = (((iRec43[1] == 1)) ? min(1.0f, fTemp85) : ((iTemp97) ? 0.0f : ((iTemp99) ? (fTemp85 * fTemp95) : ((iTemp98) ? (fRec52[0] * fTemp95) : fVec14[0]))));
			float 	fTemp101 = (1.0f / ((iTemp97) ? 0.0001f : (((iTemp98 | iTemp99)) ? (0.04761905f * fTemp89) : fTemp89)));
			float 	fTemp102 = (fRec48[1] - fTemp101);
			float 	fTemp103 = (fRec48[1] + fTemp101);
			fRec48[0] = (((fTemp103 < fTemp100)) ? fTemp103 : (((fTemp102 > fTemp100)) ? fTemp102 : fTemp100));
			fRec44[0] = fRec48[0];
			fRec42[0] = (fRec44[0] - (fConst16 * ((fConst14 * fRec42[2]) + (fConst12 * fRec42[1]))));
			fRec53[0] = (fTemp0 - (fSlow53 * ((fSlow51 * fRec53[2]) + (fSlow49 * fRec53[1]))));
			fVec16[0] = fSlow55;
			int 	iTemp104 = (fSlow57 != (0.9f * fVec16[1]));
			iVec17[0] = iTemp104;
			int 	iTemp105 = ((iVec17[1] <= 0) & (iVec17[0] > 0));
			iRec57[0] = ((iRec57[1] * (1 - iTemp105)) + (iTemp4 * iTemp105));
			float 	fTemp106 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec57[0])))) > 0.5f) & iSlow56)) ? 0.0f : fSlow54) + 1.0f)) + 0.5f))];
			fVec18[0] = fTemp106;
			int 	iTemp107 = (fVec18[0] > 0.003f);
			int 	iTemp108 = (fVec18[0] <= 0.003f);
			float 	fTemp109 = float((iTemp108 | (fVec18[1] >= 0.003f)));
			fRec58[0] = max((fRec58[1] * fTemp109), fSlow57);
			fRec59[0] = max((fTemp109 * fRec59[1]), fSlow58);
			float 	fTemp110 = (min(1.0f, fRec59[0]) + min(1.0f, fRec58[0]));
			int 	iTemp111 = (fVec18[0] >= fRec56[1]);
			int 	iTemp112 = (fRec56[1] <= 0.001f);
			int 	iTemp113 = (((iRec55[1] >= 4)) ? (((iRec55[1] >= 6)) ? ((iTemp112) ? 0 : ((iTemp107) ? 1 : 6)) : (((iRec55[1] >= 5)) ? ((iTemp108) ? 3 : ((iTemp111) ? 4 : 5)) : ((iTemp108) ? 3 : (((fVec18[0] <= fRec56[1])) ? 5 : 4)))) : (((iRec55[1] >= 2)) ? (((iRec55[1] >= 3)) ? (((iTemp108 & iTemp112)) ? 0 : ((iTemp107) ? 1 : 3)) : ((iTemp108) ? 6 : ((iTemp111) ? 4 : 2))) : (((iRec55[1] >= 1)) ? (((fRec56[1] >= min(fTemp110, 1.0f))) ? ((iTemp108) ? 6 : 2) : 1) : ((iTemp107) ? 1 : 0))));
			iRec55[0] = iTemp113;
			float 	fTemp114 = (((iTemp113 >= 4)) ? (((iTemp113 >= 6)) ? fConst0 : fConst21) : (((iTemp113 >= 2)) ? (((iTemp113 >= 3)) ? fConst20 : fConst19) : (((iTemp113 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp115 = (iRec55[1] != iRec55[2]);
			iVec19[0] = iTemp115;
			int 	iTemp116 = ((iVec19[1] <= 0) & (iVec19[0] > 0));
			iRec61[0] = ((iRec61[1] * (1 - iTemp116)) + (iTemp4 * iTemp116));
			float 	fTemp117 = (2e+01f * (((fTemp114 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec61[0]))) / fTemp114) : 0.0f));
			int 	iTemp118 = int(fTemp117);
			float 	fTemp119 = ftbl1[max(0, int(min(int(iTemp118), 20)))];
			float 	fTemp120 = (fTemp119 + ((fTemp117 - float(iTemp118)) * (ftbl1[max(0, int(min(int((iTemp118 + 1)), 20)))] - fTemp119)));
			iRec62[0] = iRec55[1];
			int 	iTemp121 = (iRec62[1] == iRec55[1]);
			int 	iTemp122 = (iRec55[1] == 0);
			fRec63[0] = ((iTemp122) ? fVec18[0] : ((iTemp121) ? min(min(fRec63[1], fVec18[0]), fRec56[1]) : min(fVec18[0], fRec56[1])));
			fRec64[0] = ((iTemp122) ? fVec18[0] : ((iTemp121) ? max(max(fRec64[1], fVec18[0]), fRec56[1]) : max(fVec18[0], fRec56[1])));
			int 	iTemp123 = (iRec55[1] == 3);
			int 	iTemp124 = (iRec55[1] == 6);
			float 	fTemp125 = (((iRec55[1] == 1)) ? min(1.0f, fTemp110) : ((iTemp122) ? 0.0f : ((iTemp124) ? (fTemp110 * fTemp120) : ((iTemp123) ? (fRec64[0] * fTemp120) : fVec18[0]))));
			float 	fTemp126 = (1.0f / ((iTemp122) ? 0.0001f : (((iTemp123 | iTemp124)) ? (0.04761905f * fTemp114) : fTemp114)));
			float 	fTemp127 = (fRec60[1] - fTemp126);
			float 	fTemp128 = (fRec60[1] + fTemp126);
			fRec60[0] = (((fTemp128 < fTemp125)) ? fTemp128 : (((fTemp127 > fTemp125)) ? fTemp127 : fTemp125));
			fRec56[0] = fRec60[0];
			fRec54[0] = (fRec56[0] - (fConst16 * ((fConst14 * fRec54[2]) + (fConst12 * fRec54[1]))));
			fRec65[0] = (fTemp0 - (fSlow65 * ((fSlow63 * fRec65[2]) + (fSlow61 * fRec65[1]))));
			fVec20[0] = fSlow67;
			int 	iTemp129 = (fSlow69 != (0.9f * fVec20[1]));
			iVec21[0] = iTemp129;
			int 	iTemp130 = ((iVec21[1] <= 0) & (iVec21[0] > 0));
			iRec69[0] = ((iRec69[1] * (1 - iTemp130)) + (iTemp4 * iTemp130));
			float 	fTemp131 = ftbl0[int(((499.5f * ((((((fConst17 * float((iRec8[0] + (-1 - iRec69[0])))) > 0.5f) & iSlow68)) ? 0.0f : fSlow66) + 1.0f)) + 0.5f))];
			fVec22[0] = fTemp131;
			int 	iTemp132 = (fVec22[0] > 0.003f);
			int 	iTemp133 = (fVec22[0] <= 0.003f);
			float 	fTemp134 = float((iTemp133 | (fVec22[1] >= 0.003f)));
			fRec70[0] = max((fRec70[1] * fTemp134), fSlow69);
			fRec71[0] = max((fTemp134 * fRec71[1]), fSlow70);
			float 	fTemp135 = (min(1.0f, fRec71[0]) + min(1.0f, fRec70[0]));
			int 	iTemp136 = (fVec22[0] >= fRec68[1]);
			int 	iTemp137 = (fRec68[1] <= 0.001f);
			int 	iTemp138 = (((iRec67[1] >= 4)) ? (((iRec67[1] >= 6)) ? ((iTemp137) ? 0 : ((iTemp132) ? 1 : 6)) : (((iRec67[1] >= 5)) ? ((iTemp133) ? 3 : ((iTemp136) ? 4 : 5)) : ((iTemp133) ? 3 : (((fVec22[0] <= fRec68[1])) ? 5 : 4)))) : (((iRec67[1] >= 2)) ? (((iRec67[1] >= 3)) ? (((iTemp133 & iTemp137)) ? 0 : ((iTemp132) ? 1 : 3)) : ((iTemp133) ? 6 : ((iTemp136) ? 4 : 2))) : (((iRec67[1] >= 1)) ? (((fRec68[1] >= min(fTemp135, 1.0f))) ? ((iTemp133) ? 6 : 2) : 1) : ((iTemp132) ? 1 : 0))));
			iRec67[0] = iTemp138;
			float 	fTemp139 = (((iTemp138 >= 4)) ? (((iTemp138 >= 6)) ? fConst0 : fConst21) : (((iTemp138 >= 2)) ? (((iTemp138 >= 3)) ? fConst20 : fConst19) : (((iTemp138 >= 1)) ? fConst18 : 0.0f)));
			int 	iTemp140 = (iRec67[1] != iRec67[2]);
			iVec23[0] = iTemp140;
			int 	iTemp141 = ((iVec23[1] <= 0) & (iVec23[0] > 0));
			iRec73[0] = ((iRec73[1] * (1 - iTemp141)) + (iTemp4 * iTemp141));
			float 	fTemp142 = (2e+01f * (((fTemp139 > 0.0f)) ? (float((iRec8[0] + (-1 - iRec73[0]))) / fTemp139) : 0.0f));
			int 	iTemp143 = int(fTemp142);
			float 	fTemp144 = ftbl1[max(0, int(min(int(iTemp143), 20)))];
			float 	fTemp145 = (fTemp144 + ((fTemp142 - float(iTemp143)) * (ftbl1[max(0, int(min(int((iTemp143 + 1)), 20)))] - fTemp144)));
			iRec74[0] = iRec67[1];
			int 	iTemp146 = (iRec74[1] == iRec67[1]);
			int 	iTemp147 = (iRec67[1] == 0);
			fRec75[0] = ((iTemp147) ? fVec22[0] : ((iTemp146) ? min(min(fRec75[1], fVec22[0]), fRec68[1]) : min(fVec22[0], fRec68[1])));
			fRec76[0] = ((iTemp147) ? fVec22[0] : ((iTemp146) ? max(max(fRec76[1], fVec22[0]), fRec68[1]) : max(fVec22[0], fRec68[1])));
			int 	iTemp148 = (iRec67[1] == 3);
			int 	iTemp149 = (iRec67[1] == 6);
			float 	fTemp150 = (((iRec67[1] == 1)) ? min(1.0f, fTemp135) : ((iTemp147) ? 0.0f : ((iTemp149) ? (fTemp135 * fTemp145) : ((iTemp148) ? (fRec76[0] * fTemp145) : fVec22[0]))));
			float 	fTemp151 = (1.0f / ((iTemp147) ? 0.0001f : (((iTemp148 | iTemp149)) ? (0.04761905f * fTemp139) : fTemp139)));
			float 	fTemp152 = (fRec72[1] - fTemp151);
			float 	fTemp153 = (fRec72[1] + fTemp151);
			fRec72[0] = (((fTemp153 < fTemp150)) ? fTemp153 : (((fTemp152 > fTemp150)) ? fTemp152 : fTemp150));
			fRec68[0] = fRec72[0];
			fRec66[0] = (fRec68[0] - (fConst16 * ((fConst14 * fRec66[2]) + (fConst12 * fRec66[1]))));
			fRec0[0] = ((2.148637e-06f * ((((((fSlow71 * (min(0.99f, (fConst22 * (((3947.8418f * fRec66[0]) + (7895.6836f * fRec66[1])) + (3947.8418f * fRec66[2])))) * (fRec65[0] - fRec65[2]))) + (fSlow59 * (min(0.99f, (fConst22 * (((3947.8418f * fRec54[0]) + (7895.6836f * fRec54[1])) + (3947.8418f * fRec54[2])))) * (fRec53[0] - fRec53[2])))) + (fSlow47 * (min(0.99f, (fConst22 * (((3947.8418f * fRec42[0]) + (7895.6836f * fRec42[1])) + (3947.8418f * fRec42[2])))) * (fRec41[0] - fRec41[2])))) + (fSlow35 * (min(0.99f, (fConst22 * (((3947.8418f * fRec30[0]) + (7895.6836f * fRec30[1])) + (3947.8418f * fRec30[2])))) * (fRec29[0] - fRec29[2])))) + (fSlow23 * (min(0.99f, (fConst22 * (((3947.8418f * fRec18[0]) + (7895.6836f * fRec18[1])) + (3947.8418f * fRec18[2])))) * (fRec17[0] - fRec17[2])))) + (fSlow11 * (min(0.99f, (fConst22 * (((3947.8418f * fRec3[0]) + (7895.6836f * fRec3[1])) + (3947.8418f * fRec3[2])))) * (fRec1[0] - fRec1[2]))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst23 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec68[1] = fRec68[0];
			fRec72[1] = fRec72[0];
			fRec76[1] = fRec76[0];
			fRec75[1] = fRec75[0];
			iRec74[1] = iRec74[0];
			iRec73[1] = iRec73[0];
			iVec23[1] = iVec23[0];
			iRec67[2] = iRec67[1]; iRec67[1] = iRec67[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fVec22[1] = fVec22[0];
			iRec69[1] = iRec69[0];
			iVec21[1] = iVec21[0];
			fVec20[1] = fVec20[0];
			fRec65[2] = fRec65[1]; fRec65[1] = fRec65[0];
			fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
			fRec56[1] = fRec56[0];
			fRec60[1] = fRec60[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			iRec62[1] = iRec62[0];
			iRec61[1] = iRec61[0];
			iVec19[1] = iVec19[0];
			iRec55[2] = iRec55[1]; iRec55[1] = iRec55[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fVec18[1] = fVec18[0];
			iRec57[1] = iRec57[0];
			iVec17[1] = iVec17[0];
			fVec16[1] = fVec16[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec42[2] = fRec42[1]; fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			fRec48[1] = fRec48[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			iRec50[1] = iRec50[0];
			iRec49[1] = iRec49[0];
			iVec15[1] = iVec15[0];
			iRec43[2] = iRec43[1]; iRec43[1] = iRec43[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fVec14[1] = fVec14[0];
			iRec45[1] = iRec45[0];
			iVec13[1] = iVec13[0];
			fVec12[1] = fVec12[0];
			fRec41[2] = fRec41[1]; fRec41[1] = fRec41[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec32[1] = fRec32[0];
			fRec36[1] = fRec36[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			iRec38[1] = iRec38[0];
			iRec37[1] = iRec37[0];
			iVec11[1] = iVec11[0];
			iRec31[2] = iRec31[1]; iRec31[1] = iRec31[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fVec10[1] = fVec10[0];
			iRec33[1] = iRec33[0];
			iVec9[1] = iVec9[0];
			fVec8[1] = fVec8[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec24[1] = fRec24[0];
			fRec28[1] = fRec28[0];
			fRec27[1] = fRec27[0];
			iRec26[1] = iRec26[0];
			iRec25[1] = iRec25[0];
			iVec7[1] = iVec7[0];
			iRec19[2] = iRec19[1]; iRec19[1] = iRec19[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fVec6[1] = fVec6[0];
			iRec21[1] = iRec21[0];
			iVec5[1] = iVec5[0];
			fVec4[1] = fVec4[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec11[1] = fRec11[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			iRec14[1] = iRec14[0];
			iRec13[1] = iRec13[0];
			iVec3[1] = iVec3[0];
			iRec4[2] = iRec4[1]; iRec4[1] = iRec4[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fVec2[1] = fVec2[0];
			iRec7[1] = iRec7[0];
			iRec8[1] = iRec8[0];
			iVec1[1] = iVec1[0];
			fVec0[1] = fVec0[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			iRec2[1] = iRec2[0];
		}
	}
};


float 	mydsp::ftbl0[1000];
float 	mydsp::ftbl1[21];

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
