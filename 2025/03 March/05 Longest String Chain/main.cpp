// Link: https://www.geeksforgeeks.org/problems/longest-string-chain/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool static cmp(const string &a, const string &b) { return a.size() < b.size(); }
    int longestStringChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> dp;
        int res = 1;
        for (const string &w : words)
        {

            dp[w] = 1;
            for (int i = 0; i < w.size(); ++i)
            {
                string pred = w.substr(0, i) + w.substr(i + 1);
                if (dp.find(pred) != dp.end())
                {
                    dp[w] = max(dp[w], dp[pred] + 1);
                }
            }
            res = max(res, dp[w]);
        }
        return res;
    }
};

int main()
{
    Solution object;
    vector<string> words = {"ba", "b", "a", "bca", "bda", "bdca"};
    cout << object.longestStringChain(words) << endl;

    words = {"abc", "a", "ab"};
    cout << object.longestStringChain(words) << endl;

    words = {"abcd", "dbqca"};
    cout << object.longestStringChain(words) << endl;
    return 0;
}