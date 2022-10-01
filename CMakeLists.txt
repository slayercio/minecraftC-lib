cmake_minimum_required(VERSION 3.10)

project(MinecraftC)

add_library(MinecraftC SHARED MinecraftC.cpp api/loader/loader.cpp 
api/loader/loader_module.cpp api/loader/loader_module_holder.cpp)

add_executable(MinecraftCE MinecraftC.cpp api/loader/loader.cpp 
api/loader/loader_module.cpp api/loader/loader_module_holder.cpp)

set(CMAKE_CXX_STANDARD 23)

if(WIN32)
    target_link_libraries(MinecraftC)
endif()

