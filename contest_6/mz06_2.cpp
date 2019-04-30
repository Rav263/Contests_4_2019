//with k == 0 sum, with k == 1 is mult, with k == 2 it's pow b^a 

#include <iostream>
#include <cstdint>


class Result {
    int64_t res;
public:
    Result(int64_t res) : res(res) {
    }

    int64_t get_res() {
        return res;
    }
};


void func(int64_t a, int64_t b, int32_t k) {
    if (k == 0) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
    }

    try {
        func(a, b - 1, k);
    } catch(Result &e) {
        func(a, e.get_res(), k - 1);
    }
}


int main() {
    int64_t a, b;
    int32_t k;

    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch (Result &e) {
            std::cout << e.get_res() << std::endl;
        }
    }
}
