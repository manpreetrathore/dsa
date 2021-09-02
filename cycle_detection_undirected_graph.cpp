#include <bits/stdc++.h>
using namespace std;

bool isCycle(int src, vector<vector<int>> &adj, vector<bool> visited, int parent)
{
    visited[src] = true;
    for (auto i : adj[src])
    {
        if (i != parent)
        {
            if (visited[i])
                return true;
            if (!visited[i] and isCycle(i, adj, visited, src))
                return true;

            
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool cycle = false;
    vector<bool> isVisited(n);
    for (int i = 0; i < n; i++)
    {
        if (!isVisited[i] and isCycle(i, adj, isVisited, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
    {
        cout << " Cycle is present" << endl;
    }
    else
    {
        cout << "No cycle" << endl;
    }
}