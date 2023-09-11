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
	float 	fRec87[2];
	float 	fRec79[2];
	float 	fRec77[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec88[2];
	float 	fRec91[2];
	float 	fVec11[2];
	float 	fVec12[4096];
	float 	fRec90[2];
	float 	fConst29;
	float 	fRec0[3];
	float 	fConst30;
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
		m->declare("filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
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
		fConst29 = (1.37f * fConst24);
		fConst30 = (0.0f - (2.0f / fConst7));
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
			iRec2[0] = ((iTemp18) ? ((iTemp17) ? ((iSlow6) ? 3 : ((iTemp13) ? 5 : 6)) : ((iTemp16) ? ((iSlow6) ? 3 : (((fSlow0 <= fRec3[1])) ? 6 : 5)) : (((fRec3[1] <= 0.1f)) ? 0 : 4))) : ((iTemp15) ? ((iTemp14) ? (((iSlow8 & (fRec3[1] <= 0.001f))) ? 4 : (((fSlow0 > fRec3[1])) ? 1 : 3)) : ((iTemp13) ? 5 : iSlow7)) : ((iTemp12) ? ((((fTemp11 >= fConst17) & (fRec3[1] >= (fRec7[0] * fTemp5)))) ? 2 : 1) : iSlow1)));
			float 	fTemp19 = ((iTemp12) ? fConst18 : 0.0f);
			float 	fTemp20 = ((iTemp18) ? ((iTemp17) ? fConst21 : ((iTemp16) ? fConst21 : fConst20)) : ((iTemp15) ? ((iTemp14) ? fConst19 : fConst18) : fTemp19));
			float 	fTemp21 = fabsf(fRec4[0]);
			float 	fTemp22 = (((fTemp21 <= 0.3f)) ? fTemp20 : ((fTemp21 * ((iTemp4) ? ((iTemp18) ? ((iTemp17) ? fConst23 : ((iTemp16) ? fConst23 : fConst20)) : ((iTemp15) ? ((iTemp14) ? fConst22 : fConst17) : fTemp19)) : (((iTemp3 == 1)) ? fTemp20 : ((iTemp18) ? fConst20 : ((iTemp15) ? ((iTemp14) ? fConst20 : fConst18) : fTemp19))))) + ((1.0f - fTemp21) * fTemp20)));
			float 	fTemp23 = floorf((2e+01f * (fTemp11 / fTemp22)));
			int 	iTemp24 = (iRec2[1] == 3);
			float 	fTemp25 = ((iTemp9) ? min(1.0f, fTemp8) : ((iTemp24) ? (fRec8[0] * (((fTemp23 >= 1e+01f)) ? (((fTemp23 >= 15.0f)) ? (((fTemp23 >= 18.0f)) ? (((fTemp23 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp23 >= 17.0f)) ? 0.03f : (((fTemp23 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp23 >= 13.0f)) ? (((fTemp23 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp23 >= 12.0f)) ? 0.14f : (((fTemp23 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp23 >= 5.0f)) ? (((fTemp23 >= 8.0f)) ? (((fTemp23 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp23 >= 7.0f)) ? 0.3f : (((fTemp23 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp23 >= 3.0f)) ? (((fTemp23 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp23 >= 2.0f)) ? 0.64f : (((fTemp23 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow0));
			float 	fTemp26 = (1.0f / ((iTemp24) ? (0.05f * fTemp22) : fTemp22));
			float 	fTemp27 = (fRec12[1] - fTemp26);
			float 	fTemp28 = (fRec12[1] + fTemp26);
			fRec12[0] = (((fTemp28 < fTemp25)) ? fTemp28 : (((fTemp27 > fTemp25)) ? fTemp27 : fTemp25));
			fRec3[0] = fRec12[0];
			fRec1[0] = (fRec3[0] - (fConst16 * ((fConst14 * fRec1[2]) + (fConst12 * fRec1[1]))));
			float 	fTemp29 = (((3947.8418f * fRec1[0]) + (7895.6836f * fRec1[1])) + (3947.8418f * fRec1[2]));
			float 	fTemp30 = (fConst24 * fTemp29);
			float 	fTemp31 = (fSlow12 + (fRec13[1] + -1.0f));
			float 	fTemp32 = (fSlow12 + fRec13[1]);
			int 	iTemp33 = (fTemp31 < 0.0f);
			fRec13[0] = ((iTemp33) ? fTemp32 : fTemp31);
			float 	fRec14 = ((iTemp33) ? fTemp32 : (fSlow12 + (fRec13[1] + (fSlow13 * fTemp31))));
			int 	iTemp34 = (1 - iVec0[1]);
			float 	fTemp35 = ((iTemp34) ? 0.0f : (fSlow16 + fRec16[1]));
			fRec16[0] = (fTemp35 - floorf(fTemp35));
			float 	fTemp36 = powf(((2.0f * fRec16[0]) + -1.0f),2.0f);
			fVec1[0] = fTemp36;
			float 	fTemp37 = float(iVec0[1]);
			float 	fTemp38 = (fSlow17 * (fTemp37 * (fVec1[0] - fVec1[1])));
			fVec2[IOTA&4095] = fTemp38;
			fRec15[0] = (((0.999f * fRec15[1]) + fVec2[IOTA&4095]) - ((fSlow23 * fVec2[(IOTA-iSlow19)&4095]) + (fSlow22 * fVec2[(IOTA-iSlow20)&4095])));
			float 	fTemp39 = (1.0f / (((iSlow30 == ((fRec20[1] > 0.0f) - (fRec20[1] < 0.0f)))) ? (((fSlow28 >= fabsf(fRec20[1]))) ? fConst17 : fConst0) : fSlow29));
			float 	fTemp40 = (fRec21[1] - fTemp39);
			float 	fTemp41 = (fRec21[1] + fTemp39);
			fRec21[0] = (((fTemp41 < fSlow27)) ? fTemp41 : (((fTemp40 > fSlow27)) ? fTemp40 : fSlow27));
			fRec20[0] = fRec21[0];
			int 	iTemp42 = ((fRec20[0] > 0.0f) + (1 - (fRec20[0] < 0.0f)));
			int 	iTemp43 = (iTemp42 == 0);
			float 	fTemp44 = ((iTemp43) ? 1.7f : 1.6f);
			iRec22[0] = iRec18[1];
			int 	iTemp45 = (iRec22[1] == iRec18[1]);
			int 	iTemp46 = (iRec18[1] == 0);
			fRec23[0] = ((iTemp46) ? fSlow25 : ((iTemp45) ? min(min(fRec23[1], fSlow25), fRec19[1]) : min(fSlow25, fRec19[1])));
			float 	fTemp47 = (fSlow25 * fTemp44);
			int 	iTemp48 = (iRec18[1] == 1);
			fRec24[0] = ((iTemp46) ? fSlow25 : ((iTemp48) ? ((iTemp45) ? max(max(fRec24[1], fTemp47), fRec19[1]) : max(fTemp47, fRec19[1])) : ((iTemp45) ? max(max(fRec24[1], fSlow25), fRec19[1]) : max(fSlow25, fRec19[1]))));
			iRec25[0] = iRec18[1];
			iRec26[0] = (((iRec25[1] != iRec18[1])) ? iTemp10 : iRec26[1]);
			float 	fTemp49 = float((iRec11[0] + (-1 - iRec26[0])));
			int 	iTemp50 = (iRec18[1] >= 1);
			int 	iTemp51 = (fSlow25 >= fRec19[1]);
			int 	iTemp52 = (iRec18[1] >= 3);
			int 	iTemp53 = (iRec18[1] >= 2);
			int 	iTemp54 = (iRec18[1] >= 5);
			int 	iTemp55 = (iRec18[1] >= 6);
			int 	iTemp56 = (iRec18[1] >= 4);
			iRec18[0] = ((iTemp56) ? ((iTemp55) ? ((iSlow31) ? 3 : ((iTemp51) ? 5 : 6)) : ((iTemp54) ? ((iSlow31) ? 3 : (((fSlow25 <= fRec19[1])) ? 6 : 5)) : (((fRec19[1] <= 0.1f)) ? 0 : 4))) : ((iTemp53) ? ((iTemp52) ? (((iSlow33 & (fRec19[1] <= 0.001f))) ? 4 : (((fSlow25 > fRec19[1])) ? 1 : 3)) : ((iTemp51) ? 5 : iSlow32)) : ((iTemp50) ? ((((fTemp49 >= fConst17) & (fRec19[1] >= (fRec23[0] * fTemp44)))) ? 2 : 1) : iSlow26)));
			float 	fTemp57 = ((iTemp50) ? fConst18 : 0.0f);
			float 	fTemp58 = ((iTemp56) ? ((iTemp55) ? fConst21 : ((iTemp54) ? fConst21 : fConst20)) : ((iTemp53) ? ((iTemp52) ? fConst19 : fConst18) : fTemp57));
			float 	fTemp59 = fabsf(fRec20[0]);
			float 	fTemp60 = (((fTemp59 <= 0.3f)) ? fTemp58 : ((fTemp59 * ((iTemp43) ? ((iTemp56) ? ((iTemp55) ? fConst23 : ((iTemp54) ? fConst23 : fConst20)) : ((iTemp53) ? ((iTemp52) ? fConst22 : fConst17) : fTemp57)) : (((iTemp42 == 1)) ? fTemp58 : ((iTemp56) ? fConst20 : ((iTemp53) ? ((iTemp52) ? fConst20 : fConst18) : fTemp57))))) + ((1.0f - fTemp59) * fTemp58)));
			float 	fTemp61 = floorf((2e+01f * (fTemp49 / fTemp60)));
			int 	iTemp62 = (iRec18[1] == 3);
			float 	fTemp63 = ((iTemp48) ? min(1.0f, fTemp47) : ((iTemp62) ? (fRec24[0] * (((fTemp61 >= 1e+01f)) ? (((fTemp61 >= 15.0f)) ? (((fTemp61 >= 18.0f)) ? (((fTemp61 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp61 >= 17.0f)) ? 0.03f : (((fTemp61 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp61 >= 13.0f)) ? (((fTemp61 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp61 >= 12.0f)) ? 0.14f : (((fTemp61 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp61 >= 5.0f)) ? (((fTemp61 >= 8.0f)) ? (((fTemp61 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp61 >= 7.0f)) ? 0.3f : (((fTemp61 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp61 >= 3.0f)) ? (((fTemp61 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp61 >= 2.0f)) ? 0.64f : (((fTemp61 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow25));
			float 	fTemp64 = (1.0f / ((iTemp62) ? (0.05f * fTemp60) : fTemp60));
			float 	fTemp65 = (fRec27[1] - fTemp64);
			float 	fTemp66 = (fRec27[1] + fTemp64);
			fRec27[0] = (((fTemp66 < fTemp63)) ? fTemp66 : (((fTemp65 > fTemp63)) ? fTemp65 : fTemp63));
			fRec19[0] = fRec27[0];
			fRec17[0] = (fRec19[0] - (fConst16 * ((fConst14 * fRec17[2]) + (fConst12 * fRec17[1]))));
			float 	fTemp67 = (((3947.8418f * fRec17[0]) + (7895.6836f * fRec17[1])) + (3947.8418f * fRec17[2]));
			float 	fTemp68 = (fConst24 * fTemp67);
			float 	fTemp69 = (fSlow37 + (fRec28[1] + -1.0f));
			float 	fTemp70 = (fSlow37 + fRec28[1]);
			int 	iTemp71 = (fTemp69 < 0.0f);
			fRec28[0] = ((iTemp71) ? fTemp70 : fTemp69);
			float 	fRec29 = ((iTemp71) ? fTemp70 : (fSlow37 + (fRec28[1] + (fSlow38 * fTemp69))));
			float 	fTemp72 = ((iTemp34) ? 0.0f : (fSlow41 + fRec31[1]));
			fRec31[0] = (fTemp72 - floorf(fTemp72));
			float 	fTemp73 = powf(((2.0f * fRec31[0]) + -1.0f),2.0f);
			fVec3[0] = fTemp73;
			float 	fTemp74 = (fSlow42 * (fTemp37 * (fVec3[0] - fVec3[1])));
			fVec4[IOTA&4095] = fTemp74;
			fRec30[0] = (((0.999f * fRec30[1]) + fVec4[IOTA&4095]) - ((fSlow48 * fVec4[(IOTA-iSlow44)&4095]) + (fSlow47 * fVec4[(IOTA-iSlow45)&4095])));
			float 	fTemp75 = (1.0f / (((iSlow55 == ((fRec35[1] > 0.0f) - (fRec35[1] < 0.0f)))) ? (((fSlow53 >= fabsf(fRec35[1]))) ? fConst17 : fConst0) : fSlow54));
			float 	fTemp76 = (fRec36[1] - fTemp75);
			float 	fTemp77 = (fRec36[1] + fTemp75);
			fRec36[0] = (((fTemp77 < fSlow52)) ? fTemp77 : (((fTemp76 > fSlow52)) ? fTemp76 : fSlow52));
			fRec35[0] = fRec36[0];
			int 	iTemp78 = ((fRec35[0] > 0.0f) + (1 - (fRec35[0] < 0.0f)));
			int 	iTemp79 = (iTemp78 == 0);
			float 	fTemp80 = ((iTemp79) ? 1.7f : 1.6f);
			iRec37[0] = iRec33[1];
			int 	iTemp81 = (iRec37[1] == iRec33[1]);
			int 	iTemp82 = (iRec33[1] == 0);
			fRec38[0] = ((iTemp82) ? fSlow50 : ((iTemp81) ? min(min(fRec38[1], fSlow50), fRec34[1]) : min(fSlow50, fRec34[1])));
			float 	fTemp83 = (fSlow50 * fTemp80);
			int 	iTemp84 = (iRec33[1] == 1);
			fRec39[0] = ((iTemp82) ? fSlow50 : ((iTemp84) ? ((iTemp81) ? max(max(fRec39[1], fTemp83), fRec34[1]) : max(fTemp83, fRec34[1])) : ((iTemp81) ? max(max(fRec39[1], fSlow50), fRec34[1]) : max(fSlow50, fRec34[1]))));
			iRec40[0] = iRec33[1];
			iRec41[0] = (((iRec40[1] != iRec33[1])) ? iTemp10 : iRec41[1]);
			float 	fTemp85 = float((iRec11[0] + (-1 - iRec41[0])));
			int 	iTemp86 = (iRec33[1] >= 1);
			int 	iTemp87 = (fSlow50 >= fRec34[1]);
			int 	iTemp88 = (iRec33[1] >= 3);
			int 	iTemp89 = (iRec33[1] >= 2);
			int 	iTemp90 = (iRec33[1] >= 5);
			int 	iTemp91 = (iRec33[1] >= 6);
			int 	iTemp92 = (iRec33[1] >= 4);
			iRec33[0] = ((iTemp92) ? ((iTemp91) ? ((iSlow56) ? 3 : ((iTemp87) ? 5 : 6)) : ((iTemp90) ? ((iSlow56) ? 3 : (((fSlow50 <= fRec34[1])) ? 6 : 5)) : (((fRec34[1] <= 0.1f)) ? 0 : 4))) : ((iTemp89) ? ((iTemp88) ? (((iSlow58 & (fRec34[1] <= 0.001f))) ? 4 : (((fSlow50 > fRec34[1])) ? 1 : 3)) : ((iTemp87) ? 5 : iSlow57)) : ((iTemp86) ? ((((fTemp85 >= fConst17) & (fRec34[1] >= (fRec38[0] * fTemp80)))) ? 2 : 1) : iSlow51)));
			float 	fTemp93 = ((iTemp86) ? fConst18 : 0.0f);
			float 	fTemp94 = ((iTemp92) ? ((iTemp91) ? fConst21 : ((iTemp90) ? fConst21 : fConst20)) : ((iTemp89) ? ((iTemp88) ? fConst19 : fConst18) : fTemp93));
			float 	fTemp95 = fabsf(fRec35[0]);
			float 	fTemp96 = (((fTemp95 <= 0.3f)) ? fTemp94 : ((fTemp95 * ((iTemp79) ? ((iTemp92) ? ((iTemp91) ? fConst23 : ((iTemp90) ? fConst23 : fConst20)) : ((iTemp89) ? ((iTemp88) ? fConst22 : fConst17) : fTemp93)) : (((iTemp78 == 1)) ? fTemp94 : ((iTemp92) ? fConst20 : ((iTemp89) ? ((iTemp88) ? fConst20 : fConst18) : fTemp93))))) + ((1.0f - fTemp95) * fTemp94)));
			float 	fTemp97 = floorf((2e+01f * (fTemp85 / fTemp96)));
			int 	iTemp98 = (iRec33[1] == 3);
			float 	fTemp99 = ((iTemp84) ? min(1.0f, fTemp83) : ((iTemp98) ? (fRec39[0] * (((fTemp97 >= 1e+01f)) ? (((fTemp97 >= 15.0f)) ? (((fTemp97 >= 18.0f)) ? (((fTemp97 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp97 >= 17.0f)) ? 0.03f : (((fTemp97 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp97 >= 13.0f)) ? (((fTemp97 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp97 >= 12.0f)) ? 0.14f : (((fTemp97 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp97 >= 5.0f)) ? (((fTemp97 >= 8.0f)) ? (((fTemp97 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp97 >= 7.0f)) ? 0.3f : (((fTemp97 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp97 >= 3.0f)) ? (((fTemp97 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp97 >= 2.0f)) ? 0.64f : (((fTemp97 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow50));
			float 	fTemp100 = (1.0f / ((iTemp98) ? (0.05f * fTemp96) : fTemp96));
			float 	fTemp101 = (fRec42[1] - fTemp100);
			float 	fTemp102 = (fRec42[1] + fTemp100);
			fRec42[0] = (((fTemp102 < fTemp99)) ? fTemp102 : (((fTemp101 > fTemp99)) ? fTemp101 : fTemp99));
			fRec34[0] = fRec42[0];
			fRec32[0] = (fRec34[0] - (fConst16 * ((fConst14 * fRec32[2]) + (fConst12 * fRec32[1]))));
			float 	fTemp103 = (((3947.8418f * fRec32[0]) + (7895.6836f * fRec32[1])) + (3947.8418f * fRec32[2]));
			float 	fTemp104 = (fConst24 * fTemp103);
			float 	fTemp105 = (fSlow62 + (fRec43[1] + -1.0f));
			float 	fTemp106 = (fSlow62 + fRec43[1]);
			int 	iTemp107 = (fTemp105 < 0.0f);
			fRec43[0] = ((iTemp107) ? fTemp106 : fTemp105);
			float 	fRec44 = ((iTemp107) ? fTemp106 : (fSlow62 + (fRec43[1] + (fSlow63 * fTemp105))));
			float 	fTemp108 = ((iTemp34) ? 0.0f : (fSlow66 + fRec46[1]));
			fRec46[0] = (fTemp108 - floorf(fTemp108));
			float 	fTemp109 = powf(((2.0f * fRec46[0]) + -1.0f),2.0f);
			fVec5[0] = fTemp109;
			float 	fTemp110 = (fSlow67 * (fTemp37 * (fVec5[0] - fVec5[1])));
			fVec6[IOTA&4095] = fTemp110;
			fRec45[0] = (((0.999f * fRec45[1]) + fVec6[IOTA&4095]) - ((fSlow73 * fVec6[(IOTA-iSlow69)&4095]) + (fSlow72 * fVec6[(IOTA-iSlow70)&4095])));
			float 	fTemp111 = (1.0f / (((iSlow80 == ((fRec50[1] > 0.0f) - (fRec50[1] < 0.0f)))) ? (((fSlow78 >= fabsf(fRec50[1]))) ? fConst17 : fConst0) : fSlow79));
			float 	fTemp112 = (fRec51[1] - fTemp111);
			float 	fTemp113 = (fRec51[1] + fTemp111);
			fRec51[0] = (((fTemp113 < fSlow77)) ? fTemp113 : (((fTemp112 > fSlow77)) ? fTemp112 : fSlow77));
			fRec50[0] = fRec51[0];
			int 	iTemp114 = ((fRec50[0] > 0.0f) + (1 - (fRec50[0] < 0.0f)));
			int 	iTemp115 = (iTemp114 == 0);
			float 	fTemp116 = ((iTemp115) ? 1.7f : 1.6f);
			iRec52[0] = iRec48[1];
			int 	iTemp117 = (iRec52[1] == iRec48[1]);
			int 	iTemp118 = (iRec48[1] == 0);
			fRec53[0] = ((iTemp118) ? fSlow75 : ((iTemp117) ? min(min(fRec53[1], fSlow75), fRec49[1]) : min(fSlow75, fRec49[1])));
			float 	fTemp119 = (fSlow75 * fTemp116);
			int 	iTemp120 = (iRec48[1] == 1);
			fRec54[0] = ((iTemp118) ? fSlow75 : ((iTemp120) ? ((iTemp117) ? max(max(fRec54[1], fTemp119), fRec49[1]) : max(fTemp119, fRec49[1])) : ((iTemp117) ? max(max(fRec54[1], fSlow75), fRec49[1]) : max(fSlow75, fRec49[1]))));
			iRec55[0] = iRec48[1];
			iRec56[0] = (((iRec55[1] != iRec48[1])) ? iTemp10 : iRec56[1]);
			float 	fTemp121 = float((iRec11[0] + (-1 - iRec56[0])));
			int 	iTemp122 = (iRec48[1] >= 1);
			int 	iTemp123 = (fSlow75 >= fRec49[1]);
			int 	iTemp124 = (iRec48[1] >= 3);
			int 	iTemp125 = (iRec48[1] >= 2);
			int 	iTemp126 = (iRec48[1] >= 5);
			int 	iTemp127 = (iRec48[1] >= 6);
			int 	iTemp128 = (iRec48[1] >= 4);
			iRec48[0] = ((iTemp128) ? ((iTemp127) ? ((iSlow81) ? 3 : ((iTemp123) ? 5 : 6)) : ((iTemp126) ? ((iSlow81) ? 3 : (((fSlow75 <= fRec49[1])) ? 6 : 5)) : (((fRec49[1] <= 0.1f)) ? 0 : 4))) : ((iTemp125) ? ((iTemp124) ? (((iSlow83 & (fRec49[1] <= 0.001f))) ? 4 : (((fSlow75 > fRec49[1])) ? 1 : 3)) : ((iTemp123) ? 5 : iSlow82)) : ((iTemp122) ? ((((fTemp121 >= fConst17) & (fRec49[1] >= (fRec53[0] * fTemp116)))) ? 2 : 1) : iSlow76)));
			float 	fTemp129 = ((iTemp122) ? fConst18 : 0.0f);
			float 	fTemp130 = ((iTemp128) ? ((iTemp127) ? fConst21 : ((iTemp126) ? fConst21 : fConst20)) : ((iTemp125) ? ((iTemp124) ? fConst19 : fConst18) : fTemp129));
			float 	fTemp131 = fabsf(fRec50[0]);
			float 	fTemp132 = (((fTemp131 <= 0.3f)) ? fTemp130 : ((fTemp131 * ((iTemp115) ? ((iTemp128) ? ((iTemp127) ? fConst23 : ((iTemp126) ? fConst23 : fConst20)) : ((iTemp125) ? ((iTemp124) ? fConst22 : fConst17) : fTemp129)) : (((iTemp114 == 1)) ? fTemp130 : ((iTemp128) ? fConst20 : ((iTemp125) ? ((iTemp124) ? fConst20 : fConst18) : fTemp129))))) + ((1.0f - fTemp131) * fTemp130)));
			float 	fTemp133 = floorf((2e+01f * (fTemp121 / fTemp132)));
			int 	iTemp134 = (iRec48[1] == 3);
			float 	fTemp135 = ((iTemp120) ? min(1.0f, fTemp119) : ((iTemp134) ? (fRec54[0] * (((fTemp133 >= 1e+01f)) ? (((fTemp133 >= 15.0f)) ? (((fTemp133 >= 18.0f)) ? (((fTemp133 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp133 >= 17.0f)) ? 0.03f : (((fTemp133 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp133 >= 13.0f)) ? (((fTemp133 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp133 >= 12.0f)) ? 0.14f : (((fTemp133 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp133 >= 5.0f)) ? (((fTemp133 >= 8.0f)) ? (((fTemp133 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp133 >= 7.0f)) ? 0.3f : (((fTemp133 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp133 >= 3.0f)) ? (((fTemp133 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp133 >= 2.0f)) ? 0.64f : (((fTemp133 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow75));
			float 	fTemp136 = (1.0f / ((iTemp134) ? (0.05f * fTemp132) : fTemp132));
			float 	fTemp137 = (fRec57[1] - fTemp136);
			float 	fTemp138 = (fRec57[1] + fTemp136);
			fRec57[0] = (((fTemp138 < fTemp135)) ? fTemp138 : (((fTemp137 > fTemp135)) ? fTemp137 : fTemp135));
			fRec49[0] = fRec57[0];
			fRec47[0] = (fRec49[0] - (fConst16 * ((fConst14 * fRec47[2]) + (fConst12 * fRec47[1]))));
			float 	fTemp139 = (((3947.8418f * fRec47[0]) + (7895.6836f * fRec47[1])) + (3947.8418f * fRec47[2]));
			float 	fTemp140 = (fConst24 * fTemp139);
			float 	fTemp141 = (fSlow87 + (fRec58[1] + -1.0f));
			float 	fTemp142 = (fSlow87 + fRec58[1]);
			int 	iTemp143 = (fTemp141 < 0.0f);
			fRec58[0] = ((iTemp143) ? fTemp142 : fTemp141);
			float 	fRec59 = ((iTemp143) ? fTemp142 : (fSlow87 + (fRec58[1] + (fSlow88 * fTemp141))));
			float 	fTemp144 = ((iTemp34) ? 0.0f : (fSlow91 + fRec61[1]));
			fRec61[0] = (fTemp144 - floorf(fTemp144));
			float 	fTemp145 = powf(((2.0f * fRec61[0]) + -1.0f),2.0f);
			fVec7[0] = fTemp145;
			float 	fTemp146 = (fSlow92 * (fTemp37 * (fVec7[0] - fVec7[1])));
			fVec8[IOTA&4095] = fTemp146;
			fRec60[0] = (((0.999f * fRec60[1]) + fVec8[IOTA&4095]) - ((fSlow98 * fVec8[(IOTA-iSlow94)&4095]) + (fSlow97 * fVec8[(IOTA-iSlow95)&4095])));
			float 	fTemp147 = (1.0f / (((iSlow105 == ((fRec65[1] > 0.0f) - (fRec65[1] < 0.0f)))) ? (((fSlow103 >= fabsf(fRec65[1]))) ? fConst17 : fConst0) : fSlow104));
			float 	fTemp148 = (fRec66[1] - fTemp147);
			float 	fTemp149 = (fRec66[1] + fTemp147);
			fRec66[0] = (((fTemp149 < fSlow102)) ? fTemp149 : (((fTemp148 > fSlow102)) ? fTemp148 : fSlow102));
			fRec65[0] = fRec66[0];
			int 	iTemp150 = ((fRec65[0] > 0.0f) + (1 - (fRec65[0] < 0.0f)));
			int 	iTemp151 = (iTemp150 == 0);
			float 	fTemp152 = ((iTemp151) ? 1.7f : 1.6f);
			iRec67[0] = iRec63[1];
			int 	iTemp153 = (iRec67[1] == iRec63[1]);
			int 	iTemp154 = (iRec63[1] == 0);
			fRec68[0] = ((iTemp154) ? fSlow100 : ((iTemp153) ? min(min(fRec68[1], fSlow100), fRec64[1]) : min(fSlow100, fRec64[1])));
			float 	fTemp155 = (fSlow100 * fTemp152);
			int 	iTemp156 = (iRec63[1] == 1);
			fRec69[0] = ((iTemp154) ? fSlow100 : ((iTemp156) ? ((iTemp153) ? max(max(fRec69[1], fTemp155), fRec64[1]) : max(fTemp155, fRec64[1])) : ((iTemp153) ? max(max(fRec69[1], fSlow100), fRec64[1]) : max(fSlow100, fRec64[1]))));
			iRec70[0] = iRec63[1];
			iRec71[0] = (((iRec70[1] != iRec63[1])) ? iTemp10 : iRec71[1]);
			float 	fTemp157 = float((iRec11[0] + (-1 - iRec71[0])));
			int 	iTemp158 = (iRec63[1] >= 1);
			int 	iTemp159 = (fSlow100 >= fRec64[1]);
			int 	iTemp160 = (iRec63[1] >= 3);
			int 	iTemp161 = (iRec63[1] >= 2);
			int 	iTemp162 = (iRec63[1] >= 5);
			int 	iTemp163 = (iRec63[1] >= 6);
			int 	iTemp164 = (iRec63[1] >= 4);
			iRec63[0] = ((iTemp164) ? ((iTemp163) ? ((iSlow106) ? 3 : ((iTemp159) ? 5 : 6)) : ((iTemp162) ? ((iSlow106) ? 3 : (((fSlow100 <= fRec64[1])) ? 6 : 5)) : (((fRec64[1] <= 0.1f)) ? 0 : 4))) : ((iTemp161) ? ((iTemp160) ? (((iSlow108 & (fRec64[1] <= 0.001f))) ? 4 : (((fSlow100 > fRec64[1])) ? 1 : 3)) : ((iTemp159) ? 5 : iSlow107)) : ((iTemp158) ? ((((fTemp157 >= fConst17) & (fRec64[1] >= (fRec68[0] * fTemp152)))) ? 2 : 1) : iSlow101)));
			float 	fTemp165 = ((iTemp158) ? fConst18 : 0.0f);
			float 	fTemp166 = ((iTemp164) ? ((iTemp163) ? fConst21 : ((iTemp162) ? fConst21 : fConst20)) : ((iTemp161) ? ((iTemp160) ? fConst19 : fConst18) : fTemp165));
			float 	fTemp167 = fabsf(fRec65[0]);
			float 	fTemp168 = (((fTemp167 <= 0.3f)) ? fTemp166 : ((fTemp167 * ((iTemp151) ? ((iTemp164) ? ((iTemp163) ? fConst23 : ((iTemp162) ? fConst23 : fConst20)) : ((iTemp161) ? ((iTemp160) ? fConst22 : fConst17) : fTemp165)) : (((iTemp150 == 1)) ? fTemp166 : ((iTemp164) ? fConst20 : ((iTemp161) ? ((iTemp160) ? fConst20 : fConst18) : fTemp165))))) + ((1.0f - fTemp167) * fTemp166)));
			float 	fTemp169 = floorf((2e+01f * (fTemp157 / fTemp168)));
			int 	iTemp170 = (iRec63[1] == 3);
			float 	fTemp171 = ((iTemp156) ? min(1.0f, fTemp155) : ((iTemp170) ? (fRec69[0] * (((fTemp169 >= 1e+01f)) ? (((fTemp169 >= 15.0f)) ? (((fTemp169 >= 18.0f)) ? (((fTemp169 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp169 >= 17.0f)) ? 0.03f : (((fTemp169 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp169 >= 13.0f)) ? (((fTemp169 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp169 >= 12.0f)) ? 0.14f : (((fTemp169 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp169 >= 5.0f)) ? (((fTemp169 >= 8.0f)) ? (((fTemp169 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp169 >= 7.0f)) ? 0.3f : (((fTemp169 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp169 >= 3.0f)) ? (((fTemp169 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp169 >= 2.0f)) ? 0.64f : (((fTemp169 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow100));
			float 	fTemp172 = (1.0f / ((iTemp170) ? (0.05f * fTemp168) : fTemp168));
			float 	fTemp173 = (fRec72[1] - fTemp172);
			float 	fTemp174 = (fRec72[1] + fTemp172);
			fRec72[0] = (((fTemp174 < fTemp171)) ? fTemp174 : (((fTemp173 > fTemp171)) ? fTemp173 : fTemp171));
			fRec64[0] = fRec72[0];
			fRec62[0] = (fRec64[0] - (fConst16 * ((fConst14 * fRec62[2]) + (fConst12 * fRec62[1]))));
			float 	fTemp175 = (((3947.8418f * fRec62[0]) + (7895.6836f * fRec62[1])) + (3947.8418f * fRec62[2]));
			float 	fTemp176 = (fConst24 * fTemp175);
			float 	fTemp177 = (fSlow112 + (fRec73[1] + -1.0f));
			float 	fTemp178 = (fSlow112 + fRec73[1]);
			int 	iTemp179 = (fTemp177 < 0.0f);
			fRec73[0] = ((iTemp179) ? fTemp178 : fTemp177);
			float 	fRec74 = ((iTemp179) ? fTemp178 : (fSlow112 + (fRec73[1] + (fSlow113 * fTemp177))));
			float 	fTemp180 = ((iTemp34) ? 0.0f : (fSlow116 + fRec76[1]));
			fRec76[0] = (fTemp180 - floorf(fTemp180));
			float 	fTemp181 = powf(((2.0f * fRec76[0]) + -1.0f),2.0f);
			fVec9[0] = fTemp181;
			float 	fTemp182 = (fSlow117 * (fTemp37 * (fVec9[0] - fVec9[1])));
			fVec10[IOTA&4095] = fTemp182;
			fRec75[0] = (((0.999f * fRec75[1]) + fVec10[IOTA&4095]) - ((fSlow123 * fVec10[(IOTA-iSlow119)&4095]) + (fSlow122 * fVec10[(IOTA-iSlow120)&4095])));
			float 	fTemp183 = (1.0f / (((iSlow130 == ((fRec80[1] > 0.0f) - (fRec80[1] < 0.0f)))) ? (((fSlow128 >= fabsf(fRec80[1]))) ? fConst17 : fConst0) : fSlow129));
			float 	fTemp184 = (fRec81[1] - fTemp183);
			float 	fTemp185 = (fRec81[1] + fTemp183);
			fRec81[0] = (((fTemp185 < fSlow127)) ? fTemp185 : (((fTemp184 > fSlow127)) ? fTemp184 : fSlow127));
			fRec80[0] = fRec81[0];
			int 	iTemp186 = ((fRec80[0] > 0.0f) + (1 - (fRec80[0] < 0.0f)));
			int 	iTemp187 = (iTemp186 == 0);
			float 	fTemp188 = ((iTemp187) ? 1.7f : 1.6f);
			iRec82[0] = iRec78[1];
			int 	iTemp189 = (iRec82[1] == iRec78[1]);
			int 	iTemp190 = (iRec78[1] == 0);
			fRec83[0] = ((iTemp190) ? fSlow125 : ((iTemp189) ? min(min(fRec83[1], fSlow125), fRec79[1]) : min(fSlow125, fRec79[1])));
			float 	fTemp191 = (fSlow125 * fTemp188);
			int 	iTemp192 = (iRec78[1] == 1);
			fRec84[0] = ((iTemp190) ? fSlow125 : ((iTemp192) ? ((iTemp189) ? max(max(fRec84[1], fTemp191), fRec79[1]) : max(fTemp191, fRec79[1])) : ((iTemp189) ? max(max(fRec84[1], fSlow125), fRec79[1]) : max(fSlow125, fRec79[1]))));
			iRec85[0] = iRec78[1];
			iRec86[0] = (((iRec85[1] != iRec78[1])) ? iTemp10 : iRec86[1]);
			float 	fTemp193 = float((iRec11[0] + (-1 - iRec86[0])));
			int 	iTemp194 = (iRec78[1] >= 1);
			int 	iTemp195 = (fSlow125 >= fRec79[1]);
			int 	iTemp196 = (iRec78[1] >= 3);
			int 	iTemp197 = (iRec78[1] >= 2);
			int 	iTemp198 = (iRec78[1] >= 5);
			int 	iTemp199 = (iRec78[1] >= 6);
			int 	iTemp200 = (iRec78[1] >= 4);
			iRec78[0] = ((iTemp200) ? ((iTemp199) ? ((iSlow131) ? 3 : ((iTemp195) ? 5 : 6)) : ((iTemp198) ? ((iSlow131) ? 3 : (((fSlow125 <= fRec79[1])) ? 6 : 5)) : (((fRec79[1] <= 0.1f)) ? 0 : 4))) : ((iTemp197) ? ((iTemp196) ? (((iSlow133 & (fRec79[1] <= 0.001f))) ? 4 : (((fSlow125 > fRec79[1])) ? 1 : 3)) : ((iTemp195) ? 5 : iSlow132)) : ((iTemp194) ? ((((fTemp193 >= fConst17) & (fRec79[1] >= (fRec83[0] * fTemp188)))) ? 2 : 1) : iSlow126)));
			float 	fTemp201 = ((iTemp194) ? fConst18 : 0.0f);
			float 	fTemp202 = ((iTemp200) ? ((iTemp199) ? fConst21 : ((iTemp198) ? fConst21 : fConst20)) : ((iTemp197) ? ((iTemp196) ? fConst19 : fConst18) : fTemp201));
			float 	fTemp203 = fabsf(fRec80[0]);
			float 	fTemp204 = (((fTemp203 <= 0.3f)) ? fTemp202 : ((fTemp203 * ((iTemp187) ? ((iTemp200) ? ((iTemp199) ? fConst23 : ((iTemp198) ? fConst23 : fConst20)) : ((iTemp197) ? ((iTemp196) ? fConst22 : fConst17) : fTemp201)) : (((iTemp186 == 1)) ? fTemp202 : ((iTemp200) ? fConst20 : ((iTemp197) ? ((iTemp196) ? fConst20 : fConst18) : fTemp201))))) + ((1.0f - fTemp203) * fTemp202)));
			float 	fTemp205 = floorf((2e+01f * (fTemp193 / fTemp204)));
			int 	iTemp206 = (iRec78[1] == 3);
			float 	fTemp207 = ((iTemp192) ? min(1.0f, fTemp191) : ((iTemp206) ? (fRec84[0] * (((fTemp205 >= 1e+01f)) ? (((fTemp205 >= 15.0f)) ? (((fTemp205 >= 18.0f)) ? (((fTemp205 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp205 >= 17.0f)) ? 0.03f : (((fTemp205 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp205 >= 13.0f)) ? (((fTemp205 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp205 >= 12.0f)) ? 0.14f : (((fTemp205 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp205 >= 5.0f)) ? (((fTemp205 >= 8.0f)) ? (((fTemp205 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp205 >= 7.0f)) ? 0.3f : (((fTemp205 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp205 >= 3.0f)) ? (((fTemp205 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp205 >= 2.0f)) ? 0.64f : (((fTemp205 >= 1.0f)) ? 0.74f : 0.86f)))))) : fSlow125));
			float 	fTemp208 = (1.0f / ((iTemp206) ? (0.05f * fTemp204) : fTemp204));
			float 	fTemp209 = (fRec87[1] - fTemp208);
			float 	fTemp210 = (fRec87[1] + fTemp208);
			fRec87[0] = (((fTemp210 < fTemp207)) ? fTemp210 : (((fTemp209 > fTemp207)) ? fTemp209 : fTemp207));
			fRec79[0] = fRec87[0];
			fRec77[0] = (fRec79[0] - (fConst16 * ((fConst14 * fRec77[2]) + (fConst12 * fRec77[1]))));
			float 	fTemp211 = (((3947.8418f * fRec77[0]) + (7895.6836f * fRec77[1])) + (3947.8418f * fRec77[2]));
			float 	fTemp212 = (fConst24 * fTemp211);
			float 	fTemp213 = (fSlow137 + (fRec88[1] + -1.0f));
			float 	fTemp214 = (fSlow137 + fRec88[1]);
			int 	iTemp215 = (fTemp213 < 0.0f);
			fRec88[0] = ((iTemp215) ? fTemp214 : fTemp213);
			float 	fRec89 = ((iTemp215) ? fTemp214 : (fSlow137 + (fRec88[1] + (fSlow138 * fTemp213))));
			float 	fTemp216 = ((iTemp34) ? 0.0f : (fSlow141 + fRec91[1]));
			fRec91[0] = (fTemp216 - floorf(fTemp216));
			float 	fTemp217 = powf(((2.0f * fRec91[0]) + -1.0f),2.0f);
			fVec11[0] = fTemp217;
			float 	fTemp218 = (fSlow142 * (fTemp37 * (fVec11[0] - fVec11[1])));
			fVec12[IOTA&4095] = fTemp218;
			fRec90[0] = (((0.999f * fRec90[1]) + fVec12[IOTA&4095]) - ((fSlow148 * fVec12[(IOTA-iSlow144)&4095]) + (fSlow147 * fVec12[(IOTA-iSlow145)&4095])));
			fRec0[0] = ((fConst29 * ((((((fTemp211 * ((fSlow149 * (fRec90[0] * ((fTemp212 + 1.0f) - fSlow125))) + (((2.0f * fRec89) + -1.0f) * (max(min((3.0f * (fSlow125 - fTemp212)), 0.3f), -0.15f) + 0.25f)))) + (fTemp175 * ((fSlow124 * (fRec75[0] * ((fTemp176 + 1.0f) - fSlow100))) + (((2.0f * fRec74) + -1.0f) * (max(min((3.0f * (fSlow100 - fTemp176)), 0.3f), -0.15f) + 0.25f))))) + (fTemp139 * ((fSlow99 * (fRec60[0] * ((fTemp140 + 1.0f) - fSlow75))) + (((2.0f * fRec59) + -1.0f) * (max(min((3.0f * (fSlow75 - fTemp140)), 0.3f), -0.15f) + 0.25f))))) + (fTemp103 * ((fSlow74 * (fRec45[0] * ((fTemp104 + 1.0f) - fSlow50))) + (((2.0f * fRec44) + -1.0f) * (max(min((3.0f * (fSlow50 - fTemp104)), 0.3f), -0.15f) + 0.25f))))) + (fTemp67 * ((fSlow49 * (fRec30[0] * ((fTemp68 + 1.0f) - fSlow25))) + (((2.0f * fRec29) + -1.0f) * (max(min((3.0f * (fSlow25 - fTemp68)), 0.3f), -0.15f) + 0.25f))))) + (fTemp29 * ((fSlow24 * (fRec15[0] * ((fTemp30 + 1.0f) - fSlow0))) + (((2.0f * fRec14) + -1.0f) * (max(min((3.0f * (fSlow0 - fTemp30)), 0.3f), -0.15f) + 0.25f)))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst30 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
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
