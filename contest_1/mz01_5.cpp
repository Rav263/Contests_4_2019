#include <string>



class Rational 
{
    int a, b;

public:
    int gcd_1(int a, int b) {
        if (b) {
            return gcd_1(b, a % b);
        }
        return a;
    }

    void min() {
        int gc = gcd_1(this->a, this->b);
        if (gc > 0) {
            this->a /= gc;
            this->b /= gc;
        }

        if (this->a < 0 && this->b < 0) {
            this->a *= -1;
            this->b *= -1;
        }
    }


    Rational(int a = 0, int b = 1) : a(a), b(b) {
        min();
    }

    std::string ToString() const {
        std::string now = std::to_string(this->a) + ":" + std::to_string(this->b);
        return now;
    }

    Rational & Add(const Rational &a) {
        this->a = this->a * a.b + a.a * this->b;
        this->b *= a.b;
        min();
        
        return *this;
    }

    Rational & Multiply(const Rational &a) {
        this->a *= a.a;
        this->b *= a.b;
        min();

        return *this;
    }

    Rational & Substract(const Rational &a) {
        this->a = this->a * a.b - a.a * this->b;
        this->b *= a.b;
        
        min();

        return *this;
    }

    bool EqualTo(const Rational &a) const {
        return this->a == a.a && this->b == a.b;
    }

    int CompareTo(const Rational &a) const {
        int tmp_1 = this->a * a.b;
        int tmp_2 = this->b * a.a;

        return tmp_1 - tmp_2;
    }

    bool IsInteger(void) const {
        return b == 1;
    }

    Rational & Divide(const Rational &a) {
        int tmp_1 = this->a * a.b;
        int tmp_2 = this->b * a.a;
        
        this->a = tmp_1;
        this->b = tmp_2;

        min();

        return *this;
    }
};
