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
	int 	iRec15[2];
	int 	iRec17[2];
	int 	iRec16[2];
	float 	fConst34;
	float 	fConst35;
	int 	iRec13[2];
	int 	iRec18[2];
	float 	fRec19[2];
	float 	fRec20[2];
	FAUSTFLOAT 	fbargraph0;
	FAUSTFLOAT 	fbargraph1;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fConst39;
	float 	fRec14[2];
	float 	fRec12[3];
	float 	fConst43;
	float 	fConst45;
	float 	fConst47;
	float 	fConst48;
	float 	fConst50;
	FAUSTFLOAT 	fslider6;
	float 	fRec23[3];
	float 	fConst51;
	float 	fRec22[3];
	float 	fConst52;
	float 	fConst53;
	float 	fRec21[2];
	float 	fRec9[2];
	float 	fRec10[2];
	FAUSTFLOAT 	fslider7;
	float 	fRec25[2];
	float 	fRec24[3];
	float 	fRec26[3];
	float 	fRec27[3];
	FAUSTFLOAT 	fslider8;
	float 	fRec28[3];
	FAUSTFLOAT 	fslider9;
	float 	fRec29[2];
	float 	fRec30[2];
	int 	iRec38[2];
	int 	iRec39[2];
	int 	iRec36[2];
	int 	iRec40[2];
	float 	fRec41[2];
	float 	fRec42[2];
	FAUSTFLOAT 	fbargraph2;
	FAUSTFLOAT 	fbargraph3;
	float 	fRec37[2];
	float 	fRec35[3];
	float 	fRec32[2];
	float 	fRec33[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec44[2];
	float 	fRec43[3];
	float 	fRec45[3];
	float 	fRec46[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec47[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec48[2];
	float 	fRec49[2];
	int 	iRec57[2];
	int 	iRec58[2];
	int 	iRec55[2];
	int 	iRec59[2];
	float 	fRec60[2];
	float 	fRec61[2];
	FAUSTFLOAT 	fbargraph4;
	FAUSTFLOAT 	fbargraph5;
	float 	fRec56[2];
	float 	fRec54[3];
	float 	fRec51[2];
	float 	fRec52[2];
	FAUSTFLOAT 	fslider13;
	float 	fRec63[2];
	float 	fRec62[3];
	float 	fRec64[3];
	float 	fRec65[3];
	FAUSTFLOAT 	fslider14;
	float 	fRec66[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec67[2];
	float 	fRec68[2];
	int 	iRec76[2];
	int 	iRec77[2];
	int 	iRec74[2];
	int 	iRec78[2];
	float 	fRec79[2];
	float 	fRec80[2];
	FAUSTFLOAT 	fbargraph6;
	FAUSTFLOAT 	fbargraph7;
	float 	fRec75[2];
	float 	fRec73[3];
	float 	fRec70[2];
	float 	fRec71[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec82[2];
	float 	fRec81[3];
	float 	fRec83[3];
	float 	fRec84[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec85[3];
	FAUSTFLOAT 	fslider18;
	float 	fRec86[2];
	float 	fRec87[2];
	int 	iRec95[2];
	int 	iRec96[2];
	int 	iRec93[2];
	int 	iRec97[2];
	float 	fRec98[2];
	float 	fRec99[2];
	FAUSTFLOAT 	fbargraph8;
	FAUSTFLOAT 	fbargraph9;
	float 	fRec94[2];
	float 	fRec92[3];
	float 	fRec89[2];
	float 	fRec90[2];
	FAUSTFLOAT 	fslider19;
	float 	fRec101[2];
	float 	fRec100[3];
	float 	fRec102[3];
	float 	fRec103[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec104[3];
	FAUSTFLOAT 	fslider21;
	float 	fRec105[2];
	float 	fRec106[2];
	int 	iRec114[2];
	int 	iRec115[2];
	int 	iRec112[2];
	int 	iRec116[2];
	float 	fRec117[2];
	float 	fRec118[2];
	FAUSTFLOAT 	fbargraph10;
	FAUSTFLOAT 	fbargraph11;
	float 	fRec113[2];
	float 	fRec111[3];
	float 	fRec108[2];
	float 	fRec109[2];
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
		float 	fConst0 = min(192000.0f, max(1.0f, (float)fSampleRate));
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
		fConst33 = (0.01f * fConst0);
		fConst34 = (0.20000000000000001f * fConst0);
		fConst35 = (0.10000000000000001f * fConst0);
		fConst36 = (10.0f / fConst0);
		fConst37 = (5.0f / fConst0);
		fConst38 = (2.8571428571428572f / fConst0);
		fConst39 = (100.0f / fConst0);
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
		fConst53 = powf(0.5f,fConst36);
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
		for (int i=0; i<2; i++) iRec15[i] = 0;
		for (int i=0; i<2; i++) iRec17[i] = 0;
		for (int i=0; i<2; i++) iRec16[i] = 0;
		for (int i=0; i<2; i++) iRec13[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
		for (int i=0; i<3; i++) fRec23[i] = 0;
		for (int i=0; i<3; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec24[i] = 0;
		for (int i=0; i<3; i++) fRec26[i] = 0;
		for (int i=0; i<3; i++) fRec27[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) iRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<3; i++) fRec43[i] = 0;
		for (int i=0; i<3; i++) fRec45[i] = 0;
		for (int i=0; i<3; i++) fRec46[i] = 0;
		for (int i=0; i<3; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) iRec57[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) iRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<3; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<3; i++) fRec62[i] = 0;
		for (int i=0; i<3; i++) fRec64[i] = 0;
		for (int i=0; i<3; i++) fRec65[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) iRec76[i] = 0;
		for (int i=0; i<2; i++) iRec77[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) iRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<3; i++) fRec81[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<3; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) iRec95[i] = 0;
		for (int i=0; i<2; i++) iRec96[i] = 0;
		for (int i=0; i<2; i++) iRec93[i] = 0;
		for (int i=0; i<2; i++) iRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<3; i++) fRec100[i] = 0;
		for (int i=0; i<3; i++) fRec102[i] = 0;
		for (int i=0; i<3; i++) fRec103[i] = 0;
		for (int i=0; i<3; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) iRec114[i] = 0;
		for (int i=0; i<2; i++) iRec115[i] = 0;
		for (int i=0; i<2; i++) iRec112[i] = 0;
		for (int i=0; i<2; i++) iRec116[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<2; i++) fRec118[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<3; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
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
		int 	iSlow35 = (fSlow32 <= 0.0f);
		int 	iSlow36 = ((int((fSlow32 <= 0.050000000000000003f)))?4:2);
		int 	iSlow37 = ((int((fSlow32 >= 0.050000000000000003f)))?1:0);
		float 	fSlow38 = (1.2f * fSlow32);
		float 	fSlow39 = float(fslider6);
		float 	fSlow40 = max((8.1757989159999997f * fSlow8), (float)200);
		float 	fSlow41 = fastpow2((0.083333333333333329f * float(fslider7)));
		int 	iSlow42 = int(min((fConst13 / fSlow41), (float)4096));
		float 	fSlow43 = float(iSlow42);
		float 	fSlow44 = (fConst14 * (fSlow41 * fSlow43));
		float 	fSlow45 = float(fslider8);
		float 	fSlow46 = float(fslider9);
		float 	fSlow47 = (1500.0f * fSlow46);
		float 	fSlow48 = (0.40000000000000002f * fSlow46);
		int 	iSlow49 = (fSlow46 <= 0.0f);
		int 	iSlow50 = ((int((fSlow46 <= 0.050000000000000003f)))?4:2);
		int 	iSlow51 = ((int((fSlow46 >= 0.050000000000000003f)))?1:0);
		float 	fSlow52 = (1.2f * fSlow46);
		float 	fSlow53 = max((8.1757989159999997f * fSlow41), (float)200);
		float 	fSlow54 = fastpow2((0.083333333333333329f * float(fslider10)));
		int 	iSlow55 = int(min((fConst13 / fSlow54), (float)4096));
		float 	fSlow56 = float(iSlow55);
		float 	fSlow57 = (fConst14 * (fSlow54 * fSlow56));
		float 	fSlow58 = float(fslider11);
		float 	fSlow59 = float(fslider12);
		float 	fSlow60 = (1500.0f * fSlow59);
		float 	fSlow61 = (0.40000000000000002f * fSlow59);
		int 	iSlow62 = (fSlow59 <= 0.0f);
		int 	iSlow63 = ((int((fSlow59 <= 0.050000000000000003f)))?4:2);
		int 	iSlow64 = ((int((fSlow59 >= 0.050000000000000003f)))?1:0);
		float 	fSlow65 = (1.2f * fSlow59);
		float 	fSlow66 = max((8.1757989159999997f * fSlow54), (float)200);
		float 	fSlow67 = fastpow2((0.083333333333333329f * float(fslider13)));
		int 	iSlow68 = int(min((fConst13 / fSlow67), (float)4096));
		float 	fSlow69 = float(iSlow68);
		float 	fSlow70 = (fConst14 * (fSlow67 * fSlow69));
		float 	fSlow71 = float(fslider14);
		float 	fSlow72 = float(fslider15);
		float 	fSlow73 = (1500.0f * fSlow72);
		float 	fSlow74 = (0.40000000000000002f * fSlow72);
		int 	iSlow75 = (fSlow72 <= 0.0f);
		int 	iSlow76 = ((int((fSlow72 <= 0.050000000000000003f)))?4:2);
		int 	iSlow77 = ((int((fSlow72 >= 0.050000000000000003f)))?1:0);
		float 	fSlow78 = (1.2f * fSlow72);
		float 	fSlow79 = max((8.1757989159999997f * fSlow67), (float)200);
		float 	fSlow80 = fastpow2((0.083333333333333329f * float(fslider16)));
		int 	iSlow81 = int(min((fConst13 / fSlow80), (float)4096));
		float 	fSlow82 = float(iSlow81);
		float 	fSlow83 = (fConst14 * (fSlow80 * fSlow82));
		float 	fSlow84 = float(fslider17);
		float 	fSlow85 = float(fslider18);
		float 	fSlow86 = (1500.0f * fSlow85);
		float 	fSlow87 = (0.40000000000000002f * fSlow85);
		int 	iSlow88 = (fSlow85 <= 0.0f);
		int 	iSlow89 = ((int((fSlow85 <= 0.050000000000000003f)))?4:2);
		int 	iSlow90 = ((int((fSlow85 >= 0.050000000000000003f)))?1:0);
		float 	fSlow91 = (1.2f * fSlow85);
		float 	fSlow92 = max((8.1757989159999997f * fSlow80), (float)200);
		float 	fSlow93 = fastpow2((0.083333333333333329f * float(fslider19)));
		int 	iSlow94 = int(min((fConst13 / fSlow93), (float)4096));
		float 	fSlow95 = float(iSlow94);
		float 	fSlow96 = (fConst14 * (fSlow93 * fSlow95));
		float 	fSlow97 = float(fslider20);
		float 	fSlow98 = float(fslider21);
		float 	fSlow99 = (1500.0f * fSlow98);
		float 	fSlow100 = (0.40000000000000002f * fSlow98);
		int 	iSlow101 = (fSlow98 <= 0.0f);
		int 	iSlow102 = ((int((fSlow98 <= 0.050000000000000003f)))?4:2);
		int 	iSlow103 = ((int((fSlow98 >= 0.050000000000000003f)))?1:0);
		float 	fSlow104 = (1.2f * fSlow98);
		float 	fSlow105 = max((8.1757989159999997f * fSlow93), (float)200);
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
			iRec15[0] = iRec13[1];
			iRec17[0] = (iRec17[1] + 1);
			int 	iTemp12 = (iRec17[0] + -1);
			iRec16[0] = ((int((iRec15[1] != iRec13[1])))?iTemp12:iRec16[1]);
			float 	fTemp13 = float((iRec17[0] + (-1 - iRec16[0])));
			int 	iTemp14 = (fSlow32 > fRec14[1]);
			int 	iTemp15 = int(iTemp14);
			int 	iTemp16 = int((iRec13[1] == 1));
			int 	iTemp17 = int((iRec13[1] == 0));
			iRec13[0] = ((iTemp17)?iSlow37:((iTemp16)?((int((fTemp13 >= fConst35)))?2:1):((int((iRec13[1] == 2)))?((int(((fTemp13 >= fConst34) | iTemp14)))?3:iSlow36):((int((iRec13[1] == 3)))?((int((fSlow32 < fRec14[1])))?2:((iTemp15)?1:3)):((int((iRec13[1] == 4)))?((int((iSlow35 & (fRec14[1] <= 0.0f))))?0:((iTemp15)?5:4)):((int((fTemp13 >= fConst33)))?0:5))))));
			iRec18[0] = iRec13[1];
			int 	iTemp18 = int((iRec18[1] == iRec13[1]));
			fRec19[0] = ((iTemp17)?fSlow32:((iTemp18)?min(min(fRec19[1], fSlow32), fRec14[1]):min(fSlow32, fRec14[1])));
			fRec20[0] = ((iTemp17)?fSlow32:((iTemp16)?((iTemp18)?max(max(fRec20[1], fSlow38), fRec14[1]):max(fSlow38, fRec14[1])):((iTemp18)?max(max(fRec20[1], fSlow32), fRec14[1]):max(fSlow32, fRec14[1]))));
			fbargraph0 = fRec20[0];
			float 	fTemp19 = fbargraph0;
			fbargraph1 = fRec19[0];
			float 	fTemp20 = fbargraph1;
			float 	fTemp21 = (fTemp19 - fTemp20);
			fRec14[0] = ((int((iRec13[1] >= 3)))?((int((iRec13[1] >= 5)))?max((float)0, (fTemp19 * (1.0f - (fConst39 * fTemp13)))):((int((iRec13[1] >= 4)))?max((float)0, (fTemp19 * (1.0f - (fConst38 * fTemp13)))):fSlow32)):((int((iRec13[1] >= 2)))?max(fTemp20, (fTemp20 + (fTemp21 * (1.0f - (fConst37 * fTemp13))))):((int((iRec13[1] >= 1)))?min(fTemp19, (fTemp20 + (fConst36 * (fTemp21 * fTemp13)))):0.0f)));
			fRec12[0] = (((int((fRec14[0] < 0.5f)))?(2.0f * faustpower<2>(fRec14[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec14[0])))))) - (fConst30 * ((fConst28 * fRec12[2]) + (fConst26 * fRec12[1]))));
			float 	fTemp22 = (((3947.8417604357433f * fRec12[0]) + (7895.6835208714865f * fRec12[1])) + (3947.8417604357433f * fRec12[2]));
			fRec23[0] = (fSlow39 - (fConst50 * ((fConst48 * fRec23[2]) + (fConst43 * fRec23[1]))));
			fRec22[0] = ((fConst51 * (((15791.367041742973f * fRec23[0]) + (31582.734083485946f * fRec23[1])) + (15791.367041742973f * fRec23[2]))) - (fConst47 * ((fConst45 * fRec22[2]) + (fConst43 * fRec22[1]))));
			fRec21[0] = (fConst53 * max(fRec21[1], min((fConst52 * (((15791.367041742973f * fRec22[0]) + (31582.734083485946f * fRec22[1])) + (15791.367041742973f * fRec22[2]))), (float)2)));
			float 	fTemp23 = max((fRec21[0] + -1.0f), (float)0);
			float 	fTemp24 = tanf((fConst32 * min((fSlow40 * (faustpower<2>((fTemp23 + (fConst31 * (fTemp22 * (1.0f - fTemp11))))) + 1.0f)), (float)16000)));
			float 	fTemp25 = ((fTemp24 * (fTemp24 + (1.0f / ((8.0f * fTemp11) + 1.0f)))) + 1.0f);
			float 	fTemp26 = (fRec9[1] + (fTemp24 * (fTemp2 - fRec10[1])));
			float 	fTemp27 = (fTemp26 / fTemp25);
			fRec9[0] = ((2.0f * fTemp27) - fRec9[1]);
			float 	fTemp28 = (fRec10[1] + ((fTemp24 * fTemp26) / fTemp25));
			fRec10[0] = ((2.0f * fTemp28) - fRec10[1]);
			float 	fRec11 = fTemp28;
			fRec25[0] = (fSlow44 + (fRec25[1] - float((iSlow42 * ((fSlow44 + fRec25[1]) > fSlow43)))));
			int 	iTemp29 = int(fRec25[0]);
			float 	fTemp30 = ftbl0[iTemp29];
			float 	fTemp31 = (fTemp30 + ((fRec25[0] - float(iTemp29)) * (ftbl0[((iTemp29 + 1) % iSlow42)] - fTemp30)));
			fRec24[0] = (fTemp31 - (((fSlow7 * fRec24[2]) + (2.0f * (fSlow6 * fRec24[1]))) / fSlow5));
			fRec26[0] = (fTemp31 - (((fSlow20 * fRec26[2]) + (2.0f * (fSlow19 * fRec26[1]))) / fSlow18));
			fRec27[0] = (fTemp31 - (((fSlow29 * fRec27[2]) + (2.0f * (fSlow28 * fRec27[1]))) / fSlow27));
			fRec28[0] = (fSlow45 - (fConst30 * ((fConst28 * fRec28[2]) + (fConst26 * fRec28[1]))));
			float 	fTemp32 = ((fConst31 * (((3947.8417604357433f * fRec28[0]) + (7895.6835208714865f * fRec28[1])) + (3947.8417604357433f * fRec28[2]))) + 1.0f);
			float 	fTemp33 = (0.5f * fTemp32);
			float 	fTemp34 = max(fTemp33, (float)0);
			float 	fTemp35 = tanf((fConst32 * ((fSlow47 * (fTemp32 * fTemp34)) + 200.0f)));
			float 	fTemp36 = ((fTemp35 * (fTemp35 + 0.5f)) + 1.0f);
			float 	fTemp37 = (fRec29[1] + (fTemp35 * (fTemp31 - fRec30[1])));
			float 	fTemp38 = (fTemp37 / fTemp36);
			fRec29[0] = ((2.0f * fTemp38) - fRec29[1]);
			float 	fTemp39 = (fRec30[1] + ((fTemp35 * fTemp37) / fTemp36));
			fRec30[0] = ((2.0f * fTemp39) - fRec30[1]);
			float 	fRec31 = fTemp38;
			float 	fTemp40 = max((-1 * fTemp33), (float)0);
			iRec38[0] = iRec36[1];
			iRec39[0] = ((int((iRec38[1] != iRec36[1])))?iTemp12:iRec39[1]);
			float 	fTemp41 = float((iRec17[0] + (-1 - iRec39[0])));
			int 	iTemp42 = (fSlow46 > fRec37[1]);
			int 	iTemp43 = int(iTemp42);
			int 	iTemp44 = int((iRec36[1] == 1));
			int 	iTemp45 = int((iRec36[1] == 0));
			iRec36[0] = ((iTemp45)?iSlow51:((iTemp44)?((int((fTemp41 >= fConst35)))?2:1):((int((iRec36[1] == 2)))?((int(((fTemp41 >= fConst34) | iTemp42)))?3:iSlow50):((int((iRec36[1] == 3)))?((int((fSlow46 < fRec37[1])))?2:((iTemp43)?1:3)):((int((iRec36[1] == 4)))?((int((iSlow49 & (fRec37[1] <= 0.0f))))?0:((iTemp43)?5:4)):((int((fTemp41 >= fConst33)))?0:5))))));
			iRec40[0] = iRec36[1];
			int 	iTemp46 = int((iRec40[1] == iRec36[1]));
			fRec41[0] = ((iTemp45)?fSlow46:((iTemp46)?min(min(fRec41[1], fSlow46), fRec37[1]):min(fSlow46, fRec37[1])));
			fRec42[0] = ((iTemp45)?fSlow46:((iTemp44)?((iTemp46)?max(max(fRec42[1], fSlow52), fRec37[1]):max(fSlow52, fRec37[1])):((iTemp46)?max(max(fRec42[1], fSlow46), fRec37[1]):max(fSlow46, fRec37[1]))));
			fbargraph2 = fRec42[0];
			float 	fTemp47 = fbargraph2;
			fbargraph3 = fRec41[0];
			float 	fTemp48 = fbargraph3;
			float 	fTemp49 = (fTemp47 - fTemp48);
			fRec37[0] = ((int((iRec36[1] >= 3)))?((int((iRec36[1] >= 5)))?max((float)0, (fTemp47 * (1.0f - (fConst39 * fTemp41)))):((int((iRec36[1] >= 4)))?max((float)0, (fTemp47 * (1.0f - (fConst38 * fTemp41)))):fSlow46)):((int((iRec36[1] >= 2)))?max(fTemp48, (fTemp48 + (fTemp49 * (1.0f - (fConst37 * fTemp41))))):((int((iRec36[1] >= 1)))?min(fTemp47, (fTemp48 + (fConst36 * (fTemp49 * fTemp41)))):0.0f)));
			fRec35[0] = (((int((fRec37[0] < 0.5f)))?(2.0f * faustpower<2>(fRec37[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec37[0])))))) - (fConst30 * ((fConst28 * fRec35[2]) + (fConst26 * fRec35[1]))));
			float 	fTemp50 = (((3947.8417604357433f * fRec35[0]) + (7895.6835208714865f * fRec35[1])) + (3947.8417604357433f * fRec35[2]));
			float 	fTemp51 = tanf((fConst32 * min((fSlow53 * (faustpower<2>((fTemp23 + (fConst31 * (fTemp50 * (1.0f - fTemp40))))) + 1.0f)), (float)16000)));
			float 	fTemp52 = ((fTemp51 * (fTemp51 + (1.0f / ((8.0f * fTemp40) + 1.0f)))) + 1.0f);
			float 	fTemp53 = (fRec32[1] + (fTemp51 * (fTemp31 - fRec33[1])));
			float 	fTemp54 = (fTemp53 / fTemp52);
			fRec32[0] = ((2.0f * fTemp54) - fRec32[1]);
			float 	fTemp55 = (fRec33[1] + ((fTemp51 * fTemp53) / fTemp52));
			fRec33[0] = ((2.0f * fTemp55) - fRec33[1]);
			float 	fRec34 = fTemp55;
			fRec44[0] = (fSlow57 + (fRec44[1] - float((iSlow55 * ((fSlow57 + fRec44[1]) > fSlow56)))));
			int 	iTemp56 = int(fRec44[0]);
			float 	fTemp57 = ftbl0[iTemp56];
			float 	fTemp58 = (fTemp57 + ((fRec44[0] - float(iTemp56)) * (ftbl0[((iTemp56 + 1) % iSlow55)] - fTemp57)));
			fRec43[0] = (fTemp58 - (((fSlow7 * fRec43[2]) + (2.0f * (fSlow6 * fRec43[1]))) / fSlow5));
			fRec45[0] = (fTemp58 - (((fSlow20 * fRec45[2]) + (2.0f * (fSlow19 * fRec45[1]))) / fSlow18));
			fRec46[0] = (fTemp58 - (((fSlow29 * fRec46[2]) + (2.0f * (fSlow28 * fRec46[1]))) / fSlow27));
			fRec47[0] = (fSlow58 - (fConst30 * ((fConst28 * fRec47[2]) + (fConst26 * fRec47[1]))));
			float 	fTemp59 = ((fConst31 * (((3947.8417604357433f * fRec47[0]) + (7895.6835208714865f * fRec47[1])) + (3947.8417604357433f * fRec47[2]))) + 1.0f);
			float 	fTemp60 = (0.5f * fTemp59);
			float 	fTemp61 = max(fTemp60, (float)0);
			float 	fTemp62 = tanf((fConst32 * ((fSlow60 * (fTemp59 * fTemp61)) + 200.0f)));
			float 	fTemp63 = ((fTemp62 * (fTemp62 + 0.5f)) + 1.0f);
			float 	fTemp64 = (fRec48[1] + (fTemp62 * (fTemp58 - fRec49[1])));
			float 	fTemp65 = (fTemp64 / fTemp63);
			fRec48[0] = ((2.0f * fTemp65) - fRec48[1]);
			float 	fTemp66 = (fRec49[1] + ((fTemp62 * fTemp64) / fTemp63));
			fRec49[0] = ((2.0f * fTemp66) - fRec49[1]);
			float 	fRec50 = fTemp65;
			float 	fTemp67 = max((-1 * fTemp60), (float)0);
			iRec57[0] = iRec55[1];
			iRec58[0] = ((int((iRec57[1] != iRec55[1])))?iTemp12:iRec58[1]);
			float 	fTemp68 = float((iRec17[0] + (-1 - iRec58[0])));
			int 	iTemp69 = (fSlow59 > fRec56[1]);
			int 	iTemp70 = int(iTemp69);
			int 	iTemp71 = int((iRec55[1] == 1));
			int 	iTemp72 = int((iRec55[1] == 0));
			iRec55[0] = ((iTemp72)?iSlow64:((iTemp71)?((int((fTemp68 >= fConst35)))?2:1):((int((iRec55[1] == 2)))?((int(((fTemp68 >= fConst34) | iTemp69)))?3:iSlow63):((int((iRec55[1] == 3)))?((int((fSlow59 < fRec56[1])))?2:((iTemp70)?1:3)):((int((iRec55[1] == 4)))?((int((iSlow62 & (fRec56[1] <= 0.0f))))?0:((iTemp70)?5:4)):((int((fTemp68 >= fConst33)))?0:5))))));
			iRec59[0] = iRec55[1];
			int 	iTemp73 = int((iRec59[1] == iRec55[1]));
			fRec60[0] = ((iTemp72)?fSlow59:((iTemp73)?min(min(fRec60[1], fSlow59), fRec56[1]):min(fSlow59, fRec56[1])));
			fRec61[0] = ((iTemp72)?fSlow59:((iTemp71)?((iTemp73)?max(max(fRec61[1], fSlow65), fRec56[1]):max(fSlow65, fRec56[1])):((iTemp73)?max(max(fRec61[1], fSlow59), fRec56[1]):max(fSlow59, fRec56[1]))));
			fbargraph4 = fRec61[0];
			float 	fTemp74 = fbargraph4;
			fbargraph5 = fRec60[0];
			float 	fTemp75 = fbargraph5;
			float 	fTemp76 = (fTemp74 - fTemp75);
			fRec56[0] = ((int((iRec55[1] >= 3)))?((int((iRec55[1] >= 5)))?max((float)0, (fTemp74 * (1.0f - (fConst39 * fTemp68)))):((int((iRec55[1] >= 4)))?max((float)0, (fTemp74 * (1.0f - (fConst38 * fTemp68)))):fSlow59)):((int((iRec55[1] >= 2)))?max(fTemp75, (fTemp75 + (fTemp76 * (1.0f - (fConst37 * fTemp68))))):((int((iRec55[1] >= 1)))?min(fTemp74, (fTemp75 + (fConst36 * (fTemp76 * fTemp68)))):0.0f)));
			fRec54[0] = (((int((fRec56[0] < 0.5f)))?(2.0f * faustpower<2>(fRec56[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec56[0])))))) - (fConst30 * ((fConst28 * fRec54[2]) + (fConst26 * fRec54[1]))));
			float 	fTemp77 = (((3947.8417604357433f * fRec54[0]) + (7895.6835208714865f * fRec54[1])) + (3947.8417604357433f * fRec54[2]));
			float 	fTemp78 = tanf((fConst32 * min((fSlow66 * (faustpower<2>((fTemp23 + (fConst31 * (fTemp77 * (1.0f - fTemp67))))) + 1.0f)), (float)16000)));
			float 	fTemp79 = ((fTemp78 * (fTemp78 + (1.0f / ((8.0f * fTemp67) + 1.0f)))) + 1.0f);
			float 	fTemp80 = (fRec51[1] + (fTemp78 * (fTemp58 - fRec52[1])));
			float 	fTemp81 = (fTemp80 / fTemp79);
			fRec51[0] = ((2.0f * fTemp81) - fRec51[1]);
			float 	fTemp82 = (fRec52[1] + ((fTemp78 * fTemp80) / fTemp79));
			fRec52[0] = ((2.0f * fTemp82) - fRec52[1]);
			float 	fRec53 = fTemp82;
			fRec63[0] = (fSlow70 + (fRec63[1] - float((iSlow68 * ((fSlow70 + fRec63[1]) > fSlow69)))));
			int 	iTemp83 = int(fRec63[0]);
			float 	fTemp84 = ftbl0[iTemp83];
			float 	fTemp85 = (fTemp84 + ((fRec63[0] - float(iTemp83)) * (ftbl0[((iTemp83 + 1) % iSlow68)] - fTemp84)));
			fRec62[0] = (fTemp85 - (((fSlow7 * fRec62[2]) + (2.0f * (fSlow6 * fRec62[1]))) / fSlow5));
			fRec64[0] = (fTemp85 - (((fSlow20 * fRec64[2]) + (2.0f * (fSlow19 * fRec64[1]))) / fSlow18));
			fRec65[0] = (fTemp85 - (((fSlow29 * fRec65[2]) + (2.0f * (fSlow28 * fRec65[1]))) / fSlow27));
			fRec66[0] = (fSlow71 - (fConst30 * ((fConst28 * fRec66[2]) + (fConst26 * fRec66[1]))));
			float 	fTemp86 = ((fConst31 * (((3947.8417604357433f * fRec66[0]) + (7895.6835208714865f * fRec66[1])) + (3947.8417604357433f * fRec66[2]))) + 1.0f);
			float 	fTemp87 = (0.5f * fTemp86);
			float 	fTemp88 = max(fTemp87, (float)0);
			float 	fTemp89 = tanf((fConst32 * ((fSlow73 * (fTemp86 * fTemp88)) + 200.0f)));
			float 	fTemp90 = ((fTemp89 * (fTemp89 + 0.5f)) + 1.0f);
			float 	fTemp91 = (fRec67[1] + (fTemp89 * (fTemp85 - fRec68[1])));
			float 	fTemp92 = (fTemp91 / fTemp90);
			fRec67[0] = ((2.0f * fTemp92) - fRec67[1]);
			float 	fTemp93 = (fRec68[1] + ((fTemp89 * fTemp91) / fTemp90));
			fRec68[0] = ((2.0f * fTemp93) - fRec68[1]);
			float 	fRec69 = fTemp92;
			float 	fTemp94 = max((-1 * fTemp87), (float)0);
			iRec76[0] = iRec74[1];
			iRec77[0] = ((int((iRec76[1] != iRec74[1])))?iTemp12:iRec77[1]);
			float 	fTemp95 = float((iRec17[0] + (-1 - iRec77[0])));
			int 	iTemp96 = (fSlow72 > fRec75[1]);
			int 	iTemp97 = int(iTemp96);
			int 	iTemp98 = int((iRec74[1] == 1));
			int 	iTemp99 = int((iRec74[1] == 0));
			iRec74[0] = ((iTemp99)?iSlow77:((iTemp98)?((int((fTemp95 >= fConst35)))?2:1):((int((iRec74[1] == 2)))?((int(((fTemp95 >= fConst34) | iTemp96)))?3:iSlow76):((int((iRec74[1] == 3)))?((int((fSlow72 < fRec75[1])))?2:((iTemp97)?1:3)):((int((iRec74[1] == 4)))?((int((iSlow75 & (fRec75[1] <= 0.0f))))?0:((iTemp97)?5:4)):((int((fTemp95 >= fConst33)))?0:5))))));
			iRec78[0] = iRec74[1];
			int 	iTemp100 = int((iRec78[1] == iRec74[1]));
			fRec79[0] = ((iTemp99)?fSlow72:((iTemp100)?min(min(fRec79[1], fSlow72), fRec75[1]):min(fSlow72, fRec75[1])));
			fRec80[0] = ((iTemp99)?fSlow72:((iTemp98)?((iTemp100)?max(max(fRec80[1], fSlow78), fRec75[1]):max(fSlow78, fRec75[1])):((iTemp100)?max(max(fRec80[1], fSlow72), fRec75[1]):max(fSlow72, fRec75[1]))));
			fbargraph6 = fRec80[0];
			float 	fTemp101 = fbargraph6;
			fbargraph7 = fRec79[0];
			float 	fTemp102 = fbargraph7;
			float 	fTemp103 = (fTemp101 - fTemp102);
			fRec75[0] = ((int((iRec74[1] >= 3)))?((int((iRec74[1] >= 5)))?max((float)0, (fTemp101 * (1.0f - (fConst39 * fTemp95)))):((int((iRec74[1] >= 4)))?max((float)0, (fTemp101 * (1.0f - (fConst38 * fTemp95)))):fSlow72)):((int((iRec74[1] >= 2)))?max(fTemp102, (fTemp102 + (fTemp103 * (1.0f - (fConst37 * fTemp95))))):((int((iRec74[1] >= 1)))?min(fTemp101, (fTemp102 + (fConst36 * (fTemp103 * fTemp95)))):0.0f)));
			fRec73[0] = (((int((fRec75[0] < 0.5f)))?(2.0f * faustpower<2>(fRec75[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec75[0])))))) - (fConst30 * ((fConst28 * fRec73[2]) + (fConst26 * fRec73[1]))));
			float 	fTemp104 = (((3947.8417604357433f * fRec73[0]) + (7895.6835208714865f * fRec73[1])) + (3947.8417604357433f * fRec73[2]));
			float 	fTemp105 = tanf((fConst32 * min((fSlow79 * (faustpower<2>((fTemp23 + (fConst31 * (fTemp104 * (1.0f - fTemp94))))) + 1.0f)), (float)16000)));
			float 	fTemp106 = ((fTemp105 * (fTemp105 + (1.0f / ((8.0f * fTemp94) + 1.0f)))) + 1.0f);
			float 	fTemp107 = (fRec70[1] + (fTemp105 * (fTemp85 - fRec71[1])));
			float 	fTemp108 = (fTemp107 / fTemp106);
			fRec70[0] = ((2.0f * fTemp108) - fRec70[1]);
			float 	fTemp109 = (fRec71[1] + ((fTemp105 * fTemp107) / fTemp106));
			fRec71[0] = ((2.0f * fTemp109) - fRec71[1]);
			float 	fRec72 = fTemp109;
			fRec82[0] = (fSlow83 + (fRec82[1] - float((iSlow81 * ((fSlow83 + fRec82[1]) > fSlow82)))));
			int 	iTemp110 = int(fRec82[0]);
			float 	fTemp111 = ftbl0[iTemp110];
			float 	fTemp112 = (fTemp111 + ((fRec82[0] - float(iTemp110)) * (ftbl0[((iTemp110 + 1) % iSlow81)] - fTemp111)));
			fRec81[0] = (fTemp112 - (((fSlow7 * fRec81[2]) + (2.0f * (fSlow6 * fRec81[1]))) / fSlow5));
			fRec83[0] = (fTemp112 - (((fSlow20 * fRec83[2]) + (2.0f * (fSlow19 * fRec83[1]))) / fSlow18));
			fRec84[0] = (fTemp112 - (((fSlow29 * fRec84[2]) + (2.0f * (fSlow28 * fRec84[1]))) / fSlow27));
			fRec85[0] = (fSlow84 - (fConst30 * ((fConst28 * fRec85[2]) + (fConst26 * fRec85[1]))));
			float 	fTemp113 = ((fConst31 * (((3947.8417604357433f * fRec85[0]) + (7895.6835208714865f * fRec85[1])) + (3947.8417604357433f * fRec85[2]))) + 1.0f);
			float 	fTemp114 = (0.5f * fTemp113);
			float 	fTemp115 = max(fTemp114, (float)0);
			float 	fTemp116 = tanf((fConst32 * ((fSlow86 * (fTemp113 * fTemp115)) + 200.0f)));
			float 	fTemp117 = ((fTemp116 * (fTemp116 + 0.5f)) + 1.0f);
			float 	fTemp118 = (fRec86[1] + (fTemp116 * (fTemp112 - fRec87[1])));
			float 	fTemp119 = (fTemp118 / fTemp117);
			fRec86[0] = ((2.0f * fTemp119) - fRec86[1]);
			float 	fTemp120 = (fRec87[1] + ((fTemp116 * fTemp118) / fTemp117));
			fRec87[0] = ((2.0f * fTemp120) - fRec87[1]);
			float 	fRec88 = fTemp119;
			float 	fTemp121 = max((-1 * fTemp114), (float)0);
			iRec95[0] = iRec93[1];
			iRec96[0] = ((int((iRec95[1] != iRec93[1])))?iTemp12:iRec96[1]);
			float 	fTemp122 = float((iRec17[0] + (-1 - iRec96[0])));
			int 	iTemp123 = (fSlow85 > fRec94[1]);
			int 	iTemp124 = int(iTemp123);
			int 	iTemp125 = int((iRec93[1] == 1));
			int 	iTemp126 = int((iRec93[1] == 0));
			iRec93[0] = ((iTemp126)?iSlow90:((iTemp125)?((int((fTemp122 >= fConst35)))?2:1):((int((iRec93[1] == 2)))?((int(((fTemp122 >= fConst34) | iTemp123)))?3:iSlow89):((int((iRec93[1] == 3)))?((int((fSlow85 < fRec94[1])))?2:((iTemp124)?1:3)):((int((iRec93[1] == 4)))?((int((iSlow88 & (fRec94[1] <= 0.0f))))?0:((iTemp124)?5:4)):((int((fTemp122 >= fConst33)))?0:5))))));
			iRec97[0] = iRec93[1];
			int 	iTemp127 = int((iRec97[1] == iRec93[1]));
			fRec98[0] = ((iTemp126)?fSlow85:((iTemp127)?min(min(fRec98[1], fSlow85), fRec94[1]):min(fSlow85, fRec94[1])));
			fRec99[0] = ((iTemp126)?fSlow85:((iTemp125)?((iTemp127)?max(max(fRec99[1], fSlow91), fRec94[1]):max(fSlow91, fRec94[1])):((iTemp127)?max(max(fRec99[1], fSlow85), fRec94[1]):max(fSlow85, fRec94[1]))));
			fbargraph8 = fRec99[0];
			float 	fTemp128 = fbargraph8;
			fbargraph9 = fRec98[0];
			float 	fTemp129 = fbargraph9;
			float 	fTemp130 = (fTemp128 - fTemp129);
			fRec94[0] = ((int((iRec93[1] >= 3)))?((int((iRec93[1] >= 5)))?max((float)0, (fTemp128 * (1.0f - (fConst39 * fTemp122)))):((int((iRec93[1] >= 4)))?max((float)0, (fTemp128 * (1.0f - (fConst38 * fTemp122)))):fSlow85)):((int((iRec93[1] >= 2)))?max(fTemp129, (fTemp129 + (fTemp130 * (1.0f - (fConst37 * fTemp122))))):((int((iRec93[1] >= 1)))?min(fTemp128, (fTemp129 + (fConst36 * (fTemp130 * fTemp122)))):0.0f)));
			fRec92[0] = (((int((fRec94[0] < 0.5f)))?(2.0f * faustpower<2>(fRec94[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec94[0])))))) - (fConst30 * ((fConst28 * fRec92[2]) + (fConst26 * fRec92[1]))));
			float 	fTemp131 = (((3947.8417604357433f * fRec92[0]) + (7895.6835208714865f * fRec92[1])) + (3947.8417604357433f * fRec92[2]));
			float 	fTemp132 = tanf((fConst32 * min((fSlow92 * (faustpower<2>((fTemp23 + (fConst31 * (fTemp131 * (1.0f - fTemp121))))) + 1.0f)), (float)16000)));
			float 	fTemp133 = ((fTemp132 * (fTemp132 + (1.0f / ((8.0f * fTemp121) + 1.0f)))) + 1.0f);
			float 	fTemp134 = (fRec89[1] + (fTemp132 * (fTemp112 - fRec90[1])));
			float 	fTemp135 = (fTemp134 / fTemp133);
			fRec89[0] = ((2.0f * fTemp135) - fRec89[1]);
			float 	fTemp136 = (fRec90[1] + ((fTemp132 * fTemp134) / fTemp133));
			fRec90[0] = ((2.0f * fTemp136) - fRec90[1]);
			float 	fRec91 = fTemp136;
			fRec101[0] = (fSlow96 + (fRec101[1] - float((iSlow94 * ((fSlow96 + fRec101[1]) > fSlow95)))));
			int 	iTemp137 = int(fRec101[0]);
			float 	fTemp138 = ftbl0[iTemp137];
			float 	fTemp139 = (fTemp138 + ((fRec101[0] - float(iTemp137)) * (ftbl0[((iTemp137 + 1) % iSlow94)] - fTemp138)));
			fRec100[0] = (fTemp139 - (((fSlow7 * fRec100[2]) + (2.0f * (fSlow6 * fRec100[1]))) / fSlow5));
			fRec102[0] = (fTemp139 - (((fSlow20 * fRec102[2]) + (2.0f * (fSlow19 * fRec102[1]))) / fSlow18));
			fRec103[0] = (fTemp139 - (((fSlow29 * fRec103[2]) + (2.0f * (fSlow28 * fRec103[1]))) / fSlow27));
			fRec104[0] = (fSlow97 - (fConst30 * ((fConst28 * fRec104[2]) + (fConst26 * fRec104[1]))));
			float 	fTemp140 = ((fConst31 * (((3947.8417604357433f * fRec104[0]) + (7895.6835208714865f * fRec104[1])) + (3947.8417604357433f * fRec104[2]))) + 1.0f);
			float 	fTemp141 = (0.5f * fTemp140);
			float 	fTemp142 = max(fTemp141, (float)0);
			float 	fTemp143 = tanf((fConst32 * ((fSlow99 * (fTemp140 * fTemp142)) + 200.0f)));
			float 	fTemp144 = ((fTemp143 * (fTemp143 + 0.5f)) + 1.0f);
			float 	fTemp145 = (fRec105[1] + (fTemp143 * (fTemp139 - fRec106[1])));
			float 	fTemp146 = (fTemp145 / fTemp144);
			fRec105[0] = ((2.0f * fTemp146) - fRec105[1]);
			float 	fTemp147 = (fRec106[1] + ((fTemp143 * fTemp145) / fTemp144));
			fRec106[0] = ((2.0f * fTemp147) - fRec106[1]);
			float 	fRec107 = fTemp146;
			float 	fTemp148 = max((-1 * fTemp141), (float)0);
			iRec114[0] = iRec112[1];
			iRec115[0] = ((int((iRec114[1] != iRec112[1])))?iTemp12:iRec115[1]);
			float 	fTemp149 = float((iRec17[0] + (-1 - iRec115[0])));
			int 	iTemp150 = (fSlow98 > fRec113[1]);
			int 	iTemp151 = int(iTemp150);
			int 	iTemp152 = int((iRec112[1] == 1));
			int 	iTemp153 = int((iRec112[1] == 0));
			iRec112[0] = ((iTemp153)?iSlow103:((iTemp152)?((int((fTemp149 >= fConst35)))?2:1):((int((iRec112[1] == 2)))?((int(((fTemp149 >= fConst34) | iTemp150)))?3:iSlow102):((int((iRec112[1] == 3)))?((int((fSlow98 < fRec113[1])))?2:((iTemp151)?1:3)):((int((iRec112[1] == 4)))?((int((iSlow101 & (fRec113[1] <= 0.0f))))?0:((iTemp151)?5:4)):((int((fTemp149 >= fConst33)))?0:5))))));
			iRec116[0] = iRec112[1];
			int 	iTemp154 = int((iRec116[1] == iRec112[1]));
			fRec117[0] = ((iTemp153)?fSlow98:((iTemp154)?min(min(fRec117[1], fSlow98), fRec113[1]):min(fSlow98, fRec113[1])));
			fRec118[0] = ((iTemp153)?fSlow98:((iTemp152)?((iTemp154)?max(max(fRec118[1], fSlow104), fRec113[1]):max(fSlow104, fRec113[1])):((iTemp154)?max(max(fRec118[1], fSlow98), fRec113[1]):max(fSlow98, fRec113[1]))));
			fbargraph10 = fRec118[0];
			float 	fTemp155 = fbargraph10;
			fbargraph11 = fRec117[0];
			float 	fTemp156 = fbargraph11;
			float 	fTemp157 = (fTemp155 - fTemp156);
			fRec113[0] = ((int((iRec112[1] >= 3)))?((int((iRec112[1] >= 5)))?max((float)0, (fTemp155 * (1.0f - (fConst39 * fTemp149)))):((int((iRec112[1] >= 4)))?max((float)0, (fTemp155 * (1.0f - (fConst38 * fTemp149)))):fSlow98)):((int((iRec112[1] >= 2)))?max(fTemp156, (fTemp156 + (fTemp157 * (1.0f - (fConst37 * fTemp149))))):((int((iRec112[1] >= 1)))?min(fTemp155, (fTemp156 + (fConst36 * (fTemp157 * fTemp149)))):0.0f)));
			fRec111[0] = (((int((fRec113[0] < 0.5f)))?(2.0f * faustpower<2>(fRec113[0])):(1.0f - (0.5f * faustpower<2>((2.0f * (1.0f - fRec113[0])))))) - (fConst30 * ((fConst28 * fRec111[2]) + (fConst26 * fRec111[1]))));
			float 	fTemp158 = (((3947.8417604357433f * fRec111[0]) + (7895.6835208714865f * fRec111[1])) + (3947.8417604357433f * fRec111[2]));
			float 	fTemp159 = tanf((fConst32 * min((fSlow105 * (faustpower<2>(((fConst31 * (fTemp158 * (1.0f - fTemp148))) + fTemp23)) + 1.0f)), (float)16000)));
			float 	fTemp160 = ((fTemp159 * (fTemp159 + (1.0f / ((8.0f * fTemp148) + 1.0f)))) + 1.0f);
			float 	fTemp161 = (fRec108[1] + (fTemp159 * (fTemp139 - fRec109[1])));
			float 	fTemp162 = (fTemp161 / fTemp160);
			fRec108[0] = ((2.0f * fTemp162) - fRec108[1]);
			float 	fTemp163 = (fRec109[1] + ((fTemp159 * fTemp161) / fTemp160));
			fRec109[0] = ((2.0f * fTemp163) - fRec109[1]);
			float 	fRec110 = fTemp163;
			fRec0[0] = ((fConst54 * ((((((fTemp158 * (((fRec110 * faustpower<2>((1.0f - (0.5f * fTemp148)))) + (fSlow100 * ((fRec107 * fTemp140) * fTemp142))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec103[0] - fRec103[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec102[0] - fRec102[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec100[0] - fRec100[2])) / fSlow5)))))))) + (fTemp131 * (((fRec91 * faustpower<2>((1.0f - (0.5f * fTemp121)))) + (fSlow87 * ((fRec88 * fTemp113) * fTemp115))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec84[0] - fRec84[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec83[0] - fRec83[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec81[0] - fRec81[2])) / fSlow5))))))))) + (fTemp104 * (((fRec72 * faustpower<2>((1.0f - (0.5f * fTemp94)))) + (fSlow74 * ((fRec69 * fTemp86) * fTemp88))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec65[0] - fRec65[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec64[0] - fRec64[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec62[0] - fRec62[2])) / fSlow5))))))))) + (fTemp77 * (((fRec53 * faustpower<2>((1.0f - (0.5f * fTemp67)))) + (fSlow61 * ((fRec50 * fTemp59) * fTemp61))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec46[0] - fRec46[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec45[0] - fRec45[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec43[0] - fRec43[2])) / fSlow5))))))))) + (fTemp50 * (((fRec34 * faustpower<2>((1.0f - (0.5f * fTemp40)))) + (fSlow48 * ((fRec31 * fTemp32) * fTemp34))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec27[0] - fRec27[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec26[0] - fRec26[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec24[0] - fRec24[2])) / fSlow5))))))))) + (fTemp22 * (((fRec11 * faustpower<2>((1.0f - (0.5f * fTemp11)))) + (fSlow34 * ((fRec8 * fTemp3) * fTemp5))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec4[0] - fRec4[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec3[0] - fRec3[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec1[0] - fRec1[2])) / fSlow5)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)((fConst55 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2])));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec109[1] = fRec109[0];
			fRec108[1] = fRec108[0];
			fRec111[2] = fRec111[1]; fRec111[1] = fRec111[0];
			fRec113[1] = fRec113[0];
			fRec118[1] = fRec118[0];
			fRec117[1] = fRec117[0];
			iRec116[1] = iRec116[0];
			iRec112[1] = iRec112[0];
			iRec115[1] = iRec115[0];
			iRec114[1] = iRec114[0];
			fRec106[1] = fRec106[0];
			fRec105[1] = fRec105[0];
			fRec104[2] = fRec104[1]; fRec104[1] = fRec104[0];
			fRec103[2] = fRec103[1]; fRec103[1] = fRec103[0];
			fRec102[2] = fRec102[1]; fRec102[1] = fRec102[0];
			fRec100[2] = fRec100[1]; fRec100[1] = fRec100[0];
			fRec101[1] = fRec101[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec92[2] = fRec92[1]; fRec92[1] = fRec92[0];
			fRec94[1] = fRec94[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			iRec97[1] = iRec97[0];
			iRec93[1] = iRec93[0];
			iRec96[1] = iRec96[0];
			iRec95[1] = iRec95[0];
			fRec87[1] = fRec87[0];
			fRec86[1] = fRec86[0];
			fRec85[2] = fRec85[1]; fRec85[1] = fRec85[0];
			fRec84[2] = fRec84[1]; fRec84[1] = fRec84[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec81[2] = fRec81[1]; fRec81[1] = fRec81[0];
			fRec82[1] = fRec82[0];
			fRec71[1] = fRec71[0];
			fRec70[1] = fRec70[0];
			fRec73[2] = fRec73[1]; fRec73[1] = fRec73[0];
			fRec75[1] = fRec75[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			iRec78[1] = iRec78[0];
			iRec74[1] = iRec74[0];
			iRec77[1] = iRec77[0];
			iRec76[1] = iRec76[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec65[2] = fRec65[1]; fRec65[1] = fRec65[0];
			fRec64[2] = fRec64[1]; fRec64[1] = fRec64[0];
			fRec62[2] = fRec62[1]; fRec62[1] = fRec62[0];
			fRec63[1] = fRec63[0];
			fRec52[1] = fRec52[0];
			fRec51[1] = fRec51[0];
			fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
			fRec56[1] = fRec56[0];
			fRec61[1] = fRec61[0];
			fRec60[1] = fRec60[0];
			iRec59[1] = iRec59[0];
			iRec55[1] = iRec55[0];
			iRec58[1] = iRec58[0];
			iRec57[1] = iRec57[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[2] = fRec47[1]; fRec47[1] = fRec47[0];
			fRec46[2] = fRec46[1]; fRec46[1] = fRec46[0];
			fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
			fRec43[2] = fRec43[1]; fRec43[1] = fRec43[0];
			fRec44[1] = fRec44[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec42[1] = fRec42[0];
			fRec41[1] = fRec41[0];
			iRec40[1] = iRec40[0];
			iRec36[1] = iRec36[0];
			iRec39[1] = iRec39[0];
			iRec38[1] = iRec38[0];
			fRec30[1] = fRec30[0];
			fRec29[1] = fRec29[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec27[2] = fRec27[1]; fRec27[1] = fRec27[0];
			fRec26[2] = fRec26[1]; fRec26[1] = fRec26[0];
			fRec24[2] = fRec24[1]; fRec24[1] = fRec24[0];
			fRec25[1] = fRec25[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec21[1] = fRec21[0];
			fRec22[2] = fRec22[1]; fRec22[1] = fRec22[0];
			fRec23[2] = fRec23[1]; fRec23[1] = fRec23[0];
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec14[1] = fRec14[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			iRec18[1] = iRec18[0];
			iRec13[1] = iRec13[0];
			iRec16[1] = iRec16[0];
			iRec17[1] = iRec17[0];
			iRec15[1] = iRec15[0];
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
