#include <cmath>
#include <iostream>

namespace Game
{
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
        T dx = (a.col - b.col > 0) ? (a.col - b.col) : (b.col - a.col);
        T delta = b.row - a.row;
        T dy = (delta > 0) ? delta : -delta;
        bool up = delta < 0, down = delta > 0;
        T dif;
        if ((down && !(a.col % 2)) || (up && a.col % 2)) {
            std::cout << up << " " << down << std::endl;
            dif = dx / 2 + dx % 2;
        } else {
            std::cout << "half" << std::endl;
            dif = dx / 2;
        }
        if (dif > dy) {
            std::cout << "more" << std::endl;
            dif = dy;
        }
        return dx + dy - dif;
    }
}
