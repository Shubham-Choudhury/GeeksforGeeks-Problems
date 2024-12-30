// Link: https://www.geeksforgeeks.org/problems/nth-natural-number/1

#include <iostream>
using namespace std;

class Solution
{
public:
    long long findNth(long long n)
    {

        long long res = 0;
        long long multi = 1;
        while (n > 0)
        {
            long rem = n % 9;
            res += multi * rem;

            n = n / 9;
            multi = multi * 10;
        }

        return res;
    }
};

int main()
{
    Solution obj;
    int n = 8;
    cout << obj.findNth(n) << endl;
    n = 9;
    cout << obj.findNth(n) << endl;
    return 0;
}