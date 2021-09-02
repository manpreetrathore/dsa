// #include<bits/stdc++.h>
#include<iostream>
// // #include<stack>
#include<deque>
using namespace std; 

int main(){
    deque<int> q;
    q.push_back(1);
    q.push_back(2);
    q.push_front(3);
    q.push_front(4);
    for(auto i:q){
        cout<<i<<" ";
    }
    cout<<endl;
    q.pop_front();
    q.pop_back();
    for(auto i:q){
        cout<<i<<" ";
    }
    cout<<endl;
    // cout<<q.pop_back()<<endl;
    // q.pop();
    // cout<<q.pop_front()<<endl;
    return 0;
}
