#pragma once
#include "AudioEffect.h"
#include<vector>


class CFlange :
    public CAudioEffect
{
public:
    CFlange() {};

    virtual void Process(double* in, double* out);
    virtual void Start();
    virtual bool Generate() { return true; };

private:
    std::vector<double> m_out_l;
    std::vector<double> m_out_r;
};

