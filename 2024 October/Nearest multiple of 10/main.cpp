// Link: https://www.geeksforgeeks.org/problems/nearest-multiple-of-102437/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string roundToNearest(string str)
    {
        int n = str.size();
        if (str[n - 1] - '0' <= 5)
        {
            str[n - 1] = '0';
            return str;
        }
        int carry = 1;
        str[n - 1] = '0';
        for (int i = n - 2; i >= 0; i--)
        {
            if (carry)
            {
                int num = str[i] - '0';
                num++;
                carry = num / 10;
                str[i] = (num % 10) + '0';
            }
            else
            {
                break;
            }
        }
        if (carry)
        {
            char ch = carry + '0';
            str = ch + str;
        }
        return str;
    }
};

int main()
{
    Solution obj;
    string str = "29";
    cout << obj.roundToNearest(str) << endl;
    str = "15";
    cout << obj.roundToNearest(str) << endl;
    return 0;
}