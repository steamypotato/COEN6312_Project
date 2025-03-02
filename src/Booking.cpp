//
// Created by Hoopa on 2/27/2025.
//
#include "Booking.h"


Booking::Booking(const std::shared_ptr<User> &user,const std::string & start_time, const std::string & end_time,
                 const std::string& roomID, const int size){
    this->m_User = user;
    this->m_Size = size;
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
    this->m_BookedRoom_ID = roomID;

}
Booking::~Booking() = default;

void Booking::setSize(const int size) {
    this->m_Size = size;
}
void Booking::setTime(const std::string &start_time,const std::string &end_time) {
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
}

void Booking::modify(const std::shared_ptr<User> & user, const std::string & start_time,const std::string& end_time,
        const std::string& roomID, const int size) {
    this->m_User = user;
    this->m_Size = size;
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
    this->m_BookedRoom_ID = roomID;
}

std::string Booking::getBookingInformation() {
    const std::string details = std::format("Room {} has been booked from {} - {} for {} for {} people",
        this->m_BookedRoom_ID, this->m_StartTime,this->m_EndTime, this->m_User->getName(),this->m_Size);
    return details;
}

