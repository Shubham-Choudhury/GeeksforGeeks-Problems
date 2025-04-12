// Link: https://www.geeksforgeeks.org/problems/clone-graph/1

#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Node
{
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

vector<Node *> bfs(Node *src)
{
    vector<Node *> ans;
    map<Node *, bool> visit;
    queue<Node *> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        Node *u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}

bool compare(Node *prev, Node *new_node, unordered_set<Node *> &prev_vis,
             unordered_set<Node *> &new_vis)
{
    if (prev == new_node)
    {
        return false;
    }
    if (!prev || !new_node)
    {
        if ((!prev && new_node) || (prev && !new_node))
        {
            return false;
        }
        return true;
    }

    if (prev_vis.count(prev) || new_vis.count(new_node))
    {
        if ((prev_vis.count(prev) && !new_vis.count(new_node)) ||
            (!prev_vis.count(prev) && new_vis.count(new_node)))
        {
            return false;
        }
        return true;
    }
    prev_vis.insert(prev);
    new_vis.insert(new_node);

    if (prev->val != new_node->val)
    {
        return false;
    }

    size_t prev_n = prev->neighbors.size();
    size_t new_n = new_node->neighbors.size();
    if (prev_n != new_n)
    {
        return false;
    }

    sort(prev->neighbors.begin(), prev->neighbors.end(),
         [](Node *a, Node *b)
         { return a->val < b->val; });
    sort(new_node->neighbors.begin(), new_node->neighbors.end(),
         [](Node *a, Node *b)
         { return a->val < b->val; });

    for (size_t i = 0; i < prev_n; ++i)
    {
        if (!compare(prev->neighbors[i], new_node->neighbors[i], prev_vis, new_vis))
        {
            return false;
        }
    }

    return true;
}

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
            return nullptr;

        unordered_map<Node *, Node *> mp;
        queue<Node *> q;

        Node *clone = new Node(node->val);
        mp[node] = clone;
        q.push(node);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();

            for (Node *neighbor : curr->neighbors)
            {
                if (mp.find(neighbor) == mp.end())
                {
                    mp[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                mp[curr]->neighbors.push_back(mp[neighbor]);
            }
        }

        return clone;
    }
};

int main()
{
    Solution solution;
    int n = 4;
    vector<vector<int>> edges = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    vector<Node *> nodes(n);
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j : edges[i])
        {
            nodes[i]->neighbors.push_back(nodes[j]);
        }
    }
    Node *clonedGraph = solution.cloneGraph(nodes[0]);
    vector<Node *> bfsResult = bfs(clonedGraph);
    cout << "Cloned Graph BFS Traversal: ";
    for (Node *node : bfsResult)
    {
        cout << node->val << " ";
    }
    cout << endl;

    cout << "Original Graph BFS Traversal: ";
    vector<Node *> originalBfsResult = bfs(nodes[0]);
    for (Node *node : originalBfsResult)
    {
        cout << node->val << " ";
    }
    cout << endl;

    n = 3;
    edges = {{1, 2}, {0}, {0}};
    nodes.clear();
    nodes.resize(n);
    for (int i = 0; i < n; ++i)
    {
        nodes[i] = new Node(i);
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j : edges[i])
        {
            nodes[i]->neighbors.push_back(nodes[j]);
        }
    }
    clonedGraph = solution.cloneGraph(nodes[0]);
    bfsResult = bfs(clonedGraph);
    cout << "Cloned Graph BFS Traversal: ";
    for (Node *node : bfsResult)
    {
        cout << node->val << " ";
    }
    cout << endl;
    cout << "Original Graph BFS Traversal: ";
    originalBfsResult = bfs(nodes[0]);
    for (Node *node : originalBfsResult)
    {
        cout << node->val << " ";
    }
    cout << endl;

    // Clean up memory
    for (Node *node : nodes)
    {
        delete node;
    }
    for (Node *node : bfsResult)
    {
        delete node;
    }
    for (Node *node : originalBfsResult)
    {
        delete node;
    }

    return 0;
}
