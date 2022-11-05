#pragma once
#include "AudioNode.h"
#include "Note.h"

class CInstrument :
    public CAudioNode
{
public:
    CInstrument(double bpm);
    CInstrument();

    virtual void SetNote(CNote* note) = 0;

	double Send(int i) { return m_sends[i]; }
	void SetSend(int i, double value) { m_sends[i] = value; }


protected:
	double m_sends[5];
};

