//
// Created by Hoopa on 2/28/2025.
//

#ifndef DRUMS_H
#define DRUMS_H

#include "Instrument.h"

class Drums : public Instrument {
public:
    Drums();
    ~Drums();
protected:
    int m_SnareDrumCount;
    int m_BassDrumCount;
    int m_TomDrumCount;
    int m_SymbalsCount;
};



#endif //DRUMS_H
