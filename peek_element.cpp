#include <bits/stdc++.h>
using namespace std;

int peak(int a[],int l,int h, int n){
    int mid = l+(h-l)/2;
    if((mid==0 || a[mid-1]<=a[mid]) && (mid==n-1 || a[mid+1] <= a[mid])){
        return mid;
    }
    else if(mid>0 && a[mid-1] > a[mid]){
        return peak(a,l,mid-1,n);
    }
    else{
        return peak(a,mid+1,h,n);
    }
}

int main(){
    int a[]={0,6,8,5,7,9};
    int n=6;
    cout<<peak(a,0,n-1,n);
    return 0;
}