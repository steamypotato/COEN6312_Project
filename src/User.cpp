//
// Created by Hoopa on 2/27/2025.
//

#include "User.h"

User::User(const std::string &firstName, const std::string &lastName, const std::string &email)  {
    this->m_email = email;
    this->m_firstName = firstName;
    this->m_lastName = lastName;
    this->m_IsCheckedIn = false;
}

void User::setCheckIn(const bool status) {
    m_IsCheckedIn = status;
}
void User::setCheckInTime(const std::string& checkInTime) {
    m_checkInTime = checkInTime;
}
std::string User::getName() const {
    return m_firstName + " " + m_lastName;
}