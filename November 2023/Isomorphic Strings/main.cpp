// Link: https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n = str1.length();
        int m = str2.length();
        if (n != m)
        {
            return false;
        }
        unordered_map<char, char> mp;
        unordered_set<char> usedChar;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(str1[i]) != mp.end())
            {
                if (mp[str1[i]] != str2[i])
                {
                    return false;
                }
            }
            else
            {
                if (usedChar.find(str2[i]) != usedChar.end())
                {
                    return false;
                }
                mp[str1[i]] = str2[i];
                usedChar.insert(str2[i]);
            }
        }
        return true;
    }
};

int main()
{
    Solution obj;
    string s1 = "aab";
    string s2 = "xxy";
    cout << obj.areIsomorphic(s1, s2) << endl;
    return 0;
}