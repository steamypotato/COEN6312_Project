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
    std::unordered_map<std::string, std::shared_ptr<Booking>> m_Bookings;
    RoomManager& roomManager = RoomManager::getInstance();

    BookingManager();
    ~BookingManager();

    public:

    std::pair<bool,std::string> createBooking(const std::shared_ptr<User> & user,const std::string & start_time, const std::string& end_time,const std::string& roomID,int size);

    std::pair<bool,std::string> modifyBooking(const std::string& id, const std::shared_ptr<User> & user,
      const std::string & start_time,const std::string& end_time, const std::string& roomID, const int size);

    std::pair<bool,std::string> checkInUser(const std::shared_ptr<User>& user, std::string bookingID, std::string roomID, std::string current_time);

    /*
        This function will go through the map and find the booking associated with the user
        This basically simulates check in, where a user gives his name to the receptionnist, and the booking is found
     */
    std::shared_ptr<Booking> getBookingForUser(const std::shared_ptr<User> & user){
      auto it = std::find_if(m_Bookings.begin(),m_Bookings.end(),[&](const std::pair<std::string,std::shared_ptr<Booking>> & booking){
        return (booking.second.get()->getUser() == user);
      });
      return (it != m_Bookings.end()) ? it->second : nullptr;
    }
    void removeBookingByID(const std::string& id){
      m_Bookings.erase(id);
    }

    std::shared_ptr<Booking> getBookingByID(const std::string& id) {
      if (!m_Bookings.contains(id))
        return nullptr;
      return m_Bookings.at(id);
    }
    std::string getBookingInformation(const std::string& id) const;
    void clearAllBookings() {
      m_Bookings.clear();
    }
    BookingManager(const BookingManager&) = delete;
    BookingManager& operator=(const BookingManager&) = delete;
    static BookingManager& getInstance();
};
#endif //BOOKINGMANAGER_H
