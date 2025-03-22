// Link: https://www.geeksforgeeks.org/problems/total-decoding-messages1235/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countWays(string &digits)
    {
        int n = digits.length();
        vector<int> memo(n, -1);
        return decodeHelper(digits, 0, memo);
    }

    int decodeHelper(string &digits, int index, vector<int> &memo)
    {
        int n = digits.length();
        if (index >= n)
        {
            return 1;
        }
        if (memo[index] != -1)
        {
            return memo[index];
        }
        int ways = 0;
        if (digits[index] != '0')
        {
            ways = decodeHelper(digits, index + 1, memo);
        }
        if ((index + 1 < n) && ((digits[index] == '1' && digits[index + 1] <= '9') ||
                                (digits[index] == '2' && digits[index + 1] <= '6')))
        {
            ways += decodeHelper(digits, index + 2, memo);
        }
        memo[index] = ways;
        return ways;
    }
};

int main()
{
    Solution obj;
    string digits = "123";
    cout << obj.countWays(digits) << endl;

    digits = "90";
    cout << obj.countWays(digits) << endl;

    digits = "05";
    cout << obj.countWays(digits) << endl;
    return 0;
}