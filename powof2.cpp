#include<bits/stdc++.h>
using namespace std;
bool is_pow_of_2(int n){
    return (n && !(n & n-1));
}
int main(){
    cout<<is_pow_of_2(6);
    return 0;
}