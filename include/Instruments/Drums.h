//
// Created by Hoopa on 2/28/2025.
//

#ifndef DRUMS_H
#define DRUMS_H

#include "Instrument.h"

enum DrumType {
    SMALL_DRUMS = 3,
    STANDARD_DRUMS = 5,
};

class Drums : public Instrument {
public:
    Drums();
    ~Drums() override;
};



#endif //DRUMS_H
