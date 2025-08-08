// Link: https://www.geeksforgeeks.org/problems/longest-periodic-proper-prefix/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> zFunction(string &s)
    {
        int n = s.size();
        vector<int> z(n);

        for (int i = 1, l = 0, r = 0; i < n; ++i)
        {
            if (i <= r)
            {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                z[i]++;
            }
            if (i + z[i] - 1 > r)
            {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    int getLongestPrefix(string &s)
    {
        int n = s.size();
        vector<int> z = zFunction(s);

        for (int i = n - 1; i > 0; i--)
        {
            if (z[i] == n - i)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    string s = "aaaaaa";
    int result = sol.getLongestPrefix(s);
    cout << result << endl;

    s = "abcab";
    result = sol.getLongestPrefix(s);
    cout << result << endl;

    s = "ababd";
    result = sol.getLongestPrefix(s);
    cout << result << endl;

    return 0;
}