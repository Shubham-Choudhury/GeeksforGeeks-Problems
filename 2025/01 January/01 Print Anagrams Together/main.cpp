// Link: https://www.geeksforgeeks.org/problems/print-anagrams-together/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution
{
public:
    vector<vector<string>> anagrams(vector<string> &arr)
    {
        unordered_map<string, vector<string>> anagramMap;

        for (const string &str : arr)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            anagramMap[sortedStr].push_back(str);
        }

        vector<vector<string>> result;

        set<string> addedGroups;

        for (const string &str : arr)
        {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            if (addedGroups.find(sortedStr) == addedGroups.end())
            {
                result.push_back(anagramMap[sortedStr]);
                addedGroups.insert(sortedStr);
            }
        }
        return result;
    }
};

int main()
{
    Solution object;
    vector<string> arr = {"act", "god", "cat", "dog", "tac"};
    vector<vector<string>> result = object.anagrams(arr);
    for (const vector<string> &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << endl;

    arr = {"no", "on", "is"};
    result = object.anagrams(arr);
    for (const vector<string> &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << endl;

    arr = {"listen", "silent", "enlist", "abc", "cab", "bac", "rat", "tar", "art"};
    result = object.anagrams(arr);
    for (const vector<string> &group : result)
    {
        for (const string &str : group)
        {
            cout << str << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}