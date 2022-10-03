#include <iostream>
#include "include/minecraft.hpp"

bool handler(Event e) {
    
}

extern "C" {
__declspec(dllexport) void StartUp(int index) {
    std::cout << "[TestPlugin2] Starting up: " << index << std::endl;
}
}