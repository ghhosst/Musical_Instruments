#pragma once
#include "BaseOrchestra.h"

class WindInstrument :
    public BaseOrchestra{
private:
    String NameManufacture;
    String Defects;
public:
    String GetNameManufacture();
    void SetNameManufacture(String NameManufacture);
    String GetDefects();
    void SetDefects(String Defects);
};