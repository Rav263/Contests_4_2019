#include <iostream>
#include <string>


int main() {
    std::string str;

    while (std::cin >> str) {
        size_t i = str.size();

        if (i < 3 or str[i - 3] != '1') {
            std::cout << "0" << std::endl;
            continue;
        }
        bool flag = true;

        for (i = 0; i < str.size(); i++) {
            if (str[i] != '0' and str[i] != '1') {
                flag = false;
                break;
            }
        }

        if (!flag) {
            std::cout << "0" << std::endl;
        } else {
            std::cout << "1" << std::endl;
        }
    }
}
