// Link: https://www.geeksforgeeks.org/problems/construct-tree-1/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

class Solution
{
public:
    void creatingMapping(vector<int> &inorder, map<int, int> &indexMapping, int n)
    {
        for (int i = 0; i < n; i++)
        {
            indexMapping[inorder[i]] = i;
        }
    }

    Node *solve(vector<int> &inorder, vector<int> &preorder, int &index, int inorderStart, int inorderEnd, map<int, int> &indexMapping, int n)
    {

        if (index >= n || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = preorder[index++];
        Node *root = new Node(element);
        int position = indexMapping[element];

        root->left = solve(inorder, preorder, index, inorderStart, position - 1, indexMapping, n);
        root->right = solve(inorder, preorder, index, position + 1, inorderEnd, indexMapping, n);

        return root;
    }

    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        int n = inorder.size();
        int preOrderIndex = 0;
        map<int, int> indexMapping;
        creatingMapping(inorder, indexMapping, n);
        Node *ans = solve(inorder, preorder, preOrderIndex, 0, n - 1, indexMapping, n);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> inorder = {1, 6, 8, 7};
    vector<int> preorder = {1, 6, 7, 8};
    Node *root = obj.buildTree(inorder, preorder);
    printPostOrder(root);
    cout << endl;

    inorder = {3, 1, 4, 0, 2, 5};
    preorder = {0, 1, 3, 4, 2, 5};
    root = obj.buildTree(inorder, preorder);
    printPostOrder(root);
    cout << endl;

    inorder = {2, 5, 4, 1, 3};
    preorder = {1, 4, 5, 2, 3};
    root = obj.buildTree(inorder, preorder);
    printPostOrder(root);
    cout << endl;
    return 0;
}