#include <iostream>
#include <vector>

#include "mz04_2.cpp"

bool func(int x) {
    return x > 10;
}

int main() {
    std::vector<int> v{1, 2, 3, 123, 123, 12,4, 14,1};

    auto some = myfilter(v, func);

    for(auto x : some) {
        std::cout << x << std::endl;
    }
}
