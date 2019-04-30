#include <iostream>
#include <string>

int is_our_string(std::string &now) {

    

    return 1;
}


int main() {
    char now;
    while (true) {
        size_t i = 0;
        size_t zero_count = 0;
        size_t one_count = 0;
        bool fir = true;
        int ans = 1;
        while (now != ' ' and now != '\n') {
            std::cin >> now;
            size_t an_z_count = 0;
            size_t an_o_count = 0;
            while (now == '0' and std::cin >> now) {
                i++;
                an_z_count++;
            }
            if (fir) {
                zero_count = an_z_count;
            } 
            if (zero_count != an_z_count) {
                ans = 0;
                break;
            }
            while (now == '1' and std::cin >> now) {
                i++;
                an_o_count++;
            }
            if (fir) {
                one_count = an_o_count;
                fir = false;
            }
            if (one_count != an_o_count) {
                ans = 0;
                break;
            }
        }

        std::cout << ans << std::endl;
    }
}
