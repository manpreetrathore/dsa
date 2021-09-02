#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left;
    node *right;
    node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* constructBst(int preorder[],int* preorderIdx,int key,int min,int max,int n){
    if(*preorderIdx>n){
        return NULL;
    }
    node* root = NULL;
    if(key>min&& key<max){
        root = new node(key);
        *preorderIdx = *preorderIdx+1;
        if(*preorderIdx<n){
            root->left = constructBst(preorder,preorderIdx, preorder[*preorderIdx],min,key,n);
        }
        if(*preorderIdx<n){
            root->right = constructBst(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
        }
    }
    return root;
}

void preoorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preoorder(root->left);
    preoorder(root->right);    
}

int main(){
    int preorder[] = {10,2,1,13,11};
    int n=5;
    int preorderIdx = 0;
    node* root = constructBst(preorder,&preorderIdx,preorder[0],INT_MIN,INT_MAX,n);
    preoorder(root);
    
    return 0;
}


// Time Complexity: O(n)