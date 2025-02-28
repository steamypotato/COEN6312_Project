#include <iostream>
#include "RecordingRoom.h"
#include "User.h"

int main() {
    // TIP Press <shortcut actionId="RenameElement"/> when your caret is at the
    // <b>lang</b> variable name to see how CLion can help you rename it.
    Room* room = new RecordingRoom();
    room->defineRoomContent();
    room->printDetails();

    User user1("John","Doe","JohnDoe@gmail.com");
    auto* booking = new Booking(std::make_shared<User>(user1),"5:00",1,room->getID());
    booking->printDetails();

    std::cin.get();
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.