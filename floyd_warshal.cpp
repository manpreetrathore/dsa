#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5+6;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph = {
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0},

    };
    int s = graph.size();
    vector<vector<int>> dist = graph;
    for(int k=0;k<s;k++)
    {
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<s;j++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    // for(int i=0;i<m;i++)
    // {
    //     int u,v,w;
    //     cin>>u>>v>>w;
    //     edges.push_back({u,v,w});
    //     // edges[v].push_back(u,w);
    // }

    return 0;
}