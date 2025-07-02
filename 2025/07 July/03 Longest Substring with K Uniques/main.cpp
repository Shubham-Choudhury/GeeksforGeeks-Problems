// Link: https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        int maxi = -1;
        vector<int> fre(26, 0);

        while (j < n)
        {
            fre[s[j] - 'a']++;

            if (fre[s[j] - 'a'] == 1)
                cnt++;

            while (cnt > k)
            {
                fre[s[i] - 'a']--;

                if (fre[s[i] - 'a'] == 0)
                    cnt--;
                i++;
            }

            if (cnt == k)
            {
                maxi = max(maxi, j - i + 1);
            }

            j++;
        }

        return maxi;
    }
};

int main()
{
    Solution sol;
    string s = "aabacbebebe";
    int k = 3;
    int result = sol.longestKSubstr(s, k);
    cout << "Length of the longest substring with " << k << " unique characters: " << result << endl;

    s = "aaaa";
    k = 2;
    result = sol.longestKSubstr(s, k);
    cout << "Length of the longest substring with " << k << " unique characters: " << result << endl;

    s = "aabaaab";
    k = 2;
    result = sol.longestKSubstr(s, k);
    cout << "Length of the longest substring with " << k << " unique characters: " << result << endl;

    return 0;
}