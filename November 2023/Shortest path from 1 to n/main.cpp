// Link: https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1

#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution
{
public:
    int minimumStep(int n)
    {
        // complete the function here
        int res = 0;
        while (n > 1)
        {
            if (n % 3)
            {
                n -= 1;
            }
            else
            {
                n /= 3;
            }
            res++;
        }
        return res;
    }
};

int main()
{
    Solution obj;
    int n = 9;
    cout << obj.minimumStep(n) << endl;

    n = 4;
    cout << obj.minimumStep(n) << endl;
    return 0;
}