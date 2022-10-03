#include "loader.hpp"
#include "../util/win32/dll_handler.hpp"
#include "loader_module.hpp"
#include "loader_module_holder.hpp"

loader_t::loader_t(std::string path) {

    using std::filesystem::absolute, std::filesystem::is_directory, std::filesystem::directory_iterator;

    auto parse_file = [this](auto file) {
        if(file.path().extension() == ".dll") loadModule(file);
    };

    auto abs = absolute(path);
    if(is_directory(abs)) {
        for(const auto& entry : directory_iterator(abs)) {
            parse_file(entry);
        }
    }
}

loader_module_t loader_t::operator[](std::string filePath) {
    return this->m_modHolder[filePath];
}

loader_module_t loader_t::operator[](int id) {
    return this->m_modHolder[id];
}

loader_module_holder_t loader_t::getHolder() {
    return this->m_modHolder;
}

void loader_t::loadModule(std::filesystem::path file) {
    DEBUG(std::cout << "Loading: " << file.string().c_str() << std::endl);
    
    HMODULE mod = LoadLibraryA(file.string().c_str());

    if(!mod || mod == INVALID_HANDLE_VALUE)
    {
        std::cout << "Failed loading!" << std::endl;
    }

    typedef void(StartupFunc_t)(int index);
    StartupFunc_t* startUp = (StartupFunc_t*) GetProcAddress(mod, "StartUp");
    if(startUp) {
        startUp(this->m_iLastIndex++);

        this->m_modHolder.addModule(loader_module_t(file.filename().string(), mod, 0, m_iLastIndex - 1, this));
    }
}

void loader_t::free() {
    for(auto mod : this->m_modHolder) {
        std::cout << "[" << __FILE__ << ":" << __LINE__ << "] Freeing lib: " << mod.getFileName() << std::endl;
        FreeLibrary(mod.getHandle());
    }
}