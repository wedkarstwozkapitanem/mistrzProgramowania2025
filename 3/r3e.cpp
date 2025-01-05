
/*
*    nazwa: Komputer w domu
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long n, m;
    std::cin >> n >> m;
    
    if (n < 1 || n > 20 || m < 0 || m > 20) return 1;
    

    if(n == 1) {
        std::cout << "1\n1\n0\n";
        return 0;
    } else if(n == 2) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << "2\n1\n" << -a << ' ' << b;
        return 0;
    }

    std::vector<std::vector<int>> graf(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        if (u >= 1 && u <= n && v >= 1 && v <= n) graf[u].push_back(v);
    }

    std::cout << n << "\n";

    const int maks_wartosc = 1000000;
    std::vector<std::vector<int>> stany(n + 1, std::vector<int>(n, 0));
    for (int i = 1; i <= n; ++i) {
        stany[i][i - 1] = std::min(i, maks_wartosc);
        for (int j = 0; j < n; ++j) std::cout << stany[i][j] << " ";
        std::cout << "\n";
    }

    std::vector<std::vector<int>> instrukcje;
    for (int u = 1; u <= n; ++u) {
        for (int v : graf[u]) {
            std::vector<int> instrukcja(n);
            for (int i = 0; i < n; ++i) instrukcja[i] = stany[v][i] - stany[u][i];
            instrukcje.push_back(instrukcja);
        }
    }

    if (instrukcje.size() > 60) return 1;

    std::cout << instrukcje.size() << "\n";
    for (const auto& i : instrukcje) {
        for (int j : i) std::cout << j << " ";
        std::cout << "\n";
    }

    return 0;
}