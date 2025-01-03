// Link: https://www.geeksforgeeks.org/problems/circle-of-strings4530/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    int isCircle(vector<string> &arr)
    {
        int n = arr.size();
        unordered_map<char, int> start, end;
        for (int i = 0; i < n; i++)
        {
            start[arr[i][0]]++;
            end[arr[i].back()]++;
        }
        for (auto &i : start)
        {
            if (start[i.first] != end[i.first])
            {
                return 0;
            }
        }
        unordered_map<char, vector<int>> graph;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            graph[arr[i][0]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = 1;
        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            char lastChar = arr[idx].back();
            for (auto &nextIdx : graph[lastChar])
            {
                if (!visited[nextIdx])
                {
                    visited[nextIdx] = true;
                    q.push(nextIdx);
                    count++;
                }
            }
        }
        return count == n ? 1 : 0;
    }
};

int main()
{
    Solution obj;
    vector<string> arr = {"abc", "bcd", "cdf"};
    cout << obj.isCircle(arr) << endl;
    arr = {"ab", "bc", "cd", "da"};
    cout << obj.isCircle(arr) << endl;
    return 0;
}