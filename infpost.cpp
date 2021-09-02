#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    switch(c){
        case '^': return 3;
        case '*': return 2;
        case '/': return 2;
        case '+': return 1;
        case '-': return 1;
        default:
            return -1;
    }
}

string infixtoPostfix(string s){
    stack<char> st;
    string res;
    for(int i=0;i<s.length();i++){
        if(s[i]>='a' && s[i]<='z'){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            if(!st.empty()){
                st.pop();
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res +=st.top();
                st.pop();

            }
            st.push(s[i]);
        }

    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}

int main(){
    cout<<infixtoPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}