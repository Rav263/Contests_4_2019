#include <iostream>
#include "den_5.cpp"


int main()
{
    std::array<std::complex<double>, 3> v1{
        std::complex<double>(1.0, 2.0),
        std::complex<double>(2.0, 0),
        std::complex<double>(3, 1.3)
    };

    auto res = Equations::quadratic(v1);
    std::cout << res.first << std::endl;
    for (auto now : res.second) {
        std::cout << now << std::endl;
    }
}
