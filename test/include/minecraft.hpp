#include "atomic_instance.hpp"
#include <vector>
#include <string>
#include <iostream>

class Event {
private:
    void* player;

public:
    virtual void* getPlayer();
};

typedef bool(EventHandler)(Event e);

class Minecraft {
private:
    atomic_instance<std::string> worlds;
    atomic_instance<std::vector<EventHandler*>> registeredHandlers;

public:
    Minecraft(std::string worlds);

    virtual std::string getWorlds();

    virtual void registerEventHandler(EventHandler* handler);
};