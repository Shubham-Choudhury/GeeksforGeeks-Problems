// Link: https://geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> arr)
    {
        if (arr.empty())
        {
            return "-1";
        }

        string prefix = arr[0];

        for (size_t i = 1; i < arr.size(); i++)
        {
            size_t j = 0;
            while (j < prefix.length() && j < arr[i].length() && prefix[j] == arr[i][j])
            {
                j++;
            }

            prefix = prefix.substr(0, j);

            if (prefix.empty())
            {
                return "-1";
            }
        }

        return prefix;
    }
};

int main()
{
    Solution obj;
    vector<string> arr1 = {"geeksforgeeks", "geeks", "geek", "geezer"};
    cout << obj.longestCommonPrefix(arr1) << endl;

    vector<string> arr2 = {"hello", "world"};
    cout << obj.longestCommonPrefix(arr2) << endl;

    return 0;
}
