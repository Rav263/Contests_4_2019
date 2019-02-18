#include <iostream>
#include <iomanip>
#include <math.h>


int main() {
    int counter = 0;


    double now;
    double avr = 0;
    double deviat = 0;

    while (std::cin >> now) {
        counter += 1;
        avr += now;
        deviat += now * now;
    }

    deviat /= counter;
    avr /= counter;

    deviat = deviat - avr * avr;

    deviat = std::sqrt(deviat);

    std::cout << std::setprecision(10) << avr << std::endl << deviat << std::endl;
}
