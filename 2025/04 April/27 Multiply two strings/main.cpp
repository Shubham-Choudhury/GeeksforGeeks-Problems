// Link: https://www.geeksforgeeks.org/problems/multiply-two-strings/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string multiplyStrings(string &s1, string &s2)
    {
        int n = s1.size();
        int m = s2.size();

        if (s1 == "0" || s2 == "0")
            return "0";

        bool isNegative = false;
        if (s1[0] == '-')
        {
            isNegative = !isNegative;
            s1 = s1.substr(1);
            n--;
        }
        if (s2[0] == '-')
        {
            isNegative = !isNegative;
            s2 = s2.substr(1);
            m--;
        }

        vector<int> v(n + m, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int mul = (s1[i] - '0') * (s2[j] - '0');
                int sum = v[i + j + 1] + mul;
                v[i + j + 1] = sum % 10;
                v[i + j] += sum / 10;
            }
        }

        string ans;

        if (isNegative)
        {
            ans = "-";
        }

        int i = 0;
        while (i < n + m && v[i] == 0)
        {
            i++;
        }

        if (i == n + m)
            return "0";

        while (i < n + m)
        {
            ans += to_string(v[i++]);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string s1 = "0033", s2 = "2";
    cout << obj.multiplyStrings(s1, s2) << endl;
    s1 = "11", s2 = "23";
    cout << obj.multiplyStrings(s1, s2) << endl;
    s1 = "123", s2 = "0";
    cout << obj.multiplyStrings(s1, s2) << endl;
    return 0;
}