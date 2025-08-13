// Link: https://www.geeksforgeeks.org/problems/count-reverse-pairs/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int merging(vector<int> &arr, int low, int mid, int high)
    {

        int count = 0, j = mid + 1;

        for (int i = low; i <= mid; i++)
        {
            while (j <= high && arr[i] > 2LL * arr[j])
            {
                j++;
            }
            count += (j - (mid + 1));
        }

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
            }
        }

        while (left <= mid)
        {
            temp.push_back(arr[left++]);
        }

        while (right <= high)
        {
            temp.push_back(arr[right++]);
        }

        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }

        return count;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {

        if (low >= high)
        {
            return 0;
        }

        int mid = low + (high - low) / 2;
        int count = mergeSort(arr, low, mid) +
                    mergeSort(arr, mid + 1, high) +
                    merging(arr, low, mid, high);

        return count;
    }

    int countRevPairs(vector<int> &arr)
    {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {3, 2, 4, 5, 1, 20};
    int result = sol.countRevPairs(arr);
    cout << "Count of reverse pairs: " << result << endl;

    arr = {5, 4, 3, 2, 2};
    result = sol.countRevPairs(arr);
    cout << "Count of reverse pairs: " << result << endl;
    return 0;
}