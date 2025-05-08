// Link: https://www.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string findMax(string &s, int k)
    {
        if (k == 0)
        {
            return s;
        }

        int n = s.size();
        string ans = s;

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (s[i] < s[j])
                {
                    swap(s[i], s[j]);
                    ans = max(ans, findMax(s, k - 1));
                    swap(s[i], s[j]);
                }
            }
        }

        return ans;
    }

    string findMaximumNum(string &s, int k)
    {
        return findMax(s, k);
    }
};

int main()
{
    Solution sol;
    string s = "1234567";
    int k = 4;
    string result = sol.findMaximumNum(s, k);
    cout << "Largest number after " << k << " swaps: " << result << endl;

    s = "3435335";
    k = 3;
    result = sol.findMaximumNum(s, k);
    cout << "Largest number after " << k << " swaps: " << result << endl;

    s = "1034";
    k = 2;
    result = sol.findMaximumNum(s, k);
    cout << "Largest number after " << k << " swaps: " << result << endl;
    return 0;
}