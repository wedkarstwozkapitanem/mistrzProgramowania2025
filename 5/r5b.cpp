/*
*    nazwa: Patrol
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string liczba; std::cin >> liczba;

    if(liczba.size()==1) std::cout << liczba << '\n';
    else {
        int a = liczba[0] - '0';
        int b = liczba[1] - '0';
        int wynik{};
        if(a >= b)  wynik = a;
        else wynik = a + 1;

        if(wynik == 10) wynik = 1; 

        for(unsigned long long i{};i<liczba.size();++i) std::cout << wynik;
    }

    return EXIT_SUCCESS;
}