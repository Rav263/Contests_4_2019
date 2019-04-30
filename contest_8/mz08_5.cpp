#include <iostream>

int main(void)
{
    int l1, h1, l2, h2;
    std::cin >> l1 >> h1 >> l2 >> h2;
    int l3 = (l1 < l2) ? l2 : l1;
    int h3 = (h1 < h2) ? h1 : h2;
    if (h3 <= l3) {
        std::cout << "0 0" << std::endl;
    } else {
        std::cout << l3 << ' ' << h3 << std::endl;
    }
    return 0;
}
