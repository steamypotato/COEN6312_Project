//
// Created by Hoopa on 2/27/2025.
//
#include "Instrument.h"

std::string Instrument::getInformation() const {
    std::string information;
    information += "Name: " + m_name + "\n";
    return information;
}
