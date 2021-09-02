#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int fib[N];
int fibo(int n)
{
    if(n==0||n==1)
    {
        return 0;
    }
    else if(n==2)
    {
        return 1;
    }
    else if(fib[n]!=-1)
    {
        return fib[n]; //Memoization
    }
    return fib[n]=fibo(n-1)+fibo(n-2);
}
int main()
{
    int n;
    cin>>n;
    // for(int i=0;i<N;i++)
    // {
    //     fib[i]=-1;
    // }
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=0;
    dp[2]=1;
    // tabulation dp
    for(int i=3;i<=n;i++)
    {
        
        dp[i] = dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    // cout<<fibo(n)<<endl;
    return 0;
}