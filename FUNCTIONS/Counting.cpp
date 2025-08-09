#include <bits/stdc++.h>
using namespace std;

// Time complexity O(log exp)
// Space complexity O(1)
template<typename T>
T FastExp(T base, T exp, T MOD){
    T res = 1;
    base %= MOD;
    while (exp > 0){
        if (exp & 1){
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

// Time complexity O(n)
// Space complexity O(1)
template <typename T>
T Factorial(T n, T MOD) {
    T res = 1;
    for (T i = 2; i <= n; ++i)
        res = (res * i) % MOD;
    return res;
}

// Time complexity O(r)
// Space complexity O(1)
template <typename T>
T Permutation(T n, T r, T MOD) {
    T res = 1;
    for (T i = 0; i < r; ++i)
        res = (res * (n - i)) % MOD;
    return res;
}

// Time complexity O(r + log(MOD))
// Space complexity O(1)
template <typename T>
T Combination(T n, T r, T MOD){
    if (r > n) return 0;
    T p = Permutation(n, r, MOD), q = Factorial(r, MOD);
    return (p * FastExp(q, MOD - 2, MOD)) % MOD;
}