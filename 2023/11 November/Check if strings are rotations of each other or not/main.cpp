// Link: https://www.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1, string s2)
    {
        int n = s1.length();

        if (n != s2.length())
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (s1 == s2)
            {
                return true;
            }
            char a = s1[n - 1];
            string s = to_string(a);
            s1.pop_back();
            s1 = a + s1;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    string s1 = "geeksforgeeks";
    string s2 = "forgeeksgeeks";
    cout << obj.areRotations(s1, s2) << endl;

    s1 = "mightandmagic";
    s2 = "andmagicmigth";
    cout << obj.areRotations(s1, s2) << endl;

    return 0;
}