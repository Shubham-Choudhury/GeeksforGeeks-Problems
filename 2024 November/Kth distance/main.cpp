// Link: https://www.geeksforgeeks.org/problems/kth-distance3757/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkDuplicatesWithinK(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            if (mp.find(arr[i]) != mp.end() and i - mp[arr[i]] <= k)
            {
                return true;
            }
            mp[arr[i]] = i;
        }
        return false;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 2, 3, 4, 1, 2, 3, 4};
    int k = 3;
    cout << boolalpha << object.checkDuplicatesWithinK(arr, k) << endl;
    arr = {1, 2, 3, 1, 4, 5};
    k = 3;
    cout << boolalpha << object.checkDuplicatesWithinK(arr, k) << endl;
    return 0;
}