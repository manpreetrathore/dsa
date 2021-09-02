#include<bits/stdc++.h>
#include<iostream>
// #include<stack>
// #include<deque>
using namespace std; 
int main(){
    cout<<1;
    int n,k=2;
    cin>>n;
    cin>>k;
    vector<int> a;
    cout<<1;
    for(auto i:a){
        cin>>i;
    }
    cout<<1;
    deque<int> q;
    vector<int> ans;
    for(int i=0;i<k;i++){
        while(!q.empty() and a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout<<1;
    ans.push_back(a[q.front()]);
    for(int i=k;i<n;i++){
        if(q.front() == i-k){
            q.pop_front();
        }
        while(!q.empty() and a[q.back()]<a[i]){
            q.pop_back();
        }
        q.push_back(i);
        ans.push_back(a[q.front()]);
    }
    cout<<1;
    for(auto i:a){
        cout<<i;
    }
    return 0;
}