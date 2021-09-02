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

int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int maxHeight(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lht = maxHeight(root->left);
    int rht = maxHeight(root->right);
    return max(lht, rht) + 1;
}

int diameter(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lht = maxHeight(root->left);
    int rht = maxHeight(root->right);
    int curdia = lht + rht + 1;
    int ldia = diameter(root->left);
    int rdia = diameter(root->right);
    int m = max(ldia, rdia);
    return max(curdia, m);
}

// diameter -> O(n^2)
// height -> O(n)

int recurDiameter(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldia = recurDiameter(root->left, &lh);
    int rdia = recurDiameter(root->right, &rh);
    int currdia = lh + rh + 1;
    *height = max(lh, rh) + 1;
    return max(currdia, max(ldia, rdia));
}


int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int height =0;
    cout << recurDiameter(root,&height);
    return 0;
}