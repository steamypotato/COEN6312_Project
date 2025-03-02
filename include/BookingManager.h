//
// Created by Hoopa on 3/2/2025.
//

#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include "Booking.h"
#include "unordered_map"
#include "RoomManager.h"
#include "Uuid.h"

class BookingManager {
    std::unordered_map<std::string, std::unique_ptr<Booking>> m_Bookings;
    RoomManager& roomManager = RoomManager::getInstance();

    BookingManager();
    ~BookingManager();

    public:

    std::pair<bool,std::string> createBooking(const std::shared_ptr<User> & user,const std::string & start_time, const std::string& end_time,const std::string& roomID,int size);

    std::pair<bool,std::string> modifyBooking(const std::string& id, const std::shared_ptr<User> & user,
      const std::string & start_time,const std::string& end_time, const std::string& roomID, const int size);

    bool checkInUser(std::string);

    std::string getBookingInformation(const std::string& id) const;

    BookingManager(const BookingManager&) = delete;
    BookingManager& operator=(const BookingManager&) = delete;
    static BookingManager& getInstance();
};
#endif //BOOKINGMANAGER_H
