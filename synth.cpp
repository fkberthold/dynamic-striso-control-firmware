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
		int 	iRec12[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec12[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec12[0] = (iRec12[1] + 1);
				float 	fTemp19 = float((iRec12[0] + -1));
				float 	fTemp20 = (0.002004008f * fTemp19);
				output[i] = (((fTemp20 < 0.5f)) ? ((0.008016032f * fTemp19) + -1.0f) : ((4.0f * (1.0f - fTemp20)) + -1.0f));
				// post processing
				iRec12[1] = iRec12[0];
			}
		}
	};


	class SIG1 {
	  private:
		int fSampleRate;
		int 	iRec14[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec14[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec14[0] = (iRec14[1] + 1);
				output[i] = ((0.004008016f * float((iRec14[0] + -1))) + -1.0f);
				// post processing
				iRec14[1] = iRec14[0];
			}
		}
	};


	class SIG2 {
	  private:
		int fSampleRate;
		int 	iRec16[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec16[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec16[0] = (iRec16[1] + 1);
				float 	fTemp30 = ((0.002002002f * float((iRec16[0] + -1))) + -1.0f);
				output[i] = ((0.0f - (0.5f * (cosf((3.1415927f * fTemp30)) + -1.0f))) * float(((fTemp30 > 0.0f) - (fTemp30 < 0.0f))));
				// post processing
				iRec16[1] = iRec16[0];
			}
		}
	};


	class SIG3 {
	  private:
		int fSampleRate;
		int 	iRec25[2];
	  public:
		int getNumInputs() { return 0; }
		int getNumOutputs() { return 1; }
		void init(int sample_rate) {
			fSampleRate = sample_rate;
			for (int i=0; i<2; i++) iRec25[i] = 0;
		}
		void fill(int count, float output[]) {
			for (int i=0; i<count; i++) {
				iRec25[0] = (iRec25[1] + 1);
				int 	iTemp42 = int((1.05f * float((iRec25[0] + -1))));
				output[i] = (((iTemp42 >= 11)) ? (((iTemp42 >= 16)) ? (((iTemp42 >= 19)) ? (((iTemp42 >= 20)) ? 0.0f : 0.01f) : (((iTemp42 >= 18)) ? 0.03f : (((iTemp42 >= 17)) ? 0.06f : 0.08f))) : (((iTemp42 >= 14)) ? (((iTemp42 >= 15)) ? 0.1f : 0.12f) : (((iTemp42 >= 13)) ? 0.14f : (((iTemp42 >= 12)) ? 0.16f : 0.19f)))) : (((iTemp42 >= 6)) ? (((iTemp42 >= 9)) ? (((iTemp42 >= 10)) ? 0.22f : 0.26f) : (((iTemp42 >= 8)) ? 0.3f : (((iTemp42 >= 7)) ? 0.35f : 0.4f))) : (((iTemp42 >= 3)) ? (((iTemp42 >= 5)) ? 0.47f : (((iTemp42 >= 4)) ? 0.55f : 0.64f)) : (((iTemp42 >= 2)) ? 0.74f : (((iTemp42 >= 1)) ? 0.86f : 1.0f)))));
				// post processing
				iRec25[1] = iRec25[0];
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
	FAUSTFLOAT 	fslider1;
	FAUSTFLOAT 	fslider2;
	FAUSTFLOAT 	fslider3;
	float 	fVec1[2];
	int 	iVec2[2];
	int 	iRec3[2];
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	float 	fConst16;
	float 	fConst17;
	int 	iRec5[2];
	float 	fRec6[2];
	float 	fRec4[3];
	float 	fConst18;
	int 	iRec9[2];
	float 	fRec10[2];
	float 	fConst19;
	float 	fRec8[2];
	float 	fConst20;
	float 	fRec0[3];
	static float 	ftbl0[500];
	FAUSTFLOAT 	fslider4;
	float 	fConst21;
	float 	fRec13[2];
	static float 	ftbl1[500];
	float 	fConst22;
	float 	fRec15[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider5;
	float 	fConst26;
	float 	fConst28;
	float 	fConst30;
	FAUSTFLOAT 	fslider6;
	FAUSTFLOAT 	fslider7;
	float 	fVec3[2];
	int 	iVec4[2];
	int 	iRec21[2];
	int 	iRec20[2];
	float 	fVec5[2];
	float 	fRec22[2];
	float 	fRec23[2];
	int 	iRec18[3];
	static float 	ftbl3[21];
	float 	fConst31;
	float 	fConst32;
	float 	fConst33;
	int 	iVec6[2];
	int 	iRec26[2];
	float 	fRec27[2];
	float 	fRec24[2];
	float 	fRec19[2];
	float 	fRec17[3];
	float 	fConst34;
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fRec28[3];
	float 	fConst38;
	float 	fConst39;
	float 	fRec30[2];
	float 	fRec31[2];
	float 	fRec32[2];
	float 	fConst40;
	float 	fRec29[2];
	FAUSTFLOAT 	fslider8;
	float 	fRec33[2];
	float 	fRec34[2];
	FAUSTFLOAT 	fslider9;
	FAUSTFLOAT 	fslider10;
	FAUSTFLOAT 	fslider11;
	float 	fVec7[2];
	int 	iVec8[2];
	int 	iRec38[2];
	float 	fVec9[2];
	float 	fRec39[2];
	float 	fRec40[2];
	int 	iRec36[3];
	int 	iVec10[2];
	int 	iRec42[2];
	float 	fRec43[2];
	float 	fRec41[2];
	float 	fRec37[2];
	float 	fRec35[3];
	float 	fRec44[3];
	float 	fRec46[2];
	float 	fRec47[2];
	float 	fRec48[2];
	float 	fRec45[2];
	FAUSTFLOAT 	fslider12;
	float 	fRec49[2];
	float 	fRec50[2];
	FAUSTFLOAT 	fslider13;
	FAUSTFLOAT 	fslider14;
	FAUSTFLOAT 	fslider15;
	float 	fVec11[2];
	int 	iVec12[2];
	int 	iRec54[2];
	float 	fVec13[2];
	float 	fRec55[2];
	float 	fRec56[2];
	int 	iRec52[3];
	int 	iVec14[2];
	int 	iRec58[2];
	float 	fRec59[2];
	float 	fRec57[2];
	float 	fRec53[2];
	float 	fRec51[3];
	float 	fRec60[3];
	float 	fRec62[2];
	float 	fRec63[2];
	float 	fRec64[2];
	float 	fRec61[2];
	FAUSTFLOAT 	fslider16;
	float 	fRec65[2];
	float 	fRec66[2];
	FAUSTFLOAT 	fslider17;
	FAUSTFLOAT 	fslider18;
	FAUSTFLOAT 	fslider19;
	float 	fVec15[2];
	int 	iVec16[2];
	int 	iRec70[2];
	float 	fVec17[2];
	float 	fRec71[2];
	float 	fRec72[2];
	int 	iRec68[3];
	int 	iVec18[2];
	int 	iRec74[2];
	float 	fRec75[2];
	float 	fRec73[2];
	float 	fRec69[2];
	float 	fRec67[3];
	float 	fRec76[3];
	float 	fRec78[2];
	float 	fRec79[2];
	float 	fRec80[2];
	float 	fRec77[2];
	FAUSTFLOAT 	fslider20;
	float 	fRec81[2];
	float 	fRec82[2];
	FAUSTFLOAT 	fslider21;
	FAUSTFLOAT 	fslider22;
	FAUSTFLOAT 	fslider23;
	float 	fVec19[2];
	int 	iVec20[2];
	int 	iRec86[2];
	float 	fVec21[2];
	float 	fRec87[2];
	float 	fRec88[2];
	int 	iRec84[3];
	int 	iVec22[2];
	int 	iRec90[2];
	float 	fRec91[2];
	float 	fRec89[2];
	float 	fRec85[2];
	float 	fRec83[3];
	float 	fRec92[3];
	float 	fRec94[2];
	float 	fRec95[2];
	float 	fRec96[2];
	float 	fRec93[2];
	FAUSTFLOAT 	fslider24;
	float 	fRec97[2];
	float 	fRec98[2];
	FAUSTFLOAT 	fslider25;
	FAUSTFLOAT 	fslider26;
	FAUSTFLOAT 	fslider27;
	float 	fVec23[2];
	int 	iVec24[2];
	int 	iRec102[2];
	float 	fVec25[2];
	float 	fRec103[2];
	float 	fRec104[2];
	int 	iRec100[3];
	int 	iVec26[2];
	int 	iRec106[2];
	float 	fRec107[2];
	float 	fRec105[2];
	float 	fRec101[2];
	float 	fRec99[3];
	float 	fRec108[3];
	float 	fRec110[2];
	float 	fRec111[2];
	float 	fRec112[2];
	float 	fRec109[2];
	float 	fRec11[3];
	float 	fConst41;
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
		fConst13 = max(1.0f, (0.02f * fConst0));
		fConst14 = (1.0f / fConst13);
		fConst15 = (0.2f * fConst0);
		fConst16 = (1.0f / max(1.0f, fConst15));
		fConst17 = (9.869604f / fConst1);
		fConst18 = (0.3f * fConst0);
		fConst19 = (1e+02f / fConst0);
		fConst20 = (0.10759955f / fConst0);
		fConst21 = (4.0878997f / fConst0);
		fConst22 = (2.0439498f / fConst0);
		float 	fConst23 = powf((62.831852f / fConst0),2.0f);
		float 	fConst24 = ((fConst23 * ((0.2033f * fConst23) + 0.31755f)) + 1.0f);
		float 	fConst25 = powf(fConst24,2.0f);
		fConst26 = (2.0f * ((3947.8418f * (fConst25 / fConst1)) + -1.0f));
		float 	fConst27 = (3947.8418f * (fConst24 / fConst0));
		fConst28 = (((fConst24 * (fConst27 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst29 = (((fConst24 * (fConst27 + 88.49557f)) / fConst0) + 1.0f);
		fConst30 = (1.0f / fConst29);
		fConst31 = (0.4f * fConst0);
		fConst32 = (0.15f * fConst0);
		fConst33 = (0.75f * fConst0);
		fConst34 = (fConst25 / (fConst1 * fConst29));
		fConst35 = (25.68503f / fConst0);
		fConst36 = (659.72076f / fConst1);
		fConst37 = (659.72076f / fConst0);
		fConst38 = (0.2568503f / fConst0);
		fConst39 = (8.175799f / fConst0);
		fConst40 = (3333.3333f / fConst0);
		fConst41 = (0.0f - (2.0f / fConst7));
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
		for (int i=0; i<2; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) iVec2[i] = 0;
		for (int i=0; i<2; i++) iRec3[i] = 0;
		for (int i=0; i<2; i++) iRec5[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<3; i++) fRec4[i] = 0;
		for (int i=0; i<2; i++) iRec9[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<3; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) iRec20[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<3; i++) iRec18[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec26[i] = 0;
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<3; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fVec7[i] = 0;
		for (int i=0; i<2; i++) iVec8[i] = 0;
		for (int i=0; i<2; i++) iRec38[i] = 0;
		for (int i=0; i<2; i++) fVec9[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<3; i++) iRec36[i] = 0;
		for (int i=0; i<2; i++) iVec10[i] = 0;
		for (int i=0; i<2; i++) iRec42[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<3; i++) fRec35[i] = 0;
		for (int i=0; i<3; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fVec11[i] = 0;
		for (int i=0; i<2; i++) iVec12[i] = 0;
		for (int i=0; i<2; i++) iRec54[i] = 0;
		for (int i=0; i<2; i++) fVec13[i] = 0;
		for (int i=0; i<2; i++) fRec55[i] = 0;
		for (int i=0; i<2; i++) fRec56[i] = 0;
		for (int i=0; i<3; i++) iRec52[i] = 0;
		for (int i=0; i<2; i++) iVec14[i] = 0;
		for (int i=0; i<2; i++) iRec58[i] = 0;
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<3; i++) fRec51[i] = 0;
		for (int i=0; i<3; i++) fRec60[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fVec15[i] = 0;
		for (int i=0; i<2; i++) iVec16[i] = 0;
		for (int i=0; i<2; i++) iRec70[i] = 0;
		for (int i=0; i<2; i++) fVec17[i] = 0;
		for (int i=0; i<2; i++) fRec71[i] = 0;
		for (int i=0; i<2; i++) fRec72[i] = 0;
		for (int i=0; i<3; i++) iRec68[i] = 0;
		for (int i=0; i<2; i++) iVec18[i] = 0;
		for (int i=0; i<2; i++) iRec74[i] = 0;
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<3; i++) fRec67[i] = 0;
		for (int i=0; i<3; i++) fRec76[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fVec19[i] = 0;
		for (int i=0; i<2; i++) iVec20[i] = 0;
		for (int i=0; i<2; i++) iRec86[i] = 0;
		for (int i=0; i<2; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec87[i] = 0;
		for (int i=0; i<2; i++) fRec88[i] = 0;
		for (int i=0; i<3; i++) iRec84[i] = 0;
		for (int i=0; i<2; i++) iVec22[i] = 0;
		for (int i=0; i<2; i++) iRec90[i] = 0;
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<3; i++) fRec83[i] = 0;
		for (int i=0; i<3; i++) fRec92[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) iVec24[i] = 0;
		for (int i=0; i<2; i++) iRec102[i] = 0;
		for (int i=0; i<2; i++) fVec25[i] = 0;
		for (int i=0; i<2; i++) fRec103[i] = 0;
		for (int i=0; i<2; i++) fRec104[i] = 0;
		for (int i=0; i<3; i++) iRec100[i] = 0;
		for (int i=0; i<2; i++) iVec26[i] = 0;
		for (int i=0; i<2; i++) iRec106[i] = 0;
		for (int i=0; i<2; i++) fRec107[i] = 0;
		for (int i=0; i<2; i++) fRec105[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<3; i++) fRec99[i] = 0;
		for (int i=0; i<3; i++) fRec108[i] = 0;
		for (int i=0; i<2; i++) fRec110[i] = 0;
		for (int i=0; i<2; i++) fRec111[i] = 0;
		for (int i=0; i<2; i++) fRec112[i] = 0;
		for (int i=0; i<2; i++) fRec109[i] = 0;
		for (int i=0; i<3; i++) fRec11[i] = 0;
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
		float 	fSlow13 = powf((fConst35 * fSlow3),2.0f);
		float 	fSlow14 = ((fSlow13 * ((0.2033f * fSlow13) + 0.31755f)) + 1.0f);
		float 	fSlow15 = (2.0f * ((fConst36 * (powf(fSlow3,2.0f) * powf(fSlow14,2.0f))) + -1.0f));
		float 	fSlow16 = (fSlow3 * fSlow14);
		float 	fSlow17 = (fConst37 * fSlow16);
		float 	fSlow18 = ((fConst12 * (fSlow16 * (fSlow17 + -0.2568503f))) + 1.0f);
		float 	fSlow19 = ((fConst12 * (fSlow16 * (fSlow17 + 0.2568503f))) + 1.0f);
		float 	fSlow20 = (1.0f / fSlow19);
		float 	fSlow21 = max(0.05f, (0.1f - fabsf(fSlow10)));
		float 	fSlow22 = (fConst38 * (fSlow16 / fSlow19));
		float 	fSlow23 = (fConst39 * fSlow3);
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
		float 	fSlow35 = powf((fConst35 * fSlow25),2.0f);
		float 	fSlow36 = ((fSlow35 * ((0.2033f * fSlow35) + 0.31755f)) + 1.0f);
		float 	fSlow37 = (2.0f * ((fConst36 * (powf(fSlow25,2.0f) * powf(fSlow36,2.0f))) + -1.0f));
		float 	fSlow38 = (fSlow25 * fSlow36);
		float 	fSlow39 = (fConst37 * fSlow38);
		float 	fSlow40 = ((fConst12 * (fSlow38 * (fSlow39 + -0.2568503f))) + 1.0f);
		float 	fSlow41 = ((fConst12 * (fSlow38 * (fSlow39 + 0.2568503f))) + 1.0f);
		float 	fSlow42 = (1.0f / fSlow41);
		float 	fSlow43 = max(0.05f, (0.1f - fabsf(fSlow32)));
		float 	fSlow44 = (fConst38 * (fSlow38 / fSlow41));
		float 	fSlow45 = (fConst39 * fSlow25);
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
		float 	fSlow57 = powf((fConst35 * fSlow47),2.0f);
		float 	fSlow58 = ((fSlow57 * ((0.2033f * fSlow57) + 0.31755f)) + 1.0f);
		float 	fSlow59 = (2.0f * ((fConst36 * (powf(fSlow47,2.0f) * powf(fSlow58,2.0f))) + -1.0f));
		float 	fSlow60 = (fSlow47 * fSlow58);
		float 	fSlow61 = (fConst37 * fSlow60);
		float 	fSlow62 = ((fConst12 * (fSlow60 * (fSlow61 + -0.2568503f))) + 1.0f);
		float 	fSlow63 = ((fConst12 * (fSlow60 * (fSlow61 + 0.2568503f))) + 1.0f);
		float 	fSlow64 = (1.0f / fSlow63);
		float 	fSlow65 = max(0.05f, (0.1f - fabsf(fSlow54)));
		float 	fSlow66 = (fConst38 * (fSlow60 / fSlow63));
		float 	fSlow67 = (fConst39 * fSlow47);
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
		float 	fSlow79 = powf((fConst35 * fSlow69),2.0f);
		float 	fSlow80 = ((fSlow79 * ((0.2033f * fSlow79) + 0.31755f)) + 1.0f);
		float 	fSlow81 = (2.0f * ((fConst36 * (powf(fSlow69,2.0f) * powf(fSlow80,2.0f))) + -1.0f));
		float 	fSlow82 = (fSlow69 * fSlow80);
		float 	fSlow83 = (fConst37 * fSlow82);
		float 	fSlow84 = ((fConst12 * (fSlow82 * (fSlow83 + -0.2568503f))) + 1.0f);
		float 	fSlow85 = ((fConst12 * (fSlow82 * (fSlow83 + 0.2568503f))) + 1.0f);
		float 	fSlow86 = (1.0f / fSlow85);
		float 	fSlow87 = max(0.05f, (0.1f - fabsf(fSlow76)));
		float 	fSlow88 = (fConst38 * (fSlow82 / fSlow85));
		float 	fSlow89 = (fConst39 * fSlow69);
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
		float 	fSlow101 = powf((fConst35 * fSlow91),2.0f);
		float 	fSlow102 = ((fSlow101 * ((0.2033f * fSlow101) + 0.31755f)) + 1.0f);
		float 	fSlow103 = (2.0f * ((fConst36 * (powf(fSlow91,2.0f) * powf(fSlow102,2.0f))) + -1.0f));
		float 	fSlow104 = (fSlow91 * fSlow102);
		float 	fSlow105 = (fConst37 * fSlow104);
		float 	fSlow106 = ((fConst12 * (fSlow104 * (fSlow105 + -0.2568503f))) + 1.0f);
		float 	fSlow107 = ((fConst12 * (fSlow104 * (fSlow105 + 0.2568503f))) + 1.0f);
		float 	fSlow108 = (1.0f / fSlow107);
		float 	fSlow109 = max(0.05f, (0.1f - fabsf(fSlow98)));
		float 	fSlow110 = (fConst38 * (fSlow104 / fSlow107));
		float 	fSlow111 = (fConst39 * fSlow91);
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
		float 	fSlow123 = powf((fConst35 * fSlow113),2.0f);
		float 	fSlow124 = ((fSlow123 * ((0.2033f * fSlow123) + 0.31755f)) + 1.0f);
		float 	fSlow125 = (2.0f * ((fConst36 * (powf(fSlow113,2.0f) * powf(fSlow124,2.0f))) + -1.0f));
		float 	fSlow126 = (fSlow113 * fSlow124);
		float 	fSlow127 = (fConst37 * fSlow126);
		float 	fSlow128 = ((fConst12 * (fSlow126 * (fSlow127 + -0.2568503f))) + 1.0f);
		float 	fSlow129 = ((fConst12 * (fSlow126 * (fSlow127 + 0.2568503f))) + 1.0f);
		float 	fSlow130 = (1.0f / fSlow129);
		float 	fSlow131 = max(0.05f, (0.1f - fabsf(fSlow120)));
		float 	fSlow132 = (fConst38 * (fSlow126 / fSlow129));
		float 	fSlow133 = (fConst39 * fSlow113);
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
			float 	fTemp1 = ((5e+02f * fRec2[0]) + 6e+01f);
			float 	fTemp2 = powf((fConst10 * fTemp1),2.0f);
			float 	fTemp3 = ((fTemp2 * ((0.2033f * fTemp2) + 0.31755f)) + 1.0f);
			float 	fTemp4 = (fTemp1 * fTemp3);
			float 	fTemp5 = (fConst11 * fTemp4);
			float 	fTemp6 = ((fConst12 * (fTemp4 * (fTemp5 + 0.07853982f))) + 1.0f);
			fVec1[0] = fSlow2;
			float 	fTemp7 = (fSlow2 - fVec1[1]);
			int 	iTemp8 = ((fTemp7 > 0.04f) & iSlow1);
			iVec2[0] = iTemp8;
			iRec3[0] = (((iRec3[1] + (iRec3[1] > 0)) * (iVec2[0] <= iVec2[1])) + (iVec2[0] > iVec2[1]));
			float 	fTemp9 = float(iRec3[0]);
			iRec5[0] = ((1103515245 * iRec5[1]) + 12345);
			float 	fTemp10 = float(iRec5[0]);
			float 	fTemp11 = max(1.1920929e-07f, fabsf(fTemp1));
			float 	fTemp12 = (fRec6[1] + (fConst12 * fTemp11));
			float 	fTemp13 = (fTemp12 + -1.0f);
			int 	iTemp14 = (fTemp13 < 0.0f);
			fRec6[0] = ((iTemp14) ? fTemp12 : fTemp13);
			float 	fRec7 = ((iTemp14) ? fTemp12 : (fTemp12 + (fTemp13 * (1.0f - (fConst0 / fTemp11)))));
			fRec4[0] = (((0.8f * ((2.0f * fRec7) + -1.0f)) + (9.313226e-11f * fTemp10)) - (((((fConst12 * (fTemp4 * (fTemp5 + -0.07853982f))) + 1.0f) * fRec4[2]) + (2.0f * (((fConst17 * (powf(fTemp1,2.0f) * powf(fTemp3,2.0f))) + -1.0f) * fRec4[1]))) / fTemp6));
			float 	fTemp15 = fabsf(fTemp7);
			int 	iTemp16 = ((fTemp15 >= fRec10[1]) | (float(iRec9[1]) >= fConst18));
			iRec9[0] = ((iTemp16) ? 0 : (iRec9[1] + 1));
			fRec10[0] = ((iTemp16) ? fTemp15 : fRec10[1]);
			float 	fTemp17 = (fRec8[1] - fConst19);
			float 	fTemp18 = (fConst19 + fRec8[1]);
			fRec8[0] = (((fTemp18 < fRec10[0])) ? fTemp18 : (((fTemp17 > fRec10[0])) ? fTemp17 : fRec10[0]));
			fRec0[0] = ((fConst20 * (((((fRec8[0] * fTemp1) * fTemp3) * (fRec4[0] - fRec4[2])) * max(0.0f, min((fConst14 * fTemp9), ((fConst16 * (fConst13 - fTemp9)) + 1.0f)))) / fTemp6)) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			int 	iTemp21 = (1 - iVec0[1]);
			float 	fTemp22 = ((iTemp21) ? 0.0f : (fSlow4 + fRec13[1]));
			fRec13[0] = (fTemp22 - floorf(fTemp22));
			float 	fTemp23 = (499.0f * fRec13[0]);
			int 	iTemp24 = int(fTemp23);
			float 	fTemp25 = ftbl0[max(0, min(iTemp24, 499))];
			float 	fTemp26 = ((iTemp21) ? 0.0f : (fSlow5 + fRec15[1]));
			fRec15[0] = (fTemp26 - floorf(fTemp26));
			float 	fTemp27 = (499.0f * fRec15[0]);
			int 	iTemp28 = int(fTemp27);
			float 	fTemp29 = ftbl1[max(0, min(iTemp28, 499))];
			fVec3[0] = fSlow10;
			int 	iTemp31 = (fSlow10 != fVec3[1]);
			iVec4[0] = iTemp31;
			int 	iTemp32 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec21[0] = (iRec21[1] + 1);
			int 	iTemp33 = (iRec21[0] + -1);
			iRec20[0] = ((iRec20[1] * (1 - iTemp32)) + (iTemp33 * iTemp32));
			float 	fTemp34 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec20[0])))) > 0.5f) & iSlow11)) ? 0.0f : fSlow9) + 1.0f)) + 0.5f))];
			fVec5[0] = fTemp34;
			int 	iTemp35 = (fVec5[0] > 0.003f);
			int 	iTemp36 = (fVec5[0] <= 0.003f);
			float 	fTemp37 = float((iTemp36 | (fVec5[1] >= 0.003f)));
			fRec22[0] = max((fRec22[1] * fTemp37), fSlow10);
			fRec23[0] = max((fTemp37 * fRec23[1]), fSlow12);
			float 	fTemp38 = (min(1.0f, fRec23[0]) + min(1.0f, fRec22[0]));
			int 	iTemp39 = (fVec5[0] >= fRec19[1]);
			int 	iTemp40 = (fRec19[1] <= 0.001f);
			int 	iTemp41 = (((iRec18[1] >= 4)) ? (((iRec18[1] >= 6)) ? ((iTemp40) ? 0 : ((iTemp35) ? 1 : 6)) : (((iRec18[1] >= 5)) ? ((iTemp36) ? 3 : ((iTemp39) ? 4 : 5)) : ((iTemp36) ? 3 : (((fVec5[0] <= fRec19[1])) ? 5 : 4)))) : (((iRec18[1] >= 2)) ? (((iRec18[1] >= 3)) ? (((iTemp36 & iTemp40)) ? 0 : ((iTemp35) ? 1 : 3)) : ((iTemp35) ? ((iTemp39) ? 4 : 2) : 6)) : (((iRec18[1] >= 1)) ? (((fRec19[1] >= min(fTemp38, 1.0f))) ? ((iTemp36) ? 6 : 2) : 1) : ((iTemp35) ? 1 : 0))));
			iRec18[0] = iTemp41;
			float 	fTemp43 = (((iTemp41 >= 4)) ? (((iTemp41 >= 6)) ? fConst33 : fConst15) : (((iTemp41 >= 2)) ? (((iTemp41 >= 3)) ? fConst32 : fConst31) : (((iTemp41 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp44 = (iRec18[1] != iRec18[2]);
			iVec6[0] = iTemp44;
			int 	iTemp45 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec26[0] = ((iRec26[1] * (1 - iTemp45)) + (iTemp33 * iTemp45));
			float 	fTemp46 = (2e+01f * (((fTemp43 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec26[0]))) / fTemp43) : 0.0f));
			int 	iTemp47 = int(fTemp46);
			float 	fTemp48 = ftbl3[max(0, int(min(int(iTemp47), 20)))];
			float 	fTemp49 = (fTemp48 + ((fTemp46 - float(iTemp47)) * (ftbl3[max(0, int(min(int((iTemp47 + 1)), 20)))] - fTemp48)));
			fRec27[0] = max((fRec27[1] * float(iVec6[0])), max(fVec5[0], fRec19[1]));
			int 	iTemp50 = (iRec18[1] == 3);
			int 	iTemp51 = (iRec18[1] == 6);
			int 	iTemp52 = (iRec18[1] == 0);
			float 	fTemp53 = (((iRec18[1] == 1)) ? min(1.0f, fTemp38) : ((iTemp52) ? 0.0f : ((iTemp51) ? (fTemp38 * fTemp49) : ((iTemp50) ? (fRec27[0] * fTemp49) : fVec5[0]))));
			float 	fTemp54 = (1.0f / ((iTemp52) ? 0.0001f : (((iTemp50 | iTemp51)) ? (0.04761905f * fTemp43) : fTemp43)));
			float 	fTemp55 = (fRec24[1] - fTemp54);
			float 	fTemp56 = (fRec24[1] + fTemp54);
			fRec24[0] = (((fTemp56 < fTemp53)) ? fTemp56 : (((fTemp55 > fTemp53)) ? fTemp55 : fTemp53));
			fRec19[0] = fRec24[0];
			fRec17[0] = (fRec19[0] - (fConst30 * ((fConst28 * fRec17[2]) + (fConst26 * fRec17[1]))));
			float 	fTemp57 = min(0.99f, (fConst34 * (((3947.8418f * fRec17[0]) + (7895.6836f * fRec17[1])) + (3947.8418f * fRec17[2]))));
			int 	iTemp58 = (fTemp57 < 0.1f);
			float 	fTemp59 = (((iTemp58) ? fTemp57 : 0.1f) * fSlow8);
			float 	fTemp60 = (4.656613e-10f * fTemp10);
			fRec28[0] = (fTemp60 - (fSlow20 * ((fSlow18 * fRec28[2]) + (fSlow15 * fRec28[1]))));
			float 	fTemp61 = min(1.0f, (fSlow21 + ((iTemp58) ? (1.0f - (1e+01f * fTemp57)) : 0.0f)));
			float 	fTemp62 = ((iTemp21) ? 0.0f : (fSlow23 + fRec30[1]));
			fRec30[0] = (fTemp62 - floorf(fTemp62));
			float 	fTemp63 = (499.0f * fRec30[0]);
			int 	iTemp64 = int(fTemp63);
			int 	iTemp65 = max(0, min(iTemp64, 499));
			float 	fTemp66 = ftbl1[iTemp65];
			int 	iTemp67 = max(0, min((iTemp64 + 1), 499));
			float 	fTemp68 = (fTemp63 - float(iTemp64));
			float 	fTemp69 = float((((fVec5[1] <= 0.003f) & iTemp35) != 1));
			fRec31[0] = max((fTemp69 * fRec31[1]), fSlow24);
			fRec32[0] = max((fRec32[1] * fTemp69), fSlow6);
			float 	fTemp70 = max(min(((0.5f * (fVec5[0] - fTemp57)) + (0.2f - (0.8f * ((iTemp36) ? (2.0f * (((fRec32[0] > fRec31[0])) ? fRec32[0] : (0.0f - fRec31[0]))) : fSlow7)))), 1.0f), 0.0f);
			float 	fTemp71 = ftbl0[iTemp65];
			float 	fTemp72 = (((fTemp71 + (fTemp68 * (ftbl0[iTemp67] - fTemp71))) * (1.0f - fTemp70)) + (fTemp70 * (fTemp66 + (fTemp68 * (ftbl1[iTemp67] - fTemp66)))));
			float 	fTemp73 = (fRec29[1] - fConst40);
			float 	fTemp74 = (fConst40 + fRec29[1]);
			fRec29[0] = (((fTemp74 < fTemp72)) ? fTemp74 : (((fTemp73 > fTemp72)) ? fTemp73 : fTemp72));
			float 	fTemp75 = ((iTemp21) ? 0.0f : (fSlow26 + fRec33[1]));
			fRec33[0] = (fTemp75 - floorf(fTemp75));
			float 	fTemp76 = (499.0f * fRec33[0]);
			int 	iTemp77 = int(fTemp76);
			float 	fTemp78 = ftbl0[max(0, min(iTemp77, 499))];
			float 	fTemp79 = ((iTemp21) ? 0.0f : (fSlow27 + fRec34[1]));
			fRec34[0] = (fTemp79 - floorf(fTemp79));
			float 	fTemp80 = (499.0f * fRec34[0]);
			int 	iTemp81 = int(fTemp80);
			float 	fTemp82 = ftbl1[max(0, min(iTemp81, 499))];
			fVec7[0] = fSlow32;
			int 	iTemp83 = (fSlow32 != fVec7[1]);
			iVec8[0] = iTemp83;
			int 	iTemp84 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec38[0] = ((iRec38[1] * (1 - iTemp84)) + (iTemp33 * iTemp84));
			float 	fTemp85 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec38[0])))) > 0.5f) & iSlow33)) ? 0.0f : fSlow31) + 1.0f)) + 0.5f))];
			fVec9[0] = fTemp85;
			int 	iTemp86 = (fVec9[0] > 0.003f);
			int 	iTemp87 = (fVec9[0] <= 0.003f);
			float 	fTemp88 = float((iTemp87 | (fVec9[1] >= 0.003f)));
			fRec39[0] = max((fRec39[1] * fTemp88), fSlow32);
			fRec40[0] = max((fTemp88 * fRec40[1]), fSlow34);
			float 	fTemp89 = (min(1.0f, fRec40[0]) + min(1.0f, fRec39[0]));
			int 	iTemp90 = (fVec9[0] >= fRec37[1]);
			int 	iTemp91 = (fRec37[1] <= 0.001f);
			int 	iTemp92 = (((iRec36[1] >= 4)) ? (((iRec36[1] >= 6)) ? ((iTemp91) ? 0 : ((iTemp86) ? 1 : 6)) : (((iRec36[1] >= 5)) ? ((iTemp87) ? 3 : ((iTemp90) ? 4 : 5)) : ((iTemp87) ? 3 : (((fVec9[0] <= fRec37[1])) ? 5 : 4)))) : (((iRec36[1] >= 2)) ? (((iRec36[1] >= 3)) ? (((iTemp87 & iTemp91)) ? 0 : ((iTemp86) ? 1 : 3)) : ((iTemp86) ? ((iTemp90) ? 4 : 2) : 6)) : (((iRec36[1] >= 1)) ? (((fRec37[1] >= min(fTemp89, 1.0f))) ? ((iTemp87) ? 6 : 2) : 1) : ((iTemp86) ? 1 : 0))));
			iRec36[0] = iTemp92;
			float 	fTemp93 = (((iTemp92 >= 4)) ? (((iTemp92 >= 6)) ? fConst33 : fConst15) : (((iTemp92 >= 2)) ? (((iTemp92 >= 3)) ? fConst32 : fConst31) : (((iTemp92 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp94 = (iRec36[1] != iRec36[2]);
			iVec10[0] = iTemp94;
			int 	iTemp95 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec42[0] = ((iRec42[1] * (1 - iTemp95)) + (iTemp33 * iTemp95));
			float 	fTemp96 = (2e+01f * (((fTemp93 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec42[0]))) / fTemp93) : 0.0f));
			int 	iTemp97 = int(fTemp96);
			float 	fTemp98 = ftbl3[max(0, int(min(int(iTemp97), 20)))];
			float 	fTemp99 = (fTemp98 + ((fTemp96 - float(iTemp97)) * (ftbl3[max(0, int(min(int((iTemp97 + 1)), 20)))] - fTemp98)));
			fRec43[0] = max((fRec43[1] * float(iVec10[0])), max(fVec9[0], fRec37[1]));
			int 	iTemp100 = (iRec36[1] == 3);
			int 	iTemp101 = (iRec36[1] == 6);
			int 	iTemp102 = (iRec36[1] == 0);
			float 	fTemp103 = (((iRec36[1] == 1)) ? min(1.0f, fTemp89) : ((iTemp102) ? 0.0f : ((iTemp101) ? (fTemp89 * fTemp99) : ((iTemp100) ? (fRec43[0] * fTemp99) : fVec9[0]))));
			float 	fTemp104 = (1.0f / ((iTemp102) ? 0.0001f : (((iTemp100 | iTemp101)) ? (0.04761905f * fTemp93) : fTemp93)));
			float 	fTemp105 = (fRec41[1] - fTemp104);
			float 	fTemp106 = (fRec41[1] + fTemp104);
			fRec41[0] = (((fTemp106 < fTemp103)) ? fTemp106 : (((fTemp105 > fTemp103)) ? fTemp105 : fTemp103));
			fRec37[0] = fRec41[0];
			fRec35[0] = (fRec37[0] - (fConst30 * ((fConst28 * fRec35[2]) + (fConst26 * fRec35[1]))));
			float 	fTemp107 = min(0.99f, (fConst34 * (((3947.8418f * fRec35[0]) + (7895.6836f * fRec35[1])) + (3947.8418f * fRec35[2]))));
			int 	iTemp108 = (fTemp107 < 0.1f);
			float 	fTemp109 = (((iTemp108) ? fTemp107 : 0.1f) * fSlow30);
			fRec44[0] = (fTemp60 - (fSlow42 * ((fSlow40 * fRec44[2]) + (fSlow37 * fRec44[1]))));
			float 	fTemp110 = min(1.0f, (fSlow43 + ((iTemp108) ? (1.0f - (1e+01f * fTemp107)) : 0.0f)));
			float 	fTemp111 = ((iTemp21) ? 0.0f : (fSlow45 + fRec46[1]));
			fRec46[0] = (fTemp111 - floorf(fTemp111));
			float 	fTemp112 = (499.0f * fRec46[0]);
			int 	iTemp113 = int(fTemp112);
			int 	iTemp114 = max(0, min(iTemp113, 499));
			float 	fTemp115 = ftbl1[iTemp114];
			int 	iTemp116 = max(0, min((iTemp113 + 1), 499));
			float 	fTemp117 = (fTemp112 - float(iTemp113));
			float 	fTemp118 = float((((fVec9[1] <= 0.003f) & iTemp86) != 1));
			fRec47[0] = max((fTemp118 * fRec47[1]), fSlow46);
			fRec48[0] = max((fRec48[1] * fTemp118), fSlow28);
			float 	fTemp119 = max(min(((0.5f * (fVec9[0] - fTemp107)) + (0.2f - (0.8f * ((iTemp87) ? (2.0f * (((fRec48[0] > fRec47[0])) ? fRec48[0] : (0.0f - fRec47[0]))) : fSlow29)))), 1.0f), 0.0f);
			float 	fTemp120 = ftbl0[iTemp114];
			float 	fTemp121 = (((fTemp120 + (fTemp117 * (ftbl0[iTemp116] - fTemp120))) * (1.0f - fTemp119)) + (fTemp119 * (fTemp115 + (fTemp117 * (ftbl1[iTemp116] - fTemp115)))));
			float 	fTemp122 = (fRec45[1] - fConst40);
			float 	fTemp123 = (fConst40 + fRec45[1]);
			fRec45[0] = (((fTemp123 < fTemp121)) ? fTemp123 : (((fTemp122 > fTemp121)) ? fTemp122 : fTemp121));
			float 	fTemp124 = ((iTemp21) ? 0.0f : (fSlow48 + fRec49[1]));
			fRec49[0] = (fTemp124 - floorf(fTemp124));
			float 	fTemp125 = (499.0f * fRec49[0]);
			int 	iTemp126 = int(fTemp125);
			float 	fTemp127 = ftbl0[max(0, min(iTemp126, 499))];
			float 	fTemp128 = ((iTemp21) ? 0.0f : (fSlow49 + fRec50[1]));
			fRec50[0] = (fTemp128 - floorf(fTemp128));
			float 	fTemp129 = (499.0f * fRec50[0]);
			int 	iTemp130 = int(fTemp129);
			float 	fTemp131 = ftbl1[max(0, min(iTemp130, 499))];
			fVec11[0] = fSlow54;
			int 	iTemp132 = (fSlow54 != fVec11[1]);
			iVec12[0] = iTemp132;
			int 	iTemp133 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec54[0] = ((iRec54[1] * (1 - iTemp133)) + (iTemp33 * iTemp133));
			float 	fTemp134 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec54[0])))) > 0.5f) & iSlow55)) ? 0.0f : fSlow53) + 1.0f)) + 0.5f))];
			fVec13[0] = fTemp134;
			int 	iTemp135 = (fVec13[0] > 0.003f);
			int 	iTemp136 = (fVec13[0] <= 0.003f);
			float 	fTemp137 = float((iTemp136 | (fVec13[1] >= 0.003f)));
			fRec55[0] = max((fRec55[1] * fTemp137), fSlow54);
			fRec56[0] = max((fTemp137 * fRec56[1]), fSlow56);
			float 	fTemp138 = (min(1.0f, fRec56[0]) + min(1.0f, fRec55[0]));
			int 	iTemp139 = (fVec13[0] >= fRec53[1]);
			int 	iTemp140 = (fRec53[1] <= 0.001f);
			int 	iTemp141 = (((iRec52[1] >= 4)) ? (((iRec52[1] >= 6)) ? ((iTemp140) ? 0 : ((iTemp135) ? 1 : 6)) : (((iRec52[1] >= 5)) ? ((iTemp136) ? 3 : ((iTemp139) ? 4 : 5)) : ((iTemp136) ? 3 : (((fVec13[0] <= fRec53[1])) ? 5 : 4)))) : (((iRec52[1] >= 2)) ? (((iRec52[1] >= 3)) ? (((iTemp136 & iTemp140)) ? 0 : ((iTemp135) ? 1 : 3)) : ((iTemp135) ? ((iTemp139) ? 4 : 2) : 6)) : (((iRec52[1] >= 1)) ? (((fRec53[1] >= min(fTemp138, 1.0f))) ? ((iTemp136) ? 6 : 2) : 1) : ((iTemp135) ? 1 : 0))));
			iRec52[0] = iTemp141;
			float 	fTemp142 = (((iTemp141 >= 4)) ? (((iTemp141 >= 6)) ? fConst33 : fConst15) : (((iTemp141 >= 2)) ? (((iTemp141 >= 3)) ? fConst32 : fConst31) : (((iTemp141 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp143 = (iRec52[1] != iRec52[2]);
			iVec14[0] = iTemp143;
			int 	iTemp144 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec58[0] = ((iRec58[1] * (1 - iTemp144)) + (iTemp33 * iTemp144));
			float 	fTemp145 = (2e+01f * (((fTemp142 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec58[0]))) / fTemp142) : 0.0f));
			int 	iTemp146 = int(fTemp145);
			float 	fTemp147 = ftbl3[max(0, int(min(int(iTemp146), 20)))];
			float 	fTemp148 = (fTemp147 + ((fTemp145 - float(iTemp146)) * (ftbl3[max(0, int(min(int((iTemp146 + 1)), 20)))] - fTemp147)));
			fRec59[0] = max((fRec59[1] * float(iVec14[0])), max(fVec13[0], fRec53[1]));
			int 	iTemp149 = (iRec52[1] == 3);
			int 	iTemp150 = (iRec52[1] == 6);
			int 	iTemp151 = (iRec52[1] == 0);
			float 	fTemp152 = (((iRec52[1] == 1)) ? min(1.0f, fTemp138) : ((iTemp151) ? 0.0f : ((iTemp150) ? (fTemp138 * fTemp148) : ((iTemp149) ? (fRec59[0] * fTemp148) : fVec13[0]))));
			float 	fTemp153 = (1.0f / ((iTemp151) ? 0.0001f : (((iTemp149 | iTemp150)) ? (0.04761905f * fTemp142) : fTemp142)));
			float 	fTemp154 = (fRec57[1] - fTemp153);
			float 	fTemp155 = (fRec57[1] + fTemp153);
			fRec57[0] = (((fTemp155 < fTemp152)) ? fTemp155 : (((fTemp154 > fTemp152)) ? fTemp154 : fTemp152));
			fRec53[0] = fRec57[0];
			fRec51[0] = (fRec53[0] - (fConst30 * ((fConst28 * fRec51[2]) + (fConst26 * fRec51[1]))));
			float 	fTemp156 = min(0.99f, (fConst34 * (((3947.8418f * fRec51[0]) + (7895.6836f * fRec51[1])) + (3947.8418f * fRec51[2]))));
			int 	iTemp157 = (fTemp156 < 0.1f);
			float 	fTemp158 = (((iTemp157) ? fTemp156 : 0.1f) * fSlow52);
			fRec60[0] = (fTemp60 - (fSlow64 * ((fSlow62 * fRec60[2]) + (fSlow59 * fRec60[1]))));
			float 	fTemp159 = min(1.0f, (fSlow65 + ((iTemp157) ? (1.0f - (1e+01f * fTemp156)) : 0.0f)));
			float 	fTemp160 = ((iTemp21) ? 0.0f : (fSlow67 + fRec62[1]));
			fRec62[0] = (fTemp160 - floorf(fTemp160));
			float 	fTemp161 = (499.0f * fRec62[0]);
			int 	iTemp162 = int(fTemp161);
			int 	iTemp163 = max(0, min(iTemp162, 499));
			float 	fTemp164 = ftbl1[iTemp163];
			int 	iTemp165 = max(0, min((iTemp162 + 1), 499));
			float 	fTemp166 = (fTemp161 - float(iTemp162));
			float 	fTemp167 = float((((fVec13[1] <= 0.003f) & iTemp135) != 1));
			fRec63[0] = max((fTemp167 * fRec63[1]), fSlow68);
			fRec64[0] = max((fRec64[1] * fTemp167), fSlow50);
			float 	fTemp168 = max(min(((0.5f * (fVec13[0] - fTemp156)) + (0.2f - (0.8f * ((iTemp136) ? (2.0f * (((fRec64[0] > fRec63[0])) ? fRec64[0] : (0.0f - fRec63[0]))) : fSlow51)))), 1.0f), 0.0f);
			float 	fTemp169 = ftbl0[iTemp163];
			float 	fTemp170 = (((fTemp169 + (fTemp166 * (ftbl0[iTemp165] - fTemp169))) * (1.0f - fTemp168)) + (fTemp168 * (fTemp164 + (fTemp166 * (ftbl1[iTemp165] - fTemp164)))));
			float 	fTemp171 = (fRec61[1] - fConst40);
			float 	fTemp172 = (fConst40 + fRec61[1]);
			fRec61[0] = (((fTemp172 < fTemp170)) ? fTemp172 : (((fTemp171 > fTemp170)) ? fTemp171 : fTemp170));
			float 	fTemp173 = ((iTemp21) ? 0.0f : (fSlow70 + fRec65[1]));
			fRec65[0] = (fTemp173 - floorf(fTemp173));
			float 	fTemp174 = (499.0f * fRec65[0]);
			int 	iTemp175 = int(fTemp174);
			float 	fTemp176 = ftbl0[max(0, min(iTemp175, 499))];
			float 	fTemp177 = ((iTemp21) ? 0.0f : (fSlow71 + fRec66[1]));
			fRec66[0] = (fTemp177 - floorf(fTemp177));
			float 	fTemp178 = (499.0f * fRec66[0]);
			int 	iTemp179 = int(fTemp178);
			float 	fTemp180 = ftbl1[max(0, min(iTemp179, 499))];
			fVec15[0] = fSlow76;
			int 	iTemp181 = (fSlow76 != fVec15[1]);
			iVec16[0] = iTemp181;
			int 	iTemp182 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec70[0] = ((iRec70[1] * (1 - iTemp182)) + (iTemp33 * iTemp182));
			float 	fTemp183 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec70[0])))) > 0.5f) & iSlow77)) ? 0.0f : fSlow75) + 1.0f)) + 0.5f))];
			fVec17[0] = fTemp183;
			int 	iTemp184 = (fVec17[0] > 0.003f);
			int 	iTemp185 = (fVec17[0] <= 0.003f);
			float 	fTemp186 = float((iTemp185 | (fVec17[1] >= 0.003f)));
			fRec71[0] = max((fRec71[1] * fTemp186), fSlow76);
			fRec72[0] = max((fTemp186 * fRec72[1]), fSlow78);
			float 	fTemp187 = (min(1.0f, fRec72[0]) + min(1.0f, fRec71[0]));
			int 	iTemp188 = (fVec17[0] >= fRec69[1]);
			int 	iTemp189 = (fRec69[1] <= 0.001f);
			int 	iTemp190 = (((iRec68[1] >= 4)) ? (((iRec68[1] >= 6)) ? ((iTemp189) ? 0 : ((iTemp184) ? 1 : 6)) : (((iRec68[1] >= 5)) ? ((iTemp185) ? 3 : ((iTemp188) ? 4 : 5)) : ((iTemp185) ? 3 : (((fVec17[0] <= fRec69[1])) ? 5 : 4)))) : (((iRec68[1] >= 2)) ? (((iRec68[1] >= 3)) ? (((iTemp185 & iTemp189)) ? 0 : ((iTemp184) ? 1 : 3)) : ((iTemp184) ? ((iTemp188) ? 4 : 2) : 6)) : (((iRec68[1] >= 1)) ? (((fRec69[1] >= min(fTemp187, 1.0f))) ? ((iTemp185) ? 6 : 2) : 1) : ((iTemp184) ? 1 : 0))));
			iRec68[0] = iTemp190;
			float 	fTemp191 = (((iTemp190 >= 4)) ? (((iTemp190 >= 6)) ? fConst33 : fConst15) : (((iTemp190 >= 2)) ? (((iTemp190 >= 3)) ? fConst32 : fConst31) : (((iTemp190 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp192 = (iRec68[1] != iRec68[2]);
			iVec18[0] = iTemp192;
			int 	iTemp193 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec74[0] = ((iRec74[1] * (1 - iTemp193)) + (iTemp33 * iTemp193));
			float 	fTemp194 = (2e+01f * (((fTemp191 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec74[0]))) / fTemp191) : 0.0f));
			int 	iTemp195 = int(fTemp194);
			float 	fTemp196 = ftbl3[max(0, int(min(int(iTemp195), 20)))];
			float 	fTemp197 = (fTemp196 + ((fTemp194 - float(iTemp195)) * (ftbl3[max(0, int(min(int((iTemp195 + 1)), 20)))] - fTemp196)));
			fRec75[0] = max((fRec75[1] * float(iVec18[0])), max(fVec17[0], fRec69[1]));
			int 	iTemp198 = (iRec68[1] == 3);
			int 	iTemp199 = (iRec68[1] == 6);
			int 	iTemp200 = (iRec68[1] == 0);
			float 	fTemp201 = (((iRec68[1] == 1)) ? min(1.0f, fTemp187) : ((iTemp200) ? 0.0f : ((iTemp199) ? (fTemp187 * fTemp197) : ((iTemp198) ? (fRec75[0] * fTemp197) : fVec17[0]))));
			float 	fTemp202 = (1.0f / ((iTemp200) ? 0.0001f : (((iTemp198 | iTemp199)) ? (0.04761905f * fTemp191) : fTemp191)));
			float 	fTemp203 = (fRec73[1] - fTemp202);
			float 	fTemp204 = (fRec73[1] + fTemp202);
			fRec73[0] = (((fTemp204 < fTemp201)) ? fTemp204 : (((fTemp203 > fTemp201)) ? fTemp203 : fTemp201));
			fRec69[0] = fRec73[0];
			fRec67[0] = (fRec69[0] - (fConst30 * ((fConst28 * fRec67[2]) + (fConst26 * fRec67[1]))));
			float 	fTemp205 = min(0.99f, (fConst34 * (((3947.8418f * fRec67[0]) + (7895.6836f * fRec67[1])) + (3947.8418f * fRec67[2]))));
			int 	iTemp206 = (fTemp205 < 0.1f);
			float 	fTemp207 = (((iTemp206) ? fTemp205 : 0.1f) * fSlow74);
			fRec76[0] = (fTemp60 - (fSlow86 * ((fSlow84 * fRec76[2]) + (fSlow81 * fRec76[1]))));
			float 	fTemp208 = min(1.0f, (fSlow87 + ((iTemp206) ? (1.0f - (1e+01f * fTemp205)) : 0.0f)));
			float 	fTemp209 = ((iTemp21) ? 0.0f : (fSlow89 + fRec78[1]));
			fRec78[0] = (fTemp209 - floorf(fTemp209));
			float 	fTemp210 = (499.0f * fRec78[0]);
			int 	iTemp211 = int(fTemp210);
			int 	iTemp212 = max(0, min(iTemp211, 499));
			float 	fTemp213 = ftbl1[iTemp212];
			int 	iTemp214 = max(0, min((iTemp211 + 1), 499));
			float 	fTemp215 = (fTemp210 - float(iTemp211));
			float 	fTemp216 = float((((fVec17[1] <= 0.003f) & iTemp184) != 1));
			fRec79[0] = max((fTemp216 * fRec79[1]), fSlow90);
			fRec80[0] = max((fRec80[1] * fTemp216), fSlow72);
			float 	fTemp217 = max(min(((0.5f * (fVec17[0] - fTemp205)) + (0.2f - (0.8f * ((iTemp185) ? (2.0f * (((fRec80[0] > fRec79[0])) ? fRec80[0] : (0.0f - fRec79[0]))) : fSlow73)))), 1.0f), 0.0f);
			float 	fTemp218 = ftbl0[iTemp212];
			float 	fTemp219 = (((fTemp218 + (fTemp215 * (ftbl0[iTemp214] - fTemp218))) * (1.0f - fTemp217)) + (fTemp217 * (fTemp213 + (fTemp215 * (ftbl1[iTemp214] - fTemp213)))));
			float 	fTemp220 = (fRec77[1] - fConst40);
			float 	fTemp221 = (fConst40 + fRec77[1]);
			fRec77[0] = (((fTemp221 < fTemp219)) ? fTemp221 : (((fTemp220 > fTemp219)) ? fTemp220 : fTemp219));
			float 	fTemp222 = ((iTemp21) ? 0.0f : (fSlow92 + fRec81[1]));
			fRec81[0] = (fTemp222 - floorf(fTemp222));
			float 	fTemp223 = (499.0f * fRec81[0]);
			int 	iTemp224 = int(fTemp223);
			float 	fTemp225 = ftbl0[max(0, min(iTemp224, 499))];
			float 	fTemp226 = ((iTemp21) ? 0.0f : (fSlow93 + fRec82[1]));
			fRec82[0] = (fTemp226 - floorf(fTemp226));
			float 	fTemp227 = (499.0f * fRec82[0]);
			int 	iTemp228 = int(fTemp227);
			float 	fTemp229 = ftbl1[max(0, min(iTemp228, 499))];
			fVec19[0] = fSlow98;
			int 	iTemp230 = (fSlow98 != fVec19[1]);
			iVec20[0] = iTemp230;
			int 	iTemp231 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec86[0] = ((iRec86[1] * (1 - iTemp231)) + (iTemp33 * iTemp231));
			float 	fTemp232 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec86[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec21[0] = fTemp232;
			int 	iTemp233 = (fVec21[0] > 0.003f);
			int 	iTemp234 = (fVec21[0] <= 0.003f);
			float 	fTemp235 = float((iTemp234 | (fVec21[1] >= 0.003f)));
			fRec87[0] = max((fRec87[1] * fTemp235), fSlow98);
			fRec88[0] = max((fTemp235 * fRec88[1]), fSlow100);
			float 	fTemp236 = (min(1.0f, fRec88[0]) + min(1.0f, fRec87[0]));
			int 	iTemp237 = (fVec21[0] >= fRec85[1]);
			int 	iTemp238 = (fRec85[1] <= 0.001f);
			int 	iTemp239 = (((iRec84[1] >= 4)) ? (((iRec84[1] >= 6)) ? ((iTemp238) ? 0 : ((iTemp233) ? 1 : 6)) : (((iRec84[1] >= 5)) ? ((iTemp234) ? 3 : ((iTemp237) ? 4 : 5)) : ((iTemp234) ? 3 : (((fVec21[0] <= fRec85[1])) ? 5 : 4)))) : (((iRec84[1] >= 2)) ? (((iRec84[1] >= 3)) ? (((iTemp234 & iTemp238)) ? 0 : ((iTemp233) ? 1 : 3)) : ((iTemp233) ? ((iTemp237) ? 4 : 2) : 6)) : (((iRec84[1] >= 1)) ? (((fRec85[1] >= min(fTemp236, 1.0f))) ? ((iTemp234) ? 6 : 2) : 1) : ((iTemp233) ? 1 : 0))));
			iRec84[0] = iTemp239;
			float 	fTemp240 = (((iTemp239 >= 4)) ? (((iTemp239 >= 6)) ? fConst33 : fConst15) : (((iTemp239 >= 2)) ? (((iTemp239 >= 3)) ? fConst32 : fConst31) : (((iTemp239 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp241 = (iRec84[1] != iRec84[2]);
			iVec22[0] = iTemp241;
			int 	iTemp242 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec90[0] = ((iRec90[1] * (1 - iTemp242)) + (iTemp33 * iTemp242));
			float 	fTemp243 = (2e+01f * (((fTemp240 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec90[0]))) / fTemp240) : 0.0f));
			int 	iTemp244 = int(fTemp243);
			float 	fTemp245 = ftbl3[max(0, int(min(int(iTemp244), 20)))];
			float 	fTemp246 = (fTemp245 + ((fTemp243 - float(iTemp244)) * (ftbl3[max(0, int(min(int((iTemp244 + 1)), 20)))] - fTemp245)));
			fRec91[0] = max((fRec91[1] * float(iVec22[0])), max(fVec21[0], fRec85[1]));
			int 	iTemp247 = (iRec84[1] == 3);
			int 	iTemp248 = (iRec84[1] == 6);
			int 	iTemp249 = (iRec84[1] == 0);
			float 	fTemp250 = (((iRec84[1] == 1)) ? min(1.0f, fTemp236) : ((iTemp249) ? 0.0f : ((iTemp248) ? (fTemp236 * fTemp246) : ((iTemp247) ? (fRec91[0] * fTemp246) : fVec21[0]))));
			float 	fTemp251 = (1.0f / ((iTemp249) ? 0.0001f : (((iTemp247 | iTemp248)) ? (0.04761905f * fTemp240) : fTemp240)));
			float 	fTemp252 = (fRec89[1] - fTemp251);
			float 	fTemp253 = (fRec89[1] + fTemp251);
			fRec89[0] = (((fTemp253 < fTemp250)) ? fTemp253 : (((fTemp252 > fTemp250)) ? fTemp252 : fTemp250));
			fRec85[0] = fRec89[0];
			fRec83[0] = (fRec85[0] - (fConst30 * ((fConst28 * fRec83[2]) + (fConst26 * fRec83[1]))));
			float 	fTemp254 = min(0.99f, (fConst34 * (((3947.8418f * fRec83[0]) + (7895.6836f * fRec83[1])) + (3947.8418f * fRec83[2]))));
			int 	iTemp255 = (fTemp254 < 0.1f);
			float 	fTemp256 = (((iTemp255) ? fTemp254 : 0.1f) * fSlow96);
			fRec92[0] = (fTemp60 - (fSlow108 * ((fSlow106 * fRec92[2]) + (fSlow103 * fRec92[1]))));
			float 	fTemp257 = min(1.0f, (fSlow109 + ((iTemp255) ? (1.0f - (1e+01f * fTemp254)) : 0.0f)));
			float 	fTemp258 = ((iTemp21) ? 0.0f : (fSlow111 + fRec94[1]));
			fRec94[0] = (fTemp258 - floorf(fTemp258));
			float 	fTemp259 = (499.0f * fRec94[0]);
			int 	iTemp260 = int(fTemp259);
			int 	iTemp261 = max(0, min(iTemp260, 499));
			float 	fTemp262 = ftbl1[iTemp261];
			int 	iTemp263 = max(0, min((iTemp260 + 1), 499));
			float 	fTemp264 = (fTemp259 - float(iTemp260));
			float 	fTemp265 = float((((fVec21[1] <= 0.003f) & iTemp233) != 1));
			fRec95[0] = max((fTemp265 * fRec95[1]), fSlow112);
			fRec96[0] = max((fRec96[1] * fTemp265), fSlow94);
			float 	fTemp266 = max(min(((0.5f * (fVec21[0] - fTemp254)) + (0.2f - (0.8f * ((iTemp234) ? (2.0f * (((fRec96[0] > fRec95[0])) ? fRec96[0] : (0.0f - fRec95[0]))) : fSlow95)))), 1.0f), 0.0f);
			float 	fTemp267 = ftbl0[iTemp261];
			float 	fTemp268 = (((fTemp267 + (fTemp264 * (ftbl0[iTemp263] - fTemp267))) * (1.0f - fTemp266)) + (fTemp266 * (fTemp262 + (fTemp264 * (ftbl1[iTemp263] - fTemp262)))));
			float 	fTemp269 = (fRec93[1] - fConst40);
			float 	fTemp270 = (fConst40 + fRec93[1]);
			fRec93[0] = (((fTemp270 < fTemp268)) ? fTemp270 : (((fTemp269 > fTemp268)) ? fTemp269 : fTemp268));
			float 	fTemp271 = ((iTemp21) ? 0.0f : (fSlow114 + fRec97[1]));
			fRec97[0] = (fTemp271 - floorf(fTemp271));
			float 	fTemp272 = (499.0f * fRec97[0]);
			int 	iTemp273 = int(fTemp272);
			float 	fTemp274 = ftbl0[max(0, min(iTemp273, 499))];
			float 	fTemp275 = ((iTemp21) ? 0.0f : (fSlow115 + fRec98[1]));
			fRec98[0] = (fTemp275 - floorf(fTemp275));
			float 	fTemp276 = (499.0f * fRec98[0]);
			int 	iTemp277 = int(fTemp276);
			float 	fTemp278 = ftbl1[max(0, min(iTemp277, 499))];
			fVec23[0] = fSlow120;
			int 	iTemp279 = (fSlow120 != fVec23[1]);
			iVec24[0] = iTemp279;
			int 	iTemp280 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec102[0] = ((iRec102[1] * (1 - iTemp280)) + (iTemp33 * iTemp280));
			float 	fTemp281 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec21[0] + (-1 - iRec102[0])))) > 0.5f) & iSlow121)) ? 0.0f : fSlow119) + 1.0f)) + 0.5f))];
			fVec25[0] = fTemp281;
			int 	iTemp282 = (fVec25[0] > 0.003f);
			int 	iTemp283 = (fVec25[0] <= 0.003f);
			float 	fTemp284 = float((iTemp283 | (fVec25[1] >= 0.003f)));
			fRec103[0] = max((fRec103[1] * fTemp284), fSlow120);
			fRec104[0] = max((fTemp284 * fRec104[1]), fSlow122);
			float 	fTemp285 = (min(1.0f, fRec104[0]) + min(1.0f, fRec103[0]));
			int 	iTemp286 = (fVec25[0] >= fRec101[1]);
			int 	iTemp287 = (fRec101[1] <= 0.001f);
			int 	iTemp288 = (((iRec100[1] >= 4)) ? (((iRec100[1] >= 6)) ? ((iTemp287) ? 0 : ((iTemp282) ? 1 : 6)) : (((iRec100[1] >= 5)) ? ((iTemp283) ? 3 : ((iTemp286) ? 4 : 5)) : ((iTemp283) ? 3 : (((fVec25[0] <= fRec101[1])) ? 5 : 4)))) : (((iRec100[1] >= 2)) ? (((iRec100[1] >= 3)) ? (((iTemp283 & iTemp287)) ? 0 : ((iTemp282) ? 1 : 3)) : ((iTemp282) ? ((iTemp286) ? 4 : 2) : 6)) : (((iRec100[1] >= 1)) ? (((fRec101[1] >= min(fTemp285, 1.0f))) ? ((iTemp283) ? 6 : 2) : 1) : ((iTemp282) ? 1 : 0))));
			iRec100[0] = iTemp288;
			float 	fTemp289 = (((iTemp288 >= 4)) ? (((iTemp288 >= 6)) ? fConst33 : fConst15) : (((iTemp288 >= 2)) ? (((iTemp288 >= 3)) ? fConst32 : fConst31) : (((iTemp288 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp290 = (iRec100[1] != iRec100[2]);
			iVec26[0] = iTemp290;
			int 	iTemp291 = ((iVec26[1] <= 0) & (iVec26[0] > 0));
			iRec106[0] = ((iRec106[1] * (1 - iTemp291)) + (iTemp33 * iTemp291));
			float 	fTemp292 = (2e+01f * (((fTemp289 > 0.0f)) ? (float((iRec21[0] + (-1 - iRec106[0]))) / fTemp289) : 0.0f));
			int 	iTemp293 = int(fTemp292);
			float 	fTemp294 = ftbl3[max(0, int(min(int(iTemp293), 20)))];
			float 	fTemp295 = (fTemp294 + ((fTemp292 - float(iTemp293)) * (ftbl3[max(0, int(min(int((iTemp293 + 1)), 20)))] - fTemp294)));
			fRec107[0] = max((fRec107[1] * float(iVec26[0])), max(fVec25[0], fRec101[1]));
			int 	iTemp296 = (iRec100[1] == 3);
			int 	iTemp297 = (iRec100[1] == 6);
			int 	iTemp298 = (iRec100[1] == 0);
			float 	fTemp299 = (((iRec100[1] == 1)) ? min(1.0f, fTemp285) : ((iTemp298) ? 0.0f : ((iTemp297) ? (fTemp285 * fTemp295) : ((iTemp296) ? (fRec107[0] * fTemp295) : fVec25[0]))));
			float 	fTemp300 = (1.0f / ((iTemp298) ? 0.0001f : (((iTemp296 | iTemp297)) ? (0.04761905f * fTemp289) : fTemp289)));
			float 	fTemp301 = (fRec105[1] - fTemp300);
			float 	fTemp302 = (fRec105[1] + fTemp300);
			fRec105[0] = (((fTemp302 < fTemp299)) ? fTemp302 : (((fTemp301 > fTemp299)) ? fTemp301 : fTemp299));
			fRec101[0] = fRec105[0];
			fRec99[0] = (fRec101[0] - (fConst30 * ((fConst28 * fRec99[2]) + (fConst26 * fRec99[1]))));
			float 	fTemp303 = min(0.99f, (fConst34 * (((3947.8418f * fRec99[0]) + (7895.6836f * fRec99[1])) + (3947.8418f * fRec99[2]))));
			int 	iTemp304 = (fTemp303 < 0.1f);
			float 	fTemp305 = (((iTemp304) ? fTemp303 : 0.1f) * fSlow118);
			fRec108[0] = (fTemp60 - (fSlow130 * ((fSlow128 * fRec108[2]) + (fSlow125 * fRec108[1]))));
			float 	fTemp306 = min(1.0f, (fSlow131 + ((iTemp304) ? (1.0f - (1e+01f * fTemp303)) : 0.0f)));
			float 	fTemp307 = ((iTemp21) ? 0.0f : (fSlow133 + fRec110[1]));
			fRec110[0] = (fTemp307 - floorf(fTemp307));
			float 	fTemp308 = (499.0f * fRec110[0]);
			int 	iTemp309 = int(fTemp308);
			int 	iTemp310 = max(0, min(iTemp309, 499));
			float 	fTemp311 = ftbl1[iTemp310];
			int 	iTemp312 = max(0, min((iTemp309 + 1), 499));
			float 	fTemp313 = (fTemp308 - float(iTemp309));
			float 	fTemp314 = float((((fVec25[1] <= 0.003f) & iTemp282) != 1));
			fRec111[0] = max((fTemp314 * fRec111[1]), fSlow134);
			fRec112[0] = max((fRec112[1] * fTemp314), fSlow116);
			float 	fTemp315 = max(min(((0.5f * (fVec25[0] - fTemp303)) + (0.2f - (0.8f * ((iTemp283) ? (2.0f * (((fRec112[0] > fRec111[0])) ? fRec112[0] : (0.0f - fRec111[0]))) : fSlow117)))), 1.0f), 0.0f);
			float 	fTemp316 = ftbl0[iTemp310];
			float 	fTemp317 = (((fTemp316 + (fTemp313 * (ftbl0[iTemp312] - fTemp316))) * (1.0f - fTemp315)) + (fTemp315 * (fTemp311 + (fTemp313 * (ftbl1[iTemp312] - fTemp311)))));
			float 	fTemp318 = (fRec109[1] - fConst40);
			float 	fTemp319 = (fConst40 + fRec109[1]);
			fRec109[0] = (((fTemp319 < fTemp317)) ? fTemp319 : (((fTemp318 > fTemp317)) ? fTemp318 : fTemp317));
			fRec11[0] = ((1.37f * ((((((fTemp303 * ((((1.1f * (fRec109[0] * (1.0f - fTemp306))) + (fSlow132 * (fTemp306 * (fRec108[0] - fRec108[2])))) * (1.0f - (0.5f * fTemp305))) + (0.5f * (fTemp305 * ((0.2f * (fTemp278 + ((fTemp276 - float(iTemp277)) * (ftbl1[max(0, min((iTemp277 + 1), 499))] - fTemp278)))) + (0.8f * (fTemp274 + ((fTemp272 - float(iTemp273)) * (ftbl0[max(0, min((iTemp273 + 1), 499))] - fTemp274))))))))) + (fTemp254 * ((((1.1f * (fRec93[0] * (1.0f - fTemp257))) + (fSlow110 * (fTemp257 * (fRec92[0] - fRec92[2])))) * (1.0f - (0.5f * fTemp256))) + (0.5f * (fTemp256 * ((0.2f * (fTemp229 + ((fTemp227 - float(iTemp228)) * (ftbl1[max(0, min((iTemp228 + 1), 499))] - fTemp229)))) + (0.8f * (fTemp225 + ((fTemp223 - float(iTemp224)) * (ftbl0[max(0, min((iTemp224 + 1), 499))] - fTemp225)))))))))) + (fTemp205 * ((((1.1f * (fRec77[0] * (1.0f - fTemp208))) + (fSlow88 * (fTemp208 * (fRec76[0] - fRec76[2])))) * (1.0f - (0.5f * fTemp207))) + (0.5f * (fTemp207 * ((0.2f * (fTemp180 + ((fTemp178 - float(iTemp179)) * (ftbl1[max(0, min((iTemp179 + 1), 499))] - fTemp180)))) + (0.8f * (fTemp176 + ((fTemp174 - float(iTemp175)) * (ftbl0[max(0, min((iTemp175 + 1), 499))] - fTemp176)))))))))) + (fTemp156 * ((((1.1f * (fRec61[0] * (1.0f - fTemp159))) + (fSlow66 * (fTemp159 * (fRec60[0] - fRec60[2])))) * (1.0f - (0.5f * fTemp158))) + (0.5f * (fTemp158 * ((0.2f * (fTemp131 + ((fTemp129 - float(iTemp130)) * (ftbl1[max(0, min((iTemp130 + 1), 499))] - fTemp131)))) + (0.8f * (fTemp127 + ((fTemp125 - float(iTemp126)) * (ftbl0[max(0, min((iTemp126 + 1), 499))] - fTemp127)))))))))) + (fTemp107 * ((((1.1f * (fRec45[0] * (1.0f - fTemp110))) + (fSlow44 * (fTemp110 * (fRec44[0] - fRec44[2])))) * (1.0f - (0.5f * fTemp109))) + (0.5f * (fTemp109 * ((0.2f * (fTemp82 + ((fTemp80 - float(iTemp81)) * (ftbl1[max(0, min((iTemp81 + 1), 499))] - fTemp82)))) + (0.8f * (fTemp78 + ((fTemp76 - float(iTemp77)) * (ftbl0[max(0, min((iTemp77 + 1), 499))] - fTemp78)))))))))) + (fTemp57 * ((((1.1f * (fRec29[0] * (1.0f - fTemp61))) + (fSlow22 * (fTemp61 * (fRec28[0] - fRec28[2])))) * (1.0f - (0.5f * fTemp59))) + (0.5f * (fTemp59 * ((0.2f * (fTemp29 + ((fTemp27 - float(iTemp28)) * (ftbl1[max(0, min((iTemp28 + 1), 499))] - fTemp29)))) + (0.8f * (fTemp25 + ((fTemp23 - float(iTemp24)) * (ftbl0[max(0, min((iTemp24 + 1), 499))] - fTemp25))))))))))) - (fConst8 * ((fConst6 * fRec11[2]) + (fConst4 * fRec11[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst41 * (fRec11[1] + fRec0[1])) + (fConst8 * ((fRec11[0] + fRec11[2]) + (fRec0[0] + fRec0[2])))));
			// post processing
			fRec11[2] = fRec11[1]; fRec11[1] = fRec11[0];
			fRec109[1] = fRec109[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec110[1] = fRec110[0];
			fRec108[2] = fRec108[1]; fRec108[1] = fRec108[0];
			fRec99[2] = fRec99[1]; fRec99[1] = fRec99[0];
			fRec101[1] = fRec101[0];
			fRec105[1] = fRec105[0];
			fRec107[1] = fRec107[0];
			iRec106[1] = iRec106[0];
			iVec26[1] = iVec26[0];
			iRec100[2] = iRec100[1]; iRec100[1] = iRec100[0];
			fRec104[1] = fRec104[0];
			fRec103[1] = fRec103[0];
			fVec25[1] = fVec25[0];
			iRec102[1] = iRec102[0];
			iVec24[1] = iVec24[0];
			fVec23[1] = fVec23[0];
			fRec98[1] = fRec98[0];
			fRec97[1] = fRec97[0];
			fRec93[1] = fRec93[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec94[1] = fRec94[0];
			fRec92[2] = fRec92[1]; fRec92[1] = fRec92[0];
			fRec83[2] = fRec83[1]; fRec83[1] = fRec83[0];
			fRec85[1] = fRec85[0];
			fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			iRec90[1] = iRec90[0];
			iVec22[1] = iVec22[0];
			iRec84[2] = iRec84[1]; iRec84[1] = iRec84[0];
			fRec88[1] = fRec88[0];
			fRec87[1] = fRec87[0];
			fVec21[1] = fVec21[0];
			iRec86[1] = iRec86[0];
			iVec20[1] = iVec20[0];
			fVec19[1] = fVec19[0];
			fRec82[1] = fRec82[0];
			fRec81[1] = fRec81[0];
			fRec77[1] = fRec77[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec78[1] = fRec78[0];
			fRec76[2] = fRec76[1]; fRec76[1] = fRec76[0];
			fRec67[2] = fRec67[1]; fRec67[1] = fRec67[0];
			fRec69[1] = fRec69[0];
			fRec73[1] = fRec73[0];
			fRec75[1] = fRec75[0];
			iRec74[1] = iRec74[0];
			iVec18[1] = iVec18[0];
			iRec68[2] = iRec68[1]; iRec68[1] = iRec68[0];
			fRec72[1] = fRec72[0];
			fRec71[1] = fRec71[0];
			fVec17[1] = fVec17[0];
			iRec70[1] = iRec70[0];
			iVec16[1] = iVec16[0];
			fVec15[1] = fVec15[0];
			fRec66[1] = fRec66[0];
			fRec65[1] = fRec65[0];
			fRec61[1] = fRec61[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec62[1] = fRec62[0];
			fRec60[2] = fRec60[1]; fRec60[1] = fRec60[0];
			fRec51[2] = fRec51[1]; fRec51[1] = fRec51[0];
			fRec53[1] = fRec53[0];
			fRec57[1] = fRec57[0];
			fRec59[1] = fRec59[0];
			iRec58[1] = iRec58[0];
			iVec14[1] = iVec14[0];
			iRec52[2] = iRec52[1]; iRec52[1] = iRec52[0];
			fRec56[1] = fRec56[0];
			fRec55[1] = fRec55[0];
			fVec13[1] = fVec13[0];
			iRec54[1] = iRec54[0];
			iVec12[1] = iVec12[0];
			fVec11[1] = fVec11[0];
			fRec50[1] = fRec50[0];
			fRec49[1] = fRec49[0];
			fRec45[1] = fRec45[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec46[1] = fRec46[0];
			fRec44[2] = fRec44[1]; fRec44[1] = fRec44[0];
			fRec35[2] = fRec35[1]; fRec35[1] = fRec35[0];
			fRec37[1] = fRec37[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			iRec42[1] = iRec42[0];
			iVec10[1] = iVec10[0];
			iRec36[2] = iRec36[1]; iRec36[1] = iRec36[0];
			fRec40[1] = fRec40[0];
			fRec39[1] = fRec39[0];
			fVec9[1] = fVec9[0];
			iRec38[1] = iRec38[0];
			iVec8[1] = iVec8[0];
			fVec7[1] = fVec7[0];
			fRec34[1] = fRec34[0];
			fRec33[1] = fRec33[0];
			fRec29[1] = fRec29[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec30[1] = fRec30[0];
			fRec28[2] = fRec28[1]; fRec28[1] = fRec28[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			fRec19[1] = fRec19[0];
			fRec24[1] = fRec24[0];
			fRec27[1] = fRec27[0];
			iRec26[1] = iRec26[0];
			iVec6[1] = iVec6[0];
			iRec18[2] = iRec18[1]; iRec18[1] = iRec18[0];
			fRec23[1] = fRec23[0];
			fRec22[1] = fRec22[0];
			fVec5[1] = fVec5[0];
			iRec20[1] = iRec20[0];
			iRec21[1] = iRec21[0];
			iVec4[1] = iVec4[0];
			fVec3[1] = fVec3[0];
			fRec15[1] = fRec15[0];
			fRec13[1] = fRec13[0];
			fRec0[2] = fRec0[1]; fRec0[1] = fRec0[0];
			fRec8[1] = fRec8[0];
			fRec10[1] = fRec10[0];
			iRec9[1] = iRec9[0];
			fRec4[2] = fRec4[1]; fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			iRec5[1] = iRec5[0];
			iRec3[1] = iRec3[0];
			iVec2[1] = iVec2[0];
			fVec1[1] = fVec1[0];
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
