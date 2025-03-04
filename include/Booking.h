//
// Created by Hoopa on 2/27/2025.
//

#ifndef BOOKING_H
#define BOOKING_H

#include "User.h"
#include <regex>
#include <memory>

class Booking {
    std::string m_ID;
    std::string m_BookedRoom_ID;
    std::shared_ptr<User> m_User;
    std::string m_StartTime;
    std::string m_EndTime;;
    std::string m_checkInTime;
    int m_Size;
    bool m_IsCheckedIn;

public:
    Booking(const std::shared_ptr<User> &,const std::string & start_time,const std::string& end_time,
        const std::string& roomID,int size);
    ~Booking();


    void modify(const std::shared_ptr<User> &, const std::string & start_time,const std::string& end_time,
        const std::string& roomID,int size);


    void setCheckIn(const bool status);
    void setCheckInTime(const std::string& checkInTime);
    void setTime(const std::string &,const std::string &);
    void setSize(int size);

    float getBookingDurationInHours() const;
    std::string getStartTime() const;
    std::string getEndTime() const;
    std::shared_ptr<User> getUser() const;
    std::string getBookingInformation() const;
    float getBookingCost() const;
    std::string getID() const;
    std::string getBookedRoomID() const;
    bool getCheckIn() const;
};
#endif //BOOKING_H
