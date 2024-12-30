// Link: https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kSubstrConcat(int n, string s, int k)
    {
        if (n % k || k == 0 || k == n)
            return 0;
        int division = n / k;
        unordered_map<string, int> mp;
        int count = 0;
        string temp = "";
        for (int i = 0; i < s.length(); i++)
        {
            count += 1;
            temp += s[i];
            if (count == k)
            {
                mp[temp]++;
                count = 0;
                temp = "";
            }
        }
        for (auto x : mp)
        {
            if (x.second == division)
                return 1;
            else if (x.second == division - 1)
                return 1;
        }
        return 0;
    }
};

int main()
{
    Solution obj;
    int N = 4;
    int K = 2;
    string S = "bdac";
    cout << obj.kSubstrConcat(N, S, K) << endl;

    N = 5;
    K = 2;
    S = "abcde";
    cout << obj.kSubstrConcat(N, S, K) << endl;

    return 0;
}