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
<<<<<<< HEAD
	float 	fRec11[2];
	float 	fConst19;
	float 	fRec9[2];
	float 	fConst20;
	float 	fRec7[2];
	float 	fConst21;
	float 	fRec0[3];
	static float 	ftbl0[500];
=======
	int 	iRec9[2];
	float 	fConst11;
	float 	fVec3[2];
	float 	fRec11[2];
	float 	fRec12[2];
	int 	iRec7[3];
	static float 	ftbl3[21];
	float 	fConst12;
	float 	fConst13;
	float 	fConst14;
	float 	fConst15;
	int 	iVec4[2];
	int 	iRec15[2];
	float 	fRec16[2];
	float 	fRec13[2];
	float 	fRec8[2];
	float 	fConst16;
	float 	fRec6[2];
	float 	fConst17;
	float 	fConst18;
	float 	fConst19;
	int 	iRec18[2];
	float 	fRec17[3];
	float 	fConst20;
	float 	fConst21;
	float 	fRec20[2];
	float 	fRec21[2];
	float 	fRec22[2];
	float 	fConst22;
	float 	fRec19[2];
>>>>>>> main
	FAUSTFLOAT 	fslider4;
	float 	fConst22;
	float 	fRec14[2];
	static float 	ftbl1[500];
	float 	fConst23;
	float 	fRec16[2];
	static float 	ftbl2[1000];
	FAUSTFLOAT 	fslider5;
	float 	fConst27;
	float 	fConst29;
	float 	fConst31;
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
	float 	fConst32;
	float 	fConst33;
	float 	fConst34;
	int 	iVec6[2];
	int 	iRec27[2];
	float 	fRec28[2];
	float 	fRec25[2];
	float 	fRec20[2];
	float 	fRec18[3];
	float 	fConst35;
	float 	fConst36;
	float 	fConst37;
	float 	fConst38;
	float 	fRec29[3];
	float 	fConst39;
	float 	fConst40;
	float 	fRec31[2];
<<<<<<< HEAD
	float 	fRec32[2];
	float 	fRec33[2];
	float 	fConst41;
	float 	fRec30[2];
=======
	float 	fRec27[2];
	float 	fRec25[2];
	float 	fRec34[3];
	float 	fRec36[2];
	float 	fRec37[2];
	float 	fRec38[2];
	float 	fRec35[2];
>>>>>>> main
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
	float 	fRec36[3];
	float 	fRec45[3];
	float 	fRec47[2];
<<<<<<< HEAD
	float 	fRec48[2];
	float 	fRec49[2];
	float 	fRec46[2];
=======
	float 	fRec43[2];
	float 	fRec41[2];
	float 	fRec50[3];
	float 	fRec52[2];
	float 	fRec53[2];
	float 	fRec54[2];
	float 	fRec51[2];
>>>>>>> main
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
	float 	fRec52[3];
	float 	fRec61[3];
	float 	fRec63[2];
<<<<<<< HEAD
	float 	fRec64[2];
	float 	fRec65[2];
	float 	fRec62[2];
=======
	float 	fRec59[2];
	float 	fRec57[2];
	float 	fRec66[3];
	float 	fRec68[2];
	float 	fRec69[2];
	float 	fRec70[2];
	float 	fRec67[2];
>>>>>>> main
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
	float 	fRec68[3];
	float 	fRec77[3];
	float 	fRec79[2];
<<<<<<< HEAD
	float 	fRec80[2];
	float 	fRec81[2];
	float 	fRec78[2];
=======
	float 	fRec75[2];
	float 	fRec73[2];
	float 	fRec82[3];
	float 	fRec84[2];
	float 	fRec85[2];
	float 	fRec86[2];
	float 	fRec83[2];
>>>>>>> main
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
	float 	fRec84[3];
	float 	fRec93[3];
	float 	fRec95[2];
<<<<<<< HEAD
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
	float 	fRec100[3];
	float 	fRec109[3];
	float 	fRec111[2];
	float 	fRec112[2];
	float 	fRec113[2];
	float 	fRec110[2];
	float 	fRec12[3];
	float 	fConst42;
=======
	float 	fRec91[2];
	float 	fRec89[2];
	float 	fRec98[3];
	float 	fRec100[2];
	float 	fRec101[2];
	float 	fRec102[2];
	float 	fRec99[2];
	float 	fRec0[3];
	float 	fConst23;
>>>>>>> main
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
<<<<<<< HEAD
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
		fConst20 = (1e+04f / fConst0);
		fConst21 = (0.10759955f / fConst0);
		fConst22 = (4.0878997f / fConst0);
		fConst23 = (2.0439498f / fConst0);
		float 	fConst24 = powf((62.831852f / fConst0),2.0f);
		float 	fConst25 = ((fConst24 * ((0.2033f * fConst24) + 0.31755f)) + 1.0f);
		float 	fConst26 = powf(fConst25,2.0f);
		fConst27 = (2.0f * ((3947.8418f * (fConst26 / fConst1)) + -1.0f));
		float 	fConst28 = (3947.8418f * (fConst25 / fConst0));
		fConst29 = (((fConst25 * (fConst28 + -88.49557f)) / fConst0) + 1.0f);
		float 	fConst30 = (((fConst25 * (fConst28 + 88.49557f)) / fConst0) + 1.0f);
		fConst31 = (1.0f / fConst30);
		fConst32 = (0.4f * fConst0);
		fConst33 = (0.15f * fConst0);
		fConst34 = (0.75f * fConst0);
		fConst35 = (fConst26 / (fConst1 * fConst30));
		fConst36 = (25.68503f / fConst0);
		fConst37 = (659.72076f / fConst1);
		fConst38 = (659.72076f / fConst0);
		fConst39 = (0.2568503f / fConst0);
		fConst40 = (8.175799f / fConst0);
		fConst41 = (3333.3333f / fConst0);
		fConst42 = (0.0f - (2.0f / fConst7));
=======
		fConst9 = (4.0878997f / fConst0);
		fConst10 = (2.0439498f / fConst0);
		fConst11 = (1.0f / fConst0);
		fConst12 = (0.2f * fConst0);
		fConst13 = (0.5f * fConst0);
		fConst14 = (0.15f * fConst0);
		fConst15 = (0.8f * fConst0);
		fConst16 = (2e+01f / fConst0);
		fConst17 = (25.68503f / fConst0);
		fConst18 = (659.72076f / fConst1);
		fConst19 = (659.72076f / fConst0);
		fConst20 = (0.2568503f / fConst0);
		fConst21 = (8.175799f / fConst0);
		fConst22 = (3333.3333f / fConst0);
		fConst23 = (0.0f - (2.0f / fConst7));
>>>>>>> main
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
<<<<<<< HEAD
		for (int i=0; i<2; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) iVec4[i] = 0;
		for (int i=0; i<2; i++) iRec22[i] = 0;
		for (int i=0; i<2; i++) iRec21[i] = 0;
		for (int i=0; i<2; i++) fVec5[i] = 0;
=======
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) iRec18[i] = 0;
		for (int i=0; i<3; i++) fRec17[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
>>>>>>> main
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
		for (int i=0; i<3; i++) iRec19[i] = 0;
		for (int i=0; i<2; i++) iVec6[i] = 0;
		for (int i=0; i<2; i++) iRec27[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<3; i++) fRec18[i] = 0;
		for (int i=0; i<3; i++) fRec29[i] = 0;
		for (int i=0; i<2; i++) fRec31[i] = 0;
<<<<<<< HEAD
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<2; i++) fRec34[i] = 0;
=======
		for (int i=0; i<2; i++) fRec27[i] = 0;
		for (int i=0; i<2; i++) fRec25[i] = 0;
		for (int i=0; i<3; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2; i++) fRec38[i] = 0;
>>>>>>> main
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
		for (int i=0; i<3; i++) fRec36[i] = 0;
		for (int i=0; i<3; i++) fRec45[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
<<<<<<< HEAD
		for (int i=0; i<2; i++) fRec48[i] = 0;
		for (int i=0; i<2; i++) fRec49[i] = 0;
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<2; i++) fRec50[i] = 0;
=======
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<3; i++) fRec50[i] = 0;
		for (int i=0; i<2; i++) fRec52[i] = 0;
		for (int i=0; i<2; i++) fRec53[i] = 0;
		for (int i=0; i<2; i++) fRec54[i] = 0;
>>>>>>> main
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
		for (int i=0; i<3; i++) fRec52[i] = 0;
		for (int i=0; i<3; i++) fRec61[i] = 0;
		for (int i=0; i<2; i++) fRec63[i] = 0;
<<<<<<< HEAD
		for (int i=0; i<2; i++) fRec64[i] = 0;
		for (int i=0; i<2; i++) fRec65[i] = 0;
		for (int i=0; i<2; i++) fRec62[i] = 0;
		for (int i=0; i<2; i++) fRec66[i] = 0;
=======
		for (int i=0; i<2; i++) fRec59[i] = 0;
		for (int i=0; i<2; i++) fRec57[i] = 0;
		for (int i=0; i<3; i++) fRec66[i] = 0;
		for (int i=0; i<2; i++) fRec68[i] = 0;
		for (int i=0; i<2; i++) fRec69[i] = 0;
		for (int i=0; i<2; i++) fRec70[i] = 0;
>>>>>>> main
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
		for (int i=0; i<3; i++) fRec68[i] = 0;
		for (int i=0; i<3; i++) fRec77[i] = 0;
		for (int i=0; i<2; i++) fRec79[i] = 0;
<<<<<<< HEAD
		for (int i=0; i<2; i++) fRec80[i] = 0;
		for (int i=0; i<2; i++) fRec81[i] = 0;
		for (int i=0; i<2; i++) fRec78[i] = 0;
		for (int i=0; i<2; i++) fRec82[i] = 0;
=======
		for (int i=0; i<2; i++) fRec75[i] = 0;
		for (int i=0; i<2; i++) fRec73[i] = 0;
		for (int i=0; i<3; i++) fRec82[i] = 0;
		for (int i=0; i<2; i++) fRec84[i] = 0;
		for (int i=0; i<2; i++) fRec85[i] = 0;
		for (int i=0; i<2; i++) fRec86[i] = 0;
>>>>>>> main
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
		for (int i=0; i<3; i++) fRec84[i] = 0;
		for (int i=0; i<3; i++) fRec93[i] = 0;
		for (int i=0; i<2; i++) fRec95[i] = 0;
<<<<<<< HEAD
		for (int i=0; i<2; i++) fRec96[i] = 0;
		for (int i=0; i<2; i++) fRec97[i] = 0;
		for (int i=0; i<2; i++) fRec94[i] = 0;
		for (int i=0; i<2; i++) fRec98[i] = 0;
=======
		for (int i=0; i<2; i++) fRec91[i] = 0;
		for (int i=0; i<2; i++) fRec89[i] = 0;
		for (int i=0; i<3; i++) fRec98[i] = 0;
		for (int i=0; i<2; i++) fRec100[i] = 0;
		for (int i=0; i<2; i++) fRec101[i] = 0;
		for (int i=0; i<2; i++) fRec102[i] = 0;
>>>>>>> main
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
		for (int i=0; i<3; i++) fRec100[i] = 0;
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
<<<<<<< HEAD
		float 	fSlow0 = fabsf(float(fslider0));
		int 	iSlow1 = (float(fslider2) < (0.0f - float(fslider1)));
		float 	fSlow2 = fabsf(float(fslider3));
		float 	fSlow3 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow4 = (fConst22 * fSlow3);
		float 	fSlow5 = (fConst23 * fSlow3);
		float 	fSlow6 = float(fslider5);
		float 	fSlow7 = ftbl2[int(((499.5f * (fSlow6 + 1.0f)) + 0.5f))];
		float 	fSlow8 = (fSlow7 + 1.0f);
		float 	fSlow9 = float(fslider6);
		float 	fSlow10 = float(fslider7);
		int 	iSlow11 = (fSlow10 == 0.0f);
		float 	fSlow12 = (0.0f - fSlow10);
		float 	fSlow13 = powf((fConst36 * fSlow3),2.0f);
		float 	fSlow14 = ((fSlow13 * ((0.2033f * fSlow13) + 0.31755f)) + 1.0f);
		float 	fSlow15 = (2.0f * ((fConst37 * (powf(fSlow3,2.0f) * powf(fSlow14,2.0f))) + -1.0f));
		float 	fSlow16 = (fSlow3 * fSlow14);
		float 	fSlow17 = (fConst38 * fSlow16);
		float 	fSlow18 = ((fConst12 * (fSlow16 * (fSlow17 + -0.2568503f))) + 1.0f);
		float 	fSlow19 = ((fConst12 * (fSlow16 * (fSlow17 + 0.2568503f))) + 1.0f);
		float 	fSlow20 = (1.0f / fSlow19);
		float 	fSlow21 = max(0.05f, (0.1f - fabsf(fSlow10)));
		float 	fSlow22 = (fConst39 * (fSlow16 / fSlow19));
		float 	fSlow23 = (fConst40 * fSlow3);
		float 	fSlow24 = (0.0f - fSlow6);
		float 	fSlow25 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow26 = (fConst22 * fSlow25);
		float 	fSlow27 = (fConst23 * fSlow25);
		float 	fSlow28 = float(fslider9);
		float 	fSlow29 = ftbl2[int(((499.5f * (fSlow28 + 1.0f)) + 0.5f))];
		float 	fSlow30 = (fSlow29 + 1.0f);
		float 	fSlow31 = float(fslider10);
		float 	fSlow32 = float(fslider11);
		int 	iSlow33 = (fSlow32 == 0.0f);
		float 	fSlow34 = (0.0f - fSlow32);
		float 	fSlow35 = powf((fConst36 * fSlow25),2.0f);
		float 	fSlow36 = ((fSlow35 * ((0.2033f * fSlow35) + 0.31755f)) + 1.0f);
		float 	fSlow37 = (2.0f * ((fConst37 * (powf(fSlow25,2.0f) * powf(fSlow36,2.0f))) + -1.0f));
		float 	fSlow38 = (fSlow25 * fSlow36);
		float 	fSlow39 = (fConst38 * fSlow38);
		float 	fSlow40 = ((fConst12 * (fSlow38 * (fSlow39 + -0.2568503f))) + 1.0f);
		float 	fSlow41 = ((fConst12 * (fSlow38 * (fSlow39 + 0.2568503f))) + 1.0f);
		float 	fSlow42 = (1.0f / fSlow41);
		float 	fSlow43 = max(0.05f, (0.1f - fabsf(fSlow32)));
		float 	fSlow44 = (fConst39 * (fSlow38 / fSlow41));
		float 	fSlow45 = (fConst40 * fSlow25);
		float 	fSlow46 = (0.0f - fSlow28);
		float 	fSlow47 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow48 = (fConst22 * fSlow47);
		float 	fSlow49 = (fConst23 * fSlow47);
		float 	fSlow50 = float(fslider13);
		float 	fSlow51 = ftbl2[int(((499.5f * (fSlow50 + 1.0f)) + 0.5f))];
		float 	fSlow52 = (fSlow51 + 1.0f);
		float 	fSlow53 = float(fslider14);
		float 	fSlow54 = float(fslider15);
		int 	iSlow55 = (fSlow54 == 0.0f);
		float 	fSlow56 = (0.0f - fSlow54);
		float 	fSlow57 = powf((fConst36 * fSlow47),2.0f);
		float 	fSlow58 = ((fSlow57 * ((0.2033f * fSlow57) + 0.31755f)) + 1.0f);
		float 	fSlow59 = (2.0f * ((fConst37 * (powf(fSlow47,2.0f) * powf(fSlow58,2.0f))) + -1.0f));
		float 	fSlow60 = (fSlow47 * fSlow58);
		float 	fSlow61 = (fConst38 * fSlow60);
		float 	fSlow62 = ((fConst12 * (fSlow60 * (fSlow61 + -0.2568503f))) + 1.0f);
		float 	fSlow63 = ((fConst12 * (fSlow60 * (fSlow61 + 0.2568503f))) + 1.0f);
		float 	fSlow64 = (1.0f / fSlow63);
		float 	fSlow65 = max(0.05f, (0.1f - fabsf(fSlow54)));
		float 	fSlow66 = (fConst39 * (fSlow60 / fSlow63));
		float 	fSlow67 = (fConst40 * fSlow47);
		float 	fSlow68 = (0.0f - fSlow50);
		float 	fSlow69 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow70 = (fConst22 * fSlow69);
		float 	fSlow71 = (fConst23 * fSlow69);
		float 	fSlow72 = float(fslider17);
		float 	fSlow73 = ftbl2[int(((499.5f * (fSlow72 + 1.0f)) + 0.5f))];
		float 	fSlow74 = (fSlow73 + 1.0f);
		float 	fSlow75 = float(fslider18);
		float 	fSlow76 = float(fslider19);
		int 	iSlow77 = (fSlow76 == 0.0f);
		float 	fSlow78 = (0.0f - fSlow76);
		float 	fSlow79 = powf((fConst36 * fSlow69),2.0f);
		float 	fSlow80 = ((fSlow79 * ((0.2033f * fSlow79) + 0.31755f)) + 1.0f);
		float 	fSlow81 = (2.0f * ((fConst37 * (powf(fSlow69,2.0f) * powf(fSlow80,2.0f))) + -1.0f));
		float 	fSlow82 = (fSlow69 * fSlow80);
		float 	fSlow83 = (fConst38 * fSlow82);
		float 	fSlow84 = ((fConst12 * (fSlow82 * (fSlow83 + -0.2568503f))) + 1.0f);
		float 	fSlow85 = ((fConst12 * (fSlow82 * (fSlow83 + 0.2568503f))) + 1.0f);
		float 	fSlow86 = (1.0f / fSlow85);
		float 	fSlow87 = max(0.05f, (0.1f - fabsf(fSlow76)));
		float 	fSlow88 = (fConst39 * (fSlow82 / fSlow85));
		float 	fSlow89 = (fConst40 * fSlow69);
		float 	fSlow90 = (0.0f - fSlow72);
		float 	fSlow91 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow92 = (fConst22 * fSlow91);
		float 	fSlow93 = (fConst23 * fSlow91);
		float 	fSlow94 = float(fslider21);
		float 	fSlow95 = ftbl2[int(((499.5f * (fSlow94 + 1.0f)) + 0.5f))];
		float 	fSlow96 = (fSlow95 + 1.0f);
		float 	fSlow97 = float(fslider22);
		float 	fSlow98 = float(fslider23);
		int 	iSlow99 = (fSlow98 == 0.0f);
		float 	fSlow100 = (0.0f - fSlow98);
		float 	fSlow101 = powf((fConst36 * fSlow91),2.0f);
		float 	fSlow102 = ((fSlow101 * ((0.2033f * fSlow101) + 0.31755f)) + 1.0f);
		float 	fSlow103 = (2.0f * ((fConst37 * (powf(fSlow91,2.0f) * powf(fSlow102,2.0f))) + -1.0f));
		float 	fSlow104 = (fSlow91 * fSlow102);
		float 	fSlow105 = (fConst38 * fSlow104);
		float 	fSlow106 = ((fConst12 * (fSlow104 * (fSlow105 + -0.2568503f))) + 1.0f);
		float 	fSlow107 = ((fConst12 * (fSlow104 * (fSlow105 + 0.2568503f))) + 1.0f);
		float 	fSlow108 = (1.0f / fSlow107);
		float 	fSlow109 = max(0.05f, (0.1f - fabsf(fSlow98)));
		float 	fSlow110 = (fConst39 * (fSlow104 / fSlow107));
		float 	fSlow111 = (fConst40 * fSlow91);
		float 	fSlow112 = (0.0f - fSlow94);
		float 	fSlow113 = fastpow2((0.083333336f * float(fslider24)));
		float 	fSlow114 = (fConst22 * fSlow113);
		float 	fSlow115 = (fConst23 * fSlow113);
		float 	fSlow116 = float(fslider25);
		float 	fSlow117 = ftbl2[int(((499.5f * (fSlow116 + 1.0f)) + 0.5f))];
		float 	fSlow118 = (fSlow117 + 1.0f);
		float 	fSlow119 = float(fslider26);
		float 	fSlow120 = float(fslider27);
		int 	iSlow121 = (fSlow120 == 0.0f);
		float 	fSlow122 = (0.0f - fSlow120);
		float 	fSlow123 = powf((fConst36 * fSlow113),2.0f);
		float 	fSlow124 = ((fSlow123 * ((0.2033f * fSlow123) + 0.31755f)) + 1.0f);
		float 	fSlow125 = (2.0f * ((fConst37 * (powf(fSlow113,2.0f) * powf(fSlow124,2.0f))) + -1.0f));
		float 	fSlow126 = (fSlow113 * fSlow124);
		float 	fSlow127 = (fConst38 * fSlow126);
		float 	fSlow128 = ((fConst12 * (fSlow126 * (fSlow127 + -0.2568503f))) + 1.0f);
		float 	fSlow129 = ((fConst12 * (fSlow126 * (fSlow127 + 0.2568503f))) + 1.0f);
		float 	fSlow130 = (1.0f / fSlow129);
		float 	fSlow131 = max(0.05f, (0.1f - fabsf(fSlow120)));
		float 	fSlow132 = (fConst39 * (fSlow126 / fSlow129));
		float 	fSlow133 = (fConst40 * fSlow113);
		float 	fSlow134 = (0.0f - fSlow116);
