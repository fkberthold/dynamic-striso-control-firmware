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
	FAUSTFLOAT 	fbargraph2;
	float 	fRec23[2];
	float 	fRec14[2];
	float 	fRec12[3];
	float 	fConst42;
	float 	fConst44;
	float 	fConst46;
	float 	fConst47;
	float 	fConst49;
	FAUSTFLOAT 	fslider6;
	float 	fRec26[3];
	float 	fConst50;
	float 	fRec25[3];
	float 	fConst51;
	float 	fConst52;
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
	float 	fConst53;
	float 	fRec0[3];
	float 	fConst54;
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
		fConst35 = (0.01f * fConst0);
		fConst36 = (0.050000000000000003f * fConst0);
		fConst37 = (8.0f * fConst0);
		fConst38 = (2.0f * fConst0);
		float 	fConst39 = faustpower<2>((125.66370614359172f / fConst0));
		float 	fConst40 = ((fConst39 * ((0.20330000000000001f * fConst39) + 0.31755f)) + 1.0f);
		float 	fConst41 = faustpower<2>(fConst40);
		fConst42 = (2.0f * ((15791.367041742973f * (fConst41 / fConst1)) + -1.0f));
		float 	fConst43 = (15791.367041742973f * (fConst40 / fConst0));
		fConst44 = (((fConst40 * (fConst43 + -232.71056693257725f)) / fConst0) + 1.0f);
		float 	fConst45 = (((fConst40 * (fConst43 + 232.71056693257725f)) / fConst0) + 1.0f);
		fConst46 = (1.0f / fConst45);
		fConst47 = (((fConst40 * (fConst43 + -95.926493239382992f)) / fConst0) + 1.0f);
		float 	fConst48 = (((fConst40 * (fConst43 + 95.926493239382992f)) / fConst0) + 1.0f);
		fConst49 = (1.0f / fConst48);
		fConst50 = (fConst41 / (fConst1 * fConst48));
		fConst51 = (fConst41 / (fConst1 * fConst45));
		fConst52 = powf(0.5f,(10.0f / fConst0));
		fConst53 = (1.3700000000000001f * fConst31);
		fConst54 = (0 - (2.0f / fConst7));
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
		int 	iSlow35 = ((int((fSlow32 >= 0.050000000000000003f)))?1:0);
		float 	fSlow36 = min((2.0f * fSlow31), 1.0f);
		float 	fSlow37 = fabsf(fSlow36);
		float 	fSlow38 = ((int((fSlow37 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow39 = ((fSlow36 > 0.0f) - (fSlow36 < 0.0f));
		int 	iSlow40 = int((fSlow32 <= 0.050000000000000003f));
		int 	iSlow41 = ((iSlow40)?3:2);
		int 	iSlow42 = (fSlow32 <= 0.0f);
		float 	fSlow43 = float(fslider6);
		float 	fSlow44 = max((8.1757989159999997f * fSlow8), (float)200);
		float 	fSlow45 = fastpow2((0.083333333333333329f * float(fslider7)));
		int 	iSlow46 = int(min((fConst13 / fSlow45), (float)4096));
		float 	fSlow47 = float(iSlow46);
		float 	fSlow48 = (fConst14 * (fSlow45 * fSlow47));
		float 	fSlow49 = float(fslider8);
		float 	fSlow50 = float(fslider9);
		float 	fSlow51 = (1500.0f * fSlow50);
		float 	fSlow52 = (0.40000000000000002f * fSlow50);
		int 	iSlow53 = ((int((fSlow50 >= 0.050000000000000003f)))?1:0);
		float 	fSlow54 = min((2.0f * fSlow49), 1.0f);
		float 	fSlow55 = fabsf(fSlow54);
		float 	fSlow56 = ((int((fSlow55 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow57 = ((fSlow54 > 0.0f) - (fSlow54 < 0.0f));
		int 	iSlow58 = int((fSlow50 <= 0.050000000000000003f));
		int 	iSlow59 = ((iSlow58)?3:2);
		int 	iSlow60 = (fSlow50 <= 0.0f);
		float 	fSlow61 = max((8.1757989159999997f * fSlow45), (float)200);
		float 	fSlow62 = fastpow2((0.083333333333333329f * float(fslider10)));
		int 	iSlow63 = int(min((fConst13 / fSlow62), (float)4096));
		float 	fSlow64 = float(iSlow63);
		float 	fSlow65 = (fConst14 * (fSlow62 * fSlow64));
		float 	fSlow66 = float(fslider11);
		float 	fSlow67 = float(fslider12);
		float 	fSlow68 = (1500.0f * fSlow67);
		float 	fSlow69 = (0.40000000000000002f * fSlow67);
		int 	iSlow70 = ((int((fSlow67 >= 0.050000000000000003f)))?1:0);
		float 	fSlow71 = min((2.0f * fSlow66), 1.0f);
		float 	fSlow72 = fabsf(fSlow71);
		float 	fSlow73 = ((int((fSlow72 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow74 = ((fSlow71 > 0.0f) - (fSlow71 < 0.0f));
		int 	iSlow75 = int((fSlow67 <= 0.050000000000000003f));
		int 	iSlow76 = ((iSlow75)?3:2);
		int 	iSlow77 = (fSlow67 <= 0.0f);
		float 	fSlow78 = max((8.1757989159999997f * fSlow62), (float)200);
		float 	fSlow79 = fastpow2((0.083333333333333329f * float(fslider13)));
		int 	iSlow80 = int(min((fConst13 / fSlow79), (float)4096));
		float 	fSlow81 = float(iSlow80);
		float 	fSlow82 = (fConst14 * (fSlow79 * fSlow81));
		float 	fSlow83 = float(fslider14);
		float 	fSlow84 = float(fslider15);
		float 	fSlow85 = (1500.0f * fSlow84);
		float 	fSlow86 = (0.40000000000000002f * fSlow84);
		int 	iSlow87 = ((int((fSlow84 >= 0.050000000000000003f)))?1:0);
		float 	fSlow88 = min((2.0f * fSlow83), 1.0f);
		float 	fSlow89 = fabsf(fSlow88);
		float 	fSlow90 = ((int((fSlow89 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow91 = ((fSlow88 > 0.0f) - (fSlow88 < 0.0f));
		int 	iSlow92 = int((fSlow84 <= 0.050000000000000003f));
		int 	iSlow93 = ((iSlow92)?3:2);
		int 	iSlow94 = (fSlow84 <= 0.0f);
		float 	fSlow95 = max((8.1757989159999997f * fSlow79), (float)200);
		float 	fSlow96 = fastpow2((0.083333333333333329f * float(fslider16)));
		int 	iSlow97 = int(min((fConst13 / fSlow96), (float)4096));
		float 	fSlow98 = float(iSlow97);
		float 	fSlow99 = (fConst14 * (fSlow96 * fSlow98));
		float 	fSlow100 = float(fslider17);
		float 	fSlow101 = float(fslider18);
		float 	fSlow102 = (1500.0f * fSlow101);
		float 	fSlow103 = (0.40000000000000002f * fSlow101);
		int 	iSlow104 = ((int((fSlow101 >= 0.050000000000000003f)))?1:0);
		float 	fSlow105 = min((2.0f * fSlow100), 1.0f);
		float 	fSlow106 = fabsf(fSlow105);
		float 	fSlow107 = ((int((fSlow106 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow108 = ((fSlow105 > 0.0f) - (fSlow105 < 0.0f));
		int 	iSlow109 = int((fSlow101 <= 0.050000000000000003f));
		int 	iSlow110 = ((iSlow109)?3:2);
		int 	iSlow111 = (fSlow101 <= 0.0f);
		float 	fSlow112 = max((8.1757989159999997f * fSlow96), (float)200);
		float 	fSlow113 = fastpow2((0.083333333333333329f * float(fslider19)));
		int 	iSlow114 = int(min((fConst13 / fSlow113), (float)4096));
		float 	fSlow115 = float(iSlow114);
		float 	fSlow116 = (fConst14 * (fSlow113 * fSlow115));
		float 	fSlow117 = float(fslider20);
		float 	fSlow118 = float(fslider21);
		float 	fSlow119 = (1500.0f * fSlow118);
		float 	fSlow120 = (0.40000000000000002f * fSlow118);
		int 	iSlow121 = ((int((fSlow118 >= 0.050000000000000003f)))?1:0);
		float 	fSlow122 = min((2.0f * fSlow117), 1.0f);
		float 	fSlow123 = fabsf(fSlow122);
		float 	fSlow124 = ((int((fSlow123 >= 0.20000000000000001f)))?fConst33:fConst0);
		int 	iSlow125 = ((fSlow122 > 0.0f) - (fSlow122 < 0.0f));
		int 	iSlow126 = int((fSlow118 <= 0.050000000000000003f));
		int 	iSlow127 = ((iSlow126)?3:2);
		int 	iSlow128 = (fSlow118 <= 0.0f);
		float 	fSlow129 = max((8.1757989159999997f * fSlow113), (float)200);
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
			float 	fTemp12 = (1.0f / ((int((iSlow39 == ((fRec15[1] > 0.0f) - (fRec15[1] < 0.0f)))))?((int((fSlow37 >= fabsf(fRec15[1]))))?fConst33:fConst0):fSlow38));
			float 	fTemp13 = (fRec16[1] - fTemp12);
			float 	fTemp14 = (fRec16[1] + fTemp12);
			fRec16[0] = ((int((fTemp14 < fSlow36)))?fTemp14:((int((fTemp13 > fSlow36)))?fTemp13:fSlow36));
			fRec15[0] = fRec16[0];
			int 	iTemp15 = ((fRec15[0] > 0.0f) + (1 - (fRec15[0] < 0.0f)));
			int 	iTemp16 = int((iTemp15 == 0));
			float 	fTemp17 = ((iTemp16)?1.7f:1.6000000000000001f);
			iRec17[0] = iRec13[1];
			int 	iTemp18 = int((iRec17[1] == iRec13[1]));
			int 	iTemp19 = int((iRec13[1] == 0));
			fRec18[0] = ((iTemp19)?fSlow32:((iTemp18)?min(min(fRec18[1], fSlow32), fRec14[1]):min(fSlow32, fRec14[1])));
			float 	fTemp20 = (fSlow32 * fTemp17);
			int 	iTemp21 = int((iRec13[1] == 1));
			fRec19[0] = ((iTemp19)?fSlow32:((iTemp21)?((iTemp18)?max(max(fRec19[1], fTemp20), fRec14[1]):max(fTemp20, fRec14[1])):((iTemp18)?max(max(fRec19[1], fSlow32), fRec14[1]):max(fSlow32, fRec14[1]))));
			fbargraph0 = fRec18[0];
			iRec20[0] = iRec13[1];
			iRec22[0] = (iRec22[1] + 1);
			int 	iTemp22 = (iRec22[0] + -1);
			iRec21[0] = ((int((iRec20[1] != iRec13[1])))?iTemp22:iRec21[1]);
			int 	iTemp23 = int((iRec13[1] >= 1));
			int 	iTemp24 = int((fSlow32 >= fRec14[1]));
			int 	iTemp25 = int((iRec13[1] >= 3));
			int 	iTemp26 = int((iRec13[1] >= 2));
			int 	iTemp27 = int((iRec13[1] >= 5));
			int 	iTemp28 = int((iRec13[1] >= 6));
			int 	iTemp29 = int((iRec13[1] >= 4));
			fbargraph1 = ((iTemp29)?((iTemp28)?((iSlow40)?3:((iTemp24)?5:6)):((iTemp27)?((iSlow40)?3:((int((fSlow32 <= fRec14[1])))?6:5)):((int((fRec14[1] <= 0.050000000000000003f)))?0:4))):((iTemp26)?((iTemp25)?((int((iSlow42 & (fRec14[1] <= 0.0f))))?0:((int((fSlow32 > fRec14[1])))?1:3)):((iTemp24)?5:iSlow41)):((iTemp23)?((int(((float((iRec22[0] + (-1 - iRec21[0]))) >= fConst33) & (fRec14[1] >= (fbargraph0 * fTemp17)))))?2:1):iSlow35)));
			iRec13[0] = fbargraph1;
			float 	fTemp30 = ((iTemp21)?fTemp20:fSlow32);
			float 	fTemp31 = ((iTemp29)?((iTemp28)?fConst0:((iTemp27)?fConst0:fConst35)):((iTemp26)?((iTemp25)?fConst0:fConst33):((iTemp23)?fConst34:0.0f)));
			float 	fTemp32 = fabsf(fRec15[0]);
			fbargraph2 = ((fTemp32 * ((iTemp16)?((iTemp29)?((iTemp28)?fConst38:((iTemp27)?fConst38:fConst35)):((iTemp26)?((iTemp25)?fConst37:fConst36):((iTemp23)?fConst36:0.0f))):((int((iTemp15 == 1)))?fTemp31:((iTemp29)?fConst35:((iTemp26)?((iTemp25)?fConst35:fConst33):((iTemp23)?fConst33:0.0f)))))) + ((1.0f - fTemp32) * fTemp31));
			float 	fTemp33 = (1.0f / fbargraph2);
			float 	fTemp34 = (fRec23[1] - fTemp33);
			float 	fTemp35 = (fRec23[1] + fTemp33);
			fRec23[0] = ((int((fTemp35 < fTemp30)))?fTemp35:((int((fTemp34 > fTemp30)))?fTemp34:fTemp30));
			fRec14[0] = fRec23[0];
			fRec12[0] = (fRec14[0] - (fConst30 * ((fConst28 * fRec12[2]) + (fConst26 * fRec12[1]))));
			float 	fTemp36 = (((3947.8417604357433f * fRec12[0]) + (7895.6835208714865f * fRec12[1])) + (3947.8417604357433f * fRec12[2]));
			fRec26[0] = (fSlow43 - (fConst49 * ((fConst47 * fRec26[2]) + (fConst42 * fRec26[1]))));
			fRec25[0] = ((fConst50 * (((15791.367041742973f * fRec26[0]) + (31582.734083485946f * fRec26[1])) + (15791.367041742973f * fRec26[2]))) - (fConst46 * ((fConst44 * fRec25[2]) + (fConst42 * fRec25[1]))));
			fRec24[0] = (fConst52 * max(fRec24[1], min((fConst51 * (((15791.367041742973f * fRec25[0]) + (31582.734083485946f * fRec25[1])) + (15791.367041742973f * fRec25[2]))), (float)2)));
			float 	fTemp37 = max((fRec24[0] + -1.0f), (float)0);
			float 	fTemp38 = tanf((fConst32 * min((fSlow44 * (faustpower<2>((fTemp37 + (fConst31 * (fTemp36 * (1.0f - fTemp11))))) + 1.0f)), (float)16000)));
			float 	fTemp39 = ((fTemp38 * (fTemp38 + (1.0f / ((8.0f * fTemp11) + 1.0f)))) + 1.0f);
			float 	fTemp40 = (fRec9[1] + (fTemp38 * (fTemp2 - fRec10[1])));
			float 	fTemp41 = (fTemp40 / fTemp39);
			fRec9[0] = ((2.0f * fTemp41) - fRec9[1]);
			float 	fTemp42 = (fRec10[1] + ((fTemp38 * fTemp40) / fTemp39));
			fRec10[0] = ((2.0f * fTemp42) - fRec10[1]);
			float 	fRec11 = fTemp42;
			fRec28[0] = (fSlow48 + (fRec28[1] - float((iSlow46 * ((fSlow48 + fRec28[1]) > fSlow47)))));
			int 	iTemp43 = int(fRec28[0]);
			float 	fTemp44 = ftbl0[iTemp43];
			float 	fTemp45 = (fTemp44 + ((fRec28[0] - float(iTemp43)) * (ftbl0[((iTemp43 + 1) % iSlow46)] - fTemp44)));
			fRec27[0] = (fTemp45 - (((fSlow7 * fRec27[2]) + (2.0f * (fSlow6 * fRec27[1]))) / fSlow5));
			fRec29[0] = (fTemp45 - (((fSlow20 * fRec29[2]) + (2.0f * (fSlow19 * fRec29[1]))) / fSlow18));
			fRec30[0] = (fTemp45 - (((fSlow29 * fRec30[2]) + (2.0f * (fSlow28 * fRec30[1]))) / fSlow27));
			fRec31[0] = (fSlow49 - (fConst30 * ((fConst28 * fRec31[2]) + (fConst26 * fRec31[1]))));
			float 	fTemp46 = ((fConst31 * (((3947.8417604357433f * fRec31[0]) + (7895.6835208714865f * fRec31[1])) + (3947.8417604357433f * fRec31[2]))) + 1.0f);
			float 	fTemp47 = (0.5f * fTemp46);
			float 	fTemp48 = max(fTemp47, (float)0);
			float 	fTemp49 = tanf((fConst32 * ((fSlow51 * (fTemp46 * fTemp48)) + 200.0f)));
			float 	fTemp50 = ((fTemp49 * (fTemp49 + 0.5f)) + 1.0f);
			float 	fTemp51 = (fRec32[1] + (fTemp49 * (fTemp45 - fRec33[1])));
			float 	fTemp52 = (fTemp51 / fTemp50);
			fRec32[0] = ((2.0f * fTemp52) - fRec32[1]);
			float 	fTemp53 = (fRec33[1] + ((fTemp49 * fTemp51) / fTemp50));
			fRec33[0] = ((2.0f * fTemp53) - fRec33[1]);
			float 	fRec34 = fTemp52;
			float 	fTemp54 = max((-1 * fTemp47), (float)0);
			float 	fTemp55 = (1.0f / ((int((iSlow57 == ((fRec41[1] > 0.0f) - (fRec41[1] < 0.0f)))))?((int((fSlow55 >= fabsf(fRec41[1]))))?fConst33:fConst0):fSlow56));
			float 	fTemp56 = (fRec42[1] - fTemp55);
			float 	fTemp57 = (fRec42[1] + fTemp55);
			fRec42[0] = ((int((fTemp57 < fSlow54)))?fTemp57:((int((fTemp56 > fSlow54)))?fTemp56:fSlow54));
			fRec41[0] = fRec42[0];
			int 	iTemp58 = ((fRec41[0] > 0.0f) + (1 - (fRec41[0] < 0.0f)));
			int 	iTemp59 = int((iTemp58 == 0));
			float 	fTemp60 = ((iTemp59)?1.7f:1.6000000000000001f);
			iRec43[0] = iRec39[1];
			int 	iTemp61 = int((iRec43[1] == iRec39[1]));
			int 	iTemp62 = int((iRec39[1] == 0));
			fRec44[0] = ((iTemp62)?fSlow50:((iTemp61)?min(min(fRec44[1], fSlow50), fRec40[1]):min(fSlow50, fRec40[1])));
			float 	fTemp63 = (fSlow50 * fTemp60);
			int 	iTemp64 = int((iRec39[1] == 1));
			fRec45[0] = ((iTemp62)?fSlow50:((iTemp64)?((iTemp61)?max(max(fRec45[1], fTemp63), fRec40[1]):max(fTemp63, fRec40[1])):((iTemp61)?max(max(fRec45[1], fSlow50), fRec40[1]):max(fSlow50, fRec40[1]))));
			fbargraph3 = fRec44[0];
			iRec46[0] = iRec39[1];
			iRec47[0] = ((int((iRec46[1] != iRec39[1])))?iTemp22:iRec47[1]);
			int 	iTemp65 = int((iRec39[1] >= 1));
			int 	iTemp66 = int((fSlow50 >= fRec40[1]));
			int 	iTemp67 = int((iRec39[1] >= 3));
			int 	iTemp68 = int((iRec39[1] >= 2));
			int 	iTemp69 = int((iRec39[1] >= 5));
			int 	iTemp70 = int((iRec39[1] >= 6));
			int 	iTemp71 = int((iRec39[1] >= 4));
			fbargraph4 = ((iTemp71)?((iTemp70)?((iSlow58)?3:((iTemp66)?5:6)):((iTemp69)?((iSlow58)?3:((int((fSlow50 <= fRec40[1])))?6:5)):((int((fRec40[1] <= 0.050000000000000003f)))?0:4))):((iTemp68)?((iTemp67)?((int((iSlow60 & (fRec40[1] <= 0.0f))))?0:((int((fSlow50 > fRec40[1])))?1:3)):((iTemp66)?5:iSlow59)):((iTemp65)?((int(((float((iRec22[0] + (-1 - iRec47[0]))) >= fConst33) & (fRec40[1] >= (fbargraph3 * fTemp60)))))?2:1):iSlow53)));
			iRec39[0] = fbargraph4;
			float 	fTemp72 = ((iTemp64)?fTemp63:fSlow50);
			float 	fTemp73 = ((iTemp71)?((iTemp70)?fConst0:((iTemp69)?fConst0:fConst35)):((iTemp68)?((iTemp67)?fConst0:fConst33):((iTemp65)?fConst34:0.0f)));
			float 	fTemp74 = fabsf(fRec41[0]);
			fbargraph5 = ((fTemp74 * ((iTemp59)?((iTemp71)?((iTemp70)?fConst38:((iTemp69)?fConst38:fConst35)):((iTemp68)?((iTemp67)?fConst37:fConst36):((iTemp65)?fConst36:0.0f))):((int((iTemp58 == 1)))?fTemp73:((iTemp71)?fConst35:((iTemp68)?((iTemp67)?fConst35:fConst33):((iTemp65)?fConst33:0.0f)))))) + ((1.0f - fTemp74) * fTemp73));
			float 	fTemp75 = (1.0f / fbargraph5);
			float 	fTemp76 = (fRec48[1] - fTemp75);
			float 	fTemp77 = (fRec48[1] + fTemp75);
			fRec48[0] = ((int((fTemp77 < fTemp72)))?fTemp77:((int((fTemp76 > fTemp72)))?fTemp76:fTemp72));
			fRec40[0] = fRec48[0];
			fRec38[0] = (fRec40[0] - (fConst30 * ((fConst28 * fRec38[2]) + (fConst26 * fRec38[1]))));
			float 	fTemp78 = (((3947.8417604357433f * fRec38[0]) + (7895.6835208714865f * fRec38[1])) + (3947.8417604357433f * fRec38[2]));
			float 	fTemp79 = tanf((fConst32 * min((fSlow61 * (faustpower<2>((fTemp37 + (fConst31 * (fTemp78 * (1.0f - fTemp54))))) + 1.0f)), (float)16000)));
			float 	fTemp80 = ((fTemp79 * (fTemp79 + (1.0f / ((8.0f * fTemp54) + 1.0f)))) + 1.0f);
			float 	fTemp81 = (fRec35[1] + (fTemp79 * (fTemp45 - fRec36[1])));
			float 	fTemp82 = (fTemp81 / fTemp80);
			fRec35[0] = ((2.0f * fTemp82) - fRec35[1]);
			float 	fTemp83 = (fRec36[1] + ((fTemp79 * fTemp81) / fTemp80));
			fRec36[0] = ((2.0f * fTemp83) - fRec36[1]);
			float 	fRec37 = fTemp83;
			fRec50[0] = (fSlow65 + (fRec50[1] - float((iSlow63 * ((fSlow65 + fRec50[1]) > fSlow64)))));
			int 	iTemp84 = int(fRec50[0]);
			float 	fTemp85 = ftbl0[iTemp84];
			float 	fTemp86 = (fTemp85 + ((fRec50[0] - float(iTemp84)) * (ftbl0[((iTemp84 + 1) % iSlow63)] - fTemp85)));
			fRec49[0] = (fTemp86 - (((fSlow7 * fRec49[2]) + (2.0f * (fSlow6 * fRec49[1]))) / fSlow5));
			fRec51[0] = (fTemp86 - (((fSlow20 * fRec51[2]) + (2.0f * (fSlow19 * fRec51[1]))) / fSlow18));
			fRec52[0] = (fTemp86 - (((fSlow29 * fRec52[2]) + (2.0f * (fSlow28 * fRec52[1]))) / fSlow27));
			fRec53[0] = (fSlow66 - (fConst30 * ((fConst28 * fRec53[2]) + (fConst26 * fRec53[1]))));
			float 	fTemp87 = ((fConst31 * (((3947.8417604357433f * fRec53[0]) + (7895.6835208714865f * fRec53[1])) + (3947.8417604357433f * fRec53[2]))) + 1.0f);
			float 	fTemp88 = (0.5f * fTemp87);
			float 	fTemp89 = max(fTemp88, (float)0);
			float 	fTemp90 = tanf((fConst32 * ((fSlow68 * (fTemp87 * fTemp89)) + 200.0f)));
			float 	fTemp91 = ((fTemp90 * (fTemp90 + 0.5f)) + 1.0f);
			float 	fTemp92 = (fRec54[1] + (fTemp90 * (fTemp86 - fRec55[1])));
			float 	fTemp93 = (fTemp92 / fTemp91);
			fRec54[0] = ((2.0f * fTemp93) - fRec54[1]);
			float 	fTemp94 = (fRec55[1] + ((fTemp90 * fTemp92) / fTemp91));
			fRec55[0] = ((2.0f * fTemp94) - fRec55[1]);
			float 	fRec56 = fTemp93;
			float 	fTemp95 = max((-1 * fTemp88), (float)0);
			float 	fTemp96 = (1.0f / ((int((iSlow74 == ((fRec63[1] > 0.0f) - (fRec63[1] < 0.0f)))))?((int((fSlow72 >= fabsf(fRec63[1]))))?fConst33:fConst0):fSlow73));
			float 	fTemp97 = (fRec64[1] - fTemp96);
			float 	fTemp98 = (fRec64[1] + fTemp96);
			fRec64[0] = ((int((fTemp98 < fSlow71)))?fTemp98:((int((fTemp97 > fSlow71)))?fTemp97:fSlow71));
			fRec63[0] = fRec64[0];
			int 	iTemp99 = ((fRec63[0] > 0.0f) + (1 - (fRec63[0] < 0.0f)));
			int 	iTemp100 = int((iTemp99 == 0));
			float 	fTemp101 = ((iTemp100)?1.7f:1.6000000000000001f);
			iRec65[0] = iRec61[1];
			int 	iTemp102 = int((iRec65[1] == iRec61[1]));
			int 	iTemp103 = int((iRec61[1] == 0));
			fRec66[0] = ((iTemp103)?fSlow67:((iTemp102)?min(min(fRec66[1], fSlow67), fRec62[1]):min(fSlow67, fRec62[1])));
			float 	fTemp104 = (fSlow67 * fTemp101);
			int 	iTemp105 = int((iRec61[1] == 1));
			fRec67[0] = ((iTemp103)?fSlow67:((iTemp105)?((iTemp102)?max(max(fRec67[1], fTemp104), fRec62[1]):max(fTemp104, fRec62[1])):((iTemp102)?max(max(fRec67[1], fSlow67), fRec62[1]):max(fSlow67, fRec62[1]))));
			fbargraph6 = fRec66[0];
			iRec68[0] = iRec61[1];
			iRec69[0] = ((int((iRec68[1] != iRec61[1])))?iTemp22:iRec69[1]);
			int 	iTemp106 = int((iRec61[1] >= 1));
			int 	iTemp107 = int((fSlow67 >= fRec62[1]));
			int 	iTemp108 = int((iRec61[1] >= 3));
			int 	iTemp109 = int((iRec61[1] >= 2));
			int 	iTemp110 = int((iRec61[1] >= 5));
			int 	iTemp111 = int((iRec61[1] >= 6));
			int 	iTemp112 = int((iRec61[1] >= 4));
			fbargraph7 = ((iTemp112)?((iTemp111)?((iSlow75)?3:((iTemp107)?5:6)):((iTemp110)?((iSlow75)?3:((int((fSlow67 <= fRec62[1])))?6:5)):((int((fRec62[1] <= 0.050000000000000003f)))?0:4))):((iTemp109)?((iTemp108)?((int((iSlow77 & (fRec62[1] <= 0.0f))))?0:((int((fSlow67 > fRec62[1])))?1:3)):((iTemp107)?5:iSlow76)):((iTemp106)?((int(((float((iRec22[0] + (-1 - iRec69[0]))) >= fConst33) & (fRec62[1] >= (fbargraph6 * fTemp101)))))?2:1):iSlow70)));
			iRec61[0] = fbargraph7;
			float 	fTemp113 = ((iTemp105)?fTemp104:fSlow67);
			float 	fTemp114 = ((iTemp112)?((iTemp111)?fConst0:((iTemp110)?fConst0:fConst35)):((iTemp109)?((iTemp108)?fConst0:fConst33):((iTemp106)?fConst34:0.0f)));
			float 	fTemp115 = fabsf(fRec63[0]);
			fbargraph8 = ((fTemp115 * ((iTemp100)?((iTemp112)?((iTemp111)?fConst38:((iTemp110)?fConst38:fConst35)):((iTemp109)?((iTemp108)?fConst37:fConst36):((iTemp106)?fConst36:0.0f))):((int((iTemp99 == 1)))?fTemp114:((iTemp112)?fConst35:((iTemp109)?((iTemp108)?fConst35:fConst33):((iTemp106)?fConst33:0.0f)))))) + ((1.0f - fTemp115) * fTemp114));
			float 	fTemp116 = (1.0f / fbargraph8);
			float 	fTemp117 = (fRec70[1] - fTemp116);
			float 	fTemp118 = (fRec70[1] + fTemp116);
			fRec70[0] = ((int((fTemp118 < fTemp113)))?fTemp118:((int((fTemp117 > fTemp113)))?fTemp117:fTemp113));
			fRec62[0] = fRec70[0];
			fRec60[0] = (fRec62[0] - (fConst30 * ((fConst28 * fRec60[2]) + (fConst26 * fRec60[1]))));
			float 	fTemp119 = (((3947.8417604357433f * fRec60[0]) + (7895.6835208714865f * fRec60[1])) + (3947.8417604357433f * fRec60[2]));
			float 	fTemp120 = tanf((fConst32 * min((fSlow78 * (faustpower<2>((fTemp37 + (fConst31 * (fTemp119 * (1.0f - fTemp95))))) + 1.0f)), (float)16000)));
			float 	fTemp121 = ((fTemp120 * (fTemp120 + (1.0f / ((8.0f * fTemp95) + 1.0f)))) + 1.0f);
			float 	fTemp122 = (fRec57[1] + (fTemp120 * (fTemp86 - fRec58[1])));
			float 	fTemp123 = (fTemp122 / fTemp121);
			fRec57[0] = ((2.0f * fTemp123) - fRec57[1]);
			float 	fTemp124 = (fRec58[1] + ((fTemp120 * fTemp122) / fTemp121));
			fRec58[0] = ((2.0f * fTemp124) - fRec58[1]);
			float 	fRec59 = fTemp124;
			fRec72[0] = (fSlow82 + (fRec72[1] - float((iSlow80 * ((fSlow82 + fRec72[1]) > fSlow81)))));
			int 	iTemp125 = int(fRec72[0]);
			float 	fTemp126 = ftbl0[iTemp125];
			float 	fTemp127 = (fTemp126 + ((fRec72[0] - float(iTemp125)) * (ftbl0[((iTemp125 + 1) % iSlow80)] - fTemp126)));
			fRec71[0] = (fTemp127 - (((fSlow7 * fRec71[2]) + (2.0f * (fSlow6 * fRec71[1]))) / fSlow5));
			fRec73[0] = (fTemp127 - (((fSlow20 * fRec73[2]) + (2.0f * (fSlow19 * fRec73[1]))) / fSlow18));
			fRec74[0] = (fTemp127 - (((fSlow29 * fRec74[2]) + (2.0f * (fSlow28 * fRec74[1]))) / fSlow27));
			fRec75[0] = (fSlow83 - (fConst30 * ((fConst28 * fRec75[2]) + (fConst26 * fRec75[1]))));
			float 	fTemp128 = ((fConst31 * (((3947.8417604357433f * fRec75[0]) + (7895.6835208714865f * fRec75[1])) + (3947.8417604357433f * fRec75[2]))) + 1.0f);
			float 	fTemp129 = (0.5f * fTemp128);
			float 	fTemp130 = max(fTemp129, (float)0);
			float 	fTemp131 = tanf((fConst32 * ((fSlow85 * (fTemp128 * fTemp130)) + 200.0f)));
			float 	fTemp132 = ((fTemp131 * (fTemp131 + 0.5f)) + 1.0f);
			float 	fTemp133 = (fRec76[1] + (fTemp131 * (fTemp127 - fRec77[1])));
			float 	fTemp134 = (fTemp133 / fTemp132);
			fRec76[0] = ((2.0f * fTemp134) - fRec76[1]);
			float 	fTemp135 = (fRec77[1] + ((fTemp131 * fTemp133) / fTemp132));
			fRec77[0] = ((2.0f * fTemp135) - fRec77[1]);
			float 	fRec78 = fTemp134;
			float 	fTemp136 = max((-1 * fTemp129), (float)0);
			float 	fTemp137 = (1.0f / ((int((iSlow91 == ((fRec85[1] > 0.0f) - (fRec85[1] < 0.0f)))))?((int((fSlow89 >= fabsf(fRec85[1]))))?fConst33:fConst0):fSlow90));
			float 	fTemp138 = (fRec86[1] - fTemp137);
			float 	fTemp139 = (fRec86[1] + fTemp137);
			fRec86[0] = ((int((fTemp139 < fSlow88)))?fTemp139:((int((fTemp138 > fSlow88)))?fTemp138:fSlow88));
			fRec85[0] = fRec86[0];
			int 	iTemp140 = ((fRec85[0] > 0.0f) + (1 - (fRec85[0] < 0.0f)));
			int 	iTemp141 = int((iTemp140 == 0));
			float 	fTemp142 = ((iTemp141)?1.7f:1.6000000000000001f);
			iRec87[0] = iRec83[1];
			int 	iTemp143 = int((iRec87[1] == iRec83[1]));
			int 	iTemp144 = int((iRec83[1] == 0));
			fRec88[0] = ((iTemp144)?fSlow84:((iTemp143)?min(min(fRec88[1], fSlow84), fRec84[1]):min(fSlow84, fRec84[1])));
			float 	fTemp145 = (fSlow84 * fTemp142);
			int 	iTemp146 = int((iRec83[1] == 1));
			fRec89[0] = ((iTemp144)?fSlow84:((iTemp146)?((iTemp143)?max(max(fRec89[1], fTemp145), fRec84[1]):max(fTemp145, fRec84[1])):((iTemp143)?max(max(fRec89[1], fSlow84), fRec84[1]):max(fSlow84, fRec84[1]))));
			fbargraph9 = fRec88[0];
			iRec90[0] = iRec83[1];
			iRec91[0] = ((int((iRec90[1] != iRec83[1])))?iTemp22:iRec91[1]);
			int 	iTemp147 = int((iRec83[1] >= 1));
			int 	iTemp148 = int((fSlow84 >= fRec84[1]));
			int 	iTemp149 = int((iRec83[1] >= 3));
			int 	iTemp150 = int((iRec83[1] >= 2));
			int 	iTemp151 = int((iRec83[1] >= 5));
			int 	iTemp152 = int((iRec83[1] >= 6));
			int 	iTemp153 = int((iRec83[1] >= 4));
			fbargraph10 = ((iTemp153)?((iTemp152)?((iSlow92)?3:((iTemp148)?5:6)):((iTemp151)?((iSlow92)?3:((int((fSlow84 <= fRec84[1])))?6:5)):((int((fRec84[1] <= 0.050000000000000003f)))?0:4))):((iTemp150)?((iTemp149)?((int((iSlow94 & (fRec84[1] <= 0.0f))))?0:((int((fSlow84 > fRec84[1])))?1:3)):((iTemp148)?5:iSlow93)):((iTemp147)?((int(((float((iRec22[0] + (-1 - iRec91[0]))) >= fConst33) & (fRec84[1] >= (fbargraph9 * fTemp142)))))?2:1):iSlow87)));
			iRec83[0] = fbargraph10;
			float 	fTemp154 = ((iTemp146)?fTemp145:fSlow84);
			float 	fTemp155 = ((iTemp153)?((iTemp152)?fConst0:((iTemp151)?fConst0:fConst35)):((iTemp150)?((iTemp149)?fConst0:fConst33):((iTemp147)?fConst34:0.0f)));
			float 	fTemp156 = fabsf(fRec85[0]);
			fbargraph11 = ((fTemp156 * ((iTemp141)?((iTemp153)?((iTemp152)?fConst38:((iTemp151)?fConst38:fConst35)):((iTemp150)?((iTemp149)?fConst37:fConst36):((iTemp147)?fConst36:0.0f))):((int((iTemp140 == 1)))?fTemp155:((iTemp153)?fConst35:((iTemp150)?((iTemp149)?fConst35:fConst33):((iTemp147)?fConst33:0.0f)))))) + ((1.0f - fTemp156) * fTemp155));
			float 	fTemp157 = (1.0f / fbargraph11);
			float 	fTemp158 = (fRec92[1] - fTemp157);
			float 	fTemp159 = (fRec92[1] + fTemp157);
			fRec92[0] = ((int((fTemp159 < fTemp154)))?fTemp159:((int((fTemp158 > fTemp154)))?fTemp158:fTemp154));
			fRec84[0] = fRec92[0];
			fRec82[0] = (fRec84[0] - (fConst30 * ((fConst28 * fRec82[2]) + (fConst26 * fRec82[1]))));
			float 	fTemp160 = (((3947.8417604357433f * fRec82[0]) + (7895.6835208714865f * fRec82[1])) + (3947.8417604357433f * fRec82[2]));
			float 	fTemp161 = tanf((fConst32 * min((fSlow95 * (faustpower<2>((fTemp37 + (fConst31 * (fTemp160 * (1.0f - fTemp136))))) + 1.0f)), (float)16000)));
			float 	fTemp162 = ((fTemp161 * (fTemp161 + (1.0f / ((8.0f * fTemp136) + 1.0f)))) + 1.0f);
			float 	fTemp163 = (fRec79[1] + (fTemp161 * (fTemp127 - fRec80[1])));
			float 	fTemp164 = (fTemp163 / fTemp162);
			fRec79[0] = ((2.0f * fTemp164) - fRec79[1]);
			float 	fTemp165 = (fRec80[1] + ((fTemp161 * fTemp163) / fTemp162));
			fRec80[0] = ((2.0f * fTemp165) - fRec80[1]);
			float 	fRec81 = fTemp165;
			fRec94[0] = (fSlow99 + (fRec94[1] - float((iSlow97 * ((fSlow99 + fRec94[1]) > fSlow98)))));
			int 	iTemp166 = int(fRec94[0]);
			float 	fTemp167 = ftbl0[iTemp166];
			float 	fTemp168 = (fTemp167 + ((fRec94[0] - float(iTemp166)) * (ftbl0[((iTemp166 + 1) % iSlow97)] - fTemp167)));
			fRec93[0] = (fTemp168 - (((fSlow7 * fRec93[2]) + (2.0f * (fSlow6 * fRec93[1]))) / fSlow5));
			fRec95[0] = (fTemp168 - (((fSlow20 * fRec95[2]) + (2.0f * (fSlow19 * fRec95[1]))) / fSlow18));
			fRec96[0] = (fTemp168 - (((fSlow29 * fRec96[2]) + (2.0f * (fSlow28 * fRec96[1]))) / fSlow27));
			fRec97[0] = (fSlow100 - (fConst30 * ((fConst28 * fRec97[2]) + (fConst26 * fRec97[1]))));
			float 	fTemp169 = ((fConst31 * (((3947.8417604357433f * fRec97[0]) + (7895.6835208714865f * fRec97[1])) + (3947.8417604357433f * fRec97[2]))) + 1.0f);
			float 	fTemp170 = (0.5f * fTemp169);
			float 	fTemp171 = max(fTemp170, (float)0);
			float 	fTemp172 = tanf((fConst32 * ((fSlow102 * (fTemp169 * fTemp171)) + 200.0f)));
			float 	fTemp173 = ((fTemp172 * (fTemp172 + 0.5f)) + 1.0f);
			float 	fTemp174 = (fRec98[1] + (fTemp172 * (fTemp168 - fRec99[1])));
			float 	fTemp175 = (fTemp174 / fTemp173);
			fRec98[0] = ((2.0f * fTemp175) - fRec98[1]);
			float 	fTemp176 = (fRec99[1] + ((fTemp172 * fTemp174) / fTemp173));
			fRec99[0] = ((2.0f * fTemp176) - fRec99[1]);
			float 	fRec100 = fTemp175;
			float 	fTemp177 = max((-1 * fTemp170), (float)0);
			float 	fTemp178 = (1.0f / ((int((iSlow108 == ((fRec107[1] > 0.0f) - (fRec107[1] < 0.0f)))))?((int((fSlow106 >= fabsf(fRec107[1]))))?fConst33:fConst0):fSlow107));
			float 	fTemp179 = (fRec108[1] - fTemp178);
			float 	fTemp180 = (fRec108[1] + fTemp178);
			fRec108[0] = ((int((fTemp180 < fSlow105)))?fTemp180:((int((fTemp179 > fSlow105)))?fTemp179:fSlow105));
			fRec107[0] = fRec108[0];
			int 	iTemp181 = ((fRec107[0] > 0.0f) + (1 - (fRec107[0] < 0.0f)));
			int 	iTemp182 = int((iTemp181 == 0));
			float 	fTemp183 = ((iTemp182)?1.7f:1.6000000000000001f);
			iRec109[0] = iRec105[1];
			int 	iTemp184 = int((iRec109[1] == iRec105[1]));
			int 	iTemp185 = int((iRec105[1] == 0));
			fRec110[0] = ((iTemp185)?fSlow101:((iTemp184)?min(min(fRec110[1], fSlow101), fRec106[1]):min(fSlow101, fRec106[1])));
			float 	fTemp186 = (fSlow101 * fTemp183);
			int 	iTemp187 = int((iRec105[1] == 1));
			fRec111[0] = ((iTemp185)?fSlow101:((iTemp187)?((iTemp184)?max(max(fRec111[1], fTemp186), fRec106[1]):max(fTemp186, fRec106[1])):((iTemp184)?max(max(fRec111[1], fSlow101), fRec106[1]):max(fSlow101, fRec106[1]))));
			fbargraph12 = fRec110[0];
			iRec112[0] = iRec105[1];
			iRec113[0] = ((int((iRec112[1] != iRec105[1])))?iTemp22:iRec113[1]);
			int 	iTemp188 = int((iRec105[1] >= 1));
			int 	iTemp189 = int((fSlow101 >= fRec106[1]));
			int 	iTemp190 = int((iRec105[1] >= 3));
			int 	iTemp191 = int((iRec105[1] >= 2));
			int 	iTemp192 = int((iRec105[1] >= 5));
			int 	iTemp193 = int((iRec105[1] >= 6));
			int 	iTemp194 = int((iRec105[1] >= 4));
			fbargraph13 = ((iTemp194)?((iTemp193)?((iSlow109)?3:((iTemp189)?5:6)):((iTemp192)?((iSlow109)?3:((int((fSlow101 <= fRec106[1])))?6:5)):((int((fRec106[1] <= 0.050000000000000003f)))?0:4))):((iTemp191)?((iTemp190)?((int((iSlow111 & (fRec106[1] <= 0.0f))))?0:((int((fSlow101 > fRec106[1])))?1:3)):((iTemp189)?5:iSlow110)):((iTemp188)?((int(((float((iRec22[0] + (-1 - iRec113[0]))) >= fConst33) & (fRec106[1] >= (fbargraph12 * fTemp183)))))?2:1):iSlow104)));
			iRec105[0] = fbargraph13;
			float 	fTemp195 = ((iTemp187)?fTemp186:fSlow101);
			float 	fTemp196 = ((iTemp194)?((iTemp193)?fConst0:((iTemp192)?fConst0:fConst35)):((iTemp191)?((iTemp190)?fConst0:fConst33):((iTemp188)?fConst34:0.0f)));
			float 	fTemp197 = fabsf(fRec107[0]);
			fbargraph14 = ((fTemp197 * ((iTemp182)?((iTemp194)?((iTemp193)?fConst38:((iTemp192)?fConst38:fConst35)):((iTemp191)?((iTemp190)?fConst37:fConst36):((iTemp188)?fConst36:0.0f))):((int((iTemp181 == 1)))?fTemp196:((iTemp194)?fConst35:((iTemp191)?((iTemp190)?fConst35:fConst33):((iTemp188)?fConst33:0.0f)))))) + ((1.0f - fTemp197) * fTemp196));
			float 	fTemp198 = (1.0f / fbargraph14);
			float 	fTemp199 = (fRec114[1] - fTemp198);
			float 	fTemp200 = (fRec114[1] + fTemp198);
			fRec114[0] = ((int((fTemp200 < fTemp195)))?fTemp200:((int((fTemp199 > fTemp195)))?fTemp199:fTemp195));
			fRec106[0] = fRec114[0];
			fRec104[0] = (fRec106[0] - (fConst30 * ((fConst28 * fRec104[2]) + (fConst26 * fRec104[1]))));
			float 	fTemp201 = (((3947.8417604357433f * fRec104[0]) + (7895.6835208714865f * fRec104[1])) + (3947.8417604357433f * fRec104[2]));
			float 	fTemp202 = tanf((fConst32 * min((fSlow112 * (faustpower<2>((fTemp37 + (fConst31 * (fTemp201 * (1.0f - fTemp177))))) + 1.0f)), (float)16000)));
			float 	fTemp203 = ((fTemp202 * (fTemp202 + (1.0f / ((8.0f * fTemp177) + 1.0f)))) + 1.0f);
			float 	fTemp204 = (fRec101[1] + (fTemp202 * (fTemp168 - fRec102[1])));
			float 	fTemp205 = (fTemp204 / fTemp203);
			fRec101[0] = ((2.0f * fTemp205) - fRec101[1]);
			float 	fTemp206 = (fRec102[1] + ((fTemp202 * fTemp204) / fTemp203));
			fRec102[0] = ((2.0f * fTemp206) - fRec102[1]);
			float 	fRec103 = fTemp206;
			fRec116[0] = (fSlow116 + (fRec116[1] - float((iSlow114 * ((fSlow116 + fRec116[1]) > fSlow115)))));
			int 	iTemp207 = int(fRec116[0]);
			float 	fTemp208 = ftbl0[iTemp207];
			float 	fTemp209 = (fTemp208 + ((fRec116[0] - float(iTemp207)) * (ftbl0[((iTemp207 + 1) % iSlow114)] - fTemp208)));
			fRec115[0] = (fTemp209 - (((fSlow7 * fRec115[2]) + (2.0f * (fSlow6 * fRec115[1]))) / fSlow5));
			fRec117[0] = (fTemp209 - (((fSlow20 * fRec117[2]) + (2.0f * (fSlow19 * fRec117[1]))) / fSlow18));
			fRec118[0] = (fTemp209 - (((fSlow29 * fRec118[2]) + (2.0f * (fSlow28 * fRec118[1]))) / fSlow27));
			fRec119[0] = (fSlow117 - (fConst30 * ((fConst28 * fRec119[2]) + (fConst26 * fRec119[1]))));
			float 	fTemp210 = ((fConst31 * (((3947.8417604357433f * fRec119[0]) + (7895.6835208714865f * fRec119[1])) + (3947.8417604357433f * fRec119[2]))) + 1.0f);
			float 	fTemp211 = (0.5f * fTemp210);
			float 	fTemp212 = max(fTemp211, (float)0);
			float 	fTemp213 = tanf((fConst32 * ((fSlow119 * (fTemp210 * fTemp212)) + 200.0f)));
			float 	fTemp214 = ((fTemp213 * (fTemp213 + 0.5f)) + 1.0f);
			float 	fTemp215 = (fRec120[1] + (fTemp213 * (fTemp209 - fRec121[1])));
			float 	fTemp216 = (fTemp215 / fTemp214);
			fRec120[0] = ((2.0f * fTemp216) - fRec120[1]);
			float 	fTemp217 = (fRec121[1] + ((fTemp213 * fTemp215) / fTemp214));
			fRec121[0] = ((2.0f * fTemp217) - fRec121[1]);
			float 	fRec122 = fTemp216;
			float 	fTemp218 = max((-1 * fTemp211), (float)0);
			float 	fTemp219 = (1.0f / ((int((iSlow125 == ((fRec129[1] > 0.0f) - (fRec129[1] < 0.0f)))))?((int((fSlow123 >= fabsf(fRec129[1]))))?fConst33:fConst0):fSlow124));
			float 	fTemp220 = (fRec130[1] - fTemp219);
			float 	fTemp221 = (fRec130[1] + fTemp219);
			fRec130[0] = ((int((fTemp221 < fSlow122)))?fTemp221:((int((fTemp220 > fSlow122)))?fTemp220:fSlow122));
			fRec129[0] = fRec130[0];
			int 	iTemp222 = ((fRec129[0] > 0.0f) + (1 - (fRec129[0] < 0.0f)));
			int 	iTemp223 = int((iTemp222 == 0));
			float 	fTemp224 = ((iTemp223)?1.7f:1.6000000000000001f);
			iRec131[0] = iRec127[1];
			int 	iTemp225 = int((iRec131[1] == iRec127[1]));
			int 	iTemp226 = int((iRec127[1] == 0));
			fRec132[0] = ((iTemp226)?fSlow118:((iTemp225)?min(min(fRec132[1], fSlow118), fRec128[1]):min(fSlow118, fRec128[1])));
			float 	fTemp227 = (fSlow118 * fTemp224);
			int 	iTemp228 = int((iRec127[1] == 1));
			fRec133[0] = ((iTemp226)?fSlow118:((iTemp228)?((iTemp225)?max(max(fRec133[1], fTemp227), fRec128[1]):max(fTemp227, fRec128[1])):((iTemp225)?max(max(fRec133[1], fSlow118), fRec128[1]):max(fSlow118, fRec128[1]))));
			fbargraph15 = fRec132[0];
			iRec134[0] = iRec127[1];
			iRec135[0] = ((int((iRec134[1] != iRec127[1])))?iTemp22:iRec135[1]);
			int 	iTemp229 = int((iRec127[1] >= 1));
			int 	iTemp230 = int((fSlow118 >= fRec128[1]));
			int 	iTemp231 = int((iRec127[1] >= 3));
			int 	iTemp232 = int((iRec127[1] >= 2));
			int 	iTemp233 = int((iRec127[1] >= 5));
			int 	iTemp234 = int((iRec127[1] >= 6));
			int 	iTemp235 = int((iRec127[1] >= 4));
			fbargraph16 = ((iTemp235)?((iTemp234)?((iSlow126)?3:((iTemp230)?5:6)):((iTemp233)?((iSlow126)?3:((int((fSlow118 <= fRec128[1])))?6:5)):((int((fRec128[1] <= 0.050000000000000003f)))?0:4))):((iTemp232)?((iTemp231)?((int((iSlow128 & (fRec128[1] <= 0.0f))))?0:((int((fSlow118 > fRec128[1])))?1:3)):((iTemp230)?5:iSlow127)):((iTemp229)?((int(((float((iRec22[0] + (-1 - iRec135[0]))) >= fConst33) & (fRec128[1] >= (fbargraph15 * fTemp224)))))?2:1):iSlow121)));
			iRec127[0] = fbargraph16;
			float 	fTemp236 = ((iTemp228)?fTemp227:fSlow118);
			float 	fTemp237 = ((iTemp235)?((iTemp234)?fConst0:((iTemp233)?fConst0:fConst35)):((iTemp232)?((iTemp231)?fConst0:fConst33):((iTemp229)?fConst34:0.0f)));
			float 	fTemp238 = fabsf(fRec129[0]);
			fbargraph17 = ((fTemp238 * ((iTemp223)?((iTemp235)?((iTemp234)?fConst38:((iTemp233)?fConst38:fConst35)):((iTemp232)?((iTemp231)?fConst37:fConst36):((iTemp229)?fConst36:0.0f))):((int((iTemp222 == 1)))?fTemp237:((iTemp235)?fConst35:((iTemp232)?((iTemp231)?fConst35:fConst33):((iTemp229)?fConst33:0.0f)))))) + ((1.0f - fTemp238) * fTemp237));
			float 	fTemp239 = (1.0f / fbargraph17);
			float 	fTemp240 = (fRec136[1] - fTemp239);
			float 	fTemp241 = (fRec136[1] + fTemp239);
			fRec136[0] = ((int((fTemp241 < fTemp236)))?fTemp241:((int((fTemp240 > fTemp236)))?fTemp240:fTemp236));
			fRec128[0] = fRec136[0];
			fRec126[0] = (fRec128[0] - (fConst30 * ((fConst28 * fRec126[2]) + (fConst26 * fRec126[1]))));
			float 	fTemp242 = (((3947.8417604357433f * fRec126[0]) + (7895.6835208714865f * fRec126[1])) + (3947.8417604357433f * fRec126[2]));
			float 	fTemp243 = tanf((fConst32 * min((fSlow129 * (faustpower<2>(((fConst31 * (fTemp242 * (1.0f - fTemp218))) + fTemp37)) + 1.0f)), (float)16000)));
			float 	fTemp244 = ((fTemp243 * (fTemp243 + (1.0f / ((8.0f * fTemp218) + 1.0f)))) + 1.0f);
			float 	fTemp245 = (fRec123[1] + (fTemp243 * (fTemp209 - fRec124[1])));
			float 	fTemp246 = (fTemp245 / fTemp244);
			fRec123[0] = ((2.0f * fTemp246) - fRec123[1]);
			float 	fTemp247 = (fRec124[1] + ((fTemp243 * fTemp245) / fTemp244));
			fRec124[0] = ((2.0f * fTemp247) - fRec124[1]);
			float 	fRec125 = fTemp247;
			fRec0[0] = ((fConst53 * ((((((fTemp242 * (((fRec125 * faustpower<2>((1.0f - (0.5f * fTemp218)))) + (fSlow120 * ((fRec122 * fTemp210) * fTemp212))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec118[0] - fRec118[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec117[0] - fRec117[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec115[0] - fRec115[2])) / fSlow5)))))))) + (fTemp201 * (((fRec103 * faustpower<2>((1.0f - (0.5f * fTemp177)))) + (fSlow103 * ((fRec100 * fTemp169) * fTemp171))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec96[0] - fRec96[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec95[0] - fRec95[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec93[0] - fRec93[2])) / fSlow5))))))))) + (fTemp160 * (((fRec81 * faustpower<2>((1.0f - (0.5f * fTemp136)))) + (fSlow86 * ((fRec78 * fTemp128) * fTemp130))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec74[0] - fRec74[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec73[0] - fRec73[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec71[0] - fRec71[2])) / fSlow5))))))))) + (fTemp119 * (((fRec59 * faustpower<2>((1.0f - (0.5f * fTemp95)))) + (fSlow69 * ((fRec56 * fTemp87) * fTemp89))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec52[0] - fRec52[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec51[0] - fRec51[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec49[0] - fRec49[2])) / fSlow5))))))))) + (fTemp78 * (((fRec37 * faustpower<2>((1.0f - (0.5f * fTemp54)))) + (fSlow52 * ((fRec34 * fTemp46) * fTemp48))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec30[0] - fRec30[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec29[0] - fRec29[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec27[0] - fRec27[2])) / fSlow5))))))))) + (fTemp36 * (((fRec11 * faustpower<2>((1.0f - (0.5f * fTemp11)))) + (fSlow34 * ((fRec8 * fTemp3) * fTemp5))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec4[0] - fRec4[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec3[0] - fRec3[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec1[0] - fRec1[2])) / fSlow5)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)((fConst54 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2])));
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
