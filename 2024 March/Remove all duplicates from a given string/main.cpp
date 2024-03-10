// Link: https://www.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string4321/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string str)
    {
        string ans = "";
        unordered_map<char, int> mapp;
        int n = str.size();

        for (int i = 0; i < n; ++i)
        {
            if (mapp[str[i]] < 1)
            {
                mapp[str[i]]++;
                char c = str[i];
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    string str = "geEksforGEeks";
    cout << obj.removeDuplicates(str) << endl;
    str = "HaPpyNewYear";
    cout << obj.removeDuplicates(str) << endl;
    return 0;
}