//
// Created by Hoopa on 2/27/2025.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <iomanip>
#include <vector>

#include "User.h"
#include <regex>
#include <memory>

class Booking {
    std::string m_ID;
    std::string m_BookedRoom_ID;
    std::shared_ptr<User> m_User;
    std::string m_StartTime;
    std::string m_EndTime;
    int m_Size;

public:
    Booking(const std::shared_ptr<User> &,const std::string & start_time,const std::string& end_time,
        const std::string& roomID,int size);
    ~Booking();
    std::string getID() const;

    void modify(const std::shared_ptr<User> &, const std::string & start_time,const std::string& end_time,
        const std::string& roomID,int size);

    float getBookingDurationInHours() const {
        int start_hour, start_minute, end_hour, end_minute;
        char colon; // To parse the ':' in "HH:MM"

        std::istringstream(m_StartTime) >> start_hour >> colon >> start_minute;
        std::istringstream(m_EndTime) >> end_hour >> colon >> end_minute;

        int start_total_minutes = start_hour * 60 + start_minute;
        int end_total_minutes = end_hour * 60 + end_minute;

        return (end_total_minutes - start_total_minutes)/60.0;
    }


    void setTime(const std::string &,const std::string &);
    void setSize(int size);
    std::string getStartTime() const;
    std::string getEndTime() const;

    std::shared_ptr<User> getUser() const;
    std::string getBookingInformation() const;
};
#endif //BOOKING_H
