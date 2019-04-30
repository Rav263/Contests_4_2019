#include <cmath>
#include <algorithm>
#include <iostream>
template<class T>
class Coord {
public:
    typedef T value_type;
    T row;
    T col;


    Coord(T a = T(), T b = T()) : row(a), col(b) {
    }
};



template<typename T>
T dist(Coord<T> &rect, Coord<T> &a, Coord<T> &b) {
    if (rect.row == 0 or rect.col == 0) {
        return T();
    }

    T minrow_1 = abs(a.row - b.row);
    T mincol_1 = abs(a.col - b.col);
    T minrow_2 = (rect.row + a.row - b.row) % rect.row;
    T minrow_3 = (rect.row + b.row - a.row) % rect.row;
    T mincol_2 = (rect.col + a.col - b.col) % rect.col;
    T mincol_3 = (rect.col + b.col - a.col) % rect.col;

    T tmp_1 = std::min(minrow_2, minrow_3);
    T tmp_2 = std::min(mincol_2, mincol_3);

    return std::max(std::min(minrow_1, tmp_1),std::min(mincol_1, tmp_2));
}

