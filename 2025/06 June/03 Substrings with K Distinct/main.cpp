// Link: https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int count(string &s, int k)
    {
        int n = s.length();
        int ans = 0;

        vector<int> freq(26, 0);
        int distinctCnt = 0;
        int i = 0;

        for (int j = 0; j < n; j++)
        {

            freq[s[j] - 'a']++;
            if (freq[s[j] - 'a'] == 1)
                distinctCnt++;

            while (distinctCnt > k)
            {
                freq[s[i] - 'a']--;
                if (freq[s[i] - 'a'] == 0)
                    distinctCnt--;
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }

    int countSubstr(string &s, int k)
    {
        int n = s.length();
        int ans = 0;
        ans = count(s, k) - count(s, k - 1);

        return ans;
    }
};

int main()
{
    Solution sol;
    string s = "abc";
    int k = 2;
    int result = sol.countSubstr(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    s = "aba";
    k = 2;
    result = sol.countSubstr(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    s = "aa";
    k = 1;
    result = sol.countSubstr(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;
    return 0;
}