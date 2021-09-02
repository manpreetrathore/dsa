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

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    else if(root1==NULL || root2==NULL){
        return false;
    }
    if (root1->data == root2->data)
    {
        if (isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    node *root1 = new node(2);
    root1->left = new node(1);
    root1->right = new node(3);
    node *root2 = new node(2);
    root2->left = new node(1);
    root2->right = new node(4);
    cout<<isIdentical(root1,root2)<<endl;
    return 0;
}