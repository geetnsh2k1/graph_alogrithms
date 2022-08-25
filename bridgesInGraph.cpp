#include <bits/stdc++.h>
using namespace std;

int timer = 0;
int res = 0;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &low, vector<int> &disc, int i, int p=-1) {
    visited[i] = true;
    disc[i] = low[i] = timer++;
    
    for(int j: graph[i]) {
        if(j == p) continue;
        if(visited[j]) {
            low[i] = min(low[i], disc[j]);
        } else {
            dfs(graph, visited, low, disc, j, i);
            low[i] = min(low[i], low[j]);
            if(low[j] > disc[i]) {
                cout << i << "  " << j << endl;
                res += 1;
            }
        }
    }
    
}

int sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<bool> visited(n, false);
    vector<int> low(n, -1);
    vector<int> disc(n, -1);
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(graph, visited, low, disc, i);
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
