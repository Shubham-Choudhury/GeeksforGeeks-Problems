// Link: https://www.geeksforgeeks.org/problems/game-with-string4100/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minValue(string s, int k)
    {
        unordered_map<char, int> m;
        priority_queue<int> q;

        for (int i = 0; i < s.size(); i++)
            m[s[i]]++;

        for (auto &val : m)
            q.push(val.second);

        while (k--)
        {
            int t = q.top();
            q.pop();
            q.push(--t);
        }
        int sum = 0;
        while (!q.empty())
        {
            int x = q.top();
            sum += (x * x);
            q.pop();
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    string s = "abccc";
    int k = 1;
    cout << obj.minValue(s, k) << endl;

    s = "aabcbcbcabcc";
    k = 3;
    cout << obj.minValue(s, k) << endl;
    return 0;
}