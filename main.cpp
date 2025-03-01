#include <iostream>
#include "User.h"
#include "RoomManager.h"

/*
 *  The first argument is the room type (band room, drum room, etc...) and then its a variable number of instruments
 *  that will be created for that room
 */
template <typename RoomType,typename... Instruments>
std::unique_ptr<RoomType> makeRoom(int max_size) {
    auto room = std::make_unique<RoomType>(max_size);
    (room->template addInstrument<Instruments>(), ...);
    return room;
}


int main() {

    RoomManager& roomManager = RoomManager::getInstance();


    // Create all rooms, we provide each room with the maximum number of people that can occupy it.
    roomManager.addRooms(
        roomManager,
        // .....................Recording Rooms................................//
        makeRoom<RecordingRoom,Microphone,SmallDrums>(1),
        // ..................... Drum Rooms ...................................//
        makeRoom<SmallDrumRoom,SmallDrums>(1),
        makeRoom<StandardDrumRoom,StandardDrums>(2),

        // .....................Solo/Duo Rooms.................................//
        // .....................Band Rooms ....................................//
        makeRoom<BandRoom,Microphone,ElectricGuitarAmp,ElectricBassAmp>(3),
        makeRoom<BandRoom,Microphone,ElectricGuitarAmp,ElectricBassAmp>(4),
        makeRoom<BandRoom,Microphone,ElectricGuitarAmp,ElectricBassAmp>(4),
        makeRoom<BandRoom,Microphone,ElectricGuitarAmp,ElectricBassAmp>(6),
        makeRoom<BandRoom,Microphone,ElectricGuitarAmp,ElectricBassAmp>(10)
    );

    roomManager.printRoomDetails();


    std::cin.get();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.