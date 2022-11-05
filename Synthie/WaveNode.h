#pragma once
#include "AudioNode.h"
class CWaveNode :
    public CAudioNode
{
public:
    CWaveNode(void);

    virtual void Start();
    virtual bool Generate();

    void SetSamples(short* sample, int num) { m_samples = sample; m_numSamples = num; }

private:
    short* m_samples;
    int m_numSamples;
    int m_pos;
};

