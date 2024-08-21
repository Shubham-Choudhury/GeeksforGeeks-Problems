// Link: https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    string findOrder(string dict[], int N, int K)
    {
        vector<int> adj[K];
        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        vector<int> ans;
        queue<int> q;
        vector<int> inDegree(K, 0);

        for (int i = 0; i < K; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        for (int i = 0; i < K; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto it : adj[node])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        string result = "";
        for (auto it : ans)
        {
            result = result + char(it + 'a');
        }

        return result;
    }
};

int main()
{
    Solution obj;
    int N = 5;
    int K = 4;
    string dict1[] = {"baa", "abcd", "abca", "cab", "cad"};
    cout << obj.findOrder(dict1, N, K) << endl;

    N = 3;
    K = 3;
    string dict2[] = {"caa", "aaa", "aab"};
    cout << obj.findOrder(dict2, N, K) << endl;
    return 0;
}