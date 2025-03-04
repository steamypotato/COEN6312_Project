#include <iostream>
#include "User.h"
#include "RoomManager.h"
#include "BookingManager.h"
/*
 *  The first argument is the room type (band room, drum room, etc...) and then its a variable number of instruments
 *  that will be created for that room
 */
template <typename RoomType,typename... Equipment>
std::shared_ptr<RoomType> makeRoom(int max_size) {
    auto room = std::make_shared<RoomType>(max_size);
    (room->template addEquipment<Equipment>(), ...);
    return room;
}

void createRooms() {
    RoomManager& roomManager = RoomManager::getInstance();

    //room_manager.addRoom<RecordingRoom>(1);
    // Create all rooms, we provide each room with the maximum number of people that can occupy it.
    roomManager.addRooms(
        roomManager,
        // .....................Recording Rooms................................//
        makeRoom<RecordingRoom,BasicSoundSystem,Microphone,SmallDrums>(1),
        makeRoom<RecordingRoom,BasicSoundSystem,Microphone,SmallDrums>(1),
        makeRoom<RecordingRoom,BasicSoundSystem,Microphone,SmallDrums>(1),
        // ..................... Drum Rooms ...................................//
        makeRoom<SmallDrumRoom,BasicSoundSystem,SmallDrums>(1),
        makeRoom<SmallDrumRoom,BasicSoundSystem,SmallDrums>(1),
        makeRoom<StandardDrumRoom,BasicSoundSystem,StandardDrums>(2),

        // .....................Solo/Duo Rooms.................................//
        makeRoom<SoloDuoRoom,BasicSoundSystem,ElectricGuitarAmp,SmallDrums>(2),
        makeRoom<SoloDuoRoom,BasicSoundSystem,ElectricBassAmp,SmallDrums>(2),

        // .....................Band Rooms ....................................//
        // 3 person room has a microphone, guitar and bass amp, small drums and a piano
        makeRoom<BandRoom,BasicSoundSystem,Microphone,ElectricGuitarAmp,ElectricBassAmp,SmallDrums,Piano>(3),
        // 4 person room has 2 microphones, 2 guitar amps and 1 bass amp, standard drums and a piano
        makeRoom<BandRoom,BasicSoundSystem,Microphone,Microphone,ElectricGuitarAmp,ElectricGuitarAmp,ElectricBassAmp,
            StandardDrums,Piano>(4),
        makeRoom<BandRoom,BasicSoundSystem,Microphone,Microphone,ElectricGuitarAmp,ElectricGuitarAmp,ElectricBassAmp,
            StandardDrums,Piano>(4),
        // 6 person room has a lighting system, 2 microphones, 2 guitar and 2 bass amps, standard drums, a synth and a piano
        makeRoom<BandRoom,BasicSoundSystem,BasicLightingSystem,Microphone,Microphone,ElectricGuitarAmp,ElectricGuitarAmp,
        ElectricBassAmp,ElectricBassAmp,StandardDrums,Synthesizer,Piano>(6),
        // 10 person room has a advanced sound and lighting system, a stage, 2 microphones, 2 guitar amps, 2 bass amps, 2 drums kit, 2 synths and a piano
        makeRoom<BandRoom,AdvancedSoundSystem,AdvancedLightingSystem,Stage,Microphone,Microphone,ElectricGuitarAmp,ElectricGuitarAmp,
        ElectricBassAmp,ElectricBassAmp,StandardDrums,StandardDrums,Synthesizer,Synthesizer,Piano>(10)
    );

}

void userBookingExample() {
    RoomManager& roomManager = RoomManager::getInstance();
    BookingManager& bookingManager = BookingManager::getInstance();

    auto user = std::make_shared<User>("John","Doe","JohnDoe@gmail.com");

    // Get the first recording room
    auto room = roomManager.getRoom<RecordingRoom>();

    if (room->getAvailable())
    {
        auto [status,id] = bookingManager.createBooking(user,"16:00","18:00",room->getID(),1);

        std::cout << bookingManager.getBookingInformation(id) << std::endl;

        bookingManager.modifyBooking(id,user,"12:00","14:00",room->getID(),1);
        std::cout << bookingManager.getBookingInformation(id)  << std::endl;
    }
    else {
        std::cout << "Room not available\n";
    }

}
int main() {

    createRooms();

    //userBookingExample();


    RoomManager::getInstance().printAllRoomDetails();


    std::cin.get();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.