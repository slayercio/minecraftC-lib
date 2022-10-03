#pragma once

#ifndef _LOADER_MODULE_HOLDER_HPP
#define _LOADER_MODULE_HOLDER_HPP

#include <vector>
#include <string>
#include "loader_module.hpp"

/// @brief Class that holds all loaded
class loader_module_holder_t final {
private:
    std::vector<loader_module_t> loadedModules;

    std::vector<loader_module_t>& get();
public:
    loader_module_holder_t(std::vector<loader_module_t> modules = {});

    loader_module_t getModuleById(int id);
    loader_module_t getModuleByFileName(std::string fileName);

    void addModule(loader_module_t mod);
    void removeModule(loader_module_t mod);

    loader_module_t operator[](int id);
    loader_module_t operator[](std::string fileName);

    std::vector<loader_module_t>::iterator begin();
    std::vector<loader_module_t>::iterator end();
};

#endif