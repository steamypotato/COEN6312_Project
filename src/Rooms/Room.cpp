//
// Created by Hoopa on 2/27/2025.
//

#include "Room.h"


Room::Room(const int capacity) {
    this->m_ID = uuid::generate_uuid_v4();
    m_MaxCapacity = capacity;
}
Room::~Room() = default;



std::string Room::getDetails() {
    std::string details = std::format("Room {} - max size {} - equipment list \n",m_ID,std::to_string(m_MaxCapacity));
    for (const auto& [id,equipment] : m_Equipment) {
        details.append(equipment->getInformation());
        details.append("\n");
    }
    return details;
}
std::string Room::getID() {
    return m_ID;
}


