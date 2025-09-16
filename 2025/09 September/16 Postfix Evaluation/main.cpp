// Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

class Solution
{
public:
    int evaluatePostfix(vector<string> &arr)
    {
        stack<int> st;

        for (string token : arr)
        {
            if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
            {
                st.push(stoi(token));
            }

            else
            {
                int val1 = st.top();
                st.pop();
                int val2 = st.top();
                st.pop();

                if (token == "+")
                    st.push(val2 + val1);
                else if (token == "-")
                    st.push(val2 - val1);
                else if (token == "*")
                    st.push(val2 * val1);
                else if (token == "/")
                {
                    if (val2 * val1 < 0 && val2 % val1 != 0)
                        st.push(val2 / val1 - 1);
                    else
                        st.push(val2 / val1);
                }
                else if (token == "^")
                    st.push(pow(val2, val1));
            }
        }
        return st.top();
    }
};

int main()
{
    Solution obj;
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    int result = obj.evaluatePostfix(arr);
    cout << "Result: " << result << endl;

    arr = {"2", "3", "^", "1", "+"};
    result = obj.evaluatePostfix(arr);
    cout << "Result: " << result << endl;
    return 0;
}