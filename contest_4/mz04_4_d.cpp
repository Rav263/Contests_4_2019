#include <algorithm>

template <typename T, typename F>
F myremove(T beg, T end, F begg, F endd) {
    int j = 0;
    F place = begg;
    for (F it = begg; it != endd; ++it) {
        bool fl = true;
        for (auto t = beg; t != end; ++t) {
            if (*t == j) {
                fl = false;
            }
        }
        if (fl) {
            *place = std::move(*it);
            ++place;
        }
        ++j;
    }
    return place;
}

