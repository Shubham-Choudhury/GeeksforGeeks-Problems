// Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
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

    // Creating vector of strings from input
    // string after splitting by space
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
    void left(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->left)
        {
            ans.push_back(root->data);
            left(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            left(root->right, ans);
        }
    }

    void bottom(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            bottom(root->left, ans);
        if (root->right)
            bottom(root->right, ans);
    }

    void right(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->right)
        {
            right(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left)
        {

            right(root->left, ans);
            ans.push_back(root->data);
        }
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        ans.push_back(root->data);
        left(root->left, ans);
        bottom(root->left, ans);
        bottom(root->right, ans);
        right(root->right, ans);
        return ans;
    }
};

int main()
{
    Solution object;
    string s = "1 2 3 4 5 6 7 N N 8 9 N N N N";
    Node *root = buildTree(s);
    vector<int> ans = object.boundaryTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    s = "1 2 N 4 9 6 5 N 3 N N N N 7 8";
    root = buildTree(s);
    ans = object.boundaryTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    s = "1 N 2 N 3 N 4 N N";
    root = buildTree(s);
    ans = object.boundaryTraversal(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}