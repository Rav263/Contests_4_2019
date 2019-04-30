#include <iostream>
#include <string>
#include <math.h>
#include <boost/date_time/gregorian/gregorian.hpp>


int main() {
    using boost::gregorian::date;
    date a, b;
    int year_1, moun_1, day_1, year_2, moun_2, day_2;
    char trash;
    std::cin >> year_1 >> trash >> moun_1 >> trash >> day_1; 
    b = date(year_1, moun_1, day_1);
    long long int sum = 0; 
    while(std::cin >> year_2 >> trash >> moun_2 >> trash >> day_2) { 
        a = date(year_2, moun_2, day_2);
        sum += abs((a-b).days());
        b = a; 
    } 
    std::cout << sum << std::endl;
}
