#include "loader_module_holder.hpp"
#include <stacktrace>

LoaderModule null() {
    LoaderModule x(std::string(""), (HMODULE)INVALID_HANDLE_VALUE, (long)-1, -1);
    return x;
}

LoaderModuleHolder::LoaderModuleHolder(std::vector<LoaderModule> modules) {
    this->loadedModules = modules;
}

LoaderModule LoaderModuleHolder::getModuleById(int id) {
    std::vector<LoaderModule>& modules = get();

    for(auto mod : modules) {
        if(mod.getId() == id) return mod;
    }

    return null();
}

LoaderModule LoaderModuleHolder::getModuleByFileName(std::string fileName) {
    for(auto mod : get()) {
        if(mod.getFileName() == fileName) return mod;
    }

    return null();
}

std::vector<LoaderModule>& LoaderModuleHolder::get() {    
    return this->loadedModules;
}

LoaderModule LoaderModuleHolder::operator[](int id) {
    return this->getModuleById(id);
}

LoaderModule LoaderModuleHolder::operator[](std::string x) {
    return this->getModuleByFileName(x);
}

std::vector<LoaderModule>::iterator LoaderModuleHolder::begin() {
    return loadedModules.begin();
}

std::vector<LoaderModule>::iterator LoaderModuleHolder::end() {
    return loadedModules.end();
}

void LoaderModuleHolder::addModule(LoaderModule mod) {
    this->loadedModules.push_back(mod);
}