// PluginSimpleFlanger.cpp
// giy (giy@site.com)

#include "SC_PlugIn.hpp"
#include "SimpleFlanger.hpp"

static InterfaceTable* ft;

namespace SimpleFlanger {

SimpleFlanger::SimpleFlanger() {
    // 초기화
    mDelaysize = sampleRate() * 0.02f; // in sample
    float _rate = in0(1);
    float _delta = (mDelaysize * _rate) / sampleRate(); // in time
    mFwdhop = _delta + 1.0f;
    mRate = _rate;
    mWritepos = 0;
    mReadpos = 0;

    mDelayline = (float*)RTAlloc(mWorld, mDelaysize * sizeof(float));
    memset(mDelayline, 0, mDelaysize * sizeof(float));

    // 이 UGen을 위한 calculation function 지정
    mCalcFunc = make_calc_function<SimpleFlanger, &SimpleFlanger::next>();

    // 1 sample의 계산을 수행
    // 몇 개의 샘들들이 처리될 것인지를 지정, 1 = control-rate, 64 = audio-rate (typically)
    next(1);
}

SimpleFlanger::~SimpleFlanger() {
    RTFree(mWorld, mDelayline);
}

void SimpleFlanger::next(int nSamples) {
    const float* input = in(0); // 0 번 input 데이터들
    float* output = out(0); // 0 번 output 데이터들

    float depth = in0(2); // in0(2) ==> in(2)[0]
    float rate = mRate;
    float fwdhop = mFwdhop;
    float readpos = mReadpos;
    float* delayline = mDelayline;
    int writepos = mWritepos;
    int delaysize = mDelaysize;

    float val, delayed, currate;

    currate = in0(1);

    if (rate != currate) {
        rate = currate;
        fwdhop = ((delaysize * rate * 2) / sampleRate()) + 1.0f;
    }

    for (int i = 0; i < nSamples; ++i) {
        val = input[i]; // input[0] : audiorate - 첫 번째 샘플 값, controlrate - 인풋 값은 하나뿐(input[0])
        delayline[writepos++] = val;
        if (writepos == delaysize) {
            writepos = 0;
        }

        delayed = delayline[(int)readpos];
        readpos += fwdhop;

        while ((int)readpos >= delaysize)
        {
            readpos -= delaysize;
        }
        while ((int)readpos < 0) {
            readpos += delaysize;
        }

        output[i] = val + (delayed * depth);
    }

    // update member variable to use next iteration.
    mRate = rate;
    mFwdhop = fwdhop;
    mWritepos = writepos;
    mReadpos = readpos;
}

} // namespace SimpleFlanger

PluginLoad(SimpleFlangerUGens) {
    // Plugin magic
    ft = inTable;
    registerUnit<SimpleFlanger::SimpleFlanger>(ft, "SimpleFlanger", false);
    // 
}
