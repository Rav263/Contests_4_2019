#include <iostream>

class Except {
    std::string now;
    bool flag;
public:
    Except(const std::string &now, bool flag) : now(now), flag(flag) {
    }

    ~Except() {
        if (flag) {
            std::cout << now << std::endl;
    
        }
    }
};


void f() {
    std::string now;
    if (std::cin >> now) {
        Except tmp(now, true);
        f();
    } else {
        throw Except("", false);
    }
}


int main() {
    try {
        f();
    }catch(Except &e) {
    }
}
