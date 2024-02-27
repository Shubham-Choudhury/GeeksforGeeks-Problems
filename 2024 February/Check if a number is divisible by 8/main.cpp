// Link: https://www.geeksforgeeks.org/problems/check-if-a-number-is-divisible-by-83957/1

#include <bits\stdc++.h>
using namespace std;

class Solution
{
public:
    int DivisibleByEight(string s)
    {
        int n = s.size();
        if (n < 3)
        {
            int r = atoi(s.c_str());
            if (r % 8 == 0)
            {
                return 1;
            }
            return -1;
        }
        string t = "";
        t = t + s[n - 3] + s[n - 2] + s[n - 1];

        int j = atoi(t.c_str());
        if (j % 8 == 0)
        {
            return 1;
        }
        return -1;
    }
};

int main()
{
    Solution obj;
    string s = "54141111648421214584416464555";
    cout << obj.DivisibleByEight(s) << endl;
    s = "16";
    cout << obj.DivisibleByEight(s) << endl;
    return 0;
}