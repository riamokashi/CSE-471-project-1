#pragma once
#include "WaveInstrument.h"
#include <vector>

class CWaveFactory
{
public:
	CWaveFactory(void);

	CWaveInstrument* MakeInstrument();
	bool LoadFile(const char* fn);

private:
	std::vector<short> m_wave;
};

