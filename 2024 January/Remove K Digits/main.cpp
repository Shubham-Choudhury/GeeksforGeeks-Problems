// Link: https://www.geeksforgeeks.org/problems/remove-k-digits/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeKdigits(string S, int K)
    {
        stack<char> s;
        int n = S.length();
        for (char i : S)
        {
            while (!s.empty() && K > 0 && s.top() > i)
            {
                s.pop();
                K--;
            }
            if (!s.empty() || i != '0')
            {
                s.push(i);
            }
        }
        while (!s.empty() && K--)
        {
            s.pop();
        }
        if (s.empty())
        {
            return "0";
        }
        while (!s.empty())
        {
            S[n - 1] = s.top();
            s.pop();
            n--;
        }
        return S.substr(n);
    }
};

int main()
{
    Solution obj;
    string S = "149811";
    int K = 3;
    cout << obj.removeKdigits(S, K) << endl;
    S = "1002991";
    K = 3;
    cout << obj.removeKdigits(S, K) << endl;
    return 0;
}