//
// Created by Hoopa on 2/27/2025.
//

#ifndef RECORDINGROOM_H
#define RECORDINGROOM_H

#include "Room.h"
#include "Microphone.h"

class RecordingRoom : public Room {
public:
    explicit RecordingRoom(int);
    ~RecordingRoom() override;
};
#endif //RECORDINGROOM_H
