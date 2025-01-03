// Link: https://www.geeksforgeeks.org/problems/clone-graph/1

#include <bits/stdc++.h>
#include <sstream>
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

bool compare(Node *prev, Node *new_node, unordered_set<Node *> &prev_vis, unordered_set<Node *> &new_vis)
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
        if ((prev_vis.count(prev) && !new_vis.count(new_node)) || (!prev_vis.count(prev) && new_vis.count(new_node)))
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

    sort(prev->neighbors.begin(), prev->neighbors.end(), [](Node *a, Node *b)
         { return a->val < b->val; });
    sort(new_node->neighbors.begin(), new_node->neighbors.end(), [](Node *a, Node *b)
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
        unordered_map<Node *, Node *> visited;
        return cloneNode(node, visited);
    }
    Node *cloneNode(Node *node, unordered_map<Node *, Node *> &visited)
    {
        if (!node)
        {
            return nullptr;
        }

        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }
        Node *newNode = new Node(node->val);
        visited[node] = newNode;
        for (Node *neighbor : node->neighbors)
        {
            newNode->neighbors.push_back(cloneNode(neighbor, visited));
        }
        return newNode;
    }
};

int main()
{
    Solution obj;
    // {{1,2}, {0,2},{1,3},{0,2}};
    Node *node = new Node(1);
    node->neighbors.push_back(new Node(2));
    node->neighbors.push_back(new Node(3));
    Node *ans = obj.cloneGraph(node);
    vector<Node *> bfs_ans = bfs(ans);
    vector<Node *> bfs_node = bfs(node);
    unordered_set<Node *> prev_vis;
    unordered_set<Node *> new_vis;
    cout << (compare(node, ans, prev_vis, new_vis) ? "true" : "false") << endl;
    return 0;
}