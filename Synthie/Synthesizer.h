#pragma once
#include "msxml2.h"
#include <list>
#include <string>
#include <vector>
#include <algorithm>

#include "Instrument.h"
#include "Note.h"
#include "DrumFactory.h"
#include "WaveFactory.h"
#include "Flange.h"
#include "NoiseGate.h"
#include "Chorus.h"

using namespace std;

class CSynthesizer
{
// Construction
public:
    CSynthesizer();

public:

    //! Number of audio channels
    int GetNumChannels() { return m_channels; }

    //! Sample rate in samples per second
    double GetSampleRate() { return m_sampleRate; }

    //! Sample period in seconds (1/samplerate)
    double GetSamplePeriod() { return m_samplePeriod; }

    //! Set the number of channels
    void SetNumChannels(int n) { m_channels = n; }

    //! Set the sample rate
    void SetSampleRate(double s) { m_sampleRate = s;  m_samplePeriod = 1.0 / s; }

    //! Start the synthesizer
    void Start(void);

    //! Generate one audio frame
    bool Generate(double* frame);

    void Clear(void);

    void OpenScore(CString& filename);


    //! Get the time since we started generating audio
    double GetTime() { return m_time; }

    double GetBeatsPerMinute() { return m_bpm; }


private:
    int		m_channels;
    double	m_sampleRate;
    double	m_samplePeriod;
    double  m_time;
    double  m_bpm;                  //!< Beats per minute
    int     m_beatspermeasure;  //!< Beats per measure
    double  m_secperbeat;        //!< Seconds per beat
    int m_currentNote;          //!< The current note we are playing
    int m_measure;              //!< The current measure
    double m_beat;              //!< The current beat within the measure
    void XmlLoadScore(IXMLDOMNode* xml);
    void XmlLoadInstrument(IXMLDOMNode* xml);
    void XmlLoadNote(IXMLDOMNode* xml, std::wstring& instrument);



private:
    std::list<CInstrument*>  m_instruments;
    std::vector<CNote> m_notes;
    CDrumFactory m_drumFactory;
    CWaveFactory m_waveFactory;
    CFlange m_flange;
    CNoiseGate m_noise_gate;
    CChorus m_chorus;
};

#pragma comment(lib, "msxml2.lib")
