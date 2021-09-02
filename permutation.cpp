#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
void permute(vector<int> &a, int id){
    if(id == a.size()){
        ans.push_back(a);
        return;
    }
    int j=0;
    for(j = id;j<a.size();j++)
    {
        swap(a[j],a[id]);
        permute(a,id+1);
        swap(a[j],a[id]);
    }
}

void helper(vector<int> a,vector<vector<int>> &ans,int id){
    if(id == a.size()){
        ans.push_back(a);
        return;
    }
    int j=0;
    for(j = id;j<a.size();j++)
    {
        if(j!=id && a[j]==a[id]){
            continue;
        }
        swap(a[j],a[id]);
        permute(a,id+1);
        // swap(a[j],a[id]);
    }
}
vector<vector<int>> permute_dup(vector<int> &a,int id){
    // if(id == a.size()){
    //     ans.push_back(a);
    //     return;
    // }
    sort(a.begin(),a.end());
    helper(a,ans,0);
    // int j=0;
    // for(j = id;j<a.size();j++)
    // {
    //     if(j!=id && a[j]==a[id]){
    //         continue;
    //     }
    //     swap(a[j],a[id]);
    //     permute(a,id+1);
    //     // swap(a[j],a[id]);
    // }
    return ans;
}

int main(){
    int n; cin>>n;
    vector<int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    // permute(a,0);
    vector<vector<int>> res = permute_dup(a,0);
    // sort(a.begin(),a.end());
    //     do{
    //         ans.push_back(a);
    //     }while(next_permutation(a.begin(),a.end()));
    for(auto v: res){
        for(auto i : v){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;
}