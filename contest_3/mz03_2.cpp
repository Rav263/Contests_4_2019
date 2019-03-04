#include <vector>
#include <iostream>
#include <algorithm>

void process(const std::vector<int> &vec_1, std::vector<int> &vec_2) {
    std::vector<int> vec_copy = vec_1;
    std::unique(vec_copy.begin(), vec_copy.end());

    std::sort(vec_copy.begin(), vec_copy.end());

    auto bad_it = vec_2.begin();
    auto bad_num_it = vec_1.begin();

    for (auto it = vec_2.begin(); it < vec_2.end(); it++) {
        if (it - vec_2.begin() == *bad_num_it) {
            
        }
    }
}
