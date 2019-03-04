#include <string>
#include <iostream>
#include <algorithm>


int main() {
    for(std::string now; std::cin >> now;) {
        std::string sub_string = now;
        std::reverse(now.begin(), now.end());

        for (unsigned long int i = 0; i < now.size(); i++) { 
            if (std::equal(now.begin(), now.end() - i, sub_string.begin() + i)) {
                std::cout << sub_string.substr(i) << std::endl;

                break;
            }
        }
    }
}
