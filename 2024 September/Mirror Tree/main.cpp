// Link: https://www.geeksforgeeks.org/problems/mirror-tree/1

#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
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

/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node *node)
{
    if (node == NULL)
        return;

    inOrder(node->left);
    printf("%d ", node->data);

    inOrder(node->right);
}

class Solution
{
public:
    void mirror(Node *node)
    {
        if (!node)
            return;

        queue<Node *> q;
        q.push(node);

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            swap(current->left, current->right);

            if (current->left)
                q.push(current->left);

            if (current->right)
                q.push(current->right);
        }
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3";
    Node *node = buildTree(s);
    obj.mirror(node);
    inOrder(node);
    cout << endl;
    s = "10 20 30 40 60";
    node = buildTree(s);
    obj.mirror(node);
    inOrder(node);
    return 0;
}
