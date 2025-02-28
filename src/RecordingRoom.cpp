//
// Created by Hoopa on 2/27/2025.
//
#include "RecordingRoom.h"


void RecordingRoom::defineRoomContent() {
    this->m_Instruments[uuid::generate_uuid_v4()] = std::make_unique<Microphone>();
}
RecordingRoom::RecordingRoom() {
    std::cout << "RecordingRoom constructor" << std::endl;
}
RecordingRoom::~RecordingRoom() {
    std::cout << "RecordingRoom destructor" << std::endl;
}
