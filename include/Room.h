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
#include <stdio.h>
#include <iostream>
class Room {

public:
    Room();
    virtual ~Room();
    void printDetails() const;
    virtual void defineRoomContent() = 0;
    std::string getID();
protected:
    std::string m_ID;
    std::vector<std::shared_ptr<Booking>> m_Bookings;
    std::map<std::string, std::unique_ptr<Instrument>> m_Instruments;
};



#endif //ROOM_H
