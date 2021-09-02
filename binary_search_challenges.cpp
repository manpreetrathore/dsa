#include <bits/stdc++.h>
using namespace std;

bool isFeasible(int mid,int a[],int n,int k){
    int pos=a[0];
    int elements=1;
    for(int i=1;i<n;i++){
        if(a[i]-pos>=mid){
            pos=a[i];
            elements++;
            if(elements==k){
                return true;
            }
        }


    }
    return false;
}

int largestMinDistance(int a[],int n,int k){
    sort(a,a+n);
    int result =-1,left = 1,right = a[n-1];
    while(left<right){
        int mid = (left+right)/2;
        if(isFeasible(mid,a,n,k)){
            result = max(result,mid);
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return result;
}

bool isPossible(int arr[],int n,int m,int min){
    int studentsReq = 1,sum=0;
    for(int i=0;i<n;i++){
        if(arr[i] > min){
            return false;
        }
        if(sum+arr[i] > min){
            studentsReq++;
            sum = arr[i];
            if(studentsReq>m){
                return false;
            }
        }
        else{
            sum+=arr[i];
        }
    }
    return true;
}

int allocateMin(int a[],int n,int m){
    int sum =0;
    if(n<m){
        return -1;
    }
    for(int i=0;i<n;i++){
        sum=sum+a[i];
    }
    int start=0,end =sum,ans=INT_MAX;
    while(start<end){
        int mid = (start+end)/2;
        if(isPossible(a,n,m,mid)){
            ans = min(ans,mid);
            end = mid-1;

        }
        else{
            start = mid+1;

        }
    }
    return ans;
}

int main(){
    int a[]={1,2,8,4,9};
    int n=5;
    int k=3;
    cout<<largestMinDistance(a,n,k)<<endl;
    int b[]={12,34,67,90};
    int x=4;
    int m=2;
    cout<<allocateMin(b,x,m)<<endl;
    return 0;
}