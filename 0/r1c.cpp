/*
    nazwa: Fufsopalindrom
    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <unordered_map>

bool fufsopalindrom(const std::string& l) {
    std::unordered_map<char, char> zamiana = {
        {'0', '0'}, {'1', '1'}, {'2', '2'}, {'5', '5'}, {'6', '9'}, {'8', '8'}, {'9', '6'}
    };

    int n = l.size();
    for (int i = 0; i < n; ++i) {
        if (zamiana.find(l[i]) == zamiana.end()) return false; 
        if (zamiana[l[i]] != l[n - i - 1])  return false; 
    }
    return true;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;

    std::string liczba;
    std::cin >> liczba;

    std::cout << (fufsopalindrom(liczba) ? "TAK" : "NIE");
    return EXIT_SUCCESS;
}
