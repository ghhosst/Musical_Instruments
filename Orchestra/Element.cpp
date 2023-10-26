#include "Element.h"
#include "PercussionInstrument.h"
#include "StringInstrument.h"
#include "WindInstrument.h"
using namespace std;

Element::Element() {
	next = nullptr;
	prev = nullptr;
	instrument = nullptr;
	numberElement = 0;
	std::cout << "\n----|Вызван конструктор класса Element (без параметров)|----\n";
	system("pause");
}

Element::Element(int choiceInstrument) {
	
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
	std::cout << "\n----|Вызван конструктор класса Element (с параметром choiceInstrument)|----\n";
	system("pause");
}

Element::Element(char TypeInstrument) {

	switch (TypeInstrument) {
	case 'P': // PercussionInstrument
		instrument = new PercussionInstrument;
		TypeInstrument = 'P';
		break;
	case 'S': // StringInstrument
		instrument = new StringInstrument;
		TypeInstrument = 'S';
		break;
	case 'W': // WindInstrument
		instrument = new WindInstrument;
		TypeInstrument = 'W';
		break;
	default:
		break;
	}
	std::cout << "\n----|Вызван конструктор класса Element (с параметром TypeInstrument)|----\n";
	system("pause");
}

Element::Element(const Element& other) {
	this->numberElement = other.numberElement;
	this->next = new Element;
	this->next = other.next;
	this->prev = new Element;
	this->prev = other.prev;
	this->instrument = other.instrument;
	std::cout << "\n----|Вызван конструктор класса Element (копирования)|----\n";
	system("pause");
}

Element::~Element() {
	next = nullptr;
	prev = nullptr;
	delete instrument;
	instrument = nullptr;
	std::cout << "\n----|Вызван деструктор класса Element|----\n";
	system("pause");
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