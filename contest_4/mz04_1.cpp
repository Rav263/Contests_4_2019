template<typename T>
auto process(const T &v, int value = 6) {
    typename T::value_type sum = typename T::value_type();

    int count = 0;

    for (typename T::const_reverse_iterator i = v.rbegin(); i != v.rend() && count < value; ++i) {
        if (count % 2 == 0) {
            sum += *i;
        }
        count += 1;
    }

    return sum;
}

