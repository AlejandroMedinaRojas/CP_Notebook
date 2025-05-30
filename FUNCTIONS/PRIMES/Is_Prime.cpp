#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

// Complejidad temporal √N
bool IsPrime(ull x){
    if (x == 1ULL) return false;
    if (x == 2ULL || x == 3ULL) return true;
    if (x % 2ULL == 0ULL || x % 3ULL == 0ULL) return false;
    for (ull i = 5ULL; i * i <= x; i += 6ULL) {
        if (x % i == 0ULL || x % (i + 2ULL) == 0ULL)
            return false;
    }
    return true;
}