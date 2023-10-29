#include "Element.h"
#include "PercussionInstrument.h"
#include "StringInstrument.h"
#include "WindInstrument.h"

Element::Element() {
	std::cout << "\n----|Вызван конструктор класса Element (без параметров)|----\n";
	system("pause");

	next = nullptr;
	prev = nullptr;
	instrument = nullptr;
	numberElement = 0;
}

Element::Element(int choiceInstrument) {
	std::cout << "\n----|Вызван конструктор класса Element (с параметром choiceInstrument)|----\n";
	system("pause");
	
	switch (choiceInstrument) {
	case 1: // PercussionInstrument
		instrument = new PercussionInstrument; 
		TypeInstrument = 'P';
		break;
	case 2: // StringInstrument
		instrument = new StringInstrument;
		TypeInstrument = 'S';
		break;
	case 3: // WindInstrument
		instrument = new WindInstrument;
		TypeInstrument = 'W';
		break;
	default:
		break;
	}
}

Element::Element(char TypeInstrument) {
	std::cout << "\n----|Вызван конструктор класса Element (с параметром TypeInstrument)|----\n";
	system("pause");

	switch (TypeInstrument) {
	case 'P': // PercussionInstrument
		instrument = new PercussionInstrument('f');
		TypeInstrument = 'P';
		break;
	case 'S': // StringInstrument
		instrument = new StringInstrument('f');
		TypeInstrument = 'S';
		break;
	case 'W': // WindInstrument
		instrument = new WindInstrument('f');
		TypeInstrument = 'W';
		break;
	default:
		break;
	}
}

Element::Element(const Element& other) {
	std::cout << "\n----|Вызван конструктор класса Element (копирования)|----\n";
	system("pause");

	this->numberElement = other.numberElement;
	this->next = new Element;
	this->next = other.next;
	this->prev = new Element;
	this->prev = other.prev;
	this->instrument = other.instrument;
}

Element::~Element() {
	std::cout << "\n----|Вызван деструктор класса Element|----\n";
	system("pause");

	next = nullptr;
	prev = nullptr;
	delete instrument;
	instrument = nullptr;
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

int Element::GetNumberElement() {
	return this->numberElement;
}

void Element::SetNumberElement(int numberElement) {
	this->numberElement = numberElement;
}

char Element::GetTypeInstrument() {
	return TypeInstrument;
}

void Element::SetTypeInstrument(char TypeInstrument) {
	this->TypeInstrument = TypeInstrument; 
}