/*
    nazwa:Woda Czyści
    autor:Dominik Łempicki Kapitan
*/

#include<iostream>

int main() {
    std::ios_base::sync_with_stdio(0),std::cin.tie(0);
    int n;std::cin >> n;
    for(int i{};i<n;++i){
        std::string txt;std::cin>>txt;
        std::cout << txt[0];
    }   
    return EXIT_SUCCESS;
}