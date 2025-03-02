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
    m_Bookings[id]  = std::make_unique<Booking>(user,start_time, end_time, roomID, size);

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
    if (size <= 0 && size > room->getMaxCapacity()) {
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
    if (size <= 0 && size > room->getMaxCapacity()) {
        return {false,std::format("Invalid size : {}, must 1 - {}",size,room->getMaxCapacity())};
    }
    if (user == nullptr) {
        return {false,"User has not been created"};
    }
    m_Bookings[id].get()->modify(user,start_time, end_time, roomID, size);

    return {true,id};
}


std::string BookingManager::getBookingInformation(const std::string& id) const {
    return m_Bookings.at(id)->getBookingInformation();
}
