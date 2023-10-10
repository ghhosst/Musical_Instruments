#pragma once
#include "BaseOrchestra.h"

class StringInstrument :
    public BaseOrchestra{
private:
    String NameManufacture;
    String TextDescription;
public:
    String GetNameManufacture();
    void SetNameManufacture(String NameManufacture);
    String GetTextDescription();
    void SetTextDescription(String TextDescription);
};