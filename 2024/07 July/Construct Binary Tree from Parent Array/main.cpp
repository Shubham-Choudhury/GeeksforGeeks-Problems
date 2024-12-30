// Link: https://www.geeksforgeeks.org/problems/construct-binary-tree-from-parent-array/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
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

void sort_and_print(vector<int> &v)
{
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    v.clear();
}

void printLevelOrder(struct Node *root)
{
    vector<int> v;
    queue<Node *> q;

    q.push(root);

    Node *next_row = NULL;

    while (!q.empty())
    {
        Node *n = q.front();
        q.pop();

        if (n == next_row)
        {
            sort_and_print(v);
            next_row = NULL;
        }

        v.push_back(n->data);

        if (n->left)
        {
            q.push(n->left);
            if (next_row == NULL)
                next_row = n->left;
        }

        if (n->right)
        {
            q.push(n->right);
            if (next_row == NULL)
                next_row = n->right;
        }
    }
    sort_and_print(v);
}

class Solution
{
public:
    Node *createTree(vector<int> parent)
    {
        unordered_map<int, Node *> mp;

        int n = parent.size();

        Node *root = NULL;

        for (int i = 0; i < n; i++)
        {

            Node *node = NULL;

            if (mp.count(i) != 0)
            {
                node = mp[i];
            }
            else
            {
                node = new Node(i);
                mp[i] = node;
            }

            if (parent[i] == -1)
            {
                root = node;
                continue;
            }

            if (mp.count(parent[i]) != 0)
            {
                if (mp[parent[i]]->left)
                    mp[parent[i]]->right = node;
                else
                    mp[parent[i]]->left = node;
            }
            else
            {
                Node *temp = new Node(parent[i]);
                mp[parent[i]] = temp;
                temp->left = node;
            }
        }

        return root;
    }
};

int main()
{
    Solution obj;
    vector<int> parent = {-1, 0, 0, 1, 1, 3, 5};
    Node *root = obj.createTree(parent);
    printLevelOrder(root);
    cout << endl;

    parent = {2, 0, -1};
    root = obj.createTree(parent);
    printLevelOrder(root);
    return 0;
}