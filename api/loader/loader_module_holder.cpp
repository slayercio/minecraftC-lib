#include "loader_module_holder.hpp"
#include <stacktrace>

loader_module_t null() {
    loader_module_t x(std::string(""), (HMODULE)INVALID_HANDLE_VALUE, (long)-1, -1, nullptr);
    return x;
}

loader_module_holder_t::loader_module_holder_t(std::vector<loader_module_t> modules) {
    this->loadedModules = modules;
}

loader_module_t loader_module_holder_t::getModuleById(int id) {
    std::vector<loader_module_t>& modules = get();

    for(auto mod : modules) {
        if(mod.getId() == id) return mod;
    }

    return null();
}

loader_module_t loader_module_holder_t::getModuleByFileName(std::string fileName) {
    for(auto mod : get()) {
        if(mod.getFileName() == fileName) return mod;
    }

    return null();
}

std::vector<loader_module_t>& loader_module_holder_t::get() {    
    return this->loadedModules;
}

loader_module_t loader_module_holder_t::operator[](int id) {
    return this->getModuleById(id);
}

loader_module_t loader_module_holder_t::operator[](std::string x) {
    return this->getModuleByFileName(x);
}

std::vector<loader_module_t>::iterator loader_module_holder_t::begin() {
    return loadedModules.begin();
}

std::vector<loader_module_t>::iterator loader_module_holder_t::end() {
    return loadedModules.end();
}

void loader_module_holder_t::addModule(loader_module_t mod) {
    this->loadedModules.push_back(mod);
}