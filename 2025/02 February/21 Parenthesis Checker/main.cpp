// Link: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isBalanced(string &s)
    {
        stack<char> st;
        for (char &ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                if ((ch == ')' && top == '(') ||
                    (ch == '}' && top == '{') ||
                    (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution object;
    string s = "[{()}]";
    cout << boolalpha << object.isBalanced(s) << endl;

    s = "[()()]{}";
    cout << boolalpha << object.isBalanced(s) << endl;

    s = "([]";
    cout << boolalpha << object.isBalanced(s) << endl;

    s = "([{]})";
    cout << boolalpha << object.isBalanced(s) << endl;
    return 0;
}