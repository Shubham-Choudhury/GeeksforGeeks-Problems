// Link: https://www.geeksforgeeks.org/problems/paths-from-root-with-a-specified-sum/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left, *right;
};

class Solution
{
public:
    void help(Node *root, int sum, vector<vector<int>> &ans, vector<int> &v)
    {
        if (!root)
            return;

        if (sum == root->key)
        {
            v.push_back(root->key);
            ans.push_back(v);
            v.pop_back();
        }
        v.push_back(root->key);
        help(root->left, sum - root->key, ans, v);
        help(root->right, sum - root->key, ans, v);

        v.pop_back();
    }

    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<int> v;
        vector<vector<int>> ans;
        help(root, sum, ans, v);

        return ans;
    }
};

int main()
{
    Solution obj;
    int sum = 38;
    struct Node *root = new Node;
    root->key = 10;
    root->left = new Node;
    root->left->key = 28;
    root->right = new Node;
    root->right->key = 13;
    root->right->left = new Node;
    root->right->right = new Node;
    root->right->left->key = 14;
    root->right->right->key = 15;
    root->right->left->left = new Node;
    root->right->left->right = new Node;
    root->right->right->left = new Node;
    root->right->right->right = new Node;
    root->right->left->left->key = 21;
    root->right->left->right->key = 22;
    root->right->right->left->key = 23;
    root->right->right->right->key = 24;
    vector<vector<int>> ans = obj.printPaths(root, sum);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}