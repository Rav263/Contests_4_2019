
#include <cmath>

template <class T>
class Coord
{
public:
    typedef T value_type;
    T row, col;
    Coord(T a = T(), T b = T()): row(a), col(b) {}
};

template <class T>
T dist(const Coord<T> &rect_size, const Coord<T> &a, const Coord<T> &b)
{
    T m = rect_size.row, n = rect_size.col, x1 = a.row, y1 = a.col, x2 = b.row, y2 = b.col;
    T dy1 = abs(y2 - y1), dy2 = (y1 < y2) ? (y1 + n - y2) : (y2 + n - y1);
    T dy = (dy1 < dy2) ? dy1 : dy2;
    T dx1 = abs(x2 - x1), dx2 = (x1 < x2) ? (x1 + m - x2) : (x2 + m - x1);
    T dx = (dx1 < dx2) ? dx1 : dx2;
    T max = (dx < dy) ? dy : dx;
    return max;   
}
