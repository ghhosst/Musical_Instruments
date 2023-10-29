#pragma once
#include "GetString.h"
#include "readLineFile.h"
#include "convertToFloat.h" 
#include <iostream>
#include <fstream>

class BaseOrchestra {
private:
	char* NameInstrument; 
	char* FullNameOwner;
	int NumUnitsOrchestra;
	float Cost;
	int NumberInstrument;
public:
	BaseOrchestra();
	BaseOrchestra(const char* initStr); 
	BaseOrchestra(const BaseOrchestra& other);
	virtual ~BaseOrchestra();

	char* GetNameInstrument();
	void SetNameInstrument(char* NameInstrument);
	char* GetFullNameOwner();
	void SetFullNameOwner(char* FullNameOwner);
	int GetNumUnitsOrchestra();
	void SetNumUnitsOrchestra(int NumUnitsOrchestra);
	float GetCost();
	void SetCost(float Cost);
	int GetNumberInstrument();
	void SetNumberInstrument(int NumberInstrument);

	virtual void ShowInstrument() = 0;
	virtual void Change() = 0;
	virtual void SaveToFile(std::ofstream& outputFile) = 0; 
	virtual void SaveSpecial(std::ofstream& fout) = 0;
	virtual void LoadFile(std::ifstream& fin) = 0; 
}; 