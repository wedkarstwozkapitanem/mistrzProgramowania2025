/*
*    nazwa: Jubileusz
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>



int main() {
    long long n;std::cin >> n;

    long long p{1};
    while(p<n) p*=2;
    std::cout << p - n;

    return EXIT_SUCCESS;
}