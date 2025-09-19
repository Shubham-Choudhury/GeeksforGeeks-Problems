// Link: https://www.geeksforgeeks.org/problems/decode-the-string2444/1

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string decodedString(string &s)
    {
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != ']')
            {
                st.push(s[i]);
            }
            else
            {
                string temp;

                while (!st.empty() && st.top() != '[')
                {
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(), temp.end());
                st.pop();

                string num;
                while (!st.empty() && isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }

                int number = stoi(num);
                string repeat;

                for (int j = 0; j < number; j++)
                    repeat.append(temp);

                for (char c : repeat)
                    st.push(c);
            }
        }

        string res;
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution obj;
    string s = "3[b2[ca]]";
    string result = obj.decodedString(s);
    cout << "Encoded String: " << s << ", Decoded String: " << result << endl;

    s = "3[ab]";
    result = obj.decodedString(s);
    cout << "Encoded String: " << s << ", Decoded String: " << result << endl;
    return 0;
}