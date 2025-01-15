/*
*    nazwa: Pomiary
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<long long> sumaWagonow(n - 1), wagiWagonow(n);

    wagiWagonow[0] = sumaWagonow[0];
    for (int i = 0; i < n - 1; ++i) {
        std::cin >> sumaWagonow[i];
        if(i==0) wagiWagonow[0] = sumaWagonow[0];
        wagiWagonow[i + 1] = sumaWagonow[i] - wagiWagonow[i];
        if (wagiWagonow[i + 1] < 0) { 
            std::cout << "Nie\n";
            return 0;
        }
    }

    std::cout << "Tak\n";
    for (const auto& i : wagiWagonow) std::cout << i << " ";
    
    std::cout << "\n";

    return 0;
}
