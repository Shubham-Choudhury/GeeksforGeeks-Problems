// Link: https://www.geeksforgeeks.org/problems/divisible-by-13/1

#include <iostream>
using namespace std;

class Solution
{
public:
    bool divBy13(string &s)
    {
        int len = s.size();

        if (len == 1 && s[0] == '0')
        {
            return true;
        }

        if (len % 3 == 1)
        {
            s += "00";
            len += 2;
        }
        else if (len % 3 == 2)
        {
            s += "0";
            len += 1;
        }

        int sum = 0;
        int p = 1;

        for (int i = len - 1; i >= 0; i--)
        {
            int group = 0;
            group += s[i--] - '0';
            group += (s[i--] - '0') * 10;
            group += (s[i] - '0') * 100;

            sum = sum + group * p;
            p *= -1;
        }

        sum = abs(sum);

        return (sum % 13 == 0);
    }
};

int main()
{
    Solution sol;
    string s = "2911285";
    bool result = sol.divBy13(s);
    cout << s << " is " << (result ? "divisible" : "not divisible") << " by 13" << endl;

    s = "27";
    result = sol.divBy13(s);
    cout << s << " is " << (result ? "divisible" : "not divisible") << " by 13" << endl;

    return 0;
}