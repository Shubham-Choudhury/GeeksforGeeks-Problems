// Link: https://www.geeksforgeeks.org/problems/lexicographically-largest-string-after-deleting-k-characters/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string maxSubseq(string s, int k)
    {

        int n = s.length();
        string res = "";
        int rem = n - k;

        for (int i = 0; i < n; i++)
        {
            while (!res.empty() && k > 0 && res.back() < s[i])
            {
                res.pop_back();
                k--;
            }

            res.push_back(s[i]);
        }

        while (k > 0)
        {
            res.pop_back();
            k--;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "ritz";
    int k = 2;
    cout << sol.maxSubseq(s, k) << endl;

    s = "zebra";
    k = 3;
    cout << sol.maxSubseq(s, k) << endl;
    return 0;
}