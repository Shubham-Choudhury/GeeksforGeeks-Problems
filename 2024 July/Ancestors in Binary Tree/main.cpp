// Link: https://www.geeksforgeeks.org/problems/ancestors-in-binary-tree/1

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

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
    vector<int> temp;
    void solve(struct Node *root, int target, vector<int> v)
    {

        if (root == NULL)
            return;

        if (root->data == target)
        {

            for (auto it : v)
            {
                temp.push_back(it);
            }

            return;
        }

        v.push_back(root->data);
        solve(root->left, target, v);
        solve(root->right, target, v);
        v.pop_back();
    }

    vector<int> Ancestors(struct Node *root, int target)
    {

        vector<int> v, a;
        solve(root, target, v);
        reverse(temp.begin(), temp.end());
        return temp;
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3 4 5 6 8 7";
    Node *root = buildTree(s);
    int target = 7;
    vector<int> res = obj.Ancestors(root, target);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    s = "1 2 3";
    root = buildTree(s);
    target = 1;
    res = obj.Ancestors(root, target);
    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}