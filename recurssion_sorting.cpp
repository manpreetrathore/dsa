#include<bits/stdc++.h>
using namespace std;

void dec(int n){
    if(n==0){
        return;
    }
    cout<<n<<endl;
    dec(n-1);

}

void inc(int n){
    
    if(n==0){
        return;
    }
    inc(n-1);
    cout<<n<<endl;
}

bool sorted(int a[], int n){

    if(n==1){
        return true;
    }
    bool restArray = sorted(a+1,n-1);
    if(a[0]<a[1] && restArray){
        return true;
    }
    return false;
}

int firstocc(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    if(a[i]==key){
        return i;
    }
    return firstocc(a,n,i+1,key);
}

int lastocc(int a[], int n, int i, int key){
    if(i==n){
        return -1;
    }
    int restArray = lastocc(a,n,i+1,key);
    if(restArray!=-1){
        return restArray;
    }
    if(a[i]==key){
        return i;
    }
    return -1;
}




int main(){
    int a[] = {1,2,3,4,5,5};
    // cout<<sorted(a,6);


    // dec(4);
    // inc(4);
    cout<<firstocc(a,6,0,5)<<endl;
    cout<<lastocc(a,6,0,5)<<endl;
    return 0;

}

