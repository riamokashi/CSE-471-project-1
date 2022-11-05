#pragma once
#include "Instrument.h"
#include "WaveNode.h"
#include "AR.h"
#include "DrumEnvelope.h"
class CDrumInstrument :
    public CInstrument
{
public:
    CDrumInstrument();

    virtual void Start();
    virtual bool Generate();
    virtual void SetNote(CNote* note) {};

    void SetDuration(double d) { m_duration = d; }

    CWaveNode* GetNode() { return &m_waveNode; }

    std::wstring GetInstrument() const { return L"Drum"; }

    void SetFrame(double frame[2]);

private:
    CAR m_ar;
    double m_time;
    double m_duration;
    CWaveNode m_waveNode;
    CDrumEnvelope m_drumEnvelope;

};

