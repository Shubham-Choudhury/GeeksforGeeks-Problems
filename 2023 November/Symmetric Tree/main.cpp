// Link: https://www.geeksforgeeks.org/problems/symmetric-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    bool solve(struct Node *root, struct Node *root1)
    {
        if (root == nullptr && root1 == nullptr)
        {
            return true;
        }
        if (root == nullptr || root1 == nullptr || root->data != root1->data)
        {
            return false;
        }

        bool left = solve(root->left, root1->right);

        bool right = solve(root->right, root1->left);

        return left && right;
    }
    // return true/false denoting whether the tree is Symmetric or not
    bool isSymmetric(struct Node *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        // Code here
        return solve(root->left, root->right);
    }
};

int main()
{
    Solution obj;
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->left = new Node(4);
    cout << obj.isSymmetric(root);
    return 0;
}