#pragma once
#include "BaseOrchestra.h"

class WindInstrument :
    public BaseOrchestra{
private:
    char* NameManufacture;
    char* Defects;
public:
    WindInstrument();

    char* GetNameManufacture();
    void SetNameManufacture(char* NameManufacture);
    char* GetDefects();
    void SetDefects(char* Defects);

    void Sound();
};