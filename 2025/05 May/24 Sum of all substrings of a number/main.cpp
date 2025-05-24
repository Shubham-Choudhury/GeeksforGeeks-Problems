// Link: https://www.geeksforgeeks.org/problems/sum-of-all-substrings-of-a-number-1587115621/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int sumSubstrings(string &s)
    {
        long long int sum = 0;

        long long int mf = 1;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            sum += (s[i] - '0') * (i + 1) * mf;
            mf = mf * 10 + 1;
        }

        return sum;
    }
};

int main()
{
    Solution solution;
    string s = "6759";
    cout << "Sum of all substrings of " << s << " is: " << solution.sumSubstrings(s) << endl;

    s = "421";
    cout << "Sum of all substrings of " << s << " is: " << solution.sumSubstrings(s) << endl;
    return 0;
}