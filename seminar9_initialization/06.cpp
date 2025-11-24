#include <iostream>

class RestrictWrapper
{
private:
    int& ref;
    const int minValue;
    const int maxValue;
    int getCounter;
    int setCounter;

public:
    RestrictWrapper(int& x, int minV, int maxV)
        : ref(x), minValue(minV), maxValue(maxV), getCounter(0), setCounter(0)
    {
    }

    int get()
    {
        ++getCounter;
        return ref;
    }

    void set(int v)
    {
        ++setCounter;
        if (v < minValue)
            ref = minValue;
        else if (v > maxValue)
            ref = maxValue;
        else
            ref = v;
    }

    int getCount() const
    {
        return getCounter;
    }

    int setCount() const
    {
        return setCounter;
    }
};

int main()
{
    int x = 100;
    RestrictWrapper w(x, 0, 300);
    std::cout << w.get() << std::endl;     // 100
    w.set(-200);
    std::cout << w.get() << std::endl;     // 0
    w.set(300);
    w.set(400);
    w.set(500);
    std::cout << w.get() << std::endl;     // 300

    std::cout << w.getCount() << std::endl; // 3
    std::cout << w.setCount() << std::endl; // 4
}
