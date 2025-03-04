//
// Created by Hoopa on 3/1/2025.
//

#include "Administrator.h"

Administrator::Administrator(const std::string & first, const std::string & last, const std::string & email): User(first, last, email) {
    m_Role = ADMINISTRATOR;
}

Administrator::~Administrator() = default;


bool Administrator::assignRole(const std::shared_ptr<User> &user, const Role role) const {
    if (m_Role == ADMINISTRATOR) {
        user->setRole(role);
        return true;
    }
    return false;
}

