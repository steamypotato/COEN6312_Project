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

enum BandRoomSize {
    THREE_PERSON_BAND_ROOM = 3,
    FOUR_PERSON_BAND_ROOM = 4,
    SIX_PERSON_BAND_ROOM = 6,
    TEN_PERSON_BAND_ROOM = 10,
};

class BandRoom : public Room {

    static constexpr int base_hourly_rate = 20;
    static constexpr int additional_per_person_room_cost = 5;

public:
    explicit BandRoom(int);
    BandRoom();
    ~BandRoom() override;

};

#endif //BANDROOM_H
