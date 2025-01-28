// Link: https://www.geeksforgeeks.org/problems/powx-n/1

#include <iostream>
using namespace std;

class Solution
{
public:
    double power(double b, int e)
    {
        if (e == 0)
            return 1;

        long long N = e;
        if (N < 0)
        {
            b = 1 / b;
            N = -N;
        }

        double result = 1;
        while (N > 0)
        {
            if (N % 2 == 1)
            {
                result *= b;
            }
            b *= b;
            N /= 2;
        }

        return result;
    }
};

int main()
{
    Solution object;
    double b = 3.00000;
    int e = 5;
    cout << object.power(b, e) << endl;

    b = 0.55000;
    e = 3;
    cout << object.power(b, e) << endl;

    b = -0.67000;
    e = 7;
    cout << object.power(b, e) << endl;
    return 0;
}