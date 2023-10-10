#pragma once
#include "BaseOrchestra.h"

class PercussionInstrument :
    public BaseOrchestra{
private:
    String TypeInstrument;
public:
    String GetTypeInstrument();
    void SetTypeInstrument(String TypeInstrument);
}; 