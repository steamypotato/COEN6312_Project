#include "TestSetup.h"

std::shared_ptr<Room> room = nullptr;
std::shared_ptr<User> user = nullptr;

void setup() {
    room_manager.clearAllRooms();
    booking_manager.clearAllBookings();

    room = std::make_shared<RecordingRoom>(1);
    room_manager.addRoom(room);

    user = std::make_shared<User>("John","Cena","JohnCena@gmail.com");
}

TEST(CreateBookingTest, InvalidStartTime) {
    setup();
    auto [status,msg] = booking_manager.createBooking(user,"11:00am","14:00",room->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidEndTime) {
    setup();
    auto [status,msg] = booking_manager.createBooking(user,"11:00","2:00pm",room->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, UserNotCreated) {
    setup();
    user = nullptr;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room->getID(),1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidBookingSize) {
    setup();
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room->getID(),2);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, RoomDoesNotExist) {
    setup();
    room_manager.removeRoomByID(room.get()->getID());
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room->getID(),1);
    EXPECT_FALSE(status) << msg;
}

// If the user books a room, the retrieved booking for that user should match to what the user booked
TEST(CreateBookingTest, BookingExistsForUser) {
    setup();
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room->getID(),1);
    auto booking_for_user = booking_manager.getBookingForUser(user);
    EXPECT_EQ(booking_for_user,booking_manager.getBookingByID(booking_id));
}

TEST(CheckInTest, RoomNotAvailable) {
    setup();
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    room->setAvailable(false);
    auto current_time = "10:55";
    auto [check_in_status, msg] = booking_manager.checkInUser(user,booking_id,room.get()->getID(),current_time);
    EXPECT_FALSE(check_in_status) << msg;
}

// If we are trying to check the user into a room that he did NOT book
TEST(CheckInTest, WrongRoomSelected) {
    setup();
    auto other_room = std::make_shared<RecordingRoom>(1);
    auto current_time = "10:55";
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,booking_id,other_room->getID(),current_time);
    EXPECT_FALSE(check_in_status) << msg;
}
// If the user did not actually book a room before checking in
TEST(CheckInTest, BookingDoesNotExist) {
    setup();
    auto booking = booking_manager.getBookingForUser(user);
    EXPECT_EQ(booking,nullptr);
}
// If the user checked in too late
TEST(CheckInTest, UserCheckedInTooLate) {
    setup();
    auto current_time = "11:15";
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,booking_id,room->getID(),current_time);
    EXPECT_FALSE(check_in_status) << msg;
}


// A correct user checking-in scenario is provided
TEST(CheckInTest, UserCheckedIn) {
    setup();
    auto current_time = "10:55";
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room.get()->getID(),1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,booking_id,room->getID(),current_time);
    EXPECT_TRUE(check_in_status) << msg;
}


// Main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    setup();
    return RUN_ALL_TESTS();
}