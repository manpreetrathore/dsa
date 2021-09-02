#include<bits/stdc++.h>
using namespace std;
void increment(int*a, int*b){
    int temp = *a;
    *a =*b;
    *b = temp;
}
int main(){
    int a=2;
    int b=4;
    int* aptr = &a;
    increment(&a,&b);
    cout<<a<<b;
    return 0;
}