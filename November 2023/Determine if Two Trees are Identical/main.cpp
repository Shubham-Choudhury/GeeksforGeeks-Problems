// Link: https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

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

class Solution
{
public:
    void check(Node *r1, Node *r2, bool &ans)
    {
        if (r1 == NULL && r2 == NULL)
        {
            return;
        }

        if ((r1 != NULL && r2 == NULL) || (r1 == NULL && r2 != NULL))
        {
            ans = false;
            return;
        }

        if ((r1->data == NULL && r2->data != NULL) || (r1->data != NULL && r2->data == NULL))
        {
            ans = false;
            return;
        }

        if (r1->data != r2->data)
        {
            ans = false;
            return;
        }
        else
        {
            check(r1->left, r2->left, ans);
            check(r1->right, r2->right, ans);
        }
    }

    bool isIdentical(Node *r1, Node *r2)
    {
        bool ans = true;
        check(r1, r2, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    cout << obj.isIdentical(root1, root2);
    return 0;
}