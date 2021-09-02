#include <bits/stdc++.h>
using namespace std;

int catalan(int n){
    int res=0;
    if(n<=1){
        return 1;
    }
    for(int i=0;i<=n-1;i++){
        res += catalan(i)*catalan(n-i-1);
    }
    return res;
}

int main(){
    for(int i=0;i<10;i++){
    cout<<catalan(i)<<" "; 
    }
    cout<<endl;  
    return 0;
}

// takes a lot of time and it's not practical to tell in interview.