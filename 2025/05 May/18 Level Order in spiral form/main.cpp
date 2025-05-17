// Link: https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    return new Node(val);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    int height(Node *node)
    {
        if (node == nullptr)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void getLevel(Node *root, int level, bool ltr, vector<int> &res)
    {
        if (root == nullptr)
            return;
        if (level == 1)
            res.push_back(root->data);
        else if (level > 1)
        {
            if (ltr)
            {
                getLevel(root->left, level - 1, ltr, res);
                getLevel(root->right, level - 1, ltr, res);
            }
            else
            {
                getLevel(root->right, level - 1, ltr, res);
                getLevel(root->left, level - 1, ltr, res);
            }
        }
    }

    vector<int> findSpiral(Node *root)
    {
        vector<int> res;
        int h = height(root);
        bool ltr = false;
        for (int i = 1; i <= h; i++)
        {
            getLevel(root, i, ltr, res);
            ltr = !ltr;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string str = "1 3 2";
    Node *root = buildTree(str);
    vector<int> result = sol.findSpiral(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    str = "10 20 30 40 60";
    root = buildTree(str);
    result = sol.findSpiral(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    str = "1 2 N 4";
    root = buildTree(str);
    result = sol.findSpiral(root);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}