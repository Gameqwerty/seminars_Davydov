#include <iostream>
#include <utility>

template<typename T>
void swapEndianness(T& value)
{
    unsigned char* bytes = reinterpret_cast<unsigned char*>(&value);
    std::size_t i = 0;
    std::size_t j = sizeof(T) - 1;
    while (i < j)
    {
        std::swap(bytes[i], bytes[j]);
        ++i;
        --j;
    }
}

int main()
{
    std::cout << std::hex;

    int a = 0x1a2b3c4d;
    std::cout << a << std::endl;
    swapEndianness(a);
    std::cout << a << std::endl;
    swapEndianness(a);
    std::cout << a << std::endl;

    short b = 0x1a2b;
    std::cout << b << std::endl;
    swapEndianness(b);
    std::cout << b << std::endl;
}
