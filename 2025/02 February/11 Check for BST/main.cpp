// Link: https://www.geeksforgeeks.org/problems/check-for-bst/1

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

void inorder(Node *root, vector<int> &v)
{
    if (root == NULL)
        return;

    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

class Solution
{
public:
    bool isBST(Node *root)
    {
        vector<int> in;
        inorder(root, in);

        for (int i = 1; i < in.size(); i++)
        {
            if (in[i - 1] > in[i])
            {
                return false;
            }
        }

        return true;
    }

    void inorder(Node *root, vector<int> &v)
    {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }
};

int main()
{
    Solution object;
    string s = "2 1 3 N N N 5";
    Node *root = buildTree(s);
    cout << boolalpha << object.isBST(root) << endl;

    s = "2 N 7 N 6 N 9";
    root = buildTree(s);
    cout << boolalpha << object.isBST(root) << endl;

    s = "10 5 20 N N 9 25";
    root = buildTree(s);
    cout << boolalpha << object.isBST(root) << endl;
    return 0;
}