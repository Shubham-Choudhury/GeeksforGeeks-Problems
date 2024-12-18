// Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

void inOrder(struct Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

// Function to Build Tree
Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    Node *root = newNode(stoi(ip[0]));

    queue<Node *> queue;
    queue.push(root);

    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        Node *currNode = queue.front();
        queue.pop();

        string currVal = ip[i];

        if (currVal != "N")
        {

            currNode->left = newNode(stoi(currVal));

            queue.push(currNode->left);
        }

        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    vector<int> levelOrder(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto f = q.front();
                q.pop();
                ans.push_back(f->data);
                if (f->left)
                {
                    q.push(f->left);
                }
                if (f->right)
                {
                    q.push(f->right);
                }
            }
        }
        return ans;
    }
};