// Link: https://www.geeksforgeeks.org/problems/smallest-window-containing-0-1-and-2--170637/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int smallestSubstring(string S)
    {
        int n = S.size();
        vector<int> freq(3, 0);
        int start = 0, end = 0;
        int cnt = 0;
        int ans = 1e9;
        while (start < n)
        {
            while (start < n && cnt < 3)
            {
                if (freq[S[start] - '0'] == 0)
                    cnt++;
                freq[S[start] - '0']++;
                start++;
            }

            while (start <= n && cnt == 3)
            {
                ans = min(ans, start - end);
                if (freq[S[end] - '0'] == 1)
                    cnt--;
                freq[S[end] - '0']--;
                end++;
            }
        }
        if (ans == 1e9)
            return -1;
        return ans;
    }
};

int main()
{
    Solution obj;
    string S = "01212";
    cout << obj.smallestSubstring(S);
    return 0;
}