#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<std::string, int> map;
    std::vector<std::string> strs;


    int counter = 1;

    std::string str;
    while (std::cin >> str) {
        if (str.back() == ':') {
            str.pop_back();
            map.insert(std::pair<std::string, int>(str, counter));
        } else {
            strs.push_back(str);
            counter++;
        }
    }

    for (size_t i = 0; i < strs.size(); i++) {
        if (map.count(strs[i]) > 0) {
            int tmp = map[strs[i]];
            strs[i] = std::to_string(tmp);
        }
    }

    for (auto now : strs) {
        std::cout << now << std::endl;
    }
}
