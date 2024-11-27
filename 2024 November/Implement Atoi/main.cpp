// Link: https://www.geeksforgeeks.org/problems/implement-atoi/1

#include <iostream>
#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(char *s)
    {
        int i = 0;

        while (s[i] == ' ')
        {
            i++;
        }

        bool sign = true;
        if (s[i] == '-')
        {
            sign = false;
            i++;
        }

        int num = 0;
        while (s[i] >= '0' && s[i] <= '9')
        {
            int digit = s[i] - '0';
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10))
            {
                return sign ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign ? num : -num;
    }
};

int main()
{
    Solution object;
    char *s = "123";
    cout << object.myAtoi(s) << endl;
    s = "  -";
    cout << object.myAtoi(s) << endl;
    s = " 1231231231311133";
    cout << object.myAtoi(s) << endl;
    s = "-999999999999";
    cout << object.myAtoi(s) << endl;
    s = "  -0012gfg4";
    cout << object.myAtoi(s) << endl;
    return 0;
}