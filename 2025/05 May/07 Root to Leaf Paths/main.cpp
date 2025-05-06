// Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

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
    void findPath(Node *node, vector<vector<int>> &ans, vector<int> temp)
    {
        if (node == NULL)
            return;

        temp.push_back(node->data);

        if (node->left == NULL && node->right == NULL)
        {
            ans.push_back(temp);
            return;
        }

        findPath(node->left, ans, temp);
        findPath(node->right, ans, temp);
    }

    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        if (root)
            findPath(root, ans, temp);
        return ans;
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3 4 5 N N";
    Node *root = buildTree(s);
    vector<vector<int>> result = obj.Paths(root);
    for (const auto &path : result)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    s = "1 2 3";
    root = buildTree(s);
    result = obj.Paths(root);
    for (const auto &path : result)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;

    s = "10 20 30 40 60 N N";
    root = buildTree(s);
    result = obj.Paths(root);
    for (const auto &path : result)
    {
        for (int val : path)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}