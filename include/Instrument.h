//
// Created by Hoopa on 2/27/2025.
//

#ifndef INSTRUMENT_H
#define INSTRUMENT_H
#include <string>
#include "Uuid.h"

class Instrument {

    public:
    Instrument() = default;
    virtual ~Instrument() = default;
    std::string getInformation() const;

    protected:
      std::string m_name;
      std::string m_id;
      std::string m_description;
};
#endif //INSTRUMENT_H
