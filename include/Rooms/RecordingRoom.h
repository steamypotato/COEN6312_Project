//
// Created by Hoopa on 2/27/2025.
//

#ifndef RECORDINGROOM_H
#define RECORDINGROOM_H

#include "Room.h"
#include "Microphone.h"

class RecordingRoom : public Room {
    static constexpr int base_hourly_rate = 10;
public:
    explicit RecordingRoom(int);
    ~RecordingRoom() override;
};
#endif //RECORDINGROOM_H
