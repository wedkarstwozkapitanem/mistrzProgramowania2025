/*
    nazwa:Mistrzostwa w brydża dla olimpijczyków
    autor:Dominik Łempicki Kapitan
*/

#include <iostream>
#include <map>

int main()
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    short n;
    std::cin >> n;
    if (n != 13)
    {
        std::cout << "OSZUST!";
        return 0;
    }

    std::map<char, short> wartosci = {{'J', 1}, {'Q', 2}, {'K', 3}, {'A', 4}};
    std::map<std::string, short> iloscWystopien;
    std::string karta;
    int suma{};
    for (short i{}; i < n; ++i){
        std::cin >> karta;
        if (karta.size() > 2){
            std::cout << "OSZUST!";
            return 0;
        }
        const char kart = karta[0];

        if (wartosci.find(karta[0]) != wartosci.end()) suma += wartosci[kart];
        else if (karta[0] < 48 || karta[0] > 57){
            std::cout << "OSZUST!";
            return 0;
        }

        if (karta.size() == 2) {
            if (karta[1] < 48 || karta[1] > 57) {
                std::cout << "OSZUST!";
                return 0;
        }
    }
    if (iloscWystopien[karta] >= 4) {
        std::cout << "OSZUST!";
        return 0;
    }
    iloscWystopien[karta]++;
}
std::cout << suma;

return 0;
}