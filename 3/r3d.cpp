/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <set>
#include <bitset>
#include <unordered_map>

inline std::string usunWiodaceZera(const std::string& binarna) {
    size_t pierwszaJedynka = binarna.find_first_not_of('0');
    return (pierwszaJedynka == std::string::npos) ? "0" : binarna.substr(pierwszaJedynka);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long n;
    std::cin >> n;

    bool mniejszeod3 = true;
    std::vector<long long> zaszyfrowane(n), klucz(n);
    std::vector<std::string> zaszyfrowaneBinarnie(n), kluczBinarnie(n);

    for (size_t i = 0; i < n; ++i) {
        std::cin >> zaszyfrowane[i];
        if (zaszyfrowane[i] > 3) mniejszeod3 = false;
        std::bitset<64> liczbaBinarnie(zaszyfrowane[i]);
        zaszyfrowaneBinarnie[i] = liczbaBinarnie.to_string();
    }

    for (size_t i = 0; i < n; ++i) {
        std::cin >> klucz[i];
        if (klucz[i] > 3) mniejszeod3 = false;
        std::bitset<64> liczbaBinarnie(klucz[i]);
        kluczBinarnie[i] = liczbaBinarnie.to_string();
    }

    if (mniejszeod3) {
        std::unordered_map<short, long long> liczbaKlucza;
        for (const auto& k : klucz) ++liczbaKlucza[k];

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


    std::sort(kluczBinarnie.begin(), kluczBinarnie.end());


    std::multiset<long long> dostepneKlucze;
    for (const auto& bin : kluczBinarnie) {
        dostepneKlucze.insert(std::stoll(bin, nullptr, 2));
    }

    for (size_t i = 0; i < n; ++i) {
        long long minxor = std::numeric_limits<long long>::max();
        long long najlepszyKlucz = -1;

        for (const auto& klucz : dostepneKlucze) {
            long long aktualnyXor = zaszyfrowane[i] ^ klucz;
            if (aktualnyXor < minxor) {
                minxor = aktualnyXor;
                najlepszyKlucz = klucz;
            } else if (aktualnyXor == minxor && klucz < najlepszyKlucz) {
                najlepszyKlucz = klucz;
            }
        }

        dostepneKlucze.erase(dostepneKlucze.find(najlepszyKlucz));
        std::cout << minxor << ' ';
    }

    return 0;
}