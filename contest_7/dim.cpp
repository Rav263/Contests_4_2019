#include <complex>
#include <vector>
#include <array>

namespace Equations
{
    template <class T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(const std::array<std::complex<T>, 3> &v)
    {
        std::pair<bool, std::vector<std::complex<T>>> res;
        if (v[1] == std::complex<T>() && v[2] == std::complex<T>() && v[0] == std::complex<T>()) {
            res.first = false;
            return res;
        }
        res.first = true;
        if (v[1] == std::complex<T>() && v[2] == std::complex<T>()) {
            return res;
        }
        if (v[2] == std::complex<T>()) {
            res.second.push_back(-v[0] / v[1]);
        } else {
            std::complex<T> sd = sqrt(v[1] * v[1] - v[0] * v[2] * ((T) 4.0));
            res.second.push_back((-v[1] - sd) / (((T) 2.0) * v[2]));
            res.second.push_back((-v[1] + sd) / (((T) 2.0) * v[2]));
        }
        return res;
    }
}
