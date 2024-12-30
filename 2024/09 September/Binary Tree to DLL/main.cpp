// Link: https://www.geeksforgeeks.org/problems/binary-tree-to-dll/1

#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node()
        : data(0), left(NULL), right(NULL) {}

    Node(int x)
        : data(x), left(NULL), right(NULL) {}
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node(val);
    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after splitting by space
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
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
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
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

/* Function to print nodes in a given doubly linked list */
void printList(Node *node)
{
    Node *prev = NULL;
    while (node != NULL)
    {
        cout << node->data << " ";
        prev = node;
        node = node->right;
    }
    cout << endl;
    while (prev != NULL)
    {
        cout << prev->data << " ";
        prev = prev->left;
    }
    cout << endl;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

class Solution
{
public:
    Node *bToDLL(Node *root)
    {
        if (!root)
            return NULL;

        Node *head = NULL, *prev = NULL;
        stack<Node *> st;
        Node *curr = root;

        while (curr != NULL || !st.empty())
        {
            while (curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            if (head == NULL)
            {
                head = curr;
            }
            else
            {
                prev->right = curr;
                curr->left = prev;
            }

            prev = curr;

            curr = curr->right;
        }

        return head;
    }
};

int main()
{
    Solution obj;
    string str = "10 12 15 25 30 36";
    Node *root = buildTree(str);
    Node *head = obj.bToDLL(root);
    printList(head);
    return 0;
}