// Link: https://www.geeksforgeeks.org/problems/lcm-triplet1501/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int lcmTriplets(int n)
    {
        int ans;

        if (n < 3)
        {
            ans = n;
        }
        else if (n % 2)
        {
            ans = n * (n - 1) * (n - 2);
        }
        else if (n % 3)
        {
            ans = n * (n - 1) * (n - 3);
        }
        else
        {
            ans = (n - 1) * (n - 2) * (n - 3);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    int n = 9;
    int result = sol.lcmTriplets(n);
    cout << "LCM of triplet for n = " << n << " is: " << result << endl;

    n = 7;
    result = sol.lcmTriplets(n);
    cout << "LCM of triplet for n = " << n << " is: " << result << endl;
    return 0;
}