#include <iostream>

class A
{   
private:
    int a;
    bool flag;

public:
    A() : flag(false) {
        std::cin >> this->a;
    }

    A(const A &b) : flag(true) {
        std::cin >> this->a;
        this->a += b.a;
    }

    ~A() {
        if(flag) {
            std::cout << this->a << std::endl;
        }
    }
};
