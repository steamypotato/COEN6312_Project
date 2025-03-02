//
// Created by Hoopa on 2/27/2025.
//

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "SmallDrums.h"
#include "StandardDrums.h"
#include "Piano.h"
#include "ElectricBassAmp.h"
#include "EletricGuitarAmp.h"
#include "Synthesizer.h"

#include "SoundSystem.h"
#include "AdvancedLightingSystem.h"
#include "AdvancedSoundSystem.h"
#include "Stage.h"
#include "RecordingRoom.h"
#include "SmallDrumRoom.h"
#include "StandardDrumRoom.h"
#include "SoloDuoRoom.h"
#include "BandRoom.h"
#include <iostream>

class RoomManager {
    std::map<std::string,std::unique_ptr<Room>> m_Rooms;

    RoomManager();
    ~RoomManager();

    public:

    /*
     * This function will add a list of rooms (they are passed std_unique_ptrs) by calling the addRoom function
     */
    template <typename... RoomPtrs>
        void addRooms(RoomManager& manager, RoomPtrs&&... rooms) {
        (manager.addRoom(std::move(rooms)), ...);
    }

    /*
     *  This function will return the first desired room. Basically, we get the first available room of type RoomType.
     */
    template <typename RoomType>
    RoomType* getRoom() {
        for(const auto& [id,room] : this->m_Rooms){
            if (auto* desiredRoom = dynamic_cast<RoomType*>(room.get())) {
                return desiredRoom;
            }
        }
        return nullptr;
    }

    /*
     *  This function will return the first desired room and also check the max capacity.
     *  This is mainly for the band room, as there can be many instance of a band room that differ only in their sizes
     */
    template <typename RoomType>
    RoomType* getRoom(int capacity) {
        static_assert(std::is_base_of_v<Room, RoomType>, "T must be derived from Room");

        for(const auto& [id,room] : this->m_Rooms){
            if (auto* matchedRoom = dynamic_cast<RoomType*>(room.get());
                matchedRoom && matchedRoom->getMaxCapacity() == capacity) {
                return matchedRoom;
            }
        }
        return nullptr;
    }

    /*
     * A room is insert into the map where the key is the ID of the room
     */
    void addRoom(std::unique_ptr<Room> room){
        const auto id = room->getID();
        this->m_Rooms[id] = std::move(room);
    }

    std::unique_ptr<Room> getRoomByID(const std::string& roomID) {
        return std::move(m_Rooms.at(roomID));
    }
    RoomManager(const RoomManager&) = delete;
    RoomManager& operator=(const RoomManager&) = delete;
    static RoomManager& getInstance();
    void printAllRoomDetails();
};



#endif //ROOMMANAGER_H
