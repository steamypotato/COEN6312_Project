#include "TestSetup.h"

TEST(PaymentTest, PriceCorrectlyCalculated) {
    auto room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto [status,booking_id] = booking_manager.createBooking(user,"11:00","14:00",room_id,1);
    EXPECT_EQ(status,true);

    float hourly_rate = room_manager.getRoomByID(room_id)->getHourlyRate();
    float price = payment_manager.getPriceForBookedRoom(room_id,booking_id);

    EXPECT_EQ(hourly_rate*3,price);
}


TEST(PaymentTests,SuccesfulPayment){
    auto room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto booking_id = booking_manager.createBooking(user,"11:00","14:00",room_id,1).second;

    float price = payment_manager.getPriceForBookedRoom(room_id,booking_id);
    float user_funds = price;

    auto [status, msg] = payment_manager.performPayment(receptionist,user,price, user_funds);
    EXPECT_EQ(status,true) << msg;
}

TEST(PaymentTests,InsufficientFunds) {
    auto room_id = room_manager.addRoom<RecordingRoom>(1).second;
    auto booking_id = booking_manager.createBooking(user,"11:00","14:00",room_id,1).second;

    float price = payment_manager.getPriceForBookedRoom(room_id,booking_id);
    float user_funds = price - 5;

    auto [status, msg] = payment_manager.performPayment(receptionist,user,price, user_funds);
    EXPECT_EQ(status,false) << msg;
}

