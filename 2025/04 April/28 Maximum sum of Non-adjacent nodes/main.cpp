// Link: https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

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
    pair<int, int> a(Node *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> l = a(root->left);
        pair<int, int> r = a(root->right);

        int in = root->data + l.second + r.second;
        int ex = max(l.first, l.second) + max(r.first, r.second);

        return {in, ex};
    }

    int getMaxSum(Node *root)
    {
        pair<int, int> akshu = a(root);
        return max(akshu.first, akshu.second);
    }
};

int main()
{
    Solution sol;
    string s = "11 1 2";
    Node *root = buildTree(s);
    cout << sol.getMaxSum(root) << endl;

    s = "1 2 3 4 N 5 6";
    root = buildTree(s);
    cout << sol.getMaxSum(root) << endl;
    return 0;
}