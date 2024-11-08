// Link: https://www.geeksforgeeks.org/problems/minimum-times-a-has-to-be-repeated-such-that-b-is-a-substring-of-it--170645/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int minRepeats(string &s1, string &s2)
    {
        int repeatCount = 1;
        string repeatedS1 = s1;

        while (repeatedS1.length() < s2.length())
        {
            repeatedS1 += s1;
            repeatCount++;
        }

        if (repeatedS1.find(s2) != string::npos)
        {
            return repeatCount;
        }

        repeatedS1 += s1;
        repeatCount++;

        if (repeatedS1.find(s2) != string::npos)
        {
            return repeatCount;
        }

        return -1;
    }
};

int main()
{
    Solution object;
    string s1 = "ww", s2 = "www";
    cout << object.minRepeats(s1, s2) << endl;

    s1 = "abcd", s2 = "cdabcdab";
    cout << object.minRepeats(s1, s2) << endl;

    s1 = "ab", s2 = "cab";
    cout << object.minRepeats(s1, s2) << endl;
    return 0;
}