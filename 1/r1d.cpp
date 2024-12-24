/*
 *    nazwa: Dzieło Bajtycha
 *    autor: Dominik Łempicki Kapitan
 */

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

void DFS(const long long aktualny, const std::vector<std::vector<long long>> &drzewo, const std::vector<long long> &wartosci, const int k, std::vector<std::pair<std::priority_queue<long long>, long long>> &mozliweZbiory, long long id)
{
    long long suma{};
    int p{};
    std::priority_queue<long long> mozliwyZbior;
    for (const auto &i : drzewo[aktualny])
    {
        suma += wartosci[i];
        if (p++ < k)
        {
            mozliwyZbior.push(wartosci[i]);
            mozliweZbiory.resize(mozliweZbiory.size() + 1);
            mozliweZbiory[mozliweZbiory.size() - 1].first = mozliwyZbior;
            mozliweZbiory[mozliweZbiory.size() - 1].second = id;
        }
        if (i != aktualny)
            DFS(i, drzewo, wartosci, k, mozliweZbiory, id);
    }
}



long long znajdzMaksSume(const std::vector<std::vector<long long>>& wartosciNaWezlach, int k) {
    long long maksSuma = -1;

    for(int i{};i<wartosciNaWezlach.size();++i) {
        for(int j{};j<wartosciNaWezlach[i].size();++j) std::cout << wartosciNaWezlach[i][j] << ' ';
        std::cout << '\n';   
    }

    return maksSuma;
}


int main()
{
    std::ios_base::sync_with_stdio(0), std::cin.tie(0);
    int n, k;
    std::cin >> n >> k;
    std::vector<long long> wartosci(n);
    for (int i{}; i < n; ++i)
        std::cin >> wartosci[i];

    std::vector<std::vector<long long>> drzewo(n);

    if(wartosci.size()==1 && k==1) {
        std::cout << wartosci[0];
        return EXIT_SUCCESS;
    } else if(wartosci.size()==2 && k==1){
        std::cout << std::max(wartosci[0],wartosci[1]);
        return EXIT_SUCCESS;
    } else if(k==1) {
        std::cout << -1;
        return EXIT_SUCCESS;
    }

    for (int i{1}; i < n; ++i)
    {
        long long tmp;
        std::cin >> tmp;
        drzewo[tmp - 1].push_back(i);
    }

    for (int i{}; i < drzewo.size(); ++i)
    {
        std::sort(drzewo[i].begin(), drzewo[i].end(), [&](const auto a, const auto b)
                  { return wartosci[a] > wartosci[b]; });
    }

    std::vector<std::pair<std::priority_queue<long long>, long long>> mozliweZbiory(k);

    std::vector<std::vector<long long>> wartoscinakwezlach;

    int licznikPodDrzew{};
    for (const auto &i : drzewo[0])
    {
        mozliweZbiory.resize(mozliweZbiory.size() + 1);
        mozliweZbiory[mozliweZbiory.size() - 1].first.push(wartosci[i]);

        wartoscinakwezlach.resize(wartoscinakwezlach.size() + 1);
        wartoscinakwezlach[wartoscinakwezlach.size() - 1].resize(k + 1,-1);

        wartoscinakwezlach[licznikPodDrzew][1] = std::max(wartoscinakwezlach[licznikPodDrzew][1], wartosci[i]);
        DFS(i, drzewo, wartosci, k, mozliweZbiory, i);

        for (auto &ip : mozliweZbiory)
        {
            long long suma{}, licznik{1};
            while (!ip.first.empty())
            {
                suma += ip.first.top();
                ip.first.pop();
                wartoscinakwezlach[licznikPodDrzew][licznik] = std::max(wartoscinakwezlach[licznikPodDrzew][licznik], suma);

                ++licznik;
            }
        }
        mozliweZbiory.clear();
        ++licznikPodDrzew;
    }


    long long maksSuma{-1};
    for(int i{};i<wartoscinakwezlach.size();++i){
        for(int j{};j<wartoscinakwezlach[i].size();++j){
            //std::cout << wartoscinakwezlach[i][j] << ' ';
            if(wartoscinakwezlach[i][j]==-1) continue;
            if(j==k) maksSuma = std::max(maksSuma,wartoscinakwezlach[i][j]);
            else {
                for(int p{};p<wartoscinakwezlach.size();++p) {
                    if(wartoscinakwezlach[p][k-j]==-1) continue;
                    if(p!=i) maksSuma = std::max(maksSuma,wartoscinakwezlach[i][j] + wartoscinakwezlach[p][k-j]);
                }
            }
        }
    }


    std::cout << maksSuma;
    return EXIT_SUCCESS;
}