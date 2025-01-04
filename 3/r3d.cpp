/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/


#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>
#include <limits>
#include <unordered_set>


inline std::string usunWiodaceZera(const std::string& binarna) {
    size_t pierwszaJedynka = binarna.find_first_not_of('0');
    return (pierwszaJedynka == std::string::npos) ? "0" : binarna.substr(pierwszaJedynka);
}

inline long long obliczXor(long long a, long long b) {
    return a ^ b;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<long long> zaszyfrowane(n), klucz(n);
    
    for (int i = 0; i < n; ++i) std::cin >> zaszyfrowane[i];
    


    for (int i = 0; i < n; ++i) std::cin >> klucz[i];
    

    std::vector<bool> użyteKlucze(n, false);
    std::vector<long long> wynik(n); 


    std::vector<std::pair<long long, int>> sortowaneKlucze;
    for (int i = 0; i < n; ++i) sortowaneKlucze.push_back({klucz[i], i});
    

    std::sort(sortowaneKlucze.begin(), sortowaneKlucze.end());

    for (int i = 0; i < n; ++i) {
        long long najlepszyWynik = std::numeric_limits<long long>::max();
        int najlepszyIndex = -1;

        for (int j = 0; j < n; ++j) {
            if (użyteKlucze[j]) continue; 
            
            long long terazniejszyWynik = obliczXor(zaszyfrowane[i], klucz[j]);
            
            if (terazniejszyWynik < najlepszyWynik) {
                najlepszyWynik = terazniejszyWynik;
                najlepszyIndex = j;
            }
        }
        
        wynik[i] = najlepszyWynik;
        użyteKlucze[najlepszyIndex] = true; 
    }

    for (int i = 0; i < n; ++i) std::cout << wynik[i] << (i < n - 1 ? ' ' : '\n');
    

    return 0;
}
