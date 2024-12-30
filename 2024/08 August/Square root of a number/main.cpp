// Link: https://www.geeksforgeeks.org/problems/square-root/1

#include <iostream>
using namespace std;

class Solution
{
public:
    long long int floorSqrt(long long int n)
    {
        long long int ans = 0;
        long long int l = 0, h = n;
        while (l <= h)
        {
            long long int mid = (l + h) / 2;
            if (mid * mid == n)
                return mid;
            else if (mid * mid < n)
            {
                ans = mid;
                l = mid + 1;
            }
            else if (mid * mid > n)
            {
                h = mid - 1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    long long int n = 5;
    cout << obj.floorSqrt(n) << endl;
    n = 4;
    cout << obj.floorSqrt(n) << endl;
    return 0;
}