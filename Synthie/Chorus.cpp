#include "pch.h"
#include "Chorus.h"

void CChorus::Start() {
	m_wrloc = 0;
	m_rdloc = 0;
	m_queue_l.resize(QSIZE);
	m_queue_r.resize(QSIZE);
}

void CChorus::Process(double* in, double* out) {

	double delay = (RANGE * m_delay) * sin(2 * PI * RATE);
	double fin_delay = m_delay + delay;

	m_wrloc = (m_wrloc + 1) % QSIZE;
	m_queue_l[m_wrloc] = in[0];
	m_wrloc = (m_wrloc + 1) % QSIZE;
	m_queue_r[m_wrloc] = in[1];

	int delay_len = int((fin_delay * GetSampleRate() + .5)) * 2;
	int rdloc = (m_wrloc + QSIZE - delay_len) % QSIZE;

	out[0] = in[0] / 2 * m_queue_l[rdloc] / 2;
	out[0] += m_wet;
	out[0] += in[0] * m_dry;

	m_wrloc = (m_wrloc + 1) % QSIZE;
	m_queue_r[m_wrloc] = in[1];
	rdloc = (m_wrloc + QSIZE - delay_len) % QSIZE;

	out[1] = in[1] / 2 + m_queue_r[rdloc] / 2;
	out[1] += m_wet;

	out[1] += in[1] * m_dry;
}