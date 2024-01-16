// Link: https://www.geeksforgeeks.org/problems/sequence-of-sequence1155/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberSequence(int m, int n)
    {

        if (n == 0)
            return 0;

        if (n == 1)
            return m;

        int sum = 0;

        for (int i = 1; i <= m; i++)
        {

            sum += numberSequence(i / 2, n - 1);
        }

        return sum;
    }
};

int main()
{
    Solution obj;
    int M = 10;
    int N = 4;
    cout << obj.numberSequence(M, N) << endl;
    M = 5;
    N = 2;
    cout << obj.numberSequence(M, N) << endl;
    return 0;
}