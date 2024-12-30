// Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->key = val;
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
    void solve(Node *root, int N, int &ans)
    {

        if (root == NULL)
            return;

        solve(root->right, N, ans);
        if (root->key <= N && ans == -1)
        {
            ans = root->key;
        }
        solve(root->left, N, ans);
    }

    int findMaxForN(Node *root, int n)
    {
        int ans = -1;
        solve(root, n, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    string s;
    s = "5 2 12 1 3 9 21 N N N N N N 19 25";
    Node *root = buildTree(s);
    int N = 4;
    cout << obj.findMaxForN(root, N) << endl;
    s = "5 2 12 1 3 9 21 N N N N N N 19 25";
    root = buildTree(s);
    N = 24;
    cout << obj.findMaxForN(root, N) << endl;
    return 0;
}