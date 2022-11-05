#include "pch.h"
#include "DrumInstrument.h"

CDrumInstrument::CDrumInstrument() {
	m_duration = .1;
}

void CDrumInstrument::Start() {
	m_waveNode.SetBeatsPerMinute(GetSampleRate());
	m_waveNode.Start();

	m_drumEnvelope.SetSource(&m_waveNode);
	m_drumEnvelope.SetSampleRate(44100);
	m_drumEnvelope.Start();
}

bool CDrumInstrument::Generate() {
	m_waveNode.Generate();

	m_frame[0] = m_drumEnvelope.Frame(0);
	m_frame[1] = m_drumEnvelope.Frame(1);

	m_time += GetSamplePeriod();

	return m_drumEnvelope.Generate();
}

void CDrumInstrument::SetFrame(double frame[2]) {
	frame[0] = m_frame[0]; 
	frame[1] = m_frame[1];
}
