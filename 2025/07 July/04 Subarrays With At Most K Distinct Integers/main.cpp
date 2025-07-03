// Link: https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countAtMostK(vector<int> &arr, int k)
    {
        int n = arr.size();
        int res = 0;

        int left = 0, right = 0;

        unordered_map<int, int> freq;
        while (right < n)
        {
            freq[arr[right]] += 1;

            if (freq[arr[right]] == 1)
                k -= 1;

            while (k < 0)
            {
                freq[arr[left]] -= 1;
                if (freq[arr[left]] == 0)
                    k += 1;
                left += 1;
            }

            res += (right - left + 1);
            right += 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {1, 2, 2, 3};
    int k = 2;
    int result = sol.countAtMostK(arr, k);
    cout << "Number of subarrays with at most " << k << " distinct integers: " << result << endl;

    arr = {1, 1, 1};
    k = 1;
    result = sol.countAtMostK(arr, k);
    cout << "Number of subarrays with at most " << k << " distinct integers: " << result << endl;

    arr = {1, 2, 1, 1, 3, 3, 4, 2, 1};
    k = 2;
    result = sol.countAtMostK(arr, k);
    cout << "Number of subarrays with at most " << k << " distinct integers: " << result << endl;

    return 0;
}