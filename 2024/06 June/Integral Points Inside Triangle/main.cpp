// Link: https://www.geeksforgeeks.org/problems/integral-points-in-triangle5026/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
    long long gcd(long long a, long long b)
    {
        while (a > 0 && b > 0)
        {
            if (a > b)
            {
                a = a % b;
            }
            else
            {
                b = b % a;
            }
        }

        if (a == 0)
        {
            return b;
        }
        return a;
    }

    long long getEdgePoint(long long x1, long long y1, long long x2, long long y2)
    {
        if (x1 == x2)
        {
            return abs(y2 - y1) - 1;
        }
        if (y1 == y2)
        {
            return abs(x1 - x2) - 1;
        }
        return gcd(abs(x1 - x2), abs(y1 - y2)) - 1;
    }

public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[])
    {
        long long x1 = p[0];
        long long y1 = p[1];
        long long x2 = q[0];
        long long y2 = q[1];
        long long x3 = r[0];
        long long y3 = r[1];
        int points = getEdgePoint(x1, y1, x2, y2) + getEdgePoint(x2, y2, x3, y3) + getEdgePoint(x3, y3, x1, y1) + 3;
        long long area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
        return (area - points + 2) / 2;
    }
};

int main()
{
    Solution obj;

    long long int p1[] = {0, 0};
    long long int q1[] = {0, 5};
    long long int r1[] = {5, 0};
    cout << obj.InternalCount(p1, q1, r1) << endl;

    long long int p2[] = {62, -3};
    long long int q2[] = {5, -45};
    long long int r2[] = {-19, -23};
    cout << obj.InternalCount(p2, q2, r2) << endl;

    return 0;
}