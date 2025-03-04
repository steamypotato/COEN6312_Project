//
// Created by Hoopa on 3/3/2025.
//
#include "PaymentManager.h"

PaymentManager::PaymentManager() = default;
PaymentManager::~PaymentManager() = default;

PaymentManager& PaymentManager::getInstance(){
    static PaymentManager instance;
    return instance;
}

float PaymentManager::getPriceForBookedRoom(const std::string& room_id,const std::string& booking_id){
    RoomManager& room_manager = RoomManager::getInstance();
    BookingManager& booking_manager = BookingManager::getInstance();
    auto time_booked = booking_manager.getBookingByID(booking_id)->getBookingDurationInHours();
    float hourly_rate = room_manager.getRoomByID(room_id)->getHourlyRate();

    return hourly_rate * time_booked;
}

std::pair<bool,std::string> PaymentManager::performPayment(const std::shared_ptr<User>& receptionist,
        const std::shared_ptr<User>& user,float price, float funds) {
    if (funds < price) {
        return std::make_pair(false,std::format("Insufficient funds | expected {} got {}",price,funds));
    }
    if (receptionist->getRole() != RECEPTIONIST) {
        return std::make_pair(false,std::format("User {} is not the correct role for this operation",receptionist->getName()));
    }
    if (user->getRole() != MUSICIAN) {
        return std::make_pair(false,std::format("User {} is not the correct role for this operation",receptionist->getName()));
    }


    return std::make_pair(true,"Transaction successful");
}
