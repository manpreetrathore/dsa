#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    priority_queue<int,vector<int>,greater<int>> mh;
    for(int i=0;i<n;i++){
        mh.push(a[i]);
    }

    int ans = 0;
    while(mh.size()>1){
        int e1 = mh.top();
        mh.pop();
        int e2 = mh.top();
        mh.pop();
        ans+=e1+e2;
        mh.push(e1+e2);
    }
    cout<<ans<<endl;

    return 0;
}
