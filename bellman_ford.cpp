#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5+6;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
        // edges[v].push_back(u,w);
    }
    int src;
    cin>>src;
    vector<int> dist(n,INF);
    dist[src] = 0;
    for(int j=0;j<n-1;j++)
    {
        for(auto e:edges)
        {
            int u=e[0];
            int v=e[1];
            int w = e[2];
            dist[v] = min(dist[v],w+dist[u]);

        }
    }
    for(auto i:dist)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}