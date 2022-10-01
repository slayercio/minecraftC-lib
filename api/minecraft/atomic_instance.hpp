#pragma once
#ifndef _ATOMIC_INSTANCE_H
#define _ATOMIC_INSTANCE_H 

#include "../Std.hpp"
#include <atomic>
#include <memory>
#include <windows.h>

template<class T>
class atomic_instance {
private:
    std::atomic<T*> m_instance;
    
public:
    atomic_instance() {}

    T* get() {
        while(!m_instance.is_lock_free()) {
            Sleep(0);
        }

        return m_instance.load();
    }

    void set(T* val) {
        while(!m_instance.is_lock_free()) {
            Sleep(0);
        }

        m_instance.store(val);
    }
};

#endif