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
class RoomManager {
    std::map<std::string,std::unique_ptr<Room>> m_Rooms;

    RoomManager();
    ~RoomManager();

    public:

    template <typename... RoomPtrs>
        void addRooms(RoomManager& manager, RoomPtrs&&... rooms) {
        (manager.addRoom(std::move(rooms)), ...);
    }

    RoomManager(const RoomManager&) = delete;
    RoomManager& operator=(const RoomManager&) = delete;
    static RoomManager& getInstance();
    void addRoom(std::unique_ptr<Room>);
    void printRoomDetails();
};



#endif //ROOMMANAGER_H
