#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9,N=1e5+6;
int dp[N];
int MinSquare(int n)
{
    if(n==1||n==2||n==3||n==0)
    {
        return n;
    }
    int ans=MOD;
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    for(int i=1;i*i<=n;i++)
    {
        ans = min(ans,1+MinSquare(n-i*i));
    }
    dp[n]=ans;
    return ans;
}

int main()
{
    for(int i=0;i<N;i++)
    {
        dp[i]=-1;
    }
    int n;
    cin>>n;
    // cout<<MinSquare(n)<<endl;
    vector<int> dp(n+1,MOD);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=1;i*i<=n;i++)
    {
        for(int j=1;i*i+j<=n;j++)
        {
            dp[i*i + j] = min(dp[i*i + j],1+dp[j]);

        }
    }
    cout<<dp[n]<<endl;
    return 0;
}