//
// Created by Hoopa on 3/2/2025.
//


#include "BookingManager.h"

BookingManager::BookingManager()= default;
BookingManager::~BookingManager() = default;

BookingManager& BookingManager::getInstance(){
    static BookingManager instance;
    return instance;
}

std::pair<bool,std::string> BookingManager::createBooking(const std::shared_ptr<User> & user,const std::string & start_time,
       const std::string& end_time,const std::string& roomID,int size){


    auto room = roomManager.getRoomByID(roomID);
    if(room==nullptr){
        return {false,std::format("Room {} does not exist",roomID)};
    }

    auto id = uuid::generate_uuid_v4();
    m_Bookings[id]  = std::make_shared<Booking>(user,start_time, end_time, roomID, size);

    /*
     * This regex makes sure strings entered in 24 hour time format are ONLY accepted.
     * Then we check if the requested room can satisfy the size requirements of this booking
     */
    std::regex timeRegex(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    if (!std::regex_match(start_time, timeRegex)) {
        return {false,std::format("Invalid start time : {}",start_time)};
    }
    if (!std::regex_match(end_time, timeRegex)) {
        return {false,std::format("Invalid end time : {}",end_time)};
    }
    if (size <= 0 | size > room->getMaxCapacity()) {
        return {false,std::format("Invalid size : {}, must 1 - {}",size,room->getMaxCapacity())};
    }
    if (user == nullptr) {
        return {false,"User has not been created"};
    }
    return {true,id};
}

std::pair<bool,std::string>  BookingManager::modifyBooking(const std::string& id, const std::shared_ptr<User> & user,
        const std::string & start_time,const std::string& end_time, const std::string& roomID, const int size) {

    const auto room = roomManager.getRoomByID(roomID);
    if(room==nullptr){
        return {false,std::format("Room {} does not exist",roomID)};
    }

    std::regex timeRegex(R"(^(?:[01]\d|2[0-3]):[0-5]\d$)");
    if (!std::regex_match(start_time, timeRegex)) {
        return {false,std::format("Invalid start time : {}",start_time)};
    }
    if (!std::regex_match(end_time, timeRegex)) {
        return {false,std::format("Invalid end time : {}",end_time)};
    }
    if (size <= 0 | size > room->getMaxCapacity()) {
        return {false,std::format("Invalid size : {}, must 1 - {}",size,room->getMaxCapacity())};
    }
    if (user == nullptr) {
        return {false,"User has not been created"};
    }
    m_Bookings[id].get()->modify(user,start_time, end_time, roomID, size);

    return {true,id};
}

std::pair<bool,std::string> BookingManager::cancelBooking(const std::string& bookingID, const std::shared_ptr<User> & user, const std::shared_ptr<User>& receptionist,
    const std::string& current_time) {
    // Does this booking exist?
    if(!m_Bookings.contains(bookingID)) {
        return std::make_pair(false,std::format("Booking {} not found",bookingID));
    }

    const std::shared_ptr<Booking> booking = m_Bookings.at(bookingID);

    // Is the user an actual musician ?
    if (user->getRole() != MUSICIAN) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",user->getName()));
    }
    // Does the receptionist have the correct role to perform this operation?
    if (receptionist->getRole() != RECEPTIONIST) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",receptionist->getName()));
    }
    int time_diff = utils::getEpochFromTimeString(current_time) - utils::getEpochFromTimeString(booking->getStartTime());
    // Less than 12 hours until the booking is non-cancelleable
    if (time_diff < (12 * 60 * 60)) {
        return std::make_pair(false,std::format("Bookings cannot be cancelled less within less than 24 hours "));
    }
    m_Bookings.erase(bookingID);
    return std::make_pair(true,std::format("Cancelled booking {}",bookingID));
}

std::pair<bool,std::string> BookingManager::checkInUser(const std::shared_ptr<User>& user, const std::shared_ptr<User>& receptionist,
    std::string bookingID, std::string roomID, const std::string &current_time) const {

    // Does this booking exist?
    if(!m_Bookings.contains(bookingID)) {
        return std::make_pair(false,std::format("Booking {} not found",bookingID));
    }
    const std::shared_ptr<Booking> booking = m_Bookings.at(bookingID);
    // Does the room exist?
    auto room = roomManager.getRoomByID(roomID);
    if(room == nullptr){
        return std::make_pair(false,std::format("Room {} not found",roomID));
    }
    // Did this user book the room hes trying to check into?
    if (booking->getBookedRoomID() != roomID) {
        return std::make_pair(false,std::format("Wrong check in for {}, has booked room {} but trying to access room {}",
            user->getName(),booking->getBookedRoomID(),roomID));
    }
    // Does the receptionist have the correct role to perform this operation?
    if (receptionist->getRole() != RECEPTIONIST) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",receptionist->getName()));
    }
    // Is the user an actual musician ?
    if (user->getRole() != MUSICIAN) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",user->getName()));
    }

    int arrival_diff = utils::getEpochFromTimeString(current_time) - utils::getEpochFromTimeString(booking->getStartTime());
    if(arrival_diff > 600){ //User is too late! (10 minutes + is late)
        return std::make_pair(false,std::format("User {} is late by {} seconds",bookingID,arrival_diff));
    }
    // What is the room is not available ?
    if(!room->getAvailable()){
        return std::make_pair(false,std::format("Room {} not available",roomID));
    }
    // Mark the room for the booking as unavailable
    room->setAvailable(false);

    // Check the user in
    booking->setCheckIn(true);

    return std::make_pair(true,std::format("{} checked in for room {}",user->getName(),roomID));
}
std::pair<bool,std::string> BookingManager::checkOutUser(const std::shared_ptr<User>& user, const std::shared_ptr<User>& receptionist,
    std::string bookingID, std::string roomID, const std::string &current_time) const {

    // Does this booking exist?
    if(!m_Bookings.contains(bookingID)) {
        return std::make_pair(false,std::format("Booking {} not found",bookingID));
    }
    const std::shared_ptr<Booking> booking = m_Bookings.at(bookingID);

    // If so, lets make sure the user checked in
    if (!booking->getCheckIn()) {
        return std::make_pair(false,std::format("User {} did not check in!",user->getName()));
    }
    // Does the receptionist have the correct role to perform this operation?
    if (receptionist->getRole() != RECEPTIONIST) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",receptionist->getName()));
    }
    // Is the user an actual musician ?
    if (user->getRole() != MUSICIAN) {
        return std::make_pair(false,std::format("User {} does not have the required role for this operation",user->getName()));
    }

    auto room = roomManager.getRoomByID(roomID);
    // Mark the room for the booking as unavailable
    room->setAvailable(true);
    // Check the user out
    booking->setCheckIn(false);

    return std::make_pair(true,std::format("{} checked out for room {}",user->getName(),roomID));
}


std::string BookingManager::getBookingInformation(const std::string& id) const {
    return m_Bookings.at(id)->getBookingInformation();
}
