#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    cin.ignore();
    char a[n+1];
    cin.getline(a,n);
    cin.ignore();
    int cur = 0, i=0, maxLen=0;
    int st=0,stend=0;
    while(1){
        if(a[i]==' ' || a[i]=='\0'){
        
        if(cur>maxLen){
            maxLen = cur;
            stend = st;
        }
        cur=0;
        st=i+1;
        }
        else
        cur++;
        if(a[i]=='\0'){
            break;
        }
        i++;
    }
    cout<<maxLen;
    for(int j=0;j<maxLen;j++){
        cout<<a[j+stend];
    }
    return 0;
}