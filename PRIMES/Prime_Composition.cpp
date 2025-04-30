#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

map<ull, int> PrimeComposition(ull x){
    map<ull, int> prime_composition;
    while (x % 2ULL == 0ULL){
        ++prime_composition[2ULL];
        x /= 2ULL;
    }
    while (x % 3ULL == 0ULL){
        ++prime_composition[3ULL];
        x /= 3ULL;
    }
    for (ull i = 5ULL; i * i <= x; i += 6ULL){
        while (x % i == 0LL){
            ++prime_composition[i];
            x /= i;
        }
        while (x % (i + 2ULL) == 0ULL){
            ++prime_composition[i];
            x /= i + 2ULL;
        }
    }
    if (x > 1ULL){
        ++prime_composition[x];
    }
    return prime_composition;
}