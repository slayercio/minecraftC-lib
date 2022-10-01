#include <iostream>
#include "api/Std.hpp"
#include "api/loader/loader.hpp"



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
    load_libs();

    free();

    return 0;
}