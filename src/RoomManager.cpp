//
// Created by Hoopa on 2/27/2025.
//

#include "RoomManager.h"
RoomManager::RoomManager()= default;
RoomManager::~RoomManager() = default;

RoomManager& RoomManager::getInstance(){
    static RoomManager instance;
    return instance;
}

void RoomManager::addRoom(std::unique_ptr<Room> room){
    const auto id = room->getID();
    this->m_Rooms[id] = std::move(room);
}

void RoomManager::printRoomDetails(){
  for(const auto& [id,room] : this->m_Rooms){
      std::cout << room->getDetails() << "\n\n";
  }
}