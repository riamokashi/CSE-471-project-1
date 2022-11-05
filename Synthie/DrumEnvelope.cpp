#include "pch.h"
#include "DrumEnvelope.h"

CDrumEnvelope::CDrumEnvelope() {
    m_attack = .01;
    m_release = .4;
    m_duration = 1;
    m_decay = .01;
    m_sustain = .55;

    m_source = NULL;
}

void CDrumEnvelope::Start()
{
    m_time = 0;
}

bool CDrumEnvelope::Generate() {
    double gain = .5;

    if (m_time < m_attack) {
        gain = m_time / m_attack;
    }
    else if (m_time > m_attack && m_time < (m_attack + m_decay)) {
        gain = 2 - ((m_time - m_attack) / m_decay) / 2;
    }
    else if (m_time >= m_duration) {
        m_frame[0] = 0;
        m_frame[1] = 0;
        return false;
    }
    else if (m_time > (m_duration - m_release)) {
        double start = m_duration - m_release;

        gain = (1 - (m_time - start) / (m_duration - start)) / 2;
    }

    if (m_source != NULL) {
        m_frame[0] = m_source->Frame(0) * gain;
        m_frame[1] = m_source->Frame(1) * gain;
    }

    m_time += GetSamplePeriod();
    return true;
}
