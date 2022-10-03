#pragma once

#ifndef _LOADER_HPP
#define _LOADER_HPP

#include <stdio.h>
#include <filesystem>
#include <ostream>
#include <fstream>
#include <istream>

/// @brief Loads all dll's found in given directory and checks if they're valid LoaderModule (that is they export void StartUp(int))
class loader_t final {
private:
    // Holds all of the loaded modules
    loader_module_holder_t m_modHolder;

    // Index of last loaded module
    int m_iLastIndex;    

    // Loads modules into memory and executes `StartUp` function that they export
    void loadModule(std::filesystem::path path);

public:
    loader_t(std::string basePath = "plugins");
    void free();

    loader_module_t operator[](std::string filePath);
    loader_module_t operator[](int id);

    loader_module_holder_t getHolder();
};

#endif