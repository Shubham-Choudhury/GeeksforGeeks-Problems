// Link: https://www.geeksforgeeks.org/problems/substrings-of-length-k-with-k-1-distinct-elements/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int substrCount(string &s, int k)
    {
        if (k > s.length())
            return 0;

        int n = s.length();

        vector<int> cnt(26, 0);
        int ans = 0;
        int distinctCnt = 0;

        for (int i = 0; i < k - 1; i++)
        {
            cnt[s[i] - 'a']++;

            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;
        }

        for (int i = k - 1; i < n; i++)
        {
            cnt[s[i] - 'a']++;
            if (cnt[s[i] - 'a'] == 1)
                distinctCnt++;

            if (distinctCnt == k - 1)
                ans++;

            cnt[s[i - k + 1] - 'a']--;

            if (cnt[s[i - k + 1] - 'a'] == 0)
                distinctCnt--;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "abcc";
    int k = 2;
    int result = sol.substrCount(s, k);
    cout << "Number of substrings of length " << k << " with " << k - 1 << " distinct elements: " << result << endl;

    s = "aabab";
    k = 3;
    result = sol.substrCount(s, k);
    cout << "Number of substrings of length " << k << " with " << k - 1 << " distinct elements: " << result << endl;
    return 0;
}