#pragma once

#include <string>
#include "Std.hpp"

/// @brief Unimplemented
namespace java {
    namespace _internal {
        typedef void*(JavaGetWorld)(std::string name);
    }

    _internal::JavaGetWorld JavaGetWorld;
    
    namespace regist {
        _SLC_API void JavaRegisterGetWorld(java::_internal::JavaGetWorld func);
    }
}