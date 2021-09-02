#include <bits/stdc++.h>
using namespace std;
int n,m,k;
vector<int> a,b;
int dp[2005][2005][7];
int solve(int i,int j,int k)
{
    if(i==n || j==m)
    {
        return 0;
    }
    if(dp[i][j][k]!=-1)
    {
        return dp[i][j][k];
    }
    int c1(0),c2(0),c3(0);
    if(a[i]==b[j])
    {
        c1=1+solve(i+1,j+1,k);
    }
    if(k>0){
        c2=1+solve(i+1,j+1,k-1);
    }
    c3= max(solve(i+1,j,k),solve(i,j+1,k));
    return dp[i][j][k]=max({c1,c2,c3});
}

int main()
{
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    a=vector<int>(n);
    b=vector<int>(m);
    for(auto &i:a)
    {
        cin>>i;
    }
    for(auto &i:b)
    {
        cin>>i;
    }
    cout<<solve(0,0,k);
    return 0;
}