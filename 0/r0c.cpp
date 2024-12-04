/*
    nazwa:Gra
    autor:Dominik Łempicki Kapitan
*/

#include<iostream>

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    int n;std::cin>>n;
    int p;
    for(int i{};i<n;++i){
        std::cin >> p;
        std::cout << 9-p << std::endl;
    }
    return 0;
}