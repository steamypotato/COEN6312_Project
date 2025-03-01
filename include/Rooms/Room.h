//
// Created by Hoopa on 2/27/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <memory>
#include "Booking.h"
#include "Instrument.h"
#include <vector>

class Room {
public:
    Room(int);
    virtual ~Room();

    virtual std::string getDetails();
    std::string getID();

    template<typename InstrumentType>
    // TODO : Make sure the user does not add too many instruments or something weird like that.
    void addInstrument() {
        static_assert(std::is_base_of_v<Instrument, InstrumentType>, "T must inherit from Instrument");
        this->m_Instruments[uuid::generate_uuid_v4()] = std::make_unique<InstrumentType>();
    }
protected:
    std::string m_ID;
    int m_MaxCapacity{};
    std::string m_Description;
    std::vector<std::shared_ptr<Booking>> m_Bookings;
    std::map<std::string, std::unique_ptr<Instrument>> m_Instruments;
};



#endif //ROOM_H
