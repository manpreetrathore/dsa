#include<bits/stdc++.h>
using namespace std;

string longestSubstring(string s){
    int low,high;
    int start=0,end=1;
    for(int i=1;i<s.length();i++){
    
        low = i-1;
        high = i;
        while(low>=0 && high<s.length() && s[low]==s[high]){
            if(high-low+1>end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    low=0;
    high=1;
    for(int i=1;i<s.length();i++){
    
        low = i-1;
        high = i+1;
        while(low>=0 && high<s.length() && s[low]==s[high]){
            if(high-low+1>end){
                start = low;
                end = high-low+1;
            }
            low--;
            high++;
        }
    }
    return s.substr(start,start+end);
}


int main(){
    string s;
    cin>>s;
    string response = longestSubstring(s);
    cout<<response<<endl;
}