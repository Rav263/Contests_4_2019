// язык типа 0 

#include <iostream>
#include <string>

int main() {
    std::string str;

    while (std::cin >> str) {
        size_t m_1 = 0;
        size_t n_1 = 0;
        size_t m_2 = 0;
        size_t n_2 = 0;

        size_t i = 0;

        while (i < str.size() and str[i] == 'a') {
            i++;
            m_1++;
        }

        while (i < str.size() and str[i] == '0') {
            i++;
            n_1++;
        }

        while (i < str.size() and str[i] == 'b') {
            i++;
            m_2++;
        }

        while (i < str.size() and str[i] == '1') {
            i++;
            n_2++;            
        }
        
        if (m_1 != m_2 or m_1 == 0 or m_2 == 0) {
            std::cout << "0" << std::endl;
            continue;
        }

        if (n_1 != n_2 or n_1 == 0 or n_2 == 0 or i < str.size()) {
            std::cout << "0" << std::endl;
            continue;
        }

        std::cout << "1" << std::endl;
    }
}
