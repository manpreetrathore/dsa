#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+2;
vector<int> adjace[N];
#define vvi vector<vector<int>>
#define vi vector<int>
#define rep(i,a,b) for(int i=a,i<b;i++)
int main(){
    int n,m;
    cin>>n>>m;
    vvi adj(n+1,vi(n+1,0));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    if(adj[3][7]==1){
        cout<<"there's an edge."<<endl;
    }
    else{
        cout<<"No edge."<<endl;
    }


    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adjace[x].push_back(y);
        adjace[y].push_back(x);
    }
    cout<<"Adjacency List"<<endl;
    for(int i=1;i<n+1;i++){
        cout<<i<<" -> ";
        vector<int> :: iterator it;
        for(it=adjace[i].begin();it!=adjace[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    return 0;
}