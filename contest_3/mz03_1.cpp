#include <iostream>
#include <vector>


void process(const std::vector<int> &vec_1, std::vector<int> &vec_2, int offset) {
    auto it_2 = vec_2.begin();

    for (auto it = vec_1.begin(); it < vec_1.end(); it += offset) {
        if (it_2 == vec_2.end()) {
            break;
        }
        
        *it_2 = *it;
        it_2 += 1;
    }


    for (auto it = vec_2.rbegin(); it < vec_2.rend(); it++) {
        std::cout << *it << std::endl;
    }
}

