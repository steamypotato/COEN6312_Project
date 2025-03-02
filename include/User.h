//
// Created by Hoopa on 2/27/2025.
//

#ifndef USER_H
#define USER_H

#include <format>
#include <iostream>
#include <string>

class User {
    std::string m_firstName;
    std::string m_lastName;
    std::string m_email;
public:
    User(const std::string &, const std::string &,
        const std::string &);

    [[nodiscard]] std::string getName() const;

};



#endif //USER_H
