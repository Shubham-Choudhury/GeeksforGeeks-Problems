// Link: https://www.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1

#include <bits/stdc++.h>
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

vector<int> noSibling(Node *root);

vector<int> noSibling(Node *node)
{
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push({node, 0});
    while (!q.empty())
    {
        Node *ptr = q.front().first;
        int level = q.front().second;
        q.pop();
        if (ptr->left && ptr->right)
        {
            q.push({ptr->left, level + 1});
            q.push({ptr->right, level + 1});
        }
        else if (ptr->left)
        {
            q.push({ptr->left, level + 1});
            ans.push_back(ptr->left->data);
        }
        else if (ptr->right)
        {
            q.push({ptr->right, level + 1});
            ans.push_back(ptr->right->data);
        }
    }
    if (ans.empty())
    {
        ans.push_back(-1);
        return ans;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string str = "37 20 113";
    Node *root = buildTree(str);
    vector<int> ans = noSibling(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    str = "1 2 3";
    root = buildTree(str);
    ans = noSibling(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}