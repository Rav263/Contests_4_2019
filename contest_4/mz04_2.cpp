template<typename T, typename F>
T myfilter(const T &v, F f) {
    T res{};

    for (const auto &x : v) {
        if (f(x)) {
            res.insert(res.end(), x);
        }
    }

    return res;
}