=======
		float 	fSlow0 = fastpow2((0.083333336f * float(fslider0)));
		float 	fSlow1 = (fConst9 * fSlow0);
		float 	fSlow2 = (fConst10 * fSlow0);
		float 	fSlow3 = float(fslider1);
		float 	fSlow4 = ftbl2[int(((499.5f * (fSlow3 + 1.0f)) + 0.5f))];
		float 	fSlow5 = (fSlow4 + 1.0f);
		float 	fSlow6 = float(fslider2);
		float 	fSlow7 = float(fslider3);
		int 	iSlow8 = (fSlow7 == 0.0f);
		float 	fSlow9 = (0.0f - fSlow7);
		float 	fSlow10 = powf((fConst17 * fSlow0),2.0f);
		float 	fSlow11 = ((fSlow10 * ((0.2033f * fSlow10) + 0.31755f)) + 1.0f);
		float 	fSlow12 = (2.0f * ((fConst18 * (powf(fSlow0,2.0f) * powf(fSlow11,2.0f))) + -1.0f));
		float 	fSlow13 = (fSlow0 * fSlow11);
		float 	fSlow14 = (fConst19 * fSlow13);
		float 	fSlow15 = ((fConst11 * (fSlow13 * (fSlow14 + -0.2568503f))) + 1.0f);
		float 	fSlow16 = ((fConst11 * (fSlow13 * (fSlow14 + 0.2568503f))) + 1.0f);
		float 	fSlow17 = (1.0f / fSlow16);
		float 	fSlow18 = max(0.05f, (0.1f - fabsf(fSlow7)));
		float 	fSlow19 = (fConst20 * (fSlow13 / fSlow16));
		float 	fSlow20 = (fConst21 * fSlow0);
		float 	fSlow21 = (0.0f - fSlow3);
		float 	fSlow22 = fastpow2((0.083333336f * float(fslider4)));
		float 	fSlow23 = (fConst9 * fSlow22);
		float 	fSlow24 = (fConst10 * fSlow22);
		float 	fSlow25 = float(fslider5);
		float 	fSlow26 = ftbl2[int(((499.5f * (fSlow25 + 1.0f)) + 0.5f))];
		float 	fSlow27 = (fSlow26 + 1.0f);
		float 	fSlow28 = float(fslider6);
		float 	fSlow29 = float(fslider7);
		int 	iSlow30 = (fSlow29 == 0.0f);
		float 	fSlow31 = (0.0f - fSlow29);
		float 	fSlow32 = powf((fConst17 * fSlow22),2.0f);
		float 	fSlow33 = ((fSlow32 * ((0.2033f * fSlow32) + 0.31755f)) + 1.0f);
		float 	fSlow34 = (2.0f * ((fConst18 * (powf(fSlow22,2.0f) * powf(fSlow33,2.0f))) + -1.0f));
		float 	fSlow35 = (fSlow22 * fSlow33);
		float 	fSlow36 = (fConst19 * fSlow35);
		float 	fSlow37 = ((fConst11 * (fSlow35 * (fSlow36 + -0.2568503f))) + 1.0f);
		float 	fSlow38 = ((fConst11 * (fSlow35 * (fSlow36 + 0.2568503f))) + 1.0f);
		float 	fSlow39 = (1.0f / fSlow38);
		float 	fSlow40 = max(0.05f, (0.1f - fabsf(fSlow29)));
		float 	fSlow41 = (fConst20 * (fSlow35 / fSlow38));
		float 	fSlow42 = (fConst21 * fSlow22);
		float 	fSlow43 = (0.0f - fSlow25);
		float 	fSlow44 = fastpow2((0.083333336f * float(fslider8)));
		float 	fSlow45 = (fConst9 * fSlow44);
		float 	fSlow46 = (fConst10 * fSlow44);
		float 	fSlow47 = float(fslider9);
		float 	fSlow48 = ftbl2[int(((499.5f * (fSlow47 + 1.0f)) + 0.5f))];
		float 	fSlow49 = (fSlow48 + 1.0f);
		float 	fSlow50 = float(fslider10);
		float 	fSlow51 = float(fslider11);
		int 	iSlow52 = (fSlow51 == 0.0f);
		float 	fSlow53 = (0.0f - fSlow51);
		float 	fSlow54 = powf((fConst17 * fSlow44),2.0f);
		float 	fSlow55 = ((fSlow54 * ((0.2033f * fSlow54) + 0.31755f)) + 1.0f);
		float 	fSlow56 = (2.0f * ((fConst18 * (powf(fSlow44,2.0f) * powf(fSlow55,2.0f))) + -1.0f));
		float 	fSlow57 = (fSlow44 * fSlow55);
		float 	fSlow58 = (fConst19 * fSlow57);
		float 	fSlow59 = ((fConst11 * (fSlow57 * (fSlow58 + -0.2568503f))) + 1.0f);
		float 	fSlow60 = ((fConst11 * (fSlow57 * (fSlow58 + 0.2568503f))) + 1.0f);
		float 	fSlow61 = (1.0f / fSlow60);
		float 	fSlow62 = max(0.05f, (0.1f - fabsf(fSlow51)));
		float 	fSlow63 = (fConst20 * (fSlow57 / fSlow60));
		float 	fSlow64 = (fConst21 * fSlow44);
		float 	fSlow65 = (0.0f - fSlow47);
		float 	fSlow66 = fastpow2((0.083333336f * float(fslider12)));
		float 	fSlow67 = (fConst9 * fSlow66);
		float 	fSlow68 = (fConst10 * fSlow66);
		float 	fSlow69 = float(fslider13);
		float 	fSlow70 = ftbl2[int(((499.5f * (fSlow69 + 1.0f)) + 0.5f))];
		float 	fSlow71 = (fSlow70 + 1.0f);
		float 	fSlow72 = float(fslider14);
		float 	fSlow73 = float(fslider15);
		int 	iSlow74 = (fSlow73 == 0.0f);
		float 	fSlow75 = (0.0f - fSlow73);
		float 	fSlow76 = powf((fConst17 * fSlow66),2.0f);
		float 	fSlow77 = ((fSlow76 * ((0.2033f * fSlow76) + 0.31755f)) + 1.0f);
		float 	fSlow78 = (2.0f * ((fConst18 * (powf(fSlow66,2.0f) * powf(fSlow77,2.0f))) + -1.0f));
		float 	fSlow79 = (fSlow66 * fSlow77);
		float 	fSlow80 = (fConst19 * fSlow79);
		float 	fSlow81 = ((fConst11 * (fSlow79 * (fSlow80 + -0.2568503f))) + 1.0f);
		float 	fSlow82 = ((fConst11 * (fSlow79 * (fSlow80 + 0.2568503f))) + 1.0f);
		float 	fSlow83 = (1.0f / fSlow82);
		float 	fSlow84 = max(0.05f, (0.1f - fabsf(fSlow73)));
		float 	fSlow85 = (fConst20 * (fSlow79 / fSlow82));
		float 	fSlow86 = (fConst21 * fSlow66);
		float 	fSlow87 = (0.0f - fSlow69);
		float 	fSlow88 = fastpow2((0.083333336f * float(fslider16)));
		float 	fSlow89 = (fConst9 * fSlow88);
		float 	fSlow90 = (fConst10 * fSlow88);
		float 	fSlow91 = float(fslider17);
		float 	fSlow92 = ftbl2[int(((499.5f * (fSlow91 + 1.0f)) + 0.5f))];
		float 	fSlow93 = (fSlow92 + 1.0f);
		float 	fSlow94 = float(fslider18);
		float 	fSlow95 = float(fslider19);
		int 	iSlow96 = (fSlow95 == 0.0f);
		float 	fSlow97 = (0.0f - fSlow95);
		float 	fSlow98 = powf((fConst17 * fSlow88),2.0f);
		float 	fSlow99 = ((fSlow98 * ((0.2033f * fSlow98) + 0.31755f)) + 1.0f);
		float 	fSlow100 = (2.0f * ((fConst18 * (powf(fSlow88,2.0f) * powf(fSlow99,2.0f))) + -1.0f));
		float 	fSlow101 = (fSlow88 * fSlow99);
		float 	fSlow102 = (fConst19 * fSlow101);
		float 	fSlow103 = ((fConst11 * (fSlow101 * (fSlow102 + -0.2568503f))) + 1.0f);
		float 	fSlow104 = ((fConst11 * (fSlow101 * (fSlow102 + 0.2568503f))) + 1.0f);
		float 	fSlow105 = (1.0f / fSlow104);
		float 	fSlow106 = max(0.05f, (0.1f - fabsf(fSlow95)));
		float 	fSlow107 = (fConst20 * (fSlow101 / fSlow104));
		float 	fSlow108 = (fConst21 * fSlow88);
		float 	fSlow109 = (0.0f - fSlow91);
		float 	fSlow110 = fastpow2((0.083333336f * float(fslider20)));
		float 	fSlow111 = (fConst9 * fSlow110);
		float 	fSlow112 = (fConst10 * fSlow110);
		float 	fSlow113 = float(fslider21);
		float 	fSlow114 = ftbl2[int(((499.5f * (fSlow113 + 1.0f)) + 0.5f))];
		float 	fSlow115 = (fSlow114 + 1.0f);
		float 	fSlow116 = float(fslider22);
		float 	fSlow117 = float(fslider23);
		int 	iSlow118 = (fSlow117 == 0.0f);
		float 	fSlow119 = (0.0f - fSlow117);
		float 	fSlow120 = powf((fConst17 * fSlow110),2.0f);
		float 	fSlow121 = ((fSlow120 * ((0.2033f * fSlow120) + 0.31755f)) + 1.0f);
		float 	fSlow122 = (2.0f * ((fConst18 * (powf(fSlow110,2.0f) * powf(fSlow121,2.0f))) + -1.0f));
		float 	fSlow123 = (fSlow110 * fSlow121);
		float 	fSlow124 = (fConst19 * fSlow123);
		float 	fSlow125 = ((fConst11 * (fSlow123 * (fSlow124 + -0.2568503f))) + 1.0f);
		float 	fSlow126 = ((fConst11 * (fSlow123 * (fSlow124 + 0.2568503f))) + 1.0f);
		float 	fSlow127 = (1.0f / fSlow126);
		float 	fSlow128 = max(0.05f, (0.1f - fabsf(fSlow117)));
		float 	fSlow129 = (fConst20 * (fSlow123 / fSlow126));
		float 	fSlow130 = (fConst21 * fSlow110);
		float 	fSlow131 = (0.0f - fSlow113);
