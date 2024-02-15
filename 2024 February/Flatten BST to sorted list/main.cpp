// Link: https://www.geeksforgeeks.org/problems/flatten-bst-to-sorted-list--111950/1

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *newNode(int key)
{
    Node *node = new Node(key);
    return node;
}

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

void printList(Node *head)
{
    while (head)
    {
        if (head->left)
            cout << "-1 ";
        cout << head->data << " ";
        head = head->right;
    }
    cout << "\n";
}

class Solution
{
public:
    pair<Node *, Node *> solve(Node *node)
    {
        if (!node)
            return {NULL, NULL};

        pair<Node *, Node *> leftPair = {NULL, NULL};
        pair<Node *, Node *> rightPair = {NULL, NULL};

        Node *first_node = NULL;
        Node *last_node = NULL;

        if (node->left)
        {
            leftPair = solve(node->left);
            leftPair.second->right = node;
            node->left = NULL;
            first_node = leftPair.first;
        }
        else
        {
            first_node = node;
        }

        if (node->right)
        {
            rightPair = solve(node->right);
            node->right = rightPair.first;
            last_node = rightPair.second;
        }
        else
        {
            last_node = node;
        }

        return {first_node, last_node};
    }

    Node *flattenBST(Node *root)
    {
        return (solve(root).first);
    }
};

int main()
{
    Solution obj;

    string s = "5 3 7 2 4 6 8";
    Node *root = buildTree(s);
    Node *head = obj.flattenBST(root);
    printList(head);

    s = "5 N 8 N N 7 9";
    root = buildTree(s);
    head = obj.flattenBST(root);
    printList(head);
    return 0;
}