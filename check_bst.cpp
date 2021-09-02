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

bool isBst(node* root, node* min=NULL,node* max=NULL){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }
    bool left = isBst(root->left,min,root);
    bool right = isBst(root->right,root,max);
    return left and right;
}

int main(){
    node* root = new node(1);
    root->right = new node(2);
    root->right->right = new node(3);
    cout<<isBst(root,NULL,NULL)<<endl;
    return 0;
}


// Time Complelxity: O(n)