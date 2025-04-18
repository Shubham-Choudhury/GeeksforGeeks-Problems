// Link: https://www.geeksforgeeks.org/problems/maximum-xor-of-two-numbers-in-an-array/1

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxXor(vector<int> &arr)
    {
        int mask = 0, out = 0;
        for (int i = 31; i >= 0; --i)
        {
            mask = mask | (1 << i);
            unordered_set<int> f;
            for (int x : arr)
            {
                f.insert(x & mask);
            }
            int temp = out | (1 << i);
            for (int j : f)
            {
                if (f.find(j ^ temp) != f.end())
                {
                    out = temp;
                    break;
                }
            }
        }
        return out;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {25, 10, 2, 8, 5, 3};
    cout << "Maximum XOR of two numbers in the array is: " << obj.maxXor(arr) << endl;
    arr = {1, 2, 3, 4, 5, 6, 7};
    cout << "Maximum XOR of two numbers in the array is: " << obj.maxXor(arr) << endl;

    return 0;
}
