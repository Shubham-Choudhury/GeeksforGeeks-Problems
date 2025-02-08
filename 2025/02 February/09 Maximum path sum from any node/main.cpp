// Link: https://www.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1

#include <iostream>
#include <queue>
#include <sstream>
#include <climits>
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
    int solve(Node *root, int &ans)
    {
        if (root == NULL)
            return 0;
        int left = solve(root->left, ans);
        int right = solve(root->right, ans);
        int temp = max(0, max(left, right));
        ans = max(ans, max(root->data + left + right, root->data + temp));

        return root->data + temp;
    }

    int findMaxSum(Node *root)
    {
        // code here
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main()
{
    Solution object;
    string s = "10 2 10 20 1 N -25 N N N N 3 4";
    Node *root = buildTree(s);
    cout << object.findMaxSum(root) << endl;

    s = "-17 11 4 20 -2 10";
    root = buildTree(s);
    cout << object.findMaxSum(root) << endl;
    return 0;
}