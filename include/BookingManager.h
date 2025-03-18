//
// Created by Hoopa on 3/2/2025.
//

#ifndef BOOKINGMANAGER_H
#define BOOKINGMANAGER_H

#include "Booking.h"
#include "unordered_map"
#include "RoomManager.h"
#include "Uuid.h"
#include "Receptionnist.h"

class BookingManager {
    std::unordered_map<std::string, std::shared_ptr<Booking>> m_Bookings;
    RoomManager& roomManager = RoomManager::getInstance();

    /*
    *  Private constructors for singleton pattern
    */
    BookingManager();
    ~BookingManager();

    public:

    std::pair<bool,std::string> createBooking(const std::shared_ptr<User> & user,const std::string & start_time, const std::string& end_time,const std::string& roomID,int size);

    std::pair<bool,std::string> modifyBooking(const std::string& id, const std::shared_ptr<User> & user,
      const std::string & start_time,const std::string& end_time, const std::string& roomID, const int size);

    std::pair<bool,std::string> cancelBooking(const std::string& id, const std::shared_ptr<User> & user, const std::shared_ptr<User> & receptionist,
      const std::string& current_time);

    std::pair<bool,std::string> checkInUser(const std::shared_ptr<User>& user, const std::shared_ptr<User>& receptionist,
      const std::string& bookingID, const std::string& roomID, const std::string &current_time) const;

    std::pair<bool,std::string> checkOutUser(const std::shared_ptr<User>& user, const std::shared_ptr<User>& receptionist,
    const std::string& bookingID, const std::string& roomID, const std::string& current_time) const;

    /*
        This function will go through the map and find the booking associated with the user
        This basically simulates check in, where a user gives his name to the receptionnist, and the booking is found
     */
    std::shared_ptr<Booking> getBookingForUser(const std::shared_ptr<User> & user);

    void removeBookingByID(const std::string& id);
    std::shared_ptr<Booking> getBookingByID(const std::string& id) const;

    std::string getBookingInformation(const std::string& id) const;

    void clearAllBookings();

    BookingManager(const BookingManager&) = delete;
    BookingManager& operator=(const BookingManager&) = delete;
    static BookingManager& getInstance();
};
#endif //BOOKINGMANAGER_H
