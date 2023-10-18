#pragma once
#include "GetString.h"
#include <iostream>

class BaseOrchestra {
private:
	char* NameInstrument; 
	char* FullNameOwner;
	int NumUnitsOrchestra;
	int Cost;
public:
	char* GetNameInstrument();
	void SetNameInstrument(char* NameInstrument);
	char* GetFullNameOwner();
	void SetFullNameOwner(char* FullNameOwner);
	int GetNumUnitsOrchestra();
	void SetNumUnitsOrchestra(int NumUnitsOrchestra);
	int GetCost();
	void SetCost(int Cost);

	virtual void Sound() = 0;
}; 