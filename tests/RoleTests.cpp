//
// Created by Hoopa on 3/3/2025.
//
#include "TestSetup.h"


TEST(RoleTests, WrongRoleTryingToAssignRole) {
    clearContext();
    admin->setRole(MUSICIAN);
    EXPECT_FALSE(admin->assignRole(user,MUSICIAN));
    EXPECT_FALSE(admin->assignRole(receptionist,MUSICIAN));
}

TEST(RoleTests, CorrectRoleAssignment) {
    clearContext();
    admin->setRole(ADMINISTRATOR);
    EXPECT_TRUE(admin->assignRole(user,MUSICIAN));
    EXPECT_TRUE(admin->assignRole(receptionist,MUSICIAN));
}
