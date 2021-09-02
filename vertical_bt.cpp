#include<bits/stdc++.h>
using namespace std;

struct node{
    int key;
    node* left;
    node* right;
    node(int x){
        key = x;
        left = NULL;
        right = NULL;
    }
};

void getVerticalOrder(node* root, int hd, map<int , vector<int>> &m){
    if(root==NULL){
        return;
    }
    m[hd].push_back(root->key);
    getVerticalOrder(root->left,hd-1,m);
    getVerticalOrder(root->right,hd+1,m);
}

int main(){
    node* root = new node(10);
    root->left = new node(7);
    root->right = new node(4);
    root->left->left = new node(3);
    root->left->right = new node(11);
    root->right->left = new node(14);
    root->right->right = new node(6);
    map<int,vector<int>> m;
    int hdis = 0;
    getVerticalOrder(root,hdis,m);
    map<int,vector<int>> :: iterator it;
    for(it=m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
    }
    return 0;
}