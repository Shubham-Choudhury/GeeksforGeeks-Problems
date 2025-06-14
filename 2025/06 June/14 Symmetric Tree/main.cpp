// Link: https://www.geeksforgeeks.org/problems/symmetric-tree/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *createBinaryTree(const string &s)
{
    if (s.empty())
        return nullptr;

    vector<string> nodes;
    size_t pos = 0, found;
    while ((found = s.find(' ', pos)) != string::npos)
    {
        nodes.push_back(s.substr(pos, found - pos));
        pos = found + 1;
    }
    nodes.push_back(s.substr(pos));

    if (nodes[0] == "N")
        return nullptr;

    Node *root = new Node(stoi(nodes[0]));
    vector<Node *> queue = {root};
    int i = 1;

    while (i < nodes.size())
    {
        Node *current = queue.front();
        queue.erase(queue.begin());

        if (nodes[i] != "N")
        {
            current->left = new Node(stoi(nodes[i]));
            queue.push_back(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "N")
        {
            current->right = new Node(stoi(nodes[i]));
            queue.push_back(current->right);
        }
        i++;
    }

    return root;
}

class Solution
{
public:
    bool isSymmetric(Node *root)
    {
        if (root == nullptr)
            return true;

        stack<Node *> s1, s2;

        s1.push(root->left);
        s2.push(root->right);

        while (!s1.empty() && !s2.empty())
        {
            Node *node1 = s1.top();
            Node *node2 = s2.top();
            s1.pop();
            s2.pop();

            if (node1 == nullptr && node2 == nullptr)
            {
                continue;
            }

            if (node1 == nullptr || node2 == nullptr || node1->data != node2->data)
            {
                return false;
            }

            s1.push(node1->left);
            s2.push(node2->right);

            s1.push(node1->right);
            s2.push(node2->left);
        }

        return s1.empty() && s2.empty();
    }
};

int main()
{
    Solution solution;
    string s = "1 2 2 3 4 4 3";
    Node *root = createBinaryTree(s);
    bool result = solution.isSymmetric(root);
    cout << boolalpha << result << endl;

    s = "1 2 2 N 3 N 3";
    root = createBinaryTree(s);
    result = solution.isSymmetric(root);
    cout << boolalpha << result << endl;

    return 0;
}