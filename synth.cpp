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
				output[i] = (9.313226e-10f * float(rand_hoaglin()));
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec24[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec24[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec24[0] = (iRec24[1] + 1);
				int 	iTemp38 = (iRec24[0] + -1);
				output[i] = expf((0.0f - (25.0f * (float(int(float((iTemp38 % 3)))) * float(int((0.33333334f * float((iTemp38 % 9)))))))));
				// post processing
				iRec24[1] = iRec24[0];
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
	float 	fRec17[2];
	float 	fRec18[2];
	float 	fRec19[2];
	FAUSTFLOAT 	fbargraph0;
	float 	fRec20[2];
	int 	iRec22[2];
	int 	iRec21[2];
	FAUSTFLOAT 	fbargraph1;
	float 	fRec13[2];
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	FAUSTFLOAT 	fbargraph2;
	float 	fRec23[2];
	static float 	ftbl1[9];
	float 	fConst38;
	FAUSTFLOAT 	fbargraph3;
	float 	fRec14[2];
	float 	fRec12[3];
	float 	fConst42;
	float 	fConst44;
	float 	fConst46;
	float 	fConst47;
	float 	fConst49;
	FAUSTFLOAT 	fslider6;
	float 	fRec27[3];
	float 	fConst50;
	float 	fRec26[3];
	float 	fConst51;
	float 	fConst52;
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
	float 	fRec44[2];
	float 	fRec45[2];
	float 	fRec46[2];
	FAUSTFLOAT 	fbargraph4;
	float 	fRec47[2];
	int 	iRec48[2];
	FAUSTFLOAT 	fbargraph5;
	float 	fRec40[2];
	FAUSTFLOAT 	fbargraph6;
	float 	fRec49[2];
	FAUSTFLOAT 	fbargraph7;
	float 	fRec41[2];
	float 	fRec39[3];
	float 	fRec36[2];
	float 	fRec37[2];
	FAUSTFLOAT 	fslider10;
	float 	fRec51[2];
	float 	fRec50[3];
	float 	fRec52[3];
	float 	fRec53[3];
	FAUSTFLOAT 	fslider11;
	float 	fRec54[3];
	FAUSTFLOAT 	fslider12;
	float 	fRec55[2];
	float 	fRec56[2];
	float 	fRec65[2];
	float 	fRec64[2];
	float 	fRec66[2];
	float 	fRec67[2];
	float 	fRec68[2];
	FAUSTFLOAT 	fbargraph8;
	float 	fRec69[2];
	int 	iRec70[2];
	FAUSTFLOAT 	fbargraph9;
	float 	fRec62[2];
	FAUSTFLOAT 	fbargraph10;
	float 	fRec71[2];
	FAUSTFLOAT 	fbargraph11;
	float 	fRec63[2];
	float 	fRec61[3];
	float 	fRec58[2];
	float 	fRec59[2];
	FAUSTFLOAT 	fslider13;
	float 	fRec73[2];
	float 	fRec72[3];
	float 	fRec74[3];
	float 	fRec75[3];
	FAUSTFLOAT 	fslider14;
	float 	fRec76[3];
	FAUSTFLOAT 	fslider15;
	float 	fRec77[2];
	float 	fRec78[2];
	float 	fRec87[2];
	float 	fRec86[2];
	float 	fRec88[2];
	float 	fRec89[2];
	float 	fRec90[2];
	FAUSTFLOAT 	fbargraph12;
	float 	fRec91[2];
	int 	iRec92[2];
	FAUSTFLOAT 	fbargraph13;
	float 	fRec84[2];
	FAUSTFLOAT 	fbargraph14;
	float 	fRec93[2];
	FAUSTFLOAT 	fbargraph15;
	float 	fRec85[2];
	float 	fRec83[3];
	float 	fRec80[2];
	float 	fRec81[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec95[2];
	float 	fRec94[3];
	float 	fRec96[3];
	float 	fRec97[3];
	FAUSTFLOAT 	fslider17;
	float 	fRec98[3];
	FAUSTFLOAT 	fslider18;
	float 	fRec99[2];
	float 	fRec100[2];
	float 	fRec109[2];
	float 	fRec108[2];
	float 	fRec110[2];
	float 	fRec111[2];
	float 	fRec112[2];
	FAUSTFLOAT 	fbargraph16;
	float 	fRec113[2];
	int 	iRec114[2];
	FAUSTFLOAT 	fbargraph17;
	float 	fRec106[2];
	FAUSTFLOAT 	fbargraph18;
	float 	fRec115[2];
	FAUSTFLOAT 	fbargraph19;
	float 	fRec107[2];
	float 	fRec105[3];
	float 	fRec102[2];
	float 	fRec103[2];
	FAUSTFLOAT 	fslider19;
	float 	fRec117[2];
	float 	fRec116[3];
	float 	fRec118[3];
	float 	fRec119[3];
	FAUSTFLOAT 	fslider20;
	float 	fRec120[3];
	FAUSTFLOAT 	fslider21;
	float 	fRec121[2];
	float 	fRec122[2];
	float 	fRec131[2];
	float 	fRec130[2];
	float 	fRec132[2];
	float 	fRec133[2];
	float 	fRec134[2];
	FAUSTFLOAT 	fbargraph20;
	float 	fRec135[2];
	int 	iRec136[2];
	FAUSTFLOAT 	fbargraph21;
	float 	fRec128[2];
	FAUSTFLOAT 	fbargraph22;
	float 	fRec137[2];
	FAUSTFLOAT 	fbargraph23;
	float 	fRec129[2];
	float 	fRec127[3];
	float 	fRec124[2];
	float 	fRec125[2];
	float 	fConst53;
	float 	fRec0[3];
	float 	fConst54;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/tabulateNd:author", "Bart Brouns");
		m->declare("basics.lib/tabulateNd:license", "AGPL-3.0");
		m->declare("basics.lib/version", "1.10.0");
		m->declare("fast.lib/author", "Piers Titus van der Torren (pierstitus@toverlamp.org)");
		m->declare("fast.lib/licence", "Apache-2.0");
		m->declare("fast.lib/name", "Faust Fast Approximations Library");
		m->declare("filename", "synth.dsp.tmp");
		m->declare("filters.lib/lowpass0_highpass1", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
		m->declare("filters.lib/name", "Faust Filters Library");
		m->declare("filters.lib/svf:author", "Oleg Nesterov");
		m->declare("filters.lib/svf:copyright", "Copyright (C) 2020 Oleg Nesterov <oleg@redhat.com>");
		m->declare("filters.lib/svf:license", "MIT-style STK-4.3 license");
		m->declare("filters.lib/version", "1.3.0");
		m->declare("interpolators.lib/interpolate_linear:author", "Stéphane Letz");
		m->declare("interpolators.lib/interpolate_linear:licence", "MIT");
		m->declare("interpolators.lib/name", "Faust Interpolator Library");
		m->declare("interpolators.lib/version", "1.3.0");
		m->declare("maths.lib/author", "GRAME");
		m->declare("maths.lib/copyright", "GRAME");
		m->declare("maths.lib/license", "LGPL with exception");
		m->declare("maths.lib/name", "Faust Math Library");
		m->declare("maths.lib/version", "2.6.0");
		m->declare("name", "synth.dsp.tmp");
		m->declare("platform.lib/name", "Generic Platform Library");
		m->declare("platform.lib/version", "1.3.0");
		m->declare("routes.lib/name", "Faust Signal Routing Library");
		m->declare("routes.lib/version", "1.2.0");
		m->declare("signals.lib/name", "Faust Signal Routing Library");
		m->declare("signals.lib/version", "1.3.0");
	}

	virtual int getNumInputs() { return 0; }
	virtual int getNumOutputs() { return 1; }
	static void classInit(int sample_rate) {
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(4096,ftbl0);
		SIG1 sig1;
		sig1.init(sample_rate);
		sig1.fill(9,ftbl1);
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
		float 	fConst9 = powf((4084.0706f / fConst0),2.0f);
		fConst10 = (4084.0706f * (((fConst9 * ((0.2033f * fConst9) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst11 = powf((8168.141f / fConst0),2.0f);
		fConst12 = (8168.141f * (((fConst11 * ((0.2033f * fConst11) + 0.31755f)) + 1.0f) / fConst0));
		fConst13 = (0.0611561f * fConst0);
		fConst14 = (8.175799f / fConst0);
		float 	fConst15 = powf((942.4778f / fConst0),2.0f);
		fConst16 = (942.4778f * (((fConst15 * ((0.2033f * fConst15) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst17 = powf((1884.9556f / fConst0),2.0f);
		fConst18 = (1884.9556f * (((fConst17 * ((0.2033f * fConst17) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst19 = powf((2827.4333f / fConst0),2.0f);
		fConst20 = (2827.4333f * (((fConst19 * ((0.2033f * fConst19) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst21 = powf((5340.7075f / fConst0),2.0f);
		fConst22 = (5340.7075f * (((fConst21 * ((0.2033f * fConst21) + 0.31755f)) + 1.0f) / fConst0));
		float 	fConst23 = powf((62.831852f / fConst0),2.0f);
		float 	fConst24 = ((fConst23 * ((0.2033f * fConst23) + 0.31755f)) + 1.0f);
		float 	fConst25 = powf(fConst24,2.0f);
		fConst26 = (2.0f * ((3947.8418f * (fConst25 / fConst1)) + -1.0f));
		float 	fConst27 = (3947.8418f * (fConst24 / fConst0));
		fConst28 = (((fConst24 * (fConst27 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst29 = (((fConst24 * (fConst27 + 88.49557f)) / fConst0) + 1.0f);
		fConst30 = (1.0f / fConst29);
		fConst31 = (fConst25 / (fConst1 * fConst29));
		fConst32 = (3.1415927f / fConst0);
		fConst33 = (0.1f * fConst0);
		fConst34 = (0.2f * fConst0);
		fConst35 = (0.01f * fConst0);
		fConst36 = (0.05f * fConst0);
		fConst37 = (2.0f * fConst0);
		fConst38 = (0.2f / fConst0);
		float 	fConst39 = powf((125.663704f / fConst0),2.0f);
		float 	fConst40 = ((fConst39 * ((0.2033f * fConst39) + 0.31755f)) + 1.0f);
		float 	fConst41 = powf(fConst40,2.0f);
		fConst42 = (2.0f * ((15791.367f * (fConst41 / fConst1)) + -1.0f));
		float 	fConst43 = (15791.367f * (fConst40 / fConst0));
		fConst44 = (((fConst40 * (fConst43 + -232.71057f)) / fConst0) + 1.0f);
		float 	fConst45 = (((fConst40 * (fConst43 + 232.71057f)) / fConst0) + 1.0f);
		fConst46 = (1.0f / fConst45);
		fConst47 = (((fConst40 * (fConst43 + -95.92649f)) / fConst0) + 1.0f);
		float 	fConst48 = (((fConst40 * (fConst43 + 95.92649f)) / fConst0) + 1.0f);
		fConst49 = (1.0f / fConst48);
		fConst50 = (fConst41 / (fConst1 * fConst48));
		fConst51 = (fConst41 / (fConst1 * fConst45));
		fConst52 = powf(0.5f,(1e+01f / fConst0));
		fConst53 = (1.37f * fConst31);
		fConst54 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
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
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) iRec48[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<3; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec53[i] = 0;
		for (int i=0; i<3; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) iRec70[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<3; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) fRec74[i] = 0;
		for (int i=0; i<3; i++) fRec75[i] = 0;
		for (int i=0; i<3; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) iRec92[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<3; i++) fRec94[i] = 0;
		for (int i=0; i<3; i++) fRec96[i] = 0;
		for (int i=0; i<3; i++) fRec97[i] = 0;
		for (int i=0; i<3; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) iRec114[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec115[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<3; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec117[i] = 0;
		for (int i=0; i<3; i++) fRec116[i] = 0;
		for (int i=0; i<3; i++) fRec118[i] = 0;
		for (int i=0; i<3; i++) fRec119[i] = 0;
		for (int i=0; i<3; i++) fRec120[i] = 0;
		for (int i=0; i<2; i++) fRec121[i] = 0;
		for (int i=0; i<2; i++) fRec122[i] = 0;
		for (int i=0; i<2; i++) fRec131[i] = 0;
		for (int i=0; i<2; i++) fRec130[i] = 0;
		for (int i=0; i<2; i++) fRec132[i] = 0;
		for (int i=0; i<2; i++) fRec133[i] = 0;
		for (int i=0; i<2; i++) fRec134[i] = 0;
		for (int i=0; i<2; i++) fRec135[i] = 0;
		for (int i=0; i<2; i++) iRec136[i] = 0;
		for (int i=0; i<2; i++) fRec128[i] = 0;
		for (int i=0; i<2; i++) fRec137[i] = 0;
		for (int i=0; i<2; i++) fRec129[i] = 0;
		for (int i=0; i<3; i++) fRec127[i] = 0;
		for (int i=0; i<2; i++) fRec124[i] = 0;
		for (int i=0; i<2; i++) fRec125[i] = 0;
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
		float 	fSlow1 = (((fSlow0 > 0.0f)) ? fConst12 : fConst10);
		float 	fSlow2 = fabsf(fSlow0);
		float 	fSlow3 = ((0.5f * fSlow2) + 1.0f);
		float 	fSlow4 = (fSlow3 * fSlow1);
		float 	fSlow5 = ((fSlow3 * (fSlow1 * (fSlow4 + 0.125f))) + 1.0f);
		float 	fSlow6 = ((powf(fSlow3,2.0f) * powf(fSlow1,2.0f)) + -1.0f);
		float 	fSlow7 = ((fSlow3 * (fSlow1 * (fSlow4 + -0.125f))) + 1.0f);
		float 	fSlow8 = fastpow2((0.083333336f * float(fslider1)));
		int 	iSlow9 = int(min((fConst13 / fSlow8), 4096.0f));
		float 	fSlow10 = float(iSlow9);
		float 	fSlow11 = (fConst14 * (fSlow8 * fSlow10));
		float 	fSlow12 = (fSlow2 * fSlow3);
		float 	fSlow13 = float(fslider2);
		float 	fSlow14 = (((fSlow13 > 0.0f)) ? fConst18 : fConst16);
		float 	fSlow15 = fabsf(fSlow13);
		float 	fSlow16 = ((0.5f * fSlow15) + 1.0f);
		float 	fSlow17 = (fSlow16 * fSlow14);
		float 	fSlow18 = ((fSlow16 * (fSlow14 * (fSlow17 + 0.125f))) + 1.0f);
		float 	fSlow19 = ((powf(fSlow16,2.0f) * powf(fSlow14,2.0f)) + -1.0f);
		float 	fSlow20 = ((fSlow16 * (fSlow14 * (fSlow17 + -0.125f))) + 1.0f);
		float 	fSlow21 = (fSlow15 * fSlow16);
		float 	fSlow22 = float(fslider3);
		float 	fSlow23 = (((fSlow22 > 0.0f)) ? fConst22 : fConst20);
		float 	fSlow24 = fabsf(fSlow22);
		float 	fSlow25 = ((0.5f * fSlow24) + 1.0f);
		float 	fSlow26 = (fSlow25 * fSlow23);
		float 	fSlow27 = ((fSlow25 * (fSlow23 * (fSlow26 + 0.2f))) + 1.0f);
		float 	fSlow28 = ((powf(fSlow25,2.0f) * powf(fSlow23,2.0f)) + -1.0f);
		float 	fSlow29 = ((fSlow25 * (fSlow23 * (fSlow26 + -0.2f))) + 1.0f);
		float 	fSlow30 = (0.2f * (fSlow24 * fSlow25));
		float 	fSlow31 = float(fslider4);
		float 	fSlow32 = float(fslider5);
		float 	fSlow33 = (1.5e+03f * fSlow32);
		float 	fSlow34 = (0.4f * fSlow32);
		int 	iSlow35 = (((fSlow32 >= 0.05f)) ? 1 : 0);
		float 	fSlow36 = min((2.0f * fSlow31), 1.0f);
		float 	fSlow37 = fabsf(fSlow36);
		float 	fSlow38 = (((fSlow37 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow39 = ((fSlow36 > 0.0f) - (fSlow36 < 0.0f));
		int 	iSlow40 = (fSlow32 <= 0.05f);
		int 	iSlow41 = ((iSlow40) ? 3 : 2);
		int 	iSlow42 = (fSlow32 <= 0.0f);
		float 	fSlow43 = float(fslider6);
		float 	fSlow44 = max((8.175799f * fSlow8), 2e+02f);
		float 	fSlow45 = fastpow2((0.083333336f * float(fslider7)));
		int 	iSlow46 = int(min((fConst13 / fSlow45), 4096.0f));
		float 	fSlow47 = float(iSlow46);
		float 	fSlow48 = (fConst14 * (fSlow45 * fSlow47));
		float 	fSlow49 = float(fslider8);
		float 	fSlow50 = float(fslider9);
		float 	fSlow51 = (1.5e+03f * fSlow50);
		float 	fSlow52 = (0.4f * fSlow50);
		int 	iSlow53 = (((fSlow50 >= 0.05f)) ? 1 : 0);
		float 	fSlow54 = min((2.0f * fSlow49), 1.0f);
		float 	fSlow55 = fabsf(fSlow54);
		float 	fSlow56 = (((fSlow55 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow57 = ((fSlow54 > 0.0f) - (fSlow54 < 0.0f));
		int 	iSlow58 = (fSlow50 <= 0.05f);
		int 	iSlow59 = ((iSlow58) ? 3 : 2);
		int 	iSlow60 = (fSlow50 <= 0.0f);
		float 	fSlow61 = max((8.175799f * fSlow45), 2e+02f);
		float 	fSlow62 = fastpow2((0.083333336f * float(fslider10)));
		int 	iSlow63 = int(min((fConst13 / fSlow62), 4096.0f));
		float 	fSlow64 = float(iSlow63);
		float 	fSlow65 = (fConst14 * (fSlow62 * fSlow64));
		float 	fSlow66 = float(fslider11);
		float 	fSlow67 = float(fslider12);
		float 	fSlow68 = (1.5e+03f * fSlow67);
		float 	fSlow69 = (0.4f * fSlow67);
		int 	iSlow70 = (((fSlow67 >= 0.05f)) ? 1 : 0);
		float 	fSlow71 = min((2.0f * fSlow66), 1.0f);
		float 	fSlow72 = fabsf(fSlow71);
		float 	fSlow73 = (((fSlow72 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow74 = ((fSlow71 > 0.0f) - (fSlow71 < 0.0f));
		int 	iSlow75 = (fSlow67 <= 0.05f);
		int 	iSlow76 = ((iSlow75) ? 3 : 2);
		int 	iSlow77 = (fSlow67 <= 0.0f);
		float 	fSlow78 = max((8.175799f * fSlow62), 2e+02f);
		float 	fSlow79 = fastpow2((0.083333336f * float(fslider13)));
		int 	iSlow80 = int(min((fConst13 / fSlow79), 4096.0f));
		float 	fSlow81 = float(iSlow80);
		float 	fSlow82 = (fConst14 * (fSlow79 * fSlow81));
		float 	fSlow83 = float(fslider14);
		float 	fSlow84 = float(fslider15);
		float 	fSlow85 = (1.5e+03f * fSlow84);
		float 	fSlow86 = (0.4f * fSlow84);
		int 	iSlow87 = (((fSlow84 >= 0.05f)) ? 1 : 0);
		float 	fSlow88 = min((2.0f * fSlow83), 1.0f);
		float 	fSlow89 = fabsf(fSlow88);
		float 	fSlow90 = (((fSlow89 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow91 = ((fSlow88 > 0.0f) - (fSlow88 < 0.0f));
		int 	iSlow92 = (fSlow84 <= 0.05f);
		int 	iSlow93 = ((iSlow92) ? 3 : 2);
		int 	iSlow94 = (fSlow84 <= 0.0f);
		float 	fSlow95 = max((8.175799f * fSlow79), 2e+02f);
		float 	fSlow96 = fastpow2((0.083333336f * float(fslider16)));
		int 	iSlow97 = int(min((fConst13 / fSlow96), 4096.0f));
		float 	fSlow98 = float(iSlow97);
		float 	fSlow99 = (fConst14 * (fSlow96 * fSlow98));
		float 	fSlow100 = float(fslider17);
		float 	fSlow101 = float(fslider18);
		float 	fSlow102 = (1.5e+03f * fSlow101);
		float 	fSlow103 = (0.4f * fSlow101);
		int 	iSlow104 = (((fSlow101 >= 0.05f)) ? 1 : 0);
		float 	fSlow105 = min((2.0f * fSlow100), 1.0f);
		float 	fSlow106 = fabsf(fSlow105);
		float 	fSlow107 = (((fSlow106 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow108 = ((fSlow105 > 0.0f) - (fSlow105 < 0.0f));
		int 	iSlow109 = (fSlow101 <= 0.05f);
		int 	iSlow110 = ((iSlow109) ? 3 : 2);
		int 	iSlow111 = (fSlow101 <= 0.0f);
		float 	fSlow112 = max((8.175799f * fSlow96), 2e+02f);
		float 	fSlow113 = fastpow2((0.083333336f * float(fslider19)));
		int 	iSlow114 = int(min((fConst13 / fSlow113), 4096.0f));
		float 	fSlow115 = float(iSlow114);
		float 	fSlow116 = (fConst14 * (fSlow113 * fSlow115));
		float 	fSlow117 = float(fslider20);
		float 	fSlow118 = float(fslider21);
		float 	fSlow119 = (1.5e+03f * fSlow118);
		float 	fSlow120 = (0.4f * fSlow118);
		int 	iSlow121 = (((fSlow118 >= 0.05f)) ? 1 : 0);
		float 	fSlow122 = min((2.0f * fSlow117), 1.0f);
		float 	fSlow123 = fabsf(fSlow122);
		float 	fSlow124 = (((fSlow123 >= 0.2f)) ? fConst33 : fConst0);
		int 	iSlow125 = ((fSlow122 > 0.0f) - (fSlow122 < 0.0f));
		int 	iSlow126 = (fSlow118 <= 0.05f);
		int 	iSlow127 = ((iSlow126) ? 3 : 2);
		int 	iSlow128 = (fSlow118 <= 0.0f);
		float 	fSlow129 = max((8.175799f * fSlow113), 2e+02f);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			fRec2[0] = (fSlow11 + (fRec2[1] - float((iSlow9 * ((fSlow11 + fRec2[1]) > fSlow10)))));
			int 	iTemp0 = int(fRec2[0]);
			float 	fTemp1 = ftbl0[max(0, int(min(int(iTemp0), 4095)))];
			float 	fTemp2 = (fTemp1 + ((fRec2[0] - float(iTemp0)) * (ftbl0[max(0, int(min(int(((iTemp0 + 1) % iSlow9)), 4095)))] - fTemp1)));
			fRec1[0] = (fTemp2 - (((fSlow7 * fRec1[2]) + (2.0f * (fSlow6 * fRec1[1]))) / fSlow5));
			fRec3[0] = (fTemp2 - (((fSlow20 * fRec3[2]) + (2.0f * (fSlow19 * fRec3[1]))) / fSlow18));
			fRec4[0] = (fTemp2 - (((fSlow29 * fRec4[2]) + (2.0f * (fSlow28 * fRec4[1]))) / fSlow27));
			fRec5[0] = (fSlow31 - (fConst30 * ((fConst28 * fRec5[2]) + (fConst26 * fRec5[1]))));
			float 	fTemp3 = ((fConst31 * (((3947.8418f * fRec5[0]) + (7895.6836f * fRec5[1])) + (3947.8418f * fRec5[2]))) + 1.0f);
			float 	fTemp4 = (0.5f * fTemp3);
			float 	fTemp5 = max(fTemp4, 0.0f);
			float 	fTemp6 = tanf((fConst32 * ((fSlow33 * (fTemp3 * fTemp5)) + 2e+02f)));
			float 	fTemp7 = ((fTemp6 * (fTemp6 + 0.5f)) + 1.0f);
			float 	fTemp8 = (fRec6[1] + (fTemp6 * (fTemp2 - fRec7[1])));
			float 	fTemp9 = (fTemp8 / fTemp7);
			fRec6[0] = ((2.0f * fTemp9) - fRec6[1]);
			float 	fTemp10 = (fRec7[1] + ((fTemp6 * fTemp8) / fTemp7));
			fRec7[0] = ((2.0f * fTemp10) - fRec7[1]);
			float 	fRec8 = fTemp9;
			float 	fTemp11 = max((-1.0f * fTemp4), 0.0f);
			float 	fTemp12 = (1.0f / (((iSlow39 == ((fRec15[1] > 0.0f) - (fRec15[1] < 0.0f)))) ? (((fSlow37 >= fabsf(fRec15[1]))) ? fConst33 : fConst0) : fSlow38));
			float 	fTemp13 = (fRec16[1] - fTemp12);
			float 	fTemp14 = (fRec16[1] + fTemp12);
			fRec16[0] = (((fTemp14 < fSlow36)) ? fTemp14 : (((fTemp13 > fSlow36)) ? fTemp13 : fSlow36));
			fRec15[0] = fRec16[0];
			int 	iTemp15 = ((fRec15[0] > 0.0f) + (1 - (fRec15[0] < 0.0f)));
			int 	iTemp16 = (iTemp15 == 0);
			float 	fTemp17 = ((iTemp16) ? 1.7f : 1.6f);
			fRec17[0] = fRec13[1];
			int 	iTemp18 = (fRec17[1] == fRec13[1]);
			int 	iTemp19 = (fRec13[1] == 0.0f);
			fRec18[0] = ((iTemp19) ? fSlow32 : ((iTemp18) ? min(min(fRec18[1], fSlow32), fRec14[1]) : min(fSlow32, fRec14[1])));
			float 	fTemp20 = (fSlow32 * fTemp17);
			int 	iTemp21 = (fRec13[1] == 1.0f);
			fRec19[0] = ((iTemp19) ? fSlow32 : ((iTemp21) ? ((iTemp18) ? max(max(fRec19[1], fTemp20), fRec14[1]) : max(fTemp20, fRec14[1])) : ((iTemp18) ? max(max(fRec19[1], fSlow32), fRec14[1]) : max(fSlow32, fRec14[1]))));
			fbargraph0 = fRec18[0];
			fRec20[0] = fRec13[1];
			iRec22[0] = (iRec22[1] + 1);
			int 	iTemp22 = (iRec22[0] + -1);
			iRec21[0] = (((fRec20[1] != fRec13[1])) ? iTemp22 : iRec21[1]);
			float 	fTemp23 = float((iRec22[0] + (-1 - iRec21[0])));
			int 	iTemp24 = (fRec13[1] >= 1.0f);
			int 	iTemp25 = (fSlow32 >= fRec14[1]);
			int 	iTemp26 = (fRec13[1] >= 3.0f);
			int 	iTemp27 = (fRec13[1] >= 2.0f);
			int 	iTemp28 = (fRec13[1] >= 5.0f);
			int 	iTemp29 = (fRec13[1] >= 6.0f);
			int 	iTemp30 = (fRec13[1] >= 4.0f);
			fbargraph1 = float(((iTemp30) ? ((iTemp29) ? ((iSlow40) ? 3 : ((iTemp25) ? 5 : 6)) : ((iTemp28) ? ((iSlow40) ? 3 : (((fSlow32 <= fRec14[1])) ? 6 : 5)) : (((fRec14[1] <= 0.05f)) ? 0 : 4))) : ((iTemp27) ? ((iTemp26) ? (((iSlow42 & (fRec14[1] <= 0.01f))) ? 4 : (((fSlow32 > fRec14[1])) ? 1 : 3)) : ((iTemp25) ? 5 : iSlow41)) : ((iTemp24) ? ((((fTemp23 >= fConst33) & (fRec14[1] >= (fbargraph0 * fTemp17)))) ? 2 : 1) : iSlow35))));
			fRec13[0] = fbargraph1;
			float 	fTemp31 = ((iTemp21) ? min(1.0f, fTemp20) : fSlow32);
			float 	fTemp32 = ((iTemp30) ? ((iTemp29) ? fConst0 : ((iTemp28) ? fConst0 : fConst35)) : ((iTemp27) ? ((iTemp26) ? 1.0f : fConst33) : ((iTemp24) ? fConst34 : 0.0f)));
			float 	fTemp33 = fabsf(fRec15[0]);
			fbargraph2 = ((fTemp33 * ((iTemp16) ? ((iTemp30) ? ((iTemp29) ? fConst37 : ((iTemp28) ? fConst37 : fConst35)) : ((iTemp27) ? ((iTemp26) ? 8.0f : fConst36) : ((iTemp24) ? fConst36 : 0.0f))) : (((iTemp15 == 1)) ? fTemp32 : ((iTemp30) ? fConst35 : ((iTemp27) ? ((iTemp26) ? 0.01f : fConst33) : ((iTemp24) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp33) * fTemp32));
			float 	fTemp34 = fbargraph2;
			float 	fTemp35 = (1.0f / fTemp34);
			float 	fTemp36 = (fRec23[1] - fTemp35);
			float 	fTemp37 = (fRec23[1] + fTemp35);
			fRec23[0] = (((fTemp37 < fTemp31)) ? fTemp37 : (((fTemp36 > fTemp31)) ? fTemp36 : fTemp31));
			float 	fTemp39 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp34))));
			int 	iTemp40 = int(fTemp39);
			float 	fTemp41 = (fConst38 * fTemp23);
			int 	iTemp42 = int(fTemp41);
			int 	iTemp43 = max(0, min(((3 * max(0, min(iTemp42, 2))) + max(0, min(iTemp40, 2))), 8));
			float 	fTemp44 = ftbl1[max(0, min((iTemp43 + 3), 8))];
			float 	fTemp45 = ftbl1[iTemp43];
			float 	fTemp46 = (ftbl1[max(0, min((iTemp43 + 1), 8))] - fTemp45);
			float 	fTemp47 = (fTemp39 - float(iTemp40));
			fbargraph3 = fRec19[0];
			int 	iTemp48 = (fRec13[1] == 3.0f);
			fRec14[0] = ((iTemp48) ? ((iTemp48) ? (fbargraph3 * ((fTemp45 + (fTemp47 * fTemp46)) + ((fTemp41 - float(iTemp42)) * (fTemp44 - (fTemp45 + (fTemp47 * (fTemp46 - (ftbl1[max(0, min((iTemp43 + 4), 8))] - fTemp44)))))))) : 0.0f) : fRec23[0]);
			fRec12[0] = (fRec14[0] - (fConst30 * ((fConst28 * fRec12[2]) + (fConst26 * fRec12[1]))));
			float 	fTemp49 = (((3947.8418f * fRec12[0]) + (7895.6836f * fRec12[1])) + (3947.8418f * fRec12[2]));
			fRec27[0] = (fSlow43 - (fConst49 * ((fConst47 * fRec27[2]) + (fConst42 * fRec27[1]))));
			fRec26[0] = ((fConst50 * (((15791.367f * fRec27[0]) + (31582.734f * fRec27[1])) + (15791.367f * fRec27[2]))) - (fConst46 * ((fConst44 * fRec26[2]) + (fConst42 * fRec26[1]))));
			fRec25[0] = (fConst52 * max(fRec25[1], min((fConst51 * (((15791.367f * fRec26[0]) + (31582.734f * fRec26[1])) + (15791.367f * fRec26[2]))), 2.0f)));
			float 	fTemp50 = max((fRec25[0] + -1.0f), 0.0f);
			float 	fTemp51 = tanf((fConst32 * min((fSlow44 * (powf((fTemp50 + (fConst31 * (fTemp49 * (1.0f - fTemp11)))),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp52 = ((fTemp51 * (fTemp51 + (1.0f / ((8.0f * fTemp11) + 1.0f)))) + 1.0f);
			float 	fTemp53 = (fRec9[1] + (fTemp51 * (fTemp2 - fRec10[1])));
			float 	fTemp54 = (fTemp53 / fTemp52);
			fRec9[0] = ((2.0f * fTemp54) - fRec9[1]);
			float 	fTemp55 = (fRec10[1] + ((fTemp51 * fTemp53) / fTemp52));
			fRec10[0] = ((2.0f * fTemp55) - fRec10[1]);
			float 	fRec11 = fTemp55;
			fRec29[0] = (fSlow48 + (fRec29[1] - float((iSlow46 * ((fSlow48 + fRec29[1]) > fSlow47)))));
			int 	iTemp56 = int(fRec29[0]);
			float 	fTemp57 = ftbl0[max(0, int(min(int(iTemp56), 4095)))];
			float 	fTemp58 = (fTemp57 + ((fRec29[0] - float(iTemp56)) * (ftbl0[max(0, int(min(int(((iTemp56 + 1) % iSlow46)), 4095)))] - fTemp57)));
			fRec28[0] = (fTemp58 - (((fSlow7 * fRec28[2]) + (2.0f * (fSlow6 * fRec28[1]))) / fSlow5));
			fRec30[0] = (fTemp58 - (((fSlow20 * fRec30[2]) + (2.0f * (fSlow19 * fRec30[1]))) / fSlow18));
			fRec31[0] = (fTemp58 - (((fSlow29 * fRec31[2]) + (2.0f * (fSlow28 * fRec31[1]))) / fSlow27));
			fRec32[0] = (fSlow49 - (fConst30 * ((fConst28 * fRec32[2]) + (fConst26 * fRec32[1]))));
			float 	fTemp59 = ((fConst31 * (((3947.8418f * fRec32[0]) + (7895.6836f * fRec32[1])) + (3947.8418f * fRec32[2]))) + 1.0f);
			float 	fTemp60 = (0.5f * fTemp59);
			float 	fTemp61 = max(fTemp60, 0.0f);
			float 	fTemp62 = tanf((fConst32 * ((fSlow51 * (fTemp59 * fTemp61)) + 2e+02f)));
			float 	fTemp63 = ((fTemp62 * (fTemp62 + 0.5f)) + 1.0f);
			float 	fTemp64 = (fRec33[1] + (fTemp62 * (fTemp58 - fRec34[1])));
			float 	fTemp65 = (fTemp64 / fTemp63);
			fRec33[0] = ((2.0f * fTemp65) - fRec33[1]);
			float 	fTemp66 = (fRec34[1] + ((fTemp62 * fTemp64) / fTemp63));
			fRec34[0] = ((2.0f * fTemp66) - fRec34[1]);
			float 	fRec35 = fTemp65;
			float 	fTemp67 = max((-1.0f * fTemp60), 0.0f);
			float 	fTemp68 = (1.0f / (((iSlow57 == ((fRec42[1] > 0.0f) - (fRec42[1] < 0.0f)))) ? (((fSlow55 >= fabsf(fRec42[1]))) ? fConst33 : fConst0) : fSlow56));
			float 	fTemp69 = (fRec43[1] - fTemp68);
			float 	fTemp70 = (fRec43[1] + fTemp68);
			fRec43[0] = (((fTemp70 < fSlow54)) ? fTemp70 : (((fTemp69 > fSlow54)) ? fTemp69 : fSlow54));
			fRec42[0] = fRec43[0];
			int 	iTemp71 = ((fRec42[0] > 0.0f) + (1 - (fRec42[0] < 0.0f)));
			int 	iTemp72 = (iTemp71 == 0);
			float 	fTemp73 = ((iTemp72) ? 1.7f : 1.6f);
			fRec44[0] = fRec40[1];
			int 	iTemp74 = (fRec44[1] == fRec40[1]);
			int 	iTemp75 = (fRec40[1] == 0.0f);
			fRec45[0] = ((iTemp75) ? fSlow50 : ((iTemp74) ? min(min(fRec45[1], fSlow50), fRec41[1]) : min(fSlow50, fRec41[1])));
			float 	fTemp76 = (fSlow50 * fTemp73);
			int 	iTemp77 = (fRec40[1] == 1.0f);
			fRec46[0] = ((iTemp75) ? fSlow50 : ((iTemp77) ? ((iTemp74) ? max(max(fRec46[1], fTemp76), fRec41[1]) : max(fTemp76, fRec41[1])) : ((iTemp74) ? max(max(fRec46[1], fSlow50), fRec41[1]) : max(fSlow50, fRec41[1]))));
			fbargraph4 = fRec45[0];
			fRec47[0] = fRec40[1];
			iRec48[0] = (((fRec47[1] != fRec40[1])) ? iTemp22 : iRec48[1]);
			float 	fTemp78 = float((iRec22[0] + (-1 - iRec48[0])));
			int 	iTemp79 = (fRec40[1] >= 1.0f);
			int 	iTemp80 = (fSlow50 >= fRec41[1]);
			int 	iTemp81 = (fRec40[1] >= 3.0f);
			int 	iTemp82 = (fRec40[1] >= 2.0f);
			int 	iTemp83 = (fRec40[1] >= 5.0f);
			int 	iTemp84 = (fRec40[1] >= 6.0f);
			int 	iTemp85 = (fRec40[1] >= 4.0f);
			fbargraph5 = float(((iTemp85) ? ((iTemp84) ? ((iSlow58) ? 3 : ((iTemp80) ? 5 : 6)) : ((iTemp83) ? ((iSlow58) ? 3 : (((fSlow50 <= fRec41[1])) ? 6 : 5)) : (((fRec41[1] <= 0.05f)) ? 0 : 4))) : ((iTemp82) ? ((iTemp81) ? (((iSlow60 & (fRec41[1] <= 0.01f))) ? 4 : (((fSlow50 > fRec41[1])) ? 1 : 3)) : ((iTemp80) ? 5 : iSlow59)) : ((iTemp79) ? ((((fTemp78 >= fConst33) & (fRec41[1] >= (fbargraph4 * fTemp73)))) ? 2 : 1) : iSlow53))));
			fRec40[0] = fbargraph5;
			float 	fTemp86 = ((iTemp77) ? min(1.0f, fTemp76) : fSlow50);
			float 	fTemp87 = ((iTemp85) ? ((iTemp84) ? fConst0 : ((iTemp83) ? fConst0 : fConst35)) : ((iTemp82) ? ((iTemp81) ? 1.0f : fConst33) : ((iTemp79) ? fConst34 : 0.0f)));
			float 	fTemp88 = fabsf(fRec42[0]);
			fbargraph6 = ((fTemp88 * ((iTemp72) ? ((iTemp85) ? ((iTemp84) ? fConst37 : ((iTemp83) ? fConst37 : fConst35)) : ((iTemp82) ? ((iTemp81) ? 8.0f : fConst36) : ((iTemp79) ? fConst36 : 0.0f))) : (((iTemp71 == 1)) ? fTemp87 : ((iTemp85) ? fConst35 : ((iTemp82) ? ((iTemp81) ? 0.01f : fConst33) : ((iTemp79) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp88) * fTemp87));
			float 	fTemp89 = fbargraph6;
			float 	fTemp90 = (1.0f / fTemp89);
			float 	fTemp91 = (fRec49[1] - fTemp90);
			float 	fTemp92 = (fRec49[1] + fTemp90);
			fRec49[0] = (((fTemp92 < fTemp86)) ? fTemp92 : (((fTemp91 > fTemp86)) ? fTemp91 : fTemp86));
			float 	fTemp93 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp89))));
			int 	iTemp94 = int(fTemp93);
			float 	fTemp95 = (fConst38 * fTemp78);
			int 	iTemp96 = int(fTemp95);
			int 	iTemp97 = max(0, min(((3 * max(0, min(iTemp96, 2))) + max(0, min(iTemp94, 2))), 8));
			float 	fTemp98 = ftbl1[max(0, min((iTemp97 + 3), 8))];
			float 	fTemp99 = ftbl1[iTemp97];
			float 	fTemp100 = (ftbl1[max(0, min((iTemp97 + 1), 8))] - fTemp99);
			float 	fTemp101 = (fTemp93 - float(iTemp94));
			fbargraph7 = fRec46[0];
			int 	iTemp102 = (fRec40[1] == 3.0f);
			fRec41[0] = ((iTemp102) ? ((iTemp102) ? (fbargraph7 * ((fTemp99 + (fTemp101 * fTemp100)) + ((fTemp95 - float(iTemp96)) * (fTemp98 - (fTemp99 + (fTemp101 * (fTemp100 - (ftbl1[max(0, min((iTemp97 + 4), 8))] - fTemp98)))))))) : 0.0f) : fRec49[0]);
			fRec39[0] = (fRec41[0] - (fConst30 * ((fConst28 * fRec39[2]) + (fConst26 * fRec39[1]))));
			float 	fTemp103 = (((3947.8418f * fRec39[0]) + (7895.6836f * fRec39[1])) + (3947.8418f * fRec39[2]));
			float 	fTemp104 = tanf((fConst32 * min((fSlow61 * (powf((fTemp50 + (fConst31 * (fTemp103 * (1.0f - fTemp67)))),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp105 = ((fTemp104 * (fTemp104 + (1.0f / ((8.0f * fTemp67) + 1.0f)))) + 1.0f);
			float 	fTemp106 = (fRec36[1] + (fTemp104 * (fTemp58 - fRec37[1])));
			float 	fTemp107 = (fTemp106 / fTemp105);
			fRec36[0] = ((2.0f * fTemp107) - fRec36[1]);
			float 	fTemp108 = (fRec37[1] + ((fTemp104 * fTemp106) / fTemp105));
			fRec37[0] = ((2.0f * fTemp108) - fRec37[1]);
			float 	fRec38 = fTemp108;
			fRec51[0] = (fSlow65 + (fRec51[1] - float((iSlow63 * ((fSlow65 + fRec51[1]) > fSlow64)))));
			int 	iTemp109 = int(fRec51[0]);
			float 	fTemp110 = ftbl0[max(0, int(min(int(iTemp109), 4095)))];
			float 	fTemp111 = (fTemp110 + ((fRec51[0] - float(iTemp109)) * (ftbl0[max(0, int(min(int(((iTemp109 + 1) % iSlow63)), 4095)))] - fTemp110)));
			fRec50[0] = (fTemp111 - (((fSlow7 * fRec50[2]) + (2.0f * (fSlow6 * fRec50[1]))) / fSlow5));
			fRec52[0] = (fTemp111 - (((fSlow20 * fRec52[2]) + (2.0f * (fSlow19 * fRec52[1]))) / fSlow18));
			fRec53[0] = (fTemp111 - (((fSlow29 * fRec53[2]) + (2.0f * (fSlow28 * fRec53[1]))) / fSlow27));
			fRec54[0] = (fSlow66 - (fConst30 * ((fConst28 * fRec54[2]) + (fConst26 * fRec54[1]))));
			float 	fTemp112 = ((fConst31 * (((3947.8418f * fRec54[0]) + (7895.6836f * fRec54[1])) + (3947.8418f * fRec54[2]))) + 1.0f);
			float 	fTemp113 = (0.5f * fTemp112);
			float 	fTemp114 = max(fTemp113, 0.0f);
			float 	fTemp115 = tanf((fConst32 * ((fSlow68 * (fTemp112 * fTemp114)) + 2e+02f)));
			float 	fTemp116 = ((fTemp115 * (fTemp115 + 0.5f)) + 1.0f);
			float 	fTemp117 = (fRec55[1] + (fTemp115 * (fTemp111 - fRec56[1])));
			float 	fTemp118 = (fTemp117 / fTemp116);
			fRec55[0] = ((2.0f * fTemp118) - fRec55[1]);
			float 	fTemp119 = (fRec56[1] + ((fTemp115 * fTemp117) / fTemp116));
			fRec56[0] = ((2.0f * fTemp119) - fRec56[1]);
			float 	fRec57 = fTemp118;
			float 	fTemp120 = max((-1.0f * fTemp113), 0.0f);
			float 	fTemp121 = (1.0f / (((iSlow74 == ((fRec64[1] > 0.0f) - (fRec64[1] < 0.0f)))) ? (((fSlow72 >= fabsf(fRec64[1]))) ? fConst33 : fConst0) : fSlow73));
			float 	fTemp122 = (fRec65[1] - fTemp121);
			float 	fTemp123 = (fRec65[1] + fTemp121);
			fRec65[0] = (((fTemp123 < fSlow71)) ? fTemp123 : (((fTemp122 > fSlow71)) ? fTemp122 : fSlow71));
			fRec64[0] = fRec65[0];
			int 	iTemp124 = ((fRec64[0] > 0.0f) + (1 - (fRec64[0] < 0.0f)));
			int 	iTemp125 = (iTemp124 == 0);
			float 	fTemp126 = ((iTemp125) ? 1.7f : 1.6f);
			fRec66[0] = fRec62[1];
			int 	iTemp127 = (fRec66[1] == fRec62[1]);
			int 	iTemp128 = (fRec62[1] == 0.0f);
			fRec67[0] = ((iTemp128) ? fSlow67 : ((iTemp127) ? min(min(fRec67[1], fSlow67), fRec63[1]) : min(fSlow67, fRec63[1])));
			float 	fTemp129 = (fSlow67 * fTemp126);
			int 	iTemp130 = (fRec62[1] == 1.0f);
			fRec68[0] = ((iTemp128) ? fSlow67 : ((iTemp130) ? ((iTemp127) ? max(max(fRec68[1], fTemp129), fRec63[1]) : max(fTemp129, fRec63[1])) : ((iTemp127) ? max(max(fRec68[1], fSlow67), fRec63[1]) : max(fSlow67, fRec63[1]))));
			fbargraph8 = fRec67[0];
			fRec69[0] = fRec62[1];
			iRec70[0] = (((fRec69[1] != fRec62[1])) ? iTemp22 : iRec70[1]);
			float 	fTemp131 = float((iRec22[0] + (-1 - iRec70[0])));
			int 	iTemp132 = (fRec62[1] >= 1.0f);
			int 	iTemp133 = (fSlow67 >= fRec63[1]);
			int 	iTemp134 = (fRec62[1] >= 3.0f);
			int 	iTemp135 = (fRec62[1] >= 2.0f);
			int 	iTemp136 = (fRec62[1] >= 5.0f);
			int 	iTemp137 = (fRec62[1] >= 6.0f);
			int 	iTemp138 = (fRec62[1] >= 4.0f);
			fbargraph9 = float(((iTemp138) ? ((iTemp137) ? ((iSlow75) ? 3 : ((iTemp133) ? 5 : 6)) : ((iTemp136) ? ((iSlow75) ? 3 : (((fSlow67 <= fRec63[1])) ? 6 : 5)) : (((fRec63[1] <= 0.05f)) ? 0 : 4))) : ((iTemp135) ? ((iTemp134) ? (((iSlow77 & (fRec63[1] <= 0.01f))) ? 4 : (((fSlow67 > fRec63[1])) ? 1 : 3)) : ((iTemp133) ? 5 : iSlow76)) : ((iTemp132) ? ((((fTemp131 >= fConst33) & (fRec63[1] >= (fbargraph8 * fTemp126)))) ? 2 : 1) : iSlow70))));
			fRec62[0] = fbargraph9;
			float 	fTemp139 = ((iTemp130) ? min(1.0f, fTemp129) : fSlow67);
			float 	fTemp140 = ((iTemp138) ? ((iTemp137) ? fConst0 : ((iTemp136) ? fConst0 : fConst35)) : ((iTemp135) ? ((iTemp134) ? 1.0f : fConst33) : ((iTemp132) ? fConst34 : 0.0f)));
			float 	fTemp141 = fabsf(fRec64[0]);
			fbargraph10 = ((fTemp141 * ((iTemp125) ? ((iTemp138) ? ((iTemp137) ? fConst37 : ((iTemp136) ? fConst37 : fConst35)) : ((iTemp135) ? ((iTemp134) ? 8.0f : fConst36) : ((iTemp132) ? fConst36 : 0.0f))) : (((iTemp124 == 1)) ? fTemp140 : ((iTemp138) ? fConst35 : ((iTemp135) ? ((iTemp134) ? 0.01f : fConst33) : ((iTemp132) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp141) * fTemp140));
			float 	fTemp142 = fbargraph10;
			float 	fTemp143 = (1.0f / fTemp142);
			float 	fTemp144 = (fRec71[1] - fTemp143);
			float 	fTemp145 = (fRec71[1] + fTemp143);
			fRec71[0] = (((fTemp145 < fTemp139)) ? fTemp145 : (((fTemp144 > fTemp139)) ? fTemp144 : fTemp139));
			float 	fTemp146 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp142))));
			int 	iTemp147 = int(fTemp146);
			float 	fTemp148 = (fConst38 * fTemp131);
			int 	iTemp149 = int(fTemp148);
			int 	iTemp150 = max(0, min(((3 * max(0, min(iTemp149, 2))) + max(0, min(iTemp147, 2))), 8));
			float 	fTemp151 = ftbl1[max(0, min((iTemp150 + 3), 8))];
			float 	fTemp152 = ftbl1[iTemp150];
			float 	fTemp153 = (ftbl1[max(0, min((iTemp150 + 1), 8))] - fTemp152);
			float 	fTemp154 = (fTemp146 - float(iTemp147));
			fbargraph11 = fRec68[0];
			int 	iTemp155 = (fRec62[1] == 3.0f);
			fRec63[0] = ((iTemp155) ? ((iTemp155) ? (fbargraph11 * ((fTemp152 + (fTemp154 * fTemp153)) + ((fTemp148 - float(iTemp149)) * (fTemp151 - (fTemp152 + (fTemp154 * (fTemp153 - (ftbl1[max(0, min((iTemp150 + 4), 8))] - fTemp151)))))))) : 0.0f) : fRec71[0]);
			fRec61[0] = (fRec63[0] - (fConst30 * ((fConst28 * fRec61[2]) + (fConst26 * fRec61[1]))));
			float 	fTemp156 = (((3947.8418f * fRec61[0]) + (7895.6836f * fRec61[1])) + (3947.8418f * fRec61[2]));
			float 	fTemp157 = tanf((fConst32 * min((fSlow78 * (powf((fTemp50 + (fConst31 * (fTemp156 * (1.0f - fTemp120)))),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp158 = ((fTemp157 * (fTemp157 + (1.0f / ((8.0f * fTemp120) + 1.0f)))) + 1.0f);
			float 	fTemp159 = (fRec58[1] + (fTemp157 * (fTemp111 - fRec59[1])));
			float 	fTemp160 = (fTemp159 / fTemp158);
			fRec58[0] = ((2.0f * fTemp160) - fRec58[1]);
			float 	fTemp161 = (fRec59[1] + ((fTemp157 * fTemp159) / fTemp158));
			fRec59[0] = ((2.0f * fTemp161) - fRec59[1]);
			float 	fRec60 = fTemp161;
			fRec73[0] = (fSlow82 + (fRec73[1] - float((iSlow80 * ((fSlow82 + fRec73[1]) > fSlow81)))));
			int 	iTemp162 = int(fRec73[0]);
			float 	fTemp163 = ftbl0[max(0, int(min(int(iTemp162), 4095)))];
			float 	fTemp164 = (fTemp163 + ((fRec73[0] - float(iTemp162)) * (ftbl0[max(0, int(min(int(((iTemp162 + 1) % iSlow80)), 4095)))] - fTemp163)));
			fRec72[0] = (fTemp164 - (((fSlow7 * fRec72[2]) + (2.0f * (fSlow6 * fRec72[1]))) / fSlow5));
			fRec74[0] = (fTemp164 - (((fSlow20 * fRec74[2]) + (2.0f * (fSlow19 * fRec74[1]))) / fSlow18));
			fRec75[0] = (fTemp164 - (((fSlow29 * fRec75[2]) + (2.0f * (fSlow28 * fRec75[1]))) / fSlow27));
			fRec76[0] = (fSlow83 - (fConst30 * ((fConst28 * fRec76[2]) + (fConst26 * fRec76[1]))));
			float 	fTemp165 = ((fConst31 * (((3947.8418f * fRec76[0]) + (7895.6836f * fRec76[1])) + (3947.8418f * fRec76[2]))) + 1.0f);
			float 	fTemp166 = (0.5f * fTemp165);
			float 	fTemp167 = max(fTemp166, 0.0f);
			float 	fTemp168 = tanf((fConst32 * ((fSlow85 * (fTemp165 * fTemp167)) + 2e+02f)));
			float 	fTemp169 = ((fTemp168 * (fTemp168 + 0.5f)) + 1.0f);
			float 	fTemp170 = (fRec77[1] + (fTemp168 * (fTemp164 - fRec78[1])));
			float 	fTemp171 = (fTemp170 / fTemp169);
			fRec77[0] = ((2.0f * fTemp171) - fRec77[1]);
			float 	fTemp172 = (fRec78[1] + ((fTemp168 * fTemp170) / fTemp169));
			fRec78[0] = ((2.0f * fTemp172) - fRec78[1]);
			float 	fRec79 = fTemp171;
			float 	fTemp173 = max((-1.0f * fTemp166), 0.0f);
			float 	fTemp174 = (1.0f / (((iSlow91 == ((fRec86[1] > 0.0f) - (fRec86[1] < 0.0f)))) ? (((fSlow89 >= fabsf(fRec86[1]))) ? fConst33 : fConst0) : fSlow90));
			float 	fTemp175 = (fRec87[1] - fTemp174);
			float 	fTemp176 = (fRec87[1] + fTemp174);
			fRec87[0] = (((fTemp176 < fSlow88)) ? fTemp176 : (((fTemp175 > fSlow88)) ? fTemp175 : fSlow88));
			fRec86[0] = fRec87[0];
			int 	iTemp177 = ((fRec86[0] > 0.0f) + (1 - (fRec86[0] < 0.0f)));
			int 	iTemp178 = (iTemp177 == 0);
			float 	fTemp179 = ((iTemp178) ? 1.7f : 1.6f);
			fRec88[0] = fRec84[1];
			int 	iTemp180 = (fRec88[1] == fRec84[1]);
			int 	iTemp181 = (fRec84[1] == 0.0f);
			fRec89[0] = ((iTemp181) ? fSlow84 : ((iTemp180) ? min(min(fRec89[1], fSlow84), fRec85[1]) : min(fSlow84, fRec85[1])));
			float 	fTemp182 = (fSlow84 * fTemp179);
			int 	iTemp183 = (fRec84[1] == 1.0f);
			fRec90[0] = ((iTemp181) ? fSlow84 : ((iTemp183) ? ((iTemp180) ? max(max(fRec90[1], fTemp182), fRec85[1]) : max(fTemp182, fRec85[1])) : ((iTemp180) ? max(max(fRec90[1], fSlow84), fRec85[1]) : max(fSlow84, fRec85[1]))));
			fbargraph12 = fRec89[0];
			fRec91[0] = fRec84[1];
			iRec92[0] = (((fRec91[1] != fRec84[1])) ? iTemp22 : iRec92[1]);
			float 	fTemp184 = float((iRec22[0] + (-1 - iRec92[0])));
			int 	iTemp185 = (fRec84[1] >= 1.0f);
			int 	iTemp186 = (fSlow84 >= fRec85[1]);
			int 	iTemp187 = (fRec84[1] >= 3.0f);
			int 	iTemp188 = (fRec84[1] >= 2.0f);
			int 	iTemp189 = (fRec84[1] >= 5.0f);
			int 	iTemp190 = (fRec84[1] >= 6.0f);
			int 	iTemp191 = (fRec84[1] >= 4.0f);
			fbargraph13 = float(((iTemp191) ? ((iTemp190) ? ((iSlow92) ? 3 : ((iTemp186) ? 5 : 6)) : ((iTemp189) ? ((iSlow92) ? 3 : (((fSlow84 <= fRec85[1])) ? 6 : 5)) : (((fRec85[1] <= 0.05f)) ? 0 : 4))) : ((iTemp188) ? ((iTemp187) ? (((iSlow94 & (fRec85[1] <= 0.01f))) ? 4 : (((fSlow84 > fRec85[1])) ? 1 : 3)) : ((iTemp186) ? 5 : iSlow93)) : ((iTemp185) ? ((((fTemp184 >= fConst33) & (fRec85[1] >= (fbargraph12 * fTemp179)))) ? 2 : 1) : iSlow87))));
			fRec84[0] = fbargraph13;
			float 	fTemp192 = ((iTemp183) ? min(1.0f, fTemp182) : fSlow84);
			float 	fTemp193 = ((iTemp191) ? ((iTemp190) ? fConst0 : ((iTemp189) ? fConst0 : fConst35)) : ((iTemp188) ? ((iTemp187) ? 1.0f : fConst33) : ((iTemp185) ? fConst34 : 0.0f)));
			float 	fTemp194 = fabsf(fRec86[0]);
			fbargraph14 = ((fTemp194 * ((iTemp178) ? ((iTemp191) ? ((iTemp190) ? fConst37 : ((iTemp189) ? fConst37 : fConst35)) : ((iTemp188) ? ((iTemp187) ? 8.0f : fConst36) : ((iTemp185) ? fConst36 : 0.0f))) : (((iTemp177 == 1)) ? fTemp193 : ((iTemp191) ? fConst35 : ((iTemp188) ? ((iTemp187) ? 0.01f : fConst33) : ((iTemp185) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp194) * fTemp193));
			float 	fTemp195 = fbargraph14;
			float 	fTemp196 = (1.0f / fTemp195);
			float 	fTemp197 = (fRec93[1] - fTemp196);
			float 	fTemp198 = (fRec93[1] + fTemp196);
			fRec93[0] = (((fTemp198 < fTemp192)) ? fTemp198 : (((fTemp197 > fTemp192)) ? fTemp197 : fTemp192));
			float 	fTemp199 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp195))));
			int 	iTemp200 = int(fTemp199);
			float 	fTemp201 = (fConst38 * fTemp184);
			int 	iTemp202 = int(fTemp201);
			int 	iTemp203 = max(0, min(((3 * max(0, min(iTemp202, 2))) + max(0, min(iTemp200, 2))), 8));
			float 	fTemp204 = ftbl1[max(0, min((iTemp203 + 3), 8))];
			float 	fTemp205 = ftbl1[iTemp203];
			float 	fTemp206 = (ftbl1[max(0, min((iTemp203 + 1), 8))] - fTemp205);
			float 	fTemp207 = (fTemp199 - float(iTemp200));
			fbargraph15 = fRec90[0];
			int 	iTemp208 = (fRec84[1] == 3.0f);
			fRec85[0] = ((iTemp208) ? ((iTemp208) ? (fbargraph15 * ((fTemp205 + (fTemp207 * fTemp206)) + ((fTemp201 - float(iTemp202)) * (fTemp204 - (fTemp205 + (fTemp207 * (fTemp206 - (ftbl1[max(0, min((iTemp203 + 4), 8))] - fTemp204)))))))) : 0.0f) : fRec93[0]);
			fRec83[0] = (fRec85[0] - (fConst30 * ((fConst28 * fRec83[2]) + (fConst26 * fRec83[1]))));
			float 	fTemp209 = (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]));
			float 	fTemp210 = tanf((fConst32 * min((fSlow95 * (powf((fTemp50 + (fConst31 * (fTemp209 * (1.0f - fTemp173)))),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp211 = ((fTemp210 * (fTemp210 + (1.0f / ((8.0f * fTemp173) + 1.0f)))) + 1.0f);
			float 	fTemp212 = (fRec80[1] + (fTemp210 * (fTemp164 - fRec81[1])));
			float 	fTemp213 = (fTemp212 / fTemp211);
			fRec80[0] = ((2.0f * fTemp213) - fRec80[1]);
			float 	fTemp214 = (fRec81[1] + ((fTemp210 * fTemp212) / fTemp211));
			fRec81[0] = ((2.0f * fTemp214) - fRec81[1]);
			float 	fRec82 = fTemp214;
			fRec95[0] = (fSlow99 + (fRec95[1] - float((iSlow97 * ((fSlow99 + fRec95[1]) > fSlow98)))));
			int 	iTemp215 = int(fRec95[0]);
			float 	fTemp216 = ftbl0[max(0, int(min(int(iTemp215), 4095)))];
			float 	fTemp217 = (fTemp216 + ((fRec95[0] - float(iTemp215)) * (ftbl0[max(0, int(min(int(((iTemp215 + 1) % iSlow97)), 4095)))] - fTemp216)));
			fRec94[0] = (fTemp217 - (((fSlow7 * fRec94[2]) + (2.0f * (fSlow6 * fRec94[1]))) / fSlow5));
			fRec96[0] = (fTemp217 - (((fSlow20 * fRec96[2]) + (2.0f * (fSlow19 * fRec96[1]))) / fSlow18));
			fRec97[0] = (fTemp217 - (((fSlow29 * fRec97[2]) + (2.0f * (fSlow28 * fRec97[1]))) / fSlow27));
			fRec98[0] = (fSlow100 - (fConst30 * ((fConst28 * fRec98[2]) + (fConst26 * fRec98[1]))));
			float 	fTemp218 = ((fConst31 * (((3947.8418f * fRec98[0]) + (7895.6836f * fRec98[1])) + (3947.8418f * fRec98[2]))) + 1.0f);
			float 	fTemp219 = (0.5f * fTemp218);
			float 	fTemp220 = max(fTemp219, 0.0f);
			float 	fTemp221 = tanf((fConst32 * ((fSlow102 * (fTemp218 * fTemp220)) + 2e+02f)));
			float 	fTemp222 = ((fTemp221 * (fTemp221 + 0.5f)) + 1.0f);
			float 	fTemp223 = (fRec99[1] + (fTemp221 * (fTemp217 - fRec100[1])));
			float 	fTemp224 = (fTemp223 / fTemp222);
			fRec99[0] = ((2.0f * fTemp224) - fRec99[1]);
			float 	fTemp225 = (fRec100[1] + ((fTemp221 * fTemp223) / fTemp222));
			fRec100[0] = ((2.0f * fTemp225) - fRec100[1]);
			float 	fRec101 = fTemp224;
			float 	fTemp226 = max((-1.0f * fTemp219), 0.0f);
			float 	fTemp227 = (1.0f / (((iSlow108 == ((fRec108[1] > 0.0f) - (fRec108[1] < 0.0f)))) ? (((fSlow106 >= fabsf(fRec108[1]))) ? fConst33 : fConst0) : fSlow107));
			float 	fTemp228 = (fRec109[1] - fTemp227);
			float 	fTemp229 = (fRec109[1] + fTemp227);
			fRec109[0] = (((fTemp229 < fSlow105)) ? fTemp229 : (((fTemp228 > fSlow105)) ? fTemp228 : fSlow105));
			fRec108[0] = fRec109[0];
			int 	iTemp230 = ((fRec108[0] > 0.0f) + (1 - (fRec108[0] < 0.0f)));
			int 	iTemp231 = (iTemp230 == 0);
			float 	fTemp232 = ((iTemp231) ? 1.7f : 1.6f);
			fRec110[0] = fRec106[1];
			int 	iTemp233 = (fRec110[1] == fRec106[1]);
			int 	iTemp234 = (fRec106[1] == 0.0f);
			fRec111[0] = ((iTemp234) ? fSlow101 : ((iTemp233) ? min(min(fRec111[1], fSlow101), fRec107[1]) : min(fSlow101, fRec107[1])));
			float 	fTemp235 = (fSlow101 * fTemp232);
			int 	iTemp236 = (fRec106[1] == 1.0f);
			fRec112[0] = ((iTemp234) ? fSlow101 : ((iTemp236) ? ((iTemp233) ? max(max(fRec112[1], fTemp235), fRec107[1]) : max(fTemp235, fRec107[1])) : ((iTemp233) ? max(max(fRec112[1], fSlow101), fRec107[1]) : max(fSlow101, fRec107[1]))));
			fbargraph16 = fRec111[0];
			fRec113[0] = fRec106[1];
			iRec114[0] = (((fRec113[1] != fRec106[1])) ? iTemp22 : iRec114[1]);
			float 	fTemp237 = float((iRec22[0] + (-1 - iRec114[0])));
			int 	iTemp238 = (fRec106[1] >= 1.0f);
			int 	iTemp239 = (fSlow101 >= fRec107[1]);
			int 	iTemp240 = (fRec106[1] >= 3.0f);
			int 	iTemp241 = (fRec106[1] >= 2.0f);
			int 	iTemp242 = (fRec106[1] >= 5.0f);
			int 	iTemp243 = (fRec106[1] >= 6.0f);
			int 	iTemp244 = (fRec106[1] >= 4.0f);
			fbargraph17 = float(((iTemp244) ? ((iTemp243) ? ((iSlow109) ? 3 : ((iTemp239) ? 5 : 6)) : ((iTemp242) ? ((iSlow109) ? 3 : (((fSlow101 <= fRec107[1])) ? 6 : 5)) : (((fRec107[1] <= 0.05f)) ? 0 : 4))) : ((iTemp241) ? ((iTemp240) ? (((iSlow111 & (fRec107[1] <= 0.01f))) ? 4 : (((fSlow101 > fRec107[1])) ? 1 : 3)) : ((iTemp239) ? 5 : iSlow110)) : ((iTemp238) ? ((((fTemp237 >= fConst33) & (fRec107[1] >= (fbargraph16 * fTemp232)))) ? 2 : 1) : iSlow104))));
			fRec106[0] = fbargraph17;
			float 	fTemp245 = ((iTemp236) ? min(1.0f, fTemp235) : fSlow101);
			float 	fTemp246 = ((iTemp244) ? ((iTemp243) ? fConst0 : ((iTemp242) ? fConst0 : fConst35)) : ((iTemp241) ? ((iTemp240) ? 1.0f : fConst33) : ((iTemp238) ? fConst34 : 0.0f)));
			float 	fTemp247 = fabsf(fRec108[0]);
			fbargraph18 = ((fTemp247 * ((iTemp231) ? ((iTemp244) ? ((iTemp243) ? fConst37 : ((iTemp242) ? fConst37 : fConst35)) : ((iTemp241) ? ((iTemp240) ? 8.0f : fConst36) : ((iTemp238) ? fConst36 : 0.0f))) : (((iTemp230 == 1)) ? fTemp246 : ((iTemp244) ? fConst35 : ((iTemp241) ? ((iTemp240) ? 0.01f : fConst33) : ((iTemp238) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp247) * fTemp246));
			float 	fTemp248 = fbargraph18;
			float 	fTemp249 = (1.0f / fTemp248);
			float 	fTemp250 = (fRec115[1] - fTemp249);
			float 	fTemp251 = (fRec115[1] + fTemp249);
			fRec115[0] = (((fTemp251 < fTemp245)) ? fTemp251 : (((fTemp250 > fTemp245)) ? fTemp250 : fTemp245));
			float 	fTemp252 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp248))));
			int 	iTemp253 = int(fTemp252);
			float 	fTemp254 = (fConst38 * fTemp237);
			int 	iTemp255 = int(fTemp254);
			int 	iTemp256 = max(0, min(((3 * max(0, min(iTemp255, 2))) + max(0, min(iTemp253, 2))), 8));
			float 	fTemp257 = ftbl1[max(0, min((iTemp256 + 3), 8))];
			float 	fTemp258 = ftbl1[iTemp256];
			float 	fTemp259 = (ftbl1[max(0, min((iTemp256 + 1), 8))] - fTemp258);
			float 	fTemp260 = (fTemp252 - float(iTemp253));
			fbargraph19 = fRec112[0];
			int 	iTemp261 = (fRec106[1] == 3.0f);
			fRec107[0] = ((iTemp261) ? ((iTemp261) ? (fbargraph19 * ((fTemp258 + (fTemp260 * fTemp259)) + ((fTemp254 - float(iTemp255)) * (fTemp257 - (fTemp258 + (fTemp260 * (fTemp259 - (ftbl1[max(0, min((iTemp256 + 4), 8))] - fTemp257)))))))) : 0.0f) : fRec115[0]);
			fRec105[0] = (fRec107[0] - (fConst30 * ((fConst28 * fRec105[2]) + (fConst26 * fRec105[1]))));
			float 	fTemp262 = (((3947.8418f * fRec105[0]) + (7895.6836f * fRec105[1])) + (3947.8418f * fRec105[2]));
			float 	fTemp263 = tanf((fConst32 * min((fSlow112 * (powf((fTemp50 + (fConst31 * (fTemp262 * (1.0f - fTemp226)))),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp264 = ((fTemp263 * (fTemp263 + (1.0f / ((8.0f * fTemp226) + 1.0f)))) + 1.0f);
			float 	fTemp265 = (fRec102[1] + (fTemp263 * (fTemp217 - fRec103[1])));
			float 	fTemp266 = (fTemp265 / fTemp264);
			fRec102[0] = ((2.0f * fTemp266) - fRec102[1]);
			float 	fTemp267 = (fRec103[1] + ((fTemp263 * fTemp265) / fTemp264));
			fRec103[0] = ((2.0f * fTemp267) - fRec103[1]);
			float 	fRec104 = fTemp267;
			fRec117[0] = (fSlow116 + (fRec117[1] - float((iSlow114 * ((fSlow116 + fRec117[1]) > fSlow115)))));
			int 	iTemp268 = int(fRec117[0]);
			float 	fTemp269 = ftbl0[max(0, int(min(int(iTemp268), 4095)))];
			float 	fTemp270 = (fTemp269 + ((fRec117[0] - float(iTemp268)) * (ftbl0[max(0, int(min(int(((iTemp268 + 1) % iSlow114)), 4095)))] - fTemp269)));
			fRec116[0] = (fTemp270 - (((fSlow7 * fRec116[2]) + (2.0f * (fSlow6 * fRec116[1]))) / fSlow5));
			fRec118[0] = (fTemp270 - (((fSlow20 * fRec118[2]) + (2.0f * (fSlow19 * fRec118[1]))) / fSlow18));
			fRec119[0] = (fTemp270 - (((fSlow29 * fRec119[2]) + (2.0f * (fSlow28 * fRec119[1]))) / fSlow27));
			fRec120[0] = (fSlow117 - (fConst30 * ((fConst28 * fRec120[2]) + (fConst26 * fRec120[1]))));
			float 	fTemp271 = ((fConst31 * (((3947.8418f * fRec120[0]) + (7895.6836f * fRec120[1])) + (3947.8418f * fRec120[2]))) + 1.0f);
			float 	fTemp272 = (0.5f * fTemp271);
			float 	fTemp273 = max(fTemp272, 0.0f);
			float 	fTemp274 = tanf((fConst32 * ((fSlow119 * (fTemp271 * fTemp273)) + 2e+02f)));
			float 	fTemp275 = ((fTemp274 * (fTemp274 + 0.5f)) + 1.0f);
			float 	fTemp276 = (fRec121[1] + (fTemp274 * (fTemp270 - fRec122[1])));
			float 	fTemp277 = (fTemp276 / fTemp275);
			fRec121[0] = ((2.0f * fTemp277) - fRec121[1]);
			float 	fTemp278 = (fRec122[1] + ((fTemp274 * fTemp276) / fTemp275));
			fRec122[0] = ((2.0f * fTemp278) - fRec122[1]);
			float 	fRec123 = fTemp277;
			float 	fTemp279 = max((-1.0f * fTemp272), 0.0f);
			float 	fTemp280 = (1.0f / (((iSlow125 == ((fRec130[1] > 0.0f) - (fRec130[1] < 0.0f)))) ? (((fSlow123 >= fabsf(fRec130[1]))) ? fConst33 : fConst0) : fSlow124));
			float 	fTemp281 = (fRec131[1] - fTemp280);
			float 	fTemp282 = (fRec131[1] + fTemp280);
			fRec131[0] = (((fTemp282 < fSlow122)) ? fTemp282 : (((fTemp281 > fSlow122)) ? fTemp281 : fSlow122));
			fRec130[0] = fRec131[0];
			int 	iTemp283 = ((fRec130[0] > 0.0f) + (1 - (fRec130[0] < 0.0f)));
			int 	iTemp284 = (iTemp283 == 0);
			float 	fTemp285 = ((iTemp284) ? 1.7f : 1.6f);
			fRec132[0] = fRec128[1];
			int 	iTemp286 = (fRec132[1] == fRec128[1]);
			int 	iTemp287 = (fRec128[1] == 0.0f);
			fRec133[0] = ((iTemp287) ? fSlow118 : ((iTemp286) ? min(min(fRec133[1], fSlow118), fRec129[1]) : min(fSlow118, fRec129[1])));
			float 	fTemp288 = (fSlow118 * fTemp285);
			int 	iTemp289 = (fRec128[1] == 1.0f);
			fRec134[0] = ((iTemp287) ? fSlow118 : ((iTemp289) ? ((iTemp286) ? max(max(fRec134[1], fTemp288), fRec129[1]) : max(fTemp288, fRec129[1])) : ((iTemp286) ? max(max(fRec134[1], fSlow118), fRec129[1]) : max(fSlow118, fRec129[1]))));
			fbargraph20 = fRec133[0];
			fRec135[0] = fRec128[1];
			iRec136[0] = (((fRec135[1] != fRec128[1])) ? iTemp22 : iRec136[1]);
			float 	fTemp290 = float((iRec22[0] + (-1 - iRec136[0])));
			int 	iTemp291 = (fRec128[1] >= 1.0f);
			int 	iTemp292 = (fSlow118 >= fRec129[1]);
			int 	iTemp293 = (fRec128[1] >= 3.0f);
			int 	iTemp294 = (fRec128[1] >= 2.0f);
			int 	iTemp295 = (fRec128[1] >= 5.0f);
			int 	iTemp296 = (fRec128[1] >= 6.0f);
			int 	iTemp297 = (fRec128[1] >= 4.0f);
			fbargraph21 = float(((iTemp297) ? ((iTemp296) ? ((iSlow126) ? 3 : ((iTemp292) ? 5 : 6)) : ((iTemp295) ? ((iSlow126) ? 3 : (((fSlow118 <= fRec129[1])) ? 6 : 5)) : (((fRec129[1] <= 0.05f)) ? 0 : 4))) : ((iTemp294) ? ((iTemp293) ? (((iSlow128 & (fRec129[1] <= 0.01f))) ? 4 : (((fSlow118 > fRec129[1])) ? 1 : 3)) : ((iTemp292) ? 5 : iSlow127)) : ((iTemp291) ? ((((fTemp290 >= fConst33) & (fRec129[1] >= (fbargraph20 * fTemp285)))) ? 2 : 1) : iSlow121))));
			fRec128[0] = fbargraph21;
			float 	fTemp298 = ((iTemp289) ? min(1.0f, fTemp288) : fSlow118);
			float 	fTemp299 = ((iTemp297) ? ((iTemp296) ? fConst0 : ((iTemp295) ? fConst0 : fConst35)) : ((iTemp294) ? ((iTemp293) ? 1.0f : fConst33) : ((iTemp291) ? fConst34 : 0.0f)));
			float 	fTemp300 = fabsf(fRec130[0]);
			fbargraph22 = ((fTemp300 * ((iTemp284) ? ((iTemp297) ? ((iTemp296) ? fConst37 : ((iTemp295) ? fConst37 : fConst35)) : ((iTemp294) ? ((iTemp293) ? 8.0f : fConst36) : ((iTemp291) ? fConst36 : 0.0f))) : (((iTemp283 == 1)) ? fTemp299 : ((iTemp297) ? fConst35 : ((iTemp294) ? ((iTemp293) ? 0.01f : fConst33) : ((iTemp291) ? fConst33 : 0.0f)))))) + ((1.0f - fTemp300) * fTemp299));
			float 	fTemp301 = fbargraph22;
			float 	fTemp302 = (1.0f / fTemp301);
			float 	fTemp303 = (fRec137[1] - fTemp302);
			float 	fTemp304 = (fRec137[1] + fTemp302);
			fRec137[0] = (((fTemp304 < fTemp298)) ? fTemp304 : (((fTemp303 > fTemp298)) ? fTemp303 : fTemp298));
			float 	fTemp305 = (0.2f * (0.0f - (0.0f - (2.9957323f / fTemp301))));
			int 	iTemp306 = int(fTemp305);
			float 	fTemp307 = (fConst38 * fTemp290);
			int 	iTemp308 = int(fTemp307);
			int 	iTemp309 = max(0, min(((3 * max(0, min(iTemp308, 2))) + max(0, min(iTemp306, 2))), 8));
			float 	fTemp310 = ftbl1[max(0, min((iTemp309 + 3), 8))];
			float 	fTemp311 = ftbl1[iTemp309];
			float 	fTemp312 = (ftbl1[max(0, min((iTemp309 + 1), 8))] - fTemp311);
			float 	fTemp313 = (fTemp305 - float(iTemp306));
			fbargraph23 = fRec134[0];
			int 	iTemp314 = (fRec128[1] == 3.0f);
			fRec129[0] = ((iTemp314) ? ((iTemp314) ? (fbargraph23 * ((fTemp311 + (fTemp313 * fTemp312)) + ((fTemp307 - float(iTemp308)) * (fTemp310 - (fTemp311 + (fTemp313 * (fTemp312 - (ftbl1[max(0, min((iTemp309 + 4), 8))] - fTemp310)))))))) : 0.0f) : fRec137[0]);
			fRec127[0] = (fRec129[0] - (fConst30 * ((fConst28 * fRec127[2]) + (fConst26 * fRec127[1]))));
			float 	fTemp315 = (((3947.8418f * fRec127[0]) + (7895.6836f * fRec127[1])) + (3947.8418f * fRec127[2]));
			float 	fTemp316 = tanf((fConst32 * min((fSlow129 * (powf(((fConst31 * (fTemp315 * (1.0f - fTemp279))) + fTemp50),2.0f) + 1.0f)), 1.6e+04f)));
			float 	fTemp317 = ((fTemp316 * (fTemp316 + (1.0f / ((8.0f * fTemp279) + 1.0f)))) + 1.0f);
			float 	fTemp318 = (fRec124[1] + (fTemp316 * (fTemp270 - fRec125[1])));
			float 	fTemp319 = (fTemp318 / fTemp317);
			fRec124[0] = ((2.0f * fTemp319) - fRec124[1]);
			float 	fTemp320 = (fRec125[1] + ((fTemp316 * fTemp318) / fTemp317));
			fRec125[0] = ((2.0f * fTemp320) - fRec125[1]);
			float 	fRec126 = fTemp320;
			fRec0[0] = ((fConst53 * ((((((fTemp315 * (((fRec126 * powf((1.0f - (0.5f * fTemp279)),2.0f)) + (fSlow120 * ((fRec123 * fTemp271) * fTemp273))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec119[0] - fRec119[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec118[0] - fRec118[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec116[0] - fRec116[2])) / fSlow5)))))))) + (fTemp262 * (((fRec104 * powf((1.0f - (0.5f * fTemp226)),2.0f)) + (fSlow103 * ((fRec101 * fTemp218) * fTemp220))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec97[0] - fRec97[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec96[0] - fRec96[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec94[0] - fRec94[2])) / fSlow5))))))))) + (fTemp209 * (((fRec82 * powf((1.0f - (0.5f * fTemp173)),2.0f)) + (fSlow86 * ((fRec79 * fTemp165) * fTemp167))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec75[0] - fRec75[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec74[0] - fRec74[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec72[0] - fRec72[2])) / fSlow5))))))))) + (fTemp156 * (((fRec60 * powf((1.0f - (0.5f * fTemp120)),2.0f)) + (fSlow69 * ((fRec57 * fTemp112) * fTemp114))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec53[0] - fRec53[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec52[0] - fRec52[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec50[0] - fRec50[2])) / fSlow5))))))))) + (fTemp103 * (((fRec38 * powf((1.0f - (0.5f * fTemp67)),2.0f)) + (fSlow52 * ((fRec35 * fTemp59) * fTemp61))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec31[0] - fRec31[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec30[0] - fRec30[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec28[0] - fRec28[2])) / fSlow5))))))))) + (fTemp49 * (((fRec11 * powf((1.0f - (0.5f * fTemp11)),2.0f)) + (fSlow34 * ((fRec8 * fTemp3) * fTemp5))) + (6.0f * ((fSlow30 * ((fSlow23 * (fRec4[0] - fRec4[2])) / fSlow27)) + (0.125f * ((fSlow21 * ((fSlow14 * (fRec3[0] - fRec3[2])) / fSlow18)) + (fSlow12 * ((fSlow1 * (fRec1[0] - fRec1[2])) / fSlow5)))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst54 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
			// post processing
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec125[1] = fRec125[0];
			fRec124[1] = fRec124[0];
			fRec127[2] = fRec127[1]; fRec127[1] = fRec127[0];
			fRec129[1] = fRec129[0];
			fRec137[1] = fRec137[0];
			fRec128[1] = fRec128[0];
			iRec136[1] = iRec136[0];
			fRec135[1] = fRec135[0];
			fRec134[1] = fRec134[0];
			fRec133[1] = fRec133[0];
			fRec132[1] = fRec132[0];
			fRec130[1] = fRec130[0];
			fRec131[1] = fRec131[0];
			fRec122[1] = fRec122[0];
			fRec121[1] = fRec121[0];
			fRec120[2] = fRec120[1]; fRec120[1] = fRec120[0];
			fRec119[2] = fRec119[1]; fRec119[1] = fRec119[0];
			fRec118[2] = fRec118[1]; fRec118[1] = fRec118[0];
			fRec116[2] = fRec116[1]; fRec116[1] = fRec116[0];
			fRec117[1] = fRec117[0];
			fRec103[1] = fRec103[0];
			fRec102[1] = fRec102[0];
			fRec105[2] = fRec105[1]; fRec105[1] = fRec105[0];
			fRec107[1] = fRec107[0];
			fRec115[1] = fRec115[0];
			fRec106[1] = fRec106[0];
			iRec114[1] = iRec114[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[1] = fRec108[0];
			fRec109[1] = fRec109[0];
			fRec100[1] = fRec100[0];
			fRec99[1] = fRec99[0];
			fRec98[2] = fRec98[1]; fRec98[1] = fRec98[0];
			fRec97[2] = fRec97[1]; fRec97[1] = fRec97[0];
			fRec96[2] = fRec96[1]; fRec96[1] = fRec96[0];
			fRec94[2] = fRec94[1]; fRec94[1] = fRec94[0];
			fRec95[1] = fRec95[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec85[1] = fRec85[0];
			fRec93[1] = fRec93[0];
			fRec84[1] = fRec84[0];
			iRec92[1] = iRec92[0];
			fRec91[1] = fRec91[0];
			fRec90[1] = fRec90[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fRec86[1] = fRec86[0];
			fRec87[1] = fRec87[0];
			fRec78[1] = fRec78[0];
			fRec77[1] = fRec77[0];
			fRec76[2] = fRec76[1]; fRec76[1] = fRec76[0];
			fRec75[2] = fRec75[1]; fRec75[1] = fRec75[0];
			fRec74[2] = fRec74[1]; fRec74[1] = fRec74[0];
			fRec72[2] = fRec72[1]; fRec72[1] = fRec72[0];
			fRec73[1] = fRec73[0];
			fRec59[1] = fRec59[0];
			fRec58[1] = fRec58[0];
			fRec61[2] = fRec61[1]; fRec61[1] = fRec61[0];
			fRec63[1] = fRec63[0];
			fRec71[1] = fRec71[0];
			fRec62[1] = fRec62[0];
			iRec70[1] = iRec70[0];
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec64[1] = fRec64[0];
			fRec65[1] = fRec65[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fRec54[2] = fRec54[1]; fRec54[1] = fRec54[0];
			fRec53[2] = fRec53[1]; fRec53[1] = fRec53[0];
			fRec52[2] = fRec52[1]; fRec52[1] = fRec52[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec51[1] = fRec51[0];
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec39[2] = fRec39[1]; fRec39[1] = fRec39[0];
			fRec41[1] = fRec41[0];
			fRec49[1] = fRec49[0];
			fRec40[1] = fRec40[0];
			iRec48[1] = iRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec45[1] = fRec45[0];
			fRec44[1] = fRec44[0];
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
			fRec23[1] = fRec23[0];
			fRec13[1] = fRec13[0];
			iRec21[1] = iRec21[0];
			iRec22[1] = iRec22[0];
			fRec20[1] = fRec20[0];
			fRec19[1] = fRec19[0];
			fRec18[1] = fRec18[0];
			fRec17[1] = fRec17[0];
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
float 	mydsp::ftbl1[9];

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
