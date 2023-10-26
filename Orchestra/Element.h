#pragma once

#include "BaseOrchestra.h"

class Element {
private:
	Element* next;
	Element* prev;
	BaseOrchestra* instrument;
	int numberElement;
	char TypeInstrument;
public:
	Element();
	Element(int choiceInstrument);
	Element(char TypeInstrument);
	Element(const Element& other);
	~Element();

	Element* GetNext();
	void SetNext(Element* next);
	Element* GetPrev();
	void SetPrev(Element* prev);
	BaseOrchestra* GetInstrument();
	void SetInstrument(BaseOrchestra* instrument);
	int GetNumberElement();
	void SetNumberElement(int numberElement);
	char GetTypeInstrument();
	void SetTypeInstrument(char TypeInstrument);
};