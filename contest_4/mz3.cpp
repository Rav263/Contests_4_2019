#include <iostream>
#include <functional>
#include <vector>
void f(int &a) {
    std::cout << a + 4 << std::endl;
}

template <typename T, typename F>
void myapply(T beg, T end, F f) {
    for (; beg != end; ++beg) {
        f(*beg);
    }
}

class DividedByTwo 
{ 
    public: 
        bool operator()(int x) const 
        { 
            return x % 2 == 0; 
        } 
}; 

template <typename Y, typename L>
std::vector<std::reference_wrapper<typename Y::value_type>> 
myfilter2(Y beg, Y end, L f){
    std::vector<std::reference_wrapper<typename Y::value_type>> ret;
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            ret.insert(ret.begin(), std::reference_wrapper<typename Y::value_type>(*beg));
        }
    }
    return ret;
}
int main() {
    std::vector<int> v = {1, 2, 3};

    auto test = myfilter2(v.begin(), v.end(), DividedByTwo());
    
    myapply(test.begin(), test.end(), f);
}
