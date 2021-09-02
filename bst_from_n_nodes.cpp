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

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

vector<node *> constructTrees(int start, int end)
{
    vector<node *> trees;
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftsub = constructTrees(start, i - 1);
        vector<node *> rightsub = constructTrees(i + 1, end);
        for (int j = 0; j < leftsub.size(); j++)
        {
            node *lft = leftsub[j];
            for (int k = 0; k < rightsub.size(); k++)
            {
                node *rght = rightsub[k];
                node *nde = new node(i);
                nde->left = lft;
                nde->right = rght;
                trees.push_back(nde);
            }
        }
    }
    return trees;
}

int main()
{
    vector<node *> totalTrees = constructTrees(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    return 0;
}

// check for permutations *just an observation