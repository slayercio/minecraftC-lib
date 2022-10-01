#pragma once

#ifndef _LOADER_MODULE_HOLDER_HPP
#define _LOADER_MODULE_HOLDER_HPP

#include <vector>
#include <string>
#include "loader_module.hpp"

/// @brief Class that holds all loaded
class LoaderModuleHolder final {
private:
    std::vector<LoaderModule> loadedModules;

    std::vector<LoaderModule>& get();
public:
    LoaderModuleHolder(std::vector<LoaderModule> modules = {});

    LoaderModule getModuleById(int id);
    LoaderModule getModuleByFileName(std::string fileName);

    void addModule(LoaderModule mod);
    void removeModule(LoaderModule mod);

    LoaderModule operator[](int id);
    LoaderModule operator[](std::string fileName);

    std::vector<LoaderModule>::iterator begin();
    std::vector<LoaderModule>::iterator end();
};

#endif