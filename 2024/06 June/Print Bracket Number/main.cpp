// Link: https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> bracketNumbers(string str)
    {
        vector<int> vec;
        stack<int> st;
        int o = 0, c = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(')
            {
                o++;
                vec.push_back(o);
                st.push(o);
            }
            else if (str[i] == ')')
            {
                int a = st.top();
                st.pop();
                vec.push_back(a);
            }
        }
        return vec;
    }
};

int main()
{
    Solution obj;
    string str = "(aa(bdc))p(dee)";
    vector<int> res = obj.bracketNumbers(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    str = "(((()(";
    res = obj.bracketNumbers(str);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}