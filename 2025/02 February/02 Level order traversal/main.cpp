// Link: https://www.geeksforgeeks.org/problems/level-order-traversal/1

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    return new Node(val);
}

void inOrder(Node *node)
{
    if (node == nullptr)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return nullptr;

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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> vt;

        if (!root)
        {
            return vt;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            vector<int> sol;

            for (int i = 0; i < n; i++)
            {
                Node *tmp = q.front();
                q.pop();

                if (tmp->left != NULL)
                {
                    q.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    q.push(tmp->right);
                }
                sol.push_back(tmp->data);
            }
            vt.push_back(sol);
        }
        return vt;
    }
};

int main()
{
    Solution object;
    string s = "1 2 3";
    Node *root = buildTree(s);
    vector<vector<int>> result = object.levelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    s = "10 20 30 40 50";
    root = buildTree(s);
    result = object.levelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    s = "1 3 2 N N N 4 6 5";
    root = buildTree(s);
    result = object.levelOrder(root);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}