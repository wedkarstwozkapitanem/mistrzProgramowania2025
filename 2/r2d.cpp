/*
*    nazwa: Sok z kumkwatu
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);

    int n, q;
    std::cin >> n >> q;

    if (n <= 0) {
        std::cerr << -1;
        return EXIT_FAILURE;
    }

    std::vector<std::map<int, long long>> wydajnosci(n, std::map<int, long long>());
    for (auto &i : wydajnosci) std::cin >> i[0];
    


    for (int i = 0; i < q; ++i) {
        char zadanie;
        std::cin >> zadanie;

        long long pracownik, wydajnosc, dzien;
        if (zadanie == 'V') { //zmien wydajnosc
            std::cin >> pracownik >> wydajnosc >> dzien;
            wydajnosci[pracownik - 1][dzien] = wydajnosc;

        } else if (zadanie == 'F') { //zwolinij
            std::cin >> pracownik >> dzien;
            wydajnosci[pracownik-1][dzien-1] = 0;
            wydajnosci[pracownik-1].clear();
        } else if (zadanie == 'H') { //zatrudnij
            std::cin >> pracownik >> wydajnosc >> dzien;
            wydajnosci[pracownik-1][dzien] = wydajnosc;

        } else if (zadanie == 'Q') { //odczytaj
            std::cin >> pracownik >> wydajnosc >> dzien;

            long long wynik = 0;
            for (int pi = pracownik-1; pi < wydajnosc; ++pi) {
                if(wydajnosci[pi].size()==1 && wydajnosci[pi][0]) wynik += wydajnosci[pi][0] * dzien;     
                else {
                    long long iloscdni = dzien,poprzedniawartosc{};
                    for(const auto &p : wydajnosci[pi]){
                        if(p.second!=0) wynik += poprzedniawartosc * (p.first);
                        poprzedniawartosc = p.second;
                        iloscdni -= p.first;
                        if(iloscdni <= 0) break;
                    }
                    if(iloscdni > 0) wynik += poprzedniawartosc * iloscdni;
                }
            }

            std::cout << wynik << '\n';
        }
    }


    return EXIT_SUCCESS;
}
