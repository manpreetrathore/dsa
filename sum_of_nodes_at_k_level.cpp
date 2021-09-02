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

int sumAtLevel(node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;
    while (!q.empty())
    {
        node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            // cout<<node->data<<" ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
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

    cout << sumAtLevel(root, 2);
    return 0;
}