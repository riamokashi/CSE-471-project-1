#pragma once
#include "AudioEffect.h"
class CNoiseGate :
    public CAudioEffect
{
public:
    CNoiseGate() {};

    virtual void Process(double* in, double* out);
    virtual void Start();
    virtual bool Generate() { return true; }

private:
    double m_gate_l;
    double m_gate_r;

};

