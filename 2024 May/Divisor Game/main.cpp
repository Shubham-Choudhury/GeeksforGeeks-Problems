// Link: https://www.geeksforgeeks.org/problems/divisor-game-1664432414/1

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool divisorGame(int n)
    {
        return n % 2 == 0;
    }
};

int main()
{
    Solution obj;
    int n = 2;
    cout << obj.divisorGame(n) << endl;
    n = 3;
    cout << obj.divisorGame(n) << endl;
    return 0;
}