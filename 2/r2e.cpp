/*
*    nazwa: Park rozrywki
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    int n;std::cin>>n;
    std::vector<long long> wynik(n);

    for(int i{};i<n;++i){
        std::cout << "1 " << (i + 1) << std::endl;
        std::cin >> wynik[i];
    }
    
    std::cout << 3 << ' ';
    for(const auto &i : wynik) std::cout << i << ' ';
    return EXIT_SUCCESS;
}