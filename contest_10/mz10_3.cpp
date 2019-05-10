#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <set>


class Rule
{
private:
    char sym;
    std::string rule;
    bool check;

public:
    Rule (char sym = 0, const std::string &rule = "") : sym(sym), rule(rule) {
        this->check = false;
    }

    void set_checked() {
        this->check = true;
    }

    bool is_checked() {
        return this->check;
    }

    std::string &get_rule() {
        return this->rule;
    }

    char get_char(size_t index) {
        return this->rule[index];
    }

    char get_sym() {
        return this->sym;
    }
};




int main() {
    std::vector<Rule> rules;

    char now_ch;
    std::string now_str;

    while (std::cin >> now_ch >> now_str) {
        rules.push_back(Rule(now_ch, now_str));
    }

    std::set<char> reached;
    reached.insert('S');

    bool flag = true;


    while (flag) {
        flag = false;

        for (Rule &now_rule : rules) {
            if (reached.count(now_rule.get_sym()) and not now_rule.is_checked()) {
                for (char now_char : now_rule.get_rule()) {
                    if (isupper(now_char) and reached.count(now_char) == 0) {
                        flag = true;
                        reached.insert(now_char);
                    }
                }

                now_rule.set_checked();
            }
        }
    }

    for (Rule &now_rule : rules) {
        if (now_rule.is_checked()) {
            std::cout << now_rule.get_sym() << " " << now_rule.get_rule() << std::endl;
        }
    }
}
