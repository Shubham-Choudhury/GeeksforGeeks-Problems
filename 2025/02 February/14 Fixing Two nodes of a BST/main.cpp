// Link: https://www.geeksforgeeks.org/problems/fixed-two-nodes-of-a-bst/1

#include <iostream>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

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

bool isBST(Node *n, int lower, int upper)
{
    if (!n)
        return true;
    if (n->data <= lower || n->data >= upper)
        return false;
    return (isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper));
}

bool compare(Node *a, Node *b, vector<pair<int, int>> &mismatch)
{
    if (!a && !b)
        return true;
    if (!a || !b)
        return false;

    if (a->data != b->data)
        mismatch.push_back(pair<int, int>(a->data, b->data));

    return (compare(a->left, b->left, mismatch) &&
            compare(a->right, b->right, mismatch));
}

class Solution
{
public:
    void make_BST(Node *root, vector<int> &v, int &i)
    {
        if (root == NULL)
        {
            return;
        }

        make_BST(root->left, v, i);
        root->data = v[i++];
        make_BST(root->right, v, i);
    }

    void LNR(Node *root, vector<int> &v)
    {
        if (root == NULL)
        {
            return;
        }

        LNR(root->left, v);
        v.push_back(root->data);
        LNR(root->right, v);
    }

    void correctBST(Node *root)
    {
        vector<int> v;
        LNR(root, v);

        sort(v.begin(), v.end());
        int i = 0;
        make_BST(root, v, i);
    }
};

int main()
{
    Solution objext;
    string s = "10 5 8 2 20";
    Node *root = buildTree(s);
    objext.correctBST(root);

    s = "5 10 20 2 8";
    root = buildTree(s);
    objext.correctBST(root);

    return 0;
}