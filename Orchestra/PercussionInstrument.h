#pragma once
#include "BaseOrchestra.h"

class PercussionInstrument :
    public BaseOrchestra{
private:
    char* TypePerc;
public:
    PercussionInstrument();
    PercussionInstrument(char file); 
    PercussionInstrument(const PercussionInstrument& other);
    ~PercussionInstrument() override;

    char* GetTypePerc();
    void SetTypePerc(char* TypePerc);

    void ShowInstrument() override;
    void Change() override;
    void SaveToFile(std::ofstream& outputFile) override;  
    void SaveSpecial(std::ofstream& fout) override;
    void LoadFile(std::ifstream& fin) override;
}; 