#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <utility>

bool check_pair(std::pair<bool, size_t> &tmp, std::pair<bool, size_t> &good) {
    return (tmp.first and not good.first) or (not good.first and tmp.second > good.second);
}


std::pair<bool, size_t> recur_check(const std::string &current, size_t index, 
        std::map<std::string, std::vector<std::string>> &rules,
        std::set<std::string> &terms, std::string &input) {
    
    if (index == input.size()) {
        if (terms.count(current)) {
            return {true, index};
        }
        
        return {false, index};
    }

    std::pair<bool, size_t> good(false, index);

    if (rules.count(current + " eps")) {
        for (auto &now_str : rules[current + " eps"]) {
            if (now_str.compare(current) != 0) {
                auto tmp = recur_check(now_str, index, rules, terms, input);

                if (check_pair(tmp, good)) {
                    good = tmp;
                }
            }
        }
    }

    if (rules.count(current + " " + input[index])) {
        for (auto &now_str : rules[current + " " + input[index]]) {
            auto tmp = recur_check(now_str, index + 1, rules, terms, input);

            if (check_pair(tmp, good)) {
                good = tmp;
            }
        }
    }


    return good;
}


int main() {
    std::map<std::string, std::vector<std::string>> rules;

    while (true) {
        std::string str_1, str_2, now_char;


        std::cin >> str_1;

        if (str_1.compare("END") == 0) {
            break;
        }

        std::cin >> now_char >> str_2;

        if (rules.count(str_1 + " " + now_char) == 0) {
            rules.insert(std::pair<std::string, std::vector<std::string>>(str_1 + " " + now_char, {str_2}));
        } else {
            rules[str_1 + " " + now_char].push_back(str_2);
        }
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

    auto result = recur_check(current, 0, rules, terms, input);

    std::cout << result.first << std::endl;
    std::cout << result.second << std::endl;
}
