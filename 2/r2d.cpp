/*
*    nazwa: Sok z kumkwatu
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <map>
#include<unordered_map>

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);

    long long n, q;
    std::cin >> n >> q;

    if (n <= 0) {std::cerr << -1;return EXIT_FAILURE;}

    std::vector<std::vector<std::map<long long, long long>>> wydajnosci(n, std::vector<std::map<long long, long long>>(1));
    for (auto &i : wydajnosci) std::cin >> i[0][0];
    
    std::unordered_map<long long,int> ilosc_nowych_pracownikow;
    for (auto qi = 0; qi < q; ++qi) {
        char zadanie;
        std::cin >> zadanie;

        if(zadanie!='Q') {
            long long pracownik, wydajnosc, dzien;
            if (zadanie == 'V') { //zmien wydajnosc
                std::cin >> pracownik >> wydajnosc >> dzien;
                --pracownik;
                wydajnosci[pracownik][ilosc_nowych_pracownikow[pracownik]][dzien] = wydajnosc;
            } else if (zadanie == 'F') { //zwolinij
                std::cin >> pracownik >> dzien;
                //wydajnosci[pracownik-1].clear();
                ++ilosc_nowych_pracownikow[--pracownik];
                wydajnosci[pracownik].resize(ilosc_nowych_pracownikow[pracownik]+1);
            } else if (zadanie == 'H') { //zatrudnij
                std::cin >> pracownik >> wydajnosc >> dzien;
                --pracownik;
                wydajnosci[pracownik][ilosc_nowych_pracownikow[pracownik]][dzien] = wydajnosc;
            }
        } else {//zapytanie
            long long i,j,dzien,wynik{};std::cin >> i >> j >> dzien;
            for (auto pi = i-1; pi < j; ++pi) {
                if (wydajnosci[pi].empty()) continue;
                long long poprzedni_czas{},aktualna_wydajnosc{};
        
                for (const auto &p : wydajnosci[pi][ilosc_nowych_pracownikow[pi]]) {
                    if (p.first > dzien) break;
                    wynik += aktualna_wydajnosc * (p.first - poprzedni_czas);
                    poprzedni_czas = p.first;
                    aktualna_wydajnosc = p.second;
                }
                wynik += aktualna_wydajnosc * (dzien - poprzedni_czas);
            }
            std::cout << wynik << std::endl;
        }
    }


    return EXIT_SUCCESS;
}