#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){

    random_device rd;

    mt19937 GenInt(rd());
    int random_int = GenInt();  // Generates random int

    mt19937_64 GenLL(rd());
    ll ramdom_ll = GenLL();     // Generates random ll

    int lo_int = 0, hi_int = 100;
    uniform_int_distribution<int> GenIntRange(lo_int, hi_int);
    int random_int_range = GenIntRange(GenInt);     // Generates random int in [lo, hi]

    ll lo_ll = 0LL, hi_ll = 100LL;
    uniform_int_distribution<ll> GenLLRange(lo_ll, hi_ll);
    ll random_ll_range = GenLLRange(GenLL);         // Generates random ll in [lo, hi]
}