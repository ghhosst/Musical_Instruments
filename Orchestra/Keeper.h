#pragma once

#include "BaseOrchestra.h"
#include "Element.h"

class Keeper {
private:
	Element* root;	// root of the list (the first element)
	Element* rear;	// end of the list (last item)
	Element* index;	// current element
public:
	Keeper();

	Element* GetRoot();
	void SetRoot(Element* root);
	Element* GetRear();
	void SetRear(Element* rear);
	Element* GetIndex();
	void SetIndex(Element* index);

	void Add(int choiceInstrument);
};