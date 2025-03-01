//
// Created by Hoopa on 2/27/2025.
//

#ifndef BOOKING_H
#define BOOKING_H

#include <vector>

#include "User.h"
#include <memory>
class Booking {
    std::string m_ID;
    std::string m_BookedRoom_ID;
    std::shared_ptr<User> m_User;
    std::string m_BookingTime;
    int m_Size;

public:
    Booking(const std::shared_ptr<User> &,const std::string &, int,const std::string& );
    ~Booking();
    void addBooking();
    void printDetails();
};
#endif //BOOKING_H
