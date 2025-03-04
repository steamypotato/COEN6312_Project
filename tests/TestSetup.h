//
// Created by Hoopa on 3/3/2025.
//

#ifndef TESTSETUP_H
#define TESTSETUP_H

#include <Receptionnist.h>
#include <Administrator.h>
#include <PaymentManager.h>

#include <gtest/gtest.h>
#include "BookingManager.h"

static RoomManager& room_manager = RoomManager::getInstance();
static BookingManager& booking_manager = BookingManager::getInstance();
static PaymentManager& payment_manager = PaymentManager::getInstance();


inline std::shared_ptr<User> user;
inline std::shared_ptr<Receptionist> receptionist;
inline std::shared_ptr<Administrator> admin;


static void clearContext() {
    user = std::make_shared<User>("Tim","Henson","TimHenson@gmail.com");
    receptionist = std::make_shared<Receptionist>("John","Mayer","JohnMayer@gmail.com");
    admin = std::make_shared<Administrator>("David","Gilmour","DavidGilmour@gmail.com");

    room_manager.clearAllRooms();
    booking_manager.clearAllBookings();

    bool status = admin->assignRole(user,MUSICIAN);
    status = admin->assignRole(receptionist,RECEPTIONIST);
}

#endif //TESTSETUP_H
