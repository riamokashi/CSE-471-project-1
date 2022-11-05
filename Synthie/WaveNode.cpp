#include "pch.h"
#include "WaveNode.h"

CWaveNode::CWaveNode(void) {
	m_samples = NULL;
	m_numSamples = 0;
}

void CWaveNode::Start() {
	m_pos = 0;
}

bool CWaveNode::Generate() {
	if (m_pos < m_numSamples) {
		m_frame[0] = m_samples[m_pos++] / static_cast<double>(32768);
		m_frame[1] = m_frame[0];
		return true;
	}
	else {
		m_frame[0] = 0;
		m_frame[1] = 0;
		return false;
	}
}