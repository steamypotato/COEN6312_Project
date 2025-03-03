//
// Created by Hoopa on 3/1/2025.
//

#ifndef SOLODUOROOM_H
#define SOLODUOROOM_H

#include "Room.h"

class SoloDuoRoom : public Room{
    static constexpr int base_hourly_rate = 20;
  public:
    explicit SoloDuoRoom(int);
    ~SoloDuoRoom() override;
};



#endif //SOLODUOROOM_H
