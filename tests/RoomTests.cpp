//
// Created by Hoopa on 3/3/2025.
//

#include <RecordingRoom.h>
#include <SmallDrumRoom.h>
#include <SoloDuoRoom.h>
#include <StandardDrumRoom.h>

#include "TestSetup.h"


TEST(RoomTests, CorrectRecordingRoomCreation) {
    clearContext();

    auto [status,msg] = room_manager.addRoom<RecordingRoom>(1);
    EXPECT_TRUE(status) << msg;
}

TEST(RoomTests, CorrectDrumRoomCreation) {
    clearContext();

    auto [status,msg] = room_manager.addRoom<SmallDrumRoom>(1);
    EXPECT_TRUE(status) << msg;
}

TEST(RoomTests, CorrectSoloDuoRoomCreation) {
    clearContext();

    auto [status,msg] = room_manager.addRoom<SoloDuoRoom>(1);
    EXPECT_TRUE(status) << msg;
}

TEST(RoomTests, CorrectBandRoomCreation) {
    clearContext();

    auto [status,msg] = room_manager.addRoom<BandRoom>(4);
    EXPECT_TRUE(status) << msg;
}




// There can only be 3 recording rooms at most
TEST(RoomTests, TooManyRecordingRooms) {
    clearContext();

    room_manager.addRoom<RecordingRoom>(1);
    room_manager.addRoom<RecordingRoom>(1);
    room_manager.addRoom<RecordingRoom>(1);
    auto [status,msg] = room_manager.addRoom<RecordingRoom>(1);
    EXPECT_FALSE(status) << msg;

    const auto rooms = room_manager.getAllRooms<RecordingRoom>(1);
    EXPECT_EQ(rooms.size(), 3);
}

TEST(RoomTest, TooManyDrumsRooms) {
    clearContext();
    room_manager.addRoom<SmallDrumRoom>(1);
    room_manager.addRoom<SmallDrumRoom>(1);
    room_manager.addRoom<SmallDrumRoom>(1);
    room_manager.addRoom<SmallDrumRoom>(1);

    room_manager.addRoom<StandardDrumRoom>(2);
    room_manager.addRoom<StandardDrumRoom>(2);

    //We can't have more than 2 small drums rooms
    auto rooms = room_manager.getAllRooms<SmallDrumRoom>(1);
    EXPECT_EQ(rooms.size(), 2);
    
    //We can't have more than 1 standard drum room
    auto rooms_2 = room_manager.getAllRooms<StandardDrumRoom>(2);
    EXPECT_EQ(rooms_2.size(), 1);

}
TEST(RoomTest, TooManySoloDuoRooms) {
    clearContext();
    room_manager.addRoom<SoloDuoRoom>(2);
    room_manager.addRoom<SoloDuoRoom>(2);
    room_manager.addRoom<SoloDuoRoom>(2);
    
    //We can't have more than 2 solo/duo rooms
    auto rooms = room_manager.getAllRooms<SoloDuoRoom>(2);
    EXPECT_EQ(rooms.size(), 2);


}

TEST(RoomTests, TooManyBandRooms) {
    clearContext();

    //We can't have more than 1 3 person band room
    room_manager.addRoom<BandRoom>(3);
    room_manager.addRoom<BandRoom>(3);
    EXPECT_EQ(room_manager.getAllRooms<BandRoom>(3).size(), 1);

    //We can't have more than 2 4 person band room
    room_manager.addRoom<BandRoom>(4);
    room_manager.addRoom<BandRoom>(4);
    room_manager.addRoom<BandRoom>(4);
    EXPECT_EQ(room_manager.getAllRooms<BandRoom>(4).size(), 2);


    //We can't have more than 1 6 person band room
    room_manager.addRoom<BandRoom>(6);
    room_manager.addRoom<BandRoom>(6);
    EXPECT_EQ(room_manager.getAllRooms<BandRoom>(6).size(), 1);

    //We can't have more than 1 10 person band room
    room_manager.addRoom<BandRoom>(10);
    room_manager.addRoom<BandRoom>(10);
    EXPECT_EQ(room_manager.getAllRooms<BandRoom>(10).size(), 1);



}


