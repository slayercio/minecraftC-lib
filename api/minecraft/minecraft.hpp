#pragma once
#ifndef _MINECRAFT_HPP
#define _MINECRAFT_HPP

#include "../Std.hpp"
#include "atomic_instance.hpp"

class Minecraft {
private:
    atomic_instance<std::string> worlds;

public:
    Minecraft(std::string worlds) {
        this->worlds.set(&worlds);
    }

    std::string getWorlds() {
        return *worlds.get();
    }
};

#endif