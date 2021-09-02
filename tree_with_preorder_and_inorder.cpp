#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
int search(int inorder[],int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key){
            return i;
        }
    }
    return -1;
}
node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx = 0;
    if(start>end){
        return NULL;
    }
    int curr = preorder[idx];
    idx++;
    node* curnode = new node(curr);
    if(start==end){
        return curnode;
    }
    int pos = search(inorder,start,end,curr);
    curnode->left = buildTree(preorder,inorder,start,pos-1);
    curnode->right = buildTree(preorder,inorder,pos+1,end);
    
    return curnode;
}

void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};
    node* root=buildTree(preorder,inorder,0,4);
    inorderPrint(root);
    return 0;
}