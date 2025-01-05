/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/


#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include<algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long n;
    std::cin >> n;

    bool mniejszeod3{true};
    std::vector<long long> zaszyfrowane(n), klucz(n);
    for (auto &i : zaszyfrowane) {
        std::cin >> i;
        if(i>3) mniejszeod3 = false; 
    }
    for (auto &i : klucz) {
        std::cin >> i;
        if(i>3) mniejszeod3 = false;
    }

    if (mniejszeod3) {
        std::unordered_map<short, long long> liczbaKlucza;
        for (const auto &k : klucz) ++liczbaKlucza[k];

        for (int i = 0; i < n; ++i) {
            long long minxor = std::numeric_limits<long long>::max();
            short minklucz = 0;
            
            for (short j = 0; j <= 3; ++j) {
                if (liczbaKlucza[j] > 0) {
                    long long aktualnyXor = zaszyfrowane[i] ^ j;
                    if (aktualnyXor < minxor) {
                        minxor = aktualnyXor;
                        minklucz = j;
                    }
                }
            }
            
            std::cout << minxor << ' ';
            --liczbaKlucza[minklucz];
        }

        return 0;
    }

    std::set<long long> dostepne_klucze;
    for (auto i = 0; i < n; ++i) dostepne_klucze.insert(i);

    for (auto &i : zaszyfrowane) {
        long long min_wartosc = std::numeric_limits<long long>::max();
        long long najlepszy_klucz = -1;

        for (const auto &j : dostepne_klucze) {
            long long aktualny = i ^ klucz[j];
            if (aktualny < min_wartosc) {
                min_wartosc = aktualny;
                najlepszy_klucz = j;
            }
        }

        i = min_wartosc;
        dostepne_klucze.erase(najlepszy_klucz);
    }

    for (const auto &i : zaszyfrowane) std::cout << i << ' ';

    return 0;
}