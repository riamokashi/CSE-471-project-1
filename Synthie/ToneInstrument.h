#pragma once
#include "Instrument.h"
#include "SineWave.h"
#include "AR.h"

class CToneInstrument :
    public CInstrument
{
public:
    CToneInstrument(void);
    CToneInstrument(double bpm);

public:
    virtual void Start();
    virtual bool Generate();

    virtual void SetNote(CNote* note);

    void SetFreq(double f) { m_sinewave.SetFreq(f); }
    void SetAmplitude(double a) { m_sinewave.SetAmplitude(a); }
    void SetDuration(double d) { m_duration = d; }

private:
    CAR         m_ar;
    CSineWave m_sinewave;
    double m_duration;
    double m_time;
};

