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

    template<typename EquipmentType>
    // TODO : Make sure the user does not add too many instruments or something weird like that.
    void addEquipment() {
        static_assert(std::is_base_of_v<Equipment, EquipmentType>, "T must inherit from Equipment");
        this->m_Equipment[uuid::generate_uuid_v4()] = std::make_unique<EquipmentType>();
    }
protected:
    std::string m_ID;
    int m_MaxCapacity{};
    std::string m_Description;
    std::vector<std::shared_ptr<Booking>> m_Bookings;
    std::map<std::string, std::unique_ptr<Equipment>> m_Equipment;
};



#endif //ROOM_H
