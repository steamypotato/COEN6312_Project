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

bool Booking::modify(const std::shared_ptr<User> & user, const std::string & start_time,const std::string& end_time,
        Room* room, const int size) {

    std::regex timeRegex(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    if (!std::regex_match(start_time, timeRegex)) {
        return false;
    }
    if (!std::regex_match(end_time, timeRegex)) {
        return false;
    }
    if (size <= 0 && size > room->getMaxCapacity()) {
        return false;
    }
    if (m_User != user) {
        return false;
    }
    this->m_Size = size;
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
    return true;
}

std::string Booking::getBookingInformation() {
    const std::string details = std::format("Room {} has been booked from {} - {} for {} for {} people",
        this->m_BookedRoom_ID, this->m_StartTime,this->m_EndTime, this->m_User->getName(),this->m_Size);
    return details;
}

