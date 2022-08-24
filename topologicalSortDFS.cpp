#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s, int i) {
    if(visited[i]) return;
    visited[i] = true;
    for(int j: graph[i]) {
        if(!visited[j]) dfs(graph, visited, s, j);
    }
    s.push(i);
}

vector<int> sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(!visited[i]) dfs(graph, visited, s, i);
    }
    
    vector<int> res;
    while(!s.empty()) {
        res.push_back(s.top());
        s.pop();
    }
    for(int i: res) cout << i << " ";
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
    sol(v, edges);
    return 0;
}
