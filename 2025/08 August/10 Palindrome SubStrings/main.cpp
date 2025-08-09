// Link: https://www.geeksforgeeks.org/problems/count-palindrome-sub-strings-of-a-string0652/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int countPS(string &s)
    {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < s.size(); i++)
        {
            int left = i - 1;
            int right = i + 1;
            while (left >= 0 and right < n)
            {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }

        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i + 1;
            while (left >= 0 and right < n)
            {
                if (s[left] == s[right])
                    count++;
                else
                    break;
                left--;
                right++;
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    string s = "abaab";
    int result = sol.countPS(s);
    cout << result << endl;

    s = "aaa";
    result = sol.countPS(s);
    cout << result << endl;

    s = "abbaeae";
    result = sol.countPS(s);
    cout << result << endl;

    return 0;
}