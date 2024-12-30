// Link: https://www.geeksforgeeks.org/problems/minimum-number-of-steps-to-reach-a-given-number5234/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(int d)
    {
        int sum = 0;
        for (int i = 1; i <= d; i++)
        {
            sum += i;
            if (sum == d)
            {
                return i;
            }
            else if ((sum - d) >= 2 and (sum - d) % 2 == 0)
            {
                return i;
            }
        }
    }
};

int main()
{
    Solution obj;
    int d = 2;
    cout << obj.minSteps(d) << endl;

    d = 10;
    cout << obj.minSteps(d) << endl;

    return 0;
}