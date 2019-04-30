#include <vector>
#include <functional>


template<typename T, typename F>
void myapply(T beg, T end, F f) {
    for (; beg != end; beg += 1) {
        f(*beg);
    }
}

template<typename T, typename F>
void myapply(T *beg, T *end, F f) {
    for (; beg != end; beg += 1) {
        f(*beg);
    }
}

template<typename T, typename F>
std::vector<std::reference_wrapper<typename T::value_type>> 
myfilter2(T beg, T end, F f) {
    std::vector<std::reference_wrapper<typename T::value_type>> res;
    for (; beg != end; beg += 1) {
        if (f(*beg)) {
            res.insert(res.end(), std::reference_wrapper<typename T::value_type>(*beg));
        }
    }

    return res;
}



template<typename T, typename F>
std::vector<std::reference_wrapper<T>> 
myfilter2(T *beg, T *end, F f) {
    std::vector<std::reference_wrapper<T>> res;
    for (; beg != end; ++beg) {
        if (f(*beg)) {
            res.insert(res.end(), std::reference_wrapper<T>(*beg));
        }
    }

    return res;
}
