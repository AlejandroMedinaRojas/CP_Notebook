#include <bits/stdc++.h>

using namespace std;

struct DSU {

    vector<int> parents, ranges, connected_component_size;
    int number_connected_components;

    DSU(int n): number_connected_components(n){
        parents.resize(n); ranges.resize(n); connected_component_size.resize(n);
        for (int i = 0; i < n; ++i){
            parents[i] = i;
            ranges[i] = 0;
            connected_component_size[i] = 1;
        }
    }

    void Union(int u, int v){
        int parent1 = Find(u);
        int parent2 = Find(v);
        if (parent1 != parent2){
            --number_connected_components;
            if (ranges[parent1] >= ranges[parent2]){
                parents[parent2] = parent1;
                connected_component_size[parent1] += connected_component_size[parent2];
                if (ranges[parent1] == ranges[parent2]) ++ranges[parent1];
            }
            else {
                parents[parent1] = parent2;
                connected_component_size[parent2] += connected_component_size[parent1];
            }
        }
    }

    int Find(int v){
        if (parents[v] == v) return v;
        else {
            parents[v] = Find(parents[v]);
            return parents[v];
        }
    }
};