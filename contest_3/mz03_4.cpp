#include <vector>
#include <algorithm>
#include <iostream>

struct Avg 
{
    double sum;

    Avg() : sum(0) {};

    void operator ()(double now) {
        sum += now;
    }
};


int main() {
    std::vector<double> values;

    double now;

    while (std::cin >> now) {
        values.push_back(now);
    }

    double part_1 = values.size() * 0.1;
    int part_tmp_1 = int(part_1);


    values.erase(values.begin(), values.begin() + part_tmp_1);
    values.erase(values.end() - part_tmp_1, values.end());

    std::sort(values.begin(), values.end());

    double part_2 = values.size() * 0.1;
    int part_tmp_2 = int(part_2);


    values.erase(values.begin(), values.begin() + part_tmp_2);
    values.erase(values.end() - part_tmp_2, values.end());


    Avg avg = std::for_each(values.begin(), values.end(), Avg());

    double tmp_avg = avg.sum / values.size();

    std::cout << tmp_avg << std::endl;

}
