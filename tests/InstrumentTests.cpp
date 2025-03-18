//
// Created by niko on 3/4/25.
//

#include <AdvancedLightingSystem.h>
#include <AdvancedSoundSystem.h>
#include <BasicLightingSystem.h>
#include <Piano.h>
#include <RecordingRoom.h>
#include <SmallDrumRoom.h>
#include <SmallDrums.h>
#include <SoloDuoRoom.h>
#include <SoundSystem.h>
#include <Stage.h>
#include <StandardDrumRoom.h>
#include <StandardDrums.h>
#include <Synthesizer.h>

#include "TestSetup.h"


TEST(InstrumentTests,RecordingRomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<RecordingRoom>(1).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<Microphone>();
    room->addEquipment<SmallDrums>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Microphone>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<SmallDrums>(), 1);
}
TEST(InstrumentTests,SmallDrumRoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<SmallDrumRoom>(1).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<SmallDrums>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<SmallDrums>(), 1);
}
TEST(InstrumentTests, BigDrumRoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<StandardDrumRoom>(2).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<StandardDrums>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 2);
}
TEST(InstrumentTests, SoloDuoRoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<SoloDuoRoom>(2).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<StandardDrums>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricGuitarAmp>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricBassAmp>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 1);
}
TEST(InstrumentTests,Band3RoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<BandRoom>(3).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<Microphone>();
    room->addEquipment<Piano>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricGuitarAmp>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricBassAmp>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Microphone>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Piano>(), 1);

}
TEST(InstrumentTests,Band4RoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<BandRoom>(4).second);
    room->addEquipment<BasicSoundSystem>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<Microphone>();
    room->addEquipment<Microphone>();
    room->addEquipment<Piano>();

    EXPECT_EQ(room->getCountOfEquipment<BasicSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricGuitarAmp>(), 2);;
    EXPECT_EQ(room->getCountOfEquipment<ElectricBassAmp>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Microphone>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<Piano>(), 1);
}
TEST(InstrumentTests,Band6RoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<BandRoom>(6).second);
    room->addEquipment<AdvancedSoundSystem>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<Microphone>();
    room->addEquipment<Microphone>();
    room->addEquipment<Piano>();
    room->addEquipment<Synthesizer>();
    room->addEquipment<BasicLightingSystem>();

    EXPECT_EQ(room->getCountOfEquipment<AdvancedSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricGuitarAmp>(), 2);;
    EXPECT_EQ(room->getCountOfEquipment<ElectricBassAmp>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Microphone>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<Piano>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Synthesizer>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<BasicLightingSystem>(), 1);
}
TEST(InstrumentTests,Band10RoomInstrumentsCorrectAmount) {
    clearContext();

    auto room = room_manager.getRoomByID(room_manager.addRoom<BandRoom>(6).second);
    room->addEquipment<AdvancedSoundSystem>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricGuitarAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<ElectricBassAmp>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<StandardDrums>();
    room->addEquipment<Microphone>();
    room->addEquipment<Microphone>();
    room->addEquipment<Piano>();
    room->addEquipment<Synthesizer>();
    room->addEquipment<Synthesizer>();
    room->addEquipment<AdvancedLightingSystem>();
    room->addEquipment<Stage>();

    EXPECT_EQ(room->getCountOfEquipment<AdvancedSoundSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<ElectricGuitarAmp>(), 3);;
    EXPECT_EQ(room->getCountOfEquipment<ElectricBassAmp>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<StandardDrums>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<Microphone>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<Piano>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Synthesizer>(), 2);
    EXPECT_EQ(room->getCountOfEquipment<AdvancedLightingSystem>(), 1);
    EXPECT_EQ(room->getCountOfEquipment<Stage>(), 1);
}