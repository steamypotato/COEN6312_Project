//
// Created by Hoopa on 3/3/2025.
//

#include "TestSetup.h"

// There can only be 3 recording rooms at most
TEST(RoomTests, TooManyRecordingRooms) {
    clearContext();

    auto room_1 = std::make_unique<RecordingRoom>(1);
    auto room_2 = std::make_unique<RecordingRoom>(1);
    auto room_3 = std::make_unique<RecordingRoom>(1);
    auto room_4 = std::make_unique<RecordingRoom>(1);

    room_manager.addRoom(std::move(room_1));
    room_manager.addRoom(std::move(room_2));
    room_manager.addRoom(std::move(room_3));
    room_manager.addRoom(std::move(room_4));

    const auto rooms = room_manager.getAllRooms<RecordingRoom>(1);
    EXPECT_EQ(rooms.size(), 3);
}