>>>>>>> main
		//zone2b
		//zone3
		FAUSTFLOAT* output0 = output[0];
		//LoopGraphScalar
		for (int i=0; i<count; i++) {
			iVec0[0] = 1;
<<<<<<< HEAD
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
			float 	fTemp20 = (fRec7[1] - fConst20);
			float 	fTemp21 = (fConst20 + fRec7[1]);
			fRec7[0] = (((fTemp21 < fTemp19)) ? fTemp21 : (((fTemp20 > fTemp19)) ? fTemp20 : fTemp19));
			fRec0[0] = ((fConst21 * ((((fRec7[0] * fTemp1) * fTemp3) * (fRec3[0] - fRec3[2])) / fTemp6)) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
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
			float 	fTemp41 = (min(1.0f, fRec24[0]) + min(1.0f, fRec23[0]));
			int 	iTemp42 = (fVec5[0] >= fRec20[1]);
			int 	iTemp43 = (fRec20[1] <= 0.001f);
			int 	iTemp44 = (((iRec19[1] >= 4)) ? (((iRec19[1] >= 6)) ? ((iTemp43) ? 0 : ((iTemp38) ? 1 : 6)) : (((iRec19[1] >= 5)) ? ((iTemp39) ? 3 : ((iTemp42) ? 4 : 5)) : ((iTemp39) ? 3 : (((fVec5[0] <= fRec20[1])) ? 5 : 4)))) : (((iRec19[1] >= 2)) ? (((iRec19[1] >= 3)) ? (((iTemp39 & iTemp43)) ? 0 : ((iTemp38) ? 1 : 3)) : ((iTemp38) ? ((iTemp42) ? 4 : 2) : 6)) : (((iRec19[1] >= 1)) ? (((fRec20[1] >= min(fTemp41, 1.0f))) ? ((iTemp39) ? 6 : 2) : 1) : ((iTemp38) ? 1 : 0))));
			iRec19[0] = iTemp44;
			float 	fTemp46 = (((iTemp44 >= 4)) ? (((iTemp44 >= 6)) ? fConst34 : fConst16) : (((iTemp44 >= 2)) ? (((iTemp44 >= 3)) ? fConst33 : fConst32) : (((iTemp44 >= 1)) ? fConst9 : 0.0f)));
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
			fRec18[0] = (fRec20[0] - (fConst31 * ((fConst29 * fRec18[2]) + (fConst27 * fRec18[1]))));
			float 	fTemp60 = min(0.99f, (fConst35 * (((3947.8418f * fRec18[0]) + (7895.6836f * fRec18[1])) + (3947.8418f * fRec18[2]))));
			int 	iTemp61 = (fTemp60 < 0.1f);
			float 	fTemp62 = (((iTemp61) ? fTemp60 : 0.1f) * fSlow8);
			float 	fTemp63 = (4.656613e-10f * fTemp7);
			fRec29[0] = (fTemp63 - (fSlow20 * ((fSlow18 * fRec29[2]) + (fSlow15 * fRec29[1]))));
			float 	fTemp64 = min(1.0f, (fSlow21 + ((iTemp61) ? (1.0f - (1e+01f * fTemp60)) : 0.0f)));
			float 	fTemp65 = ((iTemp24) ? 0.0f : (fSlow23 + fRec31[1]));
			fRec31[0] = (fTemp65 - floorf(fTemp65));
			float 	fTemp66 = (499.0f * fRec31[0]);
			int 	iTemp67 = int(fTemp66);
			int 	iTemp68 = max(0, min(iTemp67, 499));
			float 	fTemp69 = ftbl1[iTemp68];
			int 	iTemp70 = max(0, min((iTemp67 + 1), 499));
			float 	fTemp71 = (fTemp66 - float(iTemp67));
			float 	fTemp72 = float((((fVec5[1] <= 0.003f) & iTemp38) != 1));
			fRec32[0] = max((fTemp72 * fRec32[1]), fSlow24);
			fRec33[0] = max((fRec33[1] * fTemp72), fSlow6);
			float 	fTemp73 = max(min(((0.5f * (fVec5[0] - fTemp60)) + (0.2f - (0.8f * ((iTemp39) ? (2.0f * (((fRec33[0] > fRec32[0])) ? fRec33[0] : (0.0f - fRec32[0]))) : fSlow7)))), 1.0f), 0.0f);
			float 	fTemp74 = ftbl0[iTemp68];
			float 	fTemp75 = (((fTemp74 + (fTemp71 * (ftbl0[iTemp70] - fTemp74))) * (1.0f - fTemp73)) + (fTemp73 * (fTemp69 + (fTemp71 * (ftbl1[iTemp70] - fTemp69)))));
			float 	fTemp76 = (fRec30[1] - fConst41);
			float 	fTemp77 = (fConst41 + fRec30[1]);
			fRec30[0] = (((fTemp77 < fTemp75)) ? fTemp77 : (((fTemp76 > fTemp75)) ? fTemp76 : fTemp75));
			float 	fTemp78 = ((iTemp24) ? 0.0f : (fSlow26 + fRec34[1]));
			fRec34[0] = (fTemp78 - floorf(fTemp78));
			float 	fTemp79 = (499.0f * fRec34[0]);
			int 	iTemp80 = int(fTemp79);
			float 	fTemp81 = ftbl0[max(0, min(iTemp80, 499))];
			float 	fTemp82 = ((iTemp24) ? 0.0f : (fSlow27 + fRec35[1]));
			fRec35[0] = (fTemp82 - floorf(fTemp82));
			float 	fTemp83 = (499.0f * fRec35[0]);
			int 	iTemp84 = int(fTemp83);
			float 	fTemp85 = ftbl1[max(0, min(iTemp84, 499))];
			fVec7[0] = fSlow32;
			int 	iTemp86 = (fSlow32 != fVec7[1]);
			iVec8[0] = iTemp86;
			int 	iTemp87 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec39[0] = ((iRec39[1] * (1 - iTemp87)) + (iTemp36 * iTemp87));
			float 	fTemp88 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec39[0])))) > 0.5f) & iSlow33)) ? 0.0f : fSlow31) + 1.0f)) + 0.5f))];
			fVec9[0] = fTemp88;
			int 	iTemp89 = (fVec9[0] > 0.003f);
			int 	iTemp90 = (fVec9[0] <= 0.003f);
			float 	fTemp91 = float((iTemp90 | (fVec9[1] >= 0.003f)));
			fRec40[0] = max((fRec40[1] * fTemp91), fSlow32);
			fRec41[0] = max((fTemp91 * fRec41[1]), fSlow34);
			float 	fTemp92 = (min(1.0f, fRec41[0]) + min(1.0f, fRec40[0]));
			int 	iTemp93 = (fVec9[0] >= fRec38[1]);
			int 	iTemp94 = (fRec38[1] <= 0.001f);
			int 	iTemp95 = (((iRec37[1] >= 4)) ? (((iRec37[1] >= 6)) ? ((iTemp94) ? 0 : ((iTemp89) ? 1 : 6)) : (((iRec37[1] >= 5)) ? ((iTemp90) ? 3 : ((iTemp93) ? 4 : 5)) : ((iTemp90) ? 3 : (((fVec9[0] <= fRec38[1])) ? 5 : 4)))) : (((iRec37[1] >= 2)) ? (((iRec37[1] >= 3)) ? (((iTemp90 & iTemp94)) ? 0 : ((iTemp89) ? 1 : 3)) : ((iTemp89) ? ((iTemp93) ? 4 : 2) : 6)) : (((iRec37[1] >= 1)) ? (((fRec38[1] >= min(fTemp92, 1.0f))) ? ((iTemp90) ? 6 : 2) : 1) : ((iTemp89) ? 1 : 0))));
			iRec37[0] = iTemp95;
			float 	fTemp96 = (((iTemp95 >= 4)) ? (((iTemp95 >= 6)) ? fConst34 : fConst16) : (((iTemp95 >= 2)) ? (((iTemp95 >= 3)) ? fConst33 : fConst32) : (((iTemp95 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp97 = (iRec37[1] != iRec37[2]);
			iVec10[0] = iTemp97;
			int 	iTemp98 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec43[0] = ((iRec43[1] * (1 - iTemp98)) + (iTemp36 * iTemp98));
			float 	fTemp99 = (2e+01f * (((fTemp96 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec43[0]))) / fTemp96) : 0.0f));
			int 	iTemp100 = int(fTemp99);
			float 	fTemp101 = ftbl3[max(0, int(min(int(iTemp100), 20)))];
			float 	fTemp102 = (fTemp101 + ((fTemp99 - float(iTemp100)) * (ftbl3[max(0, int(min(int((iTemp100 + 1)), 20)))] - fTemp101)));
			fRec44[0] = max((fRec44[1] * float(iVec10[0])), max(fVec9[0], fRec38[1]));
			int 	iTemp103 = (iRec37[1] == 3);
			int 	iTemp104 = (iRec37[1] == 6);
			int 	iTemp105 = (iRec37[1] == 0);
			float 	fTemp106 = (((iRec37[1] == 1)) ? min(1.0f, fTemp92) : ((iTemp105) ? 0.0f : ((iTemp104) ? (fTemp92 * fTemp102) : ((iTemp103) ? (fRec44[0] * fTemp102) : fVec9[0]))));
			float 	fTemp107 = (1.0f / ((iTemp105) ? 0.0001f : (((iTemp103 | iTemp104)) ? (0.04761905f * fTemp96) : fTemp96)));
			float 	fTemp108 = (fRec42[1] - fTemp107);
			float 	fTemp109 = (fRec42[1] + fTemp107);
			fRec42[0] = (((fTemp109 < fTemp106)) ? fTemp109 : (((fTemp108 > fTemp106)) ? fTemp108 : fTemp106));
			fRec38[0] = fRec42[0];
			fRec36[0] = (fRec38[0] - (fConst31 * ((fConst29 * fRec36[2]) + (fConst27 * fRec36[1]))));
			float 	fTemp110 = min(0.99f, (fConst35 * (((3947.8418f * fRec36[0]) + (7895.6836f * fRec36[1])) + (3947.8418f * fRec36[2]))));
			int 	iTemp111 = (fTemp110 < 0.1f);
			float 	fTemp112 = (((iTemp111) ? fTemp110 : 0.1f) * fSlow30);
			fRec45[0] = (fTemp63 - (fSlow42 * ((fSlow40 * fRec45[2]) + (fSlow37 * fRec45[1]))));
			float 	fTemp113 = min(1.0f, (fSlow43 + ((iTemp111) ? (1.0f - (1e+01f * fTemp110)) : 0.0f)));
			float 	fTemp114 = ((iTemp24) ? 0.0f : (fSlow45 + fRec47[1]));
			fRec47[0] = (fTemp114 - floorf(fTemp114));
			float 	fTemp115 = (499.0f * fRec47[0]);
			int 	iTemp116 = int(fTemp115);
			int 	iTemp117 = max(0, min(iTemp116, 499));
			float 	fTemp118 = ftbl1[iTemp117];
			int 	iTemp119 = max(0, min((iTemp116 + 1), 499));
			float 	fTemp120 = (fTemp115 - float(iTemp116));
			float 	fTemp121 = float((((fVec9[1] <= 0.003f) & iTemp89) != 1));
			fRec48[0] = max((fTemp121 * fRec48[1]), fSlow46);
			fRec49[0] = max((fRec49[1] * fTemp121), fSlow28);
			float 	fTemp122 = max(min(((0.5f * (fVec9[0] - fTemp110)) + (0.2f - (0.8f * ((iTemp90) ? (2.0f * (((fRec49[0] > fRec48[0])) ? fRec49[0] : (0.0f - fRec48[0]))) : fSlow29)))), 1.0f), 0.0f);
			float 	fTemp123 = ftbl0[iTemp117];
			float 	fTemp124 = (((fTemp123 + (fTemp120 * (ftbl0[iTemp119] - fTemp123))) * (1.0f - fTemp122)) + (fTemp122 * (fTemp118 + (fTemp120 * (ftbl1[iTemp119] - fTemp118)))));
			float 	fTemp125 = (fRec46[1] - fConst41);
			float 	fTemp126 = (fConst41 + fRec46[1]);
			fRec46[0] = (((fTemp126 < fTemp124)) ? fTemp126 : (((fTemp125 > fTemp124)) ? fTemp125 : fTemp124));
			float 	fTemp127 = ((iTemp24) ? 0.0f : (fSlow48 + fRec50[1]));
			fRec50[0] = (fTemp127 - floorf(fTemp127));
			float 	fTemp128 = (499.0f * fRec50[0]);
			int 	iTemp129 = int(fTemp128);
			float 	fTemp130 = ftbl0[max(0, min(iTemp129, 499))];
			float 	fTemp131 = ((iTemp24) ? 0.0f : (fSlow49 + fRec51[1]));
			fRec51[0] = (fTemp131 - floorf(fTemp131));
			float 	fTemp132 = (499.0f * fRec51[0]);
			int 	iTemp133 = int(fTemp132);
			float 	fTemp134 = ftbl1[max(0, min(iTemp133, 499))];
			fVec11[0] = fSlow54;
			int 	iTemp135 = (fSlow54 != fVec11[1]);
			iVec12[0] = iTemp135;
			int 	iTemp136 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec55[0] = ((iRec55[1] * (1 - iTemp136)) + (iTemp36 * iTemp136));
			float 	fTemp137 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec55[0])))) > 0.5f) & iSlow55)) ? 0.0f : fSlow53) + 1.0f)) + 0.5f))];
			fVec13[0] = fTemp137;
			int 	iTemp138 = (fVec13[0] > 0.003f);
			int 	iTemp139 = (fVec13[0] <= 0.003f);
			float 	fTemp140 = float((iTemp139 | (fVec13[1] >= 0.003f)));
			fRec56[0] = max((fRec56[1] * fTemp140), fSlow54);
			fRec57[0] = max((fTemp140 * fRec57[1]), fSlow56);
			float 	fTemp141 = (min(1.0f, fRec57[0]) + min(1.0f, fRec56[0]));
			int 	iTemp142 = (fVec13[0] >= fRec54[1]);
			int 	iTemp143 = (fRec54[1] <= 0.001f);
			int 	iTemp144 = (((iRec53[1] >= 4)) ? (((iRec53[1] >= 6)) ? ((iTemp143) ? 0 : ((iTemp138) ? 1 : 6)) : (((iRec53[1] >= 5)) ? ((iTemp139) ? 3 : ((iTemp142) ? 4 : 5)) : ((iTemp139) ? 3 : (((fVec13[0] <= fRec54[1])) ? 5 : 4)))) : (((iRec53[1] >= 2)) ? (((iRec53[1] >= 3)) ? (((iTemp139 & iTemp143)) ? 0 : ((iTemp138) ? 1 : 3)) : ((iTemp138) ? ((iTemp142) ? 4 : 2) : 6)) : (((iRec53[1] >= 1)) ? (((fRec54[1] >= min(fTemp141, 1.0f))) ? ((iTemp139) ? 6 : 2) : 1) : ((iTemp138) ? 1 : 0))));
			iRec53[0] = iTemp144;
			float 	fTemp145 = (((iTemp144 >= 4)) ? (((iTemp144 >= 6)) ? fConst34 : fConst16) : (((iTemp144 >= 2)) ? (((iTemp144 >= 3)) ? fConst33 : fConst32) : (((iTemp144 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp146 = (iRec53[1] != iRec53[2]);
			iVec14[0] = iTemp146;
			int 	iTemp147 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec59[0] = ((iRec59[1] * (1 - iTemp147)) + (iTemp36 * iTemp147));
			float 	fTemp148 = (2e+01f * (((fTemp145 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec59[0]))) / fTemp145) : 0.0f));
			int 	iTemp149 = int(fTemp148);
			float 	fTemp150 = ftbl3[max(0, int(min(int(iTemp149), 20)))];
			float 	fTemp151 = (fTemp150 + ((fTemp148 - float(iTemp149)) * (ftbl3[max(0, int(min(int((iTemp149 + 1)), 20)))] - fTemp150)));
			fRec60[0] = max((fRec60[1] * float(iVec14[0])), max(fVec13[0], fRec54[1]));
			int 	iTemp152 = (iRec53[1] == 3);
			int 	iTemp153 = (iRec53[1] == 6);
			int 	iTemp154 = (iRec53[1] == 0);
			float 	fTemp155 = (((iRec53[1] == 1)) ? min(1.0f, fTemp141) : ((iTemp154) ? 0.0f : ((iTemp153) ? (fTemp141 * fTemp151) : ((iTemp152) ? (fRec60[0] * fTemp151) : fVec13[0]))));
			float 	fTemp156 = (1.0f / ((iTemp154) ? 0.0001f : (((iTemp152 | iTemp153)) ? (0.04761905f * fTemp145) : fTemp145)));
			float 	fTemp157 = (fRec58[1] - fTemp156);
			float 	fTemp158 = (fRec58[1] + fTemp156);
			fRec58[0] = (((fTemp158 < fTemp155)) ? fTemp158 : (((fTemp157 > fTemp155)) ? fTemp157 : fTemp155));
			fRec54[0] = fRec58[0];
			fRec52[0] = (fRec54[0] - (fConst31 * ((fConst29 * fRec52[2]) + (fConst27 * fRec52[1]))));
			float 	fTemp159 = min(0.99f, (fConst35 * (((3947.8418f * fRec52[0]) + (7895.6836f * fRec52[1])) + (3947.8418f * fRec52[2]))));
			int 	iTemp160 = (fTemp159 < 0.1f);
			float 	fTemp161 = (((iTemp160) ? fTemp159 : 0.1f) * fSlow52);
			fRec61[0] = (fTemp63 - (fSlow64 * ((fSlow62 * fRec61[2]) + (fSlow59 * fRec61[1]))));
			float 	fTemp162 = min(1.0f, (fSlow65 + ((iTemp160) ? (1.0f - (1e+01f * fTemp159)) : 0.0f)));
			float 	fTemp163 = ((iTemp24) ? 0.0f : (fSlow67 + fRec63[1]));
			fRec63[0] = (fTemp163 - floorf(fTemp163));
			float 	fTemp164 = (499.0f * fRec63[0]);
			int 	iTemp165 = int(fTemp164);
			int 	iTemp166 = max(0, min(iTemp165, 499));
			float 	fTemp167 = ftbl1[iTemp166];
			int 	iTemp168 = max(0, min((iTemp165 + 1), 499));
			float 	fTemp169 = (fTemp164 - float(iTemp165));
			float 	fTemp170 = float((((fVec13[1] <= 0.003f) & iTemp138) != 1));
			fRec64[0] = max((fTemp170 * fRec64[1]), fSlow68);
			fRec65[0] = max((fRec65[1] * fTemp170), fSlow50);
			float 	fTemp171 = max(min(((0.5f * (fVec13[0] - fTemp159)) + (0.2f - (0.8f * ((iTemp139) ? (2.0f * (((fRec65[0] > fRec64[0])) ? fRec65[0] : (0.0f - fRec64[0]))) : fSlow51)))), 1.0f), 0.0f);
			float 	fTemp172 = ftbl0[iTemp166];
			float 	fTemp173 = (((fTemp172 + (fTemp169 * (ftbl0[iTemp168] - fTemp172))) * (1.0f - fTemp171)) + (fTemp171 * (fTemp167 + (fTemp169 * (ftbl1[iTemp168] - fTemp167)))));
			float 	fTemp174 = (fRec62[1] - fConst41);
			float 	fTemp175 = (fConst41 + fRec62[1]);
			fRec62[0] = (((fTemp175 < fTemp173)) ? fTemp175 : (((fTemp174 > fTemp173)) ? fTemp174 : fTemp173));
			float 	fTemp176 = ((iTemp24) ? 0.0f : (fSlow70 + fRec66[1]));
			fRec66[0] = (fTemp176 - floorf(fTemp176));
			float 	fTemp177 = (499.0f * fRec66[0]);
			int 	iTemp178 = int(fTemp177);
			float 	fTemp179 = ftbl0[max(0, min(iTemp178, 499))];
			float 	fTemp180 = ((iTemp24) ? 0.0f : (fSlow71 + fRec67[1]));
			fRec67[0] = (fTemp180 - floorf(fTemp180));
			float 	fTemp181 = (499.0f * fRec67[0]);
			int 	iTemp182 = int(fTemp181);
			float 	fTemp183 = ftbl1[max(0, min(iTemp182, 499))];
			fVec15[0] = fSlow76;
			int 	iTemp184 = (fSlow76 != fVec15[1]);
			iVec16[0] = iTemp184;
			int 	iTemp185 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec71[0] = ((iRec71[1] * (1 - iTemp185)) + (iTemp36 * iTemp185));
			float 	fTemp186 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec71[0])))) > 0.5f) & iSlow77)) ? 0.0f : fSlow75) + 1.0f)) + 0.5f))];
			fVec17[0] = fTemp186;
			int 	iTemp187 = (fVec17[0] > 0.003f);
			int 	iTemp188 = (fVec17[0] <= 0.003f);
			float 	fTemp189 = float((iTemp188 | (fVec17[1] >= 0.003f)));
			fRec72[0] = max((fRec72[1] * fTemp189), fSlow76);
			fRec73[0] = max((fTemp189 * fRec73[1]), fSlow78);
			float 	fTemp190 = (min(1.0f, fRec73[0]) + min(1.0f, fRec72[0]));
			int 	iTemp191 = (fVec17[0] >= fRec70[1]);
			int 	iTemp192 = (fRec70[1] <= 0.001f);
			int 	iTemp193 = (((iRec69[1] >= 4)) ? (((iRec69[1] >= 6)) ? ((iTemp192) ? 0 : ((iTemp187) ? 1 : 6)) : (((iRec69[1] >= 5)) ? ((iTemp188) ? 3 : ((iTemp191) ? 4 : 5)) : ((iTemp188) ? 3 : (((fVec17[0] <= fRec70[1])) ? 5 : 4)))) : (((iRec69[1] >= 2)) ? (((iRec69[1] >= 3)) ? (((iTemp188 & iTemp192)) ? 0 : ((iTemp187) ? 1 : 3)) : ((iTemp187) ? ((iTemp191) ? 4 : 2) : 6)) : (((iRec69[1] >= 1)) ? (((fRec70[1] >= min(fTemp190, 1.0f))) ? ((iTemp188) ? 6 : 2) : 1) : ((iTemp187) ? 1 : 0))));
			iRec69[0] = iTemp193;
			float 	fTemp194 = (((iTemp193 >= 4)) ? (((iTemp193 >= 6)) ? fConst34 : fConst16) : (((iTemp193 >= 2)) ? (((iTemp193 >= 3)) ? fConst33 : fConst32) : (((iTemp193 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp195 = (iRec69[1] != iRec69[2]);
			iVec18[0] = iTemp195;
			int 	iTemp196 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec75[0] = ((iRec75[1] * (1 - iTemp196)) + (iTemp36 * iTemp196));
			float 	fTemp197 = (2e+01f * (((fTemp194 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec75[0]))) / fTemp194) : 0.0f));
			int 	iTemp198 = int(fTemp197);
			float 	fTemp199 = ftbl3[max(0, int(min(int(iTemp198), 20)))];
			float 	fTemp200 = (fTemp199 + ((fTemp197 - float(iTemp198)) * (ftbl3[max(0, int(min(int((iTemp198 + 1)), 20)))] - fTemp199)));
			fRec76[0] = max((fRec76[1] * float(iVec18[0])), max(fVec17[0], fRec70[1]));
			int 	iTemp201 = (iRec69[1] == 3);
			int 	iTemp202 = (iRec69[1] == 6);
			int 	iTemp203 = (iRec69[1] == 0);
			float 	fTemp204 = (((iRec69[1] == 1)) ? min(1.0f, fTemp190) : ((iTemp203) ? 0.0f : ((iTemp202) ? (fTemp190 * fTemp200) : ((iTemp201) ? (fRec76[0] * fTemp200) : fVec17[0]))));
			float 	fTemp205 = (1.0f / ((iTemp203) ? 0.0001f : (((iTemp201 | iTemp202)) ? (0.04761905f * fTemp194) : fTemp194)));
			float 	fTemp206 = (fRec74[1] - fTemp205);
			float 	fTemp207 = (fRec74[1] + fTemp205);
			fRec74[0] = (((fTemp207 < fTemp204)) ? fTemp207 : (((fTemp206 > fTemp204)) ? fTemp206 : fTemp204));
			fRec70[0] = fRec74[0];
			fRec68[0] = (fRec70[0] - (fConst31 * ((fConst29 * fRec68[2]) + (fConst27 * fRec68[1]))));
			float 	fTemp208 = min(0.99f, (fConst35 * (((3947.8418f * fRec68[0]) + (7895.6836f * fRec68[1])) + (3947.8418f * fRec68[2]))));
			int 	iTemp209 = (fTemp208 < 0.1f);
			float 	fTemp210 = (((iTemp209) ? fTemp208 : 0.1f) * fSlow74);
			fRec77[0] = (fTemp63 - (fSlow86 * ((fSlow84 * fRec77[2]) + (fSlow81 * fRec77[1]))));
			float 	fTemp211 = min(1.0f, (fSlow87 + ((iTemp209) ? (1.0f - (1e+01f * fTemp208)) : 0.0f)));
			float 	fTemp212 = ((iTemp24) ? 0.0f : (fSlow89 + fRec79[1]));
			fRec79[0] = (fTemp212 - floorf(fTemp212));
			float 	fTemp213 = (499.0f * fRec79[0]);
			int 	iTemp214 = int(fTemp213);
			int 	iTemp215 = max(0, min(iTemp214, 499));
			float 	fTemp216 = ftbl1[iTemp215];
			int 	iTemp217 = max(0, min((iTemp214 + 1), 499));
			float 	fTemp218 = (fTemp213 - float(iTemp214));
			float 	fTemp219 = float((((fVec17[1] <= 0.003f) & iTemp187) != 1));
			fRec80[0] = max((fTemp219 * fRec80[1]), fSlow90);
			fRec81[0] = max((fRec81[1] * fTemp219), fSlow72);
			float 	fTemp220 = max(min(((0.5f * (fVec17[0] - fTemp208)) + (0.2f - (0.8f * ((iTemp188) ? (2.0f * (((fRec81[0] > fRec80[0])) ? fRec81[0] : (0.0f - fRec80[0]))) : fSlow73)))), 1.0f), 0.0f);
			float 	fTemp221 = ftbl0[iTemp215];
			float 	fTemp222 = (((fTemp221 + (fTemp218 * (ftbl0[iTemp217] - fTemp221))) * (1.0f - fTemp220)) + (fTemp220 * (fTemp216 + (fTemp218 * (ftbl1[iTemp217] - fTemp216)))));
			float 	fTemp223 = (fRec78[1] - fConst41);
			float 	fTemp224 = (fConst41 + fRec78[1]);
			fRec78[0] = (((fTemp224 < fTemp222)) ? fTemp224 : (((fTemp223 > fTemp222)) ? fTemp223 : fTemp222));
			float 	fTemp225 = ((iTemp24) ? 0.0f : (fSlow92 + fRec82[1]));
			fRec82[0] = (fTemp225 - floorf(fTemp225));
			float 	fTemp226 = (499.0f * fRec82[0]);
			int 	iTemp227 = int(fTemp226);
			float 	fTemp228 = ftbl0[max(0, min(iTemp227, 499))];
			float 	fTemp229 = ((iTemp24) ? 0.0f : (fSlow93 + fRec83[1]));
			fRec83[0] = (fTemp229 - floorf(fTemp229));
			float 	fTemp230 = (499.0f * fRec83[0]);
			int 	iTemp231 = int(fTemp230);
			float 	fTemp232 = ftbl1[max(0, min(iTemp231, 499))];
			fVec19[0] = fSlow98;
			int 	iTemp233 = (fSlow98 != fVec19[1]);
			iVec20[0] = iTemp233;
			int 	iTemp234 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec87[0] = ((iRec87[1] * (1 - iTemp234)) + (iTemp36 * iTemp234));
			float 	fTemp235 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec87[0])))) > 0.5f) & iSlow99)) ? 0.0f : fSlow97) + 1.0f)) + 0.5f))];
			fVec21[0] = fTemp235;
			int 	iTemp236 = (fVec21[0] > 0.003f);
			int 	iTemp237 = (fVec21[0] <= 0.003f);
			float 	fTemp238 = float((iTemp237 | (fVec21[1] >= 0.003f)));
			fRec88[0] = max((fRec88[1] * fTemp238), fSlow98);
			fRec89[0] = max((fTemp238 * fRec89[1]), fSlow100);
			float 	fTemp239 = (min(1.0f, fRec89[0]) + min(1.0f, fRec88[0]));
			int 	iTemp240 = (fVec21[0] >= fRec86[1]);
			int 	iTemp241 = (fRec86[1] <= 0.001f);
			int 	iTemp242 = (((iRec85[1] >= 4)) ? (((iRec85[1] >= 6)) ? ((iTemp241) ? 0 : ((iTemp236) ? 1 : 6)) : (((iRec85[1] >= 5)) ? ((iTemp237) ? 3 : ((iTemp240) ? 4 : 5)) : ((iTemp237) ? 3 : (((fVec21[0] <= fRec86[1])) ? 5 : 4)))) : (((iRec85[1] >= 2)) ? (((iRec85[1] >= 3)) ? (((iTemp237 & iTemp241)) ? 0 : ((iTemp236) ? 1 : 3)) : ((iTemp236) ? ((iTemp240) ? 4 : 2) : 6)) : (((iRec85[1] >= 1)) ? (((fRec86[1] >= min(fTemp239, 1.0f))) ? ((iTemp237) ? 6 : 2) : 1) : ((iTemp236) ? 1 : 0))));
			iRec85[0] = iTemp242;
			float 	fTemp243 = (((iTemp242 >= 4)) ? (((iTemp242 >= 6)) ? fConst34 : fConst16) : (((iTemp242 >= 2)) ? (((iTemp242 >= 3)) ? fConst33 : fConst32) : (((iTemp242 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp244 = (iRec85[1] != iRec85[2]);
			iVec22[0] = iTemp244;
			int 	iTemp245 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec91[0] = ((iRec91[1] * (1 - iTemp245)) + (iTemp36 * iTemp245));
			float 	fTemp246 = (2e+01f * (((fTemp243 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec91[0]))) / fTemp243) : 0.0f));
			int 	iTemp247 = int(fTemp246);
			float 	fTemp248 = ftbl3[max(0, int(min(int(iTemp247), 20)))];
			float 	fTemp249 = (fTemp248 + ((fTemp246 - float(iTemp247)) * (ftbl3[max(0, int(min(int((iTemp247 + 1)), 20)))] - fTemp248)));
			fRec92[0] = max((fRec92[1] * float(iVec22[0])), max(fVec21[0], fRec86[1]));
			int 	iTemp250 = (iRec85[1] == 3);
			int 	iTemp251 = (iRec85[1] == 6);
			int 	iTemp252 = (iRec85[1] == 0);
			float 	fTemp253 = (((iRec85[1] == 1)) ? min(1.0f, fTemp239) : ((iTemp252) ? 0.0f : ((iTemp251) ? (fTemp239 * fTemp249) : ((iTemp250) ? (fRec92[0] * fTemp249) : fVec21[0]))));
			float 	fTemp254 = (1.0f / ((iTemp252) ? 0.0001f : (((iTemp250 | iTemp251)) ? (0.04761905f * fTemp243) : fTemp243)));
			float 	fTemp255 = (fRec90[1] - fTemp254);
			float 	fTemp256 = (fRec90[1] + fTemp254);
			fRec90[0] = (((fTemp256 < fTemp253)) ? fTemp256 : (((fTemp255 > fTemp253)) ? fTemp255 : fTemp253));
			fRec86[0] = fRec90[0];
			fRec84[0] = (fRec86[0] - (fConst31 * ((fConst29 * fRec84[2]) + (fConst27 * fRec84[1]))));
			float 	fTemp257 = min(0.99f, (fConst35 * (((3947.8418f * fRec84[0]) + (7895.6836f * fRec84[1])) + (3947.8418f * fRec84[2]))));
			int 	iTemp258 = (fTemp257 < 0.1f);
			float 	fTemp259 = (((iTemp258) ? fTemp257 : 0.1f) * fSlow96);
			fRec93[0] = (fTemp63 - (fSlow108 * ((fSlow106 * fRec93[2]) + (fSlow103 * fRec93[1]))));
			float 	fTemp260 = min(1.0f, (fSlow109 + ((iTemp258) ? (1.0f - (1e+01f * fTemp257)) : 0.0f)));
			float 	fTemp261 = ((iTemp24) ? 0.0f : (fSlow111 + fRec95[1]));
			fRec95[0] = (fTemp261 - floorf(fTemp261));
			float 	fTemp262 = (499.0f * fRec95[0]);
			int 	iTemp263 = int(fTemp262);
			int 	iTemp264 = max(0, min(iTemp263, 499));
			float 	fTemp265 = ftbl1[iTemp264];
			int 	iTemp266 = max(0, min((iTemp263 + 1), 499));
			float 	fTemp267 = (fTemp262 - float(iTemp263));
			float 	fTemp268 = float((((fVec21[1] <= 0.003f) & iTemp236) != 1));
			fRec96[0] = max((fTemp268 * fRec96[1]), fSlow112);
			fRec97[0] = max((fRec97[1] * fTemp268), fSlow94);
			float 	fTemp269 = max(min(((0.5f * (fVec21[0] - fTemp257)) + (0.2f - (0.8f * ((iTemp237) ? (2.0f * (((fRec97[0] > fRec96[0])) ? fRec97[0] : (0.0f - fRec96[0]))) : fSlow95)))), 1.0f), 0.0f);
			float 	fTemp270 = ftbl0[iTemp264];
			float 	fTemp271 = (((fTemp270 + (fTemp267 * (ftbl0[iTemp266] - fTemp270))) * (1.0f - fTemp269)) + (fTemp269 * (fTemp265 + (fTemp267 * (ftbl1[iTemp266] - fTemp265)))));
			float 	fTemp272 = (fRec94[1] - fConst41);
			float 	fTemp273 = (fConst41 + fRec94[1]);
			fRec94[0] = (((fTemp273 < fTemp271)) ? fTemp273 : (((fTemp272 > fTemp271)) ? fTemp272 : fTemp271));
			float 	fTemp274 = ((iTemp24) ? 0.0f : (fSlow114 + fRec98[1]));
			fRec98[0] = (fTemp274 - floorf(fTemp274));
			float 	fTemp275 = (499.0f * fRec98[0]);
			int 	iTemp276 = int(fTemp275);
			float 	fTemp277 = ftbl0[max(0, min(iTemp276, 499))];
			float 	fTemp278 = ((iTemp24) ? 0.0f : (fSlow115 + fRec99[1]));
			fRec99[0] = (fTemp278 - floorf(fTemp278));
			float 	fTemp279 = (499.0f * fRec99[0]);
			int 	iTemp280 = int(fTemp279);
			float 	fTemp281 = ftbl1[max(0, min(iTemp280, 499))];
			fVec23[0] = fSlow120;
			int 	iTemp282 = (fSlow120 != fVec23[1]);
			iVec24[0] = iTemp282;
			int 	iTemp283 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec103[0] = ((iRec103[1] * (1 - iTemp283)) + (iTemp36 * iTemp283));
			float 	fTemp284 = ftbl2[int(((499.5f * ((((((fConst12 * float((iRec22[0] + (-1 - iRec103[0])))) > 0.5f) & iSlow121)) ? 0.0f : fSlow119) + 1.0f)) + 0.5f))];
			fVec25[0] = fTemp284;
			int 	iTemp285 = (fVec25[0] > 0.003f);
			int 	iTemp286 = (fVec25[0] <= 0.003f);
			float 	fTemp287 = float((iTemp286 | (fVec25[1] >= 0.003f)));
			fRec104[0] = max((fRec104[1] * fTemp287), fSlow120);
			fRec105[0] = max((fTemp287 * fRec105[1]), fSlow122);
			float 	fTemp288 = (min(1.0f, fRec105[0]) + min(1.0f, fRec104[0]));
			int 	iTemp289 = (fVec25[0] >= fRec102[1]);
			int 	iTemp290 = (fRec102[1] <= 0.001f);
			int 	iTemp291 = (((iRec101[1] >= 4)) ? (((iRec101[1] >= 6)) ? ((iTemp290) ? 0 : ((iTemp285) ? 1 : 6)) : (((iRec101[1] >= 5)) ? ((iTemp286) ? 3 : ((iTemp289) ? 4 : 5)) : ((iTemp286) ? 3 : (((fVec25[0] <= fRec102[1])) ? 5 : 4)))) : (((iRec101[1] >= 2)) ? (((iRec101[1] >= 3)) ? (((iTemp286 & iTemp290)) ? 0 : ((iTemp285) ? 1 : 3)) : ((iTemp285) ? ((iTemp289) ? 4 : 2) : 6)) : (((iRec101[1] >= 1)) ? (((fRec102[1] >= min(fTemp288, 1.0f))) ? ((iTemp286) ? 6 : 2) : 1) : ((iTemp285) ? 1 : 0))));
			iRec101[0] = iTemp291;
			float 	fTemp292 = (((iTemp291 >= 4)) ? (((iTemp291 >= 6)) ? fConst34 : fConst16) : (((iTemp291 >= 2)) ? (((iTemp291 >= 3)) ? fConst33 : fConst32) : (((iTemp291 >= 1)) ? fConst9 : 0.0f)));
			int 	iTemp293 = (iRec101[1] != iRec101[2]);
			iVec26[0] = iTemp293;
			int 	iTemp294 = ((iVec26[1] <= 0) & (iVec26[0] > 0));
			iRec107[0] = ((iRec107[1] * (1 - iTemp294)) + (iTemp36 * iTemp294));
			float 	fTemp295 = (2e+01f * (((fTemp292 > 0.0f)) ? (float((iRec22[0] + (-1 - iRec107[0]))) / fTemp292) : 0.0f));
			int 	iTemp296 = int(fTemp295);
			float 	fTemp297 = ftbl3[max(0, int(min(int(iTemp296), 20)))];
			float 	fTemp298 = (fTemp297 + ((fTemp295 - float(iTemp296)) * (ftbl3[max(0, int(min(int((iTemp296 + 1)), 20)))] - fTemp297)));
			fRec108[0] = max((fRec108[1] * float(iVec26[0])), max(fVec25[0], fRec102[1]));
			int 	iTemp299 = (iRec101[1] == 3);
			int 	iTemp300 = (iRec101[1] == 6);
			int 	iTemp301 = (iRec101[1] == 0);
			float 	fTemp302 = (((iRec101[1] == 1)) ? min(1.0f, fTemp288) : ((iTemp301) ? 0.0f : ((iTemp300) ? (fTemp288 * fTemp298) : ((iTemp299) ? (fRec108[0] * fTemp298) : fVec25[0]))));
			float 	fTemp303 = (1.0f / ((iTemp301) ? 0.0001f : (((iTemp299 | iTemp300)) ? (0.04761905f * fTemp292) : fTemp292)));
			float 	fTemp304 = (fRec106[1] - fTemp303);
			float 	fTemp305 = (fRec106[1] + fTemp303);
			fRec106[0] = (((fTemp305 < fTemp302)) ? fTemp305 : (((fTemp304 > fTemp302)) ? fTemp304 : fTemp302));
			fRec102[0] = fRec106[0];
			fRec100[0] = (fRec102[0] - (fConst31 * ((fConst29 * fRec100[2]) + (fConst27 * fRec100[1]))));
			float 	fTemp306 = min(0.99f, (fConst35 * (((3947.8418f * fRec100[0]) + (7895.6836f * fRec100[1])) + (3947.8418f * fRec100[2]))));
			int 	iTemp307 = (fTemp306 < 0.1f);
			float 	fTemp308 = (((iTemp307) ? fTemp306 : 0.1f) * fSlow118);
			fRec109[0] = (fTemp63 - (fSlow130 * ((fSlow128 * fRec109[2]) + (fSlow125 * fRec109[1]))));
			float 	fTemp309 = min(1.0f, (fSlow131 + ((iTemp307) ? (1.0f - (1e+01f * fTemp306)) : 0.0f)));
			float 	fTemp310 = ((iTemp24) ? 0.0f : (fSlow133 + fRec111[1]));
			fRec111[0] = (fTemp310 - floorf(fTemp310));
			float 	fTemp311 = (499.0f * fRec111[0]);
			int 	iTemp312 = int(fTemp311);
			int 	iTemp313 = max(0, min(iTemp312, 499));
			float 	fTemp314 = ftbl1[iTemp313];
			int 	iTemp315 = max(0, min((iTemp312 + 1), 499));
			float 	fTemp316 = (fTemp311 - float(iTemp312));
			float 	fTemp317 = float((((fVec25[1] <= 0.003f) & iTemp285) != 1));
			fRec112[0] = max((fTemp317 * fRec112[1]), fSlow134);
			fRec113[0] = max((fRec113[1] * fTemp317), fSlow116);
			float 	fTemp318 = max(min(((0.5f * (fVec25[0] - fTemp306)) + (0.2f - (0.8f * ((iTemp286) ? (2.0f * (((fRec113[0] > fRec112[0])) ? fRec113[0] : (0.0f - fRec112[0]))) : fSlow117)))), 1.0f), 0.0f);
			float 	fTemp319 = ftbl0[iTemp313];
			float 	fTemp320 = (((fTemp319 + (fTemp316 * (ftbl0[iTemp315] - fTemp319))) * (1.0f - fTemp318)) + (fTemp318 * (fTemp314 + (fTemp316 * (ftbl1[iTemp315] - fTemp314)))));
			float 	fTemp321 = (fRec110[1] - fConst41);
			float 	fTemp322 = (fConst41 + fRec110[1]);
			fRec110[0] = (((fTemp322 < fTemp320)) ? fTemp322 : (((fTemp321 > fTemp320)) ? fTemp321 : fTemp320));
			fRec12[0] = ((1.37f * ((((((fTemp306 * ((((1.1f * (fRec110[0] * (1.0f - fTemp309))) + (fSlow132 * (fTemp309 * (fRec109[0] - fRec109[2])))) * (1.0f - (0.5f * fTemp308))) + (0.5f * (fTemp308 * ((0.2f * (fTemp281 + ((fTemp279 - float(iTemp280)) * (ftbl1[max(0, min((iTemp280 + 1), 499))] - fTemp281)))) + (0.8f * (fTemp277 + ((fTemp275 - float(iTemp276)) * (ftbl0[max(0, min((iTemp276 + 1), 499))] - fTemp277))))))))) + (fTemp257 * ((((1.1f * (fRec94[0] * (1.0f - fTemp260))) + (fSlow110 * (fTemp260 * (fRec93[0] - fRec93[2])))) * (1.0f - (0.5f * fTemp259))) + (0.5f * (fTemp259 * ((0.2f * (fTemp232 + ((fTemp230 - float(iTemp231)) * (ftbl1[max(0, min((iTemp231 + 1), 499))] - fTemp232)))) + (0.8f * (fTemp228 + ((fTemp226 - float(iTemp227)) * (ftbl0[max(0, min((iTemp227 + 1), 499))] - fTemp228)))))))))) + (fTemp208 * ((((1.1f * (fRec78[0] * (1.0f - fTemp211))) + (fSlow88 * (fTemp211 * (fRec77[0] - fRec77[2])))) * (1.0f - (0.5f * fTemp210))) + (0.5f * (fTemp210 * ((0.2f * (fTemp183 + ((fTemp181 - float(iTemp182)) * (ftbl1[max(0, min((iTemp182 + 1), 499))] - fTemp183)))) + (0.8f * (fTemp179 + ((fTemp177 - float(iTemp178)) * (ftbl0[max(0, min((iTemp178 + 1), 499))] - fTemp179)))))))))) + (fTemp159 * ((((1.1f * (fRec62[0] * (1.0f - fTemp162))) + (fSlow66 * (fTemp162 * (fRec61[0] - fRec61[2])))) * (1.0f - (0.5f * fTemp161))) + (0.5f * (fTemp161 * ((0.2f * (fTemp134 + ((fTemp132 - float(iTemp133)) * (ftbl1[max(0, min((iTemp133 + 1), 499))] - fTemp134)))) + (0.8f * (fTemp130 + ((fTemp128 - float(iTemp129)) * (ftbl0[max(0, min((iTemp129 + 1), 499))] - fTemp130)))))))))) + (fTemp110 * ((((1.1f * (fRec46[0] * (1.0f - fTemp113))) + (fSlow44 * (fTemp113 * (fRec45[0] - fRec45[2])))) * (1.0f - (0.5f * fTemp112))) + (0.5f * (fTemp112 * ((0.2f * (fTemp85 + ((fTemp83 - float(iTemp84)) * (ftbl1[max(0, min((iTemp84 + 1), 499))] - fTemp85)))) + (0.8f * (fTemp81 + ((fTemp79 - float(iTemp80)) * (ftbl0[max(0, min((iTemp80 + 1), 499))] - fTemp81)))))))))) + (fTemp60 * ((((1.1f * (fRec30[0] * (1.0f - fTemp64))) + (fSlow22 * (fTemp64 * (fRec29[0] - fRec29[2])))) * (1.0f - (0.5f * fTemp62))) + (0.5f * (fTemp62 * ((0.2f * (fTemp32 + ((fTemp30 - float(iTemp31)) * (ftbl1[max(0, min((iTemp31 + 1), 499))] - fTemp32)))) + (0.8f * (fTemp28 + ((fTemp26 - float(iTemp27)) * (ftbl0[max(0, min((iTemp27 + 1), 499))] - fTemp28))))))))))) - (fConst8 * ((fConst6 * fRec12[2]) + (fConst4 * fRec12[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst42 * (fRec12[1] + fRec0[1])) + (fConst8 * ((fRec12[0] + fRec12[2]) + (fRec0[0] + fRec0[2])))));
=======
			int 	iTemp2 = (1 - iVec0[1]);
			float 	fTemp3 = ((iTemp2) ? 0.0f : (fSlow1 + fRec2[1]));
			fRec2[0] = (fTemp3 - floorf(fTemp3));
			float 	fTemp4 = (499.0f * fRec2[0]);
			int 	iTemp5 = int(fTemp4);
			float 	fTemp6 = ftbl0[max(0, min(iTemp5, 499))];
			float 	fTemp7 = ((iTemp2) ? 0.0f : (fSlow2 + fRec4[1]));
			fRec4[0] = (fTemp7 - floorf(fTemp7));
			float 	fTemp8 = (499.0f * fRec4[0]);
			int 	iTemp9 = int(fTemp8);
			float 	fTemp10 = ftbl1[max(0, min(iTemp9, 499))];
			fVec1[0] = fSlow7;
			int 	iTemp12 = (fSlow7 != fVec1[1]);
			iVec2[0] = iTemp12;
			int 	iTemp13 = ((iVec2[1] <= 0) & (iVec2[0] > 0));
			iRec10[0] = (iRec10[1] + 1);
			int 	iTemp14 = (iRec10[0] + -1);
			iRec9[0] = ((iRec9[1] * (1 - iTemp13)) + (iTemp14 * iTemp13));
			float 	fTemp15 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec9[0])))) > 0.5f) & iSlow8)) ? 0.0f : fSlow6) + 1.0f)) + 0.5f))];
			fVec3[0] = fTemp15;
			int 	iTemp16 = (fVec3[0] > 0.003f);
			int 	iTemp17 = (fVec3[0] <= 0.003f);
			float 	fTemp18 = float((iTemp17 | (fVec3[1] >= 0.003f)));
			fRec11[0] = max((fRec11[1] * fTemp18), fSlow7);
			fRec12[0] = max((fTemp18 * fRec12[1]), fSlow9);
			float 	fTemp19 = (min(1.0f, fRec12[0]) + min(1.0f, (0.7f * fRec11[0])));
			int 	iTemp20 = (fVec3[0] >= fRec8[1]);
			int 	iTemp21 = (fRec8[1] <= 0.001f);
			int 	iTemp22 = (((iRec7[1] >= 4)) ? (((iRec7[1] >= 6)) ? ((iTemp21) ? 0 : ((iTemp16) ? 1 : 6)) : (((iRec7[1] >= 5)) ? ((iTemp17) ? 3 : ((iTemp20) ? 4 : 5)) : ((iTemp17) ? 3 : (((fVec3[0] <= fRec8[1])) ? 5 : 4)))) : (((iRec7[1] >= 2)) ? (((iRec7[1] >= 3)) ? (((iTemp17 & iTemp21)) ? 0 : ((iTemp16) ? 1 : 3)) : ((iTemp16) ? ((iTemp20) ? 4 : 2) : 6)) : (((iRec7[1] >= 1)) ? (((fRec8[1] >= min(fTemp19, 1.0f))) ? ((iTemp17) ? 6 : 2) : 1) : ((iTemp16) ? 1 : 0))));
			iRec7[0] = iTemp22;
			float 	fTemp24 = (((iTemp22 >= 4)) ? (((iTemp22 >= 6)) ? fConst15 : fConst12) : (((iTemp22 >= 2)) ? (((iTemp22 >= 3)) ? fConst14 : fConst13) : (((iTemp22 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp25 = (iRec7[1] != iRec7[2]);
			iVec4[0] = iTemp25;
			int 	iTemp26 = ((iVec4[1] <= 0) & (iVec4[0] > 0));
			iRec15[0] = ((iRec15[1] * (1 - iTemp26)) + (iTemp14 * iTemp26));
			float 	fTemp27 = (2e+01f * (((fTemp24 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec15[0]))) / fTemp24) : 0.0f));
			int 	iTemp28 = int(fTemp27);
			float 	fTemp29 = ftbl3[max(0, int(min(int(iTemp28), 20)))];
			float 	fTemp30 = (fTemp29 + ((fTemp27 - float(iTemp28)) * (ftbl3[max(0, int(min(int((iTemp28 + 1)), 20)))] - fTemp29)));
			fRec16[0] = max((fRec16[1] * float(iVec4[0])), max(fVec3[0], fRec8[1]));
			int 	iTemp31 = (iRec7[1] == 3);
			int 	iTemp32 = (iRec7[1] == 6);
			int 	iTemp33 = (iRec7[1] == 0);
			float 	fTemp34 = (((iRec7[1] == 1)) ? min(1.0f, fTemp19) : ((iTemp33) ? 0.0f : ((iTemp32) ? (fTemp19 * fTemp30) : ((iTemp31) ? (fRec16[0] * fTemp30) : fVec3[0]))));
			float 	fTemp35 = (1.0f / ((iTemp33) ? 0.0001f : (((iTemp31 | iTemp32)) ? (0.04761905f * fTemp24) : fTemp24)));
			float 	fTemp36 = (fRec13[1] - fTemp35);
			float 	fTemp37 = (fRec13[1] + fTemp35);
			fRec13[0] = (((fTemp37 < fTemp34)) ? fTemp37 : (((fTemp36 > fTemp34)) ? fTemp36 : fTemp34));
			fRec8[0] = fRec13[0];
			float 	fTemp38 = (fRec6[1] - fConst16);
			float 	fTemp39 = (fConst16 + fRec6[1]);
			fRec6[0] = (((fTemp39 < fRec8[0])) ? fTemp39 : (((fTemp38 > fRec8[0])) ? fTemp38 : fRec8[0]));
			int 	iTemp40 = (fRec6[0] < 0.1f);
			float 	fTemp41 = (((iTemp40) ? fRec6[0] : 0.1f) * fSlow5);
			iRec18[0] = ((1103515245 * iRec18[1]) + 12345);
			float 	fTemp42 = (4.656613e-10f * float(iRec18[0]));
			fRec17[0] = (fTemp42 - (fSlow17 * ((fSlow15 * fRec17[2]) + (fSlow12 * fRec17[1]))));
			float 	fTemp43 = min(1.0f, (fSlow18 + ((iTemp40) ? (1.0f - (1e+01f * fRec6[0])) : 0.0f)));
			float 	fTemp44 = ((iTemp2) ? 0.0f : (fSlow20 + fRec20[1]));
			fRec20[0] = (fTemp44 - floorf(fTemp44));
			float 	fTemp45 = (499.0f * fRec20[0]);
			int 	iTemp46 = int(fTemp45);
			int 	iTemp47 = max(0, min(iTemp46, 499));
			float 	fTemp48 = ftbl1[iTemp47];
			int 	iTemp49 = max(0, min((iTemp46 + 1), 499));
			float 	fTemp50 = (fTemp45 - float(iTemp46));
			float 	fTemp51 = float((((fVec3[1] <= 0.003f) & iTemp16) != 1));
			fRec21[0] = max((fTemp51 * fRec21[1]), fSlow21);
			fRec22[0] = max((fRec22[1] * fTemp51), fSlow3);
			float 	fTemp52 = max(min(((0.5f * (fVec3[0] - fRec6[0])) + (0.2f - (0.8f * ((iTemp17) ? (2.0f * (((fRec22[0] > fRec21[0])) ? fRec22[0] : (0.0f - fRec21[0]))) : fSlow4)))), 1.0f), 0.0f);
			float 	fTemp53 = ftbl0[iTemp47];
			float 	fTemp54 = (((fTemp53 + (fTemp50 * (ftbl0[iTemp49] - fTemp53))) * (1.0f - fTemp52)) + (fTemp52 * (fTemp48 + (fTemp50 * (ftbl1[iTemp49] - fTemp48)))));
			float 	fTemp55 = (fRec19[1] - fConst22);
			float 	fTemp56 = (fConst22 + fRec19[1]);
			fRec19[0] = (((fTemp56 < fTemp54)) ? fTemp56 : (((fTemp55 > fTemp54)) ? fTemp55 : fTemp54));
			float 	fTemp57 = ((iTemp2) ? 0.0f : (fSlow23 + fRec23[1]));
			fRec23[0] = (fTemp57 - floorf(fTemp57));
			float 	fTemp58 = (499.0f * fRec23[0]);
			int 	iTemp59 = int(fTemp58);
			float 	fTemp60 = ftbl0[max(0, min(iTemp59, 499))];
			float 	fTemp61 = ((iTemp2) ? 0.0f : (fSlow24 + fRec24[1]));
			fRec24[0] = (fTemp61 - floorf(fTemp61));
			float 	fTemp62 = (499.0f * fRec24[0]);
			int 	iTemp63 = int(fTemp62);
			float 	fTemp64 = ftbl1[max(0, min(iTemp63, 499))];
			fVec5[0] = fSlow29;
			int 	iTemp65 = (fSlow29 != fVec5[1]);
			iVec6[0] = iTemp65;
			int 	iTemp66 = ((iVec6[1] <= 0) & (iVec6[0] > 0));
			iRec28[0] = ((iRec28[1] * (1 - iTemp66)) + (iTemp14 * iTemp66));
			float 	fTemp67 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec28[0])))) > 0.5f) & iSlow30)) ? 0.0f : fSlow28) + 1.0f)) + 0.5f))];
			fVec7[0] = fTemp67;
			int 	iTemp68 = (fVec7[0] > 0.003f);
			int 	iTemp69 = (fVec7[0] <= 0.003f);
			float 	fTemp70 = float((iTemp69 | (fVec7[1] >= 0.003f)));
			fRec29[0] = max((fRec29[1] * fTemp70), fSlow29);
			fRec30[0] = max((fTemp70 * fRec30[1]), fSlow31);
			float 	fTemp71 = (min(1.0f, fRec30[0]) + min(1.0f, (0.7f * fRec29[0])));
			int 	iTemp72 = (fVec7[0] >= fRec27[1]);
			int 	iTemp73 = (fRec27[1] <= 0.001f);
			int 	iTemp74 = (((iRec26[1] >= 4)) ? (((iRec26[1] >= 6)) ? ((iTemp73) ? 0 : ((iTemp68) ? 1 : 6)) : (((iRec26[1] >= 5)) ? ((iTemp69) ? 3 : ((iTemp72) ? 4 : 5)) : ((iTemp69) ? 3 : (((fVec7[0] <= fRec27[1])) ? 5 : 4)))) : (((iRec26[1] >= 2)) ? (((iRec26[1] >= 3)) ? (((iTemp69 & iTemp73)) ? 0 : ((iTemp68) ? 1 : 3)) : ((iTemp68) ? ((iTemp72) ? 4 : 2) : 6)) : (((iRec26[1] >= 1)) ? (((fRec27[1] >= min(fTemp71, 1.0f))) ? ((iTemp69) ? 6 : 2) : 1) : ((iTemp68) ? 1 : 0))));
			iRec26[0] = iTemp74;
			float 	fTemp75 = (((iTemp74 >= 4)) ? (((iTemp74 >= 6)) ? fConst15 : fConst12) : (((iTemp74 >= 2)) ? (((iTemp74 >= 3)) ? fConst14 : fConst13) : (((iTemp74 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp76 = (iRec26[1] != iRec26[2]);
			iVec8[0] = iTemp76;
			int 	iTemp77 = ((iVec8[1] <= 0) & (iVec8[0] > 0));
			iRec32[0] = ((iRec32[1] * (1 - iTemp77)) + (iTemp14 * iTemp77));
			float 	fTemp78 = (2e+01f * (((fTemp75 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec32[0]))) / fTemp75) : 0.0f));
			int 	iTemp79 = int(fTemp78);
			float 	fTemp80 = ftbl3[max(0, int(min(int(iTemp79), 20)))];
			float 	fTemp81 = (fTemp80 + ((fTemp78 - float(iTemp79)) * (ftbl3[max(0, int(min(int((iTemp79 + 1)), 20)))] - fTemp80)));
			fRec33[0] = max((fRec33[1] * float(iVec8[0])), max(fVec7[0], fRec27[1]));
			int 	iTemp82 = (iRec26[1] == 3);
			int 	iTemp83 = (iRec26[1] == 6);
			int 	iTemp84 = (iRec26[1] == 0);
			float 	fTemp85 = (((iRec26[1] == 1)) ? min(1.0f, fTemp71) : ((iTemp84) ? 0.0f : ((iTemp83) ? (fTemp71 * fTemp81) : ((iTemp82) ? (fRec33[0] * fTemp81) : fVec7[0]))));
			float 	fTemp86 = (1.0f / ((iTemp84) ? 0.0001f : (((iTemp82 | iTemp83)) ? (0.04761905f * fTemp75) : fTemp75)));
			float 	fTemp87 = (fRec31[1] - fTemp86);
			float 	fTemp88 = (fRec31[1] + fTemp86);
			fRec31[0] = (((fTemp88 < fTemp85)) ? fTemp88 : (((fTemp87 > fTemp85)) ? fTemp87 : fTemp85));
			fRec27[0] = fRec31[0];
			float 	fTemp89 = (fRec25[1] - fConst16);
			float 	fTemp90 = (fConst16 + fRec25[1]);
			fRec25[0] = (((fTemp90 < fRec27[0])) ? fTemp90 : (((fTemp89 > fRec27[0])) ? fTemp89 : fRec27[0]));
			int 	iTemp91 = (fRec25[0] < 0.1f);
			float 	fTemp92 = (((iTemp91) ? fRec25[0] : 0.1f) * fSlow27);
			fRec34[0] = (fTemp42 - (fSlow39 * ((fSlow37 * fRec34[2]) + (fSlow34 * fRec34[1]))));
			float 	fTemp93 = min(1.0f, (fSlow40 + ((iTemp91) ? (1.0f - (1e+01f * fRec25[0])) : 0.0f)));
			float 	fTemp94 = ((iTemp2) ? 0.0f : (fSlow42 + fRec36[1]));
			fRec36[0] = (fTemp94 - floorf(fTemp94));
			float 	fTemp95 = (499.0f * fRec36[0]);
			int 	iTemp96 = int(fTemp95);
			int 	iTemp97 = max(0, min(iTemp96, 499));
			float 	fTemp98 = ftbl1[iTemp97];
			int 	iTemp99 = max(0, min((iTemp96 + 1), 499));
			float 	fTemp100 = (fTemp95 - float(iTemp96));
			float 	fTemp101 = float((((fVec7[1] <= 0.003f) & iTemp68) != 1));
			fRec37[0] = max((fTemp101 * fRec37[1]), fSlow43);
			fRec38[0] = max((fRec38[1] * fTemp101), fSlow25);
			float 	fTemp102 = max(min(((0.5f * (fVec7[0] - fRec25[0])) + (0.2f - (0.8f * ((iTemp69) ? (2.0f * (((fRec38[0] > fRec37[0])) ? fRec38[0] : (0.0f - fRec37[0]))) : fSlow26)))), 1.0f), 0.0f);
			float 	fTemp103 = ftbl0[iTemp97];
			float 	fTemp104 = (((fTemp103 + (fTemp100 * (ftbl0[iTemp99] - fTemp103))) * (1.0f - fTemp102)) + (fTemp102 * (fTemp98 + (fTemp100 * (ftbl1[iTemp99] - fTemp98)))));
			float 	fTemp105 = (fRec35[1] - fConst22);
			float 	fTemp106 = (fConst22 + fRec35[1]);
			fRec35[0] = (((fTemp106 < fTemp104)) ? fTemp106 : (((fTemp105 > fTemp104)) ? fTemp105 : fTemp104));
			float 	fTemp107 = ((iTemp2) ? 0.0f : (fSlow45 + fRec39[1]));
			fRec39[0] = (fTemp107 - floorf(fTemp107));
			float 	fTemp108 = (499.0f * fRec39[0]);
			int 	iTemp109 = int(fTemp108);
			float 	fTemp110 = ftbl0[max(0, min(iTemp109, 499))];
			float 	fTemp111 = ((iTemp2) ? 0.0f : (fSlow46 + fRec40[1]));
			fRec40[0] = (fTemp111 - floorf(fTemp111));
			float 	fTemp112 = (499.0f * fRec40[0]);
			int 	iTemp113 = int(fTemp112);
			float 	fTemp114 = ftbl1[max(0, min(iTemp113, 499))];
			fVec9[0] = fSlow51;
			int 	iTemp115 = (fSlow51 != fVec9[1]);
			iVec10[0] = iTemp115;
			int 	iTemp116 = ((iVec10[1] <= 0) & (iVec10[0] > 0));
			iRec44[0] = ((iRec44[1] * (1 - iTemp116)) + (iTemp14 * iTemp116));
			float 	fTemp117 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec44[0])))) > 0.5f) & iSlow52)) ? 0.0f : fSlow50) + 1.0f)) + 0.5f))];
			fVec11[0] = fTemp117;
			int 	iTemp118 = (fVec11[0] > 0.003f);
			int 	iTemp119 = (fVec11[0] <= 0.003f);
			float 	fTemp120 = float((iTemp119 | (fVec11[1] >= 0.003f)));
			fRec45[0] = max((fRec45[1] * fTemp120), fSlow51);
			fRec46[0] = max((fTemp120 * fRec46[1]), fSlow53);
			float 	fTemp121 = (min(1.0f, fRec46[0]) + min(1.0f, (0.7f * fRec45[0])));
			int 	iTemp122 = (fVec11[0] >= fRec43[1]);
			int 	iTemp123 = (fRec43[1] <= 0.001f);
			int 	iTemp124 = (((iRec42[1] >= 4)) ? (((iRec42[1] >= 6)) ? ((iTemp123) ? 0 : ((iTemp118) ? 1 : 6)) : (((iRec42[1] >= 5)) ? ((iTemp119) ? 3 : ((iTemp122) ? 4 : 5)) : ((iTemp119) ? 3 : (((fVec11[0] <= fRec43[1])) ? 5 : 4)))) : (((iRec42[1] >= 2)) ? (((iRec42[1] >= 3)) ? (((iTemp119 & iTemp123)) ? 0 : ((iTemp118) ? 1 : 3)) : ((iTemp118) ? ((iTemp122) ? 4 : 2) : 6)) : (((iRec42[1] >= 1)) ? (((fRec43[1] >= min(fTemp121, 1.0f))) ? ((iTemp119) ? 6 : 2) : 1) : ((iTemp118) ? 1 : 0))));
			iRec42[0] = iTemp124;
			float 	fTemp125 = (((iTemp124 >= 4)) ? (((iTemp124 >= 6)) ? fConst15 : fConst12) : (((iTemp124 >= 2)) ? (((iTemp124 >= 3)) ? fConst14 : fConst13) : (((iTemp124 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp126 = (iRec42[1] != iRec42[2]);
			iVec12[0] = iTemp126;
			int 	iTemp127 = ((iVec12[1] <= 0) & (iVec12[0] > 0));
			iRec48[0] = ((iRec48[1] * (1 - iTemp127)) + (iTemp14 * iTemp127));
			float 	fTemp128 = (2e+01f * (((fTemp125 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec48[0]))) / fTemp125) : 0.0f));
			int 	iTemp129 = int(fTemp128);
			float 	fTemp130 = ftbl3[max(0, int(min(int(iTemp129), 20)))];
			float 	fTemp131 = (fTemp130 + ((fTemp128 - float(iTemp129)) * (ftbl3[max(0, int(min(int((iTemp129 + 1)), 20)))] - fTemp130)));
			fRec49[0] = max((fRec49[1] * float(iVec12[0])), max(fVec11[0], fRec43[1]));
			int 	iTemp132 = (iRec42[1] == 3);
			int 	iTemp133 = (iRec42[1] == 6);
			int 	iTemp134 = (iRec42[1] == 0);
			float 	fTemp135 = (((iRec42[1] == 1)) ? min(1.0f, fTemp121) : ((iTemp134) ? 0.0f : ((iTemp133) ? (fTemp121 * fTemp131) : ((iTemp132) ? (fRec49[0] * fTemp131) : fVec11[0]))));
			float 	fTemp136 = (1.0f / ((iTemp134) ? 0.0001f : (((iTemp132 | iTemp133)) ? (0.04761905f * fTemp125) : fTemp125)));
			float 	fTemp137 = (fRec47[1] - fTemp136);
			float 	fTemp138 = (fRec47[1] + fTemp136);
			fRec47[0] = (((fTemp138 < fTemp135)) ? fTemp138 : (((fTemp137 > fTemp135)) ? fTemp137 : fTemp135));
			fRec43[0] = fRec47[0];
			float 	fTemp139 = (fRec41[1] - fConst16);
			float 	fTemp140 = (fConst16 + fRec41[1]);
			fRec41[0] = (((fTemp140 < fRec43[0])) ? fTemp140 : (((fTemp139 > fRec43[0])) ? fTemp139 : fRec43[0]));
			int 	iTemp141 = (fRec41[0] < 0.1f);
			float 	fTemp142 = (((iTemp141) ? fRec41[0] : 0.1f) * fSlow49);
			fRec50[0] = (fTemp42 - (fSlow61 * ((fSlow59 * fRec50[2]) + (fSlow56 * fRec50[1]))));
			float 	fTemp143 = min(1.0f, (fSlow62 + ((iTemp141) ? (1.0f - (1e+01f * fRec41[0])) : 0.0f)));
			float 	fTemp144 = ((iTemp2) ? 0.0f : (fSlow64 + fRec52[1]));
			fRec52[0] = (fTemp144 - floorf(fTemp144));
			float 	fTemp145 = (499.0f * fRec52[0]);
			int 	iTemp146 = int(fTemp145);
			int 	iTemp147 = max(0, min(iTemp146, 499));
			float 	fTemp148 = ftbl1[iTemp147];
			int 	iTemp149 = max(0, min((iTemp146 + 1), 499));
			float 	fTemp150 = (fTemp145 - float(iTemp146));
			float 	fTemp151 = float((((fVec11[1] <= 0.003f) & iTemp118) != 1));
			fRec53[0] = max((fTemp151 * fRec53[1]), fSlow65);
			fRec54[0] = max((fRec54[1] * fTemp151), fSlow47);
			float 	fTemp152 = max(min(((0.5f * (fVec11[0] - fRec41[0])) + (0.2f - (0.8f * ((iTemp119) ? (2.0f * (((fRec54[0] > fRec53[0])) ? fRec54[0] : (0.0f - fRec53[0]))) : fSlow48)))), 1.0f), 0.0f);
			float 	fTemp153 = ftbl0[iTemp147];
			float 	fTemp154 = (((fTemp153 + (fTemp150 * (ftbl0[iTemp149] - fTemp153))) * (1.0f - fTemp152)) + (fTemp152 * (fTemp148 + (fTemp150 * (ftbl1[iTemp149] - fTemp148)))));
			float 	fTemp155 = (fRec51[1] - fConst22);
			float 	fTemp156 = (fConst22 + fRec51[1]);
			fRec51[0] = (((fTemp156 < fTemp154)) ? fTemp156 : (((fTemp155 > fTemp154)) ? fTemp155 : fTemp154));
			float 	fTemp157 = ((iTemp2) ? 0.0f : (fSlow67 + fRec55[1]));
			fRec55[0] = (fTemp157 - floorf(fTemp157));
			float 	fTemp158 = (499.0f * fRec55[0]);
			int 	iTemp159 = int(fTemp158);
			float 	fTemp160 = ftbl0[max(0, min(iTemp159, 499))];
			float 	fTemp161 = ((iTemp2) ? 0.0f : (fSlow68 + fRec56[1]));
			fRec56[0] = (fTemp161 - floorf(fTemp161));
			float 	fTemp162 = (499.0f * fRec56[0]);
			int 	iTemp163 = int(fTemp162);
			float 	fTemp164 = ftbl1[max(0, min(iTemp163, 499))];
			fVec13[0] = fSlow73;
			int 	iTemp165 = (fSlow73 != fVec13[1]);
			iVec14[0] = iTemp165;
			int 	iTemp166 = ((iVec14[1] <= 0) & (iVec14[0] > 0));
			iRec60[0] = ((iRec60[1] * (1 - iTemp166)) + (iTemp14 * iTemp166));
			float 	fTemp167 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec60[0])))) > 0.5f) & iSlow74)) ? 0.0f : fSlow72) + 1.0f)) + 0.5f))];
			fVec15[0] = fTemp167;
			int 	iTemp168 = (fVec15[0] > 0.003f);
			int 	iTemp169 = (fVec15[0] <= 0.003f);
			float 	fTemp170 = float((iTemp169 | (fVec15[1] >= 0.003f)));
			fRec61[0] = max((fRec61[1] * fTemp170), fSlow73);
			fRec62[0] = max((fTemp170 * fRec62[1]), fSlow75);
			float 	fTemp171 = (min(1.0f, fRec62[0]) + min(1.0f, (0.7f * fRec61[0])));
			int 	iTemp172 = (fVec15[0] >= fRec59[1]);
			int 	iTemp173 = (fRec59[1] <= 0.001f);
			int 	iTemp174 = (((iRec58[1] >= 4)) ? (((iRec58[1] >= 6)) ? ((iTemp173) ? 0 : ((iTemp168) ? 1 : 6)) : (((iRec58[1] >= 5)) ? ((iTemp169) ? 3 : ((iTemp172) ? 4 : 5)) : ((iTemp169) ? 3 : (((fVec15[0] <= fRec59[1])) ? 5 : 4)))) : (((iRec58[1] >= 2)) ? (((iRec58[1] >= 3)) ? (((iTemp169 & iTemp173)) ? 0 : ((iTemp168) ? 1 : 3)) : ((iTemp168) ? ((iTemp172) ? 4 : 2) : 6)) : (((iRec58[1] >= 1)) ? (((fRec59[1] >= min(fTemp171, 1.0f))) ? ((iTemp169) ? 6 : 2) : 1) : ((iTemp168) ? 1 : 0))));
			iRec58[0] = iTemp174;
			float 	fTemp175 = (((iTemp174 >= 4)) ? (((iTemp174 >= 6)) ? fConst15 : fConst12) : (((iTemp174 >= 2)) ? (((iTemp174 >= 3)) ? fConst14 : fConst13) : (((iTemp174 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp176 = (iRec58[1] != iRec58[2]);
			iVec16[0] = iTemp176;
			int 	iTemp177 = ((iVec16[1] <= 0) & (iVec16[0] > 0));
			iRec64[0] = ((iRec64[1] * (1 - iTemp177)) + (iTemp14 * iTemp177));
			float 	fTemp178 = (2e+01f * (((fTemp175 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec64[0]))) / fTemp175) : 0.0f));
			int 	iTemp179 = int(fTemp178);
			float 	fTemp180 = ftbl3[max(0, int(min(int(iTemp179), 20)))];
			float 	fTemp181 = (fTemp180 + ((fTemp178 - float(iTemp179)) * (ftbl3[max(0, int(min(int((iTemp179 + 1)), 20)))] - fTemp180)));
			fRec65[0] = max((fRec65[1] * float(iVec16[0])), max(fVec15[0], fRec59[1]));
			int 	iTemp182 = (iRec58[1] == 3);
			int 	iTemp183 = (iRec58[1] == 6);
			int 	iTemp184 = (iRec58[1] == 0);
			float 	fTemp185 = (((iRec58[1] == 1)) ? min(1.0f, fTemp171) : ((iTemp184) ? 0.0f : ((iTemp183) ? (fTemp171 * fTemp181) : ((iTemp182) ? (fRec65[0] * fTemp181) : fVec15[0]))));
			float 	fTemp186 = (1.0f / ((iTemp184) ? 0.0001f : (((iTemp182 | iTemp183)) ? (0.04761905f * fTemp175) : fTemp175)));
			float 	fTemp187 = (fRec63[1] - fTemp186);
			float 	fTemp188 = (fRec63[1] + fTemp186);
			fRec63[0] = (((fTemp188 < fTemp185)) ? fTemp188 : (((fTemp187 > fTemp185)) ? fTemp187 : fTemp185));
			fRec59[0] = fRec63[0];
			float 	fTemp189 = (fRec57[1] - fConst16);
			float 	fTemp190 = (fConst16 + fRec57[1]);
			fRec57[0] = (((fTemp190 < fRec59[0])) ? fTemp190 : (((fTemp189 > fRec59[0])) ? fTemp189 : fRec59[0]));
			int 	iTemp191 = (fRec57[0] < 0.1f);
			float 	fTemp192 = (((iTemp191) ? fRec57[0] : 0.1f) * fSlow71);
			fRec66[0] = (fTemp42 - (fSlow83 * ((fSlow81 * fRec66[2]) + (fSlow78 * fRec66[1]))));
			float 	fTemp193 = min(1.0f, (fSlow84 + ((iTemp191) ? (1.0f - (1e+01f * fRec57[0])) : 0.0f)));
			float 	fTemp194 = ((iTemp2) ? 0.0f : (fSlow86 + fRec68[1]));
			fRec68[0] = (fTemp194 - floorf(fTemp194));
			float 	fTemp195 = (499.0f * fRec68[0]);
			int 	iTemp196 = int(fTemp195);
			int 	iTemp197 = max(0, min(iTemp196, 499));
			float 	fTemp198 = ftbl1[iTemp197];
			int 	iTemp199 = max(0, min((iTemp196 + 1), 499));
			float 	fTemp200 = (fTemp195 - float(iTemp196));
			float 	fTemp201 = float((((fVec15[1] <= 0.003f) & iTemp168) != 1));
			fRec69[0] = max((fTemp201 * fRec69[1]), fSlow87);
			fRec70[0] = max((fRec70[1] * fTemp201), fSlow69);
			float 	fTemp202 = max(min(((0.5f * (fVec15[0] - fRec57[0])) + (0.2f - (0.8f * ((iTemp169) ? (2.0f * (((fRec70[0] > fRec69[0])) ? fRec70[0] : (0.0f - fRec69[0]))) : fSlow70)))), 1.0f), 0.0f);
			float 	fTemp203 = ftbl0[iTemp197];
			float 	fTemp204 = (((fTemp203 + (fTemp200 * (ftbl0[iTemp199] - fTemp203))) * (1.0f - fTemp202)) + (fTemp202 * (fTemp198 + (fTemp200 * (ftbl1[iTemp199] - fTemp198)))));
			float 	fTemp205 = (fRec67[1] - fConst22);
			float 	fTemp206 = (fConst22 + fRec67[1]);
			fRec67[0] = (((fTemp206 < fTemp204)) ? fTemp206 : (((fTemp205 > fTemp204)) ? fTemp205 : fTemp204));
			float 	fTemp207 = ((iTemp2) ? 0.0f : (fSlow89 + fRec71[1]));
			fRec71[0] = (fTemp207 - floorf(fTemp207));
			float 	fTemp208 = (499.0f * fRec71[0]);
			int 	iTemp209 = int(fTemp208);
			float 	fTemp210 = ftbl0[max(0, min(iTemp209, 499))];
			float 	fTemp211 = ((iTemp2) ? 0.0f : (fSlow90 + fRec72[1]));
			fRec72[0] = (fTemp211 - floorf(fTemp211));
			float 	fTemp212 = (499.0f * fRec72[0]);
			int 	iTemp213 = int(fTemp212);
			float 	fTemp214 = ftbl1[max(0, min(iTemp213, 499))];
			fVec17[0] = fSlow95;
			int 	iTemp215 = (fSlow95 != fVec17[1]);
			iVec18[0] = iTemp215;
			int 	iTemp216 = ((iVec18[1] <= 0) & (iVec18[0] > 0));
			iRec76[0] = ((iRec76[1] * (1 - iTemp216)) + (iTemp14 * iTemp216));
			float 	fTemp217 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec76[0])))) > 0.5f) & iSlow96)) ? 0.0f : fSlow94) + 1.0f)) + 0.5f))];
			fVec19[0] = fTemp217;
			int 	iTemp218 = (fVec19[0] > 0.003f);
			int 	iTemp219 = (fVec19[0] <= 0.003f);
			float 	fTemp220 = float((iTemp219 | (fVec19[1] >= 0.003f)));
			fRec77[0] = max((fRec77[1] * fTemp220), fSlow95);
			fRec78[0] = max((fTemp220 * fRec78[1]), fSlow97);
			float 	fTemp221 = (min(1.0f, fRec78[0]) + min(1.0f, (0.7f * fRec77[0])));
			int 	iTemp222 = (fVec19[0] >= fRec75[1]);
			int 	iTemp223 = (fRec75[1] <= 0.001f);
			int 	iTemp224 = (((iRec74[1] >= 4)) ? (((iRec74[1] >= 6)) ? ((iTemp223) ? 0 : ((iTemp218) ? 1 : 6)) : (((iRec74[1] >= 5)) ? ((iTemp219) ? 3 : ((iTemp222) ? 4 : 5)) : ((iTemp219) ? 3 : (((fVec19[0] <= fRec75[1])) ? 5 : 4)))) : (((iRec74[1] >= 2)) ? (((iRec74[1] >= 3)) ? (((iTemp219 & iTemp223)) ? 0 : ((iTemp218) ? 1 : 3)) : ((iTemp218) ? ((iTemp222) ? 4 : 2) : 6)) : (((iRec74[1] >= 1)) ? (((fRec75[1] >= min(fTemp221, 1.0f))) ? ((iTemp219) ? 6 : 2) : 1) : ((iTemp218) ? 1 : 0))));
			iRec74[0] = iTemp224;
			float 	fTemp225 = (((iTemp224 >= 4)) ? (((iTemp224 >= 6)) ? fConst15 : fConst12) : (((iTemp224 >= 2)) ? (((iTemp224 >= 3)) ? fConst14 : fConst13) : (((iTemp224 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp226 = (iRec74[1] != iRec74[2]);
			iVec20[0] = iTemp226;
			int 	iTemp227 = ((iVec20[1] <= 0) & (iVec20[0] > 0));
			iRec80[0] = ((iRec80[1] * (1 - iTemp227)) + (iTemp14 * iTemp227));
			float 	fTemp228 = (2e+01f * (((fTemp225 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec80[0]))) / fTemp225) : 0.0f));
			int 	iTemp229 = int(fTemp228);
			float 	fTemp230 = ftbl3[max(0, int(min(int(iTemp229), 20)))];
			float 	fTemp231 = (fTemp230 + ((fTemp228 - float(iTemp229)) * (ftbl3[max(0, int(min(int((iTemp229 + 1)), 20)))] - fTemp230)));
			fRec81[0] = max((fRec81[1] * float(iVec20[0])), max(fVec19[0], fRec75[1]));
			int 	iTemp232 = (iRec74[1] == 3);
			int 	iTemp233 = (iRec74[1] == 6);
			int 	iTemp234 = (iRec74[1] == 0);
			float 	fTemp235 = (((iRec74[1] == 1)) ? min(1.0f, fTemp221) : ((iTemp234) ? 0.0f : ((iTemp233) ? (fTemp221 * fTemp231) : ((iTemp232) ? (fRec81[0] * fTemp231) : fVec19[0]))));
			float 	fTemp236 = (1.0f / ((iTemp234) ? 0.0001f : (((iTemp232 | iTemp233)) ? (0.04761905f * fTemp225) : fTemp225)));
			float 	fTemp237 = (fRec79[1] - fTemp236);
			float 	fTemp238 = (fRec79[1] + fTemp236);
			fRec79[0] = (((fTemp238 < fTemp235)) ? fTemp238 : (((fTemp237 > fTemp235)) ? fTemp237 : fTemp235));
			fRec75[0] = fRec79[0];
			float 	fTemp239 = (fRec73[1] - fConst16);
			float 	fTemp240 = (fConst16 + fRec73[1]);
			fRec73[0] = (((fTemp240 < fRec75[0])) ? fTemp240 : (((fTemp239 > fRec75[0])) ? fTemp239 : fRec75[0]));
			int 	iTemp241 = (fRec73[0] < 0.1f);
			float 	fTemp242 = (((iTemp241) ? fRec73[0] : 0.1f) * fSlow93);
			fRec82[0] = (fTemp42 - (fSlow105 * ((fSlow103 * fRec82[2]) + (fSlow100 * fRec82[1]))));
			float 	fTemp243 = min(1.0f, (fSlow106 + ((iTemp241) ? (1.0f - (1e+01f * fRec73[0])) : 0.0f)));
			float 	fTemp244 = ((iTemp2) ? 0.0f : (fSlow108 + fRec84[1]));
			fRec84[0] = (fTemp244 - floorf(fTemp244));
			float 	fTemp245 = (499.0f * fRec84[0]);
			int 	iTemp246 = int(fTemp245);
			int 	iTemp247 = max(0, min(iTemp246, 499));
			float 	fTemp248 = ftbl1[iTemp247];
			int 	iTemp249 = max(0, min((iTemp246 + 1), 499));
			float 	fTemp250 = (fTemp245 - float(iTemp246));
			float 	fTemp251 = float((((fVec19[1] <= 0.003f) & iTemp218) != 1));
			fRec85[0] = max((fTemp251 * fRec85[1]), fSlow109);
			fRec86[0] = max((fRec86[1] * fTemp251), fSlow91);
			float 	fTemp252 = max(min(((0.5f * (fVec19[0] - fRec73[0])) + (0.2f - (0.8f * ((iTemp219) ? (2.0f * (((fRec86[0] > fRec85[0])) ? fRec86[0] : (0.0f - fRec85[0]))) : fSlow92)))), 1.0f), 0.0f);
			float 	fTemp253 = ftbl0[iTemp247];
			float 	fTemp254 = (((fTemp253 + (fTemp250 * (ftbl0[iTemp249] - fTemp253))) * (1.0f - fTemp252)) + (fTemp252 * (fTemp248 + (fTemp250 * (ftbl1[iTemp249] - fTemp248)))));
			float 	fTemp255 = (fRec83[1] - fConst22);
			float 	fTemp256 = (fConst22 + fRec83[1]);
			fRec83[0] = (((fTemp256 < fTemp254)) ? fTemp256 : (((fTemp255 > fTemp254)) ? fTemp255 : fTemp254));
			float 	fTemp257 = ((iTemp2) ? 0.0f : (fSlow111 + fRec87[1]));
			fRec87[0] = (fTemp257 - floorf(fTemp257));
			float 	fTemp258 = (499.0f * fRec87[0]);
			int 	iTemp259 = int(fTemp258);
			float 	fTemp260 = ftbl0[max(0, min(iTemp259, 499))];
			float 	fTemp261 = ((iTemp2) ? 0.0f : (fSlow112 + fRec88[1]));
			fRec88[0] = (fTemp261 - floorf(fTemp261));
			float 	fTemp262 = (499.0f * fRec88[0]);
			int 	iTemp263 = int(fTemp262);
			float 	fTemp264 = ftbl1[max(0, min(iTemp263, 499))];
			fVec21[0] = fSlow117;
			int 	iTemp265 = (fSlow117 != fVec21[1]);
			iVec22[0] = iTemp265;
			int 	iTemp266 = ((iVec22[1] <= 0) & (iVec22[0] > 0));
			iRec92[0] = ((iRec92[1] * (1 - iTemp266)) + (iTemp14 * iTemp266));
			float 	fTemp267 = ftbl2[int(((499.5f * ((((((fConst11 * float((iRec10[0] + (-1 - iRec92[0])))) > 0.5f) & iSlow118)) ? 0.0f : fSlow116) + 1.0f)) + 0.5f))];
			fVec23[0] = fTemp267;
			int 	iTemp268 = (fVec23[0] > 0.003f);
			int 	iTemp269 = (fVec23[0] <= 0.003f);
			float 	fTemp270 = float((iTemp269 | (fVec23[1] >= 0.003f)));
			fRec93[0] = max((fRec93[1] * fTemp270), fSlow117);
			fRec94[0] = max((fTemp270 * fRec94[1]), fSlow119);
			float 	fTemp271 = (min(1.0f, fRec94[0]) + min(1.0f, (0.7f * fRec93[0])));
			int 	iTemp272 = (fVec23[0] >= fRec91[1]);
			int 	iTemp273 = (fRec91[1] <= 0.001f);
			int 	iTemp274 = (((iRec90[1] >= 4)) ? (((iRec90[1] >= 6)) ? ((iTemp273) ? 0 : ((iTemp268) ? 1 : 6)) : (((iRec90[1] >= 5)) ? ((iTemp269) ? 3 : ((iTemp272) ? 4 : 5)) : ((iTemp269) ? 3 : (((fVec23[0] <= fRec91[1])) ? 5 : 4)))) : (((iRec90[1] >= 2)) ? (((iRec90[1] >= 3)) ? (((iTemp269 & iTemp273)) ? 0 : ((iTemp268) ? 1 : 3)) : ((iTemp268) ? ((iTemp272) ? 4 : 2) : 6)) : (((iRec90[1] >= 1)) ? (((fRec91[1] >= min(fTemp271, 1.0f))) ? ((iTemp269) ? 6 : 2) : 1) : ((iTemp268) ? 1 : 0))));
			iRec90[0] = iTemp274;
			float 	fTemp275 = (((iTemp274 >= 4)) ? (((iTemp274 >= 6)) ? fConst15 : fConst12) : (((iTemp274 >= 2)) ? (((iTemp274 >= 3)) ? fConst14 : fConst13) : (((iTemp274 >= 1)) ? fConst12 : 0.0f)));
			int 	iTemp276 = (iRec90[1] != iRec90[2]);
			iVec24[0] = iTemp276;
			int 	iTemp277 = ((iVec24[1] <= 0) & (iVec24[0] > 0));
			iRec96[0] = ((iRec96[1] * (1 - iTemp277)) + (iTemp14 * iTemp277));
			float 	fTemp278 = (2e+01f * (((fTemp275 > 0.0f)) ? (float((iRec10[0] + (-1 - iRec96[0]))) / fTemp275) : 0.0f));
			int 	iTemp279 = int(fTemp278);
			float 	fTemp280 = ftbl3[max(0, int(min(int(iTemp279), 20)))];
			float 	fTemp281 = (fTemp280 + ((fTemp278 - float(iTemp279)) * (ftbl3[max(0, int(min(int((iTemp279 + 1)), 20)))] - fTemp280)));
			fRec97[0] = max((fRec97[1] * float(iVec24[0])), max(fVec23[0], fRec91[1]));
			int 	iTemp282 = (iRec90[1] == 3);
			int 	iTemp283 = (iRec90[1] == 6);
			int 	iTemp284 = (iRec90[1] == 0);
			float 	fTemp285 = (((iRec90[1] == 1)) ? min(1.0f, fTemp271) : ((iTemp284) ? 0.0f : ((iTemp283) ? (fTemp271 * fTemp281) : ((iTemp282) ? (fRec97[0] * fTemp281) : fVec23[0]))));
			float 	fTemp286 = (1.0f / ((iTemp284) ? 0.0001f : (((iTemp282 | iTemp283)) ? (0.04761905f * fTemp275) : fTemp275)));
			float 	fTemp287 = (fRec95[1] - fTemp286);
			float 	fTemp288 = (fRec95[1] + fTemp286);
			fRec95[0] = (((fTemp288 < fTemp285)) ? fTemp288 : (((fTemp287 > fTemp285)) ? fTemp287 : fTemp285));
			fRec91[0] = fRec95[0];
			float 	fTemp289 = (fRec89[1] - fConst16);
			float 	fTemp290 = (fConst16 + fRec89[1]);
			fRec89[0] = (((fTemp290 < fRec91[0])) ? fTemp290 : (((fTemp289 > fRec91[0])) ? fTemp289 : fRec91[0]));
			int 	iTemp291 = (fRec89[0] < 0.1f);
			float 	fTemp292 = (((iTemp291) ? fRec89[0] : 0.1f) * fSlow115);
			fRec98[0] = (fTemp42 - (fSlow127 * ((fSlow125 * fRec98[2]) + (fSlow122 * fRec98[1]))));
			float 	fTemp293 = min(1.0f, (fSlow128 + ((iTemp291) ? (1.0f - (1e+01f * fRec89[0])) : 0.0f)));
			float 	fTemp294 = ((iTemp2) ? 0.0f : (fSlow130 + fRec100[1]));
			fRec100[0] = (fTemp294 - floorf(fTemp294));
			float 	fTemp295 = (499.0f * fRec100[0]);
			int 	iTemp296 = int(fTemp295);
			int 	iTemp297 = max(0, min(iTemp296, 499));
			float 	fTemp298 = ftbl1[iTemp297];
			int 	iTemp299 = max(0, min((iTemp296 + 1), 499));
			float 	fTemp300 = (fTemp295 - float(iTemp296));
			float 	fTemp301 = float((((fVec23[1] <= 0.003f) & iTemp268) != 1));
			fRec101[0] = max((fTemp301 * fRec101[1]), fSlow131);
			fRec102[0] = max((fRec102[1] * fTemp301), fSlow113);
			float 	fTemp302 = max(min(((0.5f * (fVec23[0] - fRec89[0])) + (0.2f - (0.8f * ((iTemp269) ? (2.0f * (((fRec102[0] > fRec101[0])) ? fRec102[0] : (0.0f - fRec101[0]))) : fSlow114)))), 1.0f), 0.0f);
			float 	fTemp303 = ftbl0[iTemp297];
			float 	fTemp304 = (((fTemp303 + (fTemp300 * (ftbl0[iTemp299] - fTemp303))) * (1.0f - fTemp302)) + (fTemp302 * (fTemp298 + (fTemp300 * (ftbl1[iTemp299] - fTemp298)))));
			float 	fTemp305 = (fRec99[1] - fConst22);
			float 	fTemp306 = (fConst22 + fRec99[1]);
			fRec99[0] = (((fTemp306 < fTemp304)) ? fTemp306 : (((fTemp305 > fTemp304)) ? fTemp305 : fTemp304));
			fRec0[0] = ((1.37f * ((((((fRec89[0] * ((((1.1f * (fRec99[0] * (1.0f - fTemp293))) + (fSlow129 * (fTemp293 * (fRec98[0] - fRec98[2])))) * (1.0f - (0.5f * fTemp292))) + (0.5f * (fTemp292 * ((0.2f * (fTemp264 + ((fTemp262 - float(iTemp263)) * (ftbl1[max(0, min((iTemp263 + 1), 499))] - fTemp264)))) + (0.8f * (fTemp260 + ((fTemp258 - float(iTemp259)) * (ftbl0[max(0, min((iTemp259 + 1), 499))] - fTemp260))))))))) + (fRec73[0] * ((((1.1f * (fRec83[0] * (1.0f - fTemp243))) + (fSlow107 * (fTemp243 * (fRec82[0] - fRec82[2])))) * (1.0f - (0.5f * fTemp242))) + (0.5f * (fTemp242 * ((0.2f * (fTemp214 + ((fTemp212 - float(iTemp213)) * (ftbl1[max(0, min((iTemp213 + 1), 499))] - fTemp214)))) + (0.8f * (fTemp210 + ((fTemp208 - float(iTemp209)) * (ftbl0[max(0, min((iTemp209 + 1), 499))] - fTemp210)))))))))) + (fRec57[0] * ((((1.1f * (fRec67[0] * (1.0f - fTemp193))) + (fSlow85 * (fTemp193 * (fRec66[0] - fRec66[2])))) * (1.0f - (0.5f * fTemp192))) + (0.5f * (fTemp192 * ((0.2f * (fTemp164 + ((fTemp162 - float(iTemp163)) * (ftbl1[max(0, min((iTemp163 + 1), 499))] - fTemp164)))) + (0.8f * (fTemp160 + ((fTemp158 - float(iTemp159)) * (ftbl0[max(0, min((iTemp159 + 1), 499))] - fTemp160)))))))))) + (fRec41[0] * ((((1.1f * (fRec51[0] * (1.0f - fTemp143))) + (fSlow63 * (fTemp143 * (fRec50[0] - fRec50[2])))) * (1.0f - (0.5f * fTemp142))) + (0.5f * (fTemp142 * ((0.2f * (fTemp114 + ((fTemp112 - float(iTemp113)) * (ftbl1[max(0, min((iTemp113 + 1), 499))] - fTemp114)))) + (0.8f * (fTemp110 + ((fTemp108 - float(iTemp109)) * (ftbl0[max(0, min((iTemp109 + 1), 499))] - fTemp110)))))))))) + (fRec25[0] * ((((1.1f * (fRec35[0] * (1.0f - fTemp93))) + (fSlow41 * (fTemp93 * (fRec34[0] - fRec34[2])))) * (1.0f - (0.5f * fTemp92))) + (0.5f * (fTemp92 * ((0.2f * (fTemp64 + ((fTemp62 - float(iTemp63)) * (ftbl1[max(0, min((iTemp63 + 1), 499))] - fTemp64)))) + (0.8f * (fTemp60 + ((fTemp58 - float(iTemp59)) * (ftbl0[max(0, min((iTemp59 + 1), 499))] - fTemp60)))))))))) + (fRec6[0] * ((((1.1f * (fRec19[0] * (1.0f - fTemp43))) + (fSlow19 * (fTemp43 * (fRec17[0] - fRec17[2])))) * (1.0f - (0.5f * fTemp41))) + (0.5f * (fTemp41 * ((0.2f * (fTemp10 + ((fTemp8 - float(iTemp9)) * (ftbl1[max(0, min((iTemp9 + 1), 499))] - fTemp10)))) + (0.8f * (fTemp6 + ((fTemp4 - float(iTemp5)) * (ftbl0[max(0, min((iTemp5 + 1), 499))] - fTemp6))))))))))) - (fConst8 * ((fConst6 * fRec0[2]) + (fConst4 * fRec0[1]))));
			output0[i] = (FAUSTFLOAT)(((fConst23 * fRec0[1]) + (fConst8 * (fRec0[0] + fRec0[2]))));
>>>>>>> main
			// post processing
			fRec12[2] = fRec12[1]; fRec12[1] = fRec12[0];
			fRec110[1] = fRec110[0];
			fRec113[1] = fRec113[0];
			fRec112[1] = fRec112[0];
			fRec111[1] = fRec111[0];
			fRec109[2] = fRec109[1]; fRec109[1] = fRec109[0];
			fRec100[2] = fRec100[1]; fRec100[1] = fRec100[0];
			fRec102[1] = fRec102[0];
<<<<<<< HEAD
			fRec106[1] = fRec106[0];
			fRec108[1] = fRec108[0];
			iRec107[1] = iRec107[0];
			iVec26[1] = iVec26[0];
			iRec101[2] = iRec101[1]; iRec101[1] = iRec101[0];
			fRec105[1] = fRec105[0];
			fRec104[1] = fRec104[0];
			fVec25[1] = fVec25[0];
			iRec103[1] = iRec103[0];
=======
			fRec101[1] = fRec101[0];
			fRec100[1] = fRec100[0];
			fRec98[2] = fRec98[1]; fRec98[1] = fRec98[0];
			fRec89[1] = fRec89[0];
			fRec91[1] = fRec91[0];
			fRec95[1] = fRec95[0];
			fRec97[1] = fRec97[0];
			iRec96[1] = iRec96[0];
>>>>>>> main
			iVec24[1] = iVec24[0];
			fVec23[1] = fVec23[0];
			fRec99[1] = fRec99[0];
			fRec98[1] = fRec98[0];
			fRec94[1] = fRec94[0];
			fRec97[1] = fRec97[0];
			fRec96[1] = fRec96[0];
			fRec95[1] = fRec95[0];
			fRec93[2] = fRec93[1]; fRec93[1] = fRec93[0];
			fRec84[2] = fRec84[1]; fRec84[1] = fRec84[0];
			fRec86[1] = fRec86[0];
<<<<<<< HEAD
			fRec90[1] = fRec90[0];
			fRec92[1] = fRec92[0];
			iRec91[1] = iRec91[0];
			iVec22[1] = iVec22[0];
			iRec85[2] = iRec85[1]; iRec85[1] = iRec85[0];
			fRec89[1] = fRec89[0];
			fRec88[1] = fRec88[0];
			fVec21[1] = fVec21[0];
			iRec87[1] = iRec87[0];
=======
			fRec85[1] = fRec85[0];
			fRec84[1] = fRec84[0];
			fRec82[2] = fRec82[1]; fRec82[1] = fRec82[0];
			fRec73[1] = fRec73[0];
			fRec75[1] = fRec75[0];
			fRec79[1] = fRec79[0];
			fRec81[1] = fRec81[0];
			iRec80[1] = iRec80[0];
>>>>>>> main
			iVec20[1] = iVec20[0];
			fVec19[1] = fVec19[0];
			fRec83[1] = fRec83[0];
			fRec82[1] = fRec82[0];
			fRec78[1] = fRec78[0];
			fRec81[1] = fRec81[0];
			fRec80[1] = fRec80[0];
			fRec79[1] = fRec79[0];
			fRec77[2] = fRec77[1]; fRec77[1] = fRec77[0];
			fRec68[2] = fRec68[1]; fRec68[1] = fRec68[0];
			fRec70[1] = fRec70[0];
<<<<<<< HEAD
			fRec74[1] = fRec74[0];
			fRec76[1] = fRec76[0];
			iRec75[1] = iRec75[0];
			iVec18[1] = iVec18[0];
			iRec69[2] = iRec69[1]; iRec69[1] = iRec69[0];
			fRec73[1] = fRec73[0];
			fRec72[1] = fRec72[0];
			fVec17[1] = fVec17[0];
			iRec71[1] = iRec71[0];
=======
			fRec69[1] = fRec69[0];
			fRec68[1] = fRec68[0];
			fRec66[2] = fRec66[1]; fRec66[1] = fRec66[0];
			fRec57[1] = fRec57[0];
			fRec59[1] = fRec59[0];
			fRec63[1] = fRec63[0];
			fRec65[1] = fRec65[0];
			iRec64[1] = iRec64[0];
>>>>>>> main
			iVec16[1] = iVec16[0];
			fVec15[1] = fVec15[0];
			fRec67[1] = fRec67[0];
			fRec66[1] = fRec66[0];
			fRec62[1] = fRec62[0];
			fRec65[1] = fRec65[0];
			fRec64[1] = fRec64[0];
			fRec63[1] = fRec63[0];
			fRec61[2] = fRec61[1]; fRec61[1] = fRec61[0];
			fRec52[2] = fRec52[1]; fRec52[1] = fRec52[0];
			fRec54[1] = fRec54[0];
<<<<<<< HEAD
			fRec58[1] = fRec58[0];
			fRec60[1] = fRec60[0];
			iRec59[1] = iRec59[0];
			iVec14[1] = iVec14[0];
			iRec53[2] = iRec53[1]; iRec53[1] = iRec53[0];
			fRec57[1] = fRec57[0];
			fRec56[1] = fRec56[0];
			fVec13[1] = fVec13[0];
			iRec55[1] = iRec55[0];
=======
			fRec53[1] = fRec53[0];
			fRec52[1] = fRec52[0];
			fRec50[2] = fRec50[1]; fRec50[1] = fRec50[0];
			fRec41[1] = fRec41[0];
			fRec43[1] = fRec43[0];
			fRec47[1] = fRec47[0];
			fRec49[1] = fRec49[0];
			iRec48[1] = iRec48[0];
>>>>>>> main
			iVec12[1] = iVec12[0];
			fVec11[1] = fVec11[0];
			fRec51[1] = fRec51[0];
			fRec50[1] = fRec50[0];
			fRec46[1] = fRec46[0];
			fRec49[1] = fRec49[0];
			fRec48[1] = fRec48[0];
			fRec47[1] = fRec47[0];
			fRec45[2] = fRec45[1]; fRec45[1] = fRec45[0];
			fRec36[2] = fRec36[1]; fRec36[1] = fRec36[0];
			fRec38[1] = fRec38[0];
<<<<<<< HEAD
			fRec42[1] = fRec42[0];
			fRec44[1] = fRec44[0];
			iRec43[1] = iRec43[0];
			iVec10[1] = iVec10[0];
			iRec37[2] = iRec37[1]; iRec37[1] = iRec37[0];
			fRec41[1] = fRec41[0];
			fRec40[1] = fRec40[0];
			fVec9[1] = fVec9[0];
			iRec39[1] = iRec39[0];
=======
			fRec37[1] = fRec37[0];
			fRec36[1] = fRec36[0];
			fRec34[2] = fRec34[1]; fRec34[1] = fRec34[0];
			fRec25[1] = fRec25[0];
			fRec27[1] = fRec27[0];
			fRec31[1] = fRec31[0];
			fRec33[1] = fRec33[0];
			iRec32[1] = iRec32[0];
>>>>>>> main
			iVec8[1] = iVec8[0];
			fVec7[1] = fVec7[0];
			fRec35[1] = fRec35[0];
			fRec34[1] = fRec34[0];
			fRec30[1] = fRec30[0];
			fRec33[1] = fRec33[0];
			fRec32[1] = fRec32[0];
			fRec31[1] = fRec31[0];
			fRec29[2] = fRec29[1]; fRec29[1] = fRec29[0];
			fRec18[2] = fRec18[1]; fRec18[1] = fRec18[0];
			fRec20[1] = fRec20[0];
			fRec25[1] = fRec25[0];
			fRec28[1] = fRec28[0];
			iRec27[1] = iRec27[0];
			iVec6[1] = iVec6[0];
			iRec19[2] = iRec19[1]; iRec19[1] = iRec19[0];
			fRec24[1] = fRec24[0];
			fRec23[1] = fRec23[0];
<<<<<<< HEAD
			fVec5[1] = fVec5[0];
			iRec21[1] = iRec21[0];
			iRec22[1] = iRec22[0];
=======
			fRec19[1] = fRec19[0];
			fRec22[1] = fRec22[0];
			fRec21[1] = fRec21[0];
			fRec20[1] = fRec20[0];
			fRec17[2] = fRec17[1]; fRec17[1] = fRec17[0];
			iRec18[1] = iRec18[0];
			fRec6[1] = fRec6[0];
			fRec8[1] = fRec8[0];
			fRec13[1] = fRec13[0];
			fRec16[1] = fRec16[0];
			iRec15[1] = iRec15[0];
>>>>>>> main
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
