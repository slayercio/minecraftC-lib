#include <iostream>

extern "C" {
__declspec(dllexport) void StartUp(int index) {
    std::cout << "[TestPlugin] Starting up: " << index << std::endl;
}
}