// Link: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node)
{
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref)
{
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

class Solution
{
    // Function to serialize a tree and return a list containing nodes of tree.
    void solve(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            ans.push_back(-1);
            return;
        }
        ans.push_back(root->data);
        solve(root->left, ans);
        solve(root->right, ans);
    }

    int index = 0;

public:
    vector<int> serialize(Node *root)
    {
        // Your code here
        vector<int> ans;
        solve(root, ans);
        return ans;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        // Your code here
        if (index == A.size())
        {
            return NULL;
        }
        int val = A[index++];
        if (val == -1)
        {
            return NULL;
        }
        Node *root = new Node(val);
        root->left = deSerialize(A);
        root->right = deSerialize(A);
        return root;
    }
};

int main(){
    Solution obj;
    string s = "1 2 3";
    Node *root = buildTree(s);
    vector<int> A = obj.serialize(root);
    Node *getRoot = obj.deSerialize(A);
    inorder(getRoot);
    cout << endl;
    

    s = "10 20 30 40 60";
    root = buildTree(s);
    A = obj.serialize(root);
    getRoot = obj.deSerialize(A);
    inorder(getRoot);
}