/*
*    nazwa: Prostopadłościan
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

struct kratka {
    char pole{'-'};
    bool czyOdwiedzone[3] = {false,false,false};
};

struct p {
    int x{},y{};
};

struct doOdwiedzeniaPola {
    p pierwsza,druga;  
    int licznikOperacji{0};
    int ktorastrona{0};
};

doOdwiedzeniaPola a;


inline std::pair<int,int> wczytajPlansze(std::vector<std::vector<kratka>> &plansza) {
    int x,y;
    bool czyZnaleziono{false};
    for (int i{1}; i < plansza.size() - 1; ++i) {
        bool czywlini{false};
        for (int j{1}; j < plansza[0].size() - 1; ++j) {
            std::cin >> plansza[i][j].pole;
            if(plansza[i][j].pole=='S') {
                if(!czywlini && !czyZnaleziono) {
                    x = i;
                    y = j;
                    czywlini = true;
                    czyZnaleziono = true;
                    a.pierwsza.x = i;
                    a.pierwsza.y = j;
                    a.ktorastrona = 0;
                } else if(czywlini) {
                    a.druga.x = i;
                    a.druga.y = j;
                    a.ktorastrona = 2;
                }
                else {
                    a.druga.x = i;
                    a.druga.y = j;
                    a.ktorastrona = 1;
                }
            }
        }
    }
    return std::make_pair(x,y);
}

void wyswietl(const std::vector<std::vector<kratka>> &plansza) {
    for (const auto &i : plansza) {
        for (const auto &j : i) std::cout << j.pole;
        std::cout << '\n';
    }

std::cout << '\n';
    for (const auto &i : plansza) {
        for (const auto &j : i) std::cout << j.czyOdwiedzone[0]<< j.czyOdwiedzone[1] << j.czyOdwiedzone[2] << ' ';
        std::cout << '\n';
    }

    std::cout << '\n';
}

inline bool czywplanszy(const doOdwiedzeniaPola &a, const int n, const int m,bool czyJedna = false) {
    if(czyJedna) return (a.pierwsza.x >= 0 && a.pierwsza.y >= 0 && a.pierwsza.x < n && a.pierwsza.y < m);
    return ((a.pierwsza.x >= 0 && a.pierwsza.y >= 0 && a.pierwsza.x < n && a.pierwsza.y < m) && (a.druga.x >= 0 && a.druga.y >= 0 && a.druga.x < n && a.druga.y < m));
}



inline bool czyMoznaStawiac(const std::vector<std::vector<kratka>> &plansza,const doOdwiedzeniaPola &p) {

    if(p.ktorastrona != 0){
    if(plansza[p.pierwsza.x][p.pierwsza.y].pole == '.' && plansza[p.druga.x][p.druga.y].pole == '.') return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == '-' && plansza[p.druga.x][p.druga.y].pole == '.') || (plansza[p.pierwsza.x][p.pierwsza.y].pole == '.' && plansza[p.druga.x][p.druga.y].pole == '-')) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == 'M' && plansza[p.druga.x][p.druga.y].pole == '.') ) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == '.' && plansza[p.druga.x][p.druga.y].pole == 'M')) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == 'S' && plansza[p.druga.x][p.druga.y].pole == '.') ) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == '.' && plansza[p.druga.x][p.druga.y].pole == 'S')) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == 'S' && plansza[p.druga.x][p.druga.y].pole == '-') ) return true;
    if((plansza[p.pierwsza.x][p.pierwsza.y].pole == '-' && plansza[p.druga.x][p.druga.y].pole == 'S')) return true;
    } else {
        if(plansza[p.pierwsza.x][p.pierwsza.y].pole == '.') return true;
        if(plansza[p.pierwsza.x][p.pierwsza.y].pole == 'S') return true;
        if(plansza[p.pierwsza.x][p.pierwsza.y].pole == 'M') return true;
    }
 
    return false;
}

int bfs(std::vector<std::vector<kratka>> &plansza, const int n, const int m, int startX, int startY) {
    std::queue<doOdwiedzeniaPola> doPrzetworzenia;


    doPrzetworzenia.push(a);

    while (!doPrzetworzenia.empty()) {
        const auto aktualny = doPrzetworzenia.front();
        doPrzetworzenia.pop();

        /*
            0 -> z
            1 -> x
            2 -> y
        */

        const int x1 = aktualny.pierwsza.x,y1 = aktualny.pierwsza.y;
        const int x2 = aktualny.druga.x,y2 = aktualny.druga.y;

        if(plansza[x1][y1].czyOdwiedzone[aktualny.ktorastrona]) continue;
        plansza[x1][y1].czyOdwiedzone[aktualny.ktorastrona] = true;


        a = aktualny;
        a.licznikOperacji = aktualny.licznikOperacji + 1; 
       
        switch (aktualny.ktorastrona) {
            case 0://z
                if(plansza[x1][y1].pole == 'M') return aktualny.licznikOperacji;
                a.pierwsza.x = x1 - 2;
                a.druga.x = x1 - 1;
                a.ktorastrona = 1;
                a.druga.y = y1;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.x = x1 + 1;
                a.druga.x = x1 + 2;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.ktorastrona = 2;
                a.pierwsza.x = x1;
                a.druga.x = x1;
                a.pierwsza.y = y1-2;
                a.druga.y = y1-1;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.y = y1+1;
                a.druga.y = y1+2;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);
                
                break;
            case 1://gora
                a.ktorastrona = 0;
                a.pierwsza.x = x1 - 1;
                a.druga.x = x1 - 1;
                if(czywplanszy(a,n,m,1) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.x = x2 + 1;
                a.druga.x = x2 + 1;
                if(czywplanszy(a,n,m,1) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.ktorastrona = 1;
                a.pierwsza.y = y1 +1;
                a.druga.y = y1 + 1;
                a.pierwsza.x = x1;
                a.druga.x = x2;
                              
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.y = y1 - 1;
                a.druga.y = y1 - 1;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);
                break;
            case 2: //prawo
                
                a.ktorastrona = 0;
                a.pierwsza.x = aktualny.pierwsza.x;
                a.druga.x = aktualny.druga.x;
                a.pierwsza.y = y1 - 1;
                a.druga.y = y1 - 1;
                if(czywplanszy(a,n,m,1) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.y = y2 + 1;
                a.druga.y = y2 + 1;
                if(czywplanszy(a,n,m,1) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.ktorastrona = 2;
                a.pierwsza.x = x2 + 1;
                a.druga.x = x2 + 1;
                a.pierwsza.y = y1;
                a.druga.y = y2; 
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                a.pierwsza.x = x1 - 1;
                a.druga.x = x1 - 1;
                if(czywplanszy(a,n,m) && czyMoznaStawiac(plansza,a)) doPrzetworzenia.push(a);

                break;
        };

    }
    

  
    return -1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<kratka>> plansza(n + 2, std::vector<kratka>(m + 2));

    const auto start = wczytajPlansze(plansza);


    std::cout << bfs(plansza, n+2, m+2, start.first, start.second) << '\n';
    //wyswietl(plansza);

    return 0;
}