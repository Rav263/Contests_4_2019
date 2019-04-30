#include <iostream>
#include <vector>


int main() {
    int n;
    std::cin >> n;


    std::vector<int> some;

    for (int i = 0; i < n; i++) {
        some.push_back(i);
    }

    int64_t sum = 0;

    for (int i = 0; i < n; i += 1) {
        sum += some[i];
    }

    std::cout << sum << std::endl;
}
