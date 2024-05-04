// Link: https://www.geeksforgeeks.org/problems/vertical-sum/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

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
    vector<int> verticalSum(Node *root)
    {
        queue<pair<Node *, int>> q;
        map<int, vector<int>> list;
        q.push({root, 0});
        while (q.size() != 0)
        {
            pair<Node *, int> front = q.front();
            q.pop();
            int hd = front.second;
            Node *node = front.first;
            list[hd].push_back(node->data);
            if (node->left != NULL)
                q.push({node->left, hd - 1});
            if (node->right != NULL)
                q.push({node->right, hd + 1});
        }
        vector<int> ans;
        for (auto a : list)
        {
            int sum = 0;
            for (auto b : a.second)
                sum += b;
            ans.push_back(sum);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string str = "1 2 3 4 5 6 7";
    Node *root = buildTree(str);
    vector<int> ans = obj.verticalSum(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
