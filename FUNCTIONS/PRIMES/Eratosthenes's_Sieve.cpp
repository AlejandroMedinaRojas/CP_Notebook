#include <bits/stdc++.h>

using namespace std;

vector<int> CribaEratostenes(int n){
    vector<bool> criba_de_eratostenes(n + 1, true);
    vector<int> primes;
    criba_de_eratostenes[0] = criba_de_eratostenes[1] = false;
    for (int i = 2; i * i <= n; ++i){
        if (criba_de_eratostenes[i]){
            for (int j = i * i; j <= n; j += i){
                criba_de_eratostenes[j] = false;
            }
            primes.push_back(i);
        }
    }
    return primes;
}