#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;

int main()
{
    queue<int> q;
    int ladders,snakes;
    cin>>ladders;
    map<int,int> lad;
    map<int,int> snak;
    for(int i=0;i<ladders;i++)
    {
        int u,v;
        cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0;i<snakes;i++)
    {
        int u,v;
        cin>>u>>v;
        snak[u] = v;
    }
    int moves = 0;
    q.push(1);
    moves++;
    bool found = false;
    vector<int> vis(101,0);
    vis[1]=1;
    while(!q.empty() and !found)
    {
        int sz = q.size();
        while(sz--)
        {
            int t= q.front();
            q.pop();
            for(int d = 1;d<=6;d++)
            {
                if(t+d==100)
                {
                    found = true;
                }
                if(t+d<=100 and lad[t+d] and !vis[lad[t+d]])
                {
                    vis[lad[t+d]] = 1;
                    if(lad[t+d]==100)
                    {
                        found = true;
                    }
                    q.push(lad[t+d]);
                }
                else if(t+d<=100 and snak[t+d] and !vis[snak[t+d]])
                {
                    vis[snak[t+d]] = 1;
                    if(snak[t+d]==100)
                    {
                        found = true;
                    }
                    q.push(snak[t+d]);
                }
                else if(t+d<=100 and !vis[t+d] and !snak[t+d] and !lad[t+d])
                {
                    vis[t+d]=1;
                    q.push(t+d);
                }
            }
        }
        moves++;
        
    }
    if(found)
    {
        cout<<moves;
    }
    else{
        cout<<-1;
    }

    return 0;
}