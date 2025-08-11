// Link: https://www.geeksforgeeks.org/problems/maximum-non-overlapping-odd-palindrome-sum/1

#include <iostream>
#include <vector>
using namespace std;

class manacher
{
public:
    vector<int> p;
    string ms;

    manacher(string &s)
    {
        ms = "@";
        for (char c : s)
        {
            ms += "#" + string(1, c);
        }
        ms += "#$";
        runManacher();
    }

    void runManacher()
    {
        int n = ms.size();
        p.assign(n, 0);
        int l = 0, r = 0;

        for (int i = 1; i < n - 1; ++i)
        {
            if (r + l - i < n && r + l - i >= 0)
                p[i] = max(0, min(r - i, p[r + l - i]));

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && ms[i + 1 + p[i]] == ms[i - 1 - p[i]])
            {
                ++p[i];
            }

            if (i + p[i] > r)
            {
                l = i - p[i];
                r = i + p[i];
            }
        }
    }

    int getLongest(int cen, int odd)
    {
        int pos = 2 * cen + 2 + !odd;
        return p[pos];
    }

    bool check(int l, int r)
    {
        return (r - l + 1) <= getLongest((r + l) / 2, (r - l + 1) % 2);
    }
};

class Solution
{
public:
    int maxSum(string &s)
    {
        int n = s.size();
        vector<int> leftMark(n, 1), rightMark(n, 1);
        manacher mr(s);

        for (int i = 0; i < n; i++)
        {
            int val = mr.getLongest(i, 1);
            int li = i + val / 2;
            if (li < n)
                leftMark[li] = max(leftMark[li], val);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            leftMark[i] = max(leftMark[i], leftMark[i + 1] - 2);
        }

        for (int i = 1; i < n; i++)
        {
            leftMark[i] = max(leftMark[i], leftMark[i - 1]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int val = mr.getLongest(i, 1);
            int ri = i - val / 2;
            if (ri >= 0)
                rightMark[ri] = max(rightMark[ri], val);
        }

        for (int i = 1; i < n; i++)
        {
            rightMark[i] = max(rightMark[i], rightMark[i - 1] - 2);
        }

        for (int i = n - 2; i >= 0; i--)
        {
            rightMark[i] = max(rightMark[i], rightMark[i + 1]);
        }

        int ans = 0;
        for (int i = 0; i + 1 < n; i++)
        {
            ans = max(ans, leftMark[i] + rightMark[i + 1]);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "gfgforgeeks";
    int result = sol.maxSum(s);
    cout << "Maximum Non-Overlapping Odd Palindrome Sum: " << result << endl;

    s = "xyabacbcz";
    result = sol.maxSum(s);
    cout << "Maximum Non-Overlapping Odd Palindrome Sum: " << result << endl;

    return 0;
}