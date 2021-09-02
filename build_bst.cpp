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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}
node* insertBst(node* root, int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left = insertBst(root->left, val);
    }
    else{
        root->right = insertBst(root->right, val);
    }
    return root;
}

int main(){
    int a[]={5,1,3,4,2,7};
    node* root = NULL;

    root= insertBst(root,5);
    insertBst(root,1);
    insertBst(root,3);
    insertBst(root,4);
    insertBst(root,2);
    insertBst(root,7);
    //print inorder.
    inorder(root);
    return 0;
}