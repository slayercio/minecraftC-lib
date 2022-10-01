#pragma once

#ifndef _LOADER_HPP
#define _LOADER_HPP

#include <stdio.h>
#include <filesystem>
#include <ostream>
#include <fstream>
#include <istream>

#include "loader_module.hpp"
#include "loader_module_holder.hpp"

/// @brief Loads all dll's found in given directory and checks if they're valid LoaderModule (that is they export void StartUp(int))
class Loader final {
private:
    // Holds all of the loaded modules
    LoaderModuleHolder m_modHolder;

    // Index of last loaded module
    int m_iLastIndex;    

    // Loads modules into memory and executes `StartUp` function that they export
    void loadModule(std::filesystem::path path);

public:
    Loader(std::string basePath = "plugins");
    void free();

    LoaderModule operator[](std::string filePath);
    LoaderModule operator[](int id);

    LoaderModuleHolder getHolder();
};

#endif