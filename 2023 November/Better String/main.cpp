// Link: https://www.geeksforgeeks.org/problems/better-string/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string betterString(string str1, string str2)
    {
        int str1_subString_count = subStringCount(str1);
        int str2_subString_count = subStringCount(str2);
        if (str1_subString_count < str2_subString_count)
        {
            return str2;
        }
        else
        {
            return str1;
        }
    }

    int subStringCount(string &str)
    {
        int arr[26] = {-1};
        int count = 1;
        for (int i = 0; i < str.length(); i++)
        {
            if (arr[str[i] - 'a'] == -1)
            {
                arr[str[i] - 'a'] = count;
                count *= 2;
            }
            else if (arr[str[i] - 'a'] != -1)
            {
                int temp = arr[str[i] - 'a'];
                arr[str[i] - 'a'] = count;
                count *= 2;
                count = count - temp;
            }
        }
        return count;
    }
};

int main()
{
    Solution obj;
    string str1 = "gfg";
    string str2 = "ggg";
    cout << obj.betterString(str1, str2) << endl;

    str1 = "a";
    str2 = "b";
    cout << obj.betterString(str1, str2) << endl;
    return 0;
}