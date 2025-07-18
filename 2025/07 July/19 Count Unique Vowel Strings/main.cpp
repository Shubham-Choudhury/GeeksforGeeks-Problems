// Link: https://www.geeksforgeeks.org/problems/count-unique-vowel-strings/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int count(int mask, int k, vector<int> &freq, vector<int> &dp)
    {
        if (mask == (1 << k) - 1)
        {
            return 1;
        }

        if (dp[mask] != -1)
        {
            return dp[mask];
        }

        int total = 0;

        for (int i = 0; i < k; i++)
        {
            if ((mask & (1 << i)) == 0)
            {
                total += freq[i] * count(mask | (1 << i), k, freq, dp);
            }
        }

        dp[mask] = total;
        return total;
    }

    int vowelCount(string &s)
    {
        string v = "aeiou";
        unordered_map<char, int> f;

        for (char c : s)
        {
            if (v.find(c) != string::npos)
            {
                f[c]++;
            }
        }

        vector<int> freq;

        for (char ch : v)
        {
            if (f.find(ch) != f.end())
            {
                freq.push_back(f[ch]);
            }
        }

        int k = freq.size();
        if (k == 0)
        {
            return 0;
        }

        vector<int> dp(1 << k, -1);
        return count(0, k, freq, dp);
    }
};

int main()
{
    Solution sol;
    string s = "aeiou";
    int result = sol.vowelCount(s);
    cout << result << endl;

    s = "ae";
    result = sol.vowelCount(s);
    cout << result << endl;

    s = "aacidf";
    result = sol.vowelCount(s);
    cout << result << endl;

    return 0;
}