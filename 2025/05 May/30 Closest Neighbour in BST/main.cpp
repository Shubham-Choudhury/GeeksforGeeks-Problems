// Link: https://www.geeksforgeeks.org/problems/closest-neighbor-in-bst/1

#include <iostream>
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

Node *createBinarySearchTree(string str)
{
    Node *root = NULL;
    int n = str.length();
    int i = 0;
    while (i < n)
    {
        if (str[i] == 'N')
        {
            i += 2;
            continue;
        }
        int num = 0;
        while (i < n && str[i] != ' ')
        {
            num = num * 10 + (str[i] - '0');
            i++;
        }
        Node *newNode = new Node(num);
        if (!root)
        {
            root = newNode;
        }
        else
        {
            Node *current = root;
            while (true)
            {
                if (num < current->data)
                {
                    if (!current->left)
                    {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else
                {
                    if (!current->right)
                    {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
        }
        i++;
    }
    return root;
}

class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return k;

        else if (root->data < k)
        {

            int x = findMaxFork(root->right, k);
            if (x == -1)
                return root->data;
            else
                return x;
        }
        return findMaxFork(root->left, k);
    }
};

int main()
{
    Solution obj;
    string str = "10 7 15 2 8 11 16";
    int k = 14;
    Node *root = createBinarySearchTree(str);
    int result = obj.findMaxFork(root, k);
    if (result == -1)
        cout << "No closest neighbour found." << endl;
    else
        cout << "Closest neighbour to " << k << " is: " << result << endl;

    str = "5 2 12 1 3 9 21 N N N N N N 19 25";
    k = 24;
    root = createBinarySearchTree(str);
    result = obj.findMaxFork(root, k);
    if (result == -1)
        cout << "No closest neighbour found." << endl;
    else
        cout << "Closest neighbour to " << k << " is: " << result << endl;

    str = "5 2 12 1 3 9 21 N N N N N N 19 25";
    k = 4;
    root = createBinarySearchTree(str);
    result = obj.findMaxFork(root, k);
    if (result == -1)
        cout << "No closest neighbour found." << endl;
    else
        cout << "Closest neighbour to " << k << " is: " << result << endl;
    return 0;
}