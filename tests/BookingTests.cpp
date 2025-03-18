#include <RecordingRoom.h>

#include "TestSetup.h"

// Room is not available , probably because someone else already booked it for this time
TEST(CreateBookingTest, RoomNotAvailable) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    room_manager.getRoomByID(room_id)->setAvailable(false);
    auto [status,msg] = booking_manager.createBooking(user,"11:00am","14:00",room_id,1);
    EXPECT_EQ(status,false);
}
// Start time was invalid
TEST(CreateBookingTest, InvalidStartTime) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00am","14:00",room_id,1);
    EXPECT_FALSE(status) << msg;
}
// End time was invalid
TEST(CreateBookingTest, InvalidEndTime) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","2:00pm",room_id,1);
    EXPECT_FALSE(status) << msg;
}
// If the user books a room, the retrieved booking for that user should match to what the user booked
TEST(CreateBookingTest, SuccesfulBooking) {
    clearContext();
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [booking_status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    auto booking_for_user = booking_manager.getBookingForUser(user);
    EXPECT_EQ(booking_for_user,booking_manager.getBookingByID(booking_id));
}

TEST(CreateBookingTest, UserNotCreated) {
    clearContext();
    user = nullptr;
    std::string room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,msg] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    EXPECT_FALSE(status) << msg;
}

// Booking size is too big ! In this example, a recording room's max size is 1, but we try with 2 people.
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
// Booking was cancelled too late (less than 12 hours rom the start)
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