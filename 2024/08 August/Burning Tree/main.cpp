// Link: https://www.geeksforgeeks.org/problems/burning-tree/1

#include <iostream>
#include <queue>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution
{
private:
    Node *findTarget(Node *root, int target, unordered_map<Node *, Node *> &parentMap)
    {
        if (!root)
            return nullptr;

        queue<Node *> q;
        q.push(root);
        parentMap[root] = nullptr;

        while (!q.empty())
        {
            Node *current = q.front();
            q.pop();

            if (current->data == target)
                return current;

            if (current->left)
            {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }

        return nullptr;
    }

    int bfsBurnTime(Node *startNode, unordered_map<Node *, Node *> &parentMap)
    {
        if (!startNode)
            return 0;

        queue<Node *> q;
        unordered_set<Node *> visited;

        q.push(startNode);
        visited.insert(startNode);
        int maxTime = 0;

        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; ++i)
            {
                Node *current = q.front();
                q.pop();

                if (current->left && visited.find(current->left) == visited.end())
                {
                    q.push(current->left);
                    visited.insert(current->left);
                }
                if (current->right && visited.find(current->right) == visited.end())
                {
                    q.push(current->right);
                    visited.insert(current->right);
                }
                if (parentMap.find(current) != parentMap.end())
                {
                    Node *parent = parentMap[current];
                    if (parent && visited.find(parent) == visited.end())
                    {
                        q.push(parent);
                        visited.insert(parent);
                    }
                }
            }
            ++maxTime;
        }

        return maxTime - 1;
    }

public:
    int minTime(Node *root, int target)
    {
        if (!root)
            return 0;

        unordered_map<Node *, Node *> parentMap;
        Node *targetNode = findTarget(root, target, parentMap);

        if (!targetNode)
            return -1;

        return bfsBurnTime(targetNode, parentMap);
    }
};

int main()
{
    Solution obj;
    string s = "1 2 3 4 5 6 N N N 7 8 9 N N N N N 10 N";
    Node *root = buildTree(s);
    int target = 8;
    cout << obj.minTime(root, target) << endl;

    s = "1 2 3 4 5 7 N 8 N 10 N";
    root = buildTree(s);
    target = 10;
    cout << obj.minTime(root, target) << endl;
    return 0;
}