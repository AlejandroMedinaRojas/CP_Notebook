#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> mt, vis;
int timer = 0;

bool Khun(int u){
    if (vis[u] == timer) return false;
    vis[u] = timer;
    for (auto &v: g[u]){
        if (mt[v] == -1 || Khun(mt[v])){
            mt[v] = u;
            return true;
        }
    }
    return false;
}

// Time complexity O(n * m)
// Space complexity O(n)
int MaxMatching(){
    int res = 0;
    fill(mt.begin(), mt.end(), -1);
    for (int u = 0; u < n; ++u){
        ++timer;
        Khun(u);
    }
    for (int u = 0; u < n; ++u){
        if (mt[u] != 1) ++res;
    }
    return res;
}