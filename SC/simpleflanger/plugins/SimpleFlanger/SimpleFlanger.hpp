// PluginSimpleFlanger.hpp
// giy (giy@site.com)

#pragma once

#include "SC_PlugIn.hpp"

namespace SimpleFlanger {

class SimpleFlanger : public SCUnit {
public:
    SimpleFlanger();
    // Destructor
    ~SimpleFlanger();

private:
    // Calc function
    void next(int nSamples);

    // Member variables
    float mRate, mDelaysize, mFwdhop, mReadpos;
    int mWritepos;
    float* mDelayline;
};

} // namespace SimpleFlanger
