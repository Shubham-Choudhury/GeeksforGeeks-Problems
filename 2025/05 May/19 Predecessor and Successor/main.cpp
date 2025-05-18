// Link: https://www.geeksforgeeks.org/problems/predecessor-and-successor/1

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

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
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

class Solution
{
public:
    Node *rightMost(Node *node)
    {
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }

    Node *leftMost(Node *node)
    {
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        Node *pre = nullptr;
        Node *suc = nullptr;
        Node *curr = root;

        while (curr != nullptr)
        {
            if (curr->data < key)
            {
                pre = curr;
                curr = curr->right;
            }
            else if (curr->data > key)
            {
                suc = curr;
                curr = curr->left;
            }
            else
            {
                if (curr->left != nullptr)
                    pre = rightMost(curr->left);
                if (curr->right != nullptr)
                    suc = leftMost(curr->right);
                break;
            }
        }

        return {pre, suc};
    }
};

int main()
{
    Solution sol;
    string s = "8 1 9 N 4 N 10 3 N N N";
    Node *root = buildTree(s);
    int key = 8;
    vector<Node *> result = sol.findPreSuc(root, key);
    Node *pre = result[0];
    Node *suc = result[1];
    if (pre)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "Predecessor: NULL" << endl;
    if (suc)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "Successor: NULL" << endl;

    s = "10 2 11 1 5 N N N N 3 6 N 4 N N";
    root = buildTree(s);
    key = 11;
    result = sol.findPreSuc(root, key);
    pre = result[0];
    suc = result[1];
    if (pre)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "Predecessor: NULL" << endl;
    if (suc)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "Successor: NULL" << endl;
    return 0;
}