#include <iostream>
#include <string>

struct Except
{
    std::string s;
    bool flag;
    Except(std::string str, bool fl): s(str), flag(fl){}
    ~Except() {
        if (flag) {
            std::cout << s << std::endl;
        }
        
    }
};

void f() {
    std::string s;

    if (std::cin >> s) {
        try {
            f(); 
        } catch(const Except &c) {
            throw Except(s, true);  
        }
    } else {
        throw Except(s, false);
    }

}

int main() {
    try {
        f();
    } catch (const Except & c){

    }
}
