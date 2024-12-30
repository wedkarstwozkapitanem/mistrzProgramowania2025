/*
*    nazwa: Puk
*    autor: Dominik Łempicki Kapitan
*/

#include<iostream>
#include<vector>

long long ciogHofstadtera(const long long n){
    if(n<=0) return 0; if(n<=2) return 1;
    //return ciogHofstadtera(n - ciogHofstadtera(n-1)) + ciogHofstadtera(n-ciogHofstadtera(n-2));
    std::vector<long long> wartosci(n+1);

    wartosci[1] = 1;
    wartosci[2] = 1;
    for(int i{3};i<=n;++i) wartosci[i] = wartosci[i-wartosci[i-1]] + wartosci[i-wartosci[i-2]];
    return wartosci[n];
}


int main() {
    std::ios_base::sync_with_stdio(false),std::cin.tie(nullptr);
    long long n;std::cin >> n;
    std::cout << ciogHofstadtera(n);
    return EXIT_SUCCESS;
}