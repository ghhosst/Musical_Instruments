#pragma once
#include "BaseOrchestra.h"

class PercussionInstrument :
    public BaseOrchestra{
private:
    char* TypeInstrument;
public:
    PercussionInstrument();
    char* GetTypeInstrument();
    void SetTypeInstrument(char* TypeInstrument);

    void Sound();
}; 