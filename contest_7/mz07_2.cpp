#include <iostream>

int main() {
    std::string now;
    std::cin >> now;

    size_t pos = 1;
    int state = 'S';

    while (true) {
        char now_char = now[pos];

        if (state == 'S') {
            if (now_char == '0') {
                pos += 1;
            } else if (now_char == '1') {
                state = 'A';
                pos += 1;
            } else {
                break;
            }
        } else if (state == 'A') {
            if (now_char == '0') {
                pos += 1;
            } else if (now_char == '1') {
                state = 'S';
                pos += 1;
            } else {
                state = 'B';
                pos -= 1;
            }
        } else if (state == 'B') {
            if (now_char == '0') {
                pos -= 1;
            } else if (now_char == '1') {
                pos -= 1;            
            } else { 
                state = 'C';
                pos += 1;
            }
        } else if (state == 'C') {
            if (now_char == '0') {
                pos += 1;
            } else if (now_char == '1') {
                now[pos] = '0';
                break;
            } else {
                break;
            }
        } 
    }

    std::cout << now << std::endl;
}
