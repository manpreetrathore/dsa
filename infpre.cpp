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
                st.pop();       // condition to pop opening bracket.
            }
        }
        else{
            while(!st.empty() && prec(st.top())>prec(s[i])){
                res +=st.top();
                st.pop();    // condition to pop operators 
                            // if input's precedence is less that operator on top;

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

string infixtoPrefix(string s){
    reverse(s.begin(),s.end());
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            s[i]='(';
        }
        else if(s[i] == '('){
            s[i]=')';
        }
    }
    string res = infixtoPostfix(s);
    reverse(res.begin(),res.end());    
    
    return res;
}

int main(){
    cout<<infixtoPrefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}