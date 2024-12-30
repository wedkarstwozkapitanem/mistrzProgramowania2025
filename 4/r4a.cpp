/*
*    nazwa: Awantura o bułkę
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>


int main() {
    std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr);
    long long n;std::cin >> n;

    std::cout << (n-600)/2;
    return EXIT_SUCCESS;
}