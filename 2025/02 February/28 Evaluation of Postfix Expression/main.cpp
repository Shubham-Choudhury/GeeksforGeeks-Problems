// Link: https://www.geeksforgeeks.org/problems/evaluation-of-postfix-expression1735/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int evaluate(vector<string> &arr)
    {
        stack<int> st;

        for (int i = 0; i < arr.size(); ++i)
        {
            string it = arr[i];

            if (it == "+" || it == "-" || it == "*" || it == "/")
            {
                if (st.size() < 2)
                {
                    return -1;
                }

                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                int sum = 0;

                if (it == "+")
                {
                    sum = num2 + num1;
                }
                if (it == "-")
                {
                    sum = num2 - num1;
                }
                if (it == "*")
                {
                    sum = num2 * num1;
                }
                if (it == "/")
                {
                    if (num1 == 0)
                    {
                        return -1;
                    }
                    sum = num2 / num1;
                }
                st.push(sum);
            }
            else
            {
                st.push(stoi(it));
            }
        }

        return st.empty() ? -1 : st.top();
    }
};

int main()
{
    Solution obj;
    vector<string> arr = {"2", "3", "1", "*", "+", "9", "-"};
    cout << obj.evaluate(arr) << endl;

    arr = {"100", "200", "+", "2", "/", "5", "*", "7", "+"};
    cout << obj.evaluate(arr) << endl;
    return 0;
}