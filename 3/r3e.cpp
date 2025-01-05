/*
*    nazwa: Szyfr
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <limits>
#include <bitset>

class DrzewoTrie {
public:
    struct Węzeł {
        Węzeł* dzieci[2] = {nullptr, nullptr};
        int liczba = 0;
    };

    DrzewoTrie() : korzeń(new Węzeł()) {}

    void wstaw(long long liczba) {
        Węzeł* obecny = korzeń;
        for (int i = 63; i >= 0; --i) {
            int bit = (liczba >> i) & 1;
            if (!obecny->dzieci[bit]) {
                obecny->dzieci[bit] = new Węzeł();
            }
            obecny = obecny->dzieci[bit];
            obecny->liczba++;
        }
    }

    void usuń(long long liczba) {
        Węzeł* obecny = korzeń;
        for (int i = 63; i >= 0; --i) {
            int bit = (liczba >> i) & 1;
            obecny = obecny->dzieci[bit];
            obecny->liczba--;
        }
    }

    long long znajdźMinimalnyXOR(long long liczba) {
        Węzeł* obecny = korzeń;
        long long wynik = 0;
        for (int i = 63; i >= 0; --i) {
            int bit = (liczba >> i) & 1;
            if (obecny->dzieci[bit] && obecny->dzieci[bit]->liczba > 0) {
                obecny = obecny->dzieci[bit];
            } else {
                wynik |= (1LL << i);
                obecny = obecny->dzieci[1 - bit];
            }
        }
        return wynik;
    }

private:
    Węzeł* korzeń;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long long n;
    std::cin >> n;

    std::vector<long long> zaszyfrowane(n), klucz(n);
    for (size_t i = 0; i < n; ++i)  std::cin >> zaszyfrowane[i];
    

    for (size_t i = 0; i < n; ++i) std::cin >> klucz[i];
    
    DrzewoTrie trie;
    for (const auto& k : klucz) trie.wstaw(k);

    for (const auto& z : zaszyfrowane) {
        long long minxor = trie.znajdźMinimalnyXOR(z);
        trie.usuń(z ^ minxor);
        std::cout << minxor << ' ';
    }

    return 0;
}
