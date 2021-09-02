#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
// int dp[N][N];
// int CoinChange(vector<int> &a,int n,int x)
// {
//     if(x==0)
//     {
//         return 1;
//     }
//     if(x<0)
//     {
//         return 0;

//     }
//     if(n<=0)
//     {
//         return 0;
//     }
//     if(dp[n][x]!=-1)
//     {
//         return dp[n][x];
//     }
//     return dp[n][x]=CoinChange(a,n,x-a[n-1])+CoinChange(a,n-1,x);
// }
int main()
{
    // for(int i=0;i<N;i++)
    // {
    //     for(int j=0;j<N;j++){
    //         dp[i][j]= -1;

    //     }
    // }
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x;
    cin>>x;
    // cout<<CoinChange(a,n,x)<<endl;

    // now lets try iterative solution
    vector<vector<int>> dp(n+1,vector<int> (x+1,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<x+1;j++)
        {
            if(j-a[i-1]>=0)
            {
                dp[i][j] += dp[i][j-a[i-1]];
            }
            dp[i][j] += dp[i-1][j];
        }
    }
    cout<<dp[n][x];
    return 0;
}