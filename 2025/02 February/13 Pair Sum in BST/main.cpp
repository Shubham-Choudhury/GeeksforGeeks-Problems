// Link: https://www.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
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
public:
    bool solve(struct Node *root, int target, set<int> &s)
    {
        if (root == NULL)
            return 0;

        int ele = target - root->data;

        if (s.find(ele) != s.end())
        {
            return 1;
        }

        s.insert(root->data);

        if (solve(root->left, target, s) || solve(root->right, target, s))
        {
            return 1;
        }

        return 0;
    }

    bool findTarget(Node *root, int target)
    {
        set<int> s;
        return solve(root, target, s);
    }
};

int main()
{
    Solution object;
    string s = "7 3 8 2 4 N 9";
    int target = 12;
    Node *root = buildTree(s);
    cout << boolalpha << object.findTarget(root, target)<<endl;

    s = "9 5 10 2 6 N 12";
    target = 23;
    root = buildTree(s);
    cout << boolalpha << object.findTarget(root, target)<<endl;
    return 0;
}