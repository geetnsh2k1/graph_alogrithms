#include <bits/stdc++.h>
using namespace std;

vector<int> sol(int n, vector<vector<int>> &edges, int i=0) {
    vector<int> distance(n, INT_MAX);
    distance[i] = 0;
    int m = edges.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m; j++) {
            distance[edges[j][1]] = min(distance[edges[j][1]], distance[edges[j][0]]+edges[j][2]);
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
