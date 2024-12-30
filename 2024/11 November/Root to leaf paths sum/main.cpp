// Link: https://www.geeksforgeeks.org/problems/root-to-leaf-paths-sum/1

#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    int treePathsSum(Node *root)
    {
        if (!root)
            return 0;

        int totalSum = 0;

        stack<pair<Node *, int>> stack;
        stack.push({root, 0});

        while (!stack.empty())
        {
            auto p = stack.top();
            Node *node = p.first;
            int pathSum = p.second;
            stack.pop();

            pathSum = pathSum * 10 + node->data;

            if (!node->left && !node->right)
            {
                totalSum += pathSum;
            }
            else
            {
                if (node->right)
                {
                    stack.push({node->right, pathSum});
                }
                if (node->left)
                {
                    stack.push({node->left, pathSum});
                }
            }
        }

        return totalSum;
    }
};

int main()
{
    Solution object;
    string s = "6 3 5 2 5 N 4 N N 7 4 N N";
    Node *root = buildTree(s);
    cout << object.treePathsSum(root) << endl;

    s = "10 20 30 40 60 N N";
    root = buildTree(s);
    cout << object.treePathsSum(root) << endl;
    return 0;
}