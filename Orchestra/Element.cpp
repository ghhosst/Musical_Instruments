#include "Element.h"
#include "PercussionInstrument.h"
#include "StringInstrument.h"
#include "WindInstrument.h"
using namespace std;

Element::Element() {
	next = nullptr;
	prev = nullptr;
	instrument = nullptr;
}

Element::Element(int choiceInstrument) {
	
	switch (choiceInstrument) {
	case 1: // PercussionInstrument
		instrument = new PercussionInstrument; 
		break;
	case 2: // StringInstrument
		instrument = new StringInstrument;
		break;
	case 3: // WindInstrument
		instrument = new WindInstrument;
		break;
	default:
		break;
	}
}

Element* Element::GetNext() {
	return this->next;
}

void Element::SetNext(Element* next) {
	this->next = next;
}

Element* Element::GetPrev() {
	return this->prev;
}

void Element::SetPrev(Element* prev) {
	this->prev = prev;
}

BaseOrchestra* Element::GetInstrument() {
	return this->instrument;
}

void Element::SetInstrument(BaseOrchestra* instrument) {
	this->instrument = instrument;
}