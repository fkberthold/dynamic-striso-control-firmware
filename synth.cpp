//----------------------------------------------------------
// name: "synth.dsp.tmp"
//
// Code generated with Faust 2.37.3 (https://faust.grame.fr)
//----------------------------------------------------------

/* link with : "" */
#include "fastpow.h"
#include <math.h>
#ifndef FAUSTPOWER
#define FAUSTPOWER
//#include <cmath>
template <int N> inline int faustpower(int x)              { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline int faustpower<0>(int x)            { return 1; }
template <> 	 inline int faustpower<1>(int x)            { return x; }
template <> 	 inline int faustpower<2>(int x)            { return x*x; }
template <int N> inline float faustpower(float x)            { return faustpower<N/2>(x) * faustpower<N-N/2>(x); } 
template <> 	 inline float faustpower<0>(float x)          { return 1; }
template <> 	 inline float faustpower<1>(float x)          { return x; }
template <> 	 inline float faustpower<2>(float x)          { return x*x; }
#endif

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
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				output[i] = (9.3132257504915938e-10f * rand_hoaglin());
			}
		}
	};


	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	float 	fConst10;
	float 	fConst12;
	FAUSTFLOAT 	fslider0;
	static float 	ftbl0[4096];
	FAUSTFLOAT 	fslider1;
	float 	fConst13;
	float 	fConst14;
	float 	fRec2[2];
	float 	fRec1[3];
	float 	fConst16;
	float 	fConst18;
	FAUSTFLOAT 	fslider2;
	float 	fRec3[3];
	float 	fConst20;
	float 	fConst22;
	FAUSTFLOAT 	fslider3;
	float 	fRec4[3];
	float 	fConst26;
	float 	fConst28;
	float 	fConst30;
	FAUSTFLOAT 	fslider4;
	float 	fRec5[3];
	float 	fConst31;
	FAUSTFLOAT 	fslider5;
	float 	fConst32;
	float 	fRec6[2];
	float 	fRec7[2];
	float 	fConst33;
	float 	fRec16[2];
	float 	fRec15[2];
	int 	iRec17[2];
	float 	fRec18[2];
	float 	fRec19[2];
	FAUSTFLOAT 	fbargraph0;
	int 	iRec20[2];
	int 	iRec22[2];
	int 	iRec21[2];
	FAUSTFLOAT 	fbargraph1;
	int 	iRec13[2];
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	FAUSTFLOAT 	fbargraph2;
	float 	fRec23[2];
	float 	fRec14[2];
	float 	fRec12[3];
	float 	fConst43;
	float 	fConst45;
	float 	fConst47;
	float 	fConst48;
	float 	fConst50;
	FAUSTFLOAT 	fslider6;
	float 	fRec26[3];
	float 	fConst51;
	float 	fRec25[3];
	float 	fConst52;
	float 	fConst53;
	float 	fRec24[2];
	float 	fRec9[2];
	float 	fRec10[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec28[2];
	float 	fRec27[3];
	float 	fRec29[3];
	float 	fRec30[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec31[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fRec42[2];
	float 	fRec41[2];
	int 	iRec43[2];
	float 	fRec44[2];
	float 	fRec45[2];
	FAUSTFLOAT 	fbargraph3;
	int 	iRec46[2];
	int 	iRec47[2];
	FAUSTFLOAT 	fbargraph4;
	int 	iRec39[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec48[2];
	float 	fRec40[2];
	float 	fRec38[3];
	float 	fRec35[2];
	float 	fRec36[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec50[2];
	float 	fRec49[3];
	float 	fRec51[3];
	float 	fRec52[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec53[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec54[2];
	float 	fRec55[2];
	float 	fRec64[2];
	float 	fRec63[2];
	int 	iRec65[2];
	float 	fRec66[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fbargraph6;
	int 	iRec68[2];
	int 	iRec69[2];
	FAUSTFLOAT 	fbargraph7;
	int 	iRec61[2];
	FAUSTFLOAT 	fbargraph8;
	float 	fRec70[2];
	float 	fRec62[2];
	float 	fRec60[3];
	float 	fRec57[2];
	float 	fRec58[2];
	FAUSTFLOAT 	fslider13;
	float 	fRec72[2];
	float 	fRec71[3];
	float 	fRec73[3];
	float 	fRec74[3];
	FAUSTFLOAT 	fslider14;
	float 	fRec75[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec76[2];
	float 	fRec77[2];
	float 	fRec86[2];
	float 	fRec85[2];
	int 	iRec87[2];
	float 	fRec88[2];
	float 	fRec89[2];
	FAUSTFLOAT 	fbargraph9;
	int 	iRec90[2];
	int 	iRec91[2];
	FAUSTFLOAT 	fbargraph10;
	int 	iRec83[2];
	FAUSTFLOAT 	fbargraph11;
	float 	fRec92[2];
	float 	fRec84[2];
	float 	fRec82[3];
	float 	fRec79[2];
	float 	fRec80[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec94[2];
	float 	fRec93[3];
	float 	fRec95[3];
	float 	fRec96[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec97[3];
	FAUSTFLOAT 	fslider18;
	float 	fRec98[2];
	float 	fRec99[2];
	float 	fRec108[2];
	float 	fRec107[2];
	int 	iRec109[2];
	float 	fRec110[2];
	float 	fRec111[2];
	FAUSTFLOAT 	fbargraph12;
	int 	iRec112[2];
	int 	iRec113[2];
	FAUSTFLOAT 	fbargraph13;
	int 	iRec105[2];
	FAUSTFLOAT 	fbargraph14;
	float 	fRec114[2];
	float 	fRec106[2];
	float 	fRec104[3];
	float 	fRec101[2];
	float 	fRec102[2];
	FAUSTFLOAT 	fslider19;
	float 	fRec116[2];
	float 	fRec115[3];
	float 	fRec117[3];
	float 	fRec118[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec119[3];
	FAUSTFLOAT 	fslider21;
	float 	fRec120[2];
	float 	fRec121[2];
	float 	fRec130[2];
	float 	fRec129[2];
	int 	iRec131[2];
	float 	fRec132[2];
	float 	fRec133[2];
	FAUSTFLOAT 	fbargraph15;
	int 	iRec134[2];
	int 	iRec135[2];
	FAUSTFLOAT 	fbargraph16;
	int 	iRec127[2];
	FAUSTFLOAT 	fbargraph17;
	float 	fRec136[2];
	float 	fRec128[2];
	float 	fRec126[3];
	float 	fRec123[2];
	float 	fRec124[2];
	float 	fConst54;
	float 	fRec0[3];
	float 	fConst55;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/version", "0.2");
		m->declare("fast.lib/author", "Piers Titus van der Torren (pierstitus@toverlamp.org)");
		m->declare("fast.lib/licence", "Apache-2.0");
		m->declare("fast.lib/name", "Faust Fast Approximations Library");
		m->declare("filename", "synth.dsp.tmp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "0.3");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.5");
		m->declare("name", "synth.dsp.tmp");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "0.2");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "0.2");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "0.1");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate) {
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(4096,ftbl0);
	}
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = min(192000.0f, max(1.0f, (float)fSampleRate));
		float 	fConst1 = faustpower<2>(fConst0);
		float 	fConst2 = faustpower<2>((251.32741228718345f / fConst0));
		float 	fConst3 = ((fConst2 * ((0.20330000000000001f * fConst2) + 0.31755f)) + 1.0f);
		fConst4 = (2.0f * ((63165.468166971892f * (faustpower<2>(fConst3) / fConst1)) + -1.0f));
		float 	fConst5 = (63165.468166971892f * (fConst3 / fConst0));
		fConst6 = (((fConst3 * (fConst5 + -191.85298647876598f)) / fConst0) + 1.0f);
		float 	fConst7 = (((fConst3 * (fConst5 + 191.85298647876598f)) / fConst0) + 1.0f);
		fConst8 = (1.0f / fConst7);
		float 	fConst9 = faustpower<2>((4084.0704496667308f / fConst0));
		fConst10 = (4084.0704496667308f * (((fConst9 * ((0.20330000000000001f * fConst9) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst11 = faustpower<2>((8168.1408993334617f / fConst0));
		fConst12 = (8168.1408993334617f * (((fConst11 * ((0.20330000000000001f * fConst11) + 0.31755f)) + 1.0f) / fConst0));
		fConst13 = (0.061156102924877762f * fConst0);
		fConst14 = (8.1757989159999997f / fConst0);
		float 	fConst15 = faustpower<2>((942.47779607693792f / fConst0));
		fConst16 = (942.47779607693792f * (((fConst15 * ((0.20330000000000001f * fConst15) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst17 = faustpower<2>((1884.9555921538758f / fConst0));
		fConst18 = (1884.9555921538758f * (((fConst17 * ((0.20330000000000001f * fConst17) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst19 = faustpower<2>((2827.4333882308138f / fConst0));
		fConst20 = (2827.4333882308138f * (((fConst19 * ((0.20330000000000001f * fConst19) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst21 = faustpower<2>((5340.7075111026479f / fConst0));
		fConst22 = (5340.7075111026479f * (((fConst21 * ((0.20330000000000001f * fConst21) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst23 = faustpower<2>((62.831853071795862f / fConst0));
		float 	fConst24 = ((fConst23 * ((0.20330000000000001f * fConst23) + 0.31755f)) + 1.0f);
		float 	fConst25 = faustpower<2>(fConst24);
		fConst26 = (2.0f * ((3947.8417604357433f * (fConst25 / fConst1)) + -1.0f));
		float 	fConst27 = (3947.8417604357433f * (fConst24 / fConst0));
		fConst28 = (((fConst24 * (fConst27 + -88.495567706754741f)) / fConst0) + 1.0f);
		float 	fConst29 = (((fConst24 * (fConst27 + 88.495567706754741f)) / fConst0) + 1.0f);
		fConst30 = (1.0f / fConst29);
		fConst31 = (fConst25 / (fConst1 * fConst29));
		fConst32 = (3.1415926535897931f / fConst0);
		fConst33 = (0.10000000000000001f * fConst0);
		fConst34 = (0.20000000000000001f * fConst0);
		fConst35 = (0.34999999999999998f * fConst0);
		fConst36 = (0.01f * fConst0);
		fConst37 = (0.5f * fConst0);
		fConst38 = (0.39000000000000001f * fConst0);
		fConst39 = (8.0f * fConst0);
		float 	fConst40 = faustpower<2>((125.66370614359172f / fConst0));
		float 	fConst41 = ((fConst40 * ((0.20330000000000001f * fConst40) + 0.31755f)) + 1.0f);
		float 	fConst42 = faustpower<2>(fConst41);
		fConst43 = (2.0f * ((15791.367041742973f * (fConst42 / fConst1)) + -1.0f));
		float 	fConst44 = (15791.367041742973f * (fConst41 / fConst0));
		fConst45 = (((fConst41 * (fConst44 + -232.71056693257725f)) / fConst0) + 1.0f);
		float 	fConst46 = (((fConst41 * (fConst44 + 232.71056693257725f)) / fConst0) + 1.0f);
		fConst47 = (1.0f / fConst46);
		fConst48 = (((fConst41 * (fConst44 + -95.926493239382992f)) / fConst0) + 1.0f);
		float 	fConst49 = (((fConst41 * (fConst44 + 95.926493239382992f)) / fConst0) + 1.0f);
		fConst50 = (1.0f / fConst49);
		fConst51 = (fConst42 / (fConst1 * fConst49));
		fConst52 = (fConst42 / (fConst1 * fConst46));
		fConst53 = powf(0.5f,(10.0f / fConst0));
		fConst54 = (1.3700000000000001f * fConst31);
		fConst55 = (0 - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = 69.0f;
		fslider2 = 0.0f;
		fslider3 = 0.0f;
		fslider4 = 0.0f;
		fslider5 = 0.0f;
		fslider6 = 1.0f;
		fslider7 = 69.0f;
		fslider8 = 0.0f;
		fslider9 = 0.0f;
		fslider10 = 69.0f;
		fslider11 = 0.0f;
		fslider12 = 0.0f;
		fslider13 = 69.0f;
		fslider14 = 0.0f;
		fslider15 = 0.0f;
		fslider16 = 69.0f;
		fslider17 = 0.0f;
		fslider18 = 0.0f;
		fslider19 = 69.0f;
		fslider20 = 0.0f;
		fslider21 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<3; i++) fRec1[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<3; i++) fRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) iRec20[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) fRec26[i] = 0;
		for (int i=0; i<3; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<3; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) iRec46[i] = 0;
		for (int i=0; i<2; i++) iRec47[i] = 0;
		for (int i=0; i<2; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<3; i++) fRec49[i] = 0;
		for (int i=0; i<3; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) iRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) iRec68[i] = 0;
		for (int i=0; i<2; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) iRec61[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<3; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec71[i] = 0;
		for (int i=0; i<3; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec74[i] = 0;
		for (int i=0; i<3; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) iRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) iRec83[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) fRec93[i] = 0;
		for (int i=0; i<3; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) fRec96[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) iRec109[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) iRec112[i] = 0;
		for (int i=0; i<2; i++) iRec113[i] = 0;
		for (int i=0; i<2; i++) iRec105[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<3; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec116[i] = 0;
		for (int i=0; i<3; i++) fRec115[i] = 0;
		for (int i=0; i<3; i++) fRec117[i] = 0;
		for (int i=0; i<3; i++) fRec118[i] = 0;
		for (int i=0; i<3; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec130[i] = 0;
		for (int i=0; i<2; i++) fRec129[i] = 0;
		for (int i=0; i<2; i++) iRec131[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<2; i++) iRec134[i] = 0;
		for (int i=0; i<2; i++) iRec135[i] = 0;
		for (int i=0; i<2; i++) iRec127[i] = 0;
		for (int i=0; i<2; i++) fRec136[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<3; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec123[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
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
		synth_interface.acc_abs = &fslider6;
		synth_interface.rot_x = &fslider2;
		synth_interface.rot_y = &fslider3;
		synth_interface.rot_z = &fslider0;
		synth_interface.note[0] = &fslider19;
		synth_interface.pres[0] = &fslider21;
		synth_interface.but_y[0] = &fslider20;
		synth_interface.note[1] = &fslider16;
		synth_interface.pres[1] = &fslider18;
		synth_interface.but_y[1] = &fslider17;
		synth_interface.note[2] = &fslider13;
		synth_interface.pres[2] = &fslider15;
		synth_interface.but_y[2] = &fslider14;
		synth_interface.note[3] = &fslider10;
		synth_interface.pres[3] = &fslider12;
		synth_interface.but_y[3] = &fslider11;
		synth_interface.note[4] = &fslider7;
		synth_interface.pres[4] = &fslider9;
		synth_interface.but_y[4] = &fslider8;
		synth_interface.note[5] = &fslider1;
		synth_interface.pres[5] = &fslider5;
		synth_interface.but_y[5] = &fslider4;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = float(fslider0);
		float 	fSlow1 = ((int((fSlow0 > 0.0f)))?fConst12:fConst10);
		float 	fSlow2 = fabsf(fSlow0);
		float 	fSlow3 = ((0.5f * fSlow2) + 1.0f);
		float 	fSlow4 = (fSlow3 * fSlow1);
		float 	fSlow5 = ((fSlow3 * (fSlow1 * (fSlow4 + 0.125f))) + 1.0f);
		float 	fSlow6 = ((faustpower<2>(fSlow3) * faustpower<2>(fSlow1)) + -1.0f);
		float 	fSlow7 = ((fSlow3 * (fSlow1 * (fSlow4 + -0.125f))) + 1.0f);
		float 	fSlow8 = fastpow2((0.083333333333333329f * float(fslider1)));
		int 	iSlow9 = int(min((fConst13 / fSlow8), (float)4096));
		float 	fSlow10 = float(iSlow9);
		float 	fSlow11 = (fConst14 * (fSlow8 * fSlow10));
		float 	fSlow12 = (fSlow2 * fSlow3);
		float 	fSlow13 = float(fslider2);
		float 	fSlow14 = ((int((fSlow13 > 0.0f)))?fConst18:fConst16);
		float 	fSlow15 = fabsf(fSlow13);
		float 	fSlow16 = ((0.5f * fSlow15) + 1.0f);
		float 	fSlow17 = (fSlow16 * fSlow14);
		float 	fSlow18 = ((fSlow16 * (fSlow14 * (fSlow17 + 0.125f))) + 1.0f);
		float 	fSlow19 = ((faustpower<2>(fSlow16) * faustpower<2>(fSlow14)) + -1.0f);
		float 	fSlow20 = ((fSlow16 * (fSlow14 * (fSlow17 + -0.125f))) + 1.0f);
		float 	fSlow21 = (fSlow15 * fSlow16);
		float 	fSlow22 = float(fslider3);
		float 	fSlow23 = ((int((fSlow22 > 0.0f)))?fConst22:fConst20);
		float 	fSlow24 = fabsf(fSlow22);
		float 	fSlow25 = ((0.5f * fSlow24) + 1.0f);
		float 	fSlow26 = (fSlow25 * fSlow23);
		float 	fSlow27 = ((fSlow25 * (fSlow23 * (fSlow26 + 0.20000000000000001f))) + 1.0f);
		float 	fSlow28 = ((faustpower<2>(fSlow25) * faustpower<2>(fSlow23)) + -1.0f);
		float 	fSlow29 = ((fSlow25 * (fSlow23 * (fSlow26 + -0.20000000000000001f))) + 1.0f);
		float 	fSlow30 = (0.20000000000000001f * (fSlow24 * fSlow25));
		float 	fSlow31 = float(fslider4);
		float 	fSlow32 = float(fslider5);
		float 	fSlow33 = (1500.0f * fSlow32);
		float 	fSlow34 = (0.40000000000000002f * fSlow32);
		int 	iSlow35 = ((int((fSlow32 >= 0.01f)))?1:0);
		float 	fSlow36 = fabsf(fSlow31);
		float 	fSlow37 = ((int((fSlow36 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow38 = ((fSlow31 > 0.0f) - (fSlow31 < 0.0f));
		int 	iSlow39 = int((fSlow32 <= 0.01f));
		int 	iSlow40 = ((iSlow39)?3:2);
		int 	iSlow41 = (fSlow32 <= 0.0f);
		float 	fSlow42 = float(fslider6);
		float 	fSlow43 = max((8.1757989159999997f * fSlow8), (float)200);
		float 	fSlow44 = fastpow2((0.083333333333333329f * float(fslider7)));
		int 	iSlow45 = int(min((fConst13 / fSlow44), (float)4096));
		float 	fSlow46 = float(iSlow45);
		float 	fSlow47 = (fConst14 * (fSlow44 * fSlow46));
		float 	fSlow48 = float(fslider8);
		float 	fSlow49 = float(fslider9);
		float 	fSlow50 = (1500.0f * fSlow49);
		float 	fSlow51 = (0.40000000000000002f * fSlow49);
		int 	iSlow52 = ((int((fSlow49 >= 0.01f)))?1:0);
		float 	fSlow53 = fabsf(fSlow48);
		float 	fSlow54 = ((int((fSlow53 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow55 = ((fSlow48 > 0.0f) - (fSlow48 < 0.0f));
		int 	iSlow56 = int((fSlow49 <= 0.01f));
		int 	iSlow57 = ((iSlow56)?3:2);
		int 	iSlow58 = (fSlow49 <= 0.0f);
		float 	fSlow59 = max((8.1757989159999997f * fSlow44), (float)200);
		float 	fSlow60 = fastpow2((0.083333333333333329f * float(fslider10)));
		int 	iSlow61 = int(min((fConst13 / fSlow60), (float)4096));
		float 	fSlow62 = float(iSlow61);
		float 	fSlow63 = (fConst14 * (fSlow60 * fSlow62));
		float 	fSlow64 = float(fslider11);
		float 	fSlow65 = float(fslider12);
		float 	fSlow66 = (1500.0f * fSlow65);
		float 	fSlow67 = (0.40000000000000002f * fSlow65);
		int 	iSlow68 = ((int((fSlow65 >= 0.01f)))?1:0);
		float 	fSlow69 = fabsf(fSlow64);
		float 	fSlow70 = ((int((fSlow69 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow71 = ((fSlow64 > 0.0f) - (fSlow64 < 0.0f));
		int 	iSlow72 = int((fSlow65 <= 0.01f));
		int 	iSlow73 = ((iSlow72)?3:2);
		int 	iSlow74 = (fSlow65 <= 0.0f);
		float 	fSlow75 = max((8.1757989159999997f * fSlow60), (float)200);
		float 	fSlow76 = fastpow2((0.083333333333333329f * float(fslider13)));
		int 	iSlow77 = int(min((fConst13 / fSlow76), (float)4096));
		float 	fSlow78 = float(iSlow77);
		float 	fSlow79 = (fConst14 * (fSlow76 * fSlow78));
		float 	fSlow80 = float(fslider14);
		float 	fSlow81 = float(fslider15);
		float 	fSlow82 = (1500.0f * fSlow81);
		float 	fSlow83 = (0.40000000000000002f * fSlow81);
		int 	iSlow84 = ((int((fSlow81 >= 0.01f)))?1:0);
		float 	fSlow85 = fabsf(fSlow80);
		float 	fSlow86 = ((int((fSlow85 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow87 = ((fSlow80 > 0.0f) - (fSlow80 < 0.0f));
		int 	iSlow88 = int((fSlow81 <= 0.01f));
		int 	iSlow89 = ((iSlow88)?3:2);
		int 	iSlow90 = (fSlow81 <= 0.0f);
		float 	fSlow91 = max((8.1757989159999997f * fSlow76), (float)200);
		float 	fSlow92 = fastpow2((0.083333333333333329f * float(fslider16)));
		int 	iSlow93 = int(min((fConst13 / fSlow92), (float)4096));
		float 	fSlow94 = float(iSlow93);
		float 	fSlow95 = (fConst14 * (fSlow92 * fSlow94));
		float 	fSlow96 = float(fslider17);
		float 	fSlow97 = float(fslider18);
		float 	fSlow98 = (1500.0f * fSlow97);
		float 	fSlow99 = (0.40000000000000002f * fSlow97);
		int 	iSlow100 = ((int((fSlow97 >= 0.01f)))?1:0);
		float 	fSlow101 = fabsf(fSlow96);
		float 	fSlow102 = ((int((fSlow101 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow103 = ((fSlow96 > 0.0f) - (fSlow96 < 0.0f));
		int 	iSlow104 = int((fSlow97 <= 0.01f));
		int 	iSlow105 = ((iSlow104)?3:2);
		int 	iSlow106 = (fSlow97 <= 0.0f);
		float 	fSlow107 = max((8.1757989159999997f * fSlow92), (float)200);
		float 	fSlow108 = fastpow2((0.083333333333333329f * float(fslider19)));
		int 	iSlow109 = int(min((fConst13 / fSlow108), (float)4096));
		float 	fSlow110 = float(iSlow109);
		float 	fSlow111 = (fConst14 * (fSlow108 * fSlow110));
		float 	fSlow112 = float(fslider20);
		float 	fSlow113 = float(fslider21);
		float 	fSlow114 = (1500.0f * fSlow113);
		float 	fSlow115 = (0.40000000000000002f * fSlow113);
		int 	iSlow116 = ((int((fSlow113 >= 0.01f)))?1:0);
		float 	fSlow117 = fabsf(fSlow112);
		float 	fSlow118 = ((int((fSlow117 >= 0.050000000000000003f)))?fConst33:fConst0);
		int 	iSlow119 = ((fSlow112 > 0.0f) - (fSlow112 < 0.0f));
		int 	iSlow120 = int((fSlow113 <= 0.01f));
		int 	iSlow121 = ((iSlow120)?3:2);
		int 	iSlow122 = (fSlow113 <= 0.0f);
		float 	fSlow123 = max((8.1757989159999997f * fSlow108), (float)200);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			fRec2[0] = (fSlow11 + (fRec2[1] - float((iSlow9 * ((fSlow11 + fRec2[1]) > fSlow10)))));
			int 	iTemp0 = int(fRec2[0]);
			float 	fTemp1 = ftbl0[iTemp0];
			float 	fTemp2 = (fTemp1 + ((fRec2[0] - float(iTemp0)) * (ftbl0[((iTemp0 + 1) % iSlow9)] - fTemp1)));
			fRec1[0] = (fTemp2 - (((fSlow7 * fRec1[2]) + (2.0f * (fSlow6 * fRec1[1]))) / fSlow5));
			fRec3[0] = (fTemp2 - (((fSlow20 * fRec3[2]) + (2.0f * (fSlow19 * fRec3[1]))) / fSlow18));
			fRec4[0] = (fTemp2 - (((fSlow29 * fRec4[2]) + (2.0f * (fSlow28 * fRec4[1]))) / fSlow27));
			fRec5[0] = (fSlow31 - (fConst30 * ((fConst28 * fRec5[2]) + (fConst26 * fRec5[1]))));
			float 	fTemp3 = ((fConst31 * (((3947.8417604357433f * fRec5[0]) + (7895.6835208714865f * fRec5[1])) + (3947.8417604357433f * fRec5[2]))) + 1.0f);
			float 	fTemp4 = (0.5f * fTemp3);
			float 	fTemp5 = max(fTemp4, (float)0);
			float 	fTemp6 = tanf((fConst32 * ((fSlow33 * (fTemp3 * fTemp5)) + 200.0f)));
			float 	fTemp7 = ((fTemp6 * (fTemp6 + 0.5f)) + 1.0f);
			float 	fTemp8 = (fRec6[1] + (fTemp6 * (fTemp2 - fRec7[1])));
			float 	fTemp9 = (fTemp8 / fTemp7);
			fRec6[0] = ((2.0f * fTemp9) - fRec6[1]);
			float 	fTemp10 = (fRec7[1] + ((fTemp6 * fTemp8) / fTemp7));
			fRec7[0] = ((2.0f * fTemp10) - fRec7[1]);
			float 	fRec8 = fTemp9;
			float 	fTemp11 = max((-1 * fTemp4), (float)0);
			float 	fTemp12 = (1.0f / ((int((iSlow38 == ((fRec15[1] > 0.0f) - (fRec15[1] < 0.0f)))))?((int((fSlow36 >= fabsf(fRec15[1]))))?fConst33:fConst0):fSlow37));
			float 	fTemp13 = (fRec16[1] - fTemp12);
			float 	fTemp14 = (fRec16[1] + fTemp12);
			fRec16[0] = ((int((fTemp14 < fSlow31)))?fTemp14:((int((fTemp13 > fSlow31)))?fTemp13:fSlow31));
			fRec15[0] = fRec16[0];
			int 	iTemp15 = ((fRec15[0] > 0.0f) + (1 - (fRec15[0] < 0.0f)));
			int 	iTemp16 = int((iTemp15 == 1));
			int 	iTemp17 = int((iTemp15 == 0));
			float 	fTemp18 = ((iTemp17)?1.7f:((iTemp16)?1.2f:1.1000000000000001f));
			iRec17[0] = iRec13[1];
			int 	iTemp19 = int((iRec17[1] == iRec13[1]));
			int 	iTemp20 = int((iRec13[1] == 0));
			fRec18[0] = ((iTemp20)?fSlow32:((iTemp19)?min(min(fRec18[1], fSlow32), fRec14[1]):min(fSlow32, fRec14[1])));
			float 	fTemp21 = (fSlow32 * fTemp18);
			int 	iTemp22 = int((iRec13[1] == 1));
			fRec19[0] = ((iTemp20)?fSlow32:((iTemp22)?((iTemp19)?max(max(fRec19[1], fTemp21), fRec14[1]):max(fTemp21, fRec14[1])):((iTemp19)?max(max(fRec19[1], fSlow32), fRec14[1]):max(fSlow32, fRec14[1]))));
			fbargraph0 = fRec18[0];
			iRec20[0] = iRec13[1];
			iRec22[0] = (iRec22[1] + 1);
			int 	iTemp23 = (iRec22[0] + -1);
			iRec21[0] = ((int((iRec20[1] != iRec13[1])))?iTemp23:iRec21[1]);
			int 	iTemp24 = int((iRec13[1] >= 1));
			int 	iTemp25 = int((fSlow32 >= fRec14[1]));
			int 	iTemp26 = int((iRec13[1] >= 3));
			int 	iTemp27 = int((iRec13[1] >= 2));
			int 	iTemp28 = int((iRec13[1] >= 5));
			int 	iTemp29 = int((iRec13[1] >= 6));
			int 	iTemp30 = int((iRec13[1] >= 4));
			fbargraph1 = ((iTemp30)?((iTemp29)?((iSlow39)?3:((iTemp25)?5:6)):((iTemp28)?((iSlow39)?3:((int((fSlow32 <= fRec14[1])))?6:5)):((int((fRec14[1] <= 0.01f)))?0:4))):((iTemp27)?((iTemp26)?((int((iSlow41 & (fRec14[1] <= 0.0f))))?0:((int((fSlow32 > fRec14[1])))?4:3)):((iTemp25)?5:iSlow40)):((iTemp24)?((int(((float((iRec22[0] + (-1 - iRec21[0]))) >= fConst33) & (fRec14[1] >= (fbargraph0 * fTemp18)))))?2:1):iSlow35)));
			iRec13[0] = fbargraph1;
			float 	fTemp31 = ((iTemp22)?fTemp21:fSlow32);
			float 	fTemp32 = ((iTemp30)?((iTemp29)?fConst37:((iTemp28)?fConst37:fConst36)):((iTemp27)?((iTemp26)?fConst35:fConst34):((iTemp24)?fConst33:0.0f)));
			float 	fTemp33 = fabsf(fRec15[0]);
			fbargraph2 = ((fTemp33 * ((iTemp17)?((iTemp30)?((iTemp29)?fConst0:((iTemp28)?fConst0:fConst36)):((iTemp27)?((iTemp26)?fConst39:fConst33):((iTemp24)?fConst38:0.0f))):((iTemp16)?fTemp32:((iTemp30)?fConst36:((iTemp27)?fConst36:((iTemp24)?fConst36:0.0f)))))) + ((1.0f - fTemp33) * fTemp32));
			float 	fTemp34 = (1.0f / fbargraph2);
			float 	fTemp35 = (fRec23[1] - fTemp34);
			float 	fTemp36 = (fRec23[1] + fTemp34);
			fRec23[0] = ((int((fTemp36 < fTemp31)))?fTemp36:((int((fTemp35 > fTemp31)))?fTemp35:fTemp31));
			fRec14[0] = fRec23[0];
			fRec12[0] = (fRec14[0] - (fConst30 * ((fConst28 * fRec12[2]) + (fConst26 * fRec12[1]))));
			float 	fTemp37 = (((3947.8417604357433f * fRec12[0]) + (7895.6835208714865f * fRec12[1])) + (3947.8417604357433f * fRec12[2]));
			fRec26[0] = (fSlow42 - (fConst50 * ((fConst48 * fRec26[2]) + (fConst43 * fRec26[1]))));
			fRec25[0] = ((fConst51 * (((15791.367041742973f * fRec26[0]) + (31582.734083485946f * fRec26[1])) + (15791.367041742973f * fRec26[2]))) - (fConst47 * ((fConst45 * fRec25[2]) + (fConst43 * fRec25[1]))));
			fRec24[0] = (fConst53 * max(fRec24[1], min((fConst52 * (((15791.367041742973f * fRec25[0]) + (31582.734083485946f * fRec25[1])) + (15791.367041742973f * fRec25[2]))), (float)2)));
			float 	fTemp38 = max((fRec24[0] + -1.0f), (float)0);
			float 	fTemp39 = tanf((fConst32 * min((fSlow43 * (faustpower<2>((fTemp38 + (fConst31 * (fTemp37 * (1.0f - fTemp11))))) + 1.0f)), (float)16000)));
			float 	fTemp40 = ((fTemp39 * (fTemp39 + (1.0f / ((8.0f * fTemp11) + 1.0f)))) + 1.0f);
			float 	fTemp41 = (fRec9[1] + (fTemp39 * (fTemp2 - fRec10[1])));
			float 	fTemp42 = (fTemp41 / fTemp40);
			fRec9[0] = ((2.0f * fTemp42) - fRec9[1]);
			float 	fTemp43 = (fRec10[1] + ((fTemp39 * fTemp41) / fTemp40));
			fRec10[0] = ((2.0f * fTemp43) - fRec10[1]);
			float 	fRec11 = fTemp43;
			fRec28[0] = (fSlow47 + (fRec28[1] - float((iSlow45 * ((fSlow47 + fRec28[1]) > fSlow46)))));
			int 	iTemp44 = int(fRec28[0]);
			float 	fTemp45 = ftbl0[iTemp44];
			float 	fTemp46 = (fTemp45 + ((fRec28[0] - float(iTemp44)) * (ftbl0[((iTemp44 + 1) % iSlow45)] - fTemp45)));
			fRec27[0] = (fTemp46 - (((fSlow7 * fRec27[2]) + (2.0f * (fSlow6 * fRec27[1]))) / fSlow5));
			fRec29[0] = (fTemp46 - (((fSlow20 * fRec29[2]) + (2.0f * (fSlow19 * fRec29[1]))) / fSlow18));
			fRec30[0] = (fTemp46 - (((fSlow29 * fRec30[2]) + (2.0f * (fSlow28 * fRec30[1]))) / fSlow27));
			fRec31[0] = (fSlow48 - (fConst30 * ((fConst28 * fRec31[2]) + (fConst26 * fRec31[1]))));
			float 	fTemp47 = ((fConst31 * (((3947.8417604357433f * fRec31[0]) + (7895.6835208714865f * fRec31[1])) + (3947.8417604357433f * fRec31[2]))) + 1.0f);
			float 	fTemp48 = (0.5f * fTemp47);
			float 	fTemp49 = max(fTemp48, (float)0);
			float 	fTemp50 = tanf((fConst32 * ((fSlow50 * (fTemp47 * fTemp49)) + 200.0f)));
			float 	fTemp51 = ((fTemp50 * (fTemp50 + 0.5f)) + 1.0f);
			float 	fTemp52 = (fRec32[1] + (fTemp50 * (fTemp46 - fRec33[1])));
			float 	fTemp53 = (fTemp52 / fTemp51);
			fRec32[0] = ((2.0f * fTemp53) - fRec32[1]);
			float 	fTemp54 = (fRec33[1] + ((fTemp50 * fTemp52) / fTemp51));
			fRec33[0] = ((2.0f * fTemp54) - fRec33[1]);
			float 	fRec34 = fTemp53;
			float 	fTemp55 = max((-1 * fTemp48), (float)0);
			float 	fTemp56 = (1.0f / ((int((iSlow55 == ((fRec41[1] > 0.0f) - (fRec41[1] < 0.0f)))))?((int((fSlow53 >= fabsf(fRec41[1]))))?fConst33:fConst0):fSlow54));
			float 	fTemp57 = (fRec42[1] - fTemp56);
			float 	fTemp58 = (fRec42[1] + fTemp56);
			fRec42[0] = ((int((fTemp58 < fSlow48)))?fTemp58:((int((fTemp57 > fSlow48)))?fTemp57:fSlow48));
			fRec41[0] = fRec42[0];
			int 	iTemp59 = ((fRec41[0] > 0.0f) + (1 - (fRec41[0] < 0.0f)));
			int 	iTemp60 = int((iTemp59 == 1));
			int 	iTemp61 = int((iTemp59 == 0));
			float 	fTemp62 = ((iTemp61)?1.7f:((iTemp60)?1.2f:1.1000000000000001f));
			iRec43[0] = iRec39[1];
			int 	iTemp63 = int((iRec43[1] == iRec39[1]));
			int 	iTemp64 = int((iRec39[1] == 0));
			fRec44[0] = ((iTemp64)?fSlow49:((iTemp63)?min(min(fRec44[1], fSlow49), fRec40[1]):min(fSlow49, fRec40[1])));
			float 	fTemp65 = (fSlow49 * fTemp62);
			int 	iTemp66 = int((iRec39[1] == 1));
			fRec45[0] = ((iTemp64)?fSlow49:((iTemp66)?((iTemp63)?max(max(fRec45[1], fTemp65), fRec40[1]):max(fTemp65, fRec40[1])):((iTemp63)?max(max(fRec45[1], fSlow49), fRec40[1]):max(fSlow49, fRec40[1]))));
			fbargraph3 = fRec44[0];
			iRec46[0] = iRec39[1];
			iRec47[0] = ((int((iRec46[1] != iRec39[1])))?iTemp23:iRec47[1]);
			int 	iTemp67 = int((iRec39[1] >= 1));
			int 	iTemp68 = int((fSlow49 >= fRec40[1]));
			int 	iTemp69 = int((iRec39[1] >= 3));
			int 	iTemp70 = int((iRec39[1] >= 2));
			int 	iTemp71 = int((iRec39[1] >= 5));
			int 	iTemp72 = int((iRec39[1] >= 6));
			int 	iTemp73 = int((iRec39[1] >= 4));
			fbargraph4 = ((iTemp73)?((iTemp72)?((iSlow56)?3:((iTemp68)?5:6)):((iTemp71)?((iSlow56)?3:((int((fSlow49 <= fRec40[1])))?6:5)):((int((fRec40[1] <= 0.01f)))?0:4))):((iTemp70)?((iTemp69)?((int((iSlow58 & (fRec40[1] <= 0.0f))))?0:((int((fSlow49 > fRec40[1])))?4:3)):((iTemp68)?5:iSlow57)):((iTemp67)?((int(((float((iRec22[0] + (-1 - iRec47[0]))) >= fConst33) & (fRec40[1] >= (fbargraph3 * fTemp62)))))?2:1):iSlow52)));
			iRec39[0] = fbargraph4;
			float 	fTemp74 = ((iTemp66)?fTemp65:fSlow49);
			float 	fTemp75 = ((iTemp73)?((iTemp72)?fConst37:((iTemp71)?fConst37:fConst36)):((iTemp70)?((iTemp69)?fConst35:fConst34):((iTemp67)?fConst33:0.0f)));
			float 	fTemp76 = fabsf(fRec41[0]);
			fbargraph5 = ((fTemp76 * ((iTemp61)?((iTemp73)?((iTemp72)?fConst0:((iTemp71)?fConst0:fConst36)):((iTemp70)?((iTemp69)?fConst39:fConst33):((iTemp67)?fConst38:0.0f))):((iTemp60)?fTemp75:((iTemp73)?fConst36:((iTemp70)?fConst36:((iTemp67)?fConst36:0.0f)))))) + ((1.0f - fTemp76) * fTemp75));
			float 	fTemp77 = (1.0f / fbargraph5);
			float 	fTemp78 = (fRec48[1] - fTemp77);
			float 	fTemp79 = (fRec48[1] + fTemp77);
			fRec48[0] = ((int((fTemp79 < fTemp74)))?fTemp79:((int((fTemp78 > fTemp74)))?fTemp78:fTemp74));
			fRec40[0] = fRec48[0];
			fRec38[0] = (fRec40[0] - (fConst30 * ((fConst28 * fRec38[2]) + (fConst26 * fRec38[1]))));
			float 	fTemp80 = (((3947.8417604357433f * fRec38[0]) + (7895.6835208714865f * fRec38[1])) + (3947.8417604357433f * fRec38[2]));
			float 	fTemp81 = tanf((fConst32 * min((fSlow59 * (faustpower<2>((fTemp38 + (fConst31 * (fTemp80 * (1.0f - fTemp55))))) + 1.0f)), (float)16000)));
			float 	fTemp82 = ((fTemp81 * (fTemp81 + (1.0f / ((8.0f * fTemp55) + 1.0f)))) + 1.0f);
			float 	fTemp83 = (fRec35[1] + (fTemp81 * (fTemp46 - fRec36[1])));
			float 	fTemp84 = (fTemp83 / fTemp82);
			fRec35[0] = ((2.0f * fTemp84) - fRec35[1]);
			float 	fTemp85 = (fRec36[1] + ((fTemp81 * fTemp83) / fTemp82));
			fRec36[0] = ((2.0f * fTemp85) - fRec36[1]);
			float 	fRec37 = fTemp85;
			fRec50[0] = (fSlow63 + (fRec50[1] - float((iSlow61 * ((fSlow63 + fRec50[1]) > fSlow62)))));
			int 	iTemp86 = int(fRec50[0]);
			float 	fTemp87 = ftbl0[iTemp86];
			float 	fTemp88 = (fTemp87 + ((fRec50[0] - float(iTemp86)) * (ftbl0[((iTemp86 + 1) % iSlow61)] - fTemp87)));
			fRec49[0] = (fTemp88 - (((fSlow7 * fRec49[2]) + (2.0f * (fSlow6 * fRec49[1]))) / fSlow5));
			fRec51[0] = (fTemp88 - (((fSlow20 * fRec51[2]) + (2.0f * (fSlow19 * fRec51[1]))) / fSlow18));
			fRec52[0] = (fTemp88 - (((fSlow29 * fRec52[2]) + (2.0f * (fSlow28 * fRec52[1]))) / fSlow27));
			fRec53[0] = (fSlow64 - (fConst30 * ((fConst28 * fRec53[2]) + (fConst26 * fRec53[1]))));
			float 	fTemp89 = ((fConst31 * (((3947.8417604357433f * fRec53[0]) + (7895.6835208714865f * fRec53[1])) + (3947.8417604357433f * fRec53[2]))) + 1.0f);
			float 	fTemp90 = (0.5f * fTemp89);
			float 	fTemp91 = max(fTemp90, (float)0);
			float 	fTemp92 = tanf((fConst32 * ((fSlow66 * (fTemp89 * fTemp91)) + 200.0f)));
			float 	fTemp93 = ((fTemp92 * (fTemp92 + 0.5f)) + 1.0f);
			float 	fTemp94 = (fRec54[1] + (fTemp92 * (fTemp88 - fRec55[1])));
			float 	fTemp95 = (fTemp94 / fTemp93);
			fRec54[0] = ((2.0f * fTemp95) - fRec54[1]);
			float 	fTemp96 = (fRec55[1] + ((fTemp92 * fTemp94) / fTemp93));
			fRec55[0] = ((2.0f * fTemp96) - fRec55[1]);
			float 	fRec56 = fTemp95;
			float 	fTemp97 = max((-1 * fTemp90), (float)0);
			float 	fTemp98 = (1.0f / ((int((iSlow71 == ((fRec63[1] > 0.0f) - (fRec63[1] < 0.0f)))))?((int((fSlow69 >= fabsf(fRec63[1]))))?fConst33:fConst0):fSlow70));
			float 	fTemp99 = (fRec64[1] - fTemp98);
			float 	fTemp100 = (fRec64[1] + fTemp98);
			fRec64[0] = ((int((fTemp100 < fSlow64)))?fTemp100:((int((fTemp99 > fSlow64)))?fTemp99:fSlow64));
			fRec63[0] = fRec64[0];
			int 	iTemp101 = ((fRec63[0] > 0.0f) + (1 - (fRec63[0] < 0.0f)));
			int 	iTemp102 = int((iTemp101 == 1));
			int 	iTemp103 = int((iTemp101 == 0));
			float 	fTemp104 = ((iTemp103)?1.7f:((iTemp102)?1.2f:1.1000000000000001f));
			iRec65[0] = iRec61[1];
			int 	iTemp105 = int((iRec65[1] == iRec61[1]));
			int 	iTemp106 = int((iRec61[1] == 0));
			fRec66[0] = ((iTemp106)?fSlow65:((iTemp105)?min(min(fRec66[1], fSlow65), fRec62[1]):min(fSlow65, fRec62[1])));
			float 	fTemp107 = (fSlow65 * fTemp104);
			int 	iTemp108 = int((iRec61[1] == 1));
			fRec67[0] = ((iTemp106)?fSlow65:((iTemp108)?((iTemp105)?max(max(fRec67[1], fTemp107), fRec62[1]):max(fTemp107, fRec62[1])):((iTemp105)?max(max(fRec67[1], fSlow65), fRec62[1]):max(fSlow65, fRec62[1]))));
			fbargraph6 = fRec66[0];
			iRec68[0] = iRec61[1];
			iRec69[0] = ((int((iRec68[1] != iRec61[1])))?iTemp23:iRec69[1]);
			int 	iTemp109 = int((iRec61[1] >= 1));
			int 	iTemp110 = int((fSlow65 >= fRec62[1]));
			int 	iTemp111 = int((iRec61[1] >= 3));
			int 	iTemp112 = int((iRec61[1] >= 2));
			int 	iTemp113 = int((iRec61[1] >= 5));
			int 	iTemp114 = int((iRec61[1] >= 6));
			int 	iTemp115 = int((iRec61[1] >= 4));
			fbargraph7 = ((iTemp115)?((iTemp114)?((iSlow72)?3:((iTemp110)?5:6)):((iTemp113)?((iSlow72)?3:((int((fSlow65 <= fRec62[1])))?6:5)):((int((fRec62[1] <= 0.01f)))?0:4))):((iTemp112)?((iTemp111)?((int((iSlow74 & (fRec62[1] <= 0.0f))))?0:((int((fSlow65 > fRec62[1])))?4:3)):((iTemp110)?5:iSlow73)):((iTemp109)?((int(((float((iRec22[0] + (-1 - iRec69[0]))) >= fConst33) & (fRec62[1] >= (fbargraph6 * fTemp104)))))?2:1):iSlow68)));
			iRec61[0] = fbargraph7;
			float 	fTemp116 = ((iTemp108)?fTemp107:fSlow65);
			float 	fTemp117 = ((iTemp115)?((iTemp114)?fConst37:((iTemp113)?fConst37:fConst36)):((iTemp112)?((iTemp111)?fConst35:fConst34):((iTemp109)?fConst33:0.0f)));
			float 	fTemp118 = fabsf(fRec63[0]);
			fbargraph8 = ((fTemp118 * ((iTemp103)?((iTemp115)?((iTemp114)?fConst0:((iTemp113)?fConst0:fConst36)):((iTemp112)?((iTemp111)?fConst39:fConst33):((iTemp109)?fConst38:0.0f))):((iTemp102)?fTemp117:((iTemp115)?fConst36:((iTemp112)?fConst36:((iTemp109)?fConst36:0.0f)))))) + ((1.0f - fTemp118) * fTemp117));
			float 	fTemp119 = (1.0f / fbargraph8);
			float 	fTemp120 = (fRec70[1] - fTemp119);
			float 	fTemp121 = (fRec70[1] + fTemp119);
			fRec70[0] = ((int((fTemp121 < fTemp116)))?fTemp121:((int((fTemp120 > fTemp116)))?fTemp120:fTemp116));
			fRec62[0] = fRec70[0];
			fRec60[0] = (fRec62[0] - (fConst30 * ((fConst28 * fRec60[2]) + (fConst26 * fRec60[1]))));
			float 	fTemp122 = (((3947.8417604357433f * fRec60[0]) + (7895.6835208714865f * fRec60[1])) + (3947.8417604357433f * fRec60[2]));
			float 	fTemp123 = tanf((fConst32 * min((fSlow75 * (faustpower<2>((fTemp38 + (fConst31 * (fTemp122 * (1.0f - fTemp97))))) + 1.0f)), (float)16000)));
			float 	fTemp124 = ((fTemp123 * (fTemp123 + (1.0f / ((8.0f * fTemp97) + 1.0f)))) + 1.0f);
			float 	fTemp125 = (fRec57[1] + (fTemp123 * (fTemp88 - fRec58[1])));
			float 	fTemp126 = (fTemp125 / fTemp124);
			fRec57[0] = ((2.0f * fTemp126) - fRec57[1]);
			float 	fTemp127 = (fRec58[1] + ((fTemp123 * fTemp125) / fTemp124));
			fRec58[0] = ((2.0f * fTemp127) - fRec58[1]);
			float 	fRec59 = fTemp127;
			fRec72[0] = (fSlow79 + (fRec72[1] - float((iSlow77 * ((fSlow79 + fRec72[1]) > fSlow78)))));
			int 	iTemp128 = int(fRec72[0]);
			float 	fTemp129 = ftbl0[iTemp128];
			float 	fTemp130 = (fTemp129 + ((fRec72[0] - float(iTemp128)) * (ftbl0[((iTemp128 + 1) % iSlow77)] - fTemp129)));
			fRec71[0] = (fTemp130 - (((fSlow7 * fRec71[2]) + (2.0f * (fSlow6 * fRec71[1]))) / fSlow5));
			fRec73[0] = (fTemp130 - (((fSlow20 * fRec73[2]) + (2.0f * (fSlow19 * fRec73[1]))) / fSlow18));
			fRec74[0] = (fTemp130 - (((fSlow29 * fRec74[2]) + (2.0f * (fSlow28 * fRec74[1]))) / fSlow27));
			fRec75[0] = (fSlow80 - (fConst30 * ((fConst28 * fRec75[2]) + (fConst26 * fRec75[1]))));
			float 	fTemp131 = ((fConst31 * (((3947.8417604357433f * fRec75[0]) + (7895.6835208714865f * fRec75[1])) + (3947.8417604357433f * fRec75[2]))) + 1.0f);
			float 	fTemp132 = (0.5f * fTemp131);
			float 	fTemp133 = max(fTemp132, (float)0);
			float 	fTemp134 = tanf((fConst32 * ((fSlow82 * (fTemp131 * fTemp133)) + 200.0f)));
			float 	fTemp135 = ((fTemp134 * (fTemp134 + 0.5f)) + 1.0f);
			float 	fTemp136 = (fRec76[1] + (fTemp134 * (fTemp130 - fRec77[1])));
			float 	fTemp137 = (fTemp136 / fTemp135);
			fRec76[0] = ((2.0f * fTemp137) - fRec76[1]);
			float 	fTemp138 = (fRec77[1] + ((fTemp134 * fTemp136) / fTemp135));
			fRec77[0] = ((2.0f * fTemp138) - fRec77[1]);
			float 	fRec78 = fTemp137;
			float 	fTemp139 = max((-1 * fTemp132), (float)0);
			float 	fTemp140 = (1.0f / ((int((iSlow87 == ((fRec85[1] > 0.0f) - (fRec85[1] < 0.0f)))))?((int((fSlow85 >= fabsf(fRec85[1]))))?fConst33:fConst0):fSlow86));
			float 	fTemp141 = (fRec86[1] - fTemp140);
			float 	fTemp142 = (fRec86[1] + fTemp140);
			fRec86[0] = ((int((fTemp142 < fSlow80)))?fTemp142:((int((fTemp141 > fSlow80)))?fTemp141:fSlow80));
			fRec85[0] = fRec86[0];
			int 	iTemp143 = ((fRec85[0] > 0.0f) + (1 - (fRec85[0] < 0.0f)));
			int 	iTemp144 = int((iTemp143 == 1));
			int 	iTemp145 = int((iTemp143 == 0));
			float 	fTemp146 = ((iTemp145)?1.7f:((iTemp144)?1.2f:1.1000000000000001f));
			iRec87[0] = iRec83[1];
			int 	iTemp147 = int((iRec87[1] == iRec83[1]));
			int 	iTemp148 = int((iRec83[1] == 0));
			fRec88[0] = ((iTemp148)?fSlow81:((iTemp147)?min(min(fRec88[1], fSlow81), fRec84[1]):min(fSlow81, fRec84[1])));
			float 	fTemp149 = (fSlow81 * fTemp146);
			int 	iTemp150 = int((iRec83[1] == 1));
			fRec89[0] = ((iTemp148)?fSlow81:((iTemp150)?((iTemp147)?max(max(fRec89[1], fTemp149), fRec84[1]):max(fTemp149, fRec84[1])):((iTemp147)?max(max(fRec89[1], fSlow81), fRec84[1]):max(fSlow81, fRec84[1]))));
			fbargraph9 = fRec88[0];
			iRec90[0] = iRec83[1];
			iRec91[0] = ((int((iRec90[1] != iRec83[1])))?iTemp23:iRec91[1]);
			int 	iTemp151 = int((iRec83[1] >= 1));
			int 	iTemp152 = int((fSlow81 >= fRec84[1]));
			int 	iTemp153 = int((iRec83[1] >= 3));
			int 	iTemp154 = int((iRec83[1] >= 2));
			int 	iTemp155 = int((iRec83[1] >= 5));
			int 	iTemp156 = int((iRec83[1] >= 6));
			int 	iTemp157 = int((iRec83[1] >= 4));
			fbargraph10 = ((iTemp157)?((iTemp156)?((iSlow88)?3:((iTemp152)?5:6)):((iTemp155)?((iSlow88)?3:((int((fSlow81 <= fRec84[1])))?6:5)):((int((fRec84[1] <= 0.01f)))?0:4))):((iTemp154)?((iTemp153)?((int((iSlow90 & (fRec84[1] <= 0.0f))))?0:((int((fSlow81 > fRec84[1])))?4:3)):((iTemp152)?5:iSlow89)):((iTemp151)?((int(((float((iRec22[0] + (-1 - iRec91[0]))) >= fConst33) & (fRec84[1] >= (fbargraph9 * fTemp146)))))?2:1):iSlow84)));
			iRec83[0] = fbargraph10;
			float 	fTemp158 = ((iTemp150)?fTemp149:fSlow81);
			float 	fTemp159 = ((iTemp157)?((iTemp156)?fConst37:((iTemp155)?fConst37:fConst36)):((iTemp154)?((iTemp153)?fConst35:fConst34):((iTemp151)?fConst33:0.0f)));
			float 	fTemp160 = fabsf(fRec85[0]);
			fbargraph11 = ((fTemp160 * ((iTemp145)?((iTemp157)?((iTemp156)?fConst0:((iTemp155)?fConst0:fConst36)):((iTemp154)?((iTemp153)?fConst39:fConst33):((iTemp151)?fConst38:0.0f))):((iTemp144)?fTemp159:((iTemp157)?fConst36:((iTemp154)?fConst36:((iTemp151)?fConst36:0.0f)))))) + ((1.0f - fTemp160) * fTemp159));
			float 	fTemp161 = (1.0f / fbargraph11);
			float 	fTemp162 = (fRec92[1] - fTemp161);
			float 	fTemp163 = (fRec92[1] + fTemp161);
			fRec92[0] = ((int((fTemp163 < fTemp158)))?fTemp163:((int((fTemp162 > fTemp158)))?fTemp162:fTemp158));
			fRec84[0] = fRec92[0];
			fRec82[0] = (fRec84[0] - (fConst30 * ((fConst28 * fRec82[2]) + (fConst26 * fRec82[1]))));
			float 	fTemp164 = (((3947.8417604357433f * fRec82[0]) + (7895.6835208714865f * fRec82[1])) + (3947.8417604357433f * fRec82[2]));
			float 	fTemp165 = tanf((fConst32 * min((fSlow91 * (faustpower<2>((fTemp38 + (fConst31 * (fTemp164 * (1.0f - fTemp139))))) + 1.0f)), (float)16000)));
			float 	fTemp166 = ((fTemp165 * (fTemp165 + (1.0f / ((8.0f * fTemp139) + 1.0f)))) + 1.0f);
			float 	fTemp167 = (fRec79[1] + (fTemp165 * (fTemp130 - fRec80[1])));
			float 	fTemp168 = (fTemp167 / fTemp166);
			fRec79[0] = ((2.0f * fTemp168) - fRec79[1]);
			float 	fTemp169 = (fRec80[1] + ((fTemp165 * fTemp167) / fTemp166));
			fRec80[0] = ((2.0f * fTemp169) - fRec80[1]);
			float 	fRec81 = fTemp169;
			fRec94[0] = (fSlow95 + (fRec94[1] - float((iSlow93 * ((fSlow95 + fRec94[1]) > fSlow94)))));
			int 	iTemp170 = int(fRec94[0]);
			float 	fTemp171 = ftbl0[iTemp170];
			float 	fTemp172 = (fTemp171 + ((fRec94[0] - float(iTemp170)) * (ftbl0[((iTemp170 + 1) % iSlow93)] - fTemp171)));
			fRec93[0] = (fTemp172 - (((fSlow7 * fRec93[2]) + (2.0f * (fSlow6 * fRec93[1]))) / fSlow5));
			fRec95[0] = (fTemp172 - (((fSlow20 * fRec95[2]) + (2.0f * (fSlow19 * fRec95[1]))) / fSlow18));
			fRec96[0] = (fTemp172 - (((fSlow29 * fRec96[2]) + (2.0f * (fSlow28 * fRec96[1]))) / fSlow27));
			fRec97[0] = (fSlow96 - (fConst30 * ((fConst28 * fRec97[2]) + (fConst26 * fRec97[1]))));
			float 	fTemp173 = ((fConst31 * (((3947.8417604357433f * fRec97[0]) + (7895.6835208714865f * fRec97[1])) + (3947.8417604357433f * fRec97[2]))) + 1.0f);
			float 	fTemp174 = (0.5f * fTemp173);
			float 	fTemp175 = max(fTemp174, (float)0);
			float 	fTemp176 = tanf((fConst32 * ((fSlow98 * (fTemp173 * fTemp175)) + 200.0f)));
			float 	fTemp177 = ((fTemp176 * (fTemp176 + 0.5f)) + 1.0f);
			float 	fTemp178 = (fRec98[1] + (fTemp176 * (fTemp172 - fRec99[1])));
			float 	fTemp179 = (fTemp178 / fTemp177);
			fRec98[0] = ((2.0f * fTemp179) - fRec98[1]);
			float 	fTemp180 = (fRec99[1] + ((fTemp176 * fTemp178) / fTemp177));
			fRec99[0] = ((2.0f * fTemp180) - fRec99[1]);
			float 	fRec100 = fTemp179;
			float 	fTemp181 = max((-1 * fTemp174), (float)0);
			float 	fTemp182 = (1.0f / ((int((iSlow103 == ((fRec107[1] > 0.0f) - (fRec107[1] < 0.0f)))))?((int((fSlow101 >= fabsf(fRec107[1]))))?fConst33:fConst0):fSlow102));
			float 	fTemp183 = (fRec108[1] - fTemp182);
			float 	fTemp184 = (fRec108[1] + fTemp182);
			fRec108[0] = ((int((fTemp184 < fSlow96)))?fTemp184:((int((fTemp183 > fSlow96)))?fTemp183:fSlow96));
			fRec107[0] = fRec108[0];
			int 	iTemp185 = ((fRec107[0] > 0.0f) + (1 - (fRec107[0] < 0.0f)));
			int 	iTemp186 = int((iTemp185 == 1));
			int 	iTemp187 = int((iTemp185 == 0));
			float 	fTemp188 = ((iTemp187)?1.7f:((iTemp186)?1.2f:1.1000000000000001f));
			iRec109[0] = iRec105[1];
			int 	iTemp189 = int((iRec109[1] == iRec105[1]));
			int 	iTemp190 = int((iRec105[1] == 0));
			fRec110[0] = ((iTemp190)?fSlow97:((iTemp189)?min(min(fRec110[1], fSlow97), fRec106[1]):min(fSlow97, fRec106[1])));
			float 	fTemp191 = (fSlow97 * fTemp188);
			int 	iTemp192 = int((iRec105[1] == 1));
			fRec111[0] = ((iTemp190)?fSlow97:((iTemp192)?((iTemp189)?max(max(fRec111[1], fTemp191), fRec106[1]):max(fTemp191, fRec106[1])):((iTemp189)?max(max(fRec111[1], fSlow97), fRec106[1]):max(fSlow97, fRec106[1]))));
			fbargraph12 = fRec110[0];
			iRec112[0] = iRec105[1];
			iRec113[0] = ((int((iRec112[1] != iRec105[1])))?iTemp23:iRec113[1]);
			int 	iTemp193 = int((iRec105[1] >= 1));
			int 	iTemp194 = int((fSlow97 >= fRec106[1]));
			int 	iTemp195 = int((iRec105[1] >= 3));
			int 	iTemp196 = int((iRec105[1] >= 2));
			int 	iTemp197 = int((iRec105[1] >= 5));
			int 	iTemp198 = int((iRec105[1] >= 6));
			int 	iTemp199 = int((iRec105[1] >= 4));
			fbargraph13 = ((iTemp199)?((iTemp198)?((iSlow104)?3:((iTemp194)?5:6)):((iTemp197)?((iSlow104)?3:((int((fSlow97 <= fRec106[1])))?6:5)):((int((fRec106[1] <= 0.01f)))?0:4))):((iTemp196)?((iTemp195)?((int((iSlow106 & (fRec106[1] <= 0.0f))))?0:((int((fSlow97 > fRec106[1])))?4:3)):((iTemp194)?5:iSlow105)):((iTemp193)?((int(((float((iRec22[0] + (-1 - iRec113[0]))) >= fConst33) & (fRec106[1] >= (fbargraph12 * fTemp188)))))?2:1):iSlow100)));
			iRec105[0] = fbargraph13;
			float 	fTemp200 = ((iTemp192)?fTemp191:fSlow97);
			float 	fTemp201 = ((iTemp199)?((iTemp198)?fConst37:((iTemp197)?fConst37:fConst36)):((iTemp196)?((iTemp195)?fConst35:fConst34):((iTemp193)?fConst33:0.0f)));
			float 	fTemp202 = fabsf(fRec107[0]);
			fbargraph14 = ((fTemp202 * ((iTemp187)?((iTemp199)?((iTemp198)?fConst0:((iTemp197)?fConst0:fConst36)):((iTemp196)?((iTemp195)?fConst39:fConst33):((iTemp193)?fConst38:0.0f))):((iTemp186)?fTemp201:((iTemp199)?fConst36:((iTemp196)?fConst36:((iTemp193)?fConst36:0.0f)))))) + ((1.0f - fTemp202) * fTemp201));
			float 	fTemp203 = (1.0f / fbargraph14);
			float 	fTemp204 = (fRec114[1] - fTemp203);
			float 	fTemp205 = (fRec114[1] + fTemp203);
			fRec114[0] = ((int((fTemp205 < fTemp200)))?fTemp205:((int((fTemp204 > fTemp200)))?fTemp204:fTemp200));
			fRec106[0] = fRec114[0];
			fRec104[0] = (fRec106[0] - (fConst30 * ((fConst28 * fRec104[2]) + (fConst26 * fRec104[1]))));
			float 	fTemp206 = (((3947.8417604357433f * fRec104[0]) + (7895.6835208714865f * fRec104[1])) + (3947.8417604357433f * fRec104[2]));
			float 	fTemp207 = tanf((fConst32 * min((fSlow107 * (faustpower<2>((fTemp38 + (fConst31 * (fTemp206 * (1.0f - fTemp181))))) + 1.0f)), (float)16000)));
			float 	fTemp208 = ((fTemp207 * (fTemp207 + (1.0f / ((8.0f * fTemp181) + 1.0f)))) + 1.0f);
			float 	fTemp209 = (fRec101[1] + (fTemp207 * (fTemp172 - fRec102[1])));
			float 	fTemp210 = (fTemp209 / fTemp208);
			fRec101[0] = ((2.0f * fTemp210) - fRec101[1]);
			float 	fTemp211 = (fRec102[1] + ((fTemp207 * fTemp209) / fTemp208));
			fRec102[0] = ((2.0f * fTemp211) - fRec102[1]);
			float 	fRec103 = fTemp211;
			fRec116[0] = (fSlow111 + (fRec116[1] - float((iSlow109 * ((fSlow111 + fRec116[1]) > fSlow110)))));
			int 	iTemp212 = int(fRec116[0]);
			float 	fTemp213 = ftbl0[iTemp212];
			float 	fTemp214 = (fTemp213 + ((fRec116[0] - float(iTemp212)) * (ftbl0[((iTemp212 + 1) % iSlow109)] - fTemp213)));
			fRec115[0] = (fTemp214 - (((fSlow7 * fRec115[2]) + (2.0f * (fSlow6 * fRec115[1]))) / fSlow5));
			fRec117[0] = (fTemp214 - (((fSlow20 * fRec117[2]) + (2.0f * (fSlow19 * fRec117[1]))) / fSlow18));
			fRec118[0] = (fTemp214 - (((fSlow29 * fRec118[2]) + (2.0f * (fSlow28 * fRec118[1]))) / fSlow27));
			fRec119[0] = (fSlow112 - (fConst30 * ((fConst28 * fRec119[2]) + (fConst26 * fRec119[1]))));
			float 	fTemp215 = ((fConst31 * (((3947.8417604357433f * fRec119[0]) + (7895.6835208714865f * fRec119[1])) + (3947.8417604357433f * fRec119[2]))) + 1.0f);
			float 	fTemp216 = (0.5f * fTemp215);
			float 	fTemp217 = max(fTemp216, (float)0);
			float 	fTemp218 = tanf((fConst32 * ((fSlow114 * (fTemp215 * fTemp217)) + 200.0f)));
			float 	fTemp219 = ((fTemp218 * (fTemp218 + 0.5f)) + 1.0f);
			float 	fTemp220 = (fRec120[1] + (fTemp218 * (fTemp214 - fRec121[1])));
			float 	fTemp221 = (fTemp220 / fTemp219);
			fRec120[0] = ((2.0f * fTemp221) - fRec120[1]);
			float 	fTemp222 = (fRec121[1] + ((fTemp218 * fTemp220) / fTemp219));
			fRec121[0] = ((2.0f * fTemp222) - fRec121[1]);
			float 	fRec122 = fTemp221;
			float 	fTemp223 = max((-1 * fTemp216), (float)0);
			float 	fTemp224 = (1.0f / ((int((iSlow119 == ((fRec129[1] > 0.0f) - (fRec129[1] < 0.0f)))))?((int((fSlow117 >= fabsf(fRec129[1]))))?fConst33:fConst0):fSlow118));
			float 	fTemp225 = (fRec130[1] - fTemp224);
			float 	fTemp226 = (fRec130[1] + fTemp224);
			fRec130[0] = ((int((fTemp226 < fSlow112)))?fTemp226:((int((fTemp225 > fSlow112)))?fTemp225:fSlow112));
			fRec129[0] = fRec130[0];
			int 	iTemp227 = ((fRec129[0] > 0.0f) + (1 - (fRec129[0] < 0.0f)));
			int 	iTemp228 = int((iTemp227 == 1));
			int 	iTemp229 = int((iTemp227 == 0));
			float 	fTemp230 = ((iTemp229)?1.7f:((iTemp228)?1.2f:1.1000000000000001f));
			iRec131[0] = iRec127[1];
			int 	iTemp231 = int((iRec131[1] == iRec127[1]));
			int 	iTemp232 = int((iRec127[1] == 0));
			fRec132[0] = ((iTemp232)?fSlow113:((iTemp231)?min(min(fRec132[1], fSlow113), fRec128[1]):min(fSlow113, fRec128[1])));
			float 	fTemp233 = (fSlow113 * fTemp230);
			int 	iTemp234 = int((iRec127[1] == 1));
			fRec133[0] = ((iTemp232)?fSlow113:((iTemp234)?((iTemp231)?max(max(fRec133[1], fTemp233), fRec128[1]):max(fTemp233, fRec128[1])):((iTemp231)?max(max(fRec133[1], fSlow113), fRec128[1]):max(fSlow113, fRec128[1]))));
			fbargraph15 = fRec132[0];
			iRec134[0] = iRec127[1];
			iRec135[0] = ((int((iRec134[1] != iRec127[1])))?iTemp23:iRec135[1]);
			int 	iTemp235 = int((iRec127[1] >= 1));
			int 	iTemp236 = int((fSlow113 >= fRec128[1]));
			int 	iTemp237 = int((iRec127[1] >= 3));
			int 	iTemp238 = int((iRec127[1] >= 2));
			int 	iTemp239 = int((iRec127[1] >= 5));
			int 	iTemp240 = int((iRec127[1] >= 6));
			int 	iTemp241 = int((iRec127[1] >= 4));
			fbargraph16 = ((iTemp241)?((iTemp240)?((iSlow120)?3:((iTemp236)?5:6)):((iTemp239)?((iSlow120)?3:((int((fSlow113 <= fRec128[1])))?6:5)):((int((fRec128[1] <= 0.01f)))?0:4))):((iTemp238)?((iTemp237)?((int((iSlow122 & (fRec128[1] <= 0.0f))))?0:((int((fSlow113 > fRec128[1])))?4:3)):((iTemp236)?5:iSlow121)):((iTemp235)?((int(((float((iRec22[0] + (-1 - iRec135[0]))) >= fConst33) & (fRec128[1] >= (fbargraph15 * fTemp230)))))?2:1):iSlow116)));
			iRec127[0] = fbargraph16;
			float 	fTemp242 = ((iTemp234)?fTemp233:fSlow113);
			float 	fTemp243 = ((iTemp241)?((iTemp240)?fConst37:((iTemp239)?fConst37:fConst36)):((iTemp238)?((iTemp237)?fConst35:fConst34):((iTemp235)?fConst33:0.0f)));
			float 	fTemp244 = fabsf(fRec129[0]);
			fbargraph17 = ((fTemp244 * ((iTemp229)?((iTemp241)?((iTemp240)?fConst0:((iTemp239)?fConst0:fConst36)):((iTemp238)?((iTemp237)?fConst39:fConst33):((iTemp235)?fConst38:0.0f))):((iTemp228)?fTemp243:((iTemp241)?fConst36:((iTemp238)?fConst36:((iTemp235)?fConst36:0.0f)))))) + ((1.0f - fTemp244) * fTemp243));
			float 	fTemp245 = (1.0f / fbargraph17);
			float 	fTemp246 = (fRec136[1] - fTemp245);
			float 	fTemp247 = (fRec136[1] + fTemp245);
			fRec136[0] = ((int((fTemp247 < fTemp242)))?fTemp247:((int((fTemp246 > fTemp242)))?fTemp246:fTemp242));
			fRec128[0] = fRec136[0];
			fRec126[0] = (fRec128[0] - (fConst30 * ((fConst28 * fRec126[2]) + (fConst26 * fRec126[1]))));
			float 	fTemp248 = (((3947.8417604357433f * fRec126[0]) + (7895.6835208714865f * fRec126[1])) + (3947.8417604357433f * fRec126[2]));
			float 	fTemp249 = tanf((fConst32 * min((fSlow123 * (faustpower<2>(((fConst31 * (fTemp248 * (1.0f - fTemp223))) + fTemp38)) + 1.0f)), (float)16000)));
			float 	fTemp250 = ((fTemp249 * (fTemp249 + (1.0f / ((8.0f * fTemp223) + 1.0f)))) + 1.0f);
			float 	fTemp251 = (fRec123[1] + (fTemp249 * (fTemp214 - fRec124[1])));
			float 	fTemp252 = (fTemp251 / fTemp250);
			fRec123[0] = ((2.0f * fTemp252) - fRec123[1]);
			float 	fTemp253 = (fRec124[1] + ((fTemp249 * fTemp251) / fTemp250));
			fRec124[0] = ((2.0f * fTemp253) - fRec124[1]);
			float 	fRec125 = fTemp253;
			fRec0[0] = ((fConst54 * ((((((fTemp248 * (((fRec125 * faustpower<2>((1.0f - (0.5f * fTemp223)))) + (fSlow115 * ((fRec122 * fTemp215) * fTemp217))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec118[0] - fRec118[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec117[0] - fRec117[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec115[0] - fRec115[2])) / fSlow5)))))))) + (fTemp206 * (((fRec103 * faustpower<2>((1.0f - (0.5f * fTemp181)))) + (fSlow99 * ((fRec100 * fTemp173) * fTemp175))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec96[0] - fRec96[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec95[0] - fRec95[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec93[0] - fRec93[2])) / fSlow5))))))))) + (fTemp164 * (((fRec81 * faustpower<2>((1.0f - (0.5f * fTemp139)))) + (fSlow83 * ((fRec78 * fTemp131) * fTemp133))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec74[0] - fRec74[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec73[0] - fRec73[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec71[0] - fRec71[2])) / fSlow5))))))))) + (fTemp122 * (((fRec59 * faustpower<2>((1.0f - (0.5f * fTemp97)))) + (fSlow67 * ((fRec56 * fTemp89) * fTemp91))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec52[0] - fRec52[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec51[0] - fRec51[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec49[0] - fRec49[2])) / fSlow5))))))))) + (fTemp80 * (((fRec37 * faustpower<2>((1.0f - (0.5f * fTemp55)))) + (fSlow51 * ((fRec34 * fTemp47) * fTemp49))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec30[0] - fRec30[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec29[0] - fRec29[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec27[0] - fRec27[2])) / fSlow5))))))))) + (fTemp37 * (((fRec11 * faustpower<2>((1.0f - (0.5f * fTemp11)))) + (fSlow34 * ((fRec8 * fTemp3) * fTemp5))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec4[0] - fRec4[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec3[0] - fRec3[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec1[0] - fRec1[2])) / fSlow5)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)((fConst55 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec124[1] = fRec124[0];
			fRec123[1] = fRec123[0];
			fRec126[2] = fRec126[1]; fRec126[1] = fRec126[0];
			fRec128[1] = fRec128[0];
			fRec136[1] = fRec136[0];
			iRec127[1] = iRec127[0];
			iRec135[1] = iRec135[0];
			iRec134[1] = iRec134[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			iRec131[1] = iRec131[0];
			fRec129[1] = fRec129[0];
			fRec130[1] = fRec130[0];
			fRec121[1] = fRec121[0];
			fRec120[1] = fRec120[0];
			fRec119[2] = fRec119[1]; fRec119[1] = fRec119[0];
			fRec118[2] = fRec118[1]; fRec118[1] = fRec118[0];
			fRec117[2] = fRec117[1]; fRec117[1] = fRec117[0];
			fRec115[2] = fRec115[1]; fRec115[1] = fRec115[0];
			fRec116[1] = fRec116[0];
			fRec102[1] = fRec102[0];
			fRec101[1] = fRec101[0];
			fRec104[2] = fRec104[1]; fRec104[1] = fRec104[0];
			fRec106[1] = fRec106[0];
			fRec114[1] = fRec114[0];
			iRec105[1] = iRec105[0];
			iRec113[1] = iRec113[0];
			iRec112[1] = iRec112[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			iRec109[1] = iRec109[0];
			fRec107[1] = fRec107[0];
			fRec108[1] = fRec108[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1]; fRec96[1] = fRec96[0];
			fRec95[2] = fRec95[1]; fRec95[1] = fRec95[0];
			fRec93[2] = fRec93[1]; fRec93[1] = fRec93[0];
			fRec94[1] = fRec94[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec82[2] = fRec82[1]; fRec82[1] = fRec82[0];
			fRec84[1] = fRec84[0];
			fRec92[1] = fRec92[0];
			iRec83[1] = iRec83[0];
			iRec91[1] = iRec91[0];
			iRec90[1] = iRec90[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			iRec87[1] = iRec87[0];
			fRec85[1] = fRec85[0];
			fRec86[1] = fRec86[0];
			fRec77[1] = fRec77[0];
			fRec76[1] = fRec76[0];
			fRec75[2] = fRec75[1]; fRec75[1] = fRec75[0];
			fRec74[2] = fRec74[1]; fRec74[1] = fRec74[0];
			fRec73[2] = fRec73[1]; fRec73[1] = fRec73[0];
			fRec71[2] = fRec71[1]; fRec71[1] = fRec71[0];
			fRec72[1] = fRec72[0];
			fRec58[1] = fRec58[0];
			fRec57[1] = fRec57[0];
			fRec60[2] = fRec60[1]; fRec60[1] = fRec60[0];
			fRec62[1] = fRec62[0];
			fRec70[1] = fRec70[0];
			iRec61[1] = iRec61[0];
			iRec69[1] = iRec69[0];
			iRec68[1] = iRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			iRec65[1] = iRec65[0];
			fRec63[1] = fRec63[0];
			fRec64[1] = fRec64[0];
			fRec55[1] = fRec55[0];
			fRec54[1] = fRec54[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec52[2] = fRec52[1]; fRec52[1] = fRec52[0];
			fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
			fRec49[2] = fRec49[1]; fRec49[1] = fRec49[0];
			fRec50[1] = fRec50[0];
			fRec36[1] = fRec36[0];
			fRec35[1] = fRec35[0];
			fRec38[2] = fRec38[1]; fRec38[1] = fRec38[0];
			fRec40[1] = fRec40[0];
			fRec48[1] = fRec48[0];
			iRec39[1] = iRec39[0];
			iRec47[1] = iRec47[0];
			iRec46[1] = iRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
			iRec43[1] = iRec43[0];
			fRec41[1] = fRec41[0];
			fRec42[1] = fRec42[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
			fRec28[1] = fRec28[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec24[1] = fRec24[0];
			fRec25[2] = fRec25[1]; fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec23[1] = fRec23[0];
			iRec13[1] = iRec13[0];
			iRec21[1] = iRec21[0];
			iRec22[1] = iRec22[0];
			iRec20[1] = iRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			iRec17[1] = iRec17[0];
			fRec15[1] = fRec15[0];
			fRec16[1] = fRec16[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			fRec5[2] = fRec5[1]; fRec5[1] = fRec5[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec1[2] = fRec1[1]; fRec1[1] = fRec1[0];
			fRec2[1] = fRec2[0];
		}
	}
};


float 	mydsp::ftbl0[4096];

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
