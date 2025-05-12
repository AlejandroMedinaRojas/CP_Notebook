#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> graph(n);
vector<bool> visited(n, false);
vector<int> distances(n, 0);

vector<int> BFS(vector<int> firsts){
    queue<int> qu;
    for (int i = 0; i < firsts.size(); ++i){
        visited[firsts[i]] = true;
        qu.push(firsts[i]);
    }
    int currsize = qu.size(), currdis = 1, curr = qu.front();
    while (currsize){
        while (currsize){
            curr = qu.front();
            for (int i = 0; i < graph[curr].size(); ++i){
                if (!visited[graph[curr][i]]){
                    qu.push(graph[curr][i]);
                    distances[graph[curr][i]] = currdis;
                    visited[graph[curr][i]] = true;
                }
            }
            --currsize;
            qu.pop();
        }
        currsize = qu.size();
        ++currdis;
    }
}