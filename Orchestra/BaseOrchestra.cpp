#include "BaseOrchestra.h"

String BaseOrchestra::GetNameInstrument() {
	return this->NameInstrument;
}

void BaseOrchestra::SetNameInstrument(String NameInstrument) {
	this->NameInstrument = NameInstrument; 
}

String BaseOrchestra::GetFullNameOwner() {
	return this->FullNameOwner;
}

void BaseOrchestra::SetFullNameOwner(String FullNameOwner) {
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