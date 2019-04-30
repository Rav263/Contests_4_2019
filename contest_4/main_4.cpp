#include <iostream>
#include <vector>

#include "mz04_4_d.cpp"

int main() {
    std::vector<int> some = {0, 1, 2, 3, 4, 5, 6, 7, 9, 9, 10};
    std::vector<int> ssss = {1, 3 ,5, 10, 2 , 5, 7};


    auto end = myremove(ssss.begin(), ssss.end(), some.begin(), some.end());

    for (auto it = some.begin(); it != end; it++) {
        std::cout << *it << std::endl;
    }
}
