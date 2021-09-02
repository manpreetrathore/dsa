#include<bits/stdc++.h>
using namespace std;
void countSort(int a[],int n){
    int k = a[0];
    for(int i=0;i<n;i++){
        k=max(k,a[i]);
    }
    int count[20] = {0};
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    for(int i=0;i<=k;i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1;i>=0;i--){
        output[--count[a[i]]] = a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = output[i];
    }
}
int main(){
    int a[] = {1,1,2,3,4,4,5,5,5};
    countSort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}