#pragma once

#include "BaseOrchestra.h"

class Keeper {
private:
	BaseOrchestra* root; // root of the list (the first element)
	BaseOrchestra* rear; // end of the list (last item)
	BaseOrchestra* index; // current element
};