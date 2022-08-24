#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>> &graph, vector<int> &color, int i) {
    color[i] = 0;
    queue<int> q;
    q.push(i);
    
    while(!q.empty()) {
        int f = q.front();
        for(int j: graph[f]) {
            if(color[j]==-1) {
                color[j] = !color[f];
                q.push(j);
            } else if(color[j]==color[f]) {
                return false;
            }
        }
        q.pop();
    }
    return true;
}

bool isBipartite(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    vector<int> color(n, -1);
    for(int i=0; i<n; i++) {
        if(color[i]==-1) {
            if(!check(graph, color, i)) return false;
        }
    }
    return true;
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
    cout << isBipartite(v, edges);
    return 0;
}
