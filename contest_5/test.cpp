#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string now;

    std::getline(std::cin, now);

    size_t next = 0;
    
    double a, b;
    std::istringstream str_stream(now);

    str_stream >> a;
    str_stream >> b;

    std::cout << a << " " << b << " " << next << std::endl;
}
