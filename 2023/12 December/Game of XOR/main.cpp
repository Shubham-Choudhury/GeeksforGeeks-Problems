// Link: https://www.geeksforgeeks.org/problems/game-of-xor1541/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int gameOfXor(int N, int A[])
    {
        int ans = 0;
        for (int i = 0; i < N; i++)
        {
            long long res = (N - i) * (i + 1);
            if (res % 2 != 0)
            {
                ans = (ans ^ A[i]);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    int A[] = {1, 2, 3};
    int N = sizeof(A) / sizeof(A[0]);
    cout << obj.gameOfXor(N, A);
    return 0;
}