// Link: https://www.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1

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
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node *node)
{
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

class Solution
{

    int position(int in[], int inStart, int inEnd, int val)
    {
        for (int i = inStart; i <= inEnd; i++)
        {
            if (in[i] == val)
                return i;
        }
        return -1;
    }

    Node *tree(int in[], int post[], int &postind, int inStart, int inEnd)
    {
        if (postind < 0 || inStart > inEnd)
            return NULL;

        int val = post[postind--];
        Node *node = new Node(val);

        int pos = position(in, inStart, inEnd, val);

        node->right = tree(in, post, postind, pos + 1, inEnd);
        node->left = tree(in, post, postind, inStart, pos - 1);

        return node;
    }

public:
    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n)
    {
        int postind = n - 1;
        Node *ans = tree(in, post, postind, 0, n - 1);
        return ans;
    }
};

int main()
{
    Solution obj;
    int in1[] = {9, 5, 2, 3, 4};
    int post1[] = {5, 9, 3, 4, 2};
    int n1 = sizeof(in1) / sizeof(in1[0]);
    Node *root1 = obj.buildTree(in1, post1, n1);
    preOrder(root1);
    cout << endl;

    int in2[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int post2[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int n2 = sizeof(in2) / sizeof(in2[0]);
    Node *root2 = obj.buildTree(in2, post2, n2);
    preOrder(root2);
    cout << endl;

    return 0;
}
