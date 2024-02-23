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
	class SIG0 {
	  private:
		int fSampleRate;
		int 	iRec13[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec13[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec13[0] = (iRec13[1] + 1);
				float 	fTemp22 = float((iRec13[0] + -1));
				float 	fTemp23 = (0.002004008f * fTemp22);
				output[i] = (((fTemp23 < 0.5f)) ? ((0.008016032f * fTemp22) + -1.0f) : ((4.0f * (1.0f - fTemp23)) + -1.0f));
				// post processing
				iRec13[1] = iRec13[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec15[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec15[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec15[0] = (iRec15[1] + 1);
				output[i] = ((0.004008016f * float((iRec15[0] + -1))) + -1.0f);
				// post processing
				iRec15[1] = iRec15[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec17[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec17[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec17[0] = (iRec17[1] + 1);
				float 	fTemp33 = ((0.002002002f * float((iRec17[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp33)) + -1.0f))) * float(((fTemp33 > 0.0f) - (fTemp33 < 0.0f))));
				// post processing
				iRec17[1] = iRec17[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec26[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec26[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec26[0] = (iRec26[1] + 1);
				int 	iTemp45 = int((1.05f * float((iRec26[0] + -1))));
				output[i] = (((iTemp45 >= 11)) ? (((iTemp45 >= 16)) ? (((iTemp45 >= 19)) ? (((iTemp45 >= 20)) ? 0.0f : 0.01f) : (((iTemp45 >= 18)) ? 0.03f : (((iTemp45 >= 17)) ? 0.06f : 0.08f))) : (((iTemp45 >= 14)) ? (((iTemp45 >= 15)) ? 0.1f : 0.12f) : (((iTemp45 >= 13)) ? 0.14f : (((iTemp45 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp45 >= 6)) ? (((iTemp45 >= 9)) ? (((iTemp45 >= 10)) ? 0.22f : 0.26f) : (((iTemp45 >= 8)) ? 0.3f : (((iTemp45 >= 7)) ? 0.35f : 0.4f))) : (((iTemp45 >= 3)) ? (((iTemp45 >= 5)) ? 0.47f : (((iTemp45 >= 4)) ? 0.55f : 0.64f)) : (((iTemp45 >= 2)) ? 0.74f : (((iTemp45 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec26[1] = iRec26[0];
			}
		}
	};


	int 	iVec0[2];
	float 	fConst0;
	float 	fConst4;
	float 	fConst6;
	float 	fConst8;
	float 	fConst9;
	FAUSTFLOAT 	fslider0;
	int 	iRec1[2];
	float 	fRec2[2];
	float 	fConst10;
	float 	fConst11;
	float 	fConst12;
	float 	fConst13;
	int 	iRec4[2];
	float 	fRec5[2];
	float 	fRec3[3];
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec8[2];
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	float 	fConst18;
	int 	iRec10[2];
	float 	fRec11[2];
	float 	fConst19;
	float 	fRec9[2];
	float 	fRec7[2];
	float 	fConst20;
	float 	fRec0[3];
	static float 	ftbl0[500];
	FAUSTFLOAT 	fslider4;
	float 	fConst21;
	float 	fRec14[2];
	static float 	ftbl1[500];
	float 	fConst22;
	float 	fRec16[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider5;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec3[2];
	int 	iVec4[2];
	int 	iRec22[2];
	int 	iRec21[2];
	float 	fVec5[2];
	float 	fRec23[2];
	float 	fRec24[2];
	int 	iRec19[3];
	static float 	ftbl3[21];
	float 	fConst23;
	float 	fConst24;
	float 	fConst25;
	int 	iVec6[2];
	int 	iRec27[2];
	float 	fRec28[2];
	float 	fRec25[2];
	float 	fRec20[2];
	float 	fConst26;
	float 	fRec18[2];
	float 	fConst27;
	float 	fConst28;
	float 	fConst29;
	float 	fRec29[3];
	float 	fConst30;
	float 	fConst31;
	float 	fRec31[2];
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fConst32;
	float 	fRec30[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec34[2];
	float 	fRec35[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec7[2];
	int 	iVec8[2];
	int 	iRec39[2];
	float 	fVec9[2];
	float 	fRec40[2];
	float 	fRec41[2];
	int 	iRec37[3];
	int 	iVec10[2];
	int 	iRec43[2];
	float 	fRec44[2];
	float 	fRec42[2];
	float 	fRec38[2];
	float 	fRec36[2];
	float 	fRec45[3];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec49[2];
	float 	fRec46[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec50[2];
	float 	fRec51[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec11[2];
	int 	iVec12[2];
	int 	iRec55[2];
	float 	fVec13[2];
	float 	fRec56[2];
	float 	fRec57[2];
	int 	iRec53[3];
	int 	iVec14[2];
	int 	iRec59[2];
	float 	fRec60[2];
	float 	fRec58[2];
	float 	fRec54[2];
	float 	fRec52[2];
	float 	fRec61[3];
	float 	fRec63[2];
	float 	fRec64[2];
	float 	fRec65[2];
	float 	fRec62[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec66[2];
	float 	fRec67[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec15[2];
	int 	iVec16[2];
	int 	iRec71[2];
	float 	fVec17[2];
	float 	fRec72[2];
	float 	fRec73[2];
	int 	iRec69[3];
	int 	iVec18[2];
	int 	iRec75[2];
	float 	fRec76[2];
	float 	fRec74[2];
	float 	fRec70[2];
	float 	fRec68[2];
	float 	fRec77[3];
	float 	fRec79[2];
	float 	fRec80[2];
	float 	fRec81[2];
	float 	fRec78[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec82[2];
	float 	fRec83[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec19[2];
	int 	iVec20[2];
	int 	iRec87[2];
	float 	fVec21[2];
	float 	fRec88[2];
	float 	fRec89[2];
	int 	iRec85[3];
	int 	iVec22[2];
	int 	iRec91[2];
	float 	fRec92[2];
	float 	fRec90[2];
	float 	fRec86[2];
	float 	fRec84[2];
	float 	fRec93[3];
	float 	fRec95[2];
	float 	fRec96[2];
	float 	fRec97[2];
	float 	fRec94[2];
	FAUSTFLOAT 	fslider24;
	float 	fRec98[2];
	float 	fRec99[2];
	FAUSTFLOAT 	fslider25;
	FAUSTFLOAT 	fslider26;
	FAUSTFLOAT 	fslider27;
	float 	fVec23[2];
	int 	iVec24[2];
	int 	iRec103[2];
	float 	fVec25[2];
	float 	fRec104[2];
	float 	fRec105[2];
	int 	iRec101[3];
	int 	iVec26[2];
	int 	iRec107[2];
	float 	fRec108[2];
	float 	fRec106[2];
	float 	fRec102[2];
	float 	fRec100[2];
	float 	fRec109[3];
	float 	fRec111[2];
	float 	fRec112[2];
	float 	fRec113[2];
	float 	fRec110[2];
	float 	fRec12[3];
	float 	fConst33;
	int fSampleRate;

  public:
	virtual void metadata(Meta* m) { 
		m->declare("basics.lib/name", "Faust Basic Element Library");
		m->declare("basics.lib/peakhold:author", "Jonatan Liljedahl, revised by Romain Michon");
		m->declare("basics.lib/peakholder:author", "Dario Sanfilippo");
		m->declare("basics.lib/peakholder:copyright", "Copyright (C) 2022 Dario Sanfilippo <sanfilippo.dario@gmail.com>");
		m->declare("basics.lib/peakholder:license", "MIT-style STK-4.3 license");
		m->declare("basics.lib/tabulate:author", "Stephane Letz");
		m->declare("basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
		m->declare("basics.lib/version", "1.11.1");
		m->declare("envelopes.lib/ar:author", "Yann Orlarey, Stéphane Letz");
		m->declare("envelopes.lib/author", "GRAME");
		m->declare("envelopes.lib/copyright", "GRAME");
		m->declare("envelopes.lib/license", "LGPL with exception");
		m->declare("envelopes.lib/name", "Faust Envelope Library");
		m->declare("envelopes.lib/version", "1.2.0");
		m->declare("fast.lib/author", "Piers Titus van der Torren (pierstitus@toverlamp.org)");
		m->declare("fast.lib/licence", "Apache-2.0");
		m->declare("fast.lib/name", "Faust Fast Approximations Library");
		m->declare("filename", "synth.dsp.tmp");
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
		m->declare("noises.lib/name", "Faust Noise Generator Library");
		m->declare("noises.lib/version", "1.4.0");
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
		SIG0 sig0;
		sig0.init(sample_rate);
		sig0.fill(500,ftbl0);
		SIG1 sig1;
		sig1.init(sample_rate);
		sig1.fill(500,ftbl1);
		SIG2 sig2;
		sig2.init(sample_rate);
		sig2.fill(1000,ftbl2);
		SIG3 sig3;
		sig3.init(sample_rate);
		sig3.fill(21,ftbl3);
	}
	virtual void instanceConstants(int sample_rate) {
		fSampleRate = sample_rate;
		fConst0 = min(1.92e+05f, max(1.0f, float(fSampleRate)));
		float 	fConst1 = powf(fConst0,2.0f);
		float 	fConst2 = powf((125.663704f / fConst0),2.0f);
		float 	fConst3 = ((fConst2 * ((0.2033f * fConst2) + 0.31755f)) + 1.0f);
		fConst4 = (2.0f * ((15791.367f * (powf(fConst3,2.0f) / fConst1)) + -1.0f));
		float 	fConst5 = (15791.367f * (fConst3 / fConst0));
		fConst6 = (((fConst3 * (fConst5 + -95.92649f)) / fConst0) + 1.0f);
		float 	fConst7 = (((fConst3 * (fConst5 + 95.92649f)) / fConst0) + 1.0f);
		fConst8 = (1.0f / fConst7);
		fConst9 = (0.1f * fConst0);
		fConst10 = (3.1415927f / fConst0);
		fConst11 = (9.869604f / fConst0);
		fConst12 = (1.0f / fConst0);
		fConst13 = (9.869604f / fConst1);
		fConst14 = max(1.0f, (0.02f * fConst0));
		fConst15 = (1.0f / fConst14);
		fConst16 = (0.2f * fConst0);
		fConst17 = (1.0f / max(1.0f, fConst16));
		fConst18 = (0.3f * fConst0);
		fConst19 = (1e+02f / fConst0);
		fConst20 = (0.10759955f / fConst0);
		fConst21 = (4.0878997f / fConst0);
		fConst22 = (2.0439498f / fConst0);
		fConst23 = (0.5f * fConst0);
		fConst24 = (0.15f * fConst0);
		fConst25 = (0.8f * fConst0);
		fConst26 = (2e+01f / fConst0);
		fConst27 = (25.68503f / fConst0);
		fConst28 = (659.72076f / fConst1);
		fConst29 = (659.72076f / fConst0);
		fConst30 = (0.2568503f / fConst0);
		fConst31 = (8.175799f / fConst0);
		fConst32 = (3333.3333f / fConst0);
		fConst33 = (0.0f - (2.0f / fConst7));
	}
	virtual void instanceResetUserInterface() {
		fslider0 = 0.0f;
		fslider1 = -1.0f;
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
		fslider24 = 69.0f;
		fslider25 = 0.0f;
		fslider26 = 0.0f;
		fslider27 = 0.0f;
	}
	virtual void instanceClear() {
		for (int i=0; i<2; i++) iVec0[i] = 0;
		for (int i=0; i<2; i++) iRec1[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<2; i++) iRec4[i] = 0;
		for (int i=0; i<2; i++) fRec5[i] = 0;
		for (int i=0; i<3; i++) fRec3[i] = 0;
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec8[i] = 0;
		for (int i=0; i<2; i++) iRec10[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<3; i++) iRec19[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec39[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) iRec37[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec43[i] = 0;
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<3; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec51[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec55[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) iRec53[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec59[i] = 0;
		for (int i=0; i<2; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec58[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec67[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec71[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) iRec69[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec75[i] = 0;
		for (int i=0; i<2; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec74[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<3; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec83[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec87[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) iRec85[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec91[i] = 0;
		for (int i=0; i<2; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec90[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec99[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec103[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<3; i++) iRec101[i] = 0;
		for (int i=0; i<2; i++) iVec26[i] = 0;
		for (int i=0; i<2; i++) iRec107[i] = 0;
		for (int i=0; i<2; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec106[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<3; i++) fRec109[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec113[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<3; i++) fRec12[i] = 0;
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
		synth_interface.acc_x = &fslider3;
		synth_interface.acc_y = &fslider2;
		synth_interface.acc_z = &fslider1;
		synth_interface.rot_z = &fslider0;
		synth_interface.note[0] = &fslider24;
		synth_interface.pres[0] = &fslider26;
		synth_interface.vpres[0] = &fslider27;
		synth_interface.but_y[0] = &fslider25;
		synth_interface.note[1] = &fslider20;
		synth_interface.pres[1] = &fslider22;
		synth_interface.vpres[1] = &fslider23;
		synth_interface.but_y[1] = &fslider21;
		synth_interface.note[2] = &fslider16;
		synth_interface.pres[2] = &fslider18;
		synth_interface.vpres[2] = &fslider19;
		synth_interface.but_y[2] = &fslider17;
		synth_interface.note[3] = &fslider12;
		synth_interface.pres[3] = &fslider14;
		synth_interface.vpres[3] = &fslider15;
		synth_interface.but_y[3] = &fslider13;
		synth_interface.note[4] = &fslider8;
		synth_interface.pres[4] = &fslider10;
		synth_interface.vpres[4] = &fslider11;
		synth_interface.but_y[4] = &fslider9;
		synth_interface.note[5] = &fslider4;
		synth_interface.pres[5] = &fslider6;
		synth_interface.vpres[5] = &fslider7;
		synth_interface.but_y[5] = &fslider5;
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		//zone1
		//zone2
		float 	fSlow0 = fabsf(float(fslider0));
		int 	iSlow1 = (float(fslider2) < (0.0f - float(fslider1)));
		float 	fSlow2 = fabsf(float(fslider3));
		float 	fSlow3 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow4 = (fConst21 * fSlow3);
		float 	fSlow5 = (fConst22 * fSlow3);
		float 	fSlow6 = float(fslider5);
		float 	fSlow7 = ftbl2[int(((499.5f * (fSlow6 + 1.0f)) + 0.5f))];
		float 	fSlow8 = (fSlow7 + 1.0f);
		float 	fSlow9 = float(fslider6);
		float 	fSlow10 = float(fslider7);
		int 	iSlow11 = (fSlow10 == 0.0f);
		float 	fSlow12 = (0.0f - fSlow10);
		float 	fSlow13 = powf((fConst27 * fSlow3),2.0f);
		float 	fSlow14 = ((fSlow13 * ((0.2033f * fSlow13) + 0.31755f)) + 1.0f);
		float 	fSlow15 = (2.0f * ((fConst28 * (powf(fSlow3,2.0f) * powf(fSlow14,2.0f))) + -1.0f));
		float 	fSlow16 = (fSlow3 * fSlow14);
		float 	fSlow17 = (fConst29 * fSlow16);
		float 	fSlow18 = ((fConst12 * (fSlow16 * (fSlow17 + -0.2568503f))) + 1.0f);
		float 	fSlow19 = ((fConst12 * (fSlow16 * (fSlow17 + 0.2568503f))) + 1.0f);
		float 	fSlow20 = (1.0f / fSlow19);
		float 	fSlow21 = max(0.05f, (0.1f - fabsf(fSlow10)));
		float 	fSlow22 = (fConst30 * (fSlow16 / fSlow19));
		float 	fSlow23 = (fConst31 * fSlow3);
		float 	fSlow24 = (0.0f - fSlow6);
		float 	fSlow25 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow26 = (fConst21 * fSlow25);
		float 	fSlow27 = (fConst22 * fSlow25);
		float 	fSlow28 = float(fslider9);
		float 	fSlow29 = ftbl2[int(((499.5f * (fSlow28 + 1.0f)) + 0.5f))];
		float 	fSlow30 = (fSlow29 + 1.0f);
		float 	fSlow31 = float(fslider10);
		float 	fSlow32 = float(fslider11);
		int 	iSlow33 = (fSlow32 == 0.0f);
		float 	fSlow34 = (0.0f - fSlow32);
		float 	fSlow35 = powf((fConst27 * fSlow25),2.0f);
		float 	fSlow36 = ((fSlow35 * ((0.2033f * fSlow35) + 0.31755f)) + 1.0f);
		float 	fSlow37 = (2.0f * ((fConst28 * (powf(fSlow25,2.0f) * powf(fSlow36,2.0f))) + -1.0f));
		float 	fSlow38 = (fSlow25 * fSlow36);
		float 	fSlow39 = (fConst29 * fSlow38);
		float 	fSlow40 = ((fConst12 * (fSlow38 * (fSlow39 + -0.2568503f))) + 1.0f);
		float 	fSlow41 = ((fConst12 * (fSlow38 * (fSlow39 + 0.2568503f))) + 1.0f);
		float 	fSlow42 = (1.0f / fSlow41);
		float 	fSlow43 = max(0.05f, (0.1f - fabsf(fSlow32)));
		float 	fSlow44 = (fConst30 * (fSlow38 / fSlow41));
		float 	fSlow45 = (fConst31 * fSlow25);
		float 	fSlow46 = (0.0f - fSlow28);
		float 	fSlow47 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow48 = (fConst21 * fSlow47);
		float 	fSlow49 = (fConst22 * fSlow47);
		float 	fSlow50 = float(fslider13);
		float 	fSlow51 = ftbl2[int(((499.5f * (fSlow50 + 1.0f)) + 0.5f))];
		float 	fSlow52 = (fSlow51 + 1.0f);
		float 	fSlow53 = float(fslider14);
		float 	fSlow54 = float(fslider15);
		int 	iSlow55 = (fSlow54 == 0.0f);
		float 	fSlow56 = (0.0f - fSlow54);
		float 	fSlow57 = powf((fConst27 * fSlow47),2.0f);
		float 	fSlow58 = ((fSlow57 * ((0.2033f * fSlow57) + 0.31755f)) + 1.0f);
		float 	fSlow59 = (2.0f * ((fConst28 * (powf(fSlow47,2.0f) * powf(fSlow58,2.0f))) + -1.0f));
		float 	fSlow60 = (fSlow47 * fSlow58);
		float 	fSlow61 = (fConst29 * fSlow60);
		float 	fSlow62 = ((fConst12 * (fSlow60 * (fSlow61 + -0.2568503f))) + 1.0f);
		float 	fSlow63 = ((fConst12 * (fSlow60 * (fSlow61 + 0.2568503f))) + 1.0f);
		float 	fSlow64 = (1.0f / fSlow63);
		float 	fSlow65 = max(0.05f, (0.1f - fabsf(fSlow54)));
		float 	fSlow66 = (fConst30 * (fSlow60 / fSlow63));
		float 	fSlow67 = (fConst31 * fSlow47);
		float 	fSlow68 = (0.0f - fSlow50);
		float 	fSlow69 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow70 = (fConst21 * fSlow69);
		float 	fSlow71 = (fConst22 * fSlow69);
		float 	fSlow72 = float(fslider17);
		float 	fSlow73 = ftbl2[int(((499.5f * (fSlow72 + 1.0f)) + 0.5f))];
		float 	fSlow74 = (fSlow73 + 1.0f);
		float 	fSlow75 = float(fslider18);
		float 	fSlow76 = float(fslider19);
		int 	iSlow77 = (fSlow76 == 0.0f);
		float 	fSlow78 = (0.0f - fSlow76);
		float 	fSlow79 = powf((fConst27 * fSlow69),2.0f);
		float 	fSlow80 = ((fSlow79 * ((0.2033f * fSlow79) + 0.31755f)) + 1.0f);
		float 	fSlow81 = (2.0f * ((fConst28 * (powf(fSlow69,2.0f) * powf(fSlow80,2.0f))) + -1.0f));
		float 	fSlow82 = (fSlow69 * fSlow80);
		float 	fSlow83 = (fConst29 * fSlow82);
		float 	fSlow84 = ((fConst12 * (fSlow82 * (fSlow83 + -0.2568503f))) + 1.0f);
		float 	fSlow85 = ((fConst12 * (fSlow82 * (fSlow83 + 0.2568503f))) + 1.0f);
		float 	fSlow86 = (1.0f / fSlow85);
		float 	fSlow87 = max(0.05f, (0.1f - fabsf(fSlow76)));
		float 	fSlow88 = (fConst30 * (fSlow82 / fSlow85));
		float 	fSlow89 = (fConst31 * fSlow69);
		float 	fSlow90 = (0.0f - fSlow72);
		float 	fSlow91 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow92 = (fConst21 * fSlow91);
		float 	fSlow93 = (fConst22 * fSlow91);
		float 	fSlow94 = float(fslider21);
		float 	fSlow95 = ftbl2[int(((499.5f * (fSlow94 + 1.0f)) + 0.5f))];
		float 	fSlow96 = (fSlow95 + 1.0f);
		float 	fSlow97 = float(fslider22);
		float 	fSlow98 = float(fslider23);
		int 	iSlow99 = (fSlow98 == 0.0f);
		float 	fSlow100 = (0.0f - fSlow98);
		float 	fSlow101 = powf((fConst27 * fSlow91),2.0f);
		float 	fSlow102 = ((fSlow101 * ((0.2033f * fSlow101) + 0.31755f)) + 1.0f);
		float 	fSlow103 = (2.0f * ((fConst28 * (powf(fSlow91,2.0f) * powf(fSlow102,2.0f))) + -1.0f));
		float 	fSlow104 = (fSlow91 * fSlow102);
		float 	fSlow105 = (fConst29 * fSlow104);
		float 	fSlow106 = ((fConst12 * (fSlow104 * (fSlow105 + -0.2568503f))) + 1.0f);
		float 	fSlow107 = ((fConst12 * (fSlow104 * (fSlow105 + 0.2568503f))) + 1.0f);
		float 	fSlow108 = (1.0f / fSlow107);
		float 	fSlow109 = max(0.05f, (0.1f - fabsf(fSlow98)));
		float 	fSlow110 = (fConst30 * (fSlow104 / fSlow107));
		float 	fSlow111 = (fConst31 * fSlow91);
		float 	fSlow112 = (0.0f - fSlow94);
		float 	fSlow113 = fastpow2((0.083333336f * float(fslider24)));
		float 	fSlow114 = (fConst21 * fSlow113);
		float 	fSlow115 = (fConst22 * fSlow113);
		float 	fSlow116 = float(fslider25);
		float 	fSlow117 = ftbl2[int(((499.5f * (fSlow116 + 1.0f)) + 0.5f))];
		float 	fSlow118 = (fSlow117 + 1.0f);
		float 	fSlow119 = float(fslider26);
		float 	fSlow120 = float(fslider27);
		int 	iSlow121 = (fSlow120 == 0.0f);
		float 	fSlow122 = (0.0f - fSlow120);
		float 	fSlow123 = powf((fConst27 * fSlow113),2.0f);
		float 	fSlow124 = ((fSlow123 * ((0.2033f * fSlow123) + 0.31755f)) + 1.0f);
		float 	fSlow125 = (2.0f * ((fConst28 * (powf(fSlow113,2.0f) * powf(fSlow124,2.0f))) + -1.0f));
		float 	fSlow126 = (fSlow113 * fSlow124);
		float 	fSlow127 = (fConst29 * fSlow126);
		float 	fSlow128 = ((fConst12 * (fSlow126 * (fSlow127 + -0.2568503f))) + 1.0f);
		float 	fSlow129 = ((fConst12 * (fSlow126 * (fSlow127 + 0.2568503f))) + 1.0f);
		float 	fSlow130 = (1.0f / fSlow129);
		float 	fSlow131 = max(0.05f, (0.1f - fabsf(fSlow120)));
		float 	fSlow132 = (fConst30 * (fSlow126 / fSlow129));
		float 	fSlow133 = (fConst31 * fSlow113);
		float 	fSlow134 = (0.0f - fSlow116);
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
			int 	iTemp0 = ((fSlow0 >= fRec2[1]) | (float(iRec1[1]) >= fConst9));
			iRec1[0] = ((iTemp0) ? 0 : (iRec1[1] + 1));
			fRec2[0] = ((iTemp0) ? fSlow0 : fRec2[1]);
			float 	fTemp1 = ((1e+03f * fRec2[0]) + 6e+01f);
			float 	fTemp2 = powf((fConst10 * fTemp1),2.0f);
			float 	fTemp3 = ((fTemp2 * ((0.2033f * fTemp2) + 0.31755f)) + 1.0f);
			float 	fTemp4 = (fTemp1 * fTemp3);
			float 	fTemp5 = (fConst11 * fTemp4);
			float 	fTemp6 = ((fConst12 * (fTemp4 * (fTemp5 + 0.07853982f))) + 1.0f);
			iRec4[0] = ((1103515245 * iRec4[1]) + 12345);
			float 	fTemp7 = float(iRec4[0]);
			float 	fTemp8 = max(1.1920929e-07f, fabsf(fTemp1));
			float 	fTemp9 = (fRec5[1] + (fConst12 * fTemp8));
			float 	fTemp10 = (fTemp9 + -1.0f);
			int 	iTemp11 = (fTemp10 < 0.0f);
			fRec5[0] = ((iTemp11) ? fTemp9 : fTemp10);
			float 	fRec6 = ((iTemp11) ? fTemp9 : (fTemp9 + (fTemp10 * (1.0f - (fConst0 / fTemp8)))));
			fRec3[0] = (((0.8f * ((2.0f * fRec6) + -1.0f)) + (9.313226e-11f * fTemp7)) - (((((fConst12 * (fTemp4 * (fTemp5 + -0.07853982f))) + 1.0f) * fRec3[2]) + (2.0f * (((fConst13 * (powf(fTemp1,2.0f) * powf(fTemp3,2.0f))) + -1.0f) * fRec3[1]))) / fTemp6));
			fVec1[0] = fSlow2;
			float 	fTemp12 = (fSlow2 - fVec1[1]);
			int 	iTemp13 = ((fTemp12 > 0.04f) & iSlow1);
			iVec2[0] = iTemp13;
			iRec8[0] = (((iRec8[1] + (iRec8[1] > 0)) * (iVec2[0] <= iVec2[1])) + (iVec2[0] > iVec2[1]));
			float 	fTemp14 = float(iRec8[0]);
			float 	fTemp15 = fabsf(fTemp12);
			int 	iTemp16 = ((fTemp15 >= fRec11[1]) | (float(iRec10[1]) >= fConst18));
			iRec10[0] = ((iTemp16) ? 0 : (iRec10[1] + 1));
			fRec11[0] = ((iTemp16) ? fTemp15 : fRec11[1]);
			float 	fTemp17 = (fRec9[1] - fConst19);
			float 	fTemp18 = (fConst19 + fRec9[1]);
			fRec9[0] = (((fTemp18 < fRec11[0])) ? fTemp18 : (((fTemp17 > fRec11[0])) ? fTemp17 : fRec11[0]));
			float 	fTemp19 = (fRec9[0] * max(0.0f, min((fConst15 * fTemp14), ((fConst17 * (fConst14 - fTemp14)) + 1.0f))));
			float 	fTemp20 = (fRec7[1] - fConst19);
			float 	fTemp21 = (fConst19 + fRec7[1]);
			fRec7[0] = (((fTemp21 < fTemp19)) ? fTemp21 : (((fTemp20 > fTemp19)) ? fTemp20 : fTemp19));
			fRec0[0] = ((fConst20 * ((((fRec7[0] * fTemp1) * fTemp3) * (fRec3[0] - fRec3[2])) / fTemp6)) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			int 	iTemp24 = (1 - iVec0[1]);
			float 	fTemp25 = ((iTemp24) ? 0.0f : (fSlow4 + fRec14[1]));
			fRec14[0] = (fTemp25 - floorf(fTemp25));
			float 	fTemp26 = (499.0f * fRec14[0]);
			int 	iTemp27 = int(fTemp26);
			float 	fTemp28 = ftbl0[max(0, min(iTemp27, 499))];
			float 	fTemp29 = ((iTemp24) ? 0.0f : (fSlow5 + fRec16[1]));
			fRec16[0] = (fTemp29 - floorf(fTemp29));
			float 	fTemp30 = (499.0f * fRec16[0]);
			int 	iTemp31 = int(fTemp30);
			float 	fTemp32 = ftbl1[max(0, min(iTemp31, 499))];
			fVec3[0] = fSlow10;
			int 	iTemp34 = (fSlow10 != fVec3[1]);
			iVec4[0] = iTemp34;
			int 	iTemp35 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec22[0] = (iRec22[1] + 1);
			int 	iTemp36 = (iRec22[0] + -1);
			iRec21[0] = ((iRec21[1] * (1 - iTemp35)) + (iTemp36 * iTemp35));
			float 	fTemp37 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec21[0])))) > 0.5f) & iSlow11)) ? 0.0f : fSlow9) + 1.0f)) + 0.5f))];
			fVec5[0] = fTemp37;
			int 	iTemp38 = (fVec5[0] > 0.003f);
			int 	iTemp39 = (fVec5[0] <= 0.003f);
			float 	fTemp40 = float((iTemp39 | (fVec5[1] >= 0.003f)));
			fRec23[0] = max((fRec23[1] * fTemp40), fSlow10);
			fRec24[0] = max((fTemp40 * fRec24[1]), fSlow12);
			float 	fTemp41 = (min(1.0f, fRec24[0]) + min(1.0f, (0.7f * fRec23[0])));
			int 	iTemp42 = (fVec5[0] >= fRec20[1]);
			int 	iTemp43 = (fRec20[1] <= 0.001f);
			int 	iTemp44 = (((iRec19[1] >= 4)) ? (((iRec19[1] >= 6)) ? ((iTemp43) ? 0 : ((iTemp38) ? 1 : 6)) : (((iRec19[1] >= 5)) ? ((iTemp39) ? 3 : ((iTemp42) ? 4 : 5)) : ((iTemp39) ? 3 : (((fVec5[0] <= fRec20[1])) ? 5 : 4)))) : (((iRec19[1] >= 2)) ? (((iRec19[1] >= 3)) ? (((iTemp39 & iTemp43)) ? 0 : ((iTemp38) ? 1 : 3)) : ((iTemp38) ? ((iTemp42) ? 4 : 2) : 6)) : (((iRec19[1] >= 1)) ? (((fRec20[1] >= min(fTemp41, 1.0f))) ? ((iTemp39) ? 6 : 2) : 1) : ((iTemp38) ? 1 : 0))));
			iRec19[0] = iTemp44;
			float 	fTemp46 = (((iTemp44 >= 4)) ? (((iTemp44 >= 6)) ? fConst25 : fConst16) : (((iTemp44 >= 2)) ? (((iTemp44 >= 3)) ? fConst24 : fConst23) : (((iTemp44 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp47 = (iRec19[1] != iRec19[2]);
			iVec6[0] = iTemp47;
			int 	iTemp48 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec27[0] = ((iRec27[1] * (1 - iTemp48)) + (iTemp36 * iTemp48));
			float 	fTemp49 = (2e+01f * (((fTemp46 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec27[0]))) / fTemp46) : 0.0f));
			int 	iTemp50 = int(fTemp49);
			float 	fTemp51 = ftbl3[max(0, int(min(int(iTemp50), 20)))];
			float 	fTemp52 = (fTemp51 + ((fTemp49 - float(iTemp50)) * (ftbl3[max(0, int(min(int((iTemp50 + 1)), 20)))] - fTemp51)));
			fRec28[0] = max((fRec28[1] * float(iVec6[0])), max(fVec5[0], fRec20[1]));
			int 	iTemp53 = (iRec19[1] == 3);
			int 	iTemp54 = (iRec19[1] == 6);
			int 	iTemp55 = (iRec19[1] == 0);
			float 	fTemp56 = (((iRec19[1] == 1)) ? min(1.0f, fTemp41) : ((iTemp55) ? 0.0f : ((iTemp54) ? (fTemp41 * fTemp52) : ((iTemp53) ? (fRec28[0] * fTemp52) : fVec5[0]))));
			float 	fTemp57 = (1.0f / ((iTemp55) ? 0.0001f : (((iTemp53 | iTemp54)) ? (0.04761905f * fTemp46) : fTemp46)));
			float 	fTemp58 = (fRec25[1] - fTemp57);
			float 	fTemp59 = (fRec25[1] + fTemp57);
			fRec25[0] = (((fTemp59 < fTemp56)) ? fTemp59 : (((fTemp58 > fTemp56)) ? fTemp58 : fTemp56));
			fRec20[0] = fRec25[0];
			float 	fTemp60 = (fRec18[1] - fConst26);
			float 	fTemp61 = (fConst26 + fRec18[1]);
			fRec18[0] = (((fTemp61 < fRec20[0])) ? fTemp61 : (((fTemp60 > fRec20[0])) ? fTemp60 : fRec20[0]));
			int 	iTemp62 = (fRec18[0] < 0.1f);
			float 	fTemp63 = (((iTemp62) ? fRec18[0] : 0.1f) * fSlow8);
			float 	fTemp64 = (4.656613e-10f * fTemp7);
			fRec29[0] = (fTemp64 - (fSlow20 * ((fSlow18 * fRec29[2]) + (fSlow15 * fRec29[1]))));
			float 	fTemp65 = min(1.0f, (fSlow21 + ((iTemp62) ? (1.0f - (1e+01f * fRec18[0])) : 0.0f)));
			float 	fTemp66 = ((iTemp24) ? 0.0f : (fSlow23 + fRec31[1]));
			fRec31[0] = (fTemp66 - floorf(fTemp66));
			float 	fTemp67 = (499.0f * fRec31[0]);
			int 	iTemp68 = int(fTemp67);
			int 	iTemp69 = max(0, min(iTemp68, 499));
			float 	fTemp70 = ftbl1[iTemp69];
			int 	iTemp71 = max(0, min((iTemp68 + 1), 499));
			float 	fTemp72 = (fTemp67 - float(iTemp68));
			float 	fTemp73 = float((((fVec5[1] <= 0.003f) & iTemp38) != 1));
			fRec32[0] = max((fTemp73 * fRec32[1]), fSlow24);
			fRec33[0] = max((fRec33[1] * fTemp73), fSlow6);
			float 	fTemp74 = max(min(((0.5f * (fVec5[0] - fRec18[0])) + (0.2f - (0.8f * ((iTemp39) ? (2.0f * (((fRec33[0] > fRec32[0])) ? fRec33[0] : (0.0f - fRec32[0]))) : fSlow7)))), 1.0f), 0.0f);
			float 	fTemp75 = ftbl0[iTemp69];
			float 	fTemp76 = (((fTemp75 + (fTemp72 * (ftbl0[iTemp71] - fTemp75))) * (1.0f - fTemp74)) + (fTemp74 * (fTemp70 + (fTemp72 * (ftbl1[iTemp71] - fTemp70)))));
			float 	fTemp77 = (fRec30[1] - fConst32);
			float 	fTemp78 = (fConst32 + fRec30[1]);
			fRec30[0] = (((fTemp78 < fTemp76)) ? fTemp78 : (((fTemp77 > fTemp76)) ? fTemp77 : fTemp76));
			float 	fTemp79 = ((iTemp24) ? 0.0f : (fSlow26 + fRec34[1]));
			fRec34[0] = (fTemp79 - floorf(fTemp79));
			float 	fTemp80 = (499.0f * fRec34[0]);
			int 	iTemp81 = int(fTemp80);
			float 	fTemp82 = ftbl0[max(0, min(iTemp81, 499))];
			float 	fTemp83 = ((iTemp24) ? 0.0f : (fSlow27 + fRec35[1]));
			fRec35[0] = (fTemp83 - floorf(fTemp83));
			float 	fTemp84 = (499.0f * fRec35[0]);
			int 	iTemp85 = int(fTemp84);
			float 	fTemp86 = ftbl1[max(0, min(iTemp85, 499))];
			fVec7[0] = fSlow32;
			int 	iTemp87 = (fSlow32 != fVec7[1]);
			iVec8[0] = iTemp87;
			int 	iTemp88 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec39[0] = ((iRec39[1] * (1 - iTemp88)) + (iTemp36 * iTemp88));
			float 	fTemp89 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec39[0])))) > 0.5f) & iSlow33)) ? 0.0f : fSlow31) + 1.0f)) + 0.5f))];
			fVec9[0] = fTemp89;
			int 	iTemp90 = (fVec9[0] > 0.003f);
			int 	iTemp91 = (fVec9[0] <= 0.003f);
			float 	fTemp92 = float((iTemp91 | (fVec9[1] >= 0.003f)));
			fRec40[0] = max((fRec40[1] * fTemp92), fSlow32);
			fRec41[0] = max((fTemp92 * fRec41[1]), fSlow34);
			float 	fTemp93 = (min(1.0f, fRec41[0]) + min(1.0f, (0.7f * fRec40[0])));
			int 	iTemp94 = (fVec9[0] >= fRec38[1]);
			int 	iTemp95 = (fRec38[1] <= 0.001f);
			int 	iTemp96 = (((iRec37[1] >= 4)) ? (((iRec37[1] >= 6)) ? ((iTemp95) ? 0 : ((iTemp90) ? 1 : 6)) : (((iRec37[1] >= 5)) ? ((iTemp91) ? 3 : ((iTemp94) ? 4 : 5)) : ((iTemp91) ? 3 : (((fVec9[0] <= fRec38[1])) ? 5 : 4)))) : (((iRec37[1] >= 2)) ? (((iRec37[1] >= 3)) ? (((iTemp91 & iTemp95)) ? 0 : ((iTemp90) ? 1 : 3)) : ((iTemp90) ? ((iTemp94) ? 4 : 2) : 6)) : (((iRec37[1] >= 1)) ? (((fRec38[1] >= min(fTemp93, 1.0f))) ? ((iTemp91) ? 6 : 2) : 1) : ((iTemp90) ? 1 : 0))));
			iRec37[0] = iTemp96;
			float 	fTemp97 = (((iTemp96 >= 4)) ? (((iTemp96 >= 6)) ? fConst25 : fConst16) : (((iTemp96 >= 2)) ? (((iTemp96 >= 3)) ? fConst24 : fConst23) : (((iTemp96 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp98 = (iRec37[1] != iRec37[2]);
			iVec10[0] = iTemp98;
			int 	iTemp99 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec43[0] = ((iRec43[1] * (1 - iTemp99)) + (iTemp36 * iTemp99));
			float 	fTemp100 = (2e+01f * (((fTemp97 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec43[0]))) / fTemp97) : 0.0f));
			int 	iTemp101 = int(fTemp100);
			float 	fTemp102 = ftbl3[max(0, int(min(int(iTemp101), 20)))];
			float 	fTemp103 = (fTemp102 + ((fTemp100 - float(iTemp101)) * (ftbl3[max(0, int(min(int((iTemp101 + 1)), 20)))] - fTemp102)));
			fRec44[0] = max((fRec44[1] * float(iVec10[0])), max(fVec9[0], fRec38[1]));
			int 	iTemp104 = (iRec37[1] == 3);
			int 	iTemp105 = (iRec37[1] == 6);
			int 	iTemp106 = (iRec37[1] == 0);
			float 	fTemp107 = (((iRec37[1] == 1)) ? min(1.0f, fTemp93) : ((iTemp106) ? 0.0f : ((iTemp105) ? (fTemp93 * fTemp103) : ((iTemp104) ? (fRec44[0] * fTemp103) : fVec9[0]))));
			float 	fTemp108 = (1.0f / ((iTemp106) ? 0.0001f : (((iTemp104 | iTemp105)) ? (0.04761905f * fTemp97) : fTemp97)));
			float 	fTemp109 = (fRec42[1] - fTemp108);
			float 	fTemp110 = (fRec42[1] + fTemp108);
			fRec42[0] = (((fTemp110 < fTemp107)) ? fTemp110 : (((fTemp109 > fTemp107)) ? fTemp109 : fTemp107));
			fRec38[0] = fRec42[0];
			float 	fTemp111 = (fRec36[1] - fConst26);
			float 	fTemp112 = (fConst26 + fRec36[1]);
			fRec36[0] = (((fTemp112 < fRec38[0])) ? fTemp112 : (((fTemp111 > fRec38[0])) ? fTemp111 : fRec38[0]));
			int 	iTemp113 = (fRec36[0] < 0.1f);
			float 	fTemp114 = (((iTemp113) ? fRec36[0] : 0.1f) * fSlow30);
			fRec45[0] = (fTemp64 - (fSlow42 * ((fSlow40 * fRec45[2]) + (fSlow37 * fRec45[1]))));
			float 	fTemp115 = min(1.0f, (fSlow43 + ((iTemp113) ? (1.0f - (1e+01f * fRec36[0])) : 0.0f)));
			float 	fTemp116 = ((iTemp24) ? 0.0f : (fSlow45 + fRec47[1]));
			fRec47[0] = (fTemp116 - floorf(fTemp116));
			float 	fTemp117 = (499.0f * fRec47[0]);
			int 	iTemp118 = int(fTemp117);
			int 	iTemp119 = max(0, min(iTemp118, 499));
			float 	fTemp120 = ftbl1[iTemp119];
			int 	iTemp121 = max(0, min((iTemp118 + 1), 499));
			float 	fTemp122 = (fTemp117 - float(iTemp118));
			float 	fTemp123 = float((((fVec9[1] <= 0.003f) & iTemp90) != 1));
			fRec48[0] = max((fTemp123 * fRec48[1]), fSlow46);
			fRec49[0] = max((fRec49[1] * fTemp123), fSlow28);
			float 	fTemp124 = max(min(((0.5f * (fVec9[0] - fRec36[0])) + (0.2f - (0.8f * ((iTemp91) ? (2.0f * (((fRec49[0] > fRec48[0])) ? fRec49[0] : (0.0f - fRec48[0]))) : fSlow29)))), 1.0f), 0.0f);
			float 	fTemp125 = ftbl0[iTemp119];
			float 	fTemp126 = (((fTemp125 + (fTemp122 * (ftbl0[iTemp121] - fTemp125))) * (1.0f - fTemp124)) + (fTemp124 * (fTemp120 + (fTemp122 * (ftbl1[iTemp121] - fTemp120)))));
			float 	fTemp127 = (fRec46[1] - fConst32);
			float 	fTemp128 = (fConst32 + fRec46[1]);
			fRec46[0] = (((fTemp128 < fTemp126)) ? fTemp128 : (((fTemp127 > fTemp126)) ? fTemp127 : fTemp126));
			float 	fTemp129 = ((iTemp24) ? 0.0f : (fSlow48 + fRec50[1]));
			fRec50[0] = (fTemp129 - floorf(fTemp129));
			float 	fTemp130 = (499.0f * fRec50[0]);
			int 	iTemp131 = int(fTemp130);
			float 	fTemp132 = ftbl0[max(0, min(iTemp131, 499))];
			float 	fTemp133 = ((iTemp24) ? 0.0f : (fSlow49 + fRec51[1]));
			fRec51[0] = (fTemp133 - floorf(fTemp133));
			float 	fTemp134 = (499.0f * fRec51[0]);
			int 	iTemp135 = int(fTemp134);
			float 	fTemp136 = ftbl1[max(0, min(iTemp135, 499))];
			fVec11[0] = fSlow54;
			int 	iTemp137 = (fSlow54 != fVec11[1]);
			iVec12[0] = iTemp137;
			int 	iTemp138 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec55[0] = ((iRec55[1] * (1 - iTemp138)) + (iTemp36 * iTemp138));
			float 	fTemp139 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec55[0])))) > 0.5f) & iSlow55)) ? 0.0f : fSlow53) + 1.0f)) + 0.5f))];
			fVec13[0] = fTemp139;
			int 	iTemp140 = (fVec13[0] > 0.003f);
			int 	iTemp141 = (fVec13[0] <= 0.003f);
			float 	fTemp142 = float((iTemp141 | (fVec13[1] >= 0.003f)));
			fRec56[0] = max((fRec56[1] * fTemp142), fSlow54);
			fRec57[0] = max((fTemp142 * fRec57[1]), fSlow56);
			float 	fTemp143 = (min(1.0f, fRec57[0]) + min(1.0f, (0.7f * fRec56[0])));
			int 	iTemp144 = (fVec13[0] >= fRec54[1]);
			int 	iTemp145 = (fRec54[1] <= 0.001f);
			int 	iTemp146 = (((iRec53[1] >= 4)) ? (((iRec53[1] >= 6)) ? ((iTemp145) ? 0 : ((iTemp140) ? 1 : 6)) : (((iRec53[1] >= 5)) ? ((iTemp141) ? 3 : ((iTemp144) ? 4 : 5)) : ((iTemp141) ? 3 : (((fVec13[0] <= fRec54[1])) ? 5 : 4)))) : (((iRec53[1] >= 2)) ? (((iRec53[1] >= 3)) ? (((iTemp141 & iTemp145)) ? 0 : ((iTemp140) ? 1 : 3)) : ((iTemp140) ? ((iTemp144) ? 4 : 2) : 6)) : (((iRec53[1] >= 1)) ? (((fRec54[1] >= min(fTemp143, 1.0f))) ? ((iTemp141) ? 6 : 2) : 1) : ((iTemp140) ? 1 : 0))));
			iRec53[0] = iTemp146;
			float 	fTemp147 = (((iTemp146 >= 4)) ? (((iTemp146 >= 6)) ? fConst25 : fConst16) : (((iTemp146 >= 2)) ? (((iTemp146 >= 3)) ? fConst24 : fConst23) : (((iTemp146 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp148 = (iRec53[1] != iRec53[2]);
			iVec14[0] = iTemp148;
			int 	iTemp149 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec59[0] = ((iRec59[1] * (1 - iTemp149)) + (iTemp36 * iTemp149));
			float 	fTemp150 = (2e+01f * (((fTemp147 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec59[0]))) / fTemp147) : 0.0f));
			int 	iTemp151 = int(fTemp150);
			float 	fTemp152 = ftbl3[max(0, int(min(int(iTemp151), 20)))];
			float 	fTemp153 = (fTemp152 + ((fTemp150 - float(iTemp151)) * (ftbl3[max(0, int(min(int((iTemp151 + 1)), 20)))] - fTemp152)));
			fRec60[0] = max((fRec60[1] * float(iVec14[0])), max(fVec13[0], fRec54[1]));
			int 	iTemp154 = (iRec53[1] == 3);
			int 	iTemp155 = (iRec53[1] == 6);
			int 	iTemp156 = (iRec53[1] == 0);
			float 	fTemp157 = (((iRec53[1] == 1)) ? min(1.0f, fTemp143) : ((iTemp156) ? 0.0f : ((iTemp155) ? (fTemp143 * fTemp153) : ((iTemp154) ? (fRec60[0] * fTemp153) : fVec13[0]))));
			float 	fTemp158 = (1.0f / ((iTemp156) ? 0.0001f : (((iTemp154 | iTemp155)) ? (0.04761905f * fTemp147) : fTemp147)));
			float 	fTemp159 = (fRec58[1] - fTemp158);
			float 	fTemp160 = (fRec58[1] + fTemp158);
			fRec58[0] = (((fTemp160 < fTemp157)) ? fTemp160 : (((fTemp159 > fTemp157)) ? fTemp159 : fTemp157));
			fRec54[0] = fRec58[0];
			float 	fTemp161 = (fRec52[1] - fConst26);
			float 	fTemp162 = (fConst26 + fRec52[1]);
			fRec52[0] = (((fTemp162 < fRec54[0])) ? fTemp162 : (((fTemp161 > fRec54[0])) ? fTemp161 : fRec54[0]));
			int 	iTemp163 = (fRec52[0] < 0.1f);
			float 	fTemp164 = (((iTemp163) ? fRec52[0] : 0.1f) * fSlow52);
			fRec61[0] = (fTemp64 - (fSlow64 * ((fSlow62 * fRec61[2]) + (fSlow59 * fRec61[1]))));
			float 	fTemp165 = min(1.0f, (fSlow65 + ((iTemp163) ? (1.0f - (1e+01f * fRec52[0])) : 0.0f)));
			float 	fTemp166 = ((iTemp24) ? 0.0f : (fSlow67 + fRec63[1]));
			fRec63[0] = (fTemp166 - floorf(fTemp166));
			float 	fTemp167 = (499.0f * fRec63[0]);
			int 	iTemp168 = int(fTemp167);
			int 	iTemp169 = max(0, min(iTemp168, 499));
			float 	fTemp170 = ftbl1[iTemp169];
			int 	iTemp171 = max(0, min((iTemp168 + 1), 499));
			float 	fTemp172 = (fTemp167 - float(iTemp168));
			float 	fTemp173 = float((((fVec13[1] <= 0.003f) & iTemp140) != 1));
			fRec64[0] = max((fTemp173 * fRec64[1]), fSlow68);
			fRec65[0] = max((fRec65[1] * fTemp173), fSlow50);
			float 	fTemp174 = max(min(((0.5f * (fVec13[0] - fRec52[0])) + (0.2f - (0.8f * ((iTemp141) ? (2.0f * (((fRec65[0] > fRec64[0])) ? fRec65[0] : (0.0f - fRec64[0]))) : fSlow51)))), 1.0f), 0.0f);
			float 	fTemp175 = ftbl0[iTemp169];
			float 	fTemp176 = (((fTemp175 + (fTemp172 * (ftbl0[iTemp171] - fTemp175))) * (1.0f - fTemp174)) + (fTemp174 * (fTemp170 + (fTemp172 * (ftbl1[iTemp171] - fTemp170)))));
			float 	fTemp177 = (fRec62[1] - fConst32);
			float 	fTemp178 = (fConst32 + fRec62[1]);
			fRec62[0] = (((fTemp178 < fTemp176)) ? fTemp178 : (((fTemp177 > fTemp176)) ? fTemp177 : fTemp176));
			float 	fTemp179 = ((iTemp24) ? 0.0f : (fSlow70 + fRec66[1]));
			fRec66[0] = (fTemp179 - floorf(fTemp179));
			float 	fTemp180 = (499.0f * fRec66[0]);
			int 	iTemp181 = int(fTemp180);
			float 	fTemp182 = ftbl0[max(0, min(iTemp181, 499))];
			float 	fTemp183 = ((iTemp24) ? 0.0f : (fSlow71 + fRec67[1]));
			fRec67[0] = (fTemp183 - floorf(fTemp183));
			float 	fTemp184 = (499.0f * fRec67[0]);
			int 	iTemp185 = int(fTemp184);
			float 	fTemp186 = ftbl1[max(0, min(iTemp185, 499))];
			fVec15[0] = fSlow76;
			int 	iTemp187 = (fSlow76 != fVec15[1]);
			iVec16[0] = iTemp187;
			int 	iTemp188 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec71[0] = ((iRec71[1] * (1 - iTemp188)) + (iTemp36 * iTemp188));
			float 	fTemp189 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec71[0])))) > 0.5f) & iSlow77)) ? 0.0f : fSlow75) + 1.0f)) + 0.5f))];
			fVec17[0] = fTemp189;
			int 	iTemp190 = (fVec17[0] > 0.003f);
			int 	iTemp191 = (fVec17[0] <= 0.003f);
			float 	fTemp192 = float((iTemp191 | (fVec17[1] >= 0.003f)));
			fRec72[0] = max((fRec72[1] * fTemp192), fSlow76);
			fRec73[0] = max((fTemp192 * fRec73[1]), fSlow78);
			float 	fTemp193 = (min(1.0f, fRec73[0]) + min(1.0f, (0.7f * fRec72[0])));
			int 	iTemp194 = (fVec17[0] >= fRec70[1]);
			int 	iTemp195 = (fRec70[1] <= 0.001f);
			int 	iTemp196 = (((iRec69[1] >= 4)) ? (((iRec69[1] >= 6)) ? ((iTemp195) ? 0 : ((iTemp190) ? 1 : 6)) : (((iRec69[1] >= 5)) ? ((iTemp191) ? 3 : ((iTemp194) ? 4 : 5)) : ((iTemp191) ? 3 : (((fVec17[0] <= fRec70[1])) ? 5 : 4)))) : (((iRec69[1] >= 2)) ? (((iRec69[1] >= 3)) ? (((iTemp191 & iTemp195)) ? 0 : ((iTemp190) ? 1 : 3)) : ((iTemp190) ? ((iTemp194) ? 4 : 2) : 6)) : (((iRec69[1] >= 1)) ? (((fRec70[1] >= min(fTemp193, 1.0f))) ? ((iTemp191) ? 6 : 2) : 1) : ((iTemp190) ? 1 : 0))));
			iRec69[0] = iTemp196;
			float 	fTemp197 = (((iTemp196 >= 4)) ? (((iTemp196 >= 6)) ? fConst25 : fConst16) : (((iTemp196 >= 2)) ? (((iTemp196 >= 3)) ? fConst24 : fConst23) : (((iTemp196 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp198 = (iRec69[1] != iRec69[2]);
			iVec18[0] = iTemp198;
			int 	iTemp199 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec75[0] = ((iRec75[1] * (1 - iTemp199)) + (iTemp36 * iTemp199));
			float 	fTemp200 = (2e+01f * (((fTemp197 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec75[0]))) / fTemp197) : 0.0f));
			int 	iTemp201 = int(fTemp200);
			float 	fTemp202 = ftbl3[max(0, int(min(int(iTemp201), 20)))];
			float 	fTemp203 = (fTemp202 + ((fTemp200 - float(iTemp201)) * (ftbl3[max(0, int(min(int((iTemp201 + 1)), 20)))] - fTemp202)));
			fRec76[0] = max((fRec76[1] * float(iVec18[0])), max(fVec17[0], fRec70[1]));
			int 	iTemp204 = (iRec69[1] == 3);
			int 	iTemp205 = (iRec69[1] == 6);
			int 	iTemp206 = (iRec69[1] == 0);
			float 	fTemp207 = (((iRec69[1] == 1)) ? min(1.0f, fTemp193) : ((iTemp206) ? 0.0f : ((iTemp205) ? (fTemp193 * fTemp203) : ((iTemp204) ? (fRec76[0] * fTemp203) : fVec17[0]))));
			float 	fTemp208 = (1.0f / ((iTemp206) ? 0.0001f : (((iTemp204 | iTemp205)) ? (0.04761905f * fTemp197) : fTemp197)));
			float 	fTemp209 = (fRec74[1] - fTemp208);
			float 	fTemp210 = (fRec74[1] + fTemp208);
			fRec74[0] = (((fTemp210 < fTemp207)) ? fTemp210 : (((fTemp209 > fTemp207)) ? fTemp209 : fTemp207));
			fRec70[0] = fRec74[0];
			float 	fTemp211 = (fRec68[1] - fConst26);
			float 	fTemp212 = (fConst26 + fRec68[1]);
			fRec68[0] = (((fTemp212 < fRec70[0])) ? fTemp212 : (((fTemp211 > fRec70[0])) ? fTemp211 : fRec70[0]));
			int 	iTemp213 = (fRec68[0] < 0.1f);
			float 	fTemp214 = (((iTemp213) ? fRec68[0] : 0.1f) * fSlow74);
			fRec77[0] = (fTemp64 - (fSlow86 * ((fSlow84 * fRec77[2]) + (fSlow81 * fRec77[1]))));
			float 	fTemp215 = min(1.0f, (fSlow87 + ((iTemp213) ? (1.0f - (1e+01f * fRec68[0])) : 0.0f)));
			float 	fTemp216 = ((iTemp24) ? 0.0f : (fSlow89 + fRec79[1]));
			fRec79[0] = (fTemp216 - floorf(fTemp216));
			float 	fTemp217 = (499.0f * fRec79[0]);
			int 	iTemp218 = int(fTemp217);
			int 	iTemp219 = max(0, min(iTemp218, 499));
			float 	fTemp220 = ftbl1[iTemp219];
			int 	iTemp221 = max(0, min((iTemp218 + 1), 499));
			float 	fTemp222 = (fTemp217 - float(iTemp218));
			float 	fTemp223 = float((((fVec17[1] <= 0.003f) & iTemp190) != 1));
			fRec80[0] = max((fTemp223 * fRec80[1]), fSlow90);
			fRec81[0] = max((fRec81[1] * fTemp223), fSlow72);
			float 	fTemp224 = max(min(((0.5f * (fVec17[0] - fRec68[0])) + (0.2f - (0.8f * ((iTemp191) ? (2.0f * (((fRec81[0] > fRec80[0])) ? fRec81[0] : (0.0f - fRec80[0]))) : fSlow73)))), 1.0f), 0.0f);
			float 	fTemp225 = ftbl0[iTemp219];
			float 	fTemp226 = (((fTemp225 + (fTemp222 * (ftbl0[iTemp221] - fTemp225))) * (1.0f - fTemp224)) + (fTemp224 * (fTemp220 + (fTemp222 * (ftbl1[iTemp221] - fTemp220)))));
			float 	fTemp227 = (fRec78[1] - fConst32);
			float 	fTemp228 = (fConst32 + fRec78[1]);
			fRec78[0] = (((fTemp228 < fTemp226)) ? fTemp228 : (((fTemp227 > fTemp226)) ? fTemp227 : fTemp226));
			float 	fTemp229 = ((iTemp24) ? 0.0f : (fSlow92 + fRec82[1]));
			fRec82[0] = (fTemp229 - floorf(fTemp229));
			float 	fTemp230 = (499.0f * fRec82[0]);
			int 	iTemp231 = int(fTemp230);
			float 	fTemp232 = ftbl0[max(0, min(iTemp231, 499))];
			float 	fTemp233 = ((iTemp24) ? 0.0f : (fSlow93 + fRec83[1]));
			fRec83[0] = (fTemp233 - floorf(fTemp233));
			float 	fTemp234 = (499.0f * fRec83[0]);
			int 	iTemp235 = int(fTemp234);
			float 	fTemp236 = ftbl1[max(0, min(iTemp235, 499))];
			fVec19[0] = fSlow98;
			int 	iTemp237 = (fSlow98 != fVec19[1]);
			iVec20[0] = iTemp237;
			int 	iTemp238 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec87[0] = ((iRec87[1] * (1 - iTemp238)) + (iTemp36 * iTemp238));
			float 	fTemp239 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec87[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec21[0] = fTemp239;
			int 	iTemp240 = (fVec21[0] > 0.003f);
			int 	iTemp241 = (fVec21[0] <= 0.003f);
			float 	fTemp242 = float((iTemp241 | (fVec21[1] >= 0.003f)));
			fRec88[0] = max((fRec88[1] * fTemp242), fSlow98);
			fRec89[0] = max((fTemp242 * fRec89[1]), fSlow100);
			float 	fTemp243 = (min(1.0f, fRec89[0]) + min(1.0f, (0.7f * fRec88[0])));
			int 	iTemp244 = (fVec21[0] >= fRec86[1]);
			int 	iTemp245 = (fRec86[1] <= 0.001f);
			int 	iTemp246 = (((iRec85[1] >= 4)) ? (((iRec85[1] >= 6)) ? ((iTemp245) ? 0 : ((iTemp240) ? 1 : 6)) : (((iRec85[1] >= 5)) ? ((iTemp241) ? 3 : ((iTemp244) ? 4 : 5)) : ((iTemp241) ? 3 : (((fVec21[0] <= fRec86[1])) ? 5 : 4)))) : (((iRec85[1] >= 2)) ? (((iRec85[1] >= 3)) ? (((iTemp241 & iTemp245)) ? 0 : ((iTemp240) ? 1 : 3)) : ((iTemp240) ? ((iTemp244) ? 4 : 2) : 6)) : (((iRec85[1] >= 1)) ? (((fRec86[1] >= min(fTemp243, 1.0f))) ? ((iTemp241) ? 6 : 2) : 1) : ((iTemp240) ? 1 : 0))));
			iRec85[0] = iTemp246;
			float 	fTemp247 = (((iTemp246 >= 4)) ? (((iTemp246 >= 6)) ? fConst25 : fConst16) : (((iTemp246 >= 2)) ? (((iTemp246 >= 3)) ? fConst24 : fConst23) : (((iTemp246 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp248 = (iRec85[1] != iRec85[2]);
			iVec22[0] = iTemp248;
			int 	iTemp249 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec91[0] = ((iRec91[1] * (1 - iTemp249)) + (iTemp36 * iTemp249));
			float 	fTemp250 = (2e+01f * (((fTemp247 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec91[0]))) / fTemp247) : 0.0f));
			int 	iTemp251 = int(fTemp250);
			float 	fTemp252 = ftbl3[max(0, int(min(int(iTemp251), 20)))];
			float 	fTemp253 = (fTemp252 + ((fTemp250 - float(iTemp251)) * (ftbl3[max(0, int(min(int((iTemp251 + 1)), 20)))] - fTemp252)));
			fRec92[0] = max((fRec92[1] * float(iVec22[0])), max(fVec21[0], fRec86[1]));
			int 	iTemp254 = (iRec85[1] == 3);
			int 	iTemp255 = (iRec85[1] == 6);
			int 	iTemp256 = (iRec85[1] == 0);
			float 	fTemp257 = (((iRec85[1] == 1)) ? min(1.0f, fTemp243) : ((iTemp256) ? 0.0f : ((iTemp255) ? (fTemp243 * fTemp253) : ((iTemp254) ? (fRec92[0] * fTemp253) : fVec21[0]))));
			float 	fTemp258 = (1.0f / ((iTemp256) ? 0.0001f : (((iTemp254 | iTemp255)) ? (0.04761905f * fTemp247) : fTemp247)));
			float 	fTemp259 = (fRec90[1] - fTemp258);
			float 	fTemp260 = (fRec90[1] + fTemp258);
			fRec90[0] = (((fTemp260 < fTemp257)) ? fTemp260 : (((fTemp259 > fTemp257)) ? fTemp259 : fTemp257));
			fRec86[0] = fRec90[0];
			float 	fTemp261 = (fRec84[1] - fConst26);
			float 	fTemp262 = (fConst26 + fRec84[1]);
			fRec84[0] = (((fTemp262 < fRec86[0])) ? fTemp262 : (((fTemp261 > fRec86[0])) ? fTemp261 : fRec86[0]));
			int 	iTemp263 = (fRec84[0] < 0.1f);
			float 	fTemp264 = (((iTemp263) ? fRec84[0] : 0.1f) * fSlow96);
			fRec93[0] = (fTemp64 - (fSlow108 * ((fSlow106 * fRec93[2]) + (fSlow103 * fRec93[1]))));
			float 	fTemp265 = min(1.0f, (fSlow109 + ((iTemp263) ? (1.0f - (1e+01f * fRec84[0])) : 0.0f)));
			float 	fTemp266 = ((iTemp24) ? 0.0f : (fSlow111 + fRec95[1]));
			fRec95[0] = (fTemp266 - floorf(fTemp266));
			float 	fTemp267 = (499.0f * fRec95[0]);
			int 	iTemp268 = int(fTemp267);
			int 	iTemp269 = max(0, min(iTemp268, 499));
			float 	fTemp270 = ftbl1[iTemp269];
			int 	iTemp271 = max(0, min((iTemp268 + 1), 499));
			float 	fTemp272 = (fTemp267 - float(iTemp268));
			float 	fTemp273 = float((((fVec21[1] <= 0.003f) & iTemp240) != 1));
			fRec96[0] = max((fTemp273 * fRec96[1]), fSlow112);
			fRec97[0] = max((fRec97[1] * fTemp273), fSlow94);
			float 	fTemp274 = max(min(((0.5f * (fVec21[0] - fRec84[0])) + (0.2f - (0.8f * ((iTemp241) ? (2.0f * (((fRec97[0] > fRec96[0])) ? fRec97[0] : (0.0f - fRec96[0]))) : fSlow95)))), 1.0f), 0.0f);
			float 	fTemp275 = ftbl0[iTemp269];
			float 	fTemp276 = (((fTemp275 + (fTemp272 * (ftbl0[iTemp271] - fTemp275))) * (1.0f - fTemp274)) + (fTemp274 * (fTemp270 + (fTemp272 * (ftbl1[iTemp271] - fTemp270)))));
			float 	fTemp277 = (fRec94[1] - fConst32);
			float 	fTemp278 = (fConst32 + fRec94[1]);
			fRec94[0] = (((fTemp278 < fTemp276)) ? fTemp278 : (((fTemp277 > fTemp276)) ? fTemp277 : fTemp276));
			float 	fTemp279 = ((iTemp24) ? 0.0f : (fSlow114 + fRec98[1]));
			fRec98[0] = (fTemp279 - floorf(fTemp279));
			float 	fTemp280 = (499.0f * fRec98[0]);
			int 	iTemp281 = int(fTemp280);
			float 	fTemp282 = ftbl0[max(0, min(iTemp281, 499))];
			float 	fTemp283 = ((iTemp24) ? 0.0f : (fSlow115 + fRec99[1]));
			fRec99[0] = (fTemp283 - floorf(fTemp283));
			float 	fTemp284 = (499.0f * fRec99[0]);
			int 	iTemp285 = int(fTemp284);
			float 	fTemp286 = ftbl1[max(0, min(iTemp285, 499))];
			fVec23[0] = fSlow120;
			int 	iTemp287 = (fSlow120 != fVec23[1]);
			iVec24[0] = iTemp287;
			int 	iTemp288 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec103[0] = ((iRec103[1] * (1 - iTemp288)) + (iTemp36 * iTemp288));
			float 	fTemp289 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec103[0])))) > 0.5f) & iSlow121)) ? 0.0f : fSlow119) + 1.0f)) + 0.5f))];
			fVec25[0] = fTemp289;
			int 	iTemp290 = (fVec25[0] > 0.003f);
			int 	iTemp291 = (fVec25[0] <= 0.003f);
			float 	fTemp292 = float((iTemp291 | (fVec25[1] >= 0.003f)));
			fRec104[0] = max((fRec104[1] * fTemp292), fSlow120);
			fRec105[0] = max((fTemp292 * fRec105[1]), fSlow122);
			float 	fTemp293 = (min(1.0f, fRec105[0]) + min(1.0f, (0.7f * fRec104[0])));
			int 	iTemp294 = (fVec25[0] >= fRec102[1]);
			int 	iTemp295 = (fRec102[1] <= 0.001f);
			int 	iTemp296 = (((iRec101[1] >= 4)) ? (((iRec101[1] >= 6)) ? ((iTemp295) ? 0 : ((iTemp290) ? 1 : 6)) : (((iRec101[1] >= 5)) ? ((iTemp291) ? 3 : ((iTemp294) ? 4 : 5)) : ((iTemp291) ? 3 : (((fVec25[0] <= fRec102[1])) ? 5 : 4)))) : (((iRec101[1] >= 2)) ? (((iRec101[1] >= 3)) ? (((iTemp291 & iTemp295)) ? 0 : ((iTemp290) ? 1 : 3)) : ((iTemp290) ? ((iTemp294) ? 4 : 2) : 6)) : (((iRec101[1] >= 1)) ? (((fRec102[1] >= min(fTemp293, 1.0f))) ? ((iTemp291) ? 6 : 2) : 1) : ((iTemp290) ? 1 : 0))));
			iRec101[0] = iTemp296;
			float 	fTemp297 = (((iTemp296 >= 4)) ? (((iTemp296 >= 6)) ? fConst25 : fConst16) : (((iTemp296 >= 2)) ? (((iTemp296 >= 3)) ? fConst24 : fConst23) : (((iTemp296 >= 1)) ? fConst16 : 0.0f)));
			int 	iTemp298 = (iRec101[1] != iRec101[2]);
			iVec26[0] = iTemp298;
			int 	iTemp299 = ((iVec26[1] <= 0) & (iVec26[0] > 0));
			iRec107[0] = ((iRec107[1] * (1 - iTemp299)) + (iTemp36 * iTemp299));
			float 	fTemp300 = (2e+01f * (((fTemp297 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec107[0]))) / fTemp297) : 0.0f));
			int 	iTemp301 = int(fTemp300);
			float 	fTemp302 = ftbl3[max(0, int(min(int(iTemp301), 20)))];
			float 	fTemp303 = (fTemp302 + ((fTemp300 - float(iTemp301)) * (ftbl3[max(0, int(min(int((iTemp301 + 1)), 20)))] - fTemp302)));
			fRec108[0] = max((fRec108[1] * float(iVec26[0])), max(fVec25[0], fRec102[1]));
			int 	iTemp304 = (iRec101[1] == 3);
			int 	iTemp305 = (iRec101[1] == 6);
			int 	iTemp306 = (iRec101[1] == 0);
			float 	fTemp307 = (((iRec101[1] == 1)) ? min(1.0f, fTemp293) : ((iTemp306) ? 0.0f : ((iTemp305) ? (fTemp293 * fTemp303) : ((iTemp304) ? (fRec108[0] * fTemp303) : fVec25[0]))));
			float 	fTemp308 = (1.0f / ((iTemp306) ? 0.0001f : (((iTemp304 | iTemp305)) ? (0.04761905f * fTemp297) : fTemp297)));
			float 	fTemp309 = (fRec106[1] - fTemp308);
			float 	fTemp310 = (fRec106[1] + fTemp308);
			fRec106[0] = (((fTemp310 < fTemp307)) ? fTemp310 : (((fTemp309 > fTemp307)) ? fTemp309 : fTemp307));
			fRec102[0] = fRec106[0];
			float 	fTemp311 = (fRec100[1] - fConst26);
			float 	fTemp312 = (fConst26 + fRec100[1]);
			fRec100[0] = (((fTemp312 < fRec102[0])) ? fTemp312 : (((fTemp311 > fRec102[0])) ? fTemp311 : fRec102[0]));
			int 	iTemp313 = (fRec100[0] < 0.1f);
			float 	fTemp314 = (((iTemp313) ? fRec100[0] : 0.1f) * fSlow118);
			fRec109[0] = (fTemp64 - (fSlow130 * ((fSlow128 * fRec109[2]) + (fSlow125 * fRec109[1]))));
			float 	fTemp315 = min(1.0f, (fSlow131 + ((iTemp313) ? (1.0f - (1e+01f * fRec100[0])) : 0.0f)));
			float 	fTemp316 = ((iTemp24) ? 0.0f : (fSlow133 + fRec111[1]));
			fRec111[0] = (fTemp316 - floorf(fTemp316));
			float 	fTemp317 = (499.0f * fRec111[0]);
			int 	iTemp318 = int(fTemp317);
			int 	iTemp319 = max(0, min(iTemp318, 499));
			float 	fTemp320 = ftbl1[iTemp319];
			int 	iTemp321 = max(0, min((iTemp318 + 1), 499));
			float 	fTemp322 = (fTemp317 - float(iTemp318));
			float 	fTemp323 = float((((fVec25[1] <= 0.003f) & iTemp290) != 1));
			fRec112[0] = max((fTemp323 * fRec112[1]), fSlow134);
			fRec113[0] = max((fRec113[1] * fTemp323), fSlow116);
			float 	fTemp324 = max(min(((0.5f * (fVec25[0] - fRec100[0])) + (0.2f - (0.8f * ((iTemp291) ? (2.0f * (((fRec113[0] > fRec112[0])) ? fRec113[0] : (0.0f - fRec112[0]))) : fSlow117)))), 1.0f), 0.0f);
			float 	fTemp325 = ftbl0[iTemp319];
			float 	fTemp326 = (((fTemp325 + (fTemp322 * (ftbl0[iTemp321] - fTemp325))) * (1.0f - fTemp324)) + (fTemp324 * (fTemp320 + (fTemp322 * (ftbl1[iTemp321] - fTemp320)))));
			float 	fTemp327 = (fRec110[1] - fConst32);
			float 	fTemp328 = (fConst32 + fRec110[1]);
			fRec110[0] = (((fTemp328 < fTemp326)) ? fTemp328 : (((fTemp327 > fTemp326)) ? fTemp327 : fTemp326));
			fRec12[0] = ((1.37f * ((((((fRec100[0] * ((((1.1f * (fRec110[0] * (1.0f - fTemp315))) + (fSlow132 * (fTemp315 * (fRec109[0] - fRec109[2])))) * (1.0f - (0.5f * fTemp314))) + (0.5f * (fTemp314 * ((0.2f * (fTemp286 + ((fTemp284 - float(iTemp285)) * (ftbl1[max(0, min((iTemp285 + 1), 499))] - fTemp286)))) + (0.8f * (fTemp282 + ((fTemp280 - float(iTemp281)) * (ftbl0[max(0, min((iTemp281 + 1), 499))] - fTemp282))))))))) + (fRec84[0] * ((((1.1f * (fRec94[0] * (1.0f - fTemp265))) + (fSlow110 * (fTemp265 * (fRec93[0] - fRec93[2])))) * (1.0f - (0.5f * fTemp264))) + (0.5f * (fTemp264 * ((0.2f * (fTemp236 + ((fTemp234 - float(iTemp235)) * (ftbl1[max(0, min((iTemp235 + 1), 499))] - fTemp236)))) + (0.8f * (fTemp232 + ((fTemp230 - float(iTemp231)) * (ftbl0[max(0, min((iTemp231 + 1), 499))] - fTemp232)))))))))) + (fRec68[0] * ((((1.1f * (fRec78[0] * (1.0f - fTemp215))) + (fSlow88 * (fTemp215 * (fRec77[0] - fRec77[2])))) * (1.0f - (0.5f * fTemp214))) + (0.5f * (fTemp214 * ((0.2f * (fTemp186 + ((fTemp184 - float(iTemp185)) * (ftbl1[max(0, min((iTemp185 + 1), 499))] - fTemp186)))) + (0.8f * (fTemp182 + ((fTemp180 - float(iTemp181)) * (ftbl0[max(0, min((iTemp181 + 1), 499))] - fTemp182)))))))))) + (fRec52[0] * ((((1.1f * (fRec62[0] * (1.0f - fTemp165))) + (fSlow66 * (fTemp165 * (fRec61[0] - fRec61[2])))) * (1.0f - (0.5f * fTemp164))) + (0.5f * (fTemp164 * ((0.2f * (fTemp136 + ((fTemp134 - float(iTemp135)) * (ftbl1[max(0, min((iTemp135 + 1), 499))] - fTemp136)))) + (0.8f * (fTemp132 + ((fTemp130 - float(iTemp131)) * (ftbl0[max(0, min((iTemp131 + 1), 499))] - fTemp132)))))))))) + (fRec36[0] * ((((1.1f * (fRec46[0] * (1.0f - fTemp115))) + (fSlow44 * (fTemp115 * (fRec45[0] - fRec45[2])))) * (1.0f - (0.5f * fTemp114))) + (0.5f * (fTemp114 * ((0.2f * (fTemp86 + ((fTemp84 - float(iTemp85)) * (ftbl1[max(0, min((iTemp85 + 1), 499))] - fTemp86)))) + (0.8f * (fTemp82 + ((fTemp80 - float(iTemp81)) * (ftbl0[max(0, min((iTemp81 + 1), 499))] - fTemp82)))))))))) + (fRec18[0] * ((((1.1f * (fRec30[0] * (1.0f - fTemp65))) + (fSlow22 * (fTemp65 * (fRec29[0] - fRec29[2])))) * (1.0f - (0.5f * fTemp63))) + (0.5f * (fTemp63 * ((0.2f * (fTemp32 + ((fTemp30 - float(iTemp31)) * (ftbl1[max(0, min((iTemp31 + 1), 499))] - fTemp32)))) + (0.8f * (fTemp28 + ((fTemp26 - float(iTemp27)) * (ftbl0[max(0, min((iTemp27 + 1), 499))] - fTemp28))))))))))) - (fConst8 * ((fConst6 * fRec12[2]) + (fConst4 * fRec12[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst33 * (fRec12[1] + fRec0[1])) + (fConst8 * ((fRec12[0] + fRec12[2]) + (fRec0[0] + fRec0[2])))));
			// post processing
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec110[1] = fRec110[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec109[2] = fRec109[1]; fRec109[1] = fRec109[0];
			fRec100[1] = fRec100[0];
			fRec102[1] = fRec102[0];
			fRec106[1] = fRec106[0];
			fRec108[1] = fRec108[0];
			iRec107[1] = iRec107[0];
			iVec26[1] = iVec26[0];
			iRec101[2] = iRec101[1]; iRec101[1] = iRec101[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fVec25[1] = fVec25[0];
			iRec103[1] = iRec103[0];
			iVec24[1] = iVec24[0];
			fVec23[1] = fVec23[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec94[1] = fRec94[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[2] = fRec93[1]; fRec93[1] = fRec93[0];
			fRec84[1] = fRec84[0];
			fRec86[1] = fRec86[0];
			fRec90[1] = fRec90[0];
			fRec92[1] = fRec92[0];
			iRec91[1] = iRec91[0];
			iVec22[1] = iVec22[0];
			iRec85[2] = iRec85[1]; iRec85[1] = iRec85[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fVec21[1] = fVec21[0];
			iRec87[1] = iRec87[0];
			iVec20[1] = iVec20[0];
			fVec19[1] = fVec19[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fRec78[1] = fRec78[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec77[2] = fRec77[1]; fRec77[1] = fRec77[0];
			fRec68[1] = fRec68[0];
			fRec70[1] = fRec70[0];
			fRec74[1] = fRec74[0];
			fRec76[1] = fRec76[0];
			iRec75[1] = iRec75[0];
			iVec18[1] = iVec18[0];
			iRec69[2] = iRec69[1]; iRec69[1] = iRec69[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fVec17[1] = fVec17[0];
			iRec71[1] = iRec71[0];
			iVec16[1] = iVec16[0];
			fVec15[1] = fVec15[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec62[1] = fRec62[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec61[2] = fRec61[1]; fRec61[1] = fRec61[0];
			fRec52[1] = fRec52[0];
			fRec54[1] = fRec54[0];
			fRec58[1] = fRec58[0];
			fRec60[1] = fRec60[0];
			iRec59[1] = iRec59[0];
			iVec14[1] = iVec14[0];
			iRec53[2] = iRec53[1]; iRec53[1] = iRec53[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fVec13[1] = fVec13[0];
			iRec55[1] = iRec55[0];
			iVec12[1] = iVec12[0];
			fVec11[1] = fVec11[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec46[1] = fRec46[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
			fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			iRec43[1] = iRec43[0];
			iVec10[1] = iVec10[0];
			iRec37[2] = iRec37[1]; iRec37[1] = iRec37[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fVec9[1] = fVec9[0];
			iRec39[1] = iRec39[0];
			iVec8[1] = iVec8[0];
			fVec7[1] = fVec7[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec30[1] = fRec30[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec28[1] = fRec28[0];
			iRec27[1] = iRec27[0];
			iVec6[1] = iVec6[0];
			iRec19[2] = iRec19[1]; iRec19[1] = iRec19[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
			fVec5[1] = fVec5[0];
			iRec21[1] = iRec21[0];
			iRec22[1] = iRec22[0];
			iVec4[1] = iVec4[0];
			fVec3[1] = fVec3[0];
			fRec16[1] = fRec16[0];
			fRec14[1] = fRec14[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec7[1] = fRec7[0];
			fRec9[1] = fRec9[0];
			fRec11[1] = fRec11[0];
			iRec10[1] = iRec10[0];
			iRec8[1] = iRec8[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
			fRec3[2] = fRec3[1]; fRec3[1] = fRec3[0];
			fRec5[1] = fRec5[0];
			iRec4[1] = iRec4[0];
			fRec2[1] = fRec2[0];
			iRec1[1] = iRec1[0];
			iVec0[1] = iVec0[0];
		}
	}
};


float 	mydsp::ftbl0[500];
float 	mydsp::ftbl1[500];
float 	mydsp::ftbl2[1000];
float 	mydsp::ftbl3[21];

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
