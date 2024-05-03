// Link: https://www.geeksforgeeks.org/problems/k-distance-from-root/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
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
    vector<int> ans;
    void DoInorderTraversal(struct Node *root, int k)
    {
        if (root == NULL)
            return;
        if (k == 0)
        {
            ans.push_back(root->data);
            return;
        }
        DoInorderTraversal(root->left, k - 1);
        DoInorderTraversal(root->right, k - 1);
    }

public:
    vector<int> Kdistance(struct Node *root, int k)
    {
        ans.clear();
        DoInorderTraversal(root, k);
        return ans;
    }
};

int main()
{
    Solution obj;
    string values = "1 3 2";
    Node *root = buildTree(values);
    vector<int> res = obj.Kdistance(root, 1);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    values = "1 2 1 5 3";
    root = buildTree(values);
    res = obj.Kdistance(root, 2);
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;
    return 0;
}