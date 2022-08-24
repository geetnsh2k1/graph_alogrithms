#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> sol(int n, vector<vector<int>> &edges) {
    vector<vector<pair<int, int>>> graph(n);
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX/2));
    for(int i=0; i<n; i++) distance[i][i] = 0;
    
    for(auto edge: edges) {
        graph[edge[0]].push_back({edge[1], edge[2]});
        distance[edge[0]][edge[1]] = edge[2];
    }
    
    for(int i=0; i<n; i++) {
        
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(j == i || k == i) continue;
                distance[j][k] = min(distance[j][k], distance[j][i]+distance[i][k]);
            }
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
    sol(v, edges);
    return 0;
}
