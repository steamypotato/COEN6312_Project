//
// Created by Hoopa on 3/1/2025.
//

#ifndef STANDARDDRUMROOM_H
#define STANDARDDRUMROOM_H

#include "DrumRoom.h"

class StandardDrumRoom : public DrumRoom {
    static constexpr int base_hourly_rate = 20;
    public:
      explicit StandardDrumRoom(int);
      ~StandardDrumRoom() override;
};



#endif //STANDARDDRUMROOM_H
