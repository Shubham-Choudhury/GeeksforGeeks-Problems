// Link: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxLength(string str)
    {
        int op = 0;
        int n = str.length();
        int cl = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(')
            {
                op++;
            }
            else
            {
                cl++;
            }
            if (op == cl)
            {
                ans = max(ans, op + cl);
            }
            else if (cl > op)
            {
                op = 0;
                cl = 0;
            }
        }

        op = 0;
        cl = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] == '(')
            {
                op++;
            }
            else
            {
                cl++;
            }
            if (op == cl)
            {
                ans = max(ans, op + cl);
            }
            else if (cl < op)
            {
                op = 0;
                cl = 0;
            }
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string str = "((()";
    cout << obj.maxLength(str) << endl;
    str = ")()())";
    cout << obj.maxLength(str) << endl;
    return 0;
}
