/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<limits>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    unsigned long long n;
    std::cin >> n;
    
    std::vector<long long> zaszyfrowane(n), klucz(n);
    for(auto &i : zaszyfrowane) std::cin >> i;
    for(auto &i : klucz) std::cin >> i;

    std::unordered_set<long long> odwiedzone;
    
    for(auto i = 0; i < n; ++i) {
        long long min_wartosc = std::numeric_limits<long long>::max();
        long long najlepszy_klucz = -1;
        
        for(auto j = 0; j < n; ++j) {
            if(odwiedzone.find(j) != odwiedzone.end()) continue;
            
            long long aktualny = zaszyfrowane[i] ^ klucz[j];
            if(aktualny < min_wartosc) {
                min_wartosc = aktualny;
                najlepszy_klucz = j;
            }
        }
        
        zaszyfrowane[i] = min_wartosc;
        odwiedzone.insert(najlepszy_klucz);
    }

    for(const auto &i : zaszyfrowane) std::cout << i << ' ';
    
    return 0;
}