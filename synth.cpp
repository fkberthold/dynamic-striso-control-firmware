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
	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	FAUSTFLOAT 	fslider0;
	FAUSTFLOAT 	fslider1;
	float 	fConst17;
	float 	fRec5[2];
	float 	fRec4[2];
	int 	iRec6[2];
	float 	fRec7[2];
	float 	fRec8[2];
	int 	iRec9[2];
	int 	iRec11[2];
	int 	iRec10[2];
	int 	iRec2[2];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fbargraph1;
	float 	fRec12[2];
	float 	fRec3[2];
	float 	fRec1[3];
	float 	fConst24;
	FAUSTFLOAT 	fslider2;
	float 	fConst25;
	float 	fRec13[2];
	float 	fRec16[2];
	float 	fVec1[2];
	float 	fConst26;
	float 	fVec2[4096];
	float 	fConst27;
	float 	fRec15[2];
	float 	fConst28;
	FAUSTFLOAT 	fslider3;
	FAUSTFLOAT 	fslider4;
	float 	fRec21[2];
	float 	fRec20[2];
	int 	iRec22[2];
	float 	fRec23[2];
	float 	fRec24[2];
	int 	iRec25[2];
	int 	iRec26[2];
	int 	iRec18[2];
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fbargraph3;
	float 	fRec27[2];
	float 	fRec19[2];
	float 	fRec17[3];
	FAUSTFLOAT 	fslider5;
	float 	fRec28[2];
	float 	fRec31[2];
	float 	fVec3[2];
	float 	fVec4[4096];
	float 	fRec30[2];
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fRec36[2];
	float 	fRec35[2];
	int 	iRec37[2];
	float 	fRec38[2];
	float 	fRec39[2];
	int 	iRec40[2];
	int 	iRec41[2];
	int 	iRec33[2];
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fbargraph5;
	float 	fRec42[2];
	float 	fRec34[2];
	float 	fRec32[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec43[2];
	float 	fRec46[2];
	float 	fVec5[2];
	float 	fVec6[4096];
	float 	fRec45[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	float 	fRec51[2];
	float 	fRec50[2];
	int 	iRec52[2];
	float 	fRec53[2];
	float 	fRec54[2];
	int 	iRec55[2];
	int 	iRec56[2];
	int 	iRec48[2];
	FAUSTFLOAT 	fbargraph6;
	FAUSTFLOAT 	fbargraph7;
	float 	fRec57[2];
	float 	fRec49[2];
	float 	fRec47[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec58[2];
	float 	fRec61[2];
	float 	fVec7[2];
	float 	fVec8[4096];
	float 	fRec60[2];
	FAUSTFLOAT 	fslider12;
	FAUSTFLOAT 	fslider13;
	float 	fRec66[2];
	float 	fRec65[2];
	int 	iRec67[2];
	float 	fRec68[2];
	float 	fRec69[2];
	int 	iRec70[2];
	int 	iRec71[2];
	int 	iRec63[2];
	FAUSTFLOAT 	fbargraph8;
	FAUSTFLOAT 	fbargraph9;
	float 	fRec72[2];
	float 	fRec64[2];
	float 	fRec62[3];
	FAUSTFLOAT 	fslider14;
	float 	fRec73[2];
	float 	fRec76[2];
	float 	fVec9[2];
	float 	fVec10[4096];
	float 	fRec75[2];
	FAUSTFLOAT 	fslider15;
	FAUSTFLOAT 	fslider16;
	float 	fRec81[2];
	float 	fRec80[2];
	int 	iRec82[2];
	float 	fRec83[2];
	float 	fRec84[2];
	int 	iRec85[2];
	int 	iRec86[2];
	int 	iRec78[2];
	FAUSTFLOAT 	fbargraph10;
	FAUSTFLOAT 	fbargraph11;
	float 	fRec87[2];
	float 	fRec79[2];
	float 	fRec77[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec88[2];
	float 	fRec91[2];
	float 	fVec11[2];
	float 	fVec12[4096];
	float 	fRec90[2];
	float 	fRec0[3];
	float 	fConst29;
	int 	IOTA;
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
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/pole:author", "Julius O. Smith III");
		m->declare("filters.lib/pole:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/pole:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.6.0");
		m->declare("name", "synth.dsp.tmp");
		m->declare("oscillators.lib/lf_sawpos:author", "Bart Brouns, revised by Stéphane Letz");
		m->declare("oscillators.lib/lf_sawpos:licence", "STK-4.3");
		m->declare("oscillators.lib/name", "Faust Oscillator Library");
		m->declare("oscillators.lib/saw2ptr:author", "Julius O. Smith III");
		m->declare("oscillators.lib/saw2ptr:license", "STK-4.3");
		m->declare("oscillators.lib/sawN:author", "Julius O. Smith III");
		m->declare("oscillators.lib/sawN:license", "STK-4.3");
		m->declare("oscillators.lib/version", "1.4.0");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate) {
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
		fConst17 = (0.1f * fConst0);
		fConst18 = (0.05f * fConst0);
		fConst19 = (0.4f * fConst0);
		fConst20 = (0.01f * fConst0);
		fConst21 = (0.6f * fConst0);
		fConst22 = (8.0f * fConst0);
		fConst23 = (2.0f * fConst0);
		fConst24 = (fConst11 / (fConst1 * fConst15));
		fConst25 = (1.0f / fConst0);
		fConst26 = (0.25f * fConst0);
		fConst27 = (0.5f * fConst0);
		fConst28 = (32.703197f / fConst0);
		fConst29 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = 0.0f;
		fslider2 = 69.0f;
		fslider3 = 0.0f;
		fslider4 = 0.0f;
		fslider5 = 69.0f;
		fslider6 = 0.0f;
		fslider7 = 0.0f;
		fslider8 = 69.0f;
		fslider9 = 0.0f;
		fslider10 = 0.0f;
		fslider11 = 69.0f;
		fslider12 = 0.0f;
		fslider13 = 0.0f;
		fslider14 = 69.0f;
		fslider15 = 0.0f;
		fslider16 = 0.0f;
		fslider17 = 69.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<4096; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) iRec25[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<4096; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) iRec40[i] = 0;
		for (int i=0; i<2; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) iRec33[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<3; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<4096; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) iRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<3; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<4096; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) iRec70[i] = 0;
		for (int i=0; i<2; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<4096; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) iRec82[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) iRec85[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<3; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<4096; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		IOTA = 0;
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
		synth_interface.note[0] = &fslider17;
		synth_interface.pres[0] = &fslider15;
		synth_interface.but_y[0] = &fslider16;
		synth_interface.note[1] = &fslider14;
		synth_interface.pres[1] = &fslider12;
		synth_interface.but_y[1] = &fslider13;
		synth_interface.note[2] = &fslider11;
		synth_interface.pres[2] = &fslider9;
		synth_interface.but_y[2] = &fslider10;
		synth_interface.note[3] = &fslider8;
		synth_interface.pres[3] = &fslider6;
		synth_interface.but_y[3] = &fslider7;
		synth_interface.note[4] = &fslider5;
		synth_interface.pres[4] = &fslider3;
		synth_interface.but_y[4] = &fslider4;
		synth_interface.note[5] = &fslider2;
		synth_interface.pres[5] = &fslider0;
		synth_interface.but_y[5] = &fslider1;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = float(fslider0);
		int 	iSlow1 = (((fSlow0 >= 0.1f)) ? 1 : 0);
		float 	fSlow2 = min((2.0f * float(fslider1)), 1.0f);
		float 	fSlow3 = fabsf(fSlow2);
		float 	fSlow4 = (((fSlow3 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow5 = ((fSlow2 > 0.0f) - (fSlow2 < 0.0f));
		int 	iSlow6 = (fSlow0 <= 0.1f);
		int 	iSlow7 = ((iSlow6) ? 3 : 2);
		int 	iSlow8 = (fSlow0 <= 0.0f);
		float 	fSlow9 = fastpow2((0.083333336f * float(fslider2)));
		float 	fSlow10 = (8.175799f * fSlow9);
		float 	fSlow11 = max(1.1920929e-07f, fabsf(fSlow10));
		float 	fSlow12 = (fConst25 * fSlow11);
		float 	fSlow13 = (1.0f - (fConst0 / fSlow11));
		float 	fSlow14 = max(fSlow10, 23.44895f);
		float 	fSlow15 = max(2e+01f, fabsf(fSlow14));
		float 	fSlow16 = (fConst25 * fSlow15);
		float 	fSlow17 = (fConst26 / fSlow15);
		float 	fSlow18 = max(0.0f, min(2047.0f, (fConst27 / fSlow14)));
		int 	iSlow19 = int(fSlow18);
		int 	iSlow20 = (iSlow19 + 1);
		float 	fSlow21 = floorf(fSlow18);
		float 	fSlow22 = (fSlow18 - fSlow21);
		float 	fSlow23 = (fSlow21 + (1.0f - fSlow18));
		float 	fSlow24 = (fConst28 * fSlow9);
		float 	fSlow25 = float(fslider3);
		int 	iSlow26 = (((fSlow25 >= 0.1f)) ? 1 : 0);
		float 	fSlow27 = min((2.0f * float(fslider4)), 1.0f);
		float 	fSlow28 = fabsf(fSlow27);
		float 	fSlow29 = (((fSlow28 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow30 = ((fSlow27 > 0.0f) - (fSlow27 < 0.0f));
		int 	iSlow31 = (fSlow25 <= 0.1f);
		int 	iSlow32 = ((iSlow31) ? 3 : 2);
		int 	iSlow33 = (fSlow25 <= 0.0f);
		float 	fSlow34 = fastpow2((0.083333336f * float(fslider5)));
		float 	fSlow35 = (8.175799f * fSlow34);
		float 	fSlow36 = max(1.1920929e-07f, fabsf(fSlow35));
		float 	fSlow37 = (fConst25 * fSlow36);
		float 	fSlow38 = (1.0f - (fConst0 / fSlow36));
		float 	fSlow39 = max(fSlow35, 23.44895f);
		float 	fSlow40 = max(2e+01f, fabsf(fSlow39));
		float 	fSlow41 = (fConst25 * fSlow40);
		float 	fSlow42 = (fConst26 / fSlow40);
		float 	fSlow43 = max(0.0f, min(2047.0f, (fConst27 / fSlow39)));
		int 	iSlow44 = int(fSlow43);
		int 	iSlow45 = (iSlow44 + 1);
		float 	fSlow46 = floorf(fSlow43);
		float 	fSlow47 = (fSlow43 - fSlow46);
		float 	fSlow48 = (fSlow46 + (1.0f - fSlow43));
		float 	fSlow49 = (fConst28 * fSlow34);
		float 	fSlow50 = float(fslider6);
		int 	iSlow51 = (((fSlow50 >= 0.1f)) ? 1 : 0);
		float 	fSlow52 = min((2.0f * float(fslider7)), 1.0f);
		float 	fSlow53 = fabsf(fSlow52);
		float 	fSlow54 = (((fSlow53 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow55 = ((fSlow52 > 0.0f) - (fSlow52 < 0.0f));
		int 	iSlow56 = (fSlow50 <= 0.1f);
		int 	iSlow57 = ((iSlow56) ? 3 : 2);
		int 	iSlow58 = (fSlow50 <= 0.0f);
		float 	fSlow59 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow60 = (8.175799f * fSlow59);
		float 	fSlow61 = max(1.1920929e-07f, fabsf(fSlow60));
		float 	fSlow62 = (fConst25 * fSlow61);
		float 	fSlow63 = (1.0f - (fConst0 / fSlow61));
		float 	fSlow64 = max(fSlow60, 23.44895f);
		float 	fSlow65 = max(2e+01f, fabsf(fSlow64));
		float 	fSlow66 = (fConst25 * fSlow65);
		float 	fSlow67 = (fConst26 / fSlow65);
		float 	fSlow68 = max(0.0f, min(2047.0f, (fConst27 / fSlow64)));
		int 	iSlow69 = int(fSlow68);
		int 	iSlow70 = (iSlow69 + 1);
		float 	fSlow71 = floorf(fSlow68);
		float 	fSlow72 = (fSlow68 - fSlow71);
		float 	fSlow73 = (fSlow71 + (1.0f - fSlow68));
		float 	fSlow74 = (fConst28 * fSlow59);
		float 	fSlow75 = float(fslider9);
		int 	iSlow76 = (((fSlow75 >= 0.1f)) ? 1 : 0);
		float 	fSlow77 = min((2.0f * float(fslider10)), 1.0f);
		float 	fSlow78 = fabsf(fSlow77);
		float 	fSlow79 = (((fSlow78 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow80 = ((fSlow77 > 0.0f) - (fSlow77 < 0.0f));
		int 	iSlow81 = (fSlow75 <= 0.1f);
		int 	iSlow82 = ((iSlow81) ? 3 : 2);
		int 	iSlow83 = (fSlow75 <= 0.0f);
		float 	fSlow84 = fastpow2((0.083333336f * float(fslider11)));
		float 	fSlow85 = (8.175799f * fSlow84);
		float 	fSlow86 = max(1.1920929e-07f, fabsf(fSlow85));
		float 	fSlow87 = (fConst25 * fSlow86);
		float 	fSlow88 = (1.0f - (fConst0 / fSlow86));
		float 	fSlow89 = max(fSlow85, 23.44895f);
		float 	fSlow90 = max(2e+01f, fabsf(fSlow89));
		float 	fSlow91 = (fConst25 * fSlow90);
		float 	fSlow92 = (fConst26 / fSlow90);
		float 	fSlow93 = max(0.0f, min(2047.0f, (fConst27 / fSlow89)));
		int 	iSlow94 = int(fSlow93);
		int 	iSlow95 = (iSlow94 + 1);
		float 	fSlow96 = floorf(fSlow93);
		float 	fSlow97 = (fSlow93 - fSlow96);
		float 	fSlow98 = (fSlow96 + (1.0f - fSlow93));
		float 	fSlow99 = (fConst28 * fSlow84);
		float 	fSlow100 = float(fslider12);
		int 	iSlow101 = (((fSlow100 >= 0.1f)) ? 1 : 0);
		float 	fSlow102 = min((2.0f * float(fslider13)), 1.0f);
		float 	fSlow103 = fabsf(fSlow102);
		float 	fSlow104 = (((fSlow103 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow105 = ((fSlow102 > 0.0f) - (fSlow102 < 0.0f));
		int 	iSlow106 = (fSlow100 <= 0.1f);
		int 	iSlow107 = ((iSlow106) ? 3 : 2);
		int 	iSlow108 = (fSlow100 <= 0.0f);
		float 	fSlow109 = fastpow2((0.083333336f * float(fslider14)));
		float 	fSlow110 = (8.175799f * fSlow109);
		float 	fSlow111 = max(1.1920929e-07f, fabsf(fSlow110));
		float 	fSlow112 = (fConst25 * fSlow111);
		float 	fSlow113 = (1.0f - (fConst0 / fSlow111));
		float 	fSlow114 = max(fSlow110, 23.44895f);
		float 	fSlow115 = max(2e+01f, fabsf(fSlow114));
		float 	fSlow116 = (fConst25 * fSlow115);
		float 	fSlow117 = (fConst26 / fSlow115);
		float 	fSlow118 = max(0.0f, min(2047.0f, (fConst27 / fSlow114)));
		int 	iSlow119 = int(fSlow118);
		int 	iSlow120 = (iSlow119 + 1);
		float 	fSlow121 = floorf(fSlow118);
		float 	fSlow122 = (fSlow118 - fSlow121);
		float 	fSlow123 = (fSlow121 + (1.0f - fSlow118));
		float 	fSlow124 = (fConst28 * fSlow109);
		float 	fSlow125 = float(fslider15);
		int 	iSlow126 = (((fSlow125 >= 0.1f)) ? 1 : 0);
		float 	fSlow127 = min((2.0f * float(fslider16)), 1.0f);
		float 	fSlow128 = fabsf(fSlow127);
		float 	fSlow129 = (((fSlow128 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow130 = ((fSlow127 > 0.0f) - (fSlow127 < 0.0f));
		int 	iSlow131 = (fSlow125 <= 0.1f);
		int 	iSlow132 = ((iSlow131) ? 3 : 2);
		int 	iSlow133 = (fSlow125 <= 0.0f);
		float 	fSlow134 = fastpow2((0.083333336f * float(fslider17)));
		float 	fSlow135 = (8.175799f * fSlow134);
		float 	fSlow136 = max(1.1920929e-07f, fabsf(fSlow135));
		float 	fSlow137 = (fConst25 * fSlow136);
		float 	fSlow138 = (1.0f - (fConst0 / fSlow136));
		float 	fSlow139 = max(fSlow135, 23.44895f);
		float 	fSlow140 = max(2e+01f, fabsf(fSlow139));
		float 	fSlow141 = (fConst25 * fSlow140);
		float 	fSlow142 = (fConst26 / fSlow140);
		float 	fSlow143 = max(0.0f, min(2047.0f, (fConst27 / fSlow139)));
		int 	iSlow144 = int(fSlow143);
		int 	iSlow145 = (iSlow144 + 1);
		float 	fSlow146 = floorf(fSlow143);
		float 	fSlow147 = (fSlow143 - fSlow146);
		float 	fSlow148 = (fSlow146 + (1.0f - fSlow143));
		float 	fSlow149 = (fConst28 * fSlow134);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			float 	fTemp0 = (1.0f / (((iSlow5 == ((fRec4[1] > 0.0f) - (fRec4[1] < 0.0f)))) ? (((fSlow3 >= fabsf(fRec4[1]))) ? fConst17 : fConst0) : fSlow4));
			float 	fTemp1 = (fRec5[1] - fTemp0);
			float 	fTemp2 = (fRec5[1] + fTemp0);
			fRec5[0] = (((fTemp2 < fSlow2)) ? fTemp2 : (((fTemp1 > fSlow2)) ? fTemp1 : fSlow2));
			fRec4[0] = fRec5[0];
			int 	iTemp3 = ((fRec4[0] > 0.0f) + (1 - (fRec4[0] < 0.0f)));
			int 	iTemp4 = (iTemp3 == 0);
			float 	fTemp5 = ((iTemp4) ? 1.7f : 1.6f);
			iRec6[0] = iRec2[1];
			int 	iTemp6 = (iRec6[1] == iRec2[1]);
			int 	iTemp7 = (iRec2[1] == 0);
			fRec7[0] = ((iTemp7) ? fSlow0 : ((iTemp6) ? min(min(fRec7[1], fSlow0), fRec3[1]) : min(fSlow0, fRec3[1])));
			float 	fTemp8 = (fSlow0 * fTemp5);
			int 	iTemp9 = (iRec2[1] == 1);
			fRec8[0] = ((iTemp7) ? fSlow0 : ((iTemp9) ? ((iTemp6) ? max(max(fRec8[1], fTemp8), fRec3[1]) : max(fTemp8, fRec3[1])) : ((iTemp6) ? max(max(fRec8[1], fSlow0), fRec3[1]) : max(fSlow0, fRec3[1]))));
			iRec9[0] = iRec2[1];
			iRec11[0] = (iRec11[1] + 1);
			int 	iTemp10 = (iRec11[0] + -1);
			iRec10[0] = (((iRec9[1] != iRec2[1])) ? iTemp10 : iRec10[1]);
			float 	fTemp11 = float((iRec11[0] + (-1 - iRec10[0])));
			int 	iTemp12 = (iRec2[1] >= 1);
			int 	iTemp13 = (fSlow0 >= fRec3[1]);
			int 	iTemp14 = (iRec2[1] >= 3);
			int 	iTemp15 = (iRec2[1] >= 2);
			int 	iTemp16 = (iRec2[1] >= 5);
			int 	iTemp17 = (iRec2[1] >= 6);
			int 	iTemp18 = (iRec2[1] >= 4);
			iRec2[0] = ((iTemp18) ? ((iTemp17) ? ((iSlow6) ? 3 : ((iTemp13) ? 5 : 6)) : ((iTemp16) ? ((iSlow6) ? 3 : (((fSlow0 <= fRec3[1])) ? 6 : 5)) : (((fRec3[1] <= 0.1f)) ? 0 : 4))) : ((iTemp15) ? ((iTemp14) ? (((iSlow8 & (fRec3[1] <= 0.001f))) ? 0 : (((fSlow0 > fRec3[1])) ? 1 : 3)) : ((iTemp13) ? 5 : iSlow7)) : ((iTemp12) ? ((((fTemp11 >= fConst17) & (fRec3[1] >= (fRec7[0] * fTemp5)))) ? 2 : 1) : iSlow1)));
			float 	fTemp19 = ((iTemp12) ? fConst18 : 0.0f);
			float 	fTemp20 = ((iTemp18) ? ((iTemp17) ? fConst21 : ((iTemp16) ? fConst21 : fConst20)) : ((iTemp15) ? ((iTemp14) ? fConst19 : fConst18) : fTemp19));
			float 	fTemp21 = fabsf(fRec4[0]);
			float 	fTemp22 = (((fTemp21 <= 0.3f)) ? fTemp20 : ((fTemp21 * ((iTemp4) ? ((iTemp18) ? ((iTemp17) ? fConst23 : ((iTemp16) ? fConst23 : fConst20)) : ((iTemp15) ? ((iTemp14) ? fConst22 : fConst17) : fTemp19)) : (((iTemp3 == 1)) ? fTemp20 : ((iTemp18) ? fConst20 : ((iTemp15) ? ((iTemp14) ? fConst20 : fConst18) : fTemp19))))) + ((1.0f - fTemp21) * fTemp20)));
			fbargraph0 = (((fTemp22 > 0.0f)) ? (fTemp11 / fTemp22) : 0.0f);
			fbargraph1 = floorf((2e+01f * fbargraph0));
			float 	fTemp23 = fbargraph1;
			float 	fTemp24 = (((fTemp23 >= 1e+01f)) ? (((fTemp23 >= 15.0f)) ? (((fTemp23 >= 18.0f)) ? (((fTemp23 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp23 >= 17.0f)) ? 0.03f : (((fTemp23 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp23 >= 13.0f)) ? (((fTemp23 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp23 >= 12.0f)) ? 0.14f : (((fTemp23 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp23 >= 5.0f)) ? (((fTemp23 >= 8.0f)) ? (((fTemp23 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp23 >= 7.0f)) ? 0.3f : (((fTemp23 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp23 >= 3.0f)) ? (((fTemp23 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp23 >= 2.0f)) ? 0.64f : (((fTemp23 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp25 = (iRec2[1] == 3);
			float 	fTemp26 = ((iTemp9) ? min(1.0f, fTemp8) : ((iTemp25) ? (fRec8[0] * fTemp24) : fSlow0));
			float 	fTemp27 = (fTemp23 + -1.0f);
			float 	fTemp28 = ((((fTemp23 > 0.0f)) ? (((fTemp27 >= 1e+01f)) ? (((fTemp27 >= 15.0f)) ? (((fTemp27 >= 18.0f)) ? (((fTemp27 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp27 >= 17.0f)) ? 0.03f : (((fTemp27 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp27 >= 13.0f)) ? (((fTemp27 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp27 >= 12.0f)) ? 0.14f : (((fTemp27 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp27 >= 5.0f)) ? (((fTemp27 >= 8.0f)) ? (((fTemp27 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp27 >= 7.0f)) ? 0.3f : (((fTemp27 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp27 >= 3.0f)) ? (((fTemp27 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp27 >= 2.0f)) ? 0.64f : (((fTemp27 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp24);
			float 	fTemp29 = (1.0f / ((iTemp25) ? (((fTemp28 > 0.0f)) ? (0.05f * (fTemp22 / fTemp28)) : 0.0f) : fTemp22));
			float 	fTemp30 = (fRec12[1] - fTemp29);
			float 	fTemp31 = (fRec12[1] + fTemp29);
			fRec12[0] = (((fTemp31 < fTemp26)) ? fTemp31 : (((fTemp30 > fTemp26)) ? fTemp30 : fTemp26));
			fRec3[0] = fRec12[0];
			fRec1[0] = (fRec3[0] - (fConst16 * ((fConst14 * fRec1[2]) + (fConst12 * fRec1[1]))));
			float 	fTemp32 = min(0.95f, (fConst24 * (((3947.8418f * fRec1[0]) + (7895.6836f * fRec1[1])) + (3947.8418f * fRec1[2]))));
			float 	fTemp33 = (fSlow12 + (fRec13[1] + -1.0f));
			float 	fTemp34 = (fSlow12 + fRec13[1]);
			int 	iTemp35 = (fTemp33 < 0.0f);
			fRec13[0] = ((iTemp35) ? fTemp34 : fTemp33);
			float 	fRec14 = ((iTemp35) ? fTemp34 : (fSlow12 + (fRec13[1] + (fSlow13 * fTemp33))));
			int 	iTemp36 = (1 - iVec0[1]);
			float 	fTemp37 = ((iTemp36) ? 0.0f : (fSlow16 + fRec16[1]));
			fRec16[0] = (fTemp37 - floorf(fTemp37));
			float 	fTemp38 = powf(((2.0f * fRec16[0]) + -1.0f),2.0f);
			fVec1[0] = fTemp38;
			float 	fTemp39 = float(iVec0[1]);
			float 	fTemp40 = (fSlow17 * (fTemp39 * (fVec1[0] - fVec1[1])));
			fVec2[IOTA&4095] = fTemp40;
			fRec15[0] = (((0.999f * fRec15[1]) + fVec2[IOTA&4095]) - ((fSlow23 * fVec2[(IOTA-iSlow19)&4095]) + (fSlow22 * fVec2[(IOTA-iSlow20)&4095])));
			float 	fTemp41 = (1.0f / (((iSlow30 == ((fRec20[1] > 0.0f) - (fRec20[1] < 0.0f)))) ? (((fSlow28 >= fabsf(fRec20[1]))) ? fConst17 : fConst0) : fSlow29));
			float 	fTemp42 = (fRec21[1] - fTemp41);
			float 	fTemp43 = (fRec21[1] + fTemp41);
			fRec21[0] = (((fTemp43 < fSlow27)) ? fTemp43 : (((fTemp42 > fSlow27)) ? fTemp42 : fSlow27));
			fRec20[0] = fRec21[0];
			int 	iTemp44 = ((fRec20[0] > 0.0f) + (1 - (fRec20[0] < 0.0f)));
			int 	iTemp45 = (iTemp44 == 0);
			float 	fTemp46 = ((iTemp45) ? 1.7f : 1.6f);
			iRec22[0] = iRec18[1];
			int 	iTemp47 = (iRec22[1] == iRec18[1]);
			int 	iTemp48 = (iRec18[1] == 0);
			fRec23[0] = ((iTemp48) ? fSlow25 : ((iTemp47) ? min(min(fRec23[1], fSlow25), fRec19[1]) : min(fSlow25, fRec19[1])));
			float 	fTemp49 = (fSlow25 * fTemp46);
			int 	iTemp50 = (iRec18[1] == 1);
			fRec24[0] = ((iTemp48) ? fSlow25 : ((iTemp50) ? ((iTemp47) ? max(max(fRec24[1], fTemp49), fRec19[1]) : max(fTemp49, fRec19[1])) : ((iTemp47) ? max(max(fRec24[1], fSlow25), fRec19[1]) : max(fSlow25, fRec19[1]))));
			iRec25[0] = iRec18[1];
			iRec26[0] = (((iRec25[1] != iRec18[1])) ? iTemp10 : iRec26[1]);
			float 	fTemp51 = float((iRec11[0] + (-1 - iRec26[0])));
			int 	iTemp52 = (iRec18[1] >= 1);
			int 	iTemp53 = (fSlow25 >= fRec19[1]);
			int 	iTemp54 = (iRec18[1] >= 3);
			int 	iTemp55 = (iRec18[1] >= 2);
			int 	iTemp56 = (iRec18[1] >= 5);
			int 	iTemp57 = (iRec18[1] >= 6);
			int 	iTemp58 = (iRec18[1] >= 4);
			iRec18[0] = ((iTemp58) ? ((iTemp57) ? ((iSlow31) ? 3 : ((iTemp53) ? 5 : 6)) : ((iTemp56) ? ((iSlow31) ? 3 : (((fSlow25 <= fRec19[1])) ? 6 : 5)) : (((fRec19[1] <= 0.1f)) ? 0 : 4))) : ((iTemp55) ? ((iTemp54) ? (((iSlow33 & (fRec19[1] <= 0.001f))) ? 0 : (((fSlow25 > fRec19[1])) ? 1 : 3)) : ((iTemp53) ? 5 : iSlow32)) : ((iTemp52) ? ((((fTemp51 >= fConst17) & (fRec19[1] >= (fRec23[0] * fTemp46)))) ? 2 : 1) : iSlow26)));
			float 	fTemp59 = ((iTemp52) ? fConst18 : 0.0f);
			float 	fTemp60 = ((iTemp58) ? ((iTemp57) ? fConst21 : ((iTemp56) ? fConst21 : fConst20)) : ((iTemp55) ? ((iTemp54) ? fConst19 : fConst18) : fTemp59));
			float 	fTemp61 = fabsf(fRec20[0]);
			float 	fTemp62 = (((fTemp61 <= 0.3f)) ? fTemp60 : ((fTemp61 * ((iTemp45) ? ((iTemp58) ? ((iTemp57) ? fConst23 : ((iTemp56) ? fConst23 : fConst20)) : ((iTemp55) ? ((iTemp54) ? fConst22 : fConst17) : fTemp59)) : (((iTemp44 == 1)) ? fTemp60 : ((iTemp58) ? fConst20 : ((iTemp55) ? ((iTemp54) ? fConst20 : fConst18) : fTemp59))))) + ((1.0f - fTemp61) * fTemp60)));
			fbargraph2 = (((fTemp62 > 0.0f)) ? (fTemp51 / fTemp62) : 0.0f);
			fbargraph3 = floorf((2e+01f * fbargraph2));
			float 	fTemp63 = fbargraph3;
			float 	fTemp64 = (((fTemp63 >= 1e+01f)) ? (((fTemp63 >= 15.0f)) ? (((fTemp63 >= 18.0f)) ? (((fTemp63 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp63 >= 17.0f)) ? 0.03f : (((fTemp63 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp63 >= 13.0f)) ? (((fTemp63 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp63 >= 12.0f)) ? 0.14f : (((fTemp63 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp63 >= 5.0f)) ? (((fTemp63 >= 8.0f)) ? (((fTemp63 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp63 >= 7.0f)) ? 0.3f : (((fTemp63 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp63 >= 3.0f)) ? (((fTemp63 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp63 >= 2.0f)) ? 0.64f : (((fTemp63 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp65 = (iRec18[1] == 3);
			float 	fTemp66 = ((iTemp50) ? min(1.0f, fTemp49) : ((iTemp65) ? (fRec24[0] * fTemp64) : fSlow25));
			float 	fTemp67 = (fTemp63 + -1.0f);
			float 	fTemp68 = ((((fTemp63 > 0.0f)) ? (((fTemp67 >= 1e+01f)) ? (((fTemp67 >= 15.0f)) ? (((fTemp67 >= 18.0f)) ? (((fTemp67 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp67 >= 17.0f)) ? 0.03f : (((fTemp67 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp67 >= 13.0f)) ? (((fTemp67 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp67 >= 12.0f)) ? 0.14f : (((fTemp67 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp67 >= 5.0f)) ? (((fTemp67 >= 8.0f)) ? (((fTemp67 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp67 >= 7.0f)) ? 0.3f : (((fTemp67 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp67 >= 3.0f)) ? (((fTemp67 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp67 >= 2.0f)) ? 0.64f : (((fTemp67 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp64);
			float 	fTemp69 = (1.0f / ((iTemp65) ? (((fTemp68 > 0.0f)) ? (0.05f * (fTemp62 / fTemp68)) : 0.0f) : fTemp62));
			float 	fTemp70 = (fRec27[1] - fTemp69);
			float 	fTemp71 = (fRec27[1] + fTemp69);
			fRec27[0] = (((fTemp71 < fTemp66)) ? fTemp71 : (((fTemp70 > fTemp66)) ? fTemp70 : fTemp66));
			fRec19[0] = fRec27[0];
			fRec17[0] = (fRec19[0] - (fConst16 * ((fConst14 * fRec17[2]) + (fConst12 * fRec17[1]))));
			float 	fTemp72 = min(0.95f, (fConst24 * (((3947.8418f * fRec17[0]) + (7895.6836f * fRec17[1])) + (3947.8418f * fRec17[2]))));
			float 	fTemp73 = (fSlow37 + (fRec28[1] + -1.0f));
			float 	fTemp74 = (fSlow37 + fRec28[1]);
			int 	iTemp75 = (fTemp73 < 0.0f);
			fRec28[0] = ((iTemp75) ? fTemp74 : fTemp73);
			float 	fRec29 = ((iTemp75) ? fTemp74 : (fSlow37 + (fRec28[1] + (fSlow38 * fTemp73))));
			float 	fTemp76 = ((iTemp36) ? 0.0f : (fSlow41 + fRec31[1]));
			fRec31[0] = (fTemp76 - floorf(fTemp76));
			float 	fTemp77 = powf(((2.0f * fRec31[0]) + -1.0f),2.0f);
			fVec3[0] = fTemp77;
			float 	fTemp78 = (fSlow42 * (fTemp39 * (fVec3[0] - fVec3[1])));
			fVec4[IOTA&4095] = fTemp78;
			fRec30[0] = (((0.999f * fRec30[1]) + fVec4[IOTA&4095]) - ((fSlow48 * fVec4[(IOTA-iSlow44)&4095]) + (fSlow47 * fVec4[(IOTA-iSlow45)&4095])));
			float 	fTemp79 = (1.0f / (((iSlow55 == ((fRec35[1] > 0.0f) - (fRec35[1] < 0.0f)))) ? (((fSlow53 >= fabsf(fRec35[1]))) ? fConst17 : fConst0) : fSlow54));
			float 	fTemp80 = (fRec36[1] - fTemp79);
			float 	fTemp81 = (fRec36[1] + fTemp79);
			fRec36[0] = (((fTemp81 < fSlow52)) ? fTemp81 : (((fTemp80 > fSlow52)) ? fTemp80 : fSlow52));
			fRec35[0] = fRec36[0];
			int 	iTemp82 = ((fRec35[0] > 0.0f) + (1 - (fRec35[0] < 0.0f)));
			int 	iTemp83 = (iTemp82 == 0);
			float 	fTemp84 = ((iTemp83) ? 1.7f : 1.6f);
			iRec37[0] = iRec33[1];
			int 	iTemp85 = (iRec37[1] == iRec33[1]);
			int 	iTemp86 = (iRec33[1] == 0);
			fRec38[0] = ((iTemp86) ? fSlow50 : ((iTemp85) ? min(min(fRec38[1], fSlow50), fRec34[1]) : min(fSlow50, fRec34[1])));
			float 	fTemp87 = (fSlow50 * fTemp84);
			int 	iTemp88 = (iRec33[1] == 1);
			fRec39[0] = ((iTemp86) ? fSlow50 : ((iTemp88) ? ((iTemp85) ? max(max(fRec39[1], fTemp87), fRec34[1]) : max(fTemp87, fRec34[1])) : ((iTemp85) ? max(max(fRec39[1], fSlow50), fRec34[1]) : max(fSlow50, fRec34[1]))));
			iRec40[0] = iRec33[1];
			iRec41[0] = (((iRec40[1] != iRec33[1])) ? iTemp10 : iRec41[1]);
			float 	fTemp89 = float((iRec11[0] + (-1 - iRec41[0])));
			int 	iTemp90 = (iRec33[1] >= 1);
			int 	iTemp91 = (fSlow50 >= fRec34[1]);
			int 	iTemp92 = (iRec33[1] >= 3);
			int 	iTemp93 = (iRec33[1] >= 2);
			int 	iTemp94 = (iRec33[1] >= 5);
			int 	iTemp95 = (iRec33[1] >= 6);
			int 	iTemp96 = (iRec33[1] >= 4);
			iRec33[0] = ((iTemp96) ? ((iTemp95) ? ((iSlow56) ? 3 : ((iTemp91) ? 5 : 6)) : ((iTemp94) ? ((iSlow56) ? 3 : (((fSlow50 <= fRec34[1])) ? 6 : 5)) : (((fRec34[1] <= 0.1f)) ? 0 : 4))) : ((iTemp93) ? ((iTemp92) ? (((iSlow58 & (fRec34[1] <= 0.001f))) ? 0 : (((fSlow50 > fRec34[1])) ? 1 : 3)) : ((iTemp91) ? 5 : iSlow57)) : ((iTemp90) ? ((((fTemp89 >= fConst17) & (fRec34[1] >= (fRec38[0] * fTemp84)))) ? 2 : 1) : iSlow51)));
			float 	fTemp97 = ((iTemp90) ? fConst18 : 0.0f);
			float 	fTemp98 = ((iTemp96) ? ((iTemp95) ? fConst21 : ((iTemp94) ? fConst21 : fConst20)) : ((iTemp93) ? ((iTemp92) ? fConst19 : fConst18) : fTemp97));
			float 	fTemp99 = fabsf(fRec35[0]);
			float 	fTemp100 = (((fTemp99 <= 0.3f)) ? fTemp98 : ((fTemp99 * ((iTemp83) ? ((iTemp96) ? ((iTemp95) ? fConst23 : ((iTemp94) ? fConst23 : fConst20)) : ((iTemp93) ? ((iTemp92) ? fConst22 : fConst17) : fTemp97)) : (((iTemp82 == 1)) ? fTemp98 : ((iTemp96) ? fConst20 : ((iTemp93) ? ((iTemp92) ? fConst20 : fConst18) : fTemp97))))) + ((1.0f - fTemp99) * fTemp98)));
			fbargraph4 = (((fTemp100 > 0.0f)) ? (fTemp89 / fTemp100) : 0.0f);
			fbargraph5 = floorf((2e+01f * fbargraph4));
			float 	fTemp101 = fbargraph5;
			float 	fTemp102 = (((fTemp101 >= 1e+01f)) ? (((fTemp101 >= 15.0f)) ? (((fTemp101 >= 18.0f)) ? (((fTemp101 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp101 >= 17.0f)) ? 0.03f : (((fTemp101 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp101 >= 13.0f)) ? (((fTemp101 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp101 >= 12.0f)) ? 0.14f : (((fTemp101 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp101 >= 5.0f)) ? (((fTemp101 >= 8.0f)) ? (((fTemp101 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp101 >= 7.0f)) ? 0.3f : (((fTemp101 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp101 >= 3.0f)) ? (((fTemp101 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp101 >= 2.0f)) ? 0.64f : (((fTemp101 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp103 = (iRec33[1] == 3);
			float 	fTemp104 = ((iTemp88) ? min(1.0f, fTemp87) : ((iTemp103) ? (fRec39[0] * fTemp102) : fSlow50));
			float 	fTemp105 = (fTemp101 + -1.0f);
			float 	fTemp106 = ((((fTemp101 > 0.0f)) ? (((fTemp105 >= 1e+01f)) ? (((fTemp105 >= 15.0f)) ? (((fTemp105 >= 18.0f)) ? (((fTemp105 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp105 >= 17.0f)) ? 0.03f : (((fTemp105 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp105 >= 13.0f)) ? (((fTemp105 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp105 >= 12.0f)) ? 0.14f : (((fTemp105 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp105 >= 5.0f)) ? (((fTemp105 >= 8.0f)) ? (((fTemp105 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp105 >= 7.0f)) ? 0.3f : (((fTemp105 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp105 >= 3.0f)) ? (((fTemp105 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp105 >= 2.0f)) ? 0.64f : (((fTemp105 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp102);
			float 	fTemp107 = (1.0f / ((iTemp103) ? (((fTemp106 > 0.0f)) ? (0.05f * (fTemp100 / fTemp106)) : 0.0f) : fTemp100));
			float 	fTemp108 = (fRec42[1] - fTemp107);
			float 	fTemp109 = (fRec42[1] + fTemp107);
			fRec42[0] = (((fTemp109 < fTemp104)) ? fTemp109 : (((fTemp108 > fTemp104)) ? fTemp108 : fTemp104));
			fRec34[0] = fRec42[0];
			fRec32[0] = (fRec34[0] - (fConst16 * ((fConst14 * fRec32[2]) + (fConst12 * fRec32[1]))));
			float 	fTemp110 = min(0.95f, (fConst24 * (((3947.8418f * fRec32[0]) + (7895.6836f * fRec32[1])) + (3947.8418f * fRec32[2]))));
			float 	fTemp111 = (fSlow62 + (fRec43[1] + -1.0f));
			float 	fTemp112 = (fSlow62 + fRec43[1]);
			int 	iTemp113 = (fTemp111 < 0.0f);
			fRec43[0] = ((iTemp113) ? fTemp112 : fTemp111);
			float 	fRec44 = ((iTemp113) ? fTemp112 : (fSlow62 + (fRec43[1] + (fSlow63 * fTemp111))));
			float 	fTemp114 = ((iTemp36) ? 0.0f : (fSlow66 + fRec46[1]));
			fRec46[0] = (fTemp114 - floorf(fTemp114));
			float 	fTemp115 = powf(((2.0f * fRec46[0]) + -1.0f),2.0f);
			fVec5[0] = fTemp115;
			float 	fTemp116 = (fSlow67 * (fTemp39 * (fVec5[0] - fVec5[1])));
			fVec6[IOTA&4095] = fTemp116;
			fRec45[0] = (((0.999f * fRec45[1]) + fVec6[IOTA&4095]) - ((fSlow73 * fVec6[(IOTA-iSlow69)&4095]) + (fSlow72 * fVec6[(IOTA-iSlow70)&4095])));
			float 	fTemp117 = (1.0f / (((iSlow80 == ((fRec50[1] > 0.0f) - (fRec50[1] < 0.0f)))) ? (((fSlow78 >= fabsf(fRec50[1]))) ? fConst17 : fConst0) : fSlow79));
			float 	fTemp118 = (fRec51[1] - fTemp117);
			float 	fTemp119 = (fRec51[1] + fTemp117);
			fRec51[0] = (((fTemp119 < fSlow77)) ? fTemp119 : (((fTemp118 > fSlow77)) ? fTemp118 : fSlow77));
			fRec50[0] = fRec51[0];
			int 	iTemp120 = ((fRec50[0] > 0.0f) + (1 - (fRec50[0] < 0.0f)));
			int 	iTemp121 = (iTemp120 == 0);
			float 	fTemp122 = ((iTemp121) ? 1.7f : 1.6f);
			iRec52[0] = iRec48[1];
			int 	iTemp123 = (iRec52[1] == iRec48[1]);
			int 	iTemp124 = (iRec48[1] == 0);
			fRec53[0] = ((iTemp124) ? fSlow75 : ((iTemp123) ? min(min(fRec53[1], fSlow75), fRec49[1]) : min(fSlow75, fRec49[1])));
			float 	fTemp125 = (fSlow75 * fTemp122);
			int 	iTemp126 = (iRec48[1] == 1);
			fRec54[0] = ((iTemp124) ? fSlow75 : ((iTemp126) ? ((iTemp123) ? max(max(fRec54[1], fTemp125), fRec49[1]) : max(fTemp125, fRec49[1])) : ((iTemp123) ? max(max(fRec54[1], fSlow75), fRec49[1]) : max(fSlow75, fRec49[1]))));
			iRec55[0] = iRec48[1];
			iRec56[0] = (((iRec55[1] != iRec48[1])) ? iTemp10 : iRec56[1]);
			float 	fTemp127 = float((iRec11[0] + (-1 - iRec56[0])));
			int 	iTemp128 = (iRec48[1] >= 1);
			int 	iTemp129 = (fSlow75 >= fRec49[1]);
			int 	iTemp130 = (iRec48[1] >= 3);
			int 	iTemp131 = (iRec48[1] >= 2);
			int 	iTemp132 = (iRec48[1] >= 5);
			int 	iTemp133 = (iRec48[1] >= 6);
			int 	iTemp134 = (iRec48[1] >= 4);
			iRec48[0] = ((iTemp134) ? ((iTemp133) ? ((iSlow81) ? 3 : ((iTemp129) ? 5 : 6)) : ((iTemp132) ? ((iSlow81) ? 3 : (((fSlow75 <= fRec49[1])) ? 6 : 5)) : (((fRec49[1] <= 0.1f)) ? 0 : 4))) : ((iTemp131) ? ((iTemp130) ? (((iSlow83 & (fRec49[1] <= 0.001f))) ? 0 : (((fSlow75 > fRec49[1])) ? 1 : 3)) : ((iTemp129) ? 5 : iSlow82)) : ((iTemp128) ? ((((fTemp127 >= fConst17) & (fRec49[1] >= (fRec53[0] * fTemp122)))) ? 2 : 1) : iSlow76)));
			float 	fTemp135 = ((iTemp128) ? fConst18 : 0.0f);
			float 	fTemp136 = ((iTemp134) ? ((iTemp133) ? fConst21 : ((iTemp132) ? fConst21 : fConst20)) : ((iTemp131) ? ((iTemp130) ? fConst19 : fConst18) : fTemp135));
			float 	fTemp137 = fabsf(fRec50[0]);
			float 	fTemp138 = (((fTemp137 <= 0.3f)) ? fTemp136 : ((fTemp137 * ((iTemp121) ? ((iTemp134) ? ((iTemp133) ? fConst23 : ((iTemp132) ? fConst23 : fConst20)) : ((iTemp131) ? ((iTemp130) ? fConst22 : fConst17) : fTemp135)) : (((iTemp120 == 1)) ? fTemp136 : ((iTemp134) ? fConst20 : ((iTemp131) ? ((iTemp130) ? fConst20 : fConst18) : fTemp135))))) + ((1.0f - fTemp137) * fTemp136)));
			fbargraph6 = (((fTemp138 > 0.0f)) ? (fTemp127 / fTemp138) : 0.0f);
			fbargraph7 = floorf((2e+01f * fbargraph6));
			float 	fTemp139 = fbargraph7;
			float 	fTemp140 = (((fTemp139 >= 1e+01f)) ? (((fTemp139 >= 15.0f)) ? (((fTemp139 >= 18.0f)) ? (((fTemp139 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp139 >= 17.0f)) ? 0.03f : (((fTemp139 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp139 >= 13.0f)) ? (((fTemp139 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp139 >= 12.0f)) ? 0.14f : (((fTemp139 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp139 >= 5.0f)) ? (((fTemp139 >= 8.0f)) ? (((fTemp139 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp139 >= 7.0f)) ? 0.3f : (((fTemp139 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp139 >= 3.0f)) ? (((fTemp139 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp139 >= 2.0f)) ? 0.64f : (((fTemp139 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp141 = (iRec48[1] == 3);
			float 	fTemp142 = ((iTemp126) ? min(1.0f, fTemp125) : ((iTemp141) ? (fRec54[0] * fTemp140) : fSlow75));
			float 	fTemp143 = (fTemp139 + -1.0f);
			float 	fTemp144 = ((((fTemp139 > 0.0f)) ? (((fTemp143 >= 1e+01f)) ? (((fTemp143 >= 15.0f)) ? (((fTemp143 >= 18.0f)) ? (((fTemp143 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp143 >= 17.0f)) ? 0.03f : (((fTemp143 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp143 >= 13.0f)) ? (((fTemp143 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp143 >= 12.0f)) ? 0.14f : (((fTemp143 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp143 >= 5.0f)) ? (((fTemp143 >= 8.0f)) ? (((fTemp143 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp143 >= 7.0f)) ? 0.3f : (((fTemp143 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp143 >= 3.0f)) ? (((fTemp143 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp143 >= 2.0f)) ? 0.64f : (((fTemp143 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp140);
			float 	fTemp145 = (1.0f / ((iTemp141) ? (((fTemp144 > 0.0f)) ? (0.05f * (fTemp138 / fTemp144)) : 0.0f) : fTemp138));
			float 	fTemp146 = (fRec57[1] - fTemp145);
			float 	fTemp147 = (fRec57[1] + fTemp145);
			fRec57[0] = (((fTemp147 < fTemp142)) ? fTemp147 : (((fTemp146 > fTemp142)) ? fTemp146 : fTemp142));
			fRec49[0] = fRec57[0];
			fRec47[0] = (fRec49[0] - (fConst16 * ((fConst14 * fRec47[2]) + (fConst12 * fRec47[1]))));
			float 	fTemp148 = min(0.95f, (fConst24 * (((3947.8418f * fRec47[0]) + (7895.6836f * fRec47[1])) + (3947.8418f * fRec47[2]))));
			float 	fTemp149 = (fSlow87 + (fRec58[1] + -1.0f));
			float 	fTemp150 = (fSlow87 + fRec58[1]);
			int 	iTemp151 = (fTemp149 < 0.0f);
			fRec58[0] = ((iTemp151) ? fTemp150 : fTemp149);
			float 	fRec59 = ((iTemp151) ? fTemp150 : (fSlow87 + (fRec58[1] + (fSlow88 * fTemp149))));
			float 	fTemp152 = ((iTemp36) ? 0.0f : (fSlow91 + fRec61[1]));
			fRec61[0] = (fTemp152 - floorf(fTemp152));
			float 	fTemp153 = powf(((2.0f * fRec61[0]) + -1.0f),2.0f);
			fVec7[0] = fTemp153;
			float 	fTemp154 = (fSlow92 * (fTemp39 * (fVec7[0] - fVec7[1])));
			fVec8[IOTA&4095] = fTemp154;
			fRec60[0] = (((0.999f * fRec60[1]) + fVec8[IOTA&4095]) - ((fSlow98 * fVec8[(IOTA-iSlow94)&4095]) + (fSlow97 * fVec8[(IOTA-iSlow95)&4095])));
			float 	fTemp155 = (1.0f / (((iSlow105 == ((fRec65[1] > 0.0f) - (fRec65[1] < 0.0f)))) ? (((fSlow103 >= fabsf(fRec65[1]))) ? fConst17 : fConst0) : fSlow104));
			float 	fTemp156 = (fRec66[1] - fTemp155);
			float 	fTemp157 = (fRec66[1] + fTemp155);
			fRec66[0] = (((fTemp157 < fSlow102)) ? fTemp157 : (((fTemp156 > fSlow102)) ? fTemp156 : fSlow102));
			fRec65[0] = fRec66[0];
			int 	iTemp158 = ((fRec65[0] > 0.0f) + (1 - (fRec65[0] < 0.0f)));
			int 	iTemp159 = (iTemp158 == 0);
			float 	fTemp160 = ((iTemp159) ? 1.7f : 1.6f);
			iRec67[0] = iRec63[1];
			int 	iTemp161 = (iRec67[1] == iRec63[1]);
			int 	iTemp162 = (iRec63[1] == 0);
			fRec68[0] = ((iTemp162) ? fSlow100 : ((iTemp161) ? min(min(fRec68[1], fSlow100), fRec64[1]) : min(fSlow100, fRec64[1])));
			float 	fTemp163 = (fSlow100 * fTemp160);
			int 	iTemp164 = (iRec63[1] == 1);
			fRec69[0] = ((iTemp162) ? fSlow100 : ((iTemp164) ? ((iTemp161) ? max(max(fRec69[1], fTemp163), fRec64[1]) : max(fTemp163, fRec64[1])) : ((iTemp161) ? max(max(fRec69[1], fSlow100), fRec64[1]) : max(fSlow100, fRec64[1]))));
			iRec70[0] = iRec63[1];
			iRec71[0] = (((iRec70[1] != iRec63[1])) ? iTemp10 : iRec71[1]);
			float 	fTemp165 = float((iRec11[0] + (-1 - iRec71[0])));
			int 	iTemp166 = (iRec63[1] >= 1);
			int 	iTemp167 = (fSlow100 >= fRec64[1]);
			int 	iTemp168 = (iRec63[1] >= 3);
			int 	iTemp169 = (iRec63[1] >= 2);
			int 	iTemp170 = (iRec63[1] >= 5);
			int 	iTemp171 = (iRec63[1] >= 6);
			int 	iTemp172 = (iRec63[1] >= 4);
			iRec63[0] = ((iTemp172) ? ((iTemp171) ? ((iSlow106) ? 3 : ((iTemp167) ? 5 : 6)) : ((iTemp170) ? ((iSlow106) ? 3 : (((fSlow100 <= fRec64[1])) ? 6 : 5)) : (((fRec64[1] <= 0.1f)) ? 0 : 4))) : ((iTemp169) ? ((iTemp168) ? (((iSlow108 & (fRec64[1] <= 0.001f))) ? 0 : (((fSlow100 > fRec64[1])) ? 1 : 3)) : ((iTemp167) ? 5 : iSlow107)) : ((iTemp166) ? ((((fTemp165 >= fConst17) & (fRec64[1] >= (fRec68[0] * fTemp160)))) ? 2 : 1) : iSlow101)));
			float 	fTemp173 = ((iTemp166) ? fConst18 : 0.0f);
			float 	fTemp174 = ((iTemp172) ? ((iTemp171) ? fConst21 : ((iTemp170) ? fConst21 : fConst20)) : ((iTemp169) ? ((iTemp168) ? fConst19 : fConst18) : fTemp173));
			float 	fTemp175 = fabsf(fRec65[0]);
			float 	fTemp176 = (((fTemp175 <= 0.3f)) ? fTemp174 : ((fTemp175 * ((iTemp159) ? ((iTemp172) ? ((iTemp171) ? fConst23 : ((iTemp170) ? fConst23 : fConst20)) : ((iTemp169) ? ((iTemp168) ? fConst22 : fConst17) : fTemp173)) : (((iTemp158 == 1)) ? fTemp174 : ((iTemp172) ? fConst20 : ((iTemp169) ? ((iTemp168) ? fConst20 : fConst18) : fTemp173))))) + ((1.0f - fTemp175) * fTemp174)));
			fbargraph8 = (((fTemp176 > 0.0f)) ? (fTemp165 / fTemp176) : 0.0f);
			fbargraph9 = floorf((2e+01f * fbargraph8));
			float 	fTemp177 = fbargraph9;
			float 	fTemp178 = (((fTemp177 >= 1e+01f)) ? (((fTemp177 >= 15.0f)) ? (((fTemp177 >= 18.0f)) ? (((fTemp177 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp177 >= 17.0f)) ? 0.03f : (((fTemp177 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp177 >= 13.0f)) ? (((fTemp177 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp177 >= 12.0f)) ? 0.14f : (((fTemp177 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp177 >= 5.0f)) ? (((fTemp177 >= 8.0f)) ? (((fTemp177 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp177 >= 7.0f)) ? 0.3f : (((fTemp177 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp177 >= 3.0f)) ? (((fTemp177 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp177 >= 2.0f)) ? 0.64f : (((fTemp177 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp179 = (iRec63[1] == 3);
			float 	fTemp180 = ((iTemp164) ? min(1.0f, fTemp163) : ((iTemp179) ? (fRec69[0] * fTemp178) : fSlow100));
			float 	fTemp181 = (fTemp177 + -1.0f);
			float 	fTemp182 = ((((fTemp177 > 0.0f)) ? (((fTemp181 >= 1e+01f)) ? (((fTemp181 >= 15.0f)) ? (((fTemp181 >= 18.0f)) ? (((fTemp181 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp181 >= 17.0f)) ? 0.03f : (((fTemp181 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp181 >= 13.0f)) ? (((fTemp181 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp181 >= 12.0f)) ? 0.14f : (((fTemp181 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp181 >= 5.0f)) ? (((fTemp181 >= 8.0f)) ? (((fTemp181 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp181 >= 7.0f)) ? 0.3f : (((fTemp181 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp181 >= 3.0f)) ? (((fTemp181 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp181 >= 2.0f)) ? 0.64f : (((fTemp181 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp178);
			float 	fTemp183 = (1.0f / ((iTemp179) ? (((fTemp182 > 0.0f)) ? (0.05f * (fTemp176 / fTemp182)) : 0.0f) : fTemp176));
			float 	fTemp184 = (fRec72[1] - fTemp183);
			float 	fTemp185 = (fRec72[1] + fTemp183);
			fRec72[0] = (((fTemp185 < fTemp180)) ? fTemp185 : (((fTemp184 > fTemp180)) ? fTemp184 : fTemp180));
			fRec64[0] = fRec72[0];
			fRec62[0] = (fRec64[0] - (fConst16 * ((fConst14 * fRec62[2]) + (fConst12 * fRec62[1]))));
			float 	fTemp186 = min(0.95f, (fConst24 * (((3947.8418f * fRec62[0]) + (7895.6836f * fRec62[1])) + (3947.8418f * fRec62[2]))));
			float 	fTemp187 = (fSlow112 + (fRec73[1] + -1.0f));
			float 	fTemp188 = (fSlow112 + fRec73[1]);
			int 	iTemp189 = (fTemp187 < 0.0f);
			fRec73[0] = ((iTemp189) ? fTemp188 : fTemp187);
			float 	fRec74 = ((iTemp189) ? fTemp188 : (fSlow112 + (fRec73[1] + (fSlow113 * fTemp187))));
			float 	fTemp190 = ((iTemp36) ? 0.0f : (fSlow116 + fRec76[1]));
			fRec76[0] = (fTemp190 - floorf(fTemp190));
			float 	fTemp191 = powf(((2.0f * fRec76[0]) + -1.0f),2.0f);
			fVec9[0] = fTemp191;
			float 	fTemp192 = (fSlow117 * (fTemp39 * (fVec9[0] - fVec9[1])));
			fVec10[IOTA&4095] = fTemp192;
			fRec75[0] = (((0.999f * fRec75[1]) + fVec10[IOTA&4095]) - ((fSlow123 * fVec10[(IOTA-iSlow119)&4095]) + (fSlow122 * fVec10[(IOTA-iSlow120)&4095])));
			float 	fTemp193 = (1.0f / (((iSlow130 == ((fRec80[1] > 0.0f) - (fRec80[1] < 0.0f)))) ? (((fSlow128 >= fabsf(fRec80[1]))) ? fConst17 : fConst0) : fSlow129));
			float 	fTemp194 = (fRec81[1] - fTemp193);
			float 	fTemp195 = (fRec81[1] + fTemp193);
			fRec81[0] = (((fTemp195 < fSlow127)) ? fTemp195 : (((fTemp194 > fSlow127)) ? fTemp194 : fSlow127));
			fRec80[0] = fRec81[0];
			int 	iTemp196 = ((fRec80[0] > 0.0f) + (1 - (fRec80[0] < 0.0f)));
			int 	iTemp197 = (iTemp196 == 0);
			float 	fTemp198 = ((iTemp197) ? 1.7f : 1.6f);
			iRec82[0] = iRec78[1];
			int 	iTemp199 = (iRec82[1] == iRec78[1]);
			int 	iTemp200 = (iRec78[1] == 0);
			fRec83[0] = ((iTemp200) ? fSlow125 : ((iTemp199) ? min(min(fRec83[1], fSlow125), fRec79[1]) : min(fSlow125, fRec79[1])));
			float 	fTemp201 = (fSlow125 * fTemp198);
			int 	iTemp202 = (iRec78[1] == 1);
			fRec84[0] = ((iTemp200) ? fSlow125 : ((iTemp202) ? ((iTemp199) ? max(max(fRec84[1], fTemp201), fRec79[1]) : max(fTemp201, fRec79[1])) : ((iTemp199) ? max(max(fRec84[1], fSlow125), fRec79[1]) : max(fSlow125, fRec79[1]))));
			iRec85[0] = iRec78[1];
			iRec86[0] = (((iRec85[1] != iRec78[1])) ? iTemp10 : iRec86[1]);
			float 	fTemp203 = float((iRec11[0] + (-1 - iRec86[0])));
			int 	iTemp204 = (iRec78[1] >= 1);
			int 	iTemp205 = (fSlow125 >= fRec79[1]);
			int 	iTemp206 = (iRec78[1] >= 3);
			int 	iTemp207 = (iRec78[1] >= 2);
			int 	iTemp208 = (iRec78[1] >= 5);
			int 	iTemp209 = (iRec78[1] >= 6);
			int 	iTemp210 = (iRec78[1] >= 4);
			iRec78[0] = ((iTemp210) ? ((iTemp209) ? ((iSlow131) ? 3 : ((iTemp205) ? 5 : 6)) : ((iTemp208) ? ((iSlow131) ? 3 : (((fSlow125 <= fRec79[1])) ? 6 : 5)) : (((fRec79[1] <= 0.1f)) ? 0 : 4))) : ((iTemp207) ? ((iTemp206) ? (((iSlow133 & (fRec79[1] <= 0.001f))) ? 0 : (((fSlow125 > fRec79[1])) ? 1 : 3)) : ((iTemp205) ? 5 : iSlow132)) : ((iTemp204) ? ((((fTemp203 >= fConst17) & (fRec79[1] >= (fRec83[0] * fTemp198)))) ? 2 : 1) : iSlow126)));
			float 	fTemp211 = ((iTemp204) ? fConst18 : 0.0f);
			float 	fTemp212 = ((iTemp210) ? ((iTemp209) ? fConst21 : ((iTemp208) ? fConst21 : fConst20)) : ((iTemp207) ? ((iTemp206) ? fConst19 : fConst18) : fTemp211));
			float 	fTemp213 = fabsf(fRec80[0]);
			float 	fTemp214 = (((fTemp213 <= 0.3f)) ? fTemp212 : ((fTemp213 * ((iTemp197) ? ((iTemp210) ? ((iTemp209) ? fConst23 : ((iTemp208) ? fConst23 : fConst20)) : ((iTemp207) ? ((iTemp206) ? fConst22 : fConst17) : fTemp211)) : (((iTemp196 == 1)) ? fTemp212 : ((iTemp210) ? fConst20 : ((iTemp207) ? ((iTemp206) ? fConst20 : fConst18) : fTemp211))))) + ((1.0f - fTemp213) * fTemp212)));
			fbargraph10 = (((fTemp214 > 0.0f)) ? (fTemp203 / fTemp214) : 0.0f);
			fbargraph11 = floorf((2e+01f * fbargraph10));
			float 	fTemp215 = fbargraph11;
			float 	fTemp216 = (((fTemp215 >= 1e+01f)) ? (((fTemp215 >= 15.0f)) ? (((fTemp215 >= 18.0f)) ? (((fTemp215 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp215 >= 17.0f)) ? 0.03f : (((fTemp215 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp215 >= 13.0f)) ? (((fTemp215 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp215 >= 12.0f)) ? 0.14f : (((fTemp215 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp215 >= 5.0f)) ? (((fTemp215 >= 8.0f)) ? (((fTemp215 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp215 >= 7.0f)) ? 0.3f : (((fTemp215 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp215 >= 3.0f)) ? (((fTemp215 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp215 >= 2.0f)) ? 0.64f : (((fTemp215 >= 1.0f)) ? 0.74f : 0.86f)))));
			int 	iTemp217 = (iRec78[1] == 3);
			float 	fTemp218 = ((iTemp202) ? min(1.0f, fTemp201) : ((iTemp217) ? (fRec84[0] * fTemp216) : fSlow125));
			float 	fTemp219 = (fTemp215 + -1.0f);
			float 	fTemp220 = ((((fTemp215 > 0.0f)) ? (((fTemp219 >= 1e+01f)) ? (((fTemp219 >= 15.0f)) ? (((fTemp219 >= 18.0f)) ? (((fTemp219 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp219 >= 17.0f)) ? 0.03f : (((fTemp219 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp219 >= 13.0f)) ? (((fTemp219 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp219 >= 12.0f)) ? 0.14f : (((fTemp219 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp219 >= 5.0f)) ? (((fTemp219 >= 8.0f)) ? (((fTemp219 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp219 >= 7.0f)) ? 0.3f : (((fTemp219 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp219 >= 3.0f)) ? (((fTemp219 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp219 >= 2.0f)) ? 0.64f : (((fTemp219 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp216);
			float 	fTemp221 = (1.0f / ((iTemp217) ? (((fTemp220 > 0.0f)) ? (0.05f * (fTemp214 / fTemp220)) : 0.0f) : fTemp214));
			float 	fTemp222 = (fRec87[1] - fTemp221);
			float 	fTemp223 = (fRec87[1] + fTemp221);
			fRec87[0] = (((fTemp223 < fTemp218)) ? fTemp223 : (((fTemp222 > fTemp218)) ? fTemp222 : fTemp218));
			fRec79[0] = fRec87[0];
			fRec77[0] = (fRec79[0] - (fConst16 * ((fConst14 * fRec77[2]) + (fConst12 * fRec77[1]))));
			float 	fTemp224 = min(0.95f, (fConst24 * (((3947.8418f * fRec77[0]) + (7895.6836f * fRec77[1])) + (3947.8418f * fRec77[2]))));
			float 	fTemp225 = (fSlow137 + (fRec88[1] + -1.0f));
			float 	fTemp226 = (fSlow137 + fRec88[1]);
			int 	iTemp227 = (fTemp225 < 0.0f);
			fRec88[0] = ((iTemp227) ? fTemp226 : fTemp225);
			float 	fRec89 = ((iTemp227) ? fTemp226 : (fSlow137 + (fRec88[1] + (fSlow138 * fTemp225))));
			float 	fTemp228 = ((iTemp36) ? 0.0f : (fSlow141 + fRec91[1]));
			fRec91[0] = (fTemp228 - floorf(fTemp228));
			float 	fTemp229 = powf(((2.0f * fRec91[0]) + -1.0f),2.0f);
			fVec11[0] = fTemp229;
			float 	fTemp230 = (fSlow142 * (fTemp39 * (fVec11[0] - fVec11[1])));
			fVec12[IOTA&4095] = fTemp230;
			fRec90[0] = (((0.999f * fRec90[1]) + fVec12[IOTA&4095]) - ((fSlow148 * fVec12[(IOTA-iSlow144)&4095]) + (fSlow147 * fVec12[(IOTA-iSlow145)&4095])));
			fRec0[0] = ((1.37f * ((((((fTemp224 * ((fSlow149 * (fRec90[0] * ((fTemp224 + 1.0f) - fSlow125))) + (((2.0f * fRec89) + -1.0f) * (max(min((3.0f * (fSlow125 - fTemp224)), 0.3f), -0.15f) + 0.25f)))) + (fTemp186 * ((fSlow124 * (fRec75[0] * ((fTemp186 + 1.0f) - fSlow100))) + (((2.0f * fRec74) + -1.0f) * (max(min((3.0f * (fSlow100 - fTemp186)), 0.3f), -0.15f) + 0.25f))))) + (fTemp148 * ((fSlow99 * (fRec60[0] * ((fTemp148 + 1.0f) - fSlow75))) + (((2.0f * fRec59) + -1.0f) * (max(min((3.0f * (fSlow75 - fTemp148)), 0.3f), -0.15f) + 0.25f))))) + (fTemp110 * ((fSlow74 * (fRec45[0] * ((fTemp110 + 1.0f) - fSlow50))) + (((2.0f * fRec44) + -1.0f) * (max(min((3.0f * (fSlow50 - fTemp110)), 0.3f), -0.15f) + 0.25f))))) + (fTemp72 * ((fSlow49 * (fRec30[0] * ((fTemp72 + 1.0f) - fSlow25))) + (((2.0f * fRec29) + -1.0f) * (max(min((3.0f * (fSlow25 - fTemp72)), 0.3f), -0.15f) + 0.25f))))) + (fTemp32 * ((fSlow24 * (fRec15[0] * ((fTemp32 + 1.0f) - fSlow0))) + (((2.0f * fRec14) + -1.0f) * (max(min((3.0f * (fSlow0 - fTemp32)), 0.3f), -0.15f) + 0.25f)))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst29 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			IOTA = IOTA+1;
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec90[1] = fRec90[0];
			fVec11[1] = fVec11[0];
			fRec91[1] = fRec91[0];
			fRec88[1] = fRec88[0];
			fRec77[2] = fRec77[1]; fRec77[1] = fRec77[0];
			fRec79[1] = fRec79[0];
			fRec87[1] = fRec87[0];
			iRec78[1] = iRec78[0];
			iRec86[1] = iRec86[0];
			iRec85[1] = iRec85[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			iRec82[1] = iRec82[0];
			fRec80[1] = fRec80[0];
			fRec81[1] = fRec81[0];
			fRec75[1] = fRec75[0];
			fVec9[1] = fVec9[0];
			fRec76[1] = fRec76[0];
			fRec73[1] = fRec73[0];
			fRec62[2] = fRec62[1]; fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			fRec72[1] = fRec72[0];
			iRec63[1] = iRec63[0];
			iRec71[1] = iRec71[0];
			iRec70[1] = iRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			iRec67[1] = iRec67[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec60[1] = fRec60[0];
			fVec7[1] = fVec7[0];
			fRec61[1] = fRec61[0];
			fRec58[1] = fRec58[0];
			fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			fRec57[1] = fRec57[0];
			iRec48[1] = iRec48[0];
			iRec56[1] = iRec56[0];
			iRec55[1] = iRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[1] = fRec53[0];
			iRec52[1] = iRec52[0];
			fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec45[1] = fRec45[0];
			fVec5[1] = fVec5[0];
			fRec46[1] = fRec46[0];
			fRec43[1] = fRec43[0];
			fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
			fRec34[1] = fRec34[0];
			fRec42[1] = fRec42[0];
			iRec33[1] = iRec33[0];
			iRec41[1] = iRec41[0];
			iRec40[1] = iRec40[0];
			fRec39[1] = fRec39[0];
			fRec38[1] = fRec38[0];
			iRec37[1] = iRec37[0];
			fRec35[1] = fRec35[0];
			fRec36[1] = fRec36[0];
			fRec30[1] = fRec30[0];
			fVec3[1] = fVec3[0];
			fRec31[1] = fRec31[0];
			fRec28[1] = fRec28[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec27[1] = fRec27[0];
			iRec18[1] = iRec18[0];
			iRec26[1] = iRec26[0];
			iRec25[1] = iRec25[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			iRec22[1] = iRec22[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec15[1] = fRec15[0];
			fVec1[1] = fVec1[0];
			fRec16[1] = fRec16[0];
			fRec13[1] = fRec13[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec12[1] = fRec12[0];
			iRec2[1] = iRec2[0];
			iRec10[1] = iRec10[0];
			iRec11[1] = iRec11[0];
			iRec9[1] = iRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			iRec6[1] = iRec6[0];
			fRec4[1] = fRec4[0];
			fRec5[1] = fRec5[0];
			iVec0[1] = iVec0[0];
		}
	}
};



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
