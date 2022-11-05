#include "pch.h"
#include "AudioEffect.h"
#include <math.h>

CAudioEffect::CAudioEffect() {
	m_queue_l.resize(QSIZE);
	m_queue_r.resize(QSIZE);
}

void CAudioEffect::SetNote(CNote* note) {
	CComPtr<IXMLDOMNamedNodeMap> attributes;
	note->Node()->get_attributes(&attributes);
	long len; 
	attributes->get_length(&len);

	for (int i = 0; i < len; i++) {
		CComPtr<IXMLDOMNode> a;
		CComBSTR name;
		CComVariant val;

		attributes->get_item(i, &a);
		a->get_nodeName(&name);
		a->get_nodeValue(&val);


		if (name == "wet")
		{
			val.ChangeType(VT_R8);
			SetWet(val.dblVal);
		}
		else if (name == "dry")
		{
			val.ChangeType(VT_R8);
			SetDry(val.dblVal);
		}
		else if (name == "threshold")
		{
			val.ChangeType(VT_R8);
			SetThreshold(val.dblVal);
		}
		else if (name == "delay")
		{
			val.ChangeType(VT_R8);
			SetDelay(val.dblVal);
		}

	}
}