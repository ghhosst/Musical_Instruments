#pragma once
#include "BaseOrchestra.h"

class StringInstrument :
    public BaseOrchestra{
private:
    char* NameManufacture;
    char* TextDescription;
public:
    StringInstrument();
    StringInstrument(char* s);
    StringInstrument(const StringInstrument& other);
    ~StringInstrument() override;

    char* GetNameManufacture();
    void SetNameManufacture(char* NameManufacture);
    char* GetTextDescription();
    void SetTextDescription(char* TextDescription);

    void ShowInstrument() override;
    void Change() override;
    void SaveToFile(std::ofstream& outputFile) override;
    void SaveSpecial(std::ofstream& fout) override;
    void LoadFile(std::ifstream& fin) override; 
};