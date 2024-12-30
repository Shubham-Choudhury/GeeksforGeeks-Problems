// Link: https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findWinner(int n, int x, int y)
    {
        vector<bool> d(n + 1, true);
        for (int i = 2; i <= n; i++)
        {
            d[i] = (i - x == 0 || i - y == 0 || (i - 1 > 0 && !d[i - 1]) || (i - x > 0 && !d[i - x]) || (i - y > 0 && !d[i - y]));
        }
        return static_cast<int>(d[n]);
    }
};

int main()
{
    Solution obj;
    cout << obj.findWinner(5, 3, 4) << endl; // Output: 1
    cout << obj.findWinner(2, 3, 4) << endl; // Output: 0
    return 0;
}
