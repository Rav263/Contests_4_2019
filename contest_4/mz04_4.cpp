#include <algorithm>

template<typename T, typename F>
F myremove(T beg_1, T end_1, F beg_2, F end_2) {
    auto range_begin = beg_2, range_end = beg_2;
    ssize_t current = 0;

    while (range_end != end_2) {
        auto it = beg_1;
        while (it != end_1) {
            if (*it == current) break;
            ++it;
        }

        if (it == end_1) {
            *range_begin = std::move(*range_end);
            ++range_begin;
        }

        ++range_end;
        ++current;
    }


    return range_begin;
}
