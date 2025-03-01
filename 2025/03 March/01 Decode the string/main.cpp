// Link: https://www.geeksforgeeks.org/problems/decode-the-string2444/1

#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        stack<int> countStack;
        stack<string> strStack;
        string cur = "";
        int num = 0;

        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + (c - '0');
            }
            else if (c == '[')
            {
                countStack.push(num);
                strStack.push(cur);
                cur = "";
                num = 0;
            }
            else if (c == ']')
            {
                string temp = cur;
                int repeat = countStack.top();
                countStack.pop();
                cur = strStack.top();
                strStack.pop();
                while (repeat--)
                    cur += temp;
            }
            else
            {
                cur += c;
            }
        }
        return cur;
    }
};

int main()
{
    Solution object;
    string s = "1[b]";
    cout << object.decodedString(s) << endl;

    s = "3[b2[ca]]";
    cout << object.decodedString(s) << endl;
    return 0;
}