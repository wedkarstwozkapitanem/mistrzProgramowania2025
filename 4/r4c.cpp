/*
*    nazwa: Dylatacja++
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n == 1) {
        int p;
        std::cin >> p;
        int tmp;
        if (p == 1) {
            std::cin >> tmp;
            if(tmp==1) std::cout << "0 0";
            else std::cout << "1 1";
            return 0;
        }
        
        for (int i = 0; i < p; i++) {
            std::cin >> tmp;
            if (tmp > 1) {
                std::cout << "0 1\n";
                return 0;
            }
        }
        std::cout << "0 0\n";
        return 0;
    }
    

    int p;
    std::cin >> p;
    int maxDlugosc = 0;
    
    bool takieSame{true};
    int ostatnia{};
    bool sameJedynki{true};

    bool pwiekszeodjeden = p <= 1;

    std::unordered_map<int,int> krance;

    for (int i = 0; i < p; i++) {
        int tmp{};
        std::cin >> tmp;
        maxDlugosc += tmp;
        ++krance[maxDlugosc];
        if(i==0) ostatnia = tmp;
        else if(takieSame && ostatnia == tmp) ostatnia = tmp;
        else takieSame = false;
        if(tmp > 1) sameJedynki = false;
    }
    
    
    

    int koniec = 0;
   
    
    for (int i = 1; i < n; i++) {
        std::cin >> p;
        koniec = 0;
        if(p>1) pwiekszeodjeden = false;
        
        for (int j = 1; j <= p; j++) {
            int dl;
            std::cin >> dl;
            koniec += dl;
            if (j != p) krance[koniec]++;

            if(dl > 1) sameJedynki = false;
            if(takieSame && ostatnia == dl) ostatnia = dl;
            else takieSame = false;
        }
    }
    

    if(sameJedynki){
        std::cout << "0 0\n";
        return 0;
    }

    if(takieSame) {
        if(!pwiekszeodjeden) std::cout << 0 << ' ' << n << '\n';
        else std::cout << n << ' ' << n << '\n';
        return 0;
    }
    

    int minPaneli = n;
    int maxPaneli = 0;
    
    for (int i = 1; i < maxDlugosc; i++) {
        int roznice = n - krance[i];
        minPaneli = std::min(minPaneli, roznice);
        maxPaneli = std::max(maxPaneli, roznice);
    }
    
    std::cout << minPaneli << ' ' << maxPaneli << '\n';
    return 0;
}