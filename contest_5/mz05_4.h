#include <string>
#include <cmath>
#include <sstream>

class Rectangle : public Figure {
private:
    double a, b;
public:
    Rectangle(double a = 0, double b = 0) : a(a), b(b) {}; 

    static Rectangle *make(const std::string &str) {
        double a, b;
       
        std::stringstream str_stream(str);

        str_stream >> a >> b;

        Rectangle *ob = new Rectangle(a, b);

        return ob;
    }

    double get_square() const override {
        return a * b;
    }

    ~Rectangle() {}
};

class Square : public Figure 
{
private:
    double a;
public:
    Square(double a = 0) : a(a) {}

    static Square *make(const std::string &str) {
        double a;
        a = std::stod(str, nullptr);

        Square *ob = new Square(a);

        return ob;
    }

    double get_square() const override {
        return a * a;
    }

    ~Square() {}
};


class Circle : public Figure {
private:
    double a;
public:
    Circle(double a = 0) : a(a) {}

    static Circle *make(const std::string &str) {
        double a;

        a = std::stod(str, nullptr);

        Circle *ob = new Circle(a);

        return ob;
    }

    double get_square() const override {
        return a * a * M_PI;
    }

    ~Circle() {}
};

