#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>


int main() {
    std::map<std::string, std::string> rules;

    while (true) {
        std::string str_1, str_2;
        char now_char;

        std::cin >> str_1;

        if (str_1.compare("END") == 0) {
            break;
        }

        std::cin >> now_char >> str_2;

        rules.insert(std::pair<std::string, std::string>(str_1 + " " + now_char, str_2));
    }

    std::set<std::string> terms;

    while (true) {
        std::string now_str;
        std::cin >> now_str;

        if (now_str.compare("END") == 0) {
            break;
        }

        terms.insert(now_str);
    }

    std::string current, input;
    std::cin >> current >> input;

    size_t index = 0;
    bool ok_flg = true;

    for (index = 0; index < input.size(); index++) {
        char now_char = input[index];

        if (rules.count(current + " " + now_char) == 0) {
            ok_flg = false;
            break;
        }

        current = rules[current + " " + now_char];
    }

    if (terms.count(current) == 0) {
        ok_flg = false;
    }

    std::cout << ok_flg << std::endl;
    std::cout << index << std::endl;
    std::cout << current << std::endl;
}
