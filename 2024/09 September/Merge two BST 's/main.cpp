// Link: https://www.geeksforgeeks.org/problems/merge-two-bst-s/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// Tree Node
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

    // Create the root of the tree.....
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
    void inorderIterative(vector<int> &ans, Node *root)
    {
        if (!root)
        {
            return;
        }

        stack<Node *> st;
        Node *curr = root;

        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
            ans.push_back(curr->data);

            curr = curr->right;
        }
    }

    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> ans;
        inorderIterative(ans, root1);
        inorderIterative(ans, root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution obj;
    string s1 = "5 3 6 2 4";
    string s2 = "2 1 3 N N N 7 6";
    Node *root1 = buildTree(s1);
    Node *root2 = buildTree(s2);
    vector<int> ans = obj.merge(root1, root2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    s1 = "12 9 N 6 11";
    s2 = "8 5 10 2";
    root1 = buildTree(s1);
    root2 = buildTree(s2);
    ans = obj.merge(root1, root2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
