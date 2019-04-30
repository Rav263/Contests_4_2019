#include <algorithm>

namespace Game {
    template<class T>
    class Coord {
    public:
        typedef T value_type;
        T row;
        T col;

        Coord(T a = T(), T b = T()): row(a), col(b) {}
    };

    template<typename T>
    T dist(Coord<T> &rect, Coord<T> &a, Coord<T> &b) {
        T minrow_1 = abs(a.row - b.row);
        T mincol_1 = abs(a.col - b.col);

        T tmp = T();

        if ((a.row > b.row && a.col % 2) ||
                (b.row > a.row && not (a.col % 2))) {
            tmp = mincol_1 / 2 + mincol_1 % 2;
        } else {
            tmp = mincol_1 / 2;  
        }

        if (tmp > minrow_1) {
            tmp = minrow_1;
        }

        return mincol_1 + minrow_1 - tmp;
    }
}



