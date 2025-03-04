    #include "TestSetup.h"



TEST(CreateBookingTest, InvalidStartTime) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00am","14:00",room_id,1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidEndTime) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","2:00pm",room_id,1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, UserNotCreated) {
    clearContext();
    user = nullptr;
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, InvalidBookingSize) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room_id,2);
    EXPECT_FALSE(status) << msg;
}

TEST(CreateBookingTest, RoomDoesNotExist) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    room_manager.removeRoomByID(room_id);
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    EXPECT_FALSE(status) << msg;
}

// If the user books a room, the retrieved booking for that user should match to what the user booked
TEST(CreateBookingTest, BookingExistsForUser) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto booking_for_user = booking_manager.getBookingForUser(user);
    EXPECT_EQ(booking_for_user,booking_manager.getBookingByID(booking_id));
}

TEST(CancelBookingTest, BookingCancelledTooLate) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    EXPECT_TRUE(booking_status);
    auto booking_for_user = booking_manager.getBookingForUser(user);

    std::string current_time = "9:00";
    auto [cancel_status, msg] = booking_manager.cancelBooking(booking_id,user,receptionist,current_time);
    EXPECT_FALSE(cancel_status);
}



// Main function for GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    clearContext();
    return RUN_ALL_TESTS();
}