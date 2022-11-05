#pragma once
#include "AudioNode.h"

class CAR :
	public CAudioNode
{
public:
	CAR();

public:
	void SetSource(CAudioNode* source);

	//! Start audio generation
	virtual void Start();

	//! Generate one frame of audio
	virtual bool Generate();

	void SetSource(CAudioNode* const& source) { m_source = source; }

	void SetDuration(double d) { m_duration = d; }

private:
	double m_attack;
	double m_release;
	double m_duration;
	double m_time;
	CAudioNode* m_source;
};

