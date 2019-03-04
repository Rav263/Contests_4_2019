#include <iostream>
#include <vector>


void process(const std::vector<int> &vec_1, std::vector<int> &vec_2, unsigned int offset) {
    auto it_2 = vec_2.begin();

    for (auto it = vec_1.begin(); it < vec_1.end(); it += offset) {
        *it_2 = *it;
        it_2 += 1;

        if (it_2 == vec_2.begin()) {
            break;
        }
    }


    for (auto it = vec_2.end() - 1; it >= vec_2.begin(); it--) {
        std::cout << *it << std::endl;
    }
}

