#pragma once
#include "BaseOrchestra.h"

class WindInstrument :
    public BaseOrchestra{
private:
    char* NameManufacture;
    char* Defects;
public:
    WindInstrument();
    WindInstrument(char file);  
    WindInstrument(const WindInstrument& other);
    ~WindInstrument() override;

    char* GetNameManufacture();
    void SetNameManufacture(char* NameManufacture);
    char* GetDefects();
    void SetDefects(char* Defects);

    void ShowInstrument() override;
    void Change() override;
    void SaveToFile(std::ofstream& outputFile) override;
    void SaveSpecial(std::ofstream& fout) override; 
    void LoadFile(std::ifstream& fin) override; 
};