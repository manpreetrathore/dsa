#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char a[n+1];
    bool flag=false;
    cin>>a;

    for(int i=0;i<n;i++)
    {
        if(a[i]==a[n-i-1]){
            flag=true;
            break;
        }
    }
    if(flag){
        cout<<"Palindrome";
    }
    else{
        cout<<"Not a palindrome";
    }
    // while(ar[i]!='\0'){
    //     cout<<ar[i];
    //     i++;
    // }
    return 0;
}