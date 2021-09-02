#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+2;
int dp[N][N];

int knap(vector<int> a,vector<int> w,int n,int wt)
{
    if(wt<=0||n<=0)
    {
        return 0;
    }
    if(dp[n][wt]!=-1)
    {
        return dp[n][wt];
    }
    if(w[n-1]>wt)
    {
        return dp[n][wt]=knap(a,w,n-1,wt);
    }
    return dp[n][wt]=max(knap(a,w,n-1,wt),knap(a,w,n-1,wt-w[n-1])+a[n-1]);
}
int main()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            dp[i][j]= -1;

        }
    }
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> w(n);
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int wt;
    cin>>wt;
    cout<<knap(a,w,n,wt)<<endl;
}
