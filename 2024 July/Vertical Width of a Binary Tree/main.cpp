// Link: https://www.geeksforgeeks.org/problems/vertical-width-of-a-binary-tree/1

#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
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

class Solution
{

    int maxi = 0, mini = 0;
    void solve(Node *root, int x)
    {
        if (!root)
            return;
        maxi = max(maxi, x);
        mini = min(mini, x);
        solve(root->left, x - 1);
        solve(root->right, x + 1);
    }

public:
    int verticalWidth(Node *root)
    {
        if (!root)
            return 0;
        solve(root, 0);
        return maxi - mini + 1;
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3 4 5 6 7 N N N N N 8 9";
    Node *root = buildTree(s);
    cout << obj.verticalWidth(root) << endl;

    s = "1 2 3";
    root = buildTree(s);
    cout << obj.verticalWidth(root) << endl;
    return 0;
}