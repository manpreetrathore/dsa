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

//Case 1
void printNodes(node* root,int k){
    if(root == NULL || k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printNodes(root->left,k-1);
    printNodes(root->right,k-1);
}

//Case 2
int nodesAtK(node* root, node* target, int k){
    if(root==NULL){
        return -1;

    }
    if(root==target){
        printNodes(root,k);
        return 0;
    }
    int dl = nodesAtK(root->left,target,k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            printNodes(root->right,k-dl-2);
        }
        return 1+dl;
    }
    int dr = nodesAtK(root->right,target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            printNodes(root->left,k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main(){
    node* root=new node(1);
    root->left = new node(2);
    root->right =  new node(3);
    root->left->left = new node(4);
    nodesAtK(root,root->left,2);
    return 0;
}