#include <iostream>


class S {
    int num;

public:
    S() {
        std::cin >> num;
    }

    explicit operator bool() const {
        return true;     
    }

    static S move(const S &num) {
        return num;
    }

    ~S() {
        std::cout << num << std::endl;
    }


};
void func(S v)
{
    if (v) {
        func(std::move(v));
    }
}

int main()
{
    func(S());
}
