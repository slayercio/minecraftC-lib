#pragma once
#ifndef _MINECRAFT_HPP
#define _MINECRAFT_HPP

#include "../Std.hpp"
#include "atomic_instance.hpp"
#include "event.hpp"

typedef bool(EventHandler)(event_t e);

class Minecraft {
private:
    atomic_instance<std::string> worlds;
    atomic_instance<std::vector<EventHandler*>> registeredHandlers;

public:
    Minecraft(std::string worlds) {
        this->worlds.set(&worlds);
    }

    std::string getWorlds() {
        return *worlds.get();
    }

    void registerEventHandler(EventHandler* handler) {
        std::cout << "Registering event handler: " << handler << std::endl;

        this->registeredHandlers.get()->push_back(handler);
    }
};

#endif