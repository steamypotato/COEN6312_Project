//
// Created by Hoopa on 2/27/2025.
//

#include "Room.h"

#include <iostream>
Room::Room() {
    this->m_ID = uuid::generate_uuid_v4();
}

Room::~Room() {
    std::cout << "Room destructor" << std::endl;
}
void Room::printDetails() const {
    std::cout << "This room contains \n";
    for (const auto& i : m_Instruments) {
        std::cout << i.second->getInformation() << std::endl;
    }
}
std::string Room::getID() {
    return m_ID;
}


