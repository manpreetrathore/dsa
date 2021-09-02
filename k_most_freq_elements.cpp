#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    map<int,int> m;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(cnt!=k){
        m[a[i]]++;
        cnt++;}

        // or
        // int presentSize = freq.size();
        // if(freq[a[i]]==0 && presentSize==k){
        //     break;
        // }
        // freq[a[i]]++;
    }
    map<int,int> :: iterator it;
    vector<pair<int,int>> ans;
    for(it=m.begin();it!=m.end();it++){
        if(it->second!=0){
            ans.push_back({it->second,it->first});
        }

        // cout<<it->first<<" -> "<<it->second<<endl;
    }
    sort(ans.begin(),ans.end(),greater<pair<int,int>>());
    vector<pair<int,int>> :: iterator itr;
    for(itr=ans.begin();itr!=ans.end();itr++){
        cout<<itr->second<<" -> "<<itr->first<<endl;
    }
    return 0;
}