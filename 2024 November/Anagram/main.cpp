// Link: https://www.geeksforgeeks.org/problems/anagram-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool areAnagrams(string &s1, string &s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> arr1(26, 0);
        vector<int> arr2(26, 0);
        for (int i = 0; i < n1; i++)
        {
            arr1[s1[i] - 'a']++;
        }
        for (int i = 0; i < n2; i++)
        {
            arr2[s2[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr1[i] != arr2[i])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution object;
    string s1 = "geeks", s2 = "kseeg";
    cout << boolalpha << object.areAnagrams(s1, s2) << endl;
    s1 = "allergy", s2 = "allergic";
    cout << boolalpha << object.areAnagrams(s1, s2) << endl;
    s1 = "g", s2 = "g";
    cout << boolalpha << object.areAnagrams(s1, s2) << endl;
    return 0;
}