#include "StringInstrument.h"

String StringInstrument::GetNameManufacture() {
	return this->NameManufacture;
}

void StringInstrument::SetNameManufacture(String NameManufacture) {
	this->NameManufacture = NameManufacture;
}

String StringInstrument::GetTextDescription() {
	return this->TextDescription;
}

void StringInstrument::SetTextDescription(String TextDescription) {
	this->TextDescription = TextDescription;
}