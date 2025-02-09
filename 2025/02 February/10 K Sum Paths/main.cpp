// Link: https://www.geeksforgeeks.org/problems/k-sum-paths/1

#include <iostream>
#include <sstream>
#include <queue>
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
public:
    void solve(Node *root, int k, vector<int> &path, int &count)
    {
        if (root == nullptr)
        {
            return;
        }

        path.push_back(root->data);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }

        solve(root->left, k, path, count);
        solve(root->right, k, path, count);

        path.pop_back();
    }

    int sumK(Node *root, int k)
    {
        vector<int> path;
        int count = 0;

        solve(root, k, path, count);

        return count;
    }
};

int main()
{
    Solution object;
    string s = "8 4 5 3 2 N 2 3 -2 N 1 N N";
    Node *root = buildTree(s);
    int k = 7;
    cout << object.sumK(root, k) << endl;

    s = "1 2 3";
    root = buildTree(s);
    k = 3;
    cout << object.sumK(root, k) << endl;
    return 0;
}