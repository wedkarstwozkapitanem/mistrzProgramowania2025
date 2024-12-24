/*
*    nazwa: Kartograf i kawa
*    autor: Dominik Łempicki Kapitan
*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>

struct d {
    long long b, w, indeks;
    bool operator<(const d &o) const {
        return w > o.w;
    }
};


void pobierz(std::vector<std::map<long long,std::pair<long long,long long>>> &trasy,std::vector<std::pair<long long,bool>> &graf, std::vector<long long> &wynik,const long long m) {
    for (int i = 0; i < m; ++i) {
        long long a, b, c;
        std::cin >> a >> b >> c;
        trasy[a][b] = {c,i};
        if(c!=-1) graf.push_back({i,false});
        else graf.push_back({i,true}); 
        wynik[i] = c; 
    }
}

std::pair<long long, long long> dijkistra(const std::vector<std::map<long long,std::pair<long long,long long>>> &trasy, const long long &n, const long long &m,const long long &t) {
    std::priority_queue<d> q;
    std::vector<long long> odleglosci(n + 1, LLONG_MAX),najkrotszaSciezka(n+1,-1);

    odleglosci[1] = 0;
    q.push({1, 0, 0});

    long long ktorezamazane{-1};

    while (!q.empty()) {
        const long long aktualny = q.top().b,dystans = q.top().w;
        q.pop();

        if (dystans > odleglosci[aktualny]) continue;

        bool czyniewidoczna{false};
        long long ktorezamazanetmp=-1;
        for (const auto &i : trasy[aktualny]) {
            long long nowa_odleglosc = odleglosci[aktualny] + (i.second.first != -1 ? i.second.first : 1);
            if (nowa_odleglosc < odleglosci[i.first]) {
                odleglosci[i.first] = nowa_odleglosc;
                q.push({i.first, nowa_odleglosc, i.second.second});
                najkrotszaSciezka[i.first] = aktualny;
            }
        }
    }

    long long i =  najkrotszaSciezka.size() - 1;
    while (true) {
        const auto szukany = trasy[najkrotszaSciezka[i]].find(i);
        if(szukany != trasy[najkrotszaSciezka[i]].end() && szukany -> second.first == -1) {
            ktorezamazane = szukany -> second.second;
            //break;
        }
        i = najkrotszaSciezka[i];
        if(najkrotszaSciezka[i]==-1) break;
    }
    
    return {odleglosci[n], ktorezamazane};
}

int main() {
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    long long n, m, t;
    std::cin >> n >> m >> t;

    std::vector<std::map<long long,std::pair<long long,long long>>> trasy(n+1);
    std::vector<long long> wynik(m, -1); 
    std::vector<std::pair<long long,bool>> graf;

    pobierz(trasy,graf,wynik,m);
    const long long pt = t;
    const auto odleglosci = dijkistra(trasy, n, m, t);

    t -= odleglosci.first-1;
    if (odleglosci.first == pt) {
        for (int i = 0; i < m; ++i) std::cout << (wynik[i] != -1 ? wynik[i] : 1 )<< '\n';
    } else if (odleglosci.second != -1 && t>=1) {
        for (int i = 0; i < m; ++i) {
            if(graf[i].first == odleglosci.second) std::cout << t << '\n';
            else if(graf[i].second) std::cout << 1 << '\n';
            else std::cout << wynik[i] << '\n';
        }
    } else std::cout << -1 ;

    return EXIT_SUCCESS;
}
