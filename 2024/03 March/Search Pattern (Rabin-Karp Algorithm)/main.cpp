// Link: https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> search(string pattern, string text)
    {
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();

        for (int i = 0; i < n; i++)
        {

            bool match = true;

            for (int j = 0; j < m; j++)
                if (text[i + j] != pattern[j])
                {
                    match = false;
                    break;
                }

            if (match == true)
                ans.push_back(i + 1);
        }

        return ans;
    }
};

int main()
{
    Solution obj;
    string text = "birthdayboy";
    string pattern = "birth";
    vector<int> result = obj.search(pattern, text);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    text = "geeksforgeeks";
    pattern = "geek";
    result = obj.search(pattern, text);
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    return 0;
}