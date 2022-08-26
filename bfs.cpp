#include <bits/stdc++.h>
using namespace std;

void sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
    }
    
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty()) {
        int f = q.front();
        visited[f] = true;
        cout << f << " ";
        for(int j: graph[f]) {
            if(!visited[j]) {
                q.push(j);
                visited[j] = true;
            }
        }
        q.pop();
    }
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
