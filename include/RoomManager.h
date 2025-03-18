//
// Created by Hoopa on 2/27/2025.
//

#ifndef ROOMMANAGER_H
#define ROOMMANAGER_H

#include "BandRoom.h"
#include <ranges>
#include <optional>
#include <bits/ranges_algo.h>

class RoomManager {
    std::map<std::string,std::shared_ptr<Room>> m_Rooms;
    /*
    *  Private constructors for singleton pattern
    */
    RoomManager();
    ~RoomManager();

    public:

    /*
     * This function counts the amount of Room of type RoomType are in the rooms. For example, if
     * the user added 3 recording rooms, then 3 will be returned for countRoomsOfType<RecordingRoom>()
     */
    template <typename RoomType>
    int countRoomsOfType(std::optional<int> capacity = std::nullopt) const {

        static_assert(std::is_base_of_v<Room, RoomType>, "RoomType must be derived from Room");

        return std::ranges::count_if(std::views::values(this->m_Rooms),
            [&](const auto& room) {
                if (auto* matchedRoom = dynamic_cast<RoomType*>(room.get())) {
                    // If capacity is provided, check it, otherwise count all rooms of the given type
                    return !capacity || matchedRoom->getMaxCapacity() == *capacity;
                }
                return false;
            });
    }
    /*
     * This function will add a list of rooms (they are passed as pointers) by calling the addRoom function
     */
    template <typename... RoomPtrs>
        void addRooms(RoomManager& manager, RoomPtrs&&... rooms) {
        (manager.addRoom(rooms), ...);
    }

    /*
     *  This function will return the first desired room and also check the max capacity.
     *
     */
    template <typename RoomType>
    RoomType* getRoom(std::optional<int> capacity = std::nullopt) {
        static_assert(std::is_base_of_v<Room, RoomType>, "T must be derived from Room");

        for (auto& room : std::views::values(this->m_Rooms)) {
            if (auto* matchedRoom = dynamic_cast<RoomType*>(room.get())) {
                // If no capacity filter is provided, return the first found room.
                if (!capacity || matchedRoom->getMaxCapacity() == *capacity) {
                    return matchedRoom;
                }
            }
        }
        return nullptr;
    }

    template <typename RoomType>
    std::vector<RoomType*> getAllRooms(std::optional<int> capacity = std::nullopt) {
        static_assert(std::is_base_of_v<Room, RoomType>, "T must be derived from Room");
        std::vector<RoomType*> rooms;
        for (auto& room : std::views::values(this->m_Rooms)) {
            if (auto* matchedRoom = dynamic_cast<RoomType*>(room.get())) {
                // If no capacity filter is provided, return the first found room.
                if (!capacity || matchedRoom->getMaxCapacity() == *capacity) {
                    rooms.push_back(matchedRoom);
                }
            }
        }
        return rooms;
    }
    /*
     * A room is insert into the map where the key is the ID of the room. Usage is
     * addRoom<Recording>(2) - This specifies to add a recording room of size 2
     */
    template<typename RoomType>
    std::pair<bool,std::string> addRoom(int capacity){
        const auto id = uuid::generate_uuid_v4();

        auto room = std::make_shared<RoomType>(capacity);
        int room_type_count = countRoomsOfType<RoomType>(capacity);

        if (room_type_count >= room->getMaxRoomCount())
            return {false,"Too many rooms"};

        this->m_Rooms[id] = std::make_shared<RoomType>(capacity);
        return std::make_pair(true,id);
    }
    /*
     *  This is an overload of adding a room, in which the room object already exists.
     *  Hence the use of std::move to transfer ownership
     */
    void addRoom(const std::shared_ptr<Room>& room) {
        this->m_Rooms[room->getID()] = std::move(room);
    }
    void removeRoomByID(const std::string &roomID) {
        m_Rooms.erase(roomID);
    }
    std::shared_ptr<Room> getRoomByID(const std::string& roomID) {
        if (!m_Rooms.contains(roomID))
            return nullptr;
        return m_Rooms.at(roomID);
    }
    void clearAllRooms() {
        m_Rooms.clear();
    }
    RoomManager(const RoomManager&) = delete;
    RoomManager& operator=(const RoomManager&) = delete;
    static RoomManager& getInstance();
    void printAllRoomDetails();
};



#endif //ROOMMANAGER_H
