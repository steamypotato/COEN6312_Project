//
// Created by Hoopa on 2/28/2025.
//

#ifndef BANDROOM_H
#define BANDROOM_H

#include "Room.h"
#include "Microphone.h"
#include "ElectricBassAmp.h"
#include "EletricGuitarAmp.h"
#include "Drums.h"

enum BandRoomType {
    THREE_PERSON_ROOM = 3,
    FOUR_PERSON_ROOM = 4,
    SIX_PERSON_ROOM = 6,
    TEN_PERSON_ROOM = 10,
};

class BandRoom : public Room {
public:
    explicit BandRoom(int);
    BandRoom();
    ~BandRoom();

};

#endif //BANDROOM_H
