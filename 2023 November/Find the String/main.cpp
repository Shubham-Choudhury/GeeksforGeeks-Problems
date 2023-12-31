// Link: https://www.geeksforgeeks.org/problems/find-the-string/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int k, string prev, unordered_set<string> &seen, vector<int> &edges)
    {
        for (int i = 0; i < k; i++)
        {
            string cur = prev;
            cur += (i + '0');
            if (seen.find(cur) == seen.end())
            {
                seen.insert(cur);
                dfs(k, cur.substr(1), seen, edges);
                edges.push_back(i);
            }
        }
    }
    string findString(int n, int k)
    {
        // code here
        unordered_set<string> seen;
        string startingNode = string(n - 1, '0');
        vector<int> edges;
        dfs(k, startingNode, seen, edges);

        string ret;
        int l = pow(k, n);
        for (int i = 0; i < l; i++)
        {
            ret += (edges[i] + '0');
        }
        ret += startingNode;
        return ret;
    }
};

int main()
{
    Solution obj;
    cout << obj.findString(2, 2) << endl;
    cout << obj.findString(2, 3) << endl;
    return 0;
}