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

void zigzag(node* root){
    stack<node*> cur,next;
    if(root==NULL){
        return;
    }
    bool leftToright=true;
    cur.push(root);
    while(!cur.empty()){
        node* temp = cur.top();
        cur.pop();
        if(temp){
            cout<<temp->data<<" ";
        
        if(leftToright){
            if(temp->left){
                next.push(temp->left);
            }
            if(temp->right){
                next.push(temp->right);
            }
        }
        else{
            if(temp->right){
                next.push(temp->right);
            }
            if(temp->left){
                next.push(temp->left);
            }
        }

        }
        if(cur.empty()){
            leftToright = !leftToright;
            swap(cur,next);
        }
    }
}
// Time Complexity: O(n) -- O(2n) since we traverse/push each node twice

int main(){
    node* root = new node(12);
    root->left = new node(9);
    root->right = new node(15);
    root->left->left = new node(5);
    root->left->right = new node(10);
    zigzag(root);
    cout<<endl;
    return 0;
}