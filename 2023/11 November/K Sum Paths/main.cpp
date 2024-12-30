// Link: https://www.geeksforgeeks.org/problems/k-sum-paths/1

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
    int solve(Node *root, int k, map<int, int> &mp, int sum)
    {
        if (root == NULL)
        {
            return 0;
        }
        int c = 0;
        sum += root->data;
        if (mp.find(sum - k) != mp.end())
        {
            c += mp[sum - k];
        }
        mp[sum]++;
        int left = solve(root->left, k, mp, sum);
        int right = solve(root->right, k, mp, sum);
        mp[sum]--;
        return c + left + right;
    }
    int sumK(Node *root, int k)
    {
        // code here
        map<int, int> mp;
        mp[0] = 1;
        return solve(root, k, mp, 0);
    }
};

int main()
{
    Solution obj;
    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
    int k = 5;
    cout << obj.sumK(root, k) << endl;
    return 0;
}
// }