// Link: https://www.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1

#include <iostream>
#include <sstream>
#include <set>
#include <queue>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

Node *insert(Node *root, int key)
{
    if (!root)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

Node *createBST(string s)
{
    stringstream ss(s);
    string temp;
    Node *root = NULL;
    while (ss >> temp)
    {
        if (temp == "N")
            continue;
        int num = stoi(temp);
        root = insert(root, num);
    }
    return root;
}

class Solution
{
public:
    bool dfs(Node *root, int mini, int maxi)
    {
        if (root == nullptr)
            return false;

        if (root->left == nullptr && root->right == nullptr && mini == maxi)
        {
            return true;
        }

        return dfs(root->left, mini, root->data - 1) ||
               dfs(root->right, root->data + 1, maxi);
    }

    bool isDeadEnd(Node *root)
    {
        return dfs(root, 1, INT_MAX);
    }
};

int main()
{
    Solution obj;
    string s = "8 5 9 2 7 N N 1";
    Node *root = createBST(s);
    cout << (obj.isDeadEnd(root) ? "Yes" : "No") << endl;

    s = "8 7 10 2 N 9 13";
    root = createBST(s);
    cout << (obj.isDeadEnd(root) ? "Yes" : "No") << endl;
    return 0;
}
