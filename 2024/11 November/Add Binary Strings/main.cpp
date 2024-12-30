// Link: https://www.geeksforgeeks.org/problems/add-binary-strings3805/1

#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string &s1, string &s2)
    {
        int carry = 0;
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        string result = "";
        while (i >= 0 || j >= 0 || carry == 1)
        {
            int sum = carry;
            if (i >= 0)
            {
                sum += s1[i--] - '0';
            }
            if (j >= 0)
            {
                sum += s2[j--] - '0';
            }
            result += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        int idx = 0;
        while (idx < result.size() - 1 && result[idx] == '0')
        {
            idx++;
        }
        result = result.substr(idx);
        return result;
    }
};

int main()
{
    Solution object;
    string s1 = "1101", s2 = "111";
    cout << object.addBinary(s1, s2) << endl;
    s1 = "00100", s2 = "010";
    cout << object.addBinary(s1, s2) << endl;
    return 0;
}