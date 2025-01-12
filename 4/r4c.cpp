/*
*    nazwa: Dylatacja++
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
    std::vector<int> pierwszyWiersz(p);
    int maxDlugosc = 0;
    
    for (int i = 0; i < p; i++) {
        std::cin >> pierwszyWiersz[i];
        maxDlugosc += pierwszyWiersz[i];
    }
    
    std::vector<int> krance(maxDlugosc + 1, 0);
    

    int koniec = 0;
    for (int j = 0; j < p-1; j++) {
        koniec += pierwszyWiersz[j];
        krance[koniec]++;
    }
    

    for (int i = 1; i < n; i++) {
        std::cin >> p;
        koniec = 0;
        
        for (int j = 1; j <= p; j++) {
            int dl;
            std::cin >> dl;
            koniec += dl;
            if (j != p) krance[koniec]++;
        }
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