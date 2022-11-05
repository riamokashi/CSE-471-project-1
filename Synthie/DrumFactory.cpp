#include "pch.h"
#include "DrumFactory.h"
#include "Notes.h"

CDrumFactory::CDrumFactory() {
	LoadFile("Bottle.wav");
	LoadFile("Toms.wav");
	LoadFile("BassDrum.wav");
	LoadFile("Cymbals.wav");
	LoadFile("Snare.wav");
	LoadFile("Toms2.wav");

	SyntheticDrum();
}

void CDrumFactory::SyntheticDrum(void) {
	m_wave.clear();

	m_ar.SetAttack(.1);
	m_ar.SetDuration(.01);
	m_ar.SetDecay(.3);
	m_ar.SetSustain(.1);
	m_ar.SetRelease(.01);
	m_ar.Start();

	for (int i = 0; i < (.75 * 44100); i++) {
		m_wave.push_back(short(rand() & 32768));
	}
	m_table.push_back(m_wave);
}

void CDrumFactory::SetNote(CNote* note) {
	m_ar.Start();
	CComPtr<IXMLDOMNamedNodeMap> attr;
	note->Node()->get_attributes(&attr);

	long len; 
	attr->get_length(&len);

	for (int i = 0; i < len; i++) {
		CComPtr<IXMLDOMNode> a;
		CComBSTR name;
		CComVariant v;
		attr->get_item(i, &a);
		a->get_nodeName(&name);
		a->get_nodeValue(&v);

		if (name == "note") {
			m_wave = m_table.at(GetDrumPosition(v.bstrVal));

		}
		else if (name == "pitch") {
			std::vector<short> vec;
			v.ChangeType(VT_I4);
			int x = v.intVal;

			for (unsigned i = 0; i < m_wave.size(); i++) {
				if (x > 3) {
					vec.push_back(m_wave.at(i));
					vec.push_back(m_wave.at(i));
				}
				else {
					if ((i % 2) == 1) {
						vec.push_back(m_wave.at(i));
					}
				}
			}
			m_wave = vec;

		}
		else if (name == "attack") {
			v.ChangeType(VT_R8);
			m_ar.SetAttack(v.dblVal);
		}
		else if (name == "release") {
			v.ChangeType(VT_R8);
			m_ar.SetRelease(v.dblVal);
		}
		else if (name == "decay") {
			v.ChangeType(VT_R8);
			m_ar.SetDecay(v.dblVal);
		}

	}
}

bool CDrumFactory::LoadFile(const char* fn) {
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

	m_table.push_back(m_wave);
	file.Close();
	return true;
}

CDrumInstrument* CDrumFactory::MakeInstrument() {
	CDrumInstrument* instrument = new CDrumInstrument();
	instrument->GetNode()->SetSamples(&m_wave[0], (int)m_wave.size());

	return instrument;
}
