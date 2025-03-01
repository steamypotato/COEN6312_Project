//
// Created by Hoopa on 3/1/2025.
//
#include "Equipment.h"

Equipment::Equipment(){
}

Equipment::~Equipment() = default;

std::string Equipment::getInformation() const {
    std::string information;
    information += this->m_name + std::string(" | ") + this->m_description;
    return information;
}