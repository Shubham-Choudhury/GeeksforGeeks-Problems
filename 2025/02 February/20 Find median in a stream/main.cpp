// Link: https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<double> getMedian(vector<int> &arr)
    {
        vector<int> sortedList;
        vector<double> medians;

        for (int num : arr)
        {
            auto it = lower_bound(sortedList.begin(), sortedList.end(), num);
            sortedList.insert(it, num);
            int n = sortedList.size();
            if (n % 2 == 1)
            {
                medians.push_back(sortedList[n / 2]);
            }
            else
            {
                medians.push_back((sortedList[n / 2 - 1] + sortedList[n / 2]) / 2.0);
            }
        }

        return medians;
    }
};

int main()
{
    Solution object;
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> medians = object.getMedian(arr);
    for (double median : medians)
    {
        cout << median << " ";
    }
    cout << endl;

    arr = {2, 2, 2, 2};
    medians = object.getMedian(arr);
    for (double median : medians)
    {
        cout << median << " ";
    }
    cout << endl;
    return 0;
}