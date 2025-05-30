#include <bits/stdc++.h>

using namespace std;

int main(){

    int n;
    vector<vector<int>> adjs(n);        // Lista de adyacencia
    vector<bool> visited(n, false);     // Lista de nodos visitados
    vector<int> distances(n, 0);        // Distancia a los nodos

    queue<int> qu;
    vector<int> firsts;                         // Inicializar los elementos por los que empezará la BFS
    for (int i = 0; i < firsts.size(); ++i){
        visited[firsts[i]] = true;
        qu.push(firsts[i]);
    }
    int currsize = qu.size(), currdis = 1, curr = qu.front();

    function<void(vector<int>)> BFS = [&](vector<int> firsts){
        while (currsize){
            while (currsize){
                curr = qu.front();
                for (int i = 0; i < adjs[curr].size(); ++i){
                    if (!visited[adjs[curr][i]]){
                        qu.push(adjs[curr][i]);
                        distances[adjs[curr][i]] = currdis;
                        visited[adjs[curr][i]] = true;
                    }
                }
                --currsize;
                qu.pop();
            }
            currsize = qu.size();
            ++currdis;
        }
    };
}