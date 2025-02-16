// Link: https://www.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

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
public:
    vector<int> serialize(Node *root)
    {
        vector<int> ans;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            auto z = q.front();
            q.pop();

            if (z == NULL)
            {
                ans.push_back(-1);
                continue;
            }

            ans.push_back(z->data);
            q.push(z->left);

            q.push(z->right);
        }
        return ans;
    }

    Node *deSerialize(vector<int> &A)
    {
        int i = 0;
        Node *r = new Node(A[i++]);

        queue<Node *> q;
        q.push(r);

        int n = A.size();
        while (i < n)
        {
            if (q.empty())
                break;

            auto z = q.front();
            q.pop();

            if (A[i] != -1)
            {
                z->left = new Node(A[i++]);
                q.push(z->left);
            }
            else
                i++;

            if (i >= n)
                break;

            if (A[i] != -1)
            {
                z->right = new Node(A[i++]);
                q.push(z->right);
            }
            else
                i++;
        }

        return r;
    }
};

int main()
{
    Solution object;
    string s = "1 2 3";
    Node *root = buildTree(s);
    vector<int> A = object.serialize(root);
    Node *getRoot = object.deSerialize(A);
    inorder(getRoot);
    cout << endl;
    deleteTree(&root);
    deleteTree(&getRoot);

    s = "10 20 30 40 60 N N";
    root = buildTree(s);
    A = object.serialize(root);
    getRoot = object.deSerialize(A);
    inorder(getRoot);
    cout << endl;
    deleteTree(&root);
    deleteTree(&getRoot);
    return 0;
}
