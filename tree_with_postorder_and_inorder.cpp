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
        // cout<<1;
        if(inorder[i]==key){
            return i;
        }
    }
    return -1;
}
void inorderPrint(node* root){
    if(root==NULL){
        return;
    }
    // cout<<1;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
node* buildTree(int postorder[], int inorder[], int start,int end){
    static int idx = 4;
    
    if(start>end){
        return NULL;
    }
    int val = postorder[idx];
    idx--;
    node* curr=new node(val);
    if(start==end){
        return curr;
    }
    int pos = search(inorder,start,end,val);
    curr->right = buildTree(postorder,inorder,pos+1,end);
    curr->left = buildTree(postorder,inorder,start,pos-1);
    
    return curr;
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};
    node* root=buildTree(postorder,inorder,0,4);
    inorderPrint(root);
    return 0;
}