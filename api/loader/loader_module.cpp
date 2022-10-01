#include "loader_module.hpp"

LoaderModule::LoaderModule(std::string fileName, HMODULE hMod, long funcExported, int id) : fileName(fileName), 
    hMod(hMod), functionsExported(funcExported), id(id) {}

std::string LoaderModule::getFileName() {
    return this->fileName;
}

HMODULE LoaderModule::getHandle() {
    return this->hMod;
}

long LoaderModule::getFuncExported() {
    return this->functionsExported;
}

int LoaderModule::getId() {
    return this->id;
}

std::vector<LoaderModule::ModuleFunctions> LoaderModule::getExportedRoutines() {
    return this->functionIncluded;
}