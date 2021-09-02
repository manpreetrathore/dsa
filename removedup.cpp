#include<bits/stdc++.h>
using namespace std;
string removedup(string s){
    if(s.length()==0){
        return "";
    }
    char ch = s[0];
    string ans = removedup(s.substr(1));
    if(ch==ans[0]){
        return ans;
    }
    return ch+ans;

}
string removex(string s){
    if(s.length()==0){
        return "";

    }
    char ch = s[0];
    string ans = removex(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}
int main(){
    cout<<removex("axbxcddx")<<endl;
    return 0;
}