#define _CRT_SECURE_NO_WARNINGS  
#include "BaseOrchestra.h"

BaseOrchestra::BaseOrchestra() {
	char* s = nullptr;
	NameInstrument = initString(s);
	FullNameOwner = initString(s);
	NumUnitsOrchestra = 0;
	Cost = 0;
	NumberInstrument = 1;
	delete[] s;
	s = nullptr;
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (без параметров)|----\n"; 
	system("pause");
}

BaseOrchestra::BaseOrchestra(char* s) {
	s = nullptr;
	NameInstrument = initString(s);
	FullNameOwner = initString(s);
	NumUnitsOrchestra = 0;
	Cost = 0;
	NumberInstrument = 1;
	delete[] s;
	s = nullptr;
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (с параметром)|----\n"; 
	system("pause"); 
} 

BaseOrchestra::BaseOrchestra(const BaseOrchestra& other) {
	strcpy(this->NameInstrument, other.NameInstrument);
	strcpy(this->FullNameOwner, other.FullNameOwner);
	this->NumUnitsOrchestra = other.NumUnitsOrchestra;
	this->Cost = other.Cost;
	this->NumberInstrument = other.NumberInstrument;
	std::cout << "\n----|Вызван конструктор класса BaseOrchestra (копирования)|----\n";
	system("pause");
}

BaseOrchestra::~BaseOrchestra() {
	Cost = 0;
	NumUnitsOrchestra = 0;
	NumberInstrument = 0;
	delete[] FullNameOwner; 
	FullNameOwner = nullptr;
	delete[] NameInstrument;
	NameInstrument = nullptr;
	std::cout << "\n----|Вызван виртуальный деструктор класса BaseOrchestra|----\n";
	system("pause");
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