// Link: https://www.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

#include <iostream>
#include <queue>
#include <sstream>
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

class Solution
{
public:
    void inorder(Node *root, int &k, int &result)
    {
        if (root == nullptr || k <= 0)
            return;
        inorder(root->left, k, result);

        k--;
        if (k == 0)
        {
            result = root->data;
            return;
        }

        inorder(root->right, k, result);
    }

    int kthSmallest(Node *root, int k)
    {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};

int main()
{
    Solution object;
    string s = "2 1 3";
    Node *root = buildTree(s);
    int k = 2;
    cout << object.kthSmallest(root, k) << endl;

    s = "2 1 3";
    k = 5;
    root = buildTree(s);
    cout << object.kthSmallest(root, k) << endl;

    s = "20 8 22 4 12 N N N N 10 14";
    k = 3;
    root = buildTree(s);
    cout << object.kthSmallest(root, k) << endl;
    return 0;
}