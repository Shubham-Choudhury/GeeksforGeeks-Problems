// Link: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <utility>
using namespace std;

class Solution
{
public:
    vector<string> findPermutation(string s)
    {
        sort(s.begin(), s.end());

        stack<pair<string, string>> stack;
        stack.push({s, ""});
        vector<string> result;

        while (!stack.empty())
        {
            pair<string, string> current = stack.top();
            stack.pop();

            string remaining = current.first;
            string path = current.second;

            if (remaining.empty())
            {
                result.push_back(path);
                continue;
            }

            set<char> used;
            for (size_t i = 0; i < remaining.size(); ++i)
            {
                if (used.count(remaining[i]))
                    continue;
                used.insert(remaining[i]);
                stack.push({remaining.substr(0, i) + remaining.substr(i + 1), path + remaining[i]});
            }
        }

        return result;
    }
};

int main()
{
    Solution object;
    string s = "ABC";
    vector<string> ans = object.findPermutation(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    s = "ABSG";
    ans = object.findPermutation(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    s = "AAA";
    ans = object.findPermutation(s);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}