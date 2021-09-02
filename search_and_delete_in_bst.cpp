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

node* searchBst(node* root, int val){
    if(root==NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(root->data>val){
        node* nd = searchBst(root->left,val);
        return nd;
    }
    node* nd = searchBst(root->right,val);
    return nd;
}

node* inorderSucc(node* root){
    node* curr = root;
    while(curr && curr->left!=NULL){
        curr = curr->left;
    }
    return curr;
}

node* deleteInBst(node* root,int key){
    if(key<root->data){
        root->left = deleteInBst(root->left,key);
    }
    else if(key>root->data){
        root->right = deleteInBst(root->right,key);
    }
    else{ // when root->data == key
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }
    // case 3
    node* temp = inorderSucc(root->right);
    root->data = temp->data;
    root->right = deleteInBst(root->right,temp->data);
    }
    return root;
}

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);    
}

int main(){
    // cout<<1;
    node* root= new node(4);
    // cout<<1;
    root->left = new node(2);
    root->right = new node(5);
    // cout<<1;
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->right = new node(6);
    // cout<<1;
    inorder(root);
    cout<<endl;
    node* res = searchBst(root,1);
    cout<<res->data<<endl;
    inorder(root);
    cout<<endl;
    root = deleteInBst(root,2);
    inorder(root);
    return 0;
}


// we compare only one element at each level.
// So maximum no. of comparisons is height of bst.
// Time Complexity: O(logn)