/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>

int main() {
    std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr);
    int n;std::cin >> n;
    std::vector<long long> zaszyfrowane(n),klucz(n);
    for(auto &i : zaszyfrowane) std::cin >> i;
    for(auto &i : klucz) std::cin >> i;
    std::sort(klucz.begin(),klucz.end());
    std::vector<long long> wynik(n,std::numeric_limits<long long>::max()), aktualnawiadomosc(n);
    do {
        for(int i{};i<n;++i)aktualnawiadomosc[i] = zaszyfrowane[i] ^ klucz[i];
        if(aktualnawiadomosc < wynik) wynik = aktualnawiadomosc;
    } while (std::next_permutation(klucz.begin(),klucz.end()));

    for(const auto &i : wynik) std::cout << i << ' ';
    
    return EXIT_SUCCESS;
}