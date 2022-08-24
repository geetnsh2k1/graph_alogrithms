#include <bits/stdc++.h>
using namespace std;

vector<int> sol(int n, vector<vector<int>> &edges, int i=0) {
    vector<vector<pair<int, int>>> graph(n);
    vector<int> distance(n, INT_MAX);
    vector<bool> visited(n, false);
    
    distance[i] = 0;
    
    for(auto edge: edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    for(int i=0; i<n-1; i++) {
        int index=-1;
        for(int j=0; j<n; j++) {
            if(!visited[j] && (index==-1 || distance[j]<distance[index])) {
                index = j;
            }
        }
        visited[index] = true;
        for(pair<int, int> j: graph[index]) {
            distance[j.first] = min(distance[j.first], distance[index]+j.second);
        }
    }
    return distance;
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
    vector<int> res = sol(v, edges);
    for(int i: res) cout << i << " ";
    return 0;
}
