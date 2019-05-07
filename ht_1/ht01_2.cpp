#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <functional>
#include <stdio.h>


void thread_function(std::vector<std::mutex> &acc_lock, std::vector<double> &accs, 
        uint32_t iter_count, uint32_t index_1, uint32_t index_2, double sum_1, double sum_2) {

    for (uint32_t i = 0; i < iter_count; i++) {
        acc_lock[index_1].lock();
        accs[index_1] += sum_1;
        acc_lock[index_1].unlock();

        acc_lock[index_2].lock();
        accs[index_2] += sum_2;
        acc_lock[index_2].unlock();
    }
}


int main() {
    uint32_t acc_count, thr_count;

    std::cin >> acc_count >> thr_count;

    std::vector<std::mutex> acc_lock(acc_count);
    std::vector<double> accs(acc_count);
    std::vector<std::thread> threads;


    for (uint32_t i = 0; i < thr_count; i++) {
        uint32_t iter_count, index_1, index_2;
        double sum_1, sum_2;
        
        std::cin >> iter_count >> index_1 >> sum_1 >> index_2 >> sum_2;
        threads.push_back(std::thread(thread_function, std::ref(acc_lock), std::ref(accs), iter_count,
                    index_1, index_2, sum_1, sum_2));
    }

    for (uint32_t i = 0; i < thr_count; i++) {
        threads[i].join();
    }

    for (uint32_t i = 0; i < acc_count; i++) {
        printf("%.10g\n", accs[i]);
    }
    
}
