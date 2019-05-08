#include <iostream>
#include <thread>
#include <future>
#include <string>
#include <utility>
#include <cstdlib>
#include <vector>
#include <iomanip>

constexpr uint64_t low = 0;
constexpr uint64_t high = 40;


std::pair<uint64_t, uint64_t> count_points(uint64_t iter_count, uint32_t thread_index) {
    std::pair<uint64_t, uint64_t> result(0, 0);

    for (uint64_t i = 0; i < iter_count; i++) {
        double x_coord = (rand_r(&thread_index) / (RAND_MAX + 1.0)) * (high - low);
        double y_coord = (rand_r(&thread_index) / (RAND_MAX + 1.0)) * (high - low);

        if (x_coord * x_coord + y_coord * y_coord <= high * high) {
            ++result.second;            
        }

        ++result.first;
    }

    return result;
}


int main(int argc, char *argv[]) {
    uint64_t thread_count = std::stoll(argv[1]);
    uint64_t iter_count = std::stoll(argv[2]);

    std::vector<std::future<std::pair<uint64_t, uint64_t>>> results(thread_count);

    for (uint32_t i = 0; i < thread_count; i++) {
        results[i] = std::async(std::launch::async, count_points, iter_count, i);
    }

    uint64_t points_counter = 0;
    uint64_t good_points_counter = 0;


    for (uint32_t i = 0; i < thread_count; i++) {
        results[i].wait();
        auto now_result = results[i].get();

        points_counter += now_result.first;
        good_points_counter += now_result.second;    
    }

    double pi = ((double) good_points_counter / (double) points_counter) * 4;

    std::cout << std::setprecision(7) << pi << std::endl;
}
