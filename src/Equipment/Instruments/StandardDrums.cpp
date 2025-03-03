//
// Created by Hoopa on 3/1/2025.
//

#include "StandardDrums.h"

StandardDrums::StandardDrums(){
    m_SnareDrumCount = 1;
    m_BassDrumCount = 2;
    m_TomDrumCount = 5;
    m_SymbalsCount = 5;

    this->m_name = "Standard drum kit";
    this->m_description = std::format("This is standard all-purpose drum kit with {} bass drum, {} snare drums, {} tom drums and {} symbals",
                                          m_BassDrumCount, m_SnareDrumCount, m_TomDrumCount,m_SymbalsCount);
}
StandardDrums::~StandardDrums()=default;