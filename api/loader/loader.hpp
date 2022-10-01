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

extern "C" class Loader final {
private:
    LoaderModuleHolder m_modHolder;
    int m_iLastIndex;    

    void loadModule(std::filesystem::path path);

public:
    Loader(std::string basePath = "plugins");
    void free();

    LoaderModule operator[](std::string filePath);
    LoaderModule operator[](int id);

    LoaderModuleHolder getHolder();
};

#endif