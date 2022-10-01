#include <iostream>
#include "api/Std.hpp"
#include "api/loader/loader.hpp"
#include "api/minecraft/minecraft.hpp"



_SLC_API Loader* getLoader(std::string path = ".\\plugins") {
    static Loader* g_loader;
    if(!g_loader)
        g_loader = new Loader(path);

    return g_loader;
}

_SLC_API void load_libs() {
    getLoader();
}

_SLC_API void free() {
    getLoader()->free();
}

int main() {
    Minecraft mc{"test, 123"};

    load_libs();

    free();

    std::cout << mc.getWorlds() << std::endl;

    return 0;
}