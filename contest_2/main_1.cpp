#include <iostream>

#include "up02-2.h"

using namespace numbers;

int main() {
    complex_stack stack;

    int n;
    std::cin >> n;
    unsigned long long sum = 0;

    for (int i = 0; i < n; i++) {
        stack = stack << i;
    }

    for (size_t i = 0; i < stack.size(); i++ ){
        sum += stack[i].get_re();
    }

    std::cout << sum << std::endl;
}
