#include <bits/stdc++.h>
using namespace std;

int sol(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> graph(n);
    
    for(auto edge: edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        graph[edge[1]].push_back({edge[0], edge[2]});
    }
    
    vector<bool> visited(n, false);
    vector<int> distance(n, INT_MAX);
    vector<int> parent(n, -1);
    
    distance[0] = 0;
    int res = 0;
    
    for(int i=0; i<n; i++) {
        int index = -1;
        for(int j=0; j<n; j++) {
            if(!visited[j] && (index==-1 || distance[j] < distance[index])) index = j;
        }
        visited[index] = true;
        res += distance[index];
        for(pair<int, int> j: graph[index]) {
            if(!visited[j.first] && distance[j.first] > j.second) {
                distance[j.first] = j.second;   
                parent[j.first] = index;
            }
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
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    cout << sol(v, edges);
    return 0;
}
