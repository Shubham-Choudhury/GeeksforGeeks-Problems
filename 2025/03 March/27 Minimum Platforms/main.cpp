// Link: https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        map<int, int> mp;
        for (int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]]++;
            mp[dep[i] + 1]--;
        }
        int max1 = 0;
        int tong = 0;
        for (auto it : mp)
        {
            tong = tong + it.second;
            max1 = max(max1, tong);
        }
        return max1;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << obj.findPlatform(arr, dep) << endl;

    arr = {900, 1235, 1100};
    dep = {1000, 1240, 1200};
    cout << obj.findPlatform(arr, dep) << endl;

    arr = {1000, 935, 1100};
    dep = {1200, 1240, 1130};
    cout << obj.findPlatform(arr, dep) << endl;
    return 0;
}