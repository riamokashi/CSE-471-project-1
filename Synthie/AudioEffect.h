#pragma once
#include "Instrument.h"
#include <vector>

class CAudioEffect :
    public CInstrument
{
public:
    CAudioEffect();


    virtual void Process(double* frameIn, double* frameOut) = 0;
    virtual void SetNote(CNote* note);

    void SetWet(double w) { m_wet = w; }
    void SetDry(double d) { m_dry = d; }
    void SetDelay(double d) { m_delay = d; }
    void SetThreshold(double t) { m_thresh = t; }

protected:

    double m_wet;
    double m_dry;
    double m_delay;
    double m_thresh;

    int m_wrloc;
    int m_rdloc;

    std::vector<double> m_queue_l;
    std::vector<double> m_queue_r;

    const int QSIZE = 200000;
    const double RANGE = .5;
    const int RATE = 2;
    const int LEVEL = 2;

    double m_time = 5;


};

