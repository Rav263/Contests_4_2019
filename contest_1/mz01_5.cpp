#include <string>
#include <iostream>
class Rational 
{
private:
    int a, b;

    int gcd(int a, int b) {
       return b ? gcd (b, a % b) : a;
    }

    void min() {
        int gc = gcd(this->a, this->b);
        this->a /= gc;
        this->b /= gc;
    }

public:

    Rational(int a, int b) {
        this->a = a;
        this->b = b;
        min();
    }

    std::string ToString() {
        std::string now = std::to_string(this->a) + ":" + std::to_string(this->b);
        return now;
    }

    void Add(const Rational &a) {
        this->a *= a.b;

        this->a += a.a * this->b;
        this->b *= a.b;
    }

    void Substruct(const Rational &a) {
        this->a *= a.b;

        this->a -= a.a * this->b;
        this->b *= a.b;
    }
};


int main() {
    int c, d;

    std::cin >> c >> d;

    Rational a = Rational(c, d);
    Rational b(1, 3);
    a.Add(b);

    std::cout << a.ToString() << " " << b.ToString() << std::endl;
}
