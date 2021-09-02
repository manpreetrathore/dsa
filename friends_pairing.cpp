#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+6;
vector<int> dp(N,-1);
int friends(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n]=friends(n-1)+((n-1)*friends(n-2));
}
int main()
{
    int n=3;
    cout<<friends(n)<<endl;  // using recursion and memoization


    // using tabulation
    vector<int> dp1(n+1,0);
    dp1[0]=1;
    dp1[1]=1;
    for(int i=2;i<=n;i++)
    {
        dp1[i] = dp1[i-1]+(i-1)*dp1[i-2];
    }
    cout<<dp1[n]<<endl;
    return 0;
}