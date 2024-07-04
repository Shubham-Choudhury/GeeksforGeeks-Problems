// Link: https://www.geeksforgeeks.org/problems/duplicate-subtrees/1

#include <iostream>
#include <unordered_map>
#include <vector>
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

    // Creating veactor of strings from input
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
        string currVal = "";
        currVal += ip[i];

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

void preorder(Node *root, vector<int> &temp)
{
    if (!root)
    {
        return;
    }
    // cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}

class Solution
{
private:
    string findDuplicates(Node *node, unordered_map<string, int> &subtreeMap, vector<Node *> &duplicates)
    {
        if (!node)
        {
            return "#";
        }

        string left = findDuplicates(node->left, subtreeMap, duplicates);
        string right = findDuplicates(node->right, subtreeMap, duplicates);

        string subtree = to_string(node->data) + "," + left + "," + right;

        if (subtreeMap[subtree] == 1)
        {
            duplicates.push_back(node);
        }

        subtreeMap[subtree]++;

        return subtree;
    }

public:
    vector<Node *> printAllDups(Node *root)
    {
        vector<Node *> duplicates;
        unordered_map<string, int> subtreeMap;
        findDuplicates(root, subtreeMap, duplicates);
        return duplicates;
    }
};

int main()
{
    Solution obj;
    string s;
    s = "1 2 3 4 N 2 4 N N 4 N";
    Node *root = buildTree(s);
    vector<Node *> duplicates = obj.printAllDups(root);
    for (Node *node : duplicates)
    {
        vector<int> temp;
        preorder(node, temp);
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    cout << endl;

    s = "5 4 6 3 4 N N N N 3 6 N N N N";
    root = buildTree(s);
    duplicates = obj.printAllDups(root);
    for (Node *node : duplicates)
    {
        vector<int> temp;
        preorder(node, temp);
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}