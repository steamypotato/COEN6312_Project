//
// Created by Hoopa on 3/1/2025.
//

#include "StandardDrumRoom.h"

StandardDrumRoom::StandardDrumRoom(int capacity) : DrumRoom(capacity,base_hourly_rate) {
  m_Description = "Standard Drum Room";
}

StandardDrumRoom::~StandardDrumRoom() = default;