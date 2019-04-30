#include <stdio.h>
#include <cmath>

namespace numbers {
    class complex {
        double re;
        double im;

    public:
        complex(double re = 0, double im = 0) : re(re), im(im) {}

        explicit complex(const char *num) {
            sscanf(num, "(%lf,%lf)", &re, &im);
        }

        double get_re(void) const {
            return re;
        }

        double get_im(void) const {
            return im;
        }

        double abs(void) const {
            return std::sqrt(re * re + im * im);
        }

        double abs2(void) const{
            return re * re + im * im;
        }

        void to_string(char *buf, size_t size) const {
            snprintf(buf, size, "(%.10g,%.10g)", re, im);
        }

        friend complex operator +(const complex &num_1, const complex &num_2);
        friend complex operator -(const complex &num_1, const complex &num_2);
        friend complex operator *(const complex &num_1, const complex &num_2);
        friend complex operator /(const complex &num_1, const complex &num_2);
        friend complex operator ~(const complex &num_1);
        friend complex operator -(const complex &num_1);
    };
    
    complex operator -(const complex &num_1) {
        return complex(-num_1.re, -num_1.im);
    }
    
    complex operator ~(const complex &num_1) {
        return complex(num_1.re, -num_1.im);
    }

    complex operator +(const complex &num_1, const complex &num_2) {
        return complex(num_1.re + num_2.re, num_1.im + num_2.im);
    }

    complex operator -(const complex &num_1, const complex &num_2) {
        return complex(num_1.re - num_2.re, num_1.im - num_2.im);
    }
 
    complex operator *(const complex &num_1, const complex &num_2) {
        return complex(num_1.re * num_2.re - num_1.im * num_2.im,
                num_1.re * num_2.im + num_2.re * num_1.im);
    }
    complex operator /(const complex &num_1, const complex &num_2) {
        return complex((num_1.re * num_2.re + num_1.im * num_2.im) / num_2.abs2(),
                (num_1.im * num_2.re - num_2.im * num_1.re) / num_2.abs2());
    }
}


