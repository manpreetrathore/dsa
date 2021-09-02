#include<bits/stdc++.h>
using namespace std;

void swap(int a[],int n,int m){
    int temp = a[n];
    a[n] = a[m];
    a[m]=temp;
}

void Wave(int a[], int n){
    for(int i=1;i<n;i+=2){
        if(a[i]>a[i-1]){
            swap(a,i,i-1);

        }
        if(a[i]>a[i+1] && i<=n-2){
            swap(a,i,i+1);
        }

    }
}

int main(){
    int a[]={1,3,4,7,5,6,2};
    Wave(a,7);
    for(int i=0;i<7;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}