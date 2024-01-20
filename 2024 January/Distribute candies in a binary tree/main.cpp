// Link: https://www.geeksforgeeks.org/problems/distribute-candies-in-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
};

class Solution
{
public:
    int ans = 0;

    int help(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL && root->right == NULL)
        {
            return root->key - 1;
        }
        int lf = help(root->left);
        int rg = help(root->right);
        ans += abs(lf);
        ans += abs(rg);
        return lf + rg + root->key - 1;
    }

    int distributeCandy(Node *root)
    {
        int k = help(root);
        return ans;
    }
};

int main()
{
    Solution obj;
    Node *root = new Node();
    root->key = 3;
    root->left = new Node();
    root->left->key = 0;
    root->right = new Node();
    root->right->key = 0;
    cout << obj.distributeCandy(root) << endl;
    Node *root1 = new Node();
    root1->key = 0;
    root1->left = new Node();
    root1->left->key = 0;
    root1->right = new Node();
    root1->right->key = 3;
    cout << obj.distributeCandy(root1) << endl;
    return 0;
}