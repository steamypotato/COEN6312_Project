//
// Created by Hoopa on 3/1/2025.
//

#include "SmallDrums.h"

SmallDrums::SmallDrums(){
    m_BassDrumCount = 1;
    m_SnareDrumCount = 1;
    m_TomDrumCount = 2;
    m_SymbalsCount = 3;
    m_name = "Small drum kit";
    m_description = std::format("This is small hobbyist drum kit with {} bass drum, {} snare drums, {} tom drums and {} symbals",
                                          m_BassDrumCount, m_SnareDrumCount, m_TomDrumCount,m_SymbalsCount);
}
SmallDrums::~SmallDrums() = default;