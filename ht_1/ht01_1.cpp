#include <iostream>
#include <thread>
#include <mutex>
#include <stdio.h>


constexpr int NUM_EL = 3;
constexpr int NUM_OP = 1000000;


double elements[NUM_EL] = {0, 0, 0};

std::mutex elements_lock;

void thread_operation(int index, double s) {
    for (int i = 0; i < NUM_OP; i++) {
        elements_lock.lock();
        elements[index] += s;
        elements[(index + 1) % 3] -= s + 1;
        elements_lock.unlock();
    }
}



int main() {
    std::thread thr_1(thread_operation, 0, 100);
    std::thread thr_2(thread_operation, 1, 200);
    std::thread thr_3(thread_operation, 2, 300);

    thr_1.join();
    thr_2.join();
    thr_3.join();

    printf("%.10g %.10g %.10g\n", elements[0], elements[1], elements[2]); 
}
