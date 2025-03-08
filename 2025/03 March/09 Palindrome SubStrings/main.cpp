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

        auto expandAroundCenter = [&](int left, int right)
        {
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (right - left + 1 >= 2)
                {
                    count++;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < n; i++)
        {
            expandAroundCenter(i, i);
            expandAroundCenter(i, i + 1);
        }

        return count;
    }
};

int main()
{
    Solution obj;
    string s = "abaab";
    cout << obj.countPS(s) << endl;

    s = "aaa";
    cout << obj.countPS(s) << endl;

    s = "abbaeae";
    cout << obj.countPS(s) << endl;
    return 0;
}