#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int main() {
    std::stack<std::string> stack;

    char now;

    while (std::cin >> now) {
        if (islower(now)) {
            stack.push(std::string(1, now));
        } else {

            auto tmp = stack.top();
            stack.pop();
            std::string str = "(";
            
            str += stack.top() + now + tmp + ")";
            stack.pop();
            
            stack.push(str);
        }
    }
    std::cout << stack.top() << std::endl;
    stack.pop();
}
