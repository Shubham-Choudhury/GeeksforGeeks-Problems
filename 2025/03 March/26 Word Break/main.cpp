// Link: https://www.geeksforgeeks.org/problems/word-break1352/1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    unordered_map<int, bool> dp;

    bool solve(int i, string &s, set<string> &st)
    {
        if (i == s.length())
            return true;
        if (dp.find(i) != dp.end())
            return dp[i];

        string temp = "";
        for (int j = i; j < s.length(); j++)
        {
            temp += s[j];
            if (st.find(temp) != st.end() && solve(j + 1, s, st))
            {
                return dp[i] = true;
            }
        }

        return dp[i] = false;
    }

    int wordBreak(string &s, vector<string> &dictionary)
    {
        set<string> st(dictionary.begin(), dictionary.end());
        dp.clear();
        return solve(0, s, st);
    }
};

int main()
{
    Solution obj;
    string s = "ilikegfg";
    vector<string> dictionary = {"i", "like", "man", "india", "gfg"};
    cout << boolalpha << obj.wordBreak(s, dictionary) << endl;

    s = "ilike";
    dictionary = {"i", "like", "gfg"};
    cout << boolalpha << obj.wordBreak(s, dictionary) << endl;

    s = "ilikemangoes";
    dictionary = {"i", "like", "man", "india", "gfg"};
    cout << boolalpha << obj.wordBreak(s, dictionary) << endl;
    return 0;
}