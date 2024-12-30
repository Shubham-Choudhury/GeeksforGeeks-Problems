// Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool ispar(string x)
    {
        stack<char> st;
        for (int i = 0; i < x.size(); i++)
        {
            if (x[i] == '(' || x[i] == '[' || x[i] == '{')
            {
                st.push(x[i]);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                if (x[i] == ')' && st.top() == '(')
                {
                    st.pop();
                }
                else if (x[i] == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else if (x[i] == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    string s = "{([])}";
    cout << obj.ispar(s) << endl;

    s = "()";
    cout << obj.ispar(s) << endl;

    s = "([]";
    cout << obj.ispar(s) << endl;
    return 0;
}