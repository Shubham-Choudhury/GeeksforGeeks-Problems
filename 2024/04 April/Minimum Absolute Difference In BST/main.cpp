// Link: https://www.geeksforgeeks.org/problems/minimum-absolute-difference-in-bst-1665139652/1

#include <bits/stdc++.h>
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
    void inorder(Node *root, vector<int> &ans)
    {

        if (root == NULL)
            return;

        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }

    int absolute_diff(Node *root)
    {
        vector<int> ans;

        inorder(root, ans);

        int n = ans.size();
        int mini = ans[n - 1] - ans[0];

        for (int i = 0; i < n - 1; i++)
        {

            if (ans[i + 1] - ans[i] < mini)
            {
                mini = ans[i + 1] - ans[i];
            }
        }

        return mini;
    }
};

int main()
{
    Solution obj;
    string s;
    s = "50 30 70 20 N 60 80";
    Node *root = buildTree(s);
    cout << obj.absolute_diff(root) << endl;
    s = "60 30 90 10 N N N";
    root = buildTree(s);
    cout << obj.absolute_diff(root) << endl;
    return 0;
}