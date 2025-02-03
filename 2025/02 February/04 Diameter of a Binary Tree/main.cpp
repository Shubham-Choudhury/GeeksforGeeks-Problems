// Link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1

#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
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

Node *newNode(int val)
{
    return new Node(val);
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

class Solution
{
public:
    int height(Node *root, int &diameter1)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = height(root->left, diameter1);
        int right = height(root->right, diameter1);
        diameter1 = max(diameter1, left + right);

        return 1 + max(left, right);
    }

    int diameter(Node *root)
    {
        int diameter1 = 0;
        if (root == nullptr)
        {
            return -1;
        }
        height(root, diameter1);
        return diameter1;
    }
};

int main()
{
    Solution object;
    string s = "1 2 3";
    Node *root = buildTree(s);
    cout << object.diameter(root) << endl;

    s = "5 8 6 3 7 9";
    root = buildTree(s);
    cout << object.diameter(root) << endl;

    return 0;
}