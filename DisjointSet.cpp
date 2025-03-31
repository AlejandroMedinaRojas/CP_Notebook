struct DSU {

    vector<pair<int,int>> d;
    set<int> connected_components;

    DSU(int n) {
        d.resize(n);
        for (int i = 0; i < n; ++i){
            d[i].first = i;
            d[i].second = 1;
        }
    }

    void Union(int u, int v){
        int parent1 = Find(u);
        int parent2 = Find(v);
        if (parent1 != parent2){
            if (d[parent1].second > d[parent2].second){
                d[parent2].first = parent1;
            }
            else if (d[parent1].second < d[parent2].second){
                d[parent1].first = parent2;
            }
            else {
                d[parent2].first = parent1;
                ++d[parent1].second;
            }
        }
    }

    int Find(int v){
        if (d[v].first == v){
            return v;
        }
        else {
            d[v].first = Find(d[v].first);
            return d[v].first;
        }
    }

    int NumCC(){
        connected_components.clear();
        for (int i = 0; i < d.size(); ++i){
            connected_components.insert(Find(d[i].first));
        }
        return connected_components.size();
    }
};
