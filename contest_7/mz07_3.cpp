#include <iostream>
#include <ctime>
#include <string>
#include <chrono>



int main() {
    std::string now;
    bool first = true;
    struct std::tm was;

    using namespace std::chrono;
    int counter = 0;

    while(std::cin >> now) {
        size_t point = 0;

        int a = std::stoi(now, &point);
        size_t an_point = 0;
        int b = std::stoi(now.substr(point + 1), &an_point);
        int c = std::stoi(now.substr(point + 2 + an_point), &point);

        struct std::tm now = {1, 1, 1, c, b - 1, a - 1900};

        if (first) {
            was = now;
            first = false;
        } else {
            std::time_t x = std::mktime(&was);
            std::time_t y = std::mktime(&now);

            auto a = system_clock::from_time_t(x);
            auto b = system_clock::from_time_t(y);
            
            typedef std::chrono::duration<int, std::ratio_multiply
                <hours::period, std::ratio<24>>::type> days;    
            auto diff_in_days = std::chrono::duration_cast<days>(a - b);
            
            counter += abs(diff_in_days.count());
            
            was = now;
        }
    }

    std::cout << counter << std::endl;
}
