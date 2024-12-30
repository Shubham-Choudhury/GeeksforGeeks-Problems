// Link: https://www.geeksforgeeks.org/problems/children-sum-parent/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    };
};

class Solution
{
public:
    bool flag = 1;
    int isSum(Node *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return root->data;

        int sum = isSum(root->left) + isSum(root->right);
        if (sum != root->data)
            flag = 0;
        return root->data;
    }

    int isSumProperty(Node *root)
    {
        isSum(root);
        return flag;
    }
};