// Link: https://www.geeksforgeeks.org/problems/burning-tree/1

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

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
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

            // Create the right child for the current Node
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
    int maxDepth(Node *n)
    {
        if (!n)
            return 0;
        return 1 + max(maxDepth(n->left), maxDepth(n->right));
    }

    int traverse(Node *n, int target, int &ret)
    {
        if (!n)
            return 0;

        if (n->data == target)
        {
            ret = max(ret, maxDepth(n->right));
            ret = max(ret, maxDepth(n->left));
            return 1;
        }

        int val = traverse(n->left, target, ret);
        if (val)
        {
            ret = max(ret, val + maxDepth(n->right));
            return val + 1;
        }

        val = traverse(n->right, target, ret);
        if (val)
        {
            ret = max(ret, val + maxDepth(n->left));
            return val + 1;
        }

        return 0;
    }

    int minTime(Node *root, int target)
    {
        int ret = 0;
        traverse(root, target, ret);
        return ret;
    }
};

int main()
{
    Solution sol;
    string s = "1 2 3 4 5 6 7";
    Node *root = buildTree(s);
    int target = 2;
    cout << sol.minTime(root, target) << endl;

    s = "1 2 3 4 5 N 7 8 N 10";
    root = buildTree(s);
    target = 10;
    cout << sol.minTime(root, target) << endl;

    return 0;
}