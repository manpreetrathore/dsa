#include <bits/stdc++.h>
using namespace std;
void strrev(string a){
    if(a.length()==0){
        return;
    }
    string res = a.substr(1);
    strrev(res);
    cout<<a[0];
}
int main(){
    string a;
    getline(cin,a);
    strrev(a);
    return 0;
}