// Link: https://www.geeksforgeeks.org/problems/sum-tree/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
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
    int checkThreeSum(Node *root, bool *ans)
    {
        if (root->right == NULL && root->left == NULL)
            return root->data;

        int sumleft = 0;
        int sumright = 0;
        if (root->right)
            sumleft = checkThreeSum(root->right, ans);

        if (root->left)
            sumright = checkThreeSum(root->left, ans);

        if (root->data != sumleft + sumright)
            *ans = false;

        int totalsum = root->data + sumleft + sumright;
        return totalsum;
    }

    bool isSumTree(Node *root)
    {
        bool ans = true;
        checkThreeSum(root, &ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "3 1 2";
    Node *root = buildTree(s);
    cout << obj.isSumTree(root) << endl;

    s = "10 20 30 10 10";
    root = buildTree(s);
    cout << obj.isSumTree(root) << endl;

    return 0;
}