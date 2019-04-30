#include <iostream>
#include <string>

int is_our_string(std::string &now) {
    bool flg = true;

    for (size_t i = 0; i < now.size(); i++) {
        if (now[i] >= '1' and now[i] <= '4') {
            if (!flg and (now[i] == '3' or now[i] == '4')) {
                return 0;  
            } 
            if (now[i] == '1' or now[i] == '2') {
                flg = false;
            }
        } else {
            return 0;
        }
    }

    return 1;
}

int main() {
    std::string now;
    
    while (std::cin >> now) {
        std::cout << is_our_string(now) << std::endl;
    }
}
