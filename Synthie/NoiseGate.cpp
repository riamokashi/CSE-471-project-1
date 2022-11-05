#include "pch.h"
#include "NoiseGate.h"

void CNoiseGate::Start() {
	m_wrloc = 0;
	m_rdloc = 0;
	m_gate_r = 1;
	m_gate_l = 1;
}

void CNoiseGate::Process(double *in, double *out) {
	if (in[0] < m_thresh && in[0] > -m_thresh) {
		m_gate_l -= .005;
		if (m_gate_l < 0) {
			m_gate_l = 0;
		}
	}
	else {
		m_gate_l += .005;
		if (m_gate_l > 1) {
			m_gate_l = 1;
		}
	}

	if (in[0] < m_thresh && in[1] > -m_thresh) {
		m_gate_r -= .005;
		if (m_gate_r < 0) {
			m_gate_r = 0;
		}
	}
	else {
		m_gate_r += .005;
		if (m_gate_r > 1) {
			m_gate_r = 1;
		}
	}

	out[1] = m_dry * in[1] + (m_wet * in[1] * m_gate_r);
}

