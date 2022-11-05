#pragma once
#include "AudioEffect.h"
class CChorus :
    public CAudioEffect
{
public:
    CChorus() {}

    virtual void Process(double* in, double* out);
    virtual void Start();
    virtual bool Generate() { return true; }
};

