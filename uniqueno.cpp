#include<bits/stdc++.h>
using namespace std;

int unique(int a[], int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^a[i];
    }
    return xorsum;
}

int setBit(int n, int pos){
    return (n& (1<<pos))!=0;
}
void multipleunique(int a[], int n){
    int xorsum = 0;
    for(int i=0;i<n;i++){
        xorsum = xorsum^a[i];
    }
    int tempxor = xorsum;
    int setbit = 0;
    int pos = 0 ;
    while(setbit!=1){
        setbit = xorsum & 1;
        pos++;
        xorsum = xorsum>>1;
    }
    int newxor = 0;

    for(int i=0;i<n;i++){
        if(setBit(a[i], pos-1)){
            newxor = newxor^a[i];

        }
    }
    tempxor  =  newxor^tempxor;
    cout<<tempxor<<" "<<newxor;
}

int main(){
    int a[]={1,2,3,4,1,2,3,69};
    int b[]={1,2,3,4,1,2,3};
    multipleunique(a,8);
    cout<<unique(b,7); 
    return 0;
}