#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int,vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(1);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    priority_queue<int,vector<int>,greater<int>> minpq;
    minpq.push(2);
    minpq.push(3);
    minpq.push(4);
    minpq.push(1);
    cout<<minpq.top()<<endl;
    minpq.pop();
    cout<<minpq.top()<<endl;
    return 0;
}