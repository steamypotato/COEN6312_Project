//
// Created by Hoopa on 3/1/2025.
//

#include "SmallDrumRoom.h"


SmallDrumRoom::SmallDrumRoom(int capacity) : DrumRoom(capacity,base_hourly_rate) {
    m_Description = "Small Drum Room";
}
SmallDrumRoom::~SmallDrumRoom() = default;
