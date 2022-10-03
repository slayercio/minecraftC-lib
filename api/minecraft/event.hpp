#pragma once

#ifndef _EVENT_H
#define _EVENT_H

#include "../Std.hpp"

class event_t {
private:
    void* player;

public:
    event_t(void* player) : player(player) {}

    void* getPlayer() {
        return this->player;
    }
};

#endif