//
// Created by Hoopa on 3/3/2025.
//

#ifndef TESTSETUP_H
#define TESTSETUP_H

#include <gtest/gtest.h>
#include "BookingManager.h"
#include "User.h"

static RoomManager& room_manager = RoomManager::getInstance();
static BookingManager& booking_manager = BookingManager::getInstance();


static void clearContext() {
    room_manager.clearAllRooms();
    booking_manager.clearAllBookings();
}

#endif //TESTSETUP_H
