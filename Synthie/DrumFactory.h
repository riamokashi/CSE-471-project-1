#pragma once
#include "DrumInstrument.h"
#include "audio/DirSoundSource.h"
#include "DrumEnvelope.h"
#include "WaveNode.h"
#include "AR.h"
#include <vector>
class CDrumFactory
{
public:
	CDrumFactory();

	void SetNote(CNote* note);
	void SyntheticDrum();
	bool LoadFile(const char* fn);
	CDrumInstrument* MakeInstrument();
	std::vector<short> GetVector(int pos) { return m_table.at(pos); }

private:
	CDrumEnvelope m_ar;
	CWaveNode m_wn;
	double m_duration;
	double m_time;

	std::vector<short> m_wave;
	std::vector<short> m_vector;
	std::vector<std::vector<short>> m_table;
};

