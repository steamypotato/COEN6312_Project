//
// Created by Hoopa on 2/27/2025.
//
#include "Microphone.h"

#include <iostream>

Microphone::Microphone(): Instrument() {
    this->m_id = uuid::generate_uuid_v4();
    this->m_description = "Microphone...";
    this->m_name = "Microphone";
}
Microphone::~Microphone() {
}
