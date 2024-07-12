// Link: https://www.geeksforgeeks.org/problems/root-to-leaf-path-sum/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
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
    bool solve(Node *root, int sum)
    {
        if (root == NULL)
        {
            return 0;
        }
        if (root->left == NULL and root->right == NULL and root->data == sum)
            return 1;
        bool ans = solve(root->left, sum - root->data);
        ans = ans | solve(root->right, sum - root->data);
        return ans;
    }

public:
    bool hasPathSum(Node *root, int target)
    {
        return solve(root, target);
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3";
    Node *root = buildTree(s);
    int target = 2;
    cout << obj.hasPathSum(root, target) << endl;

    s = "1 2 3";
    root = buildTree(s);
    target = 4;
    cout << obj.hasPathSum(root, target) << endl;

    return 0;
}