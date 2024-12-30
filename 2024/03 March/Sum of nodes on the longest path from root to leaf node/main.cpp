// Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
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
    int ans = 0, mh = 0;
    void solve(Node *root, int h, int s)
    {
        if (!root)
        {
            return;
        }
        if (!root->left && !root->right)
        {
            s += root->data;
            if (h > mh)
            {
                ans = s;
                mh = h;
            }
            else if (h == mh)
            {
                ans = max(ans, s);
            }
            return;
        }

        s += root->data;
        solve(root->left, h + 1, s);
        solve(root->right, h + 1, s);

        return;
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        solve(root, 0, 0);
        return ans;
    }
};

int main()
{
    string s;
    s = "4 2 5 7 1 2 3 N N 6";
    Node *root = buildTree(s);
    Solution obj;
    cout << obj.sumOfLongRootToLeafPath(root) << endl;
    return 0;
}