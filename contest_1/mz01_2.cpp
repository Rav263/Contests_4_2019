#include <iostream>

struct A
{   
    int a;
    bool flag;


    A() {
        std::cin >> this->a;
        flag = false;
    }

    A(const A &b) {
        std::cin >> this->a;
        this->a += b.a;
        flag = true;
    }

    ~A() {
        if(flag) {
            std::cout << this->a << std::endl;
        }
    }
};
