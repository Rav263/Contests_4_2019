#include <vector>
#include <utility>
#include <complex>
#include <array>

namespace Equations
{
    template<typename T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(const std::array<std::complex<T>, 3> &args) {
        std::pair<bool, std::vector<std::complex<T>>> result;

        auto null = std::complex<T>();

        if (args[2] == null) {
            if (args[1] == null) {
                if (args[0] == null) {
                    result.first = false;
                    return result;
                }
                result.first = true;
                return result;
            }
            result.first = true;
            result.second.push_back(-args[0] / args[1]);
        } else {
            std::complex<T> discr = sqrt(args[1] * args[1] - args[0] * args[2] * T(4.0));

            std::complex<T> denom = T(2.0) * args[2];

            result.second.push_back((-args[1] - discr) / denom);
            result.second.push_back((-args[1] + discr) / denom);
            result.first = true;
        }

        return result;
    }
}
