#pragma once

#include "BaseOrchestra.h"

class Element {
private:
	Element* next;
	Element* prev;
	BaseOrchestra* instrument;
public:
	Element();
	Element(int choiceInstrument);

	Element* GetNext();
	void SetNext(Element* next);
	Element* GetPrev();
	void SetPrev(Element* prev);
	BaseOrchestra* GetInstrument();
	void SetInstrument(BaseOrchestra* instrument);
};