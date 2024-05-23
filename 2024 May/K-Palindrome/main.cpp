// Link: https://www.geeksforgeeks.org/problems/find-if-string-is-k-palindrome-or-not1923/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kPalindrome(string str, int n, int k)
    {
        vector<int> prev(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> curr(n, 0);
            curr[i] = 1;
            for (int j = i + 1; j < n; j++)
            {
                curr[j] = max(prev[j], curr[j - 1]);
                if (str[i] == str[j])
                {
                    curr[j] = max(curr[j], 2 + prev[j - 1]);
                }
            }
            prev = curr;
        }
        return (n - prev[n - 1]) <= k ? 1 : 0;
    }
};

int main()
{
    Solution obj;
    string str = "abcdecba";
    int k = 1;
    int n = str.length();
    cout << obj.kPalindrome(str, n, k) << endl;

    str = "abcdefcba";
    k = 1;
    n = str.length();
    cout << obj.kPalindrome(str, n, k) << endl;
    return 0;
}
