// Link: https://www.geeksforgeeks.org/problems/trail-of-ones3242/1

#include <iostream>
using namespace std;

class Solution
{
public:
    int numberOfConsecutiveOnes(int n)
    {
        int mod = 1e9 + 7;
        int a = 0, b = 1, c = 0;
        for (int i = 2; i <= n; i++)
        {
            int temp_a = a;
            a = b;
            c = ((c * 2) % mod + b) % mod;
            b = (temp_a + b) % mod;
        }
        return c;
    }
};

int main()
{
    Solution obj;
    int n = 2;
    cout << obj.numberOfConsecutiveOnes(n) << endl;
    n = 5;
    cout << obj.numberOfConsecutiveOnes(n) << endl;
    return 0;
}
