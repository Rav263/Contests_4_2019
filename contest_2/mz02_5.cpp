#include <iostream>


class S {
    int num;
    bool flg;

public:
    S() : num(0), flg(false) {
        if (std::cin >> num) {
            flg = true;
        } 
    }

    explicit operator bool() const {
        return flg;
    }

    S(S &&now) : flg(true) {
        if (std::cin >> num) {
            num += now.num;
            now.flg = false; 
        } else {
            num = 0;
            flg = false;
        }
    }

    ~S() {
        if (flg) {
            std::cout << num << std::endl;
        }
    }


};
