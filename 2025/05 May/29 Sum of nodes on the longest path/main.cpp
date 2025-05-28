// Link: https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

#include <iostream>
#include <queue>
#include <climits>
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

Node *createBinaryTree(vector<char> &str)
{
    if (str.empty() || str[0] == 'N')
    {
        return NULL;
    }

    Node *root = new Node(str[0] - '0');
    queue<Node *> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < str.size())
    {
        Node *currNode = q.front();
        q.pop();

        if (str[i] != 'N')
        {
            currNode->left = new Node(str[i] - '0');
            q.push(currNode->left);
        }
        i++;

        if (i >= str.size())
            break;

        if (str[i] != 'N')
        {
            currNode->right = new Node(str[i] - '0');
            q.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    void sumOfRootToLeaf(Node *root, int sum, int len, int &maxLen, int &maxSum)
    {
        if (!root)
        {
            if (len > maxLen)
            {
                maxLen = len;
                maxSum = sum;
            }

            else if (len == maxLen && sum > maxSum)
            {
                maxSum = sum;
            }
            return;
        }

        sumOfRootToLeaf(root->left, sum + root->data, len + 1, maxLen, maxSum);
        sumOfRootToLeaf(root->right, sum + root->data, len + 1, maxLen, maxSum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        if (!root)
            return 0;

        int maxSum = INT_MIN, maxLen = 0;
        sumOfRootToLeaf(root, 0, 0, maxLen, maxSum);
        return maxSum;
    }
};

int main()
{
    Solution sol;
    vector<char> str = {'4', '2', '5', '7', '1', '2', '3', 'N', 'N', '6', 'N'};
    Node *root = createBinaryTree(str);
    cout << sol.sumOfLongRootToLeafPath(root) << endl;

    str = {'1', '2', '3', '4', '5', '6', '7'};
    root = createBinaryTree(str);
    cout << sol.sumOfLongRootToLeafPath(root) << endl;

    str = {'1', '5', '5', '3', '7', 'N', '2', '1'};
    root = createBinaryTree(str);
    cout << sol.sumOfLongRootToLeafPath(root) << endl;

    return 0;
}