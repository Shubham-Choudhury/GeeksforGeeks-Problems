// Link: https://www.geeksforgeeks.org/problems/substrings-with-similar-first-and-last-characters3644/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countSubstring(string &s)
    {
        int n = s.length();
        vector<int> freq(26, 0);

        for (int i = 0; i < n; i++)
        {
            freq[s[i] - 'a']++;
        }

        int count = 0;

        for (int i = 0; i < 26; i++)
        {
            count += (freq[i] * (freq[i] + 1)) / 2;
        }

        return count;
    }
};

int main()
{
    Solution obj;
    string s = "abcab";
    int result = obj.countSubstring(s);
    cout << "The number of substrings with the same first and last character is: " << result << endl;

    s = "aba";
    result = obj.countSubstring(s);
    cout << "The number of substrings with the same first and last character is: " << result << endl;
    return 0;
}
