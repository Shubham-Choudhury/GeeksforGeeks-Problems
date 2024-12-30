// Link: https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;
#define MAX_HEIGHT 100000

struct Node
{
    int data;
    Node *left;
    Node *right;
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
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;
    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    Node *lca(Node *root, int a, int b)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root->data == a || root->data == b)
        {
            return root;
        }

        Node *left = lca(root->left, a, b);
        Node *right = lca(root->right, a, b);

        if (left == nullptr)
        {
            return right;
        }
        else if (right == nullptr)
        {
            return left;
        }
        else
        {
            return root;
        }
    }

    int distanceToNode(Node *node, int val)
    {
        if (node == nullptr)
        {
            return -1;
        }
        else if (node->data == val)
        {
            return 0;
        }

        int left = distanceToNode(node->left, val);
        int right = distanceToNode(node->right, val);

        if (left == -1 && right == -1)
        {
            return -1;
        }
        return (left == -1 ? right : left) + 1;
    }

    int findDist(Node *root, int a, int b)
    {
        Node *LCA = lca(root, a, b);
        int distanceA = distanceToNode(LCA, a);
        int distanceB = distanceToNode(LCA, b);
        if (distanceA == -1 || distanceB == -1)
        {
            return -1;
        }
        return distanceA + distanceB;
    }
};

int main()
{
    Solution obj;
    string tree = "11 22 33 44 55 66 77";
    Node *root = buildTree(tree);
    int a = 77, b = 22;
    cout << obj.findDist(root, a, b) << endl;
    return 0;
}