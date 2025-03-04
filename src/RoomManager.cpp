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
void RoomManager::printAllRoomDetails(){
  for(const auto& [id,room] : this->m_Rooms){
      std::cout << room->getDetails() << "\n\n";
  }
}


