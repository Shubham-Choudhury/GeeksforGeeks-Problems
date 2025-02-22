// Link: https://www.geeksforgeeks.org/problems/longest-valid-parentheses5657/1

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    int maxLength(string &s)
    {
        stack<int> st;
        st.push(-1);
        int max_length = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    max_length = max(max_length, i - st.top());
                }
            }
        }

        return max_length;
    }
};

int main()
{
    Solution object;
    string s = "((()";
    cout << object.maxLength(s) << endl;

    s = ")()())";
    cout << object.maxLength(s) << endl;

    s = "())()";
    cout << object.maxLength(s) << endl;

    return 0;
}