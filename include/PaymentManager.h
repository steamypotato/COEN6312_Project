//
// Created by Hoopa on 3/3/2025.
//

#ifndef PAYMENTMANAGER_H
#define PAYMENTMANAGER_H

#include "BookingManager.h"
#include "RoomManager.h"
#include "Receptionnist.h"
class PaymentManager {

    PaymentManager();
    ~PaymentManager();

  public:
    float getPriceForBookedRoom(const std::string&,const std::string&);
    PaymentManager(const PaymentManager&) = delete;
    PaymentManager& operator=(const PaymentManager&) = delete;

    std::pair<bool,std::string> performPayment(const std::shared_ptr<User>&,const std::shared_ptr<User>&,float, float);
    std::pair<bool,std::string> performRefund(const std::shared_ptr<User>&,const std::shared_ptr<User>&,float, float);

    static PaymentManager& getInstance();
};

#endif //PAYMENTMANAGER_H
