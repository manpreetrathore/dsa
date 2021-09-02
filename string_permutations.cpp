#include<bits/stdc++.h>
using namespace std;
void permutation(string s, string ans){
    if(s.length() == 0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch=s[i];
        cout<<"\t"<<s<<" -> s "<<ch<<" -> ch "<<ans<<" -> ans ";
        string res = s.substr(0,i) + s.substr(i+1);
        cout<<"\t"<<res<<" -> res "<<endl;
        permutation(res,ans+ch);
    }
}
int main(){
    permutation("ABC","");
    return 0;
}