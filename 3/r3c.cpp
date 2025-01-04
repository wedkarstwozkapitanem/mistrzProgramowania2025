/*
*    nazwa: Bajtocja Entertainmen
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <cmath>
#include<unordered_set>


bool podzielNaKawalki(const long long aktualny,const std::vector<long long> &liczby,const long long j,const long long n) {
    long long sum = 0;
    std::vector<long long> wynik;
    wynik.push_back(j);
    for (auto i = j; i < n; ++i) {
        sum += liczby[i];
        if(sum == 0 && aktualny != 0) {
            if(!wynik.empty()) {
                wynik.pop_back();
                wynik.push_back(i + 1);
            }
        }
        if (sum == aktualny) {
            wynik.push_back(i + 1);
            sum = 0; 
        }
    }

    if (wynik.size() >= 2 && wynik[wynik.size()-1] == n) {
        std::cout << "Tak\n" << wynik.size() << '\n';
        for (const auto &i : wynik) std::cout << i << ' ';
        return true;
    }
    return false;
}

int main() {
    std::ios_base::sync_with_stdio(false), std::cin.tie(nullptr);
    long long n; std::cin >> n;
    if (n < 1) { 
        std::cout << "Nie";
        return 0;
    }

    std::vector<long long> liczby(n);
    long long suma = 0;
    
    for (auto i = 0; i < n; ++i) {
        std::cin >> liczby[i];
        suma += liczby[i];
    }

    

    long long aktualnaSuma{};
    if(suma == 0) {
        std::vector<long long> wynik; 
        for(auto i = 0;i<n;++i) {
            aktualnaSuma += liczby[i];
            if(aktualnaSuma == 0) wynik.push_back(i+1);
        }
        if (wynik.size() >= 2 && wynik[wynik.size()-1] == n) {
            std::cout << "Tak\n" << wynik.size() << '\n';
            for (const auto &i : wynik) std::cout << i << ' ';
            return 0;
        }
        std::cout << "Nie\n";
        return 0;
    }

    std::unordered_set<long long> odwiedzone;
    for(int i{};i<n;++i) {
        aktualnaSuma += liczby[i];
        if(odwiedzone.find(aktualnaSuma) == odwiedzone.end()) {
            if(aktualnaSuma != 0 && suma % aktualnaSuma == 0 && podzielNaKawalki(aktualnaSuma,liczby,i+1,n))  return 0;
            odwiedzone.insert(aktualnaSuma);
        } 
    }
   
    if(podzielNaKawalki(0,liczby,1,n))  return 0;
    std::cout << "Nie\n";

    return 0;
}