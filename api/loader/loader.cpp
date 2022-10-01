#include "loader.hpp"
#include "../util/win32/dll_handler.hpp"

Loader::Loader(std::string pathToFile) {
    using std::filesystem::path, std::filesystem::absolute, std::filesystem::is_directory, std::filesystem::directory_iterator, std::filesystem::directory_entry;

    auto parse_file = [this](directory_entry file) {
        if(file.path().extension() == ".dll") loadModule(file);
    };

    path abs = absolute(pathToFile);
    if(is_directory(abs)) {
        for(const auto& entry : directory_iterator(abs)) {
            parse_file(entry);
        }
    }
}

LoaderModule Loader::operator[](std::string filePath) {
    return this->m_modHolder[filePath];
}

LoaderModule Loader::operator[](int id) {
    return this->m_modHolder[id];
}

LoaderModuleHolder Loader::getHolder() {
    return this->m_modHolder;
}

void Loader::loadModule(std::filesystem::path file) {
    DEBUG(std::cout << "Loading: " << file.string().c_str() << std::endl;)
    
    HMODULE mod = LoadLibraryA(file.string().c_str());

    if(!mod || mod == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed loading!" << std::endl;
    }

    typedef void(StartupFunc_t)(int index);
    StartupFunc_t* startUp = (StartupFunc_t*) GetProcAddress(mod, "StartUp");
    if(startUp) {
        startUp(this->m_iLastIndex++);

        this->m_modHolder.addModule(LoaderModule(file.filename().string(), mod, 0, m_iLastIndex));
    }
}

void Loader::free() {
    for(auto mod : this->m_modHolder) {
        std::cout << "[" << __FILE__ << ":" << __LINE__ << "] Freeing lib: " << mod.getFileName() << std::endl;
        FreeLibrary(mod.getHandle());
    }
}