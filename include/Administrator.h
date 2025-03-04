//
// Created by Hoopa on 3/1/2025.
//

#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <RoomManager.h>

#include "User.h"

class Administrator : public User {
    Role m_Role;
    public:

    bool assignRole(const std::shared_ptr<User> &,Role) const;
    std::pair<bool,std::string> refundUser();
    Administrator(const std::string &, const std::string &,const std::string &);
    ~Administrator();
};



#endif //ADMINISTRATOR_H
