#include <cmath>
#include <string>

class Figure
{
public:
    virtual double get_square() const = 0;
    virtual ~Figure() {}
};

class Rectangle: public Figure
{
    double a, b;
public:
    Rectangle(int x = 0, int y = 0): a(x), b(y) {}
    double get_square() const
    {
        return a * b;
    }
    static Rectangle *make(const std::string &s)
    {
        double x, y;
        size_t nxt = 0;
        x = stod(s, &nxt);
        y = stod(s.substr(nxt), nullptr);
        Rectangle *p = new Rectangle(x, y);
        return p;
    }
};

class Square: public Figure
{
    double a;
public:
    Square(int x): a(x) {}
    double get_square() const
    {
        return a * a;
    }
    static Square *make(const std::string &s)
    {
        Square *p = new Square;
        p->a = stod(s, nullptr);
        return p;
    }
};

class Circle: public Figure
{
    double r;
public:
    Circle(int x): r(x) {}
    double get_square() const
    {
        return M_PI * r * r;
    }
    static Circle*make(const std::string &s)
    {
        p->r = stod(s, nullptr);
        return p;
    }
};
