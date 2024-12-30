// Link: https://www.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool static cmp(string &a, string &b)
    {
        if (a + b > b + a)
            return true;
        return false;
    }

    string printLargest(int n, vector<string> &arr)
    {
        sort(arr.begin(), arr.end(), cmp);
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            ans += arr[i];
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<string> arr = {"3", "30", "34", "5", "9"};
    int n = arr.size();
    cout << obj.printLargest(n, arr) << endl;
    arr = {"54", "546", "548", "60"};
    n = arr.size();
    cout << obj.printLargest(n, arr) << endl;
    return 0;
}