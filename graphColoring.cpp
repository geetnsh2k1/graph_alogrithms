#include <bits/stdc++.h>
using namespace std;

int sol(int n, vector<vector<int>> &edges) {
    vector<vector<int>> graph(n);
    for(auto edge: edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }
    
    int res = 1;
    vector<int> color(n, -1);
    for(int i=0; i<n; i++) {
        vector<bool> avai(n, true);
        for(int j: graph[i]) {
            if(color[j]!=-1) {
                avai[color[j]] = false;
            }
        }
        
        int j;
        for(j=0; j<n; j++) {
            if(avai[j]) break;
        }
        color[i] = j;
        res = max(res, 1+j);
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
