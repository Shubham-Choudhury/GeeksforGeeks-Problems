// Link:

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;

    Node(char x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

struct Node *buildTree(string str)
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
    unordered_map<string, int> mp;
    /*This function returns true if the tree contains
    a duplicate subtree of size 2 or more else returns false*/
    string solve(Node *node)
    {
        if (node == NULL)
            return "";
        string ans = "";
        string l = solve(node->left);
        string r = solve(node->right);
        ans = l + "#" + to_string(node->data) + "#" + r;
        if (node->left || node->right)
            mp[ans]++;
        return ans;
    }
    int dupSub(Node *root)
    {
        string x = solve(root);
        for (auto o : mp)
        {
            if (o.second > 1)
            {
                return true;
            }
        }
        return false;
    }
};
