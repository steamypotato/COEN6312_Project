//
// Created by Hoopa on 2/27/2025.
//
#include "Booking.h"


Booking::Booking(const std::shared_ptr<User> &user,const std::string & time, int size,
                 const std::string& roomID){
    this->m_User = user;
    this->m_Size = size;
    this->m_BookingTime = time;
    this->m_BookedRoom_ID = roomID;
}
Booking::~Booking() = default;

void Booking::printDetails() {
    const std::string details = std::format("Room {} has been booked at {} for {} for {} people",
        this->m_BookedRoom_ID, this->m_BookingTime,m_User->getName(),this->m_Size);
    std::cout << details << std::endl;
}

