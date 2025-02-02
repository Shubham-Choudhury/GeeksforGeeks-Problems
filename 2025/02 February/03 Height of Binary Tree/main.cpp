// Link: https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

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
    // string after splitting by space
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
    int height(Node *node)
    {
        if (node == NULL)
            return 0;

        queue<Node *> q;
        q.push(node);
        int height = 0;

        while (!q.empty())
        {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++)
            {
                Node *current = q.front();
                q.pop();
                if (current->left)
                    q.push(current->left);
                if (current->right)
                    q.push(current->right);
            }
            height++;
        }
        return height ? height - 1 : height;
    }
};

int main()
{
    Solution object;
    string s = "12 5 18 8 11";
    Node *root = buildTree(s);
    int height = object.height(root);
    cout << "Height of the tree is: " << height << endl;

    s = "1 2 3 4 N N 5 N N 6 7";
    root = buildTree(s);
    height = object.height(root);
    cout << "Height of the tree is: " << height << endl;

    return 0;
}