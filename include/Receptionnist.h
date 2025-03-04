//
// Created by Hoopa on 3/1/2025.
//

#ifndef RECEPTIONIST_H
#define RECEPTIONIST_H
#include <User.h>


class Receptionist : public User{
    public:
    std::pair<bool,std::string> checkInUser();
    std::pair<bool, std::string> checkOutUser();
    std::pair<bool, std::string> processPayment();

    Receptionist(const std::string &, const std::string &,const std::string &);
    ~Receptionist();
};



#endif