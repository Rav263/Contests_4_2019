#include <iostream>
#include <string>

int is_our_string(std::string &now) {
    size_t zero_count = 0;
    size_t one_count = 0;
    bool fir = true;

    for (size_t i = 0; i < now.size();) {
        size_t an_z_count = 0;
        size_t an_o_count = 0;
        while (now[i] == '0' and i < now.size()) {
            i++;
            an_z_count++;
        }
        if (fir) {
            zero_count = an_z_count;
        } 
        if (zero_count != an_z_count) {
            return 0;
        }
        while (now[i] == '1' and i < now.size()) {
            i++;
            an_o_count++;
        }
        if (fir) {
            one_count = an_o_count;
            fir = false;
        }
        if (one_count != an_o_count) {
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
