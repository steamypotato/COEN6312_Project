//
// Created by Hoopa on 2/27/2025.
//

#ifndef ROOM_H
#define ROOM_H

#include <map>
#include <memory>
#include "Instrument.h"
#include <vector>
#include <regex>
#include <ranges>
#include <optional>
#include <bits/ranges_algo.h>
class Room {
public:

    Room(int, int);
    virtual ~Room();

    int getHourlyRate() const;
    int getMaxCapacity() const;
    std::string getID() const;
    std::string getDetails();
    bool getAvailable() const;
    int getMaxRoomCount() const;

    void setAvailable(bool available);

    template<typename EquipmentType>
    // TODO : Make sure the user does not add too many instruments or something weird like that.
    void addEquipment() {
        static_assert(std::is_base_of_v<Equipment, EquipmentType>, "T must inherit from Equipment");
        this->m_Equipment[uuid::generate_uuid_v4()] = std::make_shared<EquipmentType>();
    }

    template<typename EquipmentType>
    int getCountOfEquipment() const {
        static_assert(std::is_base_of_v<Equipment, EquipmentType>, "EquipmentType must be derived from Room");

        return std::ranges::count_if(std::views::values(this->m_Equipment),
       [](const auto& equipment) { return dynamic_cast<EquipmentType*>(equipment.get()) != nullptr; });

    }

protected:
    bool m_Available;
    int m_MaxCapacity;
    int m_BaseCost;
    std::string m_ID;;
    std::string m_Description;
    std::map<std::string, std::shared_ptr<Equipment>> m_Equipment;
    int m_MaxDerivedRoomCount = 5;
};



#endif //ROOM_H
