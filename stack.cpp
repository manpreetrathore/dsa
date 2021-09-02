// #include<bits/stdc++.h>
#include<iostream>
using namespace std;

#define n 100

class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top = -1;
    }

    void push(int x){
        if(top==n-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    void pop(){
        if(top==-1){
            cout<<"No elements to pop"<<endl;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<" No Element in stack"<<endl;
            return -1;
        }
        return arr[top];

    }

    bool main(){
        return top==-1;
    }
};

int main(){
    stack stc;
    stc.push(1);
    stc.push(2);
    stc.push(3);
    cout<<stc.Top()<<endl;
    stc.pop();
    cout<<stc.Top()<<endl;
    return 0;
   
}