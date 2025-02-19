// Link: https://www.geeksforgeeks.org/problems/diagonal-sum-in-binary-tree/1

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
public:
    vector<int> diagonalSum(Node *root)
    {
        vector<int> res;
        queue<Node *> q;
        q.push(root);
        if (root == 0)
            return res;
        while (!q.empty())
        {
            int sum = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)

            {
                Node *node = q.front();

                q.pop();

                while (node)
                {
                    if (node->left)
                        q.push(node->left);
                    sum += node->data;

                    node = node->right;
                }
            }

            res.push_back(sum);
        }
        return res;
    }
};

int main()
{
    Solution obj;
    string s;
    s = "10 8 2 3 5 2";
    Node *root = buildTree(s);
    vector<int> v = obj.diagonalSum(root);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}