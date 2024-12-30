// Link: https://www.geeksforgeeks.org/problems/largest-bst/1

#include <iostream>
#include <climits>
#include <algorithm>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
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
    int checkbst(Node *root, int low, int high)
    {
        if (root == nullptr)
        {
            return 1;
        }
        int val = root->data;
        if (!((val > low) && (val < high)))
        {
            return 0;
        }
        return checkbst(root->right, val, high) * checkbst(root->left, low, val);
    }

    int size(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + size(root->right) + size(root->left);
    }

    int largestBst(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        if (checkbst(root, -100001, 1000001))
        {
            return 1 + size(root->left) + size(root->right);
        }
        return max(largestBst(root->left), largestBst(root->right));
    }
};

int main()
{
    Solution obj;
    string s = "1 4 4 6 8";
    Node *root = buildTree(s);
    cout << obj.largestBst(root) << endl;

    s = "6 6 2 N 2 1 3";
    root = buildTree(s);
    cout << obj.largestBst(root) << endl;

    return 0;
}