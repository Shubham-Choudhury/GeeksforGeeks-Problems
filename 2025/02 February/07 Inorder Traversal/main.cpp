// Link: https://www.geeksforgeeks.org/problems/inorder-traversal/1

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

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

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
            currNode->left = new Node(stoi(currVal));

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
            currNode->right = new Node(stoi(currVal));

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
    void solve(Node *node, vector<int> &res)
    {
        if (node == NULL)
            return;
        solve(node->left, res);
        res.push_back(node->data);
        solve(node->right, res);
    }

    vector<int> inOrder(Node *root)
    {
        vector<int> res;
        solve(root, res);
        return res;
    }
};

int main()
{
    Solution object;
    string s = "1 2 3 4 5";
    Node *root = buildTree(s);
    vector<int> res = object.inOrder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    s = "8 1 5 N 7 10 6 N 10 6";
    root = buildTree(s);
    res = object.inOrder(root);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}