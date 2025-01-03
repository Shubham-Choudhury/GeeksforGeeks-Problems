// Link: https://www.geeksforgeeks.org/problems/count-all-triplets-with-given-sum-in-sorted-array/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr, int target)
    {
        int c = 0;
        for (int i = 0; i < arr.size() - 2; i++)
        {
            int l = i + 1, r = arr.size() - 1;
            while (l < r)
            {
                int sum = arr[i] + arr[l] + arr[r];
                if (sum == target)
                {
                    int el1 = arr[l], el2 = arr[r];
                    int c1 = 0, c2 = 0;
                    while (l <= r && arr[l] == el1)
                    {
                        l++;
                        c1++;
                    }
                    while (l <= r && arr[r] == el2)
                    {
                        r--;
                        c2++;
                    }
                    if (el1 == el2)
                    {
                        c += (c1 * (c1 - 1)) / 2;
                    }
                    else
                    {
                        c += (c1 * c2);
                    }
                }
                else if (sum < target)
                    l++;
                else
                    r--;
            }
        }
        return c;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {-3, -1, -1, 0, 1, 2};
    int target = -2;
    cout << object.countTriplets(arr, target) << endl;

    arr = {-2, 0, 1, 1, 5};
    target = 1;
    cout << object.countTriplets(arr, target) << endl;

    return 0;
}