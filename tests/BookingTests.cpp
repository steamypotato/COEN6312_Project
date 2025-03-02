#include <gtest/gtest.h>
#include "BookingManager.h"
#include "User.h"
RoomManager& room_manager = RoomManager::getInstance();
BookingManager& booking_manager = BookingManager::getInstance();

std::shared_ptr<Room> room = nullptr;
std::shared_ptr<User> user = nullptr;
void createContext() {
    room = std::make_shared<RecordingRoom>(1);
    room_manager.addRoom(room);

    user = std::make_shared<User>("John","Cena","JohnCena@gmail.com");
}

TEST(CreateBookingTest, InvalidStartTime) {
    auto [status,msg] = booking_manager.createBooking(user,"11:00am","14:00",room.get()->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidEndTime) {
    auto [status,msg] = booking_manager.createBooking(user,"11:00","2:00pm",room.get()->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, UserNotCreated) {
    user = nullptr;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidBookingSize) {
    user = nullptr;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),2);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, RoomDoesNotExist) {
    room_manager.removeRoomByID(room.get()->getID());
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    EXPECT_FALSE(status) << msg;
}

// Main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    createContext();
    return RUN_ALL_TESTS();
}