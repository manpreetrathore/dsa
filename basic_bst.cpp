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

int main(){
    struct node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);


    root->left->left = new node(4);
    root->left->right = new node(5);
}


// Maximum Nodes at level L = 2^L and levels start from 0
// Maximum no. of nodes in a tree of height h = 2^h -1 and height starts from 1
// For N nodes minimum possible height or minimum no. of levels are log(N+1){base 2}
// A binary tree with N leaves has atleasdt log(N+1){base 2} no. of levels