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

        int wynik{};
 
        int i{};
        while (i + 1 < liczba.size() && liczba[i] == liczba[i+1]) ++i;
        
        
        int a = liczba[i] - '0';
        int b = liczba[i+1] - '0';

        if(a >= b)  wynik = a;
        else wynik = a + 1;


        if(wynik < 10) liczba = std::string(liczba.size(),char(wynik + '0'));
        else {
            wynik = 1;
            liczba = std::string(liczba.size()+1,1);
        }
        std::cout << liczba << '\n';
    }

    return EXIT_SUCCESS;
}