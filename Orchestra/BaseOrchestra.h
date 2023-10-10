#pragma once
#include "String.h"

class BaseOrchestra {
private:
	String NameInstrument; 
	String FullNameOwner;
	int NumUnitsOrchestra;
	int Cost;
public:
	String GetNameInstrument();
	void SetNameInstrument(String NameInstrument);
	String GetFullNameOwner();
	void SetFullNameOwner(String FullNameOwner);
	int GetNumUnitsOrchestra();
	void SetNumUnitsOrchestra(int NumUnitsOrchestra);
	int GetCost();
	void SetCost(int Cost);

	virtual void f() = 0;
}; 