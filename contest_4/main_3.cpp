#include "mz3.cpp"

#include <vector>
#include <functional>
#include <iostream>

void func(int &x) {
    x *= 10;
}

bool some(int x) {
    return x > 3;
}


int main() {
    std::vector<int> som = {1, 2, 3, 4, 5, 6, 6, 7};
    //int som[]{1, 2, 3, 4, 5, 6, 6, 7};

    auto sss = myfilter2(som.begin(), som.end(), some);

    myapply(sss.begin(), sss.end(), func);

    for (int i = 0; i < 8; i++) {
        std::cout << som[i] << std::endl;
    }
}
