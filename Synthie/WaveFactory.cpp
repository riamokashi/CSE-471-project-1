#include "pch.h"
#include "WaveFactory.h"
#include "audio/DirSoundSource.h"
#include <cmath>

CWaveFactory::CWaveFactory(void) {
	for (double t = 0; t < 2; t += 1. / 44100.) {
		m_wave.push_back(short(3267 * sin(2 * PI * 1000 * t)));
	}
}

CWaveInstrument* CWaveFactory::MakeInstrument() {
	CWaveInstrument* instrument = new CWaveInstrument;

	instrument->GetNode()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}

bool CWaveFactory::LoadFile(const char* fn) {
	m_wave.clear();

	CDirSoundSource file;

	if (!file.Open(fn)) {
		CString msg = L"Failed to open audio file: " + static_cast<CString>(fn);
		AfxMessageBox(msg);
		return false;

	}

	for (int i = 0; i < file.NumSampleFrames(); i++) {
		short frame[2];
		file.ReadFrame(frame);
		m_wave.push_back(frame[0]);

	}
	file.Close();
	return true;
}
