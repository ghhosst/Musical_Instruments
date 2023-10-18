#include "Keeper.h"

Keeper::Keeper() {
	this->root = nullptr;
	this->rear = nullptr;
	this->index = nullptr;
}

Element* Keeper::GetRoot() {
	return this->root;
}

void Keeper::SetRoot(Element* root) {
	this->root = root;
}

Element* Keeper::GetRear() {
	return this->rear;
}

void Keeper::SetRear(Element* rear) {
	this->rear = rear;
}

Element* Keeper::GetIndex() {
	return this->index;
}

void Keeper::SetIndex(Element* index) {
	this->index = index;
}

void Keeper::Add(int choiceInstrument) {
	Element* element = new Element(choiceInstrument);
	element->SetPrev(rear);
	if (root == nullptr) { // list empty
		root = element;
		index = element;
	}
	if (rear != nullptr)
		rear->SetNext(element);
	rear = element;
}