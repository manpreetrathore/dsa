#include<bits/stdc++.h>
using namespace std;
const int MOD=1e3+2,N=1e3+4;
vector<int> a;
int dp[N][N];
int solve(int i,int j)
{
    if(i==j)
    {
        return dp[i][j]=a[i];
    }
    if(i>j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int l = a[i] + min(solve(i+2,j),solve(i+1,j-1));
    //A[i....j], rem coins = A[i+1....j]
    int r = a[j] + min(solve(i,j-2),solve(i+1,j-1));
    //A[i......j], rem coins = A[i........j-1]
    return dp[i][j]=max(l,r);
}

int main()
{
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    a = vector<int>(n);
    for(auto &i:a)
    {
        cin>>i;
    }
    cout<<solve(0,n-1)<<endl;
    return 0;
}