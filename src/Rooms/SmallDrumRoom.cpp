//
// Created by Hoopa on 3/1/2025.
//

#include "SmallDrumRoom.h"


SmallDrumRoom::SmallDrumRoom(int capacity) : DrumRoom(capacity,base_hourly_rate) {
    m_Description = "Small Drum Room";
    m_MaxDerivedRoomCount = 2;
}
SmallDrumRoom::~SmallDrumRoom() = default;
