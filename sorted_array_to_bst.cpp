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

node* arrayToBst(int a[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid = (start+end)/2;
    node* root = new node(a[mid]);
    root->left = arrayToBst(a,start,mid-1);
    root->right = arrayToBst(a,mid+1,end);
    return root;
}

void preorder(node* root){

    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    int a[]={10,20,30,40,50};
    node* root = arrayToBst(a,0,4);
    preorder(root);
    cout<<endl;
    return 0;
}