// Link: https://www.geeksforgeeks.org/problems/node-at-distance/1

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int k;
    Node *left, *right;
};

class Solution
{
public:
    int printKDistantfromLeaf(Node *root, int k)
    {
        std::unordered_set<Node *> set;
        std::vector<std::pair<Node *, int>> stack;

        stack.push_back({root, 0});

        while (stack.size() != 0)
        {
            if (stack.size() > k && stack.back().first->left == nullptr && stack.back().first->right == nullptr)
            {
                set.insert(stack.at(stack.size() - k - 1).first);
            }

            if (stack.back().second == 2)
            {
                stack.pop_back();
                continue;
            }

            if (stack.back().second == 0 && stack.back().first->left != nullptr)
            {
                stack.back().second = 1;
                stack.push_back({stack.back().first->left, 0});
            }
            else if (stack.back().second == 1 && stack.back().first->right != nullptr)
            {
                stack.back().second = 2;
                stack.push_back({stack.back().first->right, 0});
            }
            else
            {
                stack.back().second++;
            }
        }

        return set.size();
    }
};

int main()
{
    Solution obj;
    Node *root = new Node();
    root->k = 1;
    root->left = new Node();
    root->left->k = 2;
    root->right = new Node();
    root->right->k = 3;
    root->left->left = new Node();
    root->left->left->k = 4;
    root->left->right = new Node();
    root->left->right->k = 5;
    root->right->left = new Node();
    root->right->left->k = 6;
    root->right->right = new Node();
    root->right->right->k = 7;
    root->right->left->right = new Node();
    root->right->left->right->k = 8;
    int k = 2;
    cout << obj.printKDistantfromLeaf(root, k);
    return 0;
}