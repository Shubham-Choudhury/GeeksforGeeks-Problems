// Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

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

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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
    vector<int> leftView(Node *root)
    {
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }

private:
    void recursionLeft(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
        {
            return;
        }
        if (res.size() == level)
        {
            res.push_back(root->data);
        }
        recursionLeft(root->left, level + 1, res);
        recursionLeft(root->right, level + 1, res);
    }
};

int main()
{
    Solution sol;
    string str = "1 2 3 4 5 N N";
    Node *root = buildTree(str);
    vector<int> leftView = sol.leftView(root);
    for (int i : leftView)
    {
        cout << i << " ";
    }
    cout << endl;

    str = "1 2 3 N N 4 N N 5 N N";
    root = buildTree(str);
    leftView = sol.leftView(root);
    for (int i : leftView)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}