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
	FAUSTFLOAT 	fslider3;
	int 	iRec11[2];
	float 	fRec12[2];
	int 	iRec13[2];
	float 	fRec14[2];
	float 	fRec15[2];
	float 	fRec16[2];
	FAUSTFLOAT 	fbargraph0;
	float 	fRec7[3];
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	float 	fConst23;
	int 	iVec3[2];
	int 	iRec18[2];
	float 	fRec19[2];
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fRec17[2];
	float 	fRec8[2];
	float 	fRec6[3];
	float 	fConst24;
	float 	fConst25;
	float 	fRec22[2];
	FAUSTFLOAT 	fslider4;
	float 	fRec23[2];
	float 	fRec25[2];
	FAUSTFLOAT 	fslider5;
	float 	fVec4[2];
	float 	fRec27[2];
	FAUSTFLOAT 	fslider6;
	int 	iVec5[2];
	int 	iRec31[2];
	FAUSTFLOAT 	fslider7;
	int 	iRec32[2];
	float 	fRec33[2];
	int 	iRec34[2];
	float 	fRec35[2];
	float 	fRec36[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fbargraph1;
	float 	fRec29[3];
	int 	iVec6[2];
	int 	iRec39[2];
	float 	fRec40[2];
	float 	fRec41[2];
	float 	fRec42[2];
	float 	fRec38[2];
	float 	fRec30[2];
	float 	fRec28[3];
	float 	fRec43[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec44[2];
	float 	fRec46[2];
	FAUSTFLOAT 	fslider9;
	float 	fVec7[2];
	float 	fRec48[2];
	FAUSTFLOAT 	fslider10;
	int 	iVec8[2];
	int 	iRec52[2];
	FAUSTFLOAT 	fslider11;
	int 	iRec53[2];
	float 	fRec54[2];
	int 	iRec55[2];
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec58[2];
	FAUSTFLOAT 	fbargraph2;
	float 	fRec50[3];
	int 	iVec9[2];
	int 	iRec60[2];
	float 	fRec61[2];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec59[2];
	float 	fRec51[2];
	float 	fRec49[3];
	float 	fRec64[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec65[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider13;
	float 	fVec10[2];
	float 	fRec69[2];
	FAUSTFLOAT 	fslider14;
	int 	iVec11[2];
	int 	iRec73[2];
	FAUSTFLOAT 	fslider15;
	int 	iRec74[2];
	float 	fRec75[2];
	int 	iRec76[2];
	float 	fRec77[2];
	float 	fRec78[2];
	float 	fRec79[2];
	FAUSTFLOAT 	fbargraph3;
	float 	fRec71[3];
	int 	iVec12[2];
	int 	iRec81[2];
	float 	fRec82[2];
	float 	fRec83[2];
	float 	fRec84[2];
	float 	fRec80[2];
	float 	fRec72[2];
	float 	fRec70[3];
	float 	fRec85[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec86[2];
	float 	fRec88[2];
	FAUSTFLOAT 	fslider17;
	float 	fVec13[2];
	float 	fRec90[2];
	FAUSTFLOAT 	fslider18;
	int 	iVec14[2];
	int 	iRec94[2];
	FAUSTFLOAT 	fslider19;
	int 	iRec95[2];
	float 	fRec96[2];
	int 	iRec97[2];
	float 	fRec98[2];
	float 	fRec99[2];
	float 	fRec100[2];
	FAUSTFLOAT 	fbargraph4;
	float 	fRec92[3];
	int 	iVec15[2];
	int 	iRec102[2];
	float 	fRec103[2];
	float 	fRec104[2];
	float 	fRec105[2];
	float 	fRec101[2];
	float 	fRec93[2];
	float 	fRec91[3];
	float 	fRec106[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec107[2];
	float 	fRec109[2];
	FAUSTFLOAT 	fslider21;
	float 	fVec16[2];
	float 	fRec111[2];
	FAUSTFLOAT 	fslider22;
	int 	iVec17[2];
	int 	iRec115[2];
	FAUSTFLOAT 	fslider23;
	int 	iRec116[2];
	float 	fRec117[2];
	int 	iRec118[2];
	float 	fRec119[2];
	float 	fRec120[2];
	float 	fRec121[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec113[3];
	int 	iVec18[2];
	int 	iRec123[2];
	float 	fRec124[2];
	float 	fRec125[2];
	float 	fRec126[2];
	float 	fRec122[2];
	float 	fRec114[2];
	float 	fRec112[3];
	float 	fRec127[2];
	float 	fRec0[3];
	float 	fConst26;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakholder:author", "Dario Sanfilippo");
		m->declare("basics.lib/peakholder:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("basics.lib/peakholder:license", "MIT-style STK-4.3 license");
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
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.3.0");
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
		fConst10 = (1e+04f / fConst0);
		float 	fConst11 = powf((62.831852f / fConst0),2.0f);
		float 	fConst12 = ((fConst11 * ((0.2033f * fConst11) + 0.31755f)) + 1.0f);
		float 	fConst13 = powf(fConst12,2.0f);
		fConst14 = (2.0f * ((3947.8418f * (fConst13 / fConst1)) + -1.0f));
		float 	fConst15 = (3947.8418f * (fConst12 / fConst0));
		fConst16 = (((fConst12 * (fConst15 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst17 = (((fConst12 * (fConst15 + 88.49557f)) / fConst0) + 1.0f);
		fConst18 = (1.0f / fConst17);
		fConst19 = (0.05f * fConst0);
		fConst20 = (0.2f * fConst0);
		fConst21 = (0.3f * fConst0);
		fConst22 = (0.1f * fConst0);
		fConst23 = (3.0f * fConst0);
		fConst24 = (fConst13 / (fConst1 * fConst17));
		fConst25 = (8.175799f / fConst0);
		fConst26 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec1[i] = 0;
		for (int i=0; i<2; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) iRec11[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<3; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) iVec3[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) iVec5[i] = 0;
		for (int i=0; i<2; i++) iRec31[i] = 0;
		for (int i=0; i<2; i++) iRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) iRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec52[i] = 0;
		for (int i=0; i<2; i++) iRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) iVec9[i] = 0;
		for (int i=0; i<2; i++) iRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) iVec11[i] = 0;
		for (int i=0; i<2; i++) iRec73[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<3; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec94[i] = 0;
		for (int i=0; i<2; i++) iRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<3; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) iVec15[i] = 0;
		for (int i=0; i<2; i++) iRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<3; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) iVec17[i] = 0;
		for (int i=0; i<2; i++) iRec115[i] = 0;
		for (int i=0; i<2; i++) iRec116[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) iRec118[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<3; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec123[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<3; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec127[i] = 0;
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
		synth_interface.vpres[0] = &fslider21;
		synth_interface.but_y[0] = &fslider23;
		synth_interface.note[1] = &fslider16;
		synth_interface.pres[1] = &fslider18;
		synth_interface.vpres[1] = &fslider17;
		synth_interface.but_y[1] = &fslider19;
		synth_interface.note[2] = &fslider12;
		synth_interface.pres[2] = &fslider14;
		synth_interface.vpres[2] = &fslider13;
		synth_interface.but_y[2] = &fslider15;
		synth_interface.note[3] = &fslider8;
		synth_interface.pres[3] = &fslider10;
		synth_interface.vpres[3] = &fslider9;
		synth_interface.but_y[3] = &fslider11;
		synth_interface.note[4] = &fslider4;
		synth_interface.pres[4] = &fslider6;
		synth_interface.vpres[4] = &fslider5;
		synth_interface.but_y[4] = &fslider7;
		synth_interface.note[5] = &fslider0;
		synth_interface.pres[5] = &fslider2;
		synth_interface.vpres[5] = &fslider1;
		synth_interface.but_y[5] = &fslider3;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fastpow2((0.083333336f * float(fslider0)));
		float 	fSlow1 = max(1.1920929e-07f, fabsf((8.152221f * fSlow0)));
		float 	fSlow2 = (fConst9 * fSlow1);
		float 	fSlow3 = (1.0f - (fConst0 / fSlow1));
		float 	fSlow4 = max(1.1920929e-07f, fabsf((8.199446f * fSlow0)));
		float 	fSlow5 = (fConst9 * fSlow4);
		float 	fSlow6 = (1.0f - (fConst0 / fSlow4));
		float 	fSlow7 = float(fslider1);
		float 	fSlow8 = float(fslider2);
		int 	iSlow9 = (fSlow7 == 0.0f);
		float 	fSlow10 = min(float(fslider3), 1.0f);
		float 	fSlow11 = (fConst0 * (((fSlow10 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow12 = fabsf((0.0f - min(0.0f, fSlow10)));
		float 	fSlow13 = (fConst0 * (((fSlow10 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow14 = fabsf(max(0.0f, fSlow10));
		float 	fSlow15 = (fConst25 * fSlow0);
		float 	fSlow16 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow17 = max(1.1920929e-07f, fabsf((8.152221f * fSlow16)));
		float 	fSlow18 = (fConst9 * fSlow17);
		float 	fSlow19 = (1.0f - (fConst0 / fSlow17));
		float 	fSlow20 = max(1.1920929e-07f, fabsf((8.199446f * fSlow16)));
		float 	fSlow21 = (fConst9 * fSlow20);
		float 	fSlow22 = (1.0f - (fConst0 / fSlow20));
		float 	fSlow23 = float(fslider5);
		float 	fSlow24 = float(fslider6);
		int 	iSlow25 = (fSlow23 == 0.0f);
		float 	fSlow26 = min(float(fslider7), 1.0f);
		float 	fSlow27 = (fConst0 * (((fSlow26 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow28 = fabsf((0.0f - min(0.0f, fSlow26)));
		float 	fSlow29 = (fConst0 * (((fSlow26 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow30 = fabsf(max(0.0f, fSlow26));
		float 	fSlow31 = (fConst25 * fSlow16);
		float 	fSlow32 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow33 = max(1.1920929e-07f, fabsf((8.152221f * fSlow32)));
		float 	fSlow34 = (fConst9 * fSlow33);
		float 	fSlow35 = (1.0f - (fConst0 / fSlow33));
		float 	fSlow36 = max(1.1920929e-07f, fabsf((8.199446f * fSlow32)));
		float 	fSlow37 = (fConst9 * fSlow36);
		float 	fSlow38 = (1.0f - (fConst0 / fSlow36));
		float 	fSlow39 = float(fslider9);
		float 	fSlow40 = float(fslider10);
		int 	iSlow41 = (fSlow39 == 0.0f);
		float 	fSlow42 = min(float(fslider11), 1.0f);
		float 	fSlow43 = (fConst0 * (((fSlow42 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow44 = fabsf((0.0f - min(0.0f, fSlow42)));
		float 	fSlow45 = (fConst0 * (((fSlow42 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow46 = fabsf(max(0.0f, fSlow42));
		float 	fSlow47 = (fConst25 * fSlow32);
		float 	fSlow48 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow49 = max(1.1920929e-07f, fabsf((8.152221f * fSlow48)));
		float 	fSlow50 = (fConst9 * fSlow49);
		float 	fSlow51 = (1.0f - (fConst0 / fSlow49));
		float 	fSlow52 = max(1.1920929e-07f, fabsf((8.199446f * fSlow48)));
		float 	fSlow53 = (fConst9 * fSlow52);
		float 	fSlow54 = (1.0f - (fConst0 / fSlow52));
		float 	fSlow55 = float(fslider13);
		float 	fSlow56 = float(fslider14);
		int 	iSlow57 = (fSlow55 == 0.0f);
		float 	fSlow58 = min(float(fslider15), 1.0f);
		float 	fSlow59 = (fConst0 * (((fSlow58 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow60 = fabsf((0.0f - min(0.0f, fSlow58)));
		float 	fSlow61 = (fConst0 * (((fSlow58 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow62 = fabsf(max(0.0f, fSlow58));
		float 	fSlow63 = (fConst25 * fSlow48);
		float 	fSlow64 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow65 = max(1.1920929e-07f, fabsf((8.152221f * fSlow64)));
		float 	fSlow66 = (fConst9 * fSlow65);
		float 	fSlow67 = (1.0f - (fConst0 / fSlow65));
		float 	fSlow68 = max(1.1920929e-07f, fabsf((8.199446f * fSlow64)));
		float 	fSlow69 = (fConst9 * fSlow68);
		float 	fSlow70 = (1.0f - (fConst0 / fSlow68));
		float 	fSlow71 = float(fslider17);
		float 	fSlow72 = float(fslider18);
		int 	iSlow73 = (fSlow71 == 0.0f);
		float 	fSlow74 = min(float(fslider19), 1.0f);
		float 	fSlow75 = (fConst0 * (((fSlow74 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow76 = fabsf((0.0f - min(0.0f, fSlow74)));
		float 	fSlow77 = (fConst0 * (((fSlow74 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow78 = fabsf(max(0.0f, fSlow74));
		float 	fSlow79 = (fConst25 * fSlow64);
		float 	fSlow80 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow81 = max(1.1920929e-07f, fabsf((8.152221f * fSlow80)));
		float 	fSlow82 = (fConst9 * fSlow81);
		float 	fSlow83 = (1.0f - (fConst0 / fSlow81));
		float 	fSlow84 = max(1.1920929e-07f, fabsf((8.199446f * fSlow80)));
		float 	fSlow85 = (fConst9 * fSlow84);
		float 	fSlow86 = (1.0f - (fConst0 / fSlow84));
		float 	fSlow87 = float(fslider21);
		float 	fSlow88 = float(fslider22);
		int 	iSlow89 = (fSlow87 == 0.0f);
		float 	fSlow90 = min(float(fslider23), 1.0f);
		float 	fSlow91 = (fConst0 * (((fSlow90 > 0.1f)) ? 0.0f : 6.0f));
		float 	fSlow92 = fabsf((0.0f - min(0.0f, fSlow90)));
		float 	fSlow93 = (fConst0 * (((fSlow90 < -0.1f)) ? 0.0f : 6.0f));
		float 	fSlow94 = fabsf(max(0.0f, fSlow90));
		float 	fSlow95 = (fConst25 * fSlow80);
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
			float 	fTemp6 = (fRec5[1] - fConst10);
			float 	fTemp7 = (fConst10 + fRec5[1]);
			fRec5[0] = (((fTemp7 < fSlow7)) ? fTemp7 : (((fTemp6 > fSlow7)) ? fTemp6 : fSlow7));
			int 	iTemp8 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp8;
			int 	iTemp9 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec10[0] = (iRec10[1] + 1);
			int 	iTemp10 = (iRec10[0] + -1);
			iRec9[0] = ((iRec9[1] * (1 - iTemp9)) + (iTemp10 * iTemp9));
			float 	fTemp11 = (((((fConst9 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.1f) & iSlow9)) ? 0.0f : fSlow8);
			int 	iTemp12 = ((fSlow12 >= fRec12[1]) | (float(iRec11[1]) >= fSlow11));
			iRec11[0] = ((iTemp12) ? 0 : (iRec11[1] + 1));
			fRec12[0] = ((iTemp12) ? fSlow12 : fRec12[1]);
			int 	iTemp13 = ((fSlow14 >= fRec14[1]) | (float(iRec13[1]) >= fSlow13));
			iRec13[0] = ((iTemp13) ? 0 : (iRec13[1] + 1));
			fRec14[0] = ((iTemp13) ? fSlow14 : fRec14[1]);
			float 	fTemp14 = (((fRec14[0] > fRec12[0])) ? fRec14[0] : (-1.0f * fRec12[0]));
			float 	fTemp15 = fabsf(fTemp14);
			float 	fTemp16 = (1.0f - fTemp15);
			int 	iTemp17 = ((fTemp14 > 0.0f) + (1 - (fTemp14 < 0.0f)));
			int 	iTemp18 = (iTemp17 == 1);
			int 	iTemp19 = (iTemp17 == 0);
			fRec15[0] = fRec7[1];
			fRec16[0] = (((fRec15[1] != fRec7[1])) ? fRec5[0] : max(fRec16[1], fRec5[0]));
			float 	fTemp20 = (fRec16[0] * ((((iTemp19) ? 2.0f : ((iTemp18) ? 1.3f : 0.5f)) * fTemp15) + (1.3f * fTemp16)));
			int 	iTemp21 = (fTemp11 <= 0.01f);
			int 	iTemp22 = (fTemp11 >= fRec8[1]);
			fbargraph0 = float((((fRec7[1] >= 3.0f)) ? (((fRec7[1] >= 5.0f)) ? ((iTemp21) ? 3 : ((iTemp22) ? 4 : 5)) : (((fRec7[1] >= 4.0f)) ? ((iTemp21) ? 3 : (((fTemp11 <= fRec8[1])) ? 5 : 4)) : (((iTemp21 & (fRec8[1] <= 0.001f))) ? 0 : (((fTemp11 > fRec8[1])) ? 1 : 3)))) : (((fRec7[1] >= 2.0f)) ? ((iTemp22) ? 4 : ((iTemp21) ? 3 : 2)) : (((fRec7[1] >= 1.0f)) ? (((fRec8[1] >= fTemp20)) ? 2 : 1) : (((fTemp11 > 0.0f)) ? 1 : 0)))));
			float 	fTemp23 = fbargraph0;
			fRec7[0] = fTemp23;
			int 	iTemp24 = (fTemp23 >= 1.0f);
			float 	fTemp25 = ((iTemp24) ? fConst19 : 0.0f);
			int 	iTemp26 = (fTemp23 >= 2.0f);
			int 	iTemp27 = (fTemp23 >= 4.0f);
			int 	iTemp28 = (fTemp23 >= 5.0f);
			int 	iTemp29 = (fTemp23 >= 3.0f);
			float 	fTemp30 = ((iTemp29) ? ((iTemp28) ? fConst22 : ((iTemp27) ? fConst22 : fConst21)) : ((iTemp26) ? fConst20 : fTemp25));
			float 	fTemp31 = ((fTemp15 * ((iTemp19) ? ((iTemp29) ? ((iTemp28) ? fConst21 : ((iTemp27) ? fConst21 : fConst23)) : ((iTemp26) ? fConst19 : ((iTemp24) ? fConst20 : 0.0f))) : ((iTemp18) ? fTemp30 : ((iTemp29) ? fConst19 : ((iTemp26) ? fConst19 : fTemp25))))) + (fTemp16 * fTemp30));
			int 	iTemp32 = (fRec7[1] != fRec7[2]);
			iVec3[0] = iTemp32;
			int 	iTemp33 = ((iVec3[1] <= 0) & (iVec3[0] > 0));
			iRec18[0] = ((iRec18[1] * (1 - iTemp33)) + (iTemp10 * iTemp33));
			float 	fTemp34 = floorf((2e+01f * (((fTemp31 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec18[0]))) / fTemp31) : 0.0f)));
			float 	fTemp35 = (((fTemp34 >= 1e+01f)) ? (((fTemp34 >= 15.0f)) ? (((fTemp34 >= 18.0f)) ? (((fTemp34 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp34 >= 17.0f)) ? 0.03f : (((fTemp34 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp34 >= 13.0f)) ? (((fTemp34 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp34 >= 12.0f)) ? 0.14f : (((fTemp34 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp34 >= 5.0f)) ? (((fTemp34 >= 8.0f)) ? (((fTemp34 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp34 >= 7.0f)) ? 0.3f : (((fTemp34 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp34 >= 3.0f)) ? (((fTemp34 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp34 >= 2.0f)) ? 0.64f : (((fTemp34 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec19[0] = fRec7[1];
			int 	iTemp36 = (fRec19[1] == fRec7[1]);
			int 	iTemp37 = (fRec7[1] == 0.0f);
			fRec20[0] = ((iTemp37) ? fTemp11 : ((iTemp36) ? min(min(fRec20[1], fTemp11), fRec8[1]) : min(fTemp11, fRec8[1])));
			fRec21[0] = ((iTemp37) ? fTemp11 : ((iTemp36) ? max(max(fRec21[1], fTemp11), fRec8[1]) : max(fTemp11, fRec8[1])));
			int 	iTemp38 = (fRec7[1] == 3.0f);
			float 	fTemp39 = (((fRec7[1] == 1.0f)) ? min(1.0f, fTemp20) : ((iTemp37) ? 0.0f : ((iTemp38) ? (fRec21[0] * fTemp35) : fTemp11)));
			float 	fTemp40 = (fTemp34 + -1.0f);
			float 	fTemp41 = ((((fTemp34 > 0.0f)) ? (((fTemp40 >= 1e+01f)) ? (((fTemp40 >= 15.0f)) ? (((fTemp40 >= 18.0f)) ? (((fTemp40 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp40 >= 17.0f)) ? 0.03f : (((fTemp40 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp40 >= 13.0f)) ? (((fTemp40 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp40 >= 12.0f)) ? 0.14f : (((fTemp40 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp40 >= 5.0f)) ? (((fTemp40 >= 8.0f)) ? (((fTemp40 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp40 >= 7.0f)) ? 0.3f : (((fTemp40 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp40 >= 3.0f)) ? (((fTemp40 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp40 >= 2.0f)) ? 0.64f : (((fTemp40 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp35);
			float 	fTemp42 = (1.0f / ((iTemp37) ? 0.0001f : ((iTemp38) ? (((fTemp41 > 0.0f)) ? (0.05f * (fTemp31 / fTemp41)) : 0.0f) : fTemp31)));
			float 	fTemp43 = (fRec17[1] - fTemp42);
			float 	fTemp44 = (fRec17[1] + fTemp42);
			fRec17[0] = (((fTemp44 < fTemp39)) ? fTemp44 : (((fTemp43 > fTemp39)) ? fTemp43 : fTemp39));
			fRec8[0] = fRec17[0];
			fRec6[0] = (fRec8[0] - (fConst18 * ((fConst16 * fRec6[2]) + (fConst14 * fRec6[1]))));
			float 	fTemp45 = min(0.95f, (fConst24 * (((3947.8418f * fRec6[0]) + (7895.6836f * fRec6[1])) + (3947.8418f * fRec6[2]))));
			int 	iTemp46 = (1 - iVec0[1]);
			float 	fTemp47 = ((iTemp46) ? 0.0f : (fSlow15 + fRec22[1]));
			fRec22[0] = (fTemp47 - floorf(fTemp47));
			float 	fTemp48 = (fSlow18 + (fRec23[1] + -1.0f));
			float 	fTemp49 = (fSlow18 + fRec23[1]);
			int 	iTemp50 = (fTemp48 < 0.0f);
			fRec23[0] = ((iTemp50) ? fTemp49 : fTemp48);
			float 	fRec24 = ((iTemp50) ? fTemp49 : (fSlow18 + (fRec23[1] + (fSlow19 * fTemp48))));
			float 	fTemp51 = (fSlow21 + (fRec25[1] + -1.0f));
			float 	fTemp52 = (fSlow21 + fRec25[1]);
			int 	iTemp53 = (fTemp51 < 0.0f);
			fRec25[0] = ((iTemp53) ? fTemp52 : fTemp51);
			float 	fRec26 = ((iTemp53) ? fTemp52 : (fSlow21 + (fRec25[1] + (fSlow22 * fTemp51))));
			fVec4[0] = fSlow23;
			float 	fTemp54 = (fRec27[1] - fConst10);
			float 	fTemp55 = (fConst10 + fRec27[1]);
			fRec27[0] = (((fTemp55 < fSlow23)) ? fTemp55 : (((fTemp54 > fSlow23)) ? fTemp54 : fSlow23));
			int 	iTemp56 = (fSlow23 != fVec4[1]);
			iVec5[0] = iTemp56;
			int 	iTemp57 = ((iVec5[1] <= 0) & (iVec5[0] > 0));
			iRec31[0] = ((iRec31[1] * (1 - iTemp57)) + (iTemp10 * iTemp57));
			float 	fTemp58 = (((((fConst9 * float((iRec10[0] + (-1 - iRec31[0])))) > 0.1f) & iSlow25)) ? 0.0f : fSlow24);
			int 	iTemp59 = ((fSlow28 >= fRec33[1]) | (float(iRec32[1]) >= fSlow27));
			iRec32[0] = ((iTemp59) ? 0 : (iRec32[1] + 1));
			fRec33[0] = ((iTemp59) ? fSlow28 : fRec33[1]);
			int 	iTemp60 = ((fSlow30 >= fRec35[1]) | (float(iRec34[1]) >= fSlow29));
			iRec34[0] = ((iTemp60) ? 0 : (iRec34[1] + 1));
			fRec35[0] = ((iTemp60) ? fSlow30 : fRec35[1]);
			float 	fTemp61 = (((fRec35[0] > fRec33[0])) ? fRec35[0] : (-1.0f * fRec33[0]));
			float 	fTemp62 = fabsf(fTemp61);
			float 	fTemp63 = (1.0f - fTemp62);
			int 	iTemp64 = ((fTemp61 > 0.0f) + (1 - (fTemp61 < 0.0f)));
			int 	iTemp65 = (iTemp64 == 1);
			int 	iTemp66 = (iTemp64 == 0);
			fRec36[0] = fRec29[1];
			fRec37[0] = (((fRec36[1] != fRec29[1])) ? fRec27[0] : max(fRec37[1], fRec27[0]));
			float 	fTemp67 = (fRec37[0] * ((((iTemp66) ? 2.0f : ((iTemp65) ? 1.3f : 0.5f)) * fTemp62) + (1.3f * fTemp63)));
			int 	iTemp68 = (fTemp58 <= 0.01f);
			int 	iTemp69 = (fTemp58 >= fRec30[1]);
			fbargraph1 = float((((fRec29[1] >= 3.0f)) ? (((fRec29[1] >= 5.0f)) ? ((iTemp68) ? 3 : ((iTemp69) ? 4 : 5)) : (((fRec29[1] >= 4.0f)) ? ((iTemp68) ? 3 : (((fTemp58 <= fRec30[1])) ? 5 : 4)) : (((iTemp68 & (fRec30[1] <= 0.001f))) ? 0 : (((fTemp58 > fRec30[1])) ? 1 : 3)))) : (((fRec29[1] >= 2.0f)) ? ((iTemp69) ? 4 : ((iTemp68) ? 3 : 2)) : (((fRec29[1] >= 1.0f)) ? (((fRec30[1] >= fTemp67)) ? 2 : 1) : (((fTemp58 > 0.0f)) ? 1 : 0)))));
			float 	fTemp70 = fbargraph1;
			fRec29[0] = fTemp70;
			int 	iTemp71 = (fTemp70 >= 1.0f);
			float 	fTemp72 = ((iTemp71) ? fConst19 : 0.0f);
			int 	iTemp73 = (fTemp70 >= 2.0f);
			int 	iTemp74 = (fTemp70 >= 4.0f);
			int 	iTemp75 = (fTemp70 >= 5.0f);
			int 	iTemp76 = (fTemp70 >= 3.0f);
			float 	fTemp77 = ((iTemp76) ? ((iTemp75) ? fConst22 : ((iTemp74) ? fConst22 : fConst21)) : ((iTemp73) ? fConst20 : fTemp72));
			float 	fTemp78 = ((fTemp62 * ((iTemp66) ? ((iTemp76) ? ((iTemp75) ? fConst21 : ((iTemp74) ? fConst21 : fConst23)) : ((iTemp73) ? fConst19 : ((iTemp71) ? fConst20 : 0.0f))) : ((iTemp65) ? fTemp77 : ((iTemp76) ? fConst19 : ((iTemp73) ? fConst19 : fTemp72))))) + (fTemp63 * fTemp77));
			int 	iTemp79 = (fRec29[1] != fRec29[2]);
			iVec6[0] = iTemp79;
			int 	iTemp80 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec39[0] = ((iRec39[1] * (1 - iTemp80)) + (iTemp10 * iTemp80));
			float 	fTemp81 = floorf((2e+01f * (((fTemp78 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec39[0]))) / fTemp78) : 0.0f)));
			float 	fTemp82 = (((fTemp81 >= 1e+01f)) ? (((fTemp81 >= 15.0f)) ? (((fTemp81 >= 18.0f)) ? (((fTemp81 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp81 >= 17.0f)) ? 0.03f : (((fTemp81 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp81 >= 13.0f)) ? (((fTemp81 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp81 >= 12.0f)) ? 0.14f : (((fTemp81 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp81 >= 5.0f)) ? (((fTemp81 >= 8.0f)) ? (((fTemp81 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp81 >= 7.0f)) ? 0.3f : (((fTemp81 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp81 >= 3.0f)) ? (((fTemp81 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp81 >= 2.0f)) ? 0.64f : (((fTemp81 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec40[0] = fRec29[1];
			int 	iTemp83 = (fRec40[1] == fRec29[1]);
			int 	iTemp84 = (fRec29[1] == 0.0f);
			fRec41[0] = ((iTemp84) ? fTemp58 : ((iTemp83) ? min(min(fRec41[1], fTemp58), fRec30[1]) : min(fTemp58, fRec30[1])));
			fRec42[0] = ((iTemp84) ? fTemp58 : ((iTemp83) ? max(max(fRec42[1], fTemp58), fRec30[1]) : max(fTemp58, fRec30[1])));
			int 	iTemp85 = (fRec29[1] == 3.0f);
			float 	fTemp86 = (((fRec29[1] == 1.0f)) ? min(1.0f, fTemp67) : ((iTemp84) ? 0.0f : ((iTemp85) ? (fRec42[0] * fTemp82) : fTemp58)));
			float 	fTemp87 = (fTemp81 + -1.0f);
			float 	fTemp88 = ((((fTemp81 > 0.0f)) ? (((fTemp87 >= 1e+01f)) ? (((fTemp87 >= 15.0f)) ? (((fTemp87 >= 18.0f)) ? (((fTemp87 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp87 >= 17.0f)) ? 0.03f : (((fTemp87 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp87 >= 13.0f)) ? (((fTemp87 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp87 >= 12.0f)) ? 0.14f : (((fTemp87 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp87 >= 5.0f)) ? (((fTemp87 >= 8.0f)) ? (((fTemp87 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp87 >= 7.0f)) ? 0.3f : (((fTemp87 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp87 >= 3.0f)) ? (((fTemp87 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp87 >= 2.0f)) ? 0.64f : (((fTemp87 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp82);
			float 	fTemp89 = (1.0f / ((iTemp84) ? 0.0001f : ((iTemp85) ? (((fTemp88 > 0.0f)) ? (0.05f * (fTemp78 / fTemp88)) : 0.0f) : fTemp78)));
			float 	fTemp90 = (fRec38[1] - fTemp89);
			float 	fTemp91 = (fRec38[1] + fTemp89);
			fRec38[0] = (((fTemp91 < fTemp86)) ? fTemp91 : (((fTemp90 > fTemp86)) ? fTemp90 : fTemp86));
			fRec30[0] = fRec38[0];
			fRec28[0] = (fRec30[0] - (fConst18 * ((fConst16 * fRec28[2]) + (fConst14 * fRec28[1]))));
			float 	fTemp92 = min(0.95f, (fConst24 * (((3947.8418f * fRec28[0]) + (7895.6836f * fRec28[1])) + (3947.8418f * fRec28[2]))));
			float 	fTemp93 = ((iTemp46) ? 0.0f : (fSlow31 + fRec43[1]));
			fRec43[0] = (fTemp93 - floorf(fTemp93));
			float 	fTemp94 = (fSlow34 + (fRec44[1] + -1.0f));
			float 	fTemp95 = (fSlow34 + fRec44[1]);
			int 	iTemp96 = (fTemp94 < 0.0f);
			fRec44[0] = ((iTemp96) ? fTemp95 : fTemp94);
			float 	fRec45 = ((iTemp96) ? fTemp95 : (fSlow34 + (fRec44[1] + (fSlow35 * fTemp94))));
			float 	fTemp97 = (fSlow37 + (fRec46[1] + -1.0f));
			float 	fTemp98 = (fSlow37 + fRec46[1]);
			int 	iTemp99 = (fTemp97 < 0.0f);
			fRec46[0] = ((iTemp99) ? fTemp98 : fTemp97);
			float 	fRec47 = ((iTemp99) ? fTemp98 : (fSlow37 + (fRec46[1] + (fSlow38 * fTemp97))));
			fVec7[0] = fSlow39;
			float 	fTemp100 = (fRec48[1] - fConst10);
			float 	fTemp101 = (fConst10 + fRec48[1]);
			fRec48[0] = (((fTemp101 < fSlow39)) ? fTemp101 : (((fTemp100 > fSlow39)) ? fTemp100 : fSlow39));
			int 	iTemp102 = (fSlow39 != fVec7[1]);
			iVec8[0] = iTemp102;
			int 	iTemp103 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec52[0] = ((iRec52[1] * (1 - iTemp103)) + (iTemp10 * iTemp103));
			float 	fTemp104 = (((((fConst9 * float((iRec10[0] + (-1 - iRec52[0])))) > 0.1f) & iSlow41)) ? 0.0f : fSlow40);
			int 	iTemp105 = ((fSlow44 >= fRec54[1]) | (float(iRec53[1]) >= fSlow43));
			iRec53[0] = ((iTemp105) ? 0 : (iRec53[1] + 1));
			fRec54[0] = ((iTemp105) ? fSlow44 : fRec54[1]);
			int 	iTemp106 = ((fSlow46 >= fRec56[1]) | (float(iRec55[1]) >= fSlow45));
			iRec55[0] = ((iTemp106) ? 0 : (iRec55[1] + 1));
			fRec56[0] = ((iTemp106) ? fSlow46 : fRec56[1]);
			float 	fTemp107 = (((fRec56[0] > fRec54[0])) ? fRec56[0] : (-1.0f * fRec54[0]));
			float 	fTemp108 = fabsf(fTemp107);
			float 	fTemp109 = (1.0f - fTemp108);
			int 	iTemp110 = ((fTemp107 > 0.0f) + (1 - (fTemp107 < 0.0f)));
			int 	iTemp111 = (iTemp110 == 1);
			int 	iTemp112 = (iTemp110 == 0);
			fRec57[0] = fRec50[1];
			fRec58[0] = (((fRec57[1] != fRec50[1])) ? fRec48[0] : max(fRec58[1], fRec48[0]));
			float 	fTemp113 = (fRec58[0] * ((((iTemp112) ? 2.0f : ((iTemp111) ? 1.3f : 0.5f)) * fTemp108) + (1.3f * fTemp109)));
			int 	iTemp114 = (fTemp104 <= 0.01f);
			int 	iTemp115 = (fTemp104 >= fRec51[1]);
			fbargraph2 = float((((fRec50[1] >= 3.0f)) ? (((fRec50[1] >= 5.0f)) ? ((iTemp114) ? 3 : ((iTemp115) ? 4 : 5)) : (((fRec50[1] >= 4.0f)) ? ((iTemp114) ? 3 : (((fTemp104 <= fRec51[1])) ? 5 : 4)) : (((iTemp114 & (fRec51[1] <= 0.001f))) ? 0 : (((fTemp104 > fRec51[1])) ? 1 : 3)))) : (((fRec50[1] >= 2.0f)) ? ((iTemp115) ? 4 : ((iTemp114) ? 3 : 2)) : (((fRec50[1] >= 1.0f)) ? (((fRec51[1] >= fTemp113)) ? 2 : 1) : (((fTemp104 > 0.0f)) ? 1 : 0)))));
			float 	fTemp116 = fbargraph2;
			fRec50[0] = fTemp116;
			int 	iTemp117 = (fTemp116 >= 1.0f);
			float 	fTemp118 = ((iTemp117) ? fConst19 : 0.0f);
			int 	iTemp119 = (fTemp116 >= 2.0f);
			int 	iTemp120 = (fTemp116 >= 4.0f);
			int 	iTemp121 = (fTemp116 >= 5.0f);
			int 	iTemp122 = (fTemp116 >= 3.0f);
			float 	fTemp123 = ((iTemp122) ? ((iTemp121) ? fConst22 : ((iTemp120) ? fConst22 : fConst21)) : ((iTemp119) ? fConst20 : fTemp118));
			float 	fTemp124 = ((fTemp108 * ((iTemp112) ? ((iTemp122) ? ((iTemp121) ? fConst21 : ((iTemp120) ? fConst21 : fConst23)) : ((iTemp119) ? fConst19 : ((iTemp117) ? fConst20 : 0.0f))) : ((iTemp111) ? fTemp123 : ((iTemp122) ? fConst19 : ((iTemp119) ? fConst19 : fTemp118))))) + (fTemp109 * fTemp123));
			int 	iTemp125 = (fRec50[1] != fRec50[2]);
			iVec9[0] = iTemp125;
			int 	iTemp126 = ((iVec9[1] <= 0) & (iVec9[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp126)) + (iTemp10 * iTemp126));
			float 	fTemp127 = floorf((2e+01f * (((fTemp124 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec60[0]))) / fTemp124) : 0.0f)));
			float 	fTemp128 = (((fTemp127 >= 1e+01f)) ? (((fTemp127 >= 15.0f)) ? (((fTemp127 >= 18.0f)) ? (((fTemp127 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp127 >= 17.0f)) ? 0.03f : (((fTemp127 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp127 >= 13.0f)) ? (((fTemp127 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp127 >= 12.0f)) ? 0.14f : (((fTemp127 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp127 >= 5.0f)) ? (((fTemp127 >= 8.0f)) ? (((fTemp127 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp127 >= 7.0f)) ? 0.3f : (((fTemp127 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp127 >= 3.0f)) ? (((fTemp127 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp127 >= 2.0f)) ? 0.64f : (((fTemp127 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec61[0] = fRec50[1];
			int 	iTemp129 = (fRec61[1] == fRec50[1]);
			int 	iTemp130 = (fRec50[1] == 0.0f);
			fRec62[0] = ((iTemp130) ? fTemp104 : ((iTemp129) ? min(min(fRec62[1], fTemp104), fRec51[1]) : min(fTemp104, fRec51[1])));
			fRec63[0] = ((iTemp130) ? fTemp104 : ((iTemp129) ? max(max(fRec63[1], fTemp104), fRec51[1]) : max(fTemp104, fRec51[1])));
			int 	iTemp131 = (fRec50[1] == 3.0f);
			float 	fTemp132 = (((fRec50[1] == 1.0f)) ? min(1.0f, fTemp113) : ((iTemp130) ? 0.0f : ((iTemp131) ? (fRec63[0] * fTemp128) : fTemp104)));
			float 	fTemp133 = (fTemp127 + -1.0f);
			float 	fTemp134 = ((((fTemp127 > 0.0f)) ? (((fTemp133 >= 1e+01f)) ? (((fTemp133 >= 15.0f)) ? (((fTemp133 >= 18.0f)) ? (((fTemp133 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp133 >= 17.0f)) ? 0.03f : (((fTemp133 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp133 >= 13.0f)) ? (((fTemp133 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp133 >= 12.0f)) ? 0.14f : (((fTemp133 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp133 >= 5.0f)) ? (((fTemp133 >= 8.0f)) ? (((fTemp133 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp133 >= 7.0f)) ? 0.3f : (((fTemp133 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp133 >= 3.0f)) ? (((fTemp133 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp133 >= 2.0f)) ? 0.64f : (((fTemp133 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp128);
			float 	fTemp135 = (1.0f / ((iTemp130) ? 0.0001f : ((iTemp131) ? (((fTemp134 > 0.0f)) ? (0.05f * (fTemp124 / fTemp134)) : 0.0f) : fTemp124)));
			float 	fTemp136 = (fRec59[1] - fTemp135);
			float 	fTemp137 = (fRec59[1] + fTemp135);
			fRec59[0] = (((fTemp137 < fTemp132)) ? fTemp137 : (((fTemp136 > fTemp132)) ? fTemp136 : fTemp132));
			fRec51[0] = fRec59[0];
			fRec49[0] = (fRec51[0] - (fConst18 * ((fConst16 * fRec49[2]) + (fConst14 * fRec49[1]))));
			float 	fTemp138 = min(0.95f, (fConst24 * (((3947.8418f * fRec49[0]) + (7895.6836f * fRec49[1])) + (3947.8418f * fRec49[2]))));
			float 	fTemp139 = ((iTemp46) ? 0.0f : (fSlow47 + fRec64[1]));
			fRec64[0] = (fTemp139 - floorf(fTemp139));
			float 	fTemp140 = (fSlow50 + (fRec65[1] + -1.0f));
			float 	fTemp141 = (fSlow50 + fRec65[1]);
			int 	iTemp142 = (fTemp140 < 0.0f);
			fRec65[0] = ((iTemp142) ? fTemp141 : fTemp140);
			float 	fRec66 = ((iTemp142) ? fTemp141 : (fSlow50 + (fRec65[1] + (fSlow51 * fTemp140))));
			float 	fTemp143 = (fSlow53 + (fRec67[1] + -1.0f));
			float 	fTemp144 = (fSlow53 + fRec67[1]);
			int 	iTemp145 = (fTemp143 < 0.0f);
			fRec67[0] = ((iTemp145) ? fTemp144 : fTemp143);
			float 	fRec68 = ((iTemp145) ? fTemp144 : (fSlow53 + (fRec67[1] + (fSlow54 * fTemp143))));
			fVec10[0] = fSlow55;
			float 	fTemp146 = (fRec69[1] - fConst10);
			float 	fTemp147 = (fConst10 + fRec69[1]);
			fRec69[0] = (((fTemp147 < fSlow55)) ? fTemp147 : (((fTemp146 > fSlow55)) ? fTemp146 : fSlow55));
			int 	iTemp148 = (fSlow55 != fVec10[1]);
			iVec11[0] = iTemp148;
			int 	iTemp149 = ((iVec11[1] <= 0) & (iVec11[0] > 0));
			iRec73[0] = ((iRec73[1] * (1 - iTemp149)) + (iTemp10 * iTemp149));
			float 	fTemp150 = (((((fConst9 * float((iRec10[0] + (-1 - iRec73[0])))) > 0.1f) & iSlow57)) ? 0.0f : fSlow56);
			int 	iTemp151 = ((fSlow60 >= fRec75[1]) | (float(iRec74[1]) >= fSlow59));
			iRec74[0] = ((iTemp151) ? 0 : (iRec74[1] + 1));
			fRec75[0] = ((iTemp151) ? fSlow60 : fRec75[1]);
			int 	iTemp152 = ((fSlow62 >= fRec77[1]) | (float(iRec76[1]) >= fSlow61));
			iRec76[0] = ((iTemp152) ? 0 : (iRec76[1] + 1));
			fRec77[0] = ((iTemp152) ? fSlow62 : fRec77[1]);
			float 	fTemp153 = (((fRec77[0] > fRec75[0])) ? fRec77[0] : (-1.0f * fRec75[0]));
			float 	fTemp154 = fabsf(fTemp153);
			float 	fTemp155 = (1.0f - fTemp154);
			int 	iTemp156 = ((fTemp153 > 0.0f) + (1 - (fTemp153 < 0.0f)));
			int 	iTemp157 = (iTemp156 == 1);
			int 	iTemp158 = (iTemp156 == 0);
			fRec78[0] = fRec71[1];
			fRec79[0] = (((fRec78[1] != fRec71[1])) ? fRec69[0] : max(fRec79[1], fRec69[0]));
			float 	fTemp159 = (fRec79[0] * ((((iTemp158) ? 2.0f : ((iTemp157) ? 1.3f : 0.5f)) * fTemp154) + (1.3f * fTemp155)));
			int 	iTemp160 = (fTemp150 <= 0.01f);
			int 	iTemp161 = (fTemp150 >= fRec72[1]);
			fbargraph3 = float((((fRec71[1] >= 3.0f)) ? (((fRec71[1] >= 5.0f)) ? ((iTemp160) ? 3 : ((iTemp161) ? 4 : 5)) : (((fRec71[1] >= 4.0f)) ? ((iTemp160) ? 3 : (((fTemp150 <= fRec72[1])) ? 5 : 4)) : (((iTemp160 & (fRec72[1] <= 0.001f))) ? 0 : (((fTemp150 > fRec72[1])) ? 1 : 3)))) : (((fRec71[1] >= 2.0f)) ? ((iTemp161) ? 4 : ((iTemp160) ? 3 : 2)) : (((fRec71[1] >= 1.0f)) ? (((fRec72[1] >= fTemp159)) ? 2 : 1) : (((fTemp150 > 0.0f)) ? 1 : 0)))));
			float 	fTemp162 = fbargraph3;
			fRec71[0] = fTemp162;
			int 	iTemp163 = (fTemp162 >= 1.0f);
			float 	fTemp164 = ((iTemp163) ? fConst19 : 0.0f);
			int 	iTemp165 = (fTemp162 >= 2.0f);
			int 	iTemp166 = (fTemp162 >= 4.0f);
			int 	iTemp167 = (fTemp162 >= 5.0f);
			int 	iTemp168 = (fTemp162 >= 3.0f);
			float 	fTemp169 = ((iTemp168) ? ((iTemp167) ? fConst22 : ((iTemp166) ? fConst22 : fConst21)) : ((iTemp165) ? fConst20 : fTemp164));
			float 	fTemp170 = ((fTemp154 * ((iTemp158) ? ((iTemp168) ? ((iTemp167) ? fConst21 : ((iTemp166) ? fConst21 : fConst23)) : ((iTemp165) ? fConst19 : ((iTemp163) ? fConst20 : 0.0f))) : ((iTemp157) ? fTemp169 : ((iTemp168) ? fConst19 : ((iTemp165) ? fConst19 : fTemp164))))) + (fTemp155 * fTemp169));
			int 	iTemp171 = (fRec71[1] != fRec71[2]);
			iVec12[0] = iTemp171;
			int 	iTemp172 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec81[0] = ((iRec81[1] * (1 - iTemp172)) + (iTemp10 * iTemp172));
			float 	fTemp173 = floorf((2e+01f * (((fTemp170 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec81[0]))) / fTemp170) : 0.0f)));
			float 	fTemp174 = (((fTemp173 >= 1e+01f)) ? (((fTemp173 >= 15.0f)) ? (((fTemp173 >= 18.0f)) ? (((fTemp173 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp173 >= 17.0f)) ? 0.03f : (((fTemp173 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp173 >= 13.0f)) ? (((fTemp173 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp173 >= 12.0f)) ? 0.14f : (((fTemp173 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp173 >= 5.0f)) ? (((fTemp173 >= 8.0f)) ? (((fTemp173 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp173 >= 7.0f)) ? 0.3f : (((fTemp173 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp173 >= 3.0f)) ? (((fTemp173 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp173 >= 2.0f)) ? 0.64f : (((fTemp173 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec82[0] = fRec71[1];
			int 	iTemp175 = (fRec82[1] == fRec71[1]);
			int 	iTemp176 = (fRec71[1] == 0.0f);
			fRec83[0] = ((iTemp176) ? fTemp150 : ((iTemp175) ? min(min(fRec83[1], fTemp150), fRec72[1]) : min(fTemp150, fRec72[1])));
			fRec84[0] = ((iTemp176) ? fTemp150 : ((iTemp175) ? max(max(fRec84[1], fTemp150), fRec72[1]) : max(fTemp150, fRec72[1])));
			int 	iTemp177 = (fRec71[1] == 3.0f);
			float 	fTemp178 = (((fRec71[1] == 1.0f)) ? min(1.0f, fTemp159) : ((iTemp176) ? 0.0f : ((iTemp177) ? (fRec84[0] * fTemp174) : fTemp150)));
			float 	fTemp179 = (fTemp173 + -1.0f);
			float 	fTemp180 = ((((fTemp173 > 0.0f)) ? (((fTemp179 >= 1e+01f)) ? (((fTemp179 >= 15.0f)) ? (((fTemp179 >= 18.0f)) ? (((fTemp179 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp179 >= 17.0f)) ? 0.03f : (((fTemp179 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp179 >= 13.0f)) ? (((fTemp179 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp179 >= 12.0f)) ? 0.14f : (((fTemp179 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp179 >= 5.0f)) ? (((fTemp179 >= 8.0f)) ? (((fTemp179 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp179 >= 7.0f)) ? 0.3f : (((fTemp179 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp179 >= 3.0f)) ? (((fTemp179 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp179 >= 2.0f)) ? 0.64f : (((fTemp179 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp174);
			float 	fTemp181 = (1.0f / ((iTemp176) ? 0.0001f : ((iTemp177) ? (((fTemp180 > 0.0f)) ? (0.05f * (fTemp170 / fTemp180)) : 0.0f) : fTemp170)));
			float 	fTemp182 = (fRec80[1] - fTemp181);
			float 	fTemp183 = (fRec80[1] + fTemp181);
			fRec80[0] = (((fTemp183 < fTemp178)) ? fTemp183 : (((fTemp182 > fTemp178)) ? fTemp182 : fTemp178));
			fRec72[0] = fRec80[0];
			fRec70[0] = (fRec72[0] - (fConst18 * ((fConst16 * fRec70[2]) + (fConst14 * fRec70[1]))));
			float 	fTemp184 = min(0.95f, (fConst24 * (((3947.8418f * fRec70[0]) + (7895.6836f * fRec70[1])) + (3947.8418f * fRec70[2]))));
			float 	fTemp185 = ((iTemp46) ? 0.0f : (fSlow63 + fRec85[1]));
			fRec85[0] = (fTemp185 - floorf(fTemp185));
			float 	fTemp186 = (fSlow66 + (fRec86[1] + -1.0f));
			float 	fTemp187 = (fSlow66 + fRec86[1]);
			int 	iTemp188 = (fTemp186 < 0.0f);
			fRec86[0] = ((iTemp188) ? fTemp187 : fTemp186);
			float 	fRec87 = ((iTemp188) ? fTemp187 : (fSlow66 + (fRec86[1] + (fSlow67 * fTemp186))));
			float 	fTemp189 = (fSlow69 + (fRec88[1] + -1.0f));
			float 	fTemp190 = (fSlow69 + fRec88[1]);
			int 	iTemp191 = (fTemp189 < 0.0f);
			fRec88[0] = ((iTemp191) ? fTemp190 : fTemp189);
			float 	fRec89 = ((iTemp191) ? fTemp190 : (fSlow69 + (fRec88[1] + (fSlow70 * fTemp189))));
			fVec13[0] = fSlow71;
			float 	fTemp192 = (fRec90[1] - fConst10);
			float 	fTemp193 = (fConst10 + fRec90[1]);
			fRec90[0] = (((fTemp193 < fSlow71)) ? fTemp193 : (((fTemp192 > fSlow71)) ? fTemp192 : fSlow71));
			int 	iTemp194 = (fSlow71 != fVec13[1]);
			iVec14[0] = iTemp194;
			int 	iTemp195 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec94[0] = ((iRec94[1] * (1 - iTemp195)) + (iTemp10 * iTemp195));
			float 	fTemp196 = (((((fConst9 * float((iRec10[0] + (-1 - iRec94[0])))) > 0.1f) & iSlow73)) ? 0.0f : fSlow72);
			int 	iTemp197 = ((fSlow76 >= fRec96[1]) | (float(iRec95[1]) >= fSlow75));
			iRec95[0] = ((iTemp197) ? 0 : (iRec95[1] + 1));
			fRec96[0] = ((iTemp197) ? fSlow76 : fRec96[1]);
			int 	iTemp198 = ((fSlow78 >= fRec98[1]) | (float(iRec97[1]) >= fSlow77));
			iRec97[0] = ((iTemp198) ? 0 : (iRec97[1] + 1));
			fRec98[0] = ((iTemp198) ? fSlow78 : fRec98[1]);
			float 	fTemp199 = (((fRec98[0] > fRec96[0])) ? fRec98[0] : (-1.0f * fRec96[0]));
			float 	fTemp200 = fabsf(fTemp199);
			float 	fTemp201 = (1.0f - fTemp200);
			int 	iTemp202 = ((fTemp199 > 0.0f) + (1 - (fTemp199 < 0.0f)));
			int 	iTemp203 = (iTemp202 == 1);
			int 	iTemp204 = (iTemp202 == 0);
			fRec99[0] = fRec92[1];
			fRec100[0] = (((fRec99[1] != fRec92[1])) ? fRec90[0] : max(fRec100[1], fRec90[0]));
			float 	fTemp205 = (fRec100[0] * ((((iTemp204) ? 2.0f : ((iTemp203) ? 1.3f : 0.5f)) * fTemp200) + (1.3f * fTemp201)));
			int 	iTemp206 = (fTemp196 <= 0.01f);
			int 	iTemp207 = (fTemp196 >= fRec93[1]);
			fbargraph4 = float((((fRec92[1] >= 3.0f)) ? (((fRec92[1] >= 5.0f)) ? ((iTemp206) ? 3 : ((iTemp207) ? 4 : 5)) : (((fRec92[1] >= 4.0f)) ? ((iTemp206) ? 3 : (((fTemp196 <= fRec93[1])) ? 5 : 4)) : (((iTemp206 & (fRec93[1] <= 0.001f))) ? 0 : (((fTemp196 > fRec93[1])) ? 1 : 3)))) : (((fRec92[1] >= 2.0f)) ? ((iTemp207) ? 4 : ((iTemp206) ? 3 : 2)) : (((fRec92[1] >= 1.0f)) ? (((fRec93[1] >= fTemp205)) ? 2 : 1) : (((fTemp196 > 0.0f)) ? 1 : 0)))));
			float 	fTemp208 = fbargraph4;
			fRec92[0] = fTemp208;
			int 	iTemp209 = (fTemp208 >= 1.0f);
			float 	fTemp210 = ((iTemp209) ? fConst19 : 0.0f);
			int 	iTemp211 = (fTemp208 >= 2.0f);
			int 	iTemp212 = (fTemp208 >= 4.0f);
			int 	iTemp213 = (fTemp208 >= 5.0f);
			int 	iTemp214 = (fTemp208 >= 3.0f);
			float 	fTemp215 = ((iTemp214) ? ((iTemp213) ? fConst22 : ((iTemp212) ? fConst22 : fConst21)) : ((iTemp211) ? fConst20 : fTemp210));
			float 	fTemp216 = ((fTemp200 * ((iTemp204) ? ((iTemp214) ? ((iTemp213) ? fConst21 : ((iTemp212) ? fConst21 : fConst23)) : ((iTemp211) ? fConst19 : ((iTemp209) ? fConst20 : 0.0f))) : ((iTemp203) ? fTemp215 : ((iTemp214) ? fConst19 : ((iTemp211) ? fConst19 : fTemp210))))) + (fTemp201 * fTemp215));
			int 	iTemp217 = (fRec92[1] != fRec92[2]);
			iVec15[0] = iTemp217;
			int 	iTemp218 = ((iVec15[1] <= 0) & (iVec15[0] > 0));
			iRec102[0] = ((iRec102[1] * (1 - iTemp218)) + (iTemp10 * iTemp218));
			float 	fTemp219 = floorf((2e+01f * (((fTemp216 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec102[0]))) / fTemp216) : 0.0f)));
			float 	fTemp220 = (((fTemp219 >= 1e+01f)) ? (((fTemp219 >= 15.0f)) ? (((fTemp219 >= 18.0f)) ? (((fTemp219 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp219 >= 17.0f)) ? 0.03f : (((fTemp219 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp219 >= 13.0f)) ? (((fTemp219 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp219 >= 12.0f)) ? 0.14f : (((fTemp219 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp219 >= 5.0f)) ? (((fTemp219 >= 8.0f)) ? (((fTemp219 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp219 >= 7.0f)) ? 0.3f : (((fTemp219 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp219 >= 3.0f)) ? (((fTemp219 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp219 >= 2.0f)) ? 0.64f : (((fTemp219 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec103[0] = fRec92[1];
			int 	iTemp221 = (fRec103[1] == fRec92[1]);
			int 	iTemp222 = (fRec92[1] == 0.0f);
			fRec104[0] = ((iTemp222) ? fTemp196 : ((iTemp221) ? min(min(fRec104[1], fTemp196), fRec93[1]) : min(fTemp196, fRec93[1])));
			fRec105[0] = ((iTemp222) ? fTemp196 : ((iTemp221) ? max(max(fRec105[1], fTemp196), fRec93[1]) : max(fTemp196, fRec93[1])));
			int 	iTemp223 = (fRec92[1] == 3.0f);
			float 	fTemp224 = (((fRec92[1] == 1.0f)) ? min(1.0f, fTemp205) : ((iTemp222) ? 0.0f : ((iTemp223) ? (fRec105[0] * fTemp220) : fTemp196)));
			float 	fTemp225 = (fTemp219 + -1.0f);
			float 	fTemp226 = ((((fTemp219 > 0.0f)) ? (((fTemp225 >= 1e+01f)) ? (((fTemp225 >= 15.0f)) ? (((fTemp225 >= 18.0f)) ? (((fTemp225 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp225 >= 17.0f)) ? 0.03f : (((fTemp225 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp225 >= 13.0f)) ? (((fTemp225 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp225 >= 12.0f)) ? 0.14f : (((fTemp225 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp225 >= 5.0f)) ? (((fTemp225 >= 8.0f)) ? (((fTemp225 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp225 >= 7.0f)) ? 0.3f : (((fTemp225 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp225 >= 3.0f)) ? (((fTemp225 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp225 >= 2.0f)) ? 0.64f : (((fTemp225 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp220);
			float 	fTemp227 = (1.0f / ((iTemp222) ? 0.0001f : ((iTemp223) ? (((fTemp226 > 0.0f)) ? (0.05f * (fTemp216 / fTemp226)) : 0.0f) : fTemp216)));
			float 	fTemp228 = (fRec101[1] - fTemp227);
			float 	fTemp229 = (fRec101[1] + fTemp227);
			fRec101[0] = (((fTemp229 < fTemp224)) ? fTemp229 : (((fTemp228 > fTemp224)) ? fTemp228 : fTemp224));
			fRec93[0] = fRec101[0];
			fRec91[0] = (fRec93[0] - (fConst18 * ((fConst16 * fRec91[2]) + (fConst14 * fRec91[1]))));
			float 	fTemp230 = min(0.95f, (fConst24 * (((3947.8418f * fRec91[0]) + (7895.6836f * fRec91[1])) + (3947.8418f * fRec91[2]))));
			float 	fTemp231 = ((iTemp46) ? 0.0f : (fSlow79 + fRec106[1]));
			fRec106[0] = (fTemp231 - floorf(fTemp231));
			float 	fTemp232 = (fSlow82 + (fRec107[1] + -1.0f));
			float 	fTemp233 = (fSlow82 + fRec107[1]);
			int 	iTemp234 = (fTemp232 < 0.0f);
			fRec107[0] = ((iTemp234) ? fTemp233 : fTemp232);
			float 	fRec108 = ((iTemp234) ? fTemp233 : (fSlow82 + (fRec107[1] + (fSlow83 * fTemp232))));
			float 	fTemp235 = (fSlow85 + (fRec109[1] + -1.0f));
			float 	fTemp236 = (fSlow85 + fRec109[1]);
			int 	iTemp237 = (fTemp235 < 0.0f);
			fRec109[0] = ((iTemp237) ? fTemp236 : fTemp235);
			float 	fRec110 = ((iTemp237) ? fTemp236 : (fSlow85 + (fRec109[1] + (fSlow86 * fTemp235))));
			fVec16[0] = fSlow87;
			float 	fTemp238 = (fRec111[1] - fConst10);
			float 	fTemp239 = (fConst10 + fRec111[1]);
			fRec111[0] = (((fTemp239 < fSlow87)) ? fTemp239 : (((fTemp238 > fSlow87)) ? fTemp238 : fSlow87));
			int 	iTemp240 = (fSlow87 != fVec16[1]);
			iVec17[0] = iTemp240;
			int 	iTemp241 = ((iVec17[1] <= 0) & (iVec17[0] > 0));
			iRec115[0] = ((iRec115[1] * (1 - iTemp241)) + (iTemp10 * iTemp241));
			float 	fTemp242 = (((((fConst9 * float((iRec10[0] + (-1 - iRec115[0])))) > 0.1f) & iSlow89)) ? 0.0f : fSlow88);
			int 	iTemp243 = ((fSlow92 >= fRec117[1]) | (float(iRec116[1]) >= fSlow91));
			iRec116[0] = ((iTemp243) ? 0 : (iRec116[1] + 1));
			fRec117[0] = ((iTemp243) ? fSlow92 : fRec117[1]);
			int 	iTemp244 = ((fSlow94 >= fRec119[1]) | (float(iRec118[1]) >= fSlow93));
			iRec118[0] = ((iTemp244) ? 0 : (iRec118[1] + 1));
			fRec119[0] = ((iTemp244) ? fSlow94 : fRec119[1]);
			float 	fTemp245 = (((fRec119[0] > fRec117[0])) ? fRec119[0] : (-1.0f * fRec117[0]));
			float 	fTemp246 = fabsf(fTemp245);
			float 	fTemp247 = (1.0f - fTemp246);
			int 	iTemp248 = ((fTemp245 > 0.0f) + (1 - (fTemp245 < 0.0f)));
			int 	iTemp249 = (iTemp248 == 1);
			int 	iTemp250 = (iTemp248 == 0);
			fRec120[0] = fRec113[1];
			fRec121[0] = (((fRec120[1] != fRec113[1])) ? fRec111[0] : max(fRec121[1], fRec111[0]));
			float 	fTemp251 = (fRec121[0] * ((((iTemp250) ? 2.0f : ((iTemp249) ? 1.3f : 0.5f)) * fTemp246) + (1.3f * fTemp247)));
			int 	iTemp252 = (fTemp242 <= 0.01f);
			int 	iTemp253 = (fTemp242 >= fRec114[1]);
			fbargraph5 = float((((fRec113[1] >= 3.0f)) ? (((fRec113[1] >= 5.0f)) ? ((iTemp252) ? 3 : ((iTemp253) ? 4 : 5)) : (((fRec113[1] >= 4.0f)) ? ((iTemp252) ? 3 : (((fTemp242 <= fRec114[1])) ? 5 : 4)) : (((iTemp252 & (fRec114[1] <= 0.001f))) ? 0 : (((fTemp242 > fRec114[1])) ? 1 : 3)))) : (((fRec113[1] >= 2.0f)) ? ((iTemp253) ? 4 : ((iTemp252) ? 3 : 2)) : (((fRec113[1] >= 1.0f)) ? (((fRec114[1] >= fTemp251)) ? 2 : 1) : (((fTemp242 > 0.0f)) ? 1 : 0)))));
			float 	fTemp254 = fbargraph5;
			fRec113[0] = fTemp254;
			int 	iTemp255 = (fTemp254 >= 1.0f);
			float 	fTemp256 = ((iTemp255) ? fConst19 : 0.0f);
			int 	iTemp257 = (fTemp254 >= 2.0f);
			int 	iTemp258 = (fTemp254 >= 4.0f);
			int 	iTemp259 = (fTemp254 >= 5.0f);
			int 	iTemp260 = (fTemp254 >= 3.0f);
			float 	fTemp261 = ((iTemp260) ? ((iTemp259) ? fConst22 : ((iTemp258) ? fConst22 : fConst21)) : ((iTemp257) ? fConst20 : fTemp256));
			float 	fTemp262 = ((fTemp246 * ((iTemp250) ? ((iTemp260) ? ((iTemp259) ? fConst21 : ((iTemp258) ? fConst21 : fConst23)) : ((iTemp257) ? fConst19 : ((iTemp255) ? fConst20 : 0.0f))) : ((iTemp249) ? fTemp261 : ((iTemp260) ? fConst19 : ((iTemp257) ? fConst19 : fTemp256))))) + (fTemp247 * fTemp261));
			int 	iTemp263 = (fRec113[1] != fRec113[2]);
			iVec18[0] = iTemp263;
			int 	iTemp264 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec123[0] = ((iRec123[1] * (1 - iTemp264)) + (iTemp10 * iTemp264));
			float 	fTemp265 = floorf((2e+01f * (((fTemp262 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec123[0]))) / fTemp262) : 0.0f)));
			float 	fTemp266 = (((fTemp265 >= 1e+01f)) ? (((fTemp265 >= 15.0f)) ? (((fTemp265 >= 18.0f)) ? (((fTemp265 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp265 >= 17.0f)) ? 0.03f : (((fTemp265 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp265 >= 13.0f)) ? (((fTemp265 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp265 >= 12.0f)) ? 0.14f : (((fTemp265 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp265 >= 5.0f)) ? (((fTemp265 >= 8.0f)) ? (((fTemp265 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp265 >= 7.0f)) ? 0.3f : (((fTemp265 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp265 >= 3.0f)) ? (((fTemp265 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp265 >= 2.0f)) ? 0.64f : (((fTemp265 >= 1.0f)) ? 0.74f : 0.86f)))));
			fRec124[0] = fRec113[1];
			int 	iTemp267 = (fRec124[1] == fRec113[1]);
			int 	iTemp268 = (fRec113[1] == 0.0f);
			fRec125[0] = ((iTemp268) ? fTemp242 : ((iTemp267) ? min(min(fRec125[1], fTemp242), fRec114[1]) : min(fTemp242, fRec114[1])));
			fRec126[0] = ((iTemp268) ? fTemp242 : ((iTemp267) ? max(max(fRec126[1], fTemp242), fRec114[1]) : max(fTemp242, fRec114[1])));
			int 	iTemp269 = (fRec113[1] == 3.0f);
			float 	fTemp270 = (((fRec113[1] == 1.0f)) ? min(1.0f, fTemp251) : ((iTemp268) ? 0.0f : ((iTemp269) ? (fRec126[0] * fTemp266) : fTemp242)));
			float 	fTemp271 = (fTemp265 + -1.0f);
			float 	fTemp272 = ((((fTemp265 > 0.0f)) ? (((fTemp271 >= 1e+01f)) ? (((fTemp271 >= 15.0f)) ? (((fTemp271 >= 18.0f)) ? (((fTemp271 >= 19.0f)) ? 0.0f : 0.01f) : (((fTemp271 >= 17.0f)) ? 0.03f : (((fTemp271 >= 16.0f)) ? 0.06f : 0.08f))) : (((fTemp271 >= 13.0f)) ? (((fTemp271 >= 14.0f)) ? 0.1f : 0.12f) : (((fTemp271 >= 12.0f)) ? 0.14f : (((fTemp271 >= 11.0f)) ? 0.16f : 0.19f)))) : (((fTemp271 >= 5.0f)) ? (((fTemp271 >= 8.0f)) ? (((fTemp271 >= 9.0f)) ? 0.22f : 0.26f) : (((fTemp271 >= 7.0f)) ? 0.3f : (((fTemp271 >= 6.0f)) ? 0.35f : 0.4f))) : (((fTemp271 >= 3.0f)) ? (((fTemp271 >= 4.0f)) ? 0.47f : 0.55f) : (((fTemp271 >= 2.0f)) ? 0.64f : (((fTemp271 >= 1.0f)) ? 0.74f : 0.86f))))) : 1.0f) - fTemp266);
			float 	fTemp273 = (1.0f / ((iTemp268) ? 0.0001f : ((iTemp269) ? (((fTemp272 > 0.0f)) ? (0.05f * (fTemp262 / fTemp272)) : 0.0f) : fTemp262)));
			float 	fTemp274 = (fRec122[1] - fTemp273);
			float 	fTemp275 = (fRec122[1] + fTemp273);
			fRec122[0] = (((fTemp275 < fTemp270)) ? fTemp275 : (((fTemp274 > fTemp270)) ? fTemp274 : fTemp270));
			fRec114[0] = fRec122[0];
			fRec112[0] = (fRec114[0] - (fConst18 * ((fConst16 * fRec112[2]) + (fConst14 * fRec112[1]))));
			float 	fTemp276 = min(0.95f, (fConst24 * (((3947.8418f * fRec112[0]) + (7895.6836f * fRec112[1])) + (3947.8418f * fRec112[2]))));
			float 	fTemp277 = ((iTemp46) ? 0.0f : (fSlow95 + fRec127[1]));
			fRec127[0] = (fTemp277 - floorf(fTemp277));
			fRec0[0] = ((1.37f * ((((((fTemp276 * (((0.8f - (2.0f * fRec111[0])) * (((((fRec127[0] < 0.5f)) ? ((4.0f * fRec127[0]) + -1.0f) : ((4.0f * (1.0f - fRec127[0])) + -1.0f)) * ((fTemp276 + 1.0f) - fSlow88)) + (((2.0f * fRec127[0]) + -1.0f) * (max(min((3.0f * (fSlow88 - fTemp276)), 0.3f), -0.15f) + 0.25f)))) + ((fRec111[0] + 0.1f) * (((2.0f * fRec110) + -1.0f) + ((2.0f * fRec108) + -1.0f))))) + (fTemp230 * (((0.8f - (2.0f * fRec90[0])) * (((((fRec106[0] < 0.5f)) ? ((4.0f * fRec106[0]) + -1.0f) : ((4.0f * (1.0f - fRec106[0])) + -1.0f)) * ((fTemp230 + 1.0f) - fSlow72)) + (((2.0f * fRec106[0]) + -1.0f) * (max(min((3.0f * (fSlow72 - fTemp230)), 0.3f), -0.15f) + 0.25f)))) + ((fRec90[0] + 0.1f) * (((2.0f * fRec89) + -1.0f) + ((2.0f * fRec87) + -1.0f)))))) + (fTemp184 * (((0.8f - (2.0f * fRec69[0])) * (((((fRec85[0] < 0.5f)) ? ((4.0f * fRec85[0]) + -1.0f) : ((4.0f * (1.0f - fRec85[0])) + -1.0f)) * ((fTemp184 + 1.0f) - fSlow56)) + (((2.0f * fRec85[0]) + -1.0f) * (max(min((3.0f * (fSlow56 - fTemp184)), 0.3f), -0.15f) + 0.25f)))) + ((fRec69[0] + 0.1f) * (((2.0f * fRec68) + -1.0f) + ((2.0f * fRec66) + -1.0f)))))) + (fTemp138 * (((0.8f - (2.0f * fRec48[0])) * (((((fRec64[0] < 0.5f)) ? ((4.0f * fRec64[0]) + -1.0f) : ((4.0f * (1.0f - fRec64[0])) + -1.0f)) * ((fTemp138 + 1.0f) - fSlow40)) + (((2.0f * fRec64[0]) + -1.0f) * (max(min((3.0f * (fSlow40 - fTemp138)), 0.3f), -0.15f) + 0.25f)))) + ((fRec48[0] + 0.1f) * (((2.0f * fRec47) + -1.0f) + ((2.0f * fRec45) + -1.0f)))))) + (fTemp92 * (((0.8f - (2.0f * fRec27[0])) * (((((fRec43[0] < 0.5f)) ? ((4.0f * fRec43[0]) + -1.0f) : ((4.0f * (1.0f - fRec43[0])) + -1.0f)) * ((fTemp92 + 1.0f) - fSlow24)) + (((2.0f * fRec43[0]) + -1.0f) * (max(min((3.0f * (fSlow24 - fTemp92)), 0.3f), -0.15f) + 0.25f)))) + ((fRec27[0] + 0.1f) * (((2.0f * fRec26) + -1.0f) + ((2.0f * fRec24) + -1.0f)))))) + (fTemp45 * (((0.8f - (2.0f * fRec5[0])) * (((((fRec22[0] < 0.5f)) ? ((4.0f * fRec22[0]) + -1.0f) : ((4.0f * (1.0f - fRec22[0])) + -1.0f)) * ((fTemp45 + 1.0f) - fSlow8)) + (((2.0f * fRec22[0]) + -1.0f) * (max(min((3.0f * (fSlow8 - fTemp45)), 0.3f), -0.15f) + 0.25f)))) + ((fRec5[0] + 0.1f) * (((2.0f * fRec4) + -1.0f) + ((2.0f * fRec2) + -1.0f))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst26 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec127[1] = fRec127[0];
			fRec112[2] = fRec112[1]; fRec112[1] = fRec112[0];
			fRec114[1] = fRec114[0];
			fRec122[1] = fRec122[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			iRec123[1] = iRec123[0];
			iVec18[1] = iVec18[0];
			fRec113[2] = fRec113[1]; fRec113[1] = fRec113[0];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[1] = fRec119[0];
			iRec118[1] = iRec118[0];
			fRec117[1] = fRec117[0];
			iRec116[1] = iRec116[0];
			iRec115[1] = iRec115[0];
			iVec17[1] = iVec17[0];
			fRec111[1] = fRec111[0];
			fVec16[1] = fVec16[0];
			fRec109[1] = fRec109[0];
			fRec107[1] = fRec107[0];
			fRec106[1] = fRec106[0];
			fRec91[2] = fRec91[1]; fRec91[1] = fRec91[0];
			fRec93[1] = fRec93[0];
			fRec101[1] = fRec101[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			iRec102[1] = iRec102[0];
			iVec15[1] = iVec15[0];
			fRec92[2] = fRec92[1]; fRec92[1] = fRec92[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			iRec97[1] = iRec97[0];
			fRec96[1] = fRec96[0];
			iRec95[1] = iRec95[0];
			iRec94[1] = iRec94[0];
			iVec14[1] = iVec14[0];
			fRec90[1] = fRec90[0];
			fVec13[1] = fVec13[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec85[1] = fRec85[0];
			fRec70[2] = fRec70[1]; fRec70[1] = fRec70[0];
			fRec72[1] = fRec72[0];
			fRec80[1] = fRec80[0];
			fRec84[1] = fRec84[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			iRec81[1] = iRec81[0];
			iVec12[1] = iVec12[0];
			fRec71[2] = fRec71[1]; fRec71[1] = fRec71[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			iRec76[1] = iRec76[0];
			fRec75[1] = fRec75[0];
			iRec74[1] = iRec74[0];
			iRec73[1] = iRec73[0];
			iVec11[1] = iVec11[0];
			fRec69[1] = fRec69[0];
			fVec10[1] = fVec10[0];
			fRec67[1] = fRec67[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
			fRec51[1] = fRec51[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec61[1] = fRec61[0];
			iRec60[1] = iRec60[0];
			iVec9[1] = iVec9[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			iRec55[1] = iRec55[0];
			fRec54[1] = fRec54[0];
			iRec53[1] = iRec53[0];
			iRec52[1] = iRec52[0];
			iVec8[1] = iVec8[0];
			fRec48[1] = fRec48[0];
			fVec7[1] = fVec7[0];
			fRec46[1] = fRec46[0];
			fRec44[1] = fRec44[0];
			fRec43[1] = fRec43[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec30[1] = fRec30[0];
			fRec38[1] = fRec38[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			iRec39[1] = iRec39[0];
			iVec6[1] = iVec6[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			iRec34[1] = iRec34[0];
			fRec33[1] = fRec33[0];
			iRec32[1] = iRec32[0];
			iRec31[1] = iRec31[0];
			iVec5[1] = iVec5[0];
			fRec27[1] = fRec27[0];
			fVec4[1] = fVec4[0];
			fRec25[1] = fRec25[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec17[1] = fRec17[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			iRec18[1] = iRec18[0];
			iVec3[1] = iVec3[0];
			fRec7[2] = fRec7[1]; fRec7[1] = fRec7[0];
			fRec16[1] = fRec16[0];
			fRec15[1] = fRec15[0];
			fRec14[1] = fRec14[0];
			iRec13[1] = iRec13[0];
			fRec12[1] = fRec12[0];
			iRec11[1] = iRec11[0];
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
