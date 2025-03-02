//
// Created by Hoopa on 2/27/2025.
//
#include "RecordingRoom.h"

RecordingRoom::RecordingRoom(int capacity) : Room(capacity, base_hourly_rate) {
    m_Description = "Basic recording room";
}
RecordingRoom::~RecordingRoom() = default;