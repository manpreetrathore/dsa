#include<bits/stdc++.h>
using namespace std;
int countpath(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count = 0;
    for(int i=1;i<=6;i++){
        count+=countpath(s+i,e);
    }
    // cout<<count;
    return count;
}
int main(){
    cout<<countpath(0,3)<<endl;
    return 0;
}