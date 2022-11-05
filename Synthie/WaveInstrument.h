#pragma once
#include "Instrument.h"
#include "WaveNode.h"

class CWaveInstrument :
    public CInstrument
{
public:
    CWaveInstrument(void);

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note) {}

    CWaveNode* GetNode() { return &m_waveNode; }

private:
    CWaveNode m_waveNode;
};

