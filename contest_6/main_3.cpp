#include <iostream>
#include "mz06_4.cpp"

int main() {
    int a,b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;

    Game::Coord<int> rect(a, b);
    Game::Coord<int> fir(c, d);
    Game::Coord<int> sec(e, f);

    std::cout << Game::dist(rect, fir, sec) << std::endl;
}
