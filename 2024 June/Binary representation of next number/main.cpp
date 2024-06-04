// Link: https://www.geeksforgeeks.org/problems/binary-representation-of-next-number3648/1

#include <iostream>
using namespace std;

class Solution
{
public:
    string binaryNextNumber(string s)
    {
        int i = s.size() - 1;
        while (s[i] != '0' && i >= 0)
        {
            s[i] = '0';
            i--;
        }
        if (i >= 0)
        {
            s[i] = '1';
        }
        else
        {
            s = '1' + s;
        }

        i = 0;
        while (s[i] == '0')
        {
            i++;
        }

        return s.substr(i, s.size() - i);
    }
};

int main()
{
    Solution obj;
    string s = "10";
    cout << obj.binaryNextNumber(s) << endl;

    s = "111";
    cout << obj.binaryNextNumber(s) << endl;
    return 0;
}