#include "pch.h"
#include "WaveInstrument.h"

CWaveInstrument::CWaveInstrument(void) {}

void CWaveInstrument::Start() {
	m_waveNode.SetSampleRate(GetSampleRate());
	m_waveNode.Start();
}

bool CWaveInstrument::Generate() {
	m_frame[0] = m_waveNode.Frame(0);
	m_frame[1] = m_frame[0];

	return m_waveNode.Generate();
}
