#include <vector>
#include <array>
#include <complex>

namespace Equations
{
    template <class T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(const std::array<std::complex<T>, 3> &arr)
    {
        std::pair<bool, std::vector<std::complex<T>>> ans = {true, {}};
        if (arr[0] == std::complex<T>() && arr[1] == std::complex<T>() && arr[2] == std::complex<T>()) {
            ans.first = false;
            return ans;
        }
        if (arr[2] == std::complex<T>()) {
            if (arr[1] == std::complex<T>()) {
                return ans;
            }
            ans.second.push_back(-arr[0] / arr[1]);
        } else {
            std::complex<T> dis = sqrt(arr[1] * arr[1] - arr[0] * arr[2] * (T) 4.0);
            std::complex<T> tmp = ((T) 2.0) * arr[2];
            ans.second.push_back((-arr[1] - dis) / tmp);
            ans.second.push_back((-arr[1] + dis) / tmp);
        }
        return ans;
    }
}
