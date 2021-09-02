#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    int *p = new int();
    *p = a;
    cout<<p<<endl<<*p<<endl;
    *p = 20;
    cout<<a;
    delete(p);
    
    cout<<p<<endl<<*p;
    p=new int[4];
    
    cout<<p<<endl<<*p;
    delete[]p;
    
    cout<<p<<endl<<*p;
    p=NULL;
}