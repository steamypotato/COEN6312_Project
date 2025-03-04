//
// Created by niko on 3/4/25.
//
#include "TestSetup.h"

TEST(CheckInTest, RoomNotAvailable) {
    clearContext();

    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);

    room_manager.getRoomByID(room_id)->setAvailable(false);
    auto current_time = "10:55";
    auto [check_in_status, msg] = booking_manager.checkInUser(user,receptionist,booking_id,room_id,current_time);
    EXPECT_FALSE(check_in_status) << msg;
}

// If we are trying to check the user into a room that he did NOT book
TEST(CheckInTest, WrongRoomSelected) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    std::string other_room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto current_time = "10:55";
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,receptionist,booking_id,other_room_id,current_time);
    EXPECT_FALSE(check_in_status) << msg;
}
// If the user did not actually book a room before checking in
TEST(CheckInTest, BookingDoesNotExist) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto booking = booking_manager.getBookingForUser(user);
    EXPECT_EQ(booking,nullptr);
}
// If the user checked in too late
TEST(CheckInTest, UserCheckedInTooLate) {
    clearContext();
    auto current_time = "11:15";
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,receptionist,booking_id,room_id,current_time);
    EXPECT_FALSE(check_in_status) << msg;
}


// A correct user checking-in scenario is provided
TEST(CheckInTest, UserCheckedIn) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto current_time = "10:55";
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto [check_in_status, msg] = booking_manager.checkInUser(user,receptionist,booking_id,room_id,current_time);
    EXPECT_TRUE(check_in_status) << msg;
}

// User tried to checked out without checking in
TEST(CheckOutTest, UserCheckedOutWithoutCheckingIn) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto current_time = "13:55";
    auto [check_out_status, msg] = booking_manager.checkOutUser(user,receptionist,booking_id,room_id,current_time);
    EXPECT_FALSE(check_out_status) << msg;
}
// User has checked out with no problems
TEST(CheckOutTest, UserCheckedOut) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto current_time = "10:55";
    auto [check_in_status, msg] = booking_manager.checkInUser(user,receptionist,booking_id,room_id,current_time);
     current_time = "13:55";
    auto [check_out_status, msg_2] = booking_manager.checkOutUser(user,receptionist,booking_id,room_id,current_time);
    EXPECT_TRUE(check_out_status) << msg;
}