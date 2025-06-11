#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

ull FastExp(ull base, ull exponent, ull MOD){
    if (exponent == 0ULL) return 1ULL;
    ull half = FastExp(base, exponent/2ULL, MOD);
    ull result = (half * half) % MOD;
    if (exponent & 1ULL) result = (result * base) % MOD;
    return result;
}