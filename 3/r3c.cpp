/*
*    nazwa: Bajtocja Entertainment
*    autor: Dominik Łempicki Kapitan
*/


#include <iostream>
#include <vector>
#include <cmath>
#include<queue>

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    int n; 
    std::cin >> n;
    if (n < 1) { 
        std::cout << "NIE";
        return 0;
    }

    std::vector<long long> liczby(n);
    long long suma = 0;


    for (int i = 0; i < n; ++i) {
        std::cin >> liczby[i];
        suma += liczby[i];
    }



    std::priority_queue<long long> dzielniki;
   /* for (long long i = 1; i * i <= std::abs(suma); ++i) {
        if (suma % i == 0) {
            dzielniki.push_back(i);
            dzielniki.push_back(-i);
            if (i != suma / i) {
                dzielniki.push_back(suma / i); 
                dzielniki.push_back(-(suma/i));
            }
        }
    }*/

   long long sumaAk{};
   for(const auto &i : liczby) {
        sumaAk += i;
        if(sumaAk != 0 && (suma%sumaAk)==0) {
            dzielniki.push(sumaAk);
            dzielniki.push(-sumaAk);
        }
   }

    dzielniki.push(1);
    dzielniki.push(-1);
    dzielniki.push(suma);
    dzielniki.push(-suma);
    dzielniki.push(0);


    while(!dzielniki.empty()) {
        const long long aktualny = dzielniki.top();
        dzielniki.pop();
        long long sum = 0;
        std::vector<int> wynik;


        for (int i = 0; i < n; ++i) {
            sum += liczby[i];
            if (sum == aktualny) {
                wynik.push_back(i + 1);
                sum = 0; 
            }
        }

        if (sum == 0 && wynik.size() >= 2 && wynik[wynik.size()-1]==n) {
            std::cout << "Tak\n" << wynik.size() << '\n';
            for (int i = 0; i < wynik.size(); ++i) std::cout << wynik[i] << ' ';
            return 0;
        }
    }


    std::cout << "Nie";
    return 0;
}