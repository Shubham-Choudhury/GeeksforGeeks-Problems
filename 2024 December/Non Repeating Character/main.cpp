// Link: https://www.geeksforgeeks.org/problems/non-repeating-character-1587115620/1

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char nonRepeatingChar(string &s)
    {
        int n = s.size();
        unordered_map<char, int> mp;

        for (auto it : s)
        {
            mp[it]++;
        }

        for (int i = 0; i < n; i++)
        {
            if (mp[s[i]] == 1)
            {
                return s[i];
            }
        }
        return '$';
    }
};

int main()
{
    Solution object;
    string s = "geeksforgeeks";
    cout << object.nonRepeatingChar(s) << endl;
    s = "racecar";
    cout << object.nonRepeatingChar(s) << endl;
    s = "aabbccc";
    cout << object.nonRepeatingChar(s) << endl;
    return 0;
}