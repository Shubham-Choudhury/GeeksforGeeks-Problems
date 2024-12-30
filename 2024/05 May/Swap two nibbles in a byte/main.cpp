// Link: https://www.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1

#include <iostream>
#include <bitset>
using namespace std;

class Solution
{
public:
    int swapNibbles(int n)
    {
        int mask = (1 << 4) - 1;
        return ((n & mask) << 4) | (n >> 4);
    }
};

int main()
{
    Solution obj;
    int n = 100;
    cout << obj.swapNibbles(n) << endl;
    n = 129;
    cout << obj.swapNibbles(n) << endl;
    return 0;
}
