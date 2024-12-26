// Link: https://www.geeksforgeeks.org/problems/count-pairs-with-given-sum--150253/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countPairs(vector<int> &arr, int target)
    {
        unordered_map<int, int> map;
        for (int n : arr)
        {
            map[n]++;
        }
        int count = 0;

        for (int n : arr)
        {
            if ((target - n) != n && map[n] > 0 && map.count(target - n) > 0 && map[target - n] > 0)
            {
                count += (map[n] * map[target - n]);
                map[n] = 0;
                map[target - n] = 0;
            }
            else if (target - n == n && map[n] > 1)
            {
                count += (map[n] * (map[n] - 1) / 2);
                map[n] = 0;
            }
        }

        return count;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {1, 5, 7, -1, 5};
    int target = 6;
    cout << object.countPairs(arr, target) << endl;

    arr = {1, 1, 1, 1};
    target = 2;
    cout << object.countPairs(arr, target) << endl;

    arr = {10, 12, 10, 15, -1};
    target = 125;
    cout << object.countPairs(arr, target) << endl;
    return 0;
}