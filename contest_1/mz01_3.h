#include <iostream>

class Holder
{
    int value = 0;

public:
    Holder()
    {
        std::cin >> value;
    }

    ~Holder()
    {
        std::cout << value << std::endl;
    }

    void swap(Holder &other)
    {
        int tmp = value;
        value = other.value;
        other.value = tmp;
    }
};
