#pragma once
#include "BaseOrchestra.h"

class StringInstrument :
    public BaseOrchestra{
private:
    char* NameManufacture;
    char* TextDescription;
public:
    StringInstrument();

    char* GetNameManufacture();
    void SetNameManufacture(char* NameManufacture);
    char* GetTextDescription();
    void SetTextDescription(char* TextDescription);

    void Sound();
};