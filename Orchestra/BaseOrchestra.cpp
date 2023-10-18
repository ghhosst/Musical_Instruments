#include "BaseOrchestra.h"

char* BaseOrchestra::GetNameInstrument() {
	return this->NameInstrument;
}

void BaseOrchestra::SetNameInstrument(char* NameInstrument) {
	this->NameInstrument = NameInstrument; 
}

char* BaseOrchestra::GetFullNameOwner() {
	return this->FullNameOwner;
}

void BaseOrchestra::SetFullNameOwner(char* FullNameOwner) {
	this->FullNameOwner = FullNameOwner;
}

int BaseOrchestra::GetNumUnitsOrchestra() {
	return this->NumUnitsOrchestra;
}

void BaseOrchestra::SetNumUnitsOrchestra(int NumUnitsOrchestra) {
	this->NumUnitsOrchestra = NumUnitsOrchestra;
}

int BaseOrchestra::GetCost() {
	return this->Cost;
}

void BaseOrchestra::SetCost(int Cost) {
	this->Cost = Cost;
}