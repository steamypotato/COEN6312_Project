//
// Created by Hoopa on 2/28/2025.
//
#include "BandRoom.h"


BandRoom::BandRoom(const int size): Room(size, base_hourly_rate + (additional_per_person_room_cost*size)) {
}

BandRoom::~BandRoom()=default;

