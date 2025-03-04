//
// Created by Hoopa on 2/27/2025.
//

#ifndef USER_H
#define USER_H

#include <format>
#include <string>

enum Role {
    NONE,
    MUSICIAN,
    RECEPTIONIST,
    ADMINISTRATOR
};

class User {
    std::string m_firstName;
    std::string m_lastName;
    std::string m_email;
    std::string m_checkInTime;
    bool m_IsCheckedIn;
    Role m_Role = Role::NONE;
public:
    User(const std::string &, const std::string &,
        const std::string &);

    std::string getName() const;
    std::string getEmail() const;
    Role getRole() const;

    void setRole(Role) ;

};



#endif //USER_H
