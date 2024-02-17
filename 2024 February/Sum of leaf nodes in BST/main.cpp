// Link: https://www.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1

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

Node *insert(Node *r, int num);
void preOrderDisplay(Node *r);
void inOrderDisplay(Node *r);
void postOrderDisplay(Node *r);
int search(Node *r, int num);

Node *insert(Node *r, int num)
{
    if (r == NULL)
    {
        return new Node(num);
    }
    if (num < r->data)
    {
        r->left = insert(r->left, num);
    }
    else if (num > r->data)
    {
        r->right = insert(r->right, num);
    }
    return r;
}

void preOrderDisplay(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    cout << r->data << " ";
    preOrderDisplay(r->left);
    preOrderDisplay(r->right);
}

void inOrderDisplay(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    inOrderDisplay(r->left);
    cout << r->data << " ";
    inOrderDisplay(r->right);
}

void postOrderDisplay(Node *r)
{
    if (r == NULL)
    {
        return;
    }
    postOrderDisplay(r->left);
    postOrderDisplay(r->right);
    cout << r->data << " ";
}

int search(Node *r, int num)
{
    if (r == NULL)
    {
        return -1;
    }
    if (r->data == num)
    {
        return 1;
    }
    if (num < r->data)
    {
        return search(r->left, num);
    }
    else
    {
        return search(r->right, num);
    }
}

class Solution
{
public:
    void traverse(int &sum, Node *roots)
    {
        if (roots == NULL)
        {
            return;
        }
        else
        {
            if (roots->left == NULL && roots->right == NULL)
            {
                sum += roots->data;
            }
        }
        traverse(sum, roots->left);
        traverse(sum, roots->right);
    }

    int sumOfLeafNodes(Node *root)
    {
        int sum = 0;
        traverse(sum, root);
        return sum;
    }
};

int main()
{
    Solution obj;
    int arr[] = {67, 34, 82, 12, 45, 78};
    Node *root = NULL;
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr[i]);
    }
    cout << obj.sumOfLeafNodes(root) << endl;

    int arr1[] = {45};
    n = sizeof(arr1) / sizeof(arr1[0]);
    root = NULL;
    for (int i = 0; i < n; i++)
    {
        root = insert(root, arr1[i]);
    }
    cout << obj.sumOfLeafNodes(root) << endl;

    return 0;
}