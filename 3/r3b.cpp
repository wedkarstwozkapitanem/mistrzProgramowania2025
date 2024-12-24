/*
*    nazwa: Zamek
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>

int main(){
    std::string txt;std::cin >> txt;

    int p{};
    for(const auto &i : txt) {
        if(i=='?') ++p;
    }

    if(p==1) std::cout << 1;
    else if(p==0) std::cout << 0;
    else std::cout << p * p * p * p;
    return EXIT_SUCCESS;
}