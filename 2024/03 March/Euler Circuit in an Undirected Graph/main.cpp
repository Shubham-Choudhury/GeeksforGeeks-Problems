// Link: https://www.geeksforgeeks.org/problems/euler-circuit-in-a-directed-graph/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isEularCircuitExist(int v, vector<int> adj[])
    {
        for (int i = 0; i < v; i++)
        {
            if (int(adj[i].size()) % 2 == 1)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution obj;
    vector<int> adj[] = {{0, 1},
                         {0, 2},
                         {1, 3},
                         {2, 3}};
    int v = 4;
    cout << obj.isEularCircuitExist(v, adj) << endl;

    vector<int> adj2[] = {{0, 1},
                          {0, 2}};
    int v2 = 3;
    cout << obj.isEularCircuitExist(v2, adj2) << endl;
    return 0;
}