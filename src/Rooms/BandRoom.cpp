//
// Created by Hoopa on 2/28/2025.
//
#include "BandRoom.h"


BandRoom::BandRoom(const int size): Room(size, base_hourly_rate + (additional_per_person_room_cost*size)) {
    switch (size) {
        case THREE_PERSON_BAND_ROOM:
            m_MaxDerivedRoomCount = 1;
            break;
        case FOUR_PERSON_BAND_ROOM:
            m_MaxDerivedRoomCount = 2;
            break;
        case SIX_PERSON_BAND_ROOM:
            m_MaxDerivedRoomCount = 1;
            break;
        case TEN_PERSON_BAND_ROOM:
            m_MaxDerivedRoomCount = 1;
            break;
        default:
            m_MaxDerivedRoomCount = 0;
    }
}

BandRoom::~BandRoom()=default;

