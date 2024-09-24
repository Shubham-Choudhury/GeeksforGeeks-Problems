// Link: https://www.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1

#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        int n = s.size();
        int m = p.size();

        if (n < m)
            return "-1";

        vector<int> target(256, 0);
        for (char ch : p)
            target[ch]++;

        int start = 0, minLen = INT_MAX, minStart = 0;
        int count = 0;
        vector<int> window(256, 0);

        for (int end = 0; end < n; end++)
        {
            char currentChar = s[end];
            window[currentChar]++;

            if (target[currentChar] != 0 && window[currentChar] <= target[currentChar])
            {
                count++;
            }

            while (count == m)
            {
                int windowLen = end - start + 1;

                if (windowLen < minLen)
                {
                    minLen = windowLen;
                    minStart = start;
                }

                char startChar = s[start];
                window[startChar]--;

                if (target[startChar] != 0 && window[startChar] < target[startChar])
                {
                    count--;
                }

                start++;
            }
        }

        if (minLen == INT_MAX)
            return "-1";

        return s.substr(minStart, minLen);
    }
};

int main()
{
    Solution obj;
    string s = "timetopractice", p = "toc";
    cout << obj.smallestWindow(s, p) << endl;

    s = "zoomlazapzo", p = "oza";
    cout << obj.smallestWindow(s, p) << endl;
    return 0;
}