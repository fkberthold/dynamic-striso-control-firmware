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
	int 	iRec7[3];
	float 	fConst19;
	float 	fConst20;
	float 	fConst21;
	float 	fConst22;
	int 	iVec3[2];
	int 	iRec12[2];
	FAUSTFLOAT 	fbargraph0;
	float 	fRec11[2];
	float 	fRec8[2];
	float 	fRec6[3];
	float 	fConst23;
	FAUSTFLOAT 	fslider3;
	float 	fRec13[2];
	float 	fRec15[2];
	FAUSTFLOAT 	fslider4;
	float 	fVec4[2];
	float 	fRec17[2];
	FAUSTFLOAT 	fslider5;
	int 	iVec5[2];
	int 	iRec21[2];
	int 	iRec19[3];
	int 	iVec6[2];
	int 	iRec23[2];
	FAUSTFLOAT 	fbargraph1;
	float 	fRec22[2];
	float 	fRec20[2];
	float 	fRec18[3];
	FAUSTFLOAT 	fslider6;
	float 	fRec24[2];
	float 	fRec26[2];
	FAUSTFLOAT 	fslider7;
	float 	fVec7[2];
	float 	fRec28[2];
	FAUSTFLOAT 	fslider8;
	int 	iVec8[2];
	int 	iRec32[2];
	int 	iRec30[3];
	int 	iVec9[2];
	int 	iRec34[2];
	FAUSTFLOAT 	fbargraph2;
	float 	fRec33[2];
	float 	fRec31[2];
	float 	fRec29[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec35[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fslider10;
	float 	fVec10[2];
	float 	fRec39[2];
	FAUSTFLOAT 	fslider11;
	int 	iVec11[2];
	int 	iRec43[2];
	int 	iRec41[3];
	int 	iVec12[2];
	int 	iRec45[2];
	FAUSTFLOAT 	fbargraph3;
	float 	fRec44[2];
	float 	fRec42[2];
	float 	fRec40[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec46[2];
	float 	fRec48[2];
	FAUSTFLOAT 	fslider13;
	float 	fVec13[2];
	float 	fRec50[2];
	FAUSTFLOAT 	fslider14;
	int 	iVec14[2];
	int 	iRec54[2];
	int 	iRec52[3];
	int 	iVec15[2];
	int 	iRec56[2];
	FAUSTFLOAT 	fbargraph4;
	float 	fRec55[2];
	float 	fRec53[2];
	float 	fRec51[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec57[2];
	float 	fRec59[2];
	FAUSTFLOAT 	fslider16;
	float 	fVec16[2];
	float 	fRec61[2];
	FAUSTFLOAT 	fslider17;
	int 	iVec17[2];
	int 	iRec65[2];
	int 	iRec63[3];
	int 	iVec18[2];
	int 	iRec67[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec66[2];
	float 	fRec64[2];
	float 	fRec62[3];
	float 	fRec0[3];
	float 	fConst24;
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
		fConst19 = (0.05f * fConst0);
		fConst20 = (0.2f * fConst0);
		fConst21 = (0.1f * fConst0);
		fConst22 = (4.0f * fConst0);
		fConst23 = (fConst13 / (fConst1 * fConst17));
		fConst24 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<3; i++) iRec7[i] = 0;
		for (int i=0; i<2; i++) iVec3[i] = 0;
		for (int i=0; i<2; i++) iRec12[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) iVec5[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<3; i++) iRec19[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec23[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec32[i] = 0;
		for (int i=0; i<3; i++) iRec30[i] = 0;
		for (int i=0; i<2; i++) iVec9[i] = 0;
		for (int i=0; i<2; i++) iRec34[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fVec10[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) iVec11[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<3; i++) iRec41[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec45[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<3; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<3; i++) iRec52[i] = 0;
		for (int i=0; i<2; i++) iVec15[i] = 0;
		for (int i=0; i<2; i++) iRec56[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<3; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fVec16[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) iVec17[i] = 0;
		for (int i=0; i<2; i++) iRec65[i] = 0;
		for (int i=0; i<3; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec62[i] = 0;
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
		float 	fSlow10 = (0.6f - (2.0f * fSlow7));
		float 	fSlow11 = float(fslider2);
		int 	iSlow12 = (fSlow7 == 0.0f);
		float 	fSlow13 = fastpow2((0.083333336f * float(fslider3)));
		float 	fSlow14 = max(1.1920929e-07f, fabsf((8.067899f * fSlow13)));
		float 	fSlow15 = (fConst9 * fSlow14);
		float 	fSlow16 = (1.0f - (fConst0 / fSlow14));
		float 	fSlow17 = max(1.1920929e-07f, fabsf((8.285142f * fSlow13)));
		float 	fSlow18 = (fConst9 * fSlow17);
		float 	fSlow19 = (1.0f - (fConst0 / fSlow17));
		float 	fSlow20 = float(fslider4);
		float 	fSlow21 = ((0.5f * fSlow20) + 0.2f);
		float 	fSlow22 = (fConst10 * fSlow13);
		float 	fSlow23 = (0.6f - (2.0f * fSlow20));
		float 	fSlow24 = float(fslider5);
		int 	iSlow25 = (fSlow20 == 0.0f);
		float 	fSlow26 = fastpow2((0.083333336f * float(fslider6)));
		float 	fSlow27 = max(1.1920929e-07f, fabsf((8.067899f * fSlow26)));
		float 	fSlow28 = (fConst9 * fSlow27);
		float 	fSlow29 = (1.0f - (fConst0 / fSlow27));
		float 	fSlow30 = max(1.1920929e-07f, fabsf((8.285142f * fSlow26)));
		float 	fSlow31 = (fConst9 * fSlow30);
		float 	fSlow32 = (1.0f - (fConst0 / fSlow30));
		float 	fSlow33 = float(fslider7);
		float 	fSlow34 = ((0.5f * fSlow33) + 0.2f);
		float 	fSlow35 = (fConst10 * fSlow26);
		float 	fSlow36 = (0.6f - (2.0f * fSlow33));
		float 	fSlow37 = float(fslider8);
		int 	iSlow38 = (fSlow33 == 0.0f);
		float 	fSlow39 = fastpow2((0.083333336f * float(fslider9)));
		float 	fSlow40 = max(1.1920929e-07f, fabsf((8.067899f * fSlow39)));
		float 	fSlow41 = (fConst9 * fSlow40);
		float 	fSlow42 = (1.0f - (fConst0 / fSlow40));
		float 	fSlow43 = max(1.1920929e-07f, fabsf((8.285142f * fSlow39)));
		float 	fSlow44 = (fConst9 * fSlow43);
		float 	fSlow45 = (1.0f - (fConst0 / fSlow43));
		float 	fSlow46 = float(fslider10);
		float 	fSlow47 = ((0.5f * fSlow46) + 0.2f);
		float 	fSlow48 = (fConst10 * fSlow39);
		float 	fSlow49 = (0.6f - (2.0f * fSlow46));
		float 	fSlow50 = float(fslider11);
		int 	iSlow51 = (fSlow46 == 0.0f);
		float 	fSlow52 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow53 = max(1.1920929e-07f, fabsf((8.067899f * fSlow52)));
		float 	fSlow54 = (fConst9 * fSlow53);
		float 	fSlow55 = (1.0f - (fConst0 / fSlow53));
		float 	fSlow56 = max(1.1920929e-07f, fabsf((8.285142f * fSlow52)));
		float 	fSlow57 = (fConst9 * fSlow56);
		float 	fSlow58 = (1.0f - (fConst0 / fSlow56));
		float 	fSlow59 = float(fslider13);
		float 	fSlow60 = ((0.5f * fSlow59) + 0.2f);
		float 	fSlow61 = (fConst10 * fSlow52);
		float 	fSlow62 = (0.6f - (2.0f * fSlow59));
		float 	fSlow63 = float(fslider14);
		int 	iSlow64 = (fSlow59 == 0.0f);
		float 	fSlow65 = fastpow2((0.083333336f * float(fslider15)));
		float 	fSlow66 = max(1.1920929e-07f, fabsf((8.067899f * fSlow65)));
		float 	fSlow67 = (fConst9 * fSlow66);
		float 	fSlow68 = (1.0f - (fConst0 / fSlow66));
		float 	fSlow69 = max(1.1920929e-07f, fabsf((8.285142f * fSlow65)));
		float 	fSlow70 = (fConst9 * fSlow69);
		float 	fSlow71 = (1.0f - (fConst0 / fSlow69));
		float 	fSlow72 = float(fslider16);
		float 	fSlow73 = ((0.5f * fSlow72) + 0.2f);
		float 	fSlow74 = (fConst10 * fSlow65);
		float 	fSlow75 = (0.6f - (2.0f * fSlow72));
		float 	fSlow76 = float(fslider17);
		int 	iSlow77 = (fSlow72 == 0.0f);
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
			float 	fTemp11 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.5f) & iSlow12)) ? 0.0f : fSlow11))) + -1.0f)));
			int 	iTemp12 = (fTemp11 > 0.001f);
			int 	iTemp13 = (fTemp11 <= 0.001f);
			int 	iTemp14 = (fTemp11 >= fRec8[1]);
			int 	iTemp15 = (fRec8[1] <= 0.001f);
			int 	iTemp16 = (((iRec7[1] >= 4)) ? (((iRec7[1] >= 6)) ? ((iTemp15) ? 0 : ((iTemp12) ? 1 : 6)) : (((iRec7[1] >= 5)) ? ((iTemp13) ? 3 : ((iTemp14) ? 4 : 5)) : ((iTemp13) ? 3 : (((fTemp11 <= fRec8[1])) ? 5 : 4)))) : (((iRec7[1] >= 2)) ? (((iRec7[1] >= 3)) ? (((iTemp13 & iTemp15)) ? 0 : ((iTemp12) ? 1 : 3)) : ((iTemp13) ? 3 : ((iTemp14) ? ((iTemp13) ? 6 : 4) : 2))) : (((iRec7[1] >= 1)) ? (((fRec8[1] >= 1.0f)) ? ((iTemp13) ? 6 : 2) : 1) : ((iTemp12) ? 1 : 0))));
			iRec7[0] = iTemp16;
			float 	fTemp17 = (((iTemp16 == 6)) ? fConst22 : (((iTemp16 >= 4)) ? (((iTemp16 >= 6)) ? fConst22 : fConst21) : (((iTemp16 >= 2)) ? (((iTemp16 >= 3)) ? fConst19 : fConst20) : (((iTemp16 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp18 = (iRec7[1] != iRec7[2]);
			iVec3[0] = iTemp18;
			int 	iTemp19 = ((iVec3[1] <= 0) & (iVec3[0] > 0));
			iRec12[0] = ((iRec12[1] * (1 - iTemp19)) + (iTemp10 * iTemp19));
			float 	fTemp20 = min(19.0f, floorf((21.0f * (((fTemp17 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec12[0]))) / fTemp17) : 1.0f))));
			float 	fTemp21 = min((fTemp20 + 1.0f), 2e+01f);
			float 	fTemp22 = (((fTemp21 >= 11.0f)) ? (((fTemp21 >= 16.0f)) ? (((fTemp21 >= 19.0f)) ? (((fTemp21 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp21 >= 18.0f)) ? 0.03f : (((fTemp21 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp21 >= 14.0f)) ? (((fTemp21 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp21 >= 13.0f)) ? 0.14f : (((fTemp21 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp21 >= 6.0f)) ? (((fTemp21 >= 9.0f)) ? (((fTemp21 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp21 >= 8.0f)) ? 0.3f : (((fTemp21 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp21 >= 3.0f)) ? (((fTemp21 >= 5.0f)) ? 0.47f : (((fTemp21 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp21 >= 2.0f)) ? 0.74f : (((fTemp21 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp23 = ((iRec7[1] == 3) | (iRec7[1] == 6));
			int 	iTemp24 = (iRec7[1] == 0);
			fbargraph0 = float(iRec7[1]);
			float 	fTemp25 = (((fbargraph0 == 1.0f)) ? 1.0f : ((iTemp24) ? 0.0f : ((iTemp23) ? fTemp22 : fTemp11)));
			float 	fTemp26 = (1.0f / ((iTemp24) ? 0.0001f : ((iTemp23) ? (0.05f * (fTemp17 / ((((fTemp20 >= 11.0f)) ? (((fTemp20 >= 16.0f)) ? (((fTemp20 >= 19.0f)) ? (((fTemp20 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp20 >= 18.0f)) ? 0.03f : (((fTemp20 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp20 >= 14.0f)) ? (((fTemp20 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp20 >= 13.0f)) ? 0.14f : (((fTemp20 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp20 >= 6.0f)) ? (((fTemp20 >= 9.0f)) ? (((fTemp20 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp20 >= 8.0f)) ? 0.3f : (((fTemp20 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp20 >= 3.0f)) ? (((fTemp20 >= 5.0f)) ? 0.47f : (((fTemp20 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp20 >= 2.0f)) ? 0.74f : (((fTemp20 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp22))) : fTemp17)));
			float 	fTemp27 = (fRec11[1] - fTemp26);
			float 	fTemp28 = (fRec11[1] + fTemp26);
			fRec11[0] = (((fTemp28 < fTemp25)) ? fTemp28 : (((fTemp27 > fTemp25)) ? fTemp27 : fTemp25));
			fRec8[0] = fRec11[0];
			fRec6[0] = (fRec8[0] - (fConst18 * ((fConst16 * fRec6[2]) + (fConst14 * fRec6[1]))));
			float 	fTemp29 = (fSlow15 + (fRec13[1] + -1.0f));
			float 	fTemp30 = (fSlow15 + fRec13[1]);
			int 	iTemp31 = (fTemp29 < 0.0f);
			fRec13[0] = ((iTemp31) ? fTemp30 : fTemp29);
			float 	fRec14 = ((iTemp31) ? fTemp30 : (fSlow15 + (fRec13[1] + (fSlow16 * fTemp29))));
			float 	fTemp32 = (fSlow18 + (fRec15[1] + -1.0f));
			float 	fTemp33 = (fSlow18 + fRec15[1]);
			int 	iTemp34 = (fTemp32 < 0.0f);
			fRec15[0] = ((iTemp34) ? fTemp33 : fTemp32);
			float 	fRec16 = ((iTemp34) ? fTemp33 : (fSlow18 + (fRec15[1] + (fSlow19 * fTemp32))));
			fVec4[0] = fSlow20;
			float 	fTemp35 = ((iTemp6) ? 0.0f : (fSlow22 + fRec17[1]));
			fRec17[0] = (fTemp35 - floorf(fTemp35));
			int 	iTemp36 = (fSlow20 != fVec4[1]);
			iVec5[0] = iTemp36;
			int 	iTemp37 = ((iVec5[1] <= 0) & (iVec5[0] > 0));
			iRec21[0] = ((iRec21[1] * (1 - iTemp37)) + (iTemp10 * iTemp37));
			float 	fTemp38 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec21[0])))) > 0.5f) & iSlow25)) ? 0.0f : fSlow24))) + -1.0f)));
			int 	iTemp39 = (fTemp38 > 0.001f);
			int 	iTemp40 = (fTemp38 <= 0.001f);
			int 	iTemp41 = (fTemp38 >= fRec20[1]);
			int 	iTemp42 = (fRec20[1] <= 0.001f);
			int 	iTemp43 = (((iRec19[1] >= 4)) ? (((iRec19[1] >= 6)) ? ((iTemp42) ? 0 : ((iTemp39) ? 1 : 6)) : (((iRec19[1] >= 5)) ? ((iTemp40) ? 3 : ((iTemp41) ? 4 : 5)) : ((iTemp40) ? 3 : (((fTemp38 <= fRec20[1])) ? 5 : 4)))) : (((iRec19[1] >= 2)) ? (((iRec19[1] >= 3)) ? (((iTemp40 & iTemp42)) ? 0 : ((iTemp39) ? 1 : 3)) : ((iTemp40) ? 3 : ((iTemp41) ? ((iTemp40) ? 6 : 4) : 2))) : (((iRec19[1] >= 1)) ? (((fRec20[1] >= 1.0f)) ? ((iTemp40) ? 6 : 2) : 1) : ((iTemp39) ? 1 : 0))));
			iRec19[0] = iTemp43;
			float 	fTemp44 = (((iTemp43 == 6)) ? fConst22 : (((iTemp43 >= 4)) ? (((iTemp43 >= 6)) ? fConst22 : fConst21) : (((iTemp43 >= 2)) ? (((iTemp43 >= 3)) ? fConst19 : fConst20) : (((iTemp43 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp45 = (iRec19[1] != iRec19[2]);
			iVec6[0] = iTemp45;
			int 	iTemp46 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec23[0] = ((iRec23[1] * (1 - iTemp46)) + (iTemp10 * iTemp46));
			float 	fTemp47 = min(19.0f, floorf((21.0f * (((fTemp44 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec23[0]))) / fTemp44) : 1.0f))));
			float 	fTemp48 = min((fTemp47 + 1.0f), 2e+01f);
			float 	fTemp49 = (((fTemp48 >= 11.0f)) ? (((fTemp48 >= 16.0f)) ? (((fTemp48 >= 19.0f)) ? (((fTemp48 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp48 >= 18.0f)) ? 0.03f : (((fTemp48 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp48 >= 14.0f)) ? (((fTemp48 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp48 >= 13.0f)) ? 0.14f : (((fTemp48 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp48 >= 6.0f)) ? (((fTemp48 >= 9.0f)) ? (((fTemp48 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp48 >= 8.0f)) ? 0.3f : (((fTemp48 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp48 >= 3.0f)) ? (((fTemp48 >= 5.0f)) ? 0.47f : (((fTemp48 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp48 >= 2.0f)) ? 0.74f : (((fTemp48 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp50 = ((iRec19[1] == 3) | (iRec19[1] == 6));
			int 	iTemp51 = (iRec19[1] == 0);
			fbargraph1 = float(iRec19[1]);
			float 	fTemp52 = (((fbargraph1 == 1.0f)) ? 1.0f : ((iTemp51) ? 0.0f : ((iTemp50) ? fTemp49 : fTemp38)));
			float 	fTemp53 = (1.0f / ((iTemp51) ? 0.0001f : ((iTemp50) ? (0.05f * (fTemp44 / ((((fTemp47 >= 11.0f)) ? (((fTemp47 >= 16.0f)) ? (((fTemp47 >= 19.0f)) ? (((fTemp47 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp47 >= 18.0f)) ? 0.03f : (((fTemp47 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp47 >= 14.0f)) ? (((fTemp47 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp47 >= 13.0f)) ? 0.14f : (((fTemp47 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp47 >= 6.0f)) ? (((fTemp47 >= 9.0f)) ? (((fTemp47 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp47 >= 8.0f)) ? 0.3f : (((fTemp47 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp47 >= 3.0f)) ? (((fTemp47 >= 5.0f)) ? 0.47f : (((fTemp47 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp47 >= 2.0f)) ? 0.74f : (((fTemp47 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp49))) : fTemp44)));
			float 	fTemp54 = (fRec22[1] - fTemp53);
			float 	fTemp55 = (fRec22[1] + fTemp53);
			fRec22[0] = (((fTemp55 < fTemp52)) ? fTemp55 : (((fTemp54 > fTemp52)) ? fTemp54 : fTemp52));
			fRec20[0] = fRec22[0];
			fRec18[0] = (fRec20[0] - (fConst18 * ((fConst16 * fRec18[2]) + (fConst14 * fRec18[1]))));
			float 	fTemp56 = (fSlow28 + (fRec24[1] + -1.0f));
			float 	fTemp57 = (fSlow28 + fRec24[1]);
			int 	iTemp58 = (fTemp56 < 0.0f);
			fRec24[0] = ((iTemp58) ? fTemp57 : fTemp56);
			float 	fRec25 = ((iTemp58) ? fTemp57 : (fSlow28 + (fRec24[1] + (fSlow29 * fTemp56))));
			float 	fTemp59 = (fSlow31 + (fRec26[1] + -1.0f));
			float 	fTemp60 = (fSlow31 + fRec26[1]);
			int 	iTemp61 = (fTemp59 < 0.0f);
			fRec26[0] = ((iTemp61) ? fTemp60 : fTemp59);
			float 	fRec27 = ((iTemp61) ? fTemp60 : (fSlow31 + (fRec26[1] + (fSlow32 * fTemp59))));
			fVec7[0] = fSlow33;
			float 	fTemp62 = ((iTemp6) ? 0.0f : (fSlow35 + fRec28[1]));
			fRec28[0] = (fTemp62 - floorf(fTemp62));
			int 	iTemp63 = (fSlow33 != fVec7[1]);
			iVec8[0] = iTemp63;
			int 	iTemp64 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp64)) + (iTemp10 * iTemp64));
			float 	fTemp65 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec32[0])))) > 0.5f) & iSlow38)) ? 0.0f : fSlow37))) + -1.0f)));
			int 	iTemp66 = (fTemp65 > 0.001f);
			int 	iTemp67 = (fTemp65 <= 0.001f);
			int 	iTemp68 = (fTemp65 >= fRec31[1]);
			int 	iTemp69 = (fRec31[1] <= 0.001f);
			int 	iTemp70 = (((iRec30[1] >= 4)) ? (((iRec30[1] >= 6)) ? ((iTemp69) ? 0 : ((iTemp66) ? 1 : 6)) : (((iRec30[1] >= 5)) ? ((iTemp67) ? 3 : ((iTemp68) ? 4 : 5)) : ((iTemp67) ? 3 : (((fTemp65 <= fRec31[1])) ? 5 : 4)))) : (((iRec30[1] >= 2)) ? (((iRec30[1] >= 3)) ? (((iTemp67 & iTemp69)) ? 0 : ((iTemp66) ? 1 : 3)) : ((iTemp67) ? 3 : ((iTemp68) ? ((iTemp67) ? 6 : 4) : 2))) : (((iRec30[1] >= 1)) ? (((fRec31[1] >= 1.0f)) ? ((iTemp67) ? 6 : 2) : 1) : ((iTemp66) ? 1 : 0))));
			iRec30[0] = iTemp70;
			float 	fTemp71 = (((iTemp70 == 6)) ? fConst22 : (((iTemp70 >= 4)) ? (((iTemp70 >= 6)) ? fConst22 : fConst21) : (((iTemp70 >= 2)) ? (((iTemp70 >= 3)) ? fConst19 : fConst20) : (((iTemp70 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp72 = (iRec30[1] != iRec30[2]);
			iVec9[0] = iTemp72;
			int 	iTemp73 = ((iVec9[1] <= 0) & (iVec9[0] > 0));
			iRec34[0] = ((iRec34[1] * (1 - iTemp73)) + (iTemp10 * iTemp73));
			float 	fTemp74 = min(19.0f, floorf((21.0f * (((fTemp71 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec34[0]))) / fTemp71) : 1.0f))));
			float 	fTemp75 = min((fTemp74 + 1.0f), 2e+01f);
			float 	fTemp76 = (((fTemp75 >= 11.0f)) ? (((fTemp75 >= 16.0f)) ? (((fTemp75 >= 19.0f)) ? (((fTemp75 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp75 >= 18.0f)) ? 0.03f : (((fTemp75 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp75 >= 14.0f)) ? (((fTemp75 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp75 >= 13.0f)) ? 0.14f : (((fTemp75 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp75 >= 6.0f)) ? (((fTemp75 >= 9.0f)) ? (((fTemp75 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp75 >= 8.0f)) ? 0.3f : (((fTemp75 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp75 >= 3.0f)) ? (((fTemp75 >= 5.0f)) ? 0.47f : (((fTemp75 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp75 >= 2.0f)) ? 0.74f : (((fTemp75 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp77 = ((iRec30[1] == 3) | (iRec30[1] == 6));
			int 	iTemp78 = (iRec30[1] == 0);
			fbargraph2 = float(iRec30[1]);
			float 	fTemp79 = (((fbargraph2 == 1.0f)) ? 1.0f : ((iTemp78) ? 0.0f : ((iTemp77) ? fTemp76 : fTemp65)));
			float 	fTemp80 = (1.0f / ((iTemp78) ? 0.0001f : ((iTemp77) ? (0.05f * (fTemp71 / ((((fTemp74 >= 11.0f)) ? (((fTemp74 >= 16.0f)) ? (((fTemp74 >= 19.0f)) ? (((fTemp74 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp74 >= 18.0f)) ? 0.03f : (((fTemp74 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp74 >= 14.0f)) ? (((fTemp74 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp74 >= 13.0f)) ? 0.14f : (((fTemp74 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp74 >= 6.0f)) ? (((fTemp74 >= 9.0f)) ? (((fTemp74 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp74 >= 8.0f)) ? 0.3f : (((fTemp74 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp74 >= 3.0f)) ? (((fTemp74 >= 5.0f)) ? 0.47f : (((fTemp74 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp74 >= 2.0f)) ? 0.74f : (((fTemp74 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp76))) : fTemp71)));
			float 	fTemp81 = (fRec33[1] - fTemp80);
			float 	fTemp82 = (fRec33[1] + fTemp80);
			fRec33[0] = (((fTemp82 < fTemp79)) ? fTemp82 : (((fTemp81 > fTemp79)) ? fTemp81 : fTemp79));
			fRec31[0] = fRec33[0];
			fRec29[0] = (fRec31[0] - (fConst18 * ((fConst16 * fRec29[2]) + (fConst14 * fRec29[1]))));
			float 	fTemp83 = (fSlow41 + (fRec35[1] + -1.0f));
			float 	fTemp84 = (fSlow41 + fRec35[1]);
			int 	iTemp85 = (fTemp83 < 0.0f);
			fRec35[0] = ((iTemp85) ? fTemp84 : fTemp83);
			float 	fRec36 = ((iTemp85) ? fTemp84 : (fSlow41 + (fRec35[1] + (fSlow42 * fTemp83))));
			float 	fTemp86 = (fSlow44 + (fRec37[1] + -1.0f));
			float 	fTemp87 = (fSlow44 + fRec37[1]);
			int 	iTemp88 = (fTemp86 < 0.0f);
			fRec37[0] = ((iTemp88) ? fTemp87 : fTemp86);
			float 	fRec38 = ((iTemp88) ? fTemp87 : (fSlow44 + (fRec37[1] + (fSlow45 * fTemp86))));
			fVec10[0] = fSlow46;
			float 	fTemp89 = ((iTemp6) ? 0.0f : (fSlow48 + fRec39[1]));
			fRec39[0] = (fTemp89 - floorf(fTemp89));
			int 	iTemp90 = (fSlow46 != fVec10[1]);
			iVec11[0] = iTemp90;
			int 	iTemp91 = ((iVec11[1] <= 0) & (iVec11[0] > 0));
			iRec43[0] = ((iRec43[1] * (1 - iTemp91)) + (iTemp10 * iTemp91));
			float 	fTemp92 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec43[0])))) > 0.5f) & iSlow51)) ? 0.0f : fSlow50))) + -1.0f)));
			int 	iTemp93 = (fTemp92 > 0.001f);
			int 	iTemp94 = (fTemp92 <= 0.001f);
			int 	iTemp95 = (fTemp92 >= fRec42[1]);
			int 	iTemp96 = (fRec42[1] <= 0.001f);
			int 	iTemp97 = (((iRec41[1] >= 4)) ? (((iRec41[1] >= 6)) ? ((iTemp96) ? 0 : ((iTemp93) ? 1 : 6)) : (((iRec41[1] >= 5)) ? ((iTemp94) ? 3 : ((iTemp95) ? 4 : 5)) : ((iTemp94) ? 3 : (((fTemp92 <= fRec42[1])) ? 5 : 4)))) : (((iRec41[1] >= 2)) ? (((iRec41[1] >= 3)) ? (((iTemp94 & iTemp96)) ? 0 : ((iTemp93) ? 1 : 3)) : ((iTemp94) ? 3 : ((iTemp95) ? ((iTemp94) ? 6 : 4) : 2))) : (((iRec41[1] >= 1)) ? (((fRec42[1] >= 1.0f)) ? ((iTemp94) ? 6 : 2) : 1) : ((iTemp93) ? 1 : 0))));
			iRec41[0] = iTemp97;
			float 	fTemp98 = (((iTemp97 == 6)) ? fConst22 : (((iTemp97 >= 4)) ? (((iTemp97 >= 6)) ? fConst22 : fConst21) : (((iTemp97 >= 2)) ? (((iTemp97 >= 3)) ? fConst19 : fConst20) : (((iTemp97 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp99 = (iRec41[1] != iRec41[2]);
			iVec12[0] = iTemp99;
			int 	iTemp100 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec45[0] = ((iRec45[1] * (1 - iTemp100)) + (iTemp10 * iTemp100));
			float 	fTemp101 = min(19.0f, floorf((21.0f * (((fTemp98 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec45[0]))) / fTemp98) : 1.0f))));
			float 	fTemp102 = min((fTemp101 + 1.0f), 2e+01f);
			float 	fTemp103 = (((fTemp102 >= 11.0f)) ? (((fTemp102 >= 16.0f)) ? (((fTemp102 >= 19.0f)) ? (((fTemp102 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp102 >= 18.0f)) ? 0.03f : (((fTemp102 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp102 >= 14.0f)) ? (((fTemp102 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp102 >= 13.0f)) ? 0.14f : (((fTemp102 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp102 >= 6.0f)) ? (((fTemp102 >= 9.0f)) ? (((fTemp102 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp102 >= 8.0f)) ? 0.3f : (((fTemp102 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp102 >= 3.0f)) ? (((fTemp102 >= 5.0f)) ? 0.47f : (((fTemp102 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp102 >= 2.0f)) ? 0.74f : (((fTemp102 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp104 = ((iRec41[1] == 3) | (iRec41[1] == 6));
			int 	iTemp105 = (iRec41[1] == 0);
			fbargraph3 = float(iRec41[1]);
			float 	fTemp106 = (((fbargraph3 == 1.0f)) ? 1.0f : ((iTemp105) ? 0.0f : ((iTemp104) ? fTemp103 : fTemp92)));
			float 	fTemp107 = (1.0f / ((iTemp105) ? 0.0001f : ((iTemp104) ? (0.05f * (fTemp98 / ((((fTemp101 >= 11.0f)) ? (((fTemp101 >= 16.0f)) ? (((fTemp101 >= 19.0f)) ? (((fTemp101 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp101 >= 18.0f)) ? 0.03f : (((fTemp101 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp101 >= 14.0f)) ? (((fTemp101 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp101 >= 13.0f)) ? 0.14f : (((fTemp101 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp101 >= 6.0f)) ? (((fTemp101 >= 9.0f)) ? (((fTemp101 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp101 >= 8.0f)) ? 0.3f : (((fTemp101 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp101 >= 3.0f)) ? (((fTemp101 >= 5.0f)) ? 0.47f : (((fTemp101 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp101 >= 2.0f)) ? 0.74f : (((fTemp101 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp103))) : fTemp98)));
			float 	fTemp108 = (fRec44[1] - fTemp107);
			float 	fTemp109 = (fRec44[1] + fTemp107);
			fRec44[0] = (((fTemp109 < fTemp106)) ? fTemp109 : (((fTemp108 > fTemp106)) ? fTemp108 : fTemp106));
			fRec42[0] = fRec44[0];
			fRec40[0] = (fRec42[0] - (fConst18 * ((fConst16 * fRec40[2]) + (fConst14 * fRec40[1]))));
			float 	fTemp110 = (fSlow54 + (fRec46[1] + -1.0f));
			float 	fTemp111 = (fSlow54 + fRec46[1]);
			int 	iTemp112 = (fTemp110 < 0.0f);
			fRec46[0] = ((iTemp112) ? fTemp111 : fTemp110);
			float 	fRec47 = ((iTemp112) ? fTemp111 : (fSlow54 + (fRec46[1] + (fSlow55 * fTemp110))));
			float 	fTemp113 = (fSlow57 + (fRec48[1] + -1.0f));
			float 	fTemp114 = (fSlow57 + fRec48[1]);
			int 	iTemp115 = (fTemp113 < 0.0f);
			fRec48[0] = ((iTemp115) ? fTemp114 : fTemp113);
			float 	fRec49 = ((iTemp115) ? fTemp114 : (fSlow57 + (fRec48[1] + (fSlow58 * fTemp113))));
			fVec13[0] = fSlow59;
			float 	fTemp116 = ((iTemp6) ? 0.0f : (fSlow61 + fRec50[1]));
			fRec50[0] = (fTemp116 - floorf(fTemp116));
			int 	iTemp117 = (fSlow59 != fVec13[1]);
			iVec14[0] = iTemp117;
			int 	iTemp118 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec54[0] = ((iRec54[1] * (1 - iTemp118)) + (iTemp10 * iTemp118));
			float 	fTemp119 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec54[0])))) > 0.5f) & iSlow64)) ? 0.0f : fSlow63))) + -1.0f)));
			int 	iTemp120 = (fTemp119 > 0.001f);
			int 	iTemp121 = (fTemp119 <= 0.001f);
			int 	iTemp122 = (fTemp119 >= fRec53[1]);
			int 	iTemp123 = (fRec53[1] <= 0.001f);
			int 	iTemp124 = (((iRec52[1] >= 4)) ? (((iRec52[1] >= 6)) ? ((iTemp123) ? 0 : ((iTemp120) ? 1 : 6)) : (((iRec52[1] >= 5)) ? ((iTemp121) ? 3 : ((iTemp122) ? 4 : 5)) : ((iTemp121) ? 3 : (((fTemp119 <= fRec53[1])) ? 5 : 4)))) : (((iRec52[1] >= 2)) ? (((iRec52[1] >= 3)) ? (((iTemp121 & iTemp123)) ? 0 : ((iTemp120) ? 1 : 3)) : ((iTemp121) ? 3 : ((iTemp122) ? ((iTemp121) ? 6 : 4) : 2))) : (((iRec52[1] >= 1)) ? (((fRec53[1] >= 1.0f)) ? ((iTemp121) ? 6 : 2) : 1) : ((iTemp120) ? 1 : 0))));
			iRec52[0] = iTemp124;
			float 	fTemp125 = (((iTemp124 == 6)) ? fConst22 : (((iTemp124 >= 4)) ? (((iTemp124 >= 6)) ? fConst22 : fConst21) : (((iTemp124 >= 2)) ? (((iTemp124 >= 3)) ? fConst19 : fConst20) : (((iTemp124 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp126 = (iRec52[1] != iRec52[2]);
			iVec15[0] = iTemp126;
			int 	iTemp127 = ((iVec15[1] <= 0) & (iVec15[0] > 0));
			iRec56[0] = ((iRec56[1] * (1 - iTemp127)) + (iTemp10 * iTemp127));
			float 	fTemp128 = min(19.0f, floorf((21.0f * (((fTemp125 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec56[0]))) / fTemp125) : 1.0f))));
			float 	fTemp129 = min((fTemp128 + 1.0f), 2e+01f);
			float 	fTemp130 = (((fTemp129 >= 11.0f)) ? (((fTemp129 >= 16.0f)) ? (((fTemp129 >= 19.0f)) ? (((fTemp129 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp129 >= 18.0f)) ? 0.03f : (((fTemp129 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp129 >= 14.0f)) ? (((fTemp129 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp129 >= 13.0f)) ? 0.14f : (((fTemp129 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp129 >= 6.0f)) ? (((fTemp129 >= 9.0f)) ? (((fTemp129 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp129 >= 8.0f)) ? 0.3f : (((fTemp129 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp129 >= 3.0f)) ? (((fTemp129 >= 5.0f)) ? 0.47f : (((fTemp129 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp129 >= 2.0f)) ? 0.74f : (((fTemp129 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp131 = ((iRec52[1] == 3) | (iRec52[1] == 6));
			int 	iTemp132 = (iRec52[1] == 0);
			fbargraph4 = float(iRec52[1]);
			float 	fTemp133 = (((fbargraph4 == 1.0f)) ? 1.0f : ((iTemp132) ? 0.0f : ((iTemp131) ? fTemp130 : fTemp119)));
			float 	fTemp134 = (1.0f / ((iTemp132) ? 0.0001f : ((iTemp131) ? (0.05f * (fTemp125 / ((((fTemp128 >= 11.0f)) ? (((fTemp128 >= 16.0f)) ? (((fTemp128 >= 19.0f)) ? (((fTemp128 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp128 >= 18.0f)) ? 0.03f : (((fTemp128 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp128 >= 14.0f)) ? (((fTemp128 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp128 >= 13.0f)) ? 0.14f : (((fTemp128 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp128 >= 6.0f)) ? (((fTemp128 >= 9.0f)) ? (((fTemp128 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp128 >= 8.0f)) ? 0.3f : (((fTemp128 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp128 >= 3.0f)) ? (((fTemp128 >= 5.0f)) ? 0.47f : (((fTemp128 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp128 >= 2.0f)) ? 0.74f : (((fTemp128 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp130))) : fTemp125)));
			float 	fTemp135 = (fRec55[1] - fTemp134);
			float 	fTemp136 = (fRec55[1] + fTemp134);
			fRec55[0] = (((fTemp136 < fTemp133)) ? fTemp136 : (((fTemp135 > fTemp133)) ? fTemp135 : fTemp133));
			fRec53[0] = fRec55[0];
			fRec51[0] = (fRec53[0] - (fConst18 * ((fConst16 * fRec51[2]) + (fConst14 * fRec51[1]))));
			float 	fTemp137 = (fSlow67 + (fRec57[1] + -1.0f));
			float 	fTemp138 = (fSlow67 + fRec57[1]);
			int 	iTemp139 = (fTemp137 < 0.0f);
			fRec57[0] = ((iTemp139) ? fTemp138 : fTemp137);
			float 	fRec58 = ((iTemp139) ? fTemp138 : (fSlow67 + (fRec57[1] + (fSlow68 * fTemp137))));
			float 	fTemp140 = (fSlow70 + (fRec59[1] + -1.0f));
			float 	fTemp141 = (fSlow70 + fRec59[1]);
			int 	iTemp142 = (fTemp140 < 0.0f);
			fRec59[0] = ((iTemp142) ? fTemp141 : fTemp140);
			float 	fRec60 = ((iTemp142) ? fTemp141 : (fSlow70 + (fRec59[1] + (fSlow71 * fTemp140))));
			fVec16[0] = fSlow72;
			float 	fTemp143 = ((iTemp6) ? 0.0f : (fSlow74 + fRec61[1]));
			fRec61[0] = (fTemp143 - floorf(fTemp143));
			int 	iTemp144 = (fSlow72 != fVec16[1]);
			iVec17[0] = iTemp144;
			int 	iTemp145 = ((iVec17[1] <= 0) & (iVec17[0] > 0));
			iRec65[0] = ((iRec65[1] * (1 - iTemp145)) + (iTemp10 * iTemp145));
			float 	fTemp146 = (0.5f * (0.0f - (cosf((3.1415927f * (((((fConst9 * float((iRec10[0] + (-1 - iRec65[0])))) > 0.5f) & iSlow77)) ? 0.0f : fSlow76))) + -1.0f)));
			int 	iTemp147 = (fTemp146 > 0.001f);
			int 	iTemp148 = (fTemp146 <= 0.001f);
			int 	iTemp149 = (fTemp146 >= fRec64[1]);
			int 	iTemp150 = (fRec64[1] <= 0.001f);
			int 	iTemp151 = (((iRec63[1] >= 4)) ? (((iRec63[1] >= 6)) ? ((iTemp150) ? 0 : ((iTemp147) ? 1 : 6)) : (((iRec63[1] >= 5)) ? ((iTemp148) ? 3 : ((iTemp149) ? 4 : 5)) : ((iTemp148) ? 3 : (((fTemp146 <= fRec64[1])) ? 5 : 4)))) : (((iRec63[1] >= 2)) ? (((iRec63[1] >= 3)) ? (((iTemp148 & iTemp150)) ? 0 : ((iTemp147) ? 1 : 3)) : ((iTemp148) ? 3 : ((iTemp149) ? ((iTemp148) ? 6 : 4) : 2))) : (((iRec63[1] >= 1)) ? (((fRec64[1] >= 1.0f)) ? ((iTemp148) ? 6 : 2) : 1) : ((iTemp147) ? 1 : 0))));
			iRec63[0] = iTemp151;
			float 	fTemp152 = (((iTemp151 == 6)) ? fConst22 : (((iTemp151 >= 4)) ? (((iTemp151 >= 6)) ? fConst22 : fConst21) : (((iTemp151 >= 2)) ? (((iTemp151 >= 3)) ? fConst19 : fConst20) : (((iTemp151 >= 1)) ? fConst19 : 0.0f))));
			int 	iTemp153 = (iRec63[1] != iRec63[2]);
			iVec18[0] = iTemp153;
			int 	iTemp154 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec67[0] = ((iRec67[1] * (1 - iTemp154)) + (iTemp10 * iTemp154));
			float 	fTemp155 = min(19.0f, floorf((21.0f * (((fTemp152 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec67[0]))) / fTemp152) : 1.0f))));
			float 	fTemp156 = min((fTemp155 + 1.0f), 2e+01f);
			float 	fTemp157 = (((fTemp156 >= 11.0f)) ? (((fTemp156 >= 16.0f)) ? (((fTemp156 >= 19.0f)) ? (((fTemp156 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp156 >= 18.0f)) ? 0.03f : (((fTemp156 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp156 >= 14.0f)) ? (((fTemp156 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp156 >= 13.0f)) ? 0.14f : (((fTemp156 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp156 >= 6.0f)) ? (((fTemp156 >= 9.0f)) ? (((fTemp156 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp156 >= 8.0f)) ? 0.3f : (((fTemp156 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp156 >= 3.0f)) ? (((fTemp156 >= 5.0f)) ? 0.47f : (((fTemp156 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp156 >= 2.0f)) ? 0.74f : (((fTemp156 >= 1.0f)) ? 0.86f : 1.0f)))));
			int 	iTemp158 = ((iRec63[1] == 3) | (iRec63[1] == 6));
			int 	iTemp159 = (iRec63[1] == 0);
			fbargraph5 = float(iRec63[1]);
			float 	fTemp160 = (((fbargraph5 == 1.0f)) ? 1.0f : ((iTemp159) ? 0.0f : ((iTemp158) ? fTemp157 : fTemp146)));
			float 	fTemp161 = (1.0f / ((iTemp159) ? 0.0001f : ((iTemp158) ? (0.05f * (fTemp152 / ((((fTemp155 >= 11.0f)) ? (((fTemp155 >= 16.0f)) ? (((fTemp155 >= 19.0f)) ? (((fTemp155 >= 2e+01f)) ? 0.0f : 0.01f) : (((fTemp155 >= 18.0f)) ? 0.03f : (((fTemp155 >= 17.0f)) ? 0.06f : 0.08f))) : (((fTemp155 >= 14.0f)) ? (((fTemp155 >= 15.0f)) ? 0.1f : 0.12f) : (((fTemp155 >= 13.0f)) ? 0.14f : (((fTemp155 >= 12.0f)) ? 0.16f : 0.19f)))) : (((fTemp155 >= 6.0f)) ? (((fTemp155 >= 9.0f)) ? (((fTemp155 >= 1e+01f)) ? 0.22f : 0.26f) : (((fTemp155 >= 8.0f)) ? 0.3f : (((fTemp155 >= 7.0f)) ? 0.35f : 0.4f))) : (((fTemp155 >= 3.0f)) ? (((fTemp155 >= 5.0f)) ? 0.47f : (((fTemp155 >= 4.0f)) ? 0.55f : 0.64f)) : (((fTemp155 >= 2.0f)) ? 0.74f : (((fTemp155 >= 1.0f)) ? 0.86f : 1.0f))))) - fTemp157))) : fTemp152)));
			float 	fTemp162 = (fRec66[1] - fTemp161);
			float 	fTemp163 = (fRec66[1] + fTemp161);
			fRec66[0] = (((fTemp163 < fTemp160)) ? fTemp163 : (((fTemp162 > fTemp160)) ? fTemp162 : fTemp160));
			fRec64[0] = fRec66[0];
			fRec62[0] = (fRec64[0] - (fConst18 * ((fConst16 * fRec62[2]) + (fConst14 * fRec62[1]))));
			fRec0[0] = ((1.37f * ((((((min(0.99f, (fConst23 * (((3947.8418f * fRec62[0]) + (7895.6836f * fRec62[1])) + (3947.8418f * fRec62[2])))) * ((fSlow75 * ((0.75f * (((fRec61[0] < 0.5f)) ? ((4.0f * fRec61[0]) + -1.0f) : ((4.0f * (1.0f - fRec61[0])) + -1.0f))) + (0.25f * ((2.0f * fRec61[0]) + -1.0f)))) + (fSlow73 * (((2.0f * fRec60) + -1.0f) + ((2.0f * fRec58) + -1.0f))))) + (min(0.99f, (fConst23 * (((3947.8418f * fRec51[0]) + (7895.6836f * fRec51[1])) + (3947.8418f * fRec51[2])))) * ((fSlow62 * ((0.75f * (((fRec50[0] < 0.5f)) ? ((4.0f * fRec50[0]) + -1.0f) : ((4.0f * (1.0f - fRec50[0])) + -1.0f))) + (0.25f * ((2.0f * fRec50[0]) + -1.0f)))) + (fSlow60 * (((2.0f * fRec49) + -1.0f) + ((2.0f * fRec47) + -1.0f)))))) + (min(0.99f, (fConst23 * (((3947.8418f * fRec40[0]) + (7895.6836f * fRec40[1])) + (3947.8418f * fRec40[2])))) * ((fSlow49 * ((0.75f * (((fRec39[0] < 0.5f)) ? ((4.0f * fRec39[0]) + -1.0f) : ((4.0f * (1.0f - fRec39[0])) + -1.0f))) + (0.25f * ((2.0f * fRec39[0]) + -1.0f)))) + (fSlow47 * (((2.0f * fRec38) + -1.0f) + ((2.0f * fRec36) + -1.0f)))))) + (min(0.99f, (fConst23 * (((3947.8418f * fRec29[0]) + (7895.6836f * fRec29[1])) + (3947.8418f * fRec29[2])))) * ((fSlow36 * ((0.75f * (((fRec28[0] < 0.5f)) ? ((4.0f * fRec28[0]) + -1.0f) : ((4.0f * (1.0f - fRec28[0])) + -1.0f))) + (0.25f * ((2.0f * fRec28[0]) + -1.0f)))) + (fSlow34 * (((2.0f * fRec27) + -1.0f) + ((2.0f * fRec25) + -1.0f)))))) + (min(0.99f, (fConst23 * (((3947.8418f * fRec18[0]) + (7895.6836f * fRec18[1])) + (3947.8418f * fRec18[2])))) * ((fSlow23 * ((0.75f * (((fRec17[0] < 0.5f)) ? ((4.0f * fRec17[0]) + -1.0f) : ((4.0f * (1.0f - fRec17[0])) + -1.0f))) + (0.25f * ((2.0f * fRec17[0]) + -1.0f)))) + (fSlow21 * (((2.0f * fRec16) + -1.0f) + ((2.0f * fRec14) + -1.0f)))))) + (min(0.99f, (fConst23 * (((3947.8418f * fRec6[0]) + (7895.6836f * fRec6[1])) + (3947.8418f * fRec6[2])))) * ((fSlow10 * ((0.75f * (((fRec5[0] < 0.5f)) ? ((4.0f * fRec5[0]) + -1.0f) : ((4.0f * (1.0f - fRec5[0])) + -1.0f))) + (0.25f * ((2.0f * fRec5[0]) + -1.0f)))) + (fSlow8 * (((2.0f * fRec4) + -1.0f) + ((2.0f * fRec2) + -1.0f))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst24 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec62[2] = fRec62[1]; fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			fRec66[1] = fRec66[0];
			iRec67[1] = iRec67[0];
			iVec18[1] = iVec18[0];
			iRec63[2] = iRec63[1]; iRec63[1] = iRec63[0];
			iRec65[1] = iRec65[0];
			iVec17[1] = iVec17[0];
			fRec61[1] = fRec61[0];
			fVec16[1] = fVec16[0];
			fRec59[1] = fRec59[0];
			fRec57[1] = fRec57[0];
			fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
			fRec53[1] = fRec53[0];
			fRec55[1] = fRec55[0];
			iRec56[1] = iRec56[0];
			iVec15[1] = iVec15[0];
			iRec52[2] = iRec52[1]; iRec52[1] = iRec52[0];
			iRec54[1] = iRec54[0];
			iVec14[1] = iVec14[0];
			fRec50[1] = fRec50[0];
			fVec13[1] = fVec13[0];
			fRec48[1] = fRec48[0];
			fRec46[1] = fRec46[0];
			fRec40[2] = fRec40[1]; fRec40[1] = fRec40[0];
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			iRec45[1] = iRec45[0];
			iVec12[1] = iVec12[0];
			iRec41[2] = iRec41[1]; iRec41[1] = iRec41[0];
			iRec43[1] = iRec43[0];
			iVec11[1] = iVec11[0];
			fRec39[1] = fRec39[0];
			fVec10[1] = fVec10[0];
			fRec37[1] = fRec37[0];
			fRec35[1] = fRec35[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			iRec34[1] = iRec34[0];
			iVec9[1] = iVec9[0];
			iRec30[2] = iRec30[1]; iRec30[1] = iRec30[0];
			iRec32[1] = iRec32[0];
			iVec8[1] = iVec8[0];
			fRec28[1] = fRec28[0];
			fVec7[1] = fVec7[0];
			fRec26[1] = fRec26[0];
			fRec24[1] = fRec24[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec22[1] = fRec22[0];
			iRec23[1] = iRec23[0];
			iVec6[1] = iVec6[0];
			iRec19[2] = iRec19[1]; iRec19[1] = iRec19[0];
			iRec21[1] = iRec21[0];
			iVec5[1] = iVec5[0];
			fRec17[1] = fRec17[0];
			fVec4[1] = fVec4[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec6[2] = fRec6[1]; fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec11[1] = fRec11[0];
			iRec12[1] = iRec12[0];
			iVec3[1] = iVec3[0];
			iRec7[2] = iRec7[1]; iRec7[1] = iRec7[0];
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
