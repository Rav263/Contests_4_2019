#include <iostream>

int main() {
    for (int i = 0; i < 6 * 1024 * 1024; i++) {
        std::cout << "1" << std::endl;
    }
    std::cout << std::endl;
}
