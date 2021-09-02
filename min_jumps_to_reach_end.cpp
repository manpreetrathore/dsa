#include<bits/stdc++.h>
using namespace std;
const int MOD=1e3+2,N=1e3+4;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i:arr)
    {
        cin>>i;
    }
    vector<int> jumps(n,MOD);
    if(arr[0]==0)
    {
        cout<<MOD<<endl;
        return 0;
    }
    jumps[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(i<=(j+arr[j]))
            {
                jumps[i] = min(jumps[i],1+jumps[j]);
                break;
            }
        }
    }
    cout<<jumps[n-1]<<endl;
    return 0;
}