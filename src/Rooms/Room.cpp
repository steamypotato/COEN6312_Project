//
// Created by Hoopa on 2/27/2025.
//

#include "Room.h"


Room::Room() {
    this->m_ID = uuid::generate_uuid_v4();
}
Room::~Room() = default;



std::string Room::getDetails() {
    std::string details = "Room " + m_ID;
    details.append(" - max size : " + std::to_string(m_MaxCapacity)).append(" people, contains \n");
    for (const auto& [id,instrument] : m_Instruments) {
        details.append(instrument->getInformation());
        details.append("\n");
    }
    return details;
}
std::string Room::getID() {
    return m_ID;
}


