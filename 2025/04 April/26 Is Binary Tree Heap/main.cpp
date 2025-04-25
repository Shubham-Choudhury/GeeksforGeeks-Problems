// Link: https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

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

class Solution
{
public:
    bool isCompleteBT(struct Node *root)
    {

        if (!root)
            return true;

        queue<Node *> q;
        q.push(root);
        bool nullFlag = false;

        while (!q.empty())
        {

            Node *front = q.front();
            q.pop();

            if (!front)
            {
                nullFlag = true;
            }

            else
            {
                if (nullFlag)
                {
                    return false;
                }
                q.push(front->left);
                if (front->left)
                {
                    if (front->left->data > front->data)
                        return false;
                }
                q.push(front->right);
                if (front->right)
                {
                    if (front->right->data > front->data)
                        return false;
                }
            }
        }
        return true;
    }

    bool isHeap(struct Node *tree)
    {
        if (!tree)
            return true;

        return isCompleteBT(tree);
    }
};

int main()
{
    Solution obj;
    string s = "97 46 37 12 3 7 31 6 9";
    Node *root = buildTree(s);
    cout << boolalpha << obj.isHeap(root) << endl;

    s = "97 46 37 12 3 7 31 N 2 4";
    root = buildTree(s);
    cout << boolalpha << obj.isHeap(root) << endl;
    return 0;
}