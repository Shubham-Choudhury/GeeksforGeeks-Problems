// Link: https://www.geeksforgeeks.org/problems/min-add-to-make-parentheses-valid/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int minParentheses(string &s)
    {
        int n = s.size();
        int unmatchedClosing = 0;
        int balance = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                balance++;
            }
            else if (s[i] == ')')
            {
                balance--;

                if (balance < 0)
                {
                    unmatchedClosing++;
                    balance = 0;
                }
            }
        }

        int unmatchedOpening = 0;
        balance = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')
            {
                balance++;
            }
            else if (s[i] == '(')
            {
                balance--;

                if (balance < 0)
                {
                    unmatchedOpening++;
                    balance = 0;
                }
            }
        }

        return unmatchedClosing + unmatchedOpening;
    }
};

int main()
{
    Solution sol;
    string s = "(()(";
    int result = sol.minParentheses(s);
    cout << "Minimum parentheses to be added to make " << s << " valid is: " << result << endl;

    s = ")))";
    result = sol.minParentheses(s);
    cout << "Minimum parentheses to be added to make " << s << " valid is: " << result << endl;
    return 0;
}