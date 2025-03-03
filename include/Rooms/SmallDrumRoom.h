//
// Created by Hoopa on 3/1/2025.
//

#ifndef SMALLDRUMROOM_H
#define SMALLDRUMROOM_H

#include "DrumRoom.h"

enum SmallDrumRoomSizes {
    SINGLE_PERSON_SMALL_DRUM_ROOM = 1
};
class SmallDrumRoom : public DrumRoom{
    static constexpr int base_hourly_rate = 15;
public:
    explicit SmallDrumRoom(int);
    ~SmallDrumRoom() override;
};



#endif //SMALLDRUMROOM_H
