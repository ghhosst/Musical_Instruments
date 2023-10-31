#pragma once

#include "BaseOrchestra.h"
#include "Element.h"
#include <fstream>

class Keeper {
private:
	Element* root;	// root of the list (the first element)
	Element* rear;	// end of the list (last item)
	Element* index;	// current element
public:
	Keeper();
	Keeper(Element* root, Element* rear, Element* index);
	Keeper(const Keeper& other);
	~Keeper();

	Element* GetRoot();
	void SetRoot(Element* root);
	Element* GetRear();
	void SetRear(Element* rear);
	Element* GetIndex();
	void SetIndex(Element* index);

	Keeper& operator ++ ();  
	void ShowOrchestra();
	Keeper& operator -- ();
	void ÑhangeInstrument();
	void Save();
	void Load();
};