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
	FAUSTFLOAT 	fbargraph2;
	float 	fRec23[2];
	float 	fConst37;
	FAUSTFLOAT 	fbargraph3;
	float 	fRec24[2];
	float 	fRec14[2];
	float 	fRec12[3];
	float 	fConst41;
	float 	fConst43;
	float 	fConst45;
	float 	fConst46;
	float 	fConst48;
	FAUSTFLOAT 	fslider6;
	float 	fRec27[3];
	float 	fConst49;
	float 	fRec26[3];
	float 	fConst50;
	float 	fConst51;
	float 	fRec25[2];
	float 	fRec9[2];
	float 	fRec10[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec29[2];
	float 	fRec28[3];
	float 	fRec30[3];
	float 	fRec31[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec32[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec33[2];
	float 	fRec34[2];
	float 	fRec43[2];
	float 	fRec42[2];
	int 	iRec44[2];
	float 	fRec45[2];
	float 	fRec46[2];
	FAUSTFLOAT 	fbargraph4;
	int 	iRec47[2];
	int 	iRec48[2];
	FAUSTFLOAT 	fbargraph5;
	int 	iRec40[2];
	FAUSTFLOAT 	fbargraph6;
	float 	fRec49[2];
	FAUSTFLOAT 	fbargraph7;
	float 	fRec50[2];
	float 	fRec41[2];
	float 	fRec39[3];
	float 	fRec36[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec52[2];
	float 	fRec51[3];
	float 	fRec53[3];
	float 	fRec54[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec55[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec56[2];
	float 	fRec57[2];
	float 	fRec66[2];
	float 	fRec65[2];
	int 	iRec67[2];
	float 	fRec68[2];
	float 	fRec69[2];
	FAUSTFLOAT 	fbargraph8;
	int 	iRec70[2];
	int 	iRec71[2];
	FAUSTFLOAT 	fbargraph9;
	int 	iRec63[2];
	FAUSTFLOAT 	fbargraph10;
	float 	fRec72[2];
	FAUSTFLOAT 	fbargraph11;
	float 	fRec73[2];
	float 	fRec64[2];
	float 	fRec62[3];
	float 	fRec59[2];
	float 	fRec60[2];
	FAUSTFLOAT 	fslider13;
	float 	fRec75[2];
	float 	fRec74[3];
	float 	fRec76[3];
	float 	fRec77[3];
	FAUSTFLOAT 	fslider14;
	float 	fRec78[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec79[2];
	float 	fRec80[2];
	float 	fRec89[2];
	float 	fRec88[2];
	int 	iRec90[2];
	float 	fRec91[2];
	float 	fRec92[2];
	FAUSTFLOAT 	fbargraph12;
	int 	iRec93[2];
	int 	iRec94[2];
	FAUSTFLOAT 	fbargraph13;
	int 	iRec86[2];
	FAUSTFLOAT 	fbargraph14;
	float 	fRec95[2];
	FAUSTFLOAT 	fbargraph15;
	float 	fRec96[2];
	float 	fRec87[2];
	float 	fRec85[3];
	float 	fRec82[2];
	float 	fRec83[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec98[2];
	float 	fRec97[3];
	float 	fRec99[3];
	float 	fRec100[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec101[3];
	FAUSTFLOAT 	fslider18;
	float 	fRec102[2];
	float 	fRec103[2];
	float 	fRec112[2];
	float 	fRec111[2];
	int 	iRec113[2];
	float 	fRec114[2];
	float 	fRec115[2];
	FAUSTFLOAT 	fbargraph16;
	int 	iRec116[2];
	int 	iRec117[2];
	FAUSTFLOAT 	fbargraph17;
	int 	iRec109[2];
	FAUSTFLOAT 	fbargraph18;
	float 	fRec118[2];
	FAUSTFLOAT 	fbargraph19;
	float 	fRec119[2];
	float 	fRec110[2];
	float 	fRec108[3];
	float 	fRec105[2];
	float 	fRec106[2];
	FAUSTFLOAT 	fslider19;
	float 	fRec121[2];
	float 	fRec120[3];
	float 	fRec122[3];
	float 	fRec123[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec124[3];
	FAUSTFLOAT 	fslider21;
	float 	fRec125[2];
	float 	fRec126[2];
	float 	fRec135[2];
	float 	fRec134[2];
	int 	iRec136[2];
	float 	fRec137[2];
	float 	fRec138[2];
	FAUSTFLOAT 	fbargraph20;
	int 	iRec139[2];
	int 	iRec140[2];
	FAUSTFLOAT 	fbargraph21;
	int 	iRec132[2];
	FAUSTFLOAT 	fbargraph22;
	float 	fRec141[2];
	FAUSTFLOAT 	fbargraph23;
	float 	fRec142[2];
	float 	fRec133[2];
	float 	fRec131[3];
	float 	fRec128[2];
	float 	fRec129[2];
	float 	fConst52;
	float 	fRec0[3];
	float 	fConst53;
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
		fConst34 = (0.29999999999999999f * fConst0);
		fConst35 = (0.01f * fConst0);
		fConst36 = (2.0f * fConst0);
		fConst37 = (1.0f / fConst0);
		float 	fConst38 = faustpower<2>((125.66370614359172f / fConst0));
		float 	fConst39 = ((fConst38 * ((0.20330000000000001f * fConst38) + 0.31755f)) + 1.0f);
		float 	fConst40 = faustpower<2>(fConst39);
		fConst41 = (2.0f * ((15791.367041742973f * (fConst40 / fConst1)) + -1.0f));
		float 	fConst42 = (15791.367041742973f * (fConst39 / fConst0));
		fConst43 = (((fConst39 * (fConst42 + -232.71056693257725f)) / fConst0) + 1.0f);
		float 	fConst44 = (((fConst39 * (fConst42 + 232.71056693257725f)) / fConst0) + 1.0f);
		fConst45 = (1.0f / fConst44);
		fConst46 = (((fConst39 * (fConst42 + -95.926493239382992f)) / fConst0) + 1.0f);
		float 	fConst47 = (((fConst39 * (fConst42 + 95.926493239382992f)) / fConst0) + 1.0f);
		fConst48 = (1.0f / fConst47);
		fConst49 = (fConst40 / (fConst1 * fConst47));
		fConst50 = (fConst40 / (fConst1 * fConst44));
		fConst51 = powf(0.5f,(10.0f / fConst0));
		fConst52 = (1.3700000000000001f * fConst31);
		fConst53 = (0 - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) fRec26[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<3; i++) fRec30[i] = 0;
		for (int i=0; i<3; i++) fRec31[i] = 0;
		for (int i=0; i<3; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) iRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) iRec47[i] = 0;
		for (int i=0; i<2; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) iRec40[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<3; i++) fRec54[i] = 0;
		for (int i=0; i<3; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) iRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) iRec70[i] = 0;
		for (int i=0; i<2; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) iRec63[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) fRec74[i] = 0;
		for (int i=0; i<3; i++) fRec76[i] = 0;
		for (int i=0; i<3; i++) fRec77[i] = 0;
		for (int i=0; i<3; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) iRec93[i] = 0;
		for (int i=0; i<2; i++) iRec94[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<3; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<3; i++) fRec99[i] = 0;
		for (int i=0; i<3; i++) fRec100[i] = 0;
		for (int i=0; i<3; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) iRec113[i] = 0;
		for (int i=0; i<2; i++) fRec114[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<2; i++) iRec116[i] = 0;
		for (int i=0; i<2; i++) iRec117[i] = 0;
		for (int i=0; i<2; i++) iRec109[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fRec119[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<3; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<3; i++) fRec120[i] = 0;
		for (int i=0; i<3; i++) fRec122[i] = 0;
		for (int i=0; i<3; i++) fRec123[i] = 0;
		for (int i=0; i<3; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
		for (int i=0; i<2; i++) fRec126[i] = 0;
		for (int i=0; i<2; i++) fRec135[i] = 0;
		for (int i=0; i<2; i++) fRec134[i] = 0;
		for (int i=0; i<2; i++) iRec136[i] = 0;
		for (int i=0; i<2; i++) fRec137[i] = 0;
		for (int i=0; i<2; i++) fRec138[i] = 0;
		for (int i=0; i<2; i++) iRec139[i] = 0;
		for (int i=0; i<2; i++) iRec140[i] = 0;
		for (int i=0; i<2; i++) iRec132[i] = 0;
		for (int i=0; i<2; i++) fRec141[i] = 0;
		for (int i=0; i<2; i++) fRec142[i] = 0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<3; i++) fRec131[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<2; i++) fRec129[i] = 0;
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
			float 	fTemp23 = float((iRec22[0] + (-1 - iRec21[0])));
			int 	iTemp24 = int((iRec13[1] >= 1));
			int 	iTemp25 = int((fSlow32 >= fRec14[1]));
			int 	iTemp26 = int((iRec13[1] >= 3));
			int 	iTemp27 = int((iRec13[1] >= 2));
			int 	iTemp28 = int((iRec13[1] >= 5));
			int 	iTemp29 = int((iRec13[1] >= 6));
			int 	iTemp30 = int((iRec13[1] >= 4));
			fbargraph1 = ((iTemp30)?((iTemp29)?((iSlow40)?3:((iTemp25)?5:6)):((iTemp28)?((iSlow40)?3:((int((fSlow32 <= fRec14[1])))?6:5)):((int((fRec14[1] <= 0.050000000000000003f)))?0:4))):((iTemp27)?((iTemp26)?((int((iSlow42 & (fRec14[1] <= 0.01f))))?4:((int((fSlow32 > fRec14[1])))?1:3)):((iTemp25)?5:iSlow41)):((iTemp24)?((int(((fTemp23 >= fConst33) & (fRec14[1] >= (fbargraph0 * fTemp17)))))?2:1):iSlow35)));
			iRec13[0] = fbargraph1;
			float 	fTemp31 = ((iTemp21)?min((float)1, fTemp20):fSlow32);
			float 	fTemp32 = ((iTemp24)?fConst33:0.0f);
			float 	fTemp33 = ((iTemp30)?((iTemp29)?fConst0:((iTemp28)?fConst0:fConst35)):((iTemp27)?((iTemp26)?2.0f:fConst34):fTemp32));
			float 	fTemp34 = fabsf(fRec15[0]);
			fbargraph2 = ((fTemp34 * ((iTemp16)?((iTemp30)?((iTemp29)?fConst36:((iTemp28)?fConst36:fConst35)):((iTemp27)?((iTemp26)?8.0f:fConst34):fTemp32)):((int((iTemp15 == 1)))?fTemp33:((iTemp30)?fConst35:((iTemp27)?((iTemp26)?0.01f:fConst34):fTemp32))))) + ((1.0f - fTemp34) * fTemp33));
			float 	fTemp35 = fbargraph2;
			float 	fTemp36 = (1.0f / fTemp35);
			float 	fTemp37 = (fRec23[1] - fTemp36);
			float 	fTemp38 = (fRec23[1] + fTemp36);
			fRec23[0] = ((int((fTemp38 < fTemp31)))?fTemp38:((int((fTemp37 > fTemp31)))?fTemp37:fTemp31));
			fbargraph3 = fRec19[0];
			int 	iTemp39 = int((iRec13[1] == 3));
			float 	fTemp40 = ((iTemp39)?(fbargraph3 * expf((0 - (fConst37 * (fTemp23 * (0 - (0 - (2.9957322735539909f / fTemp35)))))))):0.0f);
			float 	fTemp41 = (fRec24[1] + -100.0f);
			float 	fTemp42 = (fRec24[1] + 100.0f);
			fRec24[0] = ((int((fTemp42 < fTemp40)))?fTemp42:((int((fTemp41 > fTemp40)))?fTemp41:fTemp40));
			fRec14[0] = ((iTemp39)?fRec24[0]:fRec23[0]);
			fRec12[0] = (fRec14[0] - (fConst30 * ((fConst28 * fRec12[2]) + (fConst26 * fRec12[1]))));
			float 	fTemp43 = (((3947.8417604357433f * fRec12[0]) + (7895.6835208714865f * fRec12[1])) + (3947.8417604357433f * fRec12[2]));
			fRec27[0] = (fSlow43 - (fConst48 * ((fConst46 * fRec27[2]) + (fConst41 * fRec27[1]))));
			fRec26[0] = ((fConst49 * (((15791.367041742973f * fRec27[0]) + (31582.734083485946f * fRec27[1])) + (15791.367041742973f * fRec27[2]))) - (fConst45 * ((fConst43 * fRec26[2]) + (fConst41 * fRec26[1]))));
			fRec25[0] = (fConst51 * max(fRec25[1], min((fConst50 * (((15791.367041742973f * fRec26[0]) + (31582.734083485946f * fRec26[1])) + (15791.367041742973f * fRec26[2]))), (float)2)));
			float 	fTemp44 = max((fRec25[0] + -1.0f), (float)0);
			float 	fTemp45 = tanf((fConst32 * min((fSlow44 * (faustpower<2>((fTemp44 + (fConst31 * (fTemp43 * (1.0f - fTemp11))))) + 1.0f)), (float)16000)));
			float 	fTemp46 = ((fTemp45 * (fTemp45 + (1.0f / ((8.0f * fTemp11) + 1.0f)))) + 1.0f);
			float 	fTemp47 = (fRec9[1] + (fTemp45 * (fTemp2 - fRec10[1])));
			float 	fTemp48 = (fTemp47 / fTemp46);
			fRec9[0] = ((2.0f * fTemp48) - fRec9[1]);
			float 	fTemp49 = (fRec10[1] + ((fTemp45 * fTemp47) / fTemp46));
			fRec10[0] = ((2.0f * fTemp49) - fRec10[1]);
			float 	fRec11 = fTemp49;
			fRec29[0] = (fSlow48 + (fRec29[1] - float((iSlow46 * ((fSlow48 + fRec29[1]) > fSlow47)))));
			int 	iTemp50 = int(fRec29[0]);
			float 	fTemp51 = ftbl0[iTemp50];
			float 	fTemp52 = (fTemp51 + ((fRec29[0] - float(iTemp50)) * (ftbl0[((iTemp50 + 1) % iSlow46)] - fTemp51)));
			fRec28[0] = (fTemp52 - (((fSlow7 * fRec28[2]) + (2.0f * (fSlow6 * fRec28[1]))) / fSlow5));
			fRec30[0] = (fTemp52 - (((fSlow20 * fRec30[2]) + (2.0f * (fSlow19 * fRec30[1]))) / fSlow18));
			fRec31[0] = (fTemp52 - (((fSlow29 * fRec31[2]) + (2.0f * (fSlow28 * fRec31[1]))) / fSlow27));
			fRec32[0] = (fSlow49 - (fConst30 * ((fConst28 * fRec32[2]) + (fConst26 * fRec32[1]))));
			float 	fTemp53 = ((fConst31 * (((3947.8417604357433f * fRec32[0]) + (7895.6835208714865f * fRec32[1])) + (3947.8417604357433f * fRec32[2]))) + 1.0f);
			float 	fTemp54 = (0.5f * fTemp53);
			float 	fTemp55 = max(fTemp54, (float)0);
			float 	fTemp56 = tanf((fConst32 * ((fSlow51 * (fTemp53 * fTemp55)) + 200.0f)));
			float 	fTemp57 = ((fTemp56 * (fTemp56 + 0.5f)) + 1.0f);
			float 	fTemp58 = (fRec33[1] + (fTemp56 * (fTemp52 - fRec34[1])));
			float 	fTemp59 = (fTemp58 / fTemp57);
			fRec33[0] = ((2.0f * fTemp59) - fRec33[1]);
			float 	fTemp60 = (fRec34[1] + ((fTemp56 * fTemp58) / fTemp57));
			fRec34[0] = ((2.0f * fTemp60) - fRec34[1]);
			float 	fRec35 = fTemp59;
			float 	fTemp61 = max((-1 * fTemp54), (float)0);
			float 	fTemp62 = (1.0f / ((int((iSlow57 == ((fRec42[1] > 0.0f) - (fRec42[1] < 0.0f)))))?((int((fSlow55 >= fabsf(fRec42[1]))))?fConst33:fConst0):fSlow56));
			float 	fTemp63 = (fRec43[1] - fTemp62);
			float 	fTemp64 = (fRec43[1] + fTemp62);
			fRec43[0] = ((int((fTemp64 < fSlow54)))?fTemp64:((int((fTemp63 > fSlow54)))?fTemp63:fSlow54));
			fRec42[0] = fRec43[0];
			int 	iTemp65 = ((fRec42[0] > 0.0f) + (1 - (fRec42[0] < 0.0f)));
			int 	iTemp66 = int((iTemp65 == 0));
			float 	fTemp67 = ((iTemp66)?1.7f:1.6000000000000001f);
			iRec44[0] = iRec40[1];
			int 	iTemp68 = int((iRec44[1] == iRec40[1]));
			int 	iTemp69 = int((iRec40[1] == 0));
			fRec45[0] = ((iTemp69)?fSlow50:((iTemp68)?min(min(fRec45[1], fSlow50), fRec41[1]):min(fSlow50, fRec41[1])));
			float 	fTemp70 = (fSlow50 * fTemp67);
			int 	iTemp71 = int((iRec40[1] == 1));
			fRec46[0] = ((iTemp69)?fSlow50:((iTemp71)?((iTemp68)?max(max(fRec46[1], fTemp70), fRec41[1]):max(fTemp70, fRec41[1])):((iTemp68)?max(max(fRec46[1], fSlow50), fRec41[1]):max(fSlow50, fRec41[1]))));
			fbargraph4 = fRec45[0];
			iRec47[0] = iRec40[1];
			iRec48[0] = ((int((iRec47[1] != iRec40[1])))?iTemp22:iRec48[1]);
			float 	fTemp72 = float((iRec22[0] + (-1 - iRec48[0])));
			int 	iTemp73 = int((iRec40[1] >= 1));
			int 	iTemp74 = int((fSlow50 >= fRec41[1]));
			int 	iTemp75 = int((iRec40[1] >= 3));
			int 	iTemp76 = int((iRec40[1] >= 2));
			int 	iTemp77 = int((iRec40[1] >= 5));
			int 	iTemp78 = int((iRec40[1] >= 6));
			int 	iTemp79 = int((iRec40[1] >= 4));
			fbargraph5 = ((iTemp79)?((iTemp78)?((iSlow58)?3:((iTemp74)?5:6)):((iTemp77)?((iSlow58)?3:((int((fSlow50 <= fRec41[1])))?6:5)):((int((fRec41[1] <= 0.050000000000000003f)))?0:4))):((iTemp76)?((iTemp75)?((int((iSlow60 & (fRec41[1] <= 0.01f))))?4:((int((fSlow50 > fRec41[1])))?1:3)):((iTemp74)?5:iSlow59)):((iTemp73)?((int(((fTemp72 >= fConst33) & (fRec41[1] >= (fbargraph4 * fTemp67)))))?2:1):iSlow53)));
			iRec40[0] = fbargraph5;
			float 	fTemp80 = ((iTemp71)?min((float)1, fTemp70):fSlow50);
			float 	fTemp81 = ((iTemp73)?fConst33:0.0f);
			float 	fTemp82 = ((iTemp79)?((iTemp78)?fConst0:((iTemp77)?fConst0:fConst35)):((iTemp76)?((iTemp75)?2.0f:fConst34):fTemp81));
			float 	fTemp83 = fabsf(fRec42[0]);
			fbargraph6 = ((fTemp83 * ((iTemp66)?((iTemp79)?((iTemp78)?fConst36:((iTemp77)?fConst36:fConst35)):((iTemp76)?((iTemp75)?8.0f:fConst34):fTemp81)):((int((iTemp65 == 1)))?fTemp82:((iTemp79)?fConst35:((iTemp76)?((iTemp75)?0.01f:fConst34):fTemp81))))) + ((1.0f - fTemp83) * fTemp82));
			float 	fTemp84 = fbargraph6;
			float 	fTemp85 = (1.0f / fTemp84);
			float 	fTemp86 = (fRec49[1] - fTemp85);
			float 	fTemp87 = (fRec49[1] + fTemp85);
			fRec49[0] = ((int((fTemp87 < fTemp80)))?fTemp87:((int((fTemp86 > fTemp80)))?fTemp86:fTemp80));
			fbargraph7 = fRec46[0];
			int 	iTemp88 = int((iRec40[1] == 3));
			float 	fTemp89 = ((iTemp88)?(fbargraph7 * expf((0 - (fConst37 * (fTemp72 * (0 - (0 - (2.9957322735539909f / fTemp84)))))))):0.0f);
			float 	fTemp90 = (fRec50[1] + -100.0f);
			float 	fTemp91 = (fRec50[1] + 100.0f);
			fRec50[0] = ((int((fTemp91 < fTemp89)))?fTemp91:((int((fTemp90 > fTemp89)))?fTemp90:fTemp89));
			fRec41[0] = ((iTemp88)?fRec50[0]:fRec49[0]);
			fRec39[0] = (fRec41[0] - (fConst30 * ((fConst28 * fRec39[2]) + (fConst26 * fRec39[1]))));
			float 	fTemp92 = (((3947.8417604357433f * fRec39[0]) + (7895.6835208714865f * fRec39[1])) + (3947.8417604357433f * fRec39[2]));
			float 	fTemp93 = tanf((fConst32 * min((fSlow61 * (faustpower<2>((fTemp44 + (fConst31 * (fTemp92 * (1.0f - fTemp61))))) + 1.0f)), (float)16000)));
			float 	fTemp94 = ((fTemp93 * (fTemp93 + (1.0f / ((8.0f * fTemp61) + 1.0f)))) + 1.0f);
			float 	fTemp95 = (fRec36[1] + (fTemp93 * (fTemp52 - fRec37[1])));
			float 	fTemp96 = (fTemp95 / fTemp94);
			fRec36[0] = ((2.0f * fTemp96) - fRec36[1]);
			float 	fTemp97 = (fRec37[1] + ((fTemp93 * fTemp95) / fTemp94));
			fRec37[0] = ((2.0f * fTemp97) - fRec37[1]);
			float 	fRec38 = fTemp97;
			fRec52[0] = (fSlow65 + (fRec52[1] - float((iSlow63 * ((fSlow65 + fRec52[1]) > fSlow64)))));
			int 	iTemp98 = int(fRec52[0]);
			float 	fTemp99 = ftbl0[iTemp98];
			float 	fTemp100 = (fTemp99 + ((fRec52[0] - float(iTemp98)) * (ftbl0[((iTemp98 + 1) % iSlow63)] - fTemp99)));
			fRec51[0] = (fTemp100 - (((fSlow7 * fRec51[2]) + (2.0f * (fSlow6 * fRec51[1]))) / fSlow5));
			fRec53[0] = (fTemp100 - (((fSlow20 * fRec53[2]) + (2.0f * (fSlow19 * fRec53[1]))) / fSlow18));
			fRec54[0] = (fTemp100 - (((fSlow29 * fRec54[2]) + (2.0f * (fSlow28 * fRec54[1]))) / fSlow27));
			fRec55[0] = (fSlow66 - (fConst30 * ((fConst28 * fRec55[2]) + (fConst26 * fRec55[1]))));
			float 	fTemp101 = ((fConst31 * (((3947.8417604357433f * fRec55[0]) + (7895.6835208714865f * fRec55[1])) + (3947.8417604357433f * fRec55[2]))) + 1.0f);
			float 	fTemp102 = (0.5f * fTemp101);
			float 	fTemp103 = max(fTemp102, (float)0);
			float 	fTemp104 = tanf((fConst32 * ((fSlow68 * (fTemp101 * fTemp103)) + 200.0f)));
			float 	fTemp105 = ((fTemp104 * (fTemp104 + 0.5f)) + 1.0f);
			float 	fTemp106 = (fRec56[1] + (fTemp104 * (fTemp100 - fRec57[1])));
			float 	fTemp107 = (fTemp106 / fTemp105);
			fRec56[0] = ((2.0f * fTemp107) - fRec56[1]);
			float 	fTemp108 = (fRec57[1] + ((fTemp104 * fTemp106) / fTemp105));
			fRec57[0] = ((2.0f * fTemp108) - fRec57[1]);
			float 	fRec58 = fTemp107;
			float 	fTemp109 = max((-1 * fTemp102), (float)0);
			float 	fTemp110 = (1.0f / ((int((iSlow74 == ((fRec65[1] > 0.0f) - (fRec65[1] < 0.0f)))))?((int((fSlow72 >= fabsf(fRec65[1]))))?fConst33:fConst0):fSlow73));
			float 	fTemp111 = (fRec66[1] - fTemp110);
			float 	fTemp112 = (fRec66[1] + fTemp110);
			fRec66[0] = ((int((fTemp112 < fSlow71)))?fTemp112:((int((fTemp111 > fSlow71)))?fTemp111:fSlow71));
			fRec65[0] = fRec66[0];
			int 	iTemp113 = ((fRec65[0] > 0.0f) + (1 - (fRec65[0] < 0.0f)));
			int 	iTemp114 = int((iTemp113 == 0));
			float 	fTemp115 = ((iTemp114)?1.7f:1.6000000000000001f);
			iRec67[0] = iRec63[1];
			int 	iTemp116 = int((iRec67[1] == iRec63[1]));
			int 	iTemp117 = int((iRec63[1] == 0));
			fRec68[0] = ((iTemp117)?fSlow67:((iTemp116)?min(min(fRec68[1], fSlow67), fRec64[1]):min(fSlow67, fRec64[1])));
			float 	fTemp118 = (fSlow67 * fTemp115);
			int 	iTemp119 = int((iRec63[1] == 1));
			fRec69[0] = ((iTemp117)?fSlow67:((iTemp119)?((iTemp116)?max(max(fRec69[1], fTemp118), fRec64[1]):max(fTemp118, fRec64[1])):((iTemp116)?max(max(fRec69[1], fSlow67), fRec64[1]):max(fSlow67, fRec64[1]))));
			fbargraph8 = fRec68[0];
			iRec70[0] = iRec63[1];
			iRec71[0] = ((int((iRec70[1] != iRec63[1])))?iTemp22:iRec71[1]);
			float 	fTemp120 = float((iRec22[0] + (-1 - iRec71[0])));
			int 	iTemp121 = int((iRec63[1] >= 1));
			int 	iTemp122 = int((fSlow67 >= fRec64[1]));
			int 	iTemp123 = int((iRec63[1] >= 3));
			int 	iTemp124 = int((iRec63[1] >= 2));
			int 	iTemp125 = int((iRec63[1] >= 5));
			int 	iTemp126 = int((iRec63[1] >= 6));
			int 	iTemp127 = int((iRec63[1] >= 4));
			fbargraph9 = ((iTemp127)?((iTemp126)?((iSlow75)?3:((iTemp122)?5:6)):((iTemp125)?((iSlow75)?3:((int((fSlow67 <= fRec64[1])))?6:5)):((int((fRec64[1] <= 0.050000000000000003f)))?0:4))):((iTemp124)?((iTemp123)?((int((iSlow77 & (fRec64[1] <= 0.01f))))?4:((int((fSlow67 > fRec64[1])))?1:3)):((iTemp122)?5:iSlow76)):((iTemp121)?((int(((fTemp120 >= fConst33) & (fRec64[1] >= (fbargraph8 * fTemp115)))))?2:1):iSlow70)));
			iRec63[0] = fbargraph9;
			float 	fTemp128 = ((iTemp119)?min((float)1, fTemp118):fSlow67);
			float 	fTemp129 = ((iTemp121)?fConst33:0.0f);
			float 	fTemp130 = ((iTemp127)?((iTemp126)?fConst0:((iTemp125)?fConst0:fConst35)):((iTemp124)?((iTemp123)?2.0f:fConst34):fTemp129));
			float 	fTemp131 = fabsf(fRec65[0]);
			fbargraph10 = ((fTemp131 * ((iTemp114)?((iTemp127)?((iTemp126)?fConst36:((iTemp125)?fConst36:fConst35)):((iTemp124)?((iTemp123)?8.0f:fConst34):fTemp129)):((int((iTemp113 == 1)))?fTemp130:((iTemp127)?fConst35:((iTemp124)?((iTemp123)?0.01f:fConst34):fTemp129))))) + ((1.0f - fTemp131) * fTemp130));
			float 	fTemp132 = fbargraph10;
			float 	fTemp133 = (1.0f / fTemp132);
			float 	fTemp134 = (fRec72[1] - fTemp133);
			float 	fTemp135 = (fRec72[1] + fTemp133);
			fRec72[0] = ((int((fTemp135 < fTemp128)))?fTemp135:((int((fTemp134 > fTemp128)))?fTemp134:fTemp128));
			fbargraph11 = fRec69[0];
			int 	iTemp136 = int((iRec63[1] == 3));
			float 	fTemp137 = ((iTemp136)?(fbargraph11 * expf((0 - (fConst37 * (fTemp120 * (0 - (0 - (2.9957322735539909f / fTemp132)))))))):0.0f);
			float 	fTemp138 = (fRec73[1] + -100.0f);
			float 	fTemp139 = (fRec73[1] + 100.0f);
			fRec73[0] = ((int((fTemp139 < fTemp137)))?fTemp139:((int((fTemp138 > fTemp137)))?fTemp138:fTemp137));
			fRec64[0] = ((iTemp136)?fRec73[0]:fRec72[0]);
			fRec62[0] = (fRec64[0] - (fConst30 * ((fConst28 * fRec62[2]) + (fConst26 * fRec62[1]))));
			float 	fTemp140 = (((3947.8417604357433f * fRec62[0]) + (7895.6835208714865f * fRec62[1])) + (3947.8417604357433f * fRec62[2]));
			float 	fTemp141 = tanf((fConst32 * min((fSlow78 * (faustpower<2>((fTemp44 + (fConst31 * (fTemp140 * (1.0f - fTemp109))))) + 1.0f)), (float)16000)));
			float 	fTemp142 = ((fTemp141 * (fTemp141 + (1.0f / ((8.0f * fTemp109) + 1.0f)))) + 1.0f);
			float 	fTemp143 = (fRec59[1] + (fTemp141 * (fTemp100 - fRec60[1])));
			float 	fTemp144 = (fTemp143 / fTemp142);
			fRec59[0] = ((2.0f * fTemp144) - fRec59[1]);
			float 	fTemp145 = (fRec60[1] + ((fTemp141 * fTemp143) / fTemp142));
			fRec60[0] = ((2.0f * fTemp145) - fRec60[1]);
			float 	fRec61 = fTemp145;
			fRec75[0] = (fSlow82 + (fRec75[1] - float((iSlow80 * ((fSlow82 + fRec75[1]) > fSlow81)))));
			int 	iTemp146 = int(fRec75[0]);
			float 	fTemp147 = ftbl0[iTemp146];
			float 	fTemp148 = (fTemp147 + ((fRec75[0] - float(iTemp146)) * (ftbl0[((iTemp146 + 1) % iSlow80)] - fTemp147)));
			fRec74[0] = (fTemp148 - (((fSlow7 * fRec74[2]) + (2.0f * (fSlow6 * fRec74[1]))) / fSlow5));
			fRec76[0] = (fTemp148 - (((fSlow20 * fRec76[2]) + (2.0f * (fSlow19 * fRec76[1]))) / fSlow18));
			fRec77[0] = (fTemp148 - (((fSlow29 * fRec77[2]) + (2.0f * (fSlow28 * fRec77[1]))) / fSlow27));
			fRec78[0] = (fSlow83 - (fConst30 * ((fConst28 * fRec78[2]) + (fConst26 * fRec78[1]))));
			float 	fTemp149 = ((fConst31 * (((3947.8417604357433f * fRec78[0]) + (7895.6835208714865f * fRec78[1])) + (3947.8417604357433f * fRec78[2]))) + 1.0f);
			float 	fTemp150 = (0.5f * fTemp149);
			float 	fTemp151 = max(fTemp150, (float)0);
			float 	fTemp152 = tanf((fConst32 * ((fSlow85 * (fTemp149 * fTemp151)) + 200.0f)));
			float 	fTemp153 = ((fTemp152 * (fTemp152 + 0.5f)) + 1.0f);
			float 	fTemp154 = (fRec79[1] + (fTemp152 * (fTemp148 - fRec80[1])));
			float 	fTemp155 = (fTemp154 / fTemp153);
			fRec79[0] = ((2.0f * fTemp155) - fRec79[1]);
			float 	fTemp156 = (fRec80[1] + ((fTemp152 * fTemp154) / fTemp153));
			fRec80[0] = ((2.0f * fTemp156) - fRec80[1]);
			float 	fRec81 = fTemp155;
			float 	fTemp157 = max((-1 * fTemp150), (float)0);
			float 	fTemp158 = (1.0f / ((int((iSlow91 == ((fRec88[1] > 0.0f) - (fRec88[1] < 0.0f)))))?((int((fSlow89 >= fabsf(fRec88[1]))))?fConst33:fConst0):fSlow90));
			float 	fTemp159 = (fRec89[1] - fTemp158);
			float 	fTemp160 = (fRec89[1] + fTemp158);
			fRec89[0] = ((int((fTemp160 < fSlow88)))?fTemp160:((int((fTemp159 > fSlow88)))?fTemp159:fSlow88));
			fRec88[0] = fRec89[0];
			int 	iTemp161 = ((fRec88[0] > 0.0f) + (1 - (fRec88[0] < 0.0f)));
			int 	iTemp162 = int((iTemp161 == 0));
			float 	fTemp163 = ((iTemp162)?1.7f:1.6000000000000001f);
			iRec90[0] = iRec86[1];
			int 	iTemp164 = int((iRec90[1] == iRec86[1]));
			int 	iTemp165 = int((iRec86[1] == 0));
			fRec91[0] = ((iTemp165)?fSlow84:((iTemp164)?min(min(fRec91[1], fSlow84), fRec87[1]):min(fSlow84, fRec87[1])));
			float 	fTemp166 = (fSlow84 * fTemp163);
			int 	iTemp167 = int((iRec86[1] == 1));
			fRec92[0] = ((iTemp165)?fSlow84:((iTemp167)?((iTemp164)?max(max(fRec92[1], fTemp166), fRec87[1]):max(fTemp166, fRec87[1])):((iTemp164)?max(max(fRec92[1], fSlow84), fRec87[1]):max(fSlow84, fRec87[1]))));
			fbargraph12 = fRec91[0];
			iRec93[0] = iRec86[1];
			iRec94[0] = ((int((iRec93[1] != iRec86[1])))?iTemp22:iRec94[1]);
			float 	fTemp168 = float((iRec22[0] + (-1 - iRec94[0])));
			int 	iTemp169 = int((iRec86[1] >= 1));
			int 	iTemp170 = int((fSlow84 >= fRec87[1]));
			int 	iTemp171 = int((iRec86[1] >= 3));
			int 	iTemp172 = int((iRec86[1] >= 2));
			int 	iTemp173 = int((iRec86[1] >= 5));
			int 	iTemp174 = int((iRec86[1] >= 6));
			int 	iTemp175 = int((iRec86[1] >= 4));
			fbargraph13 = ((iTemp175)?((iTemp174)?((iSlow92)?3:((iTemp170)?5:6)):((iTemp173)?((iSlow92)?3:((int((fSlow84 <= fRec87[1])))?6:5)):((int((fRec87[1] <= 0.050000000000000003f)))?0:4))):((iTemp172)?((iTemp171)?((int((iSlow94 & (fRec87[1] <= 0.01f))))?4:((int((fSlow84 > fRec87[1])))?1:3)):((iTemp170)?5:iSlow93)):((iTemp169)?((int(((fTemp168 >= fConst33) & (fRec87[1] >= (fbargraph12 * fTemp163)))))?2:1):iSlow87)));
			iRec86[0] = fbargraph13;
			float 	fTemp176 = ((iTemp167)?min((float)1, fTemp166):fSlow84);
			float 	fTemp177 = ((iTemp169)?fConst33:0.0f);
			float 	fTemp178 = ((iTemp175)?((iTemp174)?fConst0:((iTemp173)?fConst0:fConst35)):((iTemp172)?((iTemp171)?2.0f:fConst34):fTemp177));
			float 	fTemp179 = fabsf(fRec88[0]);
			fbargraph14 = ((fTemp179 * ((iTemp162)?((iTemp175)?((iTemp174)?fConst36:((iTemp173)?fConst36:fConst35)):((iTemp172)?((iTemp171)?8.0f:fConst34):fTemp177)):((int((iTemp161 == 1)))?fTemp178:((iTemp175)?fConst35:((iTemp172)?((iTemp171)?0.01f:fConst34):fTemp177))))) + ((1.0f - fTemp179) * fTemp178));
			float 	fTemp180 = fbargraph14;
			float 	fTemp181 = (1.0f / fTemp180);
			float 	fTemp182 = (fRec95[1] - fTemp181);
			float 	fTemp183 = (fRec95[1] + fTemp181);
			fRec95[0] = ((int((fTemp183 < fTemp176)))?fTemp183:((int((fTemp182 > fTemp176)))?fTemp182:fTemp176));
			fbargraph15 = fRec92[0];
			int 	iTemp184 = int((iRec86[1] == 3));
			float 	fTemp185 = ((iTemp184)?(fbargraph15 * expf((0 - (fConst37 * (fTemp168 * (0 - (0 - (2.9957322735539909f / fTemp180)))))))):0.0f);
			float 	fTemp186 = (fRec96[1] + -100.0f);
			float 	fTemp187 = (fRec96[1] + 100.0f);
			fRec96[0] = ((int((fTemp187 < fTemp185)))?fTemp187:((int((fTemp186 > fTemp185)))?fTemp186:fTemp185));
			fRec87[0] = ((iTemp184)?fRec96[0]:fRec95[0]);
			fRec85[0] = (fRec87[0] - (fConst30 * ((fConst28 * fRec85[2]) + (fConst26 * fRec85[1]))));
			float 	fTemp188 = (((3947.8417604357433f * fRec85[0]) + (7895.6835208714865f * fRec85[1])) + (3947.8417604357433f * fRec85[2]));
			float 	fTemp189 = tanf((fConst32 * min((fSlow95 * (faustpower<2>((fTemp44 + (fConst31 * (fTemp188 * (1.0f - fTemp157))))) + 1.0f)), (float)16000)));
			float 	fTemp190 = ((fTemp189 * (fTemp189 + (1.0f / ((8.0f * fTemp157) + 1.0f)))) + 1.0f);
			float 	fTemp191 = (fRec82[1] + (fTemp189 * (fTemp148 - fRec83[1])));
			float 	fTemp192 = (fTemp191 / fTemp190);
			fRec82[0] = ((2.0f * fTemp192) - fRec82[1]);
			float 	fTemp193 = (fRec83[1] + ((fTemp189 * fTemp191) / fTemp190));
			fRec83[0] = ((2.0f * fTemp193) - fRec83[1]);
			float 	fRec84 = fTemp193;
			fRec98[0] = (fSlow99 + (fRec98[1] - float((iSlow97 * ((fSlow99 + fRec98[1]) > fSlow98)))));
			int 	iTemp194 = int(fRec98[0]);
			float 	fTemp195 = ftbl0[iTemp194];
			float 	fTemp196 = (fTemp195 + ((fRec98[0] - float(iTemp194)) * (ftbl0[((iTemp194 + 1) % iSlow97)] - fTemp195)));
			fRec97[0] = (fTemp196 - (((fSlow7 * fRec97[2]) + (2.0f * (fSlow6 * fRec97[1]))) / fSlow5));
			fRec99[0] = (fTemp196 - (((fSlow20 * fRec99[2]) + (2.0f * (fSlow19 * fRec99[1]))) / fSlow18));
			fRec100[0] = (fTemp196 - (((fSlow29 * fRec100[2]) + (2.0f * (fSlow28 * fRec100[1]))) / fSlow27));
			fRec101[0] = (fSlow100 - (fConst30 * ((fConst28 * fRec101[2]) + (fConst26 * fRec101[1]))));
			float 	fTemp197 = ((fConst31 * (((3947.8417604357433f * fRec101[0]) + (7895.6835208714865f * fRec101[1])) + (3947.8417604357433f * fRec101[2]))) + 1.0f);
			float 	fTemp198 = (0.5f * fTemp197);
			float 	fTemp199 = max(fTemp198, (float)0);
			float 	fTemp200 = tanf((fConst32 * ((fSlow102 * (fTemp197 * fTemp199)) + 200.0f)));
			float 	fTemp201 = ((fTemp200 * (fTemp200 + 0.5f)) + 1.0f);
			float 	fTemp202 = (fRec102[1] + (fTemp200 * (fTemp196 - fRec103[1])));
			float 	fTemp203 = (fTemp202 / fTemp201);
			fRec102[0] = ((2.0f * fTemp203) - fRec102[1]);
			float 	fTemp204 = (fRec103[1] + ((fTemp200 * fTemp202) / fTemp201));
			fRec103[0] = ((2.0f * fTemp204) - fRec103[1]);
			float 	fRec104 = fTemp203;
			float 	fTemp205 = max((-1 * fTemp198), (float)0);
			float 	fTemp206 = (1.0f / ((int((iSlow108 == ((fRec111[1] > 0.0f) - (fRec111[1] < 0.0f)))))?((int((fSlow106 >= fabsf(fRec111[1]))))?fConst33:fConst0):fSlow107));
			float 	fTemp207 = (fRec112[1] - fTemp206);
			float 	fTemp208 = (fRec112[1] + fTemp206);
			fRec112[0] = ((int((fTemp208 < fSlow105)))?fTemp208:((int((fTemp207 > fSlow105)))?fTemp207:fSlow105));
			fRec111[0] = fRec112[0];
			int 	iTemp209 = ((fRec111[0] > 0.0f) + (1 - (fRec111[0] < 0.0f)));
			int 	iTemp210 = int((iTemp209 == 0));
			float 	fTemp211 = ((iTemp210)?1.7f:1.6000000000000001f);
			iRec113[0] = iRec109[1];
			int 	iTemp212 = int((iRec113[1] == iRec109[1]));
			int 	iTemp213 = int((iRec109[1] == 0));
			fRec114[0] = ((iTemp213)?fSlow101:((iTemp212)?min(min(fRec114[1], fSlow101), fRec110[1]):min(fSlow101, fRec110[1])));
			float 	fTemp214 = (fSlow101 * fTemp211);
			int 	iTemp215 = int((iRec109[1] == 1));
			fRec115[0] = ((iTemp213)?fSlow101:((iTemp215)?((iTemp212)?max(max(fRec115[1], fTemp214), fRec110[1]):max(fTemp214, fRec110[1])):((iTemp212)?max(max(fRec115[1], fSlow101), fRec110[1]):max(fSlow101, fRec110[1]))));
			fbargraph16 = fRec114[0];
			iRec116[0] = iRec109[1];
			iRec117[0] = ((int((iRec116[1] != iRec109[1])))?iTemp22:iRec117[1]);
			float 	fTemp216 = float((iRec22[0] + (-1 - iRec117[0])));
			int 	iTemp217 = int((iRec109[1] >= 1));
			int 	iTemp218 = int((fSlow101 >= fRec110[1]));
			int 	iTemp219 = int((iRec109[1] >= 3));
			int 	iTemp220 = int((iRec109[1] >= 2));
			int 	iTemp221 = int((iRec109[1] >= 5));
			int 	iTemp222 = int((iRec109[1] >= 6));
			int 	iTemp223 = int((iRec109[1] >= 4));
			fbargraph17 = ((iTemp223)?((iTemp222)?((iSlow109)?3:((iTemp218)?5:6)):((iTemp221)?((iSlow109)?3:((int((fSlow101 <= fRec110[1])))?6:5)):((int((fRec110[1] <= 0.050000000000000003f)))?0:4))):((iTemp220)?((iTemp219)?((int((iSlow111 & (fRec110[1] <= 0.01f))))?4:((int((fSlow101 > fRec110[1])))?1:3)):((iTemp218)?5:iSlow110)):((iTemp217)?((int(((fTemp216 >= fConst33) & (fRec110[1] >= (fbargraph16 * fTemp211)))))?2:1):iSlow104)));
			iRec109[0] = fbargraph17;
			float 	fTemp224 = ((iTemp215)?min((float)1, fTemp214):fSlow101);
			float 	fTemp225 = ((iTemp217)?fConst33:0.0f);
			float 	fTemp226 = ((iTemp223)?((iTemp222)?fConst0:((iTemp221)?fConst0:fConst35)):((iTemp220)?((iTemp219)?2.0f:fConst34):fTemp225));
			float 	fTemp227 = fabsf(fRec111[0]);
			fbargraph18 = ((fTemp227 * ((iTemp210)?((iTemp223)?((iTemp222)?fConst36:((iTemp221)?fConst36:fConst35)):((iTemp220)?((iTemp219)?8.0f:fConst34):fTemp225)):((int((iTemp209 == 1)))?fTemp226:((iTemp223)?fConst35:((iTemp220)?((iTemp219)?0.01f:fConst34):fTemp225))))) + ((1.0f - fTemp227) * fTemp226));
			float 	fTemp228 = fbargraph18;
			float 	fTemp229 = (1.0f / fTemp228);
			float 	fTemp230 = (fRec118[1] - fTemp229);
			float 	fTemp231 = (fRec118[1] + fTemp229);
			fRec118[0] = ((int((fTemp231 < fTemp224)))?fTemp231:((int((fTemp230 > fTemp224)))?fTemp230:fTemp224));
			fbargraph19 = fRec115[0];
			int 	iTemp232 = int((iRec109[1] == 3));
			float 	fTemp233 = ((iTemp232)?(fbargraph19 * expf((0 - (fConst37 * (fTemp216 * (0 - (0 - (2.9957322735539909f / fTemp228)))))))):0.0f);
			float 	fTemp234 = (fRec119[1] + -100.0f);
			float 	fTemp235 = (fRec119[1] + 100.0f);
			fRec119[0] = ((int((fTemp235 < fTemp233)))?fTemp235:((int((fTemp234 > fTemp233)))?fTemp234:fTemp233));
			fRec110[0] = ((iTemp232)?fRec119[0]:fRec118[0]);
			fRec108[0] = (fRec110[0] - (fConst30 * ((fConst28 * fRec108[2]) + (fConst26 * fRec108[1]))));
			float 	fTemp236 = (((3947.8417604357433f * fRec108[0]) + (7895.6835208714865f * fRec108[1])) + (3947.8417604357433f * fRec108[2]));
			float 	fTemp237 = tanf((fConst32 * min((fSlow112 * (faustpower<2>((fTemp44 + (fConst31 * (fTemp236 * (1.0f - fTemp205))))) + 1.0f)), (float)16000)));
			float 	fTemp238 = ((fTemp237 * (fTemp237 + (1.0f / ((8.0f * fTemp205) + 1.0f)))) + 1.0f);
			float 	fTemp239 = (fRec105[1] + (fTemp237 * (fTemp196 - fRec106[1])));
			float 	fTemp240 = (fTemp239 / fTemp238);
			fRec105[0] = ((2.0f * fTemp240) - fRec105[1]);
			float 	fTemp241 = (fRec106[1] + ((fTemp237 * fTemp239) / fTemp238));
			fRec106[0] = ((2.0f * fTemp241) - fRec106[1]);
			float 	fRec107 = fTemp241;
			fRec121[0] = (fSlow116 + (fRec121[1] - float((iSlow114 * ((fSlow116 + fRec121[1]) > fSlow115)))));
			int 	iTemp242 = int(fRec121[0]);
			float 	fTemp243 = ftbl0[iTemp242];
			float 	fTemp244 = (fTemp243 + ((fRec121[0] - float(iTemp242)) * (ftbl0[((iTemp242 + 1) % iSlow114)] - fTemp243)));
			fRec120[0] = (fTemp244 - (((fSlow7 * fRec120[2]) + (2.0f * (fSlow6 * fRec120[1]))) / fSlow5));
			fRec122[0] = (fTemp244 - (((fSlow20 * fRec122[2]) + (2.0f * (fSlow19 * fRec122[1]))) / fSlow18));
			fRec123[0] = (fTemp244 - (((fSlow29 * fRec123[2]) + (2.0f * (fSlow28 * fRec123[1]))) / fSlow27));
			fRec124[0] = (fSlow117 - (fConst30 * ((fConst28 * fRec124[2]) + (fConst26 * fRec124[1]))));
			float 	fTemp245 = ((fConst31 * (((3947.8417604357433f * fRec124[0]) + (7895.6835208714865f * fRec124[1])) + (3947.8417604357433f * fRec124[2]))) + 1.0f);
			float 	fTemp246 = (0.5f * fTemp245);
			float 	fTemp247 = max(fTemp246, (float)0);
			float 	fTemp248 = tanf((fConst32 * ((fSlow119 * (fTemp245 * fTemp247)) + 200.0f)));
			float 	fTemp249 = ((fTemp248 * (fTemp248 + 0.5f)) + 1.0f);
			float 	fTemp250 = (fRec125[1] + (fTemp248 * (fTemp244 - fRec126[1])));
			float 	fTemp251 = (fTemp250 / fTemp249);
			fRec125[0] = ((2.0f * fTemp251) - fRec125[1]);
			float 	fTemp252 = (fRec126[1] + ((fTemp248 * fTemp250) / fTemp249));
			fRec126[0] = ((2.0f * fTemp252) - fRec126[1]);
			float 	fRec127 = fTemp251;
			float 	fTemp253 = max((-1 * fTemp246), (float)0);
			float 	fTemp254 = (1.0f / ((int((iSlow125 == ((fRec134[1] > 0.0f) - (fRec134[1] < 0.0f)))))?((int((fSlow123 >= fabsf(fRec134[1]))))?fConst33:fConst0):fSlow124));
			float 	fTemp255 = (fRec135[1] - fTemp254);
			float 	fTemp256 = (fRec135[1] + fTemp254);
			fRec135[0] = ((int((fTemp256 < fSlow122)))?fTemp256:((int((fTemp255 > fSlow122)))?fTemp255:fSlow122));
			fRec134[0] = fRec135[0];
			int 	iTemp257 = ((fRec134[0] > 0.0f) + (1 - (fRec134[0] < 0.0f)));
			int 	iTemp258 = int((iTemp257 == 0));
			float 	fTemp259 = ((iTemp258)?1.7f:1.6000000000000001f);
			iRec136[0] = iRec132[1];
			int 	iTemp260 = int((iRec136[1] == iRec132[1]));
			int 	iTemp261 = int((iRec132[1] == 0));
			fRec137[0] = ((iTemp261)?fSlow118:((iTemp260)?min(min(fRec137[1], fSlow118), fRec133[1]):min(fSlow118, fRec133[1])));
			float 	fTemp262 = (fSlow118 * fTemp259);
			int 	iTemp263 = int((iRec132[1] == 1));
			fRec138[0] = ((iTemp261)?fSlow118:((iTemp263)?((iTemp260)?max(max(fRec138[1], fTemp262), fRec133[1]):max(fTemp262, fRec133[1])):((iTemp260)?max(max(fRec138[1], fSlow118), fRec133[1]):max(fSlow118, fRec133[1]))));
			fbargraph20 = fRec137[0];
			iRec139[0] = iRec132[1];
			iRec140[0] = ((int((iRec139[1] != iRec132[1])))?iTemp22:iRec140[1]);
			float 	fTemp264 = float((iRec22[0] + (-1 - iRec140[0])));
			int 	iTemp265 = int((iRec132[1] >= 1));
			int 	iTemp266 = int((fSlow118 >= fRec133[1]));
			int 	iTemp267 = int((iRec132[1] >= 3));
			int 	iTemp268 = int((iRec132[1] >= 2));
			int 	iTemp269 = int((iRec132[1] >= 5));
			int 	iTemp270 = int((iRec132[1] >= 6));
			int 	iTemp271 = int((iRec132[1] >= 4));
			fbargraph21 = ((iTemp271)?((iTemp270)?((iSlow126)?3:((iTemp266)?5:6)):((iTemp269)?((iSlow126)?3:((int((fSlow118 <= fRec133[1])))?6:5)):((int((fRec133[1] <= 0.050000000000000003f)))?0:4))):((iTemp268)?((iTemp267)?((int((iSlow128 & (fRec133[1] <= 0.01f))))?4:((int((fSlow118 > fRec133[1])))?1:3)):((iTemp266)?5:iSlow127)):((iTemp265)?((int(((fTemp264 >= fConst33) & (fRec133[1] >= (fbargraph20 * fTemp259)))))?2:1):iSlow121)));
			iRec132[0] = fbargraph21;
			float 	fTemp272 = ((iTemp263)?min((float)1, fTemp262):fSlow118);
			float 	fTemp273 = ((iTemp265)?fConst33:0.0f);
			float 	fTemp274 = ((iTemp271)?((iTemp270)?fConst0:((iTemp269)?fConst0:fConst35)):((iTemp268)?((iTemp267)?2.0f:fConst34):fTemp273));
			float 	fTemp275 = fabsf(fRec134[0]);
			fbargraph22 = ((fTemp275 * ((iTemp258)?((iTemp271)?((iTemp270)?fConst36:((iTemp269)?fConst36:fConst35)):((iTemp268)?((iTemp267)?8.0f:fConst34):fTemp273)):((int((iTemp257 == 1)))?fTemp274:((iTemp271)?fConst35:((iTemp268)?((iTemp267)?0.01f:fConst34):fTemp273))))) + ((1.0f - fTemp275) * fTemp274));
			float 	fTemp276 = fbargraph22;
			float 	fTemp277 = (1.0f / fTemp276);
			float 	fTemp278 = (fRec141[1] - fTemp277);
			float 	fTemp279 = (fRec141[1] + fTemp277);
			fRec141[0] = ((int((fTemp279 < fTemp272)))?fTemp279:((int((fTemp278 > fTemp272)))?fTemp278:fTemp272));
			fbargraph23 = fRec138[0];
			int 	iTemp280 = int((iRec132[1] == 3));
			float 	fTemp281 = ((iTemp280)?(fbargraph23 * expf((0 - (fConst37 * (fTemp264 * (0 - (0 - (2.9957322735539909f / fTemp276)))))))):0.0f);
			float 	fTemp282 = (fRec142[1] + -100.0f);
			float 	fTemp283 = (fRec142[1] + 100.0f);
			fRec142[0] = ((int((fTemp283 < fTemp281)))?fTemp283:((int((fTemp282 > fTemp281)))?fTemp282:fTemp281));
			fRec133[0] = ((iTemp280)?fRec142[0]:fRec141[0]);
			fRec131[0] = (fRec133[0] - (fConst30 * ((fConst28 * fRec131[2]) + (fConst26 * fRec131[1]))));
			float 	fTemp284 = (((3947.8417604357433f * fRec131[0]) + (7895.6835208714865f * fRec131[1])) + (3947.8417604357433f * fRec131[2]));
			float 	fTemp285 = tanf((fConst32 * min((fSlow129 * (faustpower<2>(((fConst31 * (fTemp284 * (1.0f - fTemp253))) + fTemp44)) + 1.0f)), (float)16000)));
			float 	fTemp286 = ((fTemp285 * (fTemp285 + (1.0f / ((8.0f * fTemp253) + 1.0f)))) + 1.0f);
			float 	fTemp287 = (fRec128[1] + (fTemp285 * (fTemp244 - fRec129[1])));
			float 	fTemp288 = (fTemp287 / fTemp286);
			fRec128[0] = ((2.0f * fTemp288) - fRec128[1]);
			float 	fTemp289 = (fRec129[1] + ((fTemp285 * fTemp287) / fTemp286));
			fRec129[0] = ((2.0f * fTemp289) - fRec129[1]);
			float 	fRec130 = fTemp289;
			fRec0[0] = ((fConst52 * ((((((fTemp284 * (((fRec130 * faustpower<2>((1.0f - (0.5f * fTemp253)))) + (fSlow120 * ((fRec127 * fTemp245) * fTemp247))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec123[0] - fRec123[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec122[0] - fRec122[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec120[0] - fRec120[2])) / fSlow5)))))))) + (fTemp236 * (((fRec107 * faustpower<2>((1.0f - (0.5f * fTemp205)))) + (fSlow103 * ((fRec104 * fTemp197) * fTemp199))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec100[0] - fRec100[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec99[0] - fRec99[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec97[0] - fRec97[2])) / fSlow5))))))))) + (fTemp188 * (((fRec84 * faustpower<2>((1.0f - (0.5f * fTemp157)))) + (fSlow86 * ((fRec81 * fTemp149) * fTemp151))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec77[0] - fRec77[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec76[0] - fRec76[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec74[0] - fRec74[2])) / fSlow5))))))))) + (fTemp140 * (((fRec61 * faustpower<2>((1.0f - (0.5f * fTemp109)))) + (fSlow69 * ((fRec58 * fTemp101) * fTemp103))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec54[0] - fRec54[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec53[0] - fRec53[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec51[0] - fRec51[2])) / fSlow5))))))))) + (fTemp92 * (((fRec38 * faustpower<2>((1.0f - (0.5f * fTemp61)))) + (fSlow52 * ((fRec35 * fTemp53) * fTemp55))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec31[0] - fRec31[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec30[0] - fRec30[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec28[0] - fRec28[2])) / fSlow5))))))))) + (fTemp43 * (((fRec11 * faustpower<2>((1.0f - (0.5f * fTemp11)))) + (fSlow34 * ((fRec8 * fTemp3) * fTemp5))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec4[0] - fRec4[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec3[0] - fRec3[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec1[0] - fRec1[2])) / fSlow5)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)((fConst53 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec129[1] = fRec129[0];
			fRec128[1] = fRec128[0];
			fRec131[2] = fRec131[1]; fRec131[1] = fRec131[0];
			fRec133[1] = fRec133[0];
			fRec142[1] = fRec142[0];
			fRec141[1] = fRec141[0];
			iRec132[1] = iRec132[0];
			iRec140[1] = iRec140[0];
			iRec139[1] = iRec139[0];
			fRec138[1] = fRec138[0];
			fRec137[1] = fRec137[0];
			iRec136[1] = iRec136[0];
			fRec134[1] = fRec134[0];
			fRec135[1] = fRec135[0];
			fRec126[1] = fRec126[0];
			fRec125[1] = fRec125[0];
			fRec124[2] = fRec124[1]; fRec124[1] = fRec124[0];
			fRec123[2] = fRec123[1]; fRec123[1] = fRec123[0];
			fRec122[2] = fRec122[1]; fRec122[1] = fRec122[0];
			fRec120[2] = fRec120[1]; fRec120[1] = fRec120[0];
			fRec121[1] = fRec121[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec108[2] = fRec108[1]; fRec108[1] = fRec108[0];
			fRec110[1] = fRec110[0];
			fRec119[1] = fRec119[0];
			fRec118[1] = fRec118[0];
			iRec109[1] = iRec109[0];
			iRec117[1] = iRec117[0];
			iRec116[1] = iRec116[0];
			fRec115[1] = fRec115[0];
			fRec114[1] = fRec114[0];
			iRec113[1] = iRec113[0];
			fRec111[1] = fRec111[0];
			fRec112[1] = fRec112[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec101[2] = fRec101[1]; fRec101[1] = fRec101[0];
			fRec100[2] = fRec100[1]; fRec100[1] = fRec100[0];
			fRec99[2] = fRec99[1]; fRec99[1] = fRec99[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec98[1] = fRec98[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fRec85[2] = fRec85[1]; fRec85[1] = fRec85[0];
			fRec87[1] = fRec87[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			iRec86[1] = iRec86[0];
			iRec94[1] = iRec94[0];
			iRec93[1] = iRec93[0];
			fRec92[1] = fRec92[0];
			fRec91[1] = fRec91[0];
			iRec90[1] = iRec90[0];
			fRec88[1] = fRec88[0];
			fRec89[1] = fRec89[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec78[2] = fRec78[1]; fRec78[1] = fRec78[0];
			fRec77[2] = fRec77[1]; fRec77[1] = fRec77[0];
			fRec76[2] = fRec76[1]; fRec76[1] = fRec76[0];
			fRec74[2] = fRec74[1]; fRec74[1] = fRec74[0];
			fRec75[1] = fRec75[0];
			fRec60[1] = fRec60[0];
			fRec59[1] = fRec59[0];
			fRec62[2] = fRec62[1]; fRec62[1] = fRec62[0];
			fRec64[1] = fRec64[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			iRec63[1] = iRec63[0];
			iRec71[1] = iRec71[0];
			iRec70[1] = iRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			iRec67[1] = iRec67[0];
			fRec65[1] = fRec65[0];
			fRec66[1] = fRec66[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fRec55[2] = fRec55[1]; fRec55[1] = fRec55[0];
			fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
			fRec52[1] = fRec52[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
			fRec41[1] = fRec41[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			iRec40[1] = iRec40[0];
			iRec48[1] = iRec48[0];
			iRec47[1] = iRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			iRec44[1] = iRec44[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec32[2] = fRec32[1]; fRec32[1] = fRec32[0];
			fRec31[2] = fRec31[1]; fRec31[1] = fRec31[0];
			fRec30[2] = fRec30[1]; fRec30[1] = fRec30[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec29[1] = fRec29[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec25[1] = fRec25[0];
			fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
			fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec24[1] = fRec24[0];
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
