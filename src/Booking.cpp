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
    this->m_IsCheckedIn = false;
}
std::string Booking::getID() const {
    return m_ID;
}
Booking::~Booking() = default;

void Booking::setSize(const int size) {
    this->m_Size = size;
}
void Booking::setTime(const std::string &start_time,const std::string &end_time) {
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
}
std::shared_ptr<User> Booking::getUser() const{
    return m_User;
}
void Booking::modify(const std::shared_ptr<User> & user, const std::string & start_time,const std::string& end_time,
        const std::string& roomID, const int size) {
    this->m_User = user;
    this->m_Size = size;
    this->m_StartTime = start_time;
    this->m_EndTime = end_time;
    this->m_BookedRoom_ID = roomID;
}

std::string Booking::getBookingInformation() const{
    const std::string details = std::format("Room {} has been booked from {} - {} for {} for {} people",
        this->m_BookedRoom_ID, this->m_StartTime,this->m_EndTime, this->m_User->getName(),this->m_Size);
    return details;
}
float Booking::getBookingDurationInHours() const {
    int start_hour, start_minute, end_hour, end_minute;
    char colon; // To parse the ':' in "HH:MM"

    std::istringstream(m_StartTime) >> start_hour >> colon >> start_minute;
    std::istringstream(m_EndTime) >> end_hour >> colon >> end_minute;

    int start_total_minutes = start_hour * 60 + start_minute;
    int end_total_minutes = end_hour * 60 + end_minute;

    return (end_total_minutes - start_total_minutes)/60.0;
}
std::string Booking::getStartTime() const {
    return this->m_StartTime;
}
std::string Booking::getEndTime() const {
    return this->m_EndTime;
}
void Booking::setCheckIn(const bool status) {
    m_IsCheckedIn = status;
}
void Booking::setCheckInTime(const std::string& checkInTime) {
    m_checkInTime = checkInTime;
}
bool Booking::getCheckIn() const {
    return m_IsCheckedIn;
}
std::string Booking::getBookedRoomID() const {
    return m_BookedRoom_ID;
}

