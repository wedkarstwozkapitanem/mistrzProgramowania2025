/*
*    nazwa: Gambit wieży
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>
#include<array>

const long long MOD = 10e9 + 7;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n; std::cin >> n;
    std::vector<std::array<bool,3>> wieza(n);
    bool czyNieTrzy{true};
    bool czyJeden{true};
    for(auto &i : wieza) {
        int licznik{};
        for(auto &j : i) {
            std::cin >> j;
            if(j) ++licznik;
        }
        if(licznik>1) czyJeden = false;
        if(licznik == 3) czyNieTrzy = false;
    }    

    /*for(auto &i : wieza) {
        for(auto &j : i) std::cout << j;
        std::cout << '\n';
    } */   

   if(n==2) {
        if(wieza[1][1] && !wieza[1][0] && !wieza[1][2]) std::cout << "B 1\n";
        else if(wieza[1][1] && wieza[1][0] && wieza[1][2]) std::cout << "A 1\n";
        else std::cout << "A 1\n";
        return 0;
   } else if(czyJeden) std::cout << "A 1\n";
   else if(czyNieTrzy) {
        long long ileZBoku{};
        for(int i{1};i<n;++i) {
            if(wieza[i][0] || wieza[i][2]) ++ileZBoku;
        }
        if(ileZBoku % 2) std::cout << "A " << (2 * ileZBoku)%MOD << '\n';
        else std::cout << "B " << (2 * ileZBoku)%MOD << '\n';
   }

    return EXIT_SUCCESS;
}