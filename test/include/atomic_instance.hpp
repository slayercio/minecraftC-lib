#include <atomic>

template<class T>
class atomic_instance {
private:
    std::atomic<T*> m_instance;
    
public:
    atomic_instance();

    virtual T* get();

    virtual void set(T* val);
};
