// Link: https://www.geeksforgeeks.org/problems/fruit-into-baskets-1663137462/1

#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
    int totalElements(vector<int> &arr)
    {
        map<int, int> mp;
        int i = 0, j = 0, n = arr.size();
        int size = 0;

        while (j < n)
        {
            mp[arr[j]]++;

            while (mp.size() > 2)
            {

                mp[arr[i]]--;

                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);

                i++;
            }

            size = max(size, j - i + 1);
            j++;
        }

        return size;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {2, 1, 2};
    int result = sol.totalElements(arr);
    cout << "The length of the longest subarray with at most two distinct integers is: " << result << endl;

    arr = {3, 1, 2, 2, 2, 2};
    result = sol.totalElements(arr);
    cout << "The length of the longest subarray with at most two distinct integers is: " << result << endl;

    return 0;
}