#include <iostream>
#include <thread>
#include <future>
#include <functional>
#include <vector>



bool is_simple(uint64_t num) {
    if (num == 0 or num == 1) {
        return false;
    }

    for (uint64_t i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

void thread_operation(uint64_t low, uint64_t high, uint32_t count, 
        std::vector<std::promise<uint64_t>> &ret, std::exception_ptr &except) {
    size_t promise_index = 0;

    for (uint64_t i = low; i < high; i++) {
        if (is_simple(i)) {
            ret[promise_index].set_value(i);
            promise_index++;
            if (promise_index == count) {
                return;
            }
        }
    }
    
    try {
        throw uint64_t(high);
    } catch (uint64_t now_except) {
        except = std::current_exception();
        return;
    }
}


int main() {
    uint64_t low, high;
    uint32_t count;

    std::cin >> low >> high >> count;
    
    std::vector<std::promise<uint64_t>> numbers(count);

    std::vector<std::future<uint64_t>> fts;
    
    for (auto &prom : numbers) {
        fts.push_back(prom.get_future());
    }
    
    std::exception_ptr except;

    std::thread thr(thread_operation, low, high, count, std::ref(numbers), std::ref(except));

    for (size_t i = 0; i < count; i++) {
        while (true) {
            auto now_state = fts[i].wait_for(std::chrono::milliseconds(1));
            if (now_state == std::future_status::ready) {
                break;
            }
            try {
                if (except != nullptr) {
                    std::rethrow_exception(except);
                }
            } catch (uint64_t now_except) {
                std::cout << now_except << std::endl;
                thr.join();
                return 0;
            }
        }
        std::cout << fts[i].get() << std::endl;
    }
    thr.join();
}
