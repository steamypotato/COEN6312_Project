#include <iostream>
#include "RecordingRoom.h"
#include "User.h"
#include "RoomManager.h"

template <typename RoomType,typename... Instruments>
std::unique_ptr<RoomType> makeRoom(int max_size) {
    auto room = std::make_unique<RoomType>(max_size);
    (room->template addInstrument<Instruments>(), ...);
    return room;
}


int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    //auto recording_room = std::make_unique<RecordingRoom>();


    RoomManager& roomManager = RoomManager::getInstance();



    roomManager.addRooms(
        roomManager,
        // .....................Recording Rooms................................//
        makeRoom<RecordingRoom,Microphone>(1),
        // ..................... Drum Rooms ...................................//
        // .....................Solo/Duo Rooms.................................//
        // .....................Band Rooms ....................................//
        makeRoom<BandRoom,Microphone,EletricGuitarAmp,ElectricBassAmp>(3),
        makeRoom<BandRoom,Microphone,EletricGuitarAmp,ElectricBassAmp>(4),
        makeRoom<BandRoom,Microphone,EletricGuitarAmp,ElectricBassAmp>(4),
        makeRoom<BandRoom,Microphone,EletricGuitarAmp,ElectricBassAmp>(6),
        makeRoom<BandRoom,Microphone,EletricGuitarAmp,ElectricBassAmp>(10)
    );

    roomManager.printRoomDetails();


    std::cin.get();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.