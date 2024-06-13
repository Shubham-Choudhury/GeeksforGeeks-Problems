// Link: https://www.geeksforgeeks.org/problems/padovan-sequence2855/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int padovanSequence(int n)
    {
        int MOD = 1000000007;
        int p0 = 1, p1 = 1, p2 = 1;
        if (n <= 2)
        {
            return 1;
        }
        for (int i = 3; i <= n; i++)
        {
            int p = (p1 + p0) % MOD;
            p0 = p1;
            p1 = p2;
            p2 = p;
        }
        return p2;
    }
};

int main()
{
    Solution obj;
    int n = 3;
    cout << obj.padovanSequence(n) << endl;

    n = 4;
    cout << obj.padovanSequence(n) << endl;

    return 0;
}
