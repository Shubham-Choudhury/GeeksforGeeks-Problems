// Link: https://www.geeksforgeeks.org/problems/key-pair5616/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool twoSum(vector<int> &arr, int target)
    {
        unordered_map<int, int> mp;
        for (auto &x : arr)
        {
            if (mp.find(target - x) != mp.end())
            {
                return true;
            }
            mp[x]++;
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 4, 45, 6, 10, 8};
    int target = 16;
    cout << boolalpha << object.twoSum(arr, target) << endl;

    arr = {1, 2, 4, 3, 6};
    target = 11;
    cout << boolalpha << object.twoSum(arr, target) << endl;
    return 0;
}