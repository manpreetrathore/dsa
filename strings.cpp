#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    // getline(cin,str);
    // cout<<str<<endl;
    string s1,s2;
    // cin.sync();
    getline(cin,s1);
    // cin.ignore();
    getline(cin,s2);
    // s1 = s1+s2;
    // s1.append(s2);
    // cout<<s1<<endl;
    // cout<<s1+s2;
    // cout<<s1[1];

    // s1.clear();
    // cout<<s1<<endl;
    // cout<<s1.compare(s2)<<endl;
    if(!s1.compare(s2)){
        cout<<"Strings are equal";
    }
    
    // s1.clear();
    if(s1.empty()){
        cout<<"Strings S1 is Empty";
    }

    // s2.erase(7,4);
    // cout<<s1.find("Rathore")<<endl;
    // cout<<s2;

    // s1.insert(8," lol");
    // cout<<s1;

    // string s = s1.substr(9,7);
    // cout<<s;


    // string n = "786";
    // int x = stoi(n);
    // cout<<x;

    // int x = 786;
    // cout<<to_string(x)+to_string(2);


    // sort(s1.begin(), s1.end());
    // cout<<s1;
    // cout<<s1.length()<<endl<<s1.size()<<endl;
    // to upper case
    // for(int i=0;i<s1.length();i++){
    //     if(s1[i]>='a' && s1[i]<='z'){
    //         s1[i] -= 32;
    //     }
    // }
    // cout<<s1<<endl;

    // to lower case
    // for(int i=0;i<s1.length();i++){
    //     if(s1[i]>='A' && s1[i]<='Z'){
    //         s1[i] += 32;
    //     }
    // }
    // cout<<s1<<endl;

    //to uppwe
    // transform(s1.begin()+9, s1.end(), s1.begin()+9,::toupper);
    // cout<<s1<<endl;

    //to lower
    // transform(s1.begin(), s1.end()-7, s1.begin(),::tolower);
    // cout<<s1<<endl;

    // string x= "63834921";
    // sort(x.begin() , x.end(), greater<int>());
    // cout<<x<<endl;

    // another logic for counting max occurences of a letter.
        // sort(s1.begin(),s1.end());
        // cout<<s1;
        // int count = 0;
        // int maxCount = 0;
        // for (int i=0;i<s1.size();i++){
        //     if(i==0 || s1[i]==s1[i-1]){
        //         count+=1;
        //         if(maxCount<count){
        //             maxCount= count;
        //         }
        //     }
        //     else if(s1[i]!=s1[i-1]){
        //         count=0;
        //     }
        // }
        // cout<<maxCount;

    // max occurence of a letter
        int freq[26];
        for(int i=0;i<26;i++){
            freq[i]=0;
        }
        for(int i=0;i<s1.size();i++){
            freq[s1[i]-'a']++;
        }
        char ans='a';
        int maxCount =0;
        for(int i=0;i<26;i++){
            if(freq[i]>maxCount){
                maxCount = freq[i];
                ans = i+'a';
            }

        }
        cout<<ans<<maxCount;
    return 0;
}