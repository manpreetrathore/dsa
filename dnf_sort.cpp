#include<bits/stdc++.h>
using namespace std;

void swap(int a[],int n,int m){
    int temp = a[n];
    a[n] = a[m];
    a[m]=temp;
}
void dnfSort(int a[],int n){
    int low=0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(a[mid]==0){
            swap(a,low,mid);
            low++; mid++;
        }
        else if(a[mid]==1){
            mid++;
        }
        else{
            swap(a,mid,high);
            high--;
        }
    }
}


int main(){
    int a[]={1,0,2,1,0,1,2,1,2};
    dnfSort(a,9);
    for(int i=0;i<9;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}