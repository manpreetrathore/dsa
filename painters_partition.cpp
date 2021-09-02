#include <bits/stdc++.h>
using namespace std;

int findFeasible(int br[],int n,int l){
    int sum=0,painters=1;
    for(int i=0;i<n;i++){
        sum+=br[i];
        if(sum>l){
            sum = br[i];
            painters++;
        }
    }
    return painters;
}

int paintersPartition(int b[],int n,int m){
    int totalLen = 0,k=0;
    for(int i=0;i<n;i++){
        k=max(k, b[i]);
        totalLen += b[i];
    }
    int low=k,high = totalLen;
    int mid=0;
    while(low<high){
        mid = (low+high)/2;
        int painters = findFeasible(b,n,mid);
        if(painters<=m){
            high=mid;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    int a[] = {10,20,30,40};
    int n=4,m=2;
    cout<<paintersPartition(a,n,m)<<endl;
    return 0;
}
