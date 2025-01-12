
/*
*    nazwa: Bajtex S.A.
*    autor: Dominik Łempicki Kapitan
*/

#include "fastio.h"
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class PoloczeniaBajtex {
private:
    std::vector<int> rodzice, rangi;
    std::vector<int> czas_polaczenia;
    std::stack<std::pair<int,int>> historia;
    int ilePoloczen{};
    
    int znajdz(int pracownik) {
        if (rodzice[pracownik] == pracownik) 
            return pracownik;
        return rodzice[pracownik] = znajdz(rodzice[pracownik]);
    }


    int znajdz_najwczesniejsze_polaczenie(int v) {
        int wynik = ilePoloczen + 1;
        while (v != rodzice[v]) {
            wynik = std::min(wynik, czas_polaczenia[v]);
            v = rodzice[v];
        }
        return wynik;
    }

    void polacz_z_ranga(int x, int y) {
        int px = znajdz(x);
        int py = znajdz(y);
        
        if (px != py) {
            if (rangi[px] < rangi[py]) std::swap(px, py);
            
            historia.push({py, rodzice[py]});
            rodzice[py] = px;
            czas_polaczenia[py] = ilePoloczen;
            
            if (rangi[px] == rangi[py]) rangi[px]++;
        }
    }

public:
    PoloczeniaBajtex(const int &n) {
        rodzice.resize(n + 1);
        rangi.resize(n + 1, 0);
        czas_polaczenia.resize(n + 1, ilePoloczen + 1);
        for(int i = 0; i <= n; ++i) rodzice[i] = i;
    }

    inline void polocz(const int &pracownikX, const int &pracownikY) {
        ++ilePoloczen;
        polacz_z_ranga(pracownikX, pracownikY);
    }

    inline void cofnij(const int &k) {
        int cofniecia = std::min(k, (int)historia.size());

        for(int i = 0; i < cofniecia; ++i) {
            if(!historia.empty()) {
                auto [wierzcholek, stary_rodzic] = historia.top();
                historia.pop();
                rodzice[wierzcholek] = stary_rodzic;
                czas_polaczenia[wierzcholek] = ilePoloczen + 1;
            }
        }
        ilePoloczen -= k;
    }

    inline void policzIleCofniec(const int skarzepyt, const int doWywalenia) {

        int czas_skarze = znajdz_najwczesniejsze_polaczenie(skarzepyt);
        int czas_dowywalenia = znajdz_najwczesniejsze_polaczenie(doWywalenia);
        

        int najwczesniejsze = std::min(czas_skarze, czas_dowywalenia);
        
        wypisz(ilePoloczen - najwczesniejsze + 1);
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n,m;
    wczytaj_nm(n,m);

    PoloczeniaBajtex firmaBajtex(n);

    for (int i = 0; i < m; ++i) {
        char zapytanie;
        int x,y;
        wczytaj_zapytanie(zapytanie,x,y);

        if(zapytanie == 'P') firmaBajtex.polocz(x,y);
        else if(zapytanie == 'C') firmaBajtex.cofnij(x);
        else if(zapytanie == 'Z') firmaBajtex.policzIleCofniec(x,y);
    }

    return EXIT_SUCCESS;
}