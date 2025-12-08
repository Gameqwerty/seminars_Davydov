#include <iostream>
#include <string>
#include <cstdlib>
using namespace std::string_literals;

template<typename T>
class Manager
{
private:
    void*  ptr;
    bool   allocated;
    bool   constructed;

public:
    Manager() : ptr(nullptr), allocated(false), constructed(false) {}

    void allocate()
    {
        if (!allocated)
        {
            ptr = std::malloc(sizeof(T));
            if (!ptr)
                throw std::bad_alloc{};
            allocated   = true;
            constructed = false;
        }
    }

    void construct(const T& t)
    {
        if (!allocated)
            allocate();
        if (constructed)
            destruct();
        new (ptr) T(t);
        constructed = true;
    }

    void destruct()
    {
        if (constructed)
        {
            reinterpret_cast<T*>(ptr)->~T();
            constructed = false;
        }
    }

    void deallocate()
    {
        if (allocated)
        {
            if (constructed)
                destruct();
            std::free(ptr);
            ptr        = nullptr;
            allocated  = false;
        }
    }

    T& get()
    {
        return *reinterpret_cast<T*>(ptr);
    }

    const T& get() const
    {
        return *reinterpret_cast<const T*>(ptr);
    }
};

int main()
{
    Manager<std::string> a;
    a.allocate();

    a.construct("Cats and dogs"s);
    a.get() += " and elephant";
    std::cout << a.get() << std::endl;

    a.construct("Sapere Aude"s);
    std::cout << a.get() << std::endl;
    a.destruct();

    a.deallocate();
}
