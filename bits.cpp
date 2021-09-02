#include<bits/stdc++.h>
using namespace std;

int countbits(int n){
    // n = n && !(n & n-1);
    // return countbits(n);

    int count = 0;
    while(n){
        n = n& n-1;
        count++;
    }
    return count;
}

int main(){
    cout<<countbits(19);
    return 0;
}