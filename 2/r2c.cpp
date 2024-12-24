/*
*    nazwa: Stos Kamieni
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    int n;std::cin>>n;
    std::vector<long long> kamienie(n);
    for(auto &i : kamienie) std::cin >> i;
    std::sort(kamienie.begin(),kamienie.end(),[&](const auto &a,const auto &b){
        return a<b;
    });


    long long maksDoUlorzenia{1},tmpMaks{1};
    for(int i{0};i<n;++i) {
        if(kamienie[i] == kamienie[i+1]-1) ++tmpMaks;
        else if(kamienie[i] != kamienie[i+1]) {
            maksDoUlorzenia = std::max(maksDoUlorzenia,tmpMaks);
            tmpMaks = 1;
        }
    }

    maksDoUlorzenia = std::max(maksDoUlorzenia,tmpMaks);
    std::cout << maksDoUlorzenia;

    
    return EXIT_SUCCESS;
}