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
	float 	fConst10;
	float 	fRec5[2];
	float 	fConst14;
	float 	fConst16;
	float 	fConst18;
	FAUSTFLOAT 	fslider2;
	int 	iVec2[2];
	int 	iRec10[2];
	int 	iRec9[2];
	float 	fVec3[2];
	float 	fRec11[2];
	int 	iRec7[3];
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	float 	fRec13[2];
	int 	iVec4[2];
	int 	iRec14[2];
	int 	iRec15[2];
	float 	fRec16[2];
	float 	fRec17[2];
	FAUSTFLOAT 	fbargraph0;
	float 	fRec12[2];
	float 	fRec8[2];
	float 	fRec6[3];
	float 	fConst24;
	FAUSTFLOAT 	fslider3;
	float 	fRec18[2];
	float 	fRec20[2];
	FAUSTFLOAT 	fslider4;
	float 	fVec5[2];
	float 	fRec22[2];
	FAUSTFLOAT 	fslider5;
	int 	iVec6[2];
	int 	iRec26[2];
	float 	fVec7[2];
	float 	fRec27[2];
	int 	iRec24[3];
	float 	fRec29[2];
	int 	iVec8[2];
	int 	iRec30[2];
	int 	iRec31[2];
	float 	fRec32[2];
	float 	fRec33[2];
	FAUSTFLOAT 	fbargraph1;
	float 	fRec28[2];
	float 	fRec25[2];
	float 	fRec23[3];
	FAUSTFLOAT 	fslider6;
	float 	fRec34[2];
	float 	fRec36[2];
	FAUSTFLOAT 	fslider7;
	float 	fVec9[2];
	float 	fRec38[2];
	FAUSTFLOAT 	fslider8;
	int 	iVec10[2];
	int 	iRec42[2];
	float 	fVec11[2];
	float 	fRec43[2];
	int 	iRec40[3];
	float 	fRec45[2];
	int 	iVec12[2];
	int 	iRec46[2];
	int 	iRec47[2];
	float 	fRec48[2];
	float 	fRec49[2];
	FAUSTFLOAT 	fbargraph2;
	float 	fRec44[2];
	float 	fRec41[2];
	float 	fRec39[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec50[2];
	float 	fRec52[2];
	FAUSTFLOAT 	fslider10;
	float 	fVec13[2];
	float 	fRec54[2];
	FAUSTFLOAT 	fslider11;
	int 	iVec14[2];
	int 	iRec58[2];
	float 	fVec15[2];
	float 	fRec59[2];
	int 	iRec56[3];
	float 	fRec61[2];
	int 	iVec16[2];
	int 	iRec62[2];
	int 	iRec63[2];
	float 	fRec64[2];
	float 	fRec65[2];
	FAUSTFLOAT 	fbargraph3;
	float 	fRec60[2];
	float 	fRec57[2];
	float 	fRec55[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec66[2];
	float 	fRec68[2];
	FAUSTFLOAT 	fslider13;
	float 	fVec17[2];
	float 	fRec70[2];
	FAUSTFLOAT 	fslider14;
	int 	iVec18[2];
	int 	iRec74[2];
	float 	fVec19[2];
	float 	fRec75[2];
	int 	iRec72[3];
	float 	fRec77[2];
	int 	iVec20[2];
	int 	iRec78[2];
	int 	iRec79[2];
	float 	fRec80[2];
	float 	fRec81[2];
	FAUSTFLOAT 	fbargraph4;
	float 	fRec76[2];
	float 	fRec73[2];
	float 	fRec71[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec82[2];
	float 	fRec84[2];
	FAUSTFLOAT 	fslider16;
	float 	fVec21[2];
	float 	fRec86[2];
	FAUSTFLOAT 	fslider17;
	int 	iVec22[2];
	int 	iRec90[2];
	float 	fVec23[2];
	float 	fRec91[2];
	int 	iRec88[3];
	float 	fRec93[2];
	int 	iVec24[2];
	int 	iRec94[2];
	int 	iRec95[2];
	float 	fRec96[2];
	float 	fRec97[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec92[2];
	float 	fRec89[2];
	float 	fRec87[3];
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
		fConst10 = (8.175799f / fConst0);
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
		fConst23 = (2.0f * fConst0);
		fConst24 = (fConst13 / (fConst1 * fConst17));
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
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<3; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec14[i] = 0;
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) iRec24[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) iRec40[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) iRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<3; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec62[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) iRec72[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) iRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<3; i++) iRec88[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec94[i] = 0;
		for (int i=0; i<2; i++) iRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec87[i] = 0;
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
		float 	fSlow9 = (fConst10 * fSlow0);
		float 	fSlow10 = float(fslider2);
		int 	iSlow11 = (fSlow7 == 0.0f);
		float 	fSlow12 = (0.0f - fSlow7);
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
		float 	fSlow23 = (fConst10 * fSlow14);
		float 	fSlow24 = float(fslider5);
		int 	iSlow25 = (fSlow21 == 0.0f);
		float 	fSlow26 = (0.0f - fSlow21);
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
		float 	fSlow37 = (fConst10 * fSlow28);
		float 	fSlow38 = float(fslider8);
		int 	iSlow39 = (fSlow35 == 0.0f);
		float 	fSlow40 = (0.0f - fSlow35);
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
		float 	fSlow51 = (fConst10 * fSlow42);
		float 	fSlow52 = float(fslider11);
		int 	iSlow53 = (fSlow49 == 0.0f);
		float 	fSlow54 = (0.0f - fSlow49);
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
		float 	fSlow65 = (fConst10 * fSlow56);
		float 	fSlow66 = float(fslider14);
		int 	iSlow67 = (fSlow63 == 0.0f);
		float 	fSlow68 = (0.0f - fSlow63);
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
		float 	fSlow79 = (fConst10 * fSlow70);
		float 	fSlow80 = float(fslider17);
		int 	iSlow81 = (fSlow77 == 0.0f);
		float 	fSlow82 = (0.0f - fSlow77);
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
			int 	iTemp6 = (1 - iVec0[1]);
			float 	fTemp7 = ((iTemp6) ? 0.0f : (fSlow9 + fRec5[1]));
			fRec5[0] = (fTemp7 - floorf(fTemp7));
			int 	iTemp8 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp8;
			int 	iTemp9 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec10[0] = (iRec10[1] + 1);
			int 	iTemp10 = (iRec10[0] + -1);
			iRec9[0] = ((iRec9[1] * (1 - iTemp9)) + (iTemp10 * iTemp9));
			float 	fTemp11 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.5f) & iSlow11)) ? 0.0f : fSlow10))) + -1.0f));
			fVec3[0] = fTemp11;
			float 	fTemp12 = (0.5f * fVec3[0]);
			int 	iTemp13 = (fTemp12 > 0.001f);
			int 	iTemp14 = (fTemp12 <= 0.001f);
			float 	fTemp15 = float((iTemp14 | ((0.5f * fVec3[1]) >= 0.001f)));
			fRec11[0] = max((fRec11[1] * fTemp15), fSlow7);
			float 	fTemp16 = min(1.0f, (2.0f * fRec11[0]));
			int 	iTemp17 = (fTemp12 >= fRec8[1]);
			int 	iTemp18 = (fRec8[1] <= 0.001f);
			int 	iTemp19 = (((iRec7[1] >= 4)) ? (((iRec7[1] >= 6)) ? ((iTemp18) ? 0 : ((iTemp13) ? 1 : 6)) : (((iRec7[1] >= 5)) ? ((iTemp14) ? 3 : ((iTemp17) ? 4 : 5)) : ((iTemp14) ? 3 : (((fTemp12 <= fRec8[1])) ? 5 : 4)))) : (((iRec7[1] >= 2)) ? (((iRec7[1] >= 3)) ? (((iTemp14 & iTemp18)) ? 0 : ((iTemp13) ? 1 : 3)) : ((iTemp14) ? 3 : ((iTemp17) ? ((iTemp14) ? 6 : 4) : 2))) : (((iRec7[1] >= 1)) ? (((fRec8[1] >= min(fTemp16, 1.0f))) ? ((iTemp14) ? 6 : 2) : 1) : ((iTemp13) ? 1 : 0))));
			iRec7[0] = iTemp19;
			fRec13[0] = max((fTemp15 * fRec13[1]), fSlow12);
			float 	fTemp20 = (((iTemp19 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec13[0]))) : (((iTemp19 >= 4)) ? (((iTemp19 >= 6)) ? fConst23 : fConst22) : (((iTemp19 >= 2)) ? (((iTemp19 >= 3)) ? fConst21 : fConst20) : (((iTemp19 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp21 = (iRec7[1] != iRec7[2]);
			iVec4[0] = iTemp21;
			int 	iTemp22 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec14[0] = ((iRec14[1] * (1 - iTemp22)) + (iTemp10 * iTemp22));
			float 	fTemp23 = min(19.0f, floorf((21.0f * (((fTemp20 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec14[0]))) / fTemp20) : 1.0f))));
			float 	fTemp24 = min((fTemp23 + 1.0f), 2e+01f);
			float 	fTemp25 = (((fTemp24 >= 11.0f)) ? (((fTemp24 >= 16.0f)) ? (((fTemp24 >= 19.0f)) ? (((fTemp24 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp24 >= 18.0f)) ? 0.03f : (((fTemp24 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp24 >= 14.0f)) ? (((fTemp24 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp24 >= 13.0f)) ? 0.14f : (((fTemp24 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp24 >= 6.0f)) ? (((fTemp24 >= 9.0f)) ? (((fTemp24 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp24 >= 8.0f)) ? 0.3f : (((fTemp24 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp24 >= 3.0f)) ? (((fTemp24 >= 5.0f)) ? 0.47f : (((fTemp24 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp24 >= 2.0f)) ? 0.74f : (((fTemp24 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec15[0] = iRec7[1];
			int 	iTemp26 = (iRec15[1] == iRec7[1]);
			int 	iTemp27 = (iRec7[1] == 0);
			fRec16[0] = ((iTemp27) ? fTemp12 : ((iTemp26) ? min(min(fRec16[1], fTemp12), fRec8[1]) : min(fTemp12, fRec8[1])));
			fRec17[0] = ((iTemp27) ? fTemp12 : ((iTemp26) ? max(max(fRec17[1], fTemp12), fRec8[1]) : max(fTemp12, fRec8[1])));
			int 	iTemp28 = ((iRec7[1] == 3) | (iRec7[1] == 6));
			fbargraph0 = float(iRec7[1]);
			float 	fTemp29 = (((fbargraph0 == 1.0f)) ? min(1.0f, fTemp16) : ((iTemp27) ? 0.0f : ((iTemp28) ? (fRec17[0] * fTemp25) : fTemp12)));
			float 	fTemp30 = (1.0f / ((iTemp27) ? 0.0001f : ((iTemp28) ? (0.05f * (fTemp20 / ((((fTemp23 >= 11.0f)) ? (((fTemp23 >= 16.0f)) ? (((fTemp23 >= 19.0f)) ? (((fTemp23 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp23 >= 18.0f)) ? 0.03f : (((fTemp23 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp23 >= 14.0f)) ? (((fTemp23 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp23 >= 13.0f)) ? 0.14f : (((fTemp23 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp23 >= 6.0f)) ? (((fTemp23 >= 9.0f)) ? (((fTemp23 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp23 >= 8.0f)) ? 0.3f : (((fTemp23 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp23 >= 3.0f)) ? (((fTemp23 >= 5.0f)) ? 0.47f : (((fTemp23 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp23 >= 2.0f)) ? 0.74f : (((fTemp23 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp25))) : fTemp20)));
			float 	fTemp31 = (fRec12[1] - fTemp30);
			float 	fTemp32 = (fRec12[1] + fTemp30);
			fRec12[0] = (((fTemp32 < fTemp29)) ? fTemp32 : (((fTemp31 > fTemp29)) ? fTemp31 : fTemp29));
			fRec8[0] = fRec12[0];
			fRec6[0] = (fRec8[0] - (fConst18 * ((fConst16 * fRec6[2]) + (fConst14 * fRec6[1]))));
			float 	fTemp33 = min(0.99f, (fConst24 * (((3947.8418f * fRec6[0]) + (7895.6836f * fRec6[1])) + (3947.8418f * fRec6[2]))));
			float 	fTemp34 = max(min((3.0f * (fTemp12 - fTemp33)), 0.3f), -0.15f);
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
			float 	fTemp41 = ((iTemp6) ? 0.0f : (fSlow23 + fRec22[1]));
			fRec22[0] = (fTemp41 - floorf(fTemp41));
			int 	iTemp42 = (fSlow21 != fVec5[1]);
			iVec6[0] = iTemp42;
			int 	iTemp43 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec26[0] = ((iRec26[1] * (1 - iTemp43)) + (iTemp10 * iTemp43));
			float 	fTemp44 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec26[0])))) > 0.5f) & iSlow25)) ? 0.0f : fSlow24))) + -1.0f));
			fVec7[0] = fTemp44;
			float 	fTemp45 = (0.5f * fVec7[0]);
			int 	iTemp46 = (fTemp45 > 0.001f);
			int 	iTemp47 = (fTemp45 <= 0.001f);
			float 	fTemp48 = float((iTemp47 | ((0.5f * fVec7[1]) >= 0.001f)));
			fRec27[0] = max((fRec27[1] * fTemp48), fSlow21);
			float 	fTemp49 = min(1.0f, (2.0f * fRec27[0]));
			int 	iTemp50 = (fTemp45 >= fRec25[1]);
			int 	iTemp51 = (fRec25[1] <= 0.001f);
			int 	iTemp52 = (((iRec24[1] >= 4)) ? (((iRec24[1] >= 6)) ? ((iTemp51) ? 0 : ((iTemp46) ? 1 : 6)) : (((iRec24[1] >= 5)) ? ((iTemp47) ? 3 : ((iTemp50) ? 4 : 5)) : ((iTemp47) ? 3 : (((fTemp45 <= fRec25[1])) ? 5 : 4)))) : (((iRec24[1] >= 2)) ? (((iRec24[1] >= 3)) ? (((iTemp47 & iTemp51)) ? 0 : ((iTemp46) ? 1 : 3)) : ((iTemp47) ? 3 : ((iTemp50) ? ((iTemp47) ? 6 : 4) : 2))) : (((iRec24[1] >= 1)) ? (((fRec25[1] >= min(fTemp49, 1.0f))) ? ((iTemp47) ? 6 : 2) : 1) : ((iTemp46) ? 1 : 0))));
			iRec24[0] = iTemp52;
			fRec29[0] = max((fTemp48 * fRec29[1]), fSlow26);
			float 	fTemp53 = (((iTemp52 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec29[0]))) : (((iTemp52 >= 4)) ? (((iTemp52 >= 6)) ? fConst23 : fConst22) : (((iTemp52 >= 2)) ? (((iTemp52 >= 3)) ? fConst21 : fConst20) : (((iTemp52 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp54 = (iRec24[1] != iRec24[2]);
			iVec8[0] = iTemp54;
			int 	iTemp55 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec30[0] = ((iRec30[1] * (1 - iTemp55)) + (iTemp10 * iTemp55));
			float 	fTemp56 = min(19.0f, floorf((21.0f * (((fTemp53 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec30[0]))) / fTemp53) : 1.0f))));
			float 	fTemp57 = min((fTemp56 + 1.0f), 2e+01f);
			float 	fTemp58 = (((fTemp57 >= 11.0f)) ? (((fTemp57 >= 16.0f)) ? (((fTemp57 >= 19.0f)) ? (((fTemp57 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp57 >= 18.0f)) ? 0.03f : (((fTemp57 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp57 >= 14.0f)) ? (((fTemp57 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp57 >= 13.0f)) ? 0.14f : (((fTemp57 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp57 >= 6.0f)) ? (((fTemp57 >= 9.0f)) ? (((fTemp57 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp57 >= 8.0f)) ? 0.3f : (((fTemp57 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp57 >= 3.0f)) ? (((fTemp57 >= 5.0f)) ? 0.47f : (((fTemp57 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp57 >= 2.0f)) ? 0.74f : (((fTemp57 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec31[0] = iRec24[1];
			int 	iTemp59 = (iRec31[1] == iRec24[1]);
			int 	iTemp60 = (iRec24[1] == 0);
			fRec32[0] = ((iTemp60) ? fTemp45 : ((iTemp59) ? min(min(fRec32[1], fTemp45), fRec25[1]) : min(fTemp45, fRec25[1])));
			fRec33[0] = ((iTemp60) ? fTemp45 : ((iTemp59) ? max(max(fRec33[1], fTemp45), fRec25[1]) : max(fTemp45, fRec25[1])));
			int 	iTemp61 = ((iRec24[1] == 3) | (iRec24[1] == 6));
			fbargraph1 = float(iRec24[1]);
			float 	fTemp62 = (((fbargraph1 == 1.0f)) ? min(1.0f, fTemp49) : ((iTemp60) ? 0.0f : ((iTemp61) ? (fRec33[0] * fTemp58) : fTemp45)));
			float 	fTemp63 = (1.0f / ((iTemp60) ? 0.0001f : ((iTemp61) ? (0.05f * (fTemp53 / ((((fTemp56 >= 11.0f)) ? (((fTemp56 >= 16.0f)) ? (((fTemp56 >= 19.0f)) ? (((fTemp56 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp56 >= 18.0f)) ? 0.03f : (((fTemp56 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp56 >= 14.0f)) ? (((fTemp56 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp56 >= 13.0f)) ? 0.14f : (((fTemp56 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp56 >= 6.0f)) ? (((fTemp56 >= 9.0f)) ? (((fTemp56 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp56 >= 8.0f)) ? 0.3f : (((fTemp56 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp56 >= 3.0f)) ? (((fTemp56 >= 5.0f)) ? 0.47f : (((fTemp56 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp56 >= 2.0f)) ? 0.74f : (((fTemp56 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp58))) : fTemp53)));
			float 	fTemp64 = (fRec28[1] - fTemp63);
			float 	fTemp65 = (fRec28[1] + fTemp63);
			fRec28[0] = (((fTemp65 < fTemp62)) ? fTemp65 : (((fTemp64 > fTemp62)) ? fTemp64 : fTemp62));
			fRec25[0] = fRec28[0];
			fRec23[0] = (fRec25[0] - (fConst18 * ((fConst16 * fRec23[2]) + (fConst14 * fRec23[1]))));
			float 	fTemp66 = min(0.99f, (fConst24 * (((3947.8418f * fRec23[0]) + (7895.6836f * fRec23[1])) + (3947.8418f * fRec23[2]))));
			float 	fTemp67 = max(min((3.0f * (fTemp45 - fTemp66)), 0.3f), -0.15f);
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
			float 	fTemp74 = ((iTemp6) ? 0.0f : (fSlow37 + fRec38[1]));
			fRec38[0] = (fTemp74 - floorf(fTemp74));
			int 	iTemp75 = (fSlow35 != fVec9[1]);
			iVec10[0] = iTemp75;
			int 	iTemp76 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec42[0] = ((iRec42[1] * (1 - iTemp76)) + (iTemp10 * iTemp76));
			float 	fTemp77 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec42[0])))) > 0.5f) & iSlow39)) ? 0.0f : fSlow38))) + -1.0f));
			fVec11[0] = fTemp77;
			float 	fTemp78 = (0.5f * fVec11[0]);
			int 	iTemp79 = (fTemp78 > 0.001f);
			int 	iTemp80 = (fTemp78 <= 0.001f);
			float 	fTemp81 = float((iTemp80 | ((0.5f * fVec11[1]) >= 0.001f)));
			fRec43[0] = max((fRec43[1] * fTemp81), fSlow35);
			float 	fTemp82 = min(1.0f, (2.0f * fRec43[0]));
			int 	iTemp83 = (fTemp78 >= fRec41[1]);
			int 	iTemp84 = (fRec41[1] <= 0.001f);
			int 	iTemp85 = (((iRec40[1] >= 4)) ? (((iRec40[1] >= 6)) ? ((iTemp84) ? 0 : ((iTemp79) ? 1 : 6)) : (((iRec40[1] >= 5)) ? ((iTemp80) ? 3 : ((iTemp83) ? 4 : 5)) : ((iTemp80) ? 3 : (((fTemp78 <= fRec41[1])) ? 5 : 4)))) : (((iRec40[1] >= 2)) ? (((iRec40[1] >= 3)) ? (((iTemp80 & iTemp84)) ? 0 : ((iTemp79) ? 1 : 3)) : ((iTemp80) ? 3 : ((iTemp83) ? ((iTemp80) ? 6 : 4) : 2))) : (((iRec40[1] >= 1)) ? (((fRec41[1] >= min(fTemp82, 1.0f))) ? ((iTemp80) ? 6 : 2) : 1) : ((iTemp79) ? 1 : 0))));
			iRec40[0] = iTemp85;
			fRec45[0] = max((fTemp81 * fRec45[1]), fSlow40);
			float 	fTemp86 = (((iTemp85 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec45[0]))) : (((iTemp85 >= 4)) ? (((iTemp85 >= 6)) ? fConst23 : fConst22) : (((iTemp85 >= 2)) ? (((iTemp85 >= 3)) ? fConst21 : fConst20) : (((iTemp85 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp87 = (iRec40[1] != iRec40[2]);
			iVec12[0] = iTemp87;
			int 	iTemp88 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec46[0] = ((iRec46[1] * (1 - iTemp88)) + (iTemp10 * iTemp88));
			float 	fTemp89 = min(19.0f, floorf((21.0f * (((fTemp86 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec46[0]))) / fTemp86) : 1.0f))));
			float 	fTemp90 = min((fTemp89 + 1.0f), 2e+01f);
			float 	fTemp91 = (((fTemp90 >= 11.0f)) ? (((fTemp90 >= 16.0f)) ? (((fTemp90 >= 19.0f)) ? (((fTemp90 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp90 >= 18.0f)) ? 0.03f : (((fTemp90 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp90 >= 14.0f)) ? (((fTemp90 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp90 >= 13.0f)) ? 0.14f : (((fTemp90 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp90 >= 6.0f)) ? (((fTemp90 >= 9.0f)) ? (((fTemp90 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp90 >= 8.0f)) ? 0.3f : (((fTemp90 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp90 >= 3.0f)) ? (((fTemp90 >= 5.0f)) ? 0.47f : (((fTemp90 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp90 >= 2.0f)) ? 0.74f : (((fTemp90 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec47[0] = iRec40[1];
			int 	iTemp92 = (iRec47[1] == iRec40[1]);
			int 	iTemp93 = (iRec40[1] == 0);
			fRec48[0] = ((iTemp93) ? fTemp78 : ((iTemp92) ? min(min(fRec48[1], fTemp78), fRec41[1]) : min(fTemp78, fRec41[1])));
			fRec49[0] = ((iTemp93) ? fTemp78 : ((iTemp92) ? max(max(fRec49[1], fTemp78), fRec41[1]) : max(fTemp78, fRec41[1])));
			int 	iTemp94 = ((iRec40[1] == 3) | (iRec40[1] == 6));
			fbargraph2 = float(iRec40[1]);
			float 	fTemp95 = (((fbargraph2 == 1.0f)) ? min(1.0f, fTemp82) : ((iTemp93) ? 0.0f : ((iTemp94) ? (fRec49[0] * fTemp91) : fTemp78)));
			float 	fTemp96 = (1.0f / ((iTemp93) ? 0.0001f : ((iTemp94) ? (0.05f * (fTemp86 / ((((fTemp89 >= 11.0f)) ? (((fTemp89 >= 16.0f)) ? (((fTemp89 >= 19.0f)) ? (((fTemp89 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp89 >= 18.0f)) ? 0.03f : (((fTemp89 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp89 >= 14.0f)) ? (((fTemp89 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp89 >= 13.0f)) ? 0.14f : (((fTemp89 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp89 >= 6.0f)) ? (((fTemp89 >= 9.0f)) ? (((fTemp89 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp89 >= 8.0f)) ? 0.3f : (((fTemp89 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp89 >= 3.0f)) ? (((fTemp89 >= 5.0f)) ? 0.47f : (((fTemp89 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp89 >= 2.0f)) ? 0.74f : (((fTemp89 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp91))) : fTemp86)));
			float 	fTemp97 = (fRec44[1] - fTemp96);
			float 	fTemp98 = (fRec44[1] + fTemp96);
			fRec44[0] = (((fTemp98 < fTemp95)) ? fTemp98 : (((fTemp97 > fTemp95)) ? fTemp97 : fTemp95));
			fRec41[0] = fRec44[0];
			fRec39[0] = (fRec41[0] - (fConst18 * ((fConst16 * fRec39[2]) + (fConst14 * fRec39[1]))));
			float 	fTemp99 = min(0.99f, (fConst24 * (((3947.8418f * fRec39[0]) + (7895.6836f * fRec39[1])) + (3947.8418f * fRec39[2]))));
			float 	fTemp100 = max(min((3.0f * (fTemp78 - fTemp99)), 0.3f), -0.15f);
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
			float 	fTemp107 = ((iTemp6) ? 0.0f : (fSlow51 + fRec54[1]));
			fRec54[0] = (fTemp107 - floorf(fTemp107));
			int 	iTemp108 = (fSlow49 != fVec13[1]);
			iVec14[0] = iTemp108;
			int 	iTemp109 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec58[0] = ((iRec58[1] * (1 - iTemp109)) + (iTemp10 * iTemp109));
			float 	fTemp110 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec58[0])))) > 0.5f) & iSlow53)) ? 0.0f : fSlow52))) + -1.0f));
			fVec15[0] = fTemp110;
			float 	fTemp111 = (0.5f * fVec15[0]);
			int 	iTemp112 = (fTemp111 > 0.001f);
			int 	iTemp113 = (fTemp111 <= 0.001f);
			float 	fTemp114 = float((iTemp113 | ((0.5f * fVec15[1]) >= 0.001f)));
			fRec59[0] = max((fRec59[1] * fTemp114), fSlow49);
			float 	fTemp115 = min(1.0f, (2.0f * fRec59[0]));
			int 	iTemp116 = (fTemp111 >= fRec57[1]);
			int 	iTemp117 = (fRec57[1] <= 0.001f);
			int 	iTemp118 = (((iRec56[1] >= 4)) ? (((iRec56[1] >= 6)) ? ((iTemp117) ? 0 : ((iTemp112) ? 1 : 6)) : (((iRec56[1] >= 5)) ? ((iTemp113) ? 3 : ((iTemp116) ? 4 : 5)) : ((iTemp113) ? 3 : (((fTemp111 <= fRec57[1])) ? 5 : 4)))) : (((iRec56[1] >= 2)) ? (((iRec56[1] >= 3)) ? (((iTemp113 & iTemp117)) ? 0 : ((iTemp112) ? 1 : 3)) : ((iTemp113) ? 3 : ((iTemp116) ? ((iTemp113) ? 6 : 4) : 2))) : (((iRec56[1] >= 1)) ? (((fRec57[1] >= min(fTemp115, 1.0f))) ? ((iTemp113) ? 6 : 2) : 1) : ((iTemp112) ? 1 : 0))));
			iRec56[0] = iTemp118;
			fRec61[0] = max((fTemp114 * fRec61[1]), fSlow54);
			float 	fTemp119 = (((iTemp118 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec61[0]))) : (((iTemp118 >= 4)) ? (((iTemp118 >= 6)) ? fConst23 : fConst22) : (((iTemp118 >= 2)) ? (((iTemp118 >= 3)) ? fConst21 : fConst20) : (((iTemp118 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp120 = (iRec56[1] != iRec56[2]);
			iVec16[0] = iTemp120;
			int 	iTemp121 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec62[0] = ((iRec62[1] * (1 - iTemp121)) + (iTemp10 * iTemp121));
			float 	fTemp122 = min(19.0f, floorf((21.0f * (((fTemp119 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec62[0]))) / fTemp119) : 1.0f))));
			float 	fTemp123 = min((fTemp122 + 1.0f), 2e+01f);
			float 	fTemp124 = (((fTemp123 >= 11.0f)) ? (((fTemp123 >= 16.0f)) ? (((fTemp123 >= 19.0f)) ? (((fTemp123 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp123 >= 18.0f)) ? 0.03f : (((fTemp123 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp123 >= 14.0f)) ? (((fTemp123 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp123 >= 13.0f)) ? 0.14f : (((fTemp123 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp123 >= 6.0f)) ? (((fTemp123 >= 9.0f)) ? (((fTemp123 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp123 >= 8.0f)) ? 0.3f : (((fTemp123 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp123 >= 3.0f)) ? (((fTemp123 >= 5.0f)) ? 0.47f : (((fTemp123 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp123 >= 2.0f)) ? 0.74f : (((fTemp123 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec63[0] = iRec56[1];
			int 	iTemp125 = (iRec63[1] == iRec56[1]);
			int 	iTemp126 = (iRec56[1] == 0);
			fRec64[0] = ((iTemp126) ? fTemp111 : ((iTemp125) ? min(min(fRec64[1], fTemp111), fRec57[1]) : min(fTemp111, fRec57[1])));
			fRec65[0] = ((iTemp126) ? fTemp111 : ((iTemp125) ? max(max(fRec65[1], fTemp111), fRec57[1]) : max(fTemp111, fRec57[1])));
			int 	iTemp127 = ((iRec56[1] == 3) | (iRec56[1] == 6));
			fbargraph3 = float(iRec56[1]);
			float 	fTemp128 = (((fbargraph3 == 1.0f)) ? min(1.0f, fTemp115) : ((iTemp126) ? 0.0f : ((iTemp127) ? (fRec65[0] * fTemp124) : fTemp111)));
			float 	fTemp129 = (1.0f / ((iTemp126) ? 0.0001f : ((iTemp127) ? (0.05f * (fTemp119 / ((((fTemp122 >= 11.0f)) ? (((fTemp122 >= 16.0f)) ? (((fTemp122 >= 19.0f)) ? (((fTemp122 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp122 >= 18.0f)) ? 0.03f : (((fTemp122 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp122 >= 14.0f)) ? (((fTemp122 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp122 >= 13.0f)) ? 0.14f : (((fTemp122 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp122 >= 6.0f)) ? (((fTemp122 >= 9.0f)) ? (((fTemp122 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp122 >= 8.0f)) ? 0.3f : (((fTemp122 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp122 >= 3.0f)) ? (((fTemp122 >= 5.0f)) ? 0.47f : (((fTemp122 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp122 >= 2.0f)) ? 0.74f : (((fTemp122 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp124))) : fTemp119)));
			float 	fTemp130 = (fRec60[1] - fTemp129);
			float 	fTemp131 = (fRec60[1] + fTemp129);
			fRec60[0] = (((fTemp131 < fTemp128)) ? fTemp131 : (((fTemp130 > fTemp128)) ? fTemp130 : fTemp128));
			fRec57[0] = fRec60[0];
			fRec55[0] = (fRec57[0] - (fConst18 * ((fConst16 * fRec55[2]) + (fConst14 * fRec55[1]))));
			float 	fTemp132 = min(0.99f, (fConst24 * (((3947.8418f * fRec55[0]) + (7895.6836f * fRec55[1])) + (3947.8418f * fRec55[2]))));
			float 	fTemp133 = max(min((3.0f * (fTemp111 - fTemp132)), 0.3f), -0.15f);
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
			float 	fTemp140 = ((iTemp6) ? 0.0f : (fSlow65 + fRec70[1]));
			fRec70[0] = (fTemp140 - floorf(fTemp140));
			int 	iTemp141 = (fSlow63 != fVec17[1]);
			iVec18[0] = iTemp141;
			int 	iTemp142 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec74[0] = ((iRec74[1] * (1 - iTemp142)) + (iTemp10 * iTemp142));
			float 	fTemp143 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec74[0])))) > 0.5f) & iSlow67)) ? 0.0f : fSlow66))) + -1.0f));
			fVec19[0] = fTemp143;
			float 	fTemp144 = (0.5f * fVec19[0]);
			int 	iTemp145 = (fTemp144 > 0.001f);
			int 	iTemp146 = (fTemp144 <= 0.001f);
			float 	fTemp147 = float((iTemp146 | ((0.5f * fVec19[1]) >= 0.001f)));
			fRec75[0] = max((fRec75[1] * fTemp147), fSlow63);
			float 	fTemp148 = min(1.0f, (2.0f * fRec75[0]));
			int 	iTemp149 = (fTemp144 >= fRec73[1]);
			int 	iTemp150 = (fRec73[1] <= 0.001f);
			int 	iTemp151 = (((iRec72[1] >= 4)) ? (((iRec72[1] >= 6)) ? ((iTemp150) ? 0 : ((iTemp145) ? 1 : 6)) : (((iRec72[1] >= 5)) ? ((iTemp146) ? 3 : ((iTemp149) ? 4 : 5)) : ((iTemp146) ? 3 : (((fTemp144 <= fRec73[1])) ? 5 : 4)))) : (((iRec72[1] >= 2)) ? (((iRec72[1] >= 3)) ? (((iTemp146 & iTemp150)) ? 0 : ((iTemp145) ? 1 : 3)) : ((iTemp146) ? 3 : ((iTemp149) ? ((iTemp146) ? 6 : 4) : 2))) : (((iRec72[1] >= 1)) ? (((fRec73[1] >= min(fTemp148, 1.0f))) ? ((iTemp146) ? 6 : 2) : 1) : ((iTemp145) ? 1 : 0))));
			iRec72[0] = iTemp151;
			fRec77[0] = max((fTemp147 * fRec77[1]), fSlow68);
			float 	fTemp152 = (((iTemp151 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec77[0]))) : (((iTemp151 >= 4)) ? (((iTemp151 >= 6)) ? fConst23 : fConst22) : (((iTemp151 >= 2)) ? (((iTemp151 >= 3)) ? fConst21 : fConst20) : (((iTemp151 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp153 = (iRec72[1] != iRec72[2]);
			iVec20[0] = iTemp153;
			int 	iTemp154 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec78[0] = ((iRec78[1] * (1 - iTemp154)) + (iTemp10 * iTemp154));
			float 	fTemp155 = min(19.0f, floorf((21.0f * (((fTemp152 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec78[0]))) / fTemp152) : 1.0f))));
			float 	fTemp156 = min((fTemp155 + 1.0f), 2e+01f);
			float 	fTemp157 = (((fTemp156 >= 11.0f)) ? (((fTemp156 >= 16.0f)) ? (((fTemp156 >= 19.0f)) ? (((fTemp156 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp156 >= 18.0f)) ? 0.03f : (((fTemp156 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp156 >= 14.0f)) ? (((fTemp156 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp156 >= 13.0f)) ? 0.14f : (((fTemp156 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp156 >= 6.0f)) ? (((fTemp156 >= 9.0f)) ? (((fTemp156 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp156 >= 8.0f)) ? 0.3f : (((fTemp156 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp156 >= 3.0f)) ? (((fTemp156 >= 5.0f)) ? 0.47f : (((fTemp156 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp156 >= 2.0f)) ? 0.74f : (((fTemp156 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec79[0] = iRec72[1];
			int 	iTemp158 = (iRec79[1] == iRec72[1]);
			int 	iTemp159 = (iRec72[1] == 0);
			fRec80[0] = ((iTemp159) ? fTemp144 : ((iTemp158) ? min(min(fRec80[1], fTemp144), fRec73[1]) : min(fTemp144, fRec73[1])));
			fRec81[0] = ((iTemp159) ? fTemp144 : ((iTemp158) ? max(max(fRec81[1], fTemp144), fRec73[1]) : max(fTemp144, fRec73[1])));
			int 	iTemp160 = ((iRec72[1] == 3) | (iRec72[1] == 6));
			fbargraph4 = float(iRec72[1]);
			float 	fTemp161 = (((fbargraph4 == 1.0f)) ? min(1.0f, fTemp148) : ((iTemp159) ? 0.0f : ((iTemp160) ? (fRec81[0] * fTemp157) : fTemp144)));
			float 	fTemp162 = (1.0f / ((iTemp159) ? 0.0001f : ((iTemp160) ? (0.05f * (fTemp152 / ((((fTemp155 >= 11.0f)) ? (((fTemp155 >= 16.0f)) ? (((fTemp155 >= 19.0f)) ? (((fTemp155 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp155 >= 18.0f)) ? 0.03f : (((fTemp155 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp155 >= 14.0f)) ? (((fTemp155 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp155 >= 13.0f)) ? 0.14f : (((fTemp155 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp155 >= 6.0f)) ? (((fTemp155 >= 9.0f)) ? (((fTemp155 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp155 >= 8.0f)) ? 0.3f : (((fTemp155 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp155 >= 3.0f)) ? (((fTemp155 >= 5.0f)) ? 0.47f : (((fTemp155 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp155 >= 2.0f)) ? 0.74f : (((fTemp155 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp157))) : fTemp152)));
			float 	fTemp163 = (fRec76[1] - fTemp162);
			float 	fTemp164 = (fRec76[1] + fTemp162);
			fRec76[0] = (((fTemp164 < fTemp161)) ? fTemp164 : (((fTemp163 > fTemp161)) ? fTemp163 : fTemp161));
			fRec73[0] = fRec76[0];
			fRec71[0] = (fRec73[0] - (fConst18 * ((fConst16 * fRec71[2]) + (fConst14 * fRec71[1]))));
			float 	fTemp165 = min(0.99f, (fConst24 * (((3947.8418f * fRec71[0]) + (7895.6836f * fRec71[1])) + (3947.8418f * fRec71[2]))));
			float 	fTemp166 = max(min((3.0f * (fTemp144 - fTemp165)), 0.3f), -0.15f);
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
			float 	fTemp173 = ((iTemp6) ? 0.0f : (fSlow79 + fRec86[1]));
			fRec86[0] = (fTemp173 - floorf(fTemp173));
			int 	iTemp174 = (fSlow77 != fVec21[1]);
			iVec22[0] = iTemp174;
			int 	iTemp175 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp175)) + (iTemp10 * iTemp175));
			float 	fTemp176 = (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec90[0])))) > 0.5f) & iSlow81)) ? 0.0f : fSlow80))) + -1.0f));
			fVec23[0] = fTemp176;
			float 	fTemp177 = (0.5f * fVec23[0]);
			int 	iTemp178 = (fTemp177 > 0.001f);
			int 	iTemp179 = (fTemp177 <= 0.001f);
			float 	fTemp180 = float((iTemp179 | ((0.5f * fVec23[1]) >= 0.001f)));
			fRec91[0] = max((fRec91[1] * fTemp180), fSlow77);
			float 	fTemp181 = min(1.0f, (2.0f * fRec91[0]));
			int 	iTemp182 = (fTemp177 >= fRec89[1]);
			int 	iTemp183 = (fRec89[1] <= 0.001f);
			int 	iTemp184 = (((iRec88[1] >= 4)) ? (((iRec88[1] >= 6)) ? ((iTemp183) ? 0 : ((iTemp178) ? 1 : 6)) : (((iRec88[1] >= 5)) ? ((iTemp179) ? 3 : ((iTemp182) ? 4 : 5)) : ((iTemp179) ? 3 : (((fTemp177 <= fRec89[1])) ? 5 : 4)))) : (((iRec88[1] >= 2)) ? (((iRec88[1] >= 3)) ? (((iTemp179 & iTemp183)) ? 0 : ((iTemp178) ? 1 : 3)) : ((iTemp179) ? 3 : ((iTemp182) ? ((iTemp179) ? 6 : 4) : 2))) : (((iRec88[1] >= 1)) ? (((fRec89[1] >= min(fTemp181, 1.0f))) ? ((iTemp179) ? 6 : 2) : 1) : ((iTemp178) ? 1 : 0))));
			iRec88[0] = iTemp184;
			fRec93[0] = max((fTemp180 * fRec93[1]), fSlow82);
			float 	fTemp185 = (((iTemp184 == 6)) ? (fConst23 * min(1.0f, (2.0f * fRec93[0]))) : (((iTemp184 >= 4)) ? (((iTemp184 >= 6)) ? fConst23 : fConst22) : (((iTemp184 >= 2)) ? (((iTemp184 >= 3)) ? fConst21 : fConst20) : (((iTemp184 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp186 = (iRec88[1] != iRec88[2]);
			iVec24[0] = iTemp186;
			int 	iTemp187 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec94[0] = ((iRec94[1] * (1 - iTemp187)) + (iTemp10 * iTemp187));
			float 	fTemp188 = min(19.0f, floorf((21.0f * (((fTemp185 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec94[0]))) / fTemp185) : 1.0f))));
			float 	fTemp189 = min((fTemp188 + 1.0f), 2e+01f);
			float 	fTemp190 = (((fTemp189 >= 11.0f)) ? (((fTemp189 >= 16.0f)) ? (((fTemp189 >= 19.0f)) ? (((fTemp189 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp189 >= 18.0f)) ? 0.03f : (((fTemp189 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp189 >= 14.0f)) ? (((fTemp189 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp189 >= 13.0f)) ? 0.14f : (((fTemp189 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp189 >= 6.0f)) ? (((fTemp189 >= 9.0f)) ? (((fTemp189 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp189 >= 8.0f)) ? 0.3f : (((fTemp189 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp189 >= 3.0f)) ? (((fTemp189 >= 5.0f)) ? 0.47f : (((fTemp189 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp189 >= 2.0f)) ? 0.74f : (((fTemp189 >= 1.0f)) ? 0.86f : 1.0f)))));
			iRec95[0] = iRec88[1];
			int 	iTemp191 = (iRec95[1] == iRec88[1]);
			int 	iTemp192 = (iRec88[1] == 0);
			fRec96[0] = ((iTemp192) ? fTemp177 : ((iTemp191) ? min(min(fRec96[1], fTemp177), fRec89[1]) : min(fTemp177, fRec89[1])));
			fRec97[0] = ((iTemp192) ? fTemp177 : ((iTemp191) ? max(max(fRec97[1], fTemp177), fRec89[1]) : max(fTemp177, fRec89[1])));
			int 	iTemp193 = ((iRec88[1] == 3) | (iRec88[1] == 6));
			fbargraph5 = float(iRec88[1]);
			float 	fTemp194 = (((fbargraph5 == 1.0f)) ? min(1.0f, fTemp181) : ((iTemp192) ? 0.0f : ((iTemp193) ? (fRec97[0] * fTemp190) : fTemp177)));
			float 	fTemp195 = (1.0f / ((iTemp192) ? 0.0001f : ((iTemp193) ? (0.05f * (fTemp185 / ((((fTemp188 >= 11.0f)) ? (((fTemp188 >= 16.0f)) ? (((fTemp188 >= 19.0f)) ? (((fTemp188 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp188 >= 18.0f)) ? 0.03f : (((fTemp188 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp188 >= 14.0f)) ? (((fTemp188 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp188 >= 13.0f)) ? 0.14f : (((fTemp188 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp188 >= 6.0f)) ? (((fTemp188 >= 9.0f)) ? (((fTemp188 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp188 >= 8.0f)) ? 0.3f : (((fTemp188 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp188 >= 3.0f)) ? (((fTemp188 >= 5.0f)) ? 0.47f : (((fTemp188 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp188 >= 2.0f)) ? 0.74f : (((fTemp188 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp190))) : fTemp185)));
			float 	fTemp196 = (fRec92[1] - fTemp195);
			float 	fTemp197 = (fRec92[1] + fTemp195);
			fRec92[0] = (((fTemp197 < fTemp194)) ? fTemp197 : (((fTemp196 > fTemp194)) ? fTemp196 : fTemp194));
			fRec89[0] = fRec92[0];
			fRec87[0] = (fRec89[0] - (fConst18 * ((fConst16 * fRec87[2]) + (fConst14 * fRec87[1]))));
			float 	fTemp198 = min(0.99f, (fConst24 * (((3947.8418f * fRec87[0]) + (7895.6836f * fRec87[1])) + (3947.8418f * fRec87[2]))));
			float 	fTemp199 = max(min((3.0f * (fTemp177 - fTemp198)), 0.3f), -0.15f);
			fRec0[0] = ((1.37f * ((((((fTemp198 * ((fSlow83 * (((((fRec86[0] < 0.5f)) ? ((4.0f * fRec86[0]) + -1.0f) : ((4.0f * (1.0f - fRec86[0])) + -1.0f)) * (0.75f - fTemp199)) + ((fTemp199 + 0.25f) * ((2.0f * fRec86[0]) + -1.0f)))) + (fSlow78 * (((2.0f * fRec85) + -1.0f) + ((2.0f * fRec83) + -1.0f))))) + (fTemp165 * ((fSlow69 * (((((fRec70[0] < 0.5f)) ? ((4.0f * fRec70[0]) + -1.0f) : ((4.0f * (1.0f - fRec70[0])) + -1.0f)) * (0.75f - fTemp166)) + ((fTemp166 + 0.25f) * ((2.0f * fRec70[0]) + -1.0f)))) + (fSlow64 * (((2.0f * fRec69) + -1.0f) + ((2.0f * fRec67) + -1.0f)))))) + (fTemp132 * ((fSlow55 * (((((fRec54[0] < 0.5f)) ? ((4.0f * fRec54[0]) + -1.0f) : ((4.0f * (1.0f - fRec54[0])) + -1.0f)) * (0.75f - fTemp133)) + ((fTemp133 + 0.25f) * ((2.0f * fRec54[0]) + -1.0f)))) + (fSlow50 * (((2.0f * fRec53) + -1.0f) + ((2.0f * fRec51) + -1.0f)))))) + (fTemp99 * ((fSlow41 * (((((fRec38[0] < 0.5f)) ? ((4.0f * fRec38[0]) + -1.0f) : ((4.0f * (1.0f - fRec38[0])) + -1.0f)) * (0.75f - fTemp100)) + ((fTemp100 + 0.25f) * ((2.0f * fRec38[0]) + -1.0f)))) + (fSlow36 * (((2.0f * fRec37) + -1.0f) + ((2.0f * fRec35) + -1.0f)))))) + (fTemp66 * ((fSlow27 * (((((fRec22[0] < 0.5f)) ? ((4.0f * fRec22[0]) + -1.0f) : ((4.0f * (1.0f - fRec22[0])) + -1.0f)) * (0.75f - fTemp67)) + ((fTemp67 + 0.25f) * ((2.0f * fRec22[0]) + -1.0f)))) + (fSlow22 * (((2.0f * fRec21) + -1.0f) + ((2.0f * fRec19) + -1.0f)))))) + (fTemp33 * ((fSlow13 * (((((fRec5[0] < 0.5f)) ? ((4.0f * fRec5[0]) + -1.0f) : ((4.0f * (1.0f - fRec5[0])) + -1.0f)) * (0.75f - fTemp34)) + ((fTemp34 + 0.25f) * ((2.0f * fRec5[0]) + -1.0f)))) + (fSlow8 * (((2.0f * fRec4) + -1.0f) + ((2.0f * fRec2) + -1.0f))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst25 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec87[2] = fRec87[1]; fRec87[1] = fRec87[0];
			fRec89[1] = fRec89[0];
			fRec92[1] = fRec92[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			iRec95[1] = iRec95[0];
			iRec94[1] = iRec94[0];
			iVec24[1] = iVec24[0];
			fRec93[1] = fRec93[0];
			iRec88[2] = iRec88[1]; iRec88[1] = iRec88[0];
			fRec91[1] = fRec91[0];
			fVec23[1] = fVec23[0];
			iRec90[1] = iRec90[0];
			iVec22[1] = iVec22[0];
			fRec86[1] = fRec86[0];
			fVec21[1] = fVec21[0];
			fRec84[1] = fRec84[0];
			fRec82[1] = fRec82[0];
			fRec71[2] = fRec71[1]; fRec71[1] = fRec71[0];
			fRec73[1] = fRec73[0];
			fRec76[1] = fRec76[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			iRec79[1] = iRec79[0];
			iRec78[1] = iRec78[0];
			iVec20[1] = iVec20[0];
			fRec77[1] = fRec77[0];
			iRec72[2] = iRec72[1]; iRec72[1] = iRec72[0];
			fRec75[1] = fRec75[0];
			fVec19[1] = fVec19[0];
			iRec74[1] = iRec74[0];
			iVec18[1] = iVec18[0];
			fRec70[1] = fRec70[0];
			fVec17[1] = fVec17[0];
			fRec68[1] = fRec68[0];
			fRec66[1] = fRec66[0];
			fRec55[2] = fRec55[1]; fRec55[1] = fRec55[0];
			fRec57[1] = fRec57[0];
			fRec60[1] = fRec60[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			iRec63[1] = iRec63[0];
			iRec62[1] = iRec62[0];
			iVec16[1] = iVec16[0];
			fRec61[1] = fRec61[0];
			iRec56[2] = iRec56[1]; iRec56[1] = iRec56[0];
			fRec59[1] = fRec59[0];
			fVec15[1] = fVec15[0];
			iRec58[1] = iRec58[0];
			iVec14[1] = iVec14[0];
			fRec54[1] = fRec54[0];
			fVec13[1] = fVec13[0];
			fRec52[1] = fRec52[0];
			fRec50[1] = fRec50[0];
			fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
			fRec41[1] = fRec41[0];
			fRec44[1] = fRec44[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			iRec47[1] = iRec47[0];
			iRec46[1] = iRec46[0];
			iVec12[1] = iVec12[0];
			fRec45[1] = fRec45[0];
			iRec40[2] = iRec40[1]; iRec40[1] = iRec40[0];
			fRec43[1] = fRec43[0];
			fVec11[1] = fVec11[0];
			iRec42[1] = iRec42[0];
			iVec10[1] = iVec10[0];
			fRec38[1] = fRec38[0];
			fVec9[1] = fVec9[0];
			fRec36[1] = fRec36[0];
			fRec34[1] = fRec34[0];
			fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
			fRec25[1] = fRec25[0];
			fRec28[1] = fRec28[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			iRec31[1] = iRec31[0];
			iRec30[1] = iRec30[0];
			iVec8[1] = iVec8[0];
			fRec29[1] = fRec29[0];
			iRec24[2] = iRec24[1]; iRec24[1] = iRec24[0];
			fRec27[1] = fRec27[0];
			fVec7[1] = fVec7[0];
			iRec26[1] = iRec26[0];
			iVec6[1] = iVec6[0];
			fRec22[1] = fRec22[0];
			fVec5[1] = fVec5[0];
			fRec20[1] = fRec20[0];
			fRec18[1] = fRec18[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec12[1] = fRec12[0];
			fRec17[1] = fRec17[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
			iRec14[1] = iRec14[0];
			iVec4[1] = iVec4[0];
			fRec13[1] = fRec13[0];
			iRec7[2] = iRec7[1]; iRec7[1] = iRec7[0];
			fRec11[1] = fRec11[0];
			fVec3[1] = fVec3[0];
			iRec9[1] = iRec9[0];
			iRec10[1] = iRec10[0];
			iVec2[1] = iVec2[0];
			fRec5[1] = fRec5[0];
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
