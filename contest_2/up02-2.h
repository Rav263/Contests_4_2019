#include <cstdio>

#include "mz02_1.h"

namespace numbers {
class complex_stack {
    int num, max_num;
    complex *arr;
public:
    complex_stack (int n = 15) : num (0), max_num (n) {
        arr = new complex [n];
    }
    complex_stack (const complex_stack &a) : num(a.num), max_num(a.max_num) {
        arr = new complex [a.max_num];
        int i = 0;
        for (i = 0; i < a.num; i++) {
            arr [i] = a.arr [i];
        }
    }
    ~complex_stack () {
        delete []arr;
    }
    size_t size () const {
        return num;
    }
    complex &operator[] (int n) const{
        return arr[n];
    }
    friend complex_stack operator<< (const complex_stack &a, const complex &b) {
        int tmp_size = a.max_num, i = 0;
        if (a.max_num <= a.num + 1) {
            tmp_size *= 2;
        }
        complex_stack tmp_arr(tmp_size);
        tmp_arr.num = a.num;
        for (i = 0; i < a.num; i++) {
            tmp_arr.arr[i] = a.arr[i];
        }

        tmp_arr.arr[a.num] = b;
        tmp_arr.num++;
        return tmp_arr;
    }

    complex_stack &operator= (const complex_stack &b) {
        if (this == &b) {
            return *this;
        }
        delete []arr;
        arr = new complex [b.max_num];
        int i = 0;
        for (i = 0; i < b.num; i++) {
            arr[i] = b.arr[i];
        }
        num = b.num;
        max_num = b.max_num;
        return *this;
    }
    complex &operator+ () const {
        return arr[num - 1];
    }
    complex_stack operator~ () const{
        complex_stack a = *this;
        a.num--;
        return a;
    }
};
}
