#include <iostream>
#include <vector>
#include <cassert>

struct Pracownik {
    long long wydajnosc;
    long long ostatnia_aktualizacja;
    long long suma_produkcji;
    bool aktywny;

    Pracownik(long long wyd = 0) : 
        wydajnosc(wyd), 
        ostatnia_aktualizacja(0), 
        suma_produkcji(0), 
        aktywny(true) {}
};

class LiniaProdukcyjna {
private:
    std::vector<Pracownik> pracownicy;
    
    void aktualizuj_pracownika(int indeks, long long aktualny_czas) {
        if (!pracownicy[indeks].aktywny) return;
        
        long long roznica_czasu = aktualny_czas - pracownicy[indeks].ostatnia_aktualizacja;
        pracownicy[indeks].suma_produkcji += roznica_czasu * pracownicy[indeks].wydajnosc;
        pracownicy[indeks].ostatnia_aktualizacja = aktualny_czas;
    }

public:
    LiniaProdukcyjna(int n, const std::vector<long long>& poczatkowe_wydajnosci) 
        : pracownicy(n) {
        for (int i = 0; i < n; ++i) {
            pracownicy[i] = Pracownik(poczatkowe_wydajnosci[i]);
        }
    }

    void zmien_wydajnosc(int indeks_pracownika, long long nowa_wydajnosc, long long czas) {
        aktualizuj_pracownika(indeks_pracownika, czas);
        pracownicy[indeks_pracownika].wydajnosc = nowa_wydajnosc;
    }

    void zwolnij_pracownika(int indeks_pracownika, long long czas) {
        aktualizuj_pracownika(indeks_pracownika, czas);
        pracownicy[indeks_pracownika].aktywny = false;
    }

    void zatrudnij_pracownika(int indeks_pracownika, long long nowa_wydajnosc, long long czas) {
        pracownicy[indeks_pracownika] = Pracownik(nowa_wydajnosc);
        pracownicy[indeks_pracownika].ostatnia_aktualizacja = czas;
        pracownicy[indeks_pracownika].aktywny = true;
    }

    long long zapytanie_o_przedzial(int poczatek, int koniec, long long czas) {
        long long wynik = 0;
        for (int i = poczatek; i <= koniec; ++i) {
            if (!pracownicy[i].aktywny) continue;
            
            aktualizuj_pracownika(i, czas);
            wynik += pracownicy[i].suma_produkcji;
        }
        return wynik;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long n, q;
    std::cin >> n >> q;

    std::vector<long long> poczatkowe_wydajnosci(n);
    for (int i = 0; i < n; ++i)  std::cin >> poczatkowe_wydajnosci[i];


    LiniaProdukcyjna produkcja(n, poczatkowe_wydajnosci);

    while (q--) {
        char operacja;
        std::cin >> operacja;

        if (operacja == 'V') {
            long long pracownik, wydajnosc, czas;
            std::cin >> pracownik >> wydajnosc >> czas;
            produkcja.zmien_wydajnosc(pracownik - 1, wydajnosc, czas);
        }
        else if (operacja == 'F') {
            long long pracownik, czas;
            std::cin >> pracownik >> czas;
            produkcja.zwolnij_pracownika(pracownik - 1, czas);
        }
        else if (operacja == 'H') {
            long long pracownik, wydajnosc, czas;
            std::cin >> pracownik >> wydajnosc >> czas;
            produkcja.zatrudnij_pracownika(pracownik - 1, wydajnosc, czas);
        }
        else if (operacja == 'Q') {
            long long poczatek, koniec, czas;
            std::cin >> poczatek >> koniec >> czas;
            std::cout << produkcja.zapytanie_o_przedzial(poczatek - 1, koniec - 1, czas) << '\n';
        }
    }

    return 0;
}
