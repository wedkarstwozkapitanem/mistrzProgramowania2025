/*
*    nazwa: Atak
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>


inline bool czyWyjdziePozaPlansze(const int a, const int b) {
    return (a < 0 || a >= 8 || b < 1 || b > 8);
}

inline int ileRuchowSkoczka(const char wx, const int wy) {
    const int x = (wx - 'a');
    int licznik = 0;

    std::vector<std::pair<int, int>> kierunki = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},{1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (const auto &i : kierunki) {
        int nowyX = x + i.first;
        int nowyY = wy + i.second;
        if (!czyWyjdziePozaPlansze(nowyX, nowyY))  ++licznik;
    }

    return licznik;
}

int main() {
    char x;int y;
    std::cin >> x >> y;
    std::cout << ileRuchowSkoczka(x, y) << '\n';
    return EXIT_SUCCESS;
}
