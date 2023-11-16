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
	FAUSTFLOAT 	fslider0;
	float 	fConst9;
	float 	fRec1[2];
	float 	fRec3[2];
	FAUSTFLOAT 	fslider1;
	float 	fVec1[2];
	float 	fConst13;
	float 	fConst15;
	float 	fConst17;
	FAUSTFLOAT 	fslider2;
	int 	iVec2[2];
	int 	iRec9[2];
	int 	iRec8[2];
	float 	fVec3[2];
	float 	fRec10[2];
	int 	iRec6[3];
	float 	fConst18;
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fRec12[2];
	int 	iVec4[2];
	int 	iRec13[2];
	int 	iRec14[2];
	float 	fRec15[2];
	float 	fRec16[2];
	float 	fRec11[2];
	float 	fRec7[2];
	float 	fRec5[3];
	float 	fConst23;
	float 	fConst24;
	float 	fRec17[2];
	FAUSTFLOAT 	fslider3;
	float 	fRec18[2];
	float 	fRec20[2];
	FAUSTFLOAT 	fslider4;
	float 	fVec5[2];
	FAUSTFLOAT 	fslider5;
	int 	iVec6[2];
	int 	iRec25[2];
	float 	fVec7[2];
	float 	fRec26[2];
	int 	iRec23[3];
	float 	fRec28[2];
	int 	iVec8[2];
	int 	iRec29[2];
	int 	iRec30[2];
	float 	fRec31[2];
	float 	fRec32[2];
	float 	fRec27[2];
	float 	fRec24[2];
	float 	fRec22[3];
	float 	fRec33[2];
	FAUSTFLOAT 	fslider6;
	float 	fRec34[2];
	float 	fRec36[2];
	FAUSTFLOAT 	fslider7;
	float 	fVec9[2];
	FAUSTFLOAT 	fslider8;
	int 	iVec10[2];
	int 	iRec41[2];
	float 	fVec11[2];
	float 	fRec42[2];
	int 	iRec39[3];
	float 	fRec44[2];
	int 	iVec12[2];
	int 	iRec45[2];
	int 	iRec46[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec43[2];
	float 	fRec40[2];
	float 	fRec38[3];
	float 	fRec49[2];
	FAUSTFLOAT 	fslider9;
	float 	fRec50[2];
	float 	fRec52[2];
	FAUSTFLOAT 	fslider10;
	float 	fVec13[2];
	FAUSTFLOAT 	fslider11;
	int 	iVec14[2];
	int 	iRec57[2];
	float 	fVec15[2];
	float 	fRec58[2];
	int 	iRec55[3];
	float 	fRec60[2];
	int 	iVec16[2];
	int 	iRec61[2];
	int 	iRec62[2];
	float 	fRec63[2];
	float 	fRec64[2];
	float 	fRec59[2];
	float 	fRec56[2];
	float 	fRec54[3];
	float 	fRec65[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec66[2];
	float 	fRec68[2];
	FAUSTFLOAT 	fslider13;
	float 	fVec17[2];
	FAUSTFLOAT 	fslider14;
	int 	iVec18[2];
	int 	iRec73[2];
	float 	fVec19[2];
	float 	fRec74[2];
	int 	iRec71[3];
	float 	fRec76[2];
	int 	iVec20[2];
	int 	iRec77[2];
	int 	iRec78[2];
	float 	fRec79[2];
	float 	fRec80[2];
	float 	fRec75[2];
	float 	fRec72[2];
	float 	fRec70[3];
	float 	fRec81[2];
	FAUSTFLOAT 	fslider15;
	float 	fRec82[2];
	float 	fRec84[2];
	FAUSTFLOAT 	fslider16;
	float 	fVec21[2];
	FAUSTFLOAT 	fslider17;
	int 	iVec22[2];
	int 	iRec89[2];
	float 	fVec23[2];
	float 	fRec90[2];
	int 	iRec87[3];
	float 	fRec92[2];
	int 	iVec24[2];
	int 	iRec93[2];
	int 	iRec94[2];
	float 	fRec95[2];
	float 	fRec96[2];
	float 	fRec91[2];
	float 	fRec88[2];
	float 	fRec86[3];
	float 	fRec97[2];
	float 	fRec0[3];
	float 	fConst25;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakhold:author", "Jonatan Liljedahl, revised by Romain Michon");
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
		fConst9 = (1.0f / fConst0);
		float 	fConst10 = powf((62.831852f / fConst0),2.0f);
		float 	fConst11 = ((fConst10 * ((0.2033f * fConst10) + 0.31755f)) + 1.0f);
		float 	fConst12 = powf(fConst11,2.0f);
		fConst13 = (2.0f * ((3947.8418f * (fConst12 / fConst1)) + -1.0f));
		float 	fConst14 = (3947.8418f * (fConst11 / fConst0));
		fConst15 = (((fConst11 * (fConst14 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst16 = (((fConst11 * (fConst14 + 88.49557f)) / fConst0) + 1.0f);
		fConst17 = (1.0f / fConst16);
		fConst18 = (0.05f * fConst0);
		fConst19 = (0.5f * fConst0);
		fConst20 = (0.25f * fConst0);
		fConst21 = (0.2f * fConst0);
		fConst22 = (8.0f * fConst0);
		fConst23 = (fConst12 / (fConst1 * fConst16));
		fConst24 = (8.175799f / fConst0);
		fConst25 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) iRec8[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<3; i++) iRec6[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec25[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<3; i++) iRec23[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec29[i] = 0;
		for (int i=0; i<2; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<3; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<3; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<3; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<3; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<3; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec77[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec89[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<3; i++) iRec87[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec93[i] = 0;
		for (int i=0; i<2; i++) iRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<3; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
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
		synth_interface.pres[0] = &fslider17;
		synth_interface.vpres[0] = &fslider16;
		synth_interface.note[1] = &fslider12;
		synth_interface.pres[1] = &fslider14;
		synth_interface.vpres[1] = &fslider13;
		synth_interface.note[2] = &fslider9;
		synth_interface.pres[2] = &fslider11;
		synth_interface.vpres[2] = &fslider10;
		synth_interface.note[3] = &fslider6;
		synth_interface.pres[3] = &fslider8;
		synth_interface.vpres[3] = &fslider7;
		synth_interface.note[4] = &fslider3;
		synth_interface.pres[4] = &fslider5;
		synth_interface.vpres[4] = &fslider4;
		synth_interface.note[5] = &fslider0;
		synth_interface.pres[5] = &fslider2;
		synth_interface.vpres[5] = &fslider1;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fastpow2((0.083333336f * float(fslider0)));
		float 	fSlow1 = max(1.1920929e-07f, fabsf((8.067899f * fSlow0)));
		float 	fSlow2 = (fConst9 * fSlow1);
		float 	fSlow3 = (1.0f - (fConst0 / fSlow1));
		float 	fSlow4 = max(1.1920929e-07f, fabsf((8.285142f * fSlow0)));
		float 	fSlow5 = (fConst9 * fSlow4);
		float 	fSlow6 = (1.0f - (fConst0 / fSlow4));
		float 	fSlow7 = float(fslider1);
		float 	fSlow8 = ((0.5f * fSlow7) + 0.2f);
		float 	fSlow9 = float(fslider2);
		int 	iSlow10 = (fSlow7 == 0.0f);
		float 	fSlow11 = (0.0f - fSlow7);
		float 	fSlow12 = (fConst24 * fSlow0);
		float 	fSlow13 = (0.6f - (2.0f * fSlow7));
		float 	fSlow14 = fastpow2((0.083333336f * float(fslider3)));
		float 	fSlow15 = max(1.1920929e-07f, fabsf((8.067899f * fSlow14)));
		float 	fSlow16 = (fConst9 * fSlow15);
		float 	fSlow17 = (1.0f - (fConst0 / fSlow15));
		float 	fSlow18 = max(1.1920929e-07f, fabsf((8.285142f * fSlow14)));
		float 	fSlow19 = (fConst9 * fSlow18);
		float 	fSlow20 = (1.0f - (fConst0 / fSlow18));
		float 	fSlow21 = float(fslider4);
		float 	fSlow22 = ((0.5f * fSlow21) + 0.2f);
		float 	fSlow23 = float(fslider5);
		int 	iSlow24 = (fSlow21 == 0.0f);
		float 	fSlow25 = (0.0f - fSlow21);
		float 	fSlow26 = (fConst24 * fSlow14);
		float 	fSlow27 = (0.6f - (2.0f * fSlow21));
		float 	fSlow28 = fastpow2((0.083333336f * float(fslider6)));
		float 	fSlow29 = max(1.1920929e-07f, fabsf((8.067899f * fSlow28)));
		float 	fSlow30 = (fConst9 * fSlow29);
		float 	fSlow31 = (1.0f - (fConst0 / fSlow29));
		float 	fSlow32 = max(1.1920929e-07f, fabsf((8.285142f * fSlow28)));
		float 	fSlow33 = (fConst9 * fSlow32);
		float 	fSlow34 = (1.0f - (fConst0 / fSlow32));
		float 	fSlow35 = float(fslider7);
		float 	fSlow36 = ((0.5f * fSlow35) + 0.2f);
		float 	fSlow37 = float(fslider8);
		int 	iSlow38 = (fSlow35 == 0.0f);
		float 	fSlow39 = (0.0f - fSlow35);
		float 	fSlow40 = (fConst24 * fSlow28);
		float 	fSlow41 = (0.6f - (2.0f * fSlow35));
		float 	fSlow42 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow43 = max(1.1920929e-07f, fabsf((8.067899f * fSlow42)));
		float 	fSlow44 = (fConst9 * fSlow43);
		float 	fSlow45 = (1.0f - (fConst0 / fSlow43));
		float 	fSlow46 = max(1.1920929e-07f, fabsf((8.285142f * fSlow42)));
		float 	fSlow47 = (fConst9 * fSlow46);
		float 	fSlow48 = (1.0f - (fConst0 / fSlow46));
		float 	fSlow49 = float(fslider10);
		float 	fSlow50 = ((0.5f * fSlow49) + 0.2f);
		float 	fSlow51 = float(fslider11);
		int 	iSlow52 = (fSlow49 == 0.0f);
		float 	fSlow53 = (0.0f - fSlow49);
		float 	fSlow54 = (fConst24 * fSlow42);
		float 	fSlow55 = (0.6f - (2.0f * fSlow49));
		float 	fSlow56 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow57 = max(1.1920929e-07f, fabsf((8.067899f * fSlow56)));
		float 	fSlow58 = (fConst9 * fSlow57);
		float 	fSlow59 = (1.0f - (fConst0 / fSlow57));
		float 	fSlow60 = max(1.1920929e-07f, fabsf((8.285142f * fSlow56)));
		float 	fSlow61 = (fConst9 * fSlow60);
		float 	fSlow62 = (1.0f - (fConst0 / fSlow60));
		float 	fSlow63 = float(fslider13);
		float 	fSlow64 = ((0.5f * fSlow63) + 0.2f);
		float 	fSlow65 = float(fslider14);
		int 	iSlow66 = (fSlow63 == 0.0f);
		float 	fSlow67 = (0.0f - fSlow63);
		float 	fSlow68 = (fConst24 * fSlow56);
		float 	fSlow69 = (0.6f - (2.0f * fSlow63));
		float 	fSlow70 = fastpow2((0.083333336f * float(fslider15)));
		float 	fSlow71 = max(1.1920929e-07f, fabsf((8.067899f * fSlow70)));
		float 	fSlow72 = (fConst9 * fSlow71);
		float 	fSlow73 = (1.0f - (fConst0 / fSlow71));
		float 	fSlow74 = max(1.1920929e-07f, fabsf((8.285142f * fSlow70)));
		float 	fSlow75 = (fConst9 * fSlow74);
		float 	fSlow76 = (1.0f - (fConst0 / fSlow74));
		float 	fSlow77 = float(fslider16);
		float 	fSlow78 = ((0.5f * fSlow77) + 0.2f);
		float 	fSlow79 = float(fslider17);
		int 	iSlow80 = (fSlow77 == 0.0f);
		float 	fSlow81 = (0.0f - fSlow77);
		float 	fSlow82 = (fConst24 * fSlow70);
		float 	fSlow83 = (0.6f - (2.0f * fSlow77));
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			float 	fTemp0 = (fSlow2 + (fRec1[1] + -1.0f));
			float 	fTemp1 = (fSlow2 + fRec1[1]);
			int 	iTemp2 = (fTemp0 < 0.0f);
			fRec1[0] = ((iTemp2) ? fTemp1 : fTemp0);
			float 	fRec2 = ((iTemp2) ? fTemp1 : (fSlow2 + (fRec1[1] + (fSlow3 * fTemp0))));
			float 	fTemp3 = (fSlow5 + (fRec3[1] + -1.0f));
			float 	fTemp4 = (fSlow5 + fRec3[1]);
			int 	iTemp5 = (fTemp3 < 0.0f);
			fRec3[0] = ((iTemp5) ? fTemp4 : fTemp3);
			float 	fRec4 = ((iTemp5) ? fTemp4 : (fSlow5 + (fRec3[1] + (fSlow6 * fTemp3))));
			fVec1[0] = fSlow7;
			int 	iTemp6 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp6;
			int 	iTemp7 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec9[0] = (iRec9[1] + 1);
			int 	iTemp8 = (iRec9[0] + -1);
			iRec8[0] = ((iRec8[1] * (1 - iTemp7)) + (iTemp8 * iTemp7));
			float 	fTemp9 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec8[0])))) > 0.5f) & iSlow10)) ? 0.0f : fSlow9))) + -1.0f));
			fVec3[0] = fTemp9;
			float 	fTemp10 = (0.5f * fVec3[0]);
			int 	iTemp11 = (fTemp10 > 0.001f);
			int 	iTemp12 = (fTemp10 <= 0.001f);
			float 	fTemp13 = float((iTemp12 | ((0.5f * fVec3[1]) >= 0.001f)));
			fRec10[0] = max((fRec10[1] * fTemp13), fSlow7);
			float 	fTemp14 = min(1.0f, (1.5f * fRec10[0]));
			int 	iTemp15 = (fTemp10 >= fRec7[1]);
			int 	iTemp16 = (fRec7[1] <= 0.001f);
			int 	iTemp17 = (((iRec6[1] >= 4)) ? (((iRec6[1] >= 6)) ? ((iTemp16) ? 0 : ((iTemp11) ? 1 : 6)) : (((iRec6[1] >= 5)) ? ((iTemp12) ? 3 : ((iTemp15) ? 4 : 5)) : ((iTemp12) ? 3 : (((fTemp10 <= fRec7[1])) ? 5 : 4)))) : (((iRec6[1] >= 2)) ? (((iRec6[1] >= 3)) ? (((iTemp12 & iTemp16)) ? 0 : ((iTemp11) ? 1 : 3)) : ((iTemp12) ? 3 : ((iTemp15) ? 4 : 2))) : (((iRec6[1] >= 1)) ? (((fRec7[1] >= min(fTemp14, 1.0f))) ? ((iTemp12) ? 6 : 2) : 1) : ((iTemp11) ? 1 : 0))));
			iRec6[0] = iTemp17;
			fRec12[0] = max((fTemp13 * fRec12[1]), fSlow11);
			float 	fTemp18 = (((iTemp17 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec12[0]))) : (((iTemp17 >= 4)) ? (((iTemp17 >= 6)) ? fConst22 : fConst21) : (((iTemp17 >= 2)) ? (((iTemp17 >= 3)) ? fConst20 : fConst19) : (((iTemp17 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp19 = (iRec6[1] != iRec6[2]);
			iVec4[0] = iTemp19;
			int 	iTemp20 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec13[0] = ((iRec13[1] * (1 - iTemp20)) + (iTemp8 * iTemp20));
			float 	fTemp21 = floorf((2e+01f * (((fTemp18 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec13[0]))) / fTemp18) : 0.0f)));
			float 	fTemp22 = (((fTemp21 >= 1e+01f)) ? (((fTemp21 >= 15.0f)) ? (((fTemp21 >= 18.0f)) ? (((fTemp21 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp21 >= 17.0f)) ? 0.03f : (((fTemp21 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp21 >= 13.0f)) ? (((fTemp21 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp21 >= 12.0f)) ? 0.14f : (((fTemp21 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp21 >= 5.0f)) ? (((fTemp21 >= 8.0f)) ? (((fTemp21 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp21 >= 7.0f)) ? 0.3f : (((fTemp21 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp21 >= 3.0f)) ? (((fTemp21 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp21 >= 2.0f)) ? 0.64f : (((fTemp21 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec14[0] = iRec6[1];
			int 	iTemp23 = (iRec14[1] == iRec6[1]);
			int 	iTemp24 = (iRec6[1] == 0);
			fRec15[0] = ((iTemp24) ? fTemp10 : ((iTemp23) ? min(min(fRec15[1], fTemp10), fRec7[1]) : min(fTemp10, fRec7[1])));
			fRec16[0] = ((iTemp24) ? fTemp10 : ((iTemp23) ? max(max(fRec16[1], fTemp10), fRec7[1]) : max(fTemp10, fRec7[1])));
			int 	iTemp25 = (iRec6[1] == 3);
			float 	fTemp26 = (((iRec6[1] == 1)) ? min(1.0f, fTemp14) : ((iTemp24) ? 0.0001f : (((iTemp25 | (iRec6[1] == 6))) ? (fRec16[0] * fTemp22) : fTemp10)));
			float 	fTemp27 = (fTemp21 + -1.0f);
			float 	fTemp28 = ((((fTemp21 > 0.0f)) ? (((fTemp27 >= 1e+01f)) ? (((fTemp27 >= 15.0f)) ? (((fTemp27 >= 18.0f)) ? (((fTemp27 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp27 >= 17.0f)) ? 0.03f : (((fTemp27 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp27 >= 13.0f)) ? (((fTemp27 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp27 >= 12.0f)) ? 0.14f : (((fTemp27 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp27 >= 5.0f)) ? (((fTemp27 >= 8.0f)) ? (((fTemp27 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp27 >= 7.0f)) ? 0.3f : (((fTemp27 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp27 >= 3.0f)) ? (((fTemp27 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp27 >= 2.0f)) ? 0.64f : (((fTemp27 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp22);
			float 	fTemp29 = (1.0f / ((iTemp24) ? 0.0001f : ((iTemp25) ? (((fTemp28 > 0.0f)) ? (0.05f * (fTemp18 / fTemp28)) : 0.0f) : fTemp18)));
			float 	fTemp30 = (fRec11[1] - fTemp29);
			float 	fTemp31 = (fRec11[1] + fTemp29);
			fRec11[0] = (((fTemp31 < fTemp26)) ? fTemp31 : (((fTemp30 > fTemp26)) ? fTemp30 : fTemp26));
			fRec7[0] = fRec11[0];
			fRec5[0] = (fRec7[0] - (fConst17 * ((fConst15 * fRec5[2]) + (fConst13 * fRec5[1]))));
			float 	fTemp32 = min(0.99f, (fConst23 * (((3947.8418f * fRec5[0]) + (7895.6836f * fRec5[1])) + (3947.8418f * fRec5[2]))));
			int 	iTemp33 = (1 - iVec0[1]);
			float 	fTemp34 = ((iTemp33) ? 0.0f : (fSlow12 + fRec17[1]));
			fRec17[0] = (fTemp34 - floorf(fTemp34));
			float 	fTemp35 = (fSlow16 + (fRec18[1] + -1.0f));
			float 	fTemp36 = (fSlow16 + fRec18[1]);
			int 	iTemp37 = (fTemp35 < 0.0f);
			fRec18[0] = ((iTemp37) ? fTemp36 : fTemp35);
			float 	fRec19 = ((iTemp37) ? fTemp36 : (fSlow16 + (fRec18[1] + (fSlow17 * fTemp35))));
			float 	fTemp38 = (fSlow19 + (fRec20[1] + -1.0f));
			float 	fTemp39 = (fSlow19 + fRec20[1]);
			int 	iTemp40 = (fTemp38 < 0.0f);
			fRec20[0] = ((iTemp40) ? fTemp39 : fTemp38);
			float 	fRec21 = ((iTemp40) ? fTemp39 : (fSlow19 + (fRec20[1] + (fSlow20 * fTemp38))));
			fVec5[0] = fSlow21;
			int 	iTemp41 = (fSlow21 != fVec5[1]);
			iVec6[0] = iTemp41;
			int 	iTemp42 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec25[0] = ((iRec25[1] * (1 - iTemp42)) + (iTemp8 * iTemp42));
			float 	fTemp43 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec25[0])))) > 0.5f) & iSlow24)) ? 0.0f : fSlow23))) + -1.0f));
			fVec7[0] = fTemp43;
			float 	fTemp44 = (0.5f * fVec7[0]);
			int 	iTemp45 = (fTemp44 > 0.001f);
			int 	iTemp46 = (fTemp44 <= 0.001f);
			float 	fTemp47 = float((iTemp46 | ((0.5f * fVec7[1]) >= 0.001f)));
			fRec26[0] = max((fRec26[1] * fTemp47), fSlow21);
			float 	fTemp48 = min(1.0f, (1.5f * fRec26[0]));
			int 	iTemp49 = (fTemp44 >= fRec24[1]);
			int 	iTemp50 = (fRec24[1] <= 0.001f);
			int 	iTemp51 = (((iRec23[1] >= 4)) ? (((iRec23[1] >= 6)) ? ((iTemp50) ? 0 : ((iTemp45) ? 1 : 6)) : (((iRec23[1] >= 5)) ? ((iTemp46) ? 3 : ((iTemp49) ? 4 : 5)) : ((iTemp46) ? 3 : (((fTemp44 <= fRec24[1])) ? 5 : 4)))) : (((iRec23[1] >= 2)) ? (((iRec23[1] >= 3)) ? (((iTemp46 & iTemp50)) ? 0 : ((iTemp45) ? 1 : 3)) : ((iTemp46) ? 3 : ((iTemp49) ? 4 : 2))) : (((iRec23[1] >= 1)) ? (((fRec24[1] >= min(fTemp48, 1.0f))) ? ((iTemp46) ? 6 : 2) : 1) : ((iTemp45) ? 1 : 0))));
			iRec23[0] = iTemp51;
			fRec28[0] = max((fTemp47 * fRec28[1]), fSlow25);
			float 	fTemp52 = (((iTemp51 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec28[0]))) : (((iTemp51 >= 4)) ? (((iTemp51 >= 6)) ? fConst22 : fConst21) : (((iTemp51 >= 2)) ? (((iTemp51 >= 3)) ? fConst20 : fConst19) : (((iTemp51 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp53 = (iRec23[1] != iRec23[2]);
			iVec8[0] = iTemp53;
			int 	iTemp54 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec29[0] = ((iRec29[1] * (1 - iTemp54)) + (iTemp8 * iTemp54));
			float 	fTemp55 = floorf((2e+01f * (((fTemp52 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec29[0]))) / fTemp52) : 0.0f)));
			float 	fTemp56 = (((fTemp55 >= 1e+01f)) ? (((fTemp55 >= 15.0f)) ? (((fTemp55 >= 18.0f)) ? (((fTemp55 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp55 >= 17.0f)) ? 0.03f : (((fTemp55 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp55 >= 13.0f)) ? (((fTemp55 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp55 >= 12.0f)) ? 0.14f : (((fTemp55 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp55 >= 5.0f)) ? (((fTemp55 >= 8.0f)) ? (((fTemp55 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp55 >= 7.0f)) ? 0.3f : (((fTemp55 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp55 >= 3.0f)) ? (((fTemp55 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp55 >= 2.0f)) ? 0.64f : (((fTemp55 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec30[0] = iRec23[1];
			int 	iTemp57 = (iRec30[1] == iRec23[1]);
			int 	iTemp58 = (iRec23[1] == 0);
			fRec31[0] = ((iTemp58) ? fTemp44 : ((iTemp57) ? min(min(fRec31[1], fTemp44), fRec24[1]) : min(fTemp44, fRec24[1])));
			fRec32[0] = ((iTemp58) ? fTemp44 : ((iTemp57) ? max(max(fRec32[1], fTemp44), fRec24[1]) : max(fTemp44, fRec24[1])));
			int 	iTemp59 = (iRec23[1] == 3);
			float 	fTemp60 = (((iRec23[1] == 1)) ? min(1.0f, fTemp48) : ((iTemp58) ? 0.0001f : (((iTemp59 | (iRec23[1] == 6))) ? (fRec32[0] * fTemp56) : fTemp44)));
			float 	fTemp61 = (fTemp55 + -1.0f);
			float 	fTemp62 = ((((fTemp55 > 0.0f)) ? (((fTemp61 >= 1e+01f)) ? (((fTemp61 >= 15.0f)) ? (((fTemp61 >= 18.0f)) ? (((fTemp61 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp61 >= 17.0f)) ? 0.03f : (((fTemp61 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp61 >= 13.0f)) ? (((fTemp61 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp61 >= 12.0f)) ? 0.14f : (((fTemp61 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp61 >= 5.0f)) ? (((fTemp61 >= 8.0f)) ? (((fTemp61 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp61 >= 7.0f)) ? 0.3f : (((fTemp61 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp61 >= 3.0f)) ? (((fTemp61 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp61 >= 2.0f)) ? 0.64f : (((fTemp61 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp56);
			float 	fTemp63 = (1.0f / ((iTemp58) ? 0.0001f : ((iTemp59) ? (((fTemp62 > 0.0f)) ? (0.05f * (fTemp52 / fTemp62)) : 0.0f) : fTemp52)));
			float 	fTemp64 = (fRec27[1] - fTemp63);
			float 	fTemp65 = (fRec27[1] + fTemp63);
			fRec27[0] = (((fTemp65 < fTemp60)) ? fTemp65 : (((fTemp64 > fTemp60)) ? fTemp64 : fTemp60));
			fRec24[0] = fRec27[0];
			fRec22[0] = (fRec24[0] - (fConst17 * ((fConst15 * fRec22[2]) + (fConst13 * fRec22[1]))));
			float 	fTemp66 = min(0.99f, (fConst23 * (((3947.8418f * fRec22[0]) + (7895.6836f * fRec22[1])) + (3947.8418f * fRec22[2]))));
			float 	fTemp67 = ((iTemp33) ? 0.0f : (fSlow26 + fRec33[1]));
			fRec33[0] = (fTemp67 - floorf(fTemp67));
			float 	fTemp68 = (fSlow30 + (fRec34[1] + -1.0f));
			float 	fTemp69 = (fSlow30 + fRec34[1]);
			int 	iTemp70 = (fTemp68 < 0.0f);
			fRec34[0] = ((iTemp70) ? fTemp69 : fTemp68);
			float 	fRec35 = ((iTemp70) ? fTemp69 : (fSlow30 + (fRec34[1] + (fSlow31 * fTemp68))));
			float 	fTemp71 = (fSlow33 + (fRec36[1] + -1.0f));
			float 	fTemp72 = (fSlow33 + fRec36[1]);
			int 	iTemp73 = (fTemp71 < 0.0f);
			fRec36[0] = ((iTemp73) ? fTemp72 : fTemp71);
			float 	fRec37 = ((iTemp73) ? fTemp72 : (fSlow33 + (fRec36[1] + (fSlow34 * fTemp71))));
			fVec9[0] = fSlow35;
			int 	iTemp74 = (fSlow35 != fVec9[1]);
			iVec10[0] = iTemp74;
			int 	iTemp75 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec41[0] = ((iRec41[1] * (1 - iTemp75)) + (iTemp8 * iTemp75));
			float 	fTemp76 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec41[0])))) > 0.5f) & iSlow38)) ? 0.0f : fSlow37))) + -1.0f));
			fVec11[0] = fTemp76;
			float 	fTemp77 = (0.5f * fVec11[0]);
			int 	iTemp78 = (fTemp77 > 0.001f);
			int 	iTemp79 = (fTemp77 <= 0.001f);
			float 	fTemp80 = float((iTemp79 | ((0.5f * fVec11[1]) >= 0.001f)));
			fRec42[0] = max((fRec42[1] * fTemp80), fSlow35);
			float 	fTemp81 = min(1.0f, (1.5f * fRec42[0]));
			int 	iTemp82 = (fTemp77 >= fRec40[1]);
			int 	iTemp83 = (fRec40[1] <= 0.001f);
			int 	iTemp84 = (((iRec39[1] >= 4)) ? (((iRec39[1] >= 6)) ? ((iTemp83) ? 0 : ((iTemp78) ? 1 : 6)) : (((iRec39[1] >= 5)) ? ((iTemp79) ? 3 : ((iTemp82) ? 4 : 5)) : ((iTemp79) ? 3 : (((fTemp77 <= fRec40[1])) ? 5 : 4)))) : (((iRec39[1] >= 2)) ? (((iRec39[1] >= 3)) ? (((iTemp79 & iTemp83)) ? 0 : ((iTemp78) ? 1 : 3)) : ((iTemp79) ? 3 : ((iTemp82) ? 4 : 2))) : (((iRec39[1] >= 1)) ? (((fRec40[1] >= min(fTemp81, 1.0f))) ? ((iTemp79) ? 6 : 2) : 1) : ((iTemp78) ? 1 : 0))));
			iRec39[0] = iTemp84;
			fRec44[0] = max((fTemp80 * fRec44[1]), fSlow39);
			float 	fTemp85 = (((iTemp84 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec44[0]))) : (((iTemp84 >= 4)) ? (((iTemp84 >= 6)) ? fConst22 : fConst21) : (((iTemp84 >= 2)) ? (((iTemp84 >= 3)) ? fConst20 : fConst19) : (((iTemp84 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp86 = (iRec39[1] != iRec39[2]);
			iVec12[0] = iTemp86;
			int 	iTemp87 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec45[0] = ((iRec45[1] * (1 - iTemp87)) + (iTemp8 * iTemp87));
			float 	fTemp88 = floorf((2e+01f * (((fTemp85 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec45[0]))) / fTemp85) : 0.0f)));
			float 	fTemp89 = (((fTemp88 >= 1e+01f)) ? (((fTemp88 >= 15.0f)) ? (((fTemp88 >= 18.0f)) ? (((fTemp88 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp88 >= 17.0f)) ? 0.03f : (((fTemp88 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp88 >= 13.0f)) ? (((fTemp88 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp88 >= 12.0f)) ? 0.14f : (((fTemp88 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp88 >= 5.0f)) ? (((fTemp88 >= 8.0f)) ? (((fTemp88 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp88 >= 7.0f)) ? 0.3f : (((fTemp88 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp88 >= 3.0f)) ? (((fTemp88 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp88 >= 2.0f)) ? 0.64f : (((fTemp88 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec46[0] = iRec39[1];
			int 	iTemp90 = (iRec46[1] == iRec39[1]);
			int 	iTemp91 = (iRec39[1] == 0);
			fRec47[0] = ((iTemp91) ? fTemp77 : ((iTemp90) ? min(min(fRec47[1], fTemp77), fRec40[1]) : min(fTemp77, fRec40[1])));
			fRec48[0] = ((iTemp91) ? fTemp77 : ((iTemp90) ? max(max(fRec48[1], fTemp77), fRec40[1]) : max(fTemp77, fRec40[1])));
			int 	iTemp92 = (iRec39[1] == 3);
			float 	fTemp93 = (((iRec39[1] == 1)) ? min(1.0f, fTemp81) : ((iTemp91) ? 0.0001f : (((iTemp92 | (iRec39[1] == 6))) ? (fRec48[0] * fTemp89) : fTemp77)));
			float 	fTemp94 = (fTemp88 + -1.0f);
			float 	fTemp95 = ((((fTemp88 > 0.0f)) ? (((fTemp94 >= 1e+01f)) ? (((fTemp94 >= 15.0f)) ? (((fTemp94 >= 18.0f)) ? (((fTemp94 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp94 >= 17.0f)) ? 0.03f : (((fTemp94 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp94 >= 13.0f)) ? (((fTemp94 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp94 >= 12.0f)) ? 0.14f : (((fTemp94 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp94 >= 5.0f)) ? (((fTemp94 >= 8.0f)) ? (((fTemp94 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp94 >= 7.0f)) ? 0.3f : (((fTemp94 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp94 >= 3.0f)) ? (((fTemp94 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp94 >= 2.0f)) ? 0.64f : (((fTemp94 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp89);
			float 	fTemp96 = (1.0f / ((iTemp91) ? 0.0001f : ((iTemp92) ? (((fTemp95 > 0.0f)) ? (0.05f * (fTemp85 / fTemp95)) : 0.0f) : fTemp85)));
			float 	fTemp97 = (fRec43[1] - fTemp96);
			float 	fTemp98 = (fRec43[1] + fTemp96);
			fRec43[0] = (((fTemp98 < fTemp93)) ? fTemp98 : (((fTemp97 > fTemp93)) ? fTemp97 : fTemp93));
			fRec40[0] = fRec43[0];
			fRec38[0] = (fRec40[0] - (fConst17 * ((fConst15 * fRec38[2]) + (fConst13 * fRec38[1]))));
			float 	fTemp99 = min(0.99f, (fConst23 * (((3947.8418f * fRec38[0]) + (7895.6836f * fRec38[1])) + (3947.8418f * fRec38[2]))));
			float 	fTemp100 = ((iTemp33) ? 0.0f : (fSlow40 + fRec49[1]));
			fRec49[0] = (fTemp100 - floorf(fTemp100));
			float 	fTemp101 = (fSlow44 + (fRec50[1] + -1.0f));
			float 	fTemp102 = (fSlow44 + fRec50[1]);
			int 	iTemp103 = (fTemp101 < 0.0f);
			fRec50[0] = ((iTemp103) ? fTemp102 : fTemp101);
			float 	fRec51 = ((iTemp103) ? fTemp102 : (fSlow44 + (fRec50[1] + (fSlow45 * fTemp101))));
			float 	fTemp104 = (fSlow47 + (fRec52[1] + -1.0f));
			float 	fTemp105 = (fSlow47 + fRec52[1]);
			int 	iTemp106 = (fTemp104 < 0.0f);
			fRec52[0] = ((iTemp106) ? fTemp105 : fTemp104);
			float 	fRec53 = ((iTemp106) ? fTemp105 : (fSlow47 + (fRec52[1] + (fSlow48 * fTemp104))));
			fVec13[0] = fSlow49;
			int 	iTemp107 = (fSlow49 != fVec13[1]);
			iVec14[0] = iTemp107;
			int 	iTemp108 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec57[0] = ((iRec57[1] * (1 - iTemp108)) + (iTemp8 * iTemp108));
			float 	fTemp109 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec57[0])))) > 0.5f) & iSlow52)) ? 0.0f : fSlow51))) + -1.0f));
			fVec15[0] = fTemp109;
			float 	fTemp110 = (0.5f * fVec15[0]);
			int 	iTemp111 = (fTemp110 > 0.001f);
			int 	iTemp112 = (fTemp110 <= 0.001f);
			float 	fTemp113 = float((iTemp112 | ((0.5f * fVec15[1]) >= 0.001f)));
			fRec58[0] = max((fRec58[1] * fTemp113), fSlow49);
			float 	fTemp114 = min(1.0f, (1.5f * fRec58[0]));
			int 	iTemp115 = (fTemp110 >= fRec56[1]);
			int 	iTemp116 = (fRec56[1] <= 0.001f);
			int 	iTemp117 = (((iRec55[1] >= 4)) ? (((iRec55[1] >= 6)) ? ((iTemp116) ? 0 : ((iTemp111) ? 1 : 6)) : (((iRec55[1] >= 5)) ? ((iTemp112) ? 3 : ((iTemp115) ? 4 : 5)) : ((iTemp112) ? 3 : (((fTemp110 <= fRec56[1])) ? 5 : 4)))) : (((iRec55[1] >= 2)) ? (((iRec55[1] >= 3)) ? (((iTemp112 & iTemp116)) ? 0 : ((iTemp111) ? 1 : 3)) : ((iTemp112) ? 3 : ((iTemp115) ? 4 : 2))) : (((iRec55[1] >= 1)) ? (((fRec56[1] >= min(fTemp114, 1.0f))) ? ((iTemp112) ? 6 : 2) : 1) : ((iTemp111) ? 1 : 0))));
			iRec55[0] = iTemp117;
			fRec60[0] = max((fTemp113 * fRec60[1]), fSlow53);
			float 	fTemp118 = (((iTemp117 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec60[0]))) : (((iTemp117 >= 4)) ? (((iTemp117 >= 6)) ? fConst22 : fConst21) : (((iTemp117 >= 2)) ? (((iTemp117 >= 3)) ? fConst20 : fConst19) : (((iTemp117 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp119 = (iRec55[1] != iRec55[2]);
			iVec16[0] = iTemp119;
			int 	iTemp120 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec61[0] = ((iRec61[1] * (1 - iTemp120)) + (iTemp8 * iTemp120));
			float 	fTemp121 = floorf((2e+01f * (((fTemp118 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec61[0]))) / fTemp118) : 0.0f)));
			float 	fTemp122 = (((fTemp121 >= 1e+01f)) ? (((fTemp121 >= 15.0f)) ? (((fTemp121 >= 18.0f)) ? (((fTemp121 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp121 >= 17.0f)) ? 0.03f : (((fTemp121 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp121 >= 13.0f)) ? (((fTemp121 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp121 >= 12.0f)) ? 0.14f : (((fTemp121 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp121 >= 5.0f)) ? (((fTemp121 >= 8.0f)) ? (((fTemp121 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp121 >= 7.0f)) ? 0.3f : (((fTemp121 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp121 >= 3.0f)) ? (((fTemp121 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp121 >= 2.0f)) ? 0.64f : (((fTemp121 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec62[0] = iRec55[1];
			int 	iTemp123 = (iRec62[1] == iRec55[1]);
			int 	iTemp124 = (iRec55[1] == 0);
			fRec63[0] = ((iTemp124) ? fTemp110 : ((iTemp123) ? min(min(fRec63[1], fTemp110), fRec56[1]) : min(fTemp110, fRec56[1])));
			fRec64[0] = ((iTemp124) ? fTemp110 : ((iTemp123) ? max(max(fRec64[1], fTemp110), fRec56[1]) : max(fTemp110, fRec56[1])));
			int 	iTemp125 = (iRec55[1] == 3);
			float 	fTemp126 = (((iRec55[1] == 1)) ? min(1.0f, fTemp114) : ((iTemp124) ? 0.0001f : (((iTemp125 | (iRec55[1] == 6))) ? (fRec64[0] * fTemp122) : fTemp110)));
			float 	fTemp127 = (fTemp121 + -1.0f);
			float 	fTemp128 = ((((fTemp121 > 0.0f)) ? (((fTemp127 >= 1e+01f)) ? (((fTemp127 >= 15.0f)) ? (((fTemp127 >= 18.0f)) ? (((fTemp127 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp127 >= 17.0f)) ? 0.03f : (((fTemp127 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp127 >= 13.0f)) ? (((fTemp127 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp127 >= 12.0f)) ? 0.14f : (((fTemp127 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp127 >= 5.0f)) ? (((fTemp127 >= 8.0f)) ? (((fTemp127 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp127 >= 7.0f)) ? 0.3f : (((fTemp127 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp127 >= 3.0f)) ? (((fTemp127 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp127 >= 2.0f)) ? 0.64f : (((fTemp127 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp122);
			float 	fTemp129 = (1.0f / ((iTemp124) ? 0.0001f : ((iTemp125) ? (((fTemp128 > 0.0f)) ? (0.05f * (fTemp118 / fTemp128)) : 0.0f) : fTemp118)));
			float 	fTemp130 = (fRec59[1] - fTemp129);
			float 	fTemp131 = (fRec59[1] + fTemp129);
			fRec59[0] = (((fTemp131 < fTemp126)) ? fTemp131 : (((fTemp130 > fTemp126)) ? fTemp130 : fTemp126));
			fRec56[0] = fRec59[0];
			fRec54[0] = (fRec56[0] - (fConst17 * ((fConst15 * fRec54[2]) + (fConst13 * fRec54[1]))));
			float 	fTemp132 = min(0.99f, (fConst23 * (((3947.8418f * fRec54[0]) + (7895.6836f * fRec54[1])) + (3947.8418f * fRec54[2]))));
			float 	fTemp133 = ((iTemp33) ? 0.0f : (fSlow54 + fRec65[1]));
			fRec65[0] = (fTemp133 - floorf(fTemp133));
			float 	fTemp134 = (fSlow58 + (fRec66[1] + -1.0f));
			float 	fTemp135 = (fSlow58 + fRec66[1]);
			int 	iTemp136 = (fTemp134 < 0.0f);
			fRec66[0] = ((iTemp136) ? fTemp135 : fTemp134);
			float 	fRec67 = ((iTemp136) ? fTemp135 : (fSlow58 + (fRec66[1] + (fSlow59 * fTemp134))));
			float 	fTemp137 = (fSlow61 + (fRec68[1] + -1.0f));
			float 	fTemp138 = (fSlow61 + fRec68[1]);
			int 	iTemp139 = (fTemp137 < 0.0f);
			fRec68[0] = ((iTemp139) ? fTemp138 : fTemp137);
			float 	fRec69 = ((iTemp139) ? fTemp138 : (fSlow61 + (fRec68[1] + (fSlow62 * fTemp137))));
			fVec17[0] = fSlow63;
			int 	iTemp140 = (fSlow63 != fVec17[1]);
			iVec18[0] = iTemp140;
			int 	iTemp141 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec73[0] = ((iRec73[1] * (1 - iTemp141)) + (iTemp8 * iTemp141));
			float 	fTemp142 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec73[0])))) > 0.5f) & iSlow66)) ? 0.0f : fSlow65))) + -1.0f));
			fVec19[0] = fTemp142;
			float 	fTemp143 = (0.5f * fVec19[0]);
			int 	iTemp144 = (fTemp143 > 0.001f);
			int 	iTemp145 = (fTemp143 <= 0.001f);
			float 	fTemp146 = float((iTemp145 | ((0.5f * fVec19[1]) >= 0.001f)));
			fRec74[0] = max((fRec74[1] * fTemp146), fSlow63);
			float 	fTemp147 = min(1.0f, (1.5f * fRec74[0]));
			int 	iTemp148 = (fTemp143 >= fRec72[1]);
			int 	iTemp149 = (fRec72[1] <= 0.001f);
			int 	iTemp150 = (((iRec71[1] >= 4)) ? (((iRec71[1] >= 6)) ? ((iTemp149) ? 0 : ((iTemp144) ? 1 : 6)) : (((iRec71[1] >= 5)) ? ((iTemp145) ? 3 : ((iTemp148) ? 4 : 5)) : ((iTemp145) ? 3 : (((fTemp143 <= fRec72[1])) ? 5 : 4)))) : (((iRec71[1] >= 2)) ? (((iRec71[1] >= 3)) ? (((iTemp145 & iTemp149)) ? 0 : ((iTemp144) ? 1 : 3)) : ((iTemp145) ? 3 : ((iTemp148) ? 4 : 2))) : (((iRec71[1] >= 1)) ? (((fRec72[1] >= min(fTemp147, 1.0f))) ? ((iTemp145) ? 6 : 2) : 1) : ((iTemp144) ? 1 : 0))));
			iRec71[0] = iTemp150;
			fRec76[0] = max((fTemp146 * fRec76[1]), fSlow67);
			float 	fTemp151 = (((iTemp150 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec76[0]))) : (((iTemp150 >= 4)) ? (((iTemp150 >= 6)) ? fConst22 : fConst21) : (((iTemp150 >= 2)) ? (((iTemp150 >= 3)) ? fConst20 : fConst19) : (((iTemp150 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp152 = (iRec71[1] != iRec71[2]);
			iVec20[0] = iTemp152;
			int 	iTemp153 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec77[0] = ((iRec77[1] * (1 - iTemp153)) + (iTemp8 * iTemp153));
			float 	fTemp154 = floorf((2e+01f * (((fTemp151 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec77[0]))) / fTemp151) : 0.0f)));
			float 	fTemp155 = (((fTemp154 >= 1e+01f)) ? (((fTemp154 >= 15.0f)) ? (((fTemp154 >= 18.0f)) ? (((fTemp154 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp154 >= 17.0f)) ? 0.03f : (((fTemp154 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp154 >= 13.0f)) ? (((fTemp154 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp154 >= 12.0f)) ? 0.14f : (((fTemp154 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp154 >= 5.0f)) ? (((fTemp154 >= 8.0f)) ? (((fTemp154 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp154 >= 7.0f)) ? 0.3f : (((fTemp154 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp154 >= 3.0f)) ? (((fTemp154 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp154 >= 2.0f)) ? 0.64f : (((fTemp154 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec78[0] = iRec71[1];
			int 	iTemp156 = (iRec78[1] == iRec71[1]);
			int 	iTemp157 = (iRec71[1] == 0);
			fRec79[0] = ((iTemp157) ? fTemp143 : ((iTemp156) ? min(min(fRec79[1], fTemp143), fRec72[1]) : min(fTemp143, fRec72[1])));
			fRec80[0] = ((iTemp157) ? fTemp143 : ((iTemp156) ? max(max(fRec80[1], fTemp143), fRec72[1]) : max(fTemp143, fRec72[1])));
			int 	iTemp158 = (iRec71[1] == 3);
			float 	fTemp159 = (((iRec71[1] == 1)) ? min(1.0f, fTemp147) : ((iTemp157) ? 0.0001f : (((iTemp158 | (iRec71[1] == 6))) ? (fRec80[0] * fTemp155) : fTemp143)));
			float 	fTemp160 = (fTemp154 + -1.0f);
			float 	fTemp161 = ((((fTemp154 > 0.0f)) ? (((fTemp160 >= 1e+01f)) ? (((fTemp160 >= 15.0f)) ? (((fTemp160 >= 18.0f)) ? (((fTemp160 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp160 >= 17.0f)) ? 0.03f : (((fTemp160 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp160 >= 13.0f)) ? (((fTemp160 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp160 >= 12.0f)) ? 0.14f : (((fTemp160 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp160 >= 5.0f)) ? (((fTemp160 >= 8.0f)) ? (((fTemp160 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp160 >= 7.0f)) ? 0.3f : (((fTemp160 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp160 >= 3.0f)) ? (((fTemp160 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp160 >= 2.0f)) ? 0.64f : (((fTemp160 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp155);
			float 	fTemp162 = (1.0f / ((iTemp157) ? 0.0001f : ((iTemp158) ? (((fTemp161 > 0.0f)) ? (0.05f * (fTemp151 / fTemp161)) : 0.0f) : fTemp151)));
			float 	fTemp163 = (fRec75[1] - fTemp162);
			float 	fTemp164 = (fRec75[1] + fTemp162);
			fRec75[0] = (((fTemp164 < fTemp159)) ? fTemp164 : (((fTemp163 > fTemp159)) ? fTemp163 : fTemp159));
			fRec72[0] = fRec75[0];
			fRec70[0] = (fRec72[0] - (fConst17 * ((fConst15 * fRec70[2]) + (fConst13 * fRec70[1]))));
			float 	fTemp165 = min(0.99f, (fConst23 * (((3947.8418f * fRec70[0]) + (7895.6836f * fRec70[1])) + (3947.8418f * fRec70[2]))));
			float 	fTemp166 = ((iTemp33) ? 0.0f : (fSlow68 + fRec81[1]));
			fRec81[0] = (fTemp166 - floorf(fTemp166));
			float 	fTemp167 = (fSlow72 + (fRec82[1] + -1.0f));
			float 	fTemp168 = (fSlow72 + fRec82[1]);
			int 	iTemp169 = (fTemp167 < 0.0f);
			fRec82[0] = ((iTemp169) ? fTemp168 : fTemp167);
			float 	fRec83 = ((iTemp169) ? fTemp168 : (fSlow72 + (fRec82[1] + (fSlow73 * fTemp167))));
			float 	fTemp170 = (fSlow75 + (fRec84[1] + -1.0f));
			float 	fTemp171 = (fSlow75 + fRec84[1]);
			int 	iTemp172 = (fTemp170 < 0.0f);
			fRec84[0] = ((iTemp172) ? fTemp171 : fTemp170);
			float 	fRec85 = ((iTemp172) ? fTemp171 : (fSlow75 + (fRec84[1] + (fSlow76 * fTemp170))));
			fVec21[0] = fSlow77;
			int 	iTemp173 = (fSlow77 != fVec21[1]);
			iVec22[0] = iTemp173;
			int 	iTemp174 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec89[0] = ((iRec89[1] * (1 - iTemp174)) + (iTemp8 * iTemp174));
			float 	fTemp175 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec9[0] + (-1 - iRec89[0])))) > 0.5f) & iSlow80)) ? 0.0f : fSlow79))) + -1.0f));
			fVec23[0] = fTemp175;
			float 	fTemp176 = (0.5f * fVec23[0]);
			int 	iTemp177 = (fTemp176 > 0.001f);
			int 	iTemp178 = (fTemp176 <= 0.001f);
			float 	fTemp179 = float((iTemp178 | ((0.5f * fVec23[1]) >= 0.001f)));
			fRec90[0] = max((fRec90[1] * fTemp179), fSlow77);
			float 	fTemp180 = min(1.0f, (1.5f * fRec90[0]));
			int 	iTemp181 = (fTemp176 >= fRec88[1]);
			int 	iTemp182 = (fRec88[1] <= 0.001f);
			int 	iTemp183 = (((iRec87[1] >= 4)) ? (((iRec87[1] >= 6)) ? ((iTemp182) ? 0 : ((iTemp177) ? 1 : 6)) : (((iRec87[1] >= 5)) ? ((iTemp178) ? 3 : ((iTemp181) ? 4 : 5)) : ((iTemp178) ? 3 : (((fTemp176 <= fRec88[1])) ? 5 : 4)))) : (((iRec87[1] >= 2)) ? (((iRec87[1] >= 3)) ? (((iTemp178 & iTemp182)) ? 0 : ((iTemp177) ? 1 : 3)) : ((iTemp178) ? 3 : ((iTemp181) ? 4 : 2))) : (((iRec87[1] >= 1)) ? (((fRec88[1] >= min(fTemp180, 1.0f))) ? ((iTemp178) ? 6 : 2) : 1) : ((iTemp177) ? 1 : 0))));
			iRec87[0] = iTemp183;
			fRec92[0] = max((fTemp179 * fRec92[1]), fSlow81);
			float 	fTemp184 = (((iTemp183 == 6)) ? (fConst22 * min(1.0f, (2.0f * fRec92[0]))) : (((iTemp183 >= 4)) ? (((iTemp183 >= 6)) ? fConst22 : fConst21) : (((iTemp183 >= 2)) ? (((iTemp183 >= 3)) ? fConst20 : fConst19) : (((iTemp183 >= 1)) ? fConst18 : 0.0f))));
			int 	iTemp185 = (iRec87[1] != iRec87[2]);
			iVec24[0] = iTemp185;
			int 	iTemp186 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec93[0] = ((iRec93[1] * (1 - iTemp186)) + (iTemp8 * iTemp186));
			float 	fTemp187 = floorf((2e+01f * (((fTemp184 > 0.0f)) ? (float((iRec9[0] + (-1 - iRec93[0]))) / fTemp184) : 0.0f)));
			float 	fTemp188 = (((fTemp187 >= 1e+01f)) ? (((fTemp187 >= 15.0f)) ? (((fTemp187 >= 18.0f)) ? (((fTemp187 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp187 >= 17.0f)) ? 0.03f : (((fTemp187 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp187 >= 13.0f)) ? (((fTemp187 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp187 >= 12.0f)) ? 0.14f : (((fTemp187 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp187 >= 5.0f)) ? (((fTemp187 >= 8.0f)) ? (((fTemp187 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp187 >= 7.0f)) ? 0.3f : (((fTemp187 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp187 >= 3.0f)) ? (((fTemp187 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp187 >= 2.0f)) ? 0.64f : (((fTemp187 >= 1.0f)) ? 0.74f : 0.86f)))));
			iRec94[0] = iRec87[1];
			int 	iTemp189 = (iRec94[1] == iRec87[1]);
			int 	iTemp190 = (iRec87[1] == 0);
			fRec95[0] = ((iTemp190) ? fTemp176 : ((iTemp189) ? min(min(fRec95[1], fTemp176), fRec88[1]) : min(fTemp176, fRec88[1])));
			fRec96[0] = ((iTemp190) ? fTemp176 : ((iTemp189) ? max(max(fRec96[1], fTemp176), fRec88[1]) : max(fTemp176, fRec88[1])));
			int 	iTemp191 = (iRec87[1] == 3);
			float 	fTemp192 = (((iRec87[1] == 1)) ? min(1.0f, fTemp180) : ((iTemp190) ? 0.0001f : (((iTemp191 | (iRec87[1] == 6))) ? (fRec96[0] * fTemp188) : fTemp176)));
			float 	fTemp193 = (fTemp187 + -1.0f);
			float 	fTemp194 = ((((fTemp187 > 0.0f)) ? (((fTemp193 >= 1e+01f)) ? (((fTemp193 >= 15.0f)) ? (((fTemp193 >= 18.0f)) ? (((fTemp193 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp193 >= 17.0f)) ? 0.03f : (((fTemp193 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp193 >= 13.0f)) ? (((fTemp193 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp193 >= 12.0f)) ? 0.14f : (((fTemp193 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp193 >= 5.0f)) ? (((fTemp193 >= 8.0f)) ? (((fTemp193 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp193 >= 7.0f)) ? 0.3f : (((fTemp193 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp193 >= 3.0f)) ? (((fTemp193 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp193 >= 2.0f)) ? 0.64f : (((fTemp193 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp188);
			float 	fTemp195 = (1.0f / ((iTemp190) ? 0.0001f : ((iTemp191) ? (((fTemp194 > 0.0f)) ? (0.05f * (fTemp184 / fTemp194)) : 0.0f) : fTemp184)));
			float 	fTemp196 = (fRec91[1] - fTemp195);
			float 	fTemp197 = (fRec91[1] + fTemp195);
			fRec91[0] = (((fTemp197 < fTemp192)) ? fTemp197 : (((fTemp196 > fTemp192)) ? fTemp196 : fTemp192));
			fRec88[0] = fRec91[0];
			fRec86[0] = (fRec88[0] - (fConst17 * ((fConst15 * fRec86[2]) + (fConst13 * fRec86[1]))));
			float 	fTemp198 = min(0.99f, (fConst23 * (((3947.8418f * fRec86[0]) + (7895.6836f * fRec86[1])) + (3947.8418f * fRec86[2]))));
			float 	fTemp199 = ((iTemp33) ? 0.0f : (fSlow82 + fRec97[1]));
			fRec97[0] = (fTemp199 - floorf(fTemp199));
			fRec0[0] = ((1.37f * ((((((fTemp198 * ((fSlow83 * (((((fRec97[0] < 0.5f)) ? ((4.0f * fRec97[0]) + -1.0f) : ((4.0f * (1.0f - fRec97[0])) + -1.0f)) * (fTemp198 + (1.0f - fTemp176))) + (((2.0f * fRec97[0]) + -1.0f) * (max(min((3.0f * (fTemp176 - fTemp198)), 0.3f), -0.15f) + 0.25f)))) + (fSlow78 * (((2.0f * fRec85) + -1.0f) + ((2.0f * fRec83) + -1.0f))))) + (fTemp165 * ((fSlow69 * (((((fRec81[0] < 0.5f)) ? ((4.0f * fRec81[0]) + -1.0f) : ((4.0f * (1.0f - fRec81[0])) + -1.0f)) * (fTemp165 + (1.0f - fTemp143))) + (((2.0f * fRec81[0]) + -1.0f) * (max(min((3.0f * (fTemp143 - fTemp165)), 0.3f), -0.15f) + 0.25f)))) + (fSlow64 * (((2.0f * fRec69) + -1.0f) + ((2.0f * fRec67) + -1.0f)))))) + (fTemp132 * ((fSlow55 * (((((fRec65[0] < 0.5f)) ? ((4.0f * fRec65[0]) + -1.0f) : ((4.0f * (1.0f - fRec65[0])) + -1.0f)) * (fTemp132 + (1.0f - fTemp110))) + (((2.0f * fRec65[0]) + -1.0f) * (max(min((3.0f * (fTemp110 - fTemp132)), 0.3f), -0.15f) + 0.25f)))) + (fSlow50 * (((2.0f * fRec53) + -1.0f) + ((2.0f * fRec51) + -1.0f)))))) + (fTemp99 * ((fSlow41 * (((((fRec49[0] < 0.5f)) ? ((4.0f * fRec49[0]) + -1.0f) : ((4.0f * (1.0f - fRec49[0])) + -1.0f)) * (fTemp99 + (1.0f - fTemp77))) + (((2.0f * fRec49[0]) + -1.0f) * (max(min((3.0f * (fTemp77 - fTemp99)), 0.3f), -0.15f) + 0.25f)))) + (fSlow36 * (((2.0f * fRec37) + -1.0f) + ((2.0f * fRec35) + -1.0f)))))) + (fTemp66 * ((fSlow27 * (((((fRec33[0] < 0.5f)) ? ((4.0f * fRec33[0]) + -1.0f) : ((4.0f * (1.0f - fRec33[0])) + -1.0f)) * (fTemp66 + (1.0f - fTemp44))) + (((2.0f * fRec33[0]) + -1.0f) * (max(min((3.0f * (fTemp44 - fTemp66)), 0.3f), -0.15f) + 0.25f)))) + (fSlow22 * (((2.0f * fRec21) + -1.0f) + ((2.0f * fRec19) + -1.0f)))))) + (fTemp32 * ((fSlow13 * (((((fRec17[0] < 0.5f)) ? ((4.0f * fRec17[0]) + -1.0f) : ((4.0f * (1.0f - fRec17[0])) + -1.0f)) * (fTemp32 + (1.0f - fTemp10))) + (((2.0f * fRec17[0]) + -1.0f) * (max(min((3.0f * (fTemp10 - fTemp32)), 0.3f), -0.15f) + 0.25f)))) + (fSlow8 * (((2.0f * fRec4) + -1.0f) + ((2.0f * fRec2) + -1.0f))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst25 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec97[1] = fRec97[0];
			fRec86[2] = fRec86[1]; fRec86[1] = fRec86[0];
			fRec88[1] = fRec88[0];
			fRec91[1] = fRec91[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			iRec94[1] = iRec94[0];
			iRec93[1] = iRec93[0];
			iVec24[1] = iVec24[0];
			fRec92[1] = fRec92[0];
			iRec87[2] = iRec87[1]; iRec87[1] = iRec87[0];
			fRec90[1] = fRec90[0];
			fVec23[1] = fVec23[0];
			iRec89[1] = iRec89[0];
			iVec22[1] = iVec22[0];
			fVec21[1] = fVec21[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec70[2] = fRec70[1]; fRec70[1] = fRec70[0];
			fRec72[1] = fRec72[0];
			fRec75[1] = fRec75[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			iRec78[1] = iRec78[0];
			iRec77[1] = iRec77[0];
			iVec20[1] = iVec20[0];
			fRec76[1] = fRec76[0];
			iRec71[2] = iRec71[1]; iRec71[1] = iRec71[0];
			fRec74[1] = fRec74[0];
			fVec19[1] = fVec19[0];
			iRec73[1] = iRec73[0];
			iVec18[1] = iVec18[0];
			fVec17[1] = fVec17[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
			fRec56[1] = fRec56[0];
			fRec59[1] = fRec59[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			iRec62[1] = iRec62[0];
			iRec61[1] = iRec61[0];
			iVec16[1] = iVec16[0];
			fRec60[1] = fRec60[0];
			iRec55[2] = iRec55[1]; iRec55[1] = iRec55[0];
			fRec58[1] = fRec58[0];
			fVec15[1] = fVec15[0];
			iRec57[1] = iRec57[0];
			iVec14[1] = iVec14[0];
			fVec13[1] = fVec13[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec38[2] = fRec38[1]; fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fRec43[1] = fRec43[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			iRec46[1] = iRec46[0];
			iRec45[1] = iRec45[0];
			iVec12[1] = iVec12[0];
			fRec44[1] = fRec44[0];
			iRec39[2] = iRec39[1]; iRec39[1] = iRec39[0];
			fRec42[1] = fRec42[0];
			fVec11[1] = fVec11[0];
			iRec41[1] = iRec41[0];
			iVec10[1] = iVec10[0];
			fVec9[1] = fVec9[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			iRec30[1] = iRec30[0];
			iRec29[1] = iRec29[0];
			iVec8[1] = iVec8[0];
			fRec28[1] = fRec28[0];
			iRec23[2] = iRec23[1]; iRec23[1] = iRec23[0];
			fRec26[1] = fRec26[0];
			fVec7[1] = fVec7[0];
			iRec25[1] = iRec25[0];
			iVec6[1] = iVec6[0];
			fVec5[1] = fVec5[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec7[1] = fRec7[0];
			fRec11[1] = fRec11[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			iRec14[1] = iRec14[0];
			iRec13[1] = iRec13[0];
			iVec4[1] = iVec4[0];
			fRec12[1] = fRec12[0];
			iRec6[2] = iRec6[1]; iRec6[1] = iRec6[0];
			fRec10[1] = fRec10[0];
			fVec3[1] = fVec3[0];
			iRec8[1] = iRec8[0];
			iRec9[1] = iRec9[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec3[1] = fRec3[0];
			fRec1[1] = fRec1[0];
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
