// Link: https://www.geeksforgeeks.org/problems/remove-half-nodes/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <string>
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

// Function to Build Tree
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

void inorder(Node *node)
{
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

class Solution
{
public:
    Node *RemoveHalfNodes(Node *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        root->left = RemoveHalfNodes(root->left);
        root->right = RemoveHalfNodes(root->right);
        if (root->left == NULL and root->right != NULL)
        {
            return root->right;
        }
        if (root->left != NULL and root->right == NULL)
        {
            return root->left;
        }
        return root;
    }
};

int main()
{
    Solution obj;
    string s = "5 7 8 2";
    Node *root = buildTree(s);
    cout << "Inorder Traversal of the tree before removing half nodes: ";
    inorder(root);
    cout << endl;
    root = obj.RemoveHalfNodes(root);
    cout << "Inorder Traversal of the tree after removing half nodes: ";
    inorder(root);
    cout << endl;

    s = "2 7 5";
    root = buildTree(s);
    cout << "Inorder Traversal of the tree before removing half nodes: ";
    inorder(root);
    cout << endl;
    root = obj.RemoveHalfNodes(root);
    cout << "Inorder Traversal of the tree after removing half nodes: ";
    inorder(root);
    cout << endl;

    return 0;
}