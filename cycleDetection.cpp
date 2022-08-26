#include <bits/stdc++.h>
using namespace std;

bool res = false;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int i, int p=-1) {
    visited[i] = true;
    for(int j: graph[i]) {
        if(j == p) continue;
        if(!visited[j]) dfs(graph, visited, j, i);
        else res = true;
    }
}

bool sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(graph, visited, i);
        }
    }
    return res;
      
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for(int i=0; i<e; i++) {
        int x, y;
        cin >> x >> y;
        edges.push_back({x, y});
    }
    cout << sol(v, edges);
    return 0;
}
