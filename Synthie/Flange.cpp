#include "pch.h"
#include "Flange.h"

void CFlange::Start() {
	m_wrloc = 0;
	m_rdloc = 0;
	m_out_l.resize(QSIZE);
	m_out_r.resize(QSIZE);
}

void CFlange::Process(double* in, double* out) {
	double delay = (RANGE * m_delay) * sin(2 * PI * RATE);
	double fin_delay = m_delay + delay;

	m_wrloc = (m_wrloc + 1) % QSIZE;
	m_queue_l[m_wrloc] = in[0];

	int delay_length = int((fin_delay * m_sampleRate + .5)) * 2;

	int rdloc = (m_wrloc + QSIZE - delay_length) % QSIZE;

	out[0] = in[0] / 3 + m_queue_l[rdloc] / 3 + (m_out_l[rdloc] * LEVEL) / 3;
	out[0] *= m_wet;

	out[0] = in[0] * m_dry;
	m_out_l[m_wrloc] = out[0];

	m_wrloc = (m_wrloc + 1) % QSIZE;
	m_queue_r[m_wrloc] = in[1];
	rdloc = (m_wrloc + QSIZE - delay_length) % QSIZE;

	out[1] = in[1] / 3 + m_queue_r[(rdloc + 1) % QSIZE] / 3 + (m_out_r[(rdloc + 1) % QSIZE] * LEVEL) / 3;
	out[1] *= m_wet;

	out[1] += in[1] * m_dry;

	m_out_r[m_wrloc] = out[1];
}
