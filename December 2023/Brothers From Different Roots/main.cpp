// Link: https://www.geeksforgeeks.org/problems/brothers-from-different-root/1

#include <bits/stdc++.h>
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

class Solution
{
public:
    int countPairs(Node *root1, Node *root2, int x)
    {
        int ans = 0;
        set<int> s;
        stack<Node *> k;
        k.push(root1);
        while (k.size() != NULL)
        {
            Node *l = k.top();
            s.insert(l->data);
            k.pop();
            if (l->left != NULL)
            {
                k.push(l->left);
            }
            if (l->right != NULL)
            {
                k.push(l->right);
            }
        }
        k.push(root2);
        while (k.size() != NULL)
        {
            Node *l = k.top();
            if (s.find(x - (l->data)) != s.end())
            {
                ans++;
            }
            k.pop();
            if (l->left != NULL)
            {
                k.push(l->left);
            }
            if (l->right != NULL)
            {
                k.push(l->right);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node *root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int x = 16;
    cout << obj.countPairs(root1, root2, x) << endl;
    return 0;
}