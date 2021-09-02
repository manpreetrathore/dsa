// #include<bits/stdc++.h>
#include<iostream>
// #include<stack>
#include<queue>
using namespace std;

class stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    stack(){
        N=0;
    }
    void pop(){
        if(q1.empty()){
            return ;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();

        }
        q1.pop();
        N--;

        queue<int> temp = q1;
        q1=q2;
        q2=temp;
    }

    void push(int n){
        q1.push(n);
    }

    int top(){
        if(q1.empty()){
            return -1;
        }
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();

        }
        int ans=q1.front();
        q2.push(ans);
        queue<int> temp = q1;
        q1=q2;
        q2=temp;

        return ans;
    }

    int size(){
        return N;
    }


};


int main(){
    stack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top()<<endl;
    return 0;
}