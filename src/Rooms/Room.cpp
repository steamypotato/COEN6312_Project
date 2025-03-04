//
// Created by Hoopa on 2/27/2025.
//

#include "Room.h"


Room::Room(const int capacity,const int base_cost) {
    this->m_ID = uuid::generate_uuid_v4();
    m_MaxCapacity = capacity;
    m_BaseCost = base_cost;
    m_Available = true;
}
Room::~Room() = default;

int Room::getHourlyRate() const {
    return m_BaseCost;
}
std::string Room::getID() const {
    return m_ID;
}
bool Room::getAvailable() const {
    return m_Available;
}
int Room::getMaxRoomCount() const {
    return m_MaxDerivedRoomCount;
}

int Room::getMaxCapacity() const {
    return m_MaxCapacity;
}
void Room::setAvailable(const bool available) {
    m_Available = available;
}
std::string Room::getDetails() {
    std::string details = std::format("Room {} - max size {} people - {}$/hr - Equipment list: \n",
        m_ID,std::to_string(m_MaxCapacity),getHourlyRate());
    for (const auto& [id,equipment] : m_Equipment) {
        details.append(equipment->getInformation());
        details.append("\n");
    }
    return details;
}



