#pragma once

#ifndef _LOADER_MODULE_HPP
#define _LOADER_MODULE_HPP

#include <array>
#include "../Std.hpp"
#ifdef _WIN32
#include <windows.h>
#endif

class LoaderModule final {
public:
    enum ModuleFunctions {

    };

private:
    HMODULE hMod;

    std::string fileName;

    long functionsExported;
    int id;

    std::vector<ModuleFunctions> functionIncluded;

public:
    std::string getFileName();

    HMODULE getHandle();
    long getFuncExported();
    int getId();
    std::vector<ModuleFunctions> getExportedRoutines();

    LoaderModule(std::string fileName, HMODULE hMod, long funcExported, int id);
};

#endif