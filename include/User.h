//
// Created by Hoopa on 2/27/2025.
//

#ifndef USER_H
#define USER_H

/*
 * Some magic to make <format> work on non-windows version
 */
#ifndef __cpp_lib_format
  // std::format polyfill using fmtlib
  #include <fmt/core.h>
  namespace std {
      using fmt::format;
  }
#else
#include <format>
#endif

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
public:
    User(const std::string &, const std::string &,
        const std::string &);

    std::string getName() const;
    std::string getEmail() const;
    Role getRole() const;

    void setRole(Role) ;
protected:
    Role m_Role = Role::NONE;
	
};



#endif //USER_H
