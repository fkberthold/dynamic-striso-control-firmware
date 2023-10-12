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
	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	float 	fConst12;
	float 	fConst14;
	float 	fConst16;
	FAUSTFLOAT 	fslider0;
	int 	iRec4[2];
	FAUSTFLOAT 	fslider1;
	float 	fRec5[2];
	int 	iRec2[2];
	FAUSTFLOAT 	fslider2;
	float 	fConst17;
	float 	fRec8[2];
	float 	fRec7[2];
	float 	fConst18;
	float 	fConst19;
	int 	iRec9[2];
	int 	iRec11[2];
	int 	iRec10[2];
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fbargraph1;
	int 	iRec12[2];
	float 	fRec13[2];
	float 	fRec14[2];
	float 	fRec6[2];
	float 	fRec3[2];
	float 	fRec1[3];
	float 	fConst20;
	FAUSTFLOAT 	fslider3;
	float 	fConst21;
	float 	fRec15[2];
	float 	fRec18[2];
	float 	fVec1[2];
	float 	fConst22;
	float 	fVec2[4096];
	float 	fConst23;
	float 	fRec17[2];
	float 	fConst24;
	FAUSTFLOAT 	fslider4;
	int 	iRec22[2];
	FAUSTFLOAT 	fslider5;
	float 	fRec23[2];
	int 	iRec20[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec26[2];
	float 	fRec25[2];
	int 	iRec27[2];
	int 	iRec28[2];
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fbargraph3;
	int 	iRec29[2];
	float 	fRec30[2];
	float 	fRec31[2];
	float 	fRec24[2];
	float 	fRec21[2];
	float 	fRec19[3];
	FAUSTFLOAT 	fslider7;
	float 	fRec32[2];
	float 	fRec35[2];
	float 	fVec3[2];
	float 	fVec4[4096];
	float 	fRec34[2];
	FAUSTFLOAT 	fslider8;
	int 	iRec39[2];
	FAUSTFLOAT 	fslider9;
	float 	fRec40[2];
	int 	iRec37[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec43[2];
	float 	fRec42[2];
	int 	iRec44[2];
	int 	iRec45[2];
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fbargraph5;
	int 	iRec46[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec41[2];
	float 	fRec38[2];
	float 	fRec36[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec49[2];
	float 	fRec52[2];
	float 	fVec5[2];
	float 	fVec6[4096];
	float 	fRec51[2];
	FAUSTFLOAT 	fslider12;
	int 	iRec56[2];
	FAUSTFLOAT 	fslider13;
	float 	fRec57[2];
	int 	iRec54[2];
	FAUSTFLOAT 	fslider14;
	float 	fRec60[2];
	float 	fRec59[2];
	int 	iRec61[2];
	int 	iRec62[2];
	FAUSTFLOAT 	fbargraph6;
	FAUSTFLOAT 	fbargraph7;
	int 	iRec63[2];
	float 	fRec64[2];
	float 	fRec65[2];
	float 	fRec58[2];
	float 	fRec55[2];
	float 	fRec53[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec66[2];
	float 	fRec69[2];
	float 	fVec7[2];
	float 	fVec8[4096];
	float 	fRec68[2];
	FAUSTFLOAT 	fslider16;
	int 	iRec73[2];
	FAUSTFLOAT 	fslider17;
	float 	fRec74[2];
	int 	iRec71[2];
	FAUSTFLOAT 	fslider18;
	float 	fRec77[2];
	float 	fRec76[2];
	int 	iRec78[2];
	int 	iRec79[2];
	FAUSTFLOAT 	fbargraph8;
	FAUSTFLOAT 	fbargraph9;
	int 	iRec80[2];
	float 	fRec81[2];
	float 	fRec82[2];
	float 	fRec75[2];
	float 	fRec72[2];
	float 	fRec70[3];
	FAUSTFLOAT 	fslider19;
	float 	fRec83[2];
	float 	fRec86[2];
	float 	fVec9[2];
	float 	fVec10[4096];
	float 	fRec85[2];
	FAUSTFLOAT 	fslider20;
	int 	iRec90[2];
	FAUSTFLOAT 	fslider21;
	float 	fRec91[2];
	int 	iRec88[2];
	FAUSTFLOAT 	fslider22;
	float 	fRec94[2];
	float 	fRec93[2];
	int 	iRec95[2];
	int 	iRec96[2];
	FAUSTFLOAT 	fbargraph10;
	FAUSTFLOAT 	fbargraph11;
	int 	iRec97[2];
	float 	fRec98[2];
	float 	fRec99[2];
	float 	fRec92[2];
	float 	fRec89[2];
	float 	fRec87[3];
	FAUSTFLOAT 	fslider23;
	float 	fRec100[2];
	float 	fRec103[2];
	float 	fVec11[2];
	float 	fVec12[4096];
	float 	fRec102[2];
	float 	fRec0[3];
	float 	fConst25;
	int 	IOTA;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
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
		fConst18 = (0.01f * fConst0);
		fConst19 = (0.3f * fConst0);
		fConst20 = (fConst11 / (fConst1 * fConst15));
		fConst21 = (1.0f / fConst0);
		fConst22 = (0.25f * fConst0);
		fConst23 = (0.5f * fConst0);
		fConst24 = (32.703197f / fConst0);
		fConst25 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = 0.0f;
		fslider2 = 0.0f;
		fslider3 = 69.0f;
		fslider4 = 0.0f;
		fslider5 = 0.0f;
		fslider6 = 0.0f;
		fslider7 = 69.0f;
		fslider8 = 0.0f;
		fslider9 = 0.0f;
		fslider10 = 0.0f;
		fslider11 = 69.0f;
		fslider12 = 0.0f;
		fslider13 = 0.0f;
		fslider14 = 0.0f;
		fslider15 = 69.0f;
		fslider16 = 0.0f;
		fslider17 = 0.0f;
		fslider18 = 0.0f;
		fslider19 = 69.0f;
		fslider20 = 0.0f;
		fslider21 = 0.0f;
		fslider22 = 0.0f;
		fslider23 = 69.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) iRec2[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<4096; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) iRec20[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) iRec28[i] = 0;
		for (int i=0; i<2; i++) iRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<3; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<4096; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) iRec44[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<3; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<4096; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<4096; i++) fVec8[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) iRec79[i] = 0;
		for (int i=0; i<2; i++) iRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<4096; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) iRec88[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) iRec95[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<4096; i++) fVec12[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
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
		synth_interface.note[0] = &fslider23;
		synth_interface.pres[0] = &fslider20;
		synth_interface.vpres[0] = &fslider21;
		synth_interface.but_y[0] = &fslider22;
		synth_interface.note[1] = &fslider19;
		synth_interface.pres[1] = &fslider16;
		synth_interface.vpres[1] = &fslider17;
		synth_interface.but_y[1] = &fslider18;
		synth_interface.note[2] = &fslider15;
		synth_interface.pres[2] = &fslider12;
		synth_interface.vpres[2] = &fslider13;
		synth_interface.but_y[2] = &fslider14;
		synth_interface.note[3] = &fslider11;
		synth_interface.pres[3] = &fslider8;
		synth_interface.vpres[3] = &fslider9;
		synth_interface.but_y[3] = &fslider10;
		synth_interface.note[4] = &fslider7;
		synth_interface.pres[4] = &fslider4;
		synth_interface.vpres[4] = &fslider5;
		synth_interface.but_y[4] = &fslider6;
		synth_interface.note[5] = &fslider3;
		synth_interface.pres[5] = &fslider0;
		synth_interface.vpres[5] = &fslider1;
		synth_interface.but_y[5] = &fslider2;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = float(fslider0);
		int 	iSlow1 = (((fSlow0 >= 0.0f)) ? 1 : 0);
		float 	fSlow2 = float(fslider1);
		int 	iSlow3 = (fSlow0 <= 0.1f);
		int 	iSlow4 = ((iSlow3) ? 0 : 2);
		int 	iSlow5 = (fSlow0 <= 0.0f);
		float 	fSlow6 = min((2.0f * float(fslider2)), 1.0f);
		float 	fSlow7 = fabsf(fSlow6);
		float 	fSlow8 = (((fSlow7 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow9 = ((fSlow6 > 0.0f) - (fSlow6 < 0.0f));
		float 	fSlow10 = fastpow2((0.083333336f * float(fslider3)));
		float 	fSlow11 = (8.175799f * fSlow10);
		float 	fSlow12 = max(1.1920929e-07f, fabsf(fSlow11));
		float 	fSlow13 = (fConst21 * fSlow12);
		float 	fSlow14 = (1.0f - (fConst0 / fSlow12));
		float 	fSlow15 = max(fSlow11, 23.44895f);
		float 	fSlow16 = max(2e+01f, fabsf(fSlow15));
		float 	fSlow17 = (fConst21 * fSlow16);
		float 	fSlow18 = (fConst22 / fSlow16);
		float 	fSlow19 = max(0.0f, min(2047.0f, (fConst23 / fSlow15)));
		int 	iSlow20 = int(fSlow19);
		int 	iSlow21 = (iSlow20 + 1);
		float 	fSlow22 = floorf(fSlow19);
		float 	fSlow23 = (fSlow19 - fSlow22);
		float 	fSlow24 = (fSlow22 + (1.0f - fSlow19));
		float 	fSlow25 = (fConst24 * fSlow10);
		float 	fSlow26 = float(fslider4);
		int 	iSlow27 = (((fSlow26 >= 0.0f)) ? 1 : 0);
		float 	fSlow28 = float(fslider5);
		int 	iSlow29 = (fSlow26 <= 0.1f);
		int 	iSlow30 = ((iSlow29) ? 0 : 2);
		int 	iSlow31 = (fSlow26 <= 0.0f);
		float 	fSlow32 = min((2.0f * float(fslider6)), 1.0f);
		float 	fSlow33 = fabsf(fSlow32);
		float 	fSlow34 = (((fSlow33 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow35 = ((fSlow32 > 0.0f) - (fSlow32 < 0.0f));
		float 	fSlow36 = fastpow2((0.083333336f * float(fslider7)));
		float 	fSlow37 = (8.175799f * fSlow36);
		float 	fSlow38 = max(1.1920929e-07f, fabsf(fSlow37));
		float 	fSlow39 = (fConst21 * fSlow38);
		float 	fSlow40 = (1.0f - (fConst0 / fSlow38));
		float 	fSlow41 = max(fSlow37, 23.44895f);
		float 	fSlow42 = max(2e+01f, fabsf(fSlow41));
		float 	fSlow43 = (fConst21 * fSlow42);
		float 	fSlow44 = (fConst22 / fSlow42);
		float 	fSlow45 = max(0.0f, min(2047.0f, (fConst23 / fSlow41)));
		int 	iSlow46 = int(fSlow45);
		int 	iSlow47 = (iSlow46 + 1);
		float 	fSlow48 = floorf(fSlow45);
		float 	fSlow49 = (fSlow45 - fSlow48);
		float 	fSlow50 = (fSlow48 + (1.0f - fSlow45));
		float 	fSlow51 = (fConst24 * fSlow36);
		float 	fSlow52 = float(fslider8);
		int 	iSlow53 = (((fSlow52 >= 0.0f)) ? 1 : 0);
		float 	fSlow54 = float(fslider9);
		int 	iSlow55 = (fSlow52 <= 0.1f);
		int 	iSlow56 = ((iSlow55) ? 0 : 2);
		int 	iSlow57 = (fSlow52 <= 0.0f);
		float 	fSlow58 = min((2.0f * float(fslider10)), 1.0f);
		float 	fSlow59 = fabsf(fSlow58);
		float 	fSlow60 = (((fSlow59 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow61 = ((fSlow58 > 0.0f) - (fSlow58 < 0.0f));
		float 	fSlow62 = fastpow2((0.083333336f * float(fslider11)));
		float 	fSlow63 = (8.175799f * fSlow62);
		float 	fSlow64 = max(1.1920929e-07f, fabsf(fSlow63));
		float 	fSlow65 = (fConst21 * fSlow64);
		float 	fSlow66 = (1.0f - (fConst0 / fSlow64));
		float 	fSlow67 = max(fSlow63, 23.44895f);
		float 	fSlow68 = max(2e+01f, fabsf(fSlow67));
		float 	fSlow69 = (fConst21 * fSlow68);
		float 	fSlow70 = (fConst22 / fSlow68);
		float 	fSlow71 = max(0.0f, min(2047.0f, (fConst23 / fSlow67)));
		int 	iSlow72 = int(fSlow71);
		int 	iSlow73 = (iSlow72 + 1);
		float 	fSlow74 = floorf(fSlow71);
		float 	fSlow75 = (fSlow71 - fSlow74);
		float 	fSlow76 = (fSlow74 + (1.0f - fSlow71));
		float 	fSlow77 = (fConst24 * fSlow62);
		float 	fSlow78 = float(fslider12);
		int 	iSlow79 = (((fSlow78 >= 0.0f)) ? 1 : 0);
		float 	fSlow80 = float(fslider13);
		int 	iSlow81 = (fSlow78 <= 0.1f);
		int 	iSlow82 = ((iSlow81) ? 0 : 2);
		int 	iSlow83 = (fSlow78 <= 0.0f);
		float 	fSlow84 = min((2.0f * float(fslider14)), 1.0f);
		float 	fSlow85 = fabsf(fSlow84);
		float 	fSlow86 = (((fSlow85 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow87 = ((fSlow84 > 0.0f) - (fSlow84 < 0.0f));
		float 	fSlow88 = fastpow2((0.083333336f * float(fslider15)));
		float 	fSlow89 = (8.175799f * fSlow88);
		float 	fSlow90 = max(1.1920929e-07f, fabsf(fSlow89));
		float 	fSlow91 = (fConst21 * fSlow90);
		float 	fSlow92 = (1.0f - (fConst0 / fSlow90));
		float 	fSlow93 = max(fSlow89, 23.44895f);
		float 	fSlow94 = max(2e+01f, fabsf(fSlow93));
		float 	fSlow95 = (fConst21 * fSlow94);
		float 	fSlow96 = (fConst22 / fSlow94);
		float 	fSlow97 = max(0.0f, min(2047.0f, (fConst23 / fSlow93)));
		int 	iSlow98 = int(fSlow97);
		int 	iSlow99 = (iSlow98 + 1);
		float 	fSlow100 = floorf(fSlow97);
		float 	fSlow101 = (fSlow97 - fSlow100);
		float 	fSlow102 = (fSlow100 + (1.0f - fSlow97));
		float 	fSlow103 = (fConst24 * fSlow88);
		float 	fSlow104 = float(fslider16);
		int 	iSlow105 = (((fSlow104 >= 0.0f)) ? 1 : 0);
		float 	fSlow106 = float(fslider17);
		int 	iSlow107 = (fSlow104 <= 0.1f);
		int 	iSlow108 = ((iSlow107) ? 0 : 2);
		int 	iSlow109 = (fSlow104 <= 0.0f);
		float 	fSlow110 = min((2.0f * float(fslider18)), 1.0f);
		float 	fSlow111 = fabsf(fSlow110);
		float 	fSlow112 = (((fSlow111 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow113 = ((fSlow110 > 0.0f) - (fSlow110 < 0.0f));
		float 	fSlow114 = fastpow2((0.083333336f * float(fslider19)));
		float 	fSlow115 = (8.175799f * fSlow114);
		float 	fSlow116 = max(1.1920929e-07f, fabsf(fSlow115));
		float 	fSlow117 = (fConst21 * fSlow116);
		float 	fSlow118 = (1.0f - (fConst0 / fSlow116));
		float 	fSlow119 = max(fSlow115, 23.44895f);
		float 	fSlow120 = max(2e+01f, fabsf(fSlow119));
		float 	fSlow121 = (fConst21 * fSlow120);
		float 	fSlow122 = (fConst22 / fSlow120);
		float 	fSlow123 = max(0.0f, min(2047.0f, (fConst23 / fSlow119)));
		int 	iSlow124 = int(fSlow123);
		int 	iSlow125 = (iSlow124 + 1);
		float 	fSlow126 = floorf(fSlow123);
		float 	fSlow127 = (fSlow123 - fSlow126);
		float 	fSlow128 = (fSlow126 + (1.0f - fSlow123));
		float 	fSlow129 = (fConst24 * fSlow114);
		float 	fSlow130 = float(fslider20);
		int 	iSlow131 = (((fSlow130 >= 0.0f)) ? 1 : 0);
		float 	fSlow132 = float(fslider21);
		int 	iSlow133 = (fSlow130 <= 0.1f);
		int 	iSlow134 = ((iSlow133) ? 0 : 2);
		int 	iSlow135 = (fSlow130 <= 0.0f);
		float 	fSlow136 = min((2.0f * float(fslider22)), 1.0f);
		float 	fSlow137 = fabsf(fSlow136);
		float 	fSlow138 = (((fSlow137 >= 0.2f)) ? fConst17 : fConst0);
		int 	iSlow139 = ((fSlow136 > 0.0f) - (fSlow136 < 0.0f));
		float 	fSlow140 = fastpow2((0.083333336f * float(fslider23)));
		float 	fSlow141 = (8.175799f * fSlow140);
		float 	fSlow142 = max(1.1920929e-07f, fabsf(fSlow141));
		float 	fSlow143 = (fConst21 * fSlow142);
		float 	fSlow144 = (1.0f - (fConst0 / fSlow142));
		float 	fSlow145 = max(fSlow141, 23.44895f);
		float 	fSlow146 = max(2e+01f, fabsf(fSlow145));
		float 	fSlow147 = (fConst21 * fSlow146);
		float 	fSlow148 = (fConst22 / fSlow146);
		float 	fSlow149 = max(0.0f, min(2047.0f, (fConst23 / fSlow145)));
		int 	iSlow150 = int(fSlow149);
		int 	iSlow151 = (iSlow150 + 1);
		float 	fSlow152 = floorf(fSlow149);
		float 	fSlow153 = (fSlow149 - fSlow152);
		float 	fSlow154 = (fSlow152 + (1.0f - fSlow149));
		float 	fSlow155 = (fConst24 * fSlow140);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			iRec4[0] = iRec2[1];
			fRec5[0] = (((iRec4[1] != iRec2[1])) ? fSlow2 : max(fRec5[1], fSlow2));
			int 	iTemp0 = (fSlow0 >= fRec3[1]);
			int 	iTemp1 = (((iRec2[1] >= 3)) ? (((iRec2[1] >= 5)) ? ((iSlow3) ? 3 : ((iTemp0) ? 4 : 5)) : (((iRec2[1] >= 4)) ? ((iSlow3) ? 3 : (((fSlow0 <= fRec3[1])) ? 5 : 4)) : (((iSlow5 & (fRec3[1] <= 0.001f))) ? 0 : (((fSlow0 > fRec3[1])) ? 1 : 3)))) : (((iRec2[1] >= 2)) ? ((iTemp0) ? 4 : iSlow4) : (((iRec2[1] >= 1)) ? (((fRec3[1] >= fRec5[0])) ? 2 : 1) : iSlow1)));
			iRec2[0] = iTemp1;
			float 	fTemp2 = (1.0f / (((iSlow9 == ((fRec7[1] > 0.0f) - (fRec7[1] < 0.0f)))) ? (((fSlow7 >= fabsf(fRec7[1]))) ? fConst17 : fConst0) : fSlow8));
			float 	fTemp3 = (fRec8[1] - fTemp2);
			float 	fTemp4 = (fRec8[1] + fTemp2);
			fRec8[0] = (((fTemp4 < fSlow6)) ? fTemp4 : (((fTemp3 > fSlow6)) ? fTemp3 : fSlow6));
			fRec7[0] = fRec8[0];
			float 	fTemp5 = fabsf(fRec7[0]);
			float 	fTemp6 = ((((iTemp1 >= 3)) ? fConst19 : (((iTemp1 >= 2)) ? fConst17 : (((iTemp1 >= 1)) ? fConst18 : 0.0f))) * (fTemp5 + (1.0f - fTemp5)));
			iRec9[0] = iRec2[1];
			iRec11[0] = (iRec11[1] + 1);
			int 	iTemp7 = (iRec11[0] + -1);
			iRec10[0] = (((iRec9[1] != iRec2[1])) ? iTemp7 : iRec10[1]);
			fbargraph0 = (((fTemp6 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec10[0]))) / fTemp6) : 0.0f);
			fbargraph1 = floorf((2e+01f * fbargraph0));
			float 	fTemp8 = fbargraph1;
			float 	fTemp9 = (((fTemp8 >= 1e+01f)) ? (((fTemp8 >= 15.0f)) ? (((fTemp8 >= 18.0f)) ? (((fTemp8 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp8 >= 17.0f)) ? 0.03f : (((fTemp8 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp8 >= 13.0f)) ? (((fTemp8 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp8 >= 12.0f)) ? 0.14f : (((fTemp8 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp8 >= 5.0f)) ? (((fTemp8 >= 8.0f)) ? (((fTemp8 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp8 >= 7.0f)) ? 0.3f : (((fTemp8 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp8 >= 3.0f)) ? (((fTemp8 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp8 >= 2.0f)) ? 0.64f : (((fTemp8 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec12[0] = iRec2[1];
			int 	iTemp10 = (iRec12[1] == iRec2[1]);
			int 	iTemp11 = (iRec2[1] == 0);
			fRec13[0] = ((iTemp11) ? fSlow0 : ((iTemp10) ? min(min(fRec13[1], fSlow0), fRec3[1]) : min(fSlow0, fRec3[1])));
			fRec14[0] = ((iTemp11) ? fSlow0 : ((iTemp10) ? max(max(fRec14[1], fSlow0), fRec3[1]) : max(fSlow0, fRec3[1])));
			int 	iTemp12 = (iRec2[1] == 3);
			float 	fTemp13 = (((iRec2[1] == 1)) ? min(1.0f, fRec5[0]) : ((iTemp11) ? 0.0f : ((iTemp12) ? (fRec14[0] * fTemp9) : fSlow0)));
			float 	fTemp14 = (fTemp8 + -1.0f);
			float 	fTemp15 = ((((fTemp8 > 0.0f)) ? (((fTemp14 >= 1e+01f)) ? (((fTemp14 >= 15.0f)) ? (((fTemp14 >= 18.0f)) ? (((fTemp14 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp14 >= 17.0f)) ? 0.03f : (((fTemp14 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp14 >= 13.0f)) ? (((fTemp14 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp14 >= 12.0f)) ? 0.14f : (((fTemp14 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp14 >= 5.0f)) ? (((fTemp14 >= 8.0f)) ? (((fTemp14 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp14 >= 7.0f)) ? 0.3f : (((fTemp14 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp14 >= 3.0f)) ? (((fTemp14 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp14 >= 2.0f)) ? 0.64f : (((fTemp14 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp9);
			float 	fTemp16 = (1.0f / ((iTemp11) ? 0.0001f : ((iTemp12) ? (((fTemp15 > 0.0f)) ? (0.05f * (fTemp6 / fTemp15)) : 0.0f) : fTemp6)));
			float 	fTemp17 = (fRec6[1] - fTemp16);
			float 	fTemp18 = (fRec6[1] + fTemp16);
			fRec6[0] = (((fTemp18 < fTemp13)) ? fTemp18 : (((fTemp17 > fTemp13)) ? fTemp17 : fTemp13));
			fRec3[0] = fRec6[0];
			fRec1[0] = (fRec3[0] - (fConst16 * ((fConst14 * fRec1[2]) + (fConst12 * fRec1[1]))));
			float 	fTemp19 = min(0.95f, (fConst20 * (((3947.8418f * fRec1[0]) + (7895.6836f * fRec1[1])) + (3947.8418f * fRec1[2]))));
			float 	fTemp20 = (fSlow13 + (fRec15[1] + -1.0f));
			float 	fTemp21 = (fSlow13 + fRec15[1]);
			int 	iTemp22 = (fTemp20 < 0.0f);
			fRec15[0] = ((iTemp22) ? fTemp21 : fTemp20);
			float 	fRec16 = ((iTemp22) ? fTemp21 : (fSlow13 + (fRec15[1] + (fSlow14 * fTemp20))));
			int 	iTemp23 = (1 - iVec0[1]);
			float 	fTemp24 = ((iTemp23) ? 0.0f : (fSlow17 + fRec18[1]));
			fRec18[0] = (fTemp24 - floorf(fTemp24));
			float 	fTemp25 = powf(((2.0f * fRec18[0]) + -1.0f),2.0f);
			fVec1[0] = fTemp25;
			float 	fTemp26 = float(iVec0[1]);
			float 	fTemp27 = (fSlow18 * (fTemp26 * (fVec1[0] - fVec1[1])));
			fVec2[IOTA&4095] = fTemp27;
			fRec17[0] = (((0.999f * fRec17[1]) + fVec2[IOTA&4095]) - ((fSlow24 * fVec2[(IOTA-iSlow20)&4095]) + (fSlow23 * fVec2[(IOTA-iSlow21)&4095])));
			iRec22[0] = iRec20[1];
			fRec23[0] = (((iRec22[1] != iRec20[1])) ? fSlow28 : max(fRec23[1], fSlow28));
			int 	iTemp28 = (fSlow26 >= fRec21[1]);
			int 	iTemp29 = (((iRec20[1] >= 3)) ? (((iRec20[1] >= 5)) ? ((iSlow29) ? 3 : ((iTemp28) ? 4 : 5)) : (((iRec20[1] >= 4)) ? ((iSlow29) ? 3 : (((fSlow26 <= fRec21[1])) ? 5 : 4)) : (((iSlow31 & (fRec21[1] <= 0.001f))) ? 0 : (((fSlow26 > fRec21[1])) ? 1 : 3)))) : (((iRec20[1] >= 2)) ? ((iTemp28) ? 4 : iSlow30) : (((iRec20[1] >= 1)) ? (((fRec21[1] >= fRec23[0])) ? 2 : 1) : iSlow27)));
			iRec20[0] = iTemp29;
			float 	fTemp30 = (1.0f / (((iSlow35 == ((fRec25[1] > 0.0f) - (fRec25[1] < 0.0f)))) ? (((fSlow33 >= fabsf(fRec25[1]))) ? fConst17 : fConst0) : fSlow34));
			float 	fTemp31 = (fRec26[1] - fTemp30);
			float 	fTemp32 = (fRec26[1] + fTemp30);
			fRec26[0] = (((fTemp32 < fSlow32)) ? fTemp32 : (((fTemp31 > fSlow32)) ? fTemp31 : fSlow32));
			fRec25[0] = fRec26[0];
			float 	fTemp33 = fabsf(fRec25[0]);
			float 	fTemp34 = ((((iTemp29 >= 3)) ? fConst19 : (((iTemp29 >= 2)) ? fConst17 : (((iTemp29 >= 1)) ? fConst18 : 0.0f))) * (fTemp33 + (1.0f - fTemp33)));
			iRec27[0] = iRec20[1];
			iRec28[0] = (((iRec27[1] != iRec20[1])) ? iTemp7 : iRec28[1]);
			fbargraph2 = (((fTemp34 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec28[0]))) / fTemp34) : 0.0f);
			fbargraph3 = floorf((2e+01f * fbargraph2));
			float 	fTemp35 = fbargraph3;
			float 	fTemp36 = (((fTemp35 >= 1e+01f)) ? (((fTemp35 >= 15.0f)) ? (((fTemp35 >= 18.0f)) ? (((fTemp35 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp35 >= 17.0f)) ? 0.03f : (((fTemp35 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp35 >= 13.0f)) ? (((fTemp35 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp35 >= 12.0f)) ? 0.14f : (((fTemp35 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp35 >= 5.0f)) ? (((fTemp35 >= 8.0f)) ? (((fTemp35 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp35 >= 7.0f)) ? 0.3f : (((fTemp35 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp35 >= 3.0f)) ? (((fTemp35 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp35 >= 2.0f)) ? 0.64f : (((fTemp35 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec29[0] = iRec20[1];
			int 	iTemp37 = (iRec29[1] == iRec20[1]);
			int 	iTemp38 = (iRec20[1] == 0);
			fRec30[0] = ((iTemp38) ? fSlow26 : ((iTemp37) ? min(min(fRec30[1], fSlow26), fRec21[1]) : min(fSlow26, fRec21[1])));
			fRec31[0] = ((iTemp38) ? fSlow26 : ((iTemp37) ? max(max(fRec31[1], fSlow26), fRec21[1]) : max(fSlow26, fRec21[1])));
			int 	iTemp39 = (iRec20[1] == 3);
			float 	fTemp40 = (((iRec20[1] == 1)) ? min(1.0f, fRec23[0]) : ((iTemp38) ? 0.0f : ((iTemp39) ? (fRec31[0] * fTemp36) : fSlow26)));
			float 	fTemp41 = (fTemp35 + -1.0f);
			float 	fTemp42 = ((((fTemp35 > 0.0f)) ? (((fTemp41 >= 1e+01f)) ? (((fTemp41 >= 15.0f)) ? (((fTemp41 >= 18.0f)) ? (((fTemp41 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp41 >= 17.0f)) ? 0.03f : (((fTemp41 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp41 >= 13.0f)) ? (((fTemp41 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp41 >= 12.0f)) ? 0.14f : (((fTemp41 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp41 >= 5.0f)) ? (((fTemp41 >= 8.0f)) ? (((fTemp41 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp41 >= 7.0f)) ? 0.3f : (((fTemp41 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp41 >= 3.0f)) ? (((fTemp41 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp41 >= 2.0f)) ? 0.64f : (((fTemp41 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp36);
			float 	fTemp43 = (1.0f / ((iTemp38) ? 0.0001f : ((iTemp39) ? (((fTemp42 > 0.0f)) ? (0.05f * (fTemp34 / fTemp42)) : 0.0f) : fTemp34)));
			float 	fTemp44 = (fRec24[1] - fTemp43);
			float 	fTemp45 = (fRec24[1] + fTemp43);
			fRec24[0] = (((fTemp45 < fTemp40)) ? fTemp45 : (((fTemp44 > fTemp40)) ? fTemp44 : fTemp40));
			fRec21[0] = fRec24[0];
			fRec19[0] = (fRec21[0] - (fConst16 * ((fConst14 * fRec19[2]) + (fConst12 * fRec19[1]))));
			float 	fTemp46 = min(0.95f, (fConst20 * (((3947.8418f * fRec19[0]) + (7895.6836f * fRec19[1])) + (3947.8418f * fRec19[2]))));
			float 	fTemp47 = (fSlow39 + (fRec32[1] + -1.0f));
			float 	fTemp48 = (fSlow39 + fRec32[1]);
			int 	iTemp49 = (fTemp47 < 0.0f);
			fRec32[0] = ((iTemp49) ? fTemp48 : fTemp47);
			float 	fRec33 = ((iTemp49) ? fTemp48 : (fSlow39 + (fRec32[1] + (fSlow40 * fTemp47))));
			float 	fTemp50 = ((iTemp23) ? 0.0f : (fSlow43 + fRec35[1]));
			fRec35[0] = (fTemp50 - floorf(fTemp50));
			float 	fTemp51 = powf(((2.0f * fRec35[0]) + -1.0f),2.0f);
			fVec3[0] = fTemp51;
			float 	fTemp52 = (fSlow44 * (fTemp26 * (fVec3[0] - fVec3[1])));
			fVec4[IOTA&4095] = fTemp52;
			fRec34[0] = (((0.999f * fRec34[1]) + fVec4[IOTA&4095]) - ((fSlow50 * fVec4[(IOTA-iSlow46)&4095]) + (fSlow49 * fVec4[(IOTA-iSlow47)&4095])));
			iRec39[0] = iRec37[1];
			fRec40[0] = (((iRec39[1] != iRec37[1])) ? fSlow54 : max(fRec40[1], fSlow54));
			int 	iTemp53 = (fSlow52 >= fRec38[1]);
			int 	iTemp54 = (((iRec37[1] >= 3)) ? (((iRec37[1] >= 5)) ? ((iSlow55) ? 3 : ((iTemp53) ? 4 : 5)) : (((iRec37[1] >= 4)) ? ((iSlow55) ? 3 : (((fSlow52 <= fRec38[1])) ? 5 : 4)) : (((iSlow57 & (fRec38[1] <= 0.001f))) ? 0 : (((fSlow52 > fRec38[1])) ? 1 : 3)))) : (((iRec37[1] >= 2)) ? ((iTemp53) ? 4 : iSlow56) : (((iRec37[1] >= 1)) ? (((fRec38[1] >= fRec40[0])) ? 2 : 1) : iSlow53)));
			iRec37[0] = iTemp54;
			float 	fTemp55 = (1.0f / (((iSlow61 == ((fRec42[1] > 0.0f) - (fRec42[1] < 0.0f)))) ? (((fSlow59 >= fabsf(fRec42[1]))) ? fConst17 : fConst0) : fSlow60));
			float 	fTemp56 = (fRec43[1] - fTemp55);
			float 	fTemp57 = (fRec43[1] + fTemp55);
			fRec43[0] = (((fTemp57 < fSlow58)) ? fTemp57 : (((fTemp56 > fSlow58)) ? fTemp56 : fSlow58));
			fRec42[0] = fRec43[0];
			float 	fTemp58 = fabsf(fRec42[0]);
			float 	fTemp59 = ((((iTemp54 >= 3)) ? fConst19 : (((iTemp54 >= 2)) ? fConst17 : (((iTemp54 >= 1)) ? fConst18 : 0.0f))) * (fTemp58 + (1.0f - fTemp58)));
			iRec44[0] = iRec37[1];
			iRec45[0] = (((iRec44[1] != iRec37[1])) ? iTemp7 : iRec45[1]);
			fbargraph4 = (((fTemp59 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec45[0]))) / fTemp59) : 0.0f);
			fbargraph5 = floorf((2e+01f * fbargraph4));
			float 	fTemp60 = fbargraph5;
			float 	fTemp61 = (((fTemp60 >= 1e+01f)) ? (((fTemp60 >= 15.0f)) ? (((fTemp60 >= 18.0f)) ? (((fTemp60 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp60 >= 17.0f)) ? 0.03f : (((fTemp60 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp60 >= 13.0f)) ? (((fTemp60 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp60 >= 12.0f)) ? 0.14f : (((fTemp60 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp60 >= 5.0f)) ? (((fTemp60 >= 8.0f)) ? (((fTemp60 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp60 >= 7.0f)) ? 0.3f : (((fTemp60 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp60 >= 3.0f)) ? (((fTemp60 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp60 >= 2.0f)) ? 0.64f : (((fTemp60 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec46[0] = iRec37[1];
			int 	iTemp62 = (iRec46[1] == iRec37[1]);
			int 	iTemp63 = (iRec37[1] == 0);
			fRec47[0] = ((iTemp63) ? fSlow52 : ((iTemp62) ? min(min(fRec47[1], fSlow52), fRec38[1]) : min(fSlow52, fRec38[1])));
			fRec48[0] = ((iTemp63) ? fSlow52 : ((iTemp62) ? max(max(fRec48[1], fSlow52), fRec38[1]) : max(fSlow52, fRec38[1])));
			int 	iTemp64 = (iRec37[1] == 3);
			float 	fTemp65 = (((iRec37[1] == 1)) ? min(1.0f, fRec40[0]) : ((iTemp63) ? 0.0f : ((iTemp64) ? (fRec48[0] * fTemp61) : fSlow52)));
			float 	fTemp66 = (fTemp60 + -1.0f);
			float 	fTemp67 = ((((fTemp60 > 0.0f)) ? (((fTemp66 >= 1e+01f)) ? (((fTemp66 >= 15.0f)) ? (((fTemp66 >= 18.0f)) ? (((fTemp66 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp66 >= 17.0f)) ? 0.03f : (((fTemp66 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp66 >= 13.0f)) ? (((fTemp66 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp66 >= 12.0f)) ? 0.14f : (((fTemp66 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp66 >= 5.0f)) ? (((fTemp66 >= 8.0f)) ? (((fTemp66 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp66 >= 7.0f)) ? 0.3f : (((fTemp66 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp66 >= 3.0f)) ? (((fTemp66 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp66 >= 2.0f)) ? 0.64f : (((fTemp66 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp61);
			float 	fTemp68 = (1.0f / ((iTemp63) ? 0.0001f : ((iTemp64) ? (((fTemp67 > 0.0f)) ? (0.05f * (fTemp59 / fTemp67)) : 0.0f) : fTemp59)));
			float 	fTemp69 = (fRec41[1] - fTemp68);
			float 	fTemp70 = (fRec41[1] + fTemp68);
			fRec41[0] = (((fTemp70 < fTemp65)) ? fTemp70 : (((fTemp69 > fTemp65)) ? fTemp69 : fTemp65));
			fRec38[0] = fRec41[0];
			fRec36[0] = (fRec38[0] - (fConst16 * ((fConst14 * fRec36[2]) + (fConst12 * fRec36[1]))));
			float 	fTemp71 = min(0.95f, (fConst20 * (((3947.8418f * fRec36[0]) + (7895.6836f * fRec36[1])) + (3947.8418f * fRec36[2]))));
			float 	fTemp72 = (fSlow65 + (fRec49[1] + -1.0f));
			float 	fTemp73 = (fSlow65 + fRec49[1]);
			int 	iTemp74 = (fTemp72 < 0.0f);
			fRec49[0] = ((iTemp74) ? fTemp73 : fTemp72);
			float 	fRec50 = ((iTemp74) ? fTemp73 : (fSlow65 + (fRec49[1] + (fSlow66 * fTemp72))));
			float 	fTemp75 = ((iTemp23) ? 0.0f : (fSlow69 + fRec52[1]));
			fRec52[0] = (fTemp75 - floorf(fTemp75));
			float 	fTemp76 = powf(((2.0f * fRec52[0]) + -1.0f),2.0f);
			fVec5[0] = fTemp76;
			float 	fTemp77 = (fSlow70 * (fTemp26 * (fVec5[0] - fVec5[1])));
			fVec6[IOTA&4095] = fTemp77;
			fRec51[0] = (((0.999f * fRec51[1]) + fVec6[IOTA&4095]) - ((fSlow76 * fVec6[(IOTA-iSlow72)&4095]) + (fSlow75 * fVec6[(IOTA-iSlow73)&4095])));
			iRec56[0] = iRec54[1];
			fRec57[0] = (((iRec56[1] != iRec54[1])) ? fSlow80 : max(fRec57[1], fSlow80));
			int 	iTemp78 = (fSlow78 >= fRec55[1]);
			int 	iTemp79 = (((iRec54[1] >= 3)) ? (((iRec54[1] >= 5)) ? ((iSlow81) ? 3 : ((iTemp78) ? 4 : 5)) : (((iRec54[1] >= 4)) ? ((iSlow81) ? 3 : (((fSlow78 <= fRec55[1])) ? 5 : 4)) : (((iSlow83 & (fRec55[1] <= 0.001f))) ? 0 : (((fSlow78 > fRec55[1])) ? 1 : 3)))) : (((iRec54[1] >= 2)) ? ((iTemp78) ? 4 : iSlow82) : (((iRec54[1] >= 1)) ? (((fRec55[1] >= fRec57[0])) ? 2 : 1) : iSlow79)));
			iRec54[0] = iTemp79;
			float 	fTemp80 = (1.0f / (((iSlow87 == ((fRec59[1] > 0.0f) - (fRec59[1] < 0.0f)))) ? (((fSlow85 >= fabsf(fRec59[1]))) ? fConst17 : fConst0) : fSlow86));
			float 	fTemp81 = (fRec60[1] - fTemp80);
			float 	fTemp82 = (fRec60[1] + fTemp80);
			fRec60[0] = (((fTemp82 < fSlow84)) ? fTemp82 : (((fTemp81 > fSlow84)) ? fTemp81 : fSlow84));
			fRec59[0] = fRec60[0];
			float 	fTemp83 = fabsf(fRec59[0]);
			float 	fTemp84 = ((((iTemp79 >= 3)) ? fConst19 : (((iTemp79 >= 2)) ? fConst17 : (((iTemp79 >= 1)) ? fConst18 : 0.0f))) * (fTemp83 + (1.0f - fTemp83)));
			iRec61[0] = iRec54[1];
			iRec62[0] = (((iRec61[1] != iRec54[1])) ? iTemp7 : iRec62[1]);
			fbargraph6 = (((fTemp84 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec62[0]))) / fTemp84) : 0.0f);
			fbargraph7 = floorf((2e+01f * fbargraph6));
			float 	fTemp85 = fbargraph7;
			float 	fTemp86 = (((fTemp85 >= 1e+01f)) ? (((fTemp85 >= 15.0f)) ? (((fTemp85 >= 18.0f)) ? (((fTemp85 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp85 >= 17.0f)) ? 0.03f : (((fTemp85 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp85 >= 13.0f)) ? (((fTemp85 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp85 >= 12.0f)) ? 0.14f : (((fTemp85 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp85 >= 5.0f)) ? (((fTemp85 >= 8.0f)) ? (((fTemp85 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp85 >= 7.0f)) ? 0.3f : (((fTemp85 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp85 >= 3.0f)) ? (((fTemp85 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp85 >= 2.0f)) ? 0.64f : (((fTemp85 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec63[0] = iRec54[1];
			int 	iTemp87 = (iRec63[1] == iRec54[1]);
			int 	iTemp88 = (iRec54[1] == 0);
			fRec64[0] = ((iTemp88) ? fSlow78 : ((iTemp87) ? min(min(fRec64[1], fSlow78), fRec55[1]) : min(fSlow78, fRec55[1])));
			fRec65[0] = ((iTemp88) ? fSlow78 : ((iTemp87) ? max(max(fRec65[1], fSlow78), fRec55[1]) : max(fSlow78, fRec55[1])));
			int 	iTemp89 = (iRec54[1] == 3);
			float 	fTemp90 = (((iRec54[1] == 1)) ? min(1.0f, fRec57[0]) : ((iTemp88) ? 0.0f : ((iTemp89) ? (fRec65[0] * fTemp86) : fSlow78)));
			float 	fTemp91 = (fTemp85 + -1.0f);
			float 	fTemp92 = ((((fTemp85 > 0.0f)) ? (((fTemp91 >= 1e+01f)) ? (((fTemp91 >= 15.0f)) ? (((fTemp91 >= 18.0f)) ? (((fTemp91 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp91 >= 17.0f)) ? 0.03f : (((fTemp91 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp91 >= 13.0f)) ? (((fTemp91 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp91 >= 12.0f)) ? 0.14f : (((fTemp91 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp91 >= 5.0f)) ? (((fTemp91 >= 8.0f)) ? (((fTemp91 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp91 >= 7.0f)) ? 0.3f : (((fTemp91 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp91 >= 3.0f)) ? (((fTemp91 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp91 >= 2.0f)) ? 0.64f : (((fTemp91 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp86);
			float 	fTemp93 = (1.0f / ((iTemp88) ? 0.0001f : ((iTemp89) ? (((fTemp92 > 0.0f)) ? (0.05f * (fTemp84 / fTemp92)) : 0.0f) : fTemp84)));
			float 	fTemp94 = (fRec58[1] - fTemp93);
			float 	fTemp95 = (fRec58[1] + fTemp93);
			fRec58[0] = (((fTemp95 < fTemp90)) ? fTemp95 : (((fTemp94 > fTemp90)) ? fTemp94 : fTemp90));
			fRec55[0] = fRec58[0];
			fRec53[0] = (fRec55[0] - (fConst16 * ((fConst14 * fRec53[2]) + (fConst12 * fRec53[1]))));
			float 	fTemp96 = min(0.95f, (fConst20 * (((3947.8418f * fRec53[0]) + (7895.6836f * fRec53[1])) + (3947.8418f * fRec53[2]))));
			float 	fTemp97 = (fSlow91 + (fRec66[1] + -1.0f));
			float 	fTemp98 = (fSlow91 + fRec66[1]);
			int 	iTemp99 = (fTemp97 < 0.0f);
			fRec66[0] = ((iTemp99) ? fTemp98 : fTemp97);
			float 	fRec67 = ((iTemp99) ? fTemp98 : (fSlow91 + (fRec66[1] + (fSlow92 * fTemp97))));
			float 	fTemp100 = ((iTemp23) ? 0.0f : (fSlow95 + fRec69[1]));
			fRec69[0] = (fTemp100 - floorf(fTemp100));
			float 	fTemp101 = powf(((2.0f * fRec69[0]) + -1.0f),2.0f);
			fVec7[0] = fTemp101;
			float 	fTemp102 = (fSlow96 * (fTemp26 * (fVec7[0] - fVec7[1])));
			fVec8[IOTA&4095] = fTemp102;
			fRec68[0] = (((0.999f * fRec68[1]) + fVec8[IOTA&4095]) - ((fSlow102 * fVec8[(IOTA-iSlow98)&4095]) + (fSlow101 * fVec8[(IOTA-iSlow99)&4095])));
			iRec73[0] = iRec71[1];
			fRec74[0] = (((iRec73[1] != iRec71[1])) ? fSlow106 : max(fRec74[1], fSlow106));
			int 	iTemp103 = (fSlow104 >= fRec72[1]);
			int 	iTemp104 = (((iRec71[1] >= 3)) ? (((iRec71[1] >= 5)) ? ((iSlow107) ? 3 : ((iTemp103) ? 4 : 5)) : (((iRec71[1] >= 4)) ? ((iSlow107) ? 3 : (((fSlow104 <= fRec72[1])) ? 5 : 4)) : (((iSlow109 & (fRec72[1] <= 0.001f))) ? 0 : (((fSlow104 > fRec72[1])) ? 1 : 3)))) : (((iRec71[1] >= 2)) ? ((iTemp103) ? 4 : iSlow108) : (((iRec71[1] >= 1)) ? (((fRec72[1] >= fRec74[0])) ? 2 : 1) : iSlow105)));
			iRec71[0] = iTemp104;
			float 	fTemp105 = (1.0f / (((iSlow113 == ((fRec76[1] > 0.0f) - (fRec76[1] < 0.0f)))) ? (((fSlow111 >= fabsf(fRec76[1]))) ? fConst17 : fConst0) : fSlow112));
			float 	fTemp106 = (fRec77[1] - fTemp105);
			float 	fTemp107 = (fRec77[1] + fTemp105);
			fRec77[0] = (((fTemp107 < fSlow110)) ? fTemp107 : (((fTemp106 > fSlow110)) ? fTemp106 : fSlow110));
			fRec76[0] = fRec77[0];
			float 	fTemp108 = fabsf(fRec76[0]);
			float 	fTemp109 = ((((iTemp104 >= 3)) ? fConst19 : (((iTemp104 >= 2)) ? fConst17 : (((iTemp104 >= 1)) ? fConst18 : 0.0f))) * (fTemp108 + (1.0f - fTemp108)));
			iRec78[0] = iRec71[1];
			iRec79[0] = (((iRec78[1] != iRec71[1])) ? iTemp7 : iRec79[1]);
			fbargraph8 = (((fTemp109 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec79[0]))) / fTemp109) : 0.0f);
			fbargraph9 = floorf((2e+01f * fbargraph8));
			float 	fTemp110 = fbargraph9;
			float 	fTemp111 = (((fTemp110 >= 1e+01f)) ? (((fTemp110 >= 15.0f)) ? (((fTemp110 >= 18.0f)) ? (((fTemp110 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp110 >= 17.0f)) ? 0.03f : (((fTemp110 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp110 >= 13.0f)) ? (((fTemp110 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp110 >= 12.0f)) ? 0.14f : (((fTemp110 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp110 >= 5.0f)) ? (((fTemp110 >= 8.0f)) ? (((fTemp110 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp110 >= 7.0f)) ? 0.3f : (((fTemp110 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp110 >= 3.0f)) ? (((fTemp110 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp110 >= 2.0f)) ? 0.64f : (((fTemp110 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec80[0] = iRec71[1];
			int 	iTemp112 = (iRec80[1] == iRec71[1]);
			int 	iTemp113 = (iRec71[1] == 0);
			fRec81[0] = ((iTemp113) ? fSlow104 : ((iTemp112) ? min(min(fRec81[1], fSlow104), fRec72[1]) : min(fSlow104, fRec72[1])));
			fRec82[0] = ((iTemp113) ? fSlow104 : ((iTemp112) ? max(max(fRec82[1], fSlow104), fRec72[1]) : max(fSlow104, fRec72[1])));
			int 	iTemp114 = (iRec71[1] == 3);
			float 	fTemp115 = (((iRec71[1] == 1)) ? min(1.0f, fRec74[0]) : ((iTemp113) ? 0.0f : ((iTemp114) ? (fRec82[0] * fTemp111) : fSlow104)));
			float 	fTemp116 = (fTemp110 + -1.0f);
			float 	fTemp117 = ((((fTemp110 > 0.0f)) ? (((fTemp116 >= 1e+01f)) ? (((fTemp116 >= 15.0f)) ? (((fTemp116 >= 18.0f)) ? (((fTemp116 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp116 >= 17.0f)) ? 0.03f : (((fTemp116 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp116 >= 13.0f)) ? (((fTemp116 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp116 >= 12.0f)) ? 0.14f : (((fTemp116 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp116 >= 5.0f)) ? (((fTemp116 >= 8.0f)) ? (((fTemp116 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp116 >= 7.0f)) ? 0.3f : (((fTemp116 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp116 >= 3.0f)) ? (((fTemp116 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp116 >= 2.0f)) ? 0.64f : (((fTemp116 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp111);
			float 	fTemp118 = (1.0f / ((iTemp113) ? 0.0001f : ((iTemp114) ? (((fTemp117 > 0.0f)) ? (0.05f * (fTemp109 / fTemp117)) : 0.0f) : fTemp109)));
			float 	fTemp119 = (fRec75[1] - fTemp118);
			float 	fTemp120 = (fRec75[1] + fTemp118);
			fRec75[0] = (((fTemp120 < fTemp115)) ? fTemp120 : (((fTemp119 > fTemp115)) ? fTemp119 : fTemp115));
			fRec72[0] = fRec75[0];
			fRec70[0] = (fRec72[0] - (fConst16 * ((fConst14 * fRec70[2]) + (fConst12 * fRec70[1]))));
			float 	fTemp121 = min(0.95f, (fConst20 * (((3947.8418f * fRec70[0]) + (7895.6836f * fRec70[1])) + (3947.8418f * fRec70[2]))));
			float 	fTemp122 = (fSlow117 + (fRec83[1] + -1.0f));
			float 	fTemp123 = (fSlow117 + fRec83[1]);
			int 	iTemp124 = (fTemp122 < 0.0f);
			fRec83[0] = ((iTemp124) ? fTemp123 : fTemp122);
			float 	fRec84 = ((iTemp124) ? fTemp123 : (fSlow117 + (fRec83[1] + (fSlow118 * fTemp122))));
			float 	fTemp125 = ((iTemp23) ? 0.0f : (fSlow121 + fRec86[1]));
			fRec86[0] = (fTemp125 - floorf(fTemp125));
			float 	fTemp126 = powf(((2.0f * fRec86[0]) + -1.0f),2.0f);
			fVec9[0] = fTemp126;
			float 	fTemp127 = (fSlow122 * (fTemp26 * (fVec9[0] - fVec9[1])));
			fVec10[IOTA&4095] = fTemp127;
			fRec85[0] = (((0.999f * fRec85[1]) + fVec10[IOTA&4095]) - ((fSlow128 * fVec10[(IOTA-iSlow124)&4095]) + (fSlow127 * fVec10[(IOTA-iSlow125)&4095])));
			iRec90[0] = iRec88[1];
			fRec91[0] = (((iRec90[1] != iRec88[1])) ? fSlow132 : max(fRec91[1], fSlow132));
			int 	iTemp128 = (fSlow130 >= fRec89[1]);
			int 	iTemp129 = (((iRec88[1] >= 3)) ? (((iRec88[1] >= 5)) ? ((iSlow133) ? 3 : ((iTemp128) ? 4 : 5)) : (((iRec88[1] >= 4)) ? ((iSlow133) ? 3 : (((fSlow130 <= fRec89[1])) ? 5 : 4)) : (((iSlow135 & (fRec89[1] <= 0.001f))) ? 0 : (((fSlow130 > fRec89[1])) ? 1 : 3)))) : (((iRec88[1] >= 2)) ? ((iTemp128) ? 4 : iSlow134) : (((iRec88[1] >= 1)) ? (((fRec89[1] >= fRec91[0])) ? 2 : 1) : iSlow131)));
			iRec88[0] = iTemp129;
			float 	fTemp130 = (1.0f / (((iSlow139 == ((fRec93[1] > 0.0f) - (fRec93[1] < 0.0f)))) ? (((fSlow137 >= fabsf(fRec93[1]))) ? fConst17 : fConst0) : fSlow138));
			float 	fTemp131 = (fRec94[1] - fTemp130);
			float 	fTemp132 = (fRec94[1] + fTemp130);
			fRec94[0] = (((fTemp132 < fSlow136)) ? fTemp132 : (((fTemp131 > fSlow136)) ? fTemp131 : fSlow136));
			fRec93[0] = fRec94[0];
			float 	fTemp133 = fabsf(fRec93[0]);
			float 	fTemp134 = ((((iTemp129 >= 3)) ? fConst19 : (((iTemp129 >= 2)) ? fConst17 : (((iTemp129 >= 1)) ? fConst18 : 0.0f))) * (fTemp133 + (1.0f - fTemp133)));
			iRec95[0] = iRec88[1];
			iRec96[0] = (((iRec95[1] != iRec88[1])) ? iTemp7 : iRec96[1]);
			fbargraph10 = (((fTemp134 > 0.0f)) ? (float((iRec11[0] + (-1 - iRec96[0]))) / fTemp134) : 0.0f);
			fbargraph11 = floorf((2e+01f * fbargraph10));
			float 	fTemp135 = fbargraph11;
			float 	fTemp136 = (((fTemp135 >= 1e+01f)) ? (((fTemp135 >= 15.0f)) ? (((fTemp135 >= 18.0f)) ? (((fTemp135 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp135 >= 17.0f)) ? 0.03f : (((fTemp135 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp135 >= 13.0f)) ? (((fTemp135 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp135 >= 12.0f)) ? 0.14f : (((fTemp135 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp135 >= 5.0f)) ? (((fTemp135 >= 8.0f)) ? (((fTemp135 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp135 >= 7.0f)) ? 0.3f : (((fTemp135 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp135 >= 3.0f)) ? (((fTemp135 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp135 >= 2.0f)) ? 0.64f : (((fTemp135 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec97[0] = iRec88[1];
			int 	iTemp137 = (iRec97[1] == iRec88[1]);
			int 	iTemp138 = (iRec88[1] == 0);
			fRec98[0] = ((iTemp138) ? fSlow130 : ((iTemp137) ? min(min(fRec98[1], fSlow130), fRec89[1]) : min(fSlow130, fRec89[1])));
			fRec99[0] = ((iTemp138) ? fSlow130 : ((iTemp137) ? max(max(fRec99[1], fSlow130), fRec89[1]) : max(fSlow130, fRec89[1])));
			int 	iTemp139 = (iRec88[1] == 3);
			float 	fTemp140 = (((iRec88[1] == 1)) ? min(1.0f, fRec91[0]) : ((iTemp138) ? 0.0f : ((iTemp139) ? (fRec99[0] * fTemp136) : fSlow130)));
			float 	fTemp141 = (fTemp135 + -1.0f);
			float 	fTemp142 = ((((fTemp135 > 0.0f)) ? (((fTemp141 >= 1e+01f)) ? (((fTemp141 >= 15.0f)) ? (((fTemp141 >= 18.0f)) ? (((fTemp141 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp141 >= 17.0f)) ? 0.03f : (((fTemp141 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp141 >= 13.0f)) ? (((fTemp141 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp141 >= 12.0f)) ? 0.14f : (((fTemp141 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp141 >= 5.0f)) ? (((fTemp141 >= 8.0f)) ? (((fTemp141 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp141 >= 7.0f)) ? 0.3f : (((fTemp141 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp141 >= 3.0f)) ? (((fTemp141 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp141 >= 2.0f)) ? 0.64f : (((fTemp141 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp136);
			float 	fTemp143 = (1.0f / ((iTemp138) ? 0.0001f : ((iTemp139) ? (((fTemp142 > 0.0f)) ? (0.05f * (fTemp134 / fTemp142)) : 0.0f) : fTemp134)));
			float 	fTemp144 = (fRec92[1] - fTemp143);
			float 	fTemp145 = (fRec92[1] + fTemp143);
			fRec92[0] = (((fTemp145 < fTemp140)) ? fTemp145 : (((fTemp144 > fTemp140)) ? fTemp144 : fTemp140));
			fRec89[0] = fRec92[0];
			fRec87[0] = (fRec89[0] - (fConst16 * ((fConst14 * fRec87[2]) + (fConst12 * fRec87[1]))));
			float 	fTemp146 = min(0.95f, (fConst20 * (((3947.8418f * fRec87[0]) + (7895.6836f * fRec87[1])) + (3947.8418f * fRec87[2]))));
			float 	fTemp147 = (fSlow143 + (fRec100[1] + -1.0f));
			float 	fTemp148 = (fSlow143 + fRec100[1]);
			int 	iTemp149 = (fTemp147 < 0.0f);
			fRec100[0] = ((iTemp149) ? fTemp148 : fTemp147);
			float 	fRec101 = ((iTemp149) ? fTemp148 : (fSlow143 + (fRec100[1] + (fSlow144 * fTemp147))));
			float 	fTemp150 = ((iTemp23) ? 0.0f : (fSlow147 + fRec103[1]));
			fRec103[0] = (fTemp150 - floorf(fTemp150));
			float 	fTemp151 = powf(((2.0f * fRec103[0]) + -1.0f),2.0f);
			fVec11[0] = fTemp151;
			float 	fTemp152 = (fSlow148 * (fTemp26 * (fVec11[0] - fVec11[1])));
			fVec12[IOTA&4095] = fTemp152;
			fRec102[0] = (((0.999f * fRec102[1]) + fVec12[IOTA&4095]) - ((fSlow154 * fVec12[(IOTA-iSlow150)&4095]) + (fSlow153 * fVec12[(IOTA-iSlow151)&4095])));
			fRec0[0] = ((1.37f * ((((((fTemp146 * ((fSlow155 * (fRec102[0] * ((fTemp146 + 1.0f) - fSlow130))) + (((2.0f * fRec101) + -1.0f) * (max(min((3.0f * (fSlow130 - fTemp146)), 0.3f), -0.15f) + 0.25f)))) + (fTemp121 * ((fSlow129 * (fRec85[0] * ((fTemp121 + 1.0f) - fSlow104))) + (((2.0f * fRec84) + -1.0f) * (max(min((3.0f * (fSlow104 - fTemp121)), 0.3f), -0.15f) + 0.25f))))) + (fTemp96 * ((fSlow103 * (fRec68[0] * ((fTemp96 + 1.0f) - fSlow78))) + (((2.0f * fRec67) + -1.0f) * (max(min((3.0f * (fSlow78 - fTemp96)), 0.3f), -0.15f) + 0.25f))))) + (fTemp71 * ((fSlow77 * (fRec51[0] * ((fTemp71 + 1.0f) - fSlow52))) + (((2.0f * fRec50) + -1.0f) * (max(min((3.0f * (fSlow52 - fTemp71)), 0.3f), -0.15f) + 0.25f))))) + (fTemp46 * ((fSlow51 * (fRec34[0] * ((fTemp46 + 1.0f) - fSlow26))) + (((2.0f * fRec33) + -1.0f) * (max(min((3.0f * (fSlow26 - fTemp46)), 0.3f), -0.15f) + 0.25f))))) + (fTemp19 * ((fSlow25 * (fRec17[0] * ((fTemp19 + 1.0f) - fSlow0))) + (((2.0f * fRec16) + -1.0f) * (max(min((3.0f * (fSlow0 - fTemp19)), 0.3f), -0.15f) + 0.25f)))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst25 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			IOTA = IOTA+1;
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec102[1] = fRec102[0];
			fVec11[1] = fVec11[0];
			fRec103[1] = fRec103[0];
			fRec100[1] = fRec100[0];
			fRec87[2] = fRec87[1]; fRec87[1] = fRec87[0];
			fRec89[1] = fRec89[0];
			fRec92[1] = fRec92[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			iRec97[1] = iRec97[0];
			iRec96[1] = iRec96[0];
			iRec95[1] = iRec95[0];
			fRec93[1] = fRec93[0];
			fRec94[1] = fRec94[0];
			iRec88[1] = iRec88[0];
			fRec91[1] = fRec91[0];
			iRec90[1] = iRec90[0];
			fRec85[1] = fRec85[0];
			fVec9[1] = fVec9[0];
			fRec86[1] = fRec86[0];
			fRec83[1] = fRec83[0];
			fRec70[2] = fRec70[1]; fRec70[1] = fRec70[0];
			fRec72[1] = fRec72[0];
			fRec75[1] = fRec75[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			iRec80[1] = iRec80[0];
			iRec79[1] = iRec79[0];
			iRec78[1] = iRec78[0];
			fRec76[1] = fRec76[0];
			fRec77[1] = fRec77[0];
			iRec71[1] = iRec71[0];
			fRec74[1] = fRec74[0];
			iRec73[1] = iRec73[0];
			fRec68[1] = fRec68[0];
			fVec7[1] = fVec7[0];
			fRec69[1] = fRec69[0];
			fRec66[1] = fRec66[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec55[1] = fRec55[0];
			fRec58[1] = fRec58[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			iRec63[1] = iRec63[0];
			iRec62[1] = iRec62[0];
			iRec61[1] = iRec61[0];
			fRec59[1] = fRec59[0];
			fRec60[1] = fRec60[0];
			iRec54[1] = iRec54[0];
			fRec57[1] = fRec57[0];
			iRec56[1] = iRec56[0];
			fRec51[1] = fRec51[0];
			fVec5[1] = fVec5[0];
			fRec52[1] = fRec52[0];
			fRec49[1] = fRec49[0];
			fRec36[2] = fRec36[1]; fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			fRec41[1] = fRec41[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			iRec46[1] = iRec46[0];
			iRec45[1] = iRec45[0];
			iRec44[1] = iRec44[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			iRec37[1] = iRec37[0];
			fRec40[1] = fRec40[0];
			iRec39[1] = iRec39[0];
			fRec34[1] = fRec34[0];
			fVec3[1] = fVec3[0];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec19[2] = fRec19[1]; fRec19[1] = fRec19[0];
			fRec21[1] = fRec21[0];
			fRec24[1] = fRec24[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			iRec29[1] = iRec29[0];
			iRec28[1] = iRec28[0];
			iRec27[1] = iRec27[0];
			fRec25[1] = fRec25[0];
			fRec26[1] = fRec26[0];
			iRec20[1] = iRec20[0];
			fRec23[1] = fRec23[0];
			iRec22[1] = iRec22[0];
			fRec17[1] = fRec17[0];
			fVec1[1] = fVec1[0];
			fRec18[1] = fRec18[0];
			fRec15[1] = fRec15[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec3[1] = fRec3[0];
			fRec6[1] = fRec6[0];
			fRec14[1] = fRec14[0];
			fRec13[1] = fRec13[0];
			iRec12[1] = iRec12[0];
			iRec10[1] = iRec10[0];
			iRec11[1] = iRec11[0];
			iRec9[1] = iRec9[0];
			fRec7[1] = fRec7[0];
			fRec8[1] = fRec8[0];
			iRec2[1] = iRec2[0];
			fRec5[1] = fRec5[0];
			iRec4[1] = iRec4[0];
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
