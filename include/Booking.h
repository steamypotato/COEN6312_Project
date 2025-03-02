//
// Created by Hoopa on 2/27/2025.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <vector>

#include "User.h"
#include <regex>
#include <memory>
#include "Room.h"

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

    bool modify(const std::shared_ptr<User> &, const std::string & start_time,const std::string& end_time,
        Room*,int size);

    void setTime(const std::string &,const std::string &);
    void setSize(int size);
    std::string getBookingInformation();
};
#endif //BOOKING_H
