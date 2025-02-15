// Link: https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1

#include <iostream>
#include <sstream>
#include <queue>
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
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        if (!root)
            return NULL;
        if (root->data > n1->data && root->data > n2->data)
            return LCA(root->left, n1, n2);
        else if (root->data < n1->data && root->data < n2->data)
            return LCA(root->right, n1, n2);
        else
            return root;
    }
};

int main()
{
    Solution object;
    string s = "5 4 6 3 N N 7 N N N 8";
    int n1 = 7, n2 = 8;
    Node *root = buildTree(s);
    Node *node1 = new Node(n1);
    Node *node2 = new Node(n2);
    Node *ans = object.LCA(root, node1, node2);
    cout << ans->data << endl;

    s = "20 8 22 4 12 N N N N 10 14";
    n1 = 8, n2 = 14;
    root = buildTree(s);
    node1 = new Node(n1);
    node2 = new Node(n2);
    ans = object.LCA(root, node1, node2);
    cout << ans->data << endl;

    s = "2 1 3";
    n1 = 1, n2 = 3;
    root = buildTree(s);
    node1 = new Node(n1);
    node2 = new Node(n2);
    ans = object.LCA(root, node1, node2);
    cout << ans->data << endl;
    return 0;
}