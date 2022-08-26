#include <bits/stdc++.h>
using namespace std;

void build(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &s, int i) {
    visited[i] = true;
    for(int j: graph[i]) {
        if(!visited[j]) build(graph, visited, s, j);
    }
    s.push(i);
}

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int i) {
    visited[i] = true;
    for(int j: graph[i]) {
        if(!visited[j]) dfs(graph, visited, j);
    }
}

int sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    stack<int> s;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++) {
        if(!visited[i]) build(graph, visited, s, i);
    }  
    
    vector<vector<int>> graph2(n);
    for(auto edge: edges) {
        graph2[edge[1]].push_back(edge[0]);
    }
    
    int ct = 0;
    for(int i=0; i<n; i++) visited[i] = false;
    while(!s.empty()) {
        if(!visited[s.top()]) {
            dfs(graph2, visited, s.top());
            ct += 1;
        }
        s.pop();
    }
    return ct;
    
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
