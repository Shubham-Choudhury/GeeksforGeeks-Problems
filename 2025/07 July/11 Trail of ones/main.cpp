// Link: https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int countConsec(int n)
    {
        int prev0 = 0, prev1 = 0;
        for (int i = n; i >= 1; i--)
        {
            int curr0 = prev0 + prev1;
            int curr1 = prev0 + (1 << (n - i));
            prev0 = curr0;
            prev1 = curr1;
        }

        return prev0;
    }
};

int main()
{
    Solution sol;
    int n = 2;
    int result = sol.countConsec(n);
    cout << "Number of ways to form a trail of ones for n = " << n << " is: " << result << endl;

    n = 3;
    result = sol.countConsec(n);
    cout << "Number of ways to form a trail of ones for n = " << n << " is: " << result << endl;

    n = 5;
    result = sol.countConsec(n);
    cout << "Number of ways to form a trail of ones for n = " << n << " is: " << result << endl;

    return 0;
}