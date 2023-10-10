#include "WindInstrument.h"

String WindInstrument::GetNameManufacture() {
	return this->NameManufacture;
}

void WindInstrument::SetNameManufacture(String NameManufacture) {
	this->NameManufacture = NameManufacture;
}

String WindInstrument::GetDefects() {
	return this->Defects;
}

void WindInstrument::SetDefects(String Defects) {
	this->Defects = Defects;
}