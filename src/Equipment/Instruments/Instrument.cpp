//
// Created by Hoopa on 2/27/2025.
//
#include "Instrument.h"

Instrument::Instrument() {
    this->m_id = uuid::generate_uuid_v4();
}
Instrument::~Instrument() = default;

