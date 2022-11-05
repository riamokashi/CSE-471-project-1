#pragma once
#include "AudioNode.h"
class CDrumEnvelope :
    public CAudioNode
{
public:
    CDrumEnvelope();

    virtual void Start();
    virtual bool Generate();

    void SetTime(double t) { m_time = t; }
    void SetAttack(double a) { m_attack = a; }
    void SetRelease(double r) { m_release = r; }
    void SetDuration(double d) { m_duration = d; }
    void SetDecay(double de) { m_decay = de; }
    void SetSustain(double s) { m_sustain = s; }
    void SetSource(CAudioNode* so) { m_source = so; }

private:
    double m_time;
    double m_attack;
    double m_release;
    double m_duration;
    double m_decay;
    double m_sustain;

    CAudioNode* m_source;

};

