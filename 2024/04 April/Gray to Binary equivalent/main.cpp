// Link: https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int grayToBinary(int n)
    {
        vector<int> ans(32, 0);
        int i = 0;
        while (n > 0)
        {
            ans[i] = n % 2;
            i++;
            n = n / 2;
        }
        reverse(ans.begin(), ans.end());

        vector<int> res(32, 0);

        int sum = ans[0];
        for (int i = 0; i < ans.size(); i++)
        {
            sum = sum ^ ans[i];
            res[i] = sum;
        }
        sum = 0;
        int cnt = 0, j = 0;
        while (j < res.size())
        {
            sum = sum * 2 + res[j];
            j++;
        }
        return sum;
    }
};

int main()
{
    Solution obj;
    int n = 4;
    cout << obj.grayToBinary(n) << endl;
    n = 15;
    cout << obj.grayToBinary(n) << endl;
    return 0;
}