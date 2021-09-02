#include<bits/stdc++.h>
using namespace std;
int main()
{   
    // cout<<1;
    int n,m,k; cin>>n>>m; cin>>k;
    // cout<<k;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }

    }
    
    int r=0,c=m-1;
    bool found=false;
    while(r<n and c>=0)
    {
        //  cout<<"hi";
        //  cout<<r<<c;
        if(a[r][c]==k){
            // cout<<3;
            found = true;
            break; 
            // # goes infinite without break check why.
            }
        else if(a[r][c]>k){
//             cout<<2;
            
            c--;
        }
        else{
            r++;
        }
    }
    if(found){
        cout<<"Element found";
    }
    else{
        cout<<"Element not found";
    }
    return 0;
}
