#pragma once

#ifndef _LOADER_MODULE_HPP
#define _LOADER_MODULE_HPP

#include <array>
#include "../Std.hpp"
#include "loader.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

class loader_module_t final {
private:
    HMODULE hMod;

    std::string fileName;

    long functionsExported;
    int id;

    loader_t* m_loader;
public:
    std::string getFileName();

    HMODULE getHandle();
    long getFuncExported();
    int getId();
    

    loader_module_t(std::string fileName, HMODULE hMod, long funcExported, int id, loader_t* loader);
};

#endif