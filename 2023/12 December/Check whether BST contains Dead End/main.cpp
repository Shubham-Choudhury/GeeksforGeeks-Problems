// Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

/*You are required to complete below method */
class Solution
{
public:
    bool ispossible(Node *root, int ll, int rl)
    {
        if (root == NULL)
            return false;
        if (ll >= rl)
            return true;
        return ispossible(root->left, ll, root->data - 1) || ispossible(root->right, root->data + 1, rl);
    }
    bool isDeadEnd(Node *root)
    {
        if (root == NULL)
            return false;
        return ispossible(root, 1, INT_MAX);
    }
};

int main()
{
    Solution obj;
    Node *root = new Node(8);
    root->left = new Node(5);
    root->right = new Node(9);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->left->right->left = new Node(6);
    root->right->right = new Node(10);
    cout << obj.isDeadEnd(root);
    return 0;
}