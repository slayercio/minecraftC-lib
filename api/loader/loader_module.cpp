#include "loader_module.hpp"
#include "loader.hpp"

loader_module_t::loader_module_t(std::string fileName, HMODULE hMod, long funcExported, int id, loader_t* loader) : fileName(fileName), 
    hMod(hMod), functionsExported(funcExported), id(id), m_loader(loader) {}

std::string loader_module_t::getFileName() {
    return this->fileName;
}

HMODULE loader_module_t::getHandle() {
    return this->hMod;
}

long loader_module_t::getFuncExported() {
    return this->functionsExported;
}

int loader_module_t::getId() {
    return this->id;
}