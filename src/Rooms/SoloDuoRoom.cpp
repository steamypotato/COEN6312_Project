//
// Created by Hoopa on 3/1/2025.
//

#include "SoloDuoRoom.h"


SoloDuoRoom::SoloDuoRoom(int capacity) : Room(capacity,base_hourly_rate) {
    m_Description = "Solo or duo room";
    m_MaxDerivedRoomCount = 2;
 }
 SoloDuoRoom::~SoloDuoRoom() = default;