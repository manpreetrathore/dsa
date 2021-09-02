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

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    return max(lh,rh)+1;
}

bool isbalanced(node *root)
{
    if(root==NULL){
        return true;
    }
    if (isbalanced(root->left) == false)
    {
        return false;
    }
    if (isbalanced(root->right) == false)
    {
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// isbalanced O(n^2)

bool isBalanced(node* root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    if(isBalanced(root->left,&lh)==false){
        return false;
    }
    if(isBalanced(root->right,&rh)==false){
        return false;
    }
    *height = max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    else{
        return false;
    }
}
// isBalanced() O(n) since no height function is called again and again and a pointer is passed;



int main()
{
    node *root = new node(1);
    root->left = new node(2);
    // root->right = new node(3);
    root->left->left = new node(4);
    // root->left->right = new node(5);
    // root->right->left = new node(6);
    // root->right->right = new node(7);
    int height = 0;
    cout << isBalanced(root,&height);
    return 0;
}