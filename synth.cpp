//----------------------------------------------------------
// name: "synth.dsp.tmp"
//
// Code generated with Faust 2.60.3 (https://faust.grame.fr)
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
		int 	iVec1[2];
		int 	iRec1[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iVec1[i] = 0;
			for (int i=0; i<2; i++) iRec1[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iVec1[0] = 1;
				iRec1[0] = ((iVec1[1] + iRec1[1]) % 65536);
				output[i] = sinf((9.58738e-05f * float(iRec1[0])));
				// post processing
				iRec1[1] = iRec1[0];
				iVec1[1] = iVec1[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	static float 	ftbl0[65536];
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec2[2];
	float 	fConst13;
	float 	fConst15;
	float 	fConst17;
	FAUSTFLOAT 	fslider1;
	int 	iRec6[2];
	FAUSTFLOAT 	fslider2;
	float 	fRec7[2];
	int 	iRec4[2];
	FAUSTFLOAT 	fslider3;
	float 	fConst18;
	float 	fRec10[2];
	float 	fRec9[2];
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	int 	iRec11[2];
	int 	iRec13[2];
	int 	iRec12[2];
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fbargraph1;
	int 	iRec14[2];
	float 	fRec15[2];
	float 	fRec16[2];
	float 	fRec8[2];
	float 	fRec5[2];
	float 	fRec3[3];
	float 	fConst23;
	FAUSTFLOAT 	fslider4;
	float 	fRec17[2];
	FAUSTFLOAT 	fslider5;
	int 	iRec21[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec22[2];
	int 	iRec19[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec25[2];
	float 	fRec24[2];
	int 	iRec26[2];
	int 	iRec27[2];
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fbargraph3;
	int 	iRec28[2];
	float 	fRec29[2];
	float 	fRec30[2];
	float 	fRec23[2];
	float 	fRec20[2];
	float 	fRec18[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec31[2];
	FAUSTFLOAT 	fslider9;
	int 	iRec35[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec36[2];
	int 	iRec33[2];
	FAUSTFLOAT 	fslider11;
	float 	fRec39[2];
	float 	fRec38[2];
	int 	iRec40[2];
	int 	iRec41[2];
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fbargraph5;
	int 	iRec42[2];
	float 	fRec43[2];
	float 	fRec44[2];
	float 	fRec37[2];
	float 	fRec34[2];
	float 	fRec32[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec45[2];
	FAUSTFLOAT 	fslider13;
	int 	iRec49[2];
	FAUSTFLOAT 	fslider14;
	float 	fRec50[2];
	int 	iRec47[2];
	FAUSTFLOAT 	fslider15;
	float 	fRec53[2];
	float 	fRec52[2];
	int 	iRec54[2];
	int 	iRec55[2];
	FAUSTFLOAT 	fbargraph6;
	FAUSTFLOAT 	fbargraph7;
	int 	iRec56[2];
	float 	fRec57[2];
	float 	fRec58[2];
	float 	fRec51[2];
	float 	fRec48[2];
	float 	fRec46[3];
	FAUSTFLOAT 	fslider16;
	float 	fRec59[2];
	FAUSTFLOAT 	fslider17;
	int 	iRec63[2];
	FAUSTFLOAT 	fslider18;
	float 	fRec64[2];
	int 	iRec61[2];
	FAUSTFLOAT 	fslider19;
	float 	fRec67[2];
	float 	fRec66[2];
	int 	iRec68[2];
	int 	iRec69[2];
	FAUSTFLOAT 	fbargraph8;
	FAUSTFLOAT 	fbargraph9;
	int 	iRec70[2];
	float 	fRec71[2];
	float 	fRec72[2];
	float 	fRec65[2];
	float 	fRec62[2];
	float 	fRec60[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec73[2];
	FAUSTFLOAT 	fslider21;
	int 	iRec77[2];
	FAUSTFLOAT 	fslider22;
	float 	fRec78[2];
	int 	iRec75[2];
	FAUSTFLOAT 	fslider23;
	float 	fRec81[2];
	float 	fRec80[2];
	int 	iRec82[2];
	int 	iRec83[2];
	FAUSTFLOAT 	fbargraph10;
	FAUSTFLOAT 	fbargraph11;
	int 	iRec84[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fRec79[2];
	float 	fRec76[2];
	float 	fRec74[3];
	float 	fRec0[3];
	float 	fConst24;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.10.0");
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
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate) {
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(65536,ftbl0);
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
		fConst9 = (8.175799f / fConst0);
		float 	fConst10 = powf((62.831852f / fConst0),2.0f);
		float 	fConst11 = ((fConst10 * ((0.2033f * fConst10) + 0.31755f)) + 1.0f);
		float 	fConst12 = powf(fConst11,2.0f);
		fConst13 = (2.0f * ((3947.8418f * (fConst12 / fConst1)) + -1.0f));
		float 	fConst14 = (3947.8418f * (fConst11 / fConst0));
		fConst15 = (((fConst11 * (fConst14 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst16 = (((fConst11 * (fConst14 + 88.49557f)) / fConst0) + 1.0f);
		fConst17 = (1.0f / fConst16);
		fConst18 = (0.1f * fConst0);
		fConst19 = (0.05f * fConst0);
		fConst20 = (0.5f * fConst0);
		fConst21 = (1e+01f * fConst0);
		fConst22 = (0.01f * fConst0);
		fConst23 = (fConst12 / (fConst1 * fConst16));
		fConst24 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) iRec19[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) iRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) iRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) iRec33[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) iRec40[i] = 0;
		for (int i=0; i<2; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<3; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) iRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) iRec47[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<3; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) iRec68[i] = 0;
		for (int i=0; i<2; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) iRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<3; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) iRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) iRec75[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) iRec82[i] = 0;
		for (int i=0; i<2; i++) iRec83[i] = 0;
		for (int i=0; i<2; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<3; i++) fRec74[i] = 0;
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
		synth_interface.pres[0] = &fslider21;
		synth_interface.vpres[0] = &fslider22;
		synth_interface.but_y[0] = &fslider23;
		synth_interface.note[1] = &fslider16;
		synth_interface.pres[1] = &fslider17;
		synth_interface.vpres[1] = &fslider18;
		synth_interface.but_y[1] = &fslider19;
		synth_interface.note[2] = &fslider12;
		synth_interface.pres[2] = &fslider13;
		synth_interface.vpres[2] = &fslider14;
		synth_interface.but_y[2] = &fslider15;
		synth_interface.note[3] = &fslider8;
		synth_interface.pres[3] = &fslider9;
		synth_interface.vpres[3] = &fslider10;
		synth_interface.but_y[3] = &fslider11;
		synth_interface.note[4] = &fslider4;
		synth_interface.pres[4] = &fslider5;
		synth_interface.vpres[4] = &fslider6;
		synth_interface.but_y[4] = &fslider7;
		synth_interface.note[5] = &fslider0;
		synth_interface.pres[5] = &fslider1;
		synth_interface.vpres[5] = &fslider2;
		synth_interface.but_y[5] = &fslider3;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = (fConst9 * fastpow2((0.083333336f * float(fslider0))));
		float 	fSlow1 = float(fslider1);
		int 	iSlow2 = (((fSlow1 >= 0.1f)) ? 1 : 0);
		float 	fSlow3 = float(fslider2);
		int 	iSlow4 = (fSlow1 <= 0.1f);
		int 	iSlow5 = ((iSlow4) ? 0 : 2);
		int 	iSlow6 = (fSlow1 <= 0.0f);
		float 	fSlow7 = min((2.0f * float(fslider3)), 1.0f);
		float 	fSlow8 = fabsf(fSlow7);
		float 	fSlow9 = (((fSlow8 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow10 = ((fSlow7 > 0.0f) - (fSlow7 < 0.0f));
		float 	fSlow11 = (2.0f * fSlow1);
		float 	fSlow12 = (fConst9 * fastpow2((0.083333336f * float(fslider4))));
		float 	fSlow13 = float(fslider5);
		int 	iSlow14 = (((fSlow13 >= 0.1f)) ? 1 : 0);
		float 	fSlow15 = float(fslider6);
		int 	iSlow16 = (fSlow13 <= 0.1f);
		int 	iSlow17 = ((iSlow16) ? 0 : 2);
		int 	iSlow18 = (fSlow13 <= 0.0f);
		float 	fSlow19 = min((2.0f * float(fslider7)), 1.0f);
		float 	fSlow20 = fabsf(fSlow19);
		float 	fSlow21 = (((fSlow20 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow22 = ((fSlow19 > 0.0f) - (fSlow19 < 0.0f));
		float 	fSlow23 = (2.0f * fSlow13);
		float 	fSlow24 = (fConst9 * fastpow2((0.083333336f * float(fslider8))));
		float 	fSlow25 = float(fslider9);
		int 	iSlow26 = (((fSlow25 >= 0.1f)) ? 1 : 0);
		float 	fSlow27 = float(fslider10);
		int 	iSlow28 = (fSlow25 <= 0.1f);
		int 	iSlow29 = ((iSlow28) ? 0 : 2);
		int 	iSlow30 = (fSlow25 <= 0.0f);
		float 	fSlow31 = min((2.0f * float(fslider11)), 1.0f);
		float 	fSlow32 = fabsf(fSlow31);
		float 	fSlow33 = (((fSlow32 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow34 = ((fSlow31 > 0.0f) - (fSlow31 < 0.0f));
		float 	fSlow35 = (2.0f * fSlow25);
		float 	fSlow36 = (fConst9 * fastpow2((0.083333336f * float(fslider12))));
		float 	fSlow37 = float(fslider13);
		int 	iSlow38 = (((fSlow37 >= 0.1f)) ? 1 : 0);
		float 	fSlow39 = float(fslider14);
		int 	iSlow40 = (fSlow37 <= 0.1f);
		int 	iSlow41 = ((iSlow40) ? 0 : 2);
		int 	iSlow42 = (fSlow37 <= 0.0f);
		float 	fSlow43 = min((2.0f * float(fslider15)), 1.0f);
		float 	fSlow44 = fabsf(fSlow43);
		float 	fSlow45 = (((fSlow44 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow46 = ((fSlow43 > 0.0f) - (fSlow43 < 0.0f));
		float 	fSlow47 = (2.0f * fSlow37);
		float 	fSlow48 = (fConst9 * fastpow2((0.083333336f * float(fslider16))));
		float 	fSlow49 = float(fslider17);
		int 	iSlow50 = (((fSlow49 >= 0.1f)) ? 1 : 0);
		float 	fSlow51 = float(fslider18);
		int 	iSlow52 = (fSlow49 <= 0.1f);
		int 	iSlow53 = ((iSlow52) ? 0 : 2);
		int 	iSlow54 = (fSlow49 <= 0.0f);
		float 	fSlow55 = min((2.0f * float(fslider19)), 1.0f);
		float 	fSlow56 = fabsf(fSlow55);
		float 	fSlow57 = (((fSlow56 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow58 = ((fSlow55 > 0.0f) - (fSlow55 < 0.0f));
		float 	fSlow59 = (2.0f * fSlow49);
		float 	fSlow60 = (fConst9 * fastpow2((0.083333336f * float(fslider20))));
		float 	fSlow61 = float(fslider21);
		int 	iSlow62 = (((fSlow61 >= 0.1f)) ? 1 : 0);
		float 	fSlow63 = float(fslider22);
		int 	iSlow64 = (fSlow61 <= 0.1f);
		int 	iSlow65 = ((iSlow64) ? 0 : 2);
		int 	iSlow66 = (fSlow61 <= 0.0f);
		float 	fSlow67 = min((2.0f * float(fslider23)), 1.0f);
		float 	fSlow68 = fabsf(fSlow67);
		float 	fSlow69 = (((fSlow68 >= 0.2f)) ? fConst18 : fConst0);
		int 	iSlow70 = ((fSlow67 > 0.0f) - (fSlow67 < 0.0f));
		float 	fSlow71 = (2.0f * fSlow61);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp0 = (1 - iVec0[1]);
			float 	fTemp1 = ((iTemp0) ? 0.0f : (fSlow0 + fRec2[1]));
			fRec2[0] = (fTemp1 - floorf(fTemp1));
			iRec6[0] = iRec4[1];
			fRec7[0] = (((iRec6[1] != iRec4[1])) ? fSlow3 : max(fRec7[1], fSlow3));
			float 	fTemp2 = (2.0f * fRec7[0]);
			int 	iTemp3 = (fSlow1 >= fRec5[1]);
			int 	iTemp4 = (((iRec4[1] >= 4)) ? (((iRec4[1] >= 6)) ? ((iSlow4) ? 3 : ((iTemp3) ? 5 : 6)) : (((iRec4[1] >= 5)) ? ((iSlow4) ? 3 : (((fSlow1 <= fRec5[1])) ? 6 : 5)) : (((fRec5[1] <= 0.1f)) ? 0 : 4))) : (((iRec4[1] >= 2)) ? (((iRec4[1] >= 3)) ? (((iSlow6 & (fRec5[1] <= 0.001f))) ? 0 : (((fSlow1 > fRec5[1])) ? 1 : 3)) : ((iTemp3) ? 5 : iSlow5)) : (((iRec4[1] >= 1)) ? (((fRec5[1] >= fTemp2)) ? 2 : 1) : iSlow2)));
			iRec4[0] = iTemp4;
			float 	fTemp5 = (1.0f / (((iSlow10 == ((fRec9[1] > 0.0f) - (fRec9[1] < 0.0f)))) ? (((fSlow8 >= fabsf(fRec9[1]))) ? fConst18 : fConst0) : fSlow9));
			float 	fTemp6 = (fRec10[1] - fTemp5);
			float 	fTemp7 = (fRec10[1] + fTemp5);
			fRec10[0] = (((fTemp7 < fSlow7)) ? fTemp7 : (((fTemp6 > fSlow7)) ? fTemp6 : fSlow7));
			fRec9[0] = fRec10[0];
			float 	fTemp8 = fabsf(fRec9[0]);
			float 	fTemp9 = ((((iTemp4 >= 4)) ? (((iTemp4 >= 6)) ? fConst0 : (((iTemp4 >= 5)) ? fConst0 : fConst22)) : (((iTemp4 >= 2)) ? (((iTemp4 >= 3)) ? fConst21 : fConst20) : (((iTemp4 >= 1)) ? fConst19 : 0.0f))) * (fTemp8 + (1.0f - fTemp8)));
			iRec11[0] = iRec4[1];
			iRec13[0] = (iRec13[1] + 1);
			int 	iTemp10 = (iRec13[0] + -1);
			iRec12[0] = (((iRec11[1] != iRec4[1])) ? iTemp10 : iRec12[1]);
			fbargraph0 = (((fTemp9 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec12[0]))) / fTemp9) : 0.0f);
			fbargraph1 = floorf((2e+01f * fbargraph0));
			float 	fTemp11 = fbargraph1;
			float 	fTemp12 = (((fTemp11 >= 1e+01f)) ? (((fTemp11 >= 15.0f)) ? (((fTemp11 >= 18.0f)) ? (((fTemp11 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp11 >= 17.0f)) ? 0.03f : (((fTemp11 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp11 >= 13.0f)) ? (((fTemp11 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp11 >= 12.0f)) ? 0.14f : (((fTemp11 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp11 >= 5.0f)) ? (((fTemp11 >= 8.0f)) ? (((fTemp11 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp11 >= 7.0f)) ? 0.3f : (((fTemp11 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp11 >= 3.0f)) ? (((fTemp11 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp11 >= 2.0f)) ? 0.64f : (((fTemp11 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec14[0] = iRec4[1];
			int 	iTemp13 = (iRec14[1] == iRec4[1]);
			int 	iTemp14 = (iRec4[1] == 0);
			fRec15[0] = ((iTemp14) ? fSlow1 : ((iTemp13) ? min(min(fRec15[1], fSlow1), fRec5[1]) : min(fSlow1, fRec5[1])));
			int 	iTemp15 = (iRec4[1] == 1);
			fRec16[0] = ((iTemp14) ? fSlow1 : ((iTemp15) ? ((iTemp13) ? max(max(fRec16[1], fSlow11), fRec5[1]) : max(fSlow11, fRec5[1])) : ((iTemp13) ? max(max(fRec16[1], fSlow1), fRec5[1]) : max(fSlow1, fRec5[1]))));
			int 	iTemp16 = (iRec4[1] == 3);
			float 	fTemp17 = ((iTemp15) ? min(1.0f, fTemp2) : ((iTemp14) ? 0.0f : ((iTemp16) ? (fRec16[0] * fTemp12) : fSlow1)));
			float 	fTemp18 = (fTemp11 + -1.0f);
			float 	fTemp19 = ((((fTemp11 > 0.0f)) ? (((fTemp18 >= 1e+01f)) ? (((fTemp18 >= 15.0f)) ? (((fTemp18 >= 18.0f)) ? (((fTemp18 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp18 >= 17.0f)) ? 0.03f : (((fTemp18 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp18 >= 13.0f)) ? (((fTemp18 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp18 >= 12.0f)) ? 0.14f : (((fTemp18 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp18 >= 5.0f)) ? (((fTemp18 >= 8.0f)) ? (((fTemp18 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp18 >= 7.0f)) ? 0.3f : (((fTemp18 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp18 >= 3.0f)) ? (((fTemp18 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp18 >= 2.0f)) ? 0.64f : (((fTemp18 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp12);
			float 	fTemp20 = (1.0f / ((iTemp14) ? 0.0001f : ((iTemp16) ? (((fTemp19 > 0.0f)) ? (0.05f * (fTemp9 / fTemp19)) : 0.0f) : fTemp9)));
			float 	fTemp21 = (fRec8[1] - fTemp20);
			float 	fTemp22 = (fRec8[1] + fTemp20);
			fRec8[0] = (((fTemp22 < fTemp17)) ? fTemp22 : (((fTemp21 > fTemp17)) ? fTemp21 : fTemp17));
			fRec5[0] = fRec8[0];
			fRec3[0] = (fRec5[0] - (fConst17 * ((fConst15 * fRec3[2]) + (fConst13 * fRec3[1]))));
			float 	fTemp23 = ((iTemp0) ? 0.0f : (fSlow12 + fRec17[1]));
			fRec17[0] = (fTemp23 - floorf(fTemp23));
			iRec21[0] = iRec19[1];
			fRec22[0] = (((iRec21[1] != iRec19[1])) ? fSlow15 : max(fRec22[1], fSlow15));
			float 	fTemp24 = (2.0f * fRec22[0]);
			int 	iTemp25 = (fSlow13 >= fRec20[1]);
			int 	iTemp26 = (((iRec19[1] >= 4)) ? (((iRec19[1] >= 6)) ? ((iSlow16) ? 3 : ((iTemp25) ? 5 : 6)) : (((iRec19[1] >= 5)) ? ((iSlow16) ? 3 : (((fSlow13 <= fRec20[1])) ? 6 : 5)) : (((fRec20[1] <= 0.1f)) ? 0 : 4))) : (((iRec19[1] >= 2)) ? (((iRec19[1] >= 3)) ? (((iSlow18 & (fRec20[1] <= 0.001f))) ? 0 : (((fSlow13 > fRec20[1])) ? 1 : 3)) : ((iTemp25) ? 5 : iSlow17)) : (((iRec19[1] >= 1)) ? (((fRec20[1] >= fTemp24)) ? 2 : 1) : iSlow14)));
			iRec19[0] = iTemp26;
			float 	fTemp27 = (1.0f / (((iSlow22 == ((fRec24[1] > 0.0f) - (fRec24[1] < 0.0f)))) ? (((fSlow20 >= fabsf(fRec24[1]))) ? fConst18 : fConst0) : fSlow21));
			float 	fTemp28 = (fRec25[1] - fTemp27);
			float 	fTemp29 = (fRec25[1] + fTemp27);
			fRec25[0] = (((fTemp29 < fSlow19)) ? fTemp29 : (((fTemp28 > fSlow19)) ? fTemp28 : fSlow19));
			fRec24[0] = fRec25[0];
			float 	fTemp30 = fabsf(fRec24[0]);
			float 	fTemp31 = ((((iTemp26 >= 4)) ? (((iTemp26 >= 6)) ? fConst0 : (((iTemp26 >= 5)) ? fConst0 : fConst22)) : (((iTemp26 >= 2)) ? (((iTemp26 >= 3)) ? fConst21 : fConst20) : (((iTemp26 >= 1)) ? fConst19 : 0.0f))) * (fTemp30 + (1.0f - fTemp30)));
			iRec26[0] = iRec19[1];
			iRec27[0] = (((iRec26[1] != iRec19[1])) ? iTemp10 : iRec27[1]);
			fbargraph2 = (((fTemp31 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec27[0]))) / fTemp31) : 0.0f);
			fbargraph3 = floorf((2e+01f * fbargraph2));
			float 	fTemp32 = fbargraph3;
			float 	fTemp33 = (((fTemp32 >= 1e+01f)) ? (((fTemp32 >= 15.0f)) ? (((fTemp32 >= 18.0f)) ? (((fTemp32 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp32 >= 17.0f)) ? 0.03f : (((fTemp32 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp32 >= 13.0f)) ? (((fTemp32 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp32 >= 12.0f)) ? 0.14f : (((fTemp32 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp32 >= 5.0f)) ? (((fTemp32 >= 8.0f)) ? (((fTemp32 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp32 >= 7.0f)) ? 0.3f : (((fTemp32 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp32 >= 3.0f)) ? (((fTemp32 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp32 >= 2.0f)) ? 0.64f : (((fTemp32 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec28[0] = iRec19[1];
			int 	iTemp34 = (iRec28[1] == iRec19[1]);
			int 	iTemp35 = (iRec19[1] == 0);
			fRec29[0] = ((iTemp35) ? fSlow13 : ((iTemp34) ? min(min(fRec29[1], fSlow13), fRec20[1]) : min(fSlow13, fRec20[1])));
			int 	iTemp36 = (iRec19[1] == 1);
			fRec30[0] = ((iTemp35) ? fSlow13 : ((iTemp36) ? ((iTemp34) ? max(max(fRec30[1], fSlow23), fRec20[1]) : max(fSlow23, fRec20[1])) : ((iTemp34) ? max(max(fRec30[1], fSlow13), fRec20[1]) : max(fSlow13, fRec20[1]))));
			int 	iTemp37 = (iRec19[1] == 3);
			float 	fTemp38 = ((iTemp36) ? min(1.0f, fTemp24) : ((iTemp35) ? 0.0f : ((iTemp37) ? (fRec30[0] * fTemp33) : fSlow13)));
			float 	fTemp39 = (fTemp32 + -1.0f);
			float 	fTemp40 = ((((fTemp32 > 0.0f)) ? (((fTemp39 >= 1e+01f)) ? (((fTemp39 >= 15.0f)) ? (((fTemp39 >= 18.0f)) ? (((fTemp39 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp39 >= 17.0f)) ? 0.03f : (((fTemp39 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp39 >= 13.0f)) ? (((fTemp39 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp39 >= 12.0f)) ? 0.14f : (((fTemp39 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp39 >= 5.0f)) ? (((fTemp39 >= 8.0f)) ? (((fTemp39 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp39 >= 7.0f)) ? 0.3f : (((fTemp39 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp39 >= 3.0f)) ? (((fTemp39 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp39 >= 2.0f)) ? 0.64f : (((fTemp39 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp33);
			float 	fTemp41 = (1.0f / ((iTemp35) ? 0.0001f : ((iTemp37) ? (((fTemp40 > 0.0f)) ? (0.05f * (fTemp31 / fTemp40)) : 0.0f) : fTemp31)));
			float 	fTemp42 = (fRec23[1] - fTemp41);
			float 	fTemp43 = (fRec23[1] + fTemp41);
			fRec23[0] = (((fTemp43 < fTemp38)) ? fTemp43 : (((fTemp42 > fTemp38)) ? fTemp42 : fTemp38));
			fRec20[0] = fRec23[0];
			fRec18[0] = (fRec20[0] - (fConst17 * ((fConst15 * fRec18[2]) + (fConst13 * fRec18[1]))));
			float 	fTemp44 = ((iTemp0) ? 0.0f : (fSlow24 + fRec31[1]));
			fRec31[0] = (fTemp44 - floorf(fTemp44));
			iRec35[0] = iRec33[1];
			fRec36[0] = (((iRec35[1] != iRec33[1])) ? fSlow27 : max(fRec36[1], fSlow27));
			float 	fTemp45 = (2.0f * fRec36[0]);
			int 	iTemp46 = (fSlow25 >= fRec34[1]);
			int 	iTemp47 = (((iRec33[1] >= 4)) ? (((iRec33[1] >= 6)) ? ((iSlow28) ? 3 : ((iTemp46) ? 5 : 6)) : (((iRec33[1] >= 5)) ? ((iSlow28) ? 3 : (((fSlow25 <= fRec34[1])) ? 6 : 5)) : (((fRec34[1] <= 0.1f)) ? 0 : 4))) : (((iRec33[1] >= 2)) ? (((iRec33[1] >= 3)) ? (((iSlow30 & (fRec34[1] <= 0.001f))) ? 0 : (((fSlow25 > fRec34[1])) ? 1 : 3)) : ((iTemp46) ? 5 : iSlow29)) : (((iRec33[1] >= 1)) ? (((fRec34[1] >= fTemp45)) ? 2 : 1) : iSlow26)));
			iRec33[0] = iTemp47;
			float 	fTemp48 = (1.0f / (((iSlow34 == ((fRec38[1] > 0.0f) - (fRec38[1] < 0.0f)))) ? (((fSlow32 >= fabsf(fRec38[1]))) ? fConst18 : fConst0) : fSlow33));
			float 	fTemp49 = (fRec39[1] - fTemp48);
			float 	fTemp50 = (fRec39[1] + fTemp48);
			fRec39[0] = (((fTemp50 < fSlow31)) ? fTemp50 : (((fTemp49 > fSlow31)) ? fTemp49 : fSlow31));
			fRec38[0] = fRec39[0];
			float 	fTemp51 = fabsf(fRec38[0]);
			float 	fTemp52 = ((((iTemp47 >= 4)) ? (((iTemp47 >= 6)) ? fConst0 : (((iTemp47 >= 5)) ? fConst0 : fConst22)) : (((iTemp47 >= 2)) ? (((iTemp47 >= 3)) ? fConst21 : fConst20) : (((iTemp47 >= 1)) ? fConst19 : 0.0f))) * (fTemp51 + (1.0f - fTemp51)));
			iRec40[0] = iRec33[1];
			iRec41[0] = (((iRec40[1] != iRec33[1])) ? iTemp10 : iRec41[1]);
			fbargraph4 = (((fTemp52 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec41[0]))) / fTemp52) : 0.0f);
			fbargraph5 = floorf((2e+01f * fbargraph4));
			float 	fTemp53 = fbargraph5;
			float 	fTemp54 = (((fTemp53 >= 1e+01f)) ? (((fTemp53 >= 15.0f)) ? (((fTemp53 >= 18.0f)) ? (((fTemp53 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp53 >= 17.0f)) ? 0.03f : (((fTemp53 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp53 >= 13.0f)) ? (((fTemp53 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp53 >= 12.0f)) ? 0.14f : (((fTemp53 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp53 >= 5.0f)) ? (((fTemp53 >= 8.0f)) ? (((fTemp53 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp53 >= 7.0f)) ? 0.3f : (((fTemp53 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp53 >= 3.0f)) ? (((fTemp53 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp53 >= 2.0f)) ? 0.64f : (((fTemp53 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec42[0] = iRec33[1];
			int 	iTemp55 = (iRec42[1] == iRec33[1]);
			int 	iTemp56 = (iRec33[1] == 0);
			fRec43[0] = ((iTemp56) ? fSlow25 : ((iTemp55) ? min(min(fRec43[1], fSlow25), fRec34[1]) : min(fSlow25, fRec34[1])));
			int 	iTemp57 = (iRec33[1] == 1);
			fRec44[0] = ((iTemp56) ? fSlow25 : ((iTemp57) ? ((iTemp55) ? max(max(fRec44[1], fSlow35), fRec34[1]) : max(fSlow35, fRec34[1])) : ((iTemp55) ? max(max(fRec44[1], fSlow25), fRec34[1]) : max(fSlow25, fRec34[1]))));
			int 	iTemp58 = (iRec33[1] == 3);
			float 	fTemp59 = ((iTemp57) ? min(1.0f, fTemp45) : ((iTemp56) ? 0.0f : ((iTemp58) ? (fRec44[0] * fTemp54) : fSlow25)));
			float 	fTemp60 = (fTemp53 + -1.0f);
			float 	fTemp61 = ((((fTemp53 > 0.0f)) ? (((fTemp60 >= 1e+01f)) ? (((fTemp60 >= 15.0f)) ? (((fTemp60 >= 18.0f)) ? (((fTemp60 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp60 >= 17.0f)) ? 0.03f : (((fTemp60 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp60 >= 13.0f)) ? (((fTemp60 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp60 >= 12.0f)) ? 0.14f : (((fTemp60 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp60 >= 5.0f)) ? (((fTemp60 >= 8.0f)) ? (((fTemp60 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp60 >= 7.0f)) ? 0.3f : (((fTemp60 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp60 >= 3.0f)) ? (((fTemp60 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp60 >= 2.0f)) ? 0.64f : (((fTemp60 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp54);
			float 	fTemp62 = (1.0f / ((iTemp56) ? 0.0001f : ((iTemp58) ? (((fTemp61 > 0.0f)) ? (0.05f * (fTemp52 / fTemp61)) : 0.0f) : fTemp52)));
			float 	fTemp63 = (fRec37[1] - fTemp62);
			float 	fTemp64 = (fRec37[1] + fTemp62);
			fRec37[0] = (((fTemp64 < fTemp59)) ? fTemp64 : (((fTemp63 > fTemp59)) ? fTemp63 : fTemp59));
			fRec34[0] = fRec37[0];
			fRec32[0] = (fRec34[0] - (fConst17 * ((fConst15 * fRec32[2]) + (fConst13 * fRec32[1]))));
			float 	fTemp65 = ((iTemp0) ? 0.0f : (fSlow36 + fRec45[1]));
			fRec45[0] = (fTemp65 - floorf(fTemp65));
			iRec49[0] = iRec47[1];
			fRec50[0] = (((iRec49[1] != iRec47[1])) ? fSlow39 : max(fRec50[1], fSlow39));
			float 	fTemp66 = (2.0f * fRec50[0]);
			int 	iTemp67 = (fSlow37 >= fRec48[1]);
			int 	iTemp68 = (((iRec47[1] >= 4)) ? (((iRec47[1] >= 6)) ? ((iSlow40) ? 3 : ((iTemp67) ? 5 : 6)) : (((iRec47[1] >= 5)) ? ((iSlow40) ? 3 : (((fSlow37 <= fRec48[1])) ? 6 : 5)) : (((fRec48[1] <= 0.1f)) ? 0 : 4))) : (((iRec47[1] >= 2)) ? (((iRec47[1] >= 3)) ? (((iSlow42 & (fRec48[1] <= 0.001f))) ? 0 : (((fSlow37 > fRec48[1])) ? 1 : 3)) : ((iTemp67) ? 5 : iSlow41)) : (((iRec47[1] >= 1)) ? (((fRec48[1] >= fTemp66)) ? 2 : 1) : iSlow38)));
			iRec47[0] = iTemp68;
			float 	fTemp69 = (1.0f / (((iSlow46 == ((fRec52[1] > 0.0f) - (fRec52[1] < 0.0f)))) ? (((fSlow44 >= fabsf(fRec52[1]))) ? fConst18 : fConst0) : fSlow45));
			float 	fTemp70 = (fRec53[1] - fTemp69);
			float 	fTemp71 = (fRec53[1] + fTemp69);
			fRec53[0] = (((fTemp71 < fSlow43)) ? fTemp71 : (((fTemp70 > fSlow43)) ? fTemp70 : fSlow43));
			fRec52[0] = fRec53[0];
			float 	fTemp72 = fabsf(fRec52[0]);
			float 	fTemp73 = ((((iTemp68 >= 4)) ? (((iTemp68 >= 6)) ? fConst0 : (((iTemp68 >= 5)) ? fConst0 : fConst22)) : (((iTemp68 >= 2)) ? (((iTemp68 >= 3)) ? fConst21 : fConst20) : (((iTemp68 >= 1)) ? fConst19 : 0.0f))) * (fTemp72 + (1.0f - fTemp72)));
			iRec54[0] = iRec47[1];
			iRec55[0] = (((iRec54[1] != iRec47[1])) ? iTemp10 : iRec55[1]);
			fbargraph6 = (((fTemp73 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec55[0]))) / fTemp73) : 0.0f);
			fbargraph7 = floorf((2e+01f * fbargraph6));
			float 	fTemp74 = fbargraph7;
			float 	fTemp75 = (((fTemp74 >= 1e+01f)) ? (((fTemp74 >= 15.0f)) ? (((fTemp74 >= 18.0f)) ? (((fTemp74 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp74 >= 17.0f)) ? 0.03f : (((fTemp74 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp74 >= 13.0f)) ? (((fTemp74 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp74 >= 12.0f)) ? 0.14f : (((fTemp74 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp74 >= 5.0f)) ? (((fTemp74 >= 8.0f)) ? (((fTemp74 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp74 >= 7.0f)) ? 0.3f : (((fTemp74 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp74 >= 3.0f)) ? (((fTemp74 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp74 >= 2.0f)) ? 0.64f : (((fTemp74 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec56[0] = iRec47[1];
			int 	iTemp76 = (iRec56[1] == iRec47[1]);
			int 	iTemp77 = (iRec47[1] == 0);
			fRec57[0] = ((iTemp77) ? fSlow37 : ((iTemp76) ? min(min(fRec57[1], fSlow37), fRec48[1]) : min(fSlow37, fRec48[1])));
			int 	iTemp78 = (iRec47[1] == 1);
			fRec58[0] = ((iTemp77) ? fSlow37 : ((iTemp78) ? ((iTemp76) ? max(max(fRec58[1], fSlow47), fRec48[1]) : max(fSlow47, fRec48[1])) : ((iTemp76) ? max(max(fRec58[1], fSlow37), fRec48[1]) : max(fSlow37, fRec48[1]))));
			int 	iTemp79 = (iRec47[1] == 3);
			float 	fTemp80 = ((iTemp78) ? min(1.0f, fTemp66) : ((iTemp77) ? 0.0f : ((iTemp79) ? (fRec58[0] * fTemp75) : fSlow37)));
			float 	fTemp81 = (fTemp74 + -1.0f);
			float 	fTemp82 = ((((fTemp74 > 0.0f)) ? (((fTemp81 >= 1e+01f)) ? (((fTemp81 >= 15.0f)) ? (((fTemp81 >= 18.0f)) ? (((fTemp81 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp81 >= 17.0f)) ? 0.03f : (((fTemp81 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp81 >= 13.0f)) ? (((fTemp81 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp81 >= 12.0f)) ? 0.14f : (((fTemp81 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp81 >= 5.0f)) ? (((fTemp81 >= 8.0f)) ? (((fTemp81 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp81 >= 7.0f)) ? 0.3f : (((fTemp81 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp81 >= 3.0f)) ? (((fTemp81 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp81 >= 2.0f)) ? 0.64f : (((fTemp81 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp75);
			float 	fTemp83 = (1.0f / ((iTemp77) ? 0.0001f : ((iTemp79) ? (((fTemp82 > 0.0f)) ? (0.05f * (fTemp73 / fTemp82)) : 0.0f) : fTemp73)));
			float 	fTemp84 = (fRec51[1] - fTemp83);
			float 	fTemp85 = (fRec51[1] + fTemp83);
			fRec51[0] = (((fTemp85 < fTemp80)) ? fTemp85 : (((fTemp84 > fTemp80)) ? fTemp84 : fTemp80));
			fRec48[0] = fRec51[0];
			fRec46[0] = (fRec48[0] - (fConst17 * ((fConst15 * fRec46[2]) + (fConst13 * fRec46[1]))));
			float 	fTemp86 = ((iTemp0) ? 0.0f : (fSlow48 + fRec59[1]));
			fRec59[0] = (fTemp86 - floorf(fTemp86));
			iRec63[0] = iRec61[1];
			fRec64[0] = (((iRec63[1] != iRec61[1])) ? fSlow51 : max(fRec64[1], fSlow51));
			float 	fTemp87 = (2.0f * fRec64[0]);
			int 	iTemp88 = (fSlow49 >= fRec62[1]);
			int 	iTemp89 = (((iRec61[1] >= 4)) ? (((iRec61[1] >= 6)) ? ((iSlow52) ? 3 : ((iTemp88) ? 5 : 6)) : (((iRec61[1] >= 5)) ? ((iSlow52) ? 3 : (((fSlow49 <= fRec62[1])) ? 6 : 5)) : (((fRec62[1] <= 0.1f)) ? 0 : 4))) : (((iRec61[1] >= 2)) ? (((iRec61[1] >= 3)) ? (((iSlow54 & (fRec62[1] <= 0.001f))) ? 0 : (((fSlow49 > fRec62[1])) ? 1 : 3)) : ((iTemp88) ? 5 : iSlow53)) : (((iRec61[1] >= 1)) ? (((fRec62[1] >= fTemp87)) ? 2 : 1) : iSlow50)));
			iRec61[0] = iTemp89;
			float 	fTemp90 = (1.0f / (((iSlow58 == ((fRec66[1] > 0.0f) - (fRec66[1] < 0.0f)))) ? (((fSlow56 >= fabsf(fRec66[1]))) ? fConst18 : fConst0) : fSlow57));
			float 	fTemp91 = (fRec67[1] - fTemp90);
			float 	fTemp92 = (fRec67[1] + fTemp90);
			fRec67[0] = (((fTemp92 < fSlow55)) ? fTemp92 : (((fTemp91 > fSlow55)) ? fTemp91 : fSlow55));
			fRec66[0] = fRec67[0];
			float 	fTemp93 = fabsf(fRec66[0]);
			float 	fTemp94 = ((((iTemp89 >= 4)) ? (((iTemp89 >= 6)) ? fConst0 : (((iTemp89 >= 5)) ? fConst0 : fConst22)) : (((iTemp89 >= 2)) ? (((iTemp89 >= 3)) ? fConst21 : fConst20) : (((iTemp89 >= 1)) ? fConst19 : 0.0f))) * (fTemp93 + (1.0f - fTemp93)));
			iRec68[0] = iRec61[1];
			iRec69[0] = (((iRec68[1] != iRec61[1])) ? iTemp10 : iRec69[1]);
			fbargraph8 = (((fTemp94 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec69[0]))) / fTemp94) : 0.0f);
			fbargraph9 = floorf((2e+01f * fbargraph8));
			float 	fTemp95 = fbargraph9;
			float 	fTemp96 = (((fTemp95 >= 1e+01f)) ? (((fTemp95 >= 15.0f)) ? (((fTemp95 >= 18.0f)) ? (((fTemp95 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp95 >= 17.0f)) ? 0.03f : (((fTemp95 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp95 >= 13.0f)) ? (((fTemp95 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp95 >= 12.0f)) ? 0.14f : (((fTemp95 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp95 >= 5.0f)) ? (((fTemp95 >= 8.0f)) ? (((fTemp95 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp95 >= 7.0f)) ? 0.3f : (((fTemp95 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp95 >= 3.0f)) ? (((fTemp95 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp95 >= 2.0f)) ? 0.64f : (((fTemp95 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec70[0] = iRec61[1];
			int 	iTemp97 = (iRec70[1] == iRec61[1]);
			int 	iTemp98 = (iRec61[1] == 0);
			fRec71[0] = ((iTemp98) ? fSlow49 : ((iTemp97) ? min(min(fRec71[1], fSlow49), fRec62[1]) : min(fSlow49, fRec62[1])));
			int 	iTemp99 = (iRec61[1] == 1);
			fRec72[0] = ((iTemp98) ? fSlow49 : ((iTemp99) ? ((iTemp97) ? max(max(fRec72[1], fSlow59), fRec62[1]) : max(fSlow59, fRec62[1])) : ((iTemp97) ? max(max(fRec72[1], fSlow49), fRec62[1]) : max(fSlow49, fRec62[1]))));
			int 	iTemp100 = (iRec61[1] == 3);
			float 	fTemp101 = ((iTemp99) ? min(1.0f, fTemp87) : ((iTemp98) ? 0.0f : ((iTemp100) ? (fRec72[0] * fTemp96) : fSlow49)));
			float 	fTemp102 = (fTemp95 + -1.0f);
			float 	fTemp103 = ((((fTemp95 > 0.0f)) ? (((fTemp102 >= 1e+01f)) ? (((fTemp102 >= 15.0f)) ? (((fTemp102 >= 18.0f)) ? (((fTemp102 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp102 >= 17.0f)) ? 0.03f : (((fTemp102 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp102 >= 13.0f)) ? (((fTemp102 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp102 >= 12.0f)) ? 0.14f : (((fTemp102 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp102 >= 5.0f)) ? (((fTemp102 >= 8.0f)) ? (((fTemp102 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp102 >= 7.0f)) ? 0.3f : (((fTemp102 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp102 >= 3.0f)) ? (((fTemp102 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp102 >= 2.0f)) ? 0.64f : (((fTemp102 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp96);
			float 	fTemp104 = (1.0f / ((iTemp98) ? 0.0001f : ((iTemp100) ? (((fTemp103 > 0.0f)) ? (0.05f * (fTemp94 / fTemp103)) : 0.0f) : fTemp94)));
			float 	fTemp105 = (fRec65[1] - fTemp104);
			float 	fTemp106 = (fRec65[1] + fTemp104);
			fRec65[0] = (((fTemp106 < fTemp101)) ? fTemp106 : (((fTemp105 > fTemp101)) ? fTemp105 : fTemp101));
			fRec62[0] = fRec65[0];
			fRec60[0] = (fRec62[0] - (fConst17 * ((fConst15 * fRec60[2]) + (fConst13 * fRec60[1]))));
			float 	fTemp107 = ((iTemp0) ? 0.0f : (fSlow60 + fRec73[1]));
			fRec73[0] = (fTemp107 - floorf(fTemp107));
			iRec77[0] = iRec75[1];
			fRec78[0] = (((iRec77[1] != iRec75[1])) ? fSlow63 : max(fRec78[1], fSlow63));
			float 	fTemp108 = (2.0f * fRec78[0]);
			int 	iTemp109 = (fSlow61 >= fRec76[1]);
			int 	iTemp110 = (((iRec75[1] >= 4)) ? (((iRec75[1] >= 6)) ? ((iSlow64) ? 3 : ((iTemp109) ? 5 : 6)) : (((iRec75[1] >= 5)) ? ((iSlow64) ? 3 : (((fSlow61 <= fRec76[1])) ? 6 : 5)) : (((fRec76[1] <= 0.1f)) ? 0 : 4))) : (((iRec75[1] >= 2)) ? (((iRec75[1] >= 3)) ? (((iSlow66 & (fRec76[1] <= 0.001f))) ? 0 : (((fSlow61 > fRec76[1])) ? 1 : 3)) : ((iTemp109) ? 5 : iSlow65)) : (((iRec75[1] >= 1)) ? (((fRec76[1] >= fTemp108)) ? 2 : 1) : iSlow62)));
			iRec75[0] = iTemp110;
			float 	fTemp111 = (1.0f / (((iSlow70 == ((fRec80[1] > 0.0f) - (fRec80[1] < 0.0f)))) ? (((fSlow68 >= fabsf(fRec80[1]))) ? fConst18 : fConst0) : fSlow69));
			float 	fTemp112 = (fRec81[1] - fTemp111);
			float 	fTemp113 = (fRec81[1] + fTemp111);
			fRec81[0] = (((fTemp113 < fSlow67)) ? fTemp113 : (((fTemp112 > fSlow67)) ? fTemp112 : fSlow67));
			fRec80[0] = fRec81[0];
			float 	fTemp114 = fabsf(fRec80[0]);
			float 	fTemp115 = ((((iTemp110 >= 4)) ? (((iTemp110 >= 6)) ? fConst0 : (((iTemp110 >= 5)) ? fConst0 : fConst22)) : (((iTemp110 >= 2)) ? (((iTemp110 >= 3)) ? fConst21 : fConst20) : (((iTemp110 >= 1)) ? fConst19 : 0.0f))) * (fTemp114 + (1.0f - fTemp114)));
			iRec82[0] = iRec75[1];
			iRec83[0] = (((iRec82[1] != iRec75[1])) ? iTemp10 : iRec83[1]);
			fbargraph10 = (((fTemp115 > 0.0f)) ? (float((iRec13[0] + (-1 - iRec83[0]))) / fTemp115) : 0.0f);
			fbargraph11 = floorf((2e+01f * fbargraph10));
			float 	fTemp116 = fbargraph11;
			float 	fTemp117 = (((fTemp116 >= 1e+01f)) ? (((fTemp116 >= 15.0f)) ? (((fTemp116 >= 18.0f)) ? (((fTemp116 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp116 >= 17.0f)) ? 0.03f : (((fTemp116 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp116 >= 13.0f)) ? (((fTemp116 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp116 >= 12.0f)) ? 0.14f : (((fTemp116 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp116 >= 5.0f)) ? (((fTemp116 >= 8.0f)) ? (((fTemp116 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp116 >= 7.0f)) ? 0.3f : (((fTemp116 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp116 >= 3.0f)) ? (((fTemp116 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp116 >= 2.0f)) ? 0.64f : (((fTemp116 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec84[0] = iRec75[1];
			int 	iTemp118 = (iRec84[1] == iRec75[1]);
			int 	iTemp119 = (iRec75[1] == 0);
			fRec85[0] = ((iTemp119) ? fSlow61 : ((iTemp118) ? min(min(fRec85[1], fSlow61), fRec76[1]) : min(fSlow61, fRec76[1])));
			int 	iTemp120 = (iRec75[1] == 1);
			fRec86[0] = ((iTemp119) ? fSlow61 : ((iTemp120) ? ((iTemp118) ? max(max(fRec86[1], fSlow71), fRec76[1]) : max(fSlow71, fRec76[1])) : ((iTemp118) ? max(max(fRec86[1], fSlow61), fRec76[1]) : max(fSlow61, fRec76[1]))));
			int 	iTemp121 = (iRec75[1] == 3);
			float 	fTemp122 = ((iTemp120) ? min(1.0f, fTemp108) : ((iTemp119) ? 0.0f : ((iTemp121) ? (fRec86[0] * fTemp117) : fSlow61)));
			float 	fTemp123 = (fTemp116 + -1.0f);
			float 	fTemp124 = ((((fTemp116 > 0.0f)) ? (((fTemp123 >= 1e+01f)) ? (((fTemp123 >= 15.0f)) ? (((fTemp123 >= 18.0f)) ? (((fTemp123 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp123 >= 17.0f)) ? 0.03f : (((fTemp123 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp123 >= 13.0f)) ? (((fTemp123 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp123 >= 12.0f)) ? 0.14f : (((fTemp123 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp123 >= 5.0f)) ? (((fTemp123 >= 8.0f)) ? (((fTemp123 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp123 >= 7.0f)) ? 0.3f : (((fTemp123 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp123 >= 3.0f)) ? (((fTemp123 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp123 >= 2.0f)) ? 0.64f : (((fTemp123 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp117);
			float 	fTemp125 = (1.0f / ((iTemp119) ? 0.0001f : ((iTemp121) ? (((fTemp124 > 0.0f)) ? (0.05f * (fTemp115 / fTemp124)) : 0.0f) : fTemp115)));
			float 	fTemp126 = (fRec79[1] - fTemp125);
			float 	fTemp127 = (fRec79[1] + fTemp125);
			fRec79[0] = (((fTemp127 < fTemp122)) ? fTemp127 : (((fTemp126 > fTemp122)) ? fTemp126 : fTemp122));
			fRec76[0] = fRec79[0];
			fRec74[0] = (fRec76[0] - (fConst17 * ((fConst15 * fRec74[2]) + (fConst13 * fRec74[1]))));
			fRec0[0] = ((1.37f * ((((((min(0.95f, (fConst23 * (((3947.8418f * fRec74[0]) + (7895.6836f * fRec74[1])) + (3947.8418f * fRec74[2])))) * ftbl0[max(0, min(int((65536.0f * fRec73[0])), 65535))]) + (min(0.95f, (fConst23 * (((3947.8418f * fRec60[0]) + (7895.6836f * fRec60[1])) + (3947.8418f * fRec60[2])))) * ftbl0[max(0, min(int((65536.0f * fRec59[0])), 65535))])) + (min(0.95f, (fConst23 * (((3947.8418f * fRec46[0]) + (7895.6836f * fRec46[1])) + (3947.8418f * fRec46[2])))) * ftbl0[max(0, min(int((65536.0f * fRec45[0])), 65535))])) + (min(0.95f, (fConst23 * (((3947.8418f * fRec32[0]) + (7895.6836f * fRec32[1])) + (3947.8418f * fRec32[2])))) * ftbl0[max(0, min(int((65536.0f * fRec31[0])), 65535))])) + (min(0.95f, (fConst23 * (((3947.8418f * fRec18[0]) + (7895.6836f * fRec18[1])) + (3947.8418f * fRec18[2])))) * ftbl0[max(0, min(int((65536.0f * fRec17[0])), 65535))])) + (min(0.95f, (fConst23 * (((3947.8418f * fRec3[0]) + (7895.6836f * fRec3[1])) + (3947.8418f * fRec3[2])))) * ftbl0[max(0, min(int((65536.0f * fRec2[0])), 65535))]))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst24 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec74[2] = fRec74[1]; fRec74[1] = fRec74[0];
			fRec76[1] = fRec76[0];
			fRec79[1] = fRec79[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			iRec84[1] = iRec84[0];
			iRec83[1] = iRec83[0];
			iRec82[1] = iRec82[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			iRec75[1] = iRec75[0];
			fRec78[1] = fRec78[0];
			iRec77[1] = iRec77[0];
			fRec73[1] = fRec73[0];
			fRec60[2] = fRec60[1]; fRec60[1] = fRec60[0];
			fRec62[1] = fRec62[0];
			fRec65[1] = fRec65[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			iRec70[1] = iRec70[0];
			iRec69[1] = iRec69[0];
			iRec68[1] = iRec68[0];
			fRec66[1] = fRec66[0];
			fRec67[1] = fRec67[0];
			iRec61[1] = iRec61[0];
			fRec64[1] = fRec64[0];
			iRec63[1] = iRec63[0];
			fRec59[1] = fRec59[0];
			fRec46[2] = fRec46[1]; fRec46[1] = fRec46[0];
			fRec48[1] = fRec48[0];
			fRec51[1] = fRec51[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			iRec56[1] = iRec56[0];
			iRec55[1] = iRec55[0];
			iRec54[1] = iRec54[0];
			fRec52[1] = fRec52[0];
			fRec53[1] = fRec53[0];
			iRec47[1] = iRec47[0];
			fRec50[1] = fRec50[0];
			iRec49[1] = iRec49[0];
			fRec45[1] = fRec45[0];
			fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec37[1] = fRec37[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			iRec42[1] = iRec42[0];
			iRec41[1] = iRec41[0];
			iRec40[1] = iRec40[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			iRec33[1] = iRec33[0];
			fRec36[1] = fRec36[0];
			iRec35[1] = iRec35[0];
			fRec31[1] = fRec31[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec23[1] = fRec23[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			iRec28[1] = iRec28[0];
			iRec27[1] = iRec27[0];
			iRec26[1] = iRec26[0];
			fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			iRec19[1] = iRec19[0];
			fRec22[1] = fRec22[0];
			iRec21[1] = iRec21[0];
			fRec17[1] = fRec17[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			fRec8[1] = fRec8[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			iRec14[1] = iRec14[0];
			iRec12[1] = iRec12[0];
			iRec13[1] = iRec13[0];
			iRec11[1] = iRec11[0];
			fRec9[1] = fRec9[0];
			fRec10[1] = fRec10[0];
			iRec4[1] = iRec4[0];
			fRec7[1] = fRec7[0];
			iRec6[1] = iRec6[0];
			fRec2[1] = fRec2[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[65536];

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
