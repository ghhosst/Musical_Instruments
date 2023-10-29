#define _CRT_SECURE_NO_WARNINGS  
#include "BaseOrchestra.h"

BaseOrchestra::BaseOrchestra() {
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (без параметров)|----\n";
	system("pause");

	const char* initStr = "\t-"; 

	NameInstrument = new char[sizeof(initStr)];
	strcpy(NameInstrument, initStr); 

	FullNameOwner = new char[sizeof(initStr)];
	strcpy(FullNameOwner, initStr); 

	NumUnitsOrchestra = 0;
	Cost = 0;
	NumberInstrument = 1;
}

BaseOrchestra::BaseOrchestra(const char* initStr) {
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (с параметром)|----\n";
	system("pause");

	NameInstrument = new char[sizeof(initStr)];
	strcpy(NameInstrument, initStr);

	FullNameOwner = new char[sizeof(initStr)];
	strcpy(FullNameOwner, initStr);

	NumUnitsOrchestra = 0;
	Cost = 0;
	NumberInstrument = 1;
} 

BaseOrchestra::BaseOrchestra(const BaseOrchestra& other) {
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (копирования)|----\n";
	system("pause");

	strcpy(this->NameInstrument, other.NameInstrument);
	strcpy(this->FullNameOwner, other.FullNameOwner);
	this->NumUnitsOrchestra = other.NumUnitsOrchestra;
	this->Cost = other.Cost;
	this->NumberInstrument = other.NumberInstrument;
}

BaseOrchestra::~BaseOrchestra() {
	std::cout << "\n----|Вызван виртуальный деструктор класса BaseOrchestra|----\n";
	system("pause");

	Cost = 0;
	NumUnitsOrchestra = 0;
	NumberInstrument = 0;
	delete[] FullNameOwner; 
	FullNameOwner = nullptr;
	delete[] NameInstrument;
	NameInstrument = nullptr;
}; 

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

float BaseOrchestra::GetCost() {
	return this->Cost;
}

void BaseOrchestra::SetCost(float Cost) {
	this->Cost = Cost;
}

int BaseOrchestra::GetNumberInstrument() {
	return NumberInstrument;
}

void BaseOrchestra::SetNumberInstrument(int NumberInstrument) {
	this->NumberInstrument = NumberInstrument;
}