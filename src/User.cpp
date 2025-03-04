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


std::string User::getName() const {
    return m_firstName + " " + m_lastName;
}
std::string User::getEmail() const {
    return m_email;
}

Role User::getRole() const {
    return m_Role;
}
void User::setRole(const Role role) {
    m_Role = role;
}