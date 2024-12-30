// Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

#include <iostream>
using namespace std;

class Solution
{
public:
    bool areRotations(string s1, string s2)
    {
        if (s1.length() != s2.length())
        {
            return false;
        }

        string str = s1 + s1;

        if (str.find(s2) != -1)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
};

int main()
{
    Solution object;
    string s1 = "abcd", s2 = "cdab";
    cout << boolalpha << object.areRotations(s1, s2) << endl;

    s1 = "aab", s2 = "aba";
    cout << boolalpha << object.areRotations(s1, s2) << endl;

    s1 = "abcd", s2 = "acbd";
    cout << boolalpha << object.areRotations(s1, s2) << endl;
    return 0;
}